---
categories:
- Algorithm
date: '2022-03-14'
title: '[Algorithm] 스택'
---

{% raw %}
##  스택
나중에 넣은 것을 먼저 꺼내는 LIFO(Last In First Out) 추상적 자료구조.

자주 사용되는 연산 목록
- push X: 원소 X를 추가한다.
- pop: 가장 위에 있는 원소를 삭제한다.
- top: 가장 위에 있는 원소를 반환한다.
- size: 원소 개수를 반환한다.
- empty: 스택이 비어있으면 true, 아니면 false를 반환한다.

위의 모든 연산은 O(1) 시간 복잡도를 갖는다. 가장 최근에 넣은 것을 먼저 사용해야 한다면 스택이 적합하다.

## STL
C++ stack.h에서 스택을 제공한다.
- `stack<int>`

스택이 비어 있을 때 조회/삭제 연산을 하면 오류가 발생한다. 조회/삭제 전에는 스택이 비어 있는지 검사하는 것이 좋다.

## 연관 문제
https://www.acmicpc.net/problem/10828<br>
https://www.acmicpc.net/problem/17298<br>

## 참고
https://namu.wiki/w/%EC%8A%A4%ED%83%9D(%EC%9E%90%EB%A3%8C%EA%B5%AC%EC%A1%B0)<br>
{% endraw %}