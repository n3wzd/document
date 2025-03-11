---
categories:
- Algorithm
date: '2022-07-16'
title: '[Algorithm] 덱'
---

{% raw %}
##  덱
큐와 스택의 기능을 합쳐서 FIFO 방식과 LIFO방식이 모두 가능한 추상적 자료구조. 양방향 입출력이 가능하다.

자주 사용되는 연산 목록
- push_front X: 원소 X를 가장 앞에 추가한다.
- push_back X: 원소 X를 가장 뒤에 추가한다.
- pop_front: 가장 앞에 있는 원소를 삭제한다.
- pop_back: 가장 뒤에 있는 원소를 삭제한다.
- front: 가장 앞에 있는 원소를 반환한다.
- back: 가장 뒤에 있는 원소를 반환한다.
- size: 큐에 들어있는 원소 개수를 반환한다.
- empty: 큐가 비어있으면 true, 아니면 false를 반환한다.

위의 모든 연산은 O(1) 시간 복잡도를 갖는다. 양방향 입출력이 빠른 자료구조가 필요하면 덱이 적합하다.

## STL
C++ deque.h에서 덱을 제공한다.
- `deque<int>`

덱이 비어 있을 때 조회/삭제 연산을 하면 오류가 발생한다. 조회/삭제 전에는 덱이 비어 있는지 검사하는 것이 좋다.

## 활용
슬라이딩 윈도우에서 최대/소는 나이브하게 구하면 O(N<sup>2</sup>) 시간이 걸리지만, `덱`을 사용하면 O(N)으로 구할 수 있다.

## 연관 문제
https://www.acmicpc.net/problem/10866
https://www.acmicpc.net/problem/5430

### 슬라이딩 윈도우 최대/소
https://www.acmicpc.net/problem/11003

## 참고
https://namu.wiki/w/%ED%81%90(%EC%9E%90%EB%A3%8C%EA%B5%AC%EC%A1%B0)
{% endraw %}