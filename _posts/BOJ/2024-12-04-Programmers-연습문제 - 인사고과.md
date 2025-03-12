---
categories:
- Programmers
date: '2024-12-04'
title: '[Programmers] 연습문제 - 인사고과'
---

{% raw %}
> Lv. 3<br>

## 문제
완호네 회사는 연말마다 1년 간의 인사고과에 따라 인센티브를 지급합니다. 각 사원마다 근무 태도 점수와 동료 평가 점수가 기록되어 있는데 만약 어떤 사원이 다른 임의의 사원보다 두 점수가 모두 낮은 경우가 한 번이라도 있다면 그 사원은 인센티브를 받지 못합니다. 그렇지 않은 사원들에 대해서는 두 점수의 합이 높은 순으로 석차를 내어 석차에 따라 인센티브가 차등 지급됩니다. 이때, 두 점수의 합이 동일한 사원들은 동석차이며, 동석차의 수만큼 다음 석차는 건너 뜁니다. 예를 들어 점수의 합이 가장 큰 사원이 2명이라면 1등이 2명이고 2등 없이 다음 석차는 3등부터입니다.

각 사원의 근무 태도 점수와 동료 평가 점수 목록  `scores`이 주어졌을 때, 완호의 석차를 return 하도록 solution 함수를 완성해주세요.

### 제한 사항
-   1 ≤  `scores`의 길이 ≤ 100,000
-   `scores`의 각 행은 한 사원의 근무 태도 점수와 동료 평가 점수를 나타내며 [a, b] 형태입니다.
    -   `scores`[0]은 완호의 점수입니다.
    -   0 ≤ a, b ≤ 100,000
-   완호가 인센티브를 받지 못하는 경우 -1을 return 합니다.

## 해결
크게 2가지 부분으로 나눌 수 있습니다.
1. 탈락 필터링
2. 순위 정하기

먼저 탈락을 필터링합니다. 점수를 (`x`, `y`)라고 합시다. 주어진 리스트를 `x` 내림차순, `x`가 같다면 `y` 내림차순으로 `정렬`합니다. 아래는 그 예시입니다:
```
       (5, 2) (5, 1) (4, 4) (4, 2) (4, 1) (3, 5) (3, 4) (3, 1) (2, 4) (2, 3) (1, 5) (1, 4)
통과    O      O      O      O      X      O      O      X      X      X      O      X
기준y  -1             2                    4                    5             5
```

순차 탐색했을 때, 탈락 조건은 다음과 같습니다:
> 탈락 조건: 현재 `y`가 `기준 y`보다 작으면 탈락<br>

`기준 y`는 `x`가 바뀔 때 업데이트됩니다. `기준 y`의 값은 이전 `x`의 `y` 최댓값과 현재 `기준 y`의 최대입니다.

다음으로 순위를 정해봅시다. 필터링한 리스트를 합 내림차순으로 `정렬`하고, 순차 탐색해서 순위를 부여하면 됩니다. (완호의 석차는 처음 입력의 첫번째 점수로, 리스트에선 (x, y)를 모두 비교해서 찾을 수 있습니다.)

## 코드
```
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> S) {
    int maxY = -1, curX = -1, nextMaxY = -1;
    vector<vector<int>> T; vector<int> my = S[0];
    sort(S.begin(), S.end(), [](auto a, auto b) { 
        return a[0] != b[0] ? a[0] > b[0] : a[1] > b[1];
    });
    for(auto n : S) {
        if(n[0] != curX) {
            curX = n[0];
            maxY = nextMaxY;
            nextMaxY = max(nextMaxY, n[1]);
        }
        if(n[1] >= maxY)
            T.push_back(n);
    }
    
    int psum = 1e9, rank = 0, answer = -1;
    sort(T.begin(), T.end(), [](auto a, auto b) { return a[0] + a[1] > b[0] + b[1]; });
    for(int i = 0; i < T.size(); i++) {
        auto n = T[i];
        if(psum > n[0] + n[1])
            psum = n[0] + n[1], rank = i + 1;
        if(n[0] == my[0] && n[1] == my[1])
            answer = rank;
    }
    return answer;
}
```

## 링크
<br>https://school.programmers.co.kr/learn/courses/30/lessons/152995
{% endraw %}