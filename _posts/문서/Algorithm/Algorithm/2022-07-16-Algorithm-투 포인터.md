---
categories:
- Algorithm
date: '2022-07-16'
title: '[Algorithm] 투 포인터'
---

{% raw %}
##  투 포인터
`투 포인터(Two pointer)`는 특정 위치를 가리키는 2개의 포인터를 사용해서 탐색하는 접근 테크닉이다.

투 포인터를 사용하면 1차원 배열에서 탐색 범위를 한정하는 효과를 볼 수 있다. 투 포인터를 사용하면, 투 포인터 범위 밖의 내용은 탐색하지 않기에 일반적인 선형 탐색보다 탐색 시간을 줄일 수 있다. 역으로, 투 포인터를 사용하려면 탐색 범위 밖은 확실히 조사하지 않아도 된다는 점을 보장해야 한다. (범위 밖에 답이 있으면 안된다)

투 포인터는 탐색의 범위를 한정했을 때 이득을 볼 수 있다면 사용된다. 양 끝을 가리키는 투 포인터를 적절히 줄여 목표 값을 찾는 `이분 탐색`과 `합병 정렬`의 비교 연산도 투 포인터를 사용한다고 볼 수 있다. 또한 `분할 정복 알고리즘`, `DP`와 같이 다른 알고리즘과 같이 사용되기도 한다.

### 사용 방법
```
1 2 3 4 5 6 7 8
  <sup>       </sup>
```
1. 투 포인터의 초기 위치, 탐색 범위를 정한다.
2. 투 포인터 범위 내에서 연산을 한다.
3. 연산이 끝나면 투 포인터를 적절히 움직여 탐색 범위를 줄인다. 이 과정을 반복해 최종 답을 얻는다.

탐색 범위를 한정짓기 위해 보통 `정렬`도 같이 사용되는 편이다.

### 사용 유형
**범위 선정**
- 탐색 범위의 양 끝을 잡는 경우 => 가장 보편적인 유형. 시작을 start(LO), 끝을 end(HI) 설정하고 start보다 크거나 같고 end보다 작거나 같은 위치 내에서 탐색을 한다. 일반적으로 start보다 end가 작을 때(=start가 end를 역전했을 때) 탐색이 종료된다.
- 시작점을 잡는 경우 => 투 포인터를 서로 다른 배열의 시작점에 두는 경우 (ex. `합병 정렬`의 비교 연산)

**움직임**
- 1칸씩 움직이는 경우 => 가장 보편적인 유형
- 탐색 범위 내에 있는 특정 위치로 점프 => ex. `이분 탐색`

### 슬라이딩 윈도우
`슬라이딩 윈도우(Sliding Window)`는 크기가 고정된 윈도우가 이동하면서 윈도우 내에 있는 데이터를 이용해 문제를 해결하는 투 포인터를 응용한 접근 테크닉이다. 윈도우의 양 끝을 투 포인터로 잡으면 구현할 수 있다.

슬라이딩 윈도우에서 최대/소는 나이브하게 구하면 O(N<sup>2</sup>) 시간이 걸리지만, `덱`을 사용하면 O(N)으로 구할 수 있다.

## 연관 문제
<br>https://www.acmicpc.net/problem/1806
<br>https://www.acmicpc.net/problem/2470
<br>https://www.acmicpc.net/problem/11066

### 슬라이딩 윈도우 최대/소
<br>https://www.acmicpc.net/problem/11003

## 참고
<br>https://afteracademy.com/blog/what-is-the-two-pointer-technique
<br>https://github.com/WooVictory/Ready-For-Tech-Interview/blob/master/Algorithm/%ED%88%AC%ED%8F%AC%EC%9D%B8%ED%84%B0%20%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98.md
<br>https://velog.io/@zwon/%EC%8A%AC%EB%9D%BC%EC%9D%B4%EB%94%A9-%EC%9C%88%EB%8F%84%EC%9A%B0Sliding-Window
{% endraw %}