---
categories:
- BOJ
date: '2022-08-16'
title: '[BOJ] 3444 - Robotic Sort'
---

{% raw %}
> 다이아몬드 III<br>

## 문제
Somewhere deep in the Czech Technical University buildings, there are laboratories for examining mechanical and electrical properties of various materials. In one of yesterday’s presentations, you have seen how was one of the laboratories changed into a new multimedia lab. But there are still others, serving to their original purposes.

In this task, you are to write software for a robot that handles samples in such a laboratory. Imagine there are material samples lined up on a running belt. The samples have different heights, which may cause troubles to the next processing unit. To eliminate such troubles, we need to sort the samples by their height into the ascending order.

Reordering is done by a mechanical robot arm, which is able to pick up any number of consecutive samples and turn them round, such that their mutual order is reversed. In other words, one robot operation can reverse the order of samples on positions between A and B.

A possible way to sort the samples is to find the position of the smallest one (P1) and reverse the order between positions 1 and P1, which causes the smallest sample to become first. Then we find the second one on position P2 and reverse the order between 2 and P2. Then the third sample is located etc.

The picture shows a simple example of 6 samples. The smallest one is on the 4th position, therefore, the robot arm reverses the first 4 samples. The second smallest sample is the last one, so the next robot operation will reverse the order of five samples on positions 2–6. The third step will be to reverse the samples 3–4, etc.

Your task is to find the correct sequence of reversal operations that will sort the samples using the above algorithm. If there are more samples with the same height, their mutual order must be preserved: the one that was given first in the initial order must be placed before the others in the final order too.

### 입력
The input consists of several scenarios. Each scenario is described by two lines. The first line contains one integer number N, the number of samples, 1 ≤ N ≤ 100 000. The second line lists exactly N space-separated positive integers, they specify the heights of individual samples and their initial order.

The last scenario is followed by a line containing zero.

### 출력
For each scenario, output one line with exactly N integers P1, P2,...PN , separated by a space. Each Pi must be an integer (1 ≤ Pi ≤ N) giving the position of the i-th sample just before the i-th reversal operation.

Note that if a sample is already on its correct position Pi, you should output the number Pi anyway, indicating that the “interval between Pi and Pi” (a single sample) should be reversed.

## 해결
구간 뒤집기로 정렬하는 문제. 구간 뒤집기는 `Lazy Propagation`을 사용하는 `스플레이 트리`로 빠르게 할 수 있다.

전체 과정은 아래와 같이 요약할 수 있다.
```
> 1부터 N까지 순차 탐색 => i<br>
1. [i, N]에서 높이가 최소인 샘플의 위치(key) = k
2. reverse(i, k) 수행
```

샘플의 값은 변하기 않기 때문에 구간의 최소값은 처음 입력할 때 이미 정해져 있다. 입력할 때 샘플 데이터(트리 노드 포인터, 샘플 높이, 처음 순서)를 따로 목록에 저장하고, 이 목록을 샘플 높이 오름차순으로 `안정 정렬`한 다음 순차적으로 꺼내서 사용하면 된다.

하지만 노드 포인터 x를 직접적으로 접근하는 것은 트리의 루트를 거치기 않기 때문에 몇 가지 문제가 있다.
- x의 key를 알 수 없다.
- lazy 전파가 반영되지 않는다. (x를 바로 splay하면 정확한 결과를 보장할 수 없다)

2가지 문제를 같이 해결해보자. x에서 루트까지 올라가면서 경로를 `스택`에 저장한 다음, 다시 경로를 따라 루트부터 x로 내려간다. 내려가면서 lazy 전파를 적용하고 x의 key도 구할 수 있다.

x의 key는 트리에서 중위 순회의 번호이며, key를 구하는 과정은 Find의 역연산이라고 볼 수 있다. 현재 노드에서 lazy 전파를 적용한 뒤, 왼쪽, 오른쪽 서브트리의 크기를 통해서 더하는 방식으로 key를 구한다.

