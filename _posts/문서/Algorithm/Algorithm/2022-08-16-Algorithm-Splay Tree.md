---
categories:
- Algorithm
date: '2022-08-16'
title: '[Algorithm] Splay Tree'
---

{% raw %}
## Splay Tree
`Splay Tree`는 AVL-Tree, Red-Black Tree와 같은 BBST(Balanced Binary Search Tree)다. 스플레이 트리는 BBST이므로 모든 연산은 O(logN) 시간이 걸린다.

트리 높이를 항상 O(logN)으로 유지하는 일반적인 BBST와 달리, 스플레이 트리는 현재 노드를 루트로 올리는 'Splay' 연산으로 균형을 유지한다. 또한 타 BBST보다 구현이 상대적으로 쉽다는 이점이 있다.

스플레이 트리를 사용해서 구간 연산을 수행할 수 있다. 이는 `세그먼트 트리`와 비슷하지만, 스플레이 트리는 reverse 연산과 shift 연산도 수행할 수 있다.

## Node
우선 스플레이 트리를 구성하는 노드를 생성하자.

스플레이 트리는 BBST이고, BBST는 BST(Binary Search Tree)이므로 모든 노드는 검색에 사용되는 key와 최대 2개의 자식 노드를 갖는다. 구현은 노드간 포인터 연결을 사용한다.

노드의 key는 트리의 **중위 순회의 순서번호**다. 추후 구간 연산에서 key가 변동될 수 있으므로, 각 노드에 key를 저장하지 않고 필요할 때 key를 구하는 방식으로 한다.
```
struct Node {
	Node* l, * r, * p; // 각각 왼쪽, 오른쪽, 부모 노드 포인터
	int size = 1; // 현재 노드를 루트로 하는 서브트리의 크기(=노드 개수)
	// key는 따로 저장하지 않는다.

	// 생성자
	Node(int d) {
		l = r = p = nullptr;
	}
	
	// 소멸자 (연쇄 소멸)
	~Node() { 
		if (l) delete l;
		if (r) delete r;
	}
	
	// 업데이트 연산 - 자식 노드를 통해서 값 업데이트
	void update() {
		size = 1;
		if (l) size += l->size;
		if (r) size += r->size;
	}
};
```

## Rotate
rotate 연산은 입력 노드를 부모 노드와 위치를 바꾸는 연산으로 BBST에서 균형을 유지하는데 사용된다. rotate 연산을 수행해도 노드간의 key 순서는 유지된다.
> rotate(x) = 노드 x를 x의 부모 노드 p하고 위치를 변경한다. 변경 이후에는 p는 x의 자식 노드가 된다.<br>

rotate는 크게 2가지 case로 나눌 수 있다.
```
> case 1.<br>
      pp
      p
   x     q
 a   c

> after 1<br>
      pp
      x
   a     p
       c   q

> case 2.<br>
      pp
      p
   q     x
       c   a

> after 2<br>
      pp
      x
   p     a
 q   c
```
case에 맞게 노드 x, p, c, pp의 연결 관계를 변경해주면 된다.

노드들의 자식 관계도 변경되니, 마지막에 노드 update 연산을 수행한다. rotate 이후는 p가 x의 자식이니 p->update(), x->update() 순서대로 실행하면 된다.

```
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
```

## Splay
splay 연산은 스플레이 트리에서 균형을 맞추는데 사용되는 연산으로,  rotate 연산을 활용해서입력 노드를 루트로 올린다.
> splay(x) = 노드 x를 루트로 옮긴다.<br>

하지만 단순 rotate(x)만 사용해서 균형 높이를 보장할 수 없다. 그래서 스플레이 트리에선 다음 전략을 사용한다. (이 전략을 사용해서 균형이 유지된다는 사실이 이미 증명되어 있다)
>  노드 x의 부모가 p, p의 부모가 pp일 때, 자식 방향 pp→p→x이 일직선이면 p를 먼저 회전한 다음에 x를 회전한다.<br>

