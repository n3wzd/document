---
categories:
- Algorithm
date: '2022-05-24'
title: '[Algorithm] KMP 알고리즘'
---

{% raw %}
## 문자열 패턴
어떤 입력 문자열에서 특정 문자열 패턴을 찾는 방법은 무엇일까? 일단, 간단하게 일일이 비교하는 나이브한 방법이 있다.
```
T = ABDABCDC (길이 N)
P = ABC (길이 M)

P를 T에서 일일이 비교해보자.
begin = 0
ABDABCDC
|||
ABC

begin = 1
ABDABCDC
 |||
 ABC

...

begin = 3
ABDABCDC
   |||
   ABC
=> Find!<br>
```
위의 일반적인 선형 탐색은 간단하고 구현이 편리하지만, O(NM) 시간으로 대체로 느리다!

여기서 KMP 알고리즘을 사용하면 훨씬 빠른 시간 O(N + M) 내에 문자열 패턴을 검색할 수 있다.

## KMP 알고리즘
앞선 선형 탐색에서 다음과 같은 정보를 찾을 수 있다.
```
ABCDEQWERTY
||||||
ABCDEF
=> ABCDE까지 일치<br>
```
KMP 알고리즘의 포인트는 **부분 일치 정보**를 활용하여 불필요한 비교 횟수를 줄이는 것이다.

패턴을 1칸씩 옮겨보자. 입력 문자열을 고정한 상태에서 패턴만 이동하므로, 일치했던 부분이 다음 탐색에선 항상 일치하지 않는다는 점을 알 수 있다.
```
ABCDE
 ||||
 ABCDEF

ABCDE
  |||
  ABCDEF

...

ABCDE
    |
    A
```
만약 패턴 비교를 하고 길이 L만큼 부분 문자열이 일치했다면, L만큼 평행이동을 해서 비교를 패스할 수 있고, 시간을 단축할 수 있다! => L만큼 이동  <br>

하지만 항상 L만큼 넘길 수 없다. 다음과 같이 부분 일치 문자열에서 처음과 끝이 동일한 경우를 고려해야 한다.
```
ABACCABACCABAEEABA
|||||||||
ABACCABAE
=> ABACCABA까지 일치<br>
=> 양끝이 ABA (길이 C)<br>
```
패턴을 1칸씩 이동한다면, 입력 문자열의 [5, 7] 위치와 패턴 문자열의 [0, 2] 부분에서 처음으로 일치가 발생하는 점을 확인할 수 있다. 따라서 이 경우는 처음과 끝이 일치하는 부분까지, 즉 L - C만큼 평행이동을 하면 된다. 여기서 문자 비교일 경우, 처음과 끝은 일치한다는 점을 이미 알고 있으므로 추가로 C만큼 비교를 건너뛸 수 있다. => 패턴 문자열 위치는 (L - C), 문자 비교는 L만큼 이동<br>
```
ABACCABA(C)CABAEEABA
     |||||||||
     ABA(C)CABAE
=> Find!<br>
```
만약 이 효율적인 아이디어를 적용하기 위해서는 패턴의 부분 문자열에 대한 접두사, 접미사의 최대 길이를 먼저 알고 있어야 한다.

이를 정리하면, KMP 알고리즘에 필요한 요소는 다음과 같다.

> 패턴 비교를 수행했을 때, 부분 일치 문자열의 길이, 이 문자열에서 일치하는 접두사, 접미사의 최대 길이에 대해 비교 탐색을 건너 뛸 수 있다.<br>

> 건너 뛰는 거리를 계산하기 위해, 패턴의 각 부분 문자열에서 일치하는 접두사, 접미사의 최대 길이가 필요하다.<br>

### 접두사 == 접미사
우선, KMP 알고리즘에서 사용되는 접두사, 접미사는 다음과 같다.
```
접두사 = 원본 문자열의 처음에서 시작하는 부분 문자열
접미사 = 원본 문자열의 끝에서 끝나는 부분 문자열
※ 접두사, 접미사는 항상 입력 문자열의 길이보다 작다.

ex. ABABB
접두사 = A, AB, ABA, ABAB
접미사 = B, BB, ABB, BABB
```

접두사, 접미사 정보를 저장하는 배열, pi를 다음과 같이 정의한다.
```
pi[M]
- 인덱스 = 패턴 P에서 0부터 시작하는 부분 문자열의 길이에서 1을 뺀 값
	→ 부분 문자열 [0, i]
- 값 = 해당 부분 문자열에서 일치하는 접두사, 접미사의 최대 길이

※ 접두사, 접미사의 정의에 따라, 입력 문자열과 관계없이 항상 다음이 성립
pi[0] = 0
pi[i] 최댓값 = i

ex. P = ABAABAB
부분 문자열    i   pi[i]
A            0     0
AB           1     0
ABA          2     1
ABAA         3     1
ABAAB        4     2
ABAABA       5     3
ABAABAB      6     2
```

