---
categories:
- Algorithm
date: '2022-07-16'
title: '[Algorithm] Convex Hull'
---

{% raw %}
## Convex Hull
2차원 평면에서 여러 점들이 있을 때, 모든 점을 포함하도록 몇몇 점을 선택해서 만든 볼록 다각형을 `Convex Hull(컨벡스 헐, 볼록 껍질)`이라고 한다. (볼록 다각형은 모든 내각이 180도 이하인 다각형을 의미한다)
```
   6    4
7           3
     5    2
  8         1
        0

> (0 1 3 4 6 7 8)을 연결하면 컨벡스 헐이 된다.<br>
```

일반적으로 `Graham's Scan 알고리즘`을 사용해서 컨벡스 헐을 생성한다. 이때 시간 복잡도는 O(N × logN)이다. (정렬의 시간 복잡도에 영향을 받는다)

## 설계
먼저 기준점을 잡는다. 일반적으로 다음 기준으로 선정한다.
> 1. y가 가장 작은 점<br>
> 2. y가 동일하면 x가 가장 작은 점<br>

기준점 B를 중심으로 모든 점을 반시계 방향으로 정렬한다. => `CCW` 사용 <br>
> 점 A<sub>1</sub>, B, A<sub>2</sub> 순서대로 CCW를 이었을 때,<br>
> 1. 시계 방향이면(CCW < 0) A<sub>1</sub>, A<sub>2</sub> 순서대로 정렬<br>
> 2. 반시계 방향이면(CCW > 0) A<sub>2</sub>, A<sub>1</sub> 순서대로 정렬<br>
> 3. 일직선이면(CCW == 0) B하고 거리가 가까운 순서대로 정렬<br>
```
> 정렬 이전<br>
   0    0
0           0
     0    0
  0         0
        B

> 정렬 이후<br>
   6    4
7           3
     5    2
  8         1
        B
```

그리고 `스택`을 사용해서 기준점부터 점들을 순차 탐색한다. 스택 상단 2개의 점과 현재 점을 이었을 때 CCW가 반시계 방향을 이뤄야 하며, 만약 시계 방향을 이루면 스택 상단의 점 1개를 제외한다. 최종적으로 스택에 들어있는 점들이 순서대로 컨벡스 헐을 구성한다.
```
Point P[N];
stack<int> stk;<br>

// 기준점과 1번 점을 스택에 추가한다.
stk.push(0);
stk.push(1);

for (int i = 2; i < N; i++) {
	// 스택에 2개의 점이 있으면 비교 가능
	while (stk.size() >= 2) {
		// 스택 상단 2개의 점과 현재 점을 비교한다.
		int a = stk.top(); stk.pop();
		int b = stk.top();

		// 반시계 방향(CCW > 0)을 구성하면 통과<br>
		// 그렇지 않으면 반시계 방향이 될 때까지 반복
		if (CCW(P[b], P[a], P[i]) == 1) {
			stk.push(a);
			break;
		}
	}
	// 현재 점을 스택에 추가한다.
	stk.push(i);
}
```

## 코드
`BOJ - 1708 - 볼록 껍질` 코드
```
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
typedef long long ll;
struct Point { ll x, y; };
int N;
Point P[100002];

int CCW(Point a, Point b, Point c) {
	ll D = (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
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
	cout << stk.size();
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;<br>
	for (int i = 0; i < N; i++)
		cin >> P[i].x >> P[i].y;<br>
	Convex();
	return 0;
}
```

## 관련 문제
https://www.acmicpc.net/problem/1708
https://www.acmicpc.net/problem/7420
https://www.acmicpc.net/problem/3878

## 참고
https://www.crocus.co.kr/1288
{% endraw %}