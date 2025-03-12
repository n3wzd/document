---
categories:
- Programmers
date: '2024-10-23'
title: '[Programmers] PCCP - 동영상 재생기'
---

{% raw %}
> Lv. 1<br>

## 문제
당신은 동영상 재생기를 만들고 있습니다. 당신의 동영상 재생기는 10초 전으로 이동, 10초 후로 이동, 오프닝 건너뛰기 3가지 기능을 지원합니다. 각 기능이 수행하는 작업은 다음과 같습니다.

- 10초 전으로 이동: 사용자가 "prev" 명령을 입력할 경우 동영상의 재생 위치를 현재 위치에서 10초 전으로 이동합니다. 현재 위치가 10초 미만인 경우 영상의 처음 위치로 이동합니다. 영상의 처음 위치는 0분 0초입니다.
- 10초 후로 이동: 사용자가 "next" 명령을 입력할 경우 동영상의 재생 위치를 현재 위치에서 10초 후로 이동합니다. 동영상의 남은 시간이 10초 미만일 경우 영상의 마지막 위치로 이동합니다. 영상의 마지막 위치는 동영상의 길이와 같습니다.
- 오프닝 건너뛰기: 현재 재생 위치가 오프닝 구간(`op_start`  ≤ 현재 재생 위치 ≤  `op_end`)인 경우 자동으로 오프닝이 끝나는 위치로 이동합니다.

동영상의 길이를 나타내는 문자열  `video_len`, 기능이 수행되기 직전의 재생위치를 나타내는 문자열  `pos`, 오프닝 시작 시각을 나타내는 문자열  `op_start`, 오프닝이 끝나는 시각을 나타내는 문자열  `op_end`, 사용자의 입력을 나타내는 1차원 문자열 배열  `commands`가 매개변수로 주어집니다. 이때 사용자의 입력이 모두 끝난 후 동영상의 위치를 "`mm`:`ss`" 형식으로 return 하도록 solution 함수를 완성해 주세요.

### 제한사항
-   `video_len`의 길이 =  `pos`의 길이 =  `op_start`의 길이 =  `op_end`의 길이 = 5
    -   `video_len`,  `pos`,  `op_start`,  `op_end`는 "`mm`:`ss`" 형식으로  `mm`분  `ss`초를 나타냅니다.
    -   0 ≤  `mm`  ≤ 59
    -   0 ≤  `ss`  ≤ 59
    -   분, 초가 한 자리일 경우 0을 붙여 두 자리로 나타냅니다.
    -   비디오의 현재 위치 혹은 오프닝이 끝나는 시각이 동영상의 범위 밖인 경우는 주어지지 않습니다.
    -   오프닝이 시작하는 시각은 항상 오프닝이 끝나는 시각보다 전입니다.
-   1 ≤  `commands`의 길이 ≤ 100
    -   `commands`의 원소는 "prev" 혹은 "next"입니다.
    -   "prev"는 10초 전으로 이동하는 명령입니다.
    -   "next"는 10초 후로 이동하는 명령입니다.

## 해결
주어진 시간을 정수로 변환해서 명령어를 적용한 뒤, 출력하기 전에 다시 문자열로 변환하면 됩니다.

영상 스킵은 명령 호출할 때마다 적용해주면 됩니다.

## 코드
```
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int strToInt(string time) {
    return stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3, 2));
}

string intToStr(int t) {
    stringstream m, s;
    m << setw(2) << setfill('0') << to_string(t / 60);
    s << setw(2) << setfill('0') << to_string(t % 60);
    return "" + m.str() + ":" + s.str();
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {<br>
    int len = strToInt(video_len), p = strToInt(pos);
    int start = strToInt(op_start), end = strToInt(op_end);

    if (p >= start && p <= end)
        p = end;
    for (string cmd : commands) {
        if (cmd == "next")
            p = min(p + 10, len);
        if (cmd == "prev")
            p = max(p - 10, 0);
        if (p >= start && p <= end)
            p = end;
    }
    return intToStr(p);
}
```

## 링크
https://school.programmers.co.kr/learn/courses/30/lessons/340213<br>
{% endraw %}