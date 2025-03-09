---
categories:
- Programmers
date: '2024-10-29'
title: '[Programmers] 2023 KAKAO BLIND RECRUITMENT - 표 병합'
---

{% raw %}
> Lv. 3<br>

## 문제
당신은 표 편집 프로그램을 작성하고 있습니다.  
표의 크기는 50 × 50으로 고정되어있고 초기에 모든 셀은 비어 있습니다.  
각 셀은 문자열 값을 가질 수 있고, 다른 셀과 병합될 수 있습니다.  
  
위에서  `r`번째, 왼쪽에서  `c`번째 위치를 (`r`,  `c`)라고 표현할 때, 당신은 다음 명령어들에 대한 기능을 구현하려고 합니다.

1.  `"UPDATE r c value"`
    -   (`r`,  `c`) 위치의 셀을 선택합니다.
    -   선택한 셀의 값을  `value`로 바꿉니다.
2.  `"UPDATE value1 value2"`
    -   `value1`을 값으로 가지고 있는 모든 셀을 선택합니다.
    -   선택한 셀의 값을  `value2`로 바꿉니다.
3.  `"MERGE r1 c1 r2 c2"`  
    -   (`r1`,  `c1`) 위치의 셀과 (`r2`,  `c2`) 위치의 셀을 선택하여 병합합니다.
    -   선택한 두 위치의 셀이 같은 셀일 경우 무시합니다.
    -   선택한 두 셀은 서로 인접하지 않을 수도 있습니다. 이 경우 (`r1`,  `c1`) 위치의 셀과 (`r2`,  `c2`) 위치의 셀만 영향을 받으며, 그 사이에 위치한 셀들은 영향을 받지 않습니다.
    -   두 셀 중 한 셀이 값을 가지고 있을 경우 병합된 셀은 그 값을 가지게 됩니다.
    -   두 셀 모두 값을 가지고 있을 경우 병합된 셀은 (`r1`,  `c1`) 위치의 셀 값을 가지게 됩니다.
    -   이후 (`r1`,  `c1`) 와 (`r2`,  `c2`) 중 어느 위치를 선택하여도 병합된 셀로 접근합니다.
4.  `"UNMERGE r c"`
    -   (`r`,  `c`) 위치의 셀을 선택하여 해당 셀의 모든 병합을 해제합니다.
    -   선택한 셀이 포함하고 있던 모든 셀은 프로그램 실행 초기의 상태로 돌아갑니다.
    -   병합을 해제하기 전 셀이 값을 가지고 있었을 경우 (`r`,  `c`) 위치의 셀이 그 값을 가지게 됩니다.
5.  `"PRINT r c"`
    -   (`r`,  `c`) 위치의 셀을 선택하여 셀의 값을 출력합니다.
    -   선택한 셀이 비어있을 경우  `"EMPTY"`를 출력합니다.

실행할 명령어들이 담긴 1차원 문자열 배열  `commands`가 매개변수로 주어집니다.  `commands`의 명령어들을 순서대로 실행하였을 때,  `"PRINT r c"`  명령어에 대한 실행결과를 순서대로 1차원 문자열 배열에 담아 return 하도록 solution 함수를 완성해주세요.

### 제한사항
-   1 ≤  `commands`의 길이 ≤ 1,000
-   `commands`의 각 원소는 아래 5가지 형태 중 하나입니다.
    1.  `"UPDATE r c value"`
        -   `r`,  `c`는 선택할 셀의 위치를 나타내며, 1~50 사이의 정수입니다.
        -   `value`는 셀에 입력할 내용을 나타내며, 알파벳 소문자와 숫자로 구성된 길이 1~10 사이인 문자열입니다.
    2.  `"UPDATE value1 value2"`
        -   `value1`은 선택할 셀의 값,  `value2`는 셀에 입력할 내용을 나타내며, 알파벳 소문자와 숫자로 구성된 길이 1~10 사이인 문자열입니다.
    3.  `"MERGE r1 c1 r2 c2"`  
        -   `r1`,  `c1`,  `r2`,  `c2`는 선택할 셀의 위치를 나타내며, 1~50 사이의 정수입니다.
    4.  `"UNMERGE r c"`
        -   `r`,  `c`는 선택할 셀의 위치를 나타내며, 1~50 사이의 정수입니다.
    5.  `"PRINT r c"`  
        -   `r`,  `c`는 선택할 셀의 위치를 나타내며, 1~50 사이의 정수입니다.
