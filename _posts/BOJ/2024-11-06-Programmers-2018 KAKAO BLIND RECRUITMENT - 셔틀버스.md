---
categories:
- Programmers
date: '2024-11-06'
title: '[Programmers] 2018 KAKAO BLIND RECRUITMENT - 셔틀버스'
---

{% raw %}
> Lv. 3<br>

## 문제
카카오에서는 무료 셔틀버스를 운행하기 때문에 판교역에서 편하게 사무실로 올 수 있다. 카카오의 직원은 서로를 '크루'라고 부르는데, 아침마다 많은 크루들이 이 셔틀을 이용하여 출근한다.

이 문제에서는 편의를 위해 셔틀은 다음과 같은 규칙으로 운행한다고 가정하자.

-   셔틀은  `09:00`부터 총  `n`회  `t`분 간격으로 역에 도착하며, 하나의 셔틀에는 최대  `m`명의 승객이 탈 수 있다.
-   셔틀은 도착했을 때 도착한 순간에 대기열에 선 크루까지 포함해서 대기 순서대로 태우고 바로 출발한다. 예를 들어  `09:00`에 도착한 셔틀은 자리가 있다면  `09:00`에 줄을 선 크루도 탈 수 있다.

일찍 나와서 셔틀을 기다리는 것이 귀찮았던 콘은, 일주일간의 집요한 관찰 끝에 어떤 크루가 몇 시에 셔틀 대기열에 도착하는지 알아냈다. 콘이 셔틀을 타고 사무실로 갈 수 있는 도착 시각 중 제일 늦은 시각을 구하여라.

단, 콘은 게으르기 때문에 같은 시각에 도착한 크루 중 대기열에서 제일 뒤에 선다. 또한, 모든 크루는 잠을 자야 하므로  `23:59`에 집에 돌아간다. 따라서 어떤 크루도 다음날 셔틀을 타는 일은 없다.

### 입력 형식
셔틀 운행 횟수  `n`, 셔틀 운행 간격  `t`, 한 셔틀에 탈 수 있는 최대 크루 수  `m`, 크루가 대기열에 도착하는 시각을 모은 배열  `timetable`이 입력으로 주어진다.

-   0 ＜  `n`  ≦ 10
-   0 ＜  `t`  ≦ 60
-   0 ＜  `m`  ≦ 45
-   `timetable`은 최소 길이 1이고 최대 길이 2000인 배열로, 하루 동안 크루가 대기열에 도착하는 시각이  `HH:MM`  형식으로 이루어져 있다.
-   크루의 도착 시각  `HH:MM`은  `00:01`에서  `23:59`  사이이다.

### 출력 형식
콘이 무사히 셔틀을 타고 사무실로 갈 수 있는 제일 늦은 도착 시각을 출력한다. 도착 시각은  `HH:MM`  형식이며,  `00:00`에서  `23:59`  사이의 값이 될 수 있다.

## 해결
- 막차 이전에 탈 수 있는 최대 시간을 찾으면 됩니다. 대기 인원 수가 m * (남은 셔틀 횟수)이 되기 전에 줄을 서면 탑승할 수 있습니다.
- 주어진 타임테이블은 문자열이므로 정수로 변환해서 사용합니다.

```
1. 모든 크루를 시간에 대해 저장
	- S[시간] = 새로 들어오는 크루 수
2. 00:00 시간부터 23:59까지 순차 탐색:
	1. 현재 시간에 들어오는 크루를 대기 인원에 더함
	2. 현재 시간이 셔틀 시간이면, 
		- m만큼 대기 인원 줄이기, 남은 셔틀 수 -1
		- 만약 대기 인원이 0이고 탑승 인원이 m보다 작다면 탑승 가능
	3. 대기 인원 < m * (남은 셔틀 횟수)이면 탑승 가능
```

## 코드
```
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
int N, q, busTime = 540, resTime, T[1440];
int ttoi(string t) {
    return stoi(t.substr(0, 2)) * 60 + stoi(t.substr(3, 2));
}
string itot(int t) {
    stringstream h, m;
    h << setw(2) << setfill('0') << to_string(t / 60);
    m << setw(2) << setfill('0') << to_string(t % 60);
    return h.str() + ":" + m.str();
}

string solution(int n, int p, int m, vector<string> timetables) {<br>
    for(auto t : timetables)
        T[ttoi(t)]++;
    for(int t = 0; t < 1440; t++) {
        q += T[t];
        if(t == busTime && n > 0) {<br>
            busTime += p, n--, q -= m;
            if(q < 0)
                resTime = t, q = 0;
        }
        if(q < m * n)
            resTime = t; 
    }
    return itot(resTime);
}
```

## 링크
https://school.programmers.co.kr/learn/courses/30/lessons/17678<br>
{% endraw %}