---
categories:
- Programmers
date: '2024-11-13'
title: '[Programmers] 2019 KAKAO TECH INTERNSHIP - 튜플'
---

{% raw %}
> Lv. 2<br>

## 문제
셀수있는 수량의 순서있는 열거 또는 어떤 순서를 따르는 요소들의 모음을 튜플(tuple)이라고 합니다. n개의 요소를 가진 튜플을 n-튜플(n-tuple)이라고 하며, 다음과 같이 표현할 수 있습니다.

-   (a1, a2, a3, ..., an)

튜플은 다음과 같은 성질을 가지고 있습니다.

1.  중복된 원소가 있을 수 있습니다. ex : (2, 3, 1, 2)
2.  원소에 정해진 순서가 있으며, 원소의 순서가 다르면 서로 다른 튜플입니다. ex : (1, 2, 3) ≠ (1, 3, 2)
3.  튜플의 원소 개수는 유한합니다.

원소의 개수가 n개이고,  **중복되는 원소가 없는**  튜플  `(a1, a2, a3, ..., an)`이 주어질 때(단, a1, a2, ..., an은 자연수), 이는 다음과 같이 집합 기호 '{', '}'를 이용해 표현할 수 있습니다.

-   {{a1}, {a1, a2}, {a1, a2, a3}, {a1, a2, a3, a4}, ... {a1, a2, a3, a4, ..., an}}

예를 들어 튜플이 (2, 1, 3, 4)인 경우 이는

-   {{2}, {2, 1}, {2, 1, 3}, {2, 1, 3, 4}}

와 같이 표현할 수 있습니다. 이때, 집합은 원소의 순서가 바뀌어도 상관없으므로

-   {{2}, {2, 1}, {2, 1, 3}, {2, 1, 3, 4}}
-   {{2, 1, 3, 4}, {2}, {2, 1, 3}, {2, 1}}
-   {{1, 2, 3}, {2, 1}, {1, 2, 4, 3}, {2}}

는 모두 같은 튜플 (2, 1, 3, 4)를 나타냅니다.

특정 튜플을 표현하는 집합이 담긴 문자열 s가 매개변수로 주어질 때, s가 표현하는 튜플을 배열에 담아 return 하도록 solution 함수를 완성해주세요.

### 제한사항
-   s의 길이는 5 이상 1,000,000 이하입니다.
-   s는 숫자와 '{', '}', ',' 로만 이루어져 있습니다.
-   숫자가 0으로 시작하는 경우는 없습니다.
-   s는 항상 중복되는 원소가 없는 튜플을 올바르게 표현하고 있습니다.
-   s가 표현하는 튜플의 원소는 1 이상 100,000 이하인 자연수입니다.
-   return 하는 배열의 길이가 1 이상 500 이하인 경우만 입력으로 주어집니다.

## 해결
- 집합 내 원소 순서는 무작위입니다. 즉, 튜플의 원소를 결정하려면 크기가 1인 집합부터 확인해야 합니다.
- 집합 길이의 오름차순 탐색을 위해 `정렬`을 사용합니다. (구현상 편의)
- 집합을 탐색하면서 이미 튜플에 존재하는 원소를 확인할 필요가 있습니다. 중복 판정을 위해 `set`을 활용합니다.

```
1. 입력을 정수를 저장하는 집합 목록으로 파싱
2. 집합 목록에서 길이 오름차순으로 탐색:
	1. 집합의 모든 원소 확인:
		- 튜플에 존재하지 않은 원소면 튜플에 추가
```

## 코드
```
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
int lo = 2, genID;
vector<vector<int>> arr;<br>
vector<int> answer;<br>
set<int> items;<br>

vector<int> solution(string s) {<br>
    arr.push_back({ });
    for (int i = 2; i < s.size() - 1; i++) {
        if (s[i] == '}') {
            arr[genID++].push_back(stoi(s.substr(lo, i - lo)));
            arr.push_back({ });
            lo = i + 3; i += 2;
        }
        else if (s[i] == ',') {
            arr[genID].push_back(stoi(s.substr(lo, i - lo)));
            lo = i + 1;
        }
    }
    sort(arr.begin(), arr.end(), [](const vector<int>& a, const vector<int>& b) {
        return a.size() < b.size();
    });
    for (auto subset : arr) {
        for (auto item : subset) {
            if (items.find(item) == items.end()) {
                items.insert(item);
                answer.push_back(item);
            }
        }
    }
    return answer;
}
```

## 링크
https://school.programmers.co.kr/learn/courses/30/lessons/64065<br>
{% endraw %}