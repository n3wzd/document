---
categories:
- Algorithm
date: '2022-07-26'
title: '[Algorithm] 완전 탐색'
---

{% raw %}
## 브루트 포스
모든 경우를 일일이 대입해서 문제를 해결하는 방법. 단순하지만, 100% 정확도를 보장한다.

장점이 명확한 만큼 단점도 명확한데, 바로 시간 복잡도가 대체로 크다는 점이다. 전체 경우의 수가 시간 복잡도로 직결되므로 O(N)은 기본이고, O(2<sup>N</sup>), O(N!)인 경우도 있다!

`백트래킹`은 재귀를 이용한 완전 탐색 방법이다. 따라서 브루트포스와 백트래킹은 본질적으로 다르지 않다.

## 접근
- 모든 경우를 시도하면 답을 알 수 있다. (ex. 최대, 최소, 경우의 수)
- 모든 경우를 확인하는 것보다 빠른 방법(수식, 알고리즘)이 없다.
- 입력의 범위가 대체로 작다.

## 시간 단축 테크닉?
완전 탐색을 사용해야 하지만, 입력의 크기가 애매하게 커서 오래 걸리는 경우가 있다.

이때는  확실하게 답이 안되는 경우(=오답인 경우)는 탐색하지 않아 시간을 단축할 수 있다. 즉, 일부 1개를 결정하면 답이 안되는 분기를 제외하며 1개의 확실한 전체 경우를 만들 수 있다.
> **일부가 결정되면 전체가 결정된다**<br>

- 일부 경우로 전체를 확정하기 위해 `그리디`, `이분 탐색` 등이 활용된다.
- 절반으로 나눠서 일부 경우를 구하고, 완전 탐색보다 빠른 방법으로 절반 경우로 전체 경우를 결정하는  `Meet In The Middle` 테크닉이 있다.

## 연관 문제
#### 일반
https://www.acmicpc.net/problem/7568
https://www.acmicpc.net/problem/1025
https://www.acmicpc.net/problem/14500
https://www.acmicpc.net/problem/2615

#### 테크닉 - 확실한 오답은 피하기
https://www.acmicpc.net/problem/9663
https://www.acmicpc.net/problem/14939
https://www.acmicpc.net/problem/1020

#### Meet In The Middle
`Meet In The Middle` 문서 참고

#### 답의 단서의 일부
https://www.acmicpc.net/problem/17472

## 참고
https://namu.wiki/w/%EB%B8%8C%EB%A3%A8%ED%8A%B8%20%ED%8F%AC%EC%8A%A4
{% endraw %}