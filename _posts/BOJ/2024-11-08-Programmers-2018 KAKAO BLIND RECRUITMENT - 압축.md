---
categories:
- Programmers
date: '2024-11-08'
title: '[Programmers] 2018 KAKAO BLIND RECRUITMENT - 압축'
---

{% raw %}
> Lv. 2<br>

## 문제
신입사원 어피치는 카카오톡으로 전송되는 메시지를 압축하여 전송 효율을 높이는 업무를 맡게 되었다. 메시지를 압축하더라도 전달되는 정보가 바뀌어서는 안 되므로, 압축 전의 정보를 완벽하게 복원 가능한 무손실 압축 알고리즘을 구현하기로 했다.

어피치는 여러 압축 알고리즘 중에서 성능이 좋고 구현이 간단한  **LZW**(Lempel–Ziv–Welch) 압축을 구현하기로 했다. LZW 압축은 1983년 발표된 알고리즘으로, 이미지 파일 포맷인 GIF 등 다양한 응용에서 사용되었다.

LZW 압축은 다음 과정을 거친다.

1.  길이가 1인 모든 단어를 포함하도록 사전을 초기화한다.
2.  사전에서 현재 입력과 일치하는 가장 긴 문자열  `w`를 찾는다.
3.  `w`에 해당하는 사전의 색인 번호를 출력하고, 입력에서  `w`를 제거한다.
4.  입력에서 처리되지 않은 다음 글자가 남아있다면(`c`),  `w+c`에 해당하는 단어를 사전에 등록한다.
5.  단계 2로 돌아간다.

압축 알고리즘이 영문 대문자만 처리한다고 할 때, 사전은 다음과 같이 초기화된다. 사전의 색인 번호는 정수값으로 주어지며, 1부터 시작한다고 하자.

예를 들어 입력으로  `KAKAO`가 들어온다고 하자.

1.  현재 사전에는  `KAKAO`의 첫 글자  `K`는 등록되어 있으나, 두 번째 글자까지인  `KA`는 없으므로, 첫 글자  `K`에 해당하는 색인 번호 11을 출력하고, 다음 글자인  `A`를 포함한  `KA`를 사전에 27 번째로 등록한다.
2.  두 번째 글자  `A`는 사전에 있으나, 세 번째 글자까지인  `AK`는 사전에 없으므로,  `A`의 색인 번호 1을 출력하고,  `AK`를 사전에 28 번째로 등록한다.
3.  세 번째 글자에서 시작하는  `KA`가 사전에 있으므로,  `KA`에 해당하는 색인 번호 27을 출력하고, 다음 글자  `O`를 포함한  `KAO`를 29 번째로 등록한다.
4.  마지막으로 처리되지 않은 글자  `O`에 해당하는 색인 번호 15를 출력한다.

### 입력 형식
입력으로 영문 대문자로만 이뤄진 문자열  `msg`가 주어진다.  `msg`의 길이는 1 글자 이상, 1000 글자 이하이다.

### 출력 형식
주어진 문자열을 압축한 후의 사전 색인 번호를 배열로 출력하라.

## 해결
문자열을 인덱싱히므로 `map`을 사용합니다.

```
1. 사전 생성 (A-Z)
2. 문자열 시작점부터 탐색:
	1. 사전에 존재하는 현재 위치를 시작으로 하는 최대 길이의 부분 문자열 찾기
	2. 찾은 부분 문자열의 길이를 1 연장한 문자열을 사전에 추가
	3. 현재 위치를 부분 문자열 끝의 다음 위치로 이동
```

## 코드
```
#include <string>
#include <vector>
#include <map>
using namespace std;
map<string, int> dict;<br>
string tmp = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
vector<int> answer;<br>

vector<int> solution(string msg) {<br>
    int N = msg.size(), genID = 1;
    for (; genID <= 26; genID++)
        dict[tmp.substr(genID - 1, 1)] = genID;
    for (int i = 0; i < N;) {
        int len = N - i;
        while (len) {
            string tk = msg.substr(i, len);
            if (dict[tk] > 0) {<br>
                answer.push_back(dict[tk]);
                break;
            }
            len--;
        }
        if(len + 1 <= N)
            dict[msg.substr(i, len + 1)] = genID++;
        i += len;
    }
    return answer;
}
```

## 링크
https://school.programmers.co.kr/learn/courses/30/lessons/17684<br>
{% endraw %}