---
categories:
- Programmers
date: '2024-11-14'
title: '[Programmers] 월간 코드 챌린지 시즌1 - 삼각 달팽이'
---

{% raw %}
> Lv. 2<br>

## 문제
정수 n이 매개변수로 주어집니다. 다음 그림과 같이 밑변의 길이와 높이가 n인 삼각형에서 맨 위 꼭짓점부터 반시계 방향으로 달팽이 채우기를 진행한 후, 첫 행부터 마지막 행까지 모두 순서대로 합친 새로운 배열을 return 하도록 solution 함수를 완성해주세요.

### 제한사항
-   n은 1 이상 1,000 이하입니다.

## 해결
3번째 예제를 분석하면 다음과 같습니다:
```
0
1
2  15
3  16  14
4  17  21  13
5  18  19  20  12
6   7   8   9  10  11
```

0번부터 출발한다고 합시다. [1, 6]은 아래 방향으로 6번, [7, 11]은 오른쪽 방향으로 5번, [12, 15]는 사선 방향으로 4번, [16, 18]은 아래 방향으로 3번, [19, 20]은 오른쪽 방향으로 2번, [21, 21]은 사선 방향으로 1번이면 삼각 달팽이가 완성됩니다.

이를 일반화하면, n회부터 1회까지 한 방향으로 값이 채워지며 방향은 3가지(아래, 오른쪽, 사선)가 교대로 사용됩니다.

## 코드
```
#include <vector>
using namespace std;
int tri[1001][1001];
vector<int> answer;
int dx[3] = { 0, 1, -1 }, dy[3] = { 1, 0, -1 };

void init(int n) {
    int x = 0, y = -1, genID = 1;
    for(int t = n; t > 0; t--) {
        for(int k = 0; k < t; k++) {
            x += dx[(n - t) % 3], y += dy[(n - t) % 3];
            tri[y][x] = genID++;
        }
    }
}

vector<int> solution(int n) {
    init(n);
    for(int y = 0; y < n; y++)
        for(int x = 0; x <= y; x++)
            answer.push_back(tri[y][x]);
    return answer;
}
```

## 링크
<br>https://school.programmers.co.kr/learn/courses/30/lessons/68645
{% endraw %}