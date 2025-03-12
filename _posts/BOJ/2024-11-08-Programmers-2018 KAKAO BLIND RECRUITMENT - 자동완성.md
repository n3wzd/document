---
categories:
- Programmers
date: '2024-11-08'
title: '[Programmers] 2018 KAKAO BLIND RECRUITMENT - 자동완성'
---

{% raw %}
> Lv. 4<br>

## 문제
포털 다음에서 검색어 자동완성 기능을 넣고 싶은 라이언은 한 번 입력된 문자열을 학습해서 다음 입력 때 활용하고 싶어 졌다. 예를 들어,  `go`  가 한 번 입력되었다면, 다음 사용자는  `g`  만 입력해도  `go`를 추천해주므로  `o`를 입력할 필요가 없어진다! 단, 학습에 사용된 단어들 중 앞부분이 같은 경우에는 어쩔 수 없이 다른 문자가 나올 때까지 입력을 해야 한다.  
효과가 얼마나 좋을지 알고 싶은 라이언은 학습된 단어들을 찾을 때 몇 글자를 입력해야 하는지 궁금해졌다.

예를 들어, 학습된 단어들이 아래와 같을 때
```
go
gone
guild

```
-   `go`를 찾을 때  `go`를 모두 입력해야 한다.
-   `gone`을 찾을 때  `gon`  까지 입력해야 한다. (`gon`이 입력되기 전까지는  `go`  인지  `gone`인지 확신할 수 없다.)
-   `guild`를 찾을 때는  `gu`  까지만 입력하면  `guild`가 완성된다.

이 경우 총 입력해야 할 문자의 수는  `7`이다.

라이언을 도와 위와 같이 문자열이 입력으로 주어지면 학습을 시킨 후, 학습된 단어들을 순서대로 찾을 때 몇 개의 문자를 입력하면 되는지 계산하는 프로그램을 만들어보자.

### 입력 형식
학습과 검색에 사용될 중복 없는 단어  `N`개가 주어진다.  
모든 단어는 알파벳 소문자로 구성되며 단어의 수  `N`과 단어들의 길이의 총합  `L`의 범위는 다음과 같다.

-   2 <=  `N`  <= 100,000
-   2 <=  `L`  <= 1,000,000

### 출력 형식
단어를 찾을 때 입력해야 할 총 문자수를 리턴한다.

## 해결
자동검색 단어의 조건은 다음과 같습니다.
1. 입력 단어와 동일
2. 유일한 접두사의 최소 길이

`트라이`를 사용하면 구현할 수 있습니다.
```
1. 모든 단어를 트라이에 저장
	- 카운팅 변수: 단어에 사용된 횟수
	- 종료 플래그: 어떠한 단어의 끝
2. 트리 탐색: 자동검색 단어 길이(탐색한 깊이) 찾기
	- 자동검색 조건:
	1. 카운팅 변수가 1이 되는 순간
	2. 종료 플래그를 만나는 순간
```

## 코드
```
#include <string>
#include <vector>
using namespace std;
struct Node {
    vector<Node*> c = vector<Node*>(26, nullptr);
    int cnt = 0;
    bool end = 0;
};
Node* root = new Node();
int answer = 0;

Node* getChild(Node* a, int b) {
    if (a->c[b] == nullptr)
        a->c[b] = new Node();
    return a->c[b];
}

void DFS(Node* n, int depth) {
    if(n->cnt == 1) {
        answer += depth;
        return;
    }
    if(n->end)
        answer += depth;
    for(auto child : n->c)
        if(child != nullptr)
            DFS(child, depth + 1);
}

int solution(vector<string> words) {
    for (auto word : words) {
        Node* node = root;
        for (int i = 0; i < word.size(); i++) {
            node = getChild(node, word[i] - 'a');
            node->cnt++;
        }
        node->end = 1;
    }
    DFS(root, 0);
    return answer;
}
```

## 링크
<br>https://school.programmers.co.kr/learn/courses/30/lessons/17685
{% endraw %}