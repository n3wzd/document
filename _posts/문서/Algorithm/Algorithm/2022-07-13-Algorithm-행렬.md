---
categories:
- Algorithm
date: '2022-07-13'
title: '[Algorithm] 행렬'
---

{% raw %}
## 행렬
선형방정식을 행렬로 변환하면 행렬에 적용되는 여러 공식을 통해서 더 효율적인 계산을 할 수 있다.

## 행렬 제곱
점화식을 행렬로 변환하면 행렬의 제곱 형태로 표현되는 경우가 있다. 행렬의 곱셈은 `고속 거듭제곱 알고리즘`을 적용해서 빠르게 계산할 수 있으며, 시간 복잡도를 기존 O(N)에서 O(log N)으로 단축할 수 있다.

O(log N) 행렬 곱셈에 대한 구현은 `BOJ - 10830 - 행렬 제곱`을 참고하자. (https://www.acmicpc.net/problem/10830)

## 관련 문제
https://www.acmicpc.net/problem/11444
https://www.acmicpc.net/problem/13976

## 참고
https://st-lab.tistory.com/252
https://web.media.mit.edu/~holbrow/post/calculating-fibonacci-numbers-with-matrices-and-linear-algebra/
{% endraw %}