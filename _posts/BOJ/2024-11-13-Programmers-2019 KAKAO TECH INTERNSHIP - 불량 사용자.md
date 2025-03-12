---
categories:
- Programmers
date: '2024-11-13'
title: '[Programmers] 2019 KAKAO TECH INTERNSHIP - 불량 사용자'
---

{% raw %}
> Lv. 3<br>

## 문제
개발팀 내에서 이벤트 개발을 담당하고 있는 "무지"는 최근 진행된 카카오이모티콘 이벤트에 비정상적인 방법으로 당첨을 시도한 응모자들을 발견하였습니다. 이런 응모자들을 따로 모아  `불량 사용자`라는 이름으로 목록을 만들어서 당첨 처리 시 제외하도록 이벤트 당첨자 담당자인 "프로도" 에게 전달하려고 합니다. 이 때 개인정보 보호을 위해 사용자 아이디 중 일부 문자를 '*' 문자로 가려서 전달했습니다. 가리고자 하는 문자 하나에 '*' 문자 하나를 사용하였고 아이디 당 최소 하나 이상의 '*' 문자를 사용하였습니다.  
"무지"와 "프로도"는 불량 사용자 목록에 매핑된 응모자 아이디를  `제재 아이디`  라고 부르기로 하였습니다.

이벤트 응모자 아이디 목록이 담긴 배열 user_id와 불량 사용자 아이디 목록이 담긴 배열 banned_id가 매개변수로 주어질 때, 당첨에서 제외되어야 할 제재 아이디 목록은 몇가지 경우의 수가 가능한 지 return 하도록 solution 함수를 완성해주세요.

### 제한사항
-   user_id 배열의 크기는 1 이상 8 이하입니다.
-   user_id 배열 각 원소들의 값은 길이가 1 이상 8 이하인 문자열입니다.
    -   응모한 사용자 아이디들은 서로 중복되지 않습니다.
    -   응모한 사용자 아이디는 알파벳 소문자와 숫자로만으로 구성되어 있습니다.
-   banned_id 배열의 크기는 1 이상 user_id 배열의 크기 이하입니다.
-   banned_id 배열 각 원소들의 값은 길이가 1 이상 8 이하인 문자열입니다.
    -   불량 사용자 아이디는 알파벳 소문자와 숫자, 가리기 위한 문자 '*' 로만 이루어져 있습니다.
    -   불량 사용자 아이디는 '*' 문자를 하나 이상 포함하고 있습니다.
    -   불량 사용자 아이디 하나는 응모자 아이디 중 하나에 해당하고 같은 응모자 아이디가 중복해서 제재 아이디 목록에 들어가는 경우는 없습니다.
-   제재 아이디 목록들을 구했을 때 아이디들이 나열된 순서와 관계없이 아이디 목록의 내용이 동일하다면 같은 것으로 처리하여 하나로 세면 됩니다.

## 해결
집합(제재 아이디 목록)을 원소로 하는 집합의 크기(제재 아이디 목록의 경우의 수)를 찾아야 합니다. => `set` 자료구조 사용

각 불량 사용자에 해당되는 응모자 아이디를 모두 찾은 뒤, 하나씩 제재 아이디 목록을 만들어보면 됩니다. 여기서 사용되는 집합 내부에는 순서가 구분되지 않고 중복된 원소가 없어야 합니다.

```
1. 각 불량 사용자에 해당되는 응모자 아이디 모두 찾기
2. 모든 제재 아이디 목록 확인:
	1. 제재 아이디 선택: 각 불량 사용자에서 응모자 아이디 1개씩 추출
		- 제재 아이디는 서로 중복될 수 없음
	2. 제재 아이디 목록을 최종 집합에 추가
3. 최종 집합 크기 출력
```

## 코드
```
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
set<string> S;
vector<int> caught[8];
int selected[8], N, M;

bool cmp(string user, string ban) {
    if(user.size() != ban.size())
        return 0;
    for(int i = 0; i < user.size(); i++)
        if(ban[i] != '*' && user[i] != ban[i])
            return 0;
    return 1;
}

void BT(int depth) {
    if(depth == N) {
        int item[8];
        for(int i = 0; i < N; i++)
            item[i] = selected[i];
        sort(item, item + N);
        
        string res = "";
        for(int i = 0; i < N; i++)
            res += to_string(item[i]);
        S.insert(res);
        return;
    }
    for(int i = 0; i < caught[depth].size(); i++) {
        bool ok = 1;
        for(int j = 0; j < depth; j++)
            ok &= caught[depth][i] != selected[j];
        if(ok) {
            selected[depth] = caught[depth][i];
            BT(depth + 1);
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    N = banned_id.size(), M = user_id.size();
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            if(cmp(user_id[j], banned_id[i]))
                caught[i].push_back(j);
    BT(0);
    return S.size();
}
```

## 링크
<br>https://school.programmers.co.kr/learn/courses/30/lessons/64064
{% endraw %}