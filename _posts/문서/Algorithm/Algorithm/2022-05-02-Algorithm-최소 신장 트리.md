---
categories:
- Algorithm
date: '2022-05-02'
title: '[Algorithm] 최소 신장 트리'
---

{% raw %}
## 최소 신장 트리
- 생성 트리(Spanning Tree): 그래프에서 일부 간선을 선택해서 만든 트리
- 최소 신장 트리(MST, Minimal Spanning Tree): 가중 그래프에서 모든 간선의 가중치 합이 최소인 생성 트리

## 프림 알고리즘 (Prim's Algorithm)
MST를 생성하는 알고리즘. 간선을 1개씩 추가해서 단계적으로 트리를  확장한다. 시간 복잡도는 O(E log V)이다.

```
1. 처음 노드를 아무거나 선택한다.
	- 처음 노드와 인접한 간선을 모두 큐에 추가한다.
	- 처음 노드를 방문 표시한다.
2. 큐에서 가중치가 가장 적고 도착지가 방문되지 않은 간선 1개를 가져온다.
	- 전체 비용에 선택한 간선의 가중치를 더한다.
	- 간선의 도착 노드를 기준으로 인접한 간선을 모두 큐에 추가한다.
	- 도착 노드를 방문 표시한다.
3. 큐가 빌 때까지 2번 과정 반복
```

구현에서는 간선이 추가될 때마다 정렬을 하기 위해 `우선순위 큐`를 사용한다.

### 구현 예시
```
int V, E, MST_cost = 0;
vector<Edge> graph[10002];<br>
priority_queue<Edge, vector<Edge>, cmp> pq;<br>
bool visited[10002];

void AddEdge(int v)
{
	int len = graph[v].size();
	for (int i = 0; i < len; i++)
	{
		Edge next = graph[v][i];
		if (!visited[next.end]) pq.push(next);
	}
}

void Prim()
{
	AddEdge(1);
	visited[1] = true;

	while (!pq.empty())
	{
		Edge next = pq.top();
		pq.pop();
		if (visited[next.end]) continue;

		MST_cost += next.weight;
		AddEdge(next.end);
		visited[next.end] = true;
	}
}
```

## 크루스칼 알고리즘 (Kruskal's Algorithm)
MST를 생성하는 알고리즘. 가장 최적인 간선을 선택해서 트리를 생성한다. 시간 복잡도는 O(E log E)이다.
```
1. 그래프의 모든 간선을 큐에 추가한다.
2. 큐에서 가장 적은 가중치를 가진 간선을 가져온다.
	- 간선을 그래프에 연결했을 때, 트리 구조를 유지해야 한다.
	- 즉, 간선을 추가했을 때 사이클이 발생하지 않아야 한다.
3. 큐가 빌 때까지 2번 과정 반복
```

각 단계마다 트리를 연결하고 사이클 발생을 판별하는 자료구조로 `Disjoint Set`이 적합하다.  Disjoint Set은 집합을 트리 구조로 저장하므로 union을 통해 노드를 트리 구조로 연결할 수 있다. 그리고 트리 내부에 새로운 간선 1개가 추가되면 사이클이 발생하므로, 간선의 두 정점이 같은 트리에 속한다면 사이클이 발생한다고 판단할 수 있다.
```
if (Find(A) == Find(B))
	=> 사이클 발생<br>
Union(A, B) // 트리 간선 연결
```

프림 알고리즘과 달리, 간선을 정렬하는 과정은 1번만 수행하면 된다. sort, 우선순위 큐를 사용해서 구현할 수 있다.

### 구현 예시
```
int parent[20002];
priority_queue<Edge, vector<Edge>, cmp> pq;<br>

int Find(int n)	// Find 연산
void Union(int a, int b) // Union 연산

void Kruskal()
{
	for (int i = 0; i <= V; i++)
		parent[i] = -1;

	while (!pq.empty())
	{
		Edge next = pq.top();
		pq.pop();
		if (Find(next.start) == Find(next.end)) continue; // 사이클 발생하면 패스

		MST_cost += next.weight;
		Union(next.start, next.end); // 트리 간선 연결
	}
}
```

## 전체 코드
```
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Edge {
public:
	int start, end, weight;
	Edge(int a, int b, int w) { start = a, end = b, weight = w; }
};

struct cmp {
	bool operator()(Edge a, Edge b) {
		return a.weight > b.weight;<br>
	}
};

int V, E, MST_cost = 0;
vector<Edge> graph[10002];<br>
priority_queue<Edge, vector<Edge>, cmp> pq;<br>
bool visited[10002];

void AddEdge(int v)
{
	int len = graph[v].size();
	for (int i = 0; i < len; i++)
	{
		Edge next = graph[v][i];
		if (!visited[next.end]) pq.push(next);
	}
}

void Prim()
{
	AddEdge(1);
	visited[1] = true;

	while (!pq.empty())
	{
		Edge next = pq.top();
		pq.pop();
		if (visited[next.end]) continue;

		MST_cost += next.weight;
		AddEdge(next.end);
		visited[next.end] = true;
	}
}

int parent[20002];
priority_queue<Edge, vector<Edge>, cmp> pq2;<br>

int Find(int n)
{
	int p = n;
	while (parent[p] >= 0) p = parent[p];
	if (parent[n] >= 0) parent[n] = p;
	return p;
}

void Union(int a, int b)
{
	int p1 = Find(a);
	int p2 = Find(b);
	if (p1 == p2) return;

	if (parent[p1] < parent[p2])
	{
		parent[p1] += parent[p2];
		parent[p2] = p1;
	}
	else
	{
		parent[p2] += parent[p1];
		parent[p1] = p2;
	}
}

void Kruskal()
{
	for (int i = 0; i <= V; i++)
		parent[i] = -1;

	while (!pq2.empty())
	{
		Edge next = pq2.top();
		pq2.pop();
		if (Find(next.start) == Find(next.end)) continue;

		MST_cost += next.weight;
		Union(next.start, next.end);
	}
}

int main()
{
	scanf("%d%d", &V, &E);
	for (int i = 0; i < E; i++)
	{
		int a, b, w;
		scanf("%d%d%d", &a, &b, &w);
		graph[a].push_back(Edge(a, b, w));
		graph[b].push_back(Edge(b, a, w));
		pq2.push(Edge(a, b, w));
	}
	
	// Prim();
	Kruskal();
	cout << MST_cost;
	return 0;
}
```

## 연관 문제
https://www.acmicpc.net/problem/1197<br>

## 참고
https://ongveloper.tistory.com/376<br>
{% endraw %}