---
categories:
- Programmers
date: '2024-12-06'
title: '[Programmers] 연습문제 - 달리기 경주'
---

{% raw %}
> Lv. 1<br>

## 문제
얀에서는 매년 달리기 경주가 열립니다. 해설진들은 선수들이 자기 바로 앞의 선수를 추월할 때 추월한 선수의 이름을 부릅니다. 예를 들어 1등부터 3등까지 "mumu", "soe", "poe" 선수들이 순서대로 달리고 있을 때, 해설진이 "soe"선수를 불렀다면 2등인 "soe" 선수가 1등인 "mumu" 선수를 추월했다는 것입니다. 즉 "soe" 선수가 1등, "mumu" 선수가 2등으로 바뀝니다.

선수들의 이름이 1등부터 현재 등수 순서대로 담긴 문자열 배열  `players`와 해설진이 부른 이름을 담은 문자열 배열  `callings`가 매개변수로 주어질 때, 경주가 끝났을 때 선수들의 이름을 1등부터 등수 순서대로 배열에 담아 return 하는 solution 함수를 완성해주세요.

### 제한사항
-   5 ≤  `players`의 길이 ≤ 50,000
    -   `players[i]`는 i번째 선수의 이름을 의미합니다.
    -   `players`의 원소들은 알파벳 소문자로만 이루어져 있습니다.
    -   `players`에는 중복된 값이 들어가 있지 않습니다.
    -   3 ≤  `players[i]`의 길이 ≤ 10
-   2 ≤  `callings`의 길이 ≤ 1,000,000
    -   `callings`는  `players`의 원소들로만 이루어져 있습니다.
    -   경주 진행중 1등인 선수의 이름은 불리지 않습니다.

## 해결
문자열 리스트에서 문자열 쿼리가 주어졌을 때 해당 문자열을 이전 위치의 것과 swap해야 합니다. 문자열에서 위치, 위치에서 문자열을 찾는 자료구조를 정의하면 됩니다. => 배열, `map`

## 코드
```
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
unordered_map<string, int> ranks;

vector<string> solution(vector<string> players, vector<string> callings) {
    for(int i = 0; i < players.size(); i++)
        ranks[players[i]] = i;
    for(auto cur : callings) {
        int r = ranks[cur]; string next = players[r - 1];
        ranks[cur] = r - 1;
        ranks[next] = r;
        players[r] = next;
        players[r - 1] = cur;
    }
    return players;
}
```

## 링크
<br>https://school.programmers.co.kr/learn/courses/30/lessons/178871
{% endraw %}