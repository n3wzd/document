---
categories:
- Algorithm
date: '2022-07-10'
title: '[Algorithm] 세그먼트 트리'
---

{% raw %}
## 구간 쿼리?
> 어떤 N개의 수가 주어져 있다. 그런데 중간에 수의 변경이 빈번히 일어나고 그 중간에 어떤 부분의 합을 구하려 한다.<br>

방법 1. 선형 탐색. 일일이 더한다. 단, 이 방법은 O(N) 시간이므로 시간 초과를 받는다.
방법 2. `Prefix Sum`을 사용한다. 구간 합을 O(1) 시간 내에 알 수 있지만, 값의 변경에 대처하기 어렵다.

> 값의 변경이 빈번히 일어나는 상황에서 구간 쿼리를 빠르게 수행하는 방법이 있을까?<br>

## 세그먼트 트리
`세그먼트 트리`는 구간 쿼리 연산 결과를 저장하는 `이진 트리`다. 현재 구간을 절반으로 나눠 자식 노드를 전개하는 구조를 가진다. 세그먼트 트리를 사용하면 값의 변경이 빈번히 일어나는 상황에서 구간 쿼리를 O(log N) 시간 내에 수행할 수 있다.

세그먼트 트리는 다양한 커스텀 쿼리를 장착할 수 있다. 구간 합이 가장 기본적으로 활용되며, 구간 곱, 구간 최대/최소 등 여러 가지 쿼리를 적용할 수 있다.

```
ex. 구간 [1, 8]의 세그먼트 트리 구조

                  1-8
        1-4                5-8
   1-2      3-4        5-6      7-8
  1   2    3   4      5   6    7   8
```

세그먼트 트리는 일반적으로 초기화, 반환, 업데이트 3가지 연산을 제공하며, 모두 O(log N) 시간이 걸린다.

세그먼트 트리는 자식 노드의 쿼리 연산 값을 통해 현재 노드의 쿼리 연산 값을 정하는 구조를 가지므로, 쿼리 연산은 결합법칙을 만족해야 한다. 그렇지 않다면, 세그먼트 트리를 사용할 수 없다.
> 세그먼트 트리는 쿼리 연산에 결합법칙이 성립할 때 적용할 수 있다.<br>

## 구현
### 만들기
세그먼트 트리는 일반적으로 배열을 사용해서 구현한다.

**크기**
전체 구간의 길이가 N일 때, 세그먼트 트리의 크기(=노드 개수)는 다음과 같이 구할 수 있다.
> 세그먼트 트리 크기 = N보다 큰 가장 가까운 2의 제곱수의 2배<br>

ex. N = 12이면, 세그먼트 크기는 16 × 2 = 32이다

이 과정이 귀찮다면 그냥 N × 4를 하면 된다. 위의 방법보다 메모리를 많이 차지하지만, 편리하게 이용할 수 있다.
> 세그먼트 트리 크기 = N × 4<br>

**인덱스**
세그먼트 트리의 각 노드들은 고유한 인덱스 번호를 갖는다. 루트 노드부터 1로 시작해, 왼쪽→오른쪽 방향으로 1씩 채운다. 한 깊이를 모두 채웠다면, 다음 깊이로 이동한다.
```
           1
    2             3
 4     5       6     7
```
이 인덱스를 사용하면 자식 노드를 편하게 찾을 수 있다.
> 현재 노드의 인덱스가 idx일 때, 왼쪽 노드는 idx × 2, 오른쪽 노드는 idx × 2 + 1<br>

### 초기화 연산
단말 노드에 구간 값들을 채우고, 단말 노드부터 구간 쿼리의 연산 결과를 부모 노드에 기록한다. `재귀 함수`를 사용하자. 구간의 표현은 구간의 처음과 끝을 가리키는 `투 포인터`를 사용한다.
```
[start, end] = 현재 구간
idx = 현재 노드 인덱스
num[N] = 구간 값 목록

int Init(int start, int end, int idx) {
	// 1. 구간 길이가 1이면, 구간 값을 할당하고 종료
	if(start == end)
		return tree[idx] = num[start];
	
	// 2. 구간의 반을 나눠 자식 노드를 탐색한다.
	// 3. 왼쪽 노드, 오른쪽 노드의 값을 입력으로 한 쿼리를 계산하고 현재 노드에 대입
	int mid = (start + end) / 2;
	return tree[idx] = Init(start, mid, idx * 2) + Init(mid + 1, end, idx * 2 + 1);
}
```
예를 들어 쿼리가 구간 합이면 쿼리는 더하기 연산, 구간 곱이면 곱하기 연산을 적용하면 된다. (위의 예시는 더하기 연산 사용)

