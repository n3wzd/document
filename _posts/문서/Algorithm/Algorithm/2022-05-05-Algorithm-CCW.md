---
categories:
- Algorithm
date: '2022-05-05'
title: '[Algorithm] CCW'
---

{% raw %}
## CCW
CCW(Counter Clockwise)는 좌표에서 점 3개의 선분 방향을 구하는 알고리즘이다. 점 3개 P1, P2, P3를 순서대로 선분을 이었을 때 반시계 방향, 시계 방향, 일직선 방향을 판별할 수 있다.

CCW는 벡터의 외적(cross product)을 사용한다. 두 벡터 u = (m1, m2, m3), v = (n1, n2, n3)를 외적하면 다음의 결과를 얻는다.
> u × v = (0, 0, m<sub>1</sub>n<sub>2</sub> − m<sub>2</sub>n<sub>1</sub>)<br>

위의 수식에서 D = m<sub>1</sub>n<sub>2</sub> − m<sub>2</sub>n<sub>1</sub>를 통해서 벡터 u, v의 시점을 일치시켰을 때 방향을 판별할 수 있다.<br>
- D > 0, 반시계 방향<br>
- D = 0, 일직선 방향
- D < 0, 시계 방향

만약 점 3개 P1, P2, P3 순서대로 제공된 경우, u = P2 - P1, v = P3 - P1으로 계산하면 된다.
```
CCW(P1, P2, P3)
	D = (P2.x - P1.x) * (P3.y - P1.y) - (P3.x - P1.x) * (P2.y - P1.y)
	if (D > 0) return 1		// 반시계 방향<br>
	if (D < 0) return -1	// 시계 방향
	if (D == 0) return 0	// 일직선 방향
```

## 코드
```
#include <iostream>
using namespace std;

typedef struct Point {
	int x, y;
} Point;

int CCW(Point a, Point b, Point c)
{
	int D = (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
	return (D == 0) ? 0 : ((D > 0) ? 1 : -1);<br>
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	Point a, b, c;
	cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;<br>
	cout << CCW(a, b, c);
	return 0;
}
```

## 관련 문제
https://www.acmicpc.net/problem/11758

## 참고
https://degurii.tistory.com/47#our_vector
{% endraw %}