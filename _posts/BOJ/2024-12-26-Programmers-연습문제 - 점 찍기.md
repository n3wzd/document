---
categories:
- Programmers
date: '2024-12-26'
title: '[Programmers] 연습문제 - 점 찍기'
---

{% raw %}
> Lv. 2<br>

## 문제
좌표평면을 좋아하는 진수는 x축과 y축이 직교하는 2차원 좌표평면에 점을 찍으면서 놀고 있습니다. 진수는 두 양의 정수  `k`,  `d`가 주어질 때 다음과 같이 점을 찍으려 합니다.

-   원점(0, 0)으로부터 x축 방향으로  `a*k`(a = 0, 1, 2, 3 ...), y축 방향으로  `b*k`(b = 0, 1, 2, 3 ...)만큼 떨어진 위치에 점을 찍습니다.
-   원점과 거리가  `d`를 넘는 위치에는 점을 찍지 않습니다.

예를 들어,  `k`가 2,  `d`가 4인 경우에는 (0, 0), (0, 2), (0, 4), (2, 0), (2, 2), (4, 0) 위치에 점을 찍어 총 6개의 점을 찍습니다.

정수  `k`와 원점과의 거리를 나타내는 정수  `d`가 주어졌을 때, 점이 총 몇 개 찍히는지 return 하는 solution 함수를 완성하세요.

### 제한사항
-   1 ≤  `k`  ≤ 1,000,000
-   1 ≤  `d`  ≤ 1,000,000

## 해결
원 내부에 포함되는 1사분면과 축에 있는 점의 개수를 카운팅합니다. 축 하나를 순차 탐색해서 원의 외곽에 가장 가까운 위치를 찾으면 됩니다.
```
x축 순차 탐색:
1. 현재 위치 (x, y) 거리가 d보다 같거나 작을 때까지 반복:
	- y 감소 (k 단위)
2. 위치 개수 업데이트
```

※ 비슷한 문제: `Programmers - 연습문제 - 두 원 사이의 정수 쌍`

## 코드
```
using namespace std;
typedef long long ll;

ll solution(int k2, int d2) {
    ll k = k2, d = d2, answer = 0, y = (d / k) * k;
    for(ll x = 0; x <= d; x += k) {
        while(d * d < x * x + y * y)
            y -= k;
        answer += y / k + 1;
    }
    return answer;
}
```

## 링크
https://school.programmers.co.kr/learn/courses/30/lessons/140107
{% endraw %}