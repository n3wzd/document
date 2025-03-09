---
categories:
- Programmers
date: '2024-11-06'
title: '[Programmers] 2019 KAKAO BLIND RECRUITMENT - 길 찾기 게임'
---

{% raw %}
> Lv. 3<br>

## 문제
전무로 승진한 라이언은 기분이 너무 좋아 프렌즈를 이끌고 특별 휴가를 가기로 했다.  
내친김에 여행 계획까지 구상하던 라이언은 재미있는 게임을 생각해냈고 역시 전무로 승진할만한 인재라고 스스로에게 감탄했다.

라이언이 구상한(그리고 아마도 라이언만 즐거울만한) 게임은, 카카오 프렌즈를 두 팀으로 나누고, 각 팀이 같은 곳을 다른 순서로 방문하도록 해서 먼저 순회를 마친 팀이 승리하는 것이다.

그냥 지도를 주고 게임을 시작하면 재미가 덜해지므로, 라이언은 방문할 곳의 2차원 좌표 값을 구하고 각 장소를 이진트리의 노드가 되도록 구성한 후, 순회 방법을 힌트로 주어 각 팀이 스스로 경로를 찾도록 할 계획이다.

라이언은 아래와 같은 특별한 규칙으로 트리 노드들을 구성한다.

-   트리를 구성하는 모든 노드의 x, y 좌표 값은 정수이다.
-   모든 노드는 서로 다른 x값을 가진다.
-   같은 레벨(level)에 있는 노드는 같은 y 좌표를 가진다.
-   자식 노드의 y 값은 항상 부모 노드보다 작다.
-   임의의 노드 V의 왼쪽 서브 트리(left subtree)에 있는 모든 노드의 x값은 V의 x값보다 작다.
-   임의의 노드 V의 오른쪽 서브 트리(right subtree)에 있는 모든 노드의 x값은 V의 x값보다 크다.

다행히 두 팀 모두 머리를 모아 분석한 끝에 라이언의 의도를 간신히 알아차렸다.  
  
그러나 여전히 문제는 남아있다. 노드의 수가 예시처럼 적다면 쉽게 해결할 수 있겠지만, 예상대로 라이언은 그렇게 할 생각이 전혀 없었다.

이제 당신이 나설 때가 되었다.

곤경에 빠진 카카오 프렌즈를 위해 이진트리를 구성하는 노드들의 좌표가 담긴 배열 nodeinfo가 매개변수로 주어질 때,  
노드들로 구성된 이진트리를 전위 순회, 후위 순회한 결과를 2차원 배열에 순서대로 담아 return 하도록 solution 함수를 완성하자.

### 제한사항
-   nodeinfo는 이진트리를 구성하는 각 노드의 좌표가 1번 노드부터 순서대로 들어있는 2차원 배열이다.
    -   nodeinfo의 길이는  `1`  이상  `10,000`  이하이다.
    -   nodeinfo[i] 는 i + 1번 노드의 좌표이며, [x축 좌표, y축 좌표] 순으로 들어있다.
    -   모든 노드의 좌표 값은  `0`  이상  `100,000`  이하인 정수이다.
    -   트리의 깊이가  `1,000`  이하인 경우만 입력으로 주어진다.
    -   모든 노드의 좌표는 문제에 주어진 규칙을 따르며, 잘못된 노드 위치가 주어지는 경우는 없다.

## 해결
좌표 데이터를 트리로 변환하는 문제입니다. x 구간에 따라 서브 트리가 나뉘는 점을 활용합니다. => `분할정복`<br>

먼저 주어진 정점을 y에 대해 저장합니다. (각 y에서 정점들은 x 오름차순으로`정렬`되어 있어야 합니다.) 그리고 y의 최댓값부터 탐색하여 정점을 추가합니다. 탐색의 현재 상태를 (자식으로 추가 가능한 x의 범위(lo, hi), 현재 정점(위치, 번호))으로 정의합니다.

```
현재 탐색
1. 현재 정점의 아래 방향 수직 거리와 가장 가까이 있는 정점 목록 찾기
2. 정점 목록에서 추가 가능한 x 범위에 포함되는 정점들을 순차적으로 현재 정점의 자식으로 추가
	- 현재 정점보다 x값이 작다면, 다음 탐색(lo, 현재 정점 x, 자식 정점 x, 자식 정점 y - 1, 자식 정점 번호)
	- 현재 정점보다 x값이 크다면, 다음 탐색(현재 정점 x, hi, 자식 정점 x, 자식 정점 y - 1, 자식 정점 번호)
```

루트 정점을 0번 정점으로 임시로 추가하면 편리합니다. 이때 초기 값은 (-1, 100001, 100001, 100000, 0)입니다.

전위 순회와 후위 순회는 `DFS`로 구현합니다.

## 코드
```
#include <vector>
#include <algorithm>
using namespace std;
struct Node { int x, id; };
vector<int> graph[10002];<br>
vector<Node> nodeY[100001];<br>
vector<vector<int>> answer = { {}, {} };<br>

void makeTree(int lo, int hi, int x, int y, int parent) {
    while (y >= 0 && nodeY[y].size() == 0) y--;
    if (y < 0) return;
    for (auto node : nodeY[y]) {
        if (node.x > lo && node.x < hi) {<br>
            graph[parent].push_back(node.id);
            if (node.x < x)
                makeTree(lo, x, node.x, y - 1, node.id);
            else
                makeTree(x, hi, node.x, y - 1, node.id);
        }
    }
}

void preorder(int n) {
    if (n != 0) answer[0].push_back(n);
    for (auto next : graph[n])
        preorder(next);
}

void postorder(int n) {
    for (auto next : graph[n])
        postorder(next);
    if (n != 0) answer[1].push_back(n);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {<br>
    int genID = 1;
    for (auto p : nodeinfo)
        nodeY[p[1]].push_back({ p[0], genID++ });
    for (auto& y : nodeY)
        sort(y.begin(), y.end(), [](const Node& a, const Node& b) { return a.x < b.x; });
    makeTree(-1, 100001, 100001, 100000, 0);
    preorder(0), postorder(0);
    return answer;
}
```

## 링크
https://school.programmers.co.kr/learn/courses/30/lessons/42892
{% endraw %}