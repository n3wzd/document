---
categories:
- Algorithm
date: '2022-07-05'
title: '[Algorithm] Suffix Array'
---

{% raw %}
## Suffix Array
접미사는 원본 문자열의 끝에서 끝나는 부분 문자열이다. `Suffix Array`은 모든 접미사를 사전 순으로 정렬한 자료 구조이다. 1990년 Manber & Myers가 공간을 많이 차지하는 Suffix Tree의 대안으로 Suffix Array를 도입했다고 한다.

먼저 접미사부터 저장해보자. 접미사를 문자열 그대로 저장하면 공간을 많이 차지한다. 접미사는 부분 문자열의 시작점만 알면 식별 및 검색이 가능하므로 **원본 문자열에서 접미사의 시작점** 으로 저장하자. (여기서 인덱스는 0부터 시작한다)
```
> "banana"<br>
i     Suffix    S[i]
0          a     5
1         na     4
2        ana     3
3       nana     2
4      anana     1
5     banana     0
```

Suffix Array를 구해보자. 우선 모든 접미사(=배열 S)를 그냥 정렬하는 나이브한 방법이 있다.
```
i     Suffix   SA[i]
0          a     5
1        ana     3
2      anana     1
3     banana     0
4         na     4
5       nana     2
```
이때 시간 복잡도는 O(N<sup>2</sup> × logN)이다. (각 접미사 비교 = N, 정렬 = N × logN)

## Manber-Myers Algorithm
`Manber-Myers Algorithm`은 나이브 방법보다 Suffix Array를 빨리 구하는 방법이다.

정렬 대상인 접미사는 원본 문자열의 부분 문자열이므로 접미사끼리 서로 겹치는 문자가 항상 있다는 점을 활용해서 중복 연산을 피한다.

> 정렬 기준을 매 회차마다 1번째 문자, 2번째 문자, 4번째 문자 ... 2<sup>p</sup>번째 문자 사전 순으로 설정하고, 원본 문자열 길이 N에 도달할 때까지 정렬을 반복 수행한다.<br>

매 회차마다 같은 순위에 있는 접미사들을 **그룹** 단위로 묶어서 식별한다.
```
g[N]
인덱스: 원본 문자열에서 접미사의 시작점
값: 현재 [0, b-1]번 문자가 같은 접미사 그룹 번호 = 그룹의 정렬 순위
```

매 회차마다 각 그룹 내부에서 정렬이 이뤄진다. 즉, 어떤 접미사의 그룹이 한번 결정되면, 그 접미사는 해당 그룹 바깥으로 나갈 수 없다.
```
PASS 0 (b = 1)
i     Suffix    g[i]
1      anana      0
3        ana      0
5          a      0
0     banana      1
2       nana     13
4         na     13
// 처음에는 g에 문자 번호를 저장한다.

PASS 1 (b = 2)
i     Suffix    g[i]
5          a      0
1      anana      1
3        ana      1
0     banana      2
2       nana      3
4         na      3
// banana, nana는 별개의 그룹이므로 정렬이 따로 이뤄진다.
// 따라서 b번째 문자(=a)가 같더라도 배정된 순위는 다르다.

PASS 2 (b = 4)
i     Suffix    g[i]
5          a      0
3        ana      1
1      anana      2
0     banana      3
4         na      4
2       nana      5
// 최종적으로 g의 값은 모두 달라지고, 그에 따라 SA도 최종 결정된다.
```

정렬을 위한 비교 함수를 설계해보자.
|0|1|2|3|4|5|6|7|8|9|g|
|---|---|---|---|---|---|---|---|---|---|---|
|m|i|s|s|i|s|s|i|p|i|4|
| |i|s|s|i|s|s|i|p|i|3|
| | |s|s|**i**|**s**|s|i|p|i|**?**|
| | | |s|i|s|s|i|p|i|7|
| | | | |**i**|**s**|s|i|p|i|**3**|
| | | | | |s|s|**i**|**p**|i|**?**|
| | | | | | |s|i|p|i|6|
| | | | | | | |**i**|**p**|i|**2**|
| | | | | | | | |p|i|5|
| | | | | | | | | |i|1|
위와 같이 PASS 2에서 [3-4]번째 문자 비교는 이미 PASS 1에서 비교한 결과가 있다. 따라서 문자 별로 비교를 하지 않고, 그룹으로 비교하면 이전 정렬 결과를 재활용할 수 있다.
> 1. 그룹이 다르면 그룹 순으로 정렬<br>
> 2. 그룹이 같으면 (현재 그룹 + b)번 그룹 순으로 정렬<br>
```
bool cmp(int x, int y) {
	if (g[x] == g[y])
		return g[x + b] < g[y + b];
	return g[x] < g[y];
}
```

