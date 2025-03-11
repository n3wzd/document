---
categories:
- Algorithm
date: '2022-08-05'
title: '[Algorithm] Heavy Light Decomposition'
---

{% raw %}
## 트리 경로 쿼리?
정점 개수가 N, 쿼리 개수가 M일 때, 아래의 두 쿼리를 수행해보자.

-   `1 v w`: v번 정점의 가중치를 w로 바꾼다.
-   `2 u v`: u에서 v로 가는 단순 경로에 존재하는 정점들의 가중치 총합을 출력한다.

u부터 v까지 경로를 하나씩 탐색하는 방법은 O(MN) 시간이 걸린다는 문제가 있다. 하지만 `Heavy Light Decomposition`를 사용하면 O(M(log N)<sup>2</sup>) 시간으로 해결할 수 있다.

## Heavy Light Decomposition
`Heavy Light Decomposition(HLD)`은 트리 경로 쿼리를 빠르게 수행하는 테크닉이다. 트리의 경로를 선형 구간 여러 개로 분할하며, 각 선형 구간은 `세그먼트 트리`를 활용해서 O(log N) 시간으로 처리할 수 있다.

HLD에서는 간선을 **서브트리의 크기**를 기준으로 **무거운 간선(Heavy Edge)**, **가벼운 간선(Light Edge)** 으로 분류한다. (트리의 크기 = 루트를 포함한 정점의 개수)

부모 정점 u, 자식 정점 v, 간선 (u, v)가 있을 때,
> (v의 서브 트리 크기) ≥ (u의 서브 트리 크기) / 2<br>

위의 조건을 만족한다면 (u, v)는 Heavy Edge다. Heavy Edge는 부모 정점마다 1개씩만 가지고 있으며, 나머지 간선은 모두 Light Edge다. 위의 서브 트리 조건을 만족하는 간선이 여러 개 있다면 서브 트리가 가장 큰 것을 선택한다. 따라서 다음과 같이 정리할 수 있다.
> 어떤 정점에서 출발하는 Heavy Edge는 도착 정점을 루트로 하는 서브 트리의 크기가 가장 큰 간선이다. 나머지 간선은 모두 Light Edge다.<br>

HLD에서 **체인**은 다음과 같이 정의한다.
> 1. 인접한 Heavy Edge를 모두 연결한 경로<br>
> 2. Light Edge 1개로 구성된 경로<br>

```
ex.
         1
     2       3
   4   5
 6
 
위의 트리에서 체인은 3개다.
1-2-4-6
2-5
1-3
```
체인은 선형 구간으로 볼 수 있으며, `세그먼트 트리`를 적용할 수 있다.

## 설계
### 준비 작업
HLD에서 필요한 변수를 준비하자. (정점의 번호는 1부터 N까지 순차 번호가 매겨져 있다)
```
v = 현재 정점 번호
sz[v] = v를 루트로 하는 서브트리의 크기
depth[v] = v의 깊이 (루트의 깊이 = 0)
parent[v] = v의 부모 정점 번호
top[v] = v를 포함하는 체인에서 깊이가 가장 작은 정점의 번호
in[v] = v → 구간 id
in_inv[v] = 구간 id → v
vector<int> child[v] = v의 자식 정점 목록<br>
```

현재 child[v]만 값이 저장되어 있다고 하자. 나머지 변수를 설정하기 위해 총 2번의 `DFS`를 수행해야 한다.

우선, 1번째 DFS에서는 Heavy-Light Edge를 분류한다. 구현상 편의를 위해 Heavy Edge를 가장 앞에 배치하자.
```
// sz[v], depth[v], parent[v] 설정
void DFS1(int v = 1) {
	sz[v] = 1;
	for (auto& i : child[v]) {
		depth[i] = depth[v] + 1;
		parent[i] = v;
		DFS1(i);

		sz[v] += sz[i];
		// Heavy Edge와 연결된 자식을 child에서 가장 앞에 배치한다.
		if (sz[i] > sz[child[v][0]])<br>
			swap(i, child[v][0]);
	}
}
```

2번째 DFS에서는 체인을 설정한다.
```
// top[v], in[v], in_inv[v] 설정
id = 0; // 구간 id
void DFS2(int v = 1) {
	// 정점 번호와 구간 id를 매칭한다.
	in[v] = ++id;
	in_inv[id] = v;

	for (auto i : child[v]) {
		// top[v]을 설정한다.
		// 현재 정점이 Heavy Edge의 도착점이면 부모 노드의 top으로 설정
		// 그렇지 않으면 현재 정점으로 설정
		top[i] = (i == child[v][0]) ? top[v] : i;
		DFS2(i);
	}
}
```
※  `Euler Tour Technique`를 추가로 적용할 수 있다. 함수가 종료되는 시점에 out[v] = id 구문을 삽입하면 서브트리의 구간도 같이 기록할 수 있다.

### 쿼리 작업
HLD가 완료되었다면 이제 쿼리 연산을 처리해보자. 원본 트리와 별개로 동작하는 `세그먼트 트리`가 사용된다. 두 트리는 서로 다르므로, 원본 정점의 id와 세그먼트 트리의 구간 id는 구분된다.

#### 초기화
세그먼트 트리의 노드를 초기화한다.

#### 정점 쿼리 (a)
별도의 과정 없이 세그먼트 트리의 연산을 바로 사용하면 된다.
```
seg.Update(1, N, 1, in[a], value);
```

