---
categories:
- Programmers
date: '2024-10-28'
title: '[Programmers] 2023 KAKAO BLIND RECRUITMENT - 표현 가능한 이진트리'
---

{% raw %}
> Lv. 3<br>

## 문제
당신은 이진트리를 수로 표현하는 것을 좋아합니다.

이진트리를 수로 표현하는 방법은 다음과 같습니다.

1.  이진수를 저장할 빈 문자열을 생성합니다.
2.  주어진 이진트리에 더미 노드를 추가하여 포화 이진트리로 만듭니다.  **루트 노드는 그대로 유지합니다.**
3.  만들어진 포화 이진트리의 노드들을 가장 왼쪽 노드부터 가장 오른쪽 노드까지, 왼쪽에 있는 순서대로 살펴봅니다.  **노드의 높이는 살펴보는 순서에 영향을 끼치지 않습니다.**
4.  살펴본 노드가 더미 노드라면, 문자열 뒤에 0을 추가합니다. 살펴본 노드가 더미 노드가 아니라면, 문자열 뒤에 1을 추가합니다.
5.  문자열에 저장된 이진수를 십진수로 변환합니다.

**이진트리에서 리프 노드가 아닌 노드는 자신의 왼쪽 자식이 루트인 서브트리의 노드들보다 오른쪽에 있으며, 자신의 오른쪽 자식이 루트인 서브트리의 노드들보다 왼쪽에 있다고 가정합니다.**

당신은 수가 주어졌을때, 하나의 이진트리로 해당 수를 표현할 수 있는지 알고 싶습니다.

이진트리로 만들고 싶은 수를 담은 1차원 정수 배열  `numbers`가 주어집니다.  `numbers`에 주어진 순서대로 하나의 이진트리로 해당 수를 표현할 수 있다면 1을, 표현할 수 없다면 0을 1차원 정수 배열에 담아 return 하도록 solution 함수를 완성해주세요.

### 제한사항
-   1 ≤  `numbers`의 길이 ≤ 10,000
    -   1 ≤  `numbers`의 원소 ≤ 1015

## 해결
- 주어진 트리가 `트리` 구조를 유지하는지 판정합니다. 더미가 아닌 손자 노드를 보유한 더미 노드가 존재하면 트리가 아닙니다.
- 트리를 구성하기 위해 이진수 길이는 2<sup>N</sup> - 1이어야 합니다. 부족한 길이는 0으로 채웁니다.<br>
- 루트 노드의 번호는 (이진수 길이의 절반 + 1)입니다.

```
1. 정수를 2진수 배열로 변환
2. 루트 노드 찾기
3. 트리 탐색(시작점 = 루트 노드):
	- 현재 노드가 더미 and 더미가 아닌 손자 노드 존재 => 트리 아님<br>
```

## 코드
```
#include <vector>
#include <cstring>
using namespace std;
typedef long long ll;
bool tree[65]; int pass;

bool DFS(int n, int level) {
    if(level <= 1)
        return tree[n-1];
    bool hasLive = 0;
    hasLive |= DFS(n + level / 2, level / 2);
    hasLive |= DFS(n - level / 2, level / 2);
    if(hasLive && !tree[n-1])
        pass = 0;
    return tree[n-1];
}

int isTree(long long n) {
    memset(tree, 0, sizeof(tree));
    int len = 0, root = 1; pass = 1;
    while(n > 0) tree[len++] = n % 2, n /= 2;<br>
    while(root < len) root *= 2;
    root /= 2;
    DFS(root, root);
    return pass;
}

vector<int> solution(vector<ll> numbers) {<br>
    vector<int> answer;<br>
    for(ll n : numbers)
        answer.push_back(isTree(n));
    return answer;
}
```

## 링크
https://school.programmers.co.kr/learn/courses/30/lessons/150367<br>
{% endraw %}