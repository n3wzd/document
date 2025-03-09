---
categories:
- Programmers
date: '2024-11-12'
title: '[Programmers] 2020 KAKAO TECH INTERNSHIP - 경주로 건설'
---

{% raw %}
> Lv. 3<br>

## 문제
건설회사의 설계사인  `죠르디`는 고객사로부터 자동차 경주로 건설에 필요한 견적을 의뢰받았습니다.  
제공된 경주로 설계 도면에 따르면 경주로 부지는  `N x N`  크기의 정사각형 격자 형태이며 각 격자는  `1 x 1`  크기입니다.  
설계 도면에는 각 격자의 칸은  `0`  또는  `1`  로 채워져 있으며,  `0`은 칸이 비어 있음을  `1`은 해당 칸이 벽으로 채워져 있음을 나타냅니다.  
경주로의 출발점은 (0, 0) 칸(좌측 상단)이며, 도착점은 (N-1, N-1) 칸(우측 하단)입니다. 죠르디는 출발점인 (0, 0) 칸에서 출발한 자동차가 도착점인 (N-1, N-1) 칸까지 무사히 도달할 수 있게 중간에 끊기지 않도록 경주로를 건설해야 합니다.  
경주로는 상, 하, 좌, 우로 인접한 두 빈 칸을 연결하여 건설할 수 있으며, 벽이 있는 칸에는 경주로를 건설할 수 없습니다.  
이때, 인접한 두 빈 칸을 상하 또는 좌우로 연결한 경주로를  `직선 도로`  라고 합니다.  
또한 두  `직선 도로`가 서로 직각으로 만나는 지점을  `코너`  라고 부릅니다.  
건설 비용을 계산해 보니  `직선 도로`  하나를 만들 때는 100원이 소요되며,  `코너`를 하나 만들 때는 500원이 추가로 듭니다.  
죠르디는 견적서 작성을 위해 경주로를 건설하는 데 필요한 최소 비용을 계산해야 합니다.

예를 들어, 아래 그림은  `직선 도로`  6개와  `코너`  4개로 구성된 임의의 경주로 예시이며, 건설 비용은 6 x 100 + 4 x 500 = 2600원 입니다.

또 다른 예로, 아래 그림은  `직선 도로`  4개와  `코너`  1개로 구성된 경주로이며, 건설 비용은 4 x 100 + 1 x 500 = 900원 입니다.

도면의 상태(0은 비어 있음, 1은 벽)을 나타내는 2차원 배열 board가 매개변수로 주어질 때, 경주로를 건설하는데 필요한 최소 비용을 return 하도록 solution 함수를 완성해주세요.

### 제한사항
-   board는 2차원 정사각 배열로 배열의 크기는 3 이상 25 이하입니다.
-   board 배열의 각 원소의 값은 0 또는 1 입니다.
    -   도면의 가장 왼쪽 상단 좌표는 (0, 0)이며, 가장 우측 하단 좌표는 (N-1, N-1) 입니다.
    -   원소의 값 0은 칸이 비어 있어 도로 연결이 가능함을 1은 칸이 벽으로 채워져 있어 도로 연결이 불가능함을 나타냅니다.
-   board는 항상 출발점에서 도착점까지 경주로를 건설할 수 있는 형태로 주어집니다.
-   출발점과 도착점 칸의 원소의 값은 항상 0으로 주어집니다.

## 해결
직진으로 이동할 때와 90도 전환하여 이동할 때 비용이 다른 그래프에서 최단 거리를 찾아야 합니다. `데이크스트라 알고리즘`을 사용하여 답을 찾을 수 있습니다.

현재 위치에서 이전에 어떤 방향으로 왔는지가 다음 정점의 이동 비용에 영향을 줍니다. 현재 정점을 (x, y, 수평/수직 방향)으로 정의합니다. 다음 정점은 벽이 아닌 인접한 4방향의 위치입니다. 이동 비용은 현재 방향과 이동한 방향이 한 축으로 이어지면 100, 그렇지 않으면 600입니다. 그외 전체적인 동작은 일반적인 데이크스트라 알고리즘과 같습니다.

## 코드
```
#include <vector>
#include <queue>
using namespace std;
struct Node { int x, y, axis, cost; };
struct cmp { bool operator()(const Node& a, const Node& b) { return a.cost > b.cost; } };<br>
int N, cost[26][26][2], dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 };
bool visited[26][26][2];
const int INF = 1 << 29;

int solution(vector<vector<int>> board) {<br>
    priority_queue<Node, vector<Node>, cmp> pq;<br>
    N = board.size();
    for (int y = 0; y < N; y++)
        for (int x = 0; x < N; x++)
            cost[y][x][0] = cost[y][x][1] = INF;
    cost[0][0][0] = cost[0][0][1] = 0;
    pq.push({ 0, 0, 0 }); pq.push({ 0, 0, 1 });
    while (!pq.empty()) {
        int x = pq.top().x, y = pq.top().y, a = pq.top().axis; pq.pop();
        if (visited[y][x][a])
            continue;
        visited[y][x][a] = 1;
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d], ny = y + dy[d], na = d % 2;
            if (nx < 0 || nx >= N || ny < 0 || ny >= N || visited[ny][nx][na] || board[ny][nx] == 1)
                continue;
            int ncost = cost[y][x][a] + (a == na ? 100 : 600);
            if (ncost < cost[ny][nx][na]) {
                cost[ny][nx][na] = ncost;
                pq.push({ nx, ny, na, ncost });
            }
        }
    }
    return min(cost[N - 1][N - 1][0], cost[N - 1][N - 1][1]);
}
```

## 링크
https://school.programmers.co.kr/learn/courses/30/lessons/67259
{% endraw %}