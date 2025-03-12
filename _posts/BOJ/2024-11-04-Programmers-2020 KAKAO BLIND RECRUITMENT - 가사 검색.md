---
categories:
- Programmers
date: '2024-11-04'
title: '[Programmers] 2020 KAKAO BLIND RECRUITMENT - 가사 검색'
---

{% raw %}
> Lv. 4<br>

## 문제
친구들로부터 천재 프로그래머로 불리는  **"프로도"**는 음악을 하는 친구로부터 자신이 좋아하는 노래 가사에 사용된 단어들 중에 특정 키워드가 몇 개 포함되어 있는지 궁금하니 프로그램으로 개발해 달라는 제안을 받았습니다.  
그 제안 사항 중, 키워드는 와일드카드 문자중 하나인 '?'가 포함된 패턴 형태의 문자열을 뜻합니다. 와일드카드 문자인 '?'는 글자 하나를 의미하며, 어떤 문자에도 매치된다고 가정합니다. 예를 들어  `"fro??"`는  `"frodo"`,  `"front"`,  `"frost"`  등에 매치되지만  `"frame"`,  `"frozen"`에는 매치되지 않습니다.

가사에 사용된 모든 단어들이 담긴 배열  `words`와 찾고자 하는 키워드가 담긴 배열  `queries`가 주어질 때, 각 키워드 별로 매치된 단어가 몇 개인지  **순서대로**  배열에 담아 반환하도록  `solution`  함수를 완성해 주세요.

### 가사 단어 제한사항
-   `words`의 길이(가사 단어의 개수)는 2 이상 100,000 이하입니다.
-   각 가사 단어의 길이는 1 이상 10,000 이하로 빈 문자열인 경우는 없습니다.
-   전체 가사 단어 길이의 합은 2 이상 1,000,000 이하입니다.
-   가사에 동일 단어가 여러 번 나올 경우 중복을 제거하고  `words`에는 하나로만 제공됩니다.
-   각 가사 단어는 오직 알파벳 소문자로만 구성되어 있으며, 특수문자나 숫자는 포함하지 않는 것으로 가정합니다.

### 검색 키워드 제한사항
-   `queries`의 길이(검색 키워드 개수)는 2 이상 100,000 이하입니다.
-   각 검색 키워드의 길이는 1 이상 10,000 이하로 빈 문자열인 경우는 없습니다.
-   전체 검색 키워드 길이의 합은 2 이상 1,000,000 이하입니다.
-   검색 키워드는 중복될 수도 있습니다.
-   각 검색 키워드는 오직 알파벳 소문자와 와일드카드 문자인  `'?'`  로만 구성되어 있으며, 특수문자나 숫자는 포함하지 않는 것으로 가정합니다.
-   검색 키워드는 와일드카드 문자인  `'?'`가 하나 이상 포함돼 있으며,  `'?'`는 각 검색 키워드의 접두사 아니면 접미사 중 하나로만 주어집니다.
    -   예를 들어  `"??odo"`,  `"fro??"`,  `"?????"`는 가능한 키워드입니다.
    -   반면에  `"frodo"`(`'?'`가 없음),  `"fr?do"`(`'?'`가 중간에 있음),  `"?ro??"`(`'?'`가 양쪽에 있음)는 불가능한 키워드입니다.

## 해결
- 접미사, 접두사가 주어졌을 때 일치하는 것의 개수를 찾아야 합니다. 나이브한 판정은 시간 초과를 받을 수 있어 O(N) 시간으로 해결해야 합니다. (N 최대 = 1,000,000)
- 문자열을 트리 구조로 저장하는 `Trie` 자료 구조를 활용합니다. 접두사와 접미사를 찾아야 하므로, 2개의 트리를 생성하여 주어진 단어들을 오름차순과 내림차순으로 각 트리에 저장합니다.
- 접두사/접미사 개수를 찾기 위해, 트리 노드에 카운팅 변수를 추가합니다. 한 단어를 추가할 때마다 트리의 문자 노드에 1을 더합니다. 쿼리 문자열이 주어지면 접두사/접미사를 파싱한 뒤, 트리를 탐색하고 가장 마지막 노드의 카운팅 값을 반환합니다.
- 쿼리 문자열의 길이와 단어 문자열의 길이도 비교 대상입니다. 문자열 길이를 인덱싱해서 길이마다 트리를 생성하면 됩니다.

## 코드
```
#include <string>
#include <vector>
using namespace std;
struct Node {
    vector<Node*> c = vector<Node*>(26, nullptr);<br>
    int cnt = 0;
};
vector<Node*> prefix = vector<Node*>(10001, nullptr);<br>
vector<Node*> suffix = vector<Node*>(10001, nullptr);<br>
Node* getChild(Node* a, int b) {
    if (a->c[b] == nullptr)
        a->c[b] = new Node();
    return a->c[b];
}

vector<int> solution(vector<string> words, vector<string> queries) {<br>
    vector<int> answer;<br>
    for(int i = 1; i <= 10000; i++) 
        prefix[i] = new Node(), suffix[i] = new Node();
    for (auto word : words) {
        Node* node1 = prefix[word.size()]; Node* node2 = suffix[word.size()];
        node1->cnt++; node2->cnt++;
        for (int i = 0; i < word.size(); i++) {
            node1 = getChild(node1, word[i] - 'a');
            node2 = getChild(node2, word[(word.size() - 1) - i] - 'a');
            node1->cnt++; node2->cnt++;
        }
    }
    for (auto q : queries) {
        int lo = 0, hi = q.size() - 1;
        while (q[lo] == '?') lo++;
        while (q[hi] == '?') hi--;
        
        string str = q.substr(lo, hi + 1);
        Node* node = lo == 0 ? prefix[q.size()] : suffix[q.size()];
        if(lo == 0)
            for (int i = 0; i < str.size(); i++)
                node = getChild(node, str[i] - 'a');
        else
            for (int i = str.size() - 1; i >= 0; i--)
                node = getChild(node, str[i] - 'a');
        answer.push_back(node->cnt);
    }
    return answer;
}
```

## 링크
https://school.programmers.co.kr/learn/courses/30/lessons/60060<br>
{% endraw %}