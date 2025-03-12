---
categories:
- Programmers
date: '2024-11-21'
title: '[Programmers] 월간 코드 챌린지 시즌3 - 없는 숫자 더하기'
---

{% raw %}
> Lv. 1<br>

## 문제
0부터 9까지의 숫자 중 일부가 들어있는 정수 배열  `numbers`가 매개변수로 주어집니다.  `numbers`에서 찾을 수 없는 0부터 9까지의 숫자를 모두 찾아 더한 수를 return 하도록 solution 함수를 완성해주세요.

### 제한사항
-   1 ≤  `numbers`의 길이 ≤ 9
    -   0 ≤  `numbers`의 모든 원소 ≤ 9
    -   `numbers`의 모든 원소는 서로 다릅니다.

## 해결
`numbers`는 항상 0부터 9가 유일하게 존재하므로 최댓값(45)에서 빼는 방법으로 정답을 구할 수 있습니다.

## 코드
```
#include <vector>
using namespace std;

int solution(vector<int> numbers) {
    int answer = 45;
    for(int n : numbers)
        answer -= n;
    return answer;
}
```

## 링크
<br>https://school.programmers.co.kr/learn/courses/30/lessons/86051
{% endraw %}