pi 배열을 구하는 방법으로 일일이 접두사/접미사를 비교 탐색하는 나이브한 방법이 있으며, O(M<sup>2</sup>) 시간이 걸린다. 그러나 pi 배열을 구하는 방법에 KMP 알고리즘을 적용하여 최적화를 하는 방법이 있다! 이 방법으로 하면 O(M) 시간으로 단축할 수 있다. (이 방법에 대해서는 후술)

### KMP 알고리즘
이제 아이디어를 바탕으로 KMP 알고리즘을 구현해보자.
```
T // 입력 문자열
P // 패턴 문자열
begin = 0 // 현재 탐색 위치 (= 부분 문자열[0] 위치)
window = 0 // 일치하는 부분 문자열의 길이

1. 문자에 대해 비교 탐색 수행 => T[begin + window] == P[window]<br>
	- 중간에 문자가 일치하지 않거나, 패턴이 완전 일치할 때까지 진행
	- 만약 완전 일치한다면, 현재 위치를 검색 결과에 기록한다.
2. 비교 시작점을 옮긴다.
	- window > 0이면,<br>
		- begin += L - pi[window - 1]
		- window = pi[window - 1]
	- 그렇지 않으면, 
		- begin += 1
```

```
pi[M] // pi 배열
T_len = T.size // 입력 문자열 길이
P_len = P.size // 패턴 문자열 길이
search // 찾은 위치를 저장하는 동적 배열

KMP()
	while (begin <= T_len - P_len)
		// 불일치하는 문자를 찾을 때까지 문자 비교 탐색 수행
		if (T[begin + window] == P[window] && window < P_len)
			window++;
			if (window == P_len) // 패턴 찾기 성공
				search.add(begin)
		else
			// 비교 시작점 옮기기
			if (window > 0)<br>
				begin += window - pi[window - 1]
				window = pi[window - 1]
				// 이 과정을 거쳐도 begin + window는 보존된다.
			else
				begin++
```

### pi 배열 구현
마지막으로, pi 배열을 O(M) 시간 내에 구해보자. 일치하는 접두사, 접미사를 찾는 것도 문자열에서 패턴을 찾는 것이므로 KMP 알고리즘을 적용할 수 있다.
```
< pi 배열에서 KMP 알고리즘의 입력 >
입력 문자열 = P
패턴 문자열 = P
처음 비교 시작 위치 = 1
```

pi 배열을 활용하는 부분은 이전 탐색에서 구했던 pi 배열 기록을 활용하면 된다. (DP와 유사한 원리)
```
P // 패턴 문자열
pi[M] // pi 배열
len = P.size // 패턴 문자열 길이
begin = 1 // 탐색 위치 (= 부분 문자열[0] 위치)
window = 0 // 일치하는 부분 문자열의 길이 = 일치하는 접두사/접미사 최대 길이
// pi 배열에서 기록 인덱스로 begin + window를 사용한다.

PI_Setting()
	while (begin < len)
		if (P[begin + window] == P[window])
			window++
			pi[begin + window - 1] = window // pi 배열 기록
		else
			if (window > 0)<br>
				// 이전 탐색에서 구했던 pi 데이터 활용
				begin += window - pi[window - 1]
				window = pi[window - 1]
			else
				begin++
```
```
ex. window = 5
begin  0  1  2  3  4  5  6  7
pi     0  0  1  2  3  4  5  
P      A  B  A  B  A  B  A  C
P            A  B  A  B  A  B  A  C

pi[5 - 1] = 3
begin += 5 - 3 // 2칸 건너뛴다
window = 3
begin  0  1  2  3  4  5  6  7
pi     0  0  1  2  3  4  5  
P      A  B  A  B  A  B  A  C
P                  A  B  A  B  A  B  A  C
```

위의 pi 배열을 구하는 함수를 `실패 함수(Failure Function)`라고도 한다.

## 코드
※ `BOJ - 1786 - 찾기` 코드하고 동일
```
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string T, P;
int pi[1000001];
vector<int> search;<br>

void PI_Setting()
{
	int len = P.size();
	int begin = 1, window = 0;

	while (begin < len) {
		if (P[begin + window] == P[window]) {
			window++;
			pi[begin + window - 1] = window;
		}
		else {
			if (window > 0) {<br>
				begin += window - pi[window - 1];
				window = pi[window - 1];
			}
			else begin++;
		}
	}
}

void KMP()
{
	int T_len = T.size(), P_len = P.size();
	int begin = 0, window = 0;
	PI_Setting();

	while (begin <= T_len - P_len) {
		if (T[begin + window] == P[window] && window < P_len) {
			window++;
			if (window == P_len)
				search.push_back(begin);
		}
		else {
			if (window > 0) {<br>
				begin += window - pi[window - 1];
				window = pi[window - 1];
			}
			else begin++;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	getline(cin, T);
	getline(cin, P);
	KMP();

	int len = search.size();
	cout << len << "\n";
	for (int i = 0; i < len; i++)
		cout << search[i] + 1 << " ";
	return 0;
}
```

## 관련 문제
https://www.acmicpc.net/problem/1786

## 참고
https://injae-kim.github.io/dev/2020/07/23/all-about-kmp-algorithm.html
https://bowbowbow.tistory.com/6
{% endraw %}