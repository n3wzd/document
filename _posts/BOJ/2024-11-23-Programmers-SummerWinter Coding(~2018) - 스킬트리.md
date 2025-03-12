---
categories:
- Programmers
date: '2024-11-23'
title: '[Programmers] SummerWinter Coding(~2018) - 스킬트리'
---

{% raw %}
> Lv. 2<br>

## 문제
선행 스킬이란 어떤 스킬을 배우기 전에 먼저 배워야 하는 스킬을 뜻합니다.

예를 들어 선행 스킬 순서가  `스파크 → 라이트닝 볼트 → 썬더`일때, 썬더를 배우려면 먼저 라이트닝 볼트를 배워야 하고, 라이트닝 볼트를 배우려면 먼저 스파크를 배워야 합니다.

위 순서에 없는 다른 스킬(힐링 등)은 순서에 상관없이 배울 수 있습니다. 따라서  `스파크 → 힐링 → 라이트닝 볼트 → 썬더`와 같은 스킬트리는 가능하지만,  `썬더 → 스파크`나  `라이트닝 볼트 → 스파크 → 힐링 → 썬더`와 같은 스킬트리는 불가능합니다.

선행 스킬 순서 skill과 유저들이 만든 스킬트리를 담은 배열 skill_trees가 매개변수로 주어질 때, 가능한 스킬트리 개수를 return 하는 solution 함수를 작성해주세요.

### 제한 조건
-   스킬은 알파벳 대문자로 표기하며, 모든 문자열은 알파벳 대문자로만 이루어져 있습니다.
-   스킬 순서와 스킬트리는 문자열로 표기합니다.
    -   예를 들어,  `C → B → D`  라면 "CBD"로 표기합니다
-   선행 스킬 순서 skill의 길이는 1 이상 26 이하이며, 스킬은 중복해 주어지지 않습니다.
-   skill_trees는 길이 1 이상 20 이하인 배열입니다.
-   skill_trees의 원소는 스킬을 나타내는 문자열입니다.
    -   skill_trees의 원소는 길이가 2 이상 26 이하인 문자열이며, 스킬이 중복해 주어지지 않습니다.

## 해결
선행 스킬 트리에 없는 스킬은 영향을 주지 않습니다. 스킬 트리에서 필요한 스킬만 추출하고, 시작 스킬부터 선행 스킬 트리와 비교합니다. 모두 일치하면 가능한 스킬 트리입니다. (예: 선행 스킬 트리가 "CBD"이면, "CBD", "CB", "C"가 가능합니다.)

```
1. 스킬 트리에서 무관한 스킬 모두 삭제
2. 시점 일치하여 추출한 스킬 트리와 선행 스킬 트리 비교
	- 일치하면 통과
```

## 코드
```
#include <string>
#include <vector>
using namespace std;
bool tech[26];

int solution(string user_skill, vector<string> skill_trees) {<br>
    int answer = 0;
    for(auto skill : user_skill)
        tech[skill - 'A'] = 1;
    for(auto skill_tree : skill_trees) {
        string ext = "";
        for(auto skill : skill_tree)
            if(tech[skill - 'A'])
                ext += skill;
        bool ok = 1;
        for(int i = 0; i < ext.size(); i++)
            ok &= ext[i] == user_skill[i];
        answer += ok ? 1 : 0;
    }
    return answer;
}
```

## 링크
https://school.programmers.co.kr/learn/courses/30/lessons/49993<br>
{% endraw %}