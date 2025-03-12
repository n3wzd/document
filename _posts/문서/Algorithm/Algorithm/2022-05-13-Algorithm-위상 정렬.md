---
categories:
- Algorithm
date: '2022-05-13'
title: '[Algorithm] 위상 정렬'
---

{% raw %}
## 위상 정렬
`위상 정렬(Topology Sort)`은 원소의 순서를 기준으로 정렬을 수행하는 알고리즘이다.

예를 들어 [A, B, C, D] 배열이 있을 때, (A→B), (C→D) 순서가 제공되면 다음과 같이 정렬할 수 있다.
```
A B C D
A C B D
C D A B
...
``` 
가능한 정렬은 여러 가지지만, A는 항상 B의 앞에 있고 C는 D의 앞에 있어야 하는 순서는 지켜져야 한다. 위상 정렬은 이러한 순서 정보를 보장하며 정렬을 수행한다.

사이클이 있는 순서가 있다면 위상 정렬을 사용할 수 없다. A는 B의 앞에, B는 A의 앞에 있어야 한다는 것은 서로 모순된 정보이기 때문.

## 설계
`그래프`하고 `큐`를 사용해서 구현할 수 있다. 그래프는 간선의 방향이 존재하며, 사이클이 없어야 한다.

< 그래프 구성 >
- 정점 = 정렬할 원소
- 간선 = 원소 간의 순서 정보 (방향 존재)

< 필요한 데이터 >
- 그래프 (인접 리스트 or 인접 행렬)
- 각 정점의 진입 차수 (= 해당 원소로 도착하는 간선 개수)
- 정점을 저장하는 큐

< 정렬 방법 >
```
1. 진입 차수가 0인 정점들을 큐에 추가한다.
2. 큐에서 정점 1개를 꺼낸다.
3. 현재 정점에서 인접한 정점들의 진입 차수를 1씩 줄인다.
4. 이때 진입 차수가 0이 된 정점이 있으면 큐에 추가한다.
5. 1-4 과정을 N번 반복한다. (N = 정점 개수)
```

이 방법을 구현해보자.
```
TopologySort()
	queue<int> q
	for (i = 1; i <= N; i++) // 진입 차수가 0인 정점을 큐에 추가
		if(degree[i] == 0)
			q.push(i)

	for (i = 0; i < N; i++)
		if(q.empty()) // 사이클이 있으면 N번 탐색하기 전에 큐가 비게 된다.
			return
		
		v = q.front()
		q.pop()
		print(v) // 현재 정점을 출력하거나 정렬 목록에 저장

		for (k = 0; k < graph[v].size(); k++)
			w = graph[v][k]
			if (--degree[w] == 0) // 인접 정점의 진입 차수 연산
				q.push(w)
```

## 코드
※ `BOJ - 2252 - 줄 세우기` 코드하고 동일
```
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int _SIZE = 32001;
int N, M;
int degree[_SIZE];
vector<int> graph[_SIZE];

void TopologySort()
{
	queue<int> q;
	for (int i = 1; i <= N; i++)
		if(degree[i] == 0)
			q.push(i);

	for (int i = 0; i < N; i++)
	{
		int v = q.front();
		q.pop();
		cout << v << " ";

		int len = graph[v].size();
		for (int k = 0; k < len; k++)
		{
			int w = graph[v][k];
			if (--degree[w] == 0)
				q.push(w);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		degree[b]++;
	}
	TopologySort();
	return 0;
}
```

## 연관 문제
<br>https://www.acmicpc.net/problem/2252
<br>https://www.acmicpc.net/problem/3665

## 참고
<br>https://m.blog.naver.com/ndb796/221236874984
{% endraw %}