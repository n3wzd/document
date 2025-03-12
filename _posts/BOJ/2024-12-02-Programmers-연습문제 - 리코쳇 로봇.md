---
categories:
- Programmers
date: '2024-12-02'
title: '[Programmers] 연습문제 - 리코쳇 로봇'
---

{% raw %}
> Lv. 2<br>

## 문제
리코쳇 로봇이라는 보드게임이 있습니다.

이 보드게임은 격자모양 게임판 위에서 말을 움직이는 게임으로, 시작 위치에서 출발한 뒤 목표 위치에 정확하게 멈추기 위해 최소 몇 번의 이동이 필요한지 말하는 게임입니다.

이 게임에서 말의 이동은 현재 위치에서 상, 하, 좌, 우 중 한 방향으로 게임판 위의 장애물이나 게임판 가장자리까지 부딪힐 때까지 미끄러져 움직이는 것을 한 번의 이동으로 정의합니다.

다음은 보드게임판을 나타낸 예시입니다. ("."은 빈 공간을, "R"은 로봇의 처음 위치를, "D"는 장애물의 위치를, "G"는 목표지점을 나타냅니다.)

```
...D..R
.D.G...
....D.D
D....D.
..D....

```
이때 최소 움직임은 7번이며 "R" 위치에서 아래, 왼쪽, 위, 왼쪽, 아래, 오른쪽, 위 순서로 움직이면 "G" 위치에 멈춰 설 수 있습니다.

게임판의 상태를 나타내는 문자열 배열  `board`가 주어졌을 때, 말이 목표위치에 도달하는데 최소 몇 번 이동해야 하는지 return 하는 solution함수를 완성해주세요. 만약 목표위치에 도달할 수 없다면 -1을 return 해주세요.

### 제한 사항
-   3 ≤  `board`의 길이 ≤ 100
    -   3 ≤  `board`의 원소의 길이 ≤ 100
    -   `board`의 원소의 길이는 모두 동일합니다.
    -   문자열은 ".", "D", "R", "G"로만 구성되어 있으며 각각 빈 공간, 장애물, 로봇의 처음 위치, 목표 지점을 나타냅니다.
    -   "R"과 "G"는 한 번씩 등장합니다.

## 해결
격자에서 최단 거리를 찾아야 합니다. => `최단거리 BFS`

전체 과정은 일반적인 격자 맵에서 최단거리 BFS와 같습니다. (`BOJ - 2178 - 미로 탐색` 참고) 다음 정점을 현재 정점(`x`, `y`)에서 4방향으로 벽에 닿을 때까지 이동한 위치로 하면 됩니다.

## 코드
```
#include <string>
#include <vector>
#include <queue>
using namespace std;
struct Point { int x, y; };
int dist[101][101], dx[] = { 1, 0, -1, 0 }, dy[] = { 0, 1, 0, -1 };

int solution(vector<string> board) {
    int N = board.size(), M = board[0].size();
    queue<Point> q; Point G;
    for(int y = 0; y < N; y++) {
        for(int x = 0; x < M; x++) {
            if(board[y][x] == 'R')
                q.push({ x, y }), dist[y][x] = 1;
            if(board[y][x] == 'G')
                G = { x, y };
        }
    }
    while(!q.empty()) {
        Point c = q.front(); q.pop();
        int x = c.x, y = c.y;
        if(x == G.x && y == G.y)
            return dist[y][x] - 1;
        for(int d = 0; d < 4; d++) {
            int nx = x, ny = y;
            while(nx >= 0 && nx < M && ny >= 0 && ny < N && board[ny][nx] != 'D')
                nx += dx[d], ny += dy[d];
            nx -= dx[d], ny -= dy[d];
            if(dist[ny][nx] > 0)
                continue;
            q.push({ nx, ny });
            dist[ny][nx] = dist[y][x] + 1;
        }
    }
    return -1;
}
```

## 링크
<br>https://school.programmers.co.kr/learn/courses/30/lessons/169199
{% endraw %}