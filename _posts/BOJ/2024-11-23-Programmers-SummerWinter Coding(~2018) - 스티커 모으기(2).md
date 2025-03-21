---
categories:
- Programmers
date: '2024-11-23'
title: '[Programmers] SummerWinter Coding(~2018) - 스티커 모으기(2)'
---

{% raw %}
> Lv. 3<br>

## 문제
N개의 스티커가 원형으로 연결되어 있습니다.
  
원형으로 연결된 스티커에서 몇 장의 스티커를 뜯어내어 뜯어낸 스티커에 적힌 숫자의 합이 최대가 되도록 하고 싶습니다. 단 스티커 한 장을 뜯어내면 양쪽으로 인접해있는 스티커는 찢어져서 사용할 수 없게 됩니다.

스티커에 적힌 숫자가 배열 형태로 주어질 때, 스티커를 뜯어내어 얻을 수 있는 숫자의 합의 최댓값을 return 하는 solution 함수를 완성해 주세요. 원형의 스티커 모양을 위해 배열의 첫 번째 원소와 마지막 원소가 서로 연결되어 있다고 간주합니다.

### 제한 사항
-   sticker는 원형으로 연결된 스티커의 각 칸에 적힌 숫자가 순서대로 들어있는 배열로, 길이(N)는 1 이상 100,000 이하입니다.
-   sticker의 각 원소는 스티커의 각 칸에 적힌 숫자이며, 각 칸에 적힌 숫자는 1 이상 100 이하의 자연수입니다.
-   원형의 스티커 모양을 위해 sticker 배열의 첫 번째 원소와 마지막 원소가 서로 연결되어있다고 간주합니다.

## 해결
스티커를 가져가면 이웃한 것을 사용할 수 없습니다. 입력이 작고 모든 경우를 조사해야 합니다. => `원형 DP`
현재 상태를 (스티커 번호)로 정의하고, 결과 값은 최대 합입니다. 점화식은 현재 스티커를 가져갈지 넘어할지를 판단하며, 다음과 같습니다:
> DP[n] = max(DP[n - 1], DP[n - 2] + A[N])<br>

원형이므로 1번째 스티커 선택 유무가 마지막 스티커 선택에 영향을 줍니다. 따라서 현재 상태를 확장하여 (스티커 번호, 1번째 스티커 선택 유무)로 정의합니다. 점화식은 동일하며, 마지막 스티커일 때 1번째 스티커를 선택했다면 마지막 스티커를 넘어가는 것만 고려합니다.

## 코드
```
#include <vector>
using namespace std;
int DP[100001][2];

int solution(vector<int> sticker) {
    int N = sticker.size();
    for(int i = 0; i < 2; i++) {
        DP[0][i] = i == 0 ? sticker[0] : 0;
        DP[1][i] = max(DP[0][i], sticker[1]);
        for(int n = 2; n < N - 1; n++)
            DP[n][i] = max(DP[n - 1][i], DP[n - 2][i] + sticker[n]);
        DP[N - 1][i] = max(DP[N - 2][i], i == 0 ? 0 : DP[N - 3][i] + sticker[N - 1]);
    }
    return max(DP[N - 1][0], DP[N - 1][1]);
}
```

## 링크
<br>https://school.programmers.co.kr/learn/courses/30/lessons/12971
{% endraw %}