---
categories:
- Programmers
date: '2024-11-14'
title: '[Programmers] 월간 코드 챌린지 시즌1 - 두 개 뽑아서 더하기'
---

{% raw %}
> Lv. 1<br>

## 문제
정수 배열 numbers가 주어집니다. numbers에서 서로 다른 인덱스에 있는 두 개의 수를 뽑아 더해서 만들 수 있는 모든 수를 배열에 오름차순으로 담아 return 하도록 solution 함수를 완성해주세요.

### 제한사항
-   numbers의 길이는 2 이상 100 이하입니다.
    -   numbers의 모든 수는 0 이상 100 이하입니다.

## 해결
- 한 배열을 2중 순회할 때 인덱스가 같은 것을 제외한 모든 합을 찾습니다.
- C++ 기준, 중복 제거는 자료구조 `set`이나 `unique` 함수를 사용하면 됩니다.

## 코드
```
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> numbers) {<br>
    vector<int> answer; int N = numbers.size();<br>
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            if(i != j)
                answer.push_back(numbers[i] + numbers[j]);
    sort(answer.begin(), answer.end());
    answer.erase(unique(answer.begin(), answer.end()), answer.end());
    return answer;
}
```

## 링크
https://school.programmers.co.kr/learn/courses/30/lessons/68644
{% endraw %}