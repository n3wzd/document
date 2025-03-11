---
categories:
- Programmers
date: '2024-11-07'
title: '[Programmers] 2018 KAKAO BLIND RECRUITMENT - 프렌즈4블록'
---

{% raw %}
> Lv. 2<br>

## 문제
블라인드 공채를 통과한 신입 사원 라이언은 신규 게임 개발 업무를 맡게 되었다. 이번에 출시할 게임 제목은 "프렌즈4블록".  
같은 모양의 카카오프렌즈 블록이 2×2 형태로 4개가 붙어있을 경우 사라지면서 점수를 얻는 게임이다.
  
만약 판이 주어질 경우, 라이언이 2×2로 배치된 7개 블록과 콘이 2×2로 배치된 4개 블록이 지워진다. 같은 블록은 여러 2×2에 포함될 수 있으며, 지워지는 조건에 만족하는 2×2 모양이 여러 개 있다면 한꺼번에 지워진다.

블록이 지워진 후에 위에 있는 블록이 아래로 떨어져 빈 공간을 채우게 된다.

만약 빈 공간을 채운 후에 다시 2×2 형태로 같은 모양의 블록이 모이면 다시 지워지고 떨어지고를 반복하게 된다.  

각 문자는 라이언(R), 무지(M), 어피치(A), 프로도(F), 네오(N), 튜브(T), 제이지(J), 콘(C)을 의미한다

입력으로 블록의 첫 배치가 주어졌을 때, 지워지는 블록은 모두 몇 개인지 판단하는 프로그램을 제작하라.

### 입력 형식
-   입력으로 판의 높이  `m`, 폭  `n`과 판의 배치 정보  `board`가 들어온다.
-   2 ≦  `n`,  `m`  ≦ 30
-   `board`는 길이  `n`인 문자열  `m`개의 배열로 주어진다. 블록을 나타내는 문자는 대문자 A에서 Z가 사용된다.

### 출력 형식
입력으로 주어진 판 정보를 가지고 몇 개의 블록이 지워질지 출력하라.

## 해결
주어진 게임 규칙을 구현하면 됩니다. => `시뮬레이션`<br>
```
게임 사이클
1. 모든 위치 순회: 2x2 사각형 영역이 모두 같은 블록이면 위치 기록
2. 모든 위치 순회: 과정 1에서 기록된 블록을 모두 제거
	- 제거된 블록이 없다면 게임 끝
3. y 밑부터 모든 위치 순회: 밑이 빈 공간이면 블록 내리기
```

## 코드
```
#include <string>
#include <vector>
using namespace std;
bool flag[31][31];

int solution(int m, int n, vector<string> board) {<br>
    int answer = 0;
    while (1) {
        for (int y = 0; y < m - 1; y++)
            for (int x = 0; x < n - 1; x++)
                if (board[y][x] == board[y + 1][x] && board[y][x] == board[y][x + 1]
                    && board[y][x] == board[y + 1][x + 1] && board[y][x] != '.')
                    flag[y][x] = flag[y + 1][x] = flag[y][x + 1] = flag[y + 1][x + 1] = 1;
        bool isEnd = 1;
        for (int y = 0; y < m; y++)
            for (int x = 0; x < n; x++)
                if (flag[y][x])
                    board[y][x] = '.', answer++, isEnd = 0, flag[y][x] = 0;
        if (isEnd)
            return answer;
        for (int y = m - 1; y >= 0; y--) {
            for (int x = 0; x < n; x++) {
                int ty = y;
                while (ty < m - 1 && board[ty + 1][x] == '.') ty++;
                if (y != ty) {
                    board[ty][x] = board[y][x];
                    board[y][x] = '.';
                }
            }
        }
    }
}
```

## 링크
https://school.programmers.co.kr/learn/courses/30/lessons/17679
{% endraw %}