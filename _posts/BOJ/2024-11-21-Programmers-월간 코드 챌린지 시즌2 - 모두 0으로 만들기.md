---
categories:
- Programmers
date: '2024-11-21'
title: '[Programmers] 월간 코드 챌린지 시즌2 - 모두 0으로 만들기'
---

{% raw %}
> Lv. 3<br>

## 문제
각 점에 가중치가 부여된 트리가 주어집니다. 당신은 다음 연산을 통하여, 이 트리의 모든 점들의 가중치를 0으로 만들고자 합니다.

-   임의의 연결된 두 점을 골라서 한쪽은 1 증가시키고, 다른 한쪽은 1 감소시킵니다.

하지만, 모든 트리가 위의 행동을 통하여 모든 점들의 가중치를 0으로 만들 수 있는 것은 아닙니다. 당신은 주어진 트리에 대해서 해당 사항이 가능한지 판별하고, 만약 가능하다면 최소한의 행동을 통하여 모든 점들의 가중치를 0으로 만들고자 합니다.

트리의 각 점의 가중치를 의미하는 1차원 정수 배열  `a`와 트리의 간선 정보를 의미하는  `edges`가 매개변수로 주어집니다. 주어진 행동을 통해 트리의 모든 점들의 가중치를 0으로 만드는 것이 불가능하다면 -1을, 가능하다면 최소 몇 번만에 가능한지를 찾아 return 하도록 solution 함수를 완성해주세요. (만약 처음부터 트리의 모든 정점의 가중치가 0이라면, 0을 return 해야 합니다.)

### 제한사항
-   a의 길이는 2 이상 300,000 이하입니다.
    -   a의 모든 수는 각각 -1,000,000 이상 1,000,000 이하입니다.
    -   `a[i]`는 i번 정점의 가중치를 의미합니다.
-   edges의 행의 개수는 (a의 길이 - 1)입니다.
    -   edges의 각 행은  `[u, v]`  2개의 정수로 이루어져 있으며, 이는 u번 정점과 v번 정점이 간선으로 연결되어 있음을 의미합니다.
    -   edges가 나타내는 그래프는 항상 트리로 주어집니다.

## 해결
주어진 연산은 1과 -1을 더하는 것이므로 트리 가중치 총량은 보존됩니다. 따라서 트리 가중치 종합이 0이어야만 모든 점들의 가중치가 0이 될 수 있습니다.

모든 가중치를 0으로 만들어봅시다. 먼저 리프 노드부터 차례대로 연산을 적용해 가중치를 0으로 만듭니다. 이 과정을 재귀적으로 반복하면 정답을 찾을 수 있습니다. 구현은 `DFS`을 사용합니다.

```
1. 트리 DFS 탐색
	- 자식 정점의 가중치를 부모 정점에 더하기
	- 정답 업데이트
2. 루트 정점의 가중치가 0이면 정답, 그렇지 않으면 -1 반환
```

## 코드
```
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;
ll answer;
vector<int> graph[300001];<br>
vector<ll> w;<br>

ll DFS(int n, int prev) {
    for(int c : graph[n])
        if(c != prev)
            w[n] += DFS(c, n);
    answer += abs(w[n]);
    return w[n];
}

ll solution(vector<int> a, vector<vector<int>> edges) {<br>
    for(auto b : a)
        w.push_back(b);
    for(auto edge : edges) {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }
    return DFS(0, -1) == 0 ? answer : -1;
}
```

## 링크
https://school.programmers.co.kr/learn/courses/30/lessons/76503<br>
{% endraw %}