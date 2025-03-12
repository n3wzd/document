---
categories:
- Programmers
date: '2024-12-18'
title: '[Programmers] 연습문제 - 연속 부분 수열 합의 개수'
---

{% raw %}
> Lv. 2<br>

## 문제
철호는 수열을 가지고 놀기 좋아합니다. 어느 날 철호는 어떤 자연수로 이루어진 원형 수열의 연속하는 부분 수열의 합으로 만들 수 있는 수가 모두 몇 가지인지 알아보고 싶어졌습니다. 원형 수열이란 일반적인 수열에서 처음과 끝이 연결된 형태의 수열을 말합니다. 예를 들어 수열 [7, 9, 1, 1, 4] 로 원형 수열을 만들면 다음과 같습니다.  
  
원형 수열은 처음과 끝이 연결되어 끊기는 부분이 없기 때문에 연속하는 부분 수열도 일반적인 수열보다 많아집니다.  
원형 수열의 모든 원소  `elements`가 순서대로 주어질 때, 원형 수열의 연속 부분 수열 합으로 만들 수 있는 수의 개수를 return 하도록 solution 함수를 완성해주세요.

### 제한사항
-   3 ≤  `elements`의 길이 ≤ 1,000
-   1 ≤  `elements`의 원소 ≤ 1,000

## 해결
원형 리스트에서 모든 구간 합의 종류를 카운팅해야 합니다.
- 구간 합은 `누적 합`으로 구하면 빠릅니다. 원형 리스트이므로 누적 합을 배열 길이의 2배만큼 확장합니다.
- 종류 개수는 집합 `set`으로 카운팅하면 됩니다.

## 코드
```
#include <vector>
#include <set>
using namespace std;
int ps[2001];

int solution(vector<int> A) {
    int N = A.size(); set<int> S;
    ps[0] = A[0];
    for(int i = 1; i < N * 2; i++)
        ps[i] = ps[i - 1] + A[i % N];
    for(int i = 0; i < N; i++)
        for(int j = 1; j <= N; j++)
            S.insert(ps[i + j] - ps[i]);
    return S.size();
}
```

## 링크
<br>https://school.programmers.co.kr/learn/courses/30/lessons/131701
{% endraw %}