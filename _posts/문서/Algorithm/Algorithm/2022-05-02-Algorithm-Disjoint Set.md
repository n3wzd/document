---
categories:
- Algorithm
date: '2022-05-02'
title: '[Algorithm] Disjoint Set'
---

{% raw %}
## Disjoint Set
`Disjoint Set`, `Union-Find`은 서로소(서로 중복되지 않는) 집합을 저장하는 자료 구조이다. Find, Union 2가지 연산을 제공한다.

집합의 각 노드는 `트리` 구조로 저장되며, 각각의 트리는 집합에 대응된다. 즉, 2개의 노드가 같은 트리에 있다면 같은 집합에 있다고 판단할 수 있다. 또한, 트리마다 루트 노드는 항상 1개만 존재하므로, 루트 노드를 통해 트리(집합)를 식별할 수 있다. (=트리의 루트가 해당 집합을 대표한다.)

트리는 각 노드의 parent 위치를 저장하는 1차원 배열로 구현할 수 있다. 루트 노드일 경우, 음수 값을 저장한다.

### Find
입력 노드 A가 포함된 집합을 반환하는 연산.

parent 배열을 통해 A부터 루트까지 이동하며, 루트에 도달하면 해당 루트를 반환한다. 

```
int Find(int a)
{
	int p = a;
	while (parent[p] >= 0)		// A에서 루트 노드까지 이동
		p = parent[p];
	return p;
}
```

#### Collapsing Find (Path Compaction)
입력 노드 A에서 루트 노드까지 거리가 멀수록 Find 연산의 시간이 증가한다. 만약 Find 연산을 종료할 때 A의 parent를 루트 노드로 변경한다면, Find의 연산 시간이 개선되는 효과를 볼 수 있다.

```
int Find(int a)		// A가 속한 트리의 루트 노드 반환
{
	int p = a;
	while (parent[p] >= 0)
		p = parent[p];
	if(parent[a] >= 0) parent[n] = p;	// A의 parent를 루트로 변경 (단, A != 루트)
	return p;
}
```

### Union
입력 노드 A가 포함된 집합과 입력 노드 B가 포함된 집합을 합치는 연산

트리 루트의 parent를 다른 트리의 루트로 한다면 트리를 합칠 수 있다. 즉, 2개의 루트를 연결해서 한 트리를 다른 트리의 서브 트리로 만든다.

어떤 루트를 서브 트리로 선택할지에 따라 트리의 구조가 달라지고, Find 연산 효율도 달라질 수 있다. Find 연산을 빠르게 하기 위해 서브 트리에 적합한 트리를 선택해야 한다.

#### Height Rule
> 트리의 높이(height)가 작은 트리를 서브 트리로 한다. 높이가 같다면 아무거나 선택한다.<br>

두 트리의 높이가 다르면 합해도 높이는 보존된다. 높이가 같을 때만 합쳤을 때 높이가 1 증가한다.

#### Weight Rule
> 노드의 개수(weight) 적은 트리를 서브 트리로 한다. 개수가 같다면 아무거나 선택한다.<br>

합성한 새로운 트리의 노드 개수는 이전 2개 트리의 노드 개수 합하고 같다.

트리 노드의 개수는 루트 노드의 parent에 음수로 저장한다. 음수 값이므로 기존처럼 루트 판별도 가능하다. 초기 값은 -1이다. (처음 루트 노드 1개)
```
parent[root] = -(weight)	// 노드 개수 = weight
```

weight rule 구현 예시
```
void Union(int a, int b)
{
	int p1 = Find(a);
	int p2 = Find(b);
	if (p1 == p2) return;			// 같은 집합이면 pass

	if (parent[p1] < parent[p2])	// weight rule에 따라 union 수행 (음수이므로 값이 작을수록 weight가 크다)
	{
		parent[p1] += parent[p2];
		parent[p2] = p1;
	}
	else
	{
		parent[p2] += parent[p1];
		parent[p1] = p2;
	}
}
```

## 코드
```
#include <iostream>
using namespace std;

int parent[1000002];

int Find(int n)
{
	int p = n;
	while (parent[p] >= 0) p = parent[p];
	if(parent[n] >= 0) parent[n] = p;
	return p;
}

void Union(int a, int b)
{
	int p1 = Find(a);
	int p2 = Find(b);
	if (p1 == p2) return;

	if (parent[p1] < parent[p2])
	{
		parent[p1] += parent[p2];
		parent[p2] = p1;
	}
	else
	{
		parent[p2] += parent[p1];
		parent[p1] = p2;
	}
}

int main()
{
	for (int i = 0; i <= N; i++)
		parent[i] = -1;

	Find(1);
	Find(2);
	Union(1, 2);
	return 0;
}
```

## 연관 문제
https://www.acmicpc.net/problem/1717
https://www.acmicpc.net/problem/20040
{% endraw %}