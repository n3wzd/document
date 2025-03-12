---
categories:
- Programmers
date: '2024-10-31'
title: '[Programmers] 2022 KAKAO BLIND RECRUITMENT - k진수에서 소수 개수 구하기'
---

{% raw %}
> Lv. 2<br>

## 문제
양의 정수  `n`이 주어집니다. 이 숫자를  `k`진수로 바꿨을 때, 변환된 수 안에 아래 조건에 맞는 소수(Prime number)가 몇 개인지 알아보려 합니다.
-   `0P0`처럼 소수 양쪽에 0이 있는 경우
-   `P0`처럼 소수 오른쪽에만 0이 있고 왼쪽에는 아무것도 없는 경우
-   `0P`처럼 소수 왼쪽에만 0이 있고 오른쪽에는 아무것도 없는 경우
-   `P`처럼 소수 양쪽에 아무것도 없는 경우
-   단,  `P`는 각 자릿수에 0을 포함하지 않는 소수입니다.
    -   예를 들어, 101은  `P`가 될 수 없습니다.

예를 들어, 437674을 3진수로 바꾸면  `211`0`2`01010`11`입니다. 여기서 찾을 수 있는 조건에 맞는 소수는 왼쪽부터 순서대로 211, 2, 11이 있으며, 총 3개입니다. (211, 2, 11을  `k`진법으로 보았을 때가 아닌, 10진법으로 보았을 때 소수여야 한다는 점에 주의합니다.) 211은  `P0`  형태에서 찾을 수 있으며, 2는  `0P0`에서, 11은  `0P`에서 찾을 수 있습니다.

정수  `n`과  `k`가 매개변수로 주어집니다.  `n`을  `k`진수로 바꿨을 때, 변환된 수 안에서 찾을 수 있는  **위 조건에 맞는 소수**의 개수를 return 하도록 solution 함수를 완성해 주세요.

### 제한사항
-   1 ≤  `n`  ≤ 1,000,000
-   3 ≤  `k`  ≤ 10

## 해결
- 주어진 정수를 k진수로 변환한 뒤, 0을 기준으로 파싱해서 각 수마다 소수 판정을 하면 됩니다.
- 소수 크기는 충분히 큰 수이며 개수는 적으므로 2부터 제곱근까지 나머지를 비교하는 나이브한 방법으로 소수를 판정합니다.
- 파싱한 수는 int 자료형 기준으로 오버플로우될 수 있다는 점을 유의합니다. (예: 222222222)

## 코드
```
#include <queue>
#include <cmath>
using namespace std;
typedef long long ll;
queue<int> q;
int cnt = 0;

bool isPrime(ll n) {
    ll sq = sqrt(n);
    for (int d = 2; d <= sq; d++)
        if (n % d == 0)
            return 0;
    return 1;
}

void scan() {
    if(q.empty())
        return;
    ll p = 0, d = 1;
    while (!q.empty()) {
        p += q.front() * d; q.pop();
        d *= 10;
    }
    cnt += (p != 1 && isPrime(p)) ? 1 : 0;
}

int solution(int n, int k) {
    while (n > 0) {
        n % k != 0 ? q.push(n % k) : scan();
        n /= k;
    }
    scan();
    return cnt;
}
```

## 링크
<br>https://school.programmers.co.kr/learn/courses/30/lessons/92335
{% endraw %}