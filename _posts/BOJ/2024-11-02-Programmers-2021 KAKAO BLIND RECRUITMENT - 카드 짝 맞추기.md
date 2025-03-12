---
categories:
- Programmers
date: '2024-11-02'
title: '[Programmers] 2021 KAKAO BLIND RECRUITMENT - 카드 짝 맞추기'
---

{% raw %}
> Lv. 3<br>

## 문제
게임 개발자인  `베로니`는 개발 연습을 위해 다음과 같은 간단한 카드 짝맞추기 보드 게임을 개발해 보려고 합니다.  
게임이 시작되면 화면에는 카드 16장이 뒷면을 위로하여  `4 x 4`  크기의 격자 형태로 표시되어 있습니다. 각 카드의 앞면에는 카카오프렌즈 캐릭터 그림이 그려져 있으며, 8가지의 캐릭터 그림이 그려진 카드가 각기 2장씩 화면에 무작위로 배치되어 있습니다.  
유저가 카드를 2장 선택하여 앞면으로 뒤집었을 때 같은 그림이 그려진 카드면 해당 카드는 게임 화면에서 사라지며, 같은 그림이 아니라면 원래 상태로 뒷면이 보이도록 뒤집힙니다. 이와 같은 방법으로 모든 카드를 화면에서 사라지게 하면 게임이 종료됩니다.

게임에서 카드를 선택하는 방법은 다음과 같습니다.

-   카드는  `커서`를 이용해서 선택할 수 있습니다.
    -   커서는 4 x 4 화면에서 유저가 선택한 현재 위치를 표시하는 "굵고 빨간 테두리 상자"를 의미합니다.
-   커서는 [Ctrl] 키와 방향키에 의해 이동되며 키 조작법은 다음과 같습니다.
    -   방향키 ←, ↑, ↓, → 중 하나를 누르면, 커서가 누른 키 방향으로 1칸 이동합니다.
    -   [Ctrl] 키를 누른 상태에서 방향키 ←, ↑, ↓, → 중 하나를 누르면, 누른 키 방향에 있는 가장 가까운 카드로 한번에 이동합니다.
        -   만약, 해당 방향에 카드가 하나도 없다면 그 방향의 가장 마지막 칸으로 이동합니다.
    -   만약, 누른 키 방향으로 이동 가능한 카드 또는 빈 공간이 없어 이동할 수 없다면 커서는 움직이지 않습니다.
-   커서가 위치한 카드를 뒤집기 위해서는 [Enter] 키를 입력합니다.
    -   [Enter] 키를 입력해서 카드를 뒤집었을 때
        -   앞면이 보이는 카드가 1장 뿐이라면 그림을 맞출 수 없으므로 두번째 카드를 뒤집을 때 까지 앞면을 유지합니다.
        -   앞면이 보이는 카드가 2장이 된 경우, 두개의 카드에 그려진 그림이 같으면 해당 카드들이 화면에서 사라지며, 그림이 다르다면 두 카드 모두 뒷면이 보이도록 다시 뒤집힙니다.

"베로니"는 게임 진행 중 카드의 짝을 맞춰 몇 장 제거된 상태에서 카드 앞면의 그림을 알고 있다면, 남은 카드를 모두 제거하는데 필요한 키 조작 횟수의 최솟값을 구해 보려고 합니다. 키 조작 횟수는 방향키와 [Enter] 키를 누르는 동작을 각각 조작 횟수  `1`로 계산하며, [Ctrl] 키와 방향키를 함께 누르는 동작 또한 조작 횟수  `1`로 계산합니다.

현재 카드가 놓인 상태를 나타내는 2차원 배열 board와 커서의 처음 위치 r, c가 매개변수로 주어질 때, 모든 카드를 제거하기 위한 키 조작 횟수의 최솟값을 return 하도록 solution 함수를 완성해 주세요.

### 제한사항
-   board는 4 x 4 크기의 2차원 배열입니다.
-   board 배열의 각 원소는 0 이상 6 이하인 자연수입니다.
    -   0은 카드가 제거된 빈 칸을 나타냅니다.
    -   1 부터 6까지의 자연수는 2개씩 들어있으며 같은 숫자는 같은 그림의 카드를 의미합니다.
    -   뒤집을 카드가 없는 경우(board의 모든 원소가 0인 경우)는 입력으로 주어지지 않습니다.
-   r은 커서의 최초 세로(행) 위치를 의미합니다.
-   c는 커서의 최초 가로(열) 위치를 의미합니다.
-   r과 c는 0 이상 3 이하인 정수입니다.
-   게임 화면의 좌측 상단이 (0, 0), 우측 하단이 (3, 3) 입니다.