일직선은 자식 방향이 모두 왼쪽 or 오른쪽임을 의미한다. 
- pp의 왼쪽 자식이 p이고 p의 왼쪽 자식이 x이다.
- pp의 오른쪽 자식이 p이고 p의 오른쪽 자식이 x이다.

splay(x) 연산을 정리하면 다음과 같다.
```
1. pp가 없음 => rotate(x)
2. pp→p→x가 일직선 => rotate(p), rotate(x)
3. pp→p→x가 일직선이 아님 => rotate(x), rotate(x)
```
이 과정을 x가 루트가 될 때까지 반복하면 된다.
```
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
```

## Find
find(k)는 key가 k인 노드를 루트로 올리는 연산이다. 노드는 key를 저장하지 않으므로 key를 직접 계산해야 한다.

key는 중위 순회의 순서번호이므로 왼쪽 노드로 이동하면 k를 유지하고, 오른쪽 노드로 이동하면 k에 (왼쪽 노드의 size + 1)를 빼면 된다. 이 과정을 k가 0이 될 때까지 반복하면 목표 노드를 찾을 수 있다. 마지막으로 찾은 노드를 splay 연산을 사용해서 루트 쪽으로 옮긴다.
```
void Find(int k) {
	Node* x = root;
	while (1) {
		while (x->l && x->l->size > k)
			x = x->l;
		if (x->l) k -= x->l->size;
		if (!k--) break;
		x = x->r;
	}
	Splay(x);
}
```

## GetKey
getkey(x)는 노드 x의 key를 반환하는 연산으로, Find의 역연산이다.

x에서 루트까지 올라가면서 경로를 `스택`에 저장한 다음, 다시 경로를 따라 루트부터 x로 내려간다. 내려가면서 x의 key를 구할 수 있다. (key를 더하는 과정은 Find와 비슷하다)
```
int GetKey(Node* x) {
	// x → 루트
	stack<Node*> path;
	Node* v = x; path.push(v);
	while (v->p) {
		v = v->p;
		path.push(v);
	}

	// 루트 → x
	int sz = 0;
	v = path.top(); path.pop();
	while (!path.empty()) {
		v = path.top(); path.pop();
		if (v == v->p->r) {
			if (v->p->l)
				sz += v->p->l->size;
			sz++;
		}
	}
	if (v->l) sz += v->l->size;
	return sz;
}
```

## Range
range(lo, hi)는 구간 [lo, hi] 서브트리의 루트를 반환하는 연산이다. (구간에서 위치는 key하고 같다)

(hi + 1)번 노드를 루트, (lo - 1)번 노드를 루트의 왼쪽 자식, [lo, hi]에 속하는 노드들을 (lo - 1)번 노드의 오른쪽 서브트리로 한다.
```
          (hi+1)
   (lo-1)         A
 B    [lo, hi]
```

이는 Find 연산을 응용해서 구현할 수 있다.
```
Node* Range(int lo, int hi) {
	// hi+1 노드를 루트로 올린다.
	Find(hi + 1);
	
	// 추후 Find 연산을 위해 임시로 왼쪽 노드와 루트간의 연결을 끊는다.
	Node* R = root;
	root = root->l;
	root->p = nullptr;

	// lo-1 노드를 루트(=원래 루트의 왼쪽 자식)로 올린다.
	Find(lo - 1);

	// 다시 root를 정상적으로 연결한다.
	R->l = root;
	root->p = R;
	root = R;

	// 구간 서브트리의 루트 반환
	return root->l->r;
}
```
※ 간혹 lo-1, hi+1이 key 범위의 바깥을 벗어날 수 있는데(ex. 최대 구간 = [1, N]), 이는 양끝에 더미 노드를 추가하면 해결할 수 있다. 각 더미 노드의 key값은 0, N + 1이다.

## Create
이제 노드를 트리에 추가해보자. 노드 추가는 일반적인 BST의 추가 연산과 비슷하게 구현할 수도 있지만, 여기서는 한번에 모든 노드가 추가되고 이후에는 노드가 추가되지 않는다고 가정한다.

