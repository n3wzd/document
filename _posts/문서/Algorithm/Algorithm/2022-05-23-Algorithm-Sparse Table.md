---
categories:
- Algorithm
date: '2022-05-23'
title: '[Algorithm] Sparse Table'
---

{% raw %}
## Sparse Table
특정 쿼리의 반복을 빠르게 수행하기 위해 사용되는 자료구조. 쿼리의 2<sup>k</sup>번 연산 결과를 미리 계산해서 기록한다.

전체적인 아이디어는 `고속 거듭제곱 알고리즘`하고 비슷하다. 일일이 쿼리를 직접 처리하면 쿼리마다 O(M) 시간이 걸리지만, 2<sup>k</sup> 회수로 나눠서 처리하면 O(log M) 시간으로 단축할 수 있다.  이러한 반복 쿼리의 요청이 여러 번이라면 sparse table가 효과적이다.<br>

활용 예시로, `LCA`가 있다.

## 구현
### 생성
우선, 쿼리의 2<sup>k</sup>번 연산 결과를 기록하는 sparse table을 생성해야 한다. 2<sup>k</sup>번 연산은 2<sup>k-1</sup>의 연산 기록으로 구할 수 있다. `DP`를 사용하자.

부분 문제의 현재 상태를 (i, k), 계산 결과를 출력으로 정의한다.

ex. 쿼리 F(x)에서 F(F(F(F(F(x)))))
```
k = 0
F(x) = y1
F(y1) = y2
F(y3) = res
...

k = 1
F(F(x)) = F(y1) = y2
F(F(y2)) = y3
...

k = 2
F(F(F(F(x)))) = F(F(y2)) = y3
...

=> F(F(F(F(F(x))))) = F(y3) = res<br>
```

점화식과 생성 함수(Bottom-Up DP 사용)는 다음과 같다.
> F[i][k] = F[F[i][k - 1]][k - 1]<br>
```
for (int k = 1; k <= logM; k++)
	for (int i = 1; i <= N; i++)
		F[i][k] = F[F[i][k - 1]][k - 1]
```
※ M = 쿼리 최대 반복 횟수, N = 입력 종류 개수 

### 탐색
고속 거듭제곱 알고리즘과 비슷하다. 반복 횟수 n을 2<sup>k</sup>의 합으로 분할하고, 순차적으로 sparse table을 탐색한다. 주로 반복 횟수를 알고 있다면 `비트마스크`, 반복 횟수를 모르면 `이분 탐색`을 사용한다.

구현 예시)
```
k = logM // k 최대부터 탐색 시작
while (k >= 0)
	if (n & (1 << k)) // n에 2^k가 포함되어 있는지 확인
		x = F[x][k]
	k -= 1
Print(x)
```

## 코드
※ `BOJ - 17435 - 합성함수와 쿼리`의 코드
```
#include <iostream>
using namespace std;

int N, M;
int F[200001][19];
const int logM = 19;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;<br>
	for (int i = 1; i <= N; i++) cin >> F[i][0];<br>

	for (int k = 1; k < logM; k++)
		for (int i = 1; i <= N; i++)
			F[i][k] = F[F[i][k - 1]][k - 1];

	cin >> M;<br>
	while (M--) {
		int n, x;
		cin >> n >> x;<br>

		int k = logM - 1;
		while (k >= 0) {
			if (n & (1 << k)) x = F[x][k];
			k--;
		}
		cout << x << "\n";
	}
	return 0;
}
```

## 연관 문제
https://www.acmicpc.net/problem/17435

## 참고
https://www.geeksforgeeks.org/sparse-table/
{% endraw %}