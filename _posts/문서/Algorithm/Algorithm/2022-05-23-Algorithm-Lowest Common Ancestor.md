---
categories:
- Algorithm
date: '2022-05-23'
title: '[Algorithm] Lowest Common Ancestor'
---

{% raw %}
## LCA
최소 공통 조상(LCA, Lowest Common Ancestor)은 트리에서 임의의 두 노드의 공통 조상에서 깊이가 가장 낮은 노드이다. 조상은 임의의 노드에서 루트 노드까지 경로 상에 있는 모든 노드이다.

```
             1
       2            3
   4      5     6       7
 8   9               10   11 

LCA(4, 10) = 1
LCA(6, 10) = 3
LCA(3, 11) = 3
```
노드 6과 노드 10의 공통 조상은 1, 3이며 이 중 LCA는 3이다.

## 구현 1 - O(Depth)
두 노드를 가리키는 `투 포인터`를 생성하고 부모 노드를 추적해서 같아질 때까지 탐색하는 나이브한 방법이 있다.

이 방법을 사용하기 위해선 다음 조건을 만족해야 한다.
- 각 노드의 깊이와 부모 노드의 정보가 필요
- 탐색 시작 전, 입력된 두 노드의 깊이가 같아야 함

`DFS`를 사용해서 모든 노드의 깊이와 부모 노드를 구할 수 있다.
```
parent[N]	// 부모 노드 (루트 노드일 경우 0 저장)
depth[N]	// 깊이 (값은 1부터 시작)

DFS(v, d) // v = 현재 노드, d = 현재 깊이
	depth[v] = d
	for (i = 0; i < graph[v].size(); i++) // 자식 노드 구하기
		next = graph[v][i]
		if (depth[next] == 0) // 방문 확인 (depth 사용)
			parent[next] = v
			DFS(next, d + 1)
```

LCA를 탐색해보자.
```
LCA(n1, n2) // 2개의 입력 노드
	// 깊이 통일
	while (depth[n1] > depth[n2]) n1 = parent[n1]<br>
	while (depth[n1] < depth[n2]) n2 = parent[n2]

	// 같아질 때까지 부모 노드따라 역추적
	while (n1 != n2)
		n1 = parent[n1]
		n2 = parent[n2]

	// LCA 반환
	return n1
```

### 코드
※ `BOJ - 11437 - LCA`하고 같은 코드
```
#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> graph[50001];<br>
int parent[50001];
int depth[50001];

void DFS(int v, int d)
{
	depth[v] = d;
	for (int i = 0; i < graph[v].size(); i++)
	{
		int next = graph[v][i];
		if (depth[next] == 0)
		{
			parent[next] = v;
			DFS(next, d + 1);
		}
	}
}

int LCA(int n1, int n2)
{
	while (depth[n1] > depth[n2]) n1 = parent[n1];<br>
	while (depth[n1] < depth[n2]) n2 = parent[n2];

	while (n1 != n2)
	{
		n1 = parent[n1];
		n2 = parent[n2];
	}
	return n1;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;<br>
	for (int i = 0; i < N - 1; i++)
	{
		int a, b;
		cin >> a >> b;<br>
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	DFS(1, 1);

	cin >> M;<br>
	for (int i = 0; i < M; i++)
	{
		int n1, n2;
		cin >> n1 >> n2;<br>
		cout << LCA(n1, n2) << "\n";
	}
	return 0;
}
```

## 구현 2 - O(log(Depth))
1번 방법은 선형으로 탐색하기 때문에 LCA하고 멀리 떨어져 있을수록 탐색 시간도 비례해서 증가한다. 만약 LCA를 M번 구한다면, O(M × Depth) 시간으로 계산이 오래 걸리는 문제가 있다. LCA를 구하는 시간을 단축해보자.

LCA 탐색에서 부모 노드를 찾아하는 과정이 반복된다. 이러한 특정 쿼리의 반복을 빠르게 수행하는 `Sparse Table`을 사용해서 O(log(Depth)) 시간으로 줄일 수 있다.

