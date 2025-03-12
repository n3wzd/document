---
categories:
- Programmers
date: '2024-10-28'
title: '[Programmers] 2023 KAKAO BLIND RECRUITMENT - 미로 탈출 명령어'
---

{% raw %}
> Lv. 3<br>

## 문제
`n`  x  `m`  격자 미로가 주어집니다. 당신은 미로의 (x, y)에서 출발해 (r, c)로 이동해서 탈출해야 합니다.

단, 미로를 탈출하는 조건이 세 가지 있습니다.

1.  격자의 바깥으로는 나갈 수 없습니다.
2.  (x, y)에서 (r, c)까지 이동하는 거리가 총  `k`여야 합니다.  **이때, (x, y)와 (r, c)격자를 포함해, 같은 격자를 두 번 이상 방문해도 됩니다.**
3.  미로에서 탈출한 경로를 문자열로 나타냈을 때, 문자열이 사전 순으로 가장 빠른 경로로 탈출해야 합니다.

이동 경로는 다음과 같이 문자열로 바꿀 수 있습니다.

-   l: 왼쪽으로 한 칸 이동
-   r: 오른쪽으로 한 칸 이동
-   u: 위쪽으로 한 칸 이동
-   d: 아래쪽으로 한 칸 이동

예를 들어, 왼쪽으로 한 칸, 위로 한 칸, 왼쪽으로 한 칸 움직였다면, 문자열  `"lul"`로 나타낼 수 있습니다.

미로에서는 인접한 상, 하, 좌, 우 격자로 한 칸씩 이동할 수 있습니다.

예를 들어 다음과 같이 3 x 4 격자가 있다고 가정해 보겠습니다.

```
....
..S.
E...

```

미로의 좌측 상단은 (1, 1)이고 우측 하단은 (3, 4)입니다.  `.`은 빈 공간,  `S`는 출발 지점,  `E`는 탈출 지점입니다.

탈출까지 이동해야 하는 거리  `k`가 5라면 다음과 같은 경로로 탈출할 수 있습니다.

1.  lldud
2.  ulldd
3.  rdlll
4.  dllrl
5.  dllud
6.  ...

이때 dllrl보다 사전 순으로 빠른 경로로 탈출할 수는 없습니다.

격자의 크기를 뜻하는 정수  `n`,  `m`, 출발 위치를 뜻하는 정수  `x`,  `y`, 탈출 지점을 뜻하는 정수  `r`,  `c`, 탈출까지 이동해야 하는 거리를 뜻하는 정수  `k`가 매개변수로 주어집니다. 이때, 미로를 탈출하기 위한 경로를 return 하도록 solution 함수를 완성해주세요.  **단, 위 조건대로 미로를 탈출할 수 없는 경우  `"impossible"`을 return 해야 합니다.**

### 제한사항

-   2 ≤  `n`  (= 미로의 세로 길이) ≤ 50
-   2 ≤  `m`  (= 미로의 가로 길이) ≤ 50
-   1 ≤  `x`  ≤  `n`
-   1 ≤  `y`  ≤  `m`
-   1 ≤  `r`  ≤  `n`
-   1 ≤  `c`  ≤  `m`
-   (`x`,  `y`) ≠ (`r`,  `c`)
-   1 ≤  `k`  ≤ 2,500

## 해결
- 먼저 도달 가능성을 판정해야 합니다. 시작 지점-도착 지점 거리를 D라고 했을 때, k는 D보다 같거나 크고, k와 D를 각각 2로 나눈 나머지가 동일하면 도착 지점에 갈 수 있습니다.
- 사전순은 앞의 문자가 우선됩니다. 다음 위치에 가도 충분히 골에 도달할 수 있다는 것이 보장된다는 전제 하에, 현재 위치에서 밑으로 갈 수 있다면 항상 밑으로 가는 것이 이득입니다. 만약 밑으로 최대한 이동했다면, 그 뒤는 항상 왼쪽으로 가는 것이 이득입니다. => `그리디`

```
1. 도착 가능성 판정
2. 현재 위치에서 골 지점까지 거리와 k가 같아질 때까지 이동:
	1. 최대한 아래로 이동
	2. 최대한 왼쪽으로 이동
	3. 더 이상 이동할 수 없다면 오른쪽으로 이동
	4. k -= 1
3. 현재 위치에서 골 지점까지 이동:
	- 아래-왼-오른-위 순서대로 방향 우선하여 이동
```

## 코드
```
#include <string>
#include <cmath>
using namespace std;

string solution(int n, int m, int y, int x, int goalY, int goalX, int k) {
    string answer = ""; x--, y--, goalY--, goalX--;
    int dist = abs(x - goalX) + abs(y - goalY);
    if (!(dist % 2 == k % 2 && k >= dist))
        return "impossible";
    while (k != dist) {
        if (y < n - 1)
            y++, answer += 'd';
        else if (x > 0)
            x--, answer += 'l';
        else
            x++, answer += 'r';
        k--; dist = abs(x - goalX) + abs(y - goalY);
    }
    while (k--) {
        if (y < goalY)
            y++, answer += 'd';
        else if (x > goalX)
            x--, answer += 'l';
        else if (x < goalX)
            x++, answer += 'r';
        else
            y--, answer += 'u';
    }
    return answer;
}
```

## 링크
<br>https://school.programmers.co.kr/learn/courses/30/lessons/150365
{% endraw %}