이제 실제로 구현해보자.
```
string str; // 입력 문자열
int b; // 단계별 문자 평행이동 (0, 1, 2, 4...)
int g[SIZE]; // 그룹 저장
int tg[SIZE]; // g를 설정할 때 사용되는 임시 배열
int SA[SIZE]; // Suffix Array

// 비교 함수
bool cmp(int x, int y) {
	if (g[x] == g[y])
		return g[x + b] < g[y + b];
	return g[x] < g[y];
}
// 인덱스가 배열 g의 범위를 벗어나는 경우는 없으므로 따로 처리하지 않아도 된다. 

void MakeSA() {
	// 1. PASS 0
	b = 1;
	int n = str.size();
	for (int i = 0; i < n; i++) {
		SA[i] = i;
		g[i] = str[i] - 'a';
	}

	// 2. PASS 1~
	while (b <= n) {
		// 1. SA 설정 & 기타 초항 설정
		g[n] = -1;
		sort(SA, SA + n, cmp);
		tg[SA[0]] = 0;

		// 2. tg 설정
		for (int i = 1; i < n; i++) {
			if (cmp(SA[i - 1], SA[i]))
				tg[SA[i]] = tg[SA[i - 1]] + 1;
			else
				tg[SA[i]] = tg[SA[i - 1]];
		}
		
		// 3. g 설정
		for (int i = 0; i < n; i++)
			g[i] = tg[i];

		// 4. PASS 단계 증가
		b *= 2;
	}
}
```
위 구현의 시간 복잡도는 O(N × (logN)<sup>2</sup>)이다. PS(Problem Solving)에선 이 정도면 충분히 통과할 수 있다.

여기서 O(N × logN)으로 동작하는 구현 방법이 있다. 위의 STL 정렬을 `카운팅 정렬`로 변경하면 된다. (전체적인 설계는 동일하다)

※ 이 알고리즘과 별개로 O(N) 시간으로 Suffix Array를 구하는 방법이 있다고 하나, 상당히 복잡하기 때문에 PS에선 쓰이지 않는다고 한다.

## LCP Array
`LCP(Longest Common Prefix)`는 두 문자열에서 가장 긴 접두사이다. `LCP Array`는 다음과 같이 정의된다.
```
LCP[i]
인덱스: SA하고 동일
값: SA[i], SA[i - 1]간 LCP의 길이
// LCP[0] 값은 정의되지 않으며, 주로 0으로 설정된다.
```
```
i   SA[i]   Suffix   LCP[i]
0     5          a     0
1     3        ana     1 (=a)
2     1      anana     3 (=ana)
3     0     banana     0
4     4         na     0
5     2       nana     2 (=na)
```

LCP를 구하는 방법으로 인접한 접미사끼리 문자를 비교하는 방법이 있겠지만, 오래 걸려서 PS에선 사용이 어렵다. 대신 `Kasai’s Algorithm`을 사용하면 O(N) 시간으로 LCP Array를 구할 수 있다.

`Manber-Myers Algorithm`처럼 접미사끼리 서로 겹치는 문자가 있다는 점을 활용해 중복 연산을 피한다. LCP 계산은 접미사 길이 순서대로 진행한다.
```
int r[SIZE]; // SA의 역함수
int LCP[SIZE]; // LCP 배열

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
```

## 코드
`9248 - Suffix Array` 코드
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

## 활용
LCP는 인접 접미사간 공통 접두사의 길이를 저장한다. 이 점을 활용해 한 문자열에서 2번 이상 반복되는 모든 부분 문자열을 빠르게 스캔할 수 있다.

## 관련 문제
<br>https://www.acmicpc.net/problem/9248
<br>https://www.acmicpc.net/problem/1605
<br>https://www.acmicpc.net/problem/11479

## 참고
<br>https://jason9319.tistory.com/141
<br>https://plzrun.tistory.com/entry/Suffix-Array-ONlogNlgN%EA%B3%BC-ONlogN-%EA%B5%AC%ED%98%84-%EB%B0%8F-%EC%84%A4%EB%AA%85
<br>https://www.geeksforgeeks.org/?p=137029
<br>https://en.wikipedia.org/wiki/Suffix_array
{% endraw %}