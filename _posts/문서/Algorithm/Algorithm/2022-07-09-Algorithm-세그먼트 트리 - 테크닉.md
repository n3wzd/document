---
categories:
- Algorithm
date: '2022-07-09'
title: '[Algorithm] 세그먼트 트리 - 테크닉'
---

{% raw %}
## 테크닉?
`세그먼트 트리`와 관련된 유용한 아이디어 + 테크닉을 서술.

## 카운팅 정렬
다음 문제를 해결해보자.

> 자연수를 저장하는 데이터베이스 S에 대해 다음의 쿼리를 처리합시다.<br>
> 쿼리 1 : S에 자연수 X를 추가한다.<br>
> 쿼리 2 : S에 포함된 숫자 중 K번째로 작은 수를 응답하고 그 수를 삭제한다.<br>

K번째 위치를 알려면 전체가 정렬되어 있어야 한다. 그러나 일일이 정렬을 수행하는 방법은 오래 걸려 사용이 어렵고, `우선순위 큐`는 가장 큰 수, 작은 수만 알 수 있어 문제의 쿼리에 적합하지 않다.

이러한 상황에서는 `카운팅 정렬`이 적합하다. 카운팅 정렬을 사용하는 배열은 원소의 값을 인덱스로 활용하며, 원소의 출현 횟수를 기록한다. 따라서 항상 자동으로 정렬되어 있으므로, 매 쿼리마다 정렬을 따로 수행하지 않아도 된다. 또한, 원소 추가/삭제, 중복 원소 대처도 어렵지 않다. (원소 출현 횟수만 바꿔주면 된다)

문제는 K번째 위치를 찾아가려면 선형 탐색으로는 시간이 오래 걸린다. 이때 빠른 구간 쿼리 수행을 하는 `세그먼트 트리`를 동원하면 시간 문제를 해결할 수 있다.

### 구현
세그먼트 트리는 구간에 포함된 원소의 출현 횟수 합을 저장한다.

**초기화**
처음 원소들의 등장 횟수를 초기화한다.

**업데이트**
구간 합을 사용하는 세그먼트 트리와 동일하게 동작한다. 원소를 추가한다면 해당 원소 위치에서 추가 횟수만큼 더하고, 삭제는 해당 원소 위치에서 삭제할 원소 개수만큼 빼면 된다.

**탐색**
정렬된 상태에서 K번째인 원소를 찾는 함수. `이분 탐색`을 사용해서 구현한다. 루트부터 시작해서, K가 왼쪽 노드보다 같거나 작으면 왼쪽 노드로 이동하고, 그렇지 않으면 오른쪽 노드로 이동한다. 만약 오른쪽 노드로 이동한다면, K에서 왼쪽 노드의 값을 빼준다. 단말 노드에 도착하면 해당 노드의 위치를 출력한다.
```
int Find(int start, int end, int idx, int k) {
	// 1. 구간 길이가 1이면 목표 위치를 찾은 상태 => 현재 구간 위치 반환<br>
	if (start == end)
		return start;
	
	// 2. 이분 탐색
	int mid = (start + end) / 2;
	return (k <= tree[idx * 2]) ? Find(start, mid, idx * 2, k) : Find(mid + 1, end, idx * 2 + 1, k - tree[idx * 2]);
}
```

```
ex. 3 5 1 6 8
          5
    2           3
 1     1     2     1
1 0   1 0   1 1   0 1
> 2번째로 작은 원소?<br>
=> L-R-L으로 이동해서 3을 출력한다.<br>
> 4번째로 작은 원소?<br>
=> R-L-R으로 이동해서 6을 출력한다.<br>
```

