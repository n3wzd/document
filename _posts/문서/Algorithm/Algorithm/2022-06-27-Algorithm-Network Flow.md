---
categories:
- Algorithm
date: '2022-06-27'
title: '[Algorithm] Network Flow'
---

{% raw %}
## Network Flow
방향이 있는 그래프에서 `네트워크 플로우(Network Flow)` 또는 `최대 유량(Maximum Flow)`은 소스부터 싱크까지 보낼 수 있는 최대의 유량을 계산하는 문제다.

**최대 유량에서 사용되는 개념**
- **용량(Capacity)**: 간선에서 흐를 수 있는 유량의 최대치 (간선의 가중치하고 별개인 새로운 개념) 용량이 0이면 유량이 흐를 수 없다. 
- **유량(Flow)**: 간선에서 흐르는 실제 유량. 모든 유량은 간선의 방향을 따라 흐른다.
- **잔여 용량(Residual Capacity)**: 간선에서 용량과 유량의 차이 (=해당 경로에 추가적으로 더 흘려 보낼 수 있는 유량) 최대 유량 알고리즘에선 잔여 용량을 기준으로 탐색을 수행한다.
- **소스(source)**: 모든 유량이 시작되는 정점. 유량은 소스에서 무제한으로 공급된다.
- **싱크(sink)**: 모든 유량이 도착하는 정점. 싱크는 유량을 제한 없이 수용할 수 있다.

이름에서 볼 수 있듯이 유량 그래프의 유량은 실제 물의 흐름과 유사하다. 소스에서 물이 공급되며 싱크로 물이 빠져 나간다. 두 정점을 연결하는 간선은 물이 흐르는 파이프로 비유할 수 있으며, 용량은 물이 최대로 흐를 수 있는 한도라고 볼 수 있다.

## 포드-풀커슨 알고리즘 (Ford-Fulkerson Algorithm)
`포드-풀커슨 알고리즘`은 최대 유량을 계산하는 가장 기본적인 알고리즘이다. 다른 최대 유량 알고리즘도 포드-풀커슨 알고리즘을 베이스로 한다.

소스에서 싱크로 향하는 무작위 경로 1개를 `DFS`로 찾고, 이 경로에서 보낼 수 있는 최대 유량을 보낸다. 이 작업을 소스에서 싱크로 유량을 보낼 수 없을 때까지 반복한다. 최종 답은 보냈던 최대 유량의 총합이다.
```
1. 소스에서 싱크로 이동할 수 없을 때까지 반복
	1. 소스에서 싱크로 향하는 경로 1개를 찾는다. (DFS)
		- 용량이 0인 간선을 통해 이동할 수 없다.
	2. 찾은 경로에서 최대 유량 f를 찾는다.
		- f = 경로에 포함된 간선들의 잔여 용량 최솟값
		- 전체 최대 유량 += f
	3. 해당 경로에 유량 f를 보낸다.
		- 지나가는 간선에는 용량을 f만큼 뺀다.
		- 이때 각 간선의 역방향 간선에는 용량에 f를 더한다. (유량의 대칭성)
2. 전체 최대 유량 출력
```

최대 시간 복잡도는 O(Ef)이다. (E = 간선 개수, f = 전체 최대 유량)

### 유량의 대칭성
> f(a, b) = -f(b, a)<br>

a → b 방향으로 유량이 보낸 것은 b → a 방향으로 음수의 유량을 보내는 것과 동일하다. 즉, b → a으로 유량 f를 보낸 것은 a → b으로 보냈던 유량 f를 취소하는 것과 같다.

유량 알고리즘에서 중요하게 활용되는 특성으로, 유량의 대칭성으로 인해 어느 경로를 선택하든 최종적으로 최대 유량이 계산됨이 보장된다.

![](images/NF-flowgraph.png)

(S = 소스, T = 싱크, 간선 값 = 잔여 용량)
위의 그래프에서 최대 유량을 구해보자. 첫번째로 경로 S → A → B → T를 선택되었다. 최대 유량은 2이며, 이 유량을 흘려 보낸다.

![](images/NF-flowgraph2.png)
(파란 간선 = 역방향 간선)
경로 간선들의 잔여 용량이 최대 유량만큼 감소하였다. 또한 유량의 대칭성에 따라 역방향 간선은 최대 유량만큼 증가하였다. 다음 경로로 S → B → A → T를 선택하자. 이 경로는 역방향 간선을 타고 유량을 보낼 수 있으며, 최대 유량은 1이다. 유량을 보낸 뒤에는 더 이상 소스에서 싱크로 유량을 보낼 수 없으므로 계산이 끝난다. 최종 최대 유량은 구한 최대 유량의 총합인 3이다.

