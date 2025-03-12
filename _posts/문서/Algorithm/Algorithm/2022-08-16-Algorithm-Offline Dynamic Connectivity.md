---
categories:
- Algorithm
date: '2022-08-16'
title: '[Algorithm] Offline Dynamic Connectivity'
---

{% raw %}
## Dynamic Connectivity
그래프 G가 있을 때, 아래와 같은 쿼리를 수행해보자.
- 1 A B: 정점 A와 B를 연결하는 간선을 추가한다.
- 2 A B: 정점 A와 B를 연결하는 간선을 제거한다. 
- 3 A B: 정점 A에서 B로 가는 경로가 있는지 없는지 조사한다.

이와 같이 그래프에서 실시간으로 간선이 추가/삭제될 때 관련 쿼리를 빠르게 다루는 문제를 Dynamic Connectivity Problem이라고 한다.

일반적인 Dynamic Connectivity는 상당히 어렵다고 알려져 있다. 그러나 쿼리를 순서대로 처리하지 않아도 된다면( = `오프라인 쿼리`), `분할정복`으로 해결할 수 있다. => `Offline Dynamic Connectivity`<br>

## Offline Dynamic Connectivity
간선에 'lifetime' 개념을 추가한다. 간선의 lifetime은 해당 간선이 유효한 시간이다. (여기서 시간의 단위는 쿼리 1개당 1로 정의한다.) 만약 간선 A가 3번 쿼리에서 생성되고 6번 쿼리에서 소멸되었다면 A의 lifetime은 [3, 6]이다. 만약 간선 A가 소멸되지 않았다면 lifetime은 [3, M]이다. (M = 쿼리의 개수)

모든 간선에 대해 lifetime을 계산했다면, 분할 정복을 적용할 수 있다. 정점 간의 연결 판정은 `분리 집합`을 사용한다.

**DC(lo, hi)**
1. 간선 edge의 lifetime이 [begin, end]일 때, (begin <= lo && hi <= end)을 만족하는 모든 간선을 Union한다.
	- if (begin <= lo && hi <= end)
		- Union(edge.src, edge.dest)
2. 현재 문제가 초항(lo == hi)이면, lo번 연결 쿼리(u, v)를 수행한다.
	- if (Find(u) == Find(v))
		- true라면 정점 u, v는 연결되어 있다.
4. 그렇지 않으면 문제를 분할한다. (mid = (lo + hi) / 2)
	- DC(lo, mid)
    - DC(mid + 1, hi)
4. 분리 집합을 1번 과정이 실행되기 전으로 롤백한다.

부분 문제마다 모든 간선을 탐색하는 것은 비효율적이므로 구간 범위에 맞는 간선 목록을 저장하는 것이 좋다. 분할이 구간으로 나눠진다는 점에서 `세그먼트 트리`가 적합하다. 트리의 각 노드는 해당 노드의 구간을 완전히 포함하는 lifetime을 가진 간선의 목록을 저장한다. (구간 업데이트 + 단일 반환을 수행하는 세그먼트 트리로 구현할 수 있다)

간선의 lifetime은 key-value 자료구조 `map`으로 구할 수 있다. map이 정점 개수만큼 존재할 때, 생성 쿼리가 들어오면 간선의 출발점은 배열의 인덱스, 도착점은 key, lifetime의 시작 시간은 value로 저장한다. 소멸 쿼리가 들어오면 map에서 해당 간선 데이터를 찾고 lifetime을 계산해서 세그먼트 트리에 추가하면 된다.

마지막으로 분리 집합의 롤백을 구현해보자. (여기서 분리 집합은 weight rule을 따른다)
```
ex.
> before<br>
     -4
-3
[3]  [5]

> after<br>
     -7
 5
[3]  [5]
=> 5번 노드의 값에 -3을 빼고, 3번 노드에 -3을 대입하면 롤백이 된다.<br>
```
이를 일반화하면 (weight가 작은 노드의 위치, 해당 노드의 이전 데이터)를 통해서 롤백을 수행할 수 있다.
```
struct RB { 
	int pos; // 롤백할 두 노드에서 weight가 작은 노드
	int data; // pos의 이전 데이터
};
void Rollback(RB rb) {
	if (rb.data == 0) return;
	pa[pa[rb.pos]] -= rb.data;
	pa[rb.pos] = rb.data;
}
```
Union이 발생한 간선의 RB를 `스택`에 순차적으로 저장한 다음, 작업을 마치고 롤백할 때 다시 스택에서 RB를 꺼내 롤백을 수행하면 된다.