### 코드
`BOJ - 12899 - 데이터 구조` 코드
```
#include <iostream>
using namespace std;
int N;
int tree[8000008];
const int MAXV = 2000000;

int Find(int start, int end, int idx, int k) {
	if (start == end) return start;
	int mid = (start + end) / 2;
	return (k <= tree[idx * 2]) ? Find(start, mid, idx * 2, k) : Find(mid + 1, end, idx * 2 + 1, k - tree[idx * 2]);
}

int Update(int start, int end, int idx, int pos, int diff) {
	if (start > pos || end < pos) return tree[idx];<br>
	if (start == end) return tree[idx] += diff;
	int mid = (start + end) / 2;
	return tree[idx] = Update(start, mid, idx * 2, pos, diff) + Update(mid + 1, end, idx * 2 + 1, pos, diff);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;<br>
	while (N--) {
		int a, b;
		cin >> a >> b;<br>
		if (a == 1) {
			Update(1, MAXV, 1, b, 1);
		}
		else {
			int res = Find(1, MAXV, 1, b);
			cout << res << "\n";
			Update(1, MAXV, 1, res, -1);
		}
	}
	return 0;
}
```

### 관련 문제
https://www.acmicpc.net/problem/12899
https://www.acmicpc.net/problem/2243
https://www.acmicpc.net/problem/1168

## Lazy없는 구간 업데이트? (구간 업데이트 + 단일 반환)
다음 쿼리를 구현해보자.
> 쿼리 1 `i j k`: Ai, Ai+1, ..., Aj에 k를 더한다.<br>
> 쿼리 2 `x`: Ax 를 출력한다.<br>

원래는 구간 합을 빠르게 갱신할 수 있는 `Lazy Propagation`을 사용하면 된다. 하지만 반환이 없거나 단일 값 반환만 필요하다면 Lazy Propagation을 적용하지 않아도 구현이 가능하다.

### 구현
완전히 포함되는 구간의 변경 값을 저장하는 세그먼트 트리를 사용한다.

**초기화**
단말 노드만 초기화를 하고(구간의 길이가 1인 변경 값을 적용하는 것으로 볼 수 있다), 그 외 노드는 0을 저장한다.

**업데이트**
구간의 변경 값을 적용한다. 처음과 끝이 입력 구간에 완전히 포함되는 구간 노드만 변경 값을 적용하고, 그렇지 않은 노드는 그대로 둔다.

**반환**
특정 값 1개를 반환한다. 값을 가져오면서, 거쳐 가는 노드들의 값들을 합하면 된다.
```
ex. 1 2 3 4
> 초기화<br>
       0
  0         0
1   2     3   4

> 업데이트 [1, 3] 구간 +3<br>
       0
  3         0
1   2     6   4

> 반환 2<br>
       0
  3         0
1   2     6   4
=> 5<br>
```

### 코드
`BOJ - 16975 - 수열과 쿼리 21` 코드
```
#include <iostream>
using namespace std;
typedef long long ll;
int N, M;
ll num[100001];
ll tree[400004];

void Init(int start, int end, int idx) {
	if (start == end) {
		tree[idx] = num[start];
		return;
	}
	int mid = (start + end) / 2;
	Init(start, mid, idx * 2);
	Init(mid + 1, end, idx * 2 + 1);
}

ll Get(int start, int end, int idx, int pos) {
	if (start > pos || end < pos) return 0;<br>
	if (start == end) return tree[idx];
	int mid = (start + end) / 2;
	return Get(start, mid, idx * 2, pos) + Get(mid + 1, end, idx * 2 + 1, pos) + tree[idx];
}

void Update(int start, int end, int idx, int left, int right, int diff) {
	if (start > right || end < left) return;<br>
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
	cin >> N;<br>
	for (int i = 0; i < N; i++)
		cin >> num[i];<br>
	Init(0, N - 1, 1);

	cin >> M;<br>
	while (M--) {
		int a, b, c, d;
		cin >> a >> b;<br>
		if (a == 1) {
			cin >> c >> d;<br>
			Update(0, N - 1, 1, b - 1, c - 1, d);
		}
		else
			cout << Get(0, N - 1, 1, b - 1) << "\n";
	}
	return 0;
}
```

### 관련 문제
https://www.acmicpc.net/problem/16975
https://www.acmicpc.net/problem/14268
https://www.acmicpc.net/problem/3392
https://www.acmicpc.net/problem/17353
{% endraw %}