---
categories:
- Algorithm
date: '2022-06-29'
title: '[Algorithm] Pollard-rho'
---

{% raw %}
## 폴라드-로 알고리즘 (Pollard-rho algorithm)
`폴라드-로 알고리즘`은 인수분해 알고리즘이다. 이름에서 rho는 그리스 문자 ρ의 명칭으로, 알고리즘에서 생성된 그래프의 모양이 ρ하고 비슷하게 생겨서 이름에 rho가 들어가게 되었다고 한다.

본래는 인수분해 알고리즘이지만 소인수분해로도 활용할 수 있다. 큰 수 소인수분해를 빠르게 계산할 때 사용된다.

시간 복잡도는 O(n^(1/4))이다.

### 설계
n을 소인수분해해보자.

우선, 임의의 다항함수 1개를 생성한다. 주로 아래의 함수가 쓰인다. (c = 랜덤 상수)
> f(x) = x<sup>2</sup> + c<br>

이 함수를 사용해서 다음 수열을 정의한다. (초기 x는 랜덤 상수이다)
> x, f(x), f(f(x)), ...<br>

n의 약수 p가 있다고 했을 때(아직 p의 값은 알 수 없다), 위의 수열을 p에 대해 모듈러 연산을 수행해보자. 그러면 해당 수열은 '비둘기 집의 원리'에 따라 어느 시점부터 같은 수가 반복되는 사이클이 발생하게 된다. (이 사이클에 속한 수의 개수는 p개 이하이다)

※ 비둘기 집의 원리는 간단하게 n개의 서로 다른 수가 있을 때 n+1번을 선택하면 반드시 1개는 중복된다는 원리를 의미한다.

위의 수열을 그래프로 표현하면 다음과 비슷하다. 실제로 ρ하고 비슷하게 생겼다.
![](images/Pollard_rho_cycle.png)

