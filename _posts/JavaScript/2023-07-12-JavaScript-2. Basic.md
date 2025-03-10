---
categories:
- JavaScript
date: '2023-07-12'
title: '[JavaScript] 2. Basic'
---

{% raw %}
- 실행문 끝에 세미콜론 `;`을 사용합니다.
- 자바스크립트에선 모든 부분에서 대소문자를 구분합니다.
- 자바스크립트는 공백에 민감하지 않습니다.
	- 공백의 수가 코드 실행에 큰 영향을 주지 않습니다.
- `리터럴(literal)`: 값 그 자체
- `식별자(identifier)`: 어떤 변수/함수를 식별하는 이름
	- 식별자 가능 문자: 영문자, 숫자, 언더스코어`_`, `$`
	- 식별자는 숫자로 시작할 수 없습니다.
- `키워드(keyword)/예약어(reserved word)`: 자바스크립트에서 특정 용도로 사용되는 미리 예약된 단어
	- var, function, class ...
	- 예약어는 식별자로 사용할 수 없습니다.

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
- 자바스크립트에선 관행적으로 Camel Case를 주로 사용합니다.

```
var newSuperVar;   // Camel Case
var new_super_var; // Underscore Case
```

### 주석 (Comment)
- `//`, `/* */`를 사용해서 주석을 작성할 수 있습니다.

```
// 한 줄 주석
/* 여러 줄 주석 */
```

### 출력 (Print)
- 디버깅 등 용도로 자바스크립트의 결과를 바로 출력할 필요가 있습니다. 
- 다음은 자바스크립트의 결과를 확인할 수 있는 방법 목록입니다.

1. window.alert()
2. innerHTML
3. document.write()
4. console.log()

#### window.alert()
- 브라우저의 대화 상자를 표시해서 출력을 확인할 수 있습니다.

```
var res = "출력할 값";
window.alert(res);
```

#### innerHTML
- HTML 요소의 내용을 변경해서 출력을 확인하는 방법입니다.

```
var res = "출력할 값";
document.getElementById("goal").innerHTML = res;
```

```
<p id="goal">여기에 결과가 출력됩니다.</p>
```

#### document.write()
- 웹 페이지에 새로운 데이터를 추가하여 출력을 확인하는 방법입니다.

```
var res = "출력할 값";
document.write(res);
```

#### console.log()
- 콘솔 화면에 출력하는 방법입니다.
- 웹 페이지에 영향을 주지 않으므로 디버깅 용도로 적합합니다.

```
var res = "출력할 값";
console.log(res);
```

### 타입 (Type)
- `타입(type)`: 다룰 수 있는 값의 종류
- `기본 타입`: 자바스크립트에서 미리 정의한 타입
	- 원시 타입과 객체 타입으로 구분됩니다.

#### 원시 타입
- 원시 타입은 값 그 자체가 변수에 저장됩니다.
- 원시 타입의 값 자체는 변하지 않는 `불변성`을 가집니다. 만약 변수에 저장된 값을 바꾸고 싶다면 새로운 값을 대입해야 합니다.

1. `숫자(number)`
2. `문자열(string)`
3. `불리언(boolean)`
4. `심볼(symbol)`
5. `undefined`

##### 숫자 (number)
- 자바스크립트에선 정수, 실수를 하나의 타입으로 취급합니다.
	- 특정 메소드로 정수와 실수를 구분할 수는 있습니다.
- e 표기법을 사용할 수 있습니다.

```
-5    // 정수
12.5  // 실수
10e4  // 10000
10-4  // 0.0001
```

##### 문자열 (string)
- `"`, `'`을 감싸서 표현합니다.
- 문자열 내에 `"`을 포함한다면 `'`을 사용하면 됩니다. (그 반대도 성립합니다.)

```
"문자열 데이터 1"
'문자열 데이터 2'
"'인용'한 문자열 1"
'"인용'한 문자열 2'
```

##### 불리언 (boolean)
- `true`, `false` 2가지 값을 가질 수 있습니다.
- 이 값들은 `진리값`으로, 어떤 조건이 참인지 거짓인지를 판별하는데 사용됩니다.