위의 탐색은 S → A  → T으로 유량 1,  S → A → B → T으로 유량 1, S → B → T으로 유량 1을 보낸 것과 같다.

만약 유량의 대칭성을 적용하지 않았다면, S → A → B → T에서 유량 2를 보낸 다음에는 소스에서 싱크로 유량을 보낼 수 없게 되어 2가 출력된다. 즉, 어떤 경로를 선택함에 따라 계산 결과가 달라지는 문제가 있다. 이러한 문제를 방지하기 위해 최대 유량 알고리즘은 유량의 대칭성을 적용하고 있다.

### 인접 리스트 vs 인접 행렬
알고리즘에서 간선의 변경이 자주 발생하기 때문에 인접 행렬을 사용하면 구현이 편리하다. 하지만 복잡도가 큰 것은 여전하기 때문에 정점, 간선이 많은 그래프라면 인접 리스트를 사용해야 한다.

**인접 리스트 사용 시 고려사항**
- 최대 유량 알고리즘은 역방향 간선만 알면 되기 때문에 간선 데이터에 역방향 간선의 인덱스(정점 번호가 아닌 vector에서 인덱스)를 추가로 저장하면 된다.
- 인접 리스트로 간선을 추가한다면 해당 간선의 역방향 간선도 같이 추가해야 한다. 이때 역방향 간선의 용량은 0이다.

인접 리스트는 비록 처음 구현이 불편하긴 하지만, 한번 구현해두면 추후 시간 문제로 막히는 일이 없어 편리하다.

### 코드
`BOJ - 6086 - 최대 유량` 코드
```
#include <iostream>
#include <memory.h>
#define SIZE 55
using namespace std;
int M, maxFlow = 0;
int graph[SIZE][SIZE];
bool visited[SIZE];
const int S = 0, T = 25, INF = 1 << 29;

int DFS(int v, int flow) {
	visited[v] = 1;
	if (v == T) return flow;

	for (int nv = 0; nv < SIZE; nv++) {
		int w = graph[v][nv];
		if (visited[nv] || w == 0) continue;

		int nextFlow = DFS(nv, min(flow, w));
		if (nextFlow) {
			graph[v][nv] -= nextFlow;
			graph[nv][v] += nextFlow;
			return nextFlow;
		}
	}
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> M;<br>
	for (int i = 0; i < M; i++) {
		char ca, cb;
		int a, b, w;
		cin >> ca >> cb >> w;<br>
		a = (ca < 'a') ? ca - 'A' : ca - 'a' + 26;
		b = (cb < 'a') ? cb - 'A' : cb - 'a' + 26;
		graph[a][b] += w;
		graph[b][a] += w;
	}

	while (1) {
		memset(visited, 0, sizeof(visited));
		int flow = DFS(S, INF);
		if (flow == 0) break;
		maxFlow += flow;
	}
	cout << maxFlow;
	return 0;
}
```

## 에드몬드-카프 알고리즘 (Edmonds-Karp Algorithm)
포드-풀커슨 알고리즘의 시간 복잡도는 최대 유량에 영향을 받으며, 최대 유량이 증가하면 시간이 오래 걸린다는 단점이 있다. 포드-풀커슨 알고리즘은 무작위로 경로를 선택하므로 잔여 용량이 작은 비효율적인 간선을 선택할 수 있기 때문이다. 이 문제를 보완하기 위해 `에드몬드-카프 알고리즘`이 사용된다.

`에드몬드-카프 알고리즘`은 전체적으로 포드-풀커슨 알고리즘과 동일한데, 최단 거리(=경로상 최소 간선 개수)인 경로를 선택해서 유량을 보낸다. 최단 경로를 찾기 위해 `DFS` 대신 `BFS`를 사용한다.
```
1. 소스에서 싱크로 이동할 수 없을 때까지 반복
	1. 소스에서 싱크로 향하는 최단 경로 1개를 찾는다. (BFS)
		- 용량이 0인 간선을 통해 이동할 수 없다.
	2. 찾은 경로에서 최대 유량 f를 찾는다.
		- f = 경로에 포함된 간선들의 잔여 용량 최솟값
		- 전체 최대 유량 += f
	3. 해당 경로에 유량 f를 보낸다.
		- 지나가는 간선에는 잔여 용량을 f만큼 뺀다.
		- 이때 각 간선의 역방향 간선에는 잔여 용량에 f를 더한다. (유량의 대칭성)
2. 전체 최대 유량 출력
```

