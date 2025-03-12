---
categories:
- Algorithm
date: '2022-06-13'
title: '[Algorithm] Euler Tour Technique'
---

{% raw %}
## Euler Tour Technique
`Euler Tour Technique`는 `트리`에서 서브트리를 어떠한 구간으로 변환하는 테크닉이다. 서브트리를 구간으로 변환한다면, 구간 쿼리를 빠르게 수행하는 자료 구조나 알고리즘을 적용할 수 있다.

## 방법
`DFS`으로 트리를 탐색해, 방문한 순서대로 정점에 새로운 번호를 부여한다. 그리고 새 번호를 인덱스로 하는 배열에 각 정점을 저장하면 된다.

서브 트리에 대응하는 구간 정보는 DFS에서 결정할 수 있다. 구간의 시작 지점은 현재 정점이 처음 방문 되었을 때, 끝 지점은 현재 정점의 모든 자식 정점을 방문 완료했을 때의 번호를 저장함으로써 알 수 있다.
```
1. 루트를 시작으로, DFS를 사용해 트리를 탐색한다.
	- 새 번호, 서브 트리 구간 정보를 얻는다.
2. 배열에 정점을 저장한다.
	- euler[N]
		- 인덱스: 새 번호
		- 값: 정점 번호
3. 서브 트리 구간을 저장한다.
	- subtree[N]
		- 인덱스: 시작 정점 번호
		- 값: [시작 정점의 새 번호, 끝 정점의 새 번호]
```

```
ex. 트리
             1
       2        3    4
    5     6
  7

> DFS 탐색<br>
             1(1)
       2(2)      3(6)   4(7)
    5(3)   6(5)
  7(4)

> 배열 변환<br>
1  2  3  4  5  6  7
1  2  5  7  6  3  4
[        1         ]
   [    2    ]
	          [3]
                 [4]
     [ 5  ]
           [6]
        [7]

> 구간 저장<br>
1: [1, 7]
2: [2, 5]
3: [6, 6]
4: [7, 7]
5: [3, 4]
6: [5, 5]
7: [4, 4]
```

### with 세그먼트 트리
위에서 정의한 새 번호를 구간으로 하는 `세그먼트 트리`를 사용하면, 서브트리를 대상으로 하는 쿼리를 빠르게 수행할 수 있다.

```
ex. 서브트리에서 k를 더하는 쿼리?
구간 합을 더하는 세그먼트 트리 사용

> 트리 초기화<br>
=> Init(1, N, 1)
> 정점 v의 서브트리 업데이트<br>
=> Update(1, N, 1, subtree[v].start, subtree[v].end, k)
> 정점 v의 값 출력<br>
=> Get(1, N, 1, subtree[b].start)
```

초기화 작업같이 트리에서 원래 정점 번호를 사용하고 싶다면, 위의 euler 배열을 통해 변환하면 된다.

구간 업데이트가 필요하면, 완전히 포함되는 구간의 변경 값을 저장하는 `세그먼트 트리` or `Lazy Propagation`를 사용하면 된다.

## 코드
`BOJ - 2820 - 자동차 공장` 코드
```
#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

class Range {
public:
	int start, end;
	Range() {}
	Range(int a, int b) { start = a, end = b; }
};

int N, M;
vector<int> graph[500001];
Range subtree[500001];
int euler[500001];
ll salary[500001];
ll tree[2000004];
bool visited[500001];
int dfs_num = 0;

void DFS(int v) {
	visited[v] = 1;
	subtree[v].start = ++dfs_num;
	euler[dfs_num] = v;
	int len = graph[v].size();
	for (int i = 0; i < len; i++) {
		int next = graph[v][i];
		if (!visited[next])
			DFS(next);
	}
	subtree[v].end = dfs_num;
}

void Init(int start, int end, int idx) {
	if (start == end) {
		tree[idx] = salary[euler[start]];
		return;
	}
	int mid = (start + end) / 2;
	Init(start, mid, idx * 2);
	Init(mid + 1, end, idx * 2 + 1);
}

ll Get(int start, int end, int idx, int pos) {
	if (start > pos || end < pos) return 0;
	if (start == end) return tree[idx];
	int mid = (start + end) / 2;
	return Get(start, mid, idx * 2, pos) + Get(mid + 1, end, idx * 2 + 1, pos) + tree[idx];
}

void Update(int start, int end, int idx, int left, int right, ll diff) {
	if (start > right || end < left) return;
	if (start >= left && end <= right) {
		tree[idx] += diff;
		return;
	}
	int mid = (start + end) / 2;
	Update(start, mid, idx * 2, left, right, diff);
	Update(mid + 1, end, idx * 2 + 1, left, right, diff);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	cin >> salary[1];
	for (int i = 2; i <= N; i++) {
		int a, b = i;
		cin >> salary[i] >> a;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	DFS(1);
	Init(1, N, 1);

	while (M--) {
		char a;
		int b, c;
		cin >> a;
		if (a == 'p') {
			cin >> b >> c;
			Update(1, N, 1, subtree[b].start + 1, subtree[b].end, c);
		}
		else {
			cin >> b;
			cout << Get(1, N, 1, subtree[b].start) << "\n";
		}
	}
	return 0;
}
```

## 관련 문제
<br>https://www.acmicpc.net/problem/14268
<br>https://www.acmicpc.net/problem/14287
<br>https://www.acmicpc.net/problem/2820

## 참고
<br>https://anz1217.tistory.com/41
{% endraw %}