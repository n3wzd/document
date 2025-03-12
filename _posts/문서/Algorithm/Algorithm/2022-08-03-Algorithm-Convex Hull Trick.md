---
categories:
- Algorithm
date: '2022-08-03'
title: '[Algorithm] Convex Hull Trick'
---

{% raw %}
## Convex Hull Trick
다음과 같은 함수가 있을 때, 
> F(i) = min(A[i] × B[j] + C(j)) + D[i] (j < i)<br>
> or<br>
> F(i) = max(A[i] × B[j] + C[j]) + D[i] (j < i)<br>

이를 나이브하게 계산하면 O(N<sup>2</sup>) 시간이 걸린다. 하지만 `Convex Hull Trick`을 적용하면 O(N log N), O(N)으로 최적화할 수 있다.

## 적용
`Convex Hull Trick`은 다음과 같은 상황에서 적용할 수 있다.
> F(i) = min(A[i] × B[j] + C(j)) + D[i] (j < i)<br>
> F(i) = max(A[i] × B[j] + C[j]) + D[i] (j < i)<br>

- (i에 대한 함수) × (j에 대한 함수) 구조다.
- min일 때는 (B[j - 1] ≥ B[j]), max일 때는 (B[j - 1] ≤ B[j])를 만족해야 한다.

## 설계
### 함수 정의
현재 변수 i에 대해 정리해보자. x = A[i]으로 했을 때 다음과 같이 x에 대한 1차함수를 정의할 수 있다.
> L(x) = B[j] × x + C(j)<br>

이를 점화식에 대입하면,
> F(i) = min(L(x)) + D[i]<br>

이는 여러 개의 1차함수가 있을 때 최소를 찾는 문제로 볼 수 있다. (D[i]는 상수이므로 무시할 수 있다.)

### 1차함수 목록
아래와 같이 여러 1차함수(직선)가 있을 때,
![](images/CHT-L1.png)

최소가 될 수 있는 구간은 다음과 같이 `Convex Hull` 모양을 이룬다. 교점을 기준으로 최소가 될 수 있는 직선을 저장하고 탐색하면 최솟값을 구할 수 있다.
![](images/CHT-L2.png)

최소가 될 수 있는 직선을 `스택`에 저장하자. 조건 (B[j - 1] ≥ B[j])에 따라 기울기가 감소하는 순서대로 직선이 입력됨이 보장된다.

새 직선을 A, 스택 top부터 저장된 직선 2개를 순서대로 B, C라고 하자. 직선이 추가되는 경우는 크게 2가지로 나눌 수 있다. (단, A ≠ B)
1. A, B의 교점 x값이 B, C의 교점 x값보다 작다.
2. A, B의 교점 x값이 B, C의 교점 x값보다 크다.
![](images/CHT-L3.png)

전자는 A가 항상 B보다 y값이 작은 경우로, B는 더 이상 최소가 될 수 없다. 따라서 B를 스택에서 제외한다. 후자는 A, B 모두 최소가 될 수 있는 경우로, 삭제되는 직선이 없다. 2번째 경우를 만족할 때까지 스택 삭제 과정을 반복하면 된다.
```
struct Line { ll a, b; }; // y = ax + b
int size = 0;
Line stk[SIZE]; // 인덱스 접근이 필요하므로 실제 구현은 배열을 사용한다.

// 두 직선의 교점 x좌표 반환
double Cross(int L1, int L2) {
	// 교점은 두 직선을 연립해서 구할 수 있다.
	return (double)(stk[L1].b - stk[L2].b) / (stk[L2].a - stk[L1].a);
}

// 직선 v를 추가하는 메소드
void Insert(Line v) {
	// 새 직선 추가
	stk[size] = v;
	
	// 교점 x 좌표 대소 비교 (A = size, B = size - 1, C = size - 2)
	// A, B의 교점 x > B, C의 교점 x을 만족할 때까지 스택 삭제 반복
	while (1 < size && Cross(size - 2, size - 1) > Cross(size - 1, size)) {
		stk[size - 1] = stk[size];
		size--;
	}
	size++;
}
```