### 반환 연산
구간 입력[A, B]가 주어졌을 때, [A, B]의 구간 쿼리 연산 결과를 반환한다. [A, B]에 포함되는 트리 노드의 값을 찾고, 쿼리 연산을 수행한 값을 반환하면 된다.
```
ex. 구간 [3, 7] 입력?
| | = 일부 포함
( ) = 완전 포함

                 |1-8|
       |1-4|              |5-8|
   1-2     (3-4)      (5-6)    |7-8|
  1   2    3   4      5   6   (7)  8

=> OP([3-4], OP([5-6], [7])) 반환
```

```
[start, end] = 현재 구간
idx = 현재 노드 인덱스
[left, right] = 입력 구간

int Get(int start, int end, int idx, int left, int right) {
	// 1. 현재 구간이 입력 구간을 완전히 벗어난 경우?
	//  => 쿼리 연산 항등원을 반환한다.
	if(start > right || end < left)
		return 0;

	// 2. 현재 구간이 입력 구간에 완전히 포함된 경우?
	//	=> 현재 노드 값을 반환한다.
	if(start >= left && end <= right)
		return tree[idx];

	// 3. 위 조건에 해당되지 않으며, 현재 구간이 입력 구간에 일부 겹치는 경우?
	//	=> 구간을 분할하여 탐색하며, 분할한 구간의 연산 결과를 입력으로 한 쿼리 연산 값을 반환한다.
	int mid = (start + end) / 2;
	return Get(start, mid, idx * 2, left, right) + Get(mid + 1, end, idx * 2 + 1, left, right);
}
```
항등원은 연산을 해도 입력이 변하지 않는 값을 의미한다. 예를 들어, 더하기 연산에는 0, 곱하기 연산에는 1, 최소 연산은 INF(가장 큰 수)가 항등원이다.

### 업데이트 연산
단말 노드에 있는 구간 값 1개를 변경하는 연산이다. 동시에, 영향을 받는 상위 노드(=입력 노드를 포함하는 노드)의 값도 같이 변경해준다.

값을 변경하는 방법은 순서에 따라 크게 2가지가 있다.
1. 부모 노드부터 갱신 (Top-Down)
2. 자식 노드부터 갱신 (Bottom-Up)

#### 1번 방법 - Top-Down
값의 변화량을 통해 부모 노드부터 업데이트하는 방법.
```
[start, end] = 현재 구간
idx = 현재 노드 인덱스
pos = 변경할 값의 위치
diff = 값 변화량

void Update(int start, int end, int idx, int pos, int diff) {
	// 1. 현재 구간이 입력 위치를 벗어나면 종료
	if(start > pos || end < pos)
		return;
	
	// 2. 현재 노드 업데이트 - 값의 변화량 사용
	tree[idx] += diff;

	// 3. 현재 구간의 길이가 1이면 종료
	if(start == end) return;
	
	// 4. 자식 노드 탐색
	int mid = (start + end) / 2;
	Update(start, mid, idx * 2, pos, diff);
	Update(mid + 1, end, idx * 2 + 1, pos, diff);
}
```
이 방법의 장점은 부모 노드를 업데이트할 때, 자식 노드를 거치지 않는다는 점이다. 이러한 성질로 인해 `Lazy Propagation` 테크닉에 적용할 수 있다. 그러나 변화량으로 현재 노드의 값을 바꾸는 연산을 새로 정의해야 한다는 단점이 있다.

#### 2번 방법 - Bottom-Up
변경할 단말 노드의 값을 먼저 변경하고, 이후 노드들을 위쪽 방향으로 업데이트하는 방법.
```
value = 변경할 값

int Update(int start, int end, int idx, int pos, int value) {
	// 1. 현재 구간이 입력 구간을 완전히 벗어난 경우?
	//  => 현재 노드 값을 반환한다.
	if (start > pos || end < pos)
		return tree[idx];
	
	// 2. 현재 구간의 길이가 1이면 목표 위치에 해당 => 값 업데이트
	if (start == end)
		return tree[idx] = value;

	// 3. 갱신된 자식 노드를 통해 현재 노드 값 업데이트
	int mid = (start + end) / 2;
	return tree[idx] = Update(start, mid, idx * 2, pos, value) + Update(mid + 1, end, idx * 2 + 1, pos, value);
}
```
이 방법의 장점은 새로 정의하는 연산이 없다는 점이다. 즉, 초기화 함수에서 사용했던 연산을 그대로 사용하면 된다.

