---
categories:
- Programmers
date: '2024-10-26'
title: '[Programmers] 2024 KAKAO WINTER INTERNSHIP - 주사위 고르기'
---

{% raw %}
> Lv. 3<br>

## 문제
A와 B가  `n`개의 주사위를 가지고 승부를 합니다. 주사위의 6개 면에 각각 하나의 수가 쓰여 있으며, 주사위를 던졌을 때 각 면이 나올 확률은 동일합니다. 각 주사위는 1 ~  `n`의 번호를 가지고 있으며, 주사위에 쓰인 수의 구성은 모두 다릅니다.

A가 먼저  `n / 2`개의 주사위를 가져가면 B가 남은  `n / 2`개의 주사위를 가져갑니다. 각각 가져간 주사위를 모두 굴린 뒤, 나온 수들을 모두 합해 점수를 계산합니다. 점수가 더 큰 쪽이 승리하며,  **점수가 같다면 무승부**입니다.

A는 자신이  **승리할 확률**이 가장 높아지도록 주사위를 가져가려 합니다.

주사위에 쓰인 수의 구성을 담은 2차원 정수 배열  `dice`가 매개변수로 주어집니다. 이때, 자신이 승리할 확률이 가장 높아지기 위해 A가 골라야 하는 주사위 번호를  **오름차순으로**  1차원 정수 배열에 담아 return 하도록 solution 함수를 완성해 주세요. 승리할 확률이 가장 높은 주사위 조합이 유일한 경우만 주어집니다.

### 제한사항
-   2 ≤  `dice`의 길이 =  `n`  ≤ 10
    -   `n`은 2의 배수입니다.
    -   `dice[i]`는  `i+1`번 주사위에 쓰인 6개의 수를 담고 있습니다.
    -   `dice[i]`의 길이 = 6
    -   1 ≤  `dice[i]`의 원소 ≤ 100

## 해결
A가 주사위를 선택하는 경우는 `조합`입니다. 최대 경우의 수는 <sub>N</sub>C<sub>N/2</sub>입니다. (N은 최대 10입니다.)

주사위 분배가 결정되었을 때, 승리 횟수를 조사해야 합니다. N개의 주사위가 나오는 경우의 수는 6<sup>N</sup>이라 시간 초과 리스크가 있습니다. 따라서 탐색 횟수를 줄여야 합니다.

만약 A의 주사위 총합이 S로 결정되었을 때, A가 승리하려면 B의 총합이 S 미만이어야 합니다. 즉, A의 총합과 B의 총합이 같아지는 순간을 찾는다면 승리 횟수를 바로 알 수 있습니다. 어떠한 리스트에서 특정 값을 찾는 것은 `lowerbound`로 빠르게 구할 수 있습니다. 이 방법의 시간 복잡도는 O(6<sup>N/2</sup> × log6<sup>N/2</sup>)입니다. => `Meet In The Middle`

```
승리 횟수 찾기
1. A, B의 주사위 모든 총합 찾기
2. B의 총합 리스트 오름차순 정렬
3. A의 총합 리스트 탐색:
	- 승리 횟수 += B의 총합 리스트에서 A의 총합에 대한 lowerbound
4. 승리 횟수 최댓값 업데이트
	- A의 주사위 조합 기록
```

## 코드
```
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;
int N, maxWin = -1;
bool selectedDice[10];
vector<int> winDeck, finalWinDeck;
vector<vector<int>> dice;

void sumDFS(vector<int>& diceIdx, vector<int>& sumList, int depth = 0, int sum = 0) {
    if (depth == N / 2) {
        sumList.push_back(sum);
        return;
    }
    for (int i = 0; i < 6; i++)
        sumDFS(diceIdx, sumList, depth + 1, sum + dice[diceIdx[depth]][i]);
}

void game() {
    vector<int> sumA, sumB, diceIdxA, diceIdxB;
    for (int s = 0; s < N; s++)
        selectedDice[s] ? diceIdxA.push_back(s) : diceIdxB.push_back(s);
    sumDFS(diceIdxA, sumA);
    sumDFS(diceIdxB, sumB);
    sort(sumB.begin(), sumB.end());

    int win = 0;
    for (int s : sumA)
        win += distance(sumB.begin(), lower_bound(sumB.begin(), sumB.end(), s));
    if (win > maxWin) {
        maxWin = win;
        winDeck = diceIdxA;
    }
}

void combination(int start = 0, int depth = 0) {
    if (depth == N / 2) {
        game();
        return;
    }
    for (int i = start; i < N; i++) {
        selectedDice[i] = 1;
        combination(i + 1, depth + 1);
        selectedDice[i] = 0;
    }
}

vector<int> solution(vector<vector<int>> diceInput) {
    dice = diceInput; N = dice.size();
    combination();
    for(int w : winDeck)
        finalWinDeck.push_back(w + 1);
    return finalWinDeck;
}
```

## 링크
<br>https://school.programmers.co.kr/learn/courses/30/lessons/258709
{% endraw %}