---
categories:
- Programmers
date: '2024-12-10'
title: '[Programmers] 연습문제 - 등대'
---

{% raw %}
> Lv. 3<br>

## 문제
인천 앞바다에는 1부터  `n`까지 서로 다른 번호가 매겨진 등대  `n`개가 존재합니다. 등대와 등대 사이를 오가는 뱃길이  `n-1`개 존재하여, 어느 등대에서 출발해도 다른 모든 등대까지 이동할 수 있습니다. 등대 관리자 윤성이는 전력을 아끼기 위하여, 이 중 몇 개의 등대만 켜 두려고 합니다. 하지만 등대를 아무렇게나 꺼버리면, 뱃길을 오가는 배들이 위험할 수 있습니다. 한 뱃길의 양쪽 끝 등대 중 적어도 하나는 켜져 있도록 등대를 켜 두어야 합니다.

예를 들어, 아래 그림과 같이 등대 8개와 7개의 뱃길들이 있다고 합시다. 이 경우 1번 등대와 5번 등대 두 개만 켜 두어도 모든 뱃길은 양쪽 끝 등대 중 하나가 켜져 있으므로, 배들은 안전하게 운항할 수 있습니다.

등대의 개수  `n`과 각 뱃길이 연결된 등대의 번호를 담은 이차원 배열  `lighthouse`가 매개변수로 주어집니다. 윤성이가 켜 두어야 하는 등대 개수의 최솟값을 return 하도록 solution 함수를 작성해주세요.

### 제한사항
-   2 ≤  `n`  ≤ 100,000
-   `lighthouse`의 길이 =  `n – 1`
    -   `lighthouse`  배열의 각 행  `[a, b]`는  `a`번 등대와  `b`번 등대가 뱃길로 연결되어 있다는 의미입니다.
        -   1 ≤  `a`  ≠  `b`  ≤  `n`
        -   모든 등대는 서로 다른 등대로 이동할 수 있는 뱃길이 존재하도록 입력이 주어집니다.

## 해결
제공되는 그래프는 연결 그래프이고 간선 개수가 정점 개수 - 1이므로 `트리`입니다. 즉, 사이클이 존재하지 않습니다.

모든 간선을 커버하는 최소 정점 개수를 찾아야 합니다. 간선은 정점 2개의 연결이므로, 어떠한 간선이 있을 때 반드시 두 정점 중 하나는 활성 상태여야 합니다. 모든 경우를 확인해서 최소 개수를 찾습니다. => `트리 DP`<br>
- 현재 상태: (`n` = 정점, `flag` = 활성 유무)
- 계산 값: 최소 활성 개수
- 최종 답: min((루트 정점, 0), (루트 정점, 1))
- 루트 정점은 임의의 정점으로 합니다.

현재 정점의 활성 유무가 탐색에 영향을 줍니다. 현재 정점이 활성되었다면, 자식 정점은 활성 또는 비활성이 가능합니다. 현재 정점이 비활성이라면, 자식 정점은 반드시 활성되어야 합니다. 점화식은 다음과 같습니다:
> DP(v, 0) = ∑ min(DP(next<sub>i</sub>, 0), DP(next<sub>i</sub>, 1))<br>
> DP(v, 1) = ∑ DP(next<sub>i</sub>, 0))<br>

## 코드
```
#include <vector>
using namespace std;
const int SIZE = 100001;
vector<int> graph[SIZE];<br>
int cache[SIZE][2];

int DFS(int v, int flag, int p = -1) {
    if(cache[v][flag] > 0)<br>
        return cache[v][flag];
    cache[v][flag] = flag ? 1 : 0;
    for(int n : graph[v])
        if(n != p)
            cache[v][flag] += min(DFS(n, 1, v), flag ? DFS(n, 0, v) : SIZE);
    return cache[v][flag];
}

int solution(int n, vector<vector<int>> edges) {<br>
    for(auto edge : edges) {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }
    return min(DFS(1, 0), DFS(1, 1));
}
```

## 링크
https://school.programmers.co.kr/learn/courses/30/lessons/133500<br>
{% endraw %}