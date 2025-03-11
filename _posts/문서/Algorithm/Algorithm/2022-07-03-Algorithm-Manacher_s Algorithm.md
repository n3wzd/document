---
categories:
- Algorithm
date: '2022-07-03'
title: '[Algorithm] Manacher_s Algorithm'
---

{% raw %}
## Manacher's Algorithm
팰린드롬(Palindrome, 회문)은 거꾸로 읽어도 동일한, 즉 중심을 기준으로 대칭인 문자열이다. 예를 들어 "ABCBA", "123321", "ZZZ"는 팰린드롬이지만, "ABCB", "1431"는 팰린드롬이 아니다.

`Manacher 알고리즘`은 부분 문자열의 팰린드롬 판정을 O(N) 시간으로 빠르게 처리하는 팰린드롬 특화 알고리즘이다. (N = 전체 문자열 길이)

## 설계
Manacher 알고리즘의 output은 배열 A[i]이다.
```
A[i]
인덱스 = 문자 위치
값 = i번 문자를 중심으로 하는 가장 긴 팰린드롬의 반지름 길이
```

예를 들어 "bananacana"에 대한 A[i]는 다음과 같다.
```
S = b  a  n  a  n  a  c  a  n  a
i = 0  1  2  3  4  5  6  7  8  9
A = 0  0  1  2  1  0  3  0  1  0
```
A[3]은 "an**a**na", A[6]은 "ana**c**ana"이 최대 팰린드롬이다. 정리하면 중심이 i인 부분 문자열에 대해 [i - A[i], i + A[i]]는 최대 팰린드롬이고, 그보다 넓은 범위는 팰린드롬이 아니다.

배열 A는 중심 문자를 기준으로 정의되기 때문에 짝수 길이의 팰린드롬은 판정할 수 없다는 문제가 있다. 예를 들어 팰린드롬인 "noon"의 A는 [0, 0, 0, 0]이다. 이를 해결하기 위해 Manacher를 돌리기 전에는 모든 문자의 양옆 위치에 임시문자를 1개씩 추가해준다. 임시문자를 추가했을 때 변경되는 점은 다음과 같다.
- 짝수 길이의 팰린드롬도 판별할 수 있다. 예를 들어 "#n#o#o#n#"의 A는 [0, 1, 0, 1, 4, 1, 0, 1, 0]이다.
- A의 값은 원본 문자열의 팰린드롬 길이하고 동일하다.
- i의 시작이 0일 때, 원본 문자열에서 i번 위치의 문자는 임시문자 추가된 문자열에선 (i × 2) + 1번 위치에 있다.

이제 A[i]를 구하는 Manacher 알고리즘을 구현해보자.
```
S = 입력 문자열
maxR = 현재 팰린드롬 중에서 오른쪽 끝의 최대 => i + A[i]의 최대<br>
cen = maxR에 해당되는 팰린드롬의 중심
N = S의 길이

void Manachers(string S)
	int maxR = 0, cen = 0, N = S.size();
	for (int i = 0; i < N; i++) {
		// 1. A[i]의 시작점을 찾는다. (항상 0부터 시작하지 않으므로 계산이 빨라진다)
		if (maxR - i >= 0 && 2 * cen - i >= 0)
			A[i] = min(A[2 * cen - i], maxR - i);

		// 2. A[i]를 구한다. (대칭 비교를 통해 최대 반지름을 구함)
		while (i - (A[i] + 1) >= 0 && i + A[i] + 1 < N && S[i - (A[i] + 1)] == S[i + A[i] + 1])
			A[i]++;

		// 3. maxR을 업데이트한다.
		if (maxR < i + A[i]) {
			maxR = i + A[i];
			cen = i;
		}
	}
}
```

## 코드
`13275 - 가장 긴 팰린드롬 부분 문자열` 코드
```
#include <iostream>
using namespace std;
const int SIZE = 100002;
int A[SIZE * 2];

string MakePalin(string str) {
	int len = str.size();
	string S;
	for (int i = 0; i < len; i++) {
		S += "#";
		S += str[i];
	}
	S += "#";
	return S;
}

void Manachers(string S) {
	int maxR = 0, cen = 0, N = S.size();
	for (int i = 0; i < N; i++) {
		if (maxR - i >= 0 && 2 * cen - i >= 0)
			A[i] = min(A[2 * cen - i], maxR - i);

		while (i - (A[i] + 1) >= 0 && i + A[i] + 1 < N && S[i - (A[i] + 1)] == S[i + A[i] + 1])
			A[i]++;

		if (maxR < i + A[i]) {
			maxR = i + A[i];
			cen = i;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string input, s;
	cin >> input;<br>
	s = MakePalin(input);
	Manachers(s);

	int len = s.size(), pal = 1;
	for (int i = 0; i < len; i++)
		pal = max(pal, A[i]);
	cout << pal;
	return 0;
}
```

## 관련 문제
https://www.acmicpc.net/problem/13275
https://www.acmicpc.net/problem/11046

## 참고
https://www.crocus.co.kr/1075
https://www.scaler.com/topics/data-structures/manachers-algorithm/
{% endraw %}