## 해결
- 항상 현재 위치에 가까운 카드를 선택하는 것이 최적이 아닐 수 있습니다. 또한 어떤 카드 쌍을 먼저 제거하는 것이 이득인지 알 수 없으며, 각 카드 쌍을 제거하는 과정은 서로 종속적이므로 모든 경우를 탐색해야 합니다. => `백트래킹`
- 카드 쌍 제거 순서는 `순열`로 모든 경우를 찾을 수 있습니다. 제거할 카드 쌍이 정해졌을 때, 카드 1개를 뒤집으면 항상 쌍에 맞는 다른 카드를 뒤집는 것이 이득입니다. 하지만 2개의 카드 중에서 어떤 것을 먼저 뒤집는 것이 전체 횟수에서 최적인지는 알 수 없으므로 2가지 모두 확인해야 합니다. 카드 쌍 개수가 N일 때, 전체 순서의 경우의 수는 N! × 2<sup>N</sup>입니다.
- 보드 크기가 작으므로, 전체 보드를 탐색하는 방법으로 카드 쌍 순서를 정할 수도 있습니다. 이 방법을 사용하면 카드 쌍 순서와 쌍 내부 순서를 한꺼번에 정할 수 있어 구현할 때 편리합니다.
- 시작점과 목적지가 정해졌을 때, 최적의 이동 거리는 `최단거리 BFS`로 찾을 수 있습니다. 현재 위치(x, y)가 주어졌을 때, 인접 이동, 컨트롤 이동으로 가능한 다음 위치는 최대 8가지 입니다.
	- 컨트롤 이동: 격자 바깥을 만날 때까지 이동하며, 중간에 카드를 만나면 멈춥니다.

```
카드 쌍 백트래킹(커서 위치, 누적 이동거리): 
1. 보드의 모든 칸 탐색: 카드 찾기
	1. 현재 위치에 있는 카드 A와 대응되는 다른 카드 B 찾기
	2. 커서 위치, 카드 A의 최단 거리 찾기 (BFS)
	3. 카드 A, 카드 B의 최단 거리 찾기 (BFS)
	4. 카드 A, B 지우기
	5. 다음 카드 쌍 탐색(다음 커서 위치 = 카드 B 위치, 누적 이동거리 += 두 최단 거리 + 2)
	6. 카드 A, B 활성
2. 보드에 남은 카드가 없다면 최소 누적 이동거리 업데이트
```

## 코드
```
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
struct Point { int x, y; };
int minDist = 999999, dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 };
bool visited[4][4];
vector<vector<int>> board;
bool isOut(int x, int y) { return x < 0 || x >= 4 || y < 0 || y >= 4; }
Point findOther(int tx, int ty) {
    for (int y = 0; y < 4; y++)
        for (int x = 0; x < 4; x++)
            if (board[y][x] == board[ty][tx] && !(x == tx && y == ty))
                return { x, y };
}

int BFS(int x, int y, int gx, int gy) {
    memset(visited, 0, sizeof(visited));
    queue<Point> q; q.push({ x, y });
    visited[y][x] = 1;
    int dist = 0;
    while (1) {
        int size = q.size();
        while (size--) {
            Point c = q.front(); q.pop();
            if (c.x == gx && c.y == gy)
                return dist;
            for (int d = 0; d < 4; d++) {
                int nx = c.x + dx[d], ny = c.y + dy[d];
                if (!isOut(nx, ny) && !visited[ny][nx]) {
                    visited[ny][nx] = 1;
                    q.push({ nx, ny });
                }
            }
            for (int d = 0; d < 4; d++) {
                int nx = c.x, ny = c.y;
                for (; !isOut(nx + dx[d], ny + dy[d]); nx += dx[d], ny += dy[d])
                    if (board[ny][nx] > 0 && !(nx == c.x && ny == c.y))
                        break;
                if (!visited[ny][nx]) {
                    visited[ny][nx] = 1;
                    q.push({ nx, ny });
                }
            }
        }
        dist++;
    }
}

void BT(int x, int y, int distSum) {
    bool isEmpty = 1;
    for (int cy1 = 0; cy1 < 4; cy1++) {
        for (int cx1 = 0; cx1 < 4; cx1++) {
            if (board[cy1][cx1] > 0) {
                int card = board[cy1][cx1];
                Point p = findOther(cx1, cy1); int cx2 = p.x, cy2 = p.y;
                int dist1 = BFS(x, y, cx1, cy1), dist2 = BFS(cx1, cy1, cx2, cy2);
                board[cy2][cx2] = board[cy1][cx1] = 0;
                BT(cx2, cy2, distSum + dist1 + dist2 + 2);
                board[cy2][cx2] = board[cy1][cx1] = card;
                isEmpty = 0;
            }
        }
    }
    if (isEmpty)
        minDist = min(minDist, distSum); 
}

int solution(vector<vector<int>> boardI, int r, int c) {
    board = boardI; BT(c, r, 0);
    return minDist;
}
```

## 링크
<br>https://school.programmers.co.kr/learn/courses/30/lessons/72415
{% endraw %}