---
categories:
- Programmers
date: '2025-01-01'
title: '[Programmers] 연습문제 - 순위'
---

{% raw %}
> Lv. 3<br>

## 문제
n명의 권투선수가 권투 대회에 참여했고 각각 1번부터 n번까지 번호를 받았습니다. 권투 경기는 1대1 방식으로 진행이 되고, 만약 A 선수가 B 선수보다 실력이 좋다면 A 선수는 B 선수를 항상 이깁니다. 심판은 주어진 경기 결과를 가지고 선수들의 순위를 매기려 합니다. 하지만 몇몇 경기 결과를 분실하여 정확하게 순위를 매길 수 없습니다.

선수의 수 n, 경기 결과를 담은 2차원 배열 results가 매개변수로 주어질 때 정확하게 순위를 매길 수 있는 선수의 수를 return 하도록 solution 함수를 작성해주세요.

### 제한사항
-   선수의 수는 1명 이상 100명 이하입니다.
-   경기 결과는 1개 이상 4,500개 이하입니다.
-   results 배열 각 행 [A, B]는 A 선수가 B 선수를 이겼다는 의미입니다.
-   모든 경기 결과에는 모순이 없습니다.

## 해결
> 어떤 상대를 이겼다 = 해당 상대가 이긴 상대도 모두 이긴 것<br>
> 어떤 상대에게 졌다 = 해당 상대를 이긴 상대에게 모두 진 것<br>

인접한 상대의 연결 관계에 영향을 받으므로 `그래프`를 활용해볼 수 있습니다.

순위가 결정되는 조건은 다음과 같습니다.
> 이긴 상대 수 + 진 상대 수 = `n` - 1<br>

승리 그래프(간선: 승리 -> 패배), 패배 그래프(간선: 패배 -> 승리)를 각각 생성합니다. 어떤 정점의 승리 / 패배 횟수는 해당 정점의 시작점으로 했을 때, `그래프 탐색`해서 방문한 정점 수 - 1입니다.<br>

```
1. 승리, 패배 그래프 생성
2. 모든 정점의 누적 승리, 패배 횟수 구하기
	- 순위 결정 가능성 판단 및 정답 업데이트
```

## 코드
```
#include <vector>
#include <memory.h>
using namespace std;
const int SIZE = 101;
int answer; bool visited[SIZE];
vector<int> graphW[SIZE], graphL[SIZE];<br>

int DFS(int n, vector<int> graph[]) {<br>
    if(visited[n])
        return 0;
    int cnt = 1; visited[n] = 1;
    for(int c : graph[n])
        cnt += DFS(c, graph);
    return cnt;
}

int solution(int n, vector<vector<int>> results) {<br>
    for(auto edge : results) {
        graphW[edge[0]].push_back(edge[1]);
        graphL[edge[1]].push_back(edge[0]);
    }
    for(int i = 1; i <= n; i++) {
        memset(visited, 0, sizeof(visited));
        int win = DFS(i, graphW) - 1;
        memset(visited, 0, sizeof(visited));
        int lose = DFS(i, graphL) - 1;
        answer += (win + lose == n - 1 ? 1 : 0);
    }
    return answer;
}
```

## 링크
https://school.programmers.co.kr/learn/courses/30/lessons/49191
{% endraw %}