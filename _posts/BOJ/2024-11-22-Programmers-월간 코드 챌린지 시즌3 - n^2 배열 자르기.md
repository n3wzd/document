---
categories:
- Programmers
date: '2024-11-22'
title: '[Programmers] 월간 코드 챌린지 시즌3 - n^2 배열 자르기'
---

{% raw %}
> Lv. 2<br>

## 문제
정수  `n`,  `left`,  `right`가 주어집니다. 다음 과정을 거쳐서 1차원 배열을 만들고자 합니다.

1.  `n`행  `n`열 크기의 비어있는 2차원 배열을 만듭니다.
2.  `i = 1, 2, 3, ..., n`에 대해서, 다음 과정을 반복합니다.
    -   1행 1열부터  `i`행  `i`열까지의 영역 내의 모든 빈 칸을 숫자  `i`로 채웁니다.
3.  1행, 2행, ...,  `n`행을 잘라내어 모두 이어붙인 새로운 1차원 배열을 만듭니다.
4.  새로운 1차원 배열을  `arr`이라 할 때,  `arr[left]`,  `arr[left+1]`, ...,  `arr[right]`만 남기고 나머지는 지웁니다.

정수  `n`,  `left`,  `right`가 매개변수로 주어집니다. 주어진 과정대로 만들어진 1차원 배열을 return 하도록 solution 함수를 완성해주세요.

### 제한사항
-   1 ≤  `n`  ≤ 107
-   0 ≤  `left`  ≤  `right`  < n2
-   `right`  -  `left`  < 105

## 해결
주어진 2차원 배열에서 임의의 위치에 있는 값을 찾아봅시다. 현재 위치가 (`x`, `y`)일 때, 이 위치의 값은 `max(x, y)`임을 발견할 수 있습니다.
```
1 2 3
2 2 3
3 3 3
...
```

배열을 일렬로 보았을 때 구간에 포함되는 값들을 찾아야 합니다. 직선 배열의 인덱스 `i`가 주어졌을 때, 이를 2차원 위치 (`x`, `y`)로 변환하면 구할 수 있습니다.

## 코드
```
#include <vector>
using namespace std;
typedef long long ll;

vector<int> solution(int n, ll left, ll right) {<br>
    vector<int> answer;<br>
    for(ll i = left; i <= right; i++)
        answer.push_back(max(i % n, i / n) + 1);
    return answer;
}
```

## 링크
https://school.programmers.co.kr/learn/courses/30/lessons/87390<br>
{% endraw %}