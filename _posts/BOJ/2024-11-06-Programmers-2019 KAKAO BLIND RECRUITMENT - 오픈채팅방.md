---
categories:
- Programmers
date: '2024-11-06'
title: '[Programmers] 2019 KAKAO BLIND RECRUITMENT - 오픈채팅방'
---

{% raw %}
> Lv. 2<br>

## 문제
카카오톡 오픈채팅방에서는 친구가 아닌 사람들과 대화를 할 수 있는데, 본래 닉네임이 아닌 가상의 닉네임을 사용하여 채팅방에 들어갈 수 있다.

신입사원인 김크루는 카카오톡 오픈 채팅방을 개설한 사람을 위해, 다양한 사람들이 들어오고, 나가는 것을 지켜볼 수 있는 관리자창을 만들기로 했다. 채팅방에 누군가 들어오면 다음 메시지가 출력된다.

"[닉네임]님이 들어왔습니다."

채팅방에서 누군가 나가면 다음 메시지가 출력된다.

"[닉네임]님이 나갔습니다."

채팅방에서 닉네임을 변경하는 방법은 다음과 같이 두 가지이다.

-   채팅방을 나간 후, 새로운 닉네임으로 다시 들어간다.
-   채팅방에서 닉네임을 변경한다.

닉네임을 변경할 때는 기존에 채팅방에 출력되어 있던 메시지의 닉네임도 전부 변경된다.

예를 들어, 채팅방에 "Muzi"와 "Prodo"라는 닉네임을 사용하는 사람이 순서대로 들어오면 채팅방에는 다음과 같이 메시지가 출력된다.

"Muzi님이 들어왔습니다."  
"Prodo님이 들어왔습니다."

채팅방에 있던 사람이 나가면 채팅방에는 다음과 같이 메시지가 남는다.

"Muzi님이 들어왔습니다."  
"Prodo님이 들어왔습니다."  
"Muzi님이 나갔습니다."

Muzi가 나간후 다시 들어올 때, Prodo 라는 닉네임으로 들어올 경우 기존에 채팅방에 남아있던 Muzi도 Prodo로 다음과 같이 변경된다.

"Prodo님이 들어왔습니다."  
"Prodo님이 들어왔습니다."  
"Prodo님이 나갔습니다."  
"Prodo님이 들어왔습니다."

채팅방은 중복 닉네임을 허용하기 때문에, 현재 채팅방에는 Prodo라는 닉네임을 사용하는 사람이 두 명이 있다. 이제, 채팅방에 두 번째로 들어왔던 Prodo가 Ryan으로 닉네임을 변경하면 채팅방 메시지는 다음과 같이 변경된다.

"Prodo님이 들어왔습니다."  
"Ryan님이 들어왔습니다."  
"Prodo님이 나갔습니다."  
"Prodo님이 들어왔습니다."

채팅방에 들어오고 나가거나, 닉네임을 변경한 기록이 담긴 문자열 배열 record가 매개변수로 주어질 때, 모든 기록이 처리된 후, 최종적으로 방을 개설한 사람이 보게 되는 메시지를 문자열 배열 형태로 return 하도록 solution 함수를 완성하라.

### 제한사항
-   record는 다음과 같은 문자열이 담긴 배열이며, 길이는  `1`  이상  `100,000`  이하이다.
-   다음은 record에 담긴 문자열에 대한 설명이다.
    -   모든 유저는 [유저 아이디]로 구분한다.
    -   [유저 아이디] 사용자가 [닉네임]으로 채팅방에 입장 - "Enter [유저 아이디] [닉네임]" (ex. "Enter uid1234 Muzi")
    -   [유저 아이디] 사용자가 채팅방에서 퇴장 - "Leave [유저 아이디]" (ex. "Leave uid1234")
    -   [유저 아이디] 사용자가 닉네임을 [닉네임]으로 변경 - "Change [유저 아이디] [닉네임]" (ex. "Change uid1234 Muzi")
    -   첫 단어는 Enter, Leave, Change 중 하나이다.
    -   각 단어는 공백으로 구분되어 있으며, 알파벳 대문자, 소문자, 숫자로만 이루어져있다.
    -   유저 아이디와 닉네임은 알파벳 대문자, 소문자를 구별한다.
    -   유저 아이디와 닉네임의 길이는  `1`  이상  `10`  이하이다.
    -   채팅방에서 나간 유저가 닉네임을 변경하는 등 잘못 된 입력은 주어지지 않는다.

## 해결
- 문자열을 인덱싱하므로 `맵`을 사용합니다.
- 먼저 로그를 순회하여 유저 아이디별 최종 닉네임을 찾습니다. 그리고 로그를 다시 순회해서 메시지를 출력하면 됩니다.

## 코드
```
#include <string>
#include <vector>
#include <map>
#include <sstream>
using namespace std;
map<string, string> m;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    for(auto r : record) {
        istringstream iss(r);
        string a, b, c; iss >> a >> b >> c;
        if(a == "Enter") m[b] = c;
        if(a == "Change") m[b] = c;
    }
    for(auto r : record) {
        istringstream iss(r);
        string a, b; iss >> a >> b;
        if(a == "Enter")
            answer.push_back(m[b] + "님이 들어왔습니다.");
        if(a == "Leave")
            answer.push_back(m[b] + "님이 나갔습니다.");
    }
    return answer;
}
```

## 링크
<br>https://school.programmers.co.kr/learn/courses/30/lessons/42888
{% endraw %}