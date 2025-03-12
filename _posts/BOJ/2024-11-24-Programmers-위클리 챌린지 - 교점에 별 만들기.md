---
categories:
- Programmers
date: '2024-11-24'
title: '[Programmers] 위클리 챌린지 - 교점에 별 만들기'
---

{% raw %}
> Lv. 2<br>

## 문제
`Ax + By + C = 0`으로 표현할 수 있는  `n`개의 직선이 주어질 때, 이 직선의 교점 중 정수 좌표에 별을 그리려 합니다.

직선  `A, B, C`에 대한 정보가 담긴 배열  `line`이 매개변수로 주어집니다. 이때 모든 별을 포함하는 최소 사각형을 return 하도록 solution 함수를 완성해주세요.

### 제한사항
-   line의 세로(행) 길이는 2 이상 1,000 이하인 자연수입니다.
    -   line의 가로(열) 길이는 3입니다.
    -   line의 각 원소는 [A, B, C] 형태입니다.
    -   A, B, C는 -100,000 이상 100,000 이하인 정수입니다.
    -   무수히 많은 교점이 생기는 직선 쌍은 주어지지 않습니다.
    -   A = 0이면서 B = 0인 경우는 주어지지 않습니다.
-   정답은 1,000 * 1,000 크기 이내에서 표현됩니다.
-   별이 한 개 이상 그려지는 입력만 주어집니다.

## 해결
- 일차함수의 교점은 선형 연립 방정식이므로 `행렬`로 찾을 수 있습니다. 역행렬이나 크라머의 룰을 사용하면 사칙연산만으로 교점을 찾을 수 있습니다. (※ 교점을 찾는 식은 문제 하단에 주어집니다.)
- 교점 좌표는 정수여야 합니다. 좌표 값은 두 수의 몫이므로, 나머지가 0임을 이용해서 판정하면 됩니다.
- 모든 교점을 포함하는 최소의 범위는 교점의 x최소, x최대, y최소, y최대를 이용해서 구할 수 있습니다.
- 교점 연산 및 교점 좌표는 충분히 큰 수가 될 수 있습니다. C++ 기준, 모든 자료형을 `long long`으로 하는 것을 추천합니다.

## 코드
```
#include <vector>
#include <string>
using namespace std;
typedef long long ll;

vector<string> solution(vector<vector<int>> lines) {<br>
    vector<string> answer;<br>
    vector<vector<ll>> cross;<br>
    ll N = lines.size(), x1 = 1e12, x2 = -1e12, y1 = 1e12, y2 = -1e12;
    for(ll i = 0; i < N; i++) {
        for(ll j = i + 1; j < N; j++) {
            auto L1 = lines[i], L2 = lines[j];
            ll det = (ll)L1[0] * L2[1] - (ll)L2[0] * L1[1];
            ll A = (-(ll)L2[1] * L1[2] + (ll)L1[1] * L2[2]);
            ll B = ((ll)L2[0] * L1[2] - (ll)L1[0] * L2[2]);
            if(det != 0 && A % det == 0 && B % det == 0) {
                ll x = A / det, y = B / det;
                x1 = min(x1, x), x2 = max(x2, x);
                y1 = min(y1, y), y2 = max(y2, y);
                cross.push_back({ x, y });
            }
        }
    }
    for(ll y = y1; y <= y2; y++)
        answer.push_back(string(x2 - x1 + 1, '.'));
    for(auto c : cross)
        answer[y2 - c[1]][c[0] - x1] = '*';
    return answer;
}
```

## 링크
https://school.programmers.co.kr/learn/courses/30/lessons/87377<br>
{% endraw %}