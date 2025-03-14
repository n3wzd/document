---
categories:
- Algorithm
date: '2022-05-02'
title: '[Algorithm] Meet In The Middle'
---

{% raw %}
##  Meet In The Middle
`Meet In The Middle`은 범위를 절반으로 분할하고 탐색해서 유의미한 시간 이득을 얻는 접근 테크닉이다. 입력이 적당히 작아 모든 경우를 탐색하는 `완전탐색`을 사용할 수 있지만, 모두 탐색하기에는 시간이 오래 걸릴 때 사용된다.

완전 탐색을 사용했을 때 시간 복잡도가 O(2<sup>N</sup>)이라면 N이 증가할수록 시간 복잡도는 급격하게 증가한다. N이 30이라면 2<sup>30</sup>번 연산을 수행해야 한다. 만약 여기서 N을 절반으로 분할하고 나눠서 탐색한다면 2 × 2<sup>15</sup>번 연산을 수행하게 된다. 비록 시간 복잡도는 그대로지만, 30일 때보다 연산 횟수가 크게 줄어든 효과를 볼 수 있다.

단, 나눠서 탐색한 결과는 바로 답으로 이어지지 않으므로, 분할해서 구한 결과를 적절히 취합해서 최종 답을 얻어야 하는 과정을 거쳐야 한다.

### 사용 방법
1. `완전탐색`에서 시간 복잡도가 O(2<sup>N</sup>)같이 큰 경우면 `Meet In The Middle` 사용을 고려해본다.
2. 탐색 범위를 절반을 기점으로 분할하고, 나눠서 탐색한다.
	- 각각 경우를 탐색했을 때, 취합 과정에서 활용될 값을 집합(배열)에 저장한다.
3. 분할해서 구한 결과를 적절히 취합해서 최종 답을 구한다.
	- 분할된 범위에서 얻은 결과 집합이 각각 A, B일 때, A와 B가 같이 있는 경우를 고려한다.
	- A, B의 원소를 탐색해서 A와 B를 조합하는 경우를 구한다.
	- 선형 탐색을 할 수도 있지만, `정렬`과 `이분 탐색`을 사용하면 보다 빠르게 탐색할 수 있다. 한쪽 값을 알면, 다른 쪽의 값도 바로 정해질 때 사용할 수 있다.
	- ex. 가방의 최대 용량이 10이고 결과 집합은 계산하고 남는 가방 용량을 저장했을 때, 만약 A의 원소 a의 남은 가방 용량이 3이라면, a는 10-3 용량을 사용하였고, 7보다 같거나 큰 여유 공간이 필요하다. 따라서 B에서 7보다 같거나 큰 경우를 고려한다. `lower_bound`를 통해 B의 목표값 위치를 찾아서 수식을 통해 A, B가 조합된 경우의 수를 빠르게 구한다.

## 연관 문제
<br>https://www.acmicpc.net/problem/1450

## 참고
<br>https://www.geeksforgeeks.org/meet-in-the-middle/
<br>https://velog.io/@flaxinger/ALGO-Meet-In-The-Middle
<br>https://sesang06.tistory.com/185
{% endraw %}