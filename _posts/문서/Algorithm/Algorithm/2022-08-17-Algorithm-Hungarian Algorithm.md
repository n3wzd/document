---
categories:
- Algorithm
date: '2022-08-17'
title: '[Algorithm] Hungarian Algorithm'
---

{% raw %}
## 최대 비용 매칭 문제
> N명의 사람과 N개의 일이 있다. 각 사람은 일을 1개만 담당해야 하고, 각 일을 담당하는 사람은 1명 이어야 한다. 또한, 모든 사람은 모든 일을 할 능력이 있다. 사람은 1번부터 N번까지 번호가 매겨져 있으며, 일도 1번부터 N번까지 번호가 매겨져 있다.<br>
> 
> D<sub>ij</sub>를 i번 사람이 j번 일을 할 때 필요한 비용이라고 했을 때, 모든 일을 하는데 필요한 비용의 최댓값은?<br>

모든 사람을 모든 일에 매칭하는 방법은 `브루트포스`를 사용하면 O(N!) 시간이 걸리며, `DP`를 동원하더라도 오래 걸린다. 하지만 `Hungarian` 알고리즘을 사용하면 O(N<sup>3</sup>)까지 시간을 단축할 수 있다.

## Hungarian Algorithm
`Hungarian` 알고리즘은 최대 비용으로 매칭을 수행하는 알고리즘이다.

알고리즘의 동작을 간략하게 정리하면 다음과 같다. (이 방법의 출력은 최소 비용이다)
```
매칭 대상: 크기가 N인 서로 분리된 집합 A, B
매칭 비용: 2차원 정방행렬 (N × N)
1. 모든 행에서 다음을 수행한다. => A[y]<br>
	- A[y] -= min(A[y])
2. 모든 열에서 다음을 수행한다. => B[x]<br>
	- B[x] -= min(B[x])
3. A, B를 연결하는 이분 그래프를 생성한다. 간선은 값이 0인 비용이다.
4. 해당 그래프에서 이분 매칭을 수행한다.
	- 최대 매칭이 N이면 < 탐색 종료 >
5. 해당 그래프에서 최소 정점 커버를 찾는다.
	- 찾은 정점 집합 = A, B에 대해 각각 A', B'
6. 행렬에서 A', B'가 커버하지 않는 영역에서 최소값 a를 구한다. (a는 항상 0보다 크다)
7. A'에 속하지 않는 행의 모든 원소에 a를 뺀다.
8. B'에 속하는 열의 모든 원소에 a를 더한다.
9. 3번 과정으로 이동한다.
```

### 예시
아래 예시에서 최소 비용을 찾아보자.
```
> 입력<br>
2 3 6 4
3 4 2 1
5 3 8 6
3 5 7 5

> [과정 1, 2] 수행 (양 옆의 라벨에 더한 값을 기록한다)<br>
0 1 3 2 | 2
2 3 0 0 | 1
2 0 4 3 | 3
0 2 3 2 | 3
---------
0 0 1 0

> 최대 매칭 = 3 (→ 매칭 실패)<br>
> 최소 정점 커버: X' = {1, 2}, Y' = {2}<br>
O O X X 
O O O O 
O O X X
O O X X
(O: 커버된 영역, X: 커버되지 않은 영역)
> 미커버 영역의 최소 = a = 2<br>

> [과정 7, 8] 수행<br>
0 1 1 0 | 4
4 5 0 0 | 1
2 0 2 1 | 5
0 2 1 0 | 5
---------
-2 -2 1 0

> 최대 매칭 = 4 (→ 매칭 완료)<br>
가능한 매칭 조합은 2가지이며, 최소 비용은 12다.
(4, 1) (3, 2) (2, 3) (4, 1) => 3 + 3 + 2 + 4 = 12<br>
or
(1, 1) (2, 3) (3, 2) (4, 4) => 2 + 3 + 2 + 5 = 12<br>
```

