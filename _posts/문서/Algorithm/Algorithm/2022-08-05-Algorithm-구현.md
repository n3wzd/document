---
categories:
- Algorithm
date: '2022-08-05'
title: '[Algorithm] 구현'
---

{% raw %}
## 구현
가장 간단하면서 가장 중요한 요소입니다.

※ PS = Problem Solving

### 개행 규칙
반드시 통용되는 것이 아닌 개발자의 마음대로 결정하면 됩니다. 필자는 아래의 규칙을 따릅니다.

1. 2구문 이상인 경우는 { }로 묶습니다. { } 규칙은 아래 예시와 같습니다.
2. 1구문은 { }를 생략합니다.
	- 구문이 충분히 짧다면 개행을 넣지 않고, 그 외는 개행을 넣습니다.

```
if(A)
	a = b + c - d;
if(B) {
	POO();
	print("Hello world!");
}
while( ... ) a++;
```

3. 간단한 구조체나 함수의 { }는 한줄로 통일할 수 있다면 통일합니다.
```
struct Node { int num, id; };
int Add(int a, int b) { return a + b; };
```

### 변수/프로퍼티 이름 선정
1. 한눈에 봐서 기능/역할을 파악할 수 있어야 합니다.
2. 가능한 타이핑하기 쉽게 짧은 것으로 합니다.

변수의 중요성, 등장 빈도에 따라 위의 2가지 기준을 적절히 절충합니다.

3. 상수는 ALL 대문자로 합니다.
4. 클래스/구조체의 명칭은 첫 글자를 대문자로 합니다.
```
const int SIZE = 100;
int N, M, K, tmp;
int arr[SIZE];
struct Point { int x, y; }
```

### 함수/메서드 이름 선정
프로퍼티와 동일합니다. 하지만 프로퍼티/메서드간 이름 중복은 불가능하므로 따로 구분할 수 있도록 규칙을 세워줍니다.

주로 프로퍼티는 첫 글자를 소문자, 메서드는 첫 글자를 대문자로 해서 구분합니다.
```
int Find() { ... }
void Search() { ... }
```

### const
const로 선언된 변수는 변경할 수 없습니다. 상수를 정의할 때 유용합니다.

### 변수 관련
- 무언가를 기록할 필요가 있거나 변경될 가능성이 있다면 변수를 생성합시다.
	- 엄청 큰 배열이 아닌 이상 변수 생성의 패널티는 거의 없습니다.
	- 나중에 값을 수정할 때는 변수 선언값 1가지만 바꾸면 되니 편리합니다.
- 변수의 역할은 항상 1개만 담당하는 것이 좋습니다. (여러 역할을 부여하면 나중에 코드 분석할 때 헷갈릴 수 있습니다)

### 함수
입력과 출력이 있는 함수입니다. 자주 반복되는 작업은 함수로 분리하는 것을 추천합니다. (추후 기능 수정을 할때는 함수 부분만 작업하면 되므로 편리합니다)

call by value/reference를 구분합시다. 전자는 파라미터를 통째로 복사하며, 후자는 파라미터의 주소값으로 전달합니다. call by reference는 함수 바깥에서 제공한 파라미터 변수를 함수 내에서 수정할 수 있습니다. 전달값 변경/최적화 관점에서 적절한 것을 선택하는 것이 좋습니다.

### 구조체 vs 클래스
사용자 정의 자료구조는 객체를 정의해서 다룰 수 있습니다. C++에선 구조체와 클래스가 있으며, 이 둘의 차이는 **접근제어 지시자 유무** 입니다. (접근제어 지시자: public, private...)

주로 편의성을 추구하는 PS에선 구조체, 정보은닉이 필요한 개발 프로젝트는 클래스를 사용합니다.

※ 구조체의 인스턴스 간편 생성은 { }으로 할 수 있습니다.
```
Node node = { 2, 4 };
```

### 반복되는 코드
일련의 규칙으로 반복되는 코드는 변수+반복문으로 코드를 정리할 수 있습니다.

가장 대표적인 사례는 2D 격자에서 인접한 상하좌우를 방문하는 작업입니다.
```
Next(x + 1, y);
Next(x - 1, y);
Next(x, y + 1);
Next(x, y - 1);
```

이는 아래와 같이 정리할 수 있습니다.
```
int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};
for(int d = 0; d < 4; d++)
	Next(x + dx[d], y + dy[d]);
```

### 입출력
PS에서 입출력 파일은 구분됩니다. 프로그램에서 입출력을 따로 구분하지 않아도 됩니다. ("입력이 모두 완료된 후 출력" 순서를 지키지 않아도 됩니다)

