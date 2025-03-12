---
categories:
- Programmers
date: '2024-12-02'
title: '[Programmers] 연습문제 - 호텔 대실'
---

{% raw %}
> Lv. 2<br>

## 문제
호텔을 운영 중인 코니는 최소한의 객실만을 사용하여 예약 손님들을 받으려고 합니다. 한 번 사용한 객실은 퇴실 시간을 기준으로 10분간 청소를 하고 다음 손님들이 사용할 수 있습니다.  
예약 시각이 문자열 형태로 담긴 2차원 배열 `book_time`이 매개변수로 주어질 때, 코니에게 필요한 최소 객실의 수를 return 하는 solution 함수를 완성해주세요.

### 제한사항
-   1 ≤  `book_time`의 길이 ≤ 1,000
    -   `book_time[i]`는 ["HH:MM", "HH:MM"]의 형태로 이루어진 배열입니다
        -   [대실 시작 시각, 대실 종료 시각] 형태입니다.
    -   시각은 HH:MM 형태로 24시간 표기법을 따르며, "00:00" 부터 "23:59" 까지로 주어집니다.
        -   예약 시각이 자정을 넘어가는 경우는 없습니다.
        -   시작 시각은 항상 종료 시각보다 빠릅니다.

## 해결
모든 구간을 배치했을 때, 구간이 가장 많이 존재하는 위치를 찾아야 합니다.
- 시간은 정수로 변환해서 사용합니다.
- 전체 길이가 작으므로, 모든 위치를 탐색할 수 있습니다. => `스위핑`<br>
- 현재 위치에서 구간의 개수를 정의합니다. 구간의 시작과 끝을 수직선에 기록하여, 구간 시작을 만나면 구간의 개수에 1을 더하고 끝을 만나면 구간의 개수에 1을 뺍니다. => `누적 합`<br>

```
1. 모든 구간의 시작과 끝을 수직선에 기록
2. 수직선 순회:
	- 구간 시작을 만나면 합 +1
	- 구간 끝을 만나면 합 -1
	- 정답 업데이트
```

## 코드
```
#include <string>
#include <vector>
using namespace std;
int ttoi(string t) { return stoi(t.substr(0, 2)) * 60 + stoi(t.substr(3, 2)); }
int T[1451];

int solution(vector<vector<string>> book_time) {<br>
    int answer = 0, sum = 0;
    for(auto book : book_time) {
        T[ttoi(book[0])]++;
        T[ttoi(book[1]) + 10]--;
    }
    for(int i = 0; i <= 1450; i++) {
        sum += T[i];
        answer = max(answer, sum);
    }
    return answer;
}
```

## 링크
https://school.programmers.co.kr/learn/courses/30/lessons/155651<br>
{% endraw %}