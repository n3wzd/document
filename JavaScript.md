# JavaScript
자바스크립트(JavaScript)는 객체(object) 기반의 스크립트 언어다. 주로 웹 페이지 동작이나 서버 프로그래밍에 활용된다.

자바스크립트는 동적이며, 타입을 명시하지 않아도 되는 인터프리터 언어이며, 객체 지향 프로그래밍, 함수형 프로그래밍을 모두 표현할 수 있다.

컴파일 언어인 자바(Java)하고는 관련이 없다.

## 기본 (Basic)
- 실행문 끝에 세미콜론 `;`을 사용한다.
- 대소문자를 구분한다.
- `리터럴(literal)`: 값 그 자체
- `식별자(identifier)`: 어떤 변수/함수를 식별하는 이름
	- 식별자 가능 문자: 영문자, 숫자, 언더스코어`_`, `$`
- `키워드(keyword)/예약어(reserved word)`: 자바스크립트에서 특정 용도로 사용되는 미리 예약된 단어
	- var, function, class ...
	- 예약어는 식별자로 사용할 수 없다.

```
var num = 10;
var str = "JavaScript";

/* num, str는 식별자,
 * 10, "JavaScript"는 리터럴,
 * var는 예약어입니다. */
```

### 식별자 작성법
- `Camel Case`: 첫 단어는 전체 소문자, 이후 단어는 첫글자만 대문자 사용
- `Underscore Case`: 모든 단어는 소문자, 단어간 구분은 `_` 사용
- 관행적으로 Camel Case를 주로 사용한다.

```
var newSuperVar;   // Camel Case
var new_super_var; // Underscore Case
```

### 주석 (Comment)
- `//`, `/* */`를 사용해서 주석을 작성할 수 있다.

```
// 한 줄 주석
/* 여러 줄 주석 */
```

### 출력 (Print)
디버깅 등 용도로 자바스크립트의 결과를 바로 출력할 필요가 있다. 

- window.alert()
- innerHTML
- document.write()
- console.log()

#### window.alert()
- 브라우저의 대화 상자를 표시해서 출력을 확인할 수 있다.

```
var res = "출력할 값";
window.alert(res);
```

#### innerHTML
- HTML 요소의 내용을 변경해서 출력을 확인하는 방법

```
var res = "출력할 값";
document.getElementById("goal").innerHTML = res;
```

```
<p id="goal">여기에 결과가 출력됩니다.</p>
```

#### document.write()
- 웹 페이지에 새로운 데이터를 추가하여 출력을 확인하는 방법

```
var res = "출력할 값";
document.write(res);
```

#### console.log()
- 콘솔 화면에 출력하는 방법
- 디버깅 용도로 주로 사용된다

```
var res = "출력할 값";
console.log(res);
```

### 타입 (Type)
- `타입(type)`: 다룰 수 있는 값의 종류
- `기본 타입`: 자바스크립트에서 미리 정의한 타입. 원시 타입과 객체 타입으로 구분된다.

#### 원시 타입
- `숫자(number)`
- `문자열(string)`
- `불리언(boolean)`
- `심볼(symbol)`
- `undefined`

##### 숫자 (number)
- 정수, 실수를 모두 포함함
- e 표기법 사용 가능

```
-5    // 정수
12.5  // 실수
10e4  // 10000
10-4  // 0.0001
```

##### 문자열 (string)
- `"`, `'`을 감싸서 표현한다.
- 문자열 내에 `"`을 포함한다면 `'`을 사용하면 된다. (그 반대도 마찬가지)

```
"문자열 데이터 1"
'문자열 데이터 2'
"'인용'한 문자열 1"
'"인용'한 문자열 2'
```

##### 불리언 (boolean)
- true, false 2가지 값을 가질 수 있다.
- 조건 연산자의 반환 결과값으로 쓰인다.

```
true
false
```

##### 심볼 (symbol)
- ECMAScript6에 새로 추가된 타입
- 유일하고 변경할 수 없다.
- 식별자로 사용 가능하다.

```
Symbol("sym");
```

##### undefined vs null
- `undefiend`: '타입'이 정해지지 않음을 의미하는 타입
- `null`: '값'이 정해지지 않음을 의미하는 object 타입

|값|타입|
|---|---|
|undefiend|undefiend|
|null|object|

- 타입이 다르므로 동등 연산자(\=\=)와 일치 연산자(\=\=\=)의 값이 다르다.
```
null == undefiend   // true
null === unfefined  // false
```

#### 객체 타입
- `객체(object)`: 여러 프로퍼티(property), 메소드(method)를 묶은 일종의 집합체 타입

```
{ name: "object", id: 1 }
```

### 타입 변환
자바스크립트는 타입이 유연한 편이다.

#### 암시적 타입 변환 (implicit type conversion)
- 예상되는 타입의 값이 배치될 곳에 다른 타입의 값이 온다면, 자바스크립트가 자동으로 타입을 통일시킨다.
- 만약 암시적 타입 변환이 불가능하다면 오류가 발생한다.

```
var str = "10 + 5 = ";
var res = str + 15;
/* 15는 문자열로 변환됩니다. 따라서 res의 값은 "10 + 5 = 15"입니다. */
```

#### 명시적 타입 변환 (explicit type conversion)
- 자바스크립트에서 기본 제공하는 전역 함수 등으로 명시적으로 타입을 바꿀 수 있다.

##### to number
- Number(A)
- parseInt(A): A를 특정 진법의 정수로 변환
- parseFloat(A): A를 실수(float)로 변환

##### to string
- String(A)
- A.toString(): 단, A는 null, undefined가 아님

##### to boolean
- Boolean(A): A가 number 타입의 0이면 false, 그 외는 true 변환

##### to object
- Object(A): A를 사용해 객체를 생성

### 변수 (Variable)
- `변수(Variable)`: 데이터를 저장할 수 있는 메모리 공간
- 예약어 `var`를 사용해서 변수를 선언할 수 있다.
- 변수의 이름은 `식별자(identifier)`이다.
- 선언, 초기화는 동시에 할 수 있다.
- 쉼표`,` 연산자를 사용해서 동시 선언/초기화가 가능하다.
- 같은 변수에 다른 타입의 값을 대입할 수 있다.
- 재선언은 불가능하다.
- 초기화되지 않은 변수는  undefined 값을 갖는다.

```
var data;
var num = 12;
var item1 = "포션", item2 = "폭탄";
```

```
var num = 12;
num = "다른 타입의 값도 대입할 수 있습니다.";
```

### 수 표현
- 자바스크립트는 정수/실수를 구분하지 않고, 실수로 통일해서 사용한다.
- 자바스크립트는 실수를 `64bit 부동소수점(floating point)`으로 표현한다.
	- 소수 연산에서 정수부는 15자리, 소수부는 17자리까지만 정밀도를 보장한다.
- 자바스크립트는 기본적으로 10진법을 사용한다.
- `0x` 접두사를 사용하면 16진법으로 표현된다.

#### Infinity
- `Infinity`: 양의 무한대를 의미하는 number 값
- `-Infinity`: 음의 무한대를 의미하는 number 값
- 위 값들은 읽기 전용 값이며, 어떤 수보다도 큰 수로 취급된다.

```
var x = 10 / 0;               // Infinity
var y = Infinity * 10;        // Infinity
var z = 1 / Infinity;         // 0
console.log(typeof Infinity); // number
```

#### NaN
- `NaN`: 'Not a Number'의 약자로, 정의되지 않은 수를 의미하는 number 값
- 0을 0으로 나누거나, number 타입 변환이 불가능한 값으로 산술 연산을 시도하는 경우에 이 값이 반환된다.
- 읽기 전용 값이다.

```
var x = 100 - "10";      // 10
var y = 100 - "ten";     // NaN
var z = 0 / 0;           // NaN
console.log(typeof NaN); // number
```

#### null, undefined, NaN, Infinity

|값|타입|boolean|number|의미|
|---|---|---|---|---|
|null|object|false|0|값이 정해지지 않음|
|undefined|undefined|false|NaN|타입이 정해지지 않음|
|NaN|number|false|NaN|수가 아님|
|Infinity|number|true|Infinity|무한대|

### 문자열
- 자바스크립트에서 문자열은 `"`, `'`으로 표현된다.
- 한 종류의 따옴표를 사용하면 내부에 다른 종류의 따옴표를 넣을 수 있다.

> "string"
> 'string'
> "this is 'string'!"
> 'this is "string"!'

#### 문자열 결합
- `+` 연산자를 활용해서 문자열을 결합할 수 있다.

> "more " + "string!"

```
console.log("more " + "string!"); // more string!
```

#### 특수문자 표현
- 일부 예약된 문자는 문자열 내부에서 바로 표현할 수 없다.
- 이때는 문자 앞에 `\`를 붙이면 문자 그 자체로 인식이 되어 문제가 해결된다.

```
console.log("this is \"string\"!"); // this is "string"!
```

#### 이스케이프 시퀀스 (Escape Sequence)
- 이스케이프 시퀀스를 사용하면 더 다양한 문자를 표현할 수 있다.

1. 16진수 이스케이프 시퀀스 (`\x`)
2. 유니코드 이스케이프 시퀀스 (`\u`)

```
\xA2    // 16진수로 인식
\u00A2  // 유니코드로 인식
```

## 연산자 (Operator)

|우선순위|연산자|기능|결합 방향|
|---|---|---|---|
|1|()|묶음|-|
|2|.|멤버 접근|->|
||new|인수 있는 객체 생성|-|
|3|()|함수 호출|->|
||new|인수 없는 객체 생성|<-|
|4|++|후위 증가 연산자|-|
||--|후위 감수 연산자|-|
|5|!|논리 NOT 연산자|<-|
||~|비트 NOT 연산자|<-|
||+|양의 부호|<-|
||-|음의 부호|<-|
||++|전위 증가 연산자|<-|
||--|전위 감소 연산자|<-|
||typeof|타입 반환|<-|
||void|undefiend 반환|<-|
||delete|프로퍼티 제거|<-|
|6|\*\*|거듭제곱 연산자|<-|
||\*|곱하기 연산자|->|
||/|나누기 연산자|->|
||%|나머지 연산자|->|
|7|+|더하기 연산자|->|
||-|빼기 연산자|->|
|8|<<|left shift 연산자|->|
||>>|확장 있는 right shift 연산자|->|
||>>>|확장 없는 right shift 연산자|->|
|9|<|관계 연산자(보다 작은)|->|
||<=|관계 연산자(보다 같거나 작은)|->|
||>|관계 연산자(보다 큰)|->|
||>=|관계 연산자(보다 같거나 큰)|->|
||instanceof|인스턴스 여부 판단|->|
|10|\=\=|동등 연산자|->|
||\=\=\=|일치 연산자|->|
||!=|부등 연산자|->|
||!\=\=|불일치 연산자|->|
|11|&|비트 AND 연산자|->|
|12|^|비트 XOR 연산자|->|
|13|\||비트 OR 연산자|->|
|14|&&|논리 AND 연산자|->|
|15|\|\||논리 OR 연산자|->|
|16|?:|삼항 연산자|<-|
|17|=|대입 연산자|<-|
|18|...|전개|-|
|19|,|쉼표 연산자|->|

### 산술 연산자 (Arithmetic Operator)
- 피연산자를 산술적으로 계산하는 연산
- `+` 연산자는 피연산자로 문자열이 올 수 있다. (문자열 결합 수행)

|연산자|기능|
|---|---|
|+|더하기 연산자|
|-|빼기 연산자|
|\*|곱하기 연산자|
|/|나누기 연산자|
|%|나머지 연산자|
|\*\*|거듭제곱 연산자|

```
3 + 4;      // 7
"3" + "4";  // "34"
```

### 대입 연산자 (Assignment Operator)
- 변수에 값을 대입하는 연산

|연산자|기능|
|---|---|
|=|대입 연산자|
|+=|더하기 대입 연산자|
|-=|빼기 대입 연산자|
|\*=|곱하기 대입 연산자|
|/=|나누기 대입 연산자|
|%=|나머지 대입 연산자|
|\*\*=|거듭제곱 대입 연산자|

```
var num = 2;    // num = 2
num *= 4;       // num = 8
num %= 3;       // num = 2
num **= 3;      // num = 8
```

### 증감 연산자 (Increment and Decrement Operator)
- 전위 연산: 먼저 증감을 수행한 뒤, 다른 연산 수행
- 후위 연산: 다른 연산 수행한 뒤, 증감 수행

|연산자|기능|
|---|---|
|++x|전위 증가 연산자|
|x++|후위 증가 연산자|
|--x|전위 감소 연산자|
|x--|후위 감소 연산자|

```
var num = 5;
var res1 = ++num * 2;  // 라인 종료시, res1 = 12, num = 6
var res2 = num-- * 2;  // 라인 종료시, res2 = 12, num = 5
```

### 비교 연산자 (Comparison Operator)
- 비교 판정에 따라 boolean(true/false)를 반환한다.
- `==`: 값을 비교함 (타입이 다르면 타입을 통일시키고 비교)
- `===`: 값과 타입 모두를 비교함
- 피연산자가 number면, 수 크기로 비교
- 피연산자가 string이면, 사전순으로 비교 (앞에 있을수록 작음)

|연산자|기능|true 기준|
|---|---|---|
|\=\=|동등 연산자|두 피연산자의 값이 같음|
|\=\=\=|일치 연산자|두 피연산자의 값과 타입이 모두 같음|
|!=|부등 연산자|두 피연산자의 값이 다름|
|!\=\=|불일치 연산자|두 피연산자의 값이나 타입이 다름|
|<|관계 연산자(보다 작은)|왼쪽이 오른쪽보다 작음|
|<=|관계 연산자(보다 같거나 작은)|왼쪽이 오른쪽보다 같거나 작음|
|>|관계 연산자(보다 큰)|왼쪽이 오른쪽보다 큼|
|>=|관계 연산자(보다 같거나 큰)|왼쪽이 오른쪽보다 같거나 큼|

```
"abc" <= "abd";     // true
100 > 150;          // false
null == undefiend;  // true
null !== undefiend; // true
```

### 논리 연산자 (Logical Operator)
- 논리식 판정에 따라 boolean(true/false)를 반환한다.

|연산자|기능|true 기준|
|---|---|---|
|&&|논리 AND 연산자|두 피연산자가 모두 true|
|\|\||논리 OR 연산자|두 피연산자 중 하나라도 true|
|!|논리 NOT 연산자|피연산자가 false|

|A|B|A && B|A \|\| B|!A|
|---|---|---|---|---|
|true|true|true|true|false|
|true|false|false|true|false|
|false|true|false|true|true|
|false|false|false|false|true|

### 비트 연산자 (Bitwise Operator)
- 비트(bit) 단위로 논리 연산 수행

|연산자|기능|동작|
|---|---|---|
|&|비트 AND 연산자|비트가 모두 1이면 1 설정|
|\||비트 OR 연산자|비트가 하나라도 1이면 1 설정|
|^|비트 XOR 연산자|두 비트가 서로 다르면 1 설정|
|~|비트 NOT 연산자|비트를 반전시킴|
|<<|left shift 연산자|주어진 횟수만큼 비트를 왼쪽으로 이동시킴|
|>>|확장 있는 right shift 연산자|주어진 횟수만큼 비트를 오른쪽으로 이동시킴 (새로운 비트 = MSB)|
|>>>|확장 없는 right shift 연산자|주어진 횟수만큼 비트를 오른쪽으로 이동시킴 (새로운 비트 = 0)|

- ex. 12(00001100), 17(00010001), -12(11110100)

|연산|결과(수)|결과(비트)|
|---|---|---|
|12 & 17|0|00000000|
|12 \| 17|29|00011101|
|12 ^ 17|29|00011101|
|~12|-13|11110011|
|-12 << 2|-48|11010000|
|-12 >> 2|-3|11111101|
|12 >>> 2|3|00000011|

### 기타 연산자
#### 삼항 연산자 (Ternary Operator)
- 간단한 if / else문으로 활용할 수 있다.
- `condition`이 true면 `return1`이 반환되며, 그렇지 않으면 `return2`를 반환한다.

> `condition` ? `return1` : `return2`

```
3 < 5 ? "correct!" : "wrong!";   // "correct!" 반환
```

#### 쉼표 연산자
- 한 라인에 추가적인 구문을 넣을 수 있다.

```
var num1 = 0, num2 = 10;
for(var i = 0, j = 19; i <= j; i++, j--)
	num1 += 1, num2 += 1;
