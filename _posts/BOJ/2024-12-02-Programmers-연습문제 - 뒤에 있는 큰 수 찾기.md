---
categories:
- Programmers
date: '2024-12-02'
title: '[Programmers] 연습문제 - 뒤에 있는 큰 수 찾기'
---

{% raw %}
> Lv. 2<br>

## 문제
정수로 이루어진 배열  `numbers`가 있습니다. 배열 의 각 원소들에 대해 자신보다 뒤에 있는 숫자 중에서 자신보다 크면서 가장 가까이 있는 수를 뒷 큰수라고 합니다.  
정수 배열  `numbers`가 매개변수로 주어질 때, 모든 원소에 대한 뒷 큰수들을 차례로 담은 배열을 return 하도록 solution 함수를 완성해주세요. 단, 뒷 큰수가 존재하지 않는 원소는 -1을 담습니다.

### 제한사항
-   4 ≤  `numbers`의 길이 ≤ 1,000,000
    -   1 ≤  `numbers[i]`  ≤ 1,000,000

## 해결
다음 예제를 확인해봅시다.
```
N: 8 5 4 3 7
A: - 7 7 7 -
```

다음과 같은 사실을 발견할 수 있습니다.
> 뒤큰수(현재 수보다 앞에 있고 현재 수보다 크기가 작은 수) = 현재 수<br>

최근의 수를 기록했다면 정답을 O(N) 시간 내에 구할 수 있습니다. 최근의 수는 `스택`을 사용해서 저장할 수 있습니다.
```
수열 순회:
1. 이전 수 = 스택의 가장 위의 수
2. 현재 수가 이전 수보다 크다면,
	- 뒤큰수(이전 수) = 현재 수
	- 스택에서 이전 수 제거
3. 현재 수를 스택에 추가
```

수열 순회가 끝났을 때, 스택에 남은 모든 수의 뒤큰수는 -1입니다.

※ `BOJ - 17298 - 오큰수`와 완전히 동일한 문제입니다.

## 코드
```
#include <stack>
#include <vector>
using namespace std;
struct Node { int n, i; };
stack<Node> stk;<br>

vector<int> solution(vector<int> L) {<br>
    int N = L.size(); vector<int> answer(N, 0);<br>
    for(int i = 0; i < N; i++) {
        while(!stk.empty() && stk.top().n < L[i])
            answer[stk.top().i] = L[i], stk.pop();
        stk.push({ L[i], i });
    }
    while(!stk.empty())
        answer[stk.top().i] = -1, stk.pop();
    return answer;
}
```

## 링크
https://school.programmers.co.kr/learn/courses/30/lessons/154539<br>

### 같은 문제
https://www.acmicpc.net/problem/17298<br>
{% endraw %}