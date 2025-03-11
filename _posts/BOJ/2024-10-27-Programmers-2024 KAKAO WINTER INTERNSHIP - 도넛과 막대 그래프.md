---
categories:
- Programmers
date: '2024-10-27'
title: '[Programmers] 2024 KAKAO WINTER INTERNSHIP - 도넛과 막대 그래프'
---

{% raw %}
> Lv. 2<br>

## 문제
도넛 모양 그래프, 막대 모양 그래프, 8자 모양 그래프들이 있습니다. 이 그래프들은 1개 이상의 정점과, 정점들을 연결하는 단방향 간선으로 이루어져 있습니다.

-   크기가  `n`인 도넛 모양 그래프는  `n`개의 정점과  `n`개의 간선이 있습니다. 도넛 모양 그래프의 아무 한 정점에서 출발해 이용한 적 없는 간선을 계속 따라가면 나머지  `n`-1개의 정점들을 한 번씩 방문한 뒤 원래 출발했던 정점으로 돌아오게 됩니다.

-   크기가  `n`인 막대 모양 그래프는  `n`개의 정점과  `n`-1개의 간선이 있습니다. 막대 모양 그래프는 임의의 한 정점에서 출발해 간선을 계속 따라가면 나머지  `n`-1개의 정점을 한 번씩 방문하게 되는 정점이 단 하나 존재합니다.

-   크기가  `n`인 8자 모양 그래프는  `2n`+1개의 정점과  `2n`+2개의 간선이 있습니다. 8자 모양 그래프는 크기가 동일한 2개의 도넛 모양 그래프에서 정점을 하나씩 골라 결합시킨 형태의 그래프입니다.

도넛 모양 그래프, 막대 모양 그래프, 8자 모양 그래프가 여러 개 있습니다. 이 그래프들과 무관한 정점을 하나 생성한 뒤, 각 도넛 모양 그래프, 막대 모양 그래프, 8자 모양 그래프의 임의의 정점 하나로 향하는 간선들을 연결했습니다.  
그 후 각 정점에 서로 다른 번호를 매겼습니다.  
이때 당신은 그래프의 간선 정보가 주어지면 생성한 정점의 번호와 정점을 생성하기 전 도넛 모양 그래프의 수, 막대 모양 그래프의 수, 8자 모양 그래프의 수를 구해야 합니다.

그래프의 간선 정보를 담은 2차원 정수 배열  `edges`가 매개변수로 주어집니다. 이때, 생성한 정점의 번호, 도넛 모양 그래프의 수, 막대 모양 그래프의 수, 8자 모양 그래프의 수를 순서대로 1차원 정수 배열에 담아 return 하도록 solution 함수를 완성해 주세요.

### 제한사항
-   1 ≤  `edges`의 길이 ≤ 1,000,000
    -   `edges`의 원소는 [`a`,`b`] 형태이며,  `a`번 정점에서  `b`번 정점으로 향하는 간선이 있다는 것을 나타냅니다.
    -   1 ≤  `a`,  `b`  ≤ 1,000,000
-   문제의 조건에 맞는 그래프가 주어집니다.
-   도넛 모양 그래프, 막대 모양 그래프, 8자 모양 그래프의 수의 합은 2이상입니다.

## 해결
`그래프`의 간선 in, out 개수를 이용해서 판정할 수 있습니다.
- 기준 정점은 항상 in이 0이고 out이 2보다 같거나 크며, 이러한 정점은 유일합니다.
- 막대 그래프는 out이 0인 정점이 항상 존재하며, 이러한 정점은 막대 그래프에만 있습니다.
- 8자 그래프는 out이 2인 정점이 항상 존재하며, 이러한 정점은 기준 정점을 제외하고 8자 그래프에만 있습니다.
- 도넛 그래프, 8자 그래프는 순회 시 제자리로 돌아옵니다.

```
1. 그래프 생성 (인접 리스트)
	- 정점별 간선 in, out 카운팅
2. 기준 정점 찾기 (in == 0, out >= 2인 정점)
3. 기준 정점의 다음 정점 모두 탐색:
	1. 현재 정점의 out 찾기
	2. out == 2: 8자 그래프, 탐색 종료
	3. out == 0: 막대 그래프, 탐색 종료
	4. 현재 정점 == 처음 정점: 도넛 그래프, 탐색 종료
	5. 다음 정점으로 이동
```

## 코드
```
#include <iostream>
#include <vector>
using namespace std;
int S, A, B, C, N;
vector<int> edges[1000001];<br>
int inCnt[1000001];
int in(int n) { return inCnt[n]; }
int out(int n) { return edges[n].size(); }

vector<int> solution(vector<vector<int>> edgesInput) {<br>
    vector<int> answer;<br>
    for(vector<int> edge : edgesInput) {<br>
        edges[edge[0]].push_back(edge[1]);
        N = max(N, max(edge[0], edge[1]));
        inCnt[edge[1]]++;
    }
    for(int i = 1; i <= N; i++)
        if(in(i) == 0 && out(i) >= 2)
            S = i;
    for(int next : edges[S]) {
        int first = next; bool isStart = 1;
        while(1) {
            if(out(next) == 2) {
                C++;
                break;
            }
            if(out(next) == 0) {
                B++;
                break;
            }
            if(next == first && !isStart) {
                A++;
                break;
            }
            isStart = 0;
            next = edges[next][0];
        }
    }
    return { S, A, B, C };
}
```

## 링크
https://school.programmers.co.kr/learn/courses/30/lessons/258711
{% endraw %}