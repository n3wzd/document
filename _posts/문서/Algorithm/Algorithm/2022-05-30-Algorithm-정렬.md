---
categories:
- Algorithm
date: '2022-05-30'
title: '[Algorithm] 정렬'
---

{% raw %}
## 정렬
임의의 데이터 목록을 정해진 순서대로 나열하는 문제.

여러 정렬 알고리즘이 존재하며, 이 중 평균 속도가 빠른 방법인 합병 정렬, 힙 정렬, 퀵 정렬의 평균 시간 복잡도는 O(N log N)이다. 따라서 일반적인 정렬의 시간 복잡도는 `O(N log N)`으로 볼 수 있다.

정렬의 주 용도는 바로 탐색. 정렬을 하면 해결이 쉬워지는 문제도 있고, `이분 탐색` 알고리즘을 사용하기 위해서는 탐색 대상 목록이 정렬되어 있어야 한다.

정렬했을 때, 정렬 기준이 동일한 원소들은 정렬 이전의 순서가 바뀌지 않는 정렬을 `안정 정렬(stable sort)`이라고 한다. 안정 정렬을 하면 중복된 값의 입력 순서가 유지된다는 이점이 있다.

## STL
C++ algorithm.h에서 정렬 함수를 제공한다.
- `sort(arr, arr + n)`
배열 arr의 처음부터 n - 1까지 원소를 오름차순으로 정렬한다. n을 arr의 길이로 하면 배열 전체를 정렬한다.
- `sort(arr, arr + n, cmp)`
정렬 기준을 cmp 비교 함수로 한다.
- `stable_sort(arr, arr + n)`
안정 정렬을 수행한다. 사용법은 위의 sort 함수와 동일.

비교 함수를 사용하면 다양한 비교 기준을 커스터마이징할 수 있다. sort에서 비교 함수는 다음과 같은 형식을 만족해야 한다. 
- 반환 값이 true면, a는 b의 앞쪽에 배치된다. (= a가 먼저 배치된다)
- 반환 값은 인자 a, b 순서를 바꾸면 항상 달라져야 한다. 예를 들어 3, 5을 입력했을 때 true를 반환했다면, 5, 3을 입력했을 때 false를 반환해야 한다.
```
bool cmp(int a, int b)		// 함수, 인자 이름은 아무거나 해도 상관없음
{
	return a < b;
}
```
위의 예시를 적용하면 오름차순 정렬이 수행된다. 만약 a > b이라면, 내림차순 정렬이 된다.<br>

Tip. greater<자료형>(), less<자료형>()
cmp 위치에 greater, less 객체를 줄 수 있다. 전자는 내림차순, 후자는 오름차순이다.
- `sort(arr, arr + n, greater<type>())` - 내림차순 수행
- `sort(arr, arr + n, less<type>())` - 오름차순 수행 (인자를 제공하지 않은 디폴트 정렬과 동일하므로 생략 가능)

### 코드
- first 오름차순
- first가 동일하면, second 오름차순
```
#include <iostream>
#include <algorithm>
using namespace std;

int n;
pair<int, int> arr[100002];<br>

bool cmp(pair<int, int> a, pair<int, int> b) {<br>
	if (a.first != b.first) return a.first < b.first;
	else return a.second < b.second;
}

int main()
{
	cin >> n;<br>
	for (int i = 0; i < n; i++)
		scanf("%d%d", &arr[i].first, &arr[i].second);
	sort(arr, arr + n, cmp);
	for (int i = 0; i < n; i++)
		printf("%d %d\n", arr[i].first, arr[i].second);
	return 0;
}
```

### 연관 문제
https://www.acmicpc.net/problem/2751
https://www.acmicpc.net/problem/11650
https://www.acmicpc.net/problem/1517

## 카운팅 정렬
카운팅 정렬은 원소의 값을 인덱스로 하고, 해당 원소의 출현 횟수를 값으로 하는 배열을 사용해서 정렬하는 방법이다.

입력 값이 정수이며, 입력 최대 크기 K가 비교적 작다면 `카운팅 정렬`을 고려할 수 있다. 시간 복잡도는 `O(N + K)`이다.

```
< 초기화 >
- 카운팅을 저장하는 배열 생성 및 초기화
	- 인덱스 = 원소 값
	- 값 = 해당 원소의 출현 횟수

< 추가 & 삭제 >
- 원소 X 추가: X 위치에 1을 더한다.
- 원소 X 삭제: X 위치에 1을 뺀다.

< 출력 >
- 정렬 순서대로 원소를 순차 탐색하며, 중복 개수만큼 원소를 출력한다.
	- ex. 오름차순이면 원소가 증가하는 순으로 탐색한다.
```

카운팅 정렬의 장점은 원소의 추가/삭제가 빠르며, K번째 원소의 위치를 알 수 있다는 점이다. 타 정렬은 원소가 추가되면 새로 정렬을 해야 하지만, 카운팅 정렬은 추가적인 정렬을 하지 않아도 된다. `우선순위 큐`는 원소 입출력에 대응할 수 있으나, K번째 원소 위치를 알 수 없다.

그러나 카운팅 정렬에서 선형 탐색이 오래 걸린다는 문제가 있다. 이 문제는 구간 원소 출현 횟수를 기록하는 `세그먼트 트리`를 동원하면 해결할 수 있다.

### 코드
```
#include <iostream>
using namespace std;
# define NUM_MAX 10000

int n;
int cnt[10002] = { 0, };

int main()
{
	cin >> n;<br>
	for (int i = 0; i < n; i++)
	{
		int num;
		scanf("%d", &num);
		cnt[num]++;
	}
	
	for (int i = 1; i <= NUM_MAX; i++)
		for (int c = 0; c < cnt[i]; c++)
			printf("%d\n", i);
	
	return 0;
}
```

### 연관 문제
https://www.acmicpc.net/problem/10989
https://www.acmicpc.net/problem/12899

## 참고
https://namu.wiki/w/%EC%A0%95%EB%A0%AC%20%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98
{% endraw %}