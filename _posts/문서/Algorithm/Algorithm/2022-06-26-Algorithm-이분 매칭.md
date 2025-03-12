---
categories:
- Algorithm
date: '2022-06-26'
title: '[Algorithm] 이분 매칭'
---

{% raw %}
## 이분 매칭 (Maximum Bipartite Matching)
이분 그래프(Bipartite Graph)는 모든 정점을 2개의 집합으로 나눌 때 임의의 정점이 모든 인접한 정점하고 다른 집합에 속하는 그래프이다. 두 집합을 X, Y라고 했을 때 이분 그래프에서 `이분 매칭(Bipartite Matching)`은 X의 정점을 인접한 Y의 정점과 가능한 최대로 1대1 매칭하는 과정이다. 이분 매칭을 수행하면 최대 매칭 수를 알 수 있다. 

매칭은 X의 정점 1개가 Y의 인접한 정점 1개을 점유한 상태를 의미한다. 1개의 정점이 여러 개의 정점을 점유할 수 없다.
```
 X   →   Y
 1       a
 2       b
 3       c
 4       d
 5       e
```

이분 매칭은 `최대 유량(Network Flow)` 문제로 모델링할 수 있다. X의 모든 정점을 source, Y의 모든 정점을 sink에 연결하고 모든 간선의 용량을 1로 한 그래프에서 최대 유량 알고리즘을 수행하면 된다. 이때 최대 유량은 이분 매칭의 결과하고 동일하다.
```
> 간선의 방향: soruce → X → Y → sink<br>
          X   →   Y
          1       a
          2       b
soruce    3       c    sink
          4       d
          5       e
```

## 설계
최대 유량 알고리즘을 그대로 적용해도 답은 구할 수 있으나, 최대 유량 알고리즘은 일반적인 케이스를 다루기 때문에 시간 복잡도가 상대적으로 큰 편이다. 이분 매칭은 최대 유량 문제 중에서 간선이 모두 1이며 정점들이 2개의 집합으로 나뉜 특수한 상황이므로, 주로 `포드-풀커슨 알고리즘`을 이분 매칭에 맞게 최적화한 별도의 알고리즘을 사용한다.

```
- X = source에 연결된 정점 집합
- Y = sink에 연결된 정점 집합

> 전체<br>
1. 이분 그래프를 생성한다.
	- 이때 두 집합의 정점 번호는 서로 별개이다.
	- ex. X의 1번 정점과 Y의 1번 정점은 서로 다르다.
2. X의 모든 정점 탐색 => 현재 정점 = x<br>
	- Y에 대한 방문 기록을 초기화한다.
	- 시작점이 x인 DFS 수행
		- DFS의 출력이 1이면 전체 매칭 수에 1을 더한다.
3. 전체 매칭 수 출력
```
```
x = 현재 정점
matching[MAX] = X, Y 매칭 정보 배열
	- 인덱스: Y의 정점 번호, 값: X의 정점 번호
	- 매칭이 없다면 X의 정점 번호가 아닌 다른 값 배정 (주로 0 or -1로 한다)

> DFS(x)<br>
1. x의 방문 안된 Y의 인접 정점들을 조사한다. => 인접 정점 = y<br>
	1. y의 방문 표시 활성
	2. y가 매칭되지 않았다면 x-y 매칭 기록
		- 1을 반환하고 종료
	3. 매칭이 있다면 이미 매칭된 X의 정점이 다른 Y로 양보할 수 있는지 확인한다.
		- DFS(matching[y])이 1이면 양보 성공
			- x-y 매칭 기록하고 1 반환 및 종료
2. 매칭 실패 시 0 반환 및 종료
```

시간 복잡도는 O(VE)이다. (V = 정점 수, E = 간선 수)

