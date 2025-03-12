---
categories:
- Programmers
date: '2024-11-02'
title: '[Programmers] 2021 KAKAO BLIND RECRUITMENT - 광고 삽입'
---

{% raw %}
> Lv. 3<br>

## 문제
`카카오TV`에서 유명한 크리에이터로 활동 중인  `죠르디`는 환경 단체로부터 자신의 가장 인기있는 동영상에 지구온난화의 심각성을 알리기 위한 공익광고를 넣어 달라는 요청을 받았습니다. 평소에 환경 문제에 관심을 가지고 있던 "죠르디"는 요청을 받아들였고 광고효과를 높이기 위해 시청자들이 가장 많이 보는 구간에 공익광고를 넣으려고 합니다. "죠르디"는 시청자들이 해당 동영상의 어떤 구간을 재생했는 지 알 수 있는 재생구간 기록을 구했고, 해당 기록을 바탕으로 공익광고가 삽입될 최적의 위치를 고를 수 있었습니다.  
참고로 광고는 재생 중인 동영상의 오른쪽 아래에서 원래 영상과  `동시에 재생되는`  PIP(Picture in Picture) 형태로 제공됩니다.

"죠르디"의 동영상 재생시간 길이 play_time, 공익광고의 재생시간 길이 adv_time, 시청자들이 해당 동영상을 재생했던 구간 정보 logs가 매개변수로 주어질 때, 시청자들의 누적 재생시간이 가장 많이 나오는 곳에 공익광고를 삽입하려고 합니다. 이때, 공익광고가 들어갈  `시작 시각`을 구해서 return 하도록 solution 함수를 완성해주세요. 만약, 시청자들의 누적 재생시간이 가장 많은 곳이 여러 곳이라면, 그 중에서  `가장 빠른 시작 시각`을 return 하도록 합니다.

### 제한사항
-   play_time, adv_time은 길이 8로 고정된 문자열입니다.
    -   play_time, adv_time은  `HH:MM:SS`  형식이며,  `00:00:01`  이상  `99:59:59`  이하입니다.
    -   즉, 동영상 재생시간과 공익광고 재생시간은  `00시간 00분 01초`  이상  `99시간 59분 59초`  이하입니다.
    -   공익광고 재생시간은 동영상 재생시간보다 짧거나 같게 주어집니다.
-   logs는 크기가 1 이상 300,000 이하인 문자열 배열입니다.
    -   logs 배열의 각 원소는 시청자의 재생 구간을 나타냅니다.
    -   logs 배열의 각 원소는 길이가 17로 고정된 문자열입니다.
    -   logs 배열의 각 원소는  `H1:M1:S1-H2:M2:S2`  형식입니다.
        -   `H1:M1:S1`은 동영상이 시작된 시각,  `H2:M2:S2`는 동영상이 종료된 시각을 나타냅니다.
        -   `H1:M1:S1`는  `H2:M2:S2`보다 1초 이상 이전 시각으로 주어집니다.
        -   `H1:M1:S1`와  `H2:M2:S2`는 play_time 이내의 시각입니다.
-   시간을 나타내는  `HH, H1, H2`의 범위는 00<sub>99, 분을 나타내는  `MM, M1, M2`의 범위는 00</sub>59, 초를 나타내는  `SS, S1, S2`의 범위는 00~59까지 사용됩니다. 잘못된 시각은 입력으로 주어지지 않습니다. (예:  `04:60:24`,  `11:12:78`,  `123:12:45`  등)
-   return 값의 형식
    -   공익광고를 삽입할 시각을  `HH:MM:SS`  형식의 8자리 문자열로 반환합니다.

## 해결
- 먼저 주어진 문자열 시간을 초 단위로 정수로 변환합니다. 
- 어떠한 윈도우가 주어진 상황에서 구간을 가장 많이 포함하는 위치를 찾아야 합니다. `슬라이딩 윈도우`를 `스위핑`하여 O(N) 시간으로 계산할 수 있습니다.
- 영상의 길이는 끝 시각 - 시작 시각으로 계산됩니다. 따라서 스위핑할 때, 모든 구간(시청자, 공익광고)은 시작점 이상, 끝점 미만으로 처리해야 합니다.
- 영상 최대 길이가 360000초이며 최대 인원수는 300000이므로, 누적 재생 시간은 int 자료형 기준 오버플로우가 발생할 수 있습니다.
 
```
1. 모든 구간 쿼리(시작점, 끝점) 탐색:
	- 시청자 변화량 직선에 기록 (시작점에서 +1, 끝점 - 1에서 -1)
2. 윈도우 초기 누적 합 계산:
	1. 윈도우 끝에 대해 현재 시청자 업데이트 (유입)
3. 윈도우 스위핑: 동영상 시작부터 끝 방향으로 이동
	1. 윈도우 끝에 대해 현재 시청자 업데이트 (유입)
	2. 누적 시청자 수 업데이트
	3. 정답 업데이트: 누적 시청자 수 최댓값일 때 윈도우 시작점 위치
	4. 윈도우 시작에 대해 현재 시청자 업데이트 (유출)
```

## 코드
```
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
ll width, N, sum, resSum, resLo, dt, dtx[360001];
ll ttoi(string t) {
    return stoi(t.substr(0, 2)) * 3600 + stoi(t.substr(3, 2)) * 60 + stoi(t.substr(6, 2));
}
string itot(ll t) {
    stringstream h, m, s;
    h << setw(2) << setfill('0') << to_string(t / 3600);
    m << setw(2) << setfill('0') << to_string((t % 3600) / 60);
    s << setw(2) << setfill('0') << to_string(t % 60);
    return h.str() + ":" + m.str() + ":" + s.str();
}

string solution(string play_time, string adv_time, vector<string> logs) {<br>
    N = ttoi(play_time), width = ttoi(adv_time) - 1;
    for (auto log : logs) {
        dtx[ttoi(log.substr(0, 8))]++;
        dtx[ttoi(log.substr(9, 8))]--;
    }
    for (ll i = 0; i < width; i++)
        dt += dtx[i], sum += dt;
    for (ll lo = 0; lo <= N - width; lo++) {
        dt += dtx[lo + width];
        sum += dt;
        if (sum > resSum)<br>
            resSum = sum, resLo = lo;
        dt -= dtx[lo];
    }
    return itot(resLo);
}
```

## 링크
https://school.programmers.co.kr/learn/courses/30/lessons/72414<br>
{% endraw %}