---
categories:
- Programmers
date: '2024-11-22'
title: '[Programmers] SummerWinter Coding(~2018) - 소수 만들기'
---

{% raw %}
> Lv. 1<br>

## 문제
주어진 숫자 중 3개의 수를 더했을 때 소수가 되는 경우의 개수를 구하려고 합니다. 숫자들이 들어있는 배열 nums가 매개변수로 주어질 때, nums에 있는 숫자들 중 서로 다른 3개를 골라 더했을 때 소수가 되는 경우의 개수를 return 하도록 solution 함수를 완성해주세요.

### 제한사항
-   nums에 들어있는 숫자의 개수는 3개 이상 50개 이하입니다.
-   nums의 각 원소는 1 이상 1,000 이하의 자연수이며, 중복된 숫자가 들어있지 않습니다.

## 해결
수열에서 3개의 수를 선택해서 더한 수가 소수인지 판별합니다. (`조합` 사용) 입력이 작으므로 `O(N)` 시간으로 소수를 판별할 수 있습니다.

## 코드
```
#include <vector>
#include <cmath>
using namespace std;
vector<int> nums;
int N, answer;
bool selected[51];

int isPrime(int n) {
    int d = sqrt(n);
    for(int i = 2; i <= d; i++)
        if(n % i == 0)
            return 0;
    return 1;
}

void combination(int start, int depth) {
    if(depth > 2) {
        int n = 0;
        for(int i = 0; i < N; i++)
            if(selected[i])
                n += nums[i];
        answer += isPrime(n);
        return;
    }
    for(int i = start; i < N; i++){
        selected[i] = 1;
        combination(i + 1, depth + 1);
        selected[i] = 0;
    }
}

int solution(vector<int> numsI) {
    nums = numsI; N = nums.size();
    combination(0, 0);
    return answer;
}
```

## 링크
<br>https://school.programmers.co.kr/learn/courses/30/lessons/12977
{% endraw %}