입출력은 느리므로 빠른 입출력을 항상 적용합시다. C++일 경우, 다음 구문을 메인함수 시작에 추가하고 개행에선 endl 대신 개행문자 "\n"를 사용하면 됩니
```
ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
```
※ 주의사항: 이 구문 이후에는 printf, scanf를 사용할 수 없습니다.

### 반복문
#### while
기본적인 반복문입니다. 코드를 간결하게 표현하거나 종료 조건이 불분명할 때 주로 사용됩니다. (ex. 특정 상태에 도달, 자료 구조의 상태, 사용자 입력 등등...)

사용할 때는 탈출 조건을 항상 명시해줍시다.

#### do~while
구문을 먼저 실행하고 조건을 확인합니다. 자주 쓰이지 않고 필수도 아니지만, 특정 상황에서 사용하면 편리할 때가 있습니다.

#### for
while과 함께 보편적인 반복문입니다. 선언, 탈출 조건, 매 회차마다 실행되는 구문을 간편하게 설정할 수 있습니다.

선언, 회차 구문에는 ,를 사용해서 복수의 구문을 넣어줄 수 있습니다. 또한 아무 구문을 넣지 않는 것도 가능합니다.
```
for(int i = 0, w = 1; i < 5 && w < 5; i++, w++)
for( ; ; )
```

#### break
break는 현재 루프를 즉시 탈출합니다. 무한 루프를 종료하거나 루프를 즉시 빠져나와야 할 때 사용됩니다.

#### continue
continue는 현재 루프의 조건문으로 점프하는 구문입니다. 조건에 의해 밑의 구문을 생략하고 싶을 때 사용하는 편입니다.

continue를 사용해서 코드를 정리할 수 있습니다. (중괄호 생략)
```
while( ... )
	if(A)
	{
		( 실행 )
	}
```

```
while( ... )
	if(!A)
		continue
	( 실행 )
```

#### 반복자 인덱스
변수와 동일한 규칙이 적용되나 주로 인덱스로 사용되기 때문에 1-2글자같이 짧은 것을 쓰는 편입니다.

자주 쓰이는 이름: i, j, n, k, w, d, ...
리미트 변수의 소문자를 쓰는 것도 좋습니다.

※ 코드 폰트에 따라 i와 j가 시각적으로 잘 구분되지 않을 수 있습니다. 이때는 가급적 혼용을 피하시는 것을 권장합니다.

### 조건문
#### if
가장 보편적이고 자주 쓰이는 조건문입니다.

#### switch
case work에 특화된 조건문입니다. case work를 더 시각적으로 간결하게 표현할 수 있습니다.

필수는 아니고 if로 대체 가능합니다. 개발자 취향에 맞게 사용하면 됩니다. 개인적으로 타이핑할게 많아서 switch는 잘 안 쓰는 편입니다.

### 연산자
연산자 우선순위를 주의합시다. 확신이 안서면 항상 괄호를 사용합시다.

#### 대입 연산자
=는 대입한 값을 반환합니다. 따라서 아래와 같이 사용할 수 있습니다.
```
A = B = 10
```

참고로 대입 연산자의 우선순위는 , 다음으로 가장 낮습니다.

#### 조건 연산자
&&, ||를 사용해서 각각 and, or로 연결할 수 있습니다.

#### 비트 연산자
비트 단위 연산을 하면 boolean 배열을 정수로 변환할 수 있고 2의 거듭제곱을 다룰 때도 편리합니다.

- &, |, ^: 각각 and, or, xor을 수행합니다.
- >>, <<: shift 연산입니다. shift 방향은 연산자가 표현하는 방향과 같습니다.

#### 첨가 연산자
,를 사용해서 구문을 이을 수 있습니다. 구문 종료는 아니므로 ,으로 연결된 구문은 1개의 구문으로 취급됩니다.

```
int a, b;
if(A)
	a =3, b = 4;
```

#### ;
한 줄에 ;로 끝나는 여러 구문을 넣을 수 있습니다.
```
int a = q.top(); q.pop;
```

### 포인터
주소 값을 저장합니다. 주로 call by reference에서 사용됩니다.

배열의 본질은 포인터입니다.

### 문자열
C++에선 string 클래스를 사용하는 것을 추천합니다.

### STL 자료구조/알고리즘
C++ STL에선 동적 배열, 스택, 큐, 덱, 우선순위 큐, 집합(set, map), 정렬, 이분 탐색 등을 기본적으로 제공합니다. 직접 구현하는 것보다 편리하고 성능도 좋습니다. (단, PS에선 필요에 따라 직접 구현해서 사용할 때도 있습니다)

