---
categories:
- Algorithm
date: '2022-05-23'
title: '[Algorithm] 비트마스크'
---

{% raw %}
## 비트마스크
비트(bit) 연산을 활용해서 10진수 정수를 2진수 연산으로 다루는 테크닉.

## 비트 연산
**AND 연산(&)**
두 비트가 모두 1이면, 1 반환
> 1010 & 1111 = 1010<br>

**OR 연산(|)**
두 비트가 하나라도 1이면, 1 반환
> 1010 | 1111 = 1111<br>

**XOR 연산(^)**
두 비트가 서로 다르면, 1 반환
> 1010 | 1111 = 0101<br>

**NOT 연산(~)**
비트의 값을 반전
> ~1010 = 0101<br>

**시프트(Shift) 연산(>>, <<)**
왼쪽/오른쪽으로 N번 만큼 비트를 이동 (새로 들어오는 자릿수는 0)
> 00001010 << 2 = 101000  <br>
> 00001010 >> 2 = 000010<br>

## 마스크 연산
커스텀 마스크를 생성해 특정 위치를 필터링하면, 해당 위치의 비트만 조회하거나 변경할 수 있다.

**이진수 B의 n번째 비트의 값 조회**
> B & (1 << n)  <br>

ex. 2번째 비트만 조회
> 1010 & (1 << 2) = 1010 & 0100 => 0000 = 0 <br>
> 1110 & (1 << 2) = 1110 & 0100 => 0100 = 1 <br>

**이진수 B의 n번째 비트의 값을 1로 변경**
> B | (1 << n)<br>

ex. 1010의 2번째 비트를 1로 변경
> 1010 | (1 << 2)<br>
> 1010 | 0100 => 1110<br>

**이진수 B의 n번째 비트의 값을 0으로 변경**
> B & ~(1 << n)<br>

ex. 1010의 2번째 비트를 0으로 변경
> 1110 & ~(1 << 2)  <br>
> 1110 & 1011 => 1010<br>

## 활용
비트마스크를 활용하면 0과 1만을 값으로 하는 boolean 배열을 정수 하나로 치환할 수 있다.

`DP`, `그래프` 등에서 탐색의 현재 상태를 집합의 원소 존재 유무같이 boolean 배열로 하는 경우가 있는데, 이때 비트마스크를 사용하면 정수 하나로 대체해서 표현할 수 있다.
```
ex.
DP([0, 1, 0 ... ], Time, Money)

=> bitmask 적용
DP(Visited, Time, Money)
```

그 외, 2진수 관련 연산, 2<sup>k</sup>가 필요한 연산에서 비트마스크를 사용하면 편리하다. (ex. 어떤 정수에서 2<sup>k</sup>를 확인, 2<sup>k</sup> 더하기 등)

## 관련 문제
<br>https://www.acmicpc.net/problem/2098
<br>https://www.acmicpc.net/problem/1311

## 참고
<br>https://mygumi.tistory.com/361
{% endraw %}