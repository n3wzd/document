---
categories:
- Algorithm
date: '2022-03-10'
title: '[Algorithm] 고속 거듭제곱 알고리즘'
---

{% raw %}
## 고속 거듭제곱 알고리즘
제곱 연산을 분할 정복 알고리즘을 적용하여 빠르게 계산하는 방법이다. 일일이 곱하면 O(N) 시간이 걸리지만, 이 방법을 사용하면 O(log N) 시간으로 단축할 수 있다.

## 설계
수를 N번 곱하는 것보다, 수를 제곱해서 N/2번 곱하는 것이 횟수 면에서 효율적이다.
```
(2, 8) 2 2 2 2 2 2 2 2
(4, 4) 4 4 4 4
(16, 2) 16 16
(256, 1) 256
= 256
```

여기서 홀수를 대처하기 위해 나머지를 저장하는 변수를 추가하자.
```
(2, 7) 2 2 2 2 2 2 2 -> buf *= 2<br>
(4, 3) 4 4 4 -> buf *= 4<br>
(16, 1) 16
= 16 * buf = 16 * 8 = 128
```

## 코드
```
#include <iostream>
using namespace std;

int a, b, buf = 1;

int main()
{
	cin >> a >> b;<br>

	while (b > 1)<br>
	{
		if (b % 2 != 0) buf *= a;
		a *= a;
		b /= 2;
	}

	cout << a * buf << endl;
	return 0;
}
```

## 연관 문제
https://www.acmicpc.net/problem/1629
https://www.acmicpc.net/problem/10830
{% endraw %}