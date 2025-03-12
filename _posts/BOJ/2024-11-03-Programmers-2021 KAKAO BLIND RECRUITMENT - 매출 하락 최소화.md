---
categories:
- Programmers
date: '2024-11-03'
title: '[Programmers] 2021 KAKAO BLIND RECRUITMENT - 매출 하락 최소화'
---

{% raw %}
> Lv. 4<br>

## 문제
유통전문회사  `카카오상사`의 오너인  `제이지`는 새로운 사업 아이템을 구상하기 위해 전문경영인(CEO)인  `프로도`에게 회사의 경영을 부탁하였습니다.  

"제이지"는 자신이 구상한 새로운 사업 아이템에 대해 직원들에게 설명하고자 하루 일정으로 워크숍을 계획하고 있습니다. 단, 모든 직원을 참석시킬 수 없어 아래와 같은 기준으로 워크숍에 참석할 직원들을 선발하려고 합니다.

1.  워크숍에서 교육받은 내용은 전 직원들에게 공유되어야 하므로  `모든 팀은 최소 1명 이상`의 직원을 워크숍에 참석시켜야 합니다.
2.  워크숍 기간 동안, 회사의 매출 손실을 최소화하는 것이 중요하므로 워크숍에 참석하는 직원들의 하루평균 매출액의 합이 최소가 되어야 합니다.

직원들의 하루평균 매출액 값을 담은 배열 sales, 직원들의  `팀장-팀원`의 관계를 나타내는 2차원 배열 links가 매개변수로 주어집니다. 이때, 모든 팀에서 최소 한 명 이상 워크숍에 참석하면서, 참석하는 직원들의 하루평균 매출액의 합을 최소로 하려고 합니다. 그렇게 최소화된 매출액의 합을 구해서 return 하도록 solution 함수를 완성해 주세요.

### 제한사항
-   sales 배열의 크기는 2 이상 300,000 이하입니다. sales 배열의 크기는 CEO를 포함한 전체 직원 수와 같습니다.
    -   sales 배열은 각 직원들의 하루평균 매출액을 담고 있으며,  `1번`  직원부터 직원번호 순서대로 주어집니다.
    -   sales 배열의 각 원소의 값은 0 이상 10,000 이하인 정수입니다.
-   links 배열의 크기는  `sales 배열의 크기 - 1`  입니다. 즉, 전체 직원 수보다 1이 작습니다.
-   links 배열의 각 원소는 [a, b] 형식입니다.
    -   a는 팀장의 직원번호, b는 a팀장이 관리하는 팀원의 직원번호이며, a와 b는 서로 다른 자연수입니다.
    -   1 ≤  `a`  ≤  `sales 배열의 크기`  입니다.
    -   2 ≤  `b`  ≤  `sales 배열의 크기`  입니다.
    -   직원번호 1은 CEO로 정해져 있고 CEO는 항상 팀장으므로 b ≠ 1 입니다.
    -   links 배열로 만들어지는 조직도는 하나의 트리 구조 형태입니다.
-   정답으로 return 되는 값은 231  - 1 이하인 자연수임이 보장됩니다.

## 해결
- 전체 직원 구조는 트리입니다. 팀은 부모-자식을 의미하며, 한 팀에서 팀장은 무조건 1명입니다.
	- 직원 = 정점, 팀장 = 부모 정점, 팀원 = 자식 정점, CEO = 루트 정점
- 어떤 직원이 2개의 소속을 가졌다면 두 팀에서 모두 참석한 것으로 인정되므로, 그리디를 사용할 수 없으며 모든 경우를 조사해야 합니다. => `트리 DP`

현재 상태를 (현재 직원)으로 정의합시다. 최소 팀에서 1명은 참석해야 하므로, 점화식은 다음과 같습니다: (N = 팀장, C<sub>i</sub> = 팀원, M = 매출)
> DP(N) = min(팀장 참석, 팀원1 참석, 팀원2 참석, ...)<br>
> 팀장 참석 = M(N) + DP(C<sub>1</sub>) + DP(C<sub>2</sub>) + ...<br>
> 팀원1 참석 = (M(C<sub>1</sub>) + DP(C<sub>1-1</sub>) + DP(C<sub>1-2</sub>) + ...) + DP(C<sub>2</sub>) + DP(C<sub>3</sub>) + ...<br>
> 팀원2 참석 = DP(C<sub>1</sub>) + (M(C<sub>2</sub>) + DP(C<sub>2-1</sub>) + DP(C<sub>2-2</sub>) + ...) + DP(C<sub>3</sub>) + ...<br>

구현상 편의를 위해 점화식을 정리해봅시다. 어떠한 팀원이 참석했다는 것은 해당 팀원이 팀장인 팀에서 **반드시** 참석했다는 것과 같습니다. 현재 상태를 확장하여 (현재 직원, 필수 참석 여부)로 정의하면 점화식은 다음과 같습니다. (0 - 선택 참석, 1 - 반드시 참석)

> DP(N, 1) = min(팀장 참석)<br>
> DP(N, 0) = min(팀장 참석, 팀원1 참석, 팀원2 참석, ...)<br>
> 팀장 참석 = M(N) + DP(C<sub>1</sub>, 0) + DP(C<sub>2</sub>, 0) + ...<br>
> 팀원1 참석 = DP(C<sub>1</sub>, 1) + DP(C<sub>2</sub>, 0) + DP(C<sub>3</sub>, 0) + ...<br>
> 팀원2 참석 = DP(C<sub>1</sub>, 0) + DP(C<sub>2</sub>, 1) + DP(C<sub>3</sub>, 0) + ...<br>

초항은 단말 정점입니다. 필수 참석 여부가 1이라면 해당 정점의 매출, 그렇지 않으면 0을 반환합니다.

## 코드
```
#include <iostream>
#include <vector>
using namespace std;
vector<int> childs[300001], sales;
int cache[300001][2];

int DP(int n, int must) {
    if(cache[n][must] != -1)
        return cache[n][must];
    if(childs[n].size() == 0)
        return must ? sales[n] : 0;
    cache[n][must] = sales[n];
    for(int c : childs[n])
        cache[n][must] += DP(c, 0);
    if(!must) {
        for(int c1 : childs[n]) {
            int sum = DP(c1, 1);
            for(int c2 : childs[n])
                if(c1 != c2)
                    sum += DP(c2, 0);
            cache[n][must] = min(cache[n][must], sum);
        }
    }
    return cache[n][must];
}

int solution(vector<int> sales1, vector<vector<int>> links) {
    sales = sales1;
    for(int i = 0; i < sales.size(); i++)
        cache[i][0] = cache[i][1] = -1;
    for(auto edg : links)
        childs[edg[0] - 1].push_back(edg[1] - 1);
    return DP(0, 0);
}
```

## 링크
<br>https://school.programmers.co.kr/learn/courses/30/lessons/72416
{% endraw %}