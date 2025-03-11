---
categories:
- Algorithm
date: '2022-05-25'
title: '[Algorithm] Trie'
---

{% raw %}
## Trie
문자열의 유무를 빠르게 탐색하는 자료구조. 문자들을 K진 트리 구조로 저장하며, 문자열 추가/검색 기능을 제공한다. (K = 문자 종류)

trie에서 추가/검색의 시간은 모두 O(M)으로, 일반적인 선형 탐색보다 빠르다. (M = 문자열 길이) 단, trie는 차지하는 메모리의 용량이 상대적으로 크다는 단점이 있다.

## 구조
```
ex. 문자열 ["APPLE", "APPLEMANGO", "ABC", "BANANA", "GRAPE", "GREAT"] 저장

                 0
      A          B          G
   P     B       A          R
   P    (C)      N       A     E
   L             A       P     A
  (E)            N      (E)   (T)
   M            (A)
   A
   N 
   G
  (O)
```
trie는 문자열을 문자로 노드를 나눠서 저장한다. 그리고 문자열의 끝을 마지막 문자를 저장하는 노드에 표시하여 특정 문자열의 끝을 알린다. 하나의 노드에서 여러 문자열이 거쳐갈 수 있으며, 끝을 저장하는 노드는 단말 노드일 수도, 아닐 수도 있다. 루트 노드는 문자를 저장하진 않고, 탐색의 시작점 역할을 한다.

trie에서 문자열 탐색은 루트부터 시작한다. 자식 노드를 따라 내려가는 경로에서 만나는 글자들을 모으면, 찾고자 하는 문자열의 접두사를 크기 순으로 1개씩 확인할 수 있다. (ex. A, AP, APP, APPL, APPLE) 만약 문자열의 끝에서 끝을 저장하는 노드를 만났다면 해당 문자열이 있다고 판단한다.

## 구현
자식의 종류가 많기 때문에, 포인터 연결을 사용하는 트리로 구현한다.

#### 노드
먼저, trie를 구성하는 노드를 생성하자.
```
class Node
	isEnd = false // 문자열의 끝 정보 저장
	Node* child[TYPE] // 자식 노드 위치 저장
```
TYPE은 문자의 종류(=자식의 종류)이다. 만약 자식 노드의 종류가 많다면, 동적 배열을 사용해도 된다.

#### 생성자
값을 초기화한다.
```
Node()
	isEnd = false
	for (int i = 0; i < TYPE; i++)
		child[i] = nullptr
```

#### 소멸자
상황에 따라 trie를 재구성할 필요가 있는데, trie는 메모리 공간을 많이 차지하므로 사용하지 않는 trie는 delete를 해야 한다. 이때 자식 노드들도 모두 delete해야 하므로 소멸자가 필요하다.
```
~Node()
	for (int i = 0; i < TYPE; i++)
		if (child[i])
			delete child[i]
```
동적 할당은 소멸할 때 delete를 사용한다.

#### 추가 연산
문자열을 trie에 추가하는 연산. 루트 노드부터 탐색을 시작한다.
```
root->Insert("APPLE")
```

노드마다 문자열의 위치를 가리키기 위해, 포인터를 사용하는 C스타일 문자열로 표현하자.
```
Insert(const char* str) // str = 입력 문자열
	// 현재 입력 문자열의 위치가 끝인지 검사한다.
	if (!*str)
		isEnd = true // 마지막 문자를 저장하는 노드에서 끝 표시
		return

	// 입력 문자열의 첫번째 문자 추출
	first = *str - 'A'
	if (child[first] == nullptr) // 해당 문자를 저장하는 자식 노드가 없다면 추가
		child[first] = new Node()

	// 해당 문자를 저장하는 자식 노드로 이동. 동시에 입력 문자열 인덱스 + 1
	child[first]->Insert(str + 1)
```

#### 탐색 연산
trie에 문자열이 존재하는지 판단하는 연산. 마찬가지로 루트 노드부터 탐색을 시작한다.
```
root->Find("APPLE")
```

```
Find(const char* str)
	// 현재 입력 문자열의 위치가 끝인지 검사한다.
	if (!*str)
		if (isEnd) // 문자열 끝 and 현재 노드가 끝 => true 반환<br>
			return true
		return false

	// 입력 문자열의 첫번째 문자 추출
	first = *str - 'A'
	if (child[first] == nullptr) // 해당 문자를 저장하는 자식 노드가 없다면 탐색 종료
		return false
	
	// 해당 문자를 저장하는 자식 노드로 이동. 동시에 입력 문자열 인덱스 + 1
	return child[first]->Find(str + 1)
```

## 코드
```
#include <iostream>
using namespace std;
const int TYPE = 26;

int Converter(char c) {
	return c - 'a';
}

class Node {
public:
	bool isEnd = 0;
	Node* child[TYPE];

	Node() {
		isEnd = false;
		for (int i = 0; i < TYPE; i++)
			child[i] = nullptr;
	}

	~Node() {
		for (int i = 0; i < TYPE; i++)
			if (child[i])
				delete child[i];
	}

	void Insert(const char* str) {
		if (!*str) {
			isEnd = true;
			return;
		}

		int first = Converter(*str);
		if (child[first] == nullptr)
			child[first] = new Node();
		child[first]->Insert(str + 1);
	}

	bool Find(const char* str) {
		if (!*str) {
			if (isEnd) return true;
			return false;
		}

		int first = Converter(*str);
		if (child[first] == nullptr)
			return false;
		return child[first]->Find(str + 1);
	}
};

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	Node* root = new Node();
	string str;

	cin >> str;<br>
	root->Insert(str.c_str());

	string temp = "abcd";
	if (root->Find(temp.c_str())) cout << "YES";
	else cout << "NO";
	return 0;
}
```

## 연관 문제
https://www.acmicpc.net/problem/5052
https://www.acmicpc.net/problem/14725
https://school.programmers.co.kr/learn/courses/30/lessons/60060

## 참고
https://rebro.kr/86
{% endraw %}