---
categories:
- Programmers
date: '2024-11-12'
title: '[Programmers] 2020 KAKAO TECH INTERNSHIP - 키패드 누르기'
---

{% raw %}
> Lv. 1<br>

## 문제
스마트폰 전화 키패드의 각 칸에 다음과 같이 숫자들이 적혀 있습니다.

이 전화 키패드에서 왼손과 오른손의 엄지손가락만을 이용해서 숫자만을 입력하려고 합니다.  
맨 처음 왼손 엄지손가락은  `*`  키패드에 오른손 엄지손가락은  `#`  키패드 위치에서 시작하며, 엄지손가락을 사용하는 규칙은 다음과 같습니다.

1.  엄지손가락은 상하좌우 4가지 방향으로만 이동할 수 있으며 키패드 이동 한 칸은 거리로 1에 해당합니다.
2.  왼쪽 열의 3개의 숫자  `1`,  `4`,  `7`을 입력할 때는 왼손 엄지손가락을 사용합니다.
3.  오른쪽 열의 3개의 숫자  `3`,  `6`,  `9`를 입력할 때는 오른손 엄지손가락을 사용합니다.
4.  가운데 열의 4개의 숫자  `2`,  `5`,  `8`,  `0`을 입력할 때는 두 엄지손가락의 현재 키패드의 위치에서 더 가까운 엄지손가락을 사용합니다.  
    4-1. 만약 두 엄지손가락의 거리가 같다면, 오른손잡이는 오른손 엄지손가락, 왼손잡이는 왼손 엄지손가락을 사용합니다.

순서대로 누를 번호가 담긴 배열 numbers, 왼손잡이인지 오른손잡이인 지를 나타내는 문자열 hand가 매개변수로 주어질 때, 각 번호를 누른 엄지손가락이 왼손인 지 오른손인 지를 나타내는 연속된 문자열 형태로 return 하도록 solution 함수를 완성해주세요.

### 제한사항
-   numbers 배열의 크기는 1 이상 1,000 이하입니다.
-   numbers 배열 원소의 값은 0 이상 9 이하인 정수입니다.
-   hand는  `"left"`  또는  `"right"`  입니다.
    -   `"left"`는 왼손잡이,  `"right"`는 오른손잡이를 의미합니다.
-   왼손 엄지손가락을 사용한 경우는  `L`, 오른손 엄지손가락을 사용한 경우는  `R`을 순서대로 이어붙여 문자열 형태로 return 해주세요.

## 해결
입력 번호가 주어졌을 때, 왼쪽과 오른쪽의 선택 기준은 다음과 같습니다.
> 1. 입력 번호가 1, 4, 7 => L<br>
> 2. 입력 번호가 3, 6, 9 => R<br>
> 3. 입력 번호가 2, 5, 8, 0이고 거리가 같음 => 왼손잡이면 L, 오른손잡이면 R<br>
> 4. 입력 번호가 2, 5, 8, 0이고 거리가 다름 => 거리 가까운 것 선택<br>

```
입력 번호 탐색:
1. 조건에 맞는 손가락 선택
2. 정답 업데이트
3. 선택된 손가락 위치 변경
```

## 코드
```
#include <string>
#include <vector>
#include <cmath>
using namespace std;
struct Point { int x, y; };
int distance(Point a, Point b) { return abs(a.x - b.x) + abs(a.y - b.y); }
Point P[10] = { {1, 3} };

string solution(vector<int> numbers, string hand) {<br>
    string answer = "";
    Point left = { 0, 3 }, right = { 2, 3 };
    for(int i = 0; i < 10; i++)
        P[i + 1] = { i % 3, i / 3 };
    for(auto n : numbers) {
        bool isLeft;
        int distL = distance(left, P[n]), distR = distance(right, P[n]);
        if(n == 1 || n == 4 || n == 7)
            isLeft = 1;
        else if(n == 3 || n == 6 || n == 9)
            isLeft = 0;
        else if(distL == distR)
            isLeft = hand == "left";
        else
            isLeft = distL < distR;
        if(isLeft) {
            left = P[n];
            answer += "L";
        }
        else {
            right = P[n];
            answer += "R";
        }
    }
    return answer;
}
```

## 링크
https://school.programmers.co.kr/learn/courses/30/lessons/67256<br>
{% endraw %}