```
true
false
```

##### 심볼 (symbol)
- ES2015에 새로 추가된 타입입니다.
- 유일하고 변경할 수 없습니다.
- 식별자로 사용할 수 있습니다.

```
Symbol("sym");
```

##### undefined vs null
- `undefiend`: '타입'이 정해지지 않음을 의미하는 타입 (=타입이 없음)
- `null`: '값'이 정해지지 않음을 의미하는 object 타입 (=객체가 없음)

|값|타입|
|---|---|
|undefiend|undefiend|
|null|object|

- 타입이 다르므로 동등 연산자(\=\=)와 일치 연산자(\=\=\=)의 값이 다릅니다!
```
null == undefiend   // true
null === unfefined  // false
```

#### 객체 타입
- `객체(object)`: 여러 프로퍼티(property), 메소드(method)를 묶은 일종의 집합체 타입
- 객체는 레퍼런스 형태로 변수에 담깁니다.
- 객체 그 자체는 바뀔 수 있는 `가변성` 특성을 가집니다. 그렇기에 const 변수라도 객체 자체는 변경될 수 있습니다.

```
const obj = { name: "object", id: 1 };
obj.id = 2; // 가능!
```

### 타입 변환
자바스크립트는 타입이 유연한 편입니다.

#### 암시적 타입 변환 (implicit type conversion)
- 예상되는 타입의 값이 배치될 곳에 다른 타입의 값이 온다면, 자바스크립트가 자동으로 타입을 통일시킵니다.
- 만약 암시적 타입 변환이 불가능하다면 오류가 발생합니다.

```
var str = "10 + 5 = ";
var res = str + 15;
/* 15는 문자열로 변환됩니다. 따라서 res의 값은 "10 + 5 = 15"입니다. */
```

#### 명시적 타입 변환 (explicit type conversion)
- 자바스크립트에서 기본 제공하는 전역 함수 등으로 명시적으로 타입을 바꿀 수 있습니다.

##### to number
- Number(`A`)
- parseInt(`A`): `A`를 특정 진법의 정수로 변환합니다.
- parseFloat(`A`): `A`를 실수(float)로 변환합니다.

##### to string
- String(`A`)
- `A`.toString(): 단, `A`는 null, undefined가 아닙니다.

##### to boolean
- Boolean(`A`): `A`가 truthy면 true, 그렇지 않으면 false를 반환합니다.
- `truthy`: boolean으로 변환시 true가 되는 값
- `falsy`: boolean으로 변환시 false가 되는 값
- 자바스크립트에선 다음 값만이 falsy고, 그 외는 모두 truthy입니다. 
	- `false`
	- `0`
	- `null`
	- `undefined`
	- `NaN`
	- `""`

##### to object
- Object(`A`): `A`를 사용해 객체를 생성합니다.

### 변수 (Variable)
- `변수(Variable)`: 데이터를 저장할 수 있는 메모리 공간
- 예약어 `var`를 사용해서 변수를 선언할 수 있습니다.
- ES2015에 추가된 `let`, `const`으로도 변수를 선언할 수 있습니다.
- 변수의 이름은 `식별자(identifier)`입니다.
- 선언, 초기화는 동시에 할 수 있습니다.
- 쉼표`,` 연산자를 사용해서 동시 선언 및 초기화가 가능합니다.
- 같은 변수에 다른 타입의 값을 대입할 수 있습니다.
- 일반적으로 재선언은 불가능합니다.
- 초기화되지 않은 변수는 undefined 값을 갖습니다.

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
- 자바스크립트는 정수/실수를 구분하지 않고, 실수로 통일해서 사용합니다.
- 자바스크립트는 실수를 `64bit 부동소수점(floating point)`으로 표현합니다.
	- 소수 연산에서 정수부는 15자리, 소수부는 17자리까지만 정밀도를 보장합니다.
- 자바스크립트는 기본적으로 10진법을 사용합니다.
- `0x` 접두사를 사용하면 16진법으로 표현됩니다.

