---
categories:
- Programmers
date: '2024-11-14'
title: '[Programmers] 월간 코드 챌린지 시즌1 - 트리 트리오 중간값'
---

{% raw %}
> Lv. 4<br>

## 문제
n개의 점으로 이루어진 트리가 있습니다. 이때, 트리 상에서 다음과 같은 것들을 정의합니다.

-   어떤 두 점 사이의 거리는, 두 점을 잇는 경로 상 간선의 개수로 정의합니다.
-   임의의 3개의 점 a, b, c에 대한 함수 f(a, b, c)의 값을 a와 b 사이의 거리, b와 c 사이의 거리, c와 a 사이의 거리, 3개 값의 중간값으로 정의합니다.

트리의 정점의 개수 n과 트리의 간선을 나타내는 2차원 정수 배열 edges가 매개변수로 주어집니다. 주어진 트리에서 임의의 3개의 점을 뽑아 만들 수 있는 모든 f값 중에서, 제일 큰 값을 구해 return 하도록 solution 함수를 완성해주세요.

### 제한 사항
-   n은 3 이상 250,000 이하입니다.
-   edges의 행의 개수는 n-1 입니다.
    -   edges의 각 행은 [v1, v2] 2개의 정수로 이루어져 있으며, 이는 v1번 정점과 v2번 정점 사이에 간선이 있음을 의미합니다.
    -   v1, v2는 각각 1 이상 n 이하입니다.
    -   v1, v2는 다른 수입니다.
    -   입력으로 주어지는 그래프는 항상 트리입니다.

## 해결
먼저 `트리`의 지름에서 힌트를 찾아봅시다. (트리의 지름은 트리 내 임의 경로 중에서 가장 긴 것을 의미합니다.) 트리의 지름을 구하는 과정은 다음과 같습니다:
```
1. 임의의 정점에서 가장 먼 정점 A 찾기
2. 정점 A에서 가장 먼 정점 B 찾기
3. A, B가 트리의 지름
```
`그래프 탐색`으로 구현할 수 있습니다. 임의의 정점은 루트 정점으로 하는 것이 편리합니다. => `BOJ - 1167 - 트리의 지름` 참고

다음으로 문제의 답을 찾아봅시다. 어떠한 트리를 A와 B를 기준으로 펼치면 다음과 같습니다:
```
    1       7
    |       |
A - 2 - 3 - 6 - 8 - B
        |
        4
        |
        5
```

A와 B의 거리는 이미 최대이므로 다른 정점 조합으로 최대 거리를 찾아야 합니다. A를 제외한 B에서 가장 먼 거리 또는 B를 제외한 A에서 가장 먼 거리가 정답 후보가 될 수 있습니다. 따라서 정답을 구하는 최종적인 과정은 다음과 같습니다:
```
1. 트리의 지름을 구성하는 정점 A, B 찾기
2. 정답 = max(A를 제외한 B의 가장 먼 거리, B를 제외한 A의 가장 먼 거리)
```

## 코드
```
#include <vector>
using namespace std;
vector<int> graph[250001];
int maxV, maxDist;

void DFS(int n, int prev, int dist, int banned) {
    if(maxDist < dist) {
        maxDist = dist;
        maxV = n;
    }
    for(auto c : graph[n])
        if(c != prev && c != banned)
            DFS(c, n, dist + 1, banned);
}

int solution(int n, vector<vector<int>> edges) {
    for(auto edge : edges) {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }
    maxDist = -1; DFS(1, 0, 0, -1); int A = maxV;
    maxDist = -1; DFS(A, 0, 0, -1); int B = maxV;
    maxDist = -1; DFS(A, 0, 0, B); int dist1 = maxDist;
    maxDist = -1; DFS(B, 0, 0, A); int dist2 = maxDist;
    return max(dist1, dist2);
}
```

## 링크
<br>https://school.programmers.co.kr/learn/courses/30/lessons/68937
{% endraw %}