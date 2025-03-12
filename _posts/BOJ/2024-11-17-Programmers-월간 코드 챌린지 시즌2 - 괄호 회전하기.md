---
categories:
- Programmers
date: '2024-11-17'
title: '[Programmers] 월간 코드 챌린지 시즌2 - 괄호 회전하기'
---

{% raw %}
> Lv. 2<br>

## 문제
다음 규칙을 지키는 문자열을 올바른 괄호 문자열이라고 정의합니다.

-   `()`,  `[]`,  `{}`  는 모두 올바른 괄호 문자열입니다.
-   만약  `A`가 올바른 괄호 문자열이라면,  `(A)`,  `[A]`,  `{A}`  도 올바른 괄호 문자열입니다. 예를 들어,  `[]`  가 올바른 괄호 문자열이므로,  `([])`  도 올바른 괄호 문자열입니다.
-   만약  `A`,  `B`가 올바른 괄호 문자열이라면,  `AB`  도 올바른 괄호 문자열입니다. 예를 들어,  `{}`  와  `([])`  가 올바른 괄호 문자열이므로,  `{}([])`  도 올바른 괄호 문자열입니다.

대괄호, 중괄호, 그리고 소괄호로 이루어진 문자열  `s`가 매개변수로 주어집니다. 이  `s`를 왼쪽으로 x (_0 ≤ x < (`s`의 길이)_) 칸만큼 회전시켰을 때  `s`가 올바른 괄호 문자열이 되게 하는 x의 개수를 return 하도록 solution 함수를 완성해주세요.

### 제한사항
-   s의 길이는 1 이상 1,000 이하입니다.

## 해결
- 괄호 문자열은 재귀적으로 구성될 수 있으므로 `스택`으로 표현할 수 있습니다.
- 문자열을 탐색할 때, 스택의 위쪽과 현재 문자가 괄호 쌍을 이루면 스택의 위를 제거합니다. 그렇지 않으면 현재 문자를 스택에 넣습니다. 문자열 탐색이 종료되었을 때, 스택이 비어 있다면 해당 문자열은 올바른 괄호 문자열입니다.

## 코드
```
#include <string>
#include <vector>
#include <stack>
using namespace std;
char match(char c) {
    if(c == ')') return '(';
    if(c == '}') return '{';
    if(c == ']') return '[';
    return ' ';
}

int solution(string s) {
    int answer = 0, N = s.size();
    for(int b = 0; b < N; b++) {
        stack<char> stk;
        for(int i = 0; i < N; i++) {
            char cur = s[(b + i) % N];
            if(!stk.empty() && stk.top() == match(cur))
                stk.pop();
            else
                stk.push(cur);
        }
        if(stk.empty())
            answer++;
    }
    return answer;
}
```

## 링크
<br>https://school.programmers.co.kr/learn/courses/30/lessons/76502
{% endraw %}