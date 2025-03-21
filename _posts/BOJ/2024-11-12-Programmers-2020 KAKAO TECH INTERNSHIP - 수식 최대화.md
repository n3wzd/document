---
categories:
- Programmers
date: '2024-11-12'
title: '[Programmers] 2020 KAKAO TECH INTERNSHIP - 수식 최대화'
---

{% raw %}
> Lv. 2<br>

## 문제
IT 벤처 회사를 운영하고 있는  `라이언`은 매년 사내 해커톤 대회를 개최하여 우승자에게 상금을 지급하고 있습니다.  
이번 대회에서는 우승자에게 지급되는 상금을 이전 대회와는 다르게 다음과 같은 방식으로 결정하려고 합니다.  
해커톤 대회에 참가하는 모든 참가자들에게는 숫자들과 3가지의 연산문자(`+, -, *`) 만으로 이루어진 연산 수식이 전달되며, 참가자의 미션은 전달받은 수식에 포함된 연산자의 우선순위를 자유롭게 재정의하여 만들 수 있는 가장 큰 숫자를 제출하는 것입니다.  
단, 연산자의 우선순위를 새로 정의할 때, 같은 순위의 연산자는 없어야 합니다. 즉,  `+`  >  `-`  >  `*`  또는  `-`  >  `*`  >  `+`  등과 같이 연산자 우선순위를 정의할 수 있으나  `+,*`  >  `-`  또는  `*`  >  `+,-`처럼 2개 이상의 연산자가 동일한 순위를 가지도록 연산자 우선순위를 정의할 수는 없습니다. 수식에 포함된 연산자가 2개라면 정의할 수 있는 연산자 우선순위 조합은 2! = 2가지이며, 연산자가 3개라면 3! = 6가지 조합이 가능합니다.  
만약 계산된 결과가 음수라면 해당 숫자의 절댓값으로 변환하여 제출하며 제출한 숫자가 가장 큰 참가자를 우승자로 선정하며, 우승자가 제출한 숫자를 우승상금으로 지급하게 됩니다.

예를 들어, 참가자 중  `네오`가 아래와 같은 수식을 전달받았다고 가정합니다.

`"100-200*300-500+20"`

일반적으로 수학 및 전산학에서 약속된 연산자 우선순위에 따르면 더하기와 빼기는 서로 동등하며 곱하기는 더하기, 빼기에 비해 우선순위가 높아  `*`  >  `+,-`  로 우선순위가 정의되어 있습니다.  
대회 규칙에 따라  `+`  >  `-`  >  `*`  또는  `-`  >  `*`  >  `+`  등과 같이 연산자 우선순위를 정의할 수 있으나  `+,*`  >  `-`  또는  `*`  >  `+,-`  처럼 2개 이상의 연산자가 동일한 순위를 가지도록 연산자 우선순위를 정의할 수는 없습니다.  
수식에 연산자가 3개 주어졌으므로 가능한 연산자 우선순위 조합은 3! = 6가지이며, 그 중  `+`  >  `-`  >  `*`  로 연산자 우선순위를 정한다면 결괏값은 22,000원이 됩니다.  
반면에  `*`  >  `+`  >  `-`  로 연산자 우선순위를 정한다면 수식의 결괏값은 -60,420 이지만, 규칙에 따라 우승 시 상금은 절댓값인 60,420원이 됩니다.

참가자에게 주어진 연산 수식이 담긴 문자열 expression이 매개변수로 주어질 때, 우승 시 받을 수 있는 가장 큰 상금 금액을 return 하도록 solution 함수를 완성해주세요.

### 제한사항
-   expression은 길이가 3 이상 100 이하인 문자열입니다.
-   expression은 공백문자, 괄호문자 없이 오로지 숫자와 3가지의 연산자(`+, -, *`) 만으로 이루어진 올바른 중위표기법(연산의 두 대상 사이에 연산기호를 사용하는 방식)으로 표현된 연산식입니다. 잘못된 연산식은 입력으로 주어지지 않습니다.
    -   즉,  `"402+-561*"`처럼 잘못된 수식은 올바른 중위표기법이 아니므로 주어지지 않습니다.  
        
-   expression의 피연산자(operand)는 0 이상 999 이하의 숫자입니다.
    -   즉,  `"100-2145*458+12"`처럼 999를 초과하는 피연산자가 포함된 수식은 입력으로 주어지지 않습니다.
    -   `"-56+100"`처럼 피연산자가 음수인 수식도 입력으로 주어지지 않습니다.