## 코드
`BOJ - 11375 - 열혈강호` 코드
```
#include <iostream>
#include <vector>
#include <memory.h>
#define SIZE 1002
using namespace std;
int N, M;
vector<int> graph[SIZE];<br>
int matching[SIZE];
bool visited[SIZE];

bool DFS(int v) {
	for (int i = 0; i < graph[v].size(); i++) {
		int nv = graph[v][i];
		if (visited[nv]) continue;
		visited[nv] = 1;

		if (matching[nv] == 0 || DFS(matching[nv])) {
			matching[nv] = v;
			return 1;
		}
	}
	return 0;
}

int Bipartite() {
	int mat = 0;
	for (int v = 1; v <= N; v++) {
		memset(visited, 0, sizeof(visited));
		if (DFS(v)) mat++;
	}
	return mat;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;<br>
	for (int i = 1; i <= N; i++) {
		int len, work;
		cin >> len;<br>
		while (len--) {
			cin >> work;<br>
			graph[i].push_back(work);
		}
	}
	cout << Bipartite();
	return 0;
}
```

## 접근
일반적으로 이분 매칭을 활용한 문제는 주로 다음과 같은 패턴을 가진다.
1. 이분 그래프를 생성한다.
2. 이분 매칭의 최대 매칭이 답으로 직결된다.

이분 그래프를 모델링하는 것이 중요하다. 주로 정점들을 서로 인접하지 않는 2개의 집합으로 나누는 것이 일반적이다. 한 정점이 다른 정점하고 연결(매칭)되거나 영향을 준다면 간선으로 연결해준다. 만약 답과 계산에 영향을 주지 않는 정점이라면 그래프나 매칭에서 제외하면 된다.

이분 매칭의 본질은 최대 유량이므로 유량 관점으로도 볼 수 있다. 예를 들어 `BOJ - 11376 - 열혈강호 2`에서 최대 2번을 매칭하는 것은 source → 직원의 유량이 1에서 2로 늘어난 것과 같다. 이분 매칭 알고리즘은 유량 1 보내기를 수행하므로, 이분 매칭을 2번 실행하고 합산한 값을 출력하면 된다.

## 최소 정점 커버 (Minimum Vertex Cover)
어떤 정점 집합 S가 있을 때, 그래프의 모든 간선의 양 끝 정점 중 하나가 S에 포함되는 조건을 만족한다면 S를 정점 커버(Vertex Cover)라고 한다. `최소 정점 커버`는 정점 커버 중에서 크기(=정점의 개수)가 최소인 것이다.

쾨닉의 정리(König's Theorem)에 의하면 이분 그래프에서 최소 정점 커버의 크기는 이분 매칭의 최대 매칭 수하고 동일하다는 점이 알려져 있다.
> 이분 그래프의 최소 정점 커버 문제는 이분 매칭 문제로 바꿀 수 있다.<br>

## 최대 독립 집합 (Maximum Independent Set)
어떤 정점 집합 S가 있을 때, S의 모든 정점이 서로 인접하지 않는다면 S를 독립 집합(Independent Set)이라고 한다. `최대 독립 집합`는 독립 집합 중에서 크기(=정점의 개수)가 최대인 것이다.

그래프에서 최대 독립 집합은 `최소 정점 커버`의 여집합이라는 것이 알려져 있다.

이분 그래프에서 최소 정점 커버는 이분 매칭과 본질적으로 같으므로, 만약 이분 그래프라면 이분 매칭으로 최대 독립 집합을 구할 수 있다.
> 이분 그래프일 경우, 전체 정점 개수에서 이분 매칭의 최대 매칭 수를 빼면 최대 독립 집합의 크기를 알 수 있다. <br>

## 관련 문제
### 이분 매칭
https://www.acmicpc.net/problem/11375<br>
https://www.acmicpc.net/problem/11376<br>
https://www.acmicpc.net/problem/2188<br>
https://www.acmicpc.net/problem/1017<br>
https://www.acmicpc.net/problem/1671<br>

### 최소 정점 커버
https://www.acmicpc.net/problem/1867<br>

### 최대 독립 집합
https://www.acmicpc.net/problem/11014<br>

## 참고
https://yjg-lab.tistory.com/209<br>
https://www.crocus.co.kr/756<br>
https://khj94811.tistory.com/2<br>
{% endraw %}