---
categories:
- Algorithm
date: '2022-07-07'
title: '[Algorithm] Aho-Corasick Algorithm'
---

{% raw %}
## 다중 패턴?
입력 문자열에서 1개의 문자열 패턴을 찾을 때는 `KMP Algorithm`이 사용된다. 하지만 패턴이 여러 개가 추가되면 어떨까?

이때 KMP를 사용하면 시간 복잡도는 O(N × k + M<sub>1</sub> + M<sub>2</sub> + ... )이다. (N = 입력 문자열 길이, M<sub>i</sub> = i번 패턴 길이, k = 패턴 개수)<br>

여기서 `Aho-Corasick`을 사용하면 O(N + M<sub>1</sub> + M<sub>2</sub> + ... )으로 단축할 수 있다. 일반적으로 문자열 패턴 검색은 N이 상대적으로 큰 편이므로(웹페이지에서 Ctrl+F를 사용해보자) 유의미한 감소폭이다.<br>

## Aho-Corasick Algorithm
`Aho-Corasick`은 입력 문자열에서 여러 개의 패턴을 찾는 것에 특화된 검색 알고리즘이다. 동작을 1줄로 요약하자면, `Trie`에서 `KMP Algorithm`를 수행한 것이라고 볼 수 있다.

< Aho-Corasick 과정 >
```
1. Trie에 모든 패턴 문자열을 추가한다.
2. 실패함수를 구성한다. (BFS 탐색)
3. 입력 문자열 탐색
```

### 패턴 추가
일반적인 trie 추가 과정과 동일하다.
```
ex. 패턴 목록 [c, kbcz, kbcy, ckbck]
R = 루트 노드
() = 패턴 끝이 1인 노드
        R
  (c)       k
   k        b
   b        c
   c       (z)  (y)
  (k)
```

### 실패 함수(Failure Function)
Aho-Corasick의 문자열 비교 과정은 KMP 알고리즘과 비슷하다. 만약 현재 입력 문자열의 문자와 trie의 노드가 불일치하면 실패(fail) 노드로 이동한다.

모든 노드는 실패 노드 연결 관계를 1개씩 가지고 있다. 어떤 노드에 대한 실패 노드의 정의는 다음과 같다.
> 현재 노드가 a일 때,<br>
> 지금까지 일치했던 문자열의 접미사 = S <br>
> 어떤 문자열의 접두사 = P<br>
> S == P를 만족하는 최대 길이의 S가 존재할 때, P의 마지막 노드가 a의 실패 노드다.<br>
> 만족하는 S가 존재하지 않으면 루트 노드가 a의 실패 노드다.<br>
> (단, S ≠ (루트부터 a까지 경로))<br>

만약 실패 노드의 패턴의 끝 정보가 1이라면, 현재 노드의 패턴의 끝 정보도 1이 된다. 이렇게 하면 입력 문자열을 탐색할 때 어떤 패턴에 포함된 작은 패턴의 일치 유무도 판별할 수 있다. (ex. 패턴 c, ckbck가 있을 때 ckbcz를 탐색해보자)

< 실패 노드 적용 >
![](images/Aho-Corasick-trie-fail.png)
※ []: 실패 노드에 의해 패턴의 끝이 1인 노드 

```
4
c
ckbck
kbcz
kbcy

현재 노드, 문자, 깊이, 패턴 끝, 실패 노드
053CAC60, 0, 0 = 0 => 053CAC60 // 루트<br>

053C6F68, c, 1 = 1 => 053CAC60<br>
053C4A58, k, 2 = 0 => 053D1870<br>
053CA920, b, 3 = 0 => 053D1558<br>
053CECC0, c, 4 = 1 => 053D1710<br>
053CED18, k, 5 = 1 => 053C4A58<br>

053D1870, k, 1 = 0 => 053CAC60<br>
053D1558, b, 2 = 0 => 053CAC60<br>
053D1710, c, 3 = 1 => 053C6F68<br>
053D1768, z, 4 = 1 => 053CAC60<br>
053D1818, y, 4 = 1 => 053CAC60<br>
```

- "ckbck"
	- c: 만족하는 S가 없다. 따라서 루트를 가리킨다.
	- k: (k) 중에서 k가 S를 만족한다.
	- b: (b, kb) 중에서 kb가 S를 만족한다.
	- c: (c, bc, kbc) 중에서 kbc가 S를 만족한다. 실패 노드의 끝 정보를 따라 현재 노드의 끝 정보도 1이 된다.
	- k: (k, ck, bck, kbck) 중에서 ck가 S를 만족한다.
- "kbcz/y"
	- k: 만족하는 S가 없다.
	- b: (b) 중에서 만족하는 S가 없다.
	- c: (c, bc) 중에서 c가 S를 만족한다. 실패 노드의 끝 정보를 따라 현재 노드의 끝 정보도 1이 된다.
	- z, y: 만족하는 S가 없다.

