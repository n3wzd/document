---
categories:
- Programmers
date: '2024-11-23'
title: '[Programmers] SummerWinter Coding(~2018) - 쿠키 구입'
---

{% raw %}
> Lv. 4<br>

## 문제
과자를 바구니 단위로 파는 가게가 있습니다. 이 가게는 1번부터 N번까지 차례로 번호가 붙은 바구니 N개가 일렬로 나열해 놨습니다.

철수는 두 아들에게 줄 과자를 사려합니다. 첫째 아들에게는 l번 바구니부터 m번 바구니까지, 둘째 아들에게는 m+1번 바구니부터 r번 바구니까지를 주려합니다. 단, 두 아들이 받을 과자 수는 같아야 합니다(1 <= l <= m, m+1 <= r <= N). 즉, A[i] 를 i번 바구니에 들어있는 과자 수라고 했을 때,  `A[l]+..+A[m] = A[m+1]+..+A[r]`  를 만족해야 합니다.

각 바구니 안에 들은 과자 수가 차례로 들은 배열 cookie가 주어질 때, 조건에 맞게 과자를 살 경우 한 명의 아들에게 줄 수 있는 가장 많은 과자 수를 return 하는 solution 함수를 완성해주세요. (단, 조건에 맞게 과자를 구매할 수 없다면 0을 return 합니다)

### 제한사항
-   cookie의 길이는 1 이상 2,000 이하입니다.
-   cookie의 각각의 원소는 1 이상 500 이하인 자연수입니다.

## 해결
배열에서 임의의 구간을 분할했을 때, 두 구간의 합이 같은 순간을 찾아야 합니다. 모든 구간을 탐색해야 하고, 합은 선형 연산이므로 `덱`을 활용한 `슬라이딩 윈도우`로 최댓값을 찾을 수 있습니다.

분할된 두 구간을 의미하는 왼쪽 덱, 오른쪽 덱을 정의합니다. 항상 왼쪽 덱이 오른쪽 덱보다 같거나 큽니다. (여기서 덱의 크기는 덱에 포함된 원소의 총합을 의미합니다.) 배열의 시작 값부터 순차 탐색합니다:
1. 왼쪽 덱이 오른쪽 덱보다 같거나 큼: 오른쪽 덱이 커질 때까지 오른쪽 덱 뒤에 새로운 배열 값 넣기
2. 왼쪽 덱이 오른쪽 덱보다 작음: 왼쪽 덱이 같거나 커질 때까지 오른쪽 덱 앞의 값을 왼쪽 덱 뒤에 넣기

이 과정에서 두 덱의 합이 같아지는 순간이 있으며, 이때 최댓값을 업데이트하면 됩니다. 탐색의 시간 복잡도는 O(N)입니다.

단, 위 과정은 배열의 시작 값을 포함하지 않는 경우를 찾지 못합니다. 배열의 모든 값을 시작점으로 해서 탐색을 수행해야 모든 경우를 확인할 수 있습니다. 최종 시간 복잡도는 O(N<sup>2</sup>)입니다.

## 코드
```
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> cookie) {
    int answer = 0, N = cookie.size();
    for(int s = 0; s < N; s++) {
        deque<int> L, R;
        int sumL = 0, sumR = 0, i = s;
        while(i < N) {
            while(i < N && sumL >= sumR) {
                if(sumL == sumR)
                    answer = max(answer, sumL);
                R.push_back(cookie[i]);
                sumR += cookie[i]; i++;
            }
            while(sumL < sumR) {
                L.push_back(R.front()); R.pop_front();
                sumL += L.back(), sumR -= L.back();
            }
            if(sumL == sumR)
                answer = max(answer, sumL);
        }
    }
    return answer;
}
```

## 링크
<br>https://school.programmers.co.kr/learn/courses/30/lessons/49995
{% endraw %}