---
categories:
- Programmers
date: '2024-12-24'
title: '[Programmers] 연습문제 - 가장 가까운 같은 글자'
---

{% raw %}
> Lv. 1<br>

## 문제
문자열  `s`가 주어졌을 때,  `s`의 각 위치마다 자신보다 앞에 나왔으면서, 자신과 가장 가까운 곳에 있는 같은 글자가 어디 있는지 알고 싶습니다.  
예를 들어,  `s`="banana"라고 할 때, 각 글자들을 왼쪽부터 오른쪽으로 읽어 나가면서 다음과 같이 진행할 수 있습니다.

-   b는 처음 나왔기 때문에 자신의 앞에 같은 글자가 없습니다. 이는 -1로 표현합니다.
-   a는 처음 나왔기 때문에 자신의 앞에 같은 글자가 없습니다. 이는 -1로 표현합니다.
-   n은 처음 나왔기 때문에 자신의 앞에 같은 글자가 없습니다. 이는 -1로 표현합니다.
-   a는 자신보다 두 칸 앞에 a가 있습니다. 이는 2로 표현합니다.
-   n도 자신보다 두 칸 앞에 n이 있습니다. 이는 2로 표현합니다.
-   a는 자신보다 두 칸, 네 칸 앞에 a가 있습니다. 이 중 가까운 것은 두 칸 앞이고, 이는 2로 표현합니다.

따라서 최종 결과물은 [-1, -1, -1, 2, 2, 2]가 됩니다.

문자열  `s`이 주어질 때, 위와 같이 정의된 연산을 수행하는 함수 solution을 완성해주세요.

### 제한사항
-   1 ≤  `s`의 길이 ≤ 10,000
    -   `s`은 영어 소문자로만 이루어져 있습니다.

## 해결
문자열을 탐색하며 문자의 위치를 기록합니다. 현재 문자 위치와 해당 문자의 가장 최근 위치를 계산하면 됩니다.

## 코드
```
#include <string>
#include <vector>
using namespace std;
vector<int> p(26, -1);

vector<int> solution(string s) {
    vector<int> answer;
    for(int i = 0; i < s.size(); i++) {
        answer.push_back(p[s[i] - 'a'] == -1 ? -1 : i - p[s[i] - 'a']);
        p[s[i] - 'a'] = i;
    }
    return answer;
}
```

## 링크
<br>https://school.programmers.co.kr/learn/courses/30/lessons/142086
{% endraw %}