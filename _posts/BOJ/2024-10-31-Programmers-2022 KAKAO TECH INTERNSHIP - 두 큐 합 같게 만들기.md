---
categories:
- Programmers
date: '2024-10-31'
title: '[Programmers] 2022 KAKAO TECH INTERNSHIP - 두 큐 합 같게 만들기'
---

{% raw %}
> Lv. 2<br>

## 문제
길이가 같은 두 개의 큐가 주어집니다. 하나의 큐를 골라 원소를 추출(pop)하고, 추출된 원소를  **다른 큐**에 집어넣는(insert) 작업을 통해 각 큐의 원소 합이 같도록 만들려고 합니다. 이때 필요한 작업의 최소 횟수를 구하고자 합니다. 한 번의 pop과 한 번의 insert를 합쳐서 작업을 1회 수행한 것으로 간주합니다.

큐는 먼저 집어넣은 원소가 먼저 나오는 구조입니다. 이 문제에서는 큐를 배열로 표현하며, 원소가 배열 앞쪽에 있을수록 먼저 집어넣은 원소임을 의미합니다. 즉, pop을 하면 배열의 첫 번째 원소가 추출되며, insert를 하면 배열의 끝에 원소가 추가됩니다. 예를 들어 큐  `[1, 2, 3, 4]`가 주어졌을 때, pop을 하면 맨 앞에 있는 원소 1이 추출되어  `[2, 3, 4]`가 되며, 이어서 5를 insert하면  `[2, 3, 4, 5]`가 됩니다.

길이가 같은 두 개의 큐를 나타내는 정수 배열  `queue1`,  `queue2`가 매개변수로 주어집니다. 각 큐의 원소 합을 같게 만들기 위해 필요한 작업의 최소 횟수를 return 하도록 solution 함수를 완성해주세요. 단, 어떤 방법으로도 각 큐의 원소 합을 같게 만들 수 없는 경우, -1을 return 해주세요.

### 제한사항

-   1 ≤  `queue1`의 길이 =  `queue2`의 길이 ≤ 300,000
-   1 ≤  `queue1`의 원소,  `queue2`의 원소 ≤ 109
-   주의: 언어에 따라 합 계산 과정 중 산술 오버플로우 발생 가능성이 있으므로 long type 고려가 필요합니다.

## 해결
- 두 큐의 합을 같게 하려면 항상 합이 더 큰 큐에 있는 값을 합이 작은 큐에 보내야 합니다. 이러한 과정을 반복하면 합이 같아지는 방향으로 수렴합니다. => `그리디`<br>
- 큐는 구별되지 않으므로, 두 큐가 큐 길이만큼 큐 연산을 수행하면 처음 상태와 동일하게 됩니다. 따라서 각 큐가 큐 길이만큼 연산할 때마다 사이클이 발생합니다. 주어진 큐에 따라 합 비교 탐색이 끝나지 않을 수 있으므로, 사이클이 판정되면 탐색을 종료해야 합니다.

## 코드
```
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
queue<int> q1, q2;<br>
int N, mv1, mv2; ll sum1, sum2 = 0;

int solution(vector<int> queue1, vector<int> queue2) {<br>
    N = queue1.size();
    for (int n : queue1) sum1 += n, q1.push(n);
    for (int n : queue2) sum2 += n, q2.push(n);
    while (mv1 < N || mv2 < N) {
        if(sum1 == sum2)
            return mv1 + mv2;
        else if(sum1 < sum2) {
            int n = q2.front(); q2.pop();
            sum1 += n; sum2 -= n; mv2++;
            q1.push(n);
        }
        else {
            int n = q1.front(); q1.pop();
            sum2 += n; sum1 -= n; mv1++;
            q2.push(n);
        }
    }
    return -1;
}
```

## 링크
https://school.programmers.co.kr/learn/courses/30/lessons/118667<br>
{% endraw %}