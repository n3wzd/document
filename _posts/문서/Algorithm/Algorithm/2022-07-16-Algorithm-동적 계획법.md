---
categories:
- Algorithm
date: '2022-07-16'
title: '[Algorithm] 동적 계획법'
---

{% raw %}
## 동적 계획법 (DP, dynamic programming)
어떤 문제를 풀기 위해 그 문제를 더 작은 문제의 연장선으로 생각하고, 과거에 구한 해를 재활용하는 알고리즘 설계 기법이다.

`분할 정복 알고리즘`을 기반으로 문제를 부분 문제로 분할하며, 부분 문제들을 계산한 결과를 기록하여 중복된 계산을 방지한다. 이렇게 부분 문제들을 1번씩만 계산하므로 속도를 향상시킨다. 메모리 공간과 실행 시간을 교환한다고 보면 된다.

## 메모이제이션 (Memoization)
동적 계획법의 핵심 기술로, 계산한 결과를 메모리 공간에 저장해 두었다가 다시 계산할 필요가 있을 때 기록한 값을 참조함으로써 중복 계산을 방지하는 기법.

메모이제이션을 구현할 때는 계산 과정에서 입력(현재 상태)에 대한 결과가 있어야 하며, 각각의 결과는 입력에 대해 일대일 대응이 되어야 한다. (함수 구조)
> cache(state) = result<br>

메모이제이션을 사용할 때는 공간 복잡도를 주의해야 한다. 입력 범위가 작다면 큰 문제는 없겠지만, 입력의 범위가 크면 메모리 제한으로 인해 모든 입력에 대한 결과를 저장하기 어렵기 때문. 이 경우는 입력의 대상을 전환하는 등 조치를 하거나, DP가 아닌 다른 방법으로 접근하는 것이 좋다.

## Top-Down vs Bottom-Up
DP의 접근 방법은 방문 순서를 기준으로 크게 2가지로 구분된다.
- Top-Down: 큰 문제부터 방문한다. 주로 재귀 함수로 구현된다. 문제 설계 이해와 구현이 쉽다는 이점이 있다.
- Bottom-Up: 작은 문제부터 방문한다. 주로 반복문으로 구현된다. 재귀 함수를 사용하지 않아 시간과 메모리 사용량이 줄어든다는 이점이 있다.

![Recursion Tree](images/외전-동적계획법-자료1.png "Recursion Tree")
두 문제의 크고 작음을 비교하는 기준은 문제의 분할이며, 분할 이전의 문제가 크고, 분할된 문제가 작다. (사진의 N은 어디까지나 인덱스의 표현으로, 문제의 크고 작음과는 관계가 없다.)

Top-Down과 Bottom-Up 어떤 것이 적합한지는 상황에 따라 다르다. 
- 일반적으로 분할정복 함수(점화식)와 구조가 비슷한 Top-Down으로 접근한다.
	- 분할되는 문제가 많다면 시간 초과나 메모리 스택 오버플로우를 대비해 Bottom-Up으로 바꾼다.
- 토글링, 점화식 입력 대상 전환 등 기법을 사용해 방문 순서를 조정해야 하는 경우는 Bottom-Up이 적합하다.
- 그래프, 트리같이 처음 정점부터 방문해야 하는 상황에선 Bottom-Up 구현이 어렵기 때문에 주로 Top-Down을 사용한다.
- 부분 문제 상태가 2차원 이상이라면 모든 부분 문제를 방문하는 Bottom-Up보다는 필요한 부분 문제만 방문하는 Top-Down이 속도 면에서 더 빠를 수 있다.
> 알고리즘, 분할정복 함수 설계는 Top-Down, 최적화 코드 구현은 Bottom-Up으로 한다.<br>

##  예시 - 피보나치 수열
### Top-Down
```
#include <iostream>
using namespace std;

int cache[10000] = { 0, };

int DP(int n)
{
	if (n == 0) return 0;
	if (n == 1) return 1;
	
	if (cache[n] != 0) return cache[n];

	cache[n] = DP(n - 1) + DP(n - 2);
	return cache[n];
}

int main()
{
	int n;
	cin >> n;
	cout << DP(n) << endl;
	return 0;
}
```
N이 큰 문제부터 방문한다는 점을 확인할 수 있다.

![DP필요성1](images/외전-동적계획법-자료2.png "DP필요성1")
만약 메모이제이션을 적용하지 않았다면 DP(N-2)을 계산하기 위해 2번 이상 재귀 호출을 할 것이다. 이렇게 연쇄적으로 호출이 발생하면 시간 복잡도가 크게 증가하게 된다.

![DP필요성2](images/외전-동적계획법-자료3.png "DP필요성2")
메모이제이션을 사용하여 중복된 계산을 방지한다.

### Bottom-Up
```
#include <iostream>
using namespace std;

int cache[10000] = { 0, };

int main()
{
	int n;
	cin >> n;

	cache[0] = 0;
	cache[1] = 1;
	for (int i = 2; i <= n; i++)
		cache[i] = cache[i - 1] + cache[i - 2];

	cout << cache[n] << endl;
	return 0;
}
```
Top-Down과 달리 N이 작은 문제부터 방문한다. 또한, 점화식 구조가 Top-Down과 비슷하다는 점을 알 수 있다. (Top-Down ↔ Bottom Up 전환 가능)