-   `commands`는 1개 이상의  `"PRINT r c"`  명령어를 포함하고 있습니다.

## 해결
병합된 셀은 하나의 집합을 가지며, 기준 셀이 존재합니다. => `Disjoint Set`<br>
- 트리를 저장하는 배열, 값을 저장하는 배열을 정의합니다. (크기 2500)
- UPDATE A: find 연산으로 루트 노드의 값을 바꿉니다.
- UPDATE value1: 값 배열을 순회해서 업데이트합니다.
- MERGE A B: A를 루트 노드로 해서 union합니다. A의 값이 비어 있다면 B의 값을 대입합니다.
- UNMERGE A: A의 값에 루트 노트의 값을 대입하고, A가 속한 트리의 모든 노드를 해체합니다.
- PRINT: find 연산으로 루트 노드의 값을 찾습니다.

UNMERGE는 모든 노드를 순회하는 방법으로 구현합니다.
```
1. 입력 노드의 루트 노드 찾기
2. 모든 노드 순회: 입력 노드가 속한 트리 해체
	- 현재 노드의 루트와 입력 노드의 루트가 같다면 기록
3. 노드 업데이트:
	- 기록된 노드의 트리, 값 내용 초기화
```

## 코드
```
#include <string>
#include <sstream>
#include <vector>
using namespace std;
int N, M, parent[2501];
string value[2501];
int getN(int x, int y) { return (y - 1) * 50 + x - 1; }

int find(int n) {
    int p = n;
    while (parent[p] >= 0) p = parent[p];
    if (parent[n] >= 0) parent[n] = p;
    return p;
}

void merge(int a, int b) {
    int p1 = find(a);
    int p2 = find(b);
    if (p1 == p2) return;
    parent[p2] = p1;
    if (value[p1] == "")
        value[p1] = value[p2];
}

void unmerge(int n) {
    int p = find(n);
    string v = value[p];
    vector<int> q;<br>
    for (int i = 0; i <= 2500; i++)
        if (find(i) == p)
            q.push_back(i);
    for (int i : q)
        parent[i] = -1, value[i] = "";
    value[n] = v;
}

vector<string> solution(vector<string> commands) {<br>
    vector<string> answer;<br>
    for (int i = 0; i <= 2500; i++)
        parent[i] = -1, value[i] = "";
    for (string cmd : commands) {
        istringstream iss(cmd);
        string word;
        vector<string> words;<br>
        while (iss >> word)<br>
            words.push_back(word);

        if (words[0] == "UPDATE" && words.size() == 4)
            value[find(getN(stoi(words[2]), stoi(words[1])))] = words[3];
        if (words[0] == "UPDATE" && words.size() == 3)
            for (int n = 0; n <= 2500; n++)
                if (value[n] == words[1])
                    value[n] = words[2];
        if (words[0] == "MERGE")
            merge(getN(stoi(words[2]), stoi(words[1])), getN(stoi(words[4]), stoi(words[3])));
        if (words[0] == "UNMERGE")
            unmerge(getN(stoi(words[2]), stoi(words[1])));
        if (words[0] == "PRINT") {
            string v = value[find(getN(stoi(words[2]), stoi(words[1])))];
            answer.push_back(v == "" ? "EMPTY" : v);
        }
    }
    return answer;
}
```

## 링크
https://school.programmers.co.kr/learn/courses/30/lessons/150366
{% endraw %}