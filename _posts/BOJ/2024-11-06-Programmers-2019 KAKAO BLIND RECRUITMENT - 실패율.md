---
categories:
- Programmers
date: '2024-11-06'
title: '[Programmers] 2019 KAKAO BLIND RECRUITMENT - 실패율'
---

{% raw %}
> Lv. 1<br>

## 문제
슈퍼 게임 개발자 오렐리는 큰 고민에 빠졌다. 그녀가 만든 프랜즈 오천성이 대성공을 거뒀지만, 요즘 신규 사용자의 수가 급감한 것이다. 원인은 신규 사용자와 기존 사용자 사이에 스테이지 차이가 너무 큰 것이 문제였다.

이 문제를 어떻게 할까 고민 한 그녀는 동적으로 게임 시간을 늘려서 난이도를 조절하기로 했다. 역시 슈퍼 개발자라 대부분의 로직은 쉽게 구현했지만, 실패율을 구하는 부분에서 위기에 빠지고 말았다. 오렐리를 위해 실패율을 구하는 코드를 완성하라.

-   실패율은 다음과 같이 정의한다.
    -   스테이지에 도달했으나 아직 클리어하지 못한 플레이어의 수 / 스테이지에 도달한 플레이어 수

전체 스테이지의 개수 N, 게임을 이용하는 사용자가 현재 멈춰있는 스테이지의 번호가 담긴 배열 stages가 매개변수로 주어질 때, 실패율이 높은 스테이지부터 내림차순으로 스테이지의 번호가 담겨있는 배열을 return 하도록 solution 함수를 완성하라.

### 제한사항
-   스테이지의 개수 N은  `1`  이상  `500`  이하의 자연수이다.
-   stages의 길이는  `1`  이상  `200,000`  이하이다.
-   stages에는  `1`  이상  `N + 1`  이하의 자연수가 담겨있다.
    -   각 자연수는 사용자가 현재 도전 중인 스테이지의 번호를 나타낸다.
    -   단,  `N + 1`  은 마지막 스테이지(N 번째 스테이지) 까지 클리어 한 사용자를 나타낸다.
-   만약 실패율이 같은 스테이지가 있다면 작은 번호의 스테이지가 먼저 오도록 하면 된다.
-   스테이지에 도달한 유저가 없는 경우 해당 스테이지의 실패율은  `0`  으로 정의한다.

## 해결
N번 스테이지의 실패율은 다음과 같습니다:
> N번 스테이지 실패율 = (배열에서 N과 같은 값 개수) / (배열에서 N 이상인 값 개수)<br>

이는 `lowerbound`와 `upperbound`를 활용해서 구할 수 있습니다. (`len` = 배열 길이)
> N번 스테이지 실패율 = (upperbound(N) - lowerbound(N)) / (len - lowerbound(N))<br>

위 수식을 활용해 모든 스테이지 번호, 실패율을 구하고, 목록을 주어진 조건에 맞게 `정렬`하면 최종 답이 됩니다.

실패율은 실수이며, 이를 비교하는 방법은 크게 2가지가 있습니다:
1. `double` 자료형으로 비교: 실제로 제출하면 통과될 수는 있으나, `floating point`로 인해 권장되지 않는 방법입니다.
2. 정수 자료형으로 비교: 분수를 정수 값인 분자, 분모로 표한하고, 비교할 때는 서로 다른 분자와 분모를 곱해 대소를 판정합니다.
	- 확실한 방법이지만, 이 문제에선 오버플로우가 될 수 있다는 점을 유의합니다. C++ 기준, `long long` 자료형을 사용해야 합니다.
	- 분자, 분모가 0이면 곱을 활용한 비교 판정이 불가능합니다. 이 때는 분자 -1, 분모 1로 처리하면 됩니다.

## 코드
```
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
struct Stage { ll id, a, b; };
vector<Stage> stages; vector<int> answer;<br>

vector<int> solution(int N, vector<int> clears) {<br>
    sort(clears.begin(), clears.end());
    for (int i = 1; i <= N; i++) {
        auto low = lower_bound(clears.begin(), clears.end(), i);
        auto upp = upper_bound(clears.begin(), clears.end(), i);
        ll a = distance(low, clears.end()), b = distance(low, upp);
        if(a > 0 && b > 0)<br>
            stages.push_back({ i, a, b });
        else
            stages.push_back({ i, 1, -1 });
    }
    sort(stages.begin(), stages.end(), [](const auto& x, const auto& y) {
        return x.a * y.b == y.a * x.b ? x.id < y.id : x.a * y.b < y.a * x.b;
        });
    for (auto s : stages)
        answer.push_back(s.id);
    return answer;
}
```

## 링크
https://school.programmers.co.kr/learn/courses/30/lessons/42889
{% endraw %}