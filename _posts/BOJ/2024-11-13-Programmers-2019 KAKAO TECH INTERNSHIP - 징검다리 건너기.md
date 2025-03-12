---
categories:
- Programmers
date: '2024-11-13'
title: '[Programmers] 2019 KAKAO TECH INTERNSHIP - 징검다리 건너기'
---

{% raw %}
> Lv. 3<br>

## 문제
카카오 초등학교의 "니니즈 친구들"이 "라이언" 선생님과 함께 가을 소풍을 가는 중에  **징검다리**가 있는 개울을 만나서 건너편으로 건너려고 합니다. "라이언" 선생님은 "니니즈 친구들"이 무사히 징검다리를 건널 수 있도록 다음과 같이 규칙을 만들었습니다.

-   징검다리는 일렬로 놓여 있고 각 징검다리의 디딤돌에는 모두 숫자가 적혀 있으며 디딤돌의 숫자는 한 번 밟을 때마다 1씩 줄어듭니다.
-   디딤돌의 숫자가 0이 되면 더 이상 밟을 수 없으며 이때는 그 다음 디딤돌로 한번에 여러 칸을 건너 뛸 수 있습니다.
-   단, 다음으로 밟을 수 있는 디딤돌이 여러 개인 경우 무조건 가장 가까운 디딤돌로만 건너뛸 수 있습니다.

"니니즈 친구들"은 개울의 왼쪽에 있으며, 개울의 오른쪽 건너편에 도착해야 징검다리를 건넌 것으로 인정합니다.  
"니니즈 친구들"은 한 번에 한 명씩 징검다리를 건너야 하며, 한 친구가 징검다리를 모두 건넌 후에 그 다음 친구가 건너기 시작합니다.

디딤돌에 적힌 숫자가 순서대로 담긴 배열 stones와 한 번에 건너뛸 수 있는 디딤돌의 최대 칸수 k가 매개변수로 주어질 때, 최대 몇 명까지 징검다리를 건널 수 있는지 return 하도록 solution 함수를 완성해주세요.

### 제한사항
-   징검다리를 건너야 하는 니니즈 친구들의 수는 무제한 이라고 간주합니다.
-   stones 배열의 크기는 1 이상 200,000 이하입니다.
-   stones 배열 각 원소들의 값은 1 이상 200,000,000 이하인 자연수입니다.
-   k는 1 이상 stones의 길이 이하인 자연수입니다.

## 해결
건넌 친구들의 수가 n이고 길이가 k 이상인 임의의 구간에 대해, 이 구간 내 최댓값이 n 이하면 지나갈 수 없습니다. 문제의 목표는 구간 길이가 k일 때, 지나갈 수 없게 하는 n의 최솟값을 찾아야 합니다. 이는 길이가 k인 `슬라이딩 윈도우`의 최댓값의 최소를 구하는 것과 같습니다. (구간 길이가 다를 때, 항상 작은 구간을 잡는 것이 구간 내 최댓값을 찾는데 유리합니다. 따라서 구간 길이는 최소인 k로 설정해야 합니다.)

슬라이딩 윈도우의 최댓값을 구하는 방법은 크게 2가지가 있습니다.
1. `덱`
2. `세그먼트 트리`

### 덱
슬라이딩 윈도우 이동 시, 윈도우의 시작에서 원소가 나가고 끝에 원소가 들어온다는 점에서 `덱`을 고려할 수 있습니다. 다음 조건에 맞는 덱을 정의합니다. (`A` = 입력 배열)
- 덱에는 주어진 배열의 인덱스를 저장합니다.
- 덱 내부는 주어진 배열의 값 오름차순 순서대로 정렬되어 있습니다. (A[덱의 뒤]가 윈도우의 최댓값입니다.)

덱에 새로운 원소를 넣어봅시다. 이 새로운 원소는 최댓값일수도 아닐 수도 있습니다. 그러나 윈도우 내부에서 최대가 아니며 새로운 원소보다 작거나 같고 먼저 들어온 원소는 절대 정답이 될 수 없습니다. 이 점을 이용해서 삽입 연산을 정의합니다.
```
1. A[덱의 앞]이 현재 값보다 클 때까지 반복:
	- 덱의 앞 삭제
2. 덱 앞에 현재 인덱스 추가
```

덱의 오래된 원소를 삭제해봅시다. 오래된 원소는 새 원소를 추가하는 과정에서 삭제되었거나, 덱에 남아있을 수 있습니다. 전자는 별도의 과정이 필요없으며, 후자는 빼야 할 원소가 윈도우의 최댓값에 해당하는 것이므로 덱의 뒤를 삭제하면 됩니다. 따라서 삭제 과정은 다음과 같습니다.
```
1. 삭제할 인덱스가 덱의 뒤와 같을 때: 덱의 뒤 삭제
```

시간 복잡도는 `O(N)`입니다.

### 세그먼트 트리
슬라이딩 윈도우를 최댓값을 찾는 구간 쿼리로 간주할 수 있습니다. 이는 최댓값을 저장하는 `세그먼트 트리`를 구현하면 바로 해결할 수 있습니다. => `BOJ - 2357 - 최솟값과 최댓값` 참고

시간 복잡도는 `O(N * logN)`입니다.

## 코드
### 덱
```
#include <vector>
#include <queue>
using namespace std;
deque<int> q;

int solution(vector<int> stones, int k) {
    int answer = 1 << 30;
    for(int i = 0; i < stones.size(); i++) {
        while(!q.empty() && stones[q.front()] <= stones[i])
            q.pop_front();
        q.push_front(i);
        if(i >= k && q.back() == i - k)
            q.pop_back();
        if(i >= k - 1) 
            answer = min(answer, stones[q.back()]);
    }
    return answer;
}
```

### 세그먼트 트리
```
#include <vector>
using namespace std;
const int MINV = -1;
vector<int> stones;
int N, answer = 1 << 30, tree[800004];

int init(int start, int end, int idx) {
    if (start == end) return tree[idx] = stones[start];
    int mid = (start + end) / 2;
    return tree[idx] = max(init(start, mid, idx * 2), init(mid + 1, end, idx * 2 + 1));
}

int get(int start, int end, int idx, int left, int right) {
    if (start > right || end < left) return MINV;
    if (start >= left && end <= right) return tree[idx];
    int mid = (start + end) / 2;
    return max(get(start, mid, idx * 2, left, right), get(mid + 1, end, idx * 2 + 1, left, right));
}

int solution(vector<int> stonesI, int k) {
    stones = stonesI; N = stones.size();
    init(0, N - 1, 1);
    for(int i = 0; i <= N - k; i++)
        answer = min(answer, get(0, N - 1, 1, i, i + k - 1));
    return answer;
}
```

## 링크
<br>https://school.programmers.co.kr/learn/courses/30/lessons/64062

### 비슷한 문제
<br>https://leetcode.com/problems/sliding-window-maximum/
{% endraw %}