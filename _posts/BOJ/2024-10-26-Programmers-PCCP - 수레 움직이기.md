---
categories:
- Programmers
date: '2024-10-26'
title: '[Programmers] PCCP - 수레 움직이기'
---

{% raw %}
> Lv. 3<br>

## 문제
`n`  x  `m`  크기 격자 모양의 퍼즐판이 주어집니다.

퍼즐판에는 빨간색 수레와 파란색 수레가 하나씩 존재합니다. 각 수레들은 자신의 시작 칸에서부터 자신의 도착 칸까지 이동해야 합니다.  
모든 수레들을 각자의 도착 칸으로 이동시키면 퍼즐을 풀 수 있습니다.

당신은 각 턴마다  **반드시 모든 수레를 상하좌우로 인접한 칸 중 한 칸으로 움직여야 합니다.**  단, 수레를 움직일 때는 아래와 같은 규칙이 있습니다.
-   수레는 벽이나 격자 판 밖으로 움직일 수 없습니다.
-   수레는 자신이 방문했던 칸으로 움직일 수 없습니다.
-   자신의 도착 칸에 위치한 수레는  **움직이지 않습니다.**  계속 해당 칸에 고정해 놓아야 합니다.
-   동시에 두 수레를 같은 칸으로 움직일 수 없습니다.
-   수레끼리 자리를 바꾸며 움직일 수 없습니다.

퍼즐판의 정보를 나타내는 2차원 정수 배열  `maze`가 매개변수로 주어집니다. 퍼즐을 푸는데 필요한 턴의 최솟값을 return 하도록 solution 함수를 완성해 주세요. 퍼즐을 풀 수 없는 경우 0을 return 해주세요.

### 제한사항
-   1 ≤  `maze`의 길이 (= 세로 길이) ≤ 4
    -   1 ≤  `maze[i]`의 길이 (= 가로 길이) ≤ 4
    -   `maze[i][j]`는 0,1,2,3,4,5 중 하나의 값을 갖습니다.
    -   빨간 수레의 시작 칸, 빨간 수레의 도착 칸, 파란 수레의 시작 칸, 파란 수레의 도착 칸은 퍼즐판에 1개씩 존재합니다.

## 해결
수레를 움직이는 모든 턴을 조사합니다. =>`백트래킹`

현재 턴의 상태는 두 수레의 위치(x, y)와 두 수레의 각 방문 상태(NxM 배열)입니다.
```
현재 턴 조사(수레 R, 수레 B, 현재 턴)
1. R, B가 골 지점에 있으면 탐색 종료
	- 최소 턴 업데이트
2. 각 수레의 현재 지점에 방문 표시
3. R의 다음 이동 방향 조사
	- 현재 위치가 골이면 자리 고정
	- 격자 밖, 벽, 이전 방문 지점으로 갈 수 없음
	- B의 다음 이동 방향 조사
		- 현재 위치가 골이면 자리 고정
		- 격자 밖, 벽, 이전 방문 지점으로 갈 수 없음
		- R, B의 다음 위치가 서로 같은 위치면 불가
		- R이 B의 이전 위치이고 B가 R의 이전 위치면 불가
		- 다음 턴 조사(R의 다음 위치, B의 다음 위치, 턴 +1)
4. 각 수레의 현재 지점에 방문 표시 해제
```

## 코드
```
#include <vector>
using namespace std;
struct Point { int x, y; };
struct PointSet { Point r = { 0, 0 }, b = { 0, 0 }; };
int N, M, minTurn = 999, dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 };
vector<vector<int>> board;<br>
bool visitedR[4][4], visitedB[4][4];
Point RG, BG;

void DFS(Point r, Point b, int turn) {
    bool isRGoal = r.x == RG.x && r.y == RG.y, isBGoal = b.x == BG.x && b.y == BG.y;
    if (isRGoal && isBGoal) {
        minTurn = min(turn, minTurn);
        return;
    }
    visitedR[r.y][r.x] = visitedB[b.y][b.x] = 1;
    int nx, ny, mx, my;
    for (int d1 = 0; d1 < 4; d1++) {
        if (isRGoal)
            nx = r.x, ny = r.y, d1 += 4;
        else
            nx = r.x + dx[d1], ny = r.y + dy[d1];
        if (nx < 0 || nx >= M || ny < 0 || ny >= N || board[ny][nx] == 5 || (visitedR[ny][nx] && !isRGoal))
            continue;
        for (int d2 = 0; d2 < 4; d2++) {
            if (isBGoal)
                mx = b.x, my = b.y, d2 += 4;
            else
                mx = b.x + dx[d2], my = b.y + dy[d2];
            if (mx < 0 || mx >= M || my < 0 || my >= N || board[my][mx] == 5 || (visitedB[my][mx] && !isBGoal))
                continue;
            if ((nx == mx && ny == my) || (nx == b.x && ny == b.y && mx == r.x && my == r.y))
                continue;
            DFS({ nx, ny }, { mx, my }, turn + 1);
        }
    }
    visitedR[r.y][r.x] = visitedB[b.y][b.x] = 0;
}

int solution(vector<vector<int>> maze) {<br>
    Point r, b;
    board = maze, N = maze.size(), M = maze[0].size();
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            if (maze[y][x] == 1) r = { x, y };
            if (maze[y][x] == 2) b = { x, y };
            if (maze[y][x] == 3) RG = { x, y };
            if (maze[y][x] == 4) BG = { x, y };
        }
    }
    DFS(r, b, 0);
    return minTurn == 999 ? 0 : minTurn;
}
```

## 링크
https://school.programmers.co.kr/learn/courses/30/lessons/250134<br>
{% endraw %}