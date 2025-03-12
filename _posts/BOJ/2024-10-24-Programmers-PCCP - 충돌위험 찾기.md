---
categories:
- Programmers
date: '2024-10-24'
title: '[Programmers] PCCP - 충돌위험 찾기'
---

{% raw %}
> Lv. 2<br>

## 문제
어떤 물류 센터는 로봇을 이용한 자동 운송 시스템을 운영합니다. 운송 시스템이 작동하는 규칙은 다음과 같습니다.

1.  물류 센터에는 (r, c)와 같이 2차원 좌표로 나타낼 수 있는  `n`개의 포인트가 존재합니다. 각 포인트는 1~`n`까지의 서로 다른 번호를 가집니다.
2.  로봇마다 정해진 운송 경로가 존재합니다. 운송 경로는  `m`개의 포인트로 구성되고 로봇은 첫 포인트에서 시작해 할당된 포인트를 순서대로 방문합니다.
3.  운송 시스템에 사용되는 로봇은  `x`대이고, 모든 로봇은 0초에 동시에 출발합니다. 로봇은 1초마다 r 좌표와 c 좌표 중 하나가 1만큼 감소하거나 증가한 좌표로 이동할 수 있습니다.
4.  다음 포인트로 이동할 때는 항상 최단 경로로 이동하며 최단 경로가 여러 가지일 경우, r 좌표가 변하는 이동을 c 좌표가 변하는 이동보다 먼저 합니다.
5.  마지막 포인트에 도착한 로봇은 운송을 마치고 물류 센터를 벗어납니다. 로봇이 물류 센터를 벗어나는 경로는 고려하지 않습니다.

**이동 중 같은 좌표에 로봇이 2대 이상 모인다면 충돌할 가능성이 있는 위험 상황으로 판단합니다.**  관리자인 당신은 현재 설정대로 로봇이 움직일 때 위험한 상황이 총 몇 번 일어나는지 알고 싶습니다. 만약 어떤 시간에 여러 좌표에서 위험 상황이 발생한다면 그 횟수를 모두 더합니다.

운송 포인트  `n`개의 좌표를 담은 2차원 정수 배열  `points`와 로봇  `x`대의 운송 경로를 담은 2차원 정수 배열  `routes`가 매개변수로 주어집니다. 이때 모든 로봇이 운송을 마칠 때까지 발생하는 위험한 상황의 횟수를 return 하도록 solution 함수를 완성해 주세요.

### 제한사항
-   2 ≤  `points`의 길이 =  `n`  ≤ 100
    -   `points[i]`는  `i + 1`번 포인트의 [`r 좌표`,  `c 좌표`]를 나타내는 길이가 2인 정수 배열입니다.
    -   1 ≤  `r`  ≤ 100
    -   1 ≤  `c`  ≤ 100
    -   같은 좌표에 여러 포인트가 존재하는 입력은 주어지지 않습니다.
-   2 ≤  `routes`의 길이 = 로봇의 수 =  `x`  ≤ 100
    -   2 ≤  `routes[i]`의 길이 =  `m`  ≤ 100
    -   `routes[i]`는  `i + 1`번째 로봇의 운송경로를 나타냅니다.  `routes[i]`의 길이는 모두 같습니다.
    -   `routes[i][j]`는  `i + 1`번째 로봇이  `j + 1`번째로 방문하는 포인트 번호를 나타냅니다.
    -   같은 포인트를 연속으로 방문하는 입력은 주어지지 않습니다.
    -   1 ≤  `routes[i][j]`  ≤  `n`

## 해결
로봇이 움직이는 과정을 시간별로 `시뮬레이션`해야 합니다.
- 로봇의 현재 위치, 다음 목적지 번호를 저장해야 합니다.
- 모든 로봇의 이동이 끝날 때마다 충돌 검사를 수행합니다. 충돌이 발생한 위치 개수를 결과 값에 더합니다.
- 로봇의 개수를 격자에 기록하고, 이 격자의 값이 2 이상이면 충돌이 있다고 판정합니다. (별도의 최적화 없이 격자 전체 탐색을 수행해도 됩니다.)

## 코드
```
#include <string>
#include <vector>
using namespace std;
struct Robot { int x, y, goalIdx; };
struct Point { int x, y; };
int board[101][101], C;

void addCollide() {
    for (int y = 1; y <= 100; y++)
        for (int x = 1; x <= 100; x++)
            C += board[y][x] > 1 ? 1 : 0;<br>
}

int solution(vector<vector<int>> points, vector<vector<int>> routes) {<br>
    int M = routes[0].size(), N = routes.size();
    vector<Robot> robots;<br>
    for (vector<int> route : routes) {<br>
        int x = points[route[0] - 1][1], y = points[route[0] - 1][0];
        robots.push_back({ x, y, 1 });
        board[y][x] += 1;
    }
    addCollide();

    while (1) {
        bool isEnd = 1;
        for (int i = 0; i < N; i++) {
            Robot& robot = robots[i];
            if (robot.goalIdx > M)<br>
                continue;
            if (robot.goalIdx == M) {
                board[robot.y][robot.x] -= 1;
                robot.goalIdx++;
                continue;
            }
            isEnd = 0;

            board[robot.y][robot.x] -= 1;
            int gx = points[routes[i][robot.goalIdx] - 1][1], gy = points[routes[i][robot.goalIdx] - 1][0];
            if (robot.y < gy)
                robot.y++;
            else if (robot.y > gy)<br>
                robot.y--;
            else {
                if (robot.x < gx)
                    robot.x++;
                else if (robot.x > gx)<br>
                    robot.x--;
            }
            board[robot.y][robot.x] += 1;
            if (robot.x == gx && robot.y == gy)
                robot.goalIdx++;
        }
        addCollide();
        if (isEnd)
            break;
    }
    return C;
}
```

## 링크
https://school.programmers.co.kr/learn/courses/30/lessons/340211<br>
{% endraw %}