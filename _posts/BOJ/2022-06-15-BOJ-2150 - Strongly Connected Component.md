---
categories:
- BOJ
date: '2022-06-15'
title: '[BOJ] 2150 - Strongly Connected Component'
---

{% raw %}
> 플래티넘 V<br>

## 문제
방향 그래프가 주어졌을 때, 그 그래프를 SCC들로 나누는 프로그램을 작성하시오.

방향 그래프의 SCC는 우선 정점의 최대 부분집합이며, 그 부분집합에 들어있는 서로 다른 임의의 두 정점 u, v에 대해서 u에서 v로 가는 경로와 v에서 u로 가는 경로가 모두 존재하는 경우를 말한다.

#### 입력
첫째 줄에 두 정수 V(1 ≤ V ≤ 10,000), E(1 ≤ E ≤ 100,000)가 주어진다. 이는 그래프가 V개의 정점과 E개의 간선으로 이루어져 있다는 의미이다. 다음 E개의 줄에는 간선에 대한 정보를 나타내는 두 정수 A, B가 주어진다. 이는 A번 정점과 B번 정점이 연결되어 있다는 의미이다. 이때 방향은 A → B가 된다.

정점은 1부터 V까지 번호가 매겨져 있다.

#### 출력
첫째 줄에 SCC의 개수 K를 출력한다. 다음 K개의 줄에는 각 줄에 하나의 SCC에 속한 정점의 번호를 출력한다. 각 줄의 끝에는 -1을 출력하여 그 줄의 끝을 나타낸다. 각각의 SCC를 출력할 때 그 안에 속한 정점들은 오름차순으로 출력한다. 또한 여러 개의 SCC에 대해서는 그 안에 속해있는 가장 작은 정점의 정점 번호 순으로 출력한다.

## 해결
`강한 연결 요소(SCC)`를 구하는 기본 문제. `코사라주 알고리즘`, `타잔 알고리즘` 모두 사용 가능하다.

## 코드
**코사라주 알고리즘**
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

**타잔 알고리즘**
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

## 링크
<br>https://www.acmicpc.net/problem/2150
{% endraw %}