---
categories:
- Programmers
date: '2024-11-05'
title: '[Programmers] 2019 KAKAO BLIND RECRUITMENT - 후보키'
---

{% raw %}
> Lv. 2<br>

## 문제
프렌즈대학교 컴퓨터공학과 조교인 제이지는 네오 학과장님의 지시로, 학생들의 인적사항을 정리하는 업무를 담당하게 되었다.

그의 학부 시절 프로그래밍 경험을 되살려, 모든 인적사항을 데이터베이스에 넣기로 하였고, 이를 위해 정리를 하던 중에 후보키(Candidate Key)에 대한 고민이 필요하게 되었다.

후보키에 대한 내용이 잘 기억나지 않던 제이지는, 정확한 내용을 파악하기 위해 데이터베이스 관련 서적을 확인하여 아래와 같은 내용을 확인하였다.

-   관계 데이터베이스에서 릴레이션(Relation)의 튜플(Tuple)을 유일하게 식별할 수 있는 속성(Attribute) 또는 속성의 집합 중, 다음 두 성질을 만족하는 것을 후보 키(Candidate Key)라고 한다.
    -   유일성(uniqueness) : 릴레이션에 있는 모든 튜플에 대해 유일하게 식별되어야 한다.
    -   최소성(minimality) : 유일성을 가진 키를 구성하는 속성(Attribute) 중 하나라도 제외하는 경우 유일성이 깨지는 것을 의미한다. 즉, 릴레이션의 모든 튜플을 유일하게 식별하는 데 꼭 필요한 속성들로만 구성되어야 한다.

제이지를 위해, 아래와 같은 학생들의 인적사항이 주어졌을 때, 후보 키의 최대 개수를 구하라.

위의 예를 설명하면, 학생의 인적사항 릴레이션에서 모든 학생은 각자 유일한 "학번"을 가지고 있다. 따라서 "학번"은 릴레이션의 후보 키가 될 수 있다.  
그다음 "이름"에 대해서는 같은 이름("apeach")을 사용하는 학생이 있기 때문에, "이름"은 후보 키가 될 수 없다. 그러나, 만약 ["이름", "전공"]을 함께 사용한다면 릴레이션의 모든 튜플을 유일하게 식별 가능하므로 후보 키가 될 수 있게 된다.  
물론 ["이름", "전공", "학년"]을 함께 사용해도 릴레이션의 모든 튜플을 유일하게 식별할 수 있지만, 최소성을 만족하지 못하기 때문에 후보 키가 될 수 없다.  
따라서, 위의 학생 인적사항의 후보키는 "학번", ["이름", "전공"] 두 개가 된다.

릴레이션을 나타내는 문자열 배열 relation이 매개변수로 주어질 때, 이 릴레이션에서 후보 키의 개수를 return 하도록 solution 함수를 완성하라.

### 제한사항
-   relation은 2차원 문자열 배열이다.
-   relation의 컬럼(column)의 길이는  `1`  이상  `8`  이하이며, 각각의 컬럼은 릴레이션의 속성을 나타낸다.
-   relation의 로우(row)의 길이는  `1`  이상  `20`  이하이며, 각각의 로우는 릴레이션의 튜플을 나타낸다.
-   relation의 모든 문자열의 길이는  `1`  이상  `8`  이하이며, 알파벳 소문자와 숫자로만 이루어져 있다.
-   relation의 모든 튜플은 유일하게 식별 가능하다.(즉, 중복되는 튜플은 없다.)

## 해결
- 키는 집합입니다. `조합`을 사용해서 모든 집합을 판별합니다.
- 어떠한 키에 대해 유일성을 만족하라면, 키가 포함한 속성들만 봤을 때 모든 튜플에서 중복이 없어야 합니다. 각 튜플에서 속성에 해당되는 데이터들을 일렬로 연결한 문자열들에 대해 중복을 판정합니다. => `set` 사용<br>
	- 속성별로 데이터는 구분됩니다. (예 "A", "BC" vs "AB", "C") 일렬로 연결할 때는 구분 문자를 사이에 넣어줍시다.
- 최소성은 어떠한 후보키에 다른 후보키가 포함되면 안되는 것을 의미합니다. 따라서 새로운 키를 판정하기 전에 포함 검사를 해야 합니다. 후보키는 boolean 배열이므로 `비트마스킹`으로 저장할 수 있으며, 부분 집합 판정은 존재하는 후보키 비트 값이 판정할 키에 모두 포함되는지를 확인하면 됩니다.

## 코드
```
#include <string>
#include <vector>
#include <queue>
#include <set>
using namespace std;
vector<vector<string>> R; vector<int> candidate;<br>
bool selected[9];
int N, M, cnt;

void combination(int len, int start) {
    if (len == 0) {
        int key = 0;
        for (int x = 0; x < M; x++)
            if(selected[x])
                key |= 1 << x;
        for(auto ck : candidate) {
            bool ok = 1;
            for (int x = 0; x < M; x++)
                if(ck & 1 << x)
                    ok &= !((key & 1 << x) ^ (ck & 1 << x));
            if(ok) return;
        }      
        set<string> S;<br>
        for (int y = 0; y < N; y++) {
            string tmp = "";
            for (int x = 0; x < M; x++)
                if (selected[x])
                    tmp += R[y][x] + "|";
            if (S.find(tmp) != S.end())
                return;
            S.insert(tmp);
        }
        candidate.push_back(key);
        cnt++; return;
    }
    for (int i = start; i < M; i++) {
        selected[i] = 1;
        combination(len - 1, i + 1);
        selected[i] = 0;
    }
}

int solution(vector<vector<string>> relation) {<br>
    R = relation; N = R.size(), M = R[0].size();
    for (int d = 1; d <= M; d++)
        combination(d, 0);
    return cnt;
}
```

## 링크
https://school.programmers.co.kr/learn/courses/30/lessons/42890
{% endraw %}