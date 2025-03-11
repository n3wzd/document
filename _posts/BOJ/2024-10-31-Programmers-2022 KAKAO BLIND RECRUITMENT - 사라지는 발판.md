---
categories:
- Programmers
date: '2024-10-31'
title: '[Programmers] 2022 KAKAO BLIND RECRUITMENT - 사라지는 발판'
---

{% raw %}
> Lv. 3<br>

## 문제
플레이어 A와 플레이어 B가 서로 게임을 합니다. 당신은 이 게임이 끝날 때까지 양 플레이어가 캐릭터를 몇 번 움직이게 될지 예측하려고 합니다.

각 플레이어는 자신의 캐릭터 하나를 보드 위에 올려놓고 게임을 시작합니다. 게임 보드는 1x1 크기 정사각 격자로 이루어져 있으며, 보드 안에는 발판이 있는 부분과 없는 부분이 있습니다. 발판이 있는 곳에만 캐릭터가 서있을 수 있으며, 처음 캐릭터를 올려놓는 곳은 항상 발판이 있는 곳입니다. 캐릭터는 발판이 있는 곳으로만 이동할 수 있으며, 보드 밖으로 이동할 수 없습니다. 밟고 있던 발판은 그 위에 있던 캐릭터가 다른 곳으로 이동하여 다른 발판을 밞음과 동시에 사라집니다. 양 플레이어는 번갈아가며 자기 차례에 자신의 캐릭터를 상하좌우로 인접한 4개의 칸 중에서 발판이 있는 칸으로 옮겨야 합니다.

다음과 같은 2가지 상황에서 패자와 승자가 정해지며, 게임이 종료됩니다.

-   움직일 차례인데 캐릭터의 상하좌우 주변 4칸이 모두 발판이 없거나 보드 밖이라서 이동할 수 없는 경우, 해당 차례 플레이어는 패배합니다.
-   두 캐릭터가 같은 발판 위에 있을 때, 상대 플레이어의 캐릭터가 다른 발판으로 이동하여 자신의 캐릭터가 서있던 발판이 사라지게 되면 패배합니다.

게임은 항상 플레이어 A가 먼저 시작합니다. 양 플레이어는 최적의 플레이를 합니다. 즉, 이길 수 있는 플레이어는 최대한 빨리 승리하도록 플레이하고, 질 수밖에 없는 플레이어는 최대한 오래 버티도록 플레이합니다. '이길 수 있는 플레이어'는 실수만 하지 않는다면 항상 이기는 플레이어를 의미하며, '질 수밖에 없는 플레이어'는 최선을 다해도 상대가 실수하지 않으면 항상 질 수밖에 없는 플레이어를 의미합니다. 최대한 오래 버틴다는 것은 양 플레이어가 캐릭터를 움직이는 횟수를 최대화한다는 것을 의미합니다.

게임 보드의 초기 상태를 나타내는 2차원 정수 배열  `board`와 플레이어 A의 캐릭터 초기 위치를 나타내는 정수 배열  `aloc`, 플레이어 B의 캐릭터 초기 위치를 나타내는 정수 배열  `bloc`이 매개변수로 주어집니다. 양 플레이어가 최적의 플레이를 했을 때, 두 캐릭터가 움직인 횟수의 합을 return 하도록 solution 함수를 완성해주세요.

### 제한사항
-   1 ≤  `board`의 세로 길이 ≤ 5
-   1 ≤  `board`의 가로 길이 ≤ 5
-   `board`의 원소는 0 또는 1입니다.
    -   0은 발판이 없음을, 1은 발판이 있음을 나타냅니다.
    -   게임 보드의 좌측 상단 좌표는 (0, 0), 우측 하단 좌표는 (`board`의 세로 길이 - 1,  `board`의 가로 길이 - 1)입니다.
-   `aloc`과  `bloc`은 각각 플레이어 A의 캐릭터와 플레이어 B의 캐릭터 초기 위치를 나타내는 좌표값이며 [r, c] 형태입니다.
    -   r은 몇 번째 행인지를 나타냅니다.
    -   0 ≤ r <  `board`의 세로 길이
    -   c는 몇 번째 열인지를 나타냅니다.
    -   0 ≤ c <  `board`의 가로 길이
    -   초기 보드의  `aloc`과  `bloc`  위치는 항상 발판이 있는 곳입니다.
    -   `aloc`과  `bloc`이 같을 수 있습니다.
