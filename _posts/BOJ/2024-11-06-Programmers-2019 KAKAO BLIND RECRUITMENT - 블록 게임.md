---
categories:
- Programmers
date: '2024-11-06'
title: '[Programmers] 2019 KAKAO BLIND RECRUITMENT - 블록 게임'
---

{% raw %}
> Lv. 4<br>

## 문제
프렌즈 블록이라는 신규 게임이 출시되었고, 어마어마한 상금이 걸린 이벤트 대회가 개최 되었다.

이 대회는 사람을 대신해서 플레이할 프로그램으로 참가해도 된다는 규정이 있어서, 게임 실력이 형편없는 프로도는 프로그램을 만들어서 참가하기로 결심하고 개발을 시작하였다.

프로도가 우승할 수 있도록 도와서 빠르고 정확한 프로그램을 작성해 보자.

### 게임규칙
1×1 크기의 블록을 이어 붙여 만든 3 종류의 블록을 회전해서 총 12가지 모양의 블록을 만들 수 있다.

1 x 1 크기의 정사각형으로 이루어진 N x N 크기의 보드 위에 이 블록들이 배치된 채로 게임이 시작된다. (보드 위에 놓인 블록은 회전할 수 없다). 모든 블록은 블록을 구성하는 사각형들이 정확히 보드 위의 사각형에 맞도록 놓여있으며, 선 위에 걸치거나 보드를 벗어나게 놓여있는 경우는 없다.

플레이어는 위쪽에서 1 x 1 크기의 검은 블록을 떨어뜨려 쌓을 수 있다. 검은 블록은 항상 맵의 한 칸에 꽉 차게 떨어뜨려야 하며, 줄에 걸치면 안된다.  
이때, 검은 블록과 기존에 놓인 블록을 합해  **속이 꽉 채워진**  직사각형을 만들 수 있다면 그 블록을 없앨 수 있다.

보드 위에 놓인 블록의 상태가 담긴 2차원 배열 board가 주어질 때, 검은 블록을 떨어뜨려 없앨 수 있는 블록 개수의 최댓값을 구하라.

### 제한사항
-   board는 블록의 상태가 들어있는 N x N 크기 2차원 배열이다.
    -   N은  `4`  이상  `50`  이하다.
-   board의 각 행의 원소는  `0`  이상  `200`  이하의 자연수이다.
    -   0 은 빈 칸을 나타낸다.
    -   board에 놓여있는 각 블록은 숫자를 이용해 표현한다.
    -   잘못된 블록 모양이 주어지는 경우는 없다.
    -   모양에 관계 없이 서로 다른 블록은 서로 다른 숫자로 표현된다.

## 해결
검은 블록으로 제거 가능한 블록을 찾아야 합니다. => `시뮬레이션`<br>

블록 형태 판정은 `그래프 탐색`을 사용합니다.

어떠한 블록의 직사각형 영역에 다른 블록이 끼어 있다면 제거 불가능합니다. 이 때는 방해하는 다른 블록이 없어야 해당 블록을 제거할 수 있습니다. 어떠한 두 블록이 있을 때 두 블록의 최소 y가 서로 다르다면, 최소 y가 낮은 것이 항상 방해받지 않는 것이 보장됩니다. 따라서 y = 0부터 탐색을 시작해서 블록을 찾는 것이 유리합니다.

단, 두 블록의 최소 y가 같다면 서로 종속일 수 있으며, 아래는 그 예시입니다.
```
[[2, 0, 1, 0, 3],
 [2, 1, 1, 1, 3],
 [2, 2, 0, 3, 3]]
```
이 경우는 1번 블록을 제거해야 2, 3번 블록을 제거할 수 있습니다. 같은 y에서 탐색했을 때, 블록이 제거됐다면 다시 현재 y의 처음부터 탐색을 개시하면 해결할 수 있습니다. (`DFS`를 사용한다면 재방문을 할 필요가 있는데, 이 때는 현재 제거된 블록 수를 방문 캐시 값으로 하면 됩니다.)
```
1. y 맨 위쪽부터 스위핑 탐색: 걸리는 블록 있으면 해당 블록 조사
	1. 직사각형 좌표 찾기:
		- 직사각형 좌표: (min x, min y), (max x, max y)
	2. 직사각형 영역에서 채워야 할 칸 조사:
		- 해당 칸에서 위쪽에 검은블록 놓아서 없앨 수 있는지 판단
	3. 제거 가능하면 제거.
		- 제거되면 현재 y의 처음부터 탐색 시작.
```

## 코드
```
#include <vector>
using namespace std;
int N, M, cnt = 1, gx, gy, rx1, rx2, ry1, ry2, dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
vector<vector<int>> board;<br>
int visited[51][51];

void DFS(int x, int y, int id) {
    rx1 = min(rx1, x); rx2 = max(rx2, x);
    ry1 = min(ry1, y); ry2 = max(ry2, y);
    visited[y][x] = cnt;
    for (int d = 0; d < 4; d++) {
        int nx = x + dx[d], ny = y + dy[d];
        if (nx >= 0 && nx < N && ny >= 0 && ny < N && visited[ny][nx] != cnt && board[ny][nx] == id)
            DFS(nx, ny, id);
    }
}

bool canFill(int x, int y) {
    while (y >= 0 && board[y][x] == 0) y--;
    return y < 0 ? 1 : 0;
}

void isRect(int x, int y) {
    rx1 = rx2 = x, ry1 = ry2 = y;
    DFS(x, y, board[y][x]);
    bool ok = 1;
    for (int ty = ry1; ty <= ry2; ty++)
        for (int tx = rx1; tx <= rx2; tx++)
            if (board[ty][tx] != board[y][x])
                ok &= canFill(tx, ty);
    if (ok) {
        for (int ty = ry1; ty <= ry2; ty++)
            for (int tx = rx1; tx <= rx2; tx++)
                board[ty][tx] = 0;
        cnt++; gx = 0;
    }
}

int solution(vector<vector<int>> B) {<br>
    board = B, N = board.size();
    for (gy = 0; gy < N; gy++)
        for (gx = 0; gx < N; gx++)
            if (visited[gy][gx] != cnt && board[gy][gx] > 0)<br>
                isRect(gx, gy);
    return cnt - 1;
}
```

## 링크
https://school.programmers.co.kr/learn/courses/30/lessons/42894<br>
{% endraw %}