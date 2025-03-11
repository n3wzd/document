---
categories:
- Programmers
date: '2024-11-07'
title: '[Programmers] 2018 KAKAO BLIND RECRUITMENT - 캐시'
---

{% raw %}
> Lv. 2<br>

## 문제
지도개발팀에서 근무하는 제이지는 지도에서 도시 이름을 검색하면 해당 도시와 관련된 맛집 게시물들을 데이터베이스에서 읽어 보여주는 서비스를 개발하고 있다.  
이 프로그램의 테스팅 업무를 담당하고 있는 어피치는 서비스를 오픈하기 전 각 로직에 대한 성능 측정을 수행하였는데, 제이지가 작성한 부분 중 데이터베이스에서 게시물을 가져오는 부분의 실행시간이 너무 오래 걸린다는 것을 알게 되었다.  
어피치는 제이지에게 해당 로직을 개선하라고 닦달하기 시작하였고, 제이지는 DB 캐시를 적용하여 성능 개선을 시도하고 있지만 캐시 크기를 얼마로 해야 효율적인지 몰라 난감한 상황이다.

어피치에게 시달리는 제이지를 도와, DB 캐시를 적용할 때 캐시 크기에 따른 실행시간 측정 프로그램을 작성하시오.

### 입력 형식
-   캐시 크기(`cacheSize`)와 도시이름 배열(`cities`)을 입력받는다.
-   `cacheSize`는 정수이며, 범위는 0 ≦  `cacheSize`  ≦ 30 이다.
-   `cities`는 도시 이름으로 이뤄진 문자열 배열로, 최대 도시 수는 100,000개이다.
-   각 도시 이름은 공백, 숫자, 특수문자 등이 없는 영문자로 구성되며, 대소문자 구분을 하지 않는다. 도시 이름은 최대 20자로 이루어져 있다.

### 출력 형식
-   입력된 도시이름 배열을 순서대로 처리할 때, "총 실행시간"을 출력한다.

### 조건
-   캐시 교체 알고리즘은  `LRU`(Least Recently Used)를 사용한다.
-   `cache hit`일 경우 실행시간은  `1`이다.
-   `cache miss`일 경우 실행시간은  `5`이다.

## 해결
`LRU` 캐시 교환 정책을 구현하는 문제입니다. LRU는 캐시 목록 길이가 최대일 때 새로운 캐시가 추가되면, 가장 오랫동안 쓰이지 않은 값을 버리는 방법입니다. 선입후출(First In, First Out: FIFO) 구조이므로 `큐`를 활용해서 구현합니다.

```
캐시 데이터 추가: d
1. 큐 순회: d가 있는지 확인
	- d가 존재하면 hit, 아니면 miss
	- hit일 때는 d를 큐에서 삭제
2. d를 큐에 추가
3. miss인 경우:
	- 큐 크기가 최대일 때, 큐의 마지막 값 제거
```

## 코드
```
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int N, T;
queue<string> cache;<br>
bool compare(string a, string b) {
    transform(a.begin(), a.end(), a.begin(), ::tolower);
    transform(b.begin(), b.end(), b.begin(), ::tolower);
    return a == b;
}

int find(string s) {
    bool hit = 0; int size = cache.size();
    while(size--) {
        string data = cache.front(); cache.pop();
        if(compare(data, s))
            hit = 1;
        else
            cache.push(data);
    }
    cache.push(s);
    if(hit) 
        return 1;
    else if(cache.size() > N)<br>
        cache.pop();
    return 5;
}

int solution(int cacheSize, vector<string> cities) {<br>
    N = cacheSize;
    for(auto d : cities)
        T += find(d);
    return T;
}
```

## 링크
https://school.programmers.co.kr/learn/courses/30/lessons/17680
{% endraw %}