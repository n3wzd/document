---
categories:
- Programmers
date: '2024-10-31'
title: '[Programmers] 2022 KAKAO BLIND RECRUITMENT - 양과 늑대'
---

{% raw %}
> Lv. 3<br>

## 문제
2진 트리 모양 초원의 각 노드에 늑대와 양이 한 마리씩 놓여 있습니다. 이 초원의 루트 노드에서 출발하여 각 노드를 돌아다니며 양을 모으려 합니다. 각 노드를 방문할 때 마다 해당 노드에 있던 양과 늑대가 당신을 따라오게 됩니다. 이때, 늑대는 양을 잡아먹을 기회를 노리고 있으며, 당신이 모은 양의 수보다 늑대의 수가 같거나 더 많아지면 바로 모든 양을 잡아먹어 버립니다. 당신은 중간에 양이 늑대에게 잡아먹히지 않도록 하면서 최대한 많은 수의 양을 모아서 다시 루트 노드로 돌아오려 합니다.

각 노드에 있는 양 또는 늑대에 대한 정보가 담긴 배열  `info`, 2진 트리의 각 노드들의 연결 관계를 담은 2차원 배열  `edges`가 매개변수로 주어질 때, 문제에 제시된 조건에 따라 각 노드를 방문하면서 모을 수 있는 양은 최대 몇 마리인지 return 하도록 solution 함수를 완성해주세요.

### 제한사항
-   2 ≤  `info`의 길이 ≤ 17
    -   `info`의 원소는 0 또는 1 입니다.
    -   info[i]는 i번 노드에 있는 양 또는 늑대를 나타냅니다.
    -   0은 양, 1은 늑대를 의미합니다.
    -   info[0]의 값은 항상 0입니다. 즉, 0번 노드(루트 노드)에는 항상 양이 있습니다.
-   `edges`의 세로(행) 길이 =  `info`의 길이 - 1
    -   `edges`의 가로(열) 길이 = 2
    -   `edges`의 각 행은 [부모 노드 번호, 자식 노드 번호] 형태로, 서로 연결된 두 노드를 나타냅니다.
    -   동일한 간선에 대한 정보가 중복해서 주어지지 않습니다.
    -   항상 하나의 이진 트리 형태로 입력이 주어지며, 잘못된 데이터가 주어지는 경우는 없습니다.
    -   0번 노드는 항상 루트 노드입니다.

## 해결
- 늑대 정점을 방문하는 것은 이득일 수도 아닐 수도 있습니다. 따라서 모든 경우를 탐색해야 합니다. => `백트래킹`<br>
- `그래프 탐색`으로 현재 방문 가능한 정점들에서 양의 수를 구할 수 있습니다. 탐색 대상이 트리이므로 노드마다 level을 부여해서 방문 처리를 할 수 있습니다. 탐색에 제약이 되는 것은 늑대 정점 뿐이며, 이 정점을 다음 백트래킹 탐색 대상으로 합니다.
- 백트래킹 탐색 상태를 (현재 양 수, 현재 늑대 수, 트리 탐색 시작 정점, 다음 방문할 정점 목록)으로 정의합니다. 다음 정점 목록은 boolean 배열이며, `비트마스크`로 구현할 수 있습니다.

```
현재 탐색(양, 늑대, 시작 정점, 다음 정점 목록): 
1. 시작 정점부터 트리 확인:
	- 양 개수, 다음 정점 목록 업데이트
2. 양 최댓값 업데이트
3. 양 개수가 늑대 개수보다 2 많다면 다음 정점 조사:
	- 다음 탐색(양, 늑대 + 1, 다음 정점, 다음 정점 목록)
```

## 코드
```
#include <vector>
using namespace std;
vector<int> graph[18], info;<br>
int N, level[18], tmpSheep, tmpNext, res = 1;

void setLevel(int n, int d) {
    level[n] = d;
    for (int next : graph[n])
        if (level[next] == 0)
            setLevel(next, d + 1);
}

void DFS(int cur, int start) {
    if (info[cur] && cur != start) {
        tmpNext |= 1 << cur;
        return;
    }
    if(!info[cur])
        tmpSheep++;
    for (int next : graph[cur])
        if (level[cur] < level[next])
            DFS(next, start);
}

void BT(int sheep, int wolf, int start, int next) {
    tmpNext = next, tmpSheep = 0;
    DFS(start, start);
    next = tmpNext, sheep += tmpSheep;
    res = max(res, sheep);
    for (int i = 0; i <= N; i++) {
        if (next & (1 << i) && sheep > wolf + 1)<br>
            BT(sheep, wolf + 1, i, next & ~(1 << i));
    }
}

int solution(vector<int> infoI, vector<vector<int>> edges) {<br>
    info = infoI;
    for (auto edge : edges) {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
        N = max(N, max(edge[0], edge[1]));
    }
    setLevel(0, 1);
    BT(0, 0, 0, 0);
    return res;
}
```

## 링크
https://school.programmers.co.kr/learn/courses/30/lessons/92343
{% endraw %}