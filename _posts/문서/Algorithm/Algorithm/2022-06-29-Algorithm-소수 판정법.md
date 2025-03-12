---
categories:
- Algorithm
date: '2022-06-29'
title: '[Algorithm] 소수 판정법'
---

{% raw %}
## 약수 구하기
일반적으로 약수를 구하는 방법은 1부터 N까지 조사해 하나씩 나머지 연산으로 비교해서 판정한다. 하지만 시간 복잡도가 O(N)으로 오래 걸린다.

>30 - 2, 3, 5, 6, 10, 15

사실 모든 약수를 탐사하지 않고 개수의 절반까지만 조사해도 모든 약수를 알 수 있다. 예를 들어 5가 약수임을 알면, 30 / 5 = 6이므로 6 역시 약수로 판정할 수 있다. 약수에서 개수가 절반이 되는 순간은 N의 제곱근에 수렴한다. 따라서 sqrt(N)까지만 조사하면 된다.

시간 복잡도는 O(sqrt(N))이다.

## 소수 구하기
> 소수: 1보다 큰 자연수 중 1과 자기 자신만을 약수로 가지는 수<br>

약수 알고리즘과 비슷하다. 어떤 수 N을 판정하려면, 2부터 sqrt(N)까지 조사해서 약수가 없으면 소수라고 결정할 수 있다.

시간 복잡도는 O(sqrt(N))이다.

## 에라토스테네스의 체
여러 개의 수를 소수로 판정하는 경우에선 위의 소수 알고리즘으로는 O(N sqrt(N)) 시간이 걸린다. `에라토스테네스의 체`는 여러 수의 소수를 판정하는 알고리즘으로, 가장 보편적으로 사용되는 소수 판정법이다.
```
0. A = 2
1. A를 제외한 A의 배수들을 소수 후보군에서 제외한다.
2. A에 1을 더하고, A = sqrt(N)까지 과정 반복.
```

ex. 
> A = 2 -> **2** 3 <sub></sub>4<sub></sub> 5 <sub></sub>6<sub></sub> 7 <sub></sub>8<sub></sub> 9 <sub></sub>10<sub></sub> ...<br>
> A = 3 -> 2 **3** 5 7 <sub></sub>9<sub></sub> ...<br>
> ...<br>

마찬가지로 N의 제곱근까지만 조사해도 N이 소수라는 점이 보장된다.

시간 복잡도는 O(N log(logN))으로 나이브한 판정보다 빠르다.

### 코드
```
#include <iostream>
#include <cmath>
using namespace std;

bool prime[10002] = { 0, };

int main()
{
	int n;
	cin >> n;

	int sq = sqrt(n);
	for (int i = 2; i <= sq; i++)
	{
		int d = i * 2;
		while (d <= n)
		{
			prime[d] = 1;
			d += i;
		}
	}

	for (int i = 2; i <= n; i++) // 2부터 N까지 소수 판단 출력 (0이면 소수)
		cout << i << " -> " << prime[i] << endl;

	return 0;
}
```

### 연관 문제
<br>https://www.acmicpc.net/problem/1978
<br>https://www.acmicpc.net/problem/1929

### 참고
<br>https://continuous-development.tistory.com/204

## 밀러-라빈 소수 판정법 (Miller-Rabin Primality Test)
`밀러-라빈 소수 판정법`은 페르마 소수 판정법을 개선한 소수 판정법이다. 특정 큰 수 1개를 빠르게 판정할 때는 이 방법이 적합하다.

페르마 소수 판정법은 확률적으로 소수를 판정하는 방법이다. 먼저 `페르마의 소정리`를 살펴보자. 소수 p와 p의 배수가 아닌 수 대해 다음 식이 성립한다.
> a<sup>p-1</sup> ≡ 1 (mod p)<br>

역으로 a가 주어지고 위의 식을 만족한다면 p는 소수라고 볼 수 있을까? 그럴 가능성은 있지만 아닐 수도 있다. 소수가 아닌 수도 위의 식을 성립할 수 있기 때문이다.

간단히 요약하면, 가능한 많은 a를 시도해서 페르마의 소정리가 만족된다면 p는 소수일 확률이 높다고 볼 수 있다.

### 설계
이제 밀러-라빈 소수 판정법으로 x가 소수인지를 판정해보자.

만약 x가 2보다 큰 소수라면 x는 홀수일 것이다. 또한 x−1은 짝수이다. 짝수는 2의 거듭제곱을 약수로 가지므로 아래와 같은 수식으로 표현할 수 있다.
> x - 1 = 2<sup>s</sup> × d<br>

x를 알고 있다면 s와 d는 어렵지 않게 구할 수 있다.

적당한 a를 가정하고, 위의 수식을 페르마의 소정리에 대입하자.
> a<sup>x-1</sup> ≡ 1 (mod x)<br>
> a<sup>x-1</sup> - 1 ≡ 0 (mod x)<br>