시간 복잡도는 min(O(V × E<sup>2</sup>), O(Ef))이다.

가중치가 있는 그래프에서는 `MCMF` 알고리즘이 사용된다.

### 코드
`BOJ - 6086 - 최대 유량` 코드
```
#include <iostream>
#include <queue>
#include <memory.h>
#define SIZE 55
using namespace std;
int M;
int graph[SIZE][SIZE];
bool visited[SIZE];
int parent[SIZE];
const int S = 0, T = 25, INF = 1 << 29;

bool BFS() {
	memset(visited, 0, sizeof(visited));
	queue <int> q;<br>
	q.push(S);
	visited[S] = 1;

	while (!q.empty()) {
		int v = q.front(); q.pop();
		for (int nv = 0; nv < SIZE; nv++) {
			int w = graph[v][nv];
			if (visited[nv] || w == 0) continue;

			parent[nv] = v;
			visited[nv] = 1;
			q.push(nv);
		}
	}
	return visited[T];
}

int NetFlow() {
	int sumFlow = 0;
	while (BFS()) {
		int minFlow = INF;
		for (int v = T; v != S; v = parent[v])
			minFlow = min(minFlow, graph[parent[v]][v]);

		for (int v = T; v != S; v = parent[v]) {
			graph[parent[v]][v] -= minFlow;
			graph[v][parent[v]] += minFlow;
		}
		sumFlow += minFlow;
	}
	return sumFlow;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> M;<br>
	for (int i = 0; i < M; i++) {
		char ca, cb;
		int a, b, w;
		cin >> ca >> cb >> w;<br>
		a = (ca < 'a') ? ca - 'A' : ca - 'a' + 26;
		b = (cb < 'a') ? cb - 'A' : cb - 'a' + 26;
		graph[a][b] += w;
		graph[b][a] += w;
	}

	cout << NetFlow();
	return 0;
}
```

## 디닉 알고리즘 (Dinic's Algorithm)
에드몬드-카프 알고리즘의 시간 복잡도는 간선 개수에 영향을 크게 받기 때문에 간선 개수가 많다면 계산이 오래 걸린다는 문제가 있다. 이때는 `디닉 알고리즘`이 사용된다.

`디닉 알고리즘`은 `에드몬드-카프 알고리즘`과 `포드-풀커슨 알고리즘`을 합한 것과 비슷하다. `BFS`를 사용해서 레벨 그래프를 생성하고, 이 그래프에서 포드-풀커슨 알고리즘과 비슷한 탐색을 수행한다.
- 레벨 그래프(Level Graph): 모든 정점에 대해 레벨을 부여한 배열
	- 인덱스 = 현재 정점 번호
	- 값(레벨) = 소스부터 현재 정점까지 최단 거리 (=최단 경로에 포함된 간선 개수)
	- 레벨 그래프를 생성할 때는 소스부터 시작한다.
	- 레벨 그래프의 완성 조건: 싱크의 레벨이 기록되어 있어야 한다.
- 차단 유량(Blocking Flow): 레벨 그래프를 생성할 때 용량이 0인 간선은 이동하지 않는다.
```
1. 레벨 그래프를 만들 수 없을 때까지 반복
	1. 레벨 그래프 생성 (BFS)
		- 소스부터 현재 정점까지 최단 거리 기록
		- 용량이 0인 간선을 통해 이동할 수 없다.
		- 싱크의 레벨이 기록되어 있다면 레벨 그래프 완성
	2. 소스에서 싱크로 향하는 최단 경로 1개를 찾는다. (DFS)
		- 레벨 그래프를 사용해서 최단 경로를 판정할 수 있다.
		- 용량이 0인 간선을 통해 이동할 수 없다.
		- 이전에 선택했던 경로는 선택하지 않는다.
	3. 찾은 경로에서 최대 유량 f를 찾는다.
		- f = 경로에 포함된 간선들의 잔여 용량 최솟값
		- 전체 최대 유량 += f
	4. 해당 경로에 유량 f를 보낸다.
		- 지나가는 간선에는 잔여 용량을 f만큼 뺀다.
		- 이때 각 간선의 역방향 간선에는 잔여 용량에 f를 더한다. (유량의 대칭성)
2. 전체 최대 유량 출력
```

