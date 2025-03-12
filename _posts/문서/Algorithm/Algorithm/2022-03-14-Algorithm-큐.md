---
categories:
- Algorithm
date: '2022-03-14'
title: '[Algorithm] 큐'
---

{% raw %}
##  큐
먼저 넣은 것을 먼저 꺼내는 FIFO(First In First Out) 추상적 자료구조.

자주 사용되는 연산 목록
- push X: 원소 X를 추가한다.
- pop: 가장 뒤에 있는 원소를 삭제한다.
- front: 가장 앞에 있는 원소를 반환한다.
- back: 가장 뒤에 있는 원소를 반환한다.
- size: 원소 개수를 반환한다.
- empty: 큐가 비어있으면 true, 아니면 false를 반환한다.

위의 모든 연산은 O(1) 시간 복잡도를 갖는다. 가장 처음에 넣은 것을 먼저 사용해야 한다면 큐가 적합하다.

## STL
C++ queue.h에서 큐를 제공한다.
- `queue<int>`

큐가 비어 있을 때 조회/삭제 연산을 하면 오류가 발생한다. 조회/삭제 전에는 큐가 비어 있는지 검사하는 것이 좋다.

## 연관 문제
https://www.acmicpc.net/problem/18258<br>
https://www.acmicpc.net/problem/1021<br>

## 참고
https://namu.wiki/w/%ED%81%90(%EC%9E%90%EB%A3%8C%EA%B5%AC%EC%A1%B0)<br>
{% endraw %}