-   expression은 적어도 1개 이상의 연산자를 포함하고 있습니다.
-   연산자 우선순위를 어떻게 적용하더라도, expression의 중간 계산값과 최종 결괏값은 절댓값이 263  - 1 이하가 되도록 입력이 주어집니다.
-   같은 연산자끼리는 앞에 있는 것의 우선순위가 더 높습니다.

## 해결
수식 우선순위의 모든 경우의 수는 3!이므로 별도의 알고리즘 없이 나이브하게 확인이 가능합니다.

수식의 연산을 구현합시다. 연산자의 우선순위가 존재하므로, 순위별로 연산자를 처리해야 합니다. 즉, 현재 순위에 맞는 연산자는 계산하고 그렇지 않다면 계산하지 않아야 합니다. 이는 `덱`을 사용해서 구현할 수 있습니다.
- 초기화: 수와 연산자를 각각 하나의 원소로 취급하여 수식에 주어진 순서대로 덱에 넣습니다.
- 연산: 덱에서 앞의 3개의 원소(수, 연산자, 수)를 꺼낸 뒤, 계산할 연산자라면 연산한 값을 덱의 앞에 추가합니다. 만약 계산할 연산자가 아니면, 꺼냈던 앞의 수와 연산자는 순서대로 덱의 뒤에 추가하고 마지막에 꺼냈던 수는 덱의 앞에 추가합니다.
- 연산 과정을 덱에 포함되었던 연산자 개수만큼 반복하면 현재 순위에 대한 처리가 완료됩니다. 이때 덱의 앞에는 수식의 가장 끝의 수가 존재하므로 덱의 앞 원소를 꺼내 덱의 뒤에 추가합니다.
- 모든 우선순위 처리를 마치면 덱에는 최종 연산 값만 존재합니다.

```
1. 모든 우선순위 경우 조사:
	1. 덱에 모든 수, 연산자 순서대로 추가
	2. 현재 순위에 대해 수식 연산:
		1. 덱 내부의 연산자 횟수만큼 반복:
			1. 덱 앞의 3개의 원소 꺼내기
			2. 현재 순위에 맞는 연산자라면 연산한 값을 덱의 앞에 추가
			3. 그렇지 않으면 앞의 두 원소는 덱의 뒤, 나머지 하나는 덱의 앞에 추가
		2. 덱의 앞 원소를 꺼내 덱 뒤에 추가
	3. 최종값(덱의 앞 원소) 업데이트
```

## 코드
```
#include <string>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
typedef long long ll;
struct Node { char op; ll n; };
vector<Node> list;

void init(string expr) {
    int lo = 0, hi = 0;
    for (; hi < expr.size(); hi++) {
        if (!(expr[hi] >= '0' && expr[hi] <= '9')) {
            list.push_back({ ' ', stoi(expr.substr(lo, hi - lo)) });
            list.push_back({ expr[hi], 0 });
            lo = hi + 1;
        }
    }
    list.push_back({ ' ', stoi(expr.substr(lo, hi - lo)) });
}

ll cal(vector<int> order) {
    deque<Node> q;
    for (auto n : list)
        q.push_back(n);
    for (auto target : order) {
        int size = q.size();
        while (size > 1) {
            auto a = q.front(); q.pop_front();
            auto op = q.front(); q.pop_front();
            auto b = q.front(); q.pop_front();
            if (op.op == target) {
                if (op.op == '+')
                    q.push_front({ ' ', a.n + b.n });
                if (op.op == '-')
                    q.push_front({ ' ', a.n - b.n });
                if (op.op == '*')
                    q.push_front({ ' ', a.n * b.n });
            }
            else {
                q.push_back(a);
                q.push_back(op);
                q.push_front(b);
            }
            size -= 2;
        }
        q.push_back(q.front()); q.pop_front();
    }
    return abs(q.front().n);
}

ll solution(string expr) {
    init(expr);
    return max(cal({ '+', '-', '*' }), max(cal({ '+', '*', '-' }), 
            max(cal({ '-', '+', '*' }), max(cal({ '-', '*', '+' }),
            max(cal({ '*', '+', '-' }), cal({ '*', '-', '+' }))))));
}
```

## 링크
<br>https://school.programmers.co.kr/learn/courses/30/lessons/67257
{% endraw %}