---
categories:
- Programmers
date: '2024-11-10'
title: '[Programmers] 2021 KAKAO TECH INTERNSHIP - 거리두기 확인하기'
---

{% raw %}
> Lv. 2<br>

## 문제
개발자를 희망하는 죠르디가 카카오에 면접을 보러 왔습니다.  
  
코로나 바이러스 감염 예방을 위해 응시자들은 거리를 둬서 대기를 해야하는데 개발 직군 면접인 만큼  
아래와 같은 규칙으로 대기실에 거리를 두고 앉도록 안내하고 있습니다.

> 1.  대기실은 5개이며, 각 대기실은 5x5 크기입니다.<br>
> 2.  거리두기를 위하여 응시자들 끼리는 맨해튼 거리가 2 이하로 앉지 말아 주세요.<br>
> 3.  단 응시자가 앉아있는 자리 사이가 파티션으로 막혀 있을 경우에는 허용합니다.<br>

응시자가 앉아있는 자리(`P`)를 의미합니다.

빈 테이블(`O`)을 의미합니다.

파티션(`X`)을 의미합니다.

5개의 대기실을 본 죠르디는 각 대기실에서 응시자들이 거리두기를 잘 기키고 있는지 알고 싶어졌습니다. 자리에 앉아있는 응시자들의 정보와 대기실 구조를 대기실별로 담은 2차원 문자열 배열  `places`가 매개변수로 주어집니다. 각 대기실별로 거리두기를 지키고 있으면 1을, 한 명이라도 지키지 않고 있으면 0을 배열에 담아 return 하도록 solution 함수를 완성해 주세요.

### 제한사항
-   `places`의 행 길이(대기실 개수) = 5
    -   `places`의 각 행은 하나의 대기실 구조를 나타냅니다.
-   `places`의 열 길이(대기실 세로 길이) = 5
-   `places`의 원소는  `P`,`O`,`X`로 이루어진 문자열입니다.
    -   `places`  원소의 길이(대기실 가로 길이) = 5
    -   `P`는 응시자가 앉아있는 자리를 의미합니다.
    -   `O`는 빈 테이블을 의미합니다.
    -   `X`는 파티션을 의미합니다.
-   입력으로 주어지는 5개 대기실의 크기는 모두 5x5 입니다.
-   return 값 형식
    -   1차원 정수 배열에 5개의 원소를 담아서 return 합니다.
    -   `places`에 담겨 있는 5개 대기실의 순서대로, 거리두기 준수 여부를 차례대로 배열에 담습니다.
    -   각 대기실 별로 모든 응시자가 거리두기를 지키고 있으면 1을, 한 명이라도 지키지 않고 있으면 0을 담습니다.

## 해결
- 어떠한 응시자부터 최대 깊이가 2인 `그래프 탐색`했을 때, 다른 응시자가 존재하면 안됩니다.
- 어떠한 대기실에서 모든 응시자를 시작점으로 DFS를 돌려서 모두 통과가 되면 해당 대기실은 거리두기가 지켜진 것입니다.
- 그래프 탐색시, 벽은 통과할 수 없습니다.

## 코드
```
#include <string>
#include <vector>
#include <cstring>
using namespace std;
bool visited[5][5];
int dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 };
vector<string> board;<br>
bool pass(int x, int y) { return x >= 0 && x < 5 && y >= 0 && y < 5 && !visited[y][x] && board[y][x] != 'X'; }

bool DFS(int x, int y, int depth = 0, bool init = 1) {
    if (depth == 3)
        return 1;
    if (init)
        memset(visited, 0, sizeof(visited));
    else if (board[y][x] == 'P')
        return 0;
    bool flag = 1;
    visited[y][x] = 1;
    for (int d = 0; d < 4; d++)
        if (pass(x + dx[d], y + dy[d]))
            flag &= DFS(x + dx[d], y + dy[d], depth + 1, 0);
    return flag;
}

int solve(vector<string> place) {<br>
    board = place;
    bool flag = 1;
    for (int y = 0; y < 5; y++)
        for (int x = 0; x < 5; x++)
            if (board[y][x] == 'P')
                flag &= DFS(x, y);
    return flag ? 1 : 0;
}

vector<int> solution(vector<vector<string>> places) {<br>
    vector<int> answer;<br>
    for (auto place : places)
        answer.push_back(solve(place));
    return answer;
}
```

## 링크
https://school.programmers.co.kr/learn/courses/30/lessons/81302<br>
{% endraw %}