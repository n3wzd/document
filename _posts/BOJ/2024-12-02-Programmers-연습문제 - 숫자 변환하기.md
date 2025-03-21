---
categories:
- Programmers
date: '2024-12-02'
title: '[Programmers] 연습문제 - 숫자 변환하기'
---

{% raw %}
> Lv. 2<br>

## 문제
자연수  `x`를  `y`로 변환하려고 합니다. 사용할 수 있는 연산은 다음과 같습니다.
-   `x`에  `n`을 더합니다
-   `x`에 2를 곱합니다.
-   `x`에 3을 곱합니다.

자연수  `x`,  `y`,  `n`이 매개변수로 주어질 때,  `x`를  `y`로 변환하기 위해 필요한 최소 연산 횟수를 return하도록 solution 함수를 완성해주세요. 이때  `x`를  `y`로 만들 수 없다면 -1을 return 해주세요.

### 제한사항
-   1 ≤ `x`  ≤  `y` ≤ 1,000,000
-   1 ≤  `n`  <  `y`

## 해결
적절히 위치를 옮겨서 최단 횟수로 이동해야 합니다. => `최단거리 BFS`

수직선에서 현재 위치(`c`)를 정점으로 정의합니다. 다음 정점은 `c + n`, `c * 2`, `c * 3`입니다.

※ `BOJ - 1697- 숨바꼭질`과 유사한 문제입니다.

## 코드
```
#include <vector>
#include <queue>
using namespace std;
int V[1000001];

int solution(int x, int y, int n) {
    queue<int> q;
    q.push(x); V[x] = 1;
    while(!q.empty()) {
        int c = q.front(); q.pop();
        if(c == y)
            return V[c] - 1;
        int d[] = { c + n, c * 2, c * 3 };
        for(int i = 0; i < 3; i++) {
            if(d[i] <= y && V[d[i]] == 0) {
                q.push(d[i]);
                V[d[i]] = V[c] + 1;
            }
        }
    }
    return -1;
}
```

## 링크
<br>https://school.programmers.co.kr/learn/courses/30/lessons/154538
{% endraw %}