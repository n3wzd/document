# 2-SAT
## SAT(Boolean Satisfiability Problem)
SAT 문제는 boolean 식의 각 변수에 적절한 값을 대입해서 해당 식의 출력을 true로 만들 수 있는지를 판별하는 문제다.
- Satisfiable: 각 변수에 적절한 값을 대입해서 true로 만들 수 있음
- Unsatisfiable: 각 변수에 어떤 값을 대입해도 true로 만들 수 없음 (Satisfiable의 반대)
> F~1~ = (x~1~ ∨ x~2~) ∧ (￢x~1~ ∨ ￢x~2~)
> F~2~ = (x~1~ ∨ x~1~) ∧ (￢x~1~ ∨ ￢x~1~)

F~1~은 satisfiable, F~2~는 unsatisfiable이다.

## 2-SAT
`2-SAT`는 SAT의 특수한 경우로, 모든 절(clause)이 2개의 변수(term)을 가지는 CNF(Conjunctive Normal Form)에서 SAT를 판별하는 문제다. CNF는 Product of Sums(POS)이라고도 하며, OR 연산으로 구성된 절을 모두 AND한 boolean 식이다.

> F = (A~1~ ∨ B~1~) ∧ (A~2~ ∨ B~2~) ∧ ... ∧ (A~n~ ∨ B~n~)

2-SAT는 다항 시간 내 해결 가능한 알고리즘이 알려져 있다. 

## 설계
CNF가 ture가 되려면 모든 절이 true가 되어야 한다.

A ∨ B가 1이 되려면,
-   If A = 0, B는 1이어야 함 => ￢A → B
-   If B = 0, A는 1이어야 함 => ￢B → A

따라서,
> A ∨ B ≡ (￢A → B) ∧ (￢B → A)

이 공식을 사용해서 모든 OR를 방향 그래프로 모델링할 수 있다. 만약 A → B이면, 정점 A에서 B로 가는 경로가 존재한다는 것과 같다.

A ∨ A를 조사해보자.
> (A → ￢A) ∧ (￢A → A)

A에 0, 1을 대입해도 위의 식은 1이 될 수 없다.
```
A   ￢A   A→￢A
1    1     1
1    0     0
0    1     1
0    0     1
```

이를 정리하면,
> 임의의 변수 X에 대해 X와 ￢X이 사이클을 구성한다면(X → ￢X, ￢X → X가 모두 존재한다면) 해당 CNF는 unsatisfiable하다. 그렇지 않으면 satisfiable하다.

`강한 연결 요소`를 적용하면 위의 조건을 판단할 수 있다.
> 정점 X, ￢X가 같은 SCC에 속하면 해당 그래프는 unsatisfiable이다.

### 해답 구하기
CNF가 satisfiable일 때를 살펴보자. A → B가 1이 되려면 A = 1, B = 0인 경우만 피하면 된다.
```
A    B    A→B
1    1     1
1    0     0
0    1     1
0    0     1
```
A를 0으로 가정한다면 B는 0, 1이 모두 가능하지만, A를 1로 가정하면 B는 1로 고정된다. 따라서 위상 정렬을 했을 때 앞에 있는 정점을 0으로 가정하면 편리하다.

이를 일반화하면,
> print(scc_id[v] < scc_id[-v])

## 구현
`코사라주 알고리즘`, `타잔 알고리즘` 중 1개를 선택해서 SCC를 구하면 된다.
```
N = 변수 개수
1. 그래프 입력
	- 정점 개수 = N * 2
		- ￢A의 번호 = A + N
	- 절 입력 A ∨ B
		- 간선 (￢A → B), (A → ￢B) 추가
2. SCC 구하기
3. SAT 판단
	- A, ￢A가 같은 SCC에 속하는 경우가 있으면 unsatisfiable
```

## 코드
`BOJ - 11281 - 2-SAT - 4` 코드
```
#include <iostream>
#include <vector>
#include <stack>
#define SIZE 20002
using namespace std;
int N, M;
int Did[SIZE];
int scc_id[SIZE];
vector<int> graph[SIZE];
stack<int> stk;
int Did_idx = 0, scc_idx = 1;

int DFS(int v) {
	Did[v] = ++Did_idx;
	stk.push(v);
	int minGoal = Did[v];

	int len = graph[v].size();
	for (int i = 0; i < len; i++) {
		int next = graph[v][i];
		if (Did[next] == 0) minGoal = min(minGoal, DFS(next));
		else if (scc_id[next] == 0) minGoal = min(minGoal, Did[next]);
	}

	if (minGoal == Did[v]) {
		int t;
		do {
			t = stk.top();
			scc_id[t] = scc_idx;
			stk.pop();
		} while (t != v);
		scc_idx++;
	}
	return minGoal;
}

void Tarjan() {
	for (int v = 1; v <= N * 2; v++)
		if (Did[v] == 0)
			DFS(v);
}

void SAT2() {
	Tarjan();
	for (int v = 1; v <= N; v++) {
		if (scc_id[v] == scc_id[v + N]) {
			cout << "0\n";
			return;
		}
	}

	cout << "1\n";
	for (int v = 1; v <= N; v++)
		cout << (scc_id[v] < scc_id[v + N]) << " ";
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b, ia, ib;
		cin >> a >> b;

		a = (a > 0) ? a : N - a;
		b = (b > 0) ? b : N - b;
		ia = (a > N) ? a - N : a + N;
		ib = (b > N) ? b - N : b + N;
		graph[ia].push_back(b);
		graph[ib].push_back(a);
	}
	SAT2();
	return 0;
}
```

## 관련 문제
https://www.acmicpc.net/problem/11280
https://www.acmicpc.net/problem/11281
https://www.acmicpc.net/problem/3648

## 참고
https://www.geeksforgeeks.org/2-satisfiability-2-sat-problem/
https://devbelly.tistory.com/55

