---
categories:
- Programmers
date: '2024-10-31'
title: '[Programmers] 2022 KAKAO TECH INTERNSHIP - 성격 유형 검사하기'
---

{% raw %}
> Lv. 1<br>

## 문제
나만의 카카오 성격 유형 검사지를 만들려고 합니다.  
성격 유형 검사는 다음과 같은 4개 지표로 성격 유형을 구분합니다. 성격은 각 지표에서 두 유형 중 하나로 결정됩니다.

4개의 지표가 있으므로 성격 유형은 총 16(=2 x 2 x 2 x 2)가지가 나올 수 있습니다. 예를 들어, "RFMN"이나 "TCMA"와 같은 성격 유형이 있습니다.

검사지에는 총  `n`개의 질문이 있고, 각 질문에는 아래와 같은 7개의 선택지가 있습니다.

-   `매우 비동의`
-   `비동의`
-   `약간 비동의`
-   `모르겠음`
-   `약간 동의`
-   `동의`
-   `매우 동의`

각 질문은 1가지 지표로 성격 유형 점수를 판단합니다.

하지만 각 선택지는 고정적인 크기의 점수를 가지고 있습니다.
-   `매우 동의`나  `매우 비동의`  선택지를 선택하면 3점을 얻습니다.
-   `동의`나  `비동의`  선택지를 선택하면 2점을 얻습니다.
-   `약간 동의`나  `약간 비동의`  선택지를 선택하면 1점을 얻습니다.
-   `모르겠음`  선택지를 선택하면 점수를 얻지 않습니다.

검사 결과는 모든 질문의 성격 유형 점수를 더하여 각 지표에서 더 높은 점수를 받은 성격 유형이 검사자의 성격 유형이라고 판단합니다. 단, 하나의 지표에서 각 성격 유형 점수가 같으면, 두 성격 유형 중 사전 순으로 빠른 성격 유형을 검사자의 성격 유형이라고 판단합니다.

질문마다 판단하는 지표를 담은 1차원 문자열 배열  `survey`와 검사자가 각 질문마다 선택한 선택지를 담은 1차원 정수 배열  `choices`가 매개변수로 주어집니다. 이때, 검사자의 성격 유형 검사 결과를 지표 번호 순서대로 return 하도록 solution 함수를 완성해주세요.

### 제한사항
-   1 ≤  `survey`의 길이 ( =  `n`) ≤ 1,000
    -   `survey`의 원소는  `"RT", "TR", "FC", "CF", "MJ", "JM", "AN", "NA"`  중 하나입니다.
    -   `survey[i]`의 첫 번째 캐릭터는 i+1번 질문의 비동의 관련 선택지를 선택하면 받는 성격 유형을 의미합니다.
    -   `survey[i]`의 두 번째 캐릭터는 i+1번 질문의 동의 관련 선택지를 선택하면 받는 성격 유형을 의미합니다.
-   `choices`의 길이 =  `survey`의 길이
    
    -   `choices[i]`는 검사자가 선택한 i+1번째 질문의 선택지를 의미합니다.
    -   1 ≤  `choices`의 원소 ≤ 7

## 해결
- 문자를 인덱싱하고 각 조사에 대해 점수를 더하면 됩니다.

## 코드
```
#include <string>
#include <vector>
using namespace std;
int score[26];

string solution(vector<string> survey, vector<int> choices) {<br>
    string answer = "";
    for(int i = 0; i < survey.size(); i++) {
        switch(choices[i]) {
            case 1: score[survey[i][0] - 65] += 3; break;
            case 2: score[survey[i][0] - 65] += 2; break;
            case 3: score[survey[i][0] - 65] += 1; break;
            case 5: score[survey[i][1] - 65] += 1; break;
            case 6: score[survey[i][1] - 65] += 2; break;
            case 7: score[survey[i][1] - 65] += 3; break;
        }
    }
    answer += score[17] >= score[19] ? 'R' : 'T';
    answer += score[2] >= score[5] ? 'C' : 'F';
    answer += score[9] >= score[12] ? 'J' : 'M';
    answer += score[0] >= score[13] ? 'A' : 'N';
    return answer;
}
```

## 링크
https://school.programmers.co.kr/learn/courses/30/lessons/118666<br>
{% endraw %}