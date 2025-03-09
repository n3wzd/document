---
categories:
- Programmers
date: '2024-11-09'
title: '[Programmers] 2018 KAKAO BLIND RECRUITMENT - 방금그곡'
---

{% raw %}
> Lv. 2<br>

## 문제
라디오를 자주 듣는 네오는 라디오에서 방금 나왔던 음악이 무슨 음악인지 궁금해질 때가 많다. 그럴 때 네오는 다음 포털의 '방금그곡' 서비스를 이용하곤 한다. 방금그곡에서는 TV, 라디오 등에서 나온 음악에 관해 제목 등의 정보를 제공하는 서비스이다.

네오는 자신이 기억한 멜로디를 가지고 방금그곡을 이용해 음악을 찾는다. 그런데 라디오 방송에서는 한 음악을 반복해서 재생할 때도 있어서 네오가 기억하고 있는 멜로디는 음악 끝부분과 처음 부분이 이어서 재생된 멜로디일 수도 있다. 반대로, 한 음악을 중간에 끊을 경우 원본 음악에는 네오가 기억한 멜로디가 들어있다 해도 그 곡이 네오가 들은 곡이 아닐 수도 있다. 그렇기 때문에 네오는 기억한 멜로디를 재생 시간과 제공된 악보를 직접 보면서 비교하려고 한다. 다음과 같은 가정을 할 때 네오가 찾으려는 음악의 제목을 구하여라.

-   방금그곡 서비스에서는 음악 제목, 재생이 시작되고 끝난 시각, 악보를 제공한다.
-   네오가 기억한 멜로디와 악보에 사용되는 음은 C, C#, D, D#, E, F, F#, G, G#, A, A#, B 12개이다.
-   각 음은 1분에 1개씩 재생된다. 음악은 반드시 처음부터 재생되며 음악 길이보다 재생된 시간이 길 때는 음악이 끊김 없이 처음부터 반복해서 재생된다. 음악 길이보다 재생된 시간이 짧을 때는 처음부터 재생 시간만큼만 재생된다.
-   음악이 00:00를 넘겨서까지 재생되는 일은 없다.
-   조건이 일치하는 음악이 여러 개일 때에는 라디오에서 재생된 시간이 제일 긴 음악 제목을 반환한다. 재생된 시간도 같을 경우 먼저 입력된 음악 제목을 반환한다.
-   조건이 일치하는 음악이 없을 때에는 “`(None)`”을 반환한다.

### 입력 형식
입력으로 네오가 기억한 멜로디를 담은 문자열  `m`과 방송된 곡의 정보를 담고 있는 배열  `musicinfos`가 주어진다.

-   `m`은 음  `1`개 이상  `1439`개 이하로 구성되어 있다.
-   `musicinfos`는  `100`개 이하의 곡 정보를 담고 있는 배열로, 각각의 곡 정보는 음악이 시작한 시각, 끝난 시각, 음악 제목, 악보 정보가 '`,`'로 구분된 문자열이다.
-   음악의 시작 시각과 끝난 시각은 24시간  `HH:MM`  형식이다.
-   음악 제목은 '`,`' 이외의 출력 가능한 문자로 표현된 길이  `1`  이상  `64`  이하의 문자열이다.
-   악보 정보는 음  `1`개 이상  `1439`개 이하로 구성되어 있다.

### 출력 형식
조건과 일치하는 음악 제목을 출력한다.

## 해결
주어진 검색어를 입력 문자열에서 찾는 문제입니다.
- #으로 인해 문자열 길이는 음악 길이와 다릅니다. 구현상 편의를 위해 길이가 2인 음표를 길이 1로 바꿔줍니다. (예: "C#" => "2")<br>
- 탐색할 음악은 재생 시간에 맞게 조정되어야 합니다. 원본 음악 길이가 재생 시간보다 작으면 음악 길이를 재생 시간에 맞게 잘라야 하며, 그렇지 않다면 재생 시간만큼 연장되어야 합니다.
- 음악 문자열 처리를 완료했다면 제공된 단어를 검색합니다. 입력 데이터가 작으므로 KMP 없이 나이브한 판정이 가능합니다.

```
1. 기억한 멜로디 전처리
2. 라디오 음악 탐색:
	1. 라디오 음악 전처리
	2. 검색할 음악 생성: 재생 시간만큼 음악 연장
	3. 기억한 멜로디가 검색할 음악에 포함되는지 확인:
		- 포함되고 가장 긴 재생 시간이면 정답 업데이트
```

※ 2024-11-09 기준, Programmers에는 테스트 데이터에 "B#"이 포함되어 있습니다. (지문 오류)

## 코드
```
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
using namespace std;
map<string, string> note = { {"C", "1"}, {"C#", "2"}, {"D", "3"}, {"D#", "4"}, {"E", "5"}, {"F", "6"}, {"F#", "7"}, {"G", "8"}, {"G#", "9"}, {"A", "A"}, {"A#", "B"}, {"B", "C"}, {"B#", "D"} };<br>
int ttoi(string t) { return stoi(t.substr(0, 2)) * 60 + stoi(t.substr(3, 2)); }

string init(string m) {
    string res = "";
    for (int i = 0; i < m.size(); i++) {
        if (i < m.size() - 1) {
            string t2 = m.substr(i, 2);
            if (note[t2] != "") {
                res += note[t2]; i++;
                continue;
            }
        }
        string t1 = m.substr(i, 1);
        if (note[t1] != "")
            res += note[t1];
    }
    return res;
}

bool match(string m1, string m2) {
    int N = m1.size(), M = m2.size();
    if (N > M)<br>
        return 0;
    for (int s = 0; s <= M - N; s++) {
        bool ok = 1;
        for (int i = 0; i < N; i++)
            ok &= m1[i] == m2[i + s];
        if (ok) return 1;
    }
    return 0;
}

string solution(string m, vector<string> musicinfos) {<br>
    int maxSize = -1;
    string myMusic = init(m), answer = "";
    for (int i = 0; i < musicinfos.size(); i++) {
        stringstream ss(musicinfos[i]);
        string a, b, c, d; getline(ss, a, ','); getline(ss, b, ','); getline(ss, c, ','); getline(ss, d, ',');
        string sample = init(d), radioMusic = "";
        int musicTime = ttoi(b) - ttoi(a), len = sample.size(), diff = musicTime;
        while (diff >= len)
            radioMusic += sample, diff -= len;
        radioMusic += sample.substr(0, diff);
        if (maxSize < musicTime && match(myMusic, radioMusic)) {
            maxSize = musicTime;
            answer = c;
        }
    }
    return answer == "" ? "(None)" : answer;
}
```

## 링크
https://school.programmers.co.kr/learn/courses/30/lessons/17683
{% endraw %}