console.log(num1 + ", " + num2);
```

- 출력 결과
```
10, 20
```

#### delete
- 객체, 객체의 프로퍼티, 배열의 요소 등을 삭제한다.
- 삭제한 자리에는 undefiend로 설정된다.
- 배열 요소를 delete해도 배열 길이는 유지된다.
- 삭제 성공시 true, 삭제 실패시 false를 반환한다.

```
var obj = { name: "spongebob", job: "cook" };
if(delete obj.name)
	console.log(obj.name);

var list = [1, 2, 3];
if(delete list[1]);
	console.log(list);
```

- 출력 결과
```
undefined
[1, undefiend, 3]
```

#### typeof
- 피연산자의 타입의 이름 문자열을 반환한다.

|값|반환|
|---|---|
|수|"number"|
|문자열|"string"|
|true, false|"boolean"|
|함수|"function"|
|함수가 아닌 객체|"object"|
|undefiend|"undefiend"|
|null|"object"|
|NaN|"number"|

```
typeof 5            // number 타입
typeof "string"     // string 타입
typeof { a: 15 };   // object 타입
typeof undefined;   // undefiend 타입
typeof null;        // object 타입
typeof (typeof 5);  // string 타입
```

#### instanceof
- 피연산자가 특정 객체의 인스턴스인지를 판별한다.
- 맞으면 true, 아니면 false 반환

```
var str = new String("string");

str instanceof Object;  // true
str instanceof String;  // true
str instanceof Number;  // false
```

#### void
- 피연산자 무관하게 항상 undefiend를 반환한다.

```
void(0)  // undefiend
```

## 제어문 (Control Flow Statements)
- `제어문`: 프로그램의 순차적인 흐름을 제어할 때 사용되는 실행문

### 조건문 (Conditional Statements)
- `조건문`: 주어진 조건을 따라 별도의 명령을 수행하는 제어문

#### if
- `if`: 조건이 true면 주어진 실행문을 실행하는 조건문
- `else`: 이전 if가 실행되지 않으면, 여기가 실행된다.

> if(`condition1`) {
> 	(`condition1`가 true일 때 실행)
> }
> else if(`condition2`) {
> 	(`condition1`가 false, `condition2`가 true일 때 실행)
> }
> else {
> 	(`condition1`가 false, `condition2`가 false일 때 실행)
> }

```
var n1 = 3, n2 = 5;
if(n1 > n2)
	console.log("n1은 n2보다 큽니다.");
else if(n1 < n2)
	console.log("n1은 n2보다 작습니다.");
else
	console.log("n1은 n2하고 같습니다.");
```

- 출력 결과
```
n1은 n2보다 작습니다.
```

#### switch
- `switch`: 값을 기준으로 여러 case 분기로 나눈 조건문. 주어진 조건 값이 알맞은 case 값을 만족하면 그 위치로 jump하는 방식이다.
- `case` 내에 있는 `break`는 switch를 탈출하는 기능을 한다. 만약 break를 넣지 않으면 case 값과 관계없이 아래 실행문이 이어서 실행된다.
- 조건 값이 어떠한 case도 해당되지 않으면 `default`로 이동한다.
	- default 유무는 선택사항

> switch (`target`) {
> 	case `value1`:
> 		(`target` \=\= `value1`이면 여기로 이동함)
> 		break;
> 	case `value2`:
> 		(`target` \=\= `value2`이면 여기로 이동함)
> 		break;
> 	...
> 	default:
> 		(어떠한 case도 해당되지 않으면 여기로 이동함)
> 		break;
> }

- 예제 1
```
var n = 3;
switch(n) {
	case 1: console.log("n은 1입니다."); break;
	case 2: console.log("n은 2입니다."); break;
	case 3: console.log("n은 3입니다."); break;
	case 4: console.log("n은 4입니다."); break;
	case 5: console.log("n은 5입니다."); break;
	default: console.log("n은 [1, 5] 밖의 값입니다."); break;
}
```

- 출력 결과 1
```
n은 3입니다.
```

- 예제 2
```
var n = 3;
switch(n) {
	case 1: console.log("n은 1보다 같거나 큽니다.");
	case 2: console.log("n은 2보다 같거나 큽니다.");
	case 3: console.log("n은 3보다 같거나 큽니다.");
	case 4: console.log("n은 4보다 같거나 큽니다.");
	case 5: console.log("n은 5보다 같거나 큽니다.");
	default: console.log("끝!");
}
```

- 출력 결과 2
```
n은 3보다 같거나 큽니다.
n은 4보다 같거나 큽니다.
n은 5보다 같거나 큽니다.
끝!
```

### 반복문 (Iteration Statements)
- `반복문`: 같은 구간을 주어진 횟수만큼 반복 수행하는 제어문

#### while
- `while`: 주어진 조건이 false일 때까지 반복
	- 조건 검사를 먼저 수행한 뒤, 루프를 진행한다.

> while(`condition`) {
> 	(`condition`이 true면 실행)
> }

```
var i = 3;
while(i > 0)
	console.log(i--);
```

- 출력 결과
```
3
2
1
```

#### do / while
- `do / while`: while과 비슷하나, 루프를 실행한 뒤 조건을 검사한다.

> do {
> 	(`condition`이 true면 실행)
> } while(`condition`);

```
var i = 0;
do {
	console.log(i--);
} while(i > 0);
```

- 출력 결과
```
0
```

#### for
- `for`: 초기식, 조건식, 증감식을 가진 반복문

> for(`initial`; `condition`;  `incremental`) {
> 	(`condition`이 true면 실행)
> }

- 동작 순서
```
1. initial
2. condition 
	- true면 루프 진행
	- false면 루프 종료
3. 내부 실행문
4. incremental
5. 과정 2로 이동
```

```
for(var i = 0; i < 3; i++)
	console.log(i);
```

- 출력 결과
```
0
1
2
```

#### for / in
- `for / in`: 주어진 객체의 프로퍼티 인덱스를 열거하는 반복문
	- enumerable 플래그가 true인 프로퍼티만 순회한다

> for(`index` in `object`) {
> 	(`object`의 열거 가능한 프로퍼티 개수만큼 반복)
> }

- `index`: 루프마다 열거되는 `object`의 프로퍼티 인덱스 (string 값)

- 예제 1
```
var arr = [1, 2, 3];
for(i in arr)
	console.log(i);
```

- 출력 결과 1
```
0
1
2
```

- 예제 2
```
var obj = { name: "klee", id: 2 };
for(p in obj)
	console.log(p);
```

- 출력 결과 2
```
name
id
```

#### for / of
- `for / of`: 주어진 객체의 프로퍼티 값을 열거하는 반복문
	- 순회 가능한 객체(iterable objects)만 적용 가능하다. (ex. Array, Map, Set ...)

> for(`target` of `object`) {
> 	(`object`의 프로퍼티 개수만큼 반복)
> }

- `target`: 루프마다 열거되는 `object`의 프로퍼티 값

```
var arr = [1, 2, 3];
for(n of arr)
	console.log(n);
```

- 출력 결과
```
1
2
3
```

### 기타 제어문
#### label
- `label`: 특정 영역을 식별해주는 식별자

> `label`:
> (식별할 특정 영역)

```
loop:
for(n of arr)
	console.log(n);
```

#### continue
- `continue`: 현재 루프의 조건식으로 jump하는 조건문
- label을 통해 특정 루프를 지정할 수 있다.

> continue;
> continue `label`;

- 예제 1
```
for(var i = 1; i <= 5; i++) {
	if(i % 2 == 0)
		continue;
	console.log(i);
}
```

- 출력 결과 1
```
1
3
5
```

- 예제 2
```
loop1:
for(var i = 1; i <= 3; i++) {
	for(var j = 1; j <= 3; j++) {
		if(i - j < 0)
			continue loop1;
		console.log(i - j);
	}
}
```

- 출력 결과 2
```
0
1
0
2
1
0
```

#### break
- `break`: 현재 루프를 탈출하는 조건문
- label을 통해 특정 루프를 지정할 수 있다.

> break;
> break `label`;

- 예제 1
```
for(var i = 1; i <= 5; i++) {
	if(i == 4)
		break;
	console.log(i);
}
```

- 출력 결과 1
```
1
2
3
```

- 예제 2
```
loop1:
for(var i = 1; i <= 5; i++) {
	for(var j = 1; j <= 5; j++) {
		if(i * j > 5)
			break loop1;
		console.log(i * j);
	}
}
```

- 출력 결과 2
```
1
2
3
4
5
2
4
```

## 배열 (Array)
- `배열(array)`: 이름과 인덱스로 참조되는 정렬된 값의 집합
- `배열 요소(element)`: 배열을 구성하는 각각의 값
- `인덱스(index)`: 배열에서 위치를 가리키는 number
- 배열 요소의 타입은 고정되어 있지 않다.
	- 같은 배열에 있는 배열 요소라도 서로 타입이 다를 수 있다.
- 인덱스는 불연속적일 수 있다.
	- 일부 배열 요소가 undefiend일 수 있다.
- 자바스크립트에서 배열은 `Array 객체`로 다뤄진다.
- 배열의 길이는 `length` 프로퍼티에 저장되어 있다.
	- 배열의 길이가 변동되면 length도 자동으로 갱신된다.

### 사용법
#### 생성
- 배열을 생성하는 방법은 다음이 있다. (결과는 모무 동일)

> 1. var `arr` = \[`element1`, `element2`, ...\];
> 2. var `arr` = Array(`element1`, `element2`, ...);
> 3. var `arr` = new Array(`element1`, `element2`, ...);

```
var arr = [false, 1, "2", { n: 3 }, [4]];
```

#### 참조
- `[]`연산자를 활용해서 배열 요소를 참조할 수 있다.
- 인덱스의 범위는 \[0, 2^32^\)이다.
- 배열의 현재 길이보다 더 큰 인덱스에 배열 요소를 접근/저장하는 것이 가능하다.
	- 만약 값을 저장한다면, 배열의 길이는 해당 인덱스만큼 자동으로 연장된다.
- `홀(hole)`: 인덱스에 대응하는 배열 요소가 비어있는 부분
	- undefiend 값을 갖는다.

> `arr`\[`index`\]

```
var arr = [1, 2, 3];
console.log(arr[1]);

arr[4] = 5;
console.log(arr);
```

- 출력 결과
```
2
[1, 2, 3, undefiend, 5]
```

#### 추가
- 새로운 배열 요소를 추가하는 방법은 다음과 같다.
- `push` 메소드를 사용하면 배열 맨 끝에 추가된다.
- `index`를 사용하면 해당 인덱스에서 값이 변경/추가된다.

> 1. arr.push(`element`);
> 2. arr\[`index`\] = `element`;

#### 순회
- 반복문을 사용해서 모든 요소에 접근할 수 있다.
	- `for/ in`, `for / of`를 사용하면 간편하게 순회할 수 있다.

```
var arr = [1, 2, 3, 4, 5];
for(n of arr)
	console.log(n);
```

- 출력 결과
```
1
2
3
4
5
```

### 활용
#### 희소 배열
- `희소 배열`: 배열 요소가 불연속인 배열
	- 배열 요소의 개수 < length

```
var arr = [];
arr[2] = 0;
console.log(arr.length);
```

- 출력 결과
```
3
```

#### 다차원 배열
- `다차원 배열`: 배열 요소가 또 다른 배열인 배열

```
var arr = new Array(3);
for(var y = 0, n = 0; y < arr.length; y++) {
	arr[y] = new Array(4);
	for(var x = 0; x < arr[y].length; x++)
		arr[y][x] = ++n;
	console.log(arr[y]);
}
```

- 출력 결과
```
[1, 2, 3, 4]
[5, 6, 7, 8]
[9, 10, 11, 12]
```

####  문자열 배열
- 자바스크립트에서 문자열은 읽기 전용 배열로 다룰 수 있다.
- `[]` 연산자, Array 객체가 제공하는 메소드를 사용할 수 있다.
- 읽기 전용이므로 쓰기는 불가능하다.

```
var str = "JavaScript";
console.log(str[4]);
console.log(str.length);

