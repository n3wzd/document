---
categories:
- Programmers
date: '2024-11-13'
title: '[Programmers] 2019 KAKAO TECH INTERNSHIP - 호텔 방 배정'
---

{% raw %}
> Lv. 4<br>

## 문제
"스노우타운"에서 호텔을 운영하고 있는 "스카피"는 호텔에 투숙하려는 고객들에게 방을 배정하려 합니다. 호텔에는 방이 총 k개 있으며, 각각의 방은 1번부터 k번까지 번호로 구분하고 있습니다. 처음에는 모든 방이 비어 있으며 "스카피"는 다음과 같은 규칙에 따라 고객에게 방을 배정하려고 합니다.

1.  한 번에 한 명씩 신청한 순서대로 방을 배정합니다.
2.  고객은 투숙하기 원하는 방 번호를 제출합니다.
3.  고객이 원하는 방이 비어 있다면 즉시 배정합니다.
4.  고객이 원하는 방이 이미 배정되어 있으면 원하는 방보다 번호가 크면서 비어있는 방 중 가장 번호가 작은 방을 배정합니다.

전체 방 개수 k와 고객들이 원하는 방 번호가 순서대로 들어있는 배열 room_number가 매개변수로 주어질 때, 각 고객에게 배정되는 방 번호를 순서대로 배열에 담아 return 하도록 solution 함수를 완성해주세요.

### 제한사항
-   k는 1 이상 1012  이하인 자연수입니다.
-   room_number 배열의 크기는 1 이상 200,000 이하입니다.
-   room_number 배열 각 원소들의 값은 1 이상 k 이하인 자연수입니다.
-   room_number 배열은 모든 고객이 방을 배정받을 수 있는 경우만 입력으로 주어집니다.
    -   예를 들어, k = 5, room_number = [5, 5] 와 같은 경우는 방을 배정받지 못하는 고객이 발생하므로 이런 경우는 입력으로 주어지지 않습니다.

## 해결
다음 방이 방문되었다고 가정합니다:
```
[ 4, 7, 8, 11 ]
```
아래과 같은 방이 요청되었을 때, 각각의 답은 아래와 같습니다:
- 4 => 5<br>
- 7, 8 => 9<br>
- 11 => 12<br>

여기서 연속한 방들은 답이 공통이라는 것을 발견할 수 있습니다. 방문한 연속된 방들을 집합으로 묶습니다. 방 요청이 들어오면 집합의 최댓값을 반환하면 정답을 구할 수 있습니다. 이는 `분리 집합`으로 구현할 수 있습니다.

집합의 루트 노드를 집합의 최댓값으로 하면 Find 연산으로 정답을 찾을 수 있습니다. 집합의 최댓값의 다음 방은 항상 사용 가능함이 보장됩니다. 두 집합을 Union할 때는 최댓값이 작은 집합을 서브 트리로 합니다.

```
현재 방(n) 요청
1. 방의 정답 구하기:
	- 주어진 방을 포함한 집합 존재시, Find(n) + 1
	- 그렇지 않으면, n
2. 찾은 방을 집합으로 설정
3. 찾은 방과 인접한 양쪽 방의 집합이 각각 존재한다면,
	- 찾은 방과 각 양쪽 방 Union 수행
```

**최적화**
- Find의 시간을 단축할 필요가 있으며, `Collapsing-Find`를 적용해야 합니다. 현재 정점부터 루트 정점을 제외한 모든 정점의 parent 값을 루트 정점으로 변경해줍니다.
- 방의 번호가 충분히 큰 수이므로 배열로 인덱싱을 할 수 없으며, `해시 테이블`을 사용해야 합니다. C++일 경우, `unordered_map`을 사용하면 됩니다. (문제의 시간 제한이 빡빡한 편이라, 일반 `map`은 시간 초과가 뜹니다.)
- 충분히 큰 수를 사용하므로 오버플로우에 유의합니다.

## 코드
```
#include <vector>
#include <unordered_map>
using namespace std;
typedef long long ll;
unordered_map<ll, ll> parent;<br>
bool isExist(ll n) { return parent[n] != 0; }

ll Find(ll n) {
    ll p = n, p2 = n;
    while (parent[p] != -1) p = parent[p];
    while (parent[p2] != -1) {
        ll tmp = parent[p2];
        parent[p2] = p;
        p2 = tmp;
    }
    return p;
}

void Union(ll a, ll b) {
    ll p1 = Find(a);
    ll p2 = Find(b);
    p1 > p2 ? parent[p2] = p1 : parent[p1] = p2;<br>
}

vector<ll> solution(ll k, vector<ll> room_number) {<br>
    vector<ll> answer;<br>
    for (auto num : room_number) {
        ll next = isExist(num) ? Find(num) + 1 : num;
        parent[next] = -1;
        answer.push_back(next);
        if (isExist(next + 1))
            Union(next, next + 1);
        if (isExist(next - 1))
            Union(next, next - 1);
    }
    return answer;
}
```

## 링크
https://school.programmers.co.kr/learn/courses/30/lessons/64063
{% endraw %}