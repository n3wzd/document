---
categories:
- Algorithm
date: '2022-06-13'
title: '[Algorithm] 좌표 압축'
---

{% raw %}
## 좌표 압축
`좌표 압축`은 수의 대소를 기준으로 새롭게 번호를 부여하는 과정이다.

수의 값하고 무관하게 값의 대소만 필요한 상황에서 좌표 압축이 활용된다. 수의 개수보다 수의 값의 범위가 훨씬 넓은 상황이라면, 좌표 압축을 활용해서 수의 값 범위를 수의 개수와 비슷하게 맞출 수 있다.

수의 개수가 N일 때, 압축된 좌표의 값은 [0, N-1] 범위에 속한다. 정렬했을 때 이웃간 압축 값의 차이는 0, 1이며, 중복 원소일 경우, 동일한 압축 값을 갖는다.
```
N = 5
-10 2 4 4 90
0 1 2 2 3
```

## 구현
`정렬`과 `이분 탐색`을 사용한다. `lower_bound`를 정렬된 배열에 사용해서 새로운 번호를 찾으면 된다. 총 시간은 O(N log N).

```
1. 배열 A, B 입력
2. B를 오름차순 정렬한다.
3. B에서 중복 원소를 제거한다.
4. 배열 A를 순서대로 탐색한다. => 현재 인덱스 = i<br>
	- A[i]의 새 번호 = B.lower_bound(A[i])
```

C++에서는 STL 자료구조 `vector`를 사용하면 빠르게 구현할 수 있다.

## 코드
`BOJ - 18870 - 좌표 압축` 코드
```
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, num;
vector<int> A, B;<br>

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;<br>
	for (int i = 0; i < N; i++) {
		cin >> num;<br>
		A.push_back(num);
		B.push_back(num);
	}
	sort(B.begin(), B.end());
	B.erase(unique(B.begin(), B.end()), B.end());
	for (int i = 0; i < N; i++)
		cout << lower_bound(B.begin(), B.end(), A[i]) - B.begin() << " ";

	return 0;
}
```

## 관련 문제
https://www.acmicpc.net/problem/18870
https://www.acmicpc.net/problem/5419

## 참고
https://mangu.tistory.com/90
{% endraw %}