---
categories:
- Programmers
date: '2024-10-27'
title: '[Programmers] 2024 KAKAO WINTER INTERNSHIP - 산 모양 타일링'
---

{% raw %}
> Lv. 3<br>

## 문제
한 변의 길이가 1인 정삼각형  `2n+1`개를 이어붙여 윗변의 길이가  `n`, 아랫변의 길이가  `n+1`인 사다리꼴을 만들 수 있습니다. 이때 사다리꼴의 윗변과 변을 공유하는  `n`개의 정삼각형 중 일부의 위쪽에 같은 크기의 정삼각형을 붙여 새로운 모양을 만들었습니다. 예를 들어  `n`이 4이고, 1번째, 2번째, 4번째 정삼각형 위에 정삼각형을 붙인 모양은 다음과 같습니다.

이렇게 만든 모양을  **정삼각형 타일**  또는 정삼각형 2개를 이어 붙인  **마름모 타일**로 빈 곳이 없도록 채우려고 합니다. 정삼각형 타일과 마름모 타일은 돌려서 사용할 수 있습니다.

타일을 놓을 때 다른 타일과 겹치거나 모양을 벗어나게 놓을 수는 없습니다. 위의 예시 모양을 채우는 방법 중 일부는 다음과 같습니다.

사다리꼴의 윗변의 길이를 나타내는 정수  `n`과 사다리꼴 윗변에 붙인 정삼각형을 나타내는 1차원 정수 배열  `tops`가 매개변수로 주어집니다. 이때 문제 설명에 따라 만든 모양을 정삼각형 또는 마름모 타일로 빈 곳이 없도록 채우는 경우의 수를  `10007`로 나눈 나머지를 return 하도록 solution 함수를 완성해 주세요.

### 제한사항
-   1 ≤  `n`  ≤ 100,000
-   `tops`의 길이 =  `n`
    -   `tops[i]`는 사다리꼴의 윗변과 변을 공유하는  `i+1`번째 정삼각형의 위쪽에 정삼각형을 붙이는 경우 1, 붙이지 않는 경우 0입니다.

## 해결
모든 경우의 찾아야 하며, 삼각 타일은 부분 문제로 분할 가능합니다. 부분 문제는 중복 탐색이 존재합니다. => `DP`

1층 삼각형의 번호(n)를 현재 상태로 정의합니다. n이 짝수, 홀수에 따라 구하는 답이 달라집니다. 초기 값은 1이며, 점화식은 다음과 같습니다. (T[n] = n번 삼각형 위에 있는 삼각형의 개수)
> if n is even<br>
> DP[n] = DP[n - 1] × (T[n] + 1) + DP[n - 2]<br>

> if n is odd<br>
> DP[n] = DP[n - 1] + DP[n - 2]<br>

- n은 최대 200001이므로 Bottom-Up으로 구현해야 합니다.
- 답은 10007보다 클 수 있으므로 `모듈러 연산`을 계산 과정에 적용합니다.

## 코드
```
#include <vector>
using namespace std;
vector<int> tops;
int N, DP[200003];
const int p = 10007;
int ModAdd(int a, int b) { return ((a % p) + (b % p)) % p; }
int ModMul(int a, int b) { return ((a % p) * (b % p)) % p; }

int solution(int n, vector<int> tops1) {
    tops = tops1; N = 2 * n + 1; DP[0] = DP[1] = 1;
    for (int i = 2; i <= N; i++)
        DP[i] = (i % 2 == 0)
            ? ModAdd(ModMul(DP[i - 1], (tops[i / 2 - 1] ? 2 : 1)), DP[i - 2])
            : ModAdd(DP[i - 1], DP[i - 2]);
    return DP[N];
}
```

## 링크
<br>https://school.programmers.co.kr/learn/courses/30/lessons/258705
{% endraw %}