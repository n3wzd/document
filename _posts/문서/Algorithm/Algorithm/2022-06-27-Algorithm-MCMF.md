---
categories:
- Algorithm
date: '2022-06-27'
title: '[Algorithm] MCMF'
---

{% raw %}
## Minimum Cost Maximum Flow
`MCMF(Minimum Cost Maximum Flow)`은 방향 그래프에서 `최대 유량`을 구하면서 최소 비용도 같이 구하는 문제다. 최소 비용은 최대 유량과 경로에 포함된 간선들의 가중치 총합의 곱으로 계산된다.

간단하게 작업을 나눠서 수행하면 된다. `최단 거리 알고리즘`으로 최단 경로를 구하고, 해당 경로에서 최대 유량을 구하는 작업을 반복하면 된다. 이는 `에드몬드-카프 알고리즘`에서 가중치 개념이 추가된 것과 같다. (`BFS`에서 최단 거리 알고리즘으로 대체)

### 역방향 간선
최대 유량에서 역방향 간선의 유량은 원래 간선의 유량의 반대이며, 역방향 간선으로 유량을 보낸 것은 이전에 흘린 유량을 취소하는 것과 같다. (=유량의 대칭성) 따라서 일반 간선의 가중치가 w이면 역방향 간선의 가중치는 -w이다.

가중치 차이로 인해 일반적인 최대 유량과 달리 MCMF 그래프에선 A → B 간선과 B → A의 역방향 간선이 서로 구분된다. 즉, 양방향 간선 A ↔ B 간선 1개가 추가된다면 A → B와 역방향 간선(B → A, 가중치 -w, 용량 0), B → A와 역방향 간선(A → B, 가중치 -w, 용량 0) 총 4개가 추가되어야 한다.

## 설계
크게 최단 경로와 최대 유량 구간으로 나뉜다.

역방향 간선이 포함되므로 음의 가중치를 반영할 수 있는 최단 거리 알고리즘을 사용해야 한다. `벨만 포드 알고리즘`이나 `SPFA`을 채택할 수 있으며, 보통 평균 속도가 빠른 SPFA가 채택되는 편이다.

최단 경로를 찾았다면, 해당 경로를 따라 최대 유량을 보낸다. 이 작업은 `에드몬드-카프 알고리즘`의 유량 보내기와 동일한 작업이다.

시간 복잡도는 O(V×E×f)이다. (V = 정점 개수, E = 간선 개수, f = 최대 유량)

```
0. source, sink 설정
1. source에서 sink로 이동할 수 없을 때까지 반복
	1. 최단 거리 알고리즘 수행
		- 최단 경로 1개를 찾는다.
		- 용량이 0인 간선을 통해 이동할 수 없다.
	2. 찾은 경로에서 최대 유량을 찾고 유량을 보낸다.
		- 최소 비용 += 최대 유량 × 경로에 포함된 간선들의 가중치 합
2. 최소 비용 출력
```

## 코드
`BOJ - 11408 - 열혈강호 5` 코드
```
#include <iostream>
#include <queue>
#include <memory.h>
#define SIZE 805
using namespace std;
typedef long long ll;
const int INF = (1 << 30) - 1;
struct Edge { int dest, weight, cap, prevIdx; };
int N, M, S = 1, T;
ll dist[SIZE];
bool inQ[SIZE];
int trc_v[SIZE];
int trc_idx[SIZE];
vector<Edge> graph[SIZE];

bool SPFA() {
	memset(inQ, 0, sizeof(inQ));
	for (int i = 0; i < SIZE; i++) dist[i] = INF;
	queue <int> q;
	q.push(S), dist[S] = 0, inQ[S] = 1;

	while (!q.empty()) {
		int v = q.front(); q.pop();
		inQ[v] = 0;
		for (int i = 0; i < graph[v].size(); i++) {
			if (graph[v][i].cap == 0) continue;
			int nv = graph[v][i].dest, w = graph[v][i].weight;

			if (dist[nv] > dist[v] + w) {
				dist[nv] = dist[v] + w;
				trc_v[nv] = v, trc_idx[nv] = i;

				if (!inQ[nv]) {
					q.push(nv);
					inQ[nv] = 1;
				}
			}
		}
	}
	return dist[T] != INF;
}

void NetFlow() {
	int sumFlow = 0, sumWeight = 0;
	while (SPFA()) {
		int minFlow = INF;
		for (int v = T; v != S; v = trc_v[v])
			minFlow = min(minFlow, graph[trc_v[v]][trc_idx[v]].cap);

		for (int v = T; v != S; v = trc_v[v]) {
			int pv = trc_v[v], pidx = trc_idx[v];
			graph[pv][pidx].cap -= minFlow;
			graph[v][graph[pv][pidx].prevIdx].cap += minFlow;
			sumWeight += minFlow * graph[pv][pidx].weight;
		}
		sumFlow += minFlow;
	}
	cout << sumFlow << "\n" << sumWeight << "\n";
}

void MakeEdge(int a, int b, int w, int c) {
	graph[a].push_back({ b, w, c, (int)graph[b].size() });
	graph[b].push_back({ a, -w, 0, (int)graph[a].size() - 1 });
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	S = N + M, T = N + M + 1;
	for (int n = 0; n < N; n++) {
		int len, work, cost;
		cin >> len;
		while (len--) {
			cin >> work >> cost;
			MakeEdge(n, N + work - 1, cost, 1);
		}
		MakeEdge(S, n, 0, 1);
	}
	for (int m = 0; m < M; m++)
		MakeEdge(N + m, T, 0, 1);

	NetFlow();
	return 0;
}
```

## Maximum Cost Maximum Flow ?
`MCMF`에서 최소 비용대신 최대 비용을 구하는 문제.

그래프의 모든 가중치를 음수로 바꾸고 MCMF를 그대로 수행하면 된다. 이때 구한 최소 비용을 다시 양수로 바꾼 것이 최대 비용이다.

## 관련 문제
<br>https://www.acmicpc.net/problem/11408
<br>https://www.acmicpc.net/problem/11409
<br>https://www.acmicpc.net/problem/11111
<br>https://www.acmicpc.net/problem/11493

## 참고
<br>https://anz1217.tistory.com/54
<br>https://www.crocus.co.kr/1090
{% endraw %}