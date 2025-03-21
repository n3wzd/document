---
categories:
- Programmers
date: '2024-10-29'
title: '[Programmers] 2023 KAKAO BLIND RECRUITMENT - 개인정보 수집 유효기간'
---

{% raw %}
> Lv. 1<br>

## 문제
고객의 약관 동의를 얻어서 수집된 1~`n`번으로 분류되는 개인정보  `n`개가 있습니다. 약관 종류는 여러 가지 있으며 각 약관마다 개인정보 보관 유효기간이 정해져 있습니다. 당신은 각 개인정보가 어떤 약관으로 수집됐는지 알고 있습니다. 수집된 개인정보는 유효기간 전까지만 보관 가능하며, 유효기간이 지났다면 반드시 파기해야 합니다.

예를 들어, A라는 약관의 유효기간이 12 달이고, 2021년 1월 5일에 수집된 개인정보가 A약관으로 수집되었다면 해당 개인정보는 2022년 1월 4일까지 보관 가능하며 2022년 1월 5일부터 파기해야 할 개인정보입니다.  
당신은 오늘 날짜로 파기해야 할 개인정보 번호들을 구하려 합니다.

**모든 달은 28일까지 있다고 가정합니다.**

오늘 날짜를 의미하는 문자열 `today`, 약관의 유효기간을 담은 1차원 문자열 배열 `terms`와 수집된 개인정보의 정보를 담은 1차원 문자열 배열 `privacies`가 매개변수로 주어집니다. 이때 파기해야 할 개인정보의 번호를 오름차순으로 1차원 정수 배열에 담아 return 하도록 solution 함수를 완성해 주세요.

### 제한사항
-   `today`는 "`YYYY`.`MM`.`DD`" 형태로 오늘 날짜를 나타냅니다.
-   1 ≤  `terms`의 길이 ≤ 20
    -   `terms`의 원소는 "`약관 종류`  `유효기간`" 형태의  `약관 종류`와  `유효기간`을 공백 하나로 구분한 문자열입니다.
    -   `약관 종류`는  `A`~`Z`중 알파벳 대문자 하나이며,  `terms`  배열에서  `약관 종류`는 중복되지 않습니다.
    -   `유효기간`은 개인정보를 보관할 수 있는 달 수를 나타내는 정수이며, 1 이상 100 이하입니다.
-   1 ≤  `privacies`의 길이 ≤ 100
    -   `privacies[i]`는  `i+1`번 개인정보의 수집 일자와 약관 종류를 나타냅니다.
    -   `privacies`의 원소는 "`날짜`  `약관 종류`" 형태의  `날짜`와  `약관 종류`를 공백 하나로 구분한 문자열입니다.
    -   `날짜`는 "`YYYY`.`MM`.`DD`" 형태의 개인정보가 수집된 날짜를 나타내며,  `today`  이전의 날짜만 주어집니다.
    -   `privacies`의  `약관 종류`는 항상  `terms`에 나타난  `약관 종류`만 주어집니다.
-   `today`와  `privacies`에 등장하는  `날짜`의  `YYYY`는 연도,  `MM`은 월,  `DD`는 일을 나타내며 점(`.`) 하나로 구분되어 있습니다.
    -   2000 ≤  `YYYY`  ≤ 2022
    -   1 ≤  `MM`  ≤ 12
    -   `MM`이 한 자릿수인 경우 앞에 0이 붙습니다.
    -   1 ≤  `DD`  ≤ 28
    -   `DD`가 한 자릿수인 경우 앞에 0이 붙습니다.
-   파기해야 할 개인정보가 하나 이상 존재하는 입력만 주어집니다.

## 해결
- 시간은 문자열로 주어집니다. 정수로 변환해서 비교합시다.
	- 현재 시간이 수집 일자와 유효 기간의 합보다 같거나 크면 파기 대상입니다.
- 약관 ID는 문자로 주어집니다. 따라서 정수로 인덱싱할 수 있습니다.

## 코드
```
#include <string>
#include <vector>
using namespace std;
int priv[27];
int timeToInt(string s) {
    return (stoi(s.substr(0, 4)) * 12 + stoi(s.substr(5, 2))) * 28 + stoi(s.substr(8, 2));
}

vector<int> solution(string todayS, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    int today = timeToInt(todayS);
    for (string s : terms)
        priv[s[0] - 65] = stoi(s.substr(2, s.size() - 2)) * 28;
    for (int i = 0; i < privacies.size(); i++) {
        string s = privacies[i];
        int t = timeToInt(s.substr(0, 10));
        int d = priv[s[s.size() - 1] - 65];
        if (today >= t + d)
            answer.push_back(i + 1);
    }
    return answer;
}
```

## 링크
<br>https://school.programmers.co.kr/learn/courses/30/lessons/150370
{% endraw %}