※ 이 방법을 적용하려면 Collapsing Find를 사용하지 않아야 한다. (Collapsing Find를 적용하면 노드간 연결 변경이 추가로 발생하므로 역추적이 어려워진다)

## 코드
`BOJ - 16911 - 그래프와 쿼리` 코드
```
#include <iostream>
#include <vector>
#include <stack>
#include <map>
using namespace std;
const int SIZE = 100002;
struct Edge { int src, dest; };
struct RB { int pos, data; };
int N, M;
map<int, int> con[SIZE];<br>
Edge query[SIZE];

struct Disjoint {
	int pa[SIZE];
	void Init() {
		for (int i = 0; i <= N; i++)
			pa[i] = -1;
	}

	int Find(int n) {
		int p = n;
		while (pa[p] >= 0) p = pa[p];
		return p;
	}

	RB Union(int a, int b) {
		int p1 = Find(a);
		int p2 = Find(b);
		if (p1 == p2) return { 0, 0 };

		RB rb;
		if (pa[p1] < pa[p2]) {
			rb = { p2, pa[p2] };
			pa[p1] += pa[p2];
			pa[p2] = p1;
		}
		else {
			rb = { p1, pa[p1] };
			pa[p2] += pa[p1];
			pa[p1] = p2;
		}
		return rb;
	}

	void Rollback(RB rb) {
		if (rb.data == 0) return;
		pa[pa[rb.pos]] -= rb.data;
		pa[rb.pos] = rb.data;
	}
} dj;

struct SegTree {
	vector<Edge> tree[SIZE * 4];<br>

	void Add(int start, int end, int idx, int left, int right, Edge edge) {
		if (start > right || end < left) return;<br>
		if (start >= left && end <= right) {
			tree[idx].push_back(edge);
			return;
		}
		int mid = (start + end) / 2;
		Add(start, mid, idx * 2, left, right, edge);
		Add(mid + 1, end, idx * 2 + 1, left, right, edge);
	}

	void DC(int start, int end, int idx, int left, int right) {
		stack<RB> stk;<br>
		for (auto& i : tree[idx])
			stk.push(dj.Union(i.src, i.dest));

		if (start == end) {
			Edge e = query[start];
			if (e.src != 0) {
				if (dj.Find(e.src) == dj.Find(e.dest))
					cout << "1\n";
				else
					cout << "0\n";
			}
		}
		else {
			int mid = (start + end) / 2;
			DC(start, mid, idx * 2, left, right);
			DC(mid + 1, end, idx * 2 + 1, left, right);
		}

		while (!stk.empty()) {
			dj.Rollback(stk.top());
			stk.pop();
		}
	}
} seg;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;<br>
	dj.Init();
	for (int t = 0; t < M; t++) {
		int a, b, c;
		cin >> a >> b >> c;<br>
		if (b > c) swap(b, c);<br>

		if (a == 1)
			con[b].emplace(c, t);
		if (a == 2) {
			auto i = con[b].find(c);
			seg.Add(0, M - 1, 1, i->second, t, { b, c });
			con[b].erase(i);
		}
		if (a == 3)	query[t] = { b, c };
		else query[t] = { 0, 0 };
	}
	for (int v = 1; v <= N; v++)
		for (auto i : con[v])
			seg.Add(0, M - 1, 1, i.second, M - 1, { v, i.first });

	seg.DC(0, M - 1, 1, 0, M - 1);
	return 0;
}
```

## 관련 문제
https://www.acmicpc.net/problem/16911<br>

## 참고
https://koosaga.com/121<br>
{% endraw %}