루트부터 시작해 오른쪽 자식 방향으로 더미 노드 1, N개의 노드, 더미 노드 2를 순차적으로 추가하면 된다. 마지막에는 다시 루트로 올라가면서 노드 update 연산을 수행한다.
```
void Create() {
	// 노드 추가 (루트 → x)
	Node* x = root = new Node();
	for (int i = 1; i <= N; i++) {
		x->r = new Node();
		x->r->p = x;
		x = x->r;
		pdr[i] = x;
	}
	x->r = new Node();
	x->r->p = x;

	// 노드 업데이트 (x → 루트)
	while (x) {
		x->update();
		x = x->p;
	}
}
```
필요에 따라 노드의 포인터를 직접적으로 가리키는 목록을 저장할 수 있다. (주로 GetKey의 입력으로 사용된다)

## 코드 1
`BOJ - 2042 - 구간 합 구하기` 코드

노드에서 값과 구간의 합을 저장하는 변수를 추가하자. 노드 update에서 구간 합을 업데이트할 수 있다.
```
#include <iostream>
typedef long long ll;
using namespace std;
ll N, M, K;
struct Node {
	Node* l, * r, * p;
	int key, size = 1;
	ll data = 0, sum = 0;

	Node(int k, ll d) { 
		key = k, data = d;
		l = r = p = nullptr;
	}
	void update() {
		size = 1;
		sum = data;
		if (l) size += l->size, sum += l->sum;
		if (r) size += r->size, sum += r->sum;
	}
};
Node* root;

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
		while (1) {
			while (x->l && x->l->size > k)
				x = x->l;
			if (x->l) k -= x->l->size;
			if (!k--) break;
			x = x->r;
		}
		Splay(x);
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

	void Create(int lo, int hi) {
		Node* x = root = new Node(lo - 1, 0);
		for (int i = lo; i <= hi; i++) {
			ll num; cin >> num;
			x->r = new Node(i, num);
			x->r->p = x;
			x = x->r;
		}
		x->r = new Node(hi + 1, 0);
		x->r->p = x;

		while (x) {
			x->update();
			x = x->p;
		}
	}
} splay;

void Update(int x, ll v) {
	splay.Range(x, x)->data = v;
	splay.Range(x, x)->update();
}

ll Get(int lo, int hi) {
	return splay.Range(lo, hi)->sum;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> K;
	splay.Create(1, N);

	ll Q = M + K;
	while (Q--) {
		ll a, b, c;
		cin >> a >> b >> c;
		if (a == 1) Update(b, c);
		else cout << Get(b, c) << "\n";
	}
	return 0;
}
```

## Lazy Propagation
스플레이 트리에 `Lazy Propagation`을 적용할 수 있다. 작동 메커니즘은 `세그먼트 트리`하고 동일하다. (바로 모든 노드를 업데이트하지 않고 자식 노드에 업데이트 내용을 전파)

노드를 방문할 때마다 작업을 하기 전에 전파 연산을 수행하면 된다. (노드의 update, 트리의 Find, GetKey 연산에서 propagate를 넣어주자)
```
struct Node {
	Node* l, * r, * p;
	int key, size = 1;
	ll data = 0, sum = 0, lazy = 0;
	
	// 업데이트 연산
	void update() {
		size = 1;
		sum = data;
		if (l) {
			l->propagate();
			size += l->size;
			sum += l->sum;
		}
		if (r) {
			r->propagate();
			size += r->size;
			sum += r->sum;
		}
	}
	// 전파 연산 (자식 노드에게 lazy 전파)
	void propagate() {
		data += lazy;
		sum += lazy * size;
		if (l) l->lazy += lazy;
		if (r) r->lazy += lazy;
		lazy = 0;
	}
};
```

## 코드 2
`BOJ - 10999 - 구간 합 구하기 2` 코드