(x<sup>2</sup> - 1) = (x + 1)(x - 1)을 활용해서 인수분해를 하면 다음과 같다.
> (a<sup>P1</sup> + 1)(a<sup>P2</sup> + 1) ... (a<sup>Ps</sup> + 1)(a<sup>Ps</sup> - 1) ≡ 0 (mod x) <br>
> P<sub>i</sub> = 2<sup>s-i</sup> × d<br>

페르마의 소정리를 만족하려면 위의 인수 중에서 하나라도 0이 되어야 한다. 즉, 모든 인수를 확인해서 0이 되는지를 판별하면 된다. 최종적으로 여러 번 a를 시도해서 페르마의 소정리가 만족된다면 x는 소수일 가능성이 높다고 볼 수 있다.

그러면 a는 어떤 수로 하는 것이 좋을까? 만약 x의 크기가 충분히 작다면, 다음의 a만 확인하면 소수가 확실하다는 사실이 증명되어 있다. 아래 범위를 참고하여 판정할 x의 최댓값에 따라 적당한 a를 선정하면 된다.
- x < 1,373,653 → a=2
- x < 9,080,191 → a=31,73
- x < 4,759,123,141 → a=2,7,61
- x < 2,152,302,898,747 → a=2,3,5,7,11
- x < 3,474,749,660,383 → a=2,3,5,7,11,13
- x < 341,550,071,728,321 → a=2,3,5,7,11,13,17

(출처 -  <br>https://ko.wikipedia.org/wiki/%EB%B0%80%EB%9F%AC-%EB%9D%BC%EB%B9%88_%EC%86%8C%EC%88%98%ED%8C%90%EB%B3%84%EB%B2%95)

```
> isPrime(x) // x가 소수이면 true<br>
1. d, s를 구한다.
2. a 목록에 따라 순차적으로 검사한다.
	1. x == a이면 true 반환 
	2, MillerRabin(x, a, d, s) 수행
		- 함수의 반환 값이 false면 false 반환
3. 모든 검사를 통과했다면 true 반환

> MillerRabin(x, a, d, s) // 페르마의 소정리 판단<br>
1. ad = pow(a, d)
2. if (ad == 1 || ad == x - 1) → true 반환
	- 인수 (2<sup>d + 1), (2</sup>d - 1)가 0인지 확인한다.
3. for (p = 1; p < s; p++) // 나머지 인수 확인
	1. ad *= ad
	2. if (ad == x - 1) → true 반환
4. 0이 되는 인수가 없으므로 false 반환
```
중간에 pow 거듭제곱 연산은 `고속 거듭제곱 알고리즘`을 활용하면 시간을 단축할 수 있다.

수가 충분히 커질 수 있으므로 중간에 모듈러 연산을 적용하는 것이 좋다. 위의 알고리즘은 합과 곱만 사용하므로 분배 법칙을 문제없이 적용할 수 있다.

### 코드
`BOJ - 5615 - 아파트 임대` 코드
```
#include <iostream>
using namespace std;
typedef unsigned long long ll;
ll ModAdd(ll a, ll b, ll mod) { return ((a % mod) + (b % mod)) % mod; }
ll ModMul(ll a, ll b, ll mod) {	return ((a % mod) * (b % mod)) % mod; }

ll FastPow(ll a, ll pw, ll mod) {
	ll buf = 1;
	while (pw > 1) {
		if (pw % 2 != 0) buf = ModMul(buf, a, mod);
		a = ModMul(a, a, mod); pw /= 2;
	}
	return ModMul(a, buf, mod);
}

bool MillerRabin(ll x, ll a, ll d, ll s) {
	ll ad = FastPow(a, d, x);
	if (ad == 1 || ad == x - 1) return 1;
	for (int p = 1; p < s; p++) {
		ad = ModMul(ad, ad, x);
		if (ad == x - 1) return 1;
	}
	return 0;
}

ll prime_sample[3] = { 2, 7, 61 };
bool isPrime(ll x) {
	ll d = x - 1, s = 0;
	while (d % 2 == 0) {
		d /= 2;	s++;
	}
	for (int i = 0; i < 3; i++) {
		ll a = prime_sample[i];
		if (x == a) return 1;
		if (!MillerRabin(x, a, d, s)) return 0;
	}
	return 1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, cnt = 0;
	cin >> N;
	while(N--) {
		ll x;
		cin >> x;
		if (isPrime(2 * x + 1)) cnt++;
	}
	cout << cnt;
	return 0;
}
```

### 연관 문제
<br>https://www.acmicpc.net/problem/5615

### 참고
<br>https://aruz.tistory.com/142
<br>https://rebro.kr/46
<br>https://ko.wikipedia.org/wiki/%EB%B0%80%EB%9F%AC-%EB%9D%BC%EB%B9%88_%EC%86%8C%EC%88%98%ED%8C%90%EB%B3%84%EB%B2%95
{% endraw %}