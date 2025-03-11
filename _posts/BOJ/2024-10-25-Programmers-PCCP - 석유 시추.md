---
categories:
- Programmers
date: '2024-10-25'
title: '[Programmers] PCCP - 석유 시추'
---

{% raw %}
> Lv. 2<br>

## 문제
세로길이가  `n`  가로길이가  `m`인 격자 모양의 땅 속에서 석유가 발견되었습니다. 석유는 여러 덩어리로 나누어 묻혀있습니다. 당신이 시추관을 수직으로  **단 하나만**  뚫을 수 있을 때, 가장 많은 석유를 뽑을 수 있는 시추관의 위치를 찾으려고 합니다. 시추관은 열 하나를 관통하는 형태여야 하며, 열과 열 사이에 시추관을 뚫을 수 없습니다.

시추관은 설치한 위치 아래로 끝까지 뻗어나갑니다. 만약 시추관이 석유 덩어리의 일부를 지나면 해당 덩어리에 속한 모든 석유를 뽑을 수 있습니다. 시추관이 뽑을 수 있는 석유량은 시추관이 지나는 석유 덩어리들의 크기를 모두 합한 값입니다.

석유가 묻힌 땅과 석유 덩어리를 나타내는 2차원 정수 배열  `land`가 매개변수로 주어집니다. 이때 시추관 하나를 설치해 뽑을 수 있는 가장 많은 석유량을 return 하도록 solution 함수를 완성해 주세요.

### 제한사항
-   1 ≤  `land`의 길이 = 땅의 세로길이 =  `n`  ≤ 500
    -   1 ≤  `land[i]`의 길이 = 땅의 가로길이 =  `m`  ≤ 500
    -   `land[i][j]`는  `i+1`행  `j+1`열 땅의 정보를 나타냅니다.
    -   `land[i][j]`는 0 또는 1입니다.
    -   `land[i][j]`가 0이면 빈 땅을, 1이면 석유가 있는 땅을 의미합니다.

## 해결
인접한 석유들을 조사합시다. => `그래프 탐색`<br>

```
1. 모든 칸 조사: 석유 덩어리 찾기
	- 석유 덩어리의 id, 석유량 저장
	- 현재 칸에 석유 덩어리 id 기록
2. 모든 열 조사: 최대 석유량 찾기
	- 현재 열에서 석유 덩어리 id 집합 찾기 (중복 없음)
	- 찾은 석유 덩어리의 총합으로 최대 석유량 업데이트
```

## 코드
```
#include <string>
#include <vector>
#include <queue>
using namespace std;
int N, M, genBank = 1, dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, -1, 0, 1 };
vector<vector<int>> landBoard; vector<int> oilBank = { 0 }; vector<bool> oilVisited;<br>
int oilBoard[501][501];

int DFS(int x, int y, int id) {
    int sum = 1;
    oilBoard[y][x] = id;
    for (int d = 0; d < 4; d++) {
        int nx = x + dx[d], ny = y + dy[d];
        if (nx >= 0 && nx < M && ny >= 0 && ny < N && oilBoard[ny][nx] == 0 && landBoard[ny][nx] == 1)
            sum += DFS(nx, ny, id);
    }
    return sum;
}

int solution(vector<vector<int>> land) {<br>
    landBoard = land; N = land.size(), M = land[0].size();
    for (int y = 0; y < N; y++)
        for (int x = 0; x < M; x++)
            if (landBoard[y][x] == 1 && oilBoard[y][x] == 0)
                oilBank.push_back(DFS(x, y, genBank++));
    for (int oil : oilBank)
        oilVisited.push_back(0);

    int maxOil = 0;
    for (int x = 0; x < M; x++) {
        int oil = 0;
        queue<int> q;<br>
        for (int y = 0; y < N; y++) {
            int id = oilBoard[y][x];
            if (id > 0 && !oilVisited[id]) {<br>
                oilVisited[id] = 1;
                q.push(id);
            }
        }
        while (!q.empty()) {
            int id = q.front(); q.pop();
            oil += oilBank[id];
            oilVisited[id] = 0;
        }
        maxOil = max(maxOil, oil);
    }
    return maxOil;
}
```

## 링크
https://school.programmers.co.kr/learn/courses/30/lessons/250136
{% endraw %}