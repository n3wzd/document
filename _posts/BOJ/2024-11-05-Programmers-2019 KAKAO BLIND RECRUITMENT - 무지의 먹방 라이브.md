---
categories:
- Programmers
date: '2024-11-05'
title: '[Programmers] 2019 KAKAO BLIND RECRUITMENT - 무지의 먹방 라이브'
---

{% raw %}
> Lv. 4<br>

## 문제
평소 식욕이 왕성한 무지는 자신의 재능을 뽐내고 싶어 졌고 고민 끝에 카카오 TV 라이브로 방송을 하기로 마음먹었다.

그냥 먹방을 하면 다른 방송과 차별성이 없기 때문에 무지는 아래와 같이 독특한 방식을 생각해냈다.

회전판에 먹어야 할 N 개의 음식이 있다.  
각 음식에는 1부터 N 까지 번호가 붙어있으며, 각 음식을 섭취하는데 일정 시간이 소요된다.  
무지는 다음과 같은 방법으로 음식을 섭취한다.

-   무지는 1번 음식부터 먹기 시작하며, 회전판은 번호가 증가하는 순서대로 음식을 무지 앞으로 가져다 놓는다.
-   마지막 번호의 음식을 섭취한 후에는 회전판에 의해 다시 1번 음식이 무지 앞으로 온다.
-   무지는 음식 하나를 1초 동안 섭취한 후 남은 음식은 그대로 두고, 다음 음식을 섭취한다.
    -   다음 음식이란, 아직 남은 음식 중 다음으로 섭취해야 할 가장 가까운 번호의 음식을 말한다.
-   회전판이 다음 음식을 무지 앞으로 가져오는데 걸리는 시간은 없다고 가정한다.

무지가 먹방을 시작한 지 K 초 후에 네트워크 장애로 인해 방송이 잠시 중단되었다.  
무지는 네트워크 정상화 후 다시 방송을 이어갈 때, 몇 번 음식부터 섭취해야 하는지를 알고자 한다.  
각 음식을 모두 먹는데 필요한 시간이 담겨있는 배열 food_times, 네트워크 장애가 발생한 시간 K 초가 매개변수로 주어질 때 몇 번 음식부터 다시 섭취하면 되는지 return 하도록 solution 함수를 완성하라.

### 제한사항
-   food_times 는 각 음식을 모두 먹는데 필요한 시간이 음식의 번호 순서대로 들어있는 배열이다.
-   k 는 방송이 중단된 시간을 나타낸다.
-   만약 더 섭취해야 할 음식이 없다면  `-1`을 반환하면 된다.
-   food_times 의 길이는  `1`  이상  `200,000`  이하이다.
-   food_times 의 원소는  `1`  이상  `100,000,000`  이하의 자연수이다.
-   k는  `1`  이상  `2 x 10^13`  이하의 자연수이다.

## 해결
값이 1 이상인 배열을 순회하여 -1을 더했을 때 가장 마지막 위치를 찾아야 합니다. 주어진 배열에서 최솟값이 a일 때, 배열 순회는 총 a번 발생합니다. 그리고 다음 순회부턴 a와 같은 값을 가진 원소들이 배열에서 제외됩니다. 즉, `k`에서 현재 배열 길이만큼 지속 감량하는 방법으로 답을 빠르게 구할 수 있습니다. 최종적으로 `k`를 더 이상 뺄 수 없을 때(k가 음수가 되기 전) 탐색이 종료됩니다. 이때 `k`는 가장 최근 이전 음식 용량보다 큰 음식만 포함한 배열에서의 인덱스를 의미합니다.  모든 순회를 해도 `k`가 양의 정수면 더 섭취해야 할 음식이 없는 경우입니다.

매 사이클마다 적용되는 k에 대한 수식은 다음과 같습니다:
> k -= (현재 배열 길이) × (현재 음식 용량 - 이전 음식 용량)<br>

예시: (`k` = 100, `len` = 초기 배열 길이 = 12)
|값|개수|수식|k|
|---|---|---|---|
|2|6|k - (len - 0) × 2|76|
|3|4|k - (len - 6) × 1|70|
|5|2|k - (len - 10) × 2|66|

카운팅 배열(C[음식 용량] = 해당 용량과 같은 음식 개수)을 정의합니다. 가능한 음식 용량이 큰 수이므로 바로 1차원 배열에 적용하긴 어렵습니다. `맵`을 사용해서 저장한 뒤, 이를 동적 배열에 옮기고 이 배열을 용량 오름차순으로 `정렬`해줍니다.

k는 큰 수 이므로 자료형 오버플로우에 유의합니다.

## 코드
```
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
typedef long long ll;

int solution(vector<int> food_times, ll k) {
    map<int, int> cntMap; vector<vector<int>> cnt;
    for(int food : food_times)
        cntMap[food] ? cntMap[food]++ : cntMap[food] = 1;
    for (const auto& pair : cntMap)
        cnt.push_back({ pair.first, pair.second });
    sort(cnt.begin(), cnt.end(), [](const vector<int>& s1, const vector<int>& s2) {
        return s1[0] < s2[0];
    });
    ll prevFood = 0, foodLen = food_times.size();
    for(auto c : cnt) {
        ll eat = foodLen * (c[0] - prevFood);
        if(k < eat) {
            ll idx = k % foodLen, res = 1;
            for(int food : food_times) {
                if(food > prevFood)
                    if(idx-- == 0)
                        return res;
                res++;
            }
        }
        k -= eat;
        foodLen -= c[1], prevFood = c[0];
    }
    return -1;
}
```

## 링크
<br>https://school.programmers.co.kr/learn/courses/30/lessons/42891
{% endraw %}