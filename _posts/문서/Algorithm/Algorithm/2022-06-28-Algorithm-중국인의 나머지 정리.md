---
categories:
- Algorithm
date: '2022-06-28'
title: '[Algorithm] 중국인의 나머지 정리'
---

{% raw %}
## 중국인의 나머지 정리 (Chinese Remainder Theorem)
`중국인의 나머지 정리`는 연립 항동식의 해를 찾는 정리다. 아래는 연립 항동식 문제의 예시이다.
> 97로 나누었을 때 a가 남고, 1031로 나누었을 때 b이 남는 수는?<br>

a, b, p<sub>1</sub>, p<sub>2</sub>가 주어졌을 때 아래 연립 항동식을 만족하는 x를 찾아보자.
> x ≡ a mod p<sub>1</sub><br>
> x ≡ b mod p<sub>2</sub><br>

항동식은 다음과 같이 정리할 수 있다. A<sub>i</sub>는 i번 항동식의 해이며, p<sub>i</sub>로 나누어 떨어지지 않는다.
> A<sub>1</sub> + A<sub>2</sub> mod (p<sub>1</sub> × p<sub>2</sub>) <br>

p<sub>i</sub>로 나누어 떨어지지 않는다는 점에서 A<sub>i</sub>는 다음과 같은 식으로 바꿀 수 있다.
> p<sub>2</sub>v<sub>1</sub> + p<sub>1</sub>v<sub>2</sub> mod (p<sub>1</sub> × p<sub>2</sub>) <br>

이를 다시 원래 연립 합동식에 대입하면,
> x ≡ p<sub>2</sub>v<sub>1</sub> + p<sub>1</sub>v<sub>2</sub> mod p<sub>1</sub> ≡ p<sub>2</sub>v<sub>1</sub> mod p<sub>1</sub><br>
> x ≡ p<sub>2</sub>v<sub>1</sub> + p<sub>1</sub>v<sub>2</sub> mod p<sub>2</sub> ≡ p<sub>1</sub>v<sub>2</sub> mod p<sub>1</sub><br>

정리하면 x는 다음 수식으로 구할 수 있다. 모듈러 역원은 `페르마의 소정리`나 `확장 유클리드 호제법`으로 구할 수 있다.
> v<sub>1</sub> = p<sub>2</sub><sup>-1</sup> mod p<sub>1</sub><br>
> v<sub>2</sub> = p<sub>1</sub><sup>-1</sup> mod p<sub>2</sub><br>
> x = ((a × v<sub>1</sub> × p<sub>2</sub>) + (b × v<sub>2</sub> × p<sub>1</sub>)) mod (p<sub>1</sub> × p<sub>2</sub>)<br>

이 정리를 일반화한 수식은 다음과 같다.
> d<sub>i</sub> = p<sub>i</sub>를 제외한 모든 p의 곱<br>
> v<sub>i</sub> = d<sub>i</sub><sup>-1</sup> mod p<sub>i</sub><br>
> x = ∑ (a<sub>i</sub> × v<sub>i</sub> × d<sub>i</sub>) mod (p<sub>1</sub> × p<sub>2</sub> × ... × p<sub>n</sub>)<br>

## 코드
`BOJ - 15718 - 돌아온 떡파이어` 코드
```
#include <iostream>
using namespace std;
typedef long long ll;
ll cache1[100][100], cache2[1035][1035];
const ll p1 = 97, p2 = 1031, p3 = 97 * 1031;
ll ModAdd(ll a, ll b, ll p) { return ((a % p) + (b % p)) % p; }
ll ModMul(ll a, ll b, ll p) { return ((a % p) * (b % p)) % p; }

void DP() {
	for (int n = 0; n <= p1; n++) {
		cache1[n][0] = cache1[n][n] = 1;
		for (int r = 1; r < n; r++)
			cache1[n][r] = ModAdd(cache1[n - 1][r - 1], cache1[n - 1][r], p1);
	}
	for (int n = 0; n <= p2; n++) {
		cache2[n][0] = cache2[n][n] = 1;
		for (int r = 1; r < n; r++) 
			cache2[n][r] = ModAdd(cache2[n - 1][r - 1], cache2[n - 1][r], p2);
	}
}

ll GetC(ll n, ll r, ll p) {
	ll C = 1;
	while (n > 0) {
		if(p == p1)	C = ModMul(C, cache1[n % p][r % p], p);
		else C = ModMul(C, cache2[n % p][r % p], p);
		n /= p, r /= p;
	}
	return C;
}

ll GCD2(ll a, ll b, ll* x, ll* y) {
	if (a == 0) {
		*x = 0, * y = 1;
		return b;
	}
	ll x1, y1;
	ll gcd = GCD2(b % a, a, &x1, &y1);

	*x = y1 - (b / a) * x1;
	*y = x1;
	return gcd;
}

ll ModInv(ll a, ll p) {
	ll x, y;
	GCD2(a, p, &x, &y);
	while (x < 0) x += p;
	return x;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	ll Q, inv1, inv2;
	DP(); inv1 = ModInv(p1, p2), inv2 = ModInv(p2, p1);
	cin >> Q;
	while (Q--) {
		ll N, K, C1, C2;
		cin >> N >> K;
		if (N == 0 && K == 1) { cout << "1\n"; continue; }
		if (N + 1 < K || K == 1) { cout << "0\n"; continue; }
		N--, K -= 2;
		C1 = GetC(N, K, p1), C2 = GetC(N, K, p2);
		cout << ModAdd(ModMul(C2, ModMul(inv1, p1, p3), p3), ModMul(C1, ModMul(inv2, p2, p3), p3), p3) << "\n";
	}
	return 0;
}
```

## 연관 문제
<br>https://www.acmicpc.net/problem/15718

## 참고
<br>https://blog.joonas.io/23
{% endraw %}