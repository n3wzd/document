---
categories:
- Programmers
date: '2024-11-22'
title: '[Programmers] 월간 코드 챌린지 시즌3 - 나머지가 1이 되는 수 찾기'
---

{% raw %}
> Lv. 1<br>

## 문제
자연수  `n`이 매개변수로 주어집니다.  `n`을  `x`로 나눈 나머지가 1이 되도록 하는 가장 작은 자연수  `x`를 return 하도록 solution 함수를 완성해주세요. 답이 항상 존재함은 증명될 수 있습니다.

### 제한사항
-   3 ≤  `n`  ≤ 1,000,000

## 해결
1부터 모든 자연수를 확인하면 됩니다.

## 코드
```
int solution(int n) {
    int x = 1;
    while(n % x != 1) x++;
    return x;
}
```

## 링크
https://school.programmers.co.kr/learn/courses/30/lessons/87389<br>
{% endraw %}