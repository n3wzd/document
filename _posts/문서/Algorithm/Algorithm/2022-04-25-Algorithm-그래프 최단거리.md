---
categories:
- Algorithm
date: '2022-04-25'
title: '[Algorithm] 그래프 최단거리'
---

{% raw %}
## 다익스트라 알고리즘 (Dijkstra Algorithm)
가중치가 있는 그래프의 최단 거리를 찾는 방법. `그리디` 메소드를 사용하며, 시작점으로부터 모든 정점간의 최단 거리를 찾을 수 있다.

1. 시작 정점 S, 최단 거리를 저장하는 배열 dist를 준비한다.
	- dist의 인덱스: 도착 정점 번호
	- dist의 값: S에서 도착 정점까지 최단 거리
		- dist의 초기 값일 경우, dist[S] = 0, 나머지는 모두 INF로 한다.
		- INF는 무한대에 가까운 수이다. 실제 구현에선 그래프에서 만들 수 있는 가장 긴 경로의 길이보다 큰 수로 하면 된다.
2. 탐색하지 않은 정점 중에서 dist가 가장 작은 정점 v를 선택한다.
	- 이때 선택한 정점 v의 방문 여부를 true로 한다. 
3. 현재 정점 v에서 이동 가능한(=인접한) 모든 정점 v<sub>i</sub>을 조사한다.
	- 만약 v<sub>i</sub>로 이동할 수 있는 최단 거리 dist를 갱신할 수 있다면 업데이트한다.
	- (v→v<sub>i</sub>) 간선의 가중치 = w
	- dist[v] + w < dist[v<sub>i</sub>]
		- dist[v<sub>i</sub>] = dist[v] + w
4. 모든 정점을 탐색 완료할 때까지 2-3 과정 반복

탐색하지 않은 정점에서 dist가 가장 작은 것을 찾는 과정은 1부터 N까지 탐색하는 선형 탐색 반복문으로 구현할 수 있지만, 우선순위 큐를 사용하면 더 빠르게 찾을 수 있다.

#### 시간 복잡도
- 일반적인 구현 = O(N<sup>2</sup>)
- 우선순위 큐 사용 = O(V + E log V)

(N = 정점 개수, E = 간선 개수)

#### 코드
※ 우선순위 큐 사용
```
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
#define INF 99999999

struct cmp {
	bool operator()(pair<int, int>& a, pair<int, int>& b) {
		return a.second > b.second;
	}
};

int N, E, S; // N = 정점 개수, E = 간선 개수, S = 시작 정점 번호
int dist[802]; // 최단 거리를 저장하는 배열
bool visited[802] = { 0, }; // 각 정점의 방문 여부를 저장하는 배열
vector<pair<int, int>> graph[802]; // 그래프 저장: 인접 리스트 사용
priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
// 우선순위 큐 (first: 정점 번호, second: 최단 거리 dist (우선순위 큐 정렬 기준으로 사용, dist가 가장 작은 것이 root에 위치한다))

void Dijkstra(int S)
{
	// dist, visited 초기화
	for (int i = 1; i <= N; i++)
	{
		dist[i] = INF;
		visited[i] = 0;
	}
	dist[S] = 0; // dist[시작 정점]의 값은 0
	pq.push(make_pair(S, 0));
	
	while (!pq.empty())
	{
		// 탐색하지 않은 정점 중에서 dist가 가장 작은 정점 선택
		int v = pq.top().first;
		pq.pop();
		if (visited[v]) continue;
		visited[v] = 1; // 방문 완료 표시

		int len = graph[v].size();
		for (int i = 0; i < len; i++) // 인접 정점 조사
		{
			int nv = graph[v][i].first;
			int w = graph[v][i].second;
			if (dist[v] + w < dist[nv]) // 거리 비교
			{
				dist[nv] = dist[v] + w; // dist 최솟값 갱신
				pq.push(make_pair(nv, dist[nv])); // 최솟값이 갱신되었으므로 우선순위 큐에 추가
			}
		}
	}
}

int main()
{
	scanf("%d%d%d", &N, &E, &S);
	for (int i = 1; i <= E; i++)
	{
		int a, b, w;
		scanf("%d%d%d", &a, &b, &w);
		graph[a].push_back(make_pair(b, w));
	}

	Dijkstra(S);
	for (int i = 1; i <= N; i++)
		cout << dist[i] << " ";
	cout << endl;
	return 0;
}
```

## 벨만-포드 알고리즘 (Bellman-Ford Algorithm)
가중치가 있는 그래프의 최단 거리를 찾는 방법. `동적 계획법`을 사용하며, 시작점으로부터 모든 정점간의 최단 거리를 찾을 수 있다. `다익스트라 알고리즘`과 역할이 비슷하지만, 음의 가중치가 있는 그래프에서도 사용할 수 있다는 이점이 있다. (다익스트라 알고리즘은 음의 가중치가 있는 그래프에서 사용할 수 없다)

