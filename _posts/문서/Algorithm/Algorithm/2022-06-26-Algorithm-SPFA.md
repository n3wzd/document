---
categories:
- Algorithm
date: '2022-06-26'
title: '[Algorithm] SPFA'
---

{% raw %}
## SPFA (Shortest Path Faster Algorithm)
`SPFA`는 `벨만 포드 알고리즘`의 계산 속도를 향상한 그래프 최단거리 알고리즘이다. 벨만 포드와 같이 그래프에 음수 간선이 있어도 사용할 수 있다.

SPFA의 최대 시간 복잡도는 O(V×E)으로 벨만 포드하고 동일하지만, 평균 시간 복잡도는 벨만 포드 알고리즘보다 빠르다.

## 설계
전체적으로 벨만 포드를 베이스로 한다. 하지만 모든 간선을 탐색하는 벨만 포드와 달리, SPFA는 변경된 간선만 최단 거리 갱신을 수행한다는 차이가 있다. (변경된 간선만 탐색하므로 평균 시간 복잡도는 SPFA가 앞서지만, 모든 간선을 탐색하게 된다면 SPFA과 벨만 포드의 탐색량은 동일해진다)

SPFA의 음의 사이클 판정 방법은 벨만 포드하고 동일하다. 벨만 포드에선 간선 탐색을 V번 진행했을 때(V = 정점 개수), 갱신되는 최단 거리가 존재한다면 음의 사이클이 있다고 판정한다. SPFA도 마찬가지로 큐에 특정 정점이 V번 이상 들어왔다면 특정 정점이 V번 이상 갱신되는 것이므로 음의 사이클이 았다고 판정한다.

## 구현
업데이트가 되어야 하는 정점을 담는 `큐`를 사용한다. 큐를 통해 현재 정점를 탐색하며, 만약 간선 비교를 통해 최단 거리가 갱신된다면 해당 인접 정점을 큐에 넣는다. 간선 비교는 벨만 포드하고 동일하다.

큐에는 같은 정점이 2개 이상 들어가지 않는다. 정점이 큐에 있는지를 판별하는 배열(inQ)를 추가해서 중복 insert를 방지하자.

음의 사이클 판정을 위해 정점이 큐에 들어간 횟수를 카운팅하는 배열(cycle)을 추가한다. 만약 어떤 정점의 cycle 값이 V하고 같거나 크면 음의 사이클이 존재한다고 볼 수 있다. 

## 코드
`BOJ - 11657 - 타임머신` 코드
```
#include <iostream>
#include <queue>
#include <cmath>
#define SIZE 502
using namespace std;
typedef long long ll;
const int INF = (1 << 30) - 1;
struct Edge { int dest, weight; };
int V, E, S = 1;
ll dist[SIZE];
bool inQ[SIZE];
int cycle[SIZE];
vector<Edge> graph[SIZE];

bool SPFA() {
    for (int i = 1; i <= V; i++) dist[i] = INF;
    queue <int> q;
    q.push(S), dist[S] = 0, inQ[S] = 1;

    while (!q.empty()) {
        int v = q.front(); q.pop();
        inQ[v] = 0;

        for (int i = 0; i < graph[v].size(); i++) {
            int nv = graph[v][i].dest;
            int w = graph[v][i].weight;

            if (dist[nv] > dist[v] + w) {
                dist[nv] = dist[v] + w;
                if (!inQ[nv]) {
                    cycle[nv]++;
                    if (cycle[nv] >= V) return 0;

                    q.push(nv);
                    inQ[nv] = 1;
                }
            }
        }
    }
    return 1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		graph[a].push_back({ b, w });
	}

	if (SPFA()) {
		for (int i = 1; i <= V; i++) {
			if (i == S) continue;
			if (dist[i] != INF) cout << dist[i] << "\n";
			else cout << "-1\n";
		}
	}
	else cout << "-1\n";
	return 0;
}
```

## 참고
<br>https://www.crocus.co.kr/1089
{% endraw %}