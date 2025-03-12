---
categories:
- Programmers
date: '2024-11-14'
title: '[Programmers] 월간 코드 챌린지 시즌1 - 쿼드압축 후 개수 세기'
---

{% raw %}
> Lv. 2<br>

## 문제
0과 1로 이루어진 2n  x 2n  크기의 2차원 정수 배열 arr이 있습니다. 당신은 이 arr을 쿼드 트리와 같은 방식으로 압축하고자 합니다. 구체적인 방식은 다음과 같습니다.

1.  당신이 압축하고자 하는 특정 영역을 S라고 정의합니다.
2.  만약 S 내부에 있는 모든 수가 같은 값이라면, S를 해당 수 하나로 압축시킵니다.
3.  그렇지 않다면, S를 정확히 4개의 균일한 정사각형 영역(입출력 예를 참고해주시기 바랍니다.)으로 쪼갠 뒤, 각 정사각형 영역에 대해 같은 방식의 압축을 시도합니다.

arr이 매개변수로 주어집니다. 위와 같은 방식으로 arr을 압축했을 때, 배열에 최종적으로 남는 0의 개수와 1의 개수를 배열에 담아서 return 하도록 solution 함수를 완성해주세요.

### 제한사항
-   arr의 행의 개수는 1 이상 1024 이하이며, 2의 거듭 제곱수 형태를 하고 있습니다. 즉, arr의 행의 개수는 1, 2, 4, 8, ..., 1024 중 하나입니다.
    -   arr의 각 행의 길이는 arr의 행의 개수와 같습니다. 즉, arr은 정사각형 배열입니다.
    -   arr의 각 행에 있는 모든 값은 0 또는 1 입니다.

## 해결
같은 구조가 재귀적으로 반복되므로 `분할정복 알고리즘`을 활용합니다.

탐색 상태를 ((`x`, `y`) = 사각형 위치, `d` = 사각형 길이)로 정의합니다. 현재 사각형의 내부 값이 모두 동일하면 해당 값의 카운트를 업데이트하고, 그렇지 않으면 4개의 균등한 사각형으로 분할합니다.

## 코드
```
#include <vector>
using namespace std;
vector<vector<int>> arr;<br>
int cnt[2];

void quad(int x, int y, int d) {
    bool ok = 1;
    for(int dy = 0; dy < d; dy++)
        for(int dx = 0; dx < d; dx++)
            ok &= arr[y][x] == arr[y + dy][x + dx];
    if(ok) {
        cnt[arr[y][x]]++;
        return;
    }
    int nd = d / 2;
    quad(x, y, nd);
    quad(x + nd, y, nd);
    quad(x, y + nd, nd);
    quad(x + nd, y + nd, nd);
}

vector<int> solution(vector<vector<int>> arrI) {<br>
    arr = arrI; quad(0, 0, arr.size());
    return { cnt[0], cnt[1] };
}
```

## 링크
https://school.programmers.co.kr/learn/courses/30/lessons/68936<br>
{% endraw %}