(그림 출처 - https://en.wikipedia.org/wiki/Pollard%27s_rho_algorithm)

모듈러 적용 이전 원래 수열에서 수 a, b가 있다고 하자. 만약 a, b가 ρ모양 그래프에서 같은 위치에 있다면 다음이 성립할 것이다.
> a ≡ b (mod p)<br>
> a - b ≡ 0 (mod p)<br>

n은 p의 약수이므로 abs(a - b)와 n는 모두 p를 공통 약수로 갖는다. 따라서 g = gcd(abs(a - b), n) 역시 n의 약수라고 볼 수 있다. (단, g ≠ 1, n)

만약 g가 1이면 a와 b는 ρ모양 그래프에서 같은 위치에 있지 않은 것이므로 그냥 넘어가면 된다. g가 n이면 원래 수열을 모두 탐색했으나 약수를 찾지 못한 경우로, 다항함수를 다시 랜덤으로 생성해야 한다. (c와 함수 초항의 값을 바꿔주면 된다)

g가 1과 n이 아니라고 했을 때, g는 n의 약수이지만 아직 소수임은 확실하지 않다. g가 소수인지 를 판정하자. 만약 소수가 맞다면 소인수분해 목록에 추가한다. 그렇지 않다면 g, n /g으로 분할해서 위의 탐색을 반복한다. => `분할 정복 알고리즘`<br>

마지막으로 a, b가 합동하는 순간(=나머지가 같은 순간)은 어떤 방법으로 찾을 수 있을까? 이는 `플로이드 사이클 판정 알고리즘`을 활용해서 탐색하면 해결할 수 있다. a를 1배속, b를 2배속으로 원래 수열을 탐색하게 하면 합동하는 순간을 판정할 수 있다.

### 플로이드 사이클 판정 알고리즘 (Floyd's Cycle Finding Algorithm)
`플로이드 사이클 판정 알고리즘`은 그래프의 사이클 여부를 판정하는 방법이다.

한 위치에 `투 포인터`를 배치하고 서로 다른 속도로 한 방향으로 움직이게 했을 때 두 포인터가 서로 만나는 순간이 있다면 사이클이 있다고 판정한다. 만약 느리게 움직이는 포인터가 모든 정점을 탐색했는데 두 포인터가 만나지 않았다면 사이클이 없다고 볼 수 있다.

이는 시계로 비유할 수 있다. 12시 위치에서 시침과 분침이 움직이면 약 1시 6분 정도에서 두 바늘이 만난다.

참고로 그래프 최단거리를 구하는 `플로이드-워셜 알고리즘(Floyd–Warshall algorithm)`하고는 관련이 없다.

### 구현
gcd를 구하는 것은 `유클리드 호제법`, 소수 판정법은 속도가 빠른 `밀러-라빈 소수판정법`을 주로 사용한다.

수가 충분히 크면 long long으로도 오버플로우가 발생할 수 있다. n에 대한 모듈러 연산을 적용해주자. (이때 모든 수는 n-1 이하이므로 계산에는 영향이 없다) 또한 곱하기 연산에는 128bit 자료형을 사용해야 한다.

랜덤 상수는 실제로 구현에서도 랜덤 수를 사용한다! 그래도 완전한 랜덤 수를 만들지 않아도 되기 때문에 C, C++일 경우 rand 함수를 사용하는 것으로도 충분하다.

알고리즘에서 랜덤이 사용되기 때문에 예외 케이스가 있을 수 있는데, 만약 랜덤의 범위가 충분하지 않다면 무한 루프를 돌 수 있다. 대표적으로 n = 4인 경우로, 아래 코드에서 2번째 if를 지우면 무한 루프를 돈다.
```
factors[] // 소수를 저장하는 vector
> Pollard(n) // n을 소인수분해한다.<br>
	if (n == 1) // 1이면 종료
		return
	if (n % 2 == 0) // n == 4에 대한 예외 처리
		factors.push_back(2)
		Pollard(n / 2)
		return
	if (isPrime(n)) // n에 대한 소수 판정
		factors.push_back(n) // 소수 목록에 추가
		return

	a, b, c, g = n
	auto f = [&](ll x) { return x * x + c } // 다항 함수 f(x)
	do {
		if (g == n) // g == n이면 함수 초기화
			a = b = rand() % (n - 2) // f(x)의 초항 할당
			c = rand() % 10 + 1 // 랜덤 상수 결정
			g = 1

		// 폴로이드 사이클 판정 알고리즘을 따라 a, b 이동
		a = f(a)
		b = f(f(b))
		g = GCD(max(a, b) - min(a, b), n) // gcd 구하기
	} while (g == 1) // g가 1이 아니면 탈출

	// 문제 분할
	Pollard(g)
	Pollard(n / g)
```

## 코드
`BOJ - 4149 - 큰 수 소인수분해` 코드
```
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;
typedef long long ll;
typedef __int128 int128;
ll ModAdd(ll a, ll b, ll mod) { return ((a % mod) + (b % mod)) % mod; }
ll ModMul(ll a, ll b, ll mod) {	return (((int128)a % mod) * ((int128)b % mod)) % mod; }
ll GCD(ll a, ll b) { return (a % b == 0) ? b : GCD(b, a % b); }

ll FastPow(ll a, ll pw, ll mod) {
	ll buf = 1;
	while (pw > 1) {<br>
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

ll prime_sample[12] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37 };
bool isPrime(ll x) {
	ll d = x - 1, s = 0;
	while (d % 2 == 0) {
		d /= 2;	s++;
	}
	for (int i = 0; i < 12; i++) {
		ll a = prime_sample[i];
		if (x == a) return 1;
		if (!MillerRabin(x, a, d, s)) return 0;
	}
	return 1;
}

vector<ll> factors;<br>
void Pollard(ll n) {
	if (n == 1) return;
	if (n % 2 == 0) {
		factors.push_back(2);
		Pollard(n / 2);
		return;
	}
	if (isPrime(n)) {
		factors.push_back(n);
		return;
	}
	ll a, b, c, g = n;
	auto f = [&](ll x) { return ModAdd(ModMul(x, x, n), c, n); };
	do {
		if (g == n) {
			a = b = rand() % (n - 2);
			c = rand() % 10 + 1;
			g = 1;
		}
		a = f(a);
		b = f(f(b));
		g = GCD(max(a, b) - min(a, b), n);
	} while (g == 1);
	Pollard(g);
	Pollard(n / g);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	ll N; cin >> N;<br>
	Pollard(N);
	sort(factors.begin(), factors.end());
	for (int i = 0; i < factors.size(); i++)
		cout << factors[i] << "\n";
	return 0;
}
```
※ Visual Studio에선 __int128를 지원하지 않는다. 대신 시간이 약간 더 오래걸리지만 unsigned long long으로 대체할 수 있다.

## 연관 문제
https://www.acmicpc.net/problem/4149

## 참고
https://blog.naver.com/PostView.nhn?blogId=jinhan814&logNo=222141831551&categoryNo=6&parentCategoryNo=6&viewDate=&currentPage=1&postListTopCurrentPage=1&from=postView
https://aruz.tistory.com/140
{% endraw %}