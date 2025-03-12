---
categories:
- Programmers
date: '2024-11-04'
title: '[Programmers] 2020 KAKAO BLIND RECRUITMENT - 블록 이동하기'
---

{% raw %}
> Lv. 3<br>

## 문제
로봇개발자  **"무지"**는 한 달 앞으로 다가온 "카카오배 로봇경진대회"에 출품할  **로봇**을 준비하고 있습니다. 준비 중인 로봇은  **`2 x 1`**  크기의 로봇으로 "무지"는  **"0"**과  **"1"**로 이루어진  **`N x N`**  크기의 지도에서  **`2 x 1`**  크기인 로봇을 움직여  **(N, N)**  위치까지 이동 할 수 있도록 프로그래밍을 하려고 합니다. 로봇이 이동하는 지도는 가장 왼쪽, 상단의 좌표를  **(1, 1)**로 하며 지도 내에 표시된 숫자  **"0"**은 빈칸을  **"1"**은 벽을 나타냅니다. 로봇은 벽이 있는 칸 또는 지도 밖으로는 이동할 수 없습니다. 로봇은 처음에 아래 그림과 같이 좌표  **(1, 1)**  위치에서 가로방향으로 놓여있는 상태로 시작하며, 앞뒤 구분없이 움직일 수 있습니다.

로봇이 움직일 때는 현재 놓여있는 상태를 유지하면서 이동합니다. 예를 들어, 위 그림에서 오른쪽으로 한 칸 이동한다면  **(1, 2), (1, 3)**  두 칸을 차지하게 되며, 아래로 이동한다면  **(2, 1), (2, 2)**  두 칸을 차지하게 됩니다. 로봇이 차지하는 두 칸 중 어느 한 칸이라도  **(N, N)**  위치에 도착하면 됩니다.

로봇은 90도씩 회전할 수 있습니다. 단, 로봇이 차지하는 두 칸 중, 어느 칸이든 축이 될 수 있지만, 회전하는 방향(축이 되는 칸으로부터 대각선 방향에 있는 칸)에는 벽이 없어야 합니다. 로봇이 한 칸 이동하거나 90도 회전하는 데는 걸리는 시간은 정확히 1초 입니다.

**"0"**과  **"1"**로 이루어진 지도인 board가 주어질 때, 로봇이  **(N, N)**  위치까지 이동하는데 필요한 최소 시간을 return 하도록 solution 함수를 완성해주세요.

### 제한사항
-   board의 한 변의 길이는 5 이상 100 이하입니다.
-   board의 원소는 0 또는 1입니다.
-   로봇이 처음에 놓여 있는 칸 (1, 1), (1, 2)는 항상 0으로 주어집니다.
-   로봇이 항상 목적지에 도착할 수 있는 경우만 입력으로 주어집니다.

## 해결
- 로봇이 이동하는 최단거리를 찾아야 합니다. => `최단거리 BFS`<br>
- 로봇의 회전 상태도 탐색에 영향을 주므로 위치 정점(x, y)에 회전 파라미터를 추가합니다.
- 로봇의 회전 기준점과 방향은 자유입니다. 어떠한 상황에서 로봇의 회전은 4가지가 가능합니다.
- 로봇 원점을 로봇의 좌측 상단으로 정의합니다. 회전시 원점 좌표가 바뀔 수 있습니다.

현재 정점을 (로봇의 원점 위치(x, y), 회전 각도)로 정의합니다. 회전 각도의 값은 0과 1이며, 각각 가로, 세로를 의미합니다.

다음 정점은 평행 이동 4방향, 제자리 회전 4가지로 총 8가지입니다. 평행 이동은 다음 위치에 있는 벽 유무만 고려하면 되지만, 제자리 회전은 축이 되는 칸으로부터 대각선 방향에 있는 칸의 벽 유무를 추가로 판정해야 합니다. 현재 각도에 대해 각 회전을 case work하면 다음과 같습니다:
```
. - 빈 칸, X - 로봇 원점, O - 로봇, c - 추가로 벽 판정할 칸

각도 = 가로
. .
X O
. .

4가지 회전
O c      . .      . .      c X
X .      X .      . X      . O
. .      O c      c O      . .


각도 = 세로
. X .
. O .

4가지 회전
X O .      . X O      c . .      . . c
c . .      . . c      X O .      . X O
```

## 코드
```
#include <vector>
#include <queue>
struct Node { int x, y, a; };
using namespace std;
int N, M, dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 };
int dist[102][102][2]; // 0: hor, 1: ver
vector<vector<int>> board;<br>
queue<Node> q;<br>
bool isSafe(int x, int y) { return !(x < 0 || x >= M || y < 0 || y >= N || board[y][x]); }
void add(int x, int y, int a, int d) {
    if (isSafe(x, y) && isSafe(x + dx[a], y + dy[a]) && dist[y][x][a] == 0) {
        q.push({ x, y, a });
        dist[y][x][a] = d + 1;
    }
}

int solution(vector<vector<int>> boardI) {<br>
    board = boardI; N = board.size(), M = board[0].size();
    q.push({ 0, 0, 0 }); dist[0][0][0] = 1;
    while (1) {
        auto c = q.front(); q.pop();
        int x = c.x, y = c.y, a = c.a;
        if ((x == M - 1 && y == N - 1) || (x + dx[a] == M - 1 && y + dy[a] == N - 1))
            return dist[y][x][a] - 1;

        for (int d = 0; d < 4; d++)
            add(x + dx[d], y + dy[d], a, dist[y][x][a]);
        if(a == 0) {
            if(isSafe(x + 1, y + 1))
                add(x, y, 1, dist[y][x][a]);
            if(isSafe(x, y + 1))
                add(x + 1, y, 1, dist[y][x][a]);
            if(isSafe(x + 1, y - 1))
                add(x, y - 1, 1, dist[y][x][a]);
            if(isSafe(x, y - 1))
                add(x + 1, y - 1, 1, dist[y][x][a]);
        }
        if(a == 1) {
            if(isSafe(x + 1, y + 1))
                add(x, y, 0, dist[y][x][a]);
            if(isSafe(x - 1, y + 1))
                add(x - 1, y, 0, dist[y][x][a]);
            if(isSafe(x + 1, y))
                add(x, y + 1, 0, dist[y][x][a]);
            if(isSafe(x - 1, y))
                add(x - 1, y + 1, 0, dist[y][x][a]);
        }
    }
    return 0;
}
```

## 링크
https://school.programmers.co.kr/learn/courses/30/lessons/60063<br>
{% endraw %}