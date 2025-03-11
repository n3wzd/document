---
categories:
- Algorithm
date: '2022-08-03'
title: '[Algorithm] Knuth Optimization'
---

{% raw %}
## 크누스 최적화 (Knuth Optimization)
아래와 같은 함수가 있을 때, (i < k < j)
> F[i][j] = min(F[i][k] + F[k][j]) + C[i][j]<br>

나이브한 방법으로 계산하면 O(N<sup>3</sup>) 시간이 걸린다. 하지만 `크누스 최적화`을 적용하면 O(N<sup>2</sup>)으로 최적화할 수 있다.

크누스 최적화를 적용하려면 위의 함수 구조 이외에 아래 2가지 조건을 모두 만족해야 한다.
> 사각 부등식: C[a][c] + C[b][d] ≤ C[a][d] + C[b][c] (a ≤ b ≤ c ≤ d)<br>
> 단조성: C[b][c] ≤ C[a][d] (a ≤ b ≤ c ≤ d)<br>

i, j가 주어졌을 때 F[i][j]가 최적의 값이 되게 하는 k를 K[i][j]라고 정의하자. 크누스 최적화 조건을 만족한다면 다음 식이 성립한다.
> K[i][j - 1] ≤ K[i][j] ≤ K[i + 1][j]<br>

k를 찾기 위한 탐색 범위가 [i, j]에서 [K[i][j - 1], K[i + 1][j]]으로 단축되었다.

## 코드
`BOJ - 13974 - 파일 합치기 2` 코드
```
#include <iostream>
using namespace std;
const int SIZE = 5002, INF = 1 << 30;
int Q, N, file, S[SIZE];
int cache[SIZE][SIZE], K[SIZE][SIZE];

void Solve() {
	cin >> N;<br>
	for (int i = 1; i <= N; i++) {
		cin >> file;<br>
		S[i] = S[i - 1] + file;
		cache[i - 1][i] = 0;
		K[i - 1][i] = i;
	}

	for (int w = 2; w <= N; w++) {
		for (int i = 0; i + w <= N; i++) {
			int j = i + w;
			cache[i][j] = INF;
			for (int k = K[i][j - 1]; k <= K[i + 1][j]; k++) {
				int v = cache[i][k] + cache[k][j] + S[j] - S[i];
				if (v < cache[i][j]) {
					cache[i][j] = v;
					K[i][j] = k;
				}
			}
		}
	}
	cout << cache[0][N] << "\n";
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> Q;<br>
	while (Q--)
		Solve();
	return 0;
}
```

## 연관 문제
https://www.acmicpc.net/problem/13974

## 참고
https://justicehui.github.io/hard-algorithm/2019/01/02/knuthOpt/
https://justicehui.github.io/icpc/2019/01/02/BOJ13974/
{% endraw %}