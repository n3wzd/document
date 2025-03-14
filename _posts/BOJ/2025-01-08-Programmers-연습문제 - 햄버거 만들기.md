---
categories:
- Programmers
date: '2025-01-08'
title: '[Programmers] 연습문제 - 햄버거 만들기'
---

{% raw %}
> Lv. 1<br>

## 문제
햄버거 가게에서 일을 하는 상수는 햄버거를 포장하는 일을 합니다. 함께 일을 하는 다른 직원들이 햄버거에 들어갈 재료를 조리해 주면 조리된 순서대로 상수의 앞에 아래서부터 위로 쌓이게 되고, 상수는 순서에 맞게 쌓여서 완성된 햄버거를 따로 옮겨 포장을 하게 됩니다. 상수가 일하는 가게는 정해진 순서(아래서부터, 빵 – 야채 – 고기 - 빵)로 쌓인 햄버거만 포장을 합니다. 상수는 손이 굉장히 빠르기 때문에 상수가 포장하는 동안 속 재료가 추가적으로 들어오는 일은 없으며, 재료의 높이는 무시하여 재료가 높이 쌓여서 일이 힘들어지는 경우는 없습니다.

예를 들어, 상수의 앞에 쌓이는 재료의 순서가 [야채, 빵, 빵, 야채, 고기, 빵, 야채, 고기, 빵]일 때, 상수는 여섯 번째 재료가 쌓였을 때, 세 번째 재료부터 여섯 번째 재료를 이용하여 햄버거를 포장하고, 아홉 번째 재료가 쌓였을 때, 두 번째 재료와 일곱 번째 재료부터 아홉 번째 재료를 이용하여 햄버거를 포장합니다. 즉, 2개의 햄버거를 포장하게 됩니다.

상수에게 전해지는 재료의 정보를 나타내는 정수 배열  `ingredient`가 주어졌을 때, 상수가 포장하는 햄버거의 개수를 return 하도록 solution 함수를 완성하시오.

### 제한사항
-   1 ≤  `ingredient`의 길이 ≤ 1,000,000
-   `ingredient`의 원소는 1, 2, 3 중 하나의 값이며, 순서대로 빵, 야채, 고기를 의미합니다.

## 해결
리스트 중간에 아이템이 제거되면 분리된 두 리스트는 연결됩니다. => `스택`

재료를 하나씩 스택에 넣고, 스택의 위쪽 4개의 아이템이 햄버거가 되는지 확인합니다. 햄버거가 되면 정답을 업데이트하고 위쪽 4개의 재료를 스택에서 제거하면 됩니다.

## 코드
```
#include <vector>
using namespace std;

int solution(vector<int> A) {
    vector<int> S;
    int answer = 0;
    for(int a : A) {
        S.push_back(a);
        int s = S.size();
        if(s > 3 && S[s - 1] == 1 && S[s - 2] == 3 && S[s - 3] == 2 && S[s - 4] == 1) {
            answer++;
            for(int r = 0; r < 4; r++)
                S.pop_back();
        }
    }
    return answer;
}
```

## 링크
<br>https://school.programmers.co.kr/learn/courses/30/lessons/133502
{% endraw %}