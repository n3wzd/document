---
categories:
- Programmers
date: '2024-12-02'
title: '[Programmers] 연습문제 - 과제 진행하기'
---

{% raw %}
> Lv. 2<br>

## 문제
과제를 받은 루는 다음과 같은 순서대로 과제를 하려고 계획을 세웠습니다.

-   과제는 시작하기로 한 시각이 되면 시작합니다.
-   새로운 과제를 시작할 시각이 되었을 때, 기존에 진행 중이던 과제가 있다면 진행 중이던 과제를 멈추고 새로운 과제를 시작합니다.
-   진행중이던 과제를 끝냈을 때, 잠시 멈춘 과제가 있다면, 멈춰둔 과제를 이어서 진행합니다.
    -   만약, 과제를 끝낸 시각에 새로 시작해야 되는 과제와 잠시 멈춰둔 과제가 모두 있다면, 새로 시작해야 하는 과제부터 진행합니다.
-   멈춰둔 과제가 여러 개일 경우, 가장 최근에 멈춘 과제부터 시작합니다.

과제 계획을 담은 이차원 문자열 배열  `plans`가 매개변수로 주어질 때, 과제를 끝낸 순서대로 이름을 배열에 담아 return 하는 solution 함수를 완성해주세요.

### 제한사항
-   3 ≤  `plans`의 길이 ≤ 1,000
    -   `plans`의 원소는 [name, start, playtime]의 구조로 이루어져 있습니다.
        -   name : 과제의 이름을 의미합니다.
            -   2 ≤ name의 길이 ≤ 10
            -   name은 알파벳 소문자로만 이루어져 있습니다.
            -   name이 중복되는 원소는 없습니다.
        -   start : 과제의 시작 시각을 나타냅니다.
            -   "hh:mm"의 형태로 "00:00" ~ "23:59" 사이의 시간값만 들어가 있습니다.
            -   모든 과제의 시작 시각은 달라서 겹칠 일이 없습니다.
            -   과제는 "00:00" ... "23:59" 순으로 시작하면 됩니다. 즉, 시와 분의 값이 작을수록 더 빨리 시작한 과제입니다.
        -   playtime : 과제를 마치는데 걸리는 시간을 의미하며, 단위는 분입니다.
            -   1 ≤ playtime ≤ 100
            -   playtime은 0으로 시작하지 않습니다.
        -   배열은 시간순으로 정렬되어 있지 않을 수 있습니다.
-   진행중이던 과제가 끝나는 시각과 새로운 과제를 시작해야하는 시각이 같은 경우 진행중이던 과제는 끝난 것으로 판단합니다.

## 해결
- 나중에 추가된 원소가 먼저 나가는 후입선출 자료 구조가 필요합니다. => `스택`
- 입력을 시작 시간순으로 `정렬`합니다. (시간 문자열은 정수로 변환해서 사용합니다.)
- 새로운 과제가 주어지면, 스택에 있는 진행 중인 과제가 끝나는 시간과 새로운 과제의 시작 시간을 비교합니다. 과제가 모두 끝났거나, 진행 중인 과제가 끝나는 시간이 새로운 과제 시작 시간보다 클 때 새로운 과제를 스택에 추가합니다. (그렇지 않다면 진행 중인 과제를 차례대로 완료합니다.)
- 진행 중인 과제의 진행 시간은 진행 중인 과제 앞에 새로운 과제가 추가될 때, 시작 시간은 앞에 하던 과제가 완료될 때 업데이트됩니다.

```
1. 과제 목록: 시작 시간 오름차순 정렬
2. 과제 목록 순회:
	1. 최근 과제의 완료 시간이 다음 과제의 시작 시간보다 클 때까지 진행:
		- 최근 과제의 이전 과제 시작 시간 업데이트
		- 최근 과제 완료
	2. 최근 과제의 진행 시간 업데이트
	3. 다음 과제 추가
3. 스택에 남은 모든 과제 순서대로 완료
```

## 코드
```
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
struct Node { string id; int s, d; };
int ttoi(string s) { return stoi(s.substr(0, 2)) * 60 + stoi(s.substr(3, 2)); }
stack<Node> stk;
vector<Node> P;

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    for(auto p : plans)
        P.push_back({p[0], ttoi(p[1]), stoi(p[2])});
    sort(P.begin(), P.end(), [](Node &a, Node &b) { return a.s < b.s; });
    for(auto p : P) {
        while(!stk.empty() && stk.top().s + stk.top().d <= p.s) {
            Node cur = stk.top(); stk.pop();
            answer.push_back(cur.id);
            if(!stk.empty())
                stk.top().s = cur.s + cur.d;
        }
        if(!stk.empty())
            stk.top().d -= p.s - stk.top().s;
        stk.push(p);
    }
    while(!stk.empty())
        answer.push_back(stk.top().id), stk.pop();
    return answer;
}
```

## 링크
<br>https://school.programmers.co.kr/learn/courses/30/lessons/176962
{% endraw %}