이전에 선택한 경로는 이미 최대 유량을 보냈으므로 다시 탐색하지 않아도 된다. 따라서 시간 절약을 위해 DFS에선 이미 탐색한 경로를 방문하지 않는다. 현재 정점이 탐색한 인접 간선 개수를 저장하는 배열(work)를 사용해서 이를 구현할 수 있다.

시간 복잡도는 O(V<sup>2</sup> × E)이다. 평균적으로 3가지 알고리즘 중에서 가장 빠르다.<br>

### 코드
#### 인접 행렬
`BOJ - 6086 - 최대 유량` 코드
```
#include <iostream>
#include <queue>
#include <memory.h>
#define SIZE 55
using namespace std;
int M;
int graph[SIZE][SIZE];
int level[SIZE], work[SIZE];
const int S = 0, T = 25, INF = 1 << 29;

bool BFS() {
	memset(level, -1, sizeof(level));
	queue <int> q;<br>
	q.push(S);
	level[S] = 0;

	while (!q.empty()) {
		int v = q.front(); q.pop();
		for (int nv = 0; nv < SIZE; nv++) {
			int w = graph[v][nv];
			if (level[nv] != -1 || w == 0) continue;

			level[nv] = level[v] + 1;
			q.push(nv);
		}
	}
	return level[T] != -1;
}

int DFS(int v, int flow)  {
	if (v == T) return flow;

	for (int& nv = work[v]; nv < SIZE; nv++) {
		int w = graph[v][nv];
		if (w == 0 || level[v] + 1 != level[nv]) continue;

		int nextFlow = DFS(nv, min(flow, w));
		if (nextFlow) {
			graph[v][nv] -= nextFlow;
			graph[nv][v] += nextFlow;
			return nextFlow;
		}
	}
	return 0;
}

int NetFlow() {
	int sumFlow = 0;
	while (BFS()) {
		memset(work, 0, sizeof(work));
		while (1) {
			int flow = DFS(S, INF);
			if (flow == 0) break;
			sumFlow += flow;
		}
	}
	return sumFlow;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> M;<br>
	for (int i = 0; i < M; i++) {
		char ca, cb;
		int a, b, w;
		cin >> ca >> cb >> w;<br>
		a = (ca < 'a') ? ca - 'A' : ca - 'a' + 26;
		b = (cb < 'a') ? cb - 'A' : cb - 'a' + 26;
		graph[a][b] += w;
		graph[b][a] += w;
	}

	cout << NetFlow();
	return 0;
}
```

#### 인접 리스트
`BOJ - 1420 - 학교 가지마!` 코드
```
#include <iostream>
#include <queue>
#include <memory.h>
#define SIZE 20002
using namespace std;
struct Edge { int next, cap, prevIdx; };
int N, M;
vector<Edge> graph[SIZE];<br>
int level[SIZE], work[SIZE];
int S, T, INF = 1 << 29;

bool BFS() {
	memset(level, -1, sizeof(level));
	queue <int> q;<br>
	q.push(S);
	level[S] = 0;

	while (!q.empty()) {
		int v = q.front(); q.pop();
		int len = graph[v].size();
		for (int i = 0; i < len; i++) {
			int w = graph[v][i].cap, nv = graph[v][i].next;
			if (level[nv] != -1 || w == 0) continue;

			level[nv] = level[v] + 1;
			q.push(nv);
		}
	}
	return level[T] != -1;
}

int DFS(int v, int flow) {
	if (v == T) return flow;

	int len = graph[v].size();
	for (int& i = work[v]; i < len; i++) {
		int w = graph[v][i].cap, nv = graph[v][i].next, prev = graph[v][i].prevIdx;
		if (w == 0 || level[v] + 1 != level[nv]) continue;

		int nextFlow = DFS(nv, min(flow, w));
		if (nextFlow) {
			graph[v][i].cap -= nextFlow;
			graph[nv][prev].cap += nextFlow;
			return nextFlow;
		}
	}
	return 0;
}

int NetFlow() {
	int sumFlow = 0;
	while (BFS()) {
		memset(work, 0, sizeof(work));
		while (1) {
			int flow = DFS(S, INF);
			if (flow == 0) break;
			sumFlow += flow;
		}
	}
	return sumFlow;
}

int In(int a) {	return a * 2; }
int Out(int a) { return a * 2 + 1; }

void MakeEdge(int a, int b, int w) {
	graph[a].push_back({ b, w, (int)graph[b].size() });
	graph[b].push_back({ a, 0, (int)graph[a].size() - 1 });
}

void Connect(int id) {
	int dx[4] = { 1, M, -1, -M };
	for (int d = 0; d < 4; d++) {
		int newId = id + dx[d];
		if (newId < 0 || newId >= N * M) continue;
		if (d % 2 == 0 && id / M != newId / M) continue;
		MakeEdge(Out(id), In(newId), 1);
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;<br>
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			int id = y * M + x;
			char c;
			cin >> c;<br>
			if (c == 'K') S = id;
			if (c == 'H') T = id;
			if (c != '#') MakeEdge(In(id), Out(id), 1);
			Connect(id);
		}
	}

	if ((S / M == T / M && S + 1 == T) || (S / M == T / M && S - 1 == T)
		|| S + M == T || S - M == T) cout << "-1";
	else {
		S = Out(S), T = In(T);
		cout << NetFlow();
	}
	return 0;
}
```
## 접근
일반적으로 최대 유량을 활용한 문제는 주로 다음과 같은 패턴을 가진다.
1. 유량 그래프를 생성한다.
2. 최대 유량이 답으로 직결된다.

