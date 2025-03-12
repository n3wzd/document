---
categories:
- Programmers
date: '2024-11-21'
title: '[Programmers] 월간 코드 챌린지 시즌2 - 2개 이하로 다른 비트'
---

{% raw %}
> Lv. 2<br>

## 문제
양의 정수  `x`에 대한 함수  `f(x)`를 다음과 같이 정의합니다.

-   `x`보다 크고  `x`와  **비트가 1~2개 다른**  수들 중에서 제일 작은 수

정수들이 담긴 배열  `numbers`가 매개변수로 주어집니다.  `numbers`의 모든 수들에 대하여 각 수의  `f`  값을 배열에 차례대로 담아 return 하도록 solution 함수를 완성해주세요.

### 제한사항
-   1 ≤  `numbers`의 길이 ≤ 100,000
-   0 ≤  `numbers`의 모든 수 ≤ 1015

## 해결
먼저 예시를 통해 규칙을 찾아봅시다.
```
00000 => 00001<br>
00001 => 00010<br>
00011 => 00101<br>
00111 => 01011<br>
01111 => 10111<br>
```

가장 오른쪽의 0이 1이 되고, 그 왼쪽에 있는 1이 0이 됨을 발견할 수 있습니다. 따라서 f(x)는 다음과 같이 정리할 수 있습니다:
> f(x) = 가장 오른쪽에 있는 비트 0을, 해당 비트의 오른쪽 비트 1과 스왑한 수<br>

구현은 `비트마스킹`을 사용합니다. 수가 충분히 크기 때문에 자료형에 유의합니다. (C++인 경우, shift할 1도 `long long`이어야 합니다.)

## 코드
```
#include <vector>
using namespace std;
typedef long long ll;

vector<ll> solution(vector<ll> numbers) {<br>
    vector<ll> answer; ll b = 1;<br>
    for (auto n : numbers) {
        if (n == 0) {
            answer.push_back(1);
            continue;
        }
        int i = 0;
        while ((n & b << i) != 0) i++;
        answer.push_back((n | b << i) & ~(b << (i - 1)));
    }
    return answer;
}
```

## 링크
https://school.programmers.co.kr/learn/courses/30/lessons/77885<br>
{% endraw %}