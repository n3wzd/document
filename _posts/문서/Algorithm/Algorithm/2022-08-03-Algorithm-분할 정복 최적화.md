---
categories:
- Algorithm
date: '2022-08-03'
title: '[Algorithm] 분할 정복 최적화'
---

{% raw %}
## 분할 정복 최적화 (Divide and Conquer Optimization)
아래와 같은 함수가 있을 때,
> F(i, j) = min(A[i, j])<br>
> F(i, j) = max(A[i, j])<br>

모든 i, j 조합을 조사하는 방법은 O(N<sup>2</sup>) 시간이 걸린다. 하지만 `분할정복 최적화`을 적용하면 O(N log N)으로 최적화할 수 있다.

i를 고정했을 때 최적의 답이 될 수 있는 j를 opt[i]라고 하자. 다음 조건을 만족하면 분할정복 최적화를 적용할 수 있다.
> i<sub>1</sub> < i<sub>2</sub> → opt[i<sub>1</sub>] ≤ opt[i<sub>2</sub>]<br>

## 설계
예를 들어, i<sub>2</sub> = 4, opt[i<sub>2</sub>] = 5라고 하자. opt[i<sub>1</sub>]은 전제 조건에 따라 5보다 같거나 작다. 또한 i<sub>3</sub> = 6이라면 opt[i<sub>3</sub>]은 5보다 같거나 크다. 즉, opt[i<sub>1</sub>]을 찾으려면 [1, opt[i<sub>2</sub>]] 범위, opt[i<sub>3</sub>]는 [opt[i<sub>2</sub>], N] 범위에서 조사하면 된다.<br>
```
i    2  (4)    6
j  1 2 3 4 [5] 6 7 8
```
정리하면 현재 i를 조사해서 opt[i]를 찾았다면 현재 i와 opt[i]를 기준으로 탐색 범위를 분할해서 문제를 나눌 수 있다. => `분할 정복`을 통한 시간 단축<br>

```
[lo, hi] = i의 탐색 범위
[lo2, hi2] = j의 탐색 범위
res = 0 // 전체 최적값

void DC(ll lo, ll hi, ll lo2, ll hi2) {
	// 초항 판단
	if (lo > hi)<br>
		return;

	ll i = (lo + hi) / 2; // 현재 i = i의 탐색 범위의 중간값
	ll v = 0, v_idx = 0; // 각각 최적값과 opt[i]

	// opt[i] 구하기 => 현재 j의 구간에서 순차 탐색<br>
	for (int j = lo2; j <= hi2; j++) {
		// 최적값 판단
		if (F(i, j) > v && abs(j - i) <= D) {<br>
			v = F(i, j);
			v_idx = j;
		}
	}
	// 전체 최적값 업데이트
	res = max(res, v);

	// 현재 i, opt[i]를 기준으로 문제 분할
	DC(lo, i - 1, lo2, v_idx);
	DC(i + 1, hi, v_idx, hi2);
}
```

## 코드
`BOJ - 11001 - 김치` 코드
```
#include <iostream>
typedef long long ll;
using namespace std;
const int SIZE = 1e5 + 2;
ll N, D, T[SIZE], V[SIZE], res = 0;
ll F(ll i, ll j) { return (j - i) * T[j] + V[i]; }

void DC(ll lo, ll hi, ll lo2, ll hi2) {
	if (lo > hi)<br>
		return;
	ll i = (lo + hi) / 2;
	ll v = 0, v_idx = 0;

	for (int j = lo2; j <= hi2; j++) {
		if (F(i, j) > v && abs(j - i) <= D) {<br>
			v = F(i, j);
			v_idx = j;
		}
	}
	res = max(res, v);

	DC(lo, i - 1, lo2, v_idx);
	DC(i + 1, hi, v_idx, hi2);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> D;<br>
	for (int i = 0; i < N; i++)
		cin >> T[i];<br>
	for (int i = 0; i < N; i++)
		cin >> V[i];<br>
	DC(0, N - 1, 0, N - 1);
	cout << res;
	return 0;
}
```

## 연관 문제
https://www.acmicpc.net/problem/11001<br>
https://www.acmicpc.net/problem/13261<br>

## 참고
https://stonejjun.tistory.com/58<br>
https://seastar105.tistory.com/34<br>
{% endraw %}