음의 가중치는 간선의 방향이 반대인 것이 아니라, 이동하면 오히려 이득을 보는 경우다. 예를 들어 어떤 톨게이트를 통과하면 오히려 돈을 받는 경우가 음의 가중치에 해당된다.

현재 정점 v과 최단 경로에서 사용 가능한 최대 간선 개수 k를 현재 상태 dist(v, k)로 정의한다. 그리고 벨만-포드 알고리즘에서 사용되는 점화식은 다음과 같다. (v<sub>i</sub> = v에서 인접한 정점, (v<sub>i</sub>→v))
> d(v, k) = min{d(v, k-1), min{d(v<sub>1</sub>, k-1) + weight(v<sub>1</sub>, v), d(v<sub>2</sub>, k-1) + weight(v<sub>2</sub>, v), ... }}<br>

여기서 계산할 때 k-1번 직전 캐시를 한번씩만 재참조하기 때문에 캐시 크기를 압축할 수 있다. 즉, 실제로 구현할 때는 dist에서 k인덱스를 생략할 수 있다.
> d(v) = min{d(v), min{d(v<sub>1</sub>) + weight(v<sub>1</sub>, v), d(v<sub>2</sub>) + weight(v<sub>2</sub>, v), ... }}<br>

1. 시작 정점 S, 최단 거리를 저장하는 배열 dist를 준비한다.
	- dist의 인덱스: 도착 정점 번호
	- dist의 값: S에서 도착 정점까지 최단 거리
		- dist의 초기 값일 경우, dist[S] = 0, 나머지는 모두 INF로 한다.
2. 그래프의 모든 간선을 탐색한다.
	- 간선의 시작점 = src, 간선의 도착점 = dest, 간선의 가중치 = weight
	- if (dist[src] != INF)
		- dist[dest] = min(dist[dest], dist[src] + weight);
3. 2번 과정을 N-1번 반복한다.

#### 음의 사이클 (negative-weight cycle)
음의 사이클이 존재하는 그래프에서는 최단 거리가 음의 무한대가 될 수 있다. (해당 사이클을 돌면 돌수록 이득을 보기 때문) 따라서 음의 사이클이 존재하는 경우를 판정할 필요가 있다.

벨만-포드 알고리즘에선 그래프의 최장 경로의 간선 개수는 정점 개수 N에서 1을 뺀 값으로 가정하기 때문에, N-1번만큼 간선 탐색을 한다. 그러나 음의 사이클이 존재하는 그래프에서는 N-1개 초과한 간선을 사용해서 최단 거리를 구성할 수 있으므로 벨만-포드 알고리즘이 성립하지 않는다. 이 경우에는 최단 거리가 없다고 판단한다.

벨만-포드 알고리즘에서 간선 탐색을 N-1번 진행한 상태에서 1번 더 진행했을 때, 갱신되는 최단 거리가 존재한다면 그래프에 음의 사이클이 존재한다고 판정할 수 있다.

#### 음의 방향의 오버플로우
음의 가중치를 허용하기 때문에, 음의 사이클 역시 존재하게 된다. 이 음의 사이클을 계산하는 과정에서 최단 거리의 값이 음의 방향으로 무한대로 커질 수 있기 때문에 오버플로우가 발생할 수 있다. 예를 들어 정점 개수가 500이고, 가중치가 -10000인 간선이 6000개 존재하는 단일 사이클에서는 계산되는 최단 거리가 500 × 6000 × -10000이다. (C++ 기준 int의 범위를 넘는다!)

이 경우는 최단 거리를 저장하는 배열의 자료형을 확장하면 해결할 수 있다. C++ 기준, long long으로 전환하면 된다.

#### 시간 복잡도
- 인접 행렬 사용 = O(N<sup>3</sup>)
- 인접 리스트 사용 = O(NE)

(N = 정점 개수, E = 간선 개수)

#### 코드
벨만-포드 알고리즘은 일반적으로 Bottom-Up으로 구현된다.

