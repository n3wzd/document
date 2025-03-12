---
categories:
- Algorithm
date: '2022-03-11'
title: '[Algorithm] 백트래킹'
---

{% raw %}
##  백트래킹
컴퓨터 알고리즘 분야에서 백트래킹의 정의는 다음과 같다.
>해를 얻을 때까지 모든 가능성을 시도하는 전략

구체적으로 정리하면 다음과 같다.
> 백트래킹은 재귀를 이용한 완전 탐색 방법<br>

백트래킹에 속하는 대표적인 예시로 DFS가 있다.

##  접근
일반적으로 완전 탐색에서 답을 구하는 과정이 재귀적이면 백트래킹이 적합하다.

## 구현
현재 상태를 저장하면서 탐색하는 방법을 구현하는 방법은 여러 가지가 있다. 일반적으로 재귀 함수를 사용해서 구현한다.

![백트래킹-트리](images/백트래킹-트리.png "백트래킹-트리")

재귀에 대한 자세한 구현 방법은 재귀 함수 항목 참고.

백트래킹의 목표는 해답과 관련된 모든 가능성을 탐색하는 것이다. 하지만 해답과 관련없는 경우도 포함하여 끝까지 탐색하는 것은 해답과 관련된 가능성만 탐색하는 것에 비해 상당한 시간이 걸리며, 그에 따라 전체적인 시간 복잡도가 증가하므로 효율이 떨어진다. 따라서 백트래킹은 단순 재귀로 구현하기 보다는, **정답 가능성이 있는 방향으로 재귀를 호출해야 하며, 확실한 오답을 만나는 순간 해당 위치에서 탐색을 바로 중단하고 이전 분기점으로 돌아가는** 구조로 설계한다.

## 예시 - 순열과 조합
순열 <sub>n</sub>P<sub>r</sub>과 조합<sub>n</sub>C<sub>r</sub>의 각 모든 경우의 수열을 출력하는데 백트래킹을 사용할 수 있다.

순열: 각 수열을 출력하기 위해서는 중복 없이 순서대로 출력해야 한다. 다시 말해, 수열 상에서 중복이 포함되는 경우는 확실한 오답이므로, 이를 피하기 위한 현재 상태 정보로 수열에서 사용된 숫자 목록을 추가한다. 수열의 인덱스는 재귀 호출의 인덱스로 활용하고, 탈출 조건은 수열의 길이로 한다. 예를 들어, 길이가 3인 수열을 출력하려면 총 3번의 재귀 호출이 발생한다.

조합: 순열에서 순서를 고려하지 않는 것이 조합이다. 따라서 조합의 모든 수열은 정렬된 상태라고 볼 수 있다. 앞에 있는 숫자가 뒤에 있는 숫자보다 항상 작다는 점을 활용해 함수 내부의 반복문 처음 인덱스만 조정하면 조합을 출력할 수 있다.

순열, 조합 공통으로, 각 재귀에서 구한 해답을 어딘가 기록할 필요가 있다. 이는 전역 변수 배열을 통해 해결할 수 있다.

```
#include <iostream>
using namespace std;

int arr[8]; // assume that arr is sorted array.
int n, r;

int state[8]; // current index in recursive function -> index sequence of arr<br>
bool visited[8] = { 0, }; // current used number(index of state[8]) list. 1 - used
int start = 0;

void Print()
{
	for (int i = 0; i < r; i++)
		printf("%d ", arr[state[i]]);
	printf("\n");
}

void Permutation(int index)
{
	if (index == r) // escape condition
	{
		Print();
		return;
	}

	for (int i = 0; i < n; i++) // ascending process
	{
		if (!visited[i])
		{
			visited[i] = true;
			state[index] = i;
			Permutation(index + 1); // recursive call
			visited[i] = false;
		}
	}
}

void Combination(int index)
{
	if (index == r) // escape condition
	{
		Print();
		return;
	}

	for (int i = start; i < n; i++) // ascending process
	{
		state[index] = i;
		start = i + 1;
		Combination(index + 1); // recursive call
	}
}

int main()
{
	cout << "n, r: ";
	cin >> n >> r;<br>
	cout << "arr: ";
	for (int i = 0; i < n; i++) cin >> arr[i];<br>

	cout << "nPr" << endl;
	Permutation(0);
	cout << endl;

	cout << "nCr" << endl;
	Combination(0);
	cout << endl;	

	return 0;
}
```

## 연관 문제
https://www.acmicpc.net/problem/15649<br>
https://www.acmicpc.net/problem/15650<br>

## 참고
https://ko.wikipedia.org/wiki/%ED%87%B4%EA%B0%81%EA%B2%80%EC%83%89<br>
{% endraw %}