## 설계
실제 구현에선 다음 설계를 따른다. (이 방법의 출력은 최대 비용이다)
```
B = 이분 그래프
1. 관련 데이터를 초기화한다.
2. B에서 (최대 매칭 = N)이 될 때까지 다음을 반복
	1. alternating tree을 활용해서 B의 augmenting path를 찾는다.
		- 찾았다면 매칭 횟수 +1
	2. 찾지 못했다면 라벨을 업데이트하고 B의 augmenting path를 찾는다.
```

**< 용어 정리 >**
- matcing: 매칭에 속한 간선 = M
- free vertex: M에 연결되지 않은 정점
- alternating path: M과 M에 속하지 않은 간선이 교대로 연결된 경로
- alternating tree: 이분 그래프의 정점, alternating path의 간선으로 구성된 트리
- augmenting path: 경로의 시작과 끝이 모두 free vertex인 alternating path

ex. 다음과 같은 이분 그래프가 있을 때, (M = 색칠된 간선, free vertex = 색칠 안된 정점)
![](images/Hungarian_Algorithm_big1.png)

augmenting path 중 하나는 다음과 같다.
![](images/Hungarian_Algorithm_big2.png)

augmenting path에서 간선을 모두 뒤집으면 중복 매칭 없이 매칭 횟수가 +1이 된다는 중요한 성질을 가지고 있다. (간선을 뒤집는다는 것은 매칭 안된 간선을 매칭된 간선으로, 매칭된 간선을 매칭 안된 간선으로 전환하는 것을 의미한다)
![](images/Hungarian_Algorithm_big3.png)

헝가리안 알고리즘은 이 성질을 활용해서 전체 매칭 횟수를 1씩 늘린다.

### 초기화
필요한 변수를 생성하자.
```
int N; // 집합의 크기 (= X, Y의 길이)
int max_match; // 현재 최대 매칭
int cost[SIZE][SIZE]; // 비용 행렬
int lx[SIZE]; // X의 라벨 값
int ly[SIZE]; // Y의 라벨 값
int xy[SIZE]; // 매칭 간선 (입력 = x, 값 = y)
int yx[SIZE]; // 매칭 간선 (입력 = y, 값 = x)
bool S[SIZE]; // alternating tree의 X 정점 집합
bool T[SIZE]; // alternating tree의 Y 정점 집합 (T의 정점은 항상 매칭되어 있다)
int slack[SIZE]; // 최소 비용 차이를 저장 (입력 = y, 값 = 최소 비용 차이)
int slackx[SIZE]; // 최소 비용 차이의 x 위치 (입력 = y, 값 = x)
int prevX[SIZE]; // augmenting path에서 이전 x (입력 = x, 값 = 이전 x)
```

헝가리안 알고리즘에서 사용되는 이분 그래프는 equality graph이다. equality graph은 cost[x][y] = l[x] + l[y]을 만족하는 간선으로 구성된 그래프를 의미한다. (= 0인 비용을 이분 그래프의 간선으로 한다)

slack은 다음 값을 저장한다. (단, x ∈ S)
> slack[y] = min(lx[x] + ly[y] − cost[x][y])<br>


우선, 알고리즘 실행 이전에 변수를 초기화한다.
```
int Hungarian() {
	max_match = 0;
	memset(xy, -1, sizeof(xy)); // xy, yx에서 매칭이 없으면 -1 값으로 초기화
	memset(yx, -1, sizeof(yx));
	
	memset(lx, 0, sizeof(lx));
	for (int x = 0; x < N; x++)
		for (int y = 0; y < N; y++)
			lx[x] = max(lx[x], cost[x][y]); // lx의 초기값은 현재 x에서 최대 비용
	memset(ly, 0, sizeof(ly)); // ly의 초기값은 0

	Augment();
	...
}
```


### augmenting path
다음으로 헝가리안 알고리즘의 메인 사이클을 구현해보자.
```
void Augment() {
	// 현재 최대 매칭이 N이면 종료
	if (max_match == N)
		return;

	// 탐색 변수 초기화
	int x, y, root = 0;
	queue<int> q;<br>

	// alternating tree 초기화
	memset(S, 0, sizeof(S));
	memset(T, 0, sizeof(T));
	memset(prevX, -1, sizeof(prevX));

	// S의 첫번째 원소를 구한다.
	for (x = 0; x < N; x++) {
		// X에서 임의의 free vertex 1개를 선택한다.
		if (xy[x] == -1) {
			q.push(x);
			root = x;
			prevX[x] = -2;
			S[x] = 1;
			break;
		}
	}

	// slack 초기화
	for (y = 0; y < N; y++) {
		slack[y] = lx[root] + ly[y] - cost[root][y];
		slackx[y] = root;
	}
	...
```

