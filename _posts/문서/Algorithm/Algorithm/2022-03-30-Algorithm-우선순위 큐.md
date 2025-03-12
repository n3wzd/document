---
categories:
- Algorithm
date: '2022-03-30'
title: '[Algorithm] 우선순위 큐'
---

{% raw %}
##  힙
힙은 부모-자식 간 비교 조건이 적용된 Complete Binary Tree다.

삽입과 삭제가 O(log N), 최적값 조회가 O(1)로 처리 속도가 빠르다. 따라서 자주 추가되는 데이터에서 최적 값만 필요한 경우에 적합한 자료구조다.

대표적으로 max heap, min heap이 있다. max heap은 루트 노드가 최댓값, min heap은 루트 노드가 최솟값이다.

## 구현
일반적으로 배열로 구현한다. max heap을 기준으로 구현해보자.
```
max_heap[MAX_SIZE]		// 편의상 인덱스는 1부터 시작
heap_size = 0			// 힙의 크기 = 원소의 개수
```
max heap은 항상 부모 값이 자식 값보다 커야 한다.
```
            7
     6            3
  4    5       1     2
```
배열 구조로 보면 다음과 같다. 현재 인덱스에서 ×2 연산을 사용해 부모-자식을 접근할 수 있다.
```
7 6 3 4 5 1 2
```

#### 조회
힙은 루트 노드만이 유의미한 값이다. 따라서 루트 노드만 조회할 수 있다.
```
return max_heap[1]
```

#### 삽입
1. 새로운 원소를 배열 맨 끝에 추가하고, 총 크기에 +1 더한다.
```
=> insert 8<br>
           7
     6            3
  4    5       8   
heap_size = 6
```

2. 힙의 성질을 유지하기 위해 새 원소의 위치를 조정할 필요가 있다. 삽입된 위치를 기점으로 해서 부모-자식 간 비교 연산을 수행한다.
	- 만약 부모가 자식보다 같거나 크다면 힙의 특성이 유지되었다. [과정 종료]
	- 만약 부모가 자식보다 작다면 교체를 수행한다.
	- 루트 노드에 도달했으면 더 이상 비교를 할 수 없다. [과정 종료]
```
=> child 8 > parent 3 -> replace!<br>
           7
     6            8
  4    5       3   
```
```
=> child 8 > parent 7 -> replace!<br>
           8
     6            7
  4    5       3   
```
이렇게 힙의 특성을 만족시키기 위해 수행하는 작업을 `heapify`이라고 한다.

시간 복잡도는 O(log N)이다.

#### 삭제
힙은 루트 노드만 조회가 가능하므로, 삭제 역시 루트 노드만 가능하다.
1. 루트 노드를 삭제하고, 배열 상에서 마지막 원소를 루트 노드에 옮긴다. 그리고 총 크기에서 1을 뺀다.
```
=> delete 8<br>
           
     6            7
  4    5       3   

=> move 3 to root<br>
           3
     6            7
  4    5         
```
2. 루트 노드를 기점으로 `heapify`연산을 수행한다.
	- 자식 중에서 최댓값을 선택한다.
	- 최대 자식과 루트 노드를 비교하고, 자식이 더 크면 교체를 수행.
	- 그렇지 않으면 [과정 종료]
```
=> child 7 > parent 3 -> replace!<br>
           7
     6            3
  4    5          
```

시간 복잡도는 삽입과 같이 O(log N)이다.

#### 응용
부모-자식간 비교 연산을 적절히 변형해서 원하는 최적값을 반환하는 힙을 구현할 수 있다.

예를 들어 min heap일 경우, 부모-자식간 비교 연산에서 부등호 방향만 바꾸면 된다.

##  우선순위 큐
우선순위 큐(Priority Queue)는 우선순위가 높은 값을 빠르게 조회하거나 삭제할 수 있는 자료구조다. 일반적으로 힙으로 구현된다.

## 코드
```
#include <iostream>
using namespace std;
int max_heap[100001];
int heap_size = 0;

bool Empty()
{
	return (heap_size == 0);
}

void Push(int n)
{
	max_heap[++heap_size] = n;
	int i = heap_size;

	for (; i > 1; i /= 2)<br>
	{
		if (n <= max_heap[i / 2]) break;
		max_heap[i] = max_heap[i / 2];
	}
	max_heap[i] = n;
}

int Pop()
{
	if (Empty()) return 0;

	int res = max_heap[1];
	int last = max_heap[heap_size--];
	max_heap[1] = last;

	int i = 1;
	while (i <= heap_size / 2)
	{
		int m = (max_heap[i * 2] > max_heap[i * 2 + 1]) ? i * 2 : i * 2 + 1;<br>
		if (last >= max_heap[m]) break;
		max_heap[i] = max_heap[m];
		i = m;
	}
	max_heap[i] = last;

	return res;
}

void Print()
{
	for (int i = 1; i <= heap_size; i++)
		printf("%d ", max_heap[i]);
	printf("\n");
}

int main()
{
	int t;
	scanf("%d", &t);

	for (; t > 0; t--)<br>
	{
		int cmd;
		scanf("%d", &cmd);
		if (cmd == 0) printf("%d\n", Pop());
		else Push(cmd);
	}

	return 0;
}
```

## STL
C++의 queue.h에서 우선순위 큐를 제공한다. 사용법은 일반적으로 queue하고 동일하다.
- `priority_queue<int>` -  max heap
- `priority_queue<int, vector<int>, greater<int>>` -  min heap
- `priority_queue<int, vector<int>, cmp>` -  커스텀 heap

sort함수와 비슷하게 비교 함수를 사용해서 커스터마이징이 가능하다. 비교함수는 다음과 같은 형식을 만족해야 한다. 
- 반환 값이 true면, a와 b를 swap한다. 
- 반환 값은 인자 a, b 순서를 바꾸면 항상 달라져야 한다. 예를 들어 3, 5을 입력했을 때 true를 반환했다면, 5, 3을 입력했을 때 false를 반환해야 한다.
```
struct compare{
    bool operator()(int a, int b){
        return a > b;<br>
    }
};
```
위의 예시를 사용하면 오름차순이 된다. 만약 a < b이라면, 내림차순이 된다. (sort 비교 함수와 달리, 부등호 방향이 반대라는 점을 유의하자)

## 연관 문제
https://www.acmicpc.net/problem/11279<br>
https://www.acmicpc.net/problem/11286<br>
https://www.acmicpc.net/problem/1655<br>

## 참고
https://chanhuiseok.github.io/posts/ds-4/<br>
https://doorrock.tistory.com/13<br>
{% endraw %}