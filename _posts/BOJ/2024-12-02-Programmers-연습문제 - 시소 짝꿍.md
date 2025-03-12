---
categories:
- Programmers
date: '2024-12-02'
title: '[Programmers] 연습문제 - 시소 짝꿍'
---

{% raw %}
> Lv. 2<br>

## 문제
어느 공원 놀이터에는 시소가 하나 설치되어 있습니다. 이 시소는 중심으로부터 2(m), 3(m), 4(m) 거리의 지점에 좌석이 하나씩 있습니다.  
이 시소를 두 명이 마주 보고 탄다고 할 때, 시소가 평형인 상태에서 각각에 의해 시소에 걸리는 토크의 크기가 서로 상쇄되어 완전한 균형을 이룰 수 있다면 그 두 사람을 시소 짝꿍이라고 합니다. 즉, 탑승한 사람의 무게와 시소 축과 좌석 간의 거리의 곱이 양쪽 다 같다면 시소 짝꿍이라고 할 수 있습니다.  
사람들의 몸무게 목록  `weights`이 주어질 때, 시소 짝꿍이 몇 쌍 존재하는지 구하여 return 하도록 solution 함수를 완성해주세요.

### 제한 사항
-   2 ≤  `weights`의 길이 ≤ 100,000
-   100 ≤  `weights`[i] ≤ 1,000
    -   몸무게 단위는 N(뉴턴)으로 주어집니다.
    -   몸무게는 모두 정수입니다.

## 해결
값 범위가 배열 길이보다 작습니다. 따라서 값 출현 횟수를 카운팅하고 값 내용을 순회하는 것이 이득입니다.

카운팅 배열을 `X`로 정의합니다. 어떤 수 `a`, `b`가 있을 때, 다음 중 하나라도 만족하면 가능한 조합입니다. (`a` <= `b`)
```
1. a == b
2. a * 2 == b
3. a / 2 * 3 == b
4. a / 3 * 4 == b
```

- [2, 4]번 경우는 `a`, `b`가 서로 다른 수입니다. 이때 경우의 수는 `X[a] * X[b]`입니다.
- 1번 경우는 `a`, `b`가 같은 수입니다. 이때 경우의 수는 <sub>X[a]</sub>C<sub>2</sub>입니다.

`a`에 대해 100부터 1000까지 순회하고 경우의 수 총합을 반환하면 됩니다.

## 코드
```
#include <vector>
using namespace std;
typedef long long ll;
ll w[4001];

ll solution(vector<int> weights) {
    ll answer = 0;
    for(int i : weights)
        w[i]++;
    for(int i = 100; i <= 1000; i++) {
        if(w[i] > 1)
            answer += w[i] * (w[i] - 1) / 2;
        answer += w[i] * w[i * 2];
        if(i % 2 == 0)
            answer += w[i] * w[i / 2 * 3];
        if(i % 3 == 0)
            answer += w[i] * w[i / 3 * 4];
    }
    return answer;
}
```

## 링크
<br>https://school.programmers.co.kr/learn/courses/30/lessons/152996
{% endraw %}