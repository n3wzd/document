---
categories:
- Programmers
date: '2024-12-07'
title: '[Programmers] 연습문제 - 테이블 해시 함수'
---

{% raw %}
> Lv. 2<br>

## 문제
완호가 관리하는 어떤 데이터베이스의 한 테이블은 모두 정수 타입인 컬럼들로 이루어져 있습니다. 테이블은 2차원 행렬로 표현할 수 있으며 열은 컬럼을 나타내고, 행은 튜플을 나타냅니다.  
첫 번째 컬럼은 기본키로서 모든 튜플에 대해 그 값이 중복되지 않도록 보장됩니다. 완호는 이 테이블에 대한 해시 함수를 다음과 같이 정의하였습니다.

1.  해시 함수는  `col`,  `row_begin`,  `row_end`을 입력으로 받습니다.
2.  테이블의 튜플을  `col`번째 컬럼의 값을 기준으로 오름차순 정렬을 하되, 만약 그 값이 동일하면 기본키인 첫 번째 컬럼의 값을 기준으로 내림차순 정렬합니다.
3.  정렬된 데이터에서 S_i를 i 번째 행의 튜플에 대해 각 컬럼의 값을 i 로 나눈 나머지들의 합으로 정의합니다.
4.  `row_begin`  ≤ i ≤  `row_end`  인 모든 S_i를 누적하여 bitwise XOR 한 값을 해시 값으로서 반환합니다.

테이블의 데이터  `data`와 해시 함수에 대한 입력  `col`,  `row_begin`,  `row_end`이 주어졌을 때 테이블의 해시 값을 return 하도록 solution 함수를 완성해주세요.

### 제한 사항

-   1 ≤  `data`의 길이 ≤ 2,500
-   1 ≤  `data`의 원소의 길이 ≤ 500
-   1 ≤  `data`[i][j] ≤ 1,000,000
    -   `data`[i][j]는 i + 1 번째 튜플의 j + 1 번째 컬럼의 값을 의미합니다.
-   1 ≤ col ≤  `data`의 원소의 길이
-   1 ≤  `row_begin`  ≤  `row_end`  ≤  `data`의 길이

## 해결
주어진 과정을 그대로 구현합니다. (`정렬`, 나머지 연산, XOR 연산 사용)

## 코드
```
#include <vector>
#include <algorithm>
using namespace std;

int S(vector<int> d, int n) {<br>
    int sum = 0;
    for(int i = 0; i < d.size(); i++)
        sum += d[i] % n;
    return sum;
}

int solution(vector<vector<int>> data, int col, int lo, int hi) {<br>
    col--; lo--; hi--;
    sort(data.begin(), data.end(), [col](auto a, auto b) {
        return a[col] != b[col] ? a[col] < b[col] : a[0] > b[0];<br>
    });
    int answer = S(data[lo], lo + 1);
    for(int i = lo + 1; i <= hi; i++)
        answer ^= S(data[i], i + 1);
    return answer;
}
```

## 링크
https://school.programmers.co.kr/learn/courses/30/lessons/147354<br>
{% endraw %}