유량을 흘러 보내려면 소스, 싱크가 필수이므로 소스와 싱크를 생성하고 연결하는 것이 중요하다. 주로 소스, 싱크를 새로 생성하고 한쪽 정점 집합은 소스, 다른 정점 집합은 싱크에 연결한다. 소스 → 싱크 방향으로 유량을 보내면 두 집합에 속한 간선의 용량이 같이 줄어든다는 성질을 활용해보자.

이러한 아이디어는 2개의 집합에서 매칭을 하는 `이분 매칭`과 흡사한 면이 많다. 이분 매칭의 본질은 최대 유량이므로 이분 매칭 아이디어로 접근해도 좋다.

## 최소 컷(Minimum Cut)
연결 그래프에서 정점 A, B가 각각 분리된 그래프에 속하도록 적당한 간선들을 절단하는 문제가 있다고 하자. 이때 절단 비용의 총합은 끊어진 간선 가중치의 총합이다. 이 절단 비용 총합의 최소를 구하는 것이 `최소 컷(Minimum Cut)` 문제다.

최소 컷 문제는 `최대 유량` 문제하고 같다는 사실이 증명되어 있다.
> 최소 컷 문제는 최대 유량 문제로 모델링해서 해결할 수 있다.<br>

정점 A, B를 각각 소스, 싱크로 했을 때 구한 최대 유량이 바로 최소 컷이다.

## 정점 분할
`최대 유량` 문제에서 정점의 방문 가능성을 판단해보자.

최대 유량 알고리즘은 유량을 보낼 때마다 방문한 정점 기록을 초기화해야 한다. 즉 임의의 정점 A를 방문해도 유량을 보낸 이후 다음 탐색에서 A를 재방문할 수 있어야 한다. 그렇기 때문에 단순히 방문 배열로 중복 방문을 처리하면 답을 구할 수 없다.

정점 분할 아이디어를 적용하면 정점 문제를 간선 문제로 바꿀 수 있다.
> 1개의 정점을 들어오는 간선, 나가는 간선을 담당하는 2개의 정점으로 분리한다.<br>
> 분리된 정점은 용량이 1인 단방향 간선으로 연결한다.<br>

내부의 간선이 해당 정점의 방문 가능성을 담당한다. 예를 들어 정점을 방문하면 내부의 간선이 사용되므로 정점이 최대 1번만 방문된다. 
```
ex.
A → B → C
A B
B C

> 정점 분할<br>
(A → A') → (B → B') → (C → C')
A A'
B B'
C C'
A' B
B' C
```

분리된 정점 라벨링은 (기존 정점 번호)×2 (+ 1)으로 하면 편리하다.
- 들어오는 간선 담당 = id × 2
- 나가는 간선 담당 = id × 2 + 1

## 관련 문제
### 최대 유량
https://www.acmicpc.net/problem/6086<br>
https://www.acmicpc.net/problem/2365<br>
https://www.acmicpc.net/problem/11495<br>

### 최소 컷
https://www.acmicpc.net/problem/13161<br>
https://www.acmicpc.net/problem/1420<br>

### 정점 분할
https://www.acmicpc.net/problem/2316<br>
https://www.acmicpc.net/problem/1420<br>

## 참고
https://anz1217.tistory.com/51<br>
https://everenew.tistory.com/177<br>
https://www.crocus.co.kr/1088<br>
https://www.crocus.co.kr/755<br>
{% endraw %}