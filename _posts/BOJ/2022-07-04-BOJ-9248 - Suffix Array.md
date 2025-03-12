---
categories:
- BOJ
date: '2022-07-04'
title: '[BOJ] 9248 - Suffix Array'
---

{% raw %}
> 플래티넘 III<br>

## 문제
Suffix Array란, 문자열 S가 있을 때 그 접미사들을 정렬해 놓은 배열이다.

문자열 S의 LCP Array는 Suffix Array를 구한 다음, 각 Suffix마다 정렬된 상태에서 바로 이전 Suffix와의 LCP (Longest Common Prefix, 최장 공통 접두사)의 길이를 배열에 담은 것이다.

길이가 50만보다 작거나 같은 문자열이 주어졌을 때, Suffix Array와 LCP Array를 구하는 프로그램을 작성하시오.

### 입력
첫째 줄에 알파벳 소문자로만 이루어진 문자열 S가 주어진다. S의 길이는 50만보다 작거나 같다.

### 출력
첫째 줄에는 Suffix Array를, 둘째 줄에는 LCP Array를 공백으로 구분하여 출력한다. LCP Array의 첫 값은 항상 'x'이다.

## 해결
`Suffix Array`와 `LCP Array`를 다루는 기본 문제.

## 코드
```
#include <iostream>
#include <algorithm>
using namespace std;
const int SIZE = 500005;
string str;
int b, g[SIZE], tg[SIZE], SA[SIZE];
int r[SIZE], LCP[SIZE];

bool cmp(int x, int y) {
	if (g[x] == g[y])
		return g[x + b] < g[y + b];
	return g[x] < g[y];
}

void MakeSA() {
	b = 1;
	int n = str.size();
	for (int i = 0; i < n; i++) {
		SA[i] = i;
		g[i] = str[i] - 'a';
	}

	while (b <= n) {
		g[n] = -1;
		sort(SA, SA + n, cmp);
		tg[SA[0]] = 0;

		for (int i = 1; i < n; i++) {
			if (cmp(SA[i - 1], SA[i]))
				tg[SA[i]] = tg[SA[i - 1]] + 1;
			else
				tg[SA[i]] = tg[SA[i - 1]];
		}
		for (int i = 0; i < n; i++)
			g[i] = tg[i];

		b *= 2;
	}
}

void MakeLCP() {
	int n = str.size();
	for (int i = 0; i < n; i++)
		r[SA[i]] = i;
	
	int len = 0;
	for (int i = 0; i < n; i++) {
		int k = r[i];
		if (k > 0) {
			int j = SA[k - 1];
			while (str[j + len] == str[i + len])
				len++;
			LCP[k] = len;
			if (len > 0)
				len--;
		}
	}
}

void Print() {
	int n = str.size();
	for (int i = 0; i < n; i++)
		cout << SA[i] + 1 << " ";
	cout << "\n";

	cout << "x ";
	for (int i = 1; i < n; i++)
		cout << LCP[i] << " ";
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> str;
	MakeSA();
	MakeLCP();
	Print();
	return 0;
}
```

## 링크
<br>https://www.acmicpc.net/problem/9248
{% endraw %}