### 10<sup>k</sup> 표기
e 표기로 정리할 수 있습니다. (Tip. k = 0의 개수)
```
1000000 = 1e6
```

### typedef
명칭을 재정의합니다. 타이핑 편의성을 위해 긴 명칭을 간략화할 때 사용합니다.
```
typedef long long ll
typedef double dd
typedef pair<int, int> pi
``` 

### include
라이브러리를 사용한다면 항상 헤더 파일을 포함합시다.

Tip. gcc일 경우 아래 라이브러리를 사용하면 편리합니다. (여러 주요 라이브러리를 포함합니다)
```
#include <bits/stdc++.h>
```

### auto
auto는 자료형을 컴파일러가 추론하도록 하는 키워드입니다. 즉, 자료형을 자동으로 설정합니다.

아래 예시에서 num은 int, str는 string으로 자료형이 설정됩니다.
```
auto num = 123;
auto str = "ThisIsString";
```

반복문에서도 사용할 수 있습니다. 반복자를 다룰 때 편리합니다.
```
struct Data { string name; int num; };
vector<Data> list;

// list의 모든 값 탐색 1
for (auto d : list) {
	// d는 list[i]가 복사된 값입니다.
}

// list의 모든 값 탐색 2
for (auto& d : list) {
	// d는 list[i]의 참조자입니다.
}
```

### 주석
코드를 설명하는 글입니다. 나중에 코드를 다시 확인하기 위해 적절한 설명을 붙여 줍시다.

주석의 길이는 간단명료한 것이 좋습니다. 생략이 많으면 이해가 어렵고, 내용이 길면 코드 가독성을 해치니 적정 분량으로 작성하는 것이 좋습니다.

### 격자판 바깥?
2D 격자판을 탐색할 때는 현재 위치가 격자판 바깥을 나가는 경우를 주의해야 합니다. (인덱스 참조 에러가 발생할 수 있음)
탐색하기 전에 경계 바깥에 나간 것을 찬정해야 하며, 크게 2가지 방법으로 핸들링할 수 있습니다.

1. 조건문으로 처리 - 가장 보편적인 방법입니다.
```
if(board[nx] < 0 || board[nx] >= N || board[ny] < 0 || board[ny] >= N)
	continue;
```
2. 경계 부분에 빈 공간 할당
격자 경계에는 빈 공간을 채우고 [1x1, NxN]을 탐색하는 방법입니다.
조건문을 사용하지 않아 편리하지만 상황에 따라 사용이 어려울 수 있습니다.

### 실수 표현
현대 컴퓨터에선 실수를 `Floating Point`로 표현하므로 실수에는 미세한 오차가 존재할 수 있습니다.
따라서 정수로 대체할 수 있다면 가급적 실수 사용은 피하고 정수를 활용하는 것이 좋습니다. (대표적인 예시가 정수만으로 방향을 판정하는 `CCW`가 있습니다.)

### 실수 동등 비교
`Floating Point` 오차로 인해 실수는 동등 연산자(==)로 비교를 할 수 없으며, 두 수의 차이를 활용해서 비교해야 합니다.
```
const double EPS = 1e-6; // 오차 허용 범위
bool Equal(double a, double b) { // a, b가 대략 같으면 true 반환
	return abs(a - b) < EPS;
}
```

### 2차원 배열 구조?
동일한 공간 크기를 사용할 때, 배열의 1번째 인덱스의 길이를 작게 하는 것이 시간 측면에서 유리합니다. (메모리하고 관련이 있어 컴파일러마다 다를 수 있습니다)
```
(N = 200000, K = 200)일 때,
배열을 [N][K]가 아닌 [K][N] 순서대로 설정해야 더 빠릅니다.
```
드물지만 시간 초과 유무에 영향을 주기도 합니다. 따라서 2차원 배열을 생성할 때는 가급적 작은 변수를 1번째 인덱스로 하는 것이 좋습니다.

예시 - <br>https://www.acmicpc.net/problem/10067


### unsigned int vs 모듈러 연산
간혹 값이 충분히 커질 수 있어 2<sup>32</sup>로 나눈 나머지를 저장해야 할 필요가 있습니다. 모듈러 연산으로 구현할 수도 있지만, `unsigned int`로 저장하면 오버플로우로 인해 자동으로 2<sup>32</sup>의 나머지를 유지하게 됩니다.
{% endraw %}