alternating tree을 활용해서 augmenting path 1개를 찾는다.
```
	...
	// augmenting path를 찾을 때까지 반복
	while (1) {
		// BFS로 현재 alternating tree를 탐색한다.
		while (!q.empty()) {
			x = q.front(); q.pop();
			for (y = 0; y < N; y++) {
				// 이분 그래프 간선을 통해 T에 속하지 않는 y 탐색
				if (cost[x][y] == lx[x] + ly[y] && !T[y]) {
					// 해당 y가 free vertex면 augmenting path 찾기 성공
					if (yx[y] == -1)
						break;

					// 해당 y가 free vertex가 아니면 y를 T에 추가
					T[y] = 1;
					q.push(yx[y]);
					AddTree(yx[y], x);
				}
			}
			// augmenting path를 찾았다면 즉시 탈출
			if (y < N)
				break;
		}
		if (y < N)
			break;
		...
```

중간에 활용되는 함수들을 살펴보자.
```
// y를 대상으로 alternating tree의 간선을 추가한다.
// x = alternating path에서 y의 다음 정점, lastX = y의 이전 정점
void AddTree(int x, int lastX) {
	S[x] = 1;
	prevX[x] = lastX;

	// x에 대해 slack 업데이트
	for (int y = 0; y < N; y++) {
		if (lx[x] + ly[y] - cost[x][y] < slack[y]) {
			slack[y] = lx[x] + ly[y] - cost[x][y];
			slackx[y] = x;
		}
	}
}
```

### 라벨 업데이트
>  x ∈ S, y ∈ Y - T일때,  <br>
>  a = min(lx[x] + ly[y] - cost[x][y])<br>
>  lx[x] -= a<br>
>  ly[y] += a<br>

```
// 라벨 업데이트 수행
void LabelUpdate() {
	int x, y;
	int a = INF;
	
	// slack을 활용해서 a를 빠르게 구할 수 있다.
	for (y = 0; y < N; y++)
		if (!T[y])
			a = min(a, slack[y]);

	// a에 대해 라벨, slack 업데이트
	for (x = 0; x < N; x++)
		if (S[x])
			lx[x] -= a;
	for (y = 0; y < N; y++)
		if (T[y])
			ly[y] += a;
	for (y = 0; y < N; y++)
		if (!T[y])
			slack[y] -= a;
}
```

다시 메인 사이클로 돌아오면,
```
		...
		// augmenting path를 찾지 못했다면 이하 코드를 수행한다.
		LabelUpdate();

		// augmenting path 재탐색 (이전 augmenting path 탐색과 유사하다)
		q = queue<int>();
		for (y = 0; y < N; y++) {
			if (!T[y] && slack[y] == 0) {
				if (yx[y] == -1) {
					x = slackx[y];
					break;
				}
				else {
					T[y] = 1;
					if (!S[yx[y]]) {
						q.push(yx[y]);
						AddTree(yx[y], slackx[y]);
					}
				}
			}
		}
		if (y < N) break;
	}

	// augmenting path 1개를 찾았다면 해당 path를 뒤집는다.
	if (y < N) {
		// 매칭 횟수 +1
		max_match++;
		for (int cx = x, cy = y, ty; cx != -2; cx = prevX[cx], cy = ty) {
			ty = xy[cx];
			yx[cy] = cx;
			xy[cx] = cy;
		}

		// 메인 사이클 반복
		Augment();
	}
}
```

### 출력
매칭이 종료되었다면 최종 비용을 합산한다.
```
int Hungarian() {
	...
	Augment();
	int ret = 0; // 최종 비용
	for (int x = 0; x < N; x++)
		ret += cost[x][xy[x]];
	return ret;
}
```
최종 결과는 매칭의 최대 비용이다. (매칭의 최소 비용을 출력하려면 입력 비용을 음수로 하면 된다)

