---
categories:
- Algorithm
date: '2022-06-08'
title: '[Algorithm] Mo’s Algorithm'
---

{% raw %}
## Mo’s Algorithm
`Mo’s Algorithm`은 구간 쿼리를 빠르게 수행하는 알고리즘이다. 쿼리 수행 순서를 임의로 바꾸는 `오프라인 쿼리` 방법에 속한다.

쿼리 구간의 양끝을 `투 포인터`로 잡아서 구간을 표현한다. 현재 쿼리를 계산할 때는 새로 계산하지 않고, 이전 구간의 범위를 변경해서 이전 답을 적절히 바꾸는 방식으로 현재 답을 구한다.

Mo’s Algorithm은 구간 쿼리 연산을 빠르게 수행한다는 점에서 `세그먼트 트리`하고 용도가 비슷하다. 세그먼트 트리보다 대체로 느리지만, Mo’s Algorithm은 쿼리 연산에 결합법칙이 성립하지 않아도 된다는 이점이 있다.

Mo’s Algorithm의 시간 복잡도는 O((N+M)√N)이다.

## 설계
Mo’s Algorithm의 핵심은 쿼리의 처리 순서를 적당히 변경해서 `투 포인터`의 이동이 가급적 안정적인 최소가 되게 하는 것이다.

1 ) 구간을 블록 단위로 나눈다. 이때 `평방 분할`의 로직이 이용되며, 블록의 크기는 √N이다.
```
N = 9, √N = 3
□□□□□□□□□
> □□□|□□□|□□□<br>
```

2 ) 쿼리 실행 순서를 정렬한다.
> 쿼리의 오른쪽 끝이 속한 블록이 증가하는 순서대로, 블록이 같으면 왼쪽 끝이 증가하는 순서대로 정렬한다.<br>

3 ) 쿼리 구간의 양끝을 `투 포인터`로 잡고, 쿼리를 실행한다.

다음 쿼리로 이동할 때는 끝 포인터를 각각 1칸씩 옮기면서 이동하며, 동시에 답의 변화량을 계산하고 반영한다. (이 포인터의 이동이 Mo’s Algorithm의 시간 복잡도를 결정한다.)

4 ) 쿼리 답을 출력한다. (원본 순서대로 출력해야 한다)

## 구현
> `i j`: Ai, Ai+1, ..., Aj에 존재하는 서로 다른 수의 개수를 출력한다.<br>

해당 쿼리는 결합 법칙이 성립하지 않으므로, 세그먼트 트리를 사용할 수 없다. `Mo’s algorithm`를 사용해보자.

**1 ) 블록 나누기**
블록의 크기를 구하는 과정. N의 제곱근을 구하면 된다.
```
sqN = sqrt(N)
```

**2 ) 쿼리 정렬하기**
각 쿼리는 입력 구간 정보, 원본 순서 위치 정보가 필요하다.
```
class Query
	int left, right; // 쿼리 구간
	int order; // 원본 순서 위치
Query query[MAX]
```

그리고 정렬 기준에 따라 쿼리를 정렬한다.
```
1. 쿼리의 오른쪽 끝이 속한 블록이 증가하는 순서대로 정렬
2. 블록이 같으면, 왼쪽 끝이 증가하는 순서대로 정렬

bool cmp(Query a, Query b) {
	return (a.right / sqN != b.right / sqN) ? 
		a.right / sqN < b.right / sqN : a.left < b.left;
}
```

**3) 쿼리 실행**
이전 구간 포인터를 현재 구간 방향으로 1칸씩 옮기면서, 현재 쿼리 답을 구한다.
```
[lo, hi] = 이전 구간
[newLo, newHi] = 현재 구간
res = 현재 답
resList[MAX] = 쿼리 답 저장

// 초기 설정
lo = query[0].left;
hi = lo;
cnt[arr[lo]] = 1;

// 쿼리 실행
for (int i = 0; i < M; i++) {
	// 현재 구간 구하기
	newLo = query[i].left;
	newHi = query[i].right;

	// 구간 포인터 이동 (+ 답 변화량 반영)
	while (lo > newLo) Scan(--lo, 1);
	while (lo < newLo) Scan(lo++, -1);
	while (hi < newHi) Scan(++hi, 1);
	while (hi > newHi) Scan(hi--, -1);

	// 현재 답 구하기
	resList[query[i].order] = res;
}
```

다음으로 답의 변화량을 반영하자. 이 부분은 쿼리 연산마다 다르다. 문제에서 쿼리는 서로 다른 수의 개수를 구하므로, 수의 등장 횟수를 카운팅하는 배열을 사용하자.
```
cnt[MAX] // 카운팅 배열
> 구간이 확장될 때 (lo > newLo, hi < newHi) => 새로운 수 n<br>
	- cnt[n] += 1
	- 만약 cnt[n]이 0에서 1로 되는 경우면, res += 1
> 구간이 수축될 때 (lo < newLo, hi > newHi) => 새로운 수 n<br>
	- cnt[n] -= 1
	- 만약 cnt[n]이 1에서 0으로 되는 경우면, res -= 1
```

**4 ) 쿼리 출력**
원본 순서대로 답을 출력한다.
```
for (int i = 0; i < M; i++)
	cout << resList[i] << "\n";
```

## 코드
`13547 - 수열과 쿼리 5` 코드
```
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int N, sqN, M, res = 1;
int arr[100001], resList[100001];
int cnt[1000001];

class Query {
public:
	int left, right, order;
	Query() {}
	Query(int a, int b, int c) { left = a, right = b, order = c; }
};
Query query[100001];

bool cmp(Query a, Query b) {
	return (a.right / sqN != b.right / sqN) ? a.right / sqN < b.right / sqN : a.left < b.left;
}

void Scan(int p, int d) {
	if (cnt[arr[p]] == 0 && d > 0) res++;
	if (cnt[arr[p]] == 1 && d < 0) res--;
	cnt[arr[p]] += d;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	sqN = sqrt(N);
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> query[i].left >> query[i].right;
		query[i].left--, query[i].right--, query[i].order = i;
	}
	sort(query, query + M, cmp);

	int lo = query[0].left;
	int hi = lo;
	cnt[arr[lo]] = 1;
	for (int i = 0; i < M; i++) {
		int newLo = query[i].left, newHi = query[i].right;
		while (lo > newLo) Scan(--lo, 1);
		while (lo < newLo) Scan(lo++, -1);
		while (hi < newHi) Scan(++hi, 1);
		while (hi > newHi) Scan(hi--, -1);
		resList[query[i].order] = res;
	}
	for (int i = 0; i < M; i++)
		cout << resList[i] << "\n";

	return 0;
}
```

## 연관 문제
<br>https://www.acmicpc.net/problem/13547

## 참고
<br>http://www.secmem.org/blog/2019/02/09/mo's-algorithm/
{% endraw %}