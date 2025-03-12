---
categories:
- Programmers
date: '2024-12-15'
title: '[Programmers] 연습문제 - 억억단을 외우자'
---

{% raw %}
> Lv. 3<br>

## 문제
영우는 천하제일 암산대회를 앞두고 있습니다. 암산보다는 암기에 일가견이 있는 영우는 구구단을 확장하여 억억단을 만들고 외워버리기로 하였습니다.  
  
억억단은 1억 x 1억 크기의 행렬입니다. 억억단을 외우던 영우는 친구 수연에게 퀴즈를 내달라고 부탁하였습니다.  
수연은 평범하게 문제를 내봐야 영우가 너무 쉽게 맞히기 때문에 좀 어렵게 퀴즈를 내보려고 합니다. 적당한 수  `e`를 먼저 정하여 알려주고  `e`  이하의 임의의 수  `s`를 여러 개 얘기합니다. 영우는 각  `s`에 대해서  `s`보다 크거나 같고  `e`  보다 작거나 같은 수 중에서 억억단에서 가장 많이 등장한 수를 답해야 합니다. 만약 가장 많이 등장한 수가 여러 개라면 그 중 가장 작은 수를 답해야 합니다.  
수연은 영우가 정답을 말하는지 확인하기 위해 당신에게 프로그램 제작을 의뢰하였습니다.  `e`와  `s`의 목록  `starts`가 매개변수로 주어질 때 각 퀴즈의 답 목록을 return 하도록 solution 함수를 완성해주세요.

### 제한사항
-   1 ≤  `e`  ≤ 5,000,000
-   1 ≤  `starts`의 길이 ≤ min {`e`,100,000}
-   1 ≤  `starts`의 원소 ≤  `e`
-   `starts`에는 중복되는 원소가 존재하지 않습니다.

## 해결
정수 `e`의 억억단에서 등장 개수를 세어 봅시다. `e`단에서 1개, `e`보다 큰 단에는 없고, `e`보다 작은 단에선 `a`의 약수단마다 1개씩 존재합니다. 즉, `e`의 등장 횟수는 약수 개수와 같으며, 주어진 문제는 다음과 같습니다.
> A[s, e] = [s, e] 구간 내 약수 개수가 가장 많은 정수<br>

구간 쿼리지만 `e`는 고정이며 `s`만 변수입니다. `s`의 최솟값, `m`을 찾고, `e`부터 `m`까지 구간을 확장하면서 `A[s, e]`의 값을 채웁니다. => `DP`<br>

약수 개수를 구해 봅시다. 약수 개수를 저장하는 배열을 `D`로 정의합니다. 1부터 `e`까지 모든 정수를 순회하고, 각 정수의 배수를 `x`라고 했을 때, `D[x]`의 값을 1씩 카운팅합니다. (`에라토스테네스의 체`와 비슷한 방법입니다.)

## 코드
```
#include <vector>
using namespace std;
const int MAXN = 5000001;
int D[MAXN] = { 0, 1, }, M[MAXN], X[MAXN];

void divisor(int e) {
    for(int a = 2; a <= e; a++)
        for(int i = 1; a * i <= e; i++)
            D[a * i]++;
}

vector<int> solution(int e, vector<int> starts) {<br>
    vector<int> answer; divisor(e); int m = MAXN;<br>
    for(int s : starts)
        m = min(s, m);
    M[e] = D[e]; X[e] = e;
    for(int i = e - 1; i >= m; i--) {
        X[i] = M[i + 1] <= D[i] ? i : X[i + 1];
        M[i] = max(M[i + 1], D[i]);
    }
    for(int s : starts)
        answer.push_back(X[s]);
    return answer;
}
```

## 링크
https://school.programmers.co.kr/learn/courses/30/lessons/138475<br>
{% endraw %}