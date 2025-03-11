# 0-1 BFS
## 0-1 BFS
일반적으로 가중치가 구분되는 그래프의 최단 거리는 `다익스트라 알고리즘`으로 찾는다. 그러나 가중치가 0과 1만 존재하는 특수한 경우라면 `BFS` 최단 거리 알고리즘으로도 찾을 수 있다. 이러한 방법을 `0-1 BFS` 알고리즘이라 한다.

0-1 BFS는 일반적인 BFS 최단 거리 알고리즘과 비슷하지만, 최단 거리가 짧은 정점부터 우선 탐색한다. 다익스트라 알고리즘처럼 탐색을 통해 최단 거리가 줄어든 정점만 큐에 삽입하며, 큐는 항상 최단 거리 순으로 정렬되어 있어야 한다.

정렬을 위해 우선순위 큐를 사용할 수 있으나, 원소를 추가할 때마다 O(log N)를 소모한다. 하지만 그래프의 가중치가 0과 1만 있는 특수한 상황이면, 우선순위 큐를 사용하지 않고도 O(1) 시간으로 정렬할 수 있다.

현재 정점 v을 탐색할 때, 다음과 같이 2가지 경우만 존재한다. (이웃 정점 = w)
1.  (v→w) 거리는 0이다.
2.  (v→w) 거리는 1이다.

만약 가중치가 0인 경우를 큐의 앞쪽에 추가하고, 가중치가 1인 경우를 큐의 뒤쪽에 추가하면 큐는 정렬된 상태를 유지할 수 있다. 이는 큐의 앞뒤 양방향으로 원소를 추가할 수 있는 `덱(deque)`을 사용해서 구현할 수 있다.
```
0-1 BFS(s)
0. 최단거리 저장 배열 dist를 준비한다.
	- dist의 인덱스: 도착 정점 번호
	- dist의 값: s에서 도착 정점까지 최단 거리
		- dist의 초기 값 -> dist[s] = 0, 나머지는 모두 INF
2. 시작 정점 s를 덱 Q에 넣는다.
3. Q가 빌 때까지 반복
	1. Q에서 정점 하나를 꺼낸다. => v
	2. 정점 v의 인접 정점들을 모두 가져오고, 정점 하나씩 조사한다. => w
		- 만약 w로 이동할 수 있는 최단 거리 dist를 갱신할 수 있다면 업데이트한다.
		- dist[v] + weight(v, w) < dist[w]
			- dist[w] = dist[v] + weight(v, w)
			- 가중치가 0이면 큐의 앞쪽에, 1이면 큐의 뒤쪽에 w를 추가한다.
```
전체적으로 BFS 최단 거리와 다익스트라 알고리즘을 절충한 것과 비슷한 구조다.

일반 BFS와 마찬가지로, 0-1 BFS의 시간 복잡도는 O(V + E)이다. (V = 정점 개수, E = 간선 개수) 다익스트라 알고리즘보다 빠르다! 따라서 0-1 그래프에서 최단 거리를 구한다면, 0-1 BFS를 사용하는 것이 효율적이다.

## 코드
"13549 - 숨바꼭질 3"의 코드
```
#include <iostream>
#include <queue>
using namespace std;
# define MAXV 100002

int N, K;
int dist[MAXV] = { 0, };

void BFS(int start)
{
	for (int i = 0; i < MAXV; i++) // 최단거리 배열 초기값 설정
		dist[i] = MAXV;

	deque<int> deq;
	deq.push_back(start);
	dist[start] = 0;

	while (!deq.empty())
	{
		int x = deq.front();
		deq.pop_front();

		if (x == K) // 목적지 도달
		{
			printf("%d\n", dist[x]);
			return;
		}

		for (int i = 0; i < 3; i++)	// 인접 정점 탐색
		{
			int nx;
			if (i == 0) nx = x * 2;
			if (i == 1) nx = x + 1;
			if (i == 2) nx = x - 1;

			if (nx >= 0 && nx < MAXV)
			{
				if (i == 0 && dist[nx] > dist[x]) // 가중치가 0인 경우
				{
					dist[nx] = dist[x];
					deq.push_front(nx); // 덱의 앞쪽에 추가
				}
				else if (dist[nx] > dist[x] + 1) // 가중치가 1인 경우
				{
					dist[nx] = dist[x] + 1;
					deq.push_back(nx); // 덱의 뒤쪽에 추가
				}
			}
		}
	}
}

int main()
{
	cin >> N >> K;
	BFS(N);
	return 0;
}
```

## 관련 문제
https://www.acmicpc.net/problem/13549

## 참고
https://www.geeksforgeeks.org/0-1-bfs-shortest-path-binary-graph/
https://justicehui.github.io/medium-algorithm/2018/08/30/01BFS/

