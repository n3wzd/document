---
categories:
- Algorithm
date: '2022-07-13'
title: '[Algorithm] Lazy Propagation'
---

{% raw %}
## 구간 업데이트?
>  `1 i j k`: Ai, Ai+1, ..., Aj에 k를 더한다.<br>

일반적인 `세그먼트 트리`는 값 1개를 업데이트할 수 있다. 구간 업데이트라면 업데이트를 구간 길이만큼 일일이 하면 될 수 있다. 그러나 문제는 시간이 최대 O(N log N)이므로 선형 탐색보다 오래 걸리게 된다!

## Lazy Propagation
`세그먼트 트리`에서 구간 업데이트를 빠르게 하기 위해 사용되는 테크닉. 업데이트 쿼리 실행 시, 일부 노드는 바로 갱신하지 않고 변경 정보만 미리 저장하다가, 해당 노드를 방문했을 때 변경 정보를 반영한다. 업데이트 반영을 바로 하든 나중에 하든, 출력하기 전에만 반영하면 상관없다는 귀차니즘(?) 아이디어를 활용한 것이다.

`Lazy Propagation`를 적용하면 업데이트할 때 필요한 노드까지만 탐색하기 때문에, 구간 업데이트 연산은 O(log N) 시간이 걸린다. 그리고 모든 자식 노드를 참조하지 않으므로 Top-Down 방식 업데이트를 사용해야 한다. 또한 1개의 노드는 1개의 변경 정보에 대해 업데이트를 수행할 예정이므로, 업데이트 연산은 분배 법칙이 성립해야 한다.

> Lazy Propagation을 사용하려면, Top-Down 업데이트 방법을 사용해야 하고, 업데이트 연산에는 분배 법칙이 성립해야 한다.<br>

## 구현
세그먼트 트리에서 단일 업데이트 연산이 구간 업데이트 연산으로 변경되었다.

### 만들기
세그먼트 트리의 각 노드의 변화 정보를 담는 배열을 추가한다.
```
lazy[N * 4] // 크기는 세그먼트 트리 노드 개수하고 동일
```
처음 초기화 값은 '변화량 없음'을 담는다. 일반적으로 0을 사용한다.

### Lazy 업데이트
현재 노드에서 `lazy`를 반영하는 연산. 노드를 방문하는 시점에서 이 함수가 호출되어야 한다.
```
[start, end] = 현재 구간
idx = 현재 노드 인덱스

void LazyUpdate(int start, int end, int idx) {
	// 1. 현재 lazy를 반영할 수 있는지 확인한다.
	if(lazy[idx] != 0) {
		// 2. 현재 lazy를 현재 노드에 반영한다.
		tree[idx] += (end - start + 1) * lazy[idx];

		// 3. 현재 lazy를 자식 노드에 전파한다.
		if (start != end) {
			lazy[idx * 2] += lazy[idx];
			lazy[idx * 2 + 1] += lazy[idx];
		}

		// 4. 업데이트 반영이 완료된 현재 lazy에 0을 대입
		lazy[idx] = 0;
	}
}
```

### 구간 업데이트
구간 업데이트를 수행하는 연산.
```
[start, end] = 현재 구간
idx = 현재 노드 인덱스
[left, right] = 변경할 구간
diff = 구간의 각 원소에 대한 값 변화량

void RangeUpdate(int start, int end, int idx, int left, int right, int diff) {
	// 1. 현재 노드를 방문했으면 lazy를 우선 확인한다.
	LazyUpdate(start, end, idx);

	// 2. 현재 구간이 입력 구간을 완전히 벗어난 경우? => 탐색 종료
	if (start > right || end < left) return;

	// 3. 현재 구간이 입력 구간에 완전히 포함된 경우? => 변화량 반영
	if (start >= left && end <= right) {
		// 3-1. 현재 변화량을 노드에 반영한다.
		tree[idx] += (end - start + 1) * diff;

		// 3-2. 자식 노드에게 lazy를 새로 전파하고 탐색 종료.
		if (start != end) {
			lazy[idx * 2] += diff;
			lazy[idx * 2 + 1] += diff;
		}
		return;
	}

	// 4. 위 조건에 해당되지 않으며, 현재 구간이 입력 구간에 일부 겹치는 경우?
	// => 탐색 범위를 분할한다.
	int mid = (start + end) / 2;
	RangeUpdate(start, mid, idx * 2, left, right, diff);
	RangeUpdate(mid + 1, end, idx * 2 + 1, left, right, diff);

	// 4-1. 갱신된 자식 업데이트 내용을 현재 노드에 반영한다.
	tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
}
```

