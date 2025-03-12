---
categories:
- Programmers
date: '2024-11-14'
title: '[Programmers] 월간 코드 챌린지 시즌1 - 3진법 뒤집기'
---

{% raw %}
> Lv. 1<br>

## 문제
자연수 n이 매개변수로 주어집니다. n을 3진법 상에서 앞뒤로 뒤집은 후, 이를 다시 10진법으로 표현한 수를 return 하도록 solution 함수를 완성해주세요.

### 제한사항
-   n은 1 이상 100,000,000 이하인 자연수입니다.

## 해결
- 3의 나머지와 몫을 활용해 3진법 변환을 하면 됩니다.
- 변환한 3진법은 배열에 저장하면 편리합니다.

## 코드
```
#include <vector>
using namespace std;
vector<int> T;

int solution(int n) {
    while(n > 0) {
        T.push_back(n % 3);
        n /= 3;
    }
    int answer = 0, N = T.size();
    for(int i = N - 1, d = 1; i >= 0; i--, d *= 3)
        answer += T[i] * d;
    return answer;
}
```

## 링크
<br>https://school.programmers.co.kr/learn/courses/30/lessons/68935
{% endraw %}