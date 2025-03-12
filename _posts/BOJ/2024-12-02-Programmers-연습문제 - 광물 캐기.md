---
categories:
- Programmers
date: '2024-12-02'
title: '[Programmers] 연습문제 - 광물 캐기'
---

{% raw %}
> Lv. 2<br>

## 문제
마인은 곡괭이로 광산에서 광석을 캐려고 합니다. 마인은 다이아몬드 곡괭이, 철 곡괭이, 돌 곡괭이를 각각 0개에서 5개까지 가지고 있으며, 곡괭이로 광물을 캘 때는 피로도가 소모됩니다. 각 곡괭이로 광물을 캘 때의 피로도는 아래 표와 같습니다.

예를 들어, 철 곡괭이는 다이아몬드를 캘 때 피로도 5가 소모되며, 철과 돌을 캘때는 피로도가 1씩 소모됩니다. 각 곡괭이는 종류에 상관없이 광물 5개를 캔 후에는 더 이상 사용할 수 없습니다.

마인은 다음과 같은 규칙을 지키면서 최소한의 피로도로 광물을 캐려고 합니다.
-   사용할 수 있는 곡괭이중 아무거나 하나를 선택해 광물을 캡니다.
-   한 번 사용하기 시작한 곡괭이는 사용할 수 없을 때까지 사용합니다.
-   광물은 주어진 순서대로만 캘 수 있습니다.
-   광산에 있는 모든 광물을 캐거나, 더 사용할 곡괭이가 없을 때까지 광물을 캡니다.

즉, 곡괭이를 하나 선택해서 광물 5개를 연속으로 캐고, 다음 곡괭이를 선택해서 광물 5개를 연속으로 캐는 과정을 반복하며, 더 사용할 곡괭이가 없거나 광산에 있는 모든 광물을 캘 때까지 과정을 반복하면 됩니다.

마인이 갖고 있는 곡괭이의 개수를 나타내는 정수 배열  `picks`와 광물들의 순서를 나타내는 문자열 배열  `minerals`가 매개변수로 주어질 때, 마인이 작업을 끝내기까지 필요한 최소한의 피로도를 return 하는 solution 함수를 완성해주세요.

### 제한사항
-   `picks`는 [dia, iron, stone]과 같은 구조로 이루어져 있습니다.
    -   0 ≤ dia, iron, stone ≤ 5
    -   dia는 다이아몬드 곡괭이의 수를 의미합니다.
    -   iron은 철 곡괭이의 수를 의미합니다.
    -   stone은 돌 곡괭이의 수를 의미합니다.
    -   곡괭이는 최소 1개 이상 가지고 있습니다.
-   5 ≤  `minerals`의 길이 ≤ 50
    -   `minerals`는 다음 3개의 문자열로 이루어져 있으며 각각의 의미는 다음과 같습니다.
    -   diamond : 다이아몬드
    -   iron : 철
    -   stone : 돌

## 해결
입력이 작으므로 전체 탐색이 가능하며, 부분 문제로 분할 가능하며 중복 상태가 존재합니다. => `DP`

현재 상태를 (각 남은 곡괭이 수) = (`d`, `i`, `s`)로 정의하며, 계산 결과는 최소 피로도입니다. 현재 광물 위치는 남은 곡괭이 수로 구할 수 있습니다. (초기 곡괭이 총합 - 남은 곡괭이 수) 초기 상태는 초기 곡괭이 개수이며, 곡괭이를 모두 소진하거나 캘 수 있는 광물이 없으면 탐색이 종료됩니다. 각 종류의 곡괭이를 사용하는 것으로 점화식을 설계합니다:

> DP(d, i, s) = min(DP(d - 1, i, s) + C(m, 0), DP(d, i - 1, s) + C(m, 1), DP(d, i, s - 1) + C(m, 2))<br>
> C(m, p) = p 종류 곡괭이를 사용하며 m번 위치부터 광물을 캤을 때 피로도<br>
> m = (초기 곡괭이 총합 - (d + i + s)) × 5<br>

## 코드
```
#include <string>
#include <vector>
#include <map>
using namespace std;
const int INF = 1e9;
vector<string> M;
int cache[6][6][6], N, STA[3][3] = { { 1, 1, 1 }, { 5, 1, 1 }, { 25, 5, 1 } };
map<string, int> dict;

int MANA(int m, int p) {
    int c = 0;
    for(int i = 0; i < 5 && m + i < M.size(); i++)
        c += STA[p][dict[M[m + i]]];
    return c;
}

int DP(int d, int i, int s) {
    int m = (N - (d + i + s)) * 5;
    if(cache[d][i][s] > 0)
        return cache[d][i][s];
    if(d < 0 || i < 0 || s < 0)
        return INF;
    if((d == 0 && i == 0 && s == 0) || m >= M.size())
        return 0;
    cache[d][i][s] = DP(d - 1, i, s) + MANA(m, 0);
    cache[d][i][s] = min(cache[d][i][s], DP(d, i - 1, s) + MANA(m, 1));
    cache[d][i][s] = min(cache[d][i][s], DP(d, i, s - 1) + MANA(m, 2));
    return cache[d][i][s];
}

int solution(vector<int> P, vector<string> minerals) {
    M = minerals; N = P[0] + P[1] + P[2];
    dict["diamond"] = 0, dict["iron"] = 1, dict["stone"] = 2;
    return DP(P[0], P[1], P[2]);
}
```

## 링크
<br>https://school.programmers.co.kr/learn/courses/30/lessons/172927
{% endraw %}