---
categories:
- Algorithm
date: '2022-08-16'
title: '[Algorithm] Centroid Decomposition'
---

{% raw %}
## Centroid Decomposition
`센트로이드(Centroid)`는 직역하면 무게중심이다. 트리에서 센트로이드는 다음과 같이 정의된다.

> 현재 트리 T에서 어떠한 정점 v를 삭제했을 때, 나뉜 서브트리들의 크기(=정점의 개수)의 최댓값이 T의 정점 개수 N의 절반과 같거나 작다면 v는 T의 `센트로이드`다.<br>

모든 트리는 최소한 1개의 센트로이드를 가지고 있음이 보장된다.

`센트로이드 분할`은 현재 트리의 센트로이드를 기점으로 서브트리를 나누는 재귀적인 과정이다. 센트로이드 분할을 통해 트리에서 `분할정복`을 수행할 수 있다. => 빠른 계산 가능<br>

## 설계
### 센트로이드 분할
센트로이드 분할에서 필요한 변수를 준비하자.
```
v = 현재 정점 번호
sz[v] = v를 루트로 하는 서브트리의 크기
vector<int> con[v] = v와 연결된 정점 목록<br>
visited[v] = v가 센트로이드였던 적이 있다면 true
```

먼저 `DFS`를 사용해서 sz를 구한다. (prev는 DFS의 중복 방문을 방지한다)
```
int SetSize(int v, int prev) {
	sz[v] = 1;
	for (auto i : con[v])
		if (i != prev && !visited[i])
			sz[v] += SetSize(i, v);
	return sz[v];
}
```

sz를 사용해서 정의에 따라 센트로이드를 구할 수 있다. 임의의 정점을 선택하고 이 정점이 센트로이드 정의에 맞다면 이 정점을 센트로이드로 정한다.
```
int Centroid(int v, int prev, int size) {
	for (auto i : con[v])
		if (i != prev && !visited[i] && sz[i] * 2 > size)<br>
			return Centroid(i, v, size);
	return v;
}
```

### 분할정복
현재 트리의 루트(root)를 시작으로 센트로이드를 구할 수 있다. 그리고 센트로이드와 인접한 정점을 기점으로 서브트리를 분할할 수 있다.
```
void DC(int root) {
	// 센트로이드 구하기
	int size = SetSize(root, -1, 0);
	int ctr = Centroid(root, -1, size);
	visited[ctr] = 1;

	// 서브트리 분할정복
	for (auto next : con[ctr]) {
		int i = next.v;
		if (!visited[i])
			DC(i);
	}
}
```

## 활용
주로 센트로이드 분할은 트리에서 임의의 두 정점의 거리와 관련된 쿼리를 빠르게 수행할 때 사용한다.

분할정복 과정은 일반적으로 현재 트리에서 센트로이드를 거치는 모든 경로를 조사하는 구조로 설계한다.

## 코드
`BOJ - 5820 - 경주` 코드
```
#include <iostream>
#include <vector>
using namespace std;
const int SIZE = 200002, INF = 200002;
struct Edge { int v, w; };
struct Path { int dist, depth; };
int N, K, race = INF, sz[SIZE], course[1000002];
vector<Edge> con[SIZE];<br>
vector<int> used_dist;<br>
vector<Path> path;<br>
bool visited[SIZE];

int SetSize(int v, int prev, int d) {
	sz[v] = 1;
	for (auto next : con[v]) {
		int i = next.v;
		if (i != prev && !visited[i])
			sz[v] += SetSize(i, v, d + 1);
	}
	return sz[v];
}

int Centroid(int v, int prev, int size) {
	for (auto next : con[v]) {
		int i = next.v;
		if (i != prev && !visited[i] && sz[i] * 2 > size)<br>
			return Centroid(i, v, size);
	}	
	return v;
}

void Race(int v, int prev, int depth, int dist) {
	if (dist > K)<br>
		return;

	race = min(race, depth + course[K - dist]);
	path.push_back({dist, depth});
	used_dist.push_back(dist);
	
	for (auto next : con[v]) {
		int i = next.v;
		if (i != prev && !visited[i])
			Race(i, v, depth + 1, dist + next.w);
	}
}

void DC(int root) {
	int size = SetSize(root, -1, 0);
	int ctr = Centroid(root, -1, size);
	visited[ctr] = 1;

	for (auto i : used_dist)
		course[i] = INF;
	used_dist.clear();
	for (auto next : con[ctr]) {
		int i = next.v;
		if (!visited[i])
			Race(i, ctr, 1, next.w);

		for (auto p : path)
			course[p.dist] = min(course[p.dist], p.depth);
		path.clear();
	}

	for (auto next : con[ctr]) {
		int i = next.v;
		if (!visited[i])
			DC(i);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;<br>
	for (int i = 0; i < N - 1; i++) {
		int a, b, w;
		cin >> a >> b >> w;<br>
		con[a].push_back({b, w});
		con[b].push_back({a, w});
	}
	for (int i = 1; i <= K; i++)
		course[i] = INF;

	DC(0);
	cout << (race != INF ? race : -1);
	return 0;
}
```

## 센트로이드 트리
`센트로이드 트리`는 트리의 센트로이드를 루트로 해서 새로 생성한 트리다. 센트로이드 분할을 통해서 센트로이드 트리를 만들 수 있다.
```
int parent_ctr[v] = 센트로이드 트리에서 정점 v의 부모
int CTR_Tree(int root) {
	// 센트로이드 구하기
	int size = SetSize(root, -1, 0);
	int ctr = Centroid(root, -1, size);
	visited[ctr] = 1;

	// 센트로이드 트리 구축 (서브트리 센트로이드의 부모 = 현재 트리의 센트로이드)
	for (auto i : con[ctr])
		if (!visited[i])
			parent_ctr[CTR_Tree(i)] = ctr;

	// 현재 트리의 센트로이드 반환
	return ctr;
}
```

센트로이드 트리는 크게 2가지의 특징을 가진다. (원본 트리 = T, 센트로이드 트리 = C)
> 1. T의 높이가 N일 때, C의 높이의 최대는 logN이다.<br>
> 2. 임의의 두 정점 u, v가 있을 때, C에서 u, v의 `LCA`는 T에서 u, v 경로에 항상 포함된다.<br>

## 연관 문제
### 일반
https://www.acmicpc.net/problem/5820<br>
https://www.acmicpc.net/problem/13854<br>

### 센트로이드 트리
https://www.acmicpc.net/problem/13514<br>

## 참고
https://justicehui.github.io/hard-algorithm/2020/08/25/centroid/<br>
https://www.secmem.org/blog/2021/04/14/centroid-of-a-tree/<br>
{% endraw %}