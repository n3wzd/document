---
categories:
- Programmers
date: '2024-12-17'
title: '[Programmers] 연습문제 - 2차원 동전 뒤집기'
---

{% raw %}
> Lv. 3<br>

## 문제
한수는 직사각형 모양의 공간에 놓인 동전들을 뒤집는 놀이를 하고 있습니다. 모든 동전들은 앞과 뒤가 구분되어 있으며, 동전을 뒤집기 위해서는 같은 줄에 있는 모든 동전을 뒤집어야 합니다. 동전들의 초기 상태와 목표 상태가 주어졌을 때, 초기 상태에서 최소 몇 번의 동전을 뒤집어야 목표 상태가 되는지 알아봅시다.

예를 들어, 위 그림에서 맨 왼쪽이 초기 상태, 맨 오른쪽이 목표 상태인 경우에 대해 알아봅시다. 그림에서 검은색 원은 앞면인 동전, 흰색 원은 뒷면인 동전을 의미합니다. 초기 상태에서 2행과 4행의 돌들을 뒤집으면, 두 번째 그림이 됩니다. 그 후, 2열, 4열, 5열의 돌들을 순서대로 뒤집는 다면, 총 5번의 동전 뒤집기를 통해 목표 상태가 되며, 이 경우가 최소인 경우입니다.

직사각형 모양의 공간에 놓인 동전들의 초기 상태를 나타내는 2차원 정수 배열  `beginning`, 목표 상태를 나타내는  `target`이 주어졌을 때, 초기 상태에서 목표 상태로 만들기 위해 필요한 동전 뒤집기 횟수의 최솟값을 return 하는 solution 함수를 완성하세요. 단, 목표 상태를 만들지 못하는 경우에는 -1을 return 합니다.

### 제한사항
-   1 ≤  `beginning`의 길이 =  `target`의 길이 ≤ 10
-   1 ≤  `beginning[i]`의 길이 =  `target[i]`의 길이 ≤ 10
    -   `beginning[i][j]`와  `target[i][j]`는 i + 1행 j + 1열의 동전의 상태를 나타내며, 0 또는 1의 값으로 주어집니다.
    -   0은 동전의 앞면을, 1은 동전의 뒷면을 의미합니다.

## 해결
같은 행 또는 열을 2번 뒤집으면 원래 상태로 돌아가므로, 서로 다른 행 또는 열을 선택하여 1회 뒤집는 경우를 찾습니다. 최대 경우의 수는 2<sup>20</sup>이므로 완전 탐색이 가능합니다. => `백트래킹`<br>

행 개수가 `N`, 열 개수가 `M`일 때, 뒤집을 `N + M`개의 행과 열을 선택합니다. 그리고 행렬 뒤집기 연산을 수행한 후, 목표 상태와 일치하는지 판정합니다.

## 코드
```
#include <vector>
using namespace std;
int N, M, answer = -1;
bool selected[21];
vector<vector<int>> S, T;<br>

void BT(int level, int cnt) {
    if(level == N + M) {
        bool ok = 1;
        for(int y = 0; y < N; y++)
            for(int x = 0; x < M; x++)
                ok &= T[y][x] == (selected[x] ^ selected[y + M] ? (S[y][x] == 1 ? 0 : 1) : S[y][x]);
        if(ok)
            answer = answer != -1 ? min(answer, cnt) : cnt;
        return;
    }
    selected[level] = 1;
    BT(level + 1, cnt + 1);
    selected[level] = 0;
    BT(level + 1, cnt);
}

int solution(vector<vector<int>> beginning, vector<vector<int>> target) {<br>
    S = beginning, T = target; N = S.size(), M = S[0].size();
    BT(0, 0);
    return answer;
}
```

## 링크
https://school.programmers.co.kr/learn/courses/30/lessons/131703
{% endraw %}