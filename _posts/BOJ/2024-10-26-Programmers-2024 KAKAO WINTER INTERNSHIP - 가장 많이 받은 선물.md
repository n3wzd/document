---
categories:
- Programmers
date: '2024-10-26'
title: '[Programmers] 2024 KAKAO WINTER INTERNSHIP - 가장 많이 받은 선물'
---

{% raw %}
> Lv. 1<br>

## 문제
선물을 직접 전하기 힘들 때 카카오톡 선물하기 기능을 이용해 축하 선물을 보낼 수 있습니다. 당신의 친구들이 이번 달까지 선물을 주고받은 기록을 바탕으로 다음 달에 누가 선물을 많이 받을지 예측하려고 합니다.

-   두 사람이 선물을 주고받은 기록이 있다면, 이번 달까지 두 사람 사이에 더 많은 선물을 준 사람이 다음 달에 선물을 하나 받습니다.
    -   예를 들어  `A`가  `B`에게 선물을 5번 줬고,  `B`가  `A`에게 선물을 3번 줬다면 다음 달엔  `A`가  `B`에게 선물을 하나 받습니다.
-   두 사람이 선물을 주고받은 기록이 하나도 없거나 주고받은 수가 같다면, 선물 지수가 더 큰 사람이 선물 지수가 더 작은 사람에게 선물을 하나 받습니다.
    -   선물 지수는 이번 달까지 자신이 친구들에게 준 선물의 수에서 받은 선물의 수를 뺀 값입니다.
    -   예를 들어  `A`가 친구들에게 준 선물이 3개고 받은 선물이 10개라면  `A`의 선물 지수는 -7입니다.  `B`가 친구들에게 준 선물이 3개고 받은 선물이 2개라면  `B`의 선물 지수는 1입니다. 만약  `A`와  `B`가 선물을 주고받은 적이 없거나 정확히 같은 수로 선물을 주고받았다면, 다음 달엔  `B`가  `A`에게 선물을 하나 받습니다.
    -   **만약 두 사람의 선물 지수도 같다면 다음 달에 선물을 주고받지 않습니다.**

위에서 설명한 규칙대로 다음 달에 선물을 주고받을 때, 당신은 선물을 가장 많이 받을 친구가 받을 선물의 수를 알고 싶습니다.

친구들의 이름을 담은 1차원 문자열 배열  `friends`  이번 달까지 친구들이 주고받은 선물 기록을 담은 1차원 문자열 배열  `gifts`가 매개변수로 주어집니다. 이때, 다음달에 가장 많은 선물을 받는 친구가 받을 선물의 수를 return 하도록 solution 함수를 완성해 주세요.

### 제한사항
-   2 ≤  `friends`의 길이 = 친구들의 수 ≤ 50
    -   `friends`의 원소는 친구의 이름을 의미하는 알파벳 소문자로 이루어진 길이가 10 이하인 문자열입니다.
    -   이름이 같은 친구는 없습니다.
-   1 ≤  `gifts`의 길이 ≤ 10,000
    -   `gifts`의 원소는  `"A B"`형태의 문자열입니다.  `A`는 선물을 준 친구의 이름을  `B`는 선물을 받은 친구의 이름을 의미하며 공백 하나로 구분됩니다.
    -   `A`와  `B`는  `friends`의 원소이며  `A`와  `B`가 같은 이름인 경우는 존재하지 않습니다.

## 해결
- 이름을 인덱스로 합니다. `맵`을 사용해서 정수로 변환합시다.
- 서로 주고받은 선물 개수는 2차원 격자, 선물 지수는 1차원 배열에 저장하면 됩니다.
- 친구 1명씩 탐색해서 이번달 받은 선물의 최댓값을 구합니다. (이번달 준 선물은 반영하지 않습니다.)

## 코드
```
#include <string>
#include <vector>
#include <map>
using namespace std;
map<string, int> name;
int N, gift[51][51], score[51];

int solution(vector<string> friends, vector<string> gifts) {
    N = friends.size();
    for (int i = 0; i < N; i++)
        name.insert({ friends[i], i });
    for (string str : gifts) {
        int i = 0;
        for (; i < str.size(); i++)
            if (str[i] == ' ')
                break;
        int giver = name.find(str.substr(0, i))->second;
        int taker = name.find(str.substr(i + 1, str.size()))->second;
        gift[giver][taker]++;
        score[giver]++; score[taker]--;
    }

    int maxGift = 0;
    for (int i = 0; i < N; i++) {
        int myGift = 0;
        for (int j = 0; j < N; j++)
            if (i != j && (gift[i][j] > gift[j][i] || (gift[i][j] == gift[j][i] && score[i] > score[j])))
                myGift++;
        maxGift = max(maxGift, myGift);
    }
    return maxGift;
}
```

## 링크
<br>https://school.programmers.co.kr/learn/courses/30/lessons/258712
{% endraw %}