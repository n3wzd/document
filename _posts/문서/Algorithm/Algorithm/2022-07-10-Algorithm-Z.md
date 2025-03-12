---
categories:
- Algorithm
date: '2022-07-10'
title: '[Algorithm] Z'
---

{% raw %}
## Z algorithm
`Z Algorithm`는 입력 문자열 S와 접미사의 공통 접두사의 최대 길이를 O(N) 시간으로 구하는 알고리즘이다. (약칭이 아니라 알고리즘 이름 자체가 'Z' 맞다)
```
ex.
i | 0 1 2 3 4 5 6
S | B A N B B A Z
Z | 7 0 0 1 2 0 0

"BANBBAZ", "BAZ"의 공통 접두사 최대 길이는 2이므로 Z[4] = 2이다.
```

## 설계
Z 알고리즘의 output은 Z 배열(Z array)이다.
```
z[SIZE]
- 인덱스: 접미사 시작점 (= 부분 문자열[i, n))
- 값: S, 접미사의 공통 최대 접두사 길이

부분 문자열 [L, R]
- 현재 접두사와 일치하는 최대 구간
- 초기값은 L = R = 0
```

S의 인덱스( = i)를 순차 탐색해서 Z 배열을 채워보자. 우선 i = 0일 때는 S = 접미사이므로 Z[0]는  항상 S의 길이다.

i = 1부터는 크게 2가지 케이스로 나눌 수 있다.

**Case 1. i > R**<br>
i가 [L, R] 오른쪽 바깥에 있는 경우로, 새로 검사를 시작해야 한다. L = R = i로 하고 공통 접두사를 순차적으로 검색해서 찾으면 된다.
```
case 1. [  ]  i
ABABAE...  ABABABX
           i    
ABABAE...  ABABABX
           L   R
Z[i] = 5
```

**Case 2. i ≤ R**
i가 [L, R] 내부에 있는 경우다. k = i - L로 정의하자. k에 대해 케이스가 다시 나뉜다.

**Case 2-1. Z[k] < R - i + 1**
[L, R]이 확장될 수 없는 경우다. S[i, R]하고 S[k, R - L]는 동일하므로, Z[i]와 Z[k] 역시 동일하다. 따라서 Z[i]에 Z[k]를 대입하면 된다.
```
case 2. [ i ]
2-1
ABABAE...  ABABABX
 k         Li  R
Z[k] = 0
R - i + 1 = 4
=> Z[i] = Z[k] = 0<br>
```

**Case 2-2. Z[k] ≥ R - i + 1**
[L, R]이 확장될 수 있는 경우다. case 1처럼 공통 접두사를 새로 계산해야 한다.
```
case 2. [ i ]
2-2
ABABAE...  ABABABX
  k        L i R
Z[k] = 3
R - i + 1 = 3

ABABAE...  ABABABX
  k        L i  R
=> Z[i] = 4<br>
```

## 코드
```
#include <iostream>
#include <cstring>
using namespace std;
const int SIZE = 1000001;
int z[SIZE];

void Z(const char* s) {
	int L = 0, R = 0, n = strlen(s);
	for (int i = 1; i < n; i++) {
		if (i > R) {<br>
			L = R = i;
			while (R < n && s[R - L] == s[R])
				R++;
			z[i] = R - L;
			R--;
		}
		else {
			int k = i - L;
			if (z[k] < R - i + 1)
				z[i] = z[k];
			else {
				L = i;
				while (R < n && s[R - L] == s[R])
					R++;
				z[i] = R - L;
				R--;
			}
		}
	}
	z[0] = n;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string s;
	cin >> s;<br>
	Z(s.c_str());

	int size = s.size();
	for (int i = 0; i < size; i++)
		cout << z[i] << " ";
	return 0;
}
```

## 관련 문제
https://www.acmicpc.net/problem/13713<br>
https://www.acmicpc.net/problem/16229<br>

## 참고
https://www.geeksforgeeks.org/z-algorithm-linear-time-pattern-searching-algorithm/<br>
https://anz1217.tistory.com/66<br>
{% endraw %}