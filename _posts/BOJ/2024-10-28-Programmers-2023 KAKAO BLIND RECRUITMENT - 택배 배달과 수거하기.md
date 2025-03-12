---
categories:
- Programmers
date: '2024-10-28'
title: '[Programmers] 2023 KAKAO BLIND RECRUITMENT - 택배 배달과 수거하기'
---

{% raw %}
> Lv. 2<br>

## 문제
당신은 일렬로 나열된  `n`개의 집에 택배를 배달하려 합니다. 배달할 물건은 모두 크기가 같은 재활용 택배 상자에 담아 배달하며, 배달을 다니면서 빈 재활용 택배 상자들을 수거하려 합니다.  
배달할 택배들은 모두 재활용 택배 상자에 담겨서 물류창고에 보관되어 있고,  `i`번째 집은 물류창고에서 거리  `i`만큼 떨어져 있습니다. 또한  `i`번째 집은  `j`번째 집과 거리  `j - i`만큼 떨어져 있습니다. (1 ≤  `i`  ≤  `j`  ≤  `n`)  
트럭에는 재활용 택배 상자를 최대  `cap`개 실을 수 있습니다. 트럭은 배달할 재활용 택배 상자들을 실어 물류창고에서 출발해 각 집에 배달하면서, 빈 재활용 택배 상자들을 수거해 물류창고에 내립니다. 각 집마다 배달할 재활용 택배 상자의 개수와 수거할 빈 재활용 택배 상자의 개수를 알고 있을 때, 트럭 하나로 모든 배달과 수거를 마치고 물류창고까지 돌아올 수 있는 최소 이동 거리를 구하려 합니다.  **각 집에 배달 및 수거할 때, 원하는 개수만큼 택배를 배달 및 수거할 수 있습니다.**

트럭에 실을 수 있는 재활용 택배 상자의 최대 개수를 나타내는 정수  `cap`, 배달할 집의 개수를 나타내는 정수  `n`, 각 집에 배달할 재활용 택배 상자의 개수를 담은 1차원 정수 배열  `deliveries`와 각 집에서 수거할 빈 재활용 택배 상자의 개수를 담은 1차원 정수 배열  `pickups`가 매개변수로 주어집니다. 이때, 트럭 하나로 모든 배달과 수거를 마치고 물류창고까지 돌아올 수 있는 최소 이동 거리를 return 하도록 solution 함수를 완성해 주세요.

### 제한사항
-   1 ≤  `cap`  ≤ 50
-   1 ≤  `n`  ≤ 100,000
-   `deliveries`의 길이 =  `pickups`의 길이 =  `n`
    -   `deliveries[i]`는 i+1번째 집에 배달할 재활용 택배 상자의 개수를 나타냅니다.
    -   `pickups[i]`는 i+1번째 집에서 수거할 빈 재활용 택배 상자의 개수를 나타냅니다.
    -   0 ≤  `deliveries`의 원소 ≤ 50
    -   0 ≤  `pickups`의 원소 ≤ 50
-   트럭의 초기 위치는 물류창고입니다.

## 해결
집마다 이동 거리는 모두 동일하므로 한번 이동했을 때 이동 동선만 최대한 줄이면 됩니다. 항상 멀리 있는 집부터 처리하는 것이 최적입니다. => `그리디`<br>

```
운전 사이클: 완료 횟수가 2 * n이면 종료
1. 배달량, 회수량 최대치까지 충전
2. 거리 업데이트: 가장 먼 곳까지 거리 * 2
3. 가장 먼 곳부터 배달하기
	- 충전량이 0이 되면 탐색 종료
4. 가장 먼 곳부터 상자 회수
	- 회수량이 0이 되면 탐색 종료
5. 가장 먼 곳 업데이트: 가장 먼 배달 또는 회수 지점
```

## 코드
```
#include <vector>
using namespace std;
int success, last;
long long cnt = 0;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {<br>
    for (int i = 0; i < n; i++)
        deliveries[i] == 0 ? success++ : last = max(last, i);
    for (int i = 0; i < n; i++)
        pickups[i] == 0 ? success++ : last = max(last, i);
    while (success != n * 2) {
        int c = cap, d = cap, i = last, j = last;
        while (i >= 0) {
            if (deliveries[i] > 0) {<br>
                if (c >= deliveries[i]) {
                    c -= deliveries[i];
                    deliveries[i] = 0;
                    success++;
                }
                else {
                    deliveries[i] -= c;
                    c = 0;
                    break;
                }
            }
            i--;
        }
        while (j >= 0) {
            if (pickups[j] > 0) {<br>
                if (d >= pickups[j]) {
                    d -= pickups[j];
                    pickups[j] = 0;
                    success++;
                }
                else {
                    pickups[j] -= d;
                    d = 0;
                    break;
                }
            }
            j--;
        }
        cnt += (last + 1) * 2;
        last = max(i, j);
    }
    return cnt;
}
```

## 링크
https://school.programmers.co.kr/learn/courses/30/lessons/150369<br>
{% endraw %}