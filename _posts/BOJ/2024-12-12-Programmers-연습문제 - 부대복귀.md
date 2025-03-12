---
categories:
- Programmers
date: '2024-12-12'
title: '[Programmers] 연습문제 - 부대복귀'
---

{% raw %}
> Lv. 3<br>

## 문제
강철부대의 각 부대원이 여러 지역에 뿔뿔이 흩어져 특수 임무를 수행 중입니다. 지도에서 강철부대가 위치한 지역을 포함한 각 지역은 유일한 번호로 구분되며, 두 지역 간의 길을 통과하는 데 걸리는 시간은 모두 1로 동일합니다. 임무를 수행한 각 부대원은 지도 정보를 이용하여 최단시간에 부대로 복귀하고자 합니다. 다만 적군의 방해로 인해, 임무의 시작 때와 다르게 되돌아오는 경로가 없어져 복귀가 불가능한 부대원도 있을 수 있습니다.

강철부대가 위치한 지역을 포함한 총지역의 수  `n`, 두 지역을 왕복할 수 있는 길 정보를 담은 2차원 정수 배열  `roads`, 각 부대원이 위치한 서로 다른 지역들을 나타내는 정수 배열  `sources`, 강철부대의 지역  `destination`이 주어졌을 때, 주어진  `sources`의 원소 순서대로 강철부대로 복귀할 수 있는 최단시간을 담은 배열을 return하는 solution 함수를 완성해주세요. 복귀가 불가능한 경우 해당 부대원의 최단시간은 -1입니다.

### 제한사항
-   3 ≤  `n`  ≤ 100,000
    -   각 지역은 정수 1부터  `n`까지의 번호로 구분됩니다.
-   2 ≤  `roads`의 길이 ≤ 500,000
    -   `roads`의 원소의 길이 = 2
    -   `roads`의 원소는 [a, b] 형태로 두 지역 a, b가 서로 왕복할 수 있음을 의미합니다.(1 ≤ a, b ≤ n, a ≠ b)
    -   동일한 정보가 중복해서 주어지지 않습니다.
        -   동일한 [a, b]가 중복해서 주어지지 않습니다.
        -   [a, b]가 있다면 [b, a]는 주어지지 않습니다.
-   1 ≤  `sources`의 길이 ≤ 500
    -   1 ≤ `sources[i]` ≤ n
-   1 ≤  `destination`  ≤ n

## 해결
가중치가 1인 양방향 그래프에서 출발점이 여러 개 있을 때, 1개의 목적지까지 최단 거리를 찾아야 합니다.

목적지를 출발점으로 하고, 각 정점에 대해 최단거리를 구하면 됩니다. 가중치가 고정이므로 `최단거리 BFS`를 사용합니다.

## 코드
```
#include <vector>
#include <queue>
#define SIZE 100001
using namespace std;
vector<int> graph[SIZE];
int dist[SIZE];

void BFS(int S) {
    queue<int> q;
    q.push(S); dist[S] = 1;
    while(!q.empty()) {
        int v = q.front(); q.pop();
        for(int next : graph[v]) {
            if(dist[next] == 0) {
                dist[next] = dist[v] + 1;
                q.push(next);
            }
        } 
    }
}

vector<int> solution(int n, vector<vector<int>> R, vector<int> S, int D) {
    vector<int> answer;
    for(auto r : R) {
        graph[r[0]].push_back(r[1]);
        graph[r[1]].push_back(r[0]);
    }
    BFS(D);
    for(int s : S)
        answer.push_back(dist[s] != 0 ? dist[s] - 1 : -1);
    return answer;
}
```

## 링크
<br>https://school.programmers.co.kr/learn/courses/30/lessons/132266
{% endraw %}