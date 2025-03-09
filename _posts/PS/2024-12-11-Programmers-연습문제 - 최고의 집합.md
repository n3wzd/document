---
categories:
- Programmers
date: '2024-12-11'
title: '[Programmers] 연습문제 - 최고의 집합'
---

{% raw %}
> Lv. 3<br>

## 문제
자연수 n 개로 이루어진 중복 집합(multi set, 편의상 이후에는 "집합"으로 통칭) 중에 다음 두 조건을 만족하는 집합을 최고의 집합이라고 합니다.

1.  각 원소의 합이 S가 되는 수의 집합
2.  위 조건을 만족하면서 각 원소의 곱 이 최대가 되는 집합

예를 들어서 자연수 2개로 이루어진 집합 중 합이 9가 되는 집합은 다음과 같이 4개가 있습니다.  
{ 1, 8 }, { 2, 7 }, { 3, 6 }, { 4, 5 }  
그중 각 원소의 곱이 최대인 { 4, 5 }가 최고의 집합입니다.

집합의 원소의 개수 n과 모든 원소들의 합 s가 매개변수로 주어질 때, 최고의 집합을 return 하는 solution 함수를 완성해주세요.

### 제한사항
-   최고의 집합은  **오름차순으로 정렬된 1차원 배열(list, vector)**  로 return 해주세요.
-   만약 최고의 집합이 존재하지 않는 경우에  **크기가 1인 1차원 배열(list, vector)**  에  `-1`  을 채워서 return 해주세요.
-   자연수의 개수 n은 1 이상 10,000 이하의 자연수입니다.
-   모든 원소들의 합 s는 1 이상, 100,000,000 이하의 자연수입니다.

## 해결
자연수의 분할 P(`s`, `n`) 중 곱이 최대인 것을 찾아야 합니다. 분할이 안되는 경우는 `s` < `n`입니다.

여러 수의 합이 일정할 때, 곱의 최댓값을 구하는 것과 같습니다. 산술-기하 평균 부등식에 의해 수가 최대한 모두 같은 것이 최대의 곱임이 보장됩니다.
```
1. a = s / n
2. d = s - (n * a)
3. n개의 a를 배열에 담기
4. d개의 1을 배열에 각각 분배
```

## 코드
```
#include <vector>
using namespace std;

vector<int> solution(int n, int s) {<br>
    if(s < n)
        return { -1 };
    vector<int> answer;<br>
    int a = s / n, d = s - (n * a);
    for(int i = 0; i < n; i++)
        answer.push_back(a);
    for(int i = 0; i < d; i++)
        answer[n - 1 - i] += 1;
    return answer;
}
```

## 링크
https://school.programmers.co.kr/learn/courses/30/lessons/12938
{% endraw %}