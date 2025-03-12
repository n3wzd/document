---
categories:
- Programmers
date: '2024-10-24'
title: '[Programmers] PCCP - 수식 복원하기'
---

{% raw %}
> Lv. 3<br>

## 문제
당신은 덧셈 혹은 뺄셈 수식이 여러 개 적힌 고대 문명의 유물을 찾았습니다. 이 수식들을 관찰하던 당신은 이 문명이 사용하던 진법 체계가 10진법이 아니라는 것을 알아냈습니다. (2 ~ 9진법 중 하나입니다.)

수식들 중 몇 개의 수식은 결괏값이 지워져 있으며, 당신은 이 문명이 사용하던 진법에 맞도록 지워진 결괏값을 채워 넣으려 합니다.

다음은 그 예시입니다.

<**수식**>
```
14 + 3 = 17
13 - 6 = X
51 - 5 = 44
```

-   `X`로 표시된 부분이 지워진 결괏값입니다.

`51 - 5 = 44`에서 이 문명이 사용하던 진법이 8진법임을 알 수 있습니다. 따라서  `13 - 6 = X`의 지워진 결괏값을 채워 넣으면  `13 - 6 = 5`가 됩니다.

다음은 또 다른 예시입니다.

<**수식**>
```
1 + 1 = 2
1 + 3 = 4
1 + 5 = X
1 + 2 = X
```

주어진 수식들에서 이 문명에서 사용한 진법이 6 ~ 9진법 중 하나임을 알 수 있습니다.  
`1 + 5 = X`의 결괏값은 6진법일 때 10, 7 ~ 9진법일 때 6이 됩니다. 이와 같이 결괏값이 불확실한 수식은  `?`를 사용해  `1 + 5 = ?`와 같이 결괏값을 채워 넣습니다.  
`1 + 2 = X`의 결괏값은 6 ~ 9진법에서 모두 3으로 같습니다. 따라서  `1 + 2 = X`의 지워진 결괏값을 채워 넣으면  `1 + 2 = 3`이 됩니다.

덧셈 혹은 뺄셈 수식들이 담긴 1차원 문자열 배열  `expressions`가 매개변수로 주어집니다. 이때 결괏값이 지워진 수식들의 결괏값을 채워 넣어 순서대로 문자열 배열에 담아 return 하도록 solution 함수를 완성해 주세요.

### 제한사항

-   2 ≤  `expressions`의 길이 ≤ 100
    -   `expressions`의 원소는  `"A + B = C"`  혹은  `"A - B = C"`  형태의 문자열입니다. A, B, C와 연산 기호들은 공백 하나로 구분되어 있습니다.
    -   A, B는 음이 아닌 두 자릿수 이하의 정수입니다.
    -   C는 알파벳  `X`  혹은 음이 아닌 세 자릿수 이하의 정수입니다. C가 알파벳  `X`인 수식은 결괏값이 지워진 수식을 의미하며, 이러한 수식은 한 번 이상 등장합니다.
    -   결괏값이 음수가 되거나 서로 모순되는 수식은 주어지지 않습니다.

## 해결
성립하는 진법을 모두 찾아야 합니다. => `브루트포스`
- 수식 문자열 파싱은 `정규 표현식`을 사용하면 간편하게 파싱할 수 있습니다.
- 진법 변환은 자릿수를 기준으로 변환하면 됩니다.
- 수식의 정답을 비교할 때는 주어진 진법으로 변환하고 비교합니다.

```
1. 성립하는 진법 범위 확인
	- (max(모든 정수의 각 자릿수) + 1)진법부터 9진법까지 가능
2. 모든 진법 확인하여 진법 필터링
	- 현재 진법 기준으로 답이 있는 수식의 연산이 모두 성립하면 통과
3. X값 계산: 모든 X 수식 조사
	- 모든 진법에서 같은 답 나오면 해당 답 기록
	- 그렇지 않다면 ? 기록
```

## 코드
```
#include <string>
#include <vector>
#include <regex>
using namespace std;
struct Expr { int a, b, c; bool add; };
vector<Expr> X, N;
vector<string> finalX;
bool base[10];

void parshing(string str) {
    int s = 0; Expr expr;
    regex reg("(\\d+|[+\\-*/=])");  smatch match;
    sregex_iterator begin(str.begin(), str.end(), reg), end;
    for (sregex_iterator i = begin; i != end; i++, s++) {
        if (s == 0)
            expr.a = stoi(i->str());
        if (s == 1)
            expr.add = i->str() == "+";
        if (s == 2)
            expr.b = stoi(i->str());
        if (s == 4) 
            expr.c = stoi(i->str());
    }
    str[str.size() - 1] == 'X' ? (X.push_back(expr), finalX.push_back(str)) : N.push_back(expr);
}

vector<string> solution(vector<string> expressions) {
    int lo = 1, hi = 9;
    for (string str : expressions)
        parshing(str);

    for (Expr expr : X)
        lo = max(lo, max(expr.a / 10, max(expr.a % 10, max(expr.b / 10, expr.b % 10))));
    for (Expr expr : N)
        lo = max(lo, max(expr.a / 10, max(expr.a % 10, max(expr.b / 10, max(expr.b % 10, max(expr.c / 100, max((expr.c % 100) / 10, expr.c % 10)))))));
    lo++;

    for (int bs = lo; bs <= hi; bs++) {
        base[bs] = 1;
        for (Expr expr : N) {
            int A = ((expr.a / 10) * bs) + expr.a % 10;
            int B = ((expr.b / 10) * bs) + expr.b % 10;
            int C = ((expr.c / 100) * bs * bs) + (((expr.c % 100) / 10) * bs) + expr.c % 10;
            base[bs] &= expr.add ? A + B == C : A - B == C;
        }
    }

    for (int i = 0; i < X.size(); i++) {
        Expr expr = X[i];
        vector<int> answers; bool isSame = 0; int answerBase = 0;
        for (int bs = lo; bs <= hi; bs++) {
            if (base[bs]) {
                int A = ((expr.a / 10) * bs) + expr.a % 10;
                int B = ((expr.b / 10) * bs) + expr.b % 10;
                int C = expr.add ? A + B : A - B;
                int subC[3] = { C / (bs * bs), (C % (bs * bs)) / bs, C % bs };
                answers.push_back(subC[0] * 100 + subC[1] * 10 + subC[2]);
            }
        }
        if (answers.size() > 0) {
            answerBase = answers[0]; isSame = 1;
            for (int answer : answers)
                isSame &= answerBase == answer;
        }
        if (isSame)
            finalX[i] = finalX[i].substr(0, finalX[i].size() - 1) + to_string(answerBase);
        else
            finalX[i][finalX[i].size() - 1] = '?';
    }
    return finalX;
}
```

## 링크
<br>https://school.programmers.co.kr/learn/courses/30/lessons/340210
{% endraw %}