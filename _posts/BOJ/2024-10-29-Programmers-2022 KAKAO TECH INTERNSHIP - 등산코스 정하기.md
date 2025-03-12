---
categories:
- Programmers
date: '2024-10-29'
title: '[Programmers] 2022 KAKAO TECH INTERNSHIP - 등산코스 정하기'
---

{% raw %}
> Lv. 3<br>

## 문제
XX산은  `n`개의 지점으로 이루어져 있습니다. 각 지점은 1부터  `n`까지 번호가 붙어있으며, 출입구, 쉼터, 혹은 산봉우리입니다. 각 지점은 양방향 통행이 가능한 등산로로 연결되어 있으며, 서로 다른 지점을 이동할 때 이 등산로를 이용해야 합니다. 이때, 등산로별로 이동하는데 일정 시간이 소요됩니다.

등산코스는 방문할 지점 번호들을 순서대로 나열하여 표현할 수 있습니다.  
예를 들어  `1-2-3-2-1`  으로 표현하는 등산코스는 1번지점에서 출발하여 2번, 3번, 2번, 1번 지점을 순서대로 방문한다는 뜻입니다.  
등산코스를 따라 이동하는 중 쉼터 혹은 산봉우리를 방문할 때마다 휴식을 취할 수 있으며, 휴식 없이 이동해야 하는 시간 중 가장 긴 시간을 해당 등산코스의  `intensity`라고 부르기로 합니다.

당신은 XX산의 출입구 중 한 곳에서 출발하여 산봉우리 중 한 곳만 방문한 뒤 다시  **원래의**  출입구로 돌아오는 등산코스를 정하려고 합니다. 다시 말해, 등산코스에서 출입구는  **처음과 끝에 한 번씩**, 산봉우리는  **한 번만**  포함되어야 합니다.  
당신은 이러한 규칙을 지키면서  `intensity`가 최소가 되도록 등산코스를 정하려고 합니다.

XX산의 지점 수  `n`, 각 등산로의 정보를 담은 2차원 정수 배열  `paths`, 출입구들의 번호가 담긴 정수 배열  `gates`, 산봉우리들의 번호가 담긴 정수 배열  `summits`가 매개변수로 주어집니다. 이때,  `intensity`가 최소가 되는 등산코스에 포함된 산봉우리 번호와  `intensity`의 최솟값을 차례대로 정수 배열에 담아 return 하도록 solution 함수를 완성해주세요.  `intensity`가 최소가 되는 등산코스가 여러 개라면 그중 산봉우리의 번호가 가장 낮은 등산코스를 선택합니다.

### 제한사항
-   2 ≤  `n`  ≤ 50,000
-   `n`  - 1 ≤  `paths`의 길이 ≤ 200,000
-   `paths`의 원소는  `[i, j, w]`  형태입니다.
    -   `i`번 지점과  `j`번 지점을 연결하는 등산로가 있다는 뜻입니다.
    -   `w`는 두 지점 사이를 이동하는 데 걸리는 시간입니다.
    -   1 ≤  `i`  <  `j`  ≤  `n`
    -   1 ≤  `w`  ≤ 10,000,000
    -   서로 다른 두 지점을 직접 연결하는 등산로는 최대 1개입니다.
-   1 ≤  `gates`의 길이 ≤  `n`
    -   1 ≤  `gates`의 원소 ≤  `n`
    -   `gates`의 원소는 해당 지점이 출입구임을 나타냅니다.
-   1 ≤  `summits`의 길이 ≤  `n`
    -   1 ≤  `summits`의 원소 ≤  `n`
    -   `summits`의 원소는 해당 지점이 산봉우리임을 나타냅니다.
-   출입구이면서 동시에 산봉우리인 지점은 없습니다.
-   `gates`와  `summits`에 등장하지 않은 지점은 모두 쉼터입니다.
-   임의의 두 지점 사이에 이동 가능한 경로가 항상 존재합니다.
-   return 하는 배열은  `[산봉우리의 번호, intensity의 최솟값]`  순서여야 합니다.

## 해결
임의의 시작점과 도착점을 연결하는 경로에서 가중치가 가장 낮은 간선을 찾아야 합니다. 그래프에서 간선을 모두 지우고, 가중치 순서대로 간선을 추가해봅시다. 간선을 새로 연결할 때, 시작점과 도착점으로 연결되는 경로가 생성되었다면 최적의 코스를 찾은 것입니다. 이러한 동작 과정은 `크루스칼 알고리즘`과 비슷하며, `Disjoint Set`으로 구현할 수 있습니다.

- 간선을 연결하는 과정은 union 연산으로 구현됩니다. 시작점과 도착점을 찾기 위해서, 집합의 루트 노드를 출입구 또는 산봉우리로 합니다.
- 경로는 출입구, 산봉우리를 각각 1개씩 포함해야 합니다. 만약 루트 노드가 모두 출입구 또는 산봉우리면 union하지 않습니다.

```
1. 모든 간선을 가중치 순으로 정렬
2. 가중치별로 간선 순차 탐색:
	1. 간선의 두 정점 union:
		- 루트 노드가 모두 출입구 또는 산봉우리면 union 불가
		- 루트 노드가 각각 출입구, 산봉우리면 결과 업데이트
		- 루트 노드 둘 중 하나만 출입구 또는 산봉우리면 해당 노드를 새 트리의 루트 노드로 하기
	2. 현재 가중치 간선이 모두 추가되었을 때, 결과가 존재한다면 탐색 종료
```

## 코드
```
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 50001;
int type[MAXN], parent[MAXN], intensity, summit = MAXN;

int find(int n) {
    int p = n;
    while (parent[p] >= 0) p = parent[p];
    if (parent[n] >= 0) parent[n] = p;
    return p;
}

int merge(int a, int b) {
    int p1 = find(a);
    int p2 = find(b);
    if (p1 == p2 || type[p1] + type[p2] == 4 || (type[p1] == 1 && type[p2] == 1))
        return MAXN;

    if (type[p1] + type[p2] == 3)
        return type[p1] == 2 ? p1 : p2;
    else if (type[p1] == 1 || type[p1] == 2)
        parent[p2] = p1;
    else
        parent[p1] = p2;
    return MAXN;
}

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    for (int i = 0; i <= n; i++)
        parent[i] = -1;
    for (int gate : gates)
        type[gate] = 1;
    for (int sum : summits)
        type[sum] = 2;
    sort(paths.begin(), paths.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[2] < b[2];
        });
    intensity = paths[0][2];
    for (int p = 0; p < paths.size(); p++) {
        if(intensity != paths[p][2] && summit != MAXN)
            break;
        intensity = paths[p][2];
        summit = min(summit, merge(paths[p][0], paths[p][1]));
    }
    return { summit, intensity };
}
```

## 링크
<br>https://school.programmers.co.kr/learn/courses/30/lessons/118669
{% endraw %}