## 캐시 크기 최적화 - 토글링
만약 각각의 캐시가 한번씩만 재참조된다면, 해당 캐시는 더 이상 사용되지 않을 것이다. 따라서 더 이상 사용되지 않는 캐시를 삭제해서(=덮어씌워서), 캐시 크기를 압축할 수 있다. (=특정 캐시 인덱스를 생략할 수 있다)

토글링 기법은 캐시가 한번씩만 참조되게 기존 알고리즘을 적절히 조정해서 사용되지 않는 캐시 영역을 제외하는 기법으로, 공간 복잡도를 효과적으로 줄일 수 있다.

```
DP(i, w)
	...
	DP(i - 1, w - item[i])

=> i가 1씩 감소한다. 즉, i에 대해 현재 문제에서 이전 문제의 값만 참고하므로 토글링을 고려해볼 수 있다. 
```

토글링을 구현할 때는 이전 값만 참조해야 하므로 주로 Bottom-Up으로 구현된다.

#### 활용 예시
- 냅색 알고리즘(knapsack-problem): 들고 있는 물건의 번호 i를 생략할 수 있다. DP(i, w) => DP(w)
- 벨만-포드 알고리즘: 최단 경로에서 사용 가능한 최대 간선 개수 k를 생략할 수 있다. DP(v, k) => DP(v)

## 연관 문제
1. 분할 정복 함수(점화식) 설계
	- 입력
	- 출력 
2. Top-Down vs Bottom-Up

`분할 정복 알고리즘` 편도 참고하면 좋다.

#### DP - 기초
부분 문제의 상태가 간단한 (주로 1차원) 연습 문제.
<br>https://www.acmicpc.net/problem/2579
<br>https://www.acmicpc.net/problem/10844
<br>https://www.acmicpc.net/problem/1149
<br>https://www.acmicpc.net/problem/2156

#### DP - 중급
부분 문제의 상태가 2차원 이상인 더 어려운 문제.
<br>https://www.acmicpc.net/problem/1520
<br>https://www.acmicpc.net/problem/13392
<br>https://www.acmicpc.net/problem/2169

#### LIS
대표적인 DP 문제.
<br>https://www.acmicpc.net/problem/11053
<br>https://www.acmicpc.net/problem/2565
<br>https://www.acmicpc.net/problem/15648

#### LCS
대표적인 DP 문제 2. 2개의 탐색 대상의 현재 위치를 현재 상태로 정의한다. (`투 포인터`를 현재 상태로 사용)
<br>https://www.acmicpc.net/problem/9251
<br>https://www.acmicpc.net/problem/2618

#### 0-1 가방 문제 (Knapsack Problem)
대표적인 DP 문제 3. 아이템 번호와 수치 값(ex. 가방 한도)를 현재 상태로 활용하며, 경우의 수 시나리오(ex. 현재 들고 있는 물건을 선택 vs 포기)로 문제를 분할한다. 또한 토글링을 적용할 수 있다.
<br>https://www.acmicpc.net/problem/12865
<br>https://www.acmicpc.net/problem/2629

#### 투 포인터
처음과 끝을 `투 포인터`로 하고, 탐색 범위를 분할하는 유형.
<br>https://www.acmicpc.net/problem/11066
<br>https://www.acmicpc.net/problem/11049
<br>https://www.acmicpc.net/problem/10942

#### 메모리 제한
공간 복잡도를 고려하는 문제. 토글링, 점화식 입력 대상 전환 등 기법이 필요하다. 이러한 상황에서는 Bottom-Up이 적합하다.
<br>https://www.acmicpc.net/problem/2293
<br>https://www.acmicpc.net/problem/7579
<br>https://www.acmicpc.net/problem/5977 - 필수는 아니지만 토글링을 적용할 수 있다

#### 비트마스크 적용
`비트마스크`를 사용해 boolean 배열을 정수 하나로 바꿀 수 있다.
<br>https://www.acmicpc.net/problem/2098
<br>https://www.acmicpc.net/problem/1311
<br>https://www.acmicpc.net/problem/1648
<br>https://www.acmicpc.net/problem/1086

#### 슬라이딩 윈도우 최적화
`덱`을 사용해서 O(N) 시간으로 슬라이딩 윈도우 최대/소를 찾는 문제
<br>https://www.acmicpc.net/problem/5977
<br>https://www.acmicpc.net/problem/15678

## 참고
<br>https://semaph.tistory.com/16
<br>https://namu.wiki/w/%EB%A9%94%EB%AA%A8%EC%9D%B4%EC%A0%9C%EC%9D%B4%EC%85%98
<br>https://namu.wiki/w/%EB%8F%99%EC%A0%81%20%EA%B3%84%ED%9A%8D%EB%B2%95
{% endraw %}