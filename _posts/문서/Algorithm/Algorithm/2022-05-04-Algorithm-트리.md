---
categories:
- Algorithm
date: '2022-05-04'
title: '[Algorithm] 트리'
---

{% raw %}
## 트리
`트리`는 사이클이 없는 모든 노드가 연결된 그래프이다.

트리의 특징은 다음과 같으며, 모두 동치이다.
- G는 트리이다.
- G는 사이클이 없는 연결 그래프이다.
- G에서 간선을 추가할 경우 사이클이 생긴다.
- G는 연결 그래프이며, 어떤 간선을 제거하면 연결 그래프가 아니게 된다.
- G에서 임의의 두 정점을 잡았을 때, 1가지 경로만 존재한다.
- G의 정점 개수가 N일 때, 간선의 개수는 N-1이다.

## 트리의 구성
```
         5
   3           7
1     4     6     8
```
- 노드(node): 트리를 구성하는 기본 정점
    - 루트 노드(root node/root): 트리에서 부모가 없는 최상위 노드, 트리의 시작점.
    - 리프 노드(leaf node/leaf): 자식이 없는 노드. 단말 노드라 부르기도 한다.
    - 부모 노드(parent node): 현재 노드에서 루트 노드 방향으로 직접 연결된 노드.
    - 자식 노드(child node): 현재 노드에서 루트 노드 반대 방향으로 직접 연결된 노드 집합.
- 경로(path): 한 노드에서 다른 한 노드에 이르는 길 사이에 있는 노드들의 순서
- 길이(length): 출발 노드에서 도착 노드까지 거치는 간선의 개수
- 깊이(depth): 루트에서 어떤 노드에 도달하기 위해 거쳐야 하는 간선의 수
- 레벨(level): 루트 노드부터 어떤 노드까지 연결된 간선 수의 합. 루트의 레벨은 0이나 1로 설정하며, 0인 경우는 깊이하고 동일하다.
- 높이(height): 깊이의 최댓값
- 차수(degree): 현재 노드의 자식의 개수
- 트리의 차수(degree of tree): 트리의 최대 차수
- 서브 트리(subtree): 현재 노드의 자식 노드를 루트 노드라고 보았을 때, 이 작은 트리를 서브 트리라 한다. 서브 트리 역시 다른 서브 트리로 재귀적으로 구성되어 있다.

## 이진 트리(Binary Tree)
차수가 2인 트리. 이진 트리에서 각 노드는 최대 2개의 자식 노드를 가진다. 노드의 왼쪽 서브 트리를 Left, 오른쪽 서브 트리를 Right로 구분하기도 한다.

- 포화 이진 트리(Full Binary Tree): 모든 노드가 완전히 채워진 트리. 차수가 1인 노드가 존재하지 않는다.
- 완전 이진 트리(Complete Binary Tree): 마지막 레벨을 제외한 나머지 레벨에서 노드가 완전히 채워진 트리.
- 사향 트리(Skewed Binary Tree): 차수가 최대 1인 이진 트리. 편향 트리라고도 한다.

### 이진 트리의 특징
- 높이가  h인  포화 이진 트리의 노드 개수는  2<sup>h</sup>−1이다.
- 노드 개수가 N인 포화/완전 이진 트리의 높이는 Floor(log N)이다.
- 노드 개수가 N인 이진 트리의 높이 최댓값은 N이다. (= 사향 트리의 높이)

이진 트리를 효율적으로 활용하기 위해서는 높이가 작을수록 좋다.

## 트리의 순회
이진 트리에서 트리의 순회는 각각의 노드를 정확히 한 번만, 체계적인 방법으로 방문하는 과정이다. 방문하는 순서에 따라 전위 순회, 중위 순회, 후위 순회 3가지가 있다.
> 전위 순회(PreOrder Traversal): Root → Left → Right<br>
> 중위 순회(InOrder Traversal): Left → Root → Right<br>
> 후위 순회(PostOrder Traversal): Left → Right → Root<br>

`DFS`를 사용해서 3가지 모두 구현할 수 있다.
```
PreOrder(v)
	Print(v)
	PreOrder(Left(v))
	PreOrder(Right(v))

InOrder(v)
	InOrder(Left(v))
	Print(v)
	InOrder(Right(v))

PostOrder(v)
	PostOrder(Left(v))
	PostOrder(Right(v))
	Print(v)
```

## 트리 탐색 Tip
- 트리는 사이클이 없으므로 `DFS/BFS`로 탐색했을 때, 노드 방문 확인을 하지 않아도 된다.
	- 단, 인접 리스트로 트리를 표현한 경우, 구현상 양방향 간선이 추가되어 자식 노드가 부모 노드를 가리켜서 루프가 발생하는 문제가 있다.
	- 이때는 이전처럼 노드마다 방문 처리를 하거나, 이전 부모를 인자로 제공해서 이전 부모 노드로 향하는 간선만 탐색에서 제외하는 방법으로 해결할 수 있다.
- 트리에서 `DP`를 사용하는 경우, 일반적으로 서브 트리 단위로 문제를 분할한다. (부모-자식 노드 탐색)

## 관련 문제
https://www.acmicpc.net/problem/1991
https://www.acmicpc.net/problem/1967
https://www.acmicpc.net/problem/4803

## 참고
https://namu.wiki/w/%ED%8A%B8%EB%A6%AC(%EA%B7%B8%EB%9E%98%ED%94%84)
https://jiwondh.github.io/2017/10/15/tree/
{% endraw %}