※ A와 B의 기울기가 동일한 경우가 있다면, y절편이 작은 것을 선택하면 된다.

### 찾기 쿼리 - O(N log N)
이제 쿼리 x좌표가 주어졌을 때 최솟값을 찾아보자. 일반적인 상황에선 `이분 탐색`으로 구할 수 있으며 쿼리마다 O(log N) 시간이 소모된다.

**<이분 탐색>**
- 목표 값 = x의 최솟값을 포함한 직선
	- 현재 값이 조건을 만족하면 오른쪽 구간으로 이동
- 초기 탐색 구간 = [0, 스택 길이 - 1]

**< 조건 함수 >**

두 인접한 직선의 교점 x좌표가 쿼리 x보다 같거나 작으면 true이다.
 
```
// 직선 이분 탐색
ll Search(ll x) {
	int lo = 0, hi = size - 1;
	while (lo < hi) {
		int mid = (lo + hi) / 2;
		if (Cross(mid, mid + 1) <= x)
			lo = mid + 1;
		else hi = mid;
	}
	// 최솟값 반환
	return stk[lo].a * x + stk[lo].b;
}
```

### 찾기 쿼리 - O(N)
쿼리 x가 증가하는 순서대로 주어진다면 쿼리 답 직선보다 이전에 있는 직선은 더 이상 사용되지 않는 점이 보장된다. 즉, 이전에 있는 직선들을 삭제해서 탐색의 범위를 줄일 수 있다. 이 방법을 사용하면 이분 탐색을 사용하지 않으므로 총 시간이 O(N)으로 단축된다.

이 방법을 적용하려면 기존 스택에서 앞쪽 삭제도 가능해야 한다. 이는 `덱`을 사용해서 해결할 수 있다.
```
int bot, top = 0;
Line deq[SIZE];

int Search(ll x) {
	// 쿼리 답 직선을 찾을 때까지 이전 직선을 삭제한다.
	while (1 < (top - bot) && deq[bot + 1].b - deq[bot].b >= x * (deq[bot].a - deq[bot + 1].a))
		bot++;

	// 찾은 직선 반환
	return bot;
}
```

## 코드
`BOJ - 13263 - 나무 자르기` 코드
```
#include <iostream>
using namespace std;
typedef long long ll;
struct Line { ll a, b; }; // y = ax + b
const int SIZE = 1e5 + 2;
ll A[SIZE], B[SIZE], cache; int N;

struct CHT {
	int size = 0;
	Line stk[SIZE];

	double Cross(int L1, int L2) {
		return (double)(stk[L1].b - stk[L2].b) / (stk[L2].a - stk[L1].a);
	}

	void Insert(Line v) {
		stk[size] = v;
		while (1 < size && Cross(size - 2, size - 1) > Cross(size - 1, size)) {
			stk[size - 1] = stk[size];
			size--;
		}
		size++;
	}

	ll Search(ll x) {
		int lo = 0, hi = size - 1;
		while (lo < hi) {
			int mid = (lo + hi) / 2;
			if (Cross(mid, mid + 1) <= x)
				lo = mid + 1;
			else hi = mid;
		}
		return stk[lo].a * x + stk[lo].b;
	}
};
CHT cht;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];
	for (int i = 0; i < N; i++)
		cin >> B[i];

	cht.Insert({ B[0], 0 });
	for (int i = 1; i < N; i++) {
		cache = cht.Search(A[i]);
		cht.Insert({ B[i], cache });
	}
	cout << cache;
	return 0;
}
```

## 연관 문제
<br>https://www.acmicpc.net/problem/13263
<br>https://www.acmicpc.net/problem/4008
<br>https://www.acmicpc.net/problem/10067

## 참고
<br>https://www.weeklyps.com/entry/%EC%BB%A8%EB%B2%A1%EC%8A%A4-%ED%97%90-%ED%8A%B8%EB%A6%AD-Convex-Hull-Trick
<br>https://stonejjun.tistory.com/50
{% endraw %}