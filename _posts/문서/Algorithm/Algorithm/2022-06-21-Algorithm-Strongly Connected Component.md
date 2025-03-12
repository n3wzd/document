---
categories:
- Algorithm
date: '2022-06-21'
title: '[Algorithm] Strongly Connected Component'
---

{% raw %}
## 강한 연결 요소(SCC)
방향 그래프에서 어떤 정점 집합에 있는 임의의 두 정점 A, B에 대해서 항상 A→B로 가는 경로가 존재한다면, 해당 집합을 `강한 연결 요소(SCC, Strongly Connected Component)`라고 한다.

SCC에 대한 명확한 정의는 다음과 같다.
> 1. 같은 SCC 내의 임의의 두 정점 A, B사이의 경로는 항상 존재한다.<br>
> 2. 서로 다른 SCC에서 각각 1개씩 선택한 두 정점 A, B 사이의 경로는 A→B,  B→A가 동시에 존재할 수 없다. = SCC간의 사이클이 존재하지 않는다.<br>

```
ex.
1  →  2  →  4
↑  ↙      ↓ ↑
3           5

> SCC = {1, 2, 3}, {4, 5}<br>
```

SCC를 구하는 방법으로 `코사라주 알고리즘`, `타잔 알고리즘`이 있다. 코사라주 알고리즘은 설계/구현이 상대적으로 쉽고, 타잔 알고리즘은 적용이 쉽다는 이점이 있다. 그래도 큰 차이는 아니므로 2개 중 아무거나 선택해서 사용해도 된다. 시간 복잡도는 두 방법 모두 `DFS`하고 동일한 O(V + E)이다. (V = 정점 개수, E = 간선 개수)

## 코사라주 알고리즘
기존 방향 그래프의 모든 간선 방향을 뒤집은 역방향 그래프를 사용하며 2번의 DFS를 수행해서 SCC를 구하는 방법.

정방향 그래프에서 DFS를 수행한 정점을 스택에 삽입하고, 스택에서 꺼내 역방향 그래프에 DFS를 하면 SCC를 구할 수 있다.
```
1. 정방향 그래프, 역방향 그래프 생성
2. 정방향 그래프의 모든 정점에서 DFS 수행
	- DFS 탐색이 끝나는 순서대로 정점을 스택에 삽입
3. 스택이 빌 때까지 반복
	- 스택에서 pop하는 순서대로 역방향 그래프에서 DFS 수행
		- DFS 한번에 탐색되는 정점들이 1개의 SCC를 구성한다.
```

### 코드
`BOJ - 2150 - Strongly Connected Component` 코드
```
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <memory.h>
#define SIZE 10002
using namespace std;
int N, M;
bool visited[SIZE];
vector<int> graph[SIZE];
vector<int> graphR[SIZE];
stack<int> stk;
vector<vector<int>> scc;
int scc_idx;

void DFS1(int v) {
	visited[v] = 1;
	int len = graph[v].size();
	for (int i = 0; i < len; i++) {
		int next = graph[v][i];
		if (!visited[next])
			DFS1(next);
	}
	stk.push(v);
}

void DFS2(int v) {
	visited[v] = 1;
	scc[scc_idx].push_back(v);
	int len = graphR[v].size();
	for (int i = 0; i < len; i++) {
		int next = graphR[v][i];
		if (!visited[next])
			DFS2(next);
	}
}

bool cmp(vector<int> a, vector<int> b) {
	return a[0] < b[0];
}

void Print() {
	int len = scc.size();
	cout << len << "\n";
	for (int i = 0; i < len; i++) {
		int len2 = scc[i].size();
		for (int w = 0; w < len2; w++)
			cout << scc[i][w] << " ";
		cout << "-1\n";
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graphR[b].push_back(a);
	}

	for (int v = 1; v <= N; v++)
		if (!visited[v])
			DFS1(v);
	
	memset(visited, 0, sizeof(visited));
	while (!stk.empty()) {
		int next = stk.top();
		stk.pop();
		if (visited[next])
			continue;
		
		scc.push_back(vector<int>());
		DFS2(next); 
		sort(scc[scc_idx].begin(), scc[scc_idx].end());
		scc_idx++;
	}
	sort(scc.begin(), scc.end(), cmp);
	Print();
	return 0;
}
```

## 타잔 알고리즘
SCC의 발견 조건에 주목해서 1번의 DFS를 사용해서 SCC를 구하는 방법. 

DFS의 현재 정점에서, 현재 정점과 다음 정점들이 현재 정점의 이전 정점으로 되돌아 갈 수 없다면 1개의 SCC를 구성한다.
```
1  →  2  →  4
↑  ↙      ↓ ↑
3           5
```
1번에서 DFS를 시작했을 때 현재 정점이 4번이라면, 다시 2번으로 돌아갈 수 없으므로 (4, 5)가 1개의 SCC를 구성한다.

```
1. 그래프 생성
2. DFS 수행 => 현재 정점 = v
	1. 방문 순서대로 고유 번호 부여 => Did(v)
	2. 방문 순서대로 스택에 추가
	3. 다음 정점 확인
		- 현재 정점과 다음 정점들에 대한 최소 고유 번호를 구한다.
	4. 최소 고유 번호가 Did(v)하고 동일하면 SCC를 생성한다.
		- 현재 정점을 만날 때까지 스택에서 pop한 정점들(현재 정점 포함)이 1개의 SCC를 구성한다.
```

### 코드
`BOJ - 2150 - Strongly Connected Component` 코드
```
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#define SIZE 10002
using namespace std;
int N, M;
int Did[SIZE];
bool scc_ok[SIZE];
vector<int> graph[SIZE];
stack<int> stk;
vector<vector<int>> scc;
int Did_idx = 0, scc_idx;

int DFS(int v) {
	Did[v] = ++Did_idx;
	stk.push(v);
	int minGoal = Did[v];

	int len = graph[v].size();
	for (int i = 0; i < len; i++) {
		int next = graph[v][i];
		if (Did[next] == 0) minGoal = min(minGoal, DFS(next));
		else if(!scc_ok[next]) minGoal = min(minGoal, Did[next]);
	}

	if (minGoal == Did[v]) {
		scc.push_back(vector<int>());
		int t;
		do {
			t = stk.top();
			scc[scc_idx].push_back(t);
			scc_ok[t] = 1;
			stk.pop();
		} while (t != v);
		
		sort(scc[scc_idx].begin(), scc[scc_idx].end());
		scc_idx++;
	}
	return minGoal;
}

bool cmp(vector<int> a, vector<int> b) {
	return a[0] < b[0];
}

void Print() {
	int len = scc.size();
	cout << len << "\n";
	for (int i = 0; i < len; i++) {
		int len2 = scc[i].size();
		for (int w = 0; w < len2; w++)
			cout << scc[i][w] << " ";
		cout << "-1\n";
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
	}

	for (int v = 1; v <= N; v++)
		if (Did[v] == 0)
			DFS(v);

	sort(scc.begin(), scc.end(), cmp);
	Print();
	return 0;
}
```

## 관련 문제
<br>https://www.acmicpc.net/problem/2150
<br>https://www.acmicpc.net/problem/4196
<br>https://www.acmicpc.net/problem/4013

## 참고
<br>https://jason9319.tistory.com/98
<br>https://yjg-lab.tistory.com/188
{% endraw %}