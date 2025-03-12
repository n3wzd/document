---
categories:
- Programmers
date: '2024-10-29'
title: '[Programmers] 2023 KAKAO BLIND RECRUITMENT - 이모티콘 할인행사'
---

{% raw %}
> Lv. 2<br>

## 문제
카카오톡에서는 이모티콘을 무제한으로 사용할 수 있는 이모티콘 플러스 서비스 가입자 수를 늘리려고 합니다.  
이를 위해 카카오톡에서는 이모티콘 할인 행사를 하는데, 목표는 다음과 같습니다.

1.  이모티콘 플러스 서비스 가입자를 최대한 늘리는 것.
2.  이모티콘 판매액을 최대한 늘리는 것.

**1번 목표가 우선이며, 2번 목표가 그 다음입니다.**

이모티콘 할인 행사는 다음과 같은 방식으로 진행됩니다.

-   `n`명의 카카오톡 사용자들에게 이모티콘  `m`개를 할인하여 판매합니다.
-   이모티콘마다 할인율은 다를 수 있으며, 할인율은 10%, 20%, 30%, 40% 중 하나로 설정됩니다.

카카오톡 사용자들은 다음과 같은 기준을 따라 이모티콘을 사거나, 이모티콘 플러스 서비스에 가입합니다.

-   각 사용자들은 자신의 기준에 따라 일정 비율 이상 할인하는 이모티콘을 모두 구매합니다.
-   각 사용자들은 자신의 기준에 따라 이모티콘 구매 비용의 합이 일정 가격 이상이 된다면, 이모티콘 구매를 모두 취소하고 이모티콘 플러스 서비스에 가입합니다.

카카오톡 사용자  `n`명의 구매 기준을 담은 2차원 정수 배열  `users`, 이모티콘  `m`개의 정가를 담은 1차원 정수 배열  `emoticons`가 주어집니다. 이때, 행사 목적을 최대한으로 달성했을 때의 이모티콘 플러스 서비스 가입 수와 이모티콘 매출액을 1차원 정수 배열에 담아 return 하도록 solution 함수를 완성해주세요.

### 제한사항

-   1 ≤  `users`의 길이 =  `n`  ≤ 100
    -   `users`의 원소는 [`비율`,  `가격`]의 형태입니다.
    -   `users[i]`는  `i+1`번 고객의 구매 기준을 의미합니다.
    -   `비율`% 이상의 할인이 있는 이모티콘을 모두 구매한다는 의미입니다.
        -   1 ≤  `비율`  ≤ 40
    -   `가격`이상의 돈을 이모티콘 구매에 사용한다면, 이모티콘 구매를 모두 취소하고 이모티콘 플러스 서비스에 가입한다는 의미입니다.
        -   100 ≤  `가격`  ≤ 1,000,000
        -   `가격`은 100의 배수입니다.
-   1 ≤  `emoticons`의 길이 =  `m`  ≤ 7
    -   `emoticons[i]`는  `i+1`번 이모티콘의 정가를 의미합니다.
    -   100 ≤  `emoticons`의 원소 ≤ 1,000,000
    -   `emoticons`의 원소는 100의 배수입니다.

## 해결
입력이 작으므로 모든 할인률 경우를 탐색할 수 있습니다. => `백트래킹`

```
모든 이모티콘 할인율 조사:
1. 모든 사용자 탐색: 이모티콘 구매하기
2. 사용자별로 구매 비용 확인하여 멤버십 가입 또는 수익 증가 업데이트
```

## 코드
```
#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> users;
vector<int> emoticons;
int N, maxMember, maxIncome, sale[7];

void BT(int n = 0) {
    if(n == N) {       
        int member = 0, income = 0;
        for(vector<int> user: users) {
            int preIncome = 0;
            for(int i = 0; i < N; i++)
                if(user[0] <= sale[i])
                    preIncome += emoticons[i] * (100 - sale[i]) / 100;
            preIncome >= user[1] ? member++ : income += preIncome;
        }
        if(member > maxMember || (member == maxMember && income > maxIncome))
            maxMember = member, maxIncome = income;
        return;
    }
    for(int p = 10; p <= 40; p += 10)
        sale[n] = p, BT(n + 1);
}

vector<int> solution(vector<vector<int>> usersI, vector<int> emoticonsI) {
    users = usersI, emoticons = emoticonsI; N = emoticons.size();
    BT(); return { maxMember, maxIncome };
}
```

## 링크
<br>https://school.programmers.co.kr/learn/courses/30/lessons/150368
{% endraw %}