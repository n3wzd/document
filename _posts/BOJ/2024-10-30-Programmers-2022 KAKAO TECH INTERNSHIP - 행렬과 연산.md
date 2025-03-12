---
categories:
- Programmers
date: '2024-10-30'
title: '[Programmers] 2022 KAKAO TECH INTERNSHIP - 행렬과 연산'
---

{% raw %}
> Lv. 4<br>

## 문제
당신은 행렬에 적용할 수 있는 두 가지 연산을 만들었습니다.

-   **ShiftRow**
    -   모든 행이 아래쪽으로 한 칸씩 밀려납니다. 즉, 모든 행에 대해서  `i`번째 행은  `i+1`번째 행이 됩니다. (마지막 행은 1번째 행이 됩니다.)

-   **Rotate**
    -   행렬의 바깥쪽에 있는 원소들을 시계 방향으로 한 칸 회전시킵니다.
    -   행렬의 바깥쪽에 있는 원소들은 첫 행, 첫 열, 끝 행, 끝 열에 포함되는 원소들입니다.
    -   한 칸 회전시킨다는 것은 이 원소들이 시계 방향으로 한 칸씩 밀려난다는 것을 의미합니다. 즉, 다음 4개의 연산이 동시에 시행됩니다.
        -   첫 행에서 끝 열에 있는 원소를 제외한 첫 행의 모든 원소는 오른쪽으로 한 칸 이동합니다.
        -   끝 열에서 끝 행에 있는 원소를 제외한 끝 열의 모든 원소는 아래쪽으로 한 칸 이동합니다.
        -   끝 행에서 첫 열에 있는 원소를 제외한 끝 행의 모든 원소는 왼쪽으로 한 칸 이동합니다.
        -   첫 열에서 첫 행에 있는 원소를 제외한 첫 열의 모든 원소는 위쪽으로 한 칸 이동합니다.

당신은 행렬에 연산을 여러 번 시행하려고 합니다.  
행렬의 초기 상태를 담고 있는 2차원 정수 배열  `rc`, 시행할 연산을 순서대로 담고 있는 문자열 배열  `operations`가 매개변수로 주어졌을 때, 연산을 차례대로 시행한 후의 행렬 상태를 return 하도록 solution 함수를 완성해주세요.

### 제한사항
-   2 ≤  `rc`의 행 길이(=행렬의 가로 길이) ≤ 50,000
    -   `rc`의 모든 행의 길이는 동일합니다.
-   2 ≤  `rc`의 열 길이(=행렬의 세로 길이) ≤ 50,000
    -   `rc`의 모든 열의 길이는 동일합니다.
-   4 ≤  `rc`의 행 길이 x  `rc`의 열 길이 ≤ 100,000
-   `rc[i][j]`  는  `i+1`번째 행  `j+1`번째 열에 있는 원소를 나타냅니다.
    -   1 ≤  `rc[i][j]`  ≤ 1,000,000
-   1 ≤  `operations`의 길이 ≤ 100,000
    -   `operations`의 원소는  `"ShiftRow"`  혹은  `"Rotate"`입니다.

## 해결
입력 데이터가 크므로 쿼리를 빠르게 수행해야 합니다. 두 쿼리는 서로 종속적이며 교환 법칙이 성립하지 않습니다. 이동 쿼리는 항상 행 변경만 발생하고, 회전 쿼리는 가로 또는 세로 단위로 수가 1칸씩 옮겨 간다는 점에서 `덱`를 사용하면 빠르게 수행할 수 있습니다.

행렬의 가장 끝 열을 저장하는 덱 2개, 모든 행을 저장하는 덱 N개를 생성합니다. (N: 행 개수) 각 쿼리에 대한 연산은 다음과 같으며, 모두 O(1) 시간이 걸립니다.

**Rotate**
1. 가장 위 가로 덱에서 오른쪽 pop한 것을 오른쪽 세로 덱 가장 위에 push
2. 오른쪽 세로 덱 아래를 pop한 것을 가장 아래 가로 덱 오른쪽에 push
3. 가장 아래 가로 덱에서 왼쪽 pop한 것을 왼쪽 세로 덱 아래에 push
4. 왼쪽 세로 덱 위를 pop한 것을 가장 위 가로 덱 왼쪽에 push

**Shift**
1. 가장 위 가로 덱, 가장 아래 가로 덱 변경 (1칸 위에 있는 덱)
2. 각 세로 덱 아래를 pop한 것을 위쪽에 push

- 열의 길이는 2일 수 있으므로 가로 행 덱이 비어 있을 수 있습니다. 이에 대한 예외 처리를 따로 추가해줍니다.

## 코드
```
#include <string>
#include <vector>
#include <queue>
using namespace std;
deque<int> row[50001], col[2];
int N, M, baseY;

vector<vector<int>> solution(vector<vector<int>> rc, vector<string> operations) {
    vector<vector<int>> answer;
    N = rc.size(), M = rc[0].size();
    for (int y = 0; y < N; y++)
        for (int x = 1; x < M - 1; x++)
            row[y].push_back(rc[y][x]);
    for (int x = 0; x < 2; x++)
        for (int y = 0; y < N; y++)
            col[x].push_back(rc[y][x * (M - 1)]);
    for (auto cmd : operations) {
        if (cmd == "Rotate") {
            if (M > 2) {
                int prevY = (baseY - 1 + N) % N;
                col[1].push_front(row[baseY].back()); row[baseY].pop_back();
                row[prevY].push_back(col[1].back()); col[1].pop_back();
                col[0].push_back(row[prevY].front()); row[prevY].pop_front();
                row[baseY].push_front(col[0].front()); col[0].pop_front();
            }
            else {
                col[1].push_front(col[0].front()); col[0].pop_front();
                col[0].push_back(col[1].back()); col[1].pop_back();
            }
        }
        if (cmd == "ShiftRow") {
            baseY = (baseY - 1 + N) % N;
            for (int x = 0; x < 2; x++)
                col[x].push_front(col[x].back()), col[x].pop_back();
        }
    }
    for (int y = 0; y < N; y++)
        for (int x = 1; x < M - 1; x++)
            rc[y][x] = row[(y + baseY) % N].front(), row[(y + baseY) % N].pop_front();
    for (int x = 0; x < 2; x++)
        for (int y = 0; y < N; y++)
            rc[y][x * (M - 1)] = col[x].front(), col[x].pop_front();
    return rc;
}
```

## 링크
<br>https://school.programmers.co.kr/learn/courses/30/lessons/118670
{% endraw %}