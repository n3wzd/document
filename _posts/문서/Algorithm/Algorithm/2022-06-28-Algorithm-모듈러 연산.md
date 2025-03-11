---
categories:
- Algorithm
date: '2022-06-28'
title: '[Algorithm] 모듈러 연산'
---

{% raw %}
## 모듈러 연산 (Modular Arithmetic)
모듈러 연산은 두 정수의 나머지를 반환하는 연산이다.
> a % p = r<br>

r은 a의 값과 관계 없이 항상 p보다 작은 음이 아닌 정수다.

일반적으로 모듈러 연산은 다음 용도로 활용된다.
- 나머지 구하기
- 주기적인 연산
- 분배 법칙

## 분배 법칙
모듈러 연산의 분배 법칙은 덧셈, 곱셈에 대해서 성립한다. (뺄셈일 경우, 양수와 음수 둘 중 하나가 출력될 수 있다)
```
(A + B) % p = ((A % p) + (B % p)) % p
(A * B) % p = ((A % p) * (B % p)) % p
(A - B) % p = ((A % p) - (B % p)) % p
```
일반적으로 나눗셈에 대해선 성립하지 않는다. 하지만 모듈러 역원을 활용하면 나눗셈을 곱셈으로 치환해서 분배 법칙을 적용할 수 있다. (아래는 페르마의 소정리를 활용한 예시)
> (a / b) % p = (a * b<sup>p-2</sup>) % p<br>

일부 문제는 계산에 필요한 수가 충분히 커서 답의 나머지 값을 요구하는 경우가 있다. 이 경우는 최종 답을 포함해 계산 중간에 오버플로우가 발생할 수 있으므로, 중간 연산부터 나머지 연산을 적용해야 한다.

## 모듈러 역원 (Modular Inverse)
> a<sup>-1</sup> (mod  p)<br>

`모듈러 역원`은 역수에 대한 모듈러 연산이다. 모듈러 역원은 `페르마의 소정리`나 `확장 유클리드 호제법`으로 구할 수 있다.

## 페르마의 소정리 (Fermat's little Theorem)
페르마의 소정리는 다음과 같다.
> p가 소수이고 a가 p의 배수가 아니면, a<sup>p-1</sup>≡1 (mod  p) 이다.<br>
> =><br>
> a<sup>p-1</sup> % p = 1<br>

위의 정리에서 a를 양변에 나누면, a에 대한 역원의 나머지를 알 수 있다. 
> a<sup>p-2</sup>≡1/a (mod  p)<br>

a<sup>p-2</sup>는 `고속 거듭제곱 알고리즘`을 활용해서 빠르게 구할 수 있다.

페르마의 소정리를 적용하려면 성립 조건을 유의하자.
- p는 소수
- a는 p의 배수가 아님

###  코드
```
#include <iostream>
using namespace std;
typedef long long ll;
const int p = 100000007;

ll ModAdd(ll a, ll  b) {
	return ((a % p) + (b % p)) % p;
}

ll ModMul(ll a, ll b) {
	return ((a % p) * (b % p)) % p;
}

ll FastPow(ll a, ll power) {
	ll buf = 1;
	while (power > 1) {<br>
		if (power % 2 != 0) buf = ModMul(buf, a);
		a = ModMul(a, a);
		power /= 2;
	}
	return ModMul(a, buf);
}

ll ModDiv(ll a, ll b) {
	return ModMul(a, FastPow(b, p - 2));
}

int main() {
	ll a = 3579389945350;
	ll b = 50;

	cout << (a + b) % p << "\n";
	cout << ModAdd(a, b) << "\n\n";
	cout << (a * b) % p << "\n";
	cout << ModMul(a, b) << "\n\n";
	cout << (a / b) % p << "\n";
	cout << ModDiv(a, b) << "\n\n";
}
```

### 참고
https://velog.io/@gidskql6671/%EB%82%98%EB%A8%B8%EC%A7%80Modulo-%EC%97%B0%EC%82%B0-%EB%B6%84%EB%B0%B0%EB%B2%95%EC%B9%99

## 확장 유클리드 호제법
확장 유클리드 호제법을 사용하면 다음 수식에서 x, y, gcd(a, b)를 계산할 수 있다.
> ax + by = gcd(a, b)<br>

위의 식에서 a = a, b = p를 대입해보자. a와 p는 서로소이므로 gcd(a, b)는 1이다.
> ax + py = 1<br>

양쪽에 mod p를 적용하면,
> ax = 1<br>
> x = 1 / a<br>

x가 모듈러 역원임을 알 수 있다.

만약 알고리즘으로 계산된 x가 음수라면 양수가 될 때까지 b를 더해주면 된다.

### 코드
```
#include <iostream>
using namespace std;
typedef long long ll;

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
	ll a, p = 97;
	cin >> a;<br>
	cout << ModInv(a, p);
	return 0;
}
```

### 참고
https://www.crocus.co.kr/1232

## 연관 문제
**주기 연산**
https://www.acmicpc.net/problem/2477

**나눗셈 분배법칙**
https://www.acmicpc.net/problem/11401

**DP 상태 응용**
https://www.acmicpc.net/problem/1086
{% endraw %}