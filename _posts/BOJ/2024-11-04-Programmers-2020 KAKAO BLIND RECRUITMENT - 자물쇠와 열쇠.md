---
categories:
- Programmers
date: '2024-11-04'
title: '[Programmers] 2020 KAKAO BLIND RECRUITMENT - 자물쇠와 열쇠'
---

{% raw %}
> Lv. 3<br>

## 문제
고고학자인  **"튜브"**는 고대 유적지에서 보물과 유적이 가득할 것으로 추정되는 비밀의 문을 발견하였습니다. 그런데 문을 열려고 살펴보니 특이한 형태의  **자물쇠**로 잠겨 있었고 문 앞에는 특이한 형태의  **열쇠**와 함께 자물쇠를 푸는 방법에 대해 다음과 같이 설명해 주는 종이가 발견되었습니다.

잠겨있는 자물쇠는 격자 한 칸의 크기가  **`1 x 1`**인  **`N x N`**  크기의 정사각 격자 형태이고 특이한 모양의 열쇠는  **`M x M`**  크기인 정사각 격자 형태로 되어 있습니다.

자물쇠에는 홈이 파여 있고 열쇠 또한 홈과 돌기 부분이 있습니다. 열쇠는 회전과 이동이 가능하며 열쇠의 돌기 부분을 자물쇠의 홈 부분에 딱 맞게 채우면 자물쇠가 열리게 되는 구조입니다. 자물쇠 영역을 벗어난 부분에 있는 열쇠의 홈과 돌기는 자물쇠를 여는 데 영향을 주지 않지만, 자물쇠 영역 내에서는 열쇠의 돌기 부분과 자물쇠의 홈 부분이 정확히 일치해야 하며 열쇠의 돌기와 자물쇠의 돌기가 만나서는 안됩니다. 또한 자물쇠의 모든 홈을 채워 비어있는 곳이 없어야 자물쇠를 열 수 있습니다.

열쇠를 나타내는 2차원 배열 key와 자물쇠를 나타내는 2차원 배열 lock이 매개변수로 주어질 때, 열쇠로 자물쇠를 열수 있으면 true를, 열 수 없으면 false를 return 하도록 solution 함수를 완성해주세요.

### 제한사항
-   key는 M x M(3 ≤ M ≤ 20, M은 자연수)크기 2차원 배열입니다.
-   lock은 N x N(3 ≤ N ≤ 20, N은 자연수)크기 2차원 배열입니다.
-   M은 항상 N 이하입니다.
-   key와 lock의 원소는 0 또는 1로 이루어져 있습니다.
    -   0은 홈 부분, 1은 돌기 부분을 나타냅니다.

## 해결
- 열쇠를 회전하거나 이동하여 자물쇠가 맞는지 확인해야 합니다. => `브루트포스`<br>
- 열쇠 회전은 0도, 90도, 180도, 270도 4가지 방법이 존재하며, `배열 회전`으로 4가지 열쇠를 만들어줍시다.
- 4가지 열쇠를 자물쇠의 모든 위치에 대입해봅니다. 자물쇠의 원점을 (0, 0)으로 가정했을 때, 열쇠의 원점은 (-(N - 1), -(N - 1))부터 (M - 1, M - 1)까지 가능합니다. => `슬라이딩 윈도우`<br>
- 열쇠 칸이 자물쇠 바깥에 있다면 자물쇠 홈만 고려합니다. 그렇지 않으면 열쇠 칸과 대응되는 자물쇠 칸을 `XOR` 연산합니다.
- 자물쇠 홈이 모두 1인 경우가 있습니다. 이 때는 열쇠 모양 관계없이 최종 값이 `true`입니다.

## 코드
```
#include <string>
#include <vector>
#include <iostream>
using namespace std;
int N, M;
bool key[4][21][21];
vector<vector<int>> lock;<br>
bool isOut(int x, int y) { return x < 0 || x >= M || y < 0 || y >= M; }

void rotate(int x, int y, int d) {
    bool even = M % 2 == 0; int c = even ? M / 2 - 1 : M / 2;
    int dx = x - c + (even && x <= c ? -1 : 0), dy = y - c + (even && y <= c ? -1 : 0);
    int nx = c + dy, ny = c - dx;
    key[d + 1][ny + (even && ny <= c ? 1 : 0)][nx + (even && nx <= c ? 1 : 0)] = key[d][y][x];
}

void rotateAll() {
    for (int d = 0; d < 3; d++)
        for (int y = 0; y < M; y++)
            for (int x = 0; x < M; x++)
                rotate(x, y, d);
}

bool isPass(int d, int by, int bx) {    
    bool ok = 1;
    for (int y = 0; y < N; y++)
        for (int x = 0; x < N; x++)
            ok &= isOut(bx + x, by + y) ? lock[y][x] : (lock[y][x] ^ key[d][by + y][bx + x]);
    return ok;
}

bool solution(vector<vector<int>> keyI, vector<vector<int>> lockI) {<br>
    M = keyI.size(), N = lockI.size(); lock = lockI;
    bool ok = 1;
    for (int y = 0; y < N; y++)
        for (int x = 0; x < N; x++)
            ok &= lock[y][x];
    if(ok) return 1;
    for (int y = 0; y < M; y++)
        for (int x = 0; x < M; x++)
            key[0][y][x] = keyI[y][x];
    rotateAll();
    for (int y = -(N - 1); y < M; y++)
        for (int x = -(N - 1); x < M; x++)
            for(int d = 0; d < 4; d++)
                if(isPass(d, x, y))
                    return 1;
    return 0;
}
```

## 링크
https://school.programmers.co.kr/learn/courses/30/lessons/60059
{% endraw %}