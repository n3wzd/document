---
categories:
- Algorithm
date: '2022-06-28'
title: '[Algorithm] Lucas Theorem'
---

{% raw %}
## 뤼카의 정리 (Lucas Theorem)
`뤼카의 정리`는 다음과 같다. (n, k = 정수, p = 소수)
> n = n<sub>m</sub>p<sup>m</sup> + n<sub>m-1</sub>p<sup>m-1</sup> + ... + n<sub>0</sub>p<sup>0</sup><br>
> k = k<sub>m</sub>p<sup>m</sup> + k<sub>m-1</sub>p<sup>m-1</sup> + ... + k<sub>0</sub>p<sup>0</sup><br>
> (n C k) (mod p) = (n<sub>m</sub> C k<sub>m</sub>) × (n<sub>m-1</sub> C k<sub>m-1</sub>) × ... (mod p)<br>

n과 k를 p진법으로 분리하고 각각에 대한 이항 계수를 구하면 원래 이항 계수를 알 수 있다.

뤼카의 정리를 활용하면 큰 이항 계수를 작은 이항 계수의 곱으로 분리할 수 있다. 단, 뤼카의 정리를 적용하려면 나누려는 수가 소수여야 한다는 점을 유의하자.

## 코드
`BOJ - 11402 - 이항 계수 4` 코드
```
#include <iostream>
using namespace std;
typedef long long ll;
ll cache[2002][2002];
ll N, K, M, C = 1;
ll ModAdd(ll a, ll b) { return ((a % M) + (b % M)) % M; }
ll ModMul(ll a, ll b) { return ((a % M) * (b % M)) % M; }

void DP() {
	for (int n = 0; n <= M; n++) {
		cache[n][0] = cache[n][n] = 1;
		for (int r = 1; r < n; r++)
			cache[n][r] = ModAdd(cache[n - 1][r - 1], cache[n - 1][r]);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K >> M; DP();
	while (N > 0) {
		C = ModMul(C, cache[N % M][K % M]);
		N /= M, K /= M;
	}
	cout << C;
	return 0;
}
```

## 연관 문제
<br>https://www.acmicpc.net/problem/11402
<br>https://www.acmicpc.net/problem/15718

## 참고
<br>https://bowbowbow.tistory.com/2
{% endraw %}