#### Infinity
- `Infinity`: 양의 무한대를 의미하는 number 값
- `-Infinity`: 음의 무한대를 의미하는 number 값
- 위 값들은 읽기 전용 값이며, 어떤 수보다도 큰 수로 취급됩니다.

```
var x = 10 / 0;               // Infinity
var y = Infinity * 10;        // Infinity
var z = 1 / Infinity;         // 0
console.log(typeof Infinity); // number
```

#### NaN
- `NaN`: 'Not a Number'의 약자로, 정의되지 않은 수를 의미하는 number 값
- 0을 0으로 나누거나, number 타입 변환이 불가능한 값으로 산술 연산을 시도하는 경우에 이 값이 반환됩니다.
- 읽기 전용 값입니다.
- NaN는 자바스크립트 값 중에서 유일하게 자기 자신과 같지 않은 값입니다.
	- 비교 연산자(\=\=, \=\=\=)로 NaN를 판별할 수 없습니다.
	- NaN를 판별하려면 Number.isNaN() 등 특정 메소드를 사용해야 합니다.

```
var x = 100 - "10";       // 10
var y = 100 - "ten";      // NaN
var z = 0 / 0;            // NaN
console.log(typeof NaN);  // number
console.log(NaN === NaN); // false
```

#### -0
- 자바스크립트에서 `-0`과 `0`은 별개의 값입니다.
- 일반적인 상황에선 두 값은 동일하다고 간주됩니다. 단, 다음 상황에서는 다른 값으로 취급됩니다.

```
Object.is(0, -0); // false
1 / 0;  // Infinity
1 / -0; // -Infinity
```

#### null, undefined, NaN, Infinity

|값|타입|boolean|number|의미|
|---|---|---|---|---|
|null|object|false|0|값이 정해지지 않음|
|undefined|undefined|false|NaN|타입이 정해지지 않음|
|NaN|number|false|NaN|수가 아님|
|Infinity|number|true|Infinity|무한대|

### 문자열
- 자바스크립트에서 문자열은 `"`, `'`으로 표현됩니다.
- 한 종류의 따옴표를 사용하면 내부에 다른 종류의 따옴표를 넣을 수 있습니다.

> "string"<br>
> 'string'<br>
> "this is 'string'!"<br>
> 'this is "string"!'<br>

#### 문자열 결합
- `+` 연산자를 활용해서 문자열을 결합할 수 있습니다.

> "more " + "string!"<br>

```
console.log("more " + "string!"); // more string!
```

#### 이스케이프 시퀀스 (Escape Sequence)
- 일부 예약된 문자는 문자열 내부에서 바로 표현할 수 없습니다.
- 이때는 문자 앞에 `\`를 붙이면 문자 그 자체로 인식이 되어 문제가 해결됩니다.
	- 이러한 방법을 `이스케이프 시퀀스`라고 합니다.

|표기법|문자|
|---|---|
|\\'|'|
|\\"|"|
|\\\\|\\|
|\\\$|\$|
|\\\`|\`|
|\\n|줄바꿈|
|\\t|탭|
|\\r|캐리지 리턴|
|\\x|16진수|
|\u|유니코드 문자|

```
"this is \"string\"!" // this is "string"!
\xA2    // 16진수로 인식
\u00A2  // 유니코드로 인식
```

#### 템플릿 리터럴 (Template Literal)
- `템플릿 리터럴`은 backtick(\`)으로 문자열을 표현하는 방법입니다.
- ES2015에서 새로 도입된 문자열 리터럴 방식입니다.
- 내삽(interpolation) 기능으로 문자열을 동적으로 생성할 수 있습니다.
- 줄바꿈이 포함된 문자열도 간편하게 표현할 수 있습니다. (일반 표기법에서 줄바꿈을 표현하려면 \\n을 사용해야 합니다.)

- 내삽 기능의 사용법은 다음과 같습니다.
> ${`variable`}<br>

```
var s1 = `String`;
var s2 = `Super ${s1}`;
var s3 = `Fantastic
${s2}
!!
`;

