---
categories:
- Programmers
date: '2024-12-01'
title: '[Programmers] 연습문제 - 연속된 부분 수열의 합'
---

{% raw %}
> Lv. 2<br>

## 문제
비내림차순으로 정렬된 수열이 주어질 때, 다음 조건을 만족하는 부분 수열을 찾으려고 합니다.

-   기존 수열에서 임의의 두 인덱스의 원소와 그 사이의 원소를 모두 포함하는 부분 수열이어야 합니다.
-   부분 수열의 합은  `k`입니다.
-   합이  `k`인 부분 수열이 여러 개인 경우 길이가 짧은 수열을 찾습니다.
-   길이가 짧은 수열이 여러 개인 경우 앞쪽(시작 인덱스가 작은)에 나오는 수열을 찾습니다.

수열을 나타내는 정수 배열  `sequence`와 부분 수열의 합을 나타내는 정수  `k`가 매개변수로 주어질 때, 위 조건을 만족하는 부분 수열의 시작 인덱스와 마지막 인덱스를 배열에 담아 return 하는 solution 함수를 완성해주세요. 이때 수열의 인덱스는 0부터 시작합니다.

### 제한사항
-   5 ≤  `sequence`의 길이 ≤ 1,000,000
    -   1 ≤  `sequence`의 원소 ≤ 1,000
    -   `sequence`는 비내림차순으로 정렬되어 있습니다.
-   5 ≤  `k`  ≤ 1,000,000,000
    -   `k`는 항상  `sequence`의 부분 수열로 만들 수 있는 값입니다.

## 해결
구간 합이 `K`인 것에서 구간 길이가 최소인 것을 찾아야 합니다. 합은 결합 법칙이 성립하므로 `슬라이딩 윈도우`를 활용해서 O(N) 시간으로 계산 가능합니다. 구현은 `덱`이나 `투 포인터`를 사용하면 됩니다.

덱을 사용할 경우, 현재 구간은 덱 그 자체가 됩니다. 다음은 순회 과정입니다:
```
1. 구간 합이 K보다 같거나 클 때까지 덱 뒤에 다음 값 추가
2. 구간 합이 K보다 작을 때까지 다음 수행:
	1. 구간 합이 K이고 현재 구간이 최소 길이인 경우:
		- 정답 업데이트
	2. 덱 앞의 값 제거
```

## 코드
```
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> S, int K) {
    deque<int> q;
    int sum = 0, N = S.size(), i = 0, lo = 0, hi = N - 1;
    for (int i = 0; i < N;) {
        while (sum < K && i < N) {
            q.push_back(S[i]);
            sum += S[i++];
        }
        while (sum >= K) {
            if (sum == K && (q.size() - 1 < hi - lo))
                lo = i - q.size(), hi = i - 1;
            sum -= q.front();
            q.pop_front();
        }
    }
    return { lo, hi };
}
```

## 링크
<br>https://school.programmers.co.kr/learn/courses/30/lessons/178870
{% endraw %}