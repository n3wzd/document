---
categories:
- Programmers
date: '2024-10-31'
title: '[Programmers] 2022 KAKAO BLIND RECRUITMENT - 신고 결과 받기'
---

{% raw %}
> Lv. 1<br>

## 문제
신입사원 무지는 게시판 불량 이용자를 신고하고 처리 결과를 메일로 발송하는 시스템을 개발하려 합니다. 무지가 개발하려는 시스템은 다음과 같습니다.

-   각 유저는 한 번에 한 명의 유저를 신고할 수 있습니다.
    -   신고 횟수에 제한은 없습니다. 서로 다른 유저를 계속해서 신고할 수 있습니다.
    -   한 유저를 여러 번 신고할 수도 있지만, 동일한 유저에 대한 신고 횟수는 1회로 처리됩니다.
-   k번 이상 신고된 유저는 게시판 이용이 정지되며, 해당 유저를 신고한 모든 유저에게 정지 사실을 메일로 발송합니다.
    -   유저가 신고한 모든 내용을 취합하여 마지막에 한꺼번에 게시판 이용 정지를 시키면서 정지 메일을 발송합니다.

이용자의 ID가 담긴 문자열 배열  `id_list`, 각 이용자가 신고한 이용자의 ID 정보가 담긴 문자열 배열  `report`, 정지 기준이 되는 신고 횟수  `k`가 매개변수로 주어질 때, 각 유저별로 처리 결과 메일을 받은 횟수를 배열에 담아 return 하도록 solution 함수를 완성해주세요.

### 제한사항
-   2 ≤  `id_list`의 길이 ≤ 1,000
    -   1 ≤  `id_list`의 원소 길이 ≤ 10
    -   `id_list`의 원소는 이용자의 id를 나타내는 문자열이며 알파벳 소문자로만 이루어져 있습니다.
    -   `id_list`에는 같은 아이디가 중복해서 들어있지 않습니다.
-   1 ≤  `report`의 길이 ≤ 200,000
    -   3 ≤  `report`의 원소 길이 ≤ 21
    -   `report`의 원소는 "이용자id 신고한id"형태의 문자열입니다.
    -   예를 들어 "muzi frodo"의 경우 "muzi"가 "frodo"를 신고했다는 의미입니다.
    -   id는 알파벳 소문자로만 이루어져 있습니다.
    -   이용자id와 신고한id는 공백(스페이스)하나로 구분되어 있습니다.
    -   자기 자신을 신고하는 경우는 없습니다.
-   1 ≤  `k`  ≤ 200,  `k`는 자연수입니다.
-   return 하는 배열은  `id_list`에 담긴 id 순서대로 각 유저가 받은 결과 메일 수를 담으면 됩니다.

## 해결
- 문자열을 인덱싱해야 합니다. `map`을 사용합니다.
- 한 유저가 같은 유저를 여러 번 신고하는 것은 1회로 처리합니다. 2차원 격자나 `set`으로 중복 판정을 합니다.

## 코드
```
#include <string>
#include <sstream>
#include <vector>
#include <map>
using namespace std;
map<string, int> m;<br>
int cnt[1001], genID;
bool cert[1001][1001];

vector<int> solution(vector<string> id_list, vector<string> report, int k) {<br>
    vector<int> answer;<br>
    for(auto s : id_list)
        m.insert({s, genID++});
    for(auto r : report) {
        istringstream iss(r);
        string a, b; iss >> a >> b;<br>
        int user1 = m.find(a)->second, user2 = m.find(b)->second;
        if(!cert[user1][user2]) {
            cert[user1][user2] = 1;
            cnt[user2]++;
        }
    }
    for(auto r : id_list) {
        int mail = 0, user = m.find(r)->second;
        for(int i = 0; i < id_list.size(); i++)
            if(cert[user][i] && cnt[i] >= k)
                mail++;
        answer.push_back(mail);
    }
    return answer;
}
```

## 링크
https://school.programmers.co.kr/learn/courses/30/lessons/92334<br>
{% endraw %}