마지막으로 문제에 여러 테스트 케이스가 있으니, 케이스마다 스플레이 트리를 초기화해야 한다. (delete와 소멸자를 활용하면 된다)

## 코드
```
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
int N;
struct Node {
	Node* l, * r, * p;
	int size = 1;
	bool flip = 0;

	Node() { l = r = p = nullptr; }
	~Node() { 
		if (l) delete l;
		if (r) delete r;
	}
	void update() {
		size = 1;
		if (l) {
			l->propagate();
			size += l->size;
		}
		if (r) {
			r->propagate();
			size += r->size;
		}
	}
	void propagate() {
		if (!flip) return;
		swap(l, r);
		if (l) l->flip ^= 1;
		if (r) r->flip ^= 1;
		flip = 0;
	}
};
Node* root;

struct Robotic {
	Node* p;
	int key, id;
};
Robotic robotic[100002];

bool cmp(Robotic a, Robotic b) {
	return (a.key != b.key) ? a.key < b.key : a.id < b.id;
}

struct SplayMethod {
	void Rotate(Node* x) {
		Node* p = x->p, * c, * pp;
		if (!p) return;

		if (p->l == x) {
			p->l = c = x->r;
			x->r = p;
		}
		else {
			p->r = c = x->l;
			x->l = p;
		}
		if (c) c->p = p;

		x->p = pp = p->p;
		p->p = x;
		if (!pp) root = x;
		else if (pp->l == p) pp->l = x;
		else pp->r = x;

		p->update();
		x->update();
	}

	void Splay(Node* x) {
		while (x->p) {
			Node* p = x->p, * pp = p->p;
			if (!pp)
				Rotate(x);
			else if ((pp->l == p) == (p->l == x)) {
				Rotate(p);
				Rotate(x);
			}
			else {
				Rotate(x);
				Rotate(x);
			}
		}
	}

	void Find(int k) {
		Node* x = root;
		x->propagate();
		while (1) {
			while (x->l && x->l->size > k)<br>
				x = x->l, x->propagate();
			if (x->l) k -= x->l->size;
			if (!k--) break;
			x = x->r;
			x->propagate();
		}
		Splay(x);
	}

	int PathUpdate(Node* x) {
		stack<Node*> path;<br>
		Node* v = x; path.push(v);
		while (v->p) {
			v = v->p;
			path.push(v);
		}

		int sz = 0;
		v = path.top(); path.pop();
		while (!path.empty()) {
			v->propagate();
			v = path.top(); path.pop();
			if (v == v->p->r) {
				if(v->p->l)
					sz += v->p->l->size;
				sz++;
			}
		}
		v->propagate();
		if (v->l) sz += v->l->size;

		return sz;
	}

	Node* Range(int lo, int hi) {
		Find(hi + 1);
		Node* R = root;
		root = root->l;
		root->p = nullptr;

		Find(lo - 1);
		R->l = root;
		root->p = R;
		root = R;
		return root->l->r;
	}

	void Create() {
		Node* x = root = new Node();
		for (int i = 0; i < N; i++) {
			int num; cin >> num;<br>
			x->r = new Node();
			x->r->p = x;
			x = x->r;
			robotic[i] = { x, num, i };
		}
		x->r = new Node();
		x->r->p = x;

		while (x) {
			x->update();
			x = x->p;
		}
		sort(robotic, robotic + N, cmp);
	}

	void Delete() { delete root; }
} splay;

void Flip(int lo, int hi) {
	splay.Range(lo, hi)->flip ^= 1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	while (1) {
		cin >> N;<br>
		if (N == 0) return 0;

		splay.Create();
		for (int i = 0; i < N; i++) {
			int k = splay.PathUpdate(robotic[i].p);
			cout << k << " ";
			Flip(i + 1, k);
		}
		cout << "\n";
		splay.Delete();
	}
	return 0;
}
```

## 링크
https://www.acmicpc.net/problem/3444<br>
{% endraw %}