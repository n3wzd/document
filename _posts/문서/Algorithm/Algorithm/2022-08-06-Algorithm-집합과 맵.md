---
categories:
- Algorithm
date: '2022-08-06'
title: '[Algorithm] 집합과 맵'
---

{% raw %}
## 집합과 맵
`set`은 원소 검색을 효율적으로 수행하는 자료구조다. 주로 균형 이진 검색 트리(Balanced Binary Search Tree)로 구현된다.
- 단일 값을 가진 원소를 저장한다. => **key**<br>
- 모든 원소는 key에 대해 정렬되어 있다.
- key는 중복을 허용하지 않는다. (unique)

임의의 원소 삽입/삭제가 발생하는 목록에서 특정 원소를 빠르게 찾을 때는 set이 적합하다. 원소는 key, 정렬 기준, 이분 탐색으로 찾을 수 있다.

`map`은 set과 비슷하지만 key-value 구조로 저장한다.
- key-value 구조를 가진 원소를 저장한다.
- 모든 원소는 key에 대해 정렬되어 있다.
- key는 중복을 허용하지 않는다. (unique)

`multiset`은 set과 비슷하지만 키의 중복을 허용한다.

## set
C++에서는 STL 자료구조 `set`을 제공한다.
- **set< int > s**<br>

### 연산
- **s.insert(key)**: 원소 key 추가
- **s.find(key)**: 원소 key를 가리키는 반복자 반환 (검색 실패 시, s.end() 반환)
- **s.begin()**: 첫번째 노드를 가리키는 반복자 반환
- **s.end()**: 마지막 노드의 다음을 가리키는 반복자 반환
- **s.erase(key)**: 해당 키에 속하는 노드를 삭제
- **s.clear()**: 모든 노드를 삭제
- **s.upper_bound(key)**: 원소 key에 대한 `upper_bound` 반복자 반환 (검색 실패 시, s.end() 반환)
- **s.lower_bound(key)**: 원소 key에 대한 `lower_bound` 반복자 반환 (검색 실패 시, s.end() 반환)

## map
C++에서는 STL 자료구조 `map`을 제공한다.
- **map<int, string> m**<br>

### 연산
STL 자료구조 `set`과 기능이 비슷하다. 반복자(iterator)를 사용해서 노드를 참조할 수 있다.
- **m.insert(pair<int, stinrg>(key, value))**: 키와 값을 추가
- **m.find(key)**: 키가 주어졌을 때 해당하는 노드(key-value pair)를 가리키는 반복자 반환 (검색 실패 시, m.end() 반환)
- **m.begin()**: 첫번째 노드를 가리키는 반복자 반환
- **m.end()**: 마지막 노드의 다음을 가리키는 반복자 반환
- **m.erase(key)**: 해당 키에 속하는 노드를 삭제
- **m.clear()**: 모든 노드를 삭제
- **s.upper_bound(key)**: 원소 key에 대한 `upper_bound` 반복자 반환 (검색 실패 시, m.end() 반환)
- **s.lower_bound(key)**: 원소 key에 대한 `lower_bound` 반복자 반환 (검색 실패 시, m.end() 반환)

find, erase일 경우, 반복자를 입력으로 사용할 수도 있다.

## multiset
C++에서는 STL 자료구조 `multiset`을 제공한다.
- **multiset<int> ms**<br>

### 연산
- **ms.insert(key)**: 원소 key 추가 (중복 가능)
- **ms.find(key)**: 원소 key를 가리키는 반복자 반환 (검색 실패 시, ms.end() 반환)
- **ms.begin()**: 첫번째 노드를 가리키는 반복자 반환
- **ms.end()**: 마지막 노드의 다음을 가리키는 반복자 반환
- **ms.erase(key)**: 해당 키에 속하는 모든 노드를 삭제
- **ms.clear()**: 모든 노드를 삭제
- **ms.upper_bound(key)**: 원소 key에 대한 `upper_bound` 반복자 반환 (검색 실패 시, ms.end() 반환)
- **ms.lower_bound(key)**: 원소 key에 대한 `lower_bound` 반복자 반환 (검색 실패 시, ms.end() 반환)

lower_bound를 활용해서 특정 키를 가진 원소 1개만 삭제할 수 있다.

## 시간 복잡도
- 원소 삽입 = O(logN)
- 임의의 원소 삭제, 조회 = O(logN)
- 반복자를 사용한 참조 = O(1)
- lowerbound, upperbound = O(logN)
- 첫번째/마지막 원소 조회 = O(1)

## 활용
### vs 우선순위 큐
set은 상시 정렬이 되어 있다는 점에서 `우선순위 큐`와 비슷한 용도로 활용할 수 있다.
- set은 우선순위 큐의 모든 기능을 이용할 수 있다.
- 맨 위의 원소만 삭제 가능한 우선순위 큐와 달리, set은 임의의 원소 삭제가 가능하다.
- set의 모든 연산의 시간 복잡도는 우선순위 큐하고 동일하지만, set의 삽입 연산 시간은 우선순위 큐보다 오래 걸린다.
- 주로 set은 균형 이진 트리, 우선순위 큐는 heap으로 구현된다.

=> 우선순위 큐 기능만으로 구현할 수 있다면 우선순위 큐, 그렇지 않다면 set을 사용한다.<br>

### 그 외
원소 추가/삭제가 발생하는 목록에서 `이분 탐색`할 때도 활용할 수 있다. 선형 리스트는 삭제 시간이 O(N)이지만, set 자료구조는 O(log N)이므로 더 빠르게 탐색할 수 있다.

## 관련 문제
https://www.acmicpc.net/problem/14425<br>
https://www.acmicpc.net/problem/1620<br>
https://www.acmicpc.net/problem/1202<br>

## 참고
https://blockdmask.tistory.com/87<br>
https://life-with-coding.tistory.com/305<br>
https://stackoverflow.com/questions/10141841/difference-between-stdset-and-stdpriority-queue<br>
{% endraw %}