---
categories:
- Algorithm
date: '2022-07-07'
title: '[Algorithm] DFS & BFS'
---

{% raw %}
## DFS & BFS
그래프의 모든 정점을 중복 없이 1번씩 방문하는 방법. DFS, BFS의 차이는 탐색 우선 방향에 있다.

각 정점의 '방문 상태'를 저장하는 캐시를 통해 중복 방문을 피한다. `DP`의 메모이제이션처럼 각각의 방문 상태 값은 정점에 대해 일대일 대응이 되어야 한다. (함수 구조) 일반적으로 방문 캐시는 전역 변수로 구현된다.

## DFS (Depth First Search)
깊이 우선으로 탐사한다. 만약 인접 정점이 여러 개 있을 때, 정점 하나의 모든 분기를 탐색하고 다음 인접 정점으로 넘어간다.

일반적으로 재귀 함수(백트래킹), 스택을 사용해서 구현한다.

```
DFS(s)
1. 현재 정점 = s
2. 현재 정점과 인접한 정점들을 가져오고, 하나씩 조사한다. => v<br>
	- v가 방문 상태면 패스.
	- 그렇지 않으면, v는 첫 방문이다. => v의 방문 과정을 처리한다.<br>
		- DFS(v) 호출하고 v의 방문 표시 설정.
```

## BFS (Breadth First Search)
넓이 우선으로 탐사한다. 만약 인접 정점이 여러 개 있을 때, 해당 인접 정점들만을 먼저 탐사하고, 다음 깊이로 넘어간다.

일반적으로 큐를 사용해서 구현한다.

```
BFS(s)
1. 시작 정점 s를 큐 Q에 넣고, s의 방문 과정을 처리한다.
2. Q가 빌 때까지 반복
	1. Q에서 정점 하나를 꺼낸다. => v<br>
	2. 정점 v의 인접 정점들을 가져오고, 하나씩 조사한다. => w<br>
		- w가 방문 상태면 패스.
		- 그렇지 않으면, w는 첫 방문이다. => w의 방문 과정을 처리한다.<br>
			- w를 Q에 넣고, w의 방문 표시 설정.
```

## 코드
```
#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#define SIZE 1002
using namespace std;

int N, M, V;
bool visited[SIZE] = { 0, };
vector<int> graph[SIZE];<br>

void DFS(int v)
{
	visited[v] = true;
	printf("%d ", v);

	int len = graph[v].size();
	for (int i = 0; i < len; i++)
	{
		int next = graph[v][i];
		if (!visited[next])
			DFS(next);
	}
}

void BFS(int s)
{
	queue<int> q;<br>
	q.push(s);
	visited[s] = true;

	while (!q.empty())
	{
		int v = q.front();
		q.pop();
		printf("%d ", v);

		int len = graph[v].size();
		for (int i = 0; i < len; i++)
		{
			int next = graph[v][i];
			if (!visited[next])
			{
				q.push(next);
				visited[next] = true;
			}
		}
	}
}

int main()
{
	scanf("%d%d%d", &N, &M, &V);
	for (int i = 1; i <= M; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	DFS(V);
	printf("\n");

	memset(visited, 0, SIZE);
	BFS(V);
	return 0;
}
```

### 연관 문제
https://www.acmicpc.net/problem/1260
https://www.acmicpc.net/problem/1012
https://www.acmicpc.net/problem/1707
https://www.acmicpc.net/problem/3197

## DFS vs BFS
일반적인 상황에서 그래프의 모든 정점을 방문하는 목적 뿐이라면 아무거나 선택해도 상관없다. 그러나 상황에 따라 어떤 것이 적합한지는 다를 수 있으므로, 탐색 방향을 기준으로 필요에 따라 선택해서 사용하면 된다.

DFS는 한쪽 분기를 끝날 때까지 탐사하므로, 끝이 없는 그래프(ex. 깊이가 무한한 트리)에선 영원히 빠져나오지 못할 수 있다. 이 경우에는 탐색 최대 깊이를 제한하거나 BFS를 사용한다.

## 최단 거리 BFS
BFS는 연결 간선의 가중치를 고려하지 않는 그래프에서 두 정점 사이의 최단 거리를 찾는 데 활용할 수도 있다.

BFS에서 거리를 구하는 방법은 여러 가지가 있으며, 이하 설명에선 첫번째 방법을 기준으로 한다.
1. 방문 캐시에 현재 위치의 거리를 기록
2. 매 거리마다 큐 길이만큼 순회
3. 거리 변경을 트리거하는 임시 정점을 큐에 삽입