-   상대 플레이어의 캐릭터가 있는 칸으로 이동할 수 있습니다.

## 해결
- 플레이어는 최적의 플레이를 한다는 것은 자신의 턴에서 자신이 지는 경우를 선택하지 않는 것과 같습니다. 무승부가 존재하지 않고 현재 턴에서 패배하는 경우는 선택에서 제외되므로, 어떤 상황이든 승패는 반드시 결정됩니다. (즉, 시작부터 승리, 패배를 알 수 있습니다.) => `Minimax Tree`<br>
	- 현재 턴에서 승리 선택지가 하나라도 존재한다면 이길 수 있는 상황입니다. 최대한 빨리 승리해야 하므로, 승리 선택지 중 최대 턴이 최소가 되는 선택지를 고릅니다.
	- 현재 턴에서 승리 선택지가 없다면 질 수밖에 없는 상황입니다. 최대한 오래 버텨야 하므로, 최대 턴이 최대가 되는 선택지를 고릅니다.
- `백트래킹`으로 모든 경우를 탐색합니다. 현재 상태는 (자신의 위치, 상대의 위치, 현재 플레이어, 현재 턴 수)이며, 결과 값은 (승리자, 최대 종료 턴수)입니다. 결과 값은 단일 정수로 표현할 수 있으며, 현재 플레이어와 승리자는 부호로 표현됩니다.
	- 탐색 결과 중에서 자신과 같은 부호의 정수가 존재하면 절댓값의 최솟값을 선택합니다.
	- 탐색 결과 중에서 자신과 같은 부호의 정수가 존재하지 않으면 절댓값의 최댓값을 선택합니다.
	- 패배하는 상황은 이동 가능한 칸이 없거나 현재 위치에 발판이 없는 경우입니다.

**예시**
```
예) 턴 수 | 현재 플레이어 | 분기별 게임 승리자
1. A:         B                 A
2. B:     B      -A-        A        A
3. A:   B   B                    -B-    A
4. B:                                  A A
```
- 4턴에서 B는 패배하며, 플레이어 반대 부호를 취한 현재 턴 수를 반환합니다.
- 2턴에서 B 선택지 중에 A가 승리하는 선택지가 있으며, 선택에서 제외됩니다. 이는 3턴에서 A도 마찬가지입니다.
- 이렇게 승리하는 선택지만 취한다면 어떤 상황이든 승패자를 알 수 있습니다.

## 코드
```
#include <vector>
#include <cmath>
using namespace std;
vector<vector<int>> board;<br>
int N, M, resTurn, dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 };
bool isOut(int x, int y) { return x < 0 || x >= M || y < 0 || y >= N || board[y][x] == 0; }
bool isWin(int player, int target) { return player * target > 0; }<br>

bool willLose(int x, int y) {
    bool flag = 1;
    for (int d = 0; d < 4; d++)
        flag &= isOut(x + dx[d], y + dy[d]);
    return flag || board[y][x] == 0;
}

int game(int x1, int y1, int x2, int y2, int player, int turn) {
    if (willLose(x1, y1))
        return -turn * player;
    vector<int> winCase, loseCase;<br>
    board[y1][x1] = 0;
    for (int d = 0; d < 4; d++) {
        int nx = x1 + dx[d], ny = y1 + dy[d];
        if (!isOut(nx, ny)) {
            int res = game(x2, y2, nx, ny, player * -1, turn + 1);
            isWin(player, res) ? winCase.push_back(res) : loseCase.push_back(res);
        }
    }
    board[y1][x1] = 1;

    if (winCase.size() > 0) {<br>
        int res = 99;
        for (int r : winCase)
            res = min(res, abs(r));
        return res * player;
    }
    else {
        int res = 0;
        for (int r : loseCase)
            res = max(res, abs(r));
        return -res * player;
    }
}

int solution(vector<vector<int>> b, vector<int> aloc, vector<int> bloc) {<br>
    N = b.size(), M = b[0].size(), board = b;
    return abs(game(aloc[1], aloc[0], bloc[1], bloc[0], 1, 0));
}
```

## 링크
https://school.programmers.co.kr/learn/courses/30/lessons/92345
{% endraw %}