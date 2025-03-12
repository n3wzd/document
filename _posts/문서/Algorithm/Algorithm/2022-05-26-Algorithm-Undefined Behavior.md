---
categories:
- Algorithm
date: '2022-05-26'
title: '[Algorithm] Undefined Behavior'
---

{% raw %}
## Undefined Behavior
기본적으로 C++ 컴파일러는 겉에서 보기에 행동이나 결과(observable behavior)가 동일하다면, 코드의 로직을 변경하여 컴파일할 수 있다. 그러나 몇몇 경우에선 표준이 observable behavior를 정의하지 않았거나, 구현체에게 맡기기도 한다. undefined behavior가 이에 속한다.

undefined behavior는 어떤 결과가 나올지 정의되어 있지 않은 코드를 의미한다. 이 코드의 출력은 컴파일러 상황에 따라 다를 수 있다. 운이 좋으면 의도한 방향으로 그냥 컴파일이 될 수 있지만, 아니면 조용히 내부적으로 계산이 잘못 되어가고 있을 수도 있고, 이는 단순한 오답부터 컴파일 에러까지 알 수 없는 결과로 이어질 수 있다.

C++를 사용할 때는 undefined behavior를 주의해야 한다. 이는 대체로 사소한 요인이면서, 컴파일 에러로 잡히지 않기 때문에, undefined behavior으로 문제가 발생하면 디버깅, 문제 원인 추적이 크게 어려워진다.

## 관련 사례
이하 관련 오류를 제출하면 '틀렸습니다', '컴파일 에러', '런타임 에러'가 모두 뜰 수 있다.

#### 오버플로우?
- 충분히 큰 수를 활용하는 계산에는 오버플로우가 발생할 수 있다. 이는 컴파일 에러로 감지되지 않는다.
- 단일 값이 오버플로우일 수도 있지만, 합이나 곱을 할 때 오버플로우가 발생할 수도 있다. (ex. 총합을 저장하는 변수)

> int보다 더 넓은 범위를 표현하는 long long 사용한다<br>

#### 범위를 벗어난 배열 접근?
- 범위를 벗어난 위치에 접근하면 컴파일 에러로 처리되지 않고 접근/쓰기가 가능하며, 운이 좋으면 정상 동작이 되기도 한다!
- 음수 방향으로 벗어나는 것은 간혹 컴파일러가 잡아내기도 한다. 그러나 양수 방향은 잘 안 잡기 때문에 특히 주의해야 한다.
	- Visual Studio일 경우, 일정 범위의 양수 방향 초과는 잡지 않으며, 접근/쓰기도 정상 동작할 수 있다.
- 참고로 초기화하지 않은 전역변수(배열 포함)는 자동으로 0으로 초기화된다. 이로 인해 배열 범위 초과를 정상 작동으로 착각할 수 있으니 조심해야 한다.
> 배열을 접근할 때는 항상 범위를 초과하지 않는지 확인한다<br>

#### 명시적인 #include 선언?
- Visual Studio에서는 명시적으로 헤더를 선언하지 않아도 해당 함수, 내용이 있다면 자동으로 찾아서 컴파일하는 기능이 있는 것으로 추정된다. 따라서 컴파일 에러가 없고, 정상적으로 동작도 된다! 하지만 몇몇 컴파일러는 존재하지 않는다고 오류를 띄울 수도 있기 때문에 주의해야 한다.
- ex. <limits.h>의 매크로 상수 ‘INT_MAX’, <algorithm.h>의 sort, <memory.h>의 memset 등등
> 라이브러리 함수를 사용한다면 관련 #include 선언을 한다<br>

#### 함수의 조건부 반환(return)
```
int Func(int n)
{
	if (n == 1) return 1;
	Func(n - 1);
}
```
다음 구문은 VS에서 컴파일이 되며, 동작도 정상적으로 된다! 그러나 gcc에선 런타임 에러(WithoutReturning)로 잡힌다.
참고 - <br>https://developercommunity.visualstudio.com/t/compiler-does-not-report-error-when-no-return-valu/792888

## Sequence Point
- sequence point는 모든 식의 평가(계산)이 완료되는 지점이다.
- 대표적인 sequence point는 `; || && ,?:`
- `=`은 sequence point가 아니다.
- sequence point 사이에서 식의 값은 최대 한 번만 수정되어야 한다. 이 규칙을 위반한 구문은 undefined behavior이다.
- sequence point 사이의 연산은 순서가 보장된다. 그렇지 않은 연산자는 순서를 보장할 수 없다.
	- ex. F() + G()에서 +는 sequence point가 아니므로 F()가 먼저 실행될 지, G()가 먼저 실행될지 알 수 없다. 단, F(), G()는 항상 F() 다음으로 G()가 실행된다.
- 대표 ex. `i = i++;`
	- ; 아래에서 i의 수정이 2번 발생하므로 undefined behavior에 해당
	- 컴파일러에 따라 `(i = i)++;` or `i = (i++);` 2가지로 해석될 수 있다.
	- `i = i, i++;` or `i++, i = i;`같이 순서를 명확하게 표현해야 한다.
> 확실한 연산의 순서가 필요하면, 순서를 명시적으로 표현한다<br>

### 참고
<br>https://dojang.io/mod/page/view.php?id=757
<br>https://knowledgeforengineers.tistory.com/114?category=916186

## 그럼 제출해야만 에러를 알 수 있나요?
> 아닙니다. 채점 도움말을 보시면 채점 환경과 컴파일 옵션을 확인할 수 있습니다. 이와 비슷한 환경에서 실행하시면 채점할 때 어떤 오류가 나올 지 미리 확인할 수 있습니다.<br>

컴파일러가 달라서 발생하는 오류라면, 컴파일러를 같게 하면 해결할 수 있다.

가장 정확한 방법은 직접 gcc를 사용하고 환경을 비슷하게 셋팅하는 것이지만 불편하다는 치명적인(?) 문제점이 있다.

따라서 온라인 컴파일러를 활용하자. 구글신에 검색하면 여러 컴파일러 사이트를 확인할 수 있다.
- [OnlineGDB](<br>https://www.onlinegdb.com/online_c++_compiler)
- [ideone.com](<br>http://ideone.com/)

제출하기 전에 온라인 컴파일러로 확인해서 사소한 이유로 받는 '틀렸습니다', '컴파일 에러', '런타임 에러'를 피해보자!

## 참고
Undefined behavior란? - <br>https://www.secmem.org/blog/2020/01/17/c-c++-and-ub/
컴파일 에러가 나시나요? - <br>https://www.acmicpc.net/blog/view/52
{% endraw %}