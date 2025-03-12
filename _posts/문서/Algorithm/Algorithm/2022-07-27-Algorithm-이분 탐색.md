---
categories:
- Algorithm
date: '2022-07-27'
title: '[Algorithm] 이분 탐색'
---

{% raw %}
##  이분 탐색
이분 탐색(Binary Search)은 정렬된 배열에서 특정 원소를 탐색하는 방법이다. 현재 위치와 비교해서 값이 크면 오른쪽, 아니면 왼쪽을 탐색하는 원리로 검색 범위를 줄여 나가면서 원하는 데이터를 검색하는 알고리즘이다.

처음부터 끝까지 단순 탐색할 때는 O(N) 시간이 걸리지만, 이분 탐색을 사용하면 시간을 O(log N)으로 단축할 수 있어 훨씬 빠르게 탐색할 수 있다. 단, 이분 탐색을 사용하려면 **탐색할 배열이 정렬되어 있어야 한다**는 점을 주의하자.

## 구현
배열의 처음과 끝, 그리고 중간을 저장하는 변수를 생성하자. 그리고 반복문을 돌린다. 원하는 값을 찾았다면 탐색을 종료하고, 찾지 못했다면 처음과 끝을 조절한다.
```
start = 0;
end = v.size - 1;
mid = 0;

while (start <= end)
{
	mid = (start + end) / 2;					// 탐색 범위가 절반씩 감소한다
	if(v[mid] == target) return true			// 목표 값 발견
	if(v[mid] < target) start = mid + 1			// mid에 1을 더해서 탐색에 배제
	if(v[mid] > target) end = mid - 1			// mid에 1을 빼서 탐색에 배제
}
return false;
```
만약 처음이 끝보다 큰 상황이면 더 이상 탐색할 수 없으므로 탐색이 종료된다. 이때까지 목표 값을 찾지 못했다면, 해당 배열에는 목표 값이 없는 것으로 판단한다.

## 매개변수 탐색(Parametric Search)
매개변수 탐색은 이진 탐색 알고리즘을 응용해서 목표 값을 O(log N) 시간 내에 찾는 알고리즘이다. 일일이 탐색하는 것(O(N))보다 훨씬 빠른 속도를 보장한다.

매개변수 탐색을 적용하기 위해서는...
1. x는 정렬되어 있다.
2. F(x)는 단조증가/단조감소 함수다. 

이잔 탐색의 기본 원리는 어떤 한 지점을 정하고 조사했을 때, 한쪽을 탐색에서 완전히 배제하는 것이다. 탐색에서 제외했다는 것은 확실하게 조사 범위에 벗어났다는 것을 의미한다.

아래 정렬된 수열에서 y가 4보다 같거나 큰 값에서 최소 x를 찾아보자.
> x - 1 2 3 4 5 6 7 8 9<br>
> y - 1 2 2 3 3 4 4 5 5<br>

만약 x = 5를 택했다면, y = 3이다. 3는 4보다 작으므로 목표 값은 선택한 위치에서 오른쪽에 있다고 확신할 수 있다. 이 추정을 확신할 수 있는 이유는 y가 x에 대해 단조증가하기 때문이다. 만약 y가 단조증가/단조감소하지 않다면 아래와 같이 3의 왼쪽, 오른쪽에 모두 4가 존재할 수 있다. 즉, 탐색 방향을 정할 수 없어 이진 탐색을 적용할 수 없다!
> x - 1 2 3 4 5 6 7 8 9<br>
> y - 1 4 4 3 3 4 4 5 5 ??<br>

다시 원래대로 와서 이번에는 x = 7을 선택해보자. y = 4이므로 조건을 만족하였다. 그러나 최종 목표는 "조건을 만족한 상태에서 최소 x"이므로 아직 해답까지 확신할 수 없다. 해답을 확정짓기 위해서는 탐색 범위가 1이어야 한다. 현재는 (5, 7]이므로 아직 탐색을 계속 진행한다. x = 7에서 오른쪽은 반드시 조건을 만족한다고 생각할 수 있으므로 이번에는 왼쪽을 선택한다.

x = 6으로 이동한다. y = 4이므로 조건을 만족한다. 탐색 범위의 길이가 1이 되었으므로 탐색이 종료된다. 최종 해답은 6.

#### 구현 - 왼쪽이 조건에 맞는 경우
이분 탐색 자체는 출력이 true/false인 것과 달리, 매개변수 탐색은 출력이 특정 값이라는 점에서 차이가 있다. 따라서 구현 코드도 살짝 다르다.
```
start = min(x);
end = max(x);
mid = 0;

while (start < end)
	mid = ceil((start + end) / 2);
	if (Checker(mid)) start = mid;
	else end = mid - 1;
return end;
```
시작, 끝 범위는 x의 범위다. 현재 조건(Checker)에 맞으면 오른쪽을 탐색한다. 이때 현재 위치를 탐색 범위에 포함한다. (현재 위치가 해답의 후보가 될 수 있기 때문) 따라서 start = mid이다. 만약 조건에 맞지 않으면 왼쪽을 탐색한다. 동시에 현재 위치를 탐색 범위에서 제외한다. 탐색하는 값은 x의 전범위이며, 최종 출력 값은 조건을 만족하는 최소 x다.

조건은 각 문제마다 다르다. 상황에 맞게 설계해보자.

