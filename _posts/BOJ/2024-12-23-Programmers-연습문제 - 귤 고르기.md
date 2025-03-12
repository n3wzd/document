---
categories:
- Programmers
date: '2024-12-23'
title: '[Programmers] 연습문제 - 귤 고르기'
---

{% raw %}
> Lv. 2<br>

## 문제
경화는 과수원에서 귤을 수확했습니다. 경화는 수확한 귤 중 'k'개를 골라 상자 하나에 담아 판매하려고 합니다. 그런데 수확한 귤의 크기가 일정하지 않아 보기에 좋지 않다고 생각한 경화는 귤을 크기별로 분류했을 때 서로 다른 종류의 수를 최소화하고 싶습니다.

예를 들어, 경화가 수확한 귤 8개의 크기가 [1, 3, 2, 5, 4, 5, 2, 3] 이라고 합시다. 경화가 귤 6개를 판매하고 싶다면, 크기가 1, 4인 귤을 제외한 여섯 개의 귤을 상자에 담으면, 귤의 크기의 종류가 2, 3, 5로 총 3가지가 되며 이때가 서로 다른 종류가 최소일 때입니다.

경화가 한 상자에 담으려는 귤의 개수  `k`와 귤의 크기를 담은 배열  `tangerine`이 매개변수로 주어집니다. 경화가 귤 k개를 고를 때 크기가 서로 다른 종류의 수의 최솟값을 return 하도록 solution 함수를 작성해주세요.

### 제한사항
-   1 ≤  `k`  ≤  `tangerine`의 길이 ≤ 100,000
-   1 ≤  `tangerine`의 원소 ≤ 10,000,000

## 해결
선택한 아이템의 종류가 최소여야 하며, 가장 개수가 많은 종류를 선택하는 것이 항상 이득입니다 => `그리디`
1. 각 아이템의 출현 횟수 구하기: 종류 범위가 넓으므로 `map`을 사용합니다.
2. 출현 횟수 내림차순 `정렬`
3. `k`가 0이 될 때까지 출현 횟수를 순서대로 차감합니다.
	- 차감한 횟수가 최종 정답입니다.

## 코드
```
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
unordered_map<int, int> cnt;
vector<int> C; int idx, answer;

int solution(int k, vector<int> T) {
    for(auto t : T)
        cnt[t]++;
    sort(T.begin(), T.end());
	T.erase(unique(T.begin(), T.end()), T.end());
    for(auto t : T)
        C.push_back(cnt[t]);
    sort(C.begin(), C.end(), greater<int>());
    while(k > 0)
        k -= C[idx++], answer++;
    return answer;
}
```

## 링크
<br>https://school.programmers.co.kr/learn/courses/30/lessons/138476
{% endraw %}