실패 함수는 모든 노드에 대한 실패 노드를 설정하는 과정으로, KMP 알고리즘에서 pi 배열을 구하는 포지션에 대응된다. 위의 예시처럼 실패 노드에 의한 끝 정보를 결정하는 것이 필요하므로 인접 정점부터 탐색해야 한다. 따라서 실패 함수에선 `BFS`를 사용한다.
```
void Failure() {
	queue <Node*> q;<br>
	q.push(root); // 루트부터 시작
	root->fail = root; // 루트 노드의 실패 노드 = 루트 노드

	while (!q.empty()) {
		Node* v = q.front();
		q.pop();

		// 인접 노드 조사
		for (int i = 0; i < TYPE; i++) {
			Node* next = v->child[i];
			if (next == nullptr)
				continue;

			// 다음 노드의 깊이가 1인 경우 (루트 노드와 인접한 경우)
			// => 다음 노드의 실패 노드 = 루트 노드<br>
			if (v == root)
				next->fail = root;
			// 다음 노드의 깊이가 2 이상인 경우
			else {
				// 이전 깊이 노드의 실패 노드를 활용해 다음 노드의 실패 노드를 찾는다.
				// KMP 알고리즘에서 pi 배열을 구할 때 이전 pi 정보를 활용한 것과 유사
				Node* fNode = v->fail;
				while (fNode != root && fNode->child[i] == nullptr)
					fNode = fNode->fail;
				if (fNode->child[i] != nullptr)
					fNode = fNode->child[i];
				next->fail = fNode;
			}
			// 실패 노드의 패턴의 끝 정보가 1이라면,
			// 현재 노드의 패턴의 끝 정보도 1이 된다
			if (next->fail->isEnd)
				next->isEnd = 1;

			q.push(next);
		}
	}
}
```

### 입력 문자열 탐색
KMP 알고리즘과 마찬가지로, 만약 현재 입력 문자열의 문자와 trie의 노드가 불일치하면 실패 노드로 이동한다.
```
bool KMP(const char* T) {
	Node* v = root;
	bool ok = 0;
	int len = strlen(T);

	// 입력 문자열 순차 탐색
	for (int w = 0; w < len; w++) {
		int i = Converter(T[w]);
		
		// 현재 문자와 trie 노드를 비교한다.
		// 불일치시 (실패 노드로 이동 & 비교)를 문자가 일치할 때까지 반복
		while (v != root && v->child[i] == nullptr)
			v = v->fail;
		if (v->child[i] != nullptr)
			v = v->child[i];

		// 이벤트: 현재 문자가 어떤 패턴의 끝일 때
		if (v->isEnd)
			ok = 1;
	}
	return ok;
}
```

## 코드
`BOJ - 9250 - 문자열 집합 판별` 코드
```
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
const int TYPE = 26;
int Converter(char c) { return c - 'a'; }

class Node {
public:
	bool isEnd = 0;
	Node* child[TYPE];
	Node* fail;

	Node() {
		isEnd = 0;
		for (int i = 0; i < TYPE; i++)
			child[i] = nullptr;
		fail = nullptr;
	}

	~Node() {
		for (int i = 0; i < TYPE; i++)
			if (child[i])
				delete child[i];
	}

	void Insert(const char* str) {
		if (!*str) {
			isEnd = 1;
			return;
		}

		int first = Converter(*str);
		if (child[first] == nullptr)
			child[first] = new Node();
		child[first]->Insert(str + 1);
	}
};
Node* root = new Node();

void Failure() {
	queue <Node*> q;<br>
	q.push(root);
	root->fail = root;

	while (!q.empty()) {
		Node* v = q.front();
		q.pop();

		for (int i = 0; i < TYPE; i++) {
			Node* next = v->child[i];
			if (next == nullptr)
				continue;

			if (v == root)
				next->fail = root;
			else {
				Node* fNode = v->fail;
				while (fNode != root && fNode->child[i] == nullptr)
					fNode = fNode->fail;
				if (fNode->child[i] != nullptr)
					fNode = fNode->child[i];
				next->fail = fNode;
			}
			if (next->fail->isEnd)
				next->isEnd = 1;

			q.push(next);
		}
	}
}

bool KMP(const char* T) {
	Node* v = root;
	bool ok = 0;
	int len = strlen(T);

	for (int w = 0; w < len; w++) {
		int i = Converter(T[w]);
		while (v != root && v->child[i] == nullptr)
			v = v->fail;
		if (v->child[i] != nullptr)
			v = v->child[i];

		if (v->isEnd)
			ok = 1;
	}
	return ok;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;<br>
	while (N--) {
		string s;
		cin >> s;<br>
		root->Insert(s.c_str());
	}
	Failure();

	cin >> N;<br>
	while (N--) {
		string s;
		cin >> s;<br>
		cout << (KMP(s.c_str()) ? "YES" : "NO") << "\n";
	}
	return 0;
}
```

## 관련 문제
https://www.acmicpc.net/problem/9250<br>
https://www.acmicpc.net/problem/10256<br>
https://www.acmicpc.net/problem/2809<br>

## 참고
https://pangtrue.tistory.com/305<br>
https://loosie.tistory.com/m/587<br>
https://koosaga.com/157<br>
{% endraw %}