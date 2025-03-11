---
categories:
- Algorithm
date: '2022-05-17'
title: '[Algorithm] Prefix Sum'
---

{% raw %}
## Prefix Sum
구간의 누적 합을 빠르게 구하는 `DP` 응용 테크닉. 구간 합을 일일이 구하면 O(N<sup>2</sup>)이지만, 구간 합 방법을 사용하면 O(N) 시간으로 빠르게 구할 수 있다.

## 방법
```
1. 1번부터 n번까지 누적 합을 미리 구한다. => sum[n]<br>
2. [a, b] 구간 합 = sum[b] - sum[a - 1]
```

이 방법의 본질은 DP이므로, 구간 합을 응용하는 문제가 나왔다면 DP 관점으로 접근하면 된다.

## 코드
※ `BOJ-11659 - 구간 합 구하기 4` 코드
```
#include <iostream>
using namespace std;

int N, M, num;
int sum[100002];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;<br>
	for (int i = 1; i <= N; i++) {
		cin >> num;<br>
		sum[i] = num + sum[i - 1];
	}
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;<br>
		cout << sum[b] - sum[a-1] << "\n";
	}
	return 0;
}
```

## 관련 문제
https://www.acmicpc.net/problem/11659
https://www.acmicpc.net/problem/11660

## 참고
https://jow1025.tistory.com/47
{% endraw %}