값 업데이트 쿼리는 lazy에 값을 더해주면 된다. 또한 값 반환 쿼리에서도 노드 방문이 발생하니 이때도 propagate를 넣어준다.
```
#include <iostream>
typedef long long ll;
using namespace std;
ll N, M, K;
struct Node {
	Node* l, * r, * p;
	int key, size = 1;
	ll data = 0, sum = 0, lazy = 0;

	Node(int k, ll d) { 
		key = k, data = d;
		l = r = p = nullptr;
	}
	void update() {
		size = 1;
		sum = data;
		if (l) {
			l->propagate();
			size += l->size;
			sum += l->sum;
		}
		if (r) {
			r->propagate();
			size += r->size;
			sum += r->sum;
		}
	}
	void propagate() {
		data += lazy;
		sum += lazy * size;
		if (l) l->lazy += lazy;
		if (r) r->lazy += lazy;
		lazy = 0;
	}
};
Node* root;

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
			while (x->l && x->l->size > k)
				x = x->l, x->propagate();
			if (x->l) k -= x->l->size;
			if (!k--) break;
			x = x->r;
			x->propagate();
		}
		Splay(x);
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

	void Create(int lo, int hi) {
		Node* x = root = new Node(lo - 1, 0);
		for (int i = lo; i <= hi; i++) {
			ll num; cin >> num;
			x->r = new Node(i, num);
			x->r->p = x;
			x = x->r;
		}
		x->r = new Node(hi + 1, 0);
		x->r->p = x;

		while (x) {
			x->update();
			x = x->p;
		}
	}
} splay;

void Update(int lo, int hi, ll v) {
	splay.Range(lo, hi)->lazy += v;
}

ll Get(int lo, int hi) {
	Node* x = splay.Range(lo, hi);
	x->propagate();
	return x->sum;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> K;
	splay.Create(1, N);

	ll Q = M + K;
	while (Q--) {
		ll a, b, c, d;
		cin >> a >> b >> c;
		if (a == 1) {
			cin >> d;
			Update(b, c, d);
		}
		else cout << Get(b, c) << "\n";
	}
	return 0;
}
```

## Reverse
reverse(lo, hi)는 구간 내 노드의 순서를 뒤집는 연산이다. 이는 구간 내 모든 노드의 왼쪽, 오른쪽 서브트리를 swap함으로써 구현할 수 있다. 하지만 한번에 모든 노드를 업데이트하면 오래 걸리므로 Lazy Propagation을 적용한다.

boolean 변수에 노드의 뒤집기 연산 수행 여부를 저장한다. 변수의 on/off는 XOR 연산으로 할 수 있다.
```
struct Node {
	...
	bool flip = 0; // lazy 변수: 1이면 구간 뒤집기 수행
	...
	// 전파 연산
	void propagate() {
		if (!flip) return;
		swap(l, r); // 서브트리 swap
		if (l) l->flip ^= 1;
		if (r) r->flip ^= 1;
		flip = 0;
	}
};
```

Range 연산을 사용해서 구간을 모으고 flip 변수을 on/off하는 것으로 Reverse 연산을 구현할 수 있다.
```
void Flip(int lo, int hi) {
	splay.Range(lo, hi)->flip ^= 1;
}
```
※ 이 연산에서 각 노드의 key값이 변경되므로 노드에 key를 직접 저장하지 않았다.

## Shift
shift(lo, hi, t)는 구간 [lo, hi] 내에서 노드들을 오른쪽으로 t만큼 옮기는(rotating shift) 연산이다. t가 음수일 때는 -t만큼 왼쪽으로 옮긴다.

Reverse 연산으로 구현할 수 있다. 아래와 같이 예시가 있다고 하자.
```
ex. 
1 2 3 4 (t = 2)
> 3 4 1 2<br>

1. (4 3 2 1)
2. (3 4) (1 2)
=> reverse(1, 4), reverse(1, 2), reverse(3, 4)
```
이를 일반화하면, (0 < t < hi - lo + 1)
> shift(lo, hi, t) = reverse(lo, hi), reverse(lo, lo + t - 1), reverse(lo + t, hi)<br>

