---
categories:
- Programmers
date: '2024-12-05'
title: '[Programmers] 연습문제 - 미로 탈출'
---

{% raw %}
> Lv. 2<br>

## 문제
1 x 1 크기의 칸들로 이루어진 직사각형 격자 형태의 미로에서 탈출하려고 합니다. 각 칸은 통로 또는 벽으로 구성되어 있으며, 벽으로 된 칸은 지나갈 수 없고 통로로 된 칸으로만 이동할 수 있습니다. 통로들 중 한 칸에는 미로를 빠져나가는 문이 있는데, 이 문은 레버를 당겨서만 열 수 있습니다. 레버 또한 통로들 중 한 칸에 있습니다. 따라서, 출발 지점에서 먼저 레버가 있는 칸으로 이동하여 레버를 당긴 후 미로를 빠져나가는 문이 있는 칸으로 이동하면 됩니다. 이때 아직 레버를 당기지 않았더라도 출구가 있는 칸을 지나갈 수 있습니다. 미로에서 한 칸을 이동하는데 1초가 걸린다고 할 때, 최대한 빠르게 미로를 빠져나가는데 걸리는 시간을 구하려 합니다.

미로를 나타낸 문자열 배열 `maps`가 매개변수로 주어질 때, 미로를 탈출하는데 필요한 최소 시간을 return 하는 solution 함수를 완성해주세요. 만약, 탈출할 수 없다면 -1을 return 해주세요.

### 제한사항
-   5 ≤  `maps`의 길이 ≤ 100
    -   5 ≤  `maps[i]`의 길이 ≤ 100
    -   `maps[i]`는 다음 5개의 문자들로만 이루어져 있습니다.
        -   S : 시작 지점
        -   E : 출구
        -   L : 레버
        -   O : 통로
        -   X : 벽
    -   시작 지점과 출구, 레버는 항상 다른 곳에 존재하며 한 개씩만 존재합니다.
    -   출구는 레버가 당겨지지 않아도 지나갈 수 있으며, 모든 통로, 출구, 레버, 시작점은 여러 번 지나갈 수 있습니다.

## 해결
벽이 존재하는 격자에서 특정 위치까지 최단 거리로 이동해야 합니다. => `최단거리 BFS`

독립적인 BFS를 2번(출발점에서 레버, 레버에서 도착점) 돌리면 됩니다. 둘 중 하나라도 도달하지 못하면 -1을 반환합니다.

## 코드
```
#include <string>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
struct Point { int x, y; };
vector<string> maps;
int N, M, dist[101][101], dx[] = { 1, 0, -1, 0 }, dy[] = { 0, 1, 0, -1 };

int BFS(Point S, Point E) {
    memset(dist, 0, sizeof(dist));
    queue<Point> q; q.push(S);
    dist[S.y][S.x] = 1;
    while(!q.empty()) {
        Point c = q.front(); q.pop();
        int x = c.x, y = c.y;
        if(x == E.x && y == E.y)
            return dist[y][x] - 1;
        for(int d = 0; d < 4; d++) {
            int nx = x + dx[d], ny = y + dy[d];
            if(nx < 0 || nx >= M || ny < 0 || ny >= N || dist[ny][nx] > 0 || maps[ny][nx] == 'X')
                continue;
            q.push({ nx, ny });
            dist[ny][nx] = dist[y][x] + 1;
        }
    }
    return -1e9;
}

int solution(vector<string> MI) {
    maps = MI; Point S, L, E; N = maps.size(), M = maps[0].size();
    for(int y = 0; y < N; y++) {
        for(int x = 0; x < M; x++) {
            if(maps[y][x] == 'S')
                S = { x, y };
            if(maps[y][x] == 'E')
                E = { x, y };
            if(maps[y][x] == 'L')
                L = { x, y };
        }
    }
    int answer = BFS(S, L) + BFS(L, E);
    return answer < 0 ? -1 : answer;
}
```

## 링크
<br>https://school.programmers.co.kr/learn/courses/30/lessons/159993
{% endraw %}