해당 코드에선 구현의 편의를 위해 그래프가 간선에 대해 저장하는 구조로 되어 있으나, 인접 리스트로도 구현이 가능하다.
```
#include <iostream>
#include <cmath>
using namespace std;
#define INF 9999999

class Edge { // 간선 클래스
public:
	int src, dest, weight; // 시작 정점, 도착 정점, 가중치
	Edge(int a, int b, int c) { src = a, dest = b, weight = c; }
	Edge() {}
};

int V, E, S = 1; // N = 정점 개수, E = 간선 개수, S = 시작 정점 번호
long long dist[502]; // 최단 거리 배열
Edge graph[6002]; // 간선을 저장하는 그래프

bool BellmanFord()
{
	for (int v = 1; v <= V; v++) // 초기화
		dist[v] = INF;
	dist[S] = 0;

	for (int i = 1; i <= V - 1; i++) // N-1번 탐색
	{
		for (int e = 0; e < E; e++) // 모든 간선 탐색
		{
			int src = graph[e].src;
			int dest = graph[e].dest;
			int weight = graph[e].weight;
			if (dist[src] != INF) // dist[src], dist[dest] == INF, weight < 0인 예외를 주의
				dist[dest] = min(dist[dest], dist[src] + weight);
		}
	}

	// 음의 사이클 검사
	for (int e = 0; e < E; e++)
	{
		int src = graph[e].src;
		int dest = graph[e].dest;
		int weight = graph[e].weight;
		if (dist[src] != INF && dist[dest] > dist[src] + weight)
			return false; // N-1번 이후에도 최단 거리가 갱신되면 음의 사이클이 존재함
	}

	return true;
}

int main()
{
	scanf("%d%d", &V, &E);
	for (int i = 0; i < E; i++)
	{
		int a, b, w;
		scanf("%d%d%d", &a, &b, &w);
		graph[i] = Edge(a, b, w);
	}

	if (BellmanFord())
	{
		for (int i = 1; i <= V; i++)
		{
			if (i == S) continue;
			if (dist[i] != INF) printf("%lld\n", dist[i]);
			else printf("-1\n");
		}
	}
	else printf("-1\n");

	return 0;
}
```

## 플로이드-와샬 알고리즘 (Floyd-Warshall Algorithm)
가중치가 있는 그래프의 최단 거리를 찾는 방법. `동적 계획법`을 사용하며, 앞서 살펴본 2개의 알고리즘과 달리 모든 정점에 대한 최단 거리를 찾을 수 있다. 그 외 `벨만-포드 알고리즘`과 마찬가지로 음의 가중치가 있는 그래프에서도 사용할 수 있다.

시작 정점 i, 도착 정점 j, 그리고 최단 경로에서 사용 가능한 최대 간선 개수 k를 현재 상태 dist(i, j, k)로 정의한다. 벨만-포드 알고리즘 때와 마찬가지로 캐시는 직전 값을 1번씩만 재참조하기 때문에, 실제 구현에선 k 인덱스를 생략할 수 있다.

플로이드 알고리즘에서 사용되는 점화식은 다음과 같다.
> adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j])<br>

1. 최단 거리를 저장하는 2차원 배열 adj를 준비한다.
	- adj의 인덱스: 시작 정점과 도착 정점 (i, j)
	- adj의 값: i에서 j까지 최단 거리
		- adj의 초기 값일 경우, 시작 정점과 도착 정점이 같은 경우는 0, 나머지는 모두 INF로 한다.
2. adj에 그래프 데이터를 입력한다. (초항 입력)
	- adj[i][j] = weight
3. 다음 코드를 실행한다.
```
for (int k = 1; k <= V; k++)
	for (int i = 1; i <= V; i++)
		for (int j = 1; j <= V; j++)
			adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
```

#### 시간 복잡도
O(N<sup>3</sup>)

#### 코드
```
#include <iostream>
#include <cmath>
using namespace std;
#define INF 90000000

int V, E, S = 1;
int adj[102][102];

void Floyd()
{
	for (int k = 1; k <= V; k++)
		for (int i = 1; i <= V; i++)
			for (int j = 1; j <= V; j++)
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
}

int main()
{
	scanf("%d%d", &V, &E);
	for (int i = 1; i <= V; i++)
		for (int j = 1; j <= V; j++)
			adj[i][j] = INF;
	for (int v = 1; v <= V; v++)
		adj[v][v] = 0;

	for (int i = 0; i < E; i++)
	{
		int a, b, w;
		scanf("%d%d%d", &a, &b, &w);
		adj[a][b] = min(adj[a][b], w);
	}

	Floyd();
	for (int i = 1; i <= V; i++)
	{
		for (int j = 1; j <= V; j++)
		{
			if(adj[i][j] != INF) printf("%d ", adj[i][j]);
			else printf("0 ", adj[i][j]);
		}
		printf("\n");
	}

	return 0;
}
```

## VS
#### 평균 시간 복잡도
> 다익스트라 < 벨만-포드 < 플로이드<br>

일반적으로 다익스트라 알고리즘이 가장 빠르다.

#### 최단 거리 선택?
- 가중치가 없는 그래프의 최단 거리 => BFS
- 가중치가 있는 그래프의 최단 거리 => 다익스트라
- 가중치가 있는 음의 가중치를 포함한 그래프의 최단 거리 => 벨만-포드
- 가중치가 있는 그래프의 최단 거리, 모든 정점을 시작점으로 하는 경우 => 플로이드-와샬

## 연관 문제
다익스트라 - <br>https://www.acmicpc.net/problem/1753
벨만-포드 - <br>https://www.acmicpc.net/problem/11657
플로이드-와샬 - <br>https://www.acmicpc.net/problem/11404

## 참고
<br>https://m.blog.naver.com/ndb796/221234424646
<br>https://www.geeksforgeeks.org/bellman-ford-algorithm-dp-23/
<br>https://4legs-study.tistory.com/26
<br>https://reakwon.tistory.com/55
{% endraw %}