### 반환 연산
구간 입력[A, B]가 주어졌을 때, [A, B]의 구간 쿼리 연산 결과를 반환한다. 일반적인 세그먼트 트리와 동일하지만, 방문할 때 lazy를 반영한다는 차이가 있다.
```
int Get(int start, int end, int idx, int left, int right) {
	// 1. 현재 노드를 방문했으면 lazy를 우선 확인한다.
	LazyUpdate(start, end, idx);

	// 2. 이하는 일반 세그먼트 반환 연산과 동일
	if (start > right || end < left) return 0;
	if (start >= left && end <= right) return tree[idx];
	int mid = (start + end) / 2;
	return Get(start, mid, idx * 2, left, right) + Get(mid + 1, end, idx * 2 + 1, left, right);
}
```

## 코드
`BOJ - 10999 - 구간 합 구하기 2` 코드
```
#include <iostream>
using namespace std;

int N, M, K;
int num[1000001];
int tree[4000004];
int lazy[4000004];

int Init(int start, int end, int idx) {
	if (start == end) return tree[idx] = num[start];
	int mid = (start + end) / 2;
	return tree[idx] = Init(start, mid, idx * 2) + Init(mid + 1, end, idx * 2 + 1);
}

void LazyUpdate(int start, int end, int idx) {
	if (lazy[idx] != 0) {
		tree[idx] += (end - start + 1) * lazy[idx];
		if (start != end) {
			lazy[idx * 2] += lazy[idx];
			lazy[idx * 2 + 1] += lazy[idx];
		}
		lazy[idx] = 0;
	}
}

int Get(int start, int end, int idx, int left, int right) {
	LazyUpdate(start, end, idx);
	if (start > right || end < left) return 0;
	if (start >= left && end <= right) return tree[idx];
	int mid = (start + end) / 2;
	return Get(start, mid, idx * 2, left, right) + Get(mid + 1, end, idx * 2 + 1, left, right);
}

void RangeUpdate(int start, int end, int idx, int left, int right, int diff) {
	LazyUpdate(start, end, idx);

	if (start > right || end < left) return;
	if (start >= left && end <= right) {
		tree[idx] += (end - start + 1) * diff;
		if (start != end) {
			lazy[idx * 2] += diff;
			lazy[idx * 2 + 1] += diff;
		}
		return;
	}

	int mid = (start + end) / 2;
	RangeUpdate(start, mid, idx * 2, left, right, diff);
	RangeUpdate(mid + 1, end, idx * 2 + 1, left, right, diff);
	tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++)
		cin >> num[i];
	Init(1, N, 1);

	int Q = M + K;
	while (Q--) {
		int a, b, c, d;
		cin >> a >> b >> c;
		if (a == 1) {
			cin >> d;
			RangeUpdate(1, N, 1, b, c, d);
		}
		else cout << Get(1, N, 1, b, c) << "\n";
	}
	return 0;
}
```

## 관련 문제
<br>https://www.acmicpc.net/problem/10999
<br>https://www.acmicpc.net/problem/12844
<br>https://www.acmicpc.net/problem/13925
<br>https://www.acmicpc.net/problem/10070

## 참고
<br>https://book.acmicpc.net/ds/segment-tree-lazy-propagation
<br>https://overnap.com/bottom-up-segment-tree-and-commutative-property/
{% endraw %}