t의 범위를 주의해서 Shift를 구현하면 된다.
```
void Shift(int lo, int hi, int t) {
	// (0 < t < len)
	int len = hi - lo + 1;
	t = (t + N / len * len + len) % len;
	if (t == 0) return;

	// Shift
	Flip(lo, hi);
	Flip(lo, lo + t - 1);
	Flip(lo + t, hi);
}
```

## 코드 3
`BOJ - 13159 - 배열` 코드

트리의 모든 노드 순회는 중위 순회로 `DFS` 탐색하면 된다. DFS 탐색할 때는 노드를 방문하므로 propagate를 적용하자.
```
#include <iostream>
#include <stack>
typedef long long ll;
using namespace std;
int N, M;
struct Node {
	Node* l, * r, * p;
	int size = 1;
	ll value, sum, minV, maxV;
	bool flip = 0;

	Node(int d) {
		sum = minV = maxV = value = d;
		l = r = p = nullptr;
	}
	~Node() { 
		if (l) delete l;
		if (r) delete r;
	}
	void update() {
		size = 1;
		sum = minV = maxV = value;
		if (l) {
			l->propagate();
			size += l->size;
			sum += l->sum;
			minV = min(minV, l->minV);
			maxV = max(maxV, l->maxV);
		}
		if (r) {
			r->propagate();
			size += r->size;
			sum += r->sum;
			minV = min(minV, r->minV);
			maxV = max(maxV, r->maxV);
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
Node* pdr[300002];

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
			while (x->l && x->l->size > k)
				x = x->l, x->propagate();
			if (x->l) k -= x->l->size;
			if (!k--) break;
			x = x->r;
			x->propagate();
		}
		Splay(x);
	}

	int GetKey(Node* x) {
		stack<Node*> path;
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
				if (v->p->l)
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
		Node* x = root = new Node(0);
		x->maxV = 0; x->minV = N + 1;
		for (int i = 1; i <= N; i++) {
			x->r = new Node(i);
			x->r->p = x;
			x = x->r;
			pdr[i] = x;
		}
		x->r = new Node(0);
		x->r->p = x;
		x->maxV = 0; x->minV = N + 1;

		while (x) {
			x->update();
			x = x->p;
		}
	}

	void Delete() { delete root; }
} splay;

void Flip(int lo, int hi) {
	splay.Range(lo, hi)->flip ^= 1;
}

void Shift(int lo, int hi, int t) {
	int len = hi - lo + 1;
	t = (t + N / len * len + len) % len;
	if (t == 0) return;

	Flip(lo, hi);
	Flip(lo, lo + t - 1);
	Flip(lo + t, hi);
}

void DFS(Node* v) {
	if (!v) return;
	v->propagate();
	DFS(v->l);
	if(v->value != 0)
		cout << v->value << " ";
	DFS(v->r);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	splay.Create();
	for (int i = 0; i < M; i++) {
		int a, b, c, d;
		cin >> a >> b;
		if (a == 1) {
			cin >> c;
			Node* x = splay.Range(b, c);
			cout << x->minV << " " << x->maxV << " " << x->sum << "\n";
			Flip(b, c);
		}
		if (a == 2) {
			cin >> c >> d;
			Node* x = splay.Range(b, c);
			cout << x->minV << " " << x->maxV << " " << x->sum << "\n";
			Shift(b, c, d);
		}
		if (a == 3)
			cout << splay.Range(b, b)->value << "\n";
		if (a == 4) 
			cout << splay.GetKey(pdr[b]) << "\n";
	}
	DFS(root);
	splay.Delete();
	return 0;
}
```

## 연관 문제
<br>https://www.acmicpc.net/problem/3444
<br>https://www.acmicpc.net/problem/13159

## 참고
<br>https://aruz.tistory.com/180
<br>https://justicehui.github.io/tag/#/Splay-Tree
{% endraw %}