### 생성
먼저 `DP`를 사용해서 sparse table을 생성하자. sparse table은 2<sup>k</sup>번 부모 노드를 저장하고 있다.

부분 문제의 현재 상태를 (v, k), 계산 결과를 x번 노드의 2<sup>k</sup>번 부모 노드로 정의한다. 점화식과 생성 함수(Bottom-Up DP 사용)는 다음과 같다.
> Parent[v][k] = Parent[Parent[v][k - 1]][k - 1]<br>
```
// 노드 v의 parent 구하기
for (int k = 1; k <= log(max_depth); k++)
	parent[v][k] = parent[parent[v][k-1]][k-1]
```
위의 생성 함수를 DFS 탐색에 추가하면 된다. DFS는 상단 노드부터 탐색하기 때문에 모든 노드에 대해 자연스럽게 Bottom DP를 구성하게 된다.

### 탐색
탐색은 전반적으로 방법 1과 같지만, 이번에는 sparse table를 활용한다. LCA에 도달하기 위한 목표 반복 횟수를 2<sup>k</sup>의 합으로 분할하고, 순차적으로 sparse table을 탐색한다. 아직 목표 반복 횟수를 모르기 때문에 `이분 탐색`을 사용한다.

먼저 깊이를 맞춰야 한다. n2의 2<sup>k</sup>번째 부모의 깊이가 n1보다 크다면 해당 부모 노드로 이동한다. 이 과정을 k 최대부터 0까지 순차 탐색하면 두 노드의 깊이가 통일된다.
```
// depth[n1] < depth[n2]
for (int k = log(max_depth); k >= 0; k--)
	if (depth[n1] <= depth[parent[n2][k]])
		n2 = parent[n2][k]
```
마지막으로 LCA를 찾자. 마찬가지로 k 최대부터 0까지 순차 탐색하며, 두 노드의 2<sup>k</sup>번째 부모가 동일하면 이동하지 않고, 다르다면 해당 부모 노드로 이동한다.
```
if (n1 == n2) return n1

for (int k = max_depth; k >= 0; k--)
	if (parent[n1][k] != parent[n2][k])
		n1 = parent[n1][k]
		n2 = parent[n2][k]

return parent[n1][0]
```

### 코드
※ `BOJ - 11438 - LCA 2`하고 같은 코드
```
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N, M;
vector<int> graph[100001];<br>
int parent[100001][18];
int depth[100001];
int max_depth;

void DFS(int v, int d)
{
	depth[v] = d;
	for (int k = 1; k <= max_depth; k++)
		parent[v][k] = parent[parent[v][k-1]][k-1];

	for (int i = 0; i < graph[v].size(); i++)
	{
		int next = graph[v][i];
		if (depth[next] == 0)
		{
			parent[next][0] = v;
			DFS(next, d + 1);
		}
	}
}

int LCA(int n1, int n2)
{
	if (depth[n1] > depth[n2]) {<br>
		int temp = n1;
		n1 = n2;
		n2 = temp;
	}

	if(depth[n1] != depth[n2])
		for (int k = max_depth; k >= 0; k--)
			if (depth[n1] <= depth[parent[n2][k]])
				n2 = parent[n2][k];

	if (n1 == n2) return n1;
	for (int k = max_depth; k >= 0; k--)
	{
		if (parent[n1][k] != parent[n2][k])
		{
			n1 = parent[n1][k];
			n2 = parent[n2][k];
		}
	}
	return parent[n1][0];
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;<br>
	for (int i = 0; i < N - 1; i++)
	{
		int a, b;
		cin >> a >> b;<br>
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	max_depth = (int)floor(log2(100001));
	DFS(1, 1);

	cin >> M;<br>
	for (int i = 0; i < M; i++)
	{
		int n1, n2;
		cin >> n1 >> n2;<br>
		cout << LCA(n1, n2) << "\n";
	}
	return 0;
}
```

## 연관 문제
**O(N)**
https://www.acmicpc.net/problem/11437<br>

**O(logN)**
https://www.acmicpc.net/problem/11438<br>
https://www.acmicpc.net/problem/3176<br>

## 참고
https://4legs-study.tistory.com/121<br>
{% endraw %}