각 정점(노드)마다 출발점으로부터의 최단 거리를 저장하는 변수를 하나 추가한다. 위에서 사용한 방문 캐시에 추가해도 되고, 별도의 외부 변수나 정점 내부 변수로 추가해도 된다. (단, 방문 캐시로 활용하는 경우, 거리가 0인 경우를 중복 방문할 수 있으므로 주의)
```
BFS(s)
1. 시작 정점 s를 큐 Q에 넣고, s의 방문 과정을 처리한다.
	- dist[s] = 0
2. Q가 빌 때까지 반복
	1. Q에서 정점 하나를 꺼낸다. => v<br>
	2. 정점 v의 인접 정점들을 가져오고, 하나씩 조사한다. => w<br>
		- w가 방문 상태면 패스.
		- 그렇지 않으면, w는 첫 방문이다. => w의 방문 과정을 처리한다.<br>
			- dist[w] = dist[v] + 1
			- w를 Q에 넣고, w의 방문 표시 설정.
```

가중치가 있는 그래프의 최단 거리는 다익스트라, 벨먼 포드 알고리즘 등으로 구한다.

## 구현 예시
"BOJ - 7562 - 나이트의 이동" 코드의 일부
```
class Node // 정점
{
public:
	int x, y;
	Node(int a, int b) { x = a, y = b; }
};

int dist[1000][1000] = { 0, }; // 최단거리(방문) 캐시 (0이면 방문X, 1이상이면 출발점으로부터 현재 위치까지 최단 거리)
int dx[8] = { -2, -1, 1, 2, -2, -1, 1, 2 }; // 연결 간선
int dy[8] = { 1, 2, 2 ,1, -1, -2, -2, -1 };

void BFS(start_x, start_y) // 최단거리 BFS
{
	queue<Node> q;<br>
	q.push(Node(start_x, start_y)); // 출발지 설정
	dist[start_y][start_x] = 0;

	while (!q.empty())
	{
		Node v = q.front();
		q.pop();
		int x = v.x, y = v.y;

		if (x == goal_x && y == goal_y) // 목적지 도달
		{
			printf("%d\n", dist[y][x]); // 출발지부터 목적지까지 최단거리 출력
			return;
		}

		for (int i = 0; i < 8; i++)
		{
			int nx = x + dx[i], ny = y + dy[i]; // 인접 정점 구하기

			if (nx >= 0 && nx < N && ny >= 0 && ny < N)
			{
				if (dist[ny][nx] == 0) // 첫 방문 검사
				{
					q.push(Node(nx, ny));
					dist[ny][nx] = dist[y][x] + 1; // 최단거리 기록
				}
			}
		}
	}
}
```

### 연관 문제
https://www.acmicpc.net/problem/2178
https://www.acmicpc.net/problem/7576
https://www.acmicpc.net/problem/7562
https://www.acmicpc.net/problem/2206
https://www.acmicpc.net/problem/14226
https://www.acmicpc.net/problem/5427

## BFS vs DP
최단거리 BFS로 문제를 해결하는 과정은 마치 DP와 비슷한 면이 있다. 양측 모두 캐시를 통해 현재 상태를 기록하며, 부분 문제로 분할이 가능한 것처럼 보이기 때문. 그러나 몇몇 문제는 DP를 사용할 수 없고, BFS를 사용해야 한다. 그럼 이 두 방법의 차이는 무엇일까?

BFS와 DP의 차이는 **시작(점화식의 초항), 사이클의 유무** 이다. 초항이 있고, 사이클이 없어야 DP를 사용할 수 있다. 초항이 없다면 점화식이 무한히 아래로 뻗어나가며, 사이클이 존재하면 분할이 성립하지 않으므로 DP로 해결할 수 없다.

예를 들어, `BOJ - 1697 - 숨바꼭질`은 이동 한도가 없는 상황에서 무한히 반대편 방향으로 이동하는 것이 가능하기 때문에 점화식의 초항이 없다. 또한 제자리로 돌아오는 사이클이 가능하다. 이 문제는 DP 대신 최단거리 BFS로 해결해야 한다.

정리하자면, 문제 분할을 그래프로 표현했을 때 **유한한 트리 구조** 가 아니면 DP를 사용할 수 없다.

## 참고
https://namu.wiki/w/%EA%B9%8A%EC%9D%B4%20%EC%9A%B0%EC%84%A0%20%ED%83%90%EC%83%89
https://namu.wiki/w/%EB%84%88%EB%B9%84%20%EC%9A%B0%EC%84%A0%20%ED%83%90%EC%83%89
https://gmlwjd9405.github.io/2018/08/14/algorithm-dfs.html
{% endraw %}