console.log(s1);
console.log(s2);
console.log(s3);
```

```
// 실행 결과
String
Super String
Fantastic
Super String
!!
```

### 변수 스코프 (Variable Scope)
- 변수는 유효 범위를 기준으로 2가지로 구분할 수 있습니다.

1. 지역 변수
2. 전역 변수

#### 지역 변수 (Local Variable)
- `지역 변수`: 함수/블록 내에서 선언된 변수
- 지역 변수는 선언된 함수/블록 내에서만 유효하며, 함수/블록 종료시 메모리에서 사라집니다.
- 함수의 매개변수도 해당 함수의 지역 변수에 속합니다.

```
function genNum() {
	var num = 5;
	console.log(typeof num);
}
genNum();
console.log(typeof num);
```

```
// 실행 결과
number
undefined
```

#### 전역 변수 (Global Variable)
- `전역 변수`: 함수/블록의 외부에서 선언된 변수
- 전역 변수는 어느 영역에서든 접근 가능하며, 프로그램이 종료되어야 메모리에서 사라집니다.
- 전역 변수는 wndow 객체의 프로퍼티입니다.
- 변수 선언 키워드(var, let, const)를 사용하지 않고 선언한 변수는 전역 변수입니다.
- 전역 변수와 지역 변수의 이름이 동일한 경우는, 지역 변수가 우선시됩니다.
	- 전역 변수를 사용하려면, window 객체의 프로퍼티임을 명시하면 됩니다.

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

```
// 실행 결과
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

```
// 실행 결과
local
global
```

### 변수 키워드 종류
- ES2015에는 새로운 변수 선언 키워드인 `let`, `const`이 추가되었습니다. 이들은 기존 `var`와는 몇몇 점이 다릅니다.
- 코드의 안정성 측면에서 `const`가 가장 안전합니다. 그 다음은 `let`이며, `var`는 가급적 사용하지 않는 것이 좋습니다.

| |var|let|const|
|---|---|---|---|
|스코프 기준|함수|블록|블록|
|재선언 가능|O|X|X|
|값 재할당 가능|O|O|X|
|호이스팅 이후 값|undefined|-|-|
|우선도 순위|3|2|1|

#### var
- `var`는 ES2015 이전에 변수를 선언하는 유일한 키워드입니다.
- `var` 변수의 유효 범위는 **함수**를 기준으로 합니다.
	- 함수 내부에서 선언된 변수는 `지역 변수`,  함수 외부에서 선언된 변수는 `전역 변수`입니다.
- `var` 변수는 재선언이 가능합니다.
- 함수 호이스팅 적용 이후, 선언 이전의 `var` 변수를 사용하면 undefined 값으로 참조됩니다.
- 함수 스코프와 재선언이 가능하다는 점에서, `var`는 불안정하고 의도치 않은 동작이 발생할 수 있다는 문제점이 있습니다.

#### let
- `let` 변수의 유효 범위는 **블록**을 기준으로 합니다.
	- `블록(block)`은 `{}`로 묶인 부분을 의미합니다. 함수뿐만 아니라 if, for 제어문도 블록입니다.
	- 블록 내부에서 선언된 변수는 `지역 변수`,  블록 외부에서 선언된 변수는 `전역 변수`입니다.
- `let` 변수는 재선언이 불가능합니다.
- 함수 호이스팅 적용 이후, 선언 이전의 `let` 변수를 사용하면 참조 오류가 발생할 것입니다.

#### const
- `const` 변수의 유효 범위는 **블록**을 기준으로 합니다.
- `const` 변수는 재선언이 불가능합니다.
- `const` 변수는 값 재할당이 불가능합니다.
	- 단, 가리키는 값 자체가 바뀔 수는 있습니다.
	- 객체의 프로퍼티는 변경이 가능합니다.
- `const` 변수는 반드시 선언 동시에 초기화되어야 합니다.
- 함수 호이스팅 적용 이후, 선언 이전의 `const` 변수를 사용하면 참조 오류가 발생할 것입니다.
{% endraw %}