---
categories:
- BOJ
date: '2022-07-17'
title: '[BOJ] 5977 - Mowing the Lawn'
---

{% raw %}
> 플래티넘 III<br>

## 문제
After winning the annual town competition for best lawn a year ago, Farmer John has grown lazy; he has not mowed the lawn since then and thus his lawn has become unruly. However, the competition is once again coming soon, and FJ would like to get his lawn into tiptop shape so that he can claim the title.

Unfortunately, FJ has realized that his lawn is so unkempt that he will need to get some of his N (1 <= N <= 100,000) cows, who are lined up in a row and conveniently numbered 1..N, to help him. Some cows are more efficient than others at mowing the lawn; cow i has efficiency E_i (0 <= E_i <= 1,000,000,000).

FJ has noticed that cows near each other in line often know each other well; he has also discovered that if he chooses more than K (1 <= K <= N) consecutive (adjacent) cows to help him, they will ignore the lawn and start a party instead. Thus, FJ needs you to assist him: determine the largest total cow efficiency FJ can obtain without choosing more than K consecutive cows.

### 입력
-   Line 1: Two space-separated integers: N and K
-   Lines 2..N+1: Line i+1 contains the single integer: E_i

### 출력
-   Line 1: A single integer that is the best total efficiency FJ can obtain.

## 해결
연속합의 길이가 K를 초과하지 않아야 하는 조건 속에서 최대 합을 구해야 한다. `DP`를 사용하자.

**< 부분 문제 정의 >**
- 현재 상태 = 현재 수열의 끝 => (n)
	- 목표 상태 = N
- 계산 결과 = 수열 S의 구간 [1, n]에서 문제의 조건에 맞는 최대 합

**< DP 함수 >**

소의 효율은 항상 음이 아닌 정수이므로 K 범위만 넘지 않는다면 최대한 많이 더하는 것이 이득이다.

K+1 길이의 `슬라이딩 윈도우`를 생성하고 현재 수열의 끝을 윈도우의 우측 끝이라고 하자. 현재 윈도우의 범위는 [n, n - K]이다. 현재 상태에서 새로 들어온 수는 S[n]이므로 이 수를 포함하는 경우만 추가로 계산해주면 된다. 구간 [n, n], [n - 1, n], ... , [n - K + 1, n]의 합과 n을 더하지 않는 경우를 모두 조사하자.

> DP(n) = max(Sum(i, n) + DP(i - 1))<br>
> // i = [n, n - K]<br>
> // Sum(lo, hi) = ps[hi] - ps[lo]<br>

S의 구간 합은 `누적 합`으로 구할 수 있다. (값의 변동은 없으므로 세그먼트 트리를 사용하지 않아도 된다)

코드로 작성하면,
```
for (int i = n; i >= n - K; i--)
	cache[n] = max(cache[n], ps[n] - ps[i] + cache[i - 1]);
```
시간 복잡도는 O(N<sup>2</sup>)이다. 그러나 N은 최대 10<sup>5</sup>이므로 시간 초과가 발생할 수 있어 최적화 작업이 필요하다. => 구간 최대를 빠르게 구해야 함

위의 점화식은 슬라이딩 윈도우에서 최대를 구하는 문제라고 볼 수 있으며, 이 문제는 `덱`을 사용해서 O(N) 시간으로 단축할 수 있다. 점화식에서 (-ps[i] + cache[i - 1])를 덱의 값으로 저장하면 된다.

※ 이 방법을 적용한 이후에는 누적 합, DP 캐시 모두 이전 값만 필요하게 된다. 이는 `토글링`을 적용해서 사용하지 않는 메모리 공간을 줄일 수 있다.

## 코드
```
#include <iostream>
#include <queue>
typedef long long ll;
using namespace std;
int N, K, cow;
ll ps, cache;
struct Node { ll val; int id; };
deque<Node> dq;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	for (int n = 1; n <= N; n++) {
		cin >> cow;
		ps += cow;
		if(!dq.empty())
			if (n - (K + 1) >= dq.front().id)
				dq.pop_front();

		ll val = -ps + cache;
		while (!dq.empty()) {
			if (dq.back().val > val)
				break;
			dq.pop_back();
		}
		dq.push_back({ val, n });
		cache = (n - K > 0) ? ps + dq.front().val : ps;
	}
	cout << cache;
	return 0;
}
```

## 링크
<br>https://www.acmicpc.net/problem/5977
{% endraw %}