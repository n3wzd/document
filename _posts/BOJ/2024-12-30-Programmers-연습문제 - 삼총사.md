---
categories:
- Programmers
date: '2024-12-30'
title: '[Programmers] 연습문제 - 삼총사'
---

{% raw %}
> Lv. 1<br>

## 문제
한국중학교에 다니는 학생들은 각자 정수 번호를 갖고 있습니다. 이 학교 학생 3명의 정수 번호를 더했을 때 0이 되면 3명의 학생은 삼총사라고 합니다. 예를 들어, 5명의 학생이 있고, 각각의 정수 번호가 순서대로 -2, 3, 0, 2, -5일 때, 첫 번째, 세 번째, 네 번째 학생의 정수 번호를 더하면 0이므로 세 학생은 삼총사입니다. 또한, 두 번째, 네 번째, 다섯 번째 학생의 정수 번호를 더해도 0이므로 세 학생도 삼총사입니다. 따라서 이 경우 한국중학교에서는 두 가지 방법으로 삼총사를 만들 수 있습니다.

한국중학교 학생들의 번호를 나타내는 정수 배열  `number`가 매개변수로 주어질 때, 학생들 중 삼총사를 만들 수 있는 방법의 수를 return 하도록 solution 함수를 완성하세요.

### 제한사항
-   3 ≤  `number`의 길이 ≤ 13
-   -1,000 ≤  `number`의 각 원소 ≤ 1,000
-   서로 다른 학생의 정수 번호가 같을 수 있습니다.

## 해결
길이가 3인 `조합`을 모두 확인해서 합이 0인 것의 개수를 구합니다.

## 코드
```
#include <vector>
using namespace std;
int answer; vector<int> number;<br>
bool selected[13];

void BT(int start, int depth) {
    if(depth == 0) {
        int sum = 0;
        for(int i = 0; i < number.size(); i++)
            if(selected[i])
            sum += number[i];
        answer += sum == 0 ? 1 : 0;
        return;
    }
    for(int i = start; i < number.size(); i++) {
        selected[i] = 1;
        BT(i + 1, depth - 1);
        selected[i] = 0;
    }
}

int solution(vector<int> numberI) {<br>
    number = numberI; BT(0, 3);
    return answer;
}
```

## 링크
https://school.programmers.co.kr/learn/courses/30/lessons/131705
{% endraw %}