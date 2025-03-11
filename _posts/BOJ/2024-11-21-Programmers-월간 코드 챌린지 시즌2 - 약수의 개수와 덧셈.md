---
categories:
- Programmers
date: '2024-11-21'
title: '[Programmers] 월간 코드 챌린지 시즌2 - 약수의 개수와 덧셈'
---

{% raw %}
> Lv. 1<br>

## 문제
두 정수  `left`와  `right`가 매개변수로 주어집니다.  `left`부터  `right`까지의 모든 수들 중에서, 약수의 개수가 짝수인 수는 더하고, 약수의 개수가 홀수인 수는 뺀 수를 return 하도록 solution 함수를 완성해주세요.

### 제한사항
-   1 ≤  `left`  ≤  `right`  ≤ 1,000

## 해결
구간 내 정수들의 각 약수 개수를 구하면 됩니다. 입력이 작으므로 `O(n)` 시간으로 판별해도 통과합니다.

## 코드
```
#include <cmath>
using namespace std;

int find(int n) {
    int cnt = 0;
    for(int i = 1; i <= n; i++)
        if(n % i == 0)
            cnt++;
    return cnt;
}

int solution(int left, int right) {
    int answer = 0;
    for(int n = left; n <= right; n++)
        answer += find(n) % 2 == 0 ? n : -n;
    return answer;
}
```

## 링크
https://school.programmers.co.kr/learn/courses/30/lessons/77884
{% endraw %}