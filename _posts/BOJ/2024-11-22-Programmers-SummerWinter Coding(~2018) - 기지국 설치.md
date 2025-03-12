---
categories:
- Programmers
date: '2024-11-22'
title: '[Programmers] SummerWinter Coding(~2018) - 기지국 설치'
---

{% raw %}
> Lv. 3<br>

## 문제
N개의 아파트가 일렬로 쭉 늘어서 있습니다. 이 중에서 일부 아파트 옥상에는 4g 기지국이 설치되어 있습니다. 기술이 발전해 5g 수요가 높아져 4g 기지국을 5g 기지국으로 바꾸려 합니다. 그런데 5g 기지국은 4g 기지국보다 전달 범위가 좁아, 4g 기지국을 5g 기지국으로 바꾸면 어떤 아파트에는 전파가 도달하지 않습니다.

아파트의 개수 N, 현재 기지국이 설치된 아파트의 번호가 담긴 1차원 배열 stations, 전파의 도달 거리 W가 매개변수로 주어질 때, 모든 아파트에 전파를 전달하기 위해 증설해야 할 기지국 개수의 최솟값을 리턴하는 solution 함수를 완성해주세요

### 제한사항
-   N: 200,000,000 이하의 자연수
-   stations의 크기: 10,000 이하의 자연수
-   stations는 오름차순으로 정렬되어 있고, 배열에 담긴 수는 N보다 같거나 작은 자연수입니다.
-   W: 10,000 이하의 자연수

## 해결
설치된 안테나가 커버하지 못하는 구간을 모두 찾고, ceil(구간 길이 / 커버 범위)를 모두 더하면 됩니다. (커버 범위 = `W `* 2 + 1)

```
1. 모든 안테나 조사해서 커버 안된 구간 모두 찾기
2. ceil(구간 길이 / 커버 범위) 모두 더하기
```

## 코드
```
#include <vector>
using namespace std;
int answer;

void install(int lo, int hi, int W) {
    if(lo < hi) {
        int dist = hi - lo, wide = W * 2 + 1;
        answer += dist / wide + (dist % wide != 0 ? 1 : 0);
    }
}

int solution(int N, vector<int> S, int W) {<br>
    int lo = 1;
    for(int i = 0; i < S.size(); i++) {
        install(lo, S[i] - W, W);
        lo = S[i] + W + 1;
    }
    install(lo, N + 1, W);
    return answer;
}
```

## 링크
https://school.programmers.co.kr/learn/courses/30/lessons/12979<br>
{% endraw %}