---
categories:
- Algorithm
date: '2022-07-17'
title: '[Algorithm] Rotating Calipers'
---

{% raw %}
## Rotating Calipers
`Rotating Calipers`는 `Convex Hull`의 최대 지름을 구하는 알고리즘이다. 컨벡스 헐의 최대 지름은 컨벡스 헐을 구성하는 점에서 최대 거리를 의미한다.

최대 거리를 완전 탐색으로 찾으면 O(N<sup>2</sup>) 시간이 걸리지만 회전하는 캘리퍼스를 활용하면 O(N)으로 줄일 수 있다.

주로 여러 점에서 최대 거리를 찾을 때 컨벡스 헐 + 회전하는 캘리버스를 활용된다.

## 설계
캘리퍼스는 물체를 집게로 잡고 지름을 측정하는 도구다. 이 알고리즘의 동작도 현실 캘리퍼스와 유사하다.

먼저 컨벡스 헐을 구한 다음, x좌표가 가장 작은 점과 큰 점을 찾는다. (캘리퍼스를 수직으로 세운 것과 같다)
```
|             |
|   6     4   |
|7           3|
|             |
|  8        1 |
|        0    |

> 점 3, 7에서 시작<br>
```

모든 점들은 반시계 방향 순서대로 나열되어 있다고 하자. 캘리퍼스와 맞닿은 점을 P<sub>A</sub>라고 했을 때, 선분 P<sub>A</sub>P<sub>A+1</sub>하고 캘리퍼스가 이루는 각도를 비교한다. 이때 각도가 작은 쪽을 따라 캘리퍼스를 회전시킨다. (회전 이후의 캘리퍼스는 P<sub>A</sub>P<sub>A+1</sub>의 방향과 평행하다) 이 과정을 총 N번 반복하면 최대 지름을 찾을 수 있다. (N = 컨벡스 헐을 구성하는 점의 개수)

각도 구하기는 실수 사용 없이 `CCW`으로 찾을 수 있다. 현재 두 점이 P<sub>A</sub>, P<sub>B</sub>일 때, 벡터 P<sub>A</sub>P<sub>A+1</sub>와 P<sub>B+1</sub>P<sub>B</sub>를 원점 O로 옮겨 보자.
```
> 위의 예시에서 PA = 7, PB = 3이라고 했을 때,<br>
O
   B
  A
```
A, O, B 순서대로 CCW를 구했을 때 양수가 출력되면(= 반시계 방향이면) B쪽의 캘리퍼스 각도가 더 작다고 볼 수 있다. 위의 예시에선 시계 방향이므로 A쪽의 각도가 더 작다.
```
double Calipers() {
	double maxDist = 0;
	int p1 = minpx, p2 = maxpx;

	// N번 탐색
	for (int i = 0; i < cvx_N; i++) {
		// 1. 현재 두 점의 거리 구하기
		maxDist = max(maxDist, Distance(P[cvx[p1]], P[cvx[p2]]));

		// 2. 캘리퍼스 각도 비교
		if (CCW({ P[cvx[(p1 + 1) % cvx_N]] - P[cvx[p1]] }, { 0, 0 }, P[cvx[p2]] - P[cvx[(p2 + 1) % cvx_N]]) > 0)<br>
			p2 = (p2 + 1) % cvx_N;
		else
			p1 = (p1 + 1) % cvx_N;
	}
	return maxDist;
}
```

## 코드
`9240 - 로버트 후드` 코드
```
#include <iostream>
#include <algorithm>
#include <stack>
#include <cmath>
using namespace std;
const int SIZE = 100002;
struct Point { int x, y; };
Point operator-(Point a, Point b) { return { a.x - b.x, a.y - b.y }; }
int N, cvx[SIZE], cvx_N, minpx, maxpx;
Point P[SIZE];
double Distance(Point a, Point b) { return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2)); }

int CCW(Point a, Point b, Point c) {
	int D = (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
	return (D == 0) ? 0 : ((D > 0) ? 1 : -1);<br>
}

bool cmp1(Point a, Point b) {
	return (a.y != b.y) ? a.y < b.y : a.x < b.x;
}

bool cmp2(Point a, Point b) {
	int D = CCW(a, P[0], b);
	if (D == 1) return 0;
	else if (D == -1) return 1;
	else return (a.y != b.y) ? a.y < b.y : a.x < b.x;
}

void Convex() {
	sort(P, P + N, cmp1);
	sort(P + 1, P + N, cmp2);

	stack<int> stk;<br>
	stk.push(0);
	stk.push(1);
	for (int i = 2; i < N; i++) {
		while (stk.size() >= 2) {
			int a = stk.top(); stk.pop();
			int b = stk.top();
			if (CCW(P[b], P[a], P[i]) == 1) {
				stk.push(a);
				break;
			}
		}
		stk.push(i);
	}

	cvx_N = stk.size();
	int minX = 1000, maxX = -1000;
	for (int i = cvx_N - 1; i >= 0; i--) {
		cvx[i] = stk.top(); stk.pop();
		if (minX > P[cvx[i]].x) {<br>
			minX = P[cvx[i]].x;
			minpx = i;
		}
		if (maxX < P[cvx[i]].x) {
			maxX = P[cvx[i]].x;
			maxpx = i;
		}
	}
}

double Calipers() {
	double maxDist = 0;
	int p1 = minpx, p2 = maxpx;
	for (int i = 0; i < cvx_N; i++) {
		maxDist = max(maxDist, Distance(P[cvx[p1]], P[cvx[p2]]));
		if (CCW({ P[cvx[(p1 + 1) % cvx_N]] - P[cvx[p1]] }, { 0, 0 }, P[cvx[p2]] - P[cvx[(p2 + 1) % cvx_N]]) > 0)<br>
			p2 = (p2 + 1) % cvx_N;
		else
			p1 = (p1 + 1) % cvx_N;
	}
	return maxDist;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cout << fixed; cout.precision(8);
	cin >> N;<br>
	for (int i = 0; i < N; i++)
		cin >> P[i].x >> P[i].y;<br>
	Convex();
	cout << Calipers();
	return 0;
}
```

## 관련 문제
https://www.acmicpc.net/problem/9240
https://www.acmicpc.net/problem/10254

## 참고
https://aruz.tistory.com/59
{% endraw %}