**Top-Down vs Bottom-Up ??**
일반적으로 Bottom-Up이 편리하다. 구간 내 값이 1개라도 변경되면 연산을 새로 해야 하는 경우는 값 1개만으로 구간의 값을 변경하기 어렵기 때문이다. 

예를 들어, 곱하기 연산에서 [2, 3, 4, 5, 0] 구간의 값은 0이다. 만약 0을 1로 변경한다면 구간의 값은 120으로 바뀌어야 한다. 그러나 기존 구간 값 0과 변경된 값 1, 이 2가지 정보만으로 120을 유도할 수 없다!

> 일반적인 세그먼트 트리는 Bottom-Up이 적합하다. 단, `Lazy Propagation`같이 자식 노드를 참조하지 않는 테크닉은 Top-Down이 적합하다.<br>

## 코드
**Update - Top-Down**
```
#include <iostream>
using namespace std;

int N, M, K;
int num[1000001];
int tree[4000004];

int Init(int start, int end, int idx) {
	if(start == end) return tree[idx] = num[start];
	int mid = (start + end) / 2;
	return tree[idx] = Init(start, mid, idx * 2) + Init(mid + 1, end, idx * 2 + 1);
}

int Get(int start, int end, int idx, int left, int right) {
	if(start > right || end < left) return 0;
	if(start >= left && end <= right) return tree[idx];
	int mid = (start + end) / 2;
	return Get(start, mid, idx * 2, left, right) + Get(mid + 1, end, idx * 2 + 1, left, right);
}

void Update(int start, int end, int idx, int pos, int diff) {
	if(start > pos || end < pos) return;
	
	tree[idx] += diff;
	if(start == end) return;
	
	int mid = (start + end) / 2;
	Update(start, mid, idx * 2, pos, diff);
	Update(mid + 1, end, idx * 2 + 1, pos, diff);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++)
		cin >> num[i];
	Init(1, N, 1);

	int Q = M + K;
	while (Q--) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			Update(1, N, 1, b, c - num[b]);
			num[b] = c;
		}
		else cout << Get(1, N, 1, b, c) << "\n";
	}
	return 0;
}
```

**Update - Bottom-Up**
```
#include <iostream>
using namespace std;

int N, M, K;
int num[1000001];
int tree[4000004];

int Init(int start, int end, int idx) {
	if(start == end) return tree[idx] = num[start];
	int mid = (start + end) / 2;
	return tree[idx] = Init(start, mid, idx * 2) + Init(mid + 1, end, idx * 2 + 1);
}

int Get(int start, int end, int idx, int left, int right) {
	if(start > right || end < left) return 0;
	if(start >= left && end <= right) return tree[idx];
	int mid = (start + end) / 2;
	return Get(start, mid, idx * 2, left, right) + Get(mid + 1, end, idx * 2 + 1, left, right);
}

int Update(int start, int end, int idx, int pos, int value) {
	if (start > pos || end < pos) return tree[idx];
	if (start == end) return tree[idx] = value;
	int mid = (start + end) / 2;
	return tree[idx] = Update(start, mid, idx * 2, pos, value) + Update(mid + 1, end, idx * 2 + 1, pos, value);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++)
		cin >> num[i];
	Init(1, N, 1);

	int Q = M + K;
	while (Q--) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1) Update(1, N, 1, b, c);
		else cout << Get(1, N, 1, b, c) << "\n";
	}
	return 0;
}
```

## 관련 문제
**기본 문제**
<br>https://www.acmicpc.net/problem/2042

**Bottom-Up 업데이트 사용**
<br>https://www.acmicpc.net/problem/11505
<br>https://www.acmicpc.net/problem/2357

**커스텀 노드**
<br>https://www.acmicpc.net/problem/16993

## 참고
<br>https://m.blog.naver.com/ndb796/221282210534
<br>https://www.acmicpc.net/blog/view/9
<br>https://book.acmicpc.net/ds/segment-tree
<br>https://www.crocus.co.kr/648
{% endraw %}