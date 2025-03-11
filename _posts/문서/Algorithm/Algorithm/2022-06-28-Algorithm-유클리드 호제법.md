---
categories:
- Algorithm
date: '2022-06-28'
title: '[Algorithm] 유클리드 호제법'
---

{% raw %}
## 유클리드 호제법 (Euclidean Algorithm)
`유클리드 호제법`은 최대공약수(gcd)를 구하는 알고리즘이다. 두 자연수 a, b의 gcd는 다음 함수로 구할 수 있다.
```
gcd(a, b)
	if (a % b == 0) return b
	else return gcd(b, a % b)
```

ex. 78696, 19332의 최대공약수는 36이다.
>**78696** ＝ **19332**×4 ＋ 1368
>19332 ＝ 1368×14 ＋ 180
>1368 ＝ 180×7 ＋ 108
>180 ＝ 108×1 ＋ 72
>108 ＝ 72×1 ＋ 36
>72 ＝ **36**×2 ＋ 0

### 최소공배수
두 자연수 a, b의 최소공배수(lcm)는 최대공약수를 통해 구할 수 있다.
> lcm(a, b) × gcd(a, b) = a × b<br>

### 코드
```
#include <iostream>
using namespace std;

int gcd(int a, int b) {
	return (a % b == 0) ? b : gcd(b, a % b);
}

int main() {
	int n1, n2, res;
	cin >> n1 >> n2;<br>
	res = gcd(n1, n2);

	cout << res << "\n"; // gcd
	cout << n1 * n2 / res << "\n"; // lcm
	return 0;
}
```

### 연관 문제
https://www.acmicpc.net/problem/2609

### 참고
https://ko.wikipedia.org/wiki/%EC%B5%9C%EB%8C%80%EA%B3%B5%EC%95%BD%EC%88%98
https://ko.wikipedia.org/wiki/%EC%9C%A0%ED%81%B4%EB%A6%AC%EB%93%9C_%ED%98%B8%EC%A0%9C%EB%B2%95


## 확장 유클리드 호제법 (Extended Euclidean Algorithm)
> ax + by = c<br>

위 식에서 x, y가 정수해를 가지려면 c가 gcd(a, b)의 배수여야 한다는 사실이 알려져 있다.
> ax + by = gcd(a, b)<br>

`확장 유클리드 호제법`을 사용하면 gcd하고 x, y도 같이 구할 수 있다.
```
ex.
Input: a = 30, b = 20
Output: gcd = 10
        x = 1, y = -1
```

알고리즘으로 x, y를 구했으나 원하는 수가 아닐 수 있다. 이때는 원하는 수가 나올 때까지 x, y에 각각 b, a를 더하고 빼는 과정을 반복하면 된다.

예를 들어 x를 음수로 하고 싶다면 다음을 실행하면 된다.
```
while (x >= 0) 
	x -= b
	y += a
```

### 코드
`BOJ - 3955 - 캔디 분배` 코드
```
#include <iostream>
typedef long long ll;
using namespace std;

ll GCD2(ll a, ll b, ll* x, ll* y) {
	if (a == 0) {
		*x = 0, *y = 1;
		return b;
	}
	ll x1, y1;
	ll gcd = GCD2(b % a, a, &x1, &y1);

	*x = y1 - (b / a) * x1;
	*y = x1;
	return gcd;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int Q;
	cin >> Q;<br>
	while (Q--) {
		ll x, y, a, b;
		cin >> a >> b;<br>
		ll g = GCD2(a, b, &x, &y);
		while (x >= 0) {
			x -= b, y += a;
		}
		if (g == 1 && y <= 1e9) cout << y << "\n";
		else cout << "IMPOSSIBLE\n";
	}
	return 0;
}
```

### 연관 문제
https://www.acmicpc.net/problem/3955

### 참고
https://www.geeksforgeeks.org/euclidean-algorithms-basic-and-extended/
https://www.crocus.co.kr/1232
{% endraw %}