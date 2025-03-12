---
categories:
- Programmers
date: '2024-12-31'
title: '[Programmers] 연습문제 - 모의고사'
---

{% raw %}
> Lv. 1<br>

## 문제
수포자는 수학을 포기한 사람의 준말입니다. 수포자 삼인방은 모의고사에 수학 문제를 전부 찍으려 합니다. 수포자는 1번 문제부터 마지막 문제까지 다음과 같이 찍습니다.

1번 수포자가 찍는 방식: 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, ...  
2번 수포자가 찍는 방식: 2, 1, 2, 3, 2, 4, 2, 5, 2, 1, 2, 3, 2, 4, 2, 5, ...  
3번 수포자가 찍는 방식: 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, ...

1번 문제부터 마지막 문제까지의 정답이 순서대로 들은 배열 answers가 주어졌을 때, 가장 많은 문제를 맞힌 사람이 누구인지 배열에 담아 return 하도록 solution 함수를 작성해주세요.

### 제한 조건
-   시험은 최대 10,000 문제로 구성되어있습니다.
-   문제의 정답은 1, 2, 3, 4, 5중 하나입니다.
-   가장 높은 점수를 받은 사람이 여럿일 경우, return하는 값을 오름차순 정렬해주세요.

## 해결
주어진 규칙적인 수열 3개와 입력 수열이 일치하는 횟수를 각각 카운팅합니다.

수열 길이는 모두 다를 수 있으므로 `모듈러 연산`을 활용하면 보다 편리하게 구현할 수 있습니다.

## 코드
```
#include <vector>
using namespace std;
vector<int> D[3] = {{1, 2, 3, 4, 5}, {2, 1, 2, 3, 2, 4, 2, 5}, {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}};<br>
int cnt[3], maxScore = 0;

vector<int> solution(vector<int> answers) {<br>
    vector<int> solution;<br>
    for(int i = 0; i < answers.size(); i++)
        for(int d = 0; d < 3; d++)
            cnt[d] += answers[i] == D[d][i % D[d].size()] ? 1 : 0;
    for(int d = 0; d < 3; d++)
        maxScore = max(maxScore, cnt[d]);
    for(int d = 0; d < 3; d++)
        if(cnt[d] == maxScore)
            solution.push_back(d + 1);
    return solution;
}
```

## 링크
https://school.programmers.co.kr/learn/courses/30/lessons/42840<br>
{% endraw %}