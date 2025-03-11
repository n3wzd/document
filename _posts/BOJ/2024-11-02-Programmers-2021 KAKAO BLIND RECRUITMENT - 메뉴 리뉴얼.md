---
categories:
- Programmers
date: '2024-11-02'
title: '[Programmers] 2021 KAKAO BLIND RECRUITMENT - 메뉴 리뉴얼'
---

{% raw %}
> Lv. 2<br>

## 문제
레스토랑을 운영하던  `스카피`는 코로나19로 인한 불경기를 극복하고자 메뉴를 새로 구성하려고 고민하고 있습니다.  
기존에는 단품으로만 제공하던 메뉴를 조합해서 코스요리 형태로 재구성해서 새로운 메뉴를 제공하기로 결정했습니다. 어떤 단품메뉴들을 조합해서 코스요리 메뉴로 구성하면 좋을 지 고민하던 "스카피"는 이전에 각 손님들이 주문할 때 가장 많이 함께 주문한 단품메뉴들을 코스요리 메뉴로 구성하기로 했습니다.  
단, 코스요리 메뉴는 최소 2가지 이상의 단품메뉴로 구성하려고 합니다. 또한, 최소 2명 이상의 손님으로부터 주문된 단품메뉴 조합에 대해서만 코스요리 메뉴 후보에 포함하기로 했습니다.

각 손님들이 주문한 단품메뉴들이 문자열 형식으로 담긴 배열 orders, "스카피"가  `추가하고 싶어하는`  코스요리를 구성하는 단품메뉴들의 갯수가 담긴 배열 course가 매개변수로 주어질 때, "스카피"가 새로 추가하게 될 코스요리의 메뉴 구성을 문자열 형태로 배열에 담아 return 하도록 solution 함수를 완성해 주세요.

### 제한사항
-   orders 배열의 크기는 2 이상 20 이하입니다.
-   orders 배열의 각 원소는 크기가 2 이상 10 이하인 문자열입니다.
    -   각 문자열은 알파벳 대문자로만 이루어져 있습니다.
    -   각 문자열에는 같은 알파벳이 중복해서 들어있지 않습니다.
-   course 배열의 크기는 1 이상 10 이하입니다.
    -   course 배열의 각 원소는 2 이상 10 이하인 자연수가  `오름차순`으로 정렬되어 있습니다.
    -   course 배열에는 같은 값이 중복해서 들어있지 않습니다.
-   정답은 각 코스요리 메뉴의 구성을 문자열 형식으로 배열에 담아 사전 순으로  `오름차순`  정렬해서 return 해주세요.
    -   배열의 각 원소에 저장된 문자열 또한 알파벳  `오름차순`으로 정렬되어야 합니다.
    -   만약 가장 많이 함께 주문된 메뉴 구성이 여러 개라면, 모두 배열에 담아 return 하면 됩니다.
    -   orders와 course 매개변수는 return 하는 배열의 길이가 1 이상이 되도록 주어집니다.

## 해결
- 메뉴 `조합` 중 코스 메뉴의 길이마다 가장 많이 나타난 조합들을 찾으면 됩니다. (코스 길이는 입력으로 주어집니다.) 손님의 주문 목록은 무작위 순서로 주어지므로 탐색 전에 `정렬`해야 합니다.
- 메뉴 조합은 문자열이므로 `맵`을 사용해서 개수를 셉니다.
- 최종 정답은 사전순이므로 정렬을 한번 더 해줍니다.

```
1. 모든 주문목록 탐색:
	1. 목록 정렬
	2. 모든 코스 길이 탐색:
		- 주어진 길이에 해당하는 모든 메뉴 조합 카운팅
		- 코스 메뉴 길이마다 최대 개수 업데이트
2. 모든 메뉴 조합 순회:
	- 각 코스 메뉴 길이마다 최대인 조합만 반환
```

## 코드
```
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;
map<string, int> cnt;<br>
int maxCntByItem[11];
bool selected[11];

void combination(string str, int k, int d, int start) {
    if(k == d) {
        string menu = "";
        for(int i = 0; i < str.size(); i++)
            if(selected[i])
                menu += str[i];
        auto data = cnt.find(menu);
        if(data != cnt.end()) {
            data->second++;
            maxCntByItem[k] = max(maxCntByItem[k], data->second);
        }
        else
            cnt.insert({ menu, 1 });
    }
    for(int i = start; i < str.size(); i++) {
        selected[i] = 1;
        combination(str, k, d + 1, i + 1);
        selected[i] = 0;
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {<br>
    vector<string> answer;<br>
    for(auto& order : orders)
        sort(order.begin(), order.end());
    for(auto order : orders)
        for(auto c : course)
            if(c <= order.size())
                combination(order, c, 0, 0);
    for (const auto& menu : cnt)
        if(maxCntByItem[menu.first.size()] == menu.second)
            answer.push_back(menu.first); 
    sort(answer.begin(), answer.end());
    return answer;
}
```

## 링크
https://school.programmers.co.kr/learn/courses/30/lessons/72411
{% endraw %}