str[4] = 'A'; // 반영되지 않습니다.
console.log(str);
```

- 출력 결과
```
S
10
JavaScript
```

#### 배열 여부 확인
- 자바스크립트에선 배열이라는 타입(type)이 없다.
	- Array 객체로 배열을 다루기 때문
	- typeof 연산자는 "object"를 반환한다.
- 대신, 다음과 같은 방법으로 배열을 판정할 수 있다.
	- true 반환시 `target`은 배열

> 1. Array.isArray(`target`);       // Array 메소드 사용
> 2. `target` instanceof Array    // instanceof 연산자 사용

```
var arr = [], str = "";
console.log(Array.isArray(arr));    // true
console.log(str instanceof Array);  // false
```
## 함수 (Function)
- `함수(function)`: 특정 목적의 단일 작업을 수행하도록 설계된 독립적인 블록
	- 필요할 때마다 호출하여 해당 작업을 수행할 수 있다.
- 자바스크립트에선 함수도 별개의 타입(type)으로 취급된다.
	- 함수를 변수에 대입하거나, 함수에 프로퍼티를 지정하는 것이 가능하다.
- 하나의 함수가 다른 함수 내에 중첩되어 정의될 수 있다.

### 사용법
#### 정의

> function `name`(_`param1`, `param2`, ..._) {
> 	(주어진 목적의 작업을 수행하는 실행문)
> 	_return `result`_
> }

- `name`: 함수의 이름 (=함수를 구분하는 식별자)
- `param`: 함수 내에서 활용될 수 있는 매개변수
- `result`: 함수가 반환(return)문을 포함할 경우, 함수가 반환하는 값
	- 반환문은 함수의 실행을 즉시 중단하고 주어진 값을 반환한다.
	- 반환값은 모든 타입이 올 수 있다.

```
function addNum(n1, n2) {
	return n1 + n2;
}
```

#### 호출
- 호출할 함수의 이름과 인자를 제공해서, 해당 함수를 호출할 수 있다.

> `name`(`argument1`, `argument2`, ...)

```
console.log(addNum(1, 2));  // 3
```

#### 값
- 자바스크립트에서 함수는 값으로 활용될 수 있다.
- 함수를 변수에 대입하거나, 다른 함수에 함수를 전달하는 것이 가능하다.

```
var func = addNum;
console.log(func(2, 4));  // 6
```

### 변수의 유효 범위 (Variable Scope)
- `변수의 유효 범위`: 해당 변수를 접근할 수 있는 변수, 객체, 함수의 집합

1. 지역 변수(local variable)
2. 전역 변수(global variable)

#### 지역 변수 (Local Variable)
- `지역 변수`: 함수 내에서 선언된 변수
- 지역 변수는 선언된 함수 내에서만 유효하며, 함수 종료시 메모리에서 사라진다.
- 함수의 매개변수도 해당 함수의 지역 변수에 속한다.

```
function genNum() {
	var num = 5;
	console.log(typeof num);
}
genNum();
console.log(typeof num);
```

- 출력 결과
```
number
undefined
```

#### 전역 변수 (Global Variable)
- `전역 변수`: 함수의 외부에서 선언된 변수
- 전역 변수는 어느 영역에서든 접근 가능하며, 프로그램이 종료되어야 메모리에서 사라진다.
- 전역 변수는 wndow 객체의 프로퍼티다.
- 자바스크립트에선 if, for 등 제어문 내부에서 선언된 변수는 전역 변수다.
	- 자바스크립트에선 유효 범위의 기준을 함수로 하기 때문
- var 키워드를 사용하지 않고 선언한 변수는 전역 변수다.
- 전역 변수와 지역 변수의 이름이 동일한 경우는, 지역 변수가 우선시된다.
	- 전역 변수를 사용하려면, window 객체의 프로퍼티임을 명시하면 된다.

- 예제 1
```
var num = 5;
function addNum() {
	num++;
}
for(var i = 0; i < 5; i++)
	addNum();
console.log(num + ", " + i);
```

- 출력 결과 1
```
10, 5
```

- 예제 2
```
var str = "global";
function func() {
	var str = "local";
	console.log(str);
	console.log(window.str);
}
func();
```

- 출력 결과 2
```
local
global
```

### 함수의 유효 범위 (Function Scope)
- `블록(block)`: `{}`로 묶인 부분
- 자바스크립트에선 유효 범위의 기준을 함수로 한다.
- 어떤 함수의 유효 범위 = 해당 함수의 블록 + 부모 함수의 유효 범위
	- 함수들의 체계는 트리 구조로 생각할 수 있다.
	- 전역은 루트 노드로 볼 수 있다.
	- 자식 함수의 블록은 유효 범위에 포함되지 않는다.
- 유효 범위 내에 선언된 변수와 함수만이 접근 가능하다.
- 유효 범위 밖은 접근 불가능하다.

```
// func의 유효 범위
 |  ...
 |  function otherFunc() {
       ...
    }	    
 |  ...
 |  function parentFunc() {
 |     ...
 |     function func() {
 |         ...
 |		   function childFunc() {
 		      ...
  		   }
 |		   ...
 |     }
 |     ...
 |  }
 |  ...
```

```
// 트리 구조 (함수 체계)
             global
	    /               \
    parentFunc      otherFunc
      /
    func
    /
childFunc
```

```
function func1() {
	var a = 1, b = 2;
	console.log(a + b);
}

function func2() {
	var a = 3, b = 4;
	function func2_2() {
		console.log(a + b);
	}
	func2_2();
}

func1();   // 3
func2();   // 7
console.log(a + b); // 오류 발생
```

#### 함수 호이스팅 (Hoisting)
- `함수 호이스팅`: 함수의 유효 범위의 적용이 변수 선언 이전에도 적용되는 자바스크립트의 특성
- 함수 내부의 모든 변수 선언이 해당 함수의 블록 맨 처음으로 이동한 것으로 생각할 수 있다.
- 함수 호이스팅으로 인해, 함수 블록 첫 부분에 변수를 선언하는 것이 좋다.

```
function main() {
	var n = 10;
	function sub() {
		console.log(n);   // 10?
		var n = 20;
		console.log(n);   // 20?
	}
	sub();
}
main();
```

- 위 예제는 자바스크립트 내부에서 함수 호이스팅에 의해 다음 예제처럼 변경되어 처리된다.
```
function main() {
	var n = 10;
	function sub() {
		var n;
		console.log(n);   // undefined
		n = 20;
		console.log(n);   // 20
	}
	sub();
}
main();
```

### 매개변수 (Parameter)
- `매개변수(parameter)`: 함수 정의에서 전달받은 인수를 함수 내부로 전달하기 위해 사용하는 변수
- `인수(argument)`: 함수 호출에서 함수로 전달되는 값

> function poo(`parameter1`, `parameter2`, ...) { ... }
> poo(`argument1`, `argument2`, ...);

- 함수 정의시, 매개변수의 타입을 명시하지 않는다.
- 함수 호출시, 인수의 타입을 검사하지 않는다.
- 자바스크립트에서 매개변수의 기본값은 undefined 값이다.
	- 함수 호출시, 제공한 인수의 개수가 정의된 매개변수의 개수보다 적다면, 나머지 매개변수에는 자동으로 undefined 값이 할당된다.

```
function printTriple(a, b, c) {
	console.log(a + ", " + b + ", " + c);
}
printTriple("Java", "Script");
```

- 출력 결과
```
Java, Script, undefined
```

#### arguments
- `arguments`: 함수에 전달된 인자를 배열 구조로 저장하는 객체
- n번째 인수 = arguments\[n - 1\]
- 인수의 개수 = arguments.length
- arguments 객체는 배열과 유사하지만 Array 객체가 아니다.
- arguments 객체를 사용하면 인자의 개수가 매개변수 개수보다 많은 상황을 유연하게 대처할 수 있다.

```
// 인자들의 총합을 구하는 함수 (인자 개수 제약 없음)
function addNum() {
	var sum = 0;
	for(n of arguments)
		sum += n;
	return sum;
}
console.log(addNum(1, 2));
console.log(addNum(1, 2, 3, 4, 5));
console.log(addNum());
```

- 출력 결과
```
3
15
0
```

#### 디폴트 매개변수 (Default Parameter)
- `디폴트 매개변수`: 함수 호출시, 명시된 매개변수에 인자가 제공되지 않은 경우에 사용할 기본값

> function `name`(`param`=`default`, ...) {
> 	...
> }

```
function mulNum(a, b=1) {
	return a * b;
}
console.log(mulNum(4, 5));   // 20
console.log(mulNum(4));      // 4
```

#### 나머지 매개변수 (Rest Parameter)
- `나머지 매개변수`: 앞에 명시된 개별 매개변수 외의 매개변수들을 묶은 매개변수 배열
- 생략 접두사(`...`)로 표현된다.

> function `name`(`param1`, `param2`, ... , ...`params`) {
> 	...
> }

```
function subNum(base, ...sub) {
	for(n of sub)
		base -= n;
	return base;
}
console.log(subNum(10, 1));
console.log(subNum(10, 1, 2, 3));
console.log(subNum(10));
```

- 출력 결과
```
9
4
10
```

### 미리 정의된 전역 함수 (Predefined Functions)
- 자바스크립트에서 편의성을 위해 여러 전역 함수를 미리 정의하여 제공한다.

|함수|반환|기능|
|---|---|---|
|eval(`string`)|실행 결과값|문자열로 표현된 자바스크립트 코드를 수행|
|isFinite(`number`)|boolean|전달된 값이 유한한 수면 true 반환|
|isNaN(`number`)|boolean|전달된 값이 NaN면 true 반환|
|parseFloat(`string`)|number|문자열을 파싱한 부동소수를 반환|
|parseInt(`string`, _`method`_)|number|문자열을 파싱한 정수를 반환|
|encodeURI(`uri`)|string|URI를 이스케이프 시퀸스 처리하여 부호화 (특수문자 제외)|
|encodeURIComponent(`uri`)|string|URI를 이스케이프 시퀸스 처리하여 부호화|
|decodeURI(`enc`)|string|encodeURI()로 부호화한 URI를 복호화|
|decodeURIComponent(`enc`)|string|encodeURIComponent()로 부호화한 URI를 복호화|
|Number(`value`)|number|주어진 값을 number 타입으로 변환|
|String(`value`)|string|주어진 값을 string 타입으로 변환|

#### eval()
- 문자열로 표현된 자바스크립트 코드를 수행한다.
- 코드에서 결과값이 존재하면 해당 값을 반환한다.

```
eval("var a = 10, b = 30");
console.log(eval("a * b"));   // 300
```

#### isFinite()
- 전달된 값이 유한한 수면 true를 반환한다.
- 전달된 값이 number가 아니면 number로 변환해서 검사한다.
	- 변환이 불가능하면 false 반환

```
isFinite(500);       // true
isFinite(true);      // true
isFinite(false);     // true
isFinite(null);      // true
isFinite("500");     // true
isFinite("");        // true

isFinite("오백");     // false
isFinite(undefined); // false
isFinite(NaN);       // false
```

#### isNaN()
- 전달된 값이 NaN면 true 반환한다.
- 전달된 값이 number가 아니면 number로 변환해서 검사한다.
	- 변환이 불가능하면 true 반환
- number 강제 변환이 불확실하기에 ECMAScript6부터는 Number.isNan() 사용이 권장된다.

```
isNaN(500);       // false
isNaN(true);      // false
isNaN(false);     // false
isNaN(null);      // false
isNaN("500");     // false
isNaN("");        // false

isNaN("오백");     // true
isNaN(undefined); // true
isNaN(NaN);       // true
```

#### parseFloat()
- 문자열을 파싱한 부동소수를 반환한다.
- 변환 실패시, NaN를 반환한다.

```
parseFloat("123");      // 123
parseFloat("123.45");   // 123.45
parseFloat("123.00");   // 123
parseFloat("123 45");   // 123
parseFloat(" 123 ");    // 123
parseFloat("123 abc");  // 123
parseFloat("abc 123");  // NaN
```

#### parseInt()
- 문자열을 파싱한 정수를 반환한다.
- 변환 실패시, NaN를 반환한다.
- 2번째 인자로 특정 진법을 전달하면, 주어진 문자열을 해당 진법으로 표현된 수로로 인식하고 변환을 수행한다.
- 문자열이 "0x"으로 시작하면 16진수로 변환을 수행한다.

```
parseInt("123");      // 123
parseInt("123.45");   // 123
parseInt("123.00");   // 123
parseInt("123 45");   // 123
parseInt(" 123 ");    // 123
parseInt("123 abc");  // 123
parseInt("abc 123");  // NaN

