---
categories:
- Programmers
date: '2024-11-23'
title: '[Programmers] SummerWinter Coding(2019) - 지형 이동'
---

{% raw %}
> Lv. 4<br>

## 문제
N x N 크기인 정사각 격자 형태의 지형이 있습니다. 각 격자 칸은 1 x 1 크기이며, 숫자가 하나씩 적혀있습니다. 격자 칸에 적힌 숫자는 그 칸의 높이를 나타냅니다.

이 지형의 아무 칸에서나 출발해 모든 칸을 방문하는 탐험을 떠나려 합니다. 칸을 이동할 때는 상, 하, 좌, 우로 한 칸씩 이동할 수 있는데, 현재 칸과 이동하려는 칸의 높이 차가 height 이하여야 합니다. 높이 차가 height 보다 많이 나는 경우에는 사다리를 설치해서 이동할 수 있습니다. 이때, 사다리를 설치하는데 두 격자 칸의 높이차만큼 비용이 듭니다. 따라서, 최대한 적은 비용이 들도록 사다리를 설치해서 모든 칸으로 이동 가능하도록 해야 합니다. 설치할 수 있는 사다리 개수에 제한은 없으며, 설치한 사다리는 철거하지 않습니다.

각 격자칸의 높이가 담긴 2차원 배열 land와 이동 가능한 최대 높이차 height가 매개변수로 주어질 때, 모든 칸을 방문하기 위해 필요한 사다리 설치 비용의 최솟값을 return 하도록 solution 함수를 완성해주세요.

### 제한사항
-   land는 N x N크기인 2차원 배열입니다.
-   land의 최소 크기는 4 x 4, 최대 크기는 300 x 300입니다.
-   land의 원소는 각 격자 칸의 높이를 나타냅니다.
-   격자 칸의 높이는 1 이상 10,000 이하인 자연수입니다.
-   height는 1 이상 10,000 이하인 자연수입니다.

## 해결
먼저 사다리 없이 이동 가능한 영역들을 찾아야 합니다. 높이 차가 `height`인 칸은 이동할 수 있으며, `그래프 탐색`으로 영역을 구분할 수 있습니다.

다음으로 사다리를 건설해야 합니다. 사다리 개수는 항상 적게 하는게 이득이므로 사다리 개수는 항상 영역 개수 - 1이며, 이는 `트리`를 의미합니다. 최종적으로 사다리 비용이 최소여야 하며, 이는 `최소 신장 트리`를 생성하는 것과 같습니다.

구분한 영역들을 정점으로 하고, 영역 간 연결을 모두 간선으로 처리합니다. (영역 간 연결은 그래프 탐색에서 찾을 수 있으며, 이동 불가능한 두 칸의 연결을 의미합니다. 간선 가중치는 두 칸의 높이 차입니다.) 그리고 최소 신장 트리 알고리즘을 돌려서 최소 비용을 찾으면 됩니다.

## 코드
```
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
struct Edge { int x, y, w; };
vector<vector<int>> L;<br>
int N, M, H, genID = 1, area[301][301], dx[] = { 1, 0, -1, 0 }, dy[] = { 0, 1, 0, -1 };
vector<Edge> graph[90001];<br>
bool visited[90001];
struct cmp { bool operator()(Edge a, Edge b) { return a.w > b.w; } };<br>
priority_queue<Edge, vector<Edge>, cmp> pq;<br>

void DFS(int x, int y) {
    if(area[y][x] > 0) return;<br>
    area[y][x] = genID;
    for(int d = 0; d < 4; d++) {
        int nx = x + dx[d], ny = y + dy[d];
        if(nx < 0 || nx >= M || ny < 0 || ny >= N)
            continue;
        int cost = abs(L[y][x] - L[ny][nx]);
        if(cost <= H)
            DFS(nx, ny);
        else
            graph[genID].push_back({ nx, ny, cost });
    }
}

void addEdge(int v) {
	for (auto next : graph[v])
		if (!visited[area[next.y][next.x]])
            pq.push(next);
}

int mst() {
    int cost = 0;
	addEdge(1); visited[1] = 1;
	while (!pq.empty()) {
		Edge next = pq.top(); pq.pop();
        int v = area[next.y][next.x];
		if (visited[v])
            continue;
        visited[v] = 1;
		cost += next.w;
		addEdge(v);
	}
    return cost;
}

int solution(vector<vector<int>> land, int height) {<br>
    L = land, N = land.size(), M = land[0].size(), H = height;
    for(int y = 0; y < N; y++)
        for(int x = 0; x < M; x++)
            if(area[y][x] == 0)
                DFS(x, y), genID++;
    return mst();
}
```

## 링크
https://school.programmers.co.kr/learn/courses/30/lessons/62050<br>
{% endraw %}