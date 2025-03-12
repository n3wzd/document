---
categories:
- Programmers
date: '2024-11-14'
title: '[Programmers] 월간 코드 챌린지 시즌1 - 짝수 행 세기'
---

{% raw %}
> Lv. 4<br>

## 문제
모든 수가 0 또는 1로 이루어진 2차원 배열 a가 주어집니다. 다음 조건을 모두 만족하는 2차원 배열 b의 경우의 수를 (107  + 19)로 나눈 나머지를 return 하도록 solution 함수를 완성해주세요.

-   b의 모든 원소는 0 아니면 1입니다.
-   a의 행/열의 개수와 b의 행/열의 개수가 같습니다. (= a와 b의 크기가 같습니다.)
-   `i = 1, 2, ..., (a의 열의 개수)`에 대해서 a의 i번째 열과 b의 i번째 열에 들어 있는 1의 개수가 같습니다.
-   b의 각 행에 들어 있는 1의 개수가 짝수입니다. (0도 짝수입니다.)

### 제한 사항
-   a의 행의 개수는 1 이상 300 이하입니다.
    -   a의 각 행의 길이는 1 이상 300 이하로 모두 동일합니다.

## 해결
모든 경우의 수를 계산해야 하며, 계산 과정에서 중복 상태가 존재합니다. => `DP`

어떠한 열에 포함된 1의 개수가 2개라고 가정합시다. 이 열을 어떻게 배열하든, 다음 열에는 2개의 행만이 계산에 영향을 받습니다. 즉,  열의 1의 개수가 중요합니다. (이전 열의 배치 방법은 다음 열의 경우의 수 계산 방법이 달라지지 않습니다.)

탐색 상태를 (`x` = 현재 열, `k` = 1을 반드시 배치해야 하는 행의 개수)로 정의합니다. 목표 상태는 `DP(M, 0)`입니다. (`N` = 열 길이, `M` = 행 길이)
> DP(x, k)<br>

`k`가 0이어야 문제의 조건에 맞는 행렬이므로 초기 상태인 `DP(0, 0)`의 값을 1로 설정합니다.

다음으로 점화식을 구해봅시다. 먼저 다음과 같은 예시를 가정합니다: (`A[x]` = `x`번 열에서 배치할 1 개수, `q` = 경우의 수)
```
A[x] = 1
DP(x, k) = DP(x + 1, k + 1) * q + DP(x + 1, k - 1) * q

A[x] = 2
DP(x, k) = DP(x + 1, k + 2) * q + DP(x + 1, k) * q + DP(x + 1, k - 2) * q

A[x] = 3
DP(x, k) = DP(x + 1, k + 3) * q + DP(x + 1, k + 1) * q + DP(x + 1, k - 1) * q + DP(x + 1, k - 3) * q
...
```

경우의 수 `q`를 구해봅시다. 현재 열을 2개의 영역으로 구분할 수 있습니다:
```
0 0 0 ... 0 | 1 1 1 ... 1
ㄴ N - k개     ㄴ k개
```

구분된 영역에서 `A[x]`개의 1을 배치하는 경우이며, 이는 `조합`으로 구할 수 있습니다. 0이 있는 곳에 `i`개만큼 1을 배치했을 때, `q`는 다음과 같습니다:
> q = <sub>N-k</sub>C<sub>i</sub> × <sub>k</sub>C<sub>A[x]-i</sub><br>

정리하여 다음과 같은 최종 점화식을 얻습니다:
> DP(x, k) = ∑ i (0, A[x]): DP(x - 1, nextK) × <sub>(N-k)</sub>C<sub>i</sub> × <sub>k</sub>C<sub>A[x]-i</sub><br>
> nextK = k + (i × 2 - A[x])<br>

**기타**
- 조합의 값은 `DP`로 구할 수 있습니다.
- 경우의 수가 충분히 큰 수이므로 `모듈러 연산`을 적용합니다.
- 입력이 크기 때문에 `Top-down` 구현시 스택 오버플로우가 발생할 수 있습니다. `Bottom-up`으로 구현해야 합니다.

## 코드
```
#include <vector>
using namespace std;
typedef long long ll;
const ll p = 1e7 + 19;
ll N, M, DP[301][301], A[301], C[301][301];
ll add(ll a, ll b) { return ((a % p) + (b % p)) % p; }
ll mul(ll a, ll b) { return ((a % p) * (b % p)) % p; }

void combination() {
    int L = max(N, M);
    for (int a = 0; a <= L; a++) {
        C[a][0] = C[a][a] = 1;
        for (int b = 1; b < a; b++)
            C[a][b] = add(C[a - 1][b - 1], C[a - 1][b]);
    }
}

void solve() {
    DP[0][0] = 1;
    for (int x = 1; x <= M; x++) {
        for (int k = 0; k <= N; k++) {
            for (int i = 0; i <= A[x]; i++) {
                ll nextK = k + (i * 2 - A[x]);
                if(nextK >= 0 && nextK <= N && A[x] - i >= 0)
                    DP[x][k] = add(DP[x][k], mul(DP[x - 1][nextK], mul(C[N - k][i], C[k][A[x] - i])));
            }
        }
    }
}

int solution(vector<vector<int>> a) {
    N = a.size(), M = a[0].size();
    for (int x = 1; x <= M; x++)
        for (int y = 0; y < N; y++)
            A[x] += a[y][x - 1];
    combination(); solve();
    return DP[M][0];
}
```

## 링크
<br>https://school.programmers.co.kr/learn/courses/30/lessons/68647
{% endraw %}