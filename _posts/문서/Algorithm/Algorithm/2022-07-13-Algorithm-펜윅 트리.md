---
categories:
- Algorithm
date: '2022-07-13'
title: '[Algorithm] 펜윅 트리'
---

{% raw %}
## 펜윅 트리
펜윅 트리는 세그먼트 트리와 비슷하며 다음의 차이가 있다.
- 메모리 공간을 보다 효율적으로 사용함
- 구현 및 응용이 복잡함

## 코드
`BOJ - 2042 - 구간 합 구하기` 코드
```
#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;
const int SIZE = 1e6 + 2;
int N, M, K;
ll num[SIZE];
ll tree[SIZE];

ll Sum(int i) {
    ll ans = 0;
    while (i > 0) {
        ans += tree[i];
        i -= (i & -i);
    }
    return ans;
}
void Update(int i, ll diff) {
    while (i < N + 1) {
        tree[i] += diff;
        i += (i & -i);
    }
}

int main() {
    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++) {
        cin >> num[i];
        Update(i, num[i]);
    }

    M += K;
    while (M--) {
        ll a, b, c, diff;
        cin >> a;
        if (a == 1) {
            cin >> b >> c;
            diff = c - num[b];
            num[b] = c;
            Update(b, diff);
        }
        else {
            cin >> b >> c;
            cout << Sum(c) - Sum(b - 1) << "\n";
        }
    }
    return 0;
}
```

## 링크
{% endraw %}