parseInt("10", 10);   // 10
parseInt("10", 8);    // 8
parseInt("10", 16);   // 16
parseInt("0x10");     // 16
```

#### encodeURI()
- URI를 이스케이프 시퀸스(escape sequences) 처리하여 부호화한다. (특수문자 제외)

```
var uri = "http://google.com/search.php?name=abc&word=검색";
console.log(encodeURI(uri));
```

- 출력 결과
```
http://google.com/search.php?name=abc&word=%EA%B2%80%EC%83%89
```

#### encodeURIComponent()
- URI의 모든 문자를 이스케이프 시퀸스 처리하여 부호화한다.

```
var uri = "http://google.com/search.php?name=abc&word=검색";
console.log(encodeURIComponent(uri));
```

- 출력 결과
```
http%3A%2F%2Fgoogle.com%2Fsearch.php%3Fname%3Dabc%26word%3D%EA%B2%80%EC%83%89
```

#### decodeURI()
- encodeURI()로 부호화한 URI를 복호화한다.

```
var uri = "http://google.com/search.php?name=abc&word=검색";
var enc = encodeURI(uri);
console.log(decodeURI(enc));
```

- 출력 결과
```
http://google.com/search.php?name=abc&word=검색
```

#### decodeURIComponent()
- encodeURIComponent()로 부호화한 URI를 복호화한다.

```
var uri = "http://google.com/search.php?name=abc&word=검색";
var enc = encodeURIComponent(uri);
console.log(decodeURIComponent(enc));
```

- 출력 결과
```
http://google.com/search.php?name=abc&word=검색
```

#### Number()
- 주어진 값을 number 타입으로 변환한다.
- 변환 실패시 NaN를 반환한다.

```
Number("123");       // 123
Number("123.00");    // 123
Number("123.45");    // 123.45
Number("12 34");     // NaN
Number("12 ab");     // NaN
Number(true);        // 1
Number(false);       // 0
Number(null);        // 0
```

#### String()
- 주어진 값을 string 타입으로 변환한다.

```
Number(123);        // "123"
Number(123.45");    // "123.45"
Number(true);       // "true"
Number(false);      // "false"
Number(null);       // "null"
```

## 객체 (Object)
- `객체(object)`: 프로퍼티의 정렬되지 않은 집합
- `프로퍼티(property)`: 이름(name)과 값(value)으로 구성된 객체 내 변수
- `메소드(method)`: 함수가 값인 프로퍼티
- 자바스크립트에선 number, string, boolean 등 원시 타입도 값이 정해진 객체로 취급된다.
- `객체 레퍼런스(object reference)`: 객체가 위치한 주소를 저장하는 변수
	- 자바스크립트에서 객체는 레퍼런스 형태로 변수에 담긴다.
	- 객체 레퍼런스의 값은 객체 그 자체가 아니라 객체가 메모리에 위치한 주소다.

### 생성 (Create)
- `인스턴스(instance)`: 생성된 객체
- 객체를 생성하는 방법은 다음이 있다.

1. 리터럴 표기(literal notation)
2. 생성자 함수(constructor function)
3. Object.create()

#### 리터럴 표기 (Literal Notation)
- 직접 객체의 프로퍼티를 작성해서 생성하는 방법.

> var `object` = {
> 	`property1`: `value1`,
> 	`property2`: `value2`,
> 	...
> };

```
var item = {
	hp: 100,
	mp: 50,
	effect: function() {
		console.log("LEVEL UP!!");
	}
};
```

#### 생성자 함수 (Constructor Function)
- `생성자 함수`: 객체를 생성할 때 사용되는 함수
- 모든 함수는 생성자가 될 수 있다.
- `new` 연산자: 생성자 함수를 통해 객체를 생성
- 자바스크립트에서 미리 정의된 생성자 함수(Object, Number, String 등)도 있고, 직접 생성자 함수를 작성할 수도 있다.

> new `Constructor`

```
var str = new String();
```

#### Object.create()
- Object의 create() 메소드로 객체를 생성할 수 있다.
- 프로토타입을 직접 설정할 수 있다.
- 2번째 인자로부터 프로퍼티를 추가할 수도 있으며, 추가할 프로퍼티의 속성도 같이 설정할 수 있다.

> Object.create(`prototype`, { `property1`: { value: `value1`, ... }, ... });

```
var item = Object.create(null, { 
		hp: { value: 100, enumerable:true }, 
		mp: { value: 50, enumerable:true }
	});
console.log(item.hp + ", " + item.mp); // 100, 50
```

### 프로퍼티 (Property)
#### 참조
- 프로퍼티를 참조하는 방법은 다음과 같다.

> `object`.`property`
> `object`\["`property`"\]

- 메소드를 호출하는 방법은 다음과 같다.

> `object`.`method`()

- 만약 `()`를 붙이지 않으면 프로퍼티로 취급되어, 함수 그 자체가 반환된다.

```
var item = {
	hp: 100,
	mp: 50,
	effect: function() {
		console.log("LEVEL UP!!");
	}
};

item.effect(); // LEVEL UP!!
console.log(item.hp + ", " + item.mp); // 200, 100
```

#### 삭제
- `delete` 키워드를 사용해서 객체의 프로퍼티 자체를 삭제할 수 있다.

> delete `object`.`property`

```
var item = {
	hp: 100,
	mp: 50
};

delete item.mp;
console.log(item.hp + ", " + item.mp); // 100, undefined
```

#### 순회
- 객체의 프로퍼티를 순회하는 방법은 다음이 있다.

1. for / in
2. Object의 keys() 메소드 사용
3. Object의 getOwnPropertyNames() 메소드 사용

```
var item = {
	hp: 100,
	mp: 50,
	exp: 25
};

for(i in item)
	console.log(i);
```

- 출력 결과
```
hp
mp
exp
```

#### this
- `this` 키워드는 해당 키워드가 위치한 코드 영역을 포함하는 객체를 가리킨다.
	- 간단히 말해, 자기 자신을 가리킨다.
- this를 사용해서 객체 내부에서 사용되는 프로퍼티임을 명시할 수 있다.

```
var item = {
	hp: 100,
	mp: 50,
	effect: function() {
		// this를 사용해서 프로퍼티임을 명시합니다.
		// this를 사용하지 않으면 함수 내 지역변수로 취급됩니다.
		this.hp += 100;
		this.mp += 50;
	}
};

item.effect();
console.log(item.hp + ", " + item.mp); // 200, 100
```

### 프로토타입 (Prototype)
- `상속(inheritance)`: 새로운 클래스에서 기존 클래스의 모든 프로퍼티와 메소드를 이어받는 것
	- 객체지향 프로그래밍에선 상속을 통해 클래스 간 종속 관계를 형성해서 객체의 관계를 조직화할 수 있다는 이점이 있다.
- 자바스크립트는 `프로토타입 기반(prototype-based)` 객체지향 언어다.
	- 기존의 객체를 복사하여 새로운 객체를 생성한다.
	- C++, Java 등 클래스 기반(class-based) 객체지향 언어와는 다른 점이 있다.
- `프로토타입(prototype)`: 자바스크립트에서 상속하는 정보를 제공하는 객체
	- 모든 객체는 프로토타입 객체를 가지고 있다.
	- 모든 객체는 해당 프로토타입으로부터 프로퍼티와 메소드를 상속한다.
	- 모든 객체는 최소한 1개 이상의 다른 객체를 상속한다. 
- 자바스크립트에서 상속은 현재 존재한 객체를 복제하여 재사용하는 것을 의미한다.

#### 프로토타입 프로퍼티 (prototype Property)
- 모든 함수는 `prototype` 프로퍼티를 기본적으로 가지고 있다.
- prototype은 해당 객체의 프로토타입을 가리킨다.

#### 프로토타입 체인 (Phototype Chain)
- 어떤 객체의 프로토타입을 계속 추적할 경우, 이러한 추적의 종점은 항상 `Object.prototype`이다.
- 즉, 모든 객체는 Object.prototype를 상속한다.
- Object.prototype 객체는 어떠한 프로토타입, 프로퍼티를 가지지 않는 빈 객체다. => {}
- 이러한 어떤 객체부터 Object.prototype까지 프로토타입 연결 관계를 `프로토타입 체인`이라 한다.

#### 프로토타입 생성
- 생성자 함수에서 인스턴스에 추가할 프로퍼티들을 정의할 수 있다.
- `new` 키워드를 통해 생성자 함수로 인스턴스 객체를 생성할 수 있다.

> function `Constructor`() {
> 	this.`property1` = `value1`
> 	...
> }

> var `instance` = new `Constructor`();

```
// 생성자 함수
function Item(hp, mp) {
	this.hp = hp;
	this.mp = mp;
}

// 인스턴스 생성
var item = new Item(100, 50);
console.log(JSON.stringify(item));  // { "hp":100, "mp":50 }
```

위 예제의 동작을 정리하면 다음과 같다.
```
1. 생성자 함수(Item)를 정의할 때 빈 객체가 생성된다.
	- 이 객체는 `Item.prototype`으로 참조할 수 있다.
2. new 키워드를 사용하면,
	1. Item.prototype를 복사해서 새로운 객체를 생성한다. => item
	2. 생성자 함수가 실행된다. (이때 this는 item이다)
```

#### 프로퍼티 추가
##### 인스턴스
- 참조 연산자를 활용해서 인스턴스에 프로퍼티를 추가할 수 있다.

> var `instance`.`newProperty` = `value`;

```
function Item(hp, mp, atk) {
	this.hp = hp;
	this.mp = mp;
}

var hpPotion = new Item(100, 50, 20);
var expPotion = new Item(50, 100, 10);
expPotion.exp = 50; // 새로운 인스턴스 프로퍼티

var potionList = [hpPotion, expPotion];
for(p of potionList)
	console.log(p.hp + ", " + p.mp + ", " + p.exp);
```

- 출력 결과
```
100, 50, undefined
50, 100, 50
```

##### 프로토타입
- 프로토타입에 프로퍼티를 추가하는 방법은 다음이 있다. 

1. 생성자 함수에 추가
2.  생성자 함수의 프로토타입에 추가

> function `Constructor`(...) {
> 	this.`newProperty` = `value`
> 	...
> }
> or
> `Constructor`.prototype.`newProperty` = `value`;

- 인스턴스에서 프로퍼티를 추가하면 해당 객체에만 적용되지만, 프로토타입에 추가하면 해당 프로토타입을 상속하는 모든 객체에 적용된다.

```
function Item(hp, mp, atk) {
	this.hp = hp;
	this.mp = mp;
	this.atk = atk; // 새로운 프로토타입 프로퍼티 1
}

var hpPotion = new Item(100, 50, 20);
var expPotion = new Item(50, 100, 10);
Item.prototype.def = 5; // 새로운 프로토타입 프로퍼티 2

var potionList = [hpPotion, expPotion];
for(p of potionList)
	console.log(p.hp + ", " + p.mp + ", " + p.atk + ", " + p.def);
```

- 출력 결과
```
100, 50, 20, 5
50, 100, 10, 5
```

### Object
- 자바스크립트의 모든 객체는 Object를 상속한다.
- 모든 객체는 Object.prototype의 프로퍼티와 메소드를 사용할 수 있다.

#### Object

|메소드|반환|기능|
|---|---|---|
|keys(`object`)|Array|주어진 객체의 열거 가능한 고유 프로퍼티의 이름을 담은 배열 반환|
|getOwnPropertyNames(`object`)|Array|주어진 객체의 모든 고유 프로퍼티의 이름을 담은 배열 반환|
|isExtensible(`object`)|boolean|주어진 객체에 새로운 프로퍼티를 추가할 수 있다면 true 반환|

##### keys()
- 주어진 객체의 열거 가능한 고유 프로퍼티의 이름을 담은 배열을 반환한다.

```
var item = {
	hp: 100,
	mp: 50,
	exp: 25
};

Object.defineProperty(item, 'exp', {enumerable : false} );
console.log(Object.keys(item)); // [hp, mp]
```

##### getOwnPropertyNames()
- 주어진 객체의 모든 고유 프로퍼티의 이름을 담은 배열을 반환한다.

```
var item = {
	hp: 100,
	mp: 50,
	exp: 25
};

Object.defineProperty(item, 'exp', {enumerable : false} );
console.log(Object.getOwnPropertyNames(item)); // [hp, mp, exp]
```

##### isExtensible()
- 주어진 객체에 새로운 프로퍼티를 추가할 수 있다면 true를 반환한다.

```
var item = {
	hp: 100,
	mp: 50
};

console.log(Object.isExtensible(item)); // true

// 새 프로퍼티를 추가할 수 없게 설정
Object.preventExtensions(item);
console.log(Object.isExtensible(item)); // false
```

#### Object.prototype

|프로퍼티|값|
|---|---|
|prototype|해당 객체의 프로토타입|

|메소드|반환|기능|
|---|---|---|
|hasOwnProperty(`prop-name`)|boolean|현재 객체가 직접 선언된 특정 프로퍼티를 가지고 있다면 true 반환|
|propertyIsEnumerable(`prop-name`)|boolean|현재 객체의 프로퍼티가 열거 가능하다면 true 반환|
|isPrototypeOf(`object`)|boolean|현재 객체가 `object`의 프로토타입 체인에 속하면 true 반환|
|toString()|string|현재 객체를 string으로 변환|
|valueOf()||현재 객체의 원시 타입(number, string...)의 값 반환|

##### hasOwnProperty()
- 해당 객체가 직접 선언된 특정 프로퍼티를 가지고 있다면 true를 반환한다.
- 상속받은 프로퍼티는 false로 판단한다.

```
var item = {
	hp: 100,
	mp: 50
};

console.log(item.hasOwnProperty("hp")); // true
console.log(item.hasOwnProperty("exp")); // false
console.log(item.hasOwnProperty("prototype")); // false
```

##### propertyIsEnumerable()
- 해당 객체의 프로퍼티가 열거 가능하다면 true를 반환한다.
- 해당 프로퍼티가 객체 내 존재하지 않는다면(=hasOwnProperty()의 결과) false를 반환한다.

```
var item = {
	hp: 100,
	mp: 50,
	exp: 25
};

// item.exp의 enumerable 속성을 false로 설정
Object.defineProperty(item, 'exp', {enumerable : false} );

console.log(item.propertyIsEnumerable("hp")); // true
console.log(item.propertyIsEnumerable("exp")); // false
console.log(item.propertyIsEnumerable("atk")); // false
```

##### isPrototypeOf()
- 현재 객체가 특정 객체의 프로토타입 체인에 속하면 true를 반환한다.
	- 특정 객체가 현재 객체의 상속을 받는지를 판단하는 것과 같다.

```
var num = new Number();

console.log(Number.prototype.isPrototypeOf(num)); // true
console.log(String.prototype.isPrototypeOf(num)); // false
console.log(Object.prototype.isPrototypeOf(num)); // true
```

##### toString()
- 현재 객체를 string으로 변환한다.

```
var item = [100, 50];
console.log(item.toString()); // "100, 50"
```

##### valueOf()
- 현재 객체의 원시 타입(number, string...)의 값을 반환한다.
- 자바스크립트에선 원시 타입이 기대되는 곳에 객체가 사용되면, 내부적으로 이 메소드를 호출해서 처리한다.
- 해당 객체가 원시 타입의 값을 가지고 있지 않다면 객체 자신을 반환한다.
- valueOf()를 새로 작성해서 커스터마이징할 수 있다. (오버라이딩)

```
var item = {
	hp: 100,
	mp: 50
};
// valueOf()가 객체 자신을 반환하여 문자열 결합 연산이 수행됩니다.
console.log(item + 100); // [object Object]100

// valueOf() 재정의
item.valueOf = function() {
	return this.hp;
};
console.log(item + 100); // 200
```

### getter / setter
- `getter`: 특정 프로퍼티의 값을 받아오는 메소드
- `setter`: 특정 프로퍼티의 값을 설정하는 메소드
- 접근자 프로퍼티: getter, setter 메소드로 정의된 프로퍼티
- 일반 메소드와 달리, 호출 방법이 프로퍼티 조작과 비슷하다.

> `object`.`getter`
> `object`.`setter` = `argument`

```
var item = {
	hp: 100,
	mp: 50
};

Object.defineProperty(item, "getHPBarGuage", { get: function() { return this.hp * 100; }});
Object.defineProperty(item, "upgradeHP", { set: function(n) { this.hp *= n; }});

item.upgradeHP = 3;
console.log(item.getHPBarGuage); // 30000
```

### 전역 객체 (Global Object)
- `전역 객체`: 자바스크립트에서 미리 정의된 객체로, 전역 프로퍼티와 전역 함수가 저장되어 있다.
	- 전역에서 `this`를 통해 접근할 수 있다.
- 모든 객체는 전역 객체의 프로퍼티다.

### 래퍼 객체 (Wrapper Object)
- `래퍼 객체`: 원시 타입(number, string 등)의 프로퍼티를 접근하려 할 때, 자동으로 생성되는 임시 객체
- 원시 타입은 객체가 아니니 프로퍼티가 없다. 그렇기에 원시 타입에서 프로퍼티를 참조하면 오류가 발생할 것으로 예측할 수 있다. 그러나 자바스크립트에선 내부적으로 래퍼 객체를 생성함으로써 동작이 가능해진다.
- 프로퍼티의 참조가 끝나면 래퍼 객체는 자동으로 삭제된다.

```
var str = "JavaScript";
console.log(str.length); // 10
```

위 예제는 자바스크립트에서 내부적으로 아래와 비슷하게 바뀐다.
```
var str = "JavaScript";
console.log((new String(str)).length);
```

## 표준 객체 (Standard Object)
- `표준 객체`: 다른 객체의 기초가 되는 핵심 객체
- 자주 사용되는 표준 객체는 다음과 같다.

1. Number
2. Math
3. Date
4. String
5. Array

### Number
`Number`: number에 대한 여러 가지 기능을 제공하는 객체

#### Number

|메소드|반환|기능|
|---|---|---|
|parseFloat(`string`)|number|문자열을 파싱한 부동소수를 반환|
|parseInt(`string`, _`method`_)|number|문자열을 파싱한 정수를 반환|
|isFinite(`number`)|boolean|전달된 값이 number 타입이고 유한한 수면 true 반환|
|isNaN(`number`)|boolean|전달된 값이 number 타입이고 NaN면 true 반환|
|isInteger(`number`)|boolean|전달된 값이 number 타입이고 정수일 때만 true를 반환|
|isSafeInteger(`number`)|boolean|전달된 값이 number 타입이고 안전한 정수일 때만 true를 반환|

##### parseFloat()
- 전역 함수 `parseFloat()`하고 완전히 동일한 기능을 수행한다.

##### parseInt()
- 전역 함수 `parseInt()`하고 완전히 동일한 기능을 수행한다.

##### isFinite()
- 전역 함수 `isFinite()`하고 비슷하지만, number 강제 변환이 수행되지 않는다.
- 주어진 값이 number 타입이고 값이 유한할 때만 true가 반환되며, 그 외는 false가 반환된다.

```
Number.isFinite(500);       // true
Number.isFinite("500");     // false
Number.isFinite(null);      // false
Number.isFinite(Infinity);  // false
Number.isFinite(NaN);       // false
```

##### isNaN()
- 전역 함수 `isNaN()`하고 비슷하지만, number 강제 변환이 수행되지 않는다.
- 주어진 값이 number 타입이고 값이 NaN일 때만 true가 반환되며, 그 외는 false가 반환된다.

```
Number.isNaN("NaN");     // false
Number.isNaN(undefined); // false
Number.isNaN(NaN);       // true
```

##### isInteger()
- 주어진 값이 number 타입이고 정수일 때만 true가 반환되며, 그 외는 false가 반환된다.

```
Number.isInteger(10);       // true
Number.isInteger(1.0);      // true
Number.isInteger(1.5);      // false
Number.isInteger("10");     // false
Number.isInteger(Infinity); // false
Number.isInteger(true);     // false
```

##### isSafeInteger()
- 주어진 값이 number 타입이고 안전한 정수일 때만 true가 반환되며, 그 외는 false가 반환된다.
- `안전한 정수(safe integer)`: 자바스크립트에서 사용하는 64bit 부동소수점으로 연산했을 때 정밀도가 보장되는 정수
- 안전한 정수의 범위는 \[-(2^53^ - 1), 2^53^ - 1\]이다.

```
Number.isSafeInteger(10);                  // true
Number.isSafeInteger(math.pow(2, 53) - 1); // true
Number.isSafeInteger(math.pow(2, 53));     // false
Number.isSafeInteger(1.5);                 // false
```

#### Number.prototype

|메소드|반환|기능|
|---|---|---|
|toExponential(_`range`_)|string|현재 Number를 지수 표기법으로 변환한 결과를 반환|
|toFixed(_`range`_)|string|현재 Number를 반올림하여 소수점 자리가 `range`까지인 결과를 반환|
|toPrecision(_`range`_)|string|현재 Number를 반올림하여 전체 자리가 `range`까지인 결과를 반환|

##### toExponential()
- Number 인스턴스를 지수 표기법으로 변환한 결과를 반환한다.
- 선택 인자를 전달하면, 반올림되어 소수점 자리가 n까지 표시된다.

```
var num = 12.345;
num.toExponential();  // 1.2345e+1
num.toExponential(2); // 1.23e+1
```

##### toFixed()
- Number 인스턴스를 반올림하여 소수점 자리가 n까지인 결과를 반환한다.
- 인자의 기본 값은 0이다.

```
var num = 12.345678;
num.toFixed();  // 12
num.toFixed(2); // 12.35
```

##### toPrecision()
- Number 인스턴스를 반올림하여 전체 자리가 n까지인 결과를 반환한다.
- 인자를 제공하지 않으면 전체 수가 반환된다.

```
var num = 12.345678;
num.toPrecision();  // 12.345678
num.toPrecision(4); // 12.35
```

### Math
- `Math`: 수학에서 자주 쓰이는 상수와 함수들을 미리 구현한 객체

|프로퍼티|의미|근삿값|
|---|---|---|
|E|자연로그의 밑|2.718|
|PI|파이 상수|3.141|
|SQRT2|2의 제곱근|1.414|

|메소드|반환값|
|---|---|
|min(`x1`, `x2`, ...)|최소값|
|max(`x1`, `x2`, ...)|최대값|
|random()|\[0, 1) 구간 사이의 무작위 수|
|round(`x`)|`x`를 소수점 1번째 자리에서 반올림한 값|
|floor(`x`)|`x`를 소수점 1번째 자리에서 버림한 값|
|ceil(`x`)|`x`를 소수점 1번째 자리에서 올림한 값|
|abs(`x`)|`x`의 절댓값|
|sign(`x`)|`x`의 부호 값 (-1, 0, 1)|
|pow(`x`, `y`)|x^y^|
|sqrt(`x`)|`x`의 제곱근|
|cbrt(`x`)|`x`의 세제곱근|
|exp(`x`)|e^x^ (e = 자연로그의 밑)|
|log(`x`)|ln `x` (자연로그 값)|
|log10(`x`)|log~10~ `x`|
|log2(`x`)|log~2~ `x`|
|sin(`x`)|sin(`x`)|
|cos(`x`)|sin(`x`)|
|tan(`x`)|sin(`x`)|

```
Math.min(-10, 10, 0); // -10
Math.max(-10, 10, 0); // 10
Math.round(Math.PI);  // 3
```

```
var lo = 20, hi = 50;
Math.random() * (hi - lo) + lo; // [lo, hi) 랜덤값
```

### Date
- `Date`: 시간과 날짜를 관리하는 객체

#### 날짜 표현
- 자바스크립트에선 주로 `Date` 객체를 사용해서 시간과 날짜를 관리한다.
- 날짜와 시간을 표현하는 값의 범위는 다음과 같다.
	- 자바스크립트에선 월의 값이 0부터 시작한다.
	- 연도일 경우, 2000년대 이전은 2자리 값으로 표기 가능
	- 2000년대 이후는 4자리로 표현해야 한다.

|시간|범위(시간)|범위(값)|
|---|---|---|
|year|현재 연도(4자리)||
|month|\[1월, 12월\]|\[0, 11\]|
|day|\[1일, 31일\]|\[1, 31\]|
|hours|\[0시, 23시\]|\[0, 23\]|
|minutes|\[0분, 59분\]|\[0, 59\]|
|seconds|\[0초, 59초\]|\[0, 59\]|

#### 날짜 양식 (Date Format)
자바스크립트에서 날짜를 표현하는 양식은 여러 가지가 있다.

1. ISO 날짜 양식
2. Long 날짜 양식
3. Short 날짜 양식
4. Full 날짜 양식

##### ISO 날짜 양식
- `ISO 8601`: 날짜와 시간을 나타내는 국제 표준 양식
- T는 UTC(협정시)를 의미하는 문자

> `YYYY`-`MM`-`DD`T`HH`:`MM`:`SS`
> `YYYY`-`MM`-`DD`
> `YYYY`
> `YYYY`

```
2023-07-19T07:41:25
2023-07-19           // 기본 시간 = 09:00:00
2023-07              // 기본 일 = 1
2023                 // 기본 월 = 1
```

##### Long 날짜 양식
> `MMM` `DD` `YYYY`
> `DD` `MMM` `YYYY`

```
Jul 19 2023
19 Jul 2023
July 19 2023   // 월의 전체 단어도 인식됩니다.
19, JULY, 2023 // 쉼표를 사용해도 되며, 대소문자 구분은 없습니다.
```

##### Short 날짜 양식
> `MM`-`DD`-`YYYY`
> `YYYY`-`MM`-`DD`

```
2023-07-19
07/19/2023  // /를 사용할 수도 있습니다.
```

##### Full 날짜 양식
> `MM` `DD` `YYYY` `HH`:`MM`:`SS` GMT+`diff-time` (`time-zone`)

```
July 20 2023 02:19:25 GMT+0900 (Seoul Time)
```

#### 생성
Date 객체를 생성하는 다양한 방법이 제공된다.

1. new Date()
2. new Date(`date-string`)
3. new Date(`miliseconds`)
4. new Date(`year`, `month`, `day`, `hours`, `minutes`, `seconds`, `miliseconds`)

```
// 아무런 인자를 주지 않으면 기본값으로 현재 시간이 적용됩니다.
new Date();

// 날짜 양식을 문자열로 제공해서 Date를 생성할 수 있습니다.
new Date("2023-07-19 16:20:30");

// UTC 협정시(1970년 1월 1일 00:00:00)부터 지난 시간(밀리초 단위)
new Date(90000000);

// 여러 인자로 분할해서 제공할 수도 있습니다.
new Date(2023, 6, 19, 16, 20, 30);
```

- 출력 결과
```
2023-07-19T07:34:22.796Z
2023-07-19T07:20:30.000Z
2022-04-15T05:20:00.000Z
2023-07-19T07:20:30.000Z
```

#### 메소드

|메소드|값 범위|기능|
|---|---|---|
|now()|-|UTC 협정시부터 현재까지의 시간 차(밀리초) 반환|
|getTime()|-|now()와 동일|
|getFullYear()|YYYY|연도 반환|
|getMonth()|\[0, 11\]|월 반환|
|getDate()|\[1, 31\]|일자 반환|
|getDay()|\[0, 6\]|요일 반환|
|getHours()|\[0, 23\]|시간 반환|
|getMinutes()|\[0, 59\]|분 반환|
|getSeconds()|\[0, 59\]|초 반환|
|getMilliseconds()|\[0, 999\]|밀리초 반환|
|setTime(`milliseconds`)|-|UTC 협정시부터 현재까지의 시간 차(밀리초)로 시간 설정|
|setFullYear(`YYYY`, _`MM`_, _`DD`_)|-|연도(+월, 일) 설정|
|setMonth(`month`)|\[0, 11\]|월 설정|
|setDate(`date`)|\[1, 31\]|일자 설정|
|setHours(`hours`)|\[0, 23\]|시간 설정|
|setMinutes(`minutes`)|\[0, 59\]|분 설정|
|setSeconds(`seconds`)|\[0, 59\]|초 설정|
|setMilliseconds(`milliseconds`)|\[0, 999\]|밀리초 설정|

```
var date = new Date(Date.now());
console.log(date); // 현재 시간이 출력됩니다.

date.setFullYear(2022);
date.setMonth(9);
date.setDate(31);
console.log(date.getFullYear() + "-" + (date.getMonth() + 1) + "-" + date.getDate()); // 2022-10-31
```

- 메소드명에 UTC가 들어가면 UTC 협정시 기준, 아니면 현지 시각을 기준으로 한다.

```
var date = new Date();
date.setUTCFullYear(2022);
date.setUTCMonth(9);
date.setUTCDate(31);

console.log(date.getUTCFullYear() + "-" + (date.getUTCMonth() + 1) + "-" + date.getUTCDate()); // 2022-10-31
```

### String
- `String`: 문자열에 대한 여러 기능을 제공하는 객체
- String.prototype에서 여러 가지 메소드를 제공한다.
	- 메소드를 실행해도 현재 문자열은 불변한다.
- 일부 메소드는 정규 표현식을 요구한다.

|프로퍼티|값|의미|
|---|---|---|
|length|number|문자열 길이|

|메소드|값|기능|
|---|---|---|
|indexOf(`search`, _`pos`_)|number|현재 문자열에서 `search` 문자열이 등장하는 첫 위치 반환|
|lastIndexOf(`search`)|number|현재 문자열에서 `search` 문자열이 등장하는 마지막 위치 반환|
|charAt(`i`)|string|현재 문자열에서 i번째 문자 반환|
|charCodeAt(`i`)|string|charAt()의 결과를 UFT-16 코드로 반환|
|slice(`lo`, _`hi`_)|string|현재 문자열을 인덱스 \[`lo`, `hi`\) 범위만큼 추출한 문자열 반환|
|substring(`lo`, _`hi`_)|string|slice()와 동일|
|substr(`lo`, _`hi`_)|string|slice()와 동일|
|split(`seperator`)|Array|현재 문자열을 `seperator` 기준으로 분할하고, 나뉜 조각들을 담은 배열 반환|
|concat(`extra`)|string|현재 문자열 끝에 문자열 `extra`을 덧붙인 결과 반환|
|toUpperCase()|string|현재 문자열의 모든 문자를 대문자로 바꾼 결과 변환|
|toLowerCase()|string|현재 문자열의 모든 문자를 소문자로 바꾼 결과 변환|
|trim()|string|현재 문자열의 양 끝에 존재하는 모든 공백과 줄바꿈 문자를 제거한 결과 반환|
|includes(`search`)|boolean|현재 문자열에 문자열 `search`가 포함되어 있다면 true 반환|
|startsWith(`search`)|boolean|현재 문자열이 문자열 `search`으로 시작하면 true 반환|
|endsWith(`search`)|boolean|현재 문자열이 문자열 `search`으로 끝나면 true 반환|
|search(`reg`)|number|정규 표현식으로 검색한 결과 반환 (성공시 일치한 패턴의 최소 인덱스, 실패시 -1 반환)|
|replace(`reg`, `string`)|string|정규 표현식으로 검색된 패턴을 `string`으로 대체한 입력 문자열 반환|

#### 문자열 위치 찾기
- indexOf(`search`, _`pos`_): 현재 문자열에서 `search` 문자열이 등장하는 첫 위치를 반환
	- `pos` 전달시, 현재 문자열의 해당 인덱스부터 검색이 시작된다.
- lastIndexOf(`search`): 현재 문자열에서 `search` 문자열이 등장하는 마지막 위치를 반환
- 두 메소드 모두 검색 실패시 -1이 반환된다.

```
var str = "abcDEFabc";
str.indexOf("abc");     // 0
str.indexOf("abcd");    // -1
str.indexOf("abc", 3);  // 6
str.lastIndexOf("abc"); // 6
str.indexOf("b");       // 7
```

#### 문자열 문자 접근
- charAt(`i`): 문자열에서 i번째 문자 반환
	- `[]` 연산자도 같은 기능을 수행한다.
	- i >= length일 경우, 빈 문자열이 반환된다.
- charCodeAt(`i`): charAt()의 결과를 UFT-16 코드로 반환

```
var str = "JavaScript";
str.charAt(5);     // c
str[5];            // c
str.charCodeAt(5); // 99
```

#### 문자열 추출
- slice(`lo`, _`hi`_): 현재 문자열을 인덱스 \[`lo`, `hi`\) 범위만큼 추출한 문자열 반환
	- `hi` 생략시, 현재 문자열의 마지막까지 추출됨
- substring(), substr(): slice()와 동일

```
var str = "JavaScript";
str.slice(2, 6); // vaSc
str.substr(2);   // vaScript
```

#### 문자열 분리
- split(`seperator`): 현재 문자열을 `seperator` 기준으로 분할하고, 나뉜 조각들을 담은 배열 반환
	- 인수 미제공시, 분할이 발생하지 않는다. (전체 문자열이 담긴 길이 1 배열 반환)

```
var str = "HTML vs CSS vs JavaScript";

// [ 'HTML', 'CSS', 'JavaScrip' ]
str.split(" vs ");
```

#### 문자열 결합
- concat(`extra`): 현재 문자열 끝에 문자열 `extra`을 덧붙인 결과 반환

```
var str = "JavaScript";

// "JavaScript is SO AWESOME!!"
str.concat(" is SO AWESOME!!");
```

#### 문자열 대소문자 변환
- toUpperCase(): 현재 문자열의 모든 문자를 대문자로 바꾼 결과 변환
- toLowerCase(): 현재 문자열의 모든 문자를 소문자로 바꾼 결과 변환

```
var str = "JavaScript";
str.toUpperCase(); // JAVASCRIPT
str.toLowerCase(); // javascript
```

#### 문자열 주위 공백 제거
- trim(): 현재 문자열의 양 끝에 존재하는 모든 공백과 줄바꿈 문자를 제거한 결과 반환
	- 문자열 내부에는 영향이 없다.

```
var str = "   Java vs Script   ";
str.trim(); // Java vs Script
```

#### 문자열 포함 유무
- includes(`search`): 현재 문자열에 문자열 `search`가 포함되어 있다면 true 반환
- startsWith(`search`): 현재 문자열이 문자열 `search`으로 시작하면 true 반환
- endsWith(`search`): 현재 문자열이 문자열 `search`으로 끝나면 true 반환

```
var str = "JavaScript";
str.includes("Java");   // true
str.includes("scr");    // false
str.startsWith("Java"); // true
str.endsWith("pt");     // true
```

### Array
- `Array`: 자바스크립트에서 배열을 담당하는 객체

#### Array

|메소드|반환|기능|
|---|---|---|
|isArray(`array`)|boolean|`array`가 Array 객체면 true 반환|
|from(`target`)|Array|`target`을 배열로 바꾼 결과 반환|
|of(`v1`, `v2`, ...)|Array|제공된 인자로 구성된 배열 반환|

##### isArray()
- 인자가 Array 객체면 true 반환

```
Array.isArray([]);      // true
Array.isArray("Array"); // false
Array.isArray(true);    // false
```

##### from()
- 인자를 Array 객체를 상속하는 객체로 바꾼 결과 반환
- 바꿀 수 있는 객체:
	- 배열과 비슷한 객체: length 프로퍼티와 인덱스 요소 존재
	- 반복 가능한 객체: 요소를 개별 선택 가능함 (String, Map, Set 등)

```
Array.from(new Map([1, 2], [3, 4])); // [1,2,3,4]
Array.from("JavaScript"); // [J,a,v,a,S,c,r,i,p,t]
```

##### of()
- 제공된 인자로 구성된 배열 반환 (인수간 타입 무관)

```
Array.of(1, "234", true); // [1, "234", true]
```

#### Array.prototype
- 현재 배열이 변경되는 메소드

|메소드|반환|기능|
|---|---|---|
|push(`x1`, `x2`, ...)|변경된 배열의 length|1개 이상의 요소를 배열의 마지막에 추가|
|pop()|제거된 요소|배열의 가장 마지막 요소 제거|
|shift()|제거된 요소|배열의 가장 앞의 요소 제거|
|reverse()|변경된 배열|배열의 순서를 뒤집음|
|sort()|변경된 배열|배열의 요소를 정렬 (string 사전순)|
|splice(`pos`, `cnt`, _`x1`_, _`x2`_, ...)|제거된 요소들로 구성된 배열|배열의 `pos` 인덱스부터 `cnt`개 요소들을 제거한 뒤, `x` 요소들을 그 인덱스에 추가|

- 현재 배열이 변경되지 않는 메소드

|메소드|반환|기능|
|---|---|---|
|join(`seperator`)|string|배열의 모든 요소를 문자열 `seperator`로 구분한 문자열 반환|
|slice(`lo`, _`hi`_)|Array|배열 인덱스\[`lo`, `hi`)에 해당하는 요소들을 배열로 묶어 반환|
|concat(`x1`, `x2`, ...)|Array|1개 이상의 요소를 배열의 마지막에 추가한 결과 반환|
|toString()|string|현재 배열을 문자열로 변환 (join()과 동일)|
|indexOf(`x`)|number|`x`와 동일한 배열 요소의 최소 인덱스 반환|
|lastIndexOf(`x`)|number|`x`와 동일한 배열 요소의 최대 인덱스 반환|

- 콜백 함수로 현재 배열을 반복 참조하는 메소드

|메소드|반환|기능|
|---|---|---|
|forEach(`function`)||현재 배열의 모든 요소를 대상으로 콜백 함수 1회씩 호출|
|map(`function`)|Array|현재 배열의 모든 요소를 대상으로 콜백 함수 1회씩 호출하고, 호출 결과를 각 요소에 대입한 배열 반환|
|filter(`function`)|Array|현재 배열의 모든 요소를 대상으로 콜백 함수 1회씩 호출하고, 호출 결과가 true인 요소만 담은 배열 반환|
|every(`function`)|boolean|현재 배열의 모든 요소를 대상으로 콜백 함수 1회씩 호출하고, 호출 결과가 모두 true면 true 반환|
|some(`function`)|boolean|현재 배열의 모든 요소를 대상으로 콜백 함수 1회씩 호출하고, 호출 결과가 하나라도 true면 true 반환|
|reduce(`function`)||현재 배열에 대해 `A(n) = F(A(n-1), arr[n])` 구조의 콜백 함수를 실행한 결과 반환|
|reduceRight(`function`)||현재 배열의 순서를 뒤집고 reduce() 수행|
|entries()|Array|배열 요소별로 키(key)와 값(value) 쌍으로 이루어진 배열 반복자 객체(Array Iterator Object)로 구성된 배열 반환|

- forEach(), map(), filter(), every(), some()에서 콜백 함수의 선택인자는 다음과 같다.

> function calBack(value, index, array) {
>	// value = 현재 배열 요소
>	// index = 현재 배열 인덱스
>	// array = 탐색 중인 배열
> }

##### push()
- 1개 이상의 요소를 배열의 마지막에 추가
- 추가 성공시, 변경된 배열의 length를 반환

```
var arr = [1, 2, 3];
arr.push(4);
arr.push(5, 6, 7);
console.log(arr); // [1,2,3,4,5,6,7]
```

##### pop()
- 배열의 가장 마지막 요소를 제거하고, 그 제거된 요소를 반환

```
var arr = [1, 2, 3];
console.log(arr.pop()); // 3
console.log(arr);       // [1, 2]
```

##### shift()
- 배열의 가장 앞의 요소를 제거하고, 그 제거된 요소를 반환

```
var arr = [1, 2, 3];
console.log(arr.pop()); // 1
console.log(arr);       // [2, 3]
```

##### unshift()
- 1개 이상의 요소를 배열의 앞에 추가
- 추가 성공시, 변경된 배열의 length를 반환

```
var arr = [1, 2, 3];
arr.unshift(0);
arr.unshift(-3, -2, -1);
console.log(arr); // [-3,-2,-1,0,1,2,3]
```

##### reverse()
- 배열의 순서를 뒤집음

```
var arr = [1, 2, 3];
arr.reverse();
console.log(arr); // [3, 2, 1]
```

##### sort()
- 배열의 요소를 정렬 (string 사전순)
- stirng 기준으로 정렬되므로, number 등은 문자열로 변환된 것을 정렬 기준으로 한다.

```
var arr = ["html", "css", "javascript", 123, true];
arr.sort();
console.log(arr); // [123, "css", "html", "javascript", true]
```

##### splice()
- 특정 위치부터 배열의 요소들을 제거하고 주어진 인자들을 해당 자리에 추가

```
var arr = [1, 2, 3, 4, 5];
console.log(arr.splice(2, 2, "3", "4")); // [3, 4]
console.log(arr); // [1, 2, "3", "4", 5]
```
##### join()
- 배열의 모든 요소를 구분자(제공한 인자)로 구분한 문자열 반환
- 인자의 기본값은 `,`이다.

```
var arr = [1, 2, 3];
arr.join();     // 1,2,3
arr.join("");   // 123
arr.join(" + ") // 1 + 2 + 3
```

##### slice()
- 특정 구간에 해당하는 요소들을 배열로 묶어 반환
	- 2번째 인자 생략시, 배열 끝까지 연장됨

```
var arr = [1, 2, 3, 4, 5];
arr.slice(1, 3); // [2, 3]
arr.slice(2); // [3, 4, 5]
```

##### concat()
- 1개 이상의 요소를 배열의 마지막에 추가한 결과 반환
- 배열이 인자로 제공된 경우, 해당 인자의 요소들을 추가함 (배열 자체가 추가되진 않음)

```
var arr = [1, 2, 3];
console.log(arr.concat(4, 5));      // [1,2,3,4,5]
console.log(arr.concat(4, [5, 6])); // [1,2,3,4,5,6]
```

##### toString()
- 현재 배열을 문자열로 변환 (join()과 동일)

```
var arr = [1, 2, 3];
arr.toString(); // 1,2,3
```

##### indexOf()
- 인자값과 동일한 배열 요소의 최소 인덱스 반환

```
var arr = [1, 2, 3, 2, 1];
arr.indexOf(2); // 1
```

##### lastIndexOf()
- 인자값과 동일한 배열 요소의 최대 인덱스 반환

```
var arr = [1, 2, 3, 2, 1];
arr.indexOf(2); // 3
```


##### forEach()
- 현재 배열의 모든 요소를 대상으로 콜백 함수 1회씩 호출

```
var arr = ['A', 'B', 'C'];
function printAll(value, index, array) {
	console.log(index + ": " + value);
}
arr.forEach(printAll);
```

- 출력 결과
```
0: A
1: B
2: C
```

##### map()
- 현재 배열의 모든 요소를 대상으로 콜백 함수 1회씩 호출하고, 호출 결과를 각 요소에 대입한 배열 반환

```
var arr = [1, -2, 3, -4, 5];
console.log(arr.map(Math.abs)); // [1, 2, 3, 4, 5]
```

##### filter()
- 현재 배열의 모든 요소를 대상으로 콜백 함수 1회씩 호출하고, 호출 결과가 true인 요소만 담은 배열 반환

```
var arr = [1, -2, 3, -4, 5];
function isOverZero(value) {
	return value > 0;
}
console.log(arr.filter(isOverZero)); // [1, 3, 5]
```

##### every()
- 현재 배열의 모든 요소를 대상으로 콜백 함수 1회씩 호출하고, 호출 결과가 모두 true면 true 반환

```
var arr1 = [1, -2, 3, -4, 5];
var arr2 = [1, 2, 3, 4, 5];
function isOverZero(value) {
	return value > 0;
}
console.log(arr1.every(isOverZero)); // false
console.log(arr2.every(isOverZero)); // true
```

##### some()
- 현재 배열의 모든 요소를 대상으로 콜백 함수 1회씩 호출하고, 호출 결과가 하나라도 true면 true 반환

```
var arr1 = [1, 2, 3, -4, 5];
var arr2 = [1, 2, 3, 4, 5];
function isUnderZero(value) {
	return value < 0;
}
console.log(arr1.some(isUnderZero)); // true
console.log(arr2.some(isUnderZero)); // false
```

##### reduce()
- 현재 배열에 대해 다음 구조의 콜백 함수를 실행한 결과 반환

> A~0~ = arr\[0\]
> A~n~ = F(A~n-1~, arr\[n\])

> function F(a, b) {
> 	// a = A~n-1~
> 	// b = arr\[n\]
> }

```
var arr = [1, 2, 3, 4, 5];
function sumAll(a, b) {
	return a + b;
}
console.log(arr.reduce(sumAll)); // 15
```

##### reduceRight()
- 현재 배열의 순서를 뒤집고 reduce() 수행

```
var arr = [1, 2, 3, 4, 5, 15];
function subtactAll(a, b) {
	return a - b;
}
console.log(arr.reduceRight(subtactAll)); // 0
```

##### entries()
- 배열 요소별로 키(key)와 값(value) 쌍으로 이루어진 배열 반복자 객체(Array Iterator Object)로 구성된 배열 반환

```
var arr = ['A', 'B', 'C'];
var arrEntries = arr.entries();
for(var entry of arrEntries)
	console.log(entry);
```

- 출력 결과
```
[ 0, 'A' ]
[ 1, 'B' ]
[ 2, 'C' ]
```


## DOM (Document Object Model)
- `문서 객체 모델(DOM ,Document Object Model)`: XML이나 HTML 문서에 접근하기 위한 일종의 인터페이스
- DOM을 통해 HTML 요소에 대해 접근/변경/추가/삭제 등을 할 수 있다.
- CSS 스타일 변경, HTML 이벤트 추가도 가능하다.
- W3C 표준 DOM 종류
	- Core DOM: 모든 문서 타입을 위한 DOM 모델
	- HTML DOM: HTML 문서를 위한 DOM 모델
	- XML DOM: XML 문서를 위한 DOM 모델

### Document
- `document`: HTML DOM 객체

#### HTML 선택

|메소드|반환|기능|
|---|---|---|
|getElementsByTagName(`tag`)|HTMLCollection|해당 태그 이름과 일치하는 모든 HTML 요소 선택|
|getElementById(`id`)|Element|해당 id 속성 값과 일치하는 HTML 요소 선택|
|getElementsByClassName(`class`)|HTMLCollection|해당 class 속성 값과 일치하는 모든 HTML 요소 선택|
|getElementsByName(`name`)|NodeList|해당 name 속성 값과 일치하는 모든 HTML 요소 선택|
|querySelectorAll(`selector`)|NodeList|CSS 선택자로 HTML 요소 선택|

```
<html>
	<body>
		<div id="hello">
			This is 
			<p class="welcome">DOM!</p>
		</div>
		<div class="welcome">
			Where is 
			<p name="line">my node??</p>
		</div>
		<script>
			console.log(document.getElementsByTagName("div"));
			console.log(document.getElementById("hello"));
			console.log(document.getElementsByClassName("welcome"));
			console.log(document.getElementsByName("line"));
		</script>
	<body>
</html>
```

```
HTMLCollection(2) ?[div#hello, div.welcome, hello: div#hello]
<div id="hello"></div>
HTMLCollection(2) [p.welcome, div.welcome]
NodeList [p]
```

#### HTML 생성

|메소드|기능|
|---|---|
|write(`script`)|현재 위치에 HTML 스크립트 삽입|

### HTML DOM
- HTML DOM은 노드들을 `트리(tree)` 구조로 저장하고 있다. => `노드 트리(node tree)`
- `Node`: HTML DOM을 구성하는 객체
- `NodeList`: Node 객체들을 저장하는 콜렉션 객체 (배열처럼 사용 가능)
- `Element`: HTML 요소를 저장하는 객체 (Node를 상속함)
- `HTMLCollection`: Element 객체들을 저장하는 콜렉션 객체
- Node의 읽기 전용 프로퍼티는 DOM이 업데이트가 되면 자동으로 갱신된다.

#### 노드 종류

|노드|설명|
|---|---|
|문서 노드(document node)|HTML 문서 전체(=Document)|
|요소 노드(element node)|HTML 요소|
|속성 노드(attribute node)|HTML 요소의 속성|
|텍스트 노드(text node)|HTML 문서의 텍스트|
|주석 노드(comment node)|HTML 문서의 주석|

- 문서 노드는 HTML DOM의 루트에 있다.
- 문서 노드 아래에 요소 노드들이 트리를 구성한다.
- 속성 노드는 요소 노드에 관한 정보를 가지고 있으나, 요소 노드의 자식 노드엔 포함되지 않는다.
- 어떤 요소의 텍스트 노드는 해당 요소 노드의 자식 노드다.

#### 노드 접근
- 요소 노드의 firstChild는 텍스트 노드다.

|프로퍼티|의미|
|---|---|
|parentNode|부모 노드|
|childNodes|자식 노드 리스트|
|firstChild|1번째 자식 노드|
|lastChild|마지막 자식 노드|
|nextSibling|다음 형제 노드|
|previousSibling|이전 형제 노드|

#### 노드 정보

|프로퍼티|의미|
|---|---|
|nodeName|노드 고유의 이름|
|nodeValue|노드의 값|
|nodeType|노드 고유의 타입|

##### nodeName
- 노드 고유의 이름을 저장하는 읽기 전용 프로퍼티

|노드 종류|값|
|---|---|
|문서 노드(document node)|`#document`|
|요소 노드(element node)|태그 이름|
|속성 노드(attribute node)|속성 이름|
|텍스트 노드(text node)|`#text`|

##### nodeValue
- 노드의 값을 저장하는 프로퍼티
- 직접 값을 수정할 수도 있다.

|노드 종류|값|
|---|---|
|요소 노드(element node)|undefined|
|속성 노드(attribute node)|속성 값|
|텍스트 노드(text node)|텍스트 내용|

##### nodeType
- 노드 고유의 타입을 저장하는 읽기 전용 프로퍼티

|노드 종류|값|
|---|---|
|문서 노드(document node)|9|
|요소 노드(element node)|1|
|속성 노드(attribute node)|2|
|텍스트 노드(text node)|3|
|주석 노드(comment node)|8|

#### 노드 추가/생성

|메소드|기능|
|---|---|
|appendChild(`new-node`)|현재 노드의 자식 노드 리스트의 마지막에 새로운 노드 추가|
|insertBefore(`new-node`, `pos-node`)|현재 노드의 자식 노드 `pos-node` 앞 위치에 새로운 노드 추가|
|insertDate(`offset`, `text-data`)|텍스트 노드의 텍스트 데이터에서 `offset` 위치에 새로운 텍스트 추가|
|setAttributeNode(`attribute-node`)|현재 요소에 속성 노드 추가|
|createElement(`tag-name`)|태그명으로 새로운 요소 노드 생성|
|createAttribute(`attribute-name`)|속성명으로 새로운 속성 노드 생성|
|createTextNode(`text-data`)|전달된 데이터로 텍스트 노드 생성|

```
<html>
	<body>
		<script>
			var body = document.getElementsByTagName("body")[0];
			var div = document.createElement("div");
			var div_style = document.createAttribute("style");
			var div_text = document.createTextNode("New Node!!");
			
			// <div style="color:orange">New Node!!</div>가 추가됩니다.
			div_style.value = "color:orange";
			div.setAttributeNode(div_style);
			div.appendChild(div_text);
			body.appendChild(div);
		</script>
	<body>
</html>
```

- 속성 노드일 경우, 프로퍼티처럼 참조하는 방식으로도 추가가 가능하다.

> `element-node`.`attribute-node` = `attribute-value`

```
<html>
	<body>
		<script>
			var body = document.getElementsByTagName("body")[0];
			var div = document.createElement("div");
			var div_text = document.createTextNode("New Node!!");
			
			// <div style="color:orange">New Node!!</div>가 추가됩니다.
			div.style = "color:orange";
			div.appendChild(div_text);
			body.appendChild(div);
		</script>
	<body>
</html>
```

#### 노드 제거
- 어떤 노드가 제거되면, 해당 노드의 자식 노드들도 같이 제거된다.

|메소드|반환|기능|
|---|---|---|
|removeChild(`child-node`)|제거된 노드|현재 노드의 자식 노드 리스트에서 해당 자식 노드 제거|
|removeAttribute(`attribute-name`)||속성명으로 현재 노드의 속성 노드 삭제|


```
<html>
	<body>
		<div style="color:orange"><p>New </p>Node!!</div>
		<script>
			var div = document.getElementsByTagName("div")[0];
			var p = document.getElementsByTagName("p")[0];
			
			// <div>Node!!</div>으로 변경됨
			div.removeChild(p);
			div.removeAttribute("style");
		</script>
	<body>
</html>
```

#### 노드 복제

|메소드|반환|기능|
|---|---|---|
|cloneNode(`clone-child?`)|복제된 노드|현재 노드를 복제한 노드 반환|

- cloneNode()의 인자는 자식 노드도 같이 복제할 것인지 여부를 설정한다. (true시 자식 노드도 복제)

```
<html>
	<body>
		<div style="color:orange"><p>New </p>Node!!</div>
		<script>
			var body = document.getElementsByTagName("body")[0];
			var div = document.getElementsByTagName("div")[0];
			body.appendChild(div.cloneNode(true));
		</script>
	<body>
</html>
```

#### 노드 교체

|메소드|기능|
|---|---|
|replaceChild(`new-node`, `child-node`)|현재 노드의 자식 노드 리스트에서 해당 자식 노드를 새로운 노드로 대체|
|replaceData(`offset`, `del-cnt`, `text-data`)|텍스트 노드의 텍스트 데이터에서 `offset` 위치에 `del-cnt`만큼 기존 문자를 삭제하고 새로운 텍스트 추가|

## BOM (Browser Object Model)
- `브라우저 객체 모델 (BOM, Browser Object Model)`: 브라우저 관련 정보를 제공하는 객체 모델
- W3C 표준 객체 모델은 아니다.
- 자바스크립트에서 BOM의 객체들은 전역 객체로 사용할 수 있다.

### Window
- `Window`: 브라우저의 창(window)을 나타내는 객체
- 자바스크립트의 전역 객체는 Window 객체다.
	- 즉, Window 객체의 프로퍼티는 전역 변수, 메소드는 전역 함수다.

|프로퍼티|의미|
|---|---|
|innerHeight|창 높이|
|innerWidth|창 너비|
|ScreenX|스크린에서 창 x축 위치|
|ScreenY|스크린에서 창 y축 위치|
|document|HTML DOM 객체|

|메소드|기능|
|---|---|
|open()|새로운 창 열기|
|close()|현재 창 닫기|

### Location
- `Location`: 현재 브라우저의 주소 관련 정보를 담은 객체
- window, document의 location 프로퍼티를 통해 접근 가능

|프로퍼티|의미|
|---|---|
|href|현재 문서의 URL 주소|
|hostname|현재 문서의 인터넷 호스트 이름|
|pathname|현재 문서의 파일 경로명|

|메소드|기능|
|---|---|
|assign(`url`)|해당 url의 문서 불러오기|
|replace(`url`)|해당 url의 문서 불러오기 (현재 문서는 히스토리에서 제거)|

```
// 현재 창을 불러옵니다.
location.assign(location.href);
```

### History
- `Histroy`: 브라우저의 히스토리 정보를 저장하는 객체
- window의 history 프로퍼티를 통해 접근 가능

|프로퍼티|의미|
|---|---|
|length|브라우저 히스토리 목록 개수|

|메소드|기능|
|---|---|
|back()|이전 페이지로 이동|
|forward()|다음 페이지로 이동|
|go(`x`)|x번 앞으로 페이지 이동|

- go(-1)은 back(), go(1)은 forward()하고 동일하다.

### Screen
- `Screen`: 사용자 디스플레이 화면의 정보를 저장하는 객체
- window의 screen 프로퍼티를 통해 접근 가능

|프로퍼티|의미|
|---|---|
|width|사용자 스크린 화면 너비|
|height|사용자 스크린 화면 높이|
|outerWidth|브라우저 창 너비|
|outerHeight|브라우저 창 높이|
|availWidth|사용 가능한 화면 너비|
|availHeight|사용 가능한 화면 높이|
|colorDepth|한 색상당 사용할 수 있는 bit 수|
|pixelDepth|화면에서 pixel당 표시 가능한 bit 수|

### Navigator
- `Navigator`: 브라우저에 대한 다양한 정보를 제공하는 객체
- window의 navigator 프로퍼티를 통해 접근 가능

|프로퍼티|의미|
|---|---|
|platform|현재 브라우저가 실행되고 있는 운영체제 이름|
|language|현재 사용 중인 브라우저 기본 언어 설정|
|cookieEnabled|브라우저가 쿠키를 사용 가능한지 여부|

### Dialog Box
- window 객체에서 대화 상자와 관련된 메소드를 제공한다.
- 대화 상자가 뜨는동안 브라우저의 실행은 잠시 중단된다.

|메소드|반환|기능|
|---|---|---|
|alert(`msg`)||내용이 `msg`인 대화 상자 생성|
|confirm(`msg`)|boolean|내용이 `msg`인 대화 상자 생성. 사용자가 확인 버튼을 누르면 true 반환|
|prompt(`msg`, `contents`)|string|내용이 `msg`인 텍스트 대화 상자 생성. (텍스트 기본값 = `contents`) 사용자가 대화 상자에 입력한 문자열 반환|

```
var name = prompt("이름을 입력해주세요.");
if(confirm("버튼을 눌러주세요."))
	alert(name + "님은 확인을 누르셨습니다.");
else
	alert(name + "님은 취소를 누르셨습니다.");
```

### Timer
- window 객체에서 타이머 관련 메소드를 제공한다.
- 타이머 함수는 타이머 시작 성공시, 고유의 timeoutID를 반환한다.
	- 이 ID는 타이머 중단 메소드의 인자로 줄 수 있다.

|메소드|반환|기능|
|---|---|---|
|SetTimeout(`function`, `time`)|timeoutID|`time` 밀리초 이후에 콜백 함수 실행|
|SetInterval(`function`, `period`)|timeoutID|`period` 밀리초 단위로 콜백 함수 반복 실행|
|clearTimeout(`timeoutID`)||해당 SetTimeout() 타이머 작동 중단|
|clearInterval(`timeoutID`)||해당 SetInterval() 타이머 작동 중단|

```
var cnt = 5;
var cntTimerID;
function BOOM() {
	document.write("BOOM!!");
	clearInterval(cntTimerID);
}
function counter() {
	document.write(cnt-- + "...");
}

// 5초 뒤에 폭발합니다!
cntTimerID = setInterval(counter, 1000);
setTimeout(BOOM, 5999);
```

- 출력 결과
```
5...4...3...2...1...BOOM!!
```

## 이벤트 (Event)
- `이벤트(event)`: 웹 브라우저가 알려주는 HTML 요소에 대한 사건의 발생
- 자바스크립트는 이벤트에 따라 특정 동작을 수행하도록 설정할 수 있다.
- `이벤트 타입(event type)`: 발생한 이벤트의 종류를 나타내는 문자열
	- `이벤트 명(event name)`이라고도 한다.
	- 키보드 마우스 등 여러 가지 이벤트가 있다.

### 이벤트 리스너 (Event Listener)
- `이벤트 리스너`: 이벤트 발생을 처리하는 함수
- `이벤트 핸들러(event handler)`라고도 한다.

#### 등록
크게 2가지 방법이 있다.

1. HTML 요소 속성 사용
2. addEventListener() 사용

##### HTML 요소 속성
- onclick 등 HTML 속성에 값으로 이벤트 리스너를 제공할 수 있다.

```
<!--HTML-->
<p onclick="alert('여기를 클릭하셨습니다.');">버튼</p>
```

```
// JavaScript
var p = document.getElementsByTagName("p")[0];
p.onclick = function() { alert("여기를 클릭하셨습니다."); }
```

##### addEventListener()
- 요소 노드의 메소드인 addEventListener()로 이벤트 리스너를 등록할 수 있다.
- 속성 방식과 달리, 한 이벤트 타입에 여러 개의 이벤트 리스너를 등록할 수 있다.

> addEventListener(`event-name`, `function`, _`prop-method`_)
> `event-name` = 추가할 이벤트 타입
> `function` = 추가할 이벤트 리스너
> `prop-method` = 이벤트 전파 방식 (false: bubbling(기본값), true: capturing)

```
var p = document.getElementsByTagName("p")[0];
p.addEventListener("click", function() { alert("여기를 클릭하셨습니다."); });
```

#### 삭제
- removeEventListener()를 사용해 이벤트 리스너를 삭제할 수 있다.

> removeEventListener(`event-name`, `function`)
> `event-name` = 삭제할 이벤트 타입
> `function` = 삭제할 이벤트 리스너


```
var p = document.getElementsByTagName("p")[0];

// 마우스를 올리면 글자색이 바뀝니다.
function overP() { p.style = "color:orange"; }
function outP() { p.style = "color:black"; }
function clickP() { 
	alert("호버 이벤트가 종료되었습니다.");
	p.removeEventListener("mouseover", overP);
	p.removeEventListener("mouseout", outP);
	p.style = "color:grey";
}

p.addEventListener("click", clickP);
p.addEventListener("mouseover", overP);
p.addEventListener("mouseout", outP);
```

#### 호출
한 이벤트 타입에 여러 이벤트 리스너가 있다면, 호출 순서는 다음과 같다.

1. HTML 요소의 속성에 등록된 이벤트 리스너
2. addEventListener()로 등록된 이벤트 리스너 (여러 개라면 등록 순서대로)

### 이벤트 객체 (Event Object)
- `이벤트 객체`: 해당 타입의 이벤트에 대한 상제 정보를 저장한 객체
- 이벤트 객체는 이벤트 리스너가 호출될 때 인수로 전달된다.

|프로퍼티|의미|
|---|---|
|type|이벤트 타입|
|target|이벤트를 호출한 대상|

|메소드|의미|
|---|---|
|preventDefault()|해당 이벤트의 기본 동작을 실행하지 않음|
|stopPropagation()|이벤트 전파를 취소함|

```
<p id="Event">Event</p>
<p id="Object">Object</p>
<script>
	function clickEvent(event) {
		// event는 이벤트 객체입니다.
		// 호출한 요소 노드의 id를 출력합니다.
		alert(event.target.id);
	}

	var pList = document.getElementsByTagName("p");
	for(p of pList) {
		p.addEventListener("click", clickEvent);
	}
</script>
```

### 이벤트 전파 (Event Propagation)
- `이벤트 전파`: 이벤트 발생시, 이벤트 리스너를 실행할 요소의 순서를 결정하는 과정
- 2가지 이벤트 전파 방식이 있다.

1. 버블링(bubbling) 전파 방식
2. 캡쳐링(capturing) 전파 방식

#### 버블링
- `버블링`: 이벤트 발생 노드에서 최상위 노드(window) 방향으로 전파되는 방식
- addEventListener의 기본 전파 방식이다.

```
<div id="div">
	<p id="p">
		<span id="span">Button</span>
	</p>
</div>
<script>
	var div = document.getElementById("div");
	var p = document.getElementById("p");
	var span = document.getElementById("span");

	// 클릭하면 span => p => div 순서대로 실행됩니다.
	div.addEventListener("click", function () { alert("div"); });
	p.addEventListener("click", function () { alert("p"); });
	span.addEventListener("click", function () { alert("span"); });
</script>
```

#### 캡쳐링
- `캡쳐링`: 최상위 노드(window)에서 이벤트 발생 노드 방향으로 전파되는 방식
- addEventListener의 3번째 인자를 true로 주면 된다.

```
<div id="div">
	<p id="p">
		<span id="span">Button</span>
	</p>
</div>
<script>
	var div = document.getElementById("div");
	var p = document.getElementById("p");
	var span = document.getElementById("span");

	// 클릭하면 div => p => span 순서대로 실행됩니다.
	div.addEventListener("click", function () { alert("div"); }, true);
	p.addEventListener("click", function () { alert("p"); }, true);
	span.addEventListener("click", function () { alert("span"); }, true);
</script>
```

#### 전파 취소
- 이벤트 객체의 메소드로 기본 동작을 막거나 전파를 취소할 수 있다.

```
<div id="div">
	<p id="p">
		<a href="www.google.com" id="a">
			<span id="span">Button</span>
		</a>
	</p>
</div>
<script>
	function aEvent(event) {
		// a의 기본 동작을 취소합니다. (링크가 실행되지 않습니다)
		event.preventDefault();
		event.stopPropagation();
		alert("a");
	}
	
	var div = document.getElementById("div");
	var p = document.getElementById("p");
	var a = document.getElementById("a");
	var span = document.getElementById("span");

	// 클릭하면 div => p => a 까지만 실행됩니다.
	div.addEventListener("click", function () { alert("div"); }, true);
	p.addEventListener("click", function () { alert("p"); }, true);
	a.addEventListener("click", aEvent, true);
	span.addEventListener("click", function () { alert("span"); }, true);
</script>
```

## 예외 (Exception)
### 예외 처리 (Exception Handling)
- 자바스크립트에선 예외 처리를 담당하는 `try / catch / finally`문을 제공한다.
- `try`: 처음으로 실행되는 영역. 이 구간에서 예외가 발생하면 즉시 catch로 이동한다.
- `catch`: 예외 발생시 실행되는 영역. 인자로 throw가 던져준 값을 갖는다.
- `finally`: 예외 상관없이 항상 마지막에 실행되는 영역
- catch, finally는 반드시 사용하지 않아도 되는 선택적인 옵션이다.
- `throw`: 예외를 발생시키는 키워드
	- number, Error 객체 등 대부분 타입이 올 수 있으며, 이 값은 catch의 인자로 전달된다.
- `Error`: 에러 정보를 저장하는 객체
- 자바스크립트에서 런타임 오류가 발생하면, 해당 오류 정보를 저장하는 Error 객체의 인스턴스가 생성된다.

> try {
> 	// 예외가 발생할 수 있는 작업 영역
> }
> catch (`error`) {
> 	// 예외 발생시 실행되는 영역
> }
> finally {
> 	// try나 catch 구간이 끝나고 실행되는 영역
> }

> throw `error`

```
var loop = true;
while(loop) {
	try {
		var word = prompt("길이가 2-3인 단어를 입력하세요.", "");
		if(word.length <= 3) {
			if(word.length >= 2)
				alert("입력된 단어는 " + word + "입니다.");
			else
				throw 0;
		}
		else
			throw 1;
	}
	catch(e) {
		if(e == 0)
			alert("단어 길이가 2보다 작습니다.");
		else
			alert("단어 길이가 3보다 큽니다.");
	}
	finally {
		loop = confirm("계속 진행할까요?");
	}
}
```

### strict 모드
- `strict 모드`는 자바스크립트 코드에 보다 엄격한 오류 검사와 향상된 보안 기능을 제공한다.
- 스크립트나 함수의 맨 처음에 다음 지시어를 추가하면, 해당 블록에 strict 모드가 적용된다.

> "use strict"

strict 모드에서 대표적인 변경사항은 다음과 같다.
- 선언되지 않은 변수는 사용 불가
- eval() 함수 내에서 선언된 변수는 외부에서 사용 불가
- 읽기 전용 프로퍼티에 대입 불가
- 한 프로퍼티를 여러 번 정의 불가
- 함수를 구문이나 블록 내에서 선언 불가
- 중복된 매개변수 불가
- arguments 객체의 요소 값 변경 불가
- 문자열 "eval", "arguments" 사용 불가
- delete 키워드 사용 불가
- with 문 사용 불가
- 일부 예약어 사용 불가

## 정규 표현식 (Regular Expression)
- 자바스크립트에선 `정규 표현식`을 지원하며, 정규 표현식으로 문자열을 자세히 검색할 수 있다.

### 생성
- 정규 표현식을 생성하는 방법은 다음과 같다.
- 생성한 정규 표현식은 변수로 저장할 수 있다.

1. 리터럴 방식
2. RegExp 객체 사용

> /`expression`/`flag`
> new RegExp("`expression`");

### 검색
- String의 search() 메소드로 정규 표현식을 사용할 수 있다.

```
var str = "asd abc asd";
var reg = new RegExp("abc");
console.log(str.search(reg)); // 4
```

### 플래그 (Flags)
- 정규 표현식을 생성할 때, 플래그 옵션을 추가할 수 있다.

|플래그|기능|
|---|---|
|i|대소문자 구분 없음|
|g|일치하는 모든 부분 선택|
|m|여러 줄의 입력 문자열을 변경없이 그 상태로 검색|
|y|대상 문자열의 현재 위치부터 비교 시작|

### 특수 문자
- 자바스크립트에서 사용 가능한 정규 표현식의 특수 문자 목록은 다음과 같다.

|조건|기능|
|---|---|
|\\|이 문자 다음에 일반 문자가 나오면 이스케이프 문자, 특수 문자가 나오면 특수 문자 그대로 해석|
|\\d|숫자 검색|
|\\D|숫자가 아닌 문자 검색|
|\\w|영문자, 숫자, 언더스코어(`_`) 검색|
|\\W|영문자, 숫자, 언더스코어(`_`)가 아닌 문자 검색|
|\\s|공백 문자(스페이스, 탭, 줄바꿈) 검색|
|\\S|공백 문자가 아닌 문자 검색|
|\b|입력 문자열에서 모든 단어의 맨 앞이나 맨 뒤가 패턴과 일치하는지 검색|

```
var str = "abcd123efgh";
var reg = /\d/;

// 숫자 검색
console.log(str.search(reg)); // 4
```

```
var str = "123 cab qwe";
var reg = /ab\b/;

// 단어 123, cab, qwe을 대상으로 비교
console.log(str.search(reg)); // 5
```

### 양화사

|양화사|의미|
|---|---|
|`n`\*|문자 `n`이 0회 이상 출현하는지 검색|
|`n`+|문자 `n`이 1회 이상 출현하는지 검색|
|`n`\?|문자 `n`이 0회 or 1회만 출현하는지 검색|

```
var str = "abccdccba";
var reg = /cd+/;

// c 다음에 d가 1회 이상 출현하는지 검색
console.log(str.search(reg)); // 3
```

### 괄호

|괄호|의미|
|---|---|
|(`abc`)|괄호 내 문자열을 저장함|
|\[`abc`\]|괄호 내 문자열을 검색함|
|\[`0`-`9`\]|괄호 내 숫자를 검색함 (`0`부터 `9`까지)|
|\[\\b\]|백스페이스 문자 검색|
|{`n`}|앞의 문자가 n번 나타나는지 검색|
|{`n`, `m`}|앞의 문자가 최소 n번 이상, 최대 m번 이하 나타나는지 검색|

- ()으로 저장된 문자열은 String.replace()에선 `$1`, `$2`, ... , `$n`, 같은 정규 표현식 내에선 `\1`, `\2`, ... , `\n`으로 참조할 수 있다.

```
var str = "abccdccba";
var reg = /(c)(d+)/;

// 검색한 패턴을 제공한 문자열로 대체
console.log(str.replace(reg, "#$2#$1#")); // abc#d#c#ccba
```

### 위치 문자

|문자|의미|
|---|---|
|^`a`|단어의 맨 앞에 패턴 `a`가 나타나는지 검색|
|`a`$|단어의 맨 뒤에 패턴 `a`가 나타나는지 검색|

```
var str = "abc";
var reg = /^a/;

// 단어의 시작이 a인지 검색
console.log(str.search(reg)); // 0
```

### RegExp
- `RegExp`: 정규 표현식을 담당하는 표준 객체
- 생성 방법은 다음과 같다.

> new RegExp(`exporession`\[, `flag`\]);

#### RegExp.prototype

|프로퍼티|의미|
|---|---|
|global|플래그 g 활성 유무|
|ignoreCase|플래그 i 활성 유무|
|multiline|플래그 m 활성 유무|
|source|검색 패턴이 포함한 문자열|

|메소드|반환|기능|
|---|---|---|
|exec(`string`)|object|입력 문자열 `string` 대상으로 검색한 결과를 객체 형태로 정리해서 반환 (검색 실패시 null 반환)|
|test(`string`)|boolean|입력 문자열 `string` 대상으로 검색해서 일치한 패턴이 있다면 true 반환|
|toString()|string|정규 표현식을 string으로 반환|

```
var reg = new RegExp("abc");

// [ 'abc', index: 2, input: 'bcabcbc', groups: undefined ]
console.log(reg.exec("bcabcbc"));

// false
console.log(reg.test("bcacbc"));
```

## 출처 (Reference)
http://www.tcpschool.com/javascript/intro
