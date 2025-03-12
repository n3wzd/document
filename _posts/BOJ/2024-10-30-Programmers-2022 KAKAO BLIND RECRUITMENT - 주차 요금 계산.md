---
categories:
- Programmers
date: '2024-10-30'
title: '[Programmers] 2022 KAKAO BLIND RECRUITMENT - 주차 요금 계산'
---

{% raw %}
> Lv. 2<br>

## 문제
주차장의 요금표와 차량이 들어오고(입차) 나간(출차) 기록이 주어졌을 때, 차량별로 주차 요금을 계산하려고 합니다.

-   어떤 차량이 입차된 후에 출차된 내역이 없다면, 23:59에 출차된 것으로 간주합니다.
    -   `0000`번 차량은 18:59에 입차된 이후, 출차된 내역이 없습니다. 따라서, 23:59에 출차된 것으로 간주합니다.
-   00:00부터 23:59까지의 입/출차 내역을 바탕으로 차량별 누적 주차 시간을 계산하여 요금을 일괄로 정산합니다.
-   누적 주차 시간이  `기본 시간`이하라면,  `기본 요금`을 청구합니다.  
-   누적 주차 시간이  `기본 시간`을 초과하면,  `기본 요금`에 더해서, 초과한 시간에 대해서  `단위 시간`  마다  `단위 요금`을 청구합니다.
    -   초과한 시간이  `단위 시간`으로 나누어 떨어지지 않으면,  `올림`합니다.  
    -   `⌈`a`⌉`  : a보다 작지 않은 최소의 정수를 의미합니다. 즉,  `올림`을 의미합니다.

주차 요금을 나타내는 정수 배열  `fees`, 자동차의 입/출차 내역을 나타내는 문자열 배열  `records`가 매개변수로 주어집니다.  **차량 번호가 작은 자동차부터**  청구할 주차 요금을 차례대로 정수 배열에 담아서 return 하도록 solution 함수를 완성해주세요.

## 해결
- 차량번호는 4자리이므로 정수로 인덱싱이 가능합니다. (최대 9999)
- 시간은 정수로 변환해서 계산합니다.
- 같은 차량이 2번 IN할 수 있으며, 요금 계산 시 누적 주차 시간을 기준으로 합니다.

## 코드
```
#include <string>
#include <sstream>
#include <vector>
using namespace std;
int in[10001], sum[10001];
int timeToN(string t) { return stoi(t.substr(0, 2)) * 60 + stoi(t.substr(3, 2)) + 1; }

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    int lastTime = timeToN("23:59");
    for (string cmd : records) {
        istringstream iss(cmd);
        vector<string> words(3);
        for (auto& word : words) iss >> word;
        int id = stoi(words[1]);
        if (words[2] == "IN")
            in[id] = timeToN(words[0]);
        else
            sum[id] += timeToN(words[0]) - in[id], in[id] = 0;
    }
    for (int i = 0; i < 10000; i++)
        if (in[i] != 0)
            sum[i] += lastTime - in[i];
    for (int i = 0; i < 10000; i++) {
        if (sum[i] == 0) continue;
        int overTime = 0;
        if (sum[i] > fees[0]) {
            overTime = (sum[i] - fees[0]) / fees[2];
            if ((sum[i] - fees[0]) % fees[2] != 0)
                overTime++;
        }
        answer.push_back(fees[1] + overTime * fees[3]);
    }
    return answer;
}
```

## 링크
<br>https://school.programmers.co.kr/learn/courses/30/lessons/92341
{% endraw %}