#### 구현 - 오른쪽이 조건에 맞는 경우
```
start = min(x);
end = max(x);
mid = 0;

while (start < end)
	mid = (start + end) / 2;
	if (Checker(mid)) end = mid;
	else start = mid + 1;
return end;
```
현재 조건(Checker)에 맞으면 왼쪽을 탐색한다. 이때 현재 위치를 탐색 범위에 포함한다. 따라서 end = mid이다. 최종 출력 값은 조건을 만족하는 최대 x다.

#### 짝수에서 왼쪽 vs 오른쪽 ???
탐색 범위의 길이가 홀수인 경우는 가운데를 선택하면 된다. 하지만 짝수인 경우는 가운데가 2개다. 잘못 선택하면 무한루프나 처음, 끝이 역전되는 현상이 발생할 수 있다! 그러면 어느 쪽을 선택해야 할까?
> [199, 200]<br>
> 199 vs 200 ???<br>

직접 실험해서 확인해보자.
```
199 200, mid = 199
if Checker(mid) = TRUE
start = mid => 199 200 (loop ???)
end = mid => 199 199

if Checker(mid) = FALSE
end = mid - 1 => 199 198 ???
start = mid + 1=> 200 200


199 200, mid = 200
if Checker(mid) = TRUE
start = mid => 200 200
end = mid => 199 200 (loop ???)

if Checker(mid) = FALSE
end = mid - 1 => 199 199
start = mid + 1=> 201 200 ???
```

end = mid일 때는 왼쪽, start = mid일 때는 오른쪽을 선택하면 된다.

## LowerBound & UpperBound
LowerBound는 키 값 이상이 배열에서 처음 나오는 위치를 찾는 과정이고, UpperBound는 키 값 초과가 배열에서 처음 나오는 위치를 찾는 과정이다. 아래 배열에서 3의 LowerBound는 3이며, UpperBound는 6이다.
> 1 2 2 **3** 3 3 **4** 4 4 4<br>

LowerBound와 UpperBound는 매개변수 탐색으로 구현할 수 있다.

**LowerBound**
```
while(end - start > 0)
	mid = (start + end) / 2
	if(v[mid] < target) start = mid + 1
	if(v[mid] >= target) end = mid
return end
```
만약 현재 값이 키 값보다 같거나 크면 끝을 중간과 같게 한다. (=탐색 경계에 포함) 그렇지 않다면 시작에 중간+1을 대입한다. 이 과정을 반복하면 키 값 이상이 배열에서 처음 나오는 위치로 수렴한다. 만약 시작과 끝이 같아 탐색 경계의 길이가 0이 되면 그 위치가 목표한 위치이므로 탐색이 종료된다.

**UpperBound**
```
while(end - start > 0)
	mid = (start + end) / 2
	if(v[mid] <= target) start = mid + 1
	if(v[mid] > target) end = mid
return end
```
 LowerBound와 비슷하지만 조건이 >=에서 >으로 되었다. 초과인 값만 탐색 경계에 포함하므로, 반복할수록 키 값 초과가 배열에서 처음 나오는 위치로 수렴한다.

## 코드
```
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
int target;

bool BinarySearch()
{
	int start = 0;
	int end = v.size() - 1;
	int mid;

	while (start <= end)
	{
		mid = (start + end) / 2;
		if (v[mid] == target) return true;
		else if (v[mid] < target) start = mid + 1;
		else if (v[mid] > target) end = mid - 1;
	}

	return false;
}

int LowerBound()
{
	int start = 0;
	int end = v.size() - 1;
	int mid = 0;

	while (start < end)
	{
		mid = (start + end) / 2;
		if (v[mid] < target) start = mid + 1;
		else end = mid;
	}

	return end;
}

int UpperBound()
{
	int start = 0;
	int end = v.size() - 1;
	int mid = 0;

	while (start < end)
	{
		mid = (start + end) / 2;
		if (v[mid] <= target) start = mid + 1;
		else end = mid;
	}

	return end;
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());

	cin >> target;
	cout << BinarySearch() << endl;
	cout << LowerBound() << endl;
	cout << UpperBound() << endl;
	return 0;
}
```

## STL
C++의 algorithm.h에선 이분 탐색과 관련된 함수를 제공한다.
- `binary_search(arr_start, arr_end, key)` -  이분 탐색 결과를 반환한다.
- `lower_bound(arr_start, arr_end, key)` -  lowerbound 결과를 반환한다.
- `upper_bound(arr_start, arr_end, key)` -  upperbound 결과를 반환한다.

또한 `set`, `map`, `multimap`에서도 전용 lower_bound, upper_bound 메소드를 제공한다.

## 연관 문제
<br>https://www.acmicpc.net/problem/1920
<br>https://www.acmicpc.net/problem/10816
<br>https://www.acmicpc.net/problem/1654
<br>https://www.acmicpc.net/problem/1300
<br>https://www.acmicpc.net/problem/17951
<br>https://www.acmicpc.net/problem/1202

## 참고
<br>https://satisfactoryplace.tistory.com/39
<br>https://namu.wiki/w/%EC%9D%B4%EC%A7%84%20%ED%83%90%EC%83%89
<br>https://blog.naver.com/bestmaker0290/220820005454
<br>https://chanhuiseok.github.io/posts/algo-55/
{% endraw %}