총 시간 복잡도는 O(N<sup>3</sup>)이다.

## 코드
`BOJ - 14216 - 할 일 정하기 2` 코드
```
#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;
const int SIZE = 502, INF = 1 << 30;
int N, max_match;
int cost[SIZE][SIZE];
int lx[SIZE], ly[SIZE];
int xy[SIZE], yx[SIZE];
bool S[SIZE], T[SIZE];
int slack[SIZE], slackx[SIZE];
int prevX[SIZE];

void LabelUpdate() {
	int x, y;
	int a = INF;
	for (y = 0; y < N; y++)
		if (!T[y])
			a = min(a, slack[y]);
	for (x = 0; x < N; x++)
		if (S[x])
			lx[x] -= a;
	for (y = 0; y < N; y++)
		if (T[y])
			ly[y] += a;
	for (y = 0; y < N; y++)
		if (!T[y])
			slack[y] -= a;
}

void AddTree(int x, int lastX) {
	S[x] = 1;
	prevX[x] = lastX;
	for (int y = 0; y < N; y++) {
		if (lx[x] + ly[y] - cost[x][y] < slack[y]) {
			slack[y] = lx[x] + ly[y] - cost[x][y];
			slackx[y] = x;
		}
	}
}

void Augment() {
	if (max_match == N) return;
	int x, y, root = 0;
	queue<int> q;<br>

	memset(S, 0, sizeof(S));
	memset(T, 0, sizeof(T));
	memset(prevX, -1, sizeof(prevX));

	for (x = 0; x < N; x++) {
		if (xy[x] == -1) {
			q.push(x);
			root = x;
			prevX[x] = -2;
			S[x] = 1;
			break;
		}
	}

	for (y = 0; y < N; y++) {
		slack[y] = lx[root] + ly[y] - cost[root][y];
		slackx[y] = root;
	}

	while (1) {
		while (!q.empty()) {
			x = q.front(); q.pop();
			for (y = 0; y < N; y++) {
				if (cost[x][y] == lx[x] + ly[y] && !T[y]) {
					if (yx[y] == -1) break;
					T[y] = 1;
					q.push(yx[y]);
					AddTree(yx[y], x);
				}
			}
			if (y < N) break;
		}
		if (y < N) break;

		LabelUpdate();
		q = queue<int>();
		for (y = 0; y < N; y++) {
			if (!T[y] && slack[y] == 0) {
				if (yx[y] == -1) {
					x = slackx[y];
					break;
				}
				else {
					T[y] = 1;
					if (!S[yx[y]]) {
						q.push(yx[y]);
						AddTree(yx[y], slackx[y]);
					}
				}
			}
		}
		if (y < N) break;
	}

	if (y < N) {
		max_match++;
		for (int cx = x, cy = y, ty; cx != -2; cx = prevX[cx], cy = ty) {
			ty = xy[cx];
			yx[cy] = cx;
			xy[cx] = cy;
		}
		Augment();
	}
}

int Hungarian() {
	int ret = 0;
	max_match = 0;
	memset(xy, -1, sizeof(xy));
	memset(yx, -1, sizeof(yx));
	memset(lx, 0, sizeof(lx));
	memset(ly, 0, sizeof(ly));
	for (int x = 0; x < N; x++)
		for (int y = 0; y < N; y++)
			lx[x] = max(lx[x], cost[x][y]);

	Augment();
	for (int x = 0; x < N; x++)
		ret += cost[x][xy[x]];
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;<br>
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> cost[y][x];<br>
			cost[y][x] = -cost[y][x];
		}
	}
	cout << -Hungarian() << "\n";
	return 0;
}
```

## 연관 문제
https://www.acmicpc.net/problem/14216<br>

## 참고
https://www.geeksforgeeks.org/hungarian-algorithm-assignment-problem-set-1-introduction/<br>
https://gazelle-and-cs.tistory.com/29<br>
http://www.secmem.org/blog/2021/04/18/hungarian-algorithm/<br>
https://kibbomi.tistory.com/141<br>
{% endraw %}