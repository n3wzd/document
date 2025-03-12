---
categories:
- Programmers
date: '2024-11-10'
title: '[Programmers] 2021 KAKAO TECH INTERNSHIP - 숫자 문자열과 영단어'
---

{% raw %}
> Lv. 1<br>

## 문제
네오와 프로도가 숫자놀이를 하고 있습니다. 네오가 프로도에게 숫자를 건넬 때 일부 자릿수를 영단어로 바꾼 카드를 건네주면 프로도는 원래 숫자를 찾는 게임입니다.  
  
다음은 숫자의 일부 자릿수를 영단어로 바꾸는 예시입니다.

-   1478 → "one4seveneight"
-   234567 → "23four5six7"
-   10203 → "1zerotwozero3"

이렇게 숫자의 일부 자릿수가 영단어로 바뀌어졌거나, 혹은 바뀌지 않고 그대로인 문자열  `s`가 매개변수로 주어집니다.  `s`가 의미하는 원래 숫자를 return 하도록 solution 함수를 완성해주세요.

### 제한사항
-   1 ≤  `s`의 길이 ≤ 50
-   `s`가 "zero" 또는 "0"으로 시작하는 경우는 주어지지 않습니다.
-   return 값이 1 이상 2,000,000,000 이하의 정수가 되는 올바른 입력만  `s`로 주어집니다.

## 해결
- 주어진 문자열에서 20가지 단어를 비교하며 탐색합니다.
- 접두사, 접미사가 겹쳐지는 단어가 없으므로 단어 대체를 사용할 수도 있습니다. => `정규 표현식`

## 코드
```
#include <string>
#include <vector>
using namespace std;
string list[20] = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

int solution(string s) {
    string answer = ""; s += "     ";
    for(int i = 0; i < s.size(); i++) {
        for(int d = 0; d < 20; d++) {
            if(s.substr(i, list[d].size()) == list[d]) {
                answer += list[d % 10];
                i += list[d].size() - 1;
                break;
            }
        }
    }
    return stoi(answer);
}
```

## 링크
<br>https://school.programmers.co.kr/learn/courses/30/lessons/81301
{% endraw %}