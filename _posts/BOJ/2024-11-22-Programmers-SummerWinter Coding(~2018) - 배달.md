---
categories:
- Programmers
date: '2024-11-22'
title: '[Programmers] SummerWinter Coding(~2018) - 배달'
---

{% raw %}
> Lv. 2<br>

## 문제
N개의 마을로 이루어진 나라가 있습니다. 이 나라의 각 마을에는 1부터 N까지의 번호가 각각 하나씩 부여되어 있습니다. 각 마을은 양방향으로 통행할 수 있는 도로로 연결되어 있는데, 서로 다른 마을 간에 이동할 때는 이 도로를 지나야 합니다. 도로를 지날 때 걸리는 시간은 도로별로 다릅니다. 현재 1번 마을에 있는 음식점에서 각 마을로 음식 배달을 하려고 합니다. 각 마을로부터 음식 주문을 받으려고 하는데, N개의 마을 중에서 K 시간 이하로 배달이 가능한 마을에서만 주문을 받으려고 합니다.

마을의 개수 N, 각 마을을 연결하는 도로의 정보 road, 음식 배달이 가능한 시간 K가 매개변수로 주어질 때, 음식 주문을 받을 수 있는 마을의 개수를 return 하도록 solution 함수를 완성해주세요.

### 제한사항
-   마을의 개수 N은 1 이상 50 이하의 자연수입니다.
-   road의 길이(도로 정보의 개수)는 1 이상 2,000 이하입니다.
-   road의 각 원소는 마을을 연결하고 있는 각 도로의 정보를 나타냅니다.
-   road는 길이가 3인 배열이며, 순서대로 (a, b, c)를 나타냅니다.
    -   a, b(1 ≤ a, b ≤ N, a != b)는 도로가 연결하는 두 마을의 번호이며, c(1 ≤ c ≤ 10,000, c는 자연수)는 도로를 지나는데 걸리는 시간입니다.
    -   두 마을 a, b를 연결하는 도로는 여러 개가 있을 수 있습니다.
    -   한 도로의 정보가 여러 번 중복해서 주어지지 않습니다.
-   K는 음식 배달이 가능한 시간을 나타내며, 1 이상 500,000 이하입니다.
-   임의의 두 마을간에 항상 이동 가능한 경로가 존재합니다.
-   1번 마을에 있는 음식점이 K 이하의 시간에 배달이 가능한 마을의 개수를 return 하면 됩니다.

## 해결
`데이크스트라 알고리즘`을 사용해서 1번 정점부터 모든 정점의 최단 거리를 구하고, 최단 거리가 `K` 이하인 정점 수를 찾으면 됩니다.

## 코드
```
#include <vector>
#include <queue>
using namespace std;
struct Edge { int v, w; };
struct cmp { bool operator()(Edge& a, Edge& b) { return a.w > b.w; }};
const int INF = 99999999;
int N, answer, dist[51];
bool visited[51];
vector<Edge> graph[51];
priority_queue<Edge, vector<Edge>, cmp> pq;

void Dijkstra() {
	for (int i = 1; i <= N; i++)
		dist[i] = INF;
	dist[1] = 0;
	pq.push({ 1, 0 });
	while (!pq.empty()) {
		int v = pq.top().v; pq.pop();
		if (visited[v]) continue;
		visited[v] = 1;
		for (auto n : graph[v]) {
			if (dist[v] + n.w < dist[n.v]) {
				dist[n.v] = dist[v] + n.w;
				pq.push({ n.v, dist[n.v] });
			}
		}
	}
}

int solution(int n, vector<vector<int>> roads, int K) {
    N = n;
    for(auto road : roads) {
        graph[road[0]].push_back({road[1], road[2]});
        graph[road[1]].push_back({road[0], road[2]});
    }
    Dijkstra();
    for(int i = 1; i <= N; i++)
        if(dist[i] <= K)
            answer++;
    return answer;
}
```

## 링크
<br>https://school.programmers.co.kr/learn/courses/30/lessons/12978
{% endraw %}