#### 경로 쿼리 (a, b)
경로에는 여러 개의 체인이 포함될 수 있다. 각 체인별로 세그먼트 트리의 구간 연산을 수행한 다음, 결과 값들을 취합하면 된다.

만약 정점 a, b가 같은 체인에 속한다면, 바로 세그먼트 트리의 구간 연산을 수행할 수 있다. 그렇지 않다면 a, b 중에서 깊이가 큰 것을 선택하고 해당 정점이 속한 체인을 대상으로 구간 연산을 수행한다. 그리고 이 체인의 top의 부모 정점으로 이동한다. 이 과정을 두 정점이 같은 체인에 속할 때까지 반복하면 된다. (`LCA` 구하기와 비슷하다)

※ 현재 세그먼트 트리는 구간 합을 저장하고 있다고 가정
```
// 경로 쿼리
int Query(int a, int b) {
	int res = 0; // 쿼리의 최종 결과

	// a, b가 같은 체인에 속하는지 확인
	while (top[a] != top[b]) {
		// 1. 깊이가 큰 정점 선택
		if (depth[top[a]] < depth[top[b]])
			swap(a, b);

		// 2. 선택한 체인을 대상으로 구간 연산 수행
		res += seg.Get(1, N, 1, in[top[a]], in[a]));
		
		// 3. 선택한 체인의 top의 부모 정점으로 이동
		a = parent[top[a]];
	}
	// 구간의 시작, 끝을 정렬하는 과정 (ex. [5, 3] → [3, 5])
	if (depth[a] > depth[b])<br>
		swap(a, b);
	
	// 같은 체인을 대상으로 구간 연산 수행
	res += seg.Get(1, N, 1, in[a], in[b]));

	// 최종 쿼리 결과 반환
	return res;
}
```

## 코드
`BOJ - 13510 - 트리와 쿼리 1` 코드
```
#include <iostream>
#include <vector>
using namespace std;
const int SIZE = 100002;
struct Edge { int dest, w, id; };
int N, M, id = 0, sz[SIZE], depth[SIZE], parent[SIZE];
int top[SIZE], in[SIZE], in_inv[SIZE], weight[SIZE], etov[SIZE];
vector<int> child[SIZE];<br>
vector<Edge> con[SIZE];<br>
bool visited[SIZE];

struct SegmentTree {
	int tree[SIZE * 4];
	int Init(int start, int end, int idx) {
		if (start == end) return tree[idx] = weight[in_inv[start]];
		int mid = (start + end) / 2;
		return tree[idx] = max(Init(start, mid, idx * 2), Init(mid + 1, end, idx * 2 + 1));
	}

	int Get(int start, int end, int idx, int left, int right) {
		if (start > right || end < left) return 0;<br>
		if (start >= left && end <= right) return tree[idx];
		int mid = (start + end) / 2;
		return max(Get(start, mid, idx * 2, left, right), Get(mid + 1, end, idx * 2 + 1, left, right));
	}

	int Update(int start, int end, int idx, int pos, int value) {
		if (start > pos || end < pos) return tree[idx];<br>
		if (start == end) return tree[idx] = value;
		int mid = (start + end) / 2;
		return tree[idx] = max(Update(start, mid, idx * 2, pos, value), Update(mid + 1, end, idx * 2 + 1, pos, value));
	}
} seg;

void DFS0(int v = 1) {
	visited[v] = 1;
	for (auto edge : con[v]) {
		int i = edge.dest;
		if (visited[i]) continue;
		visited[i] = 1;

		weight[i] = edge.w;
		etov[edge.id] = i;
		child[v].push_back(i);
		DFS0(i);
	}
}

void DFS1(int v = 1) {
	sz[v] = 1;
	for (auto& i : child[v]) {
		depth[i] = depth[v] + 1;
		parent[i] = v;
		DFS1(i);

		sz[v] += sz[i];
		if (sz[i] > sz[child[v][0]])<br>
			swap(i, child[v][0]);
	}
}

void DFS2(int v = 1) {
	in[v] = ++id;
	in_inv[id] = v;
	for (auto i : child[v]) {
		top[i] = (i == child[v][0]) ? top[v] : i;
		DFS2(i);
	}
}

void Update(int a, int d) {
	seg.Update(1, N, 1, in[etov[a]], d);
}

int Query(int a, int b) {
	int res = 0;
	while (top[a] != top[b]) {
		if (depth[top[a]] < depth[top[b]])
			swap(a, b);
		res = max(res, seg.Get(1, N, 1, in[top[a]], in[a]));
		a = parent[top[a]];
	}
	if (depth[a] > depth[b])<br>
		swap(a, b);
	res = max(res, seg.Get(1, N, 1, in[a] + 1, in[b]));
	return res;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;<br>
	for (int i = 1; i <= N - 1; i++) {
		int a, b, w;
		cin >> a >> b >> w;<br>
		con[a].push_back({ b, w, i });
		con[b].push_back({ a, w, i });
	}
	DFS0(); DFS1(); DFS2();
	seg.Init(1, N, 1);

	cin >> M;<br>
	while (M--) {
		int q, a, b;
		cin >> q >> a >> b;<br>
		if (q == 1)	Update(a, b);
		else cout << Query(a, b) << "\n";
	}
	return 0;
}
```

## 연관 문제
https://www.acmicpc.net/problem/13512
https://www.acmicpc.net/problem/13510
https://www.acmicpc.net/problem/2927
https://www.acmicpc.net/problem/17429

## 참고
https://justicehui.github.io/hard-algorithm/2020/01/24/hld/
{% endraw %}