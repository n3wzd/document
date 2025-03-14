---
categories:
- Programmers
date: '2024-10-26'
title: '[Programmers] PCCP - 아날로그 시계'
---

{% raw %}
> Lv. 2<br>

## 문제
시침, 분침, 초침이 있는 아날로그시계가 있습니다. 시계의 시침은 12시간마다, 분침은 60분마다, 초침은 60초마다 시계를 한 바퀴 돕니다. 따라서 시침, 분침, 초침이 움직이는 속도는 일정하며 각각 다릅니다. 이 시계에는 초침이 시침/분침과 겹칠 때마다 알람이 울리는 기능이 있습니다. 당신은 특정 시간 동안 알람이 울린 횟수를 알고 싶습니다.

알람이 울리는 횟수를 센 시간을 나타내는 정수  `h1`,  `m1`,  `s1`,  `h2`,  `m2`,  `s2`가 매개변수로 주어집니다. 이때, 알람이 울리는 횟수를 return 하도록 solution 함수를 완성해주세요.

### 제한사항
-   0 ≤  `h1`,  `h2`  ≤ 23
-   0 ≤  `m1`,  `m2`  ≤ 59
-   0 ≤  `s1`,  `s2`  ≤ 59
-   `h1시 m1분 s1초`부터  `h2시 m2분 s2초`까지 알람이 울리는 횟수를 센다는 의미입니다.
    -   `h1시 m1분 s1초`  <  `h2시 m2분 s2초`
    -   시간이 23시 59분 59초를 초과해서 0시 0분 0초로 돌아가는 경우는 주어지지 않습니다.

## 해결
초침-분침, 초침-시침이 같아지는 규칙을 찾아야 합니다. => `애드 혹`

먼저 각 침의 속도를 찾아봅시다. 1시간을 기준으로 했을 때(시침이 0에서 5까지 이동), 분침은 60회, 초침은 3600회만큼 사이클을 완료합니다. 초침을 기준으로 시계의 선형 거리를 정의합니다.
```
0      1                            5
|------|----------------------------|

- 0에서 5까지 거리 = 3600
- 0에서 1까지 거리 = 720
- 0과 1 사이의 60등분한 거리 = 12
- 전체 거리 = 43200
- 초침의 초당 속도 = 720
- 분침의 초당 속도 = 12
- 시침의 초당 속도 = 1
```

따라서 (h, m, s)가 주어졌을 때, 현재 침의 위치는 다음과 같습니다.
```
S = s * 720
M = m * 720 + s * 12
H = h * 3600 + m * 60 + s
```

다음으로 초침-분침, 초침-시침이 같아지는 순간을 찾아봅시다. 매 초마다 탐색을 했을 때, 아래 2가지 조건 중 하나라도 만족하면 두 침이 일치하다고 판정합니다.
1. 현재 시점에서 두 침이 같은 위치
2. 이전 시점에서 침이 다른 침의 왼쪽일 때, 현재 시점에서 오른쪽에 위치

두 침의 위치 관계를 찾아야 합니다. 침 a가 침 b의 왼쪽인 경우는 다음과 같습니다. (C = 전체 거리의 절반)
> 0 < b - a < C (또는) b - a < -C<br>

초침-분침-시침이 모두 일치하는 경우도 있으며, 이 때는 카운팅을 중복으로 하지 않습니다. (현재 카운팅에서 1을 추가로 빼주면 됩니다.)

## 코드
```
using namespace std;
int getTime(int h, int m, int s) { return h * 3600 + m * 60 + s; }
bool isLeft(int a, int b) { int d = b - a; return (d > 0 && d <= 21600) || d < -21600; }

int solution(int h1, int m1, int s1, int h2, int m2, int s2) {
    int cnt = 0, lo = getTime(h1, m1, s1), hi = getTime(h2, m2, s2), diff = hi - lo;
    int s = s1 * 720, m = m1 * 720 + s1 * 12, h = (h1 % 12) * 3600 + m1 * 60 + s1;
    if (s == m) cnt++;
    if (s == h) cnt++;
    if (m == h) cnt--;
    while (diff--) {
        h = (h + 1) % 43200;
        m = (m + 12) % 43200;
        s = (s + 720) % 43200;
        if ((isLeft((s + 42480) % 43200, (m + 43188) % 43200) && !isLeft(s, m)) || s == m)
            cnt++;
        if ((isLeft((s + 42480) % 43200, (h + 43199) % 43200) && !isLeft(s, h)) || s == h)
            cnt++;
        if (s == m && s == h && m == h)
            cnt--;
    }
    return cnt;
}
```

## 링크
<br>https://school.programmers.co.kr/learn/courses/30/lessons/250135
{% endraw %}