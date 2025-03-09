---
categories:
- Programmers
date: '2024-11-21'
title: '[Programmers] 월간 코드 챌린지 시즌3 - 빛의 경로 사이클'
---

{% raw %}
> Lv. 2<br>

## 문제
각 칸마다 S, L, 또는 R가 써져 있는 격자가 있습니다. 당신은 이 격자에서 빛을 쏘고자 합니다. 이 격자의 각 칸에는 다음과 같은 특이한 성질이 있습니다.

-   빛이 "S"가 써진 칸에 도달한 경우, 직진합니다.
-   빛이 "L"이 써진 칸에 도달한 경우, 좌회전을 합니다.
-   빛이 "R"이 써진 칸에 도달한 경우, 우회전을 합니다.
-   빛이 격자의 끝을 넘어갈 경우, 반대쪽 끝으로 다시 돌아옵니다. 예를 들어, 빛이 1행에서 행이 줄어드는 방향으로 이동할 경우, 같은 열의 반대쪽 끝 행으로 다시 돌아옵니다.

당신은 이 격자 내에서 빛이 이동할 수 있는 경로 사이클이 몇 개 있고, 각 사이클의 길이가 얼마인지 알고 싶습니다. 경로 사이클이란, 빛이 이동하는 순환 경로를 의미합니다.

격자의 정보를 나타내는 1차원 문자열 배열  `grid`가 매개변수로 주어집니다. 주어진 격자를 통해 만들어지는 빛의 경로 사이클의 모든 길이들을 배열에 담아 오름차순으로 정렬하여 return 하도록 solution 함수를 완성해주세요.

### 제한사항
-   1 ≤  `grid`의 길이 ≤ 500
    -   1 ≤  `grid`의 각 문자열의 길이 ≤ 500
    -   `grid`의 모든 문자열의 길이는 서로 같습니다.
    -   `grid`의 모든 문자열은  `'L', 'R', 'S'`로 이루어져 있습니다.

## 해결
어떠한 위치와 방향을 시작으로 했을 때, 두 경로가 완전히 일치한다면 같은 사이클입니다. `그래프 탐색`으로 사이클을 순회할 수 있습니다.

모든 위치, 각 4방향을 탐색하여 시작점이 될 수 있는지 확인합니다. 한번 방문한 (위치, 방향)은 이미 방문한 사이클의 일부이므로 탐색하지 않습니다. 만약 방문하지 않았다면 항상 신규 사이클이므로 현재  (위치, 방향)을 시작점으로 해서 사이클을 순회합니다. 사이클 순회할 때는 방문한 (위치, 방향)을 모두 방문 표시하고, 다시 시작점에 왔을 때 사이클 길이를 정답에 추가합니다. 

## 코드
```
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int N, M, dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 };
bool visited[501][501][4];
vector<string> G; vector<int> answer;<br>

void cycle(int x, int y, int d, int sx, int sy, int sd, int len = 0) {
    if(x == sx && y == sy && d == sd && len > 0) {<br>
        answer.push_back(len);
        return;
    }
    visited[y][x][d] = 1;
    if(G[y][x] == 'L')
        d = (d + 3) % 4;
    if(G[y][x] == 'R')
        d = (d + 1) % 4;
    cycle((x + dx[d] + M) % M, (y + dy[d] + N) % N, d, sx, sy, sd, len + 1);
}

vector<int> solution(vector<string> grid) {<br>
    N = grid.size(), M = grid[0].size(); G = grid;
    for(int y = 0; y < N; y++)
        for(int x = 0; x < M; x++)
            for(int d = 0; d < 4; d++)
                if(!visited[y][x][d])
                    cycle(x, y, d, x, y, d);
    sort(answer.begin(), answer.end());
    return answer;
}
```

## 링크
https://school.programmers.co.kr/learn/courses/30/lessons/86052
{% endraw %}