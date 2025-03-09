---
categories:
- Programmers
date: '2024-11-10'
title: '[Programmers] 2018 KAKAO BLIND RECRUITMENT - 추석 트래픽'
---

{% raw %}
> Lv. 3<br>

## 문제
이번 추석에도 시스템 장애가 없는 명절을 보내고 싶은 어피치는 서버를 증설해야 할지 고민이다. 장애 대비용 서버 증설 여부를 결정하기 위해 작년 추석 기간인 9월 15일 로그 데이터를 분석한 후 초당 최대 처리량을 계산해보기로 했다.  **초당 최대 처리량**은 요청의 응답 완료 여부에 관계없이 임의 시간부터 1초(=1,000밀리초)간 처리하는 요청의 최대 개수를 의미한다.

### 입력 형식
-   `solution`  함수에 전달되는  `lines`  배열은  **N**(1 ≦  **N**  ≦ 2,000)개의 로그 문자열로 되어 있으며, 각 로그 문자열마다 요청에 대한 응답완료시간  **S**와 처리시간  **T**가 공백으로 구분되어 있다.
-   응답완료시간  **S**는 작년 추석인 2016년 9월 15일만 포함하여 고정 길이  `2016-09-15 hh:mm:ss.sss`  형식으로 되어 있다.
-   처리시간  **T**는  `0.1s`,  `0.312s`,  `2s`  와 같이 최대 소수점 셋째 자리까지 기록하며 뒤에는 초 단위를 의미하는  `s`로 끝난다.
-   예를 들어, 로그 문자열  `2016-09-15 03:10:33.020 0.011s`은 "2016년 9월 15일 오전 3시 10분  **33.010초**"부터 "2016년 9월 15일 오전 3시 10분  **33.020초**"까지 "**0.011초**" 동안 처리된 요청을 의미한다.  **(처리시간은 시작시간과 끝시간을 포함)**
-   서버에는 타임아웃이 3초로 적용되어 있기 때문에 처리시간은  **0.001 ≦ T ≦ 3.000**이다.
-   `lines`  배열은 응답완료시간  **S**를 기준으로 오름차순 정렬되어 있다.

### 출력 형식
-   `solution`  함수에서는 로그 데이터  `lines`  배열에 대해  **초당 최대 처리량**을 리턴한다.

## 해결
- 구간이 주어졌을 때, 특정 범위 내 걸쳐지거나 포함되는 구간의 최대 개수를 찾아야 합니다. => `슬라이딩 윈도우`<br>
- N의 최대가 충분히 작기 때문에 모든 구간을 나이브로 비교하는 O(N<sup>2</sup>) 방법이 가능합니다.
- 구간을 최대한 많이 포함하려면 항상 윈도우의 시작을 어떠한 구간의 시작점 또는 끝점으로 하는 것이 이득입니다.

```
1. 시간 구간을 정수 구간으로 변환
2. 모든 구간 탐색:
	- 구간의 시작점 또는 끝점을 윈도우 시작점으로 설정
	- 모든 구간 탐색하여 윈도우 범위에 포함되는 개수 찾기
	- 최대 개수 업데이트
```

## 코드
```
#include <string>
#include <vector>
using namespace std;
struct Range { int lo, hi; };
int ttoi(string t) {
    return stoi(t.substr(11, 2)) * 3600000 + stoi(t.substr(14, 2)) * 60000 +
        stoi(t.substr(17, 2)) * 1000 + stoi(t.substr(20, 3));
}

int solution(vector<string> logs) {<br>
    vector<Range> R;<br>
    for (auto log : logs) {
        int hi = ttoi(log);
        int lo = hi - stod(log.substr(24, log.size() - 25)) * 1000;
        R.push_back({ lo + 1, hi });
    }
    int maxCnt = 1, N = R.size();
    for(int i = 0; i < N; i++) {
        int cnt1 = 0, cnt2 = 0;
        for(int j = 0; j < N; j++) {
            if(!(R[j].lo > R[i].lo + 999 || R[j].hi < R[i].lo))<br>
                cnt1++;
            if(!(R[j].lo > R[i].hi + 999 || R[j].hi < R[i].hi))<br>
                cnt2++;
        }  
        maxCnt = max(maxCnt, max(cnt1, cnt2));
    }
    return maxCnt;
}
```

## 링크
https://school.programmers.co.kr/learn/courses/30/lessons/17676
{% endraw %}