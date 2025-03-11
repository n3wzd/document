---
categories:
- JavaScript
date: '2023-07-16'
title: '[JavaScript] 6. Function'
---

{% raw %}
- `함수(function)`: 특정 목적의 단일 작업을 수행하도록 설계된 독립적인 블록
	- 필요할 때마다 호출하여 해당 작업을 수행할 수 있습니다.
- 자바스크립트에서 함수는 별개의 타입(type)으로 취급됩니다.
	- 함수를 변수에 대입하는 것이 가능합니다.
- 하나의 함수가 다른 함수 내에 중첩되어 정의될 수 있습니다.
- 자바스크립트에서 모든 함수는 `Function` 객체로 다뤄집니다.
	- 즉, 자바스크립트에서 함수는 객체입니다!
	- 함수는 `Function` 생성자의 인스턴스입니다.

### 사용법
#### 정의

> function `name`(_`param1`, `param2`, ..._) {<br>
> 	(주어진 목적의 작업을 수행하는 실행문)<br>
> 	_return `result`_<br>
> }<br>

- `name`: 함수의 이름 (=함수를 구분하는 식별자)
- `param`: 함수 내에서 활용될 수 있는 매개변수
- `result`: 함수가 반환(return)문을 포함할 경우, 함수가 반환하는 값
	- 반환문은 함수의 실행을 즉시 중단하고 주어진 값을 반환합니다.
	- 반환값은 모든 타입이 올 수 있습니다.

```
function addNum(n1, n2) {
	return n1 + n2;
}
```

#### 호출
- 호출할 함수의 이름과 인자를 제공해서, 해당 함수를 호출할 수 있습니다.

> `name`(`argument1`, `argument2`, ...)<br>

```
console.log(addNum(1, 2));  // 3
```

#### 값
- 자바스크립트에서 함수는 값으로 활용될 수 있습니다.
- 함수를 변수에 대입하거나, 다른 함수에 함수를 전달하는 것이 가능합니다.

```
var func = addNum;
console.log(func(2, 4));  // 6
```

### this
- `this` 키워드는 현재 함수를 호출한 객체를 가리킵니다.
- 일반적으로 this는 메소드 내에서 사용됩니다. 메소드 내에서 사용되는 this는 해당 메소드를 포함한 객체를 가리킵니다.
	- this를 사용해서 객체 내부에서 사용되는 프로퍼티임을 명시할 수 있습니다.
- 현재 함수를 호출한 객체가 지정되지 않았다면 undefined가 반환됩니다.
	- 단, 함수를 전역에서 호출한다면 전역 객체를 가리킵니다.
	- `strict 모드`에선 다시 undefined가 반환되도록 수정됩니다.
- bind() 등 메소드를 통해 this가 특정 객체를 가리리게 할 수 있습니다.

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

```
function printHp() {
	// 이때 this는 자신을 호출한 객체입니다.
	console.log(this.hp);
}
function Item(hp) {
	this.hp = hp;
    this.show = printHp;
}
const item1 = new Item(100);
const item2 = new Item(200);
item1.show(); // 100
item2.show(); // 200
```

### 매개변수 (Parameter)
- `매개변수(parameter)`: 함수 정의에서 전달받은 인수를 함수 내부로 전달하기 위해 사용하는 변수
- `인수(argument)`: 함수 호출에서 함수로 전달되는 값

> function poo(`parameter1`, `parameter2`, ...) { ... }<br>
> poo(`argument1`, `argument2`, ...);<br>

- 함수 정의시, 매개변수의 타입을 명시하지 않습니다.
- 함수 호출시, 인수의 타입을 검사하지 않습니다.
- 자바스크립트에서 매개변수의 기본값은 undefined 값입니다.
	- 함수 호출시, 제공한 인수의 개수가 정의된 매개변수의 개수보다 적다면, 나머지 매개변수에는 자동으로 undefined 값이 할당됩니다.

```
function printTriple(a, b, c) {
	console.log(a + ", " + b + ", " + c);
}
printTriple("Java", "Script");
```

```
// 실행 결과
Java, Script, undefined
```

#### 디폴트 매개변수 (Default Parameter)
- `디폴트 매개변수`: 함수 호출시, 명시된 매개변수에 인자가 제공되지 않은 경우에 사용할 기본값

> function `name`(`param`=`default`, ...) {<br>
> 	...<br>
> }<br>

```
function mulNum(a, b=1) {
	return a * b;
}
console.log(mulNum(4, 5));   // 20
console.log(mulNum(4));      // 4
```

#### 나머지 매개변수 (Rest Parameter)
- `나머지 매개변수`: 앞에 명시된 개별 매개변수 외의 매개변수들을 묶은 매개변수 배열
- 생략 접두사(`...`)로 표현됩니다.

> function `name`(`param1`, `param2`, ... , ...`params`) {<br>
> 	...<br>
> }<br>

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

```
// 실행 결과
9
4
10
```

### 미리 정의된 전역 함수 (Predefined Functions)
- 자바스크립트에서 편의성을 위해 여러 전역 함수를 미리 정의하여 제공합니다.

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
- 문자열로 표현된 자바스크립트 코드를 수행합니다.
- 코드에서 결과값이 존재하면 해당 값을 반환합니다.

```
eval("var a = 10, b = 30");
console.log(eval("a * b"));   // 300
```

#### isFinite()
- 전달된 값이 유한한 수면 true를 반환합니다.
- 전달된 값이 number가 아니면 number로 변환해서 검사합니다.
	- 변환이 불가능하면 false를 반환합니다.

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
- 전달된 값이 NaN면 true 반환합니다.
- 전달된 값이 number가 아니면 number로 변환해서 검사합니다.
	- 변환이 불가능하면 true를 반환합니다.
- number 강제 변환이 불확실하기에 ECMAScript6부터는 Number.isNan() 사용이 권장됩니다.

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
- 문자열을 파싱한 부동소수를 반환합니다.
- 변환 실패시, NaN를 반환합니다.

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
- 문자열을 파싱한 정수를 반환합니다.
- 변환 실패시, NaN를 반환합니다.
- 2번째 인자로 특정 진법을 전달하면, 주어진 문자열을 해당 진법으로 표현된 수로로 인식하고 변환을 수행합니다.
- 문자열이 "0x"으로 시작하면 16진수로 변환을 수행합니다.

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
- URI를 이스케이프 시퀸스(escape sequences) 처리하여 부호화합니다. (특수문자 제외)

```
var uri = "http://google.com/search.php?name=abc&word=검색";
console.log(encodeURI(uri));
```

```
// 실행 결과
http://google.com/search.php?name=abc&word=%EA%B2%80%EC%83%89
```

#### encodeURIComponent()
- URI의 모든 문자를 이스케이프 시퀸스 처리하여 부호화합니다.

```
var uri = "http://google.com/search.php?name=abc&word=검색";
console.log(encodeURIComponent(uri));
```

```
// 실행 결과
http%3A%2F%2Fgoogle.com%2Fsearch.php%3Fname%3Dabc%26word%3D%EA%B2%80%EC%83%89
```

#### decodeURI()
- encodeURI()로 부호화한 URI를 복호화합니다.

```
var uri = "http://google.com/search.php?name=abc&word=검색";
var enc = encodeURI(uri);
console.log(decodeURI(enc));
```

```
// 실행 결과
http://google.com/search.php?name=abc&word=검색
```

#### decodeURIComponent()
- encodeURIComponent()로 부호화한 URI를 복호화합니다.

```
var uri = "http://google.com/search.php?name=abc&word=검색";
var enc = encodeURIComponent(uri);
console.log(decodeURIComponent(enc));
```

```
// 실행 결과
http://google.com/search.php?name=abc&word=검색
```

#### Number()
- 주어진 값을 number 타입으로 변환합니다.
- 변환 실패시 NaN를 반환합니다.

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
- 주어진 값을 string 타입으로 변환합니다.

```
Number(123);        // "123"
Number(123.45");    // "123.45"
Number(true);       // "true"
Number(false);      // "false"
Number(null);       // "null"
```

### 함수 호이스팅 (Hoisting)
- `함수 호이스팅`: 함수 내부의 모든 변수 선언이 해당 함수의 블록 맨 처음으로 이동하는 메커니즘
- 함수 호이스팅으로 인해, 함수 블록 첫 부분에 변수를 선언하는 것이 좋습니다.

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

- 위 예제는 자바스크립트 내부에서 함수 호이스팅에 의해 다음 예제처럼 변경되어 처리됩니다.
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

### 익명 함수 (Anonymous Function)
- 자바스크립트에서 함수를 선언할 때 이름을 붙이지 않을 수 있습니다. 이러한 함수를 `익명 함수` 또는 `함수 리터럴`이라고 합니다.
- 이름이 없으므로 익명 함수만으로는 호출이 불가능합니다.
- 익명 함수는 주로 함수를 인자로 넘겨줄 때 사용됩니다.

```
function(x, y) {
	return x + y;
};
```

### 화살표 함수 (Arrow Function)
- `화살표 함수`는 ES2015부터 도입된 새로운 함수 표기법입니다.
- 표기법이 간단하기에 주로 함수를 인자로 전달할 때 사용됩니다.
- 화살표 함수만의 특징으로 인해 객체의 메소드를 정의할 때는 사용하지 않는 것이 좋습니다.

> (`param1`, `param2`, ...) \=\> { ... }<br>

```
const mix = (hp, mp) => { return hp + mp; };<br>
```

조건에 따라 더 간결하게 표현할 수 있습니다.
- 화살표 함수의 매개변수가 1개면, 괄호를 생략할 수 있습니다.
- 화살표 함수 내부의 구문이 1개면, 중괄호를 생략할 수 있습니다. 또한 구문의 결과값이 해당 함수의 반환값이 됩니다.

> `param` \=\> `statement`<br>

```
const buff = hp => hp * 2;<br>
```

화살표 함수는 function 구문으로 정의되는 일반적인 함수와 다른 점이 있습니다.
- 화살표 함수는 생성자로 사용될 수 없습니다.
	- `prototype` 프로퍼티가 존재하지 않습니다.
	- `new.target`를 사용할 수 없습니다.
- 화살표 함수는 자신만의 `this`, `arguments`, `super`를 가지지 않습니다.
	- 화살표 함수 내에서 이 프로퍼티들은 각각 해당 함수가 정의된 스코프의 것을 가리킵니다.
	- 예를 들어, 화살표 함수의 this는 이 함수가 정의된 스코프의 this와 동일합니다. 또한 화살표 함수의 this는 strict 모드의 영향을 받지 않으며, bind() 등을 통한 강제 변경도 불가능합니다.
- 화살표 함수 내에서 `yield`를 사용할 수 없습니다.

```
// 생성자 함수
function Item(name) {
	this.name = name;
	this.show = () => this.name;<br>
}
const item1 = new Item("Sword");

// 리터럴
const item2 = {
	name: "Spear",
	show: () => this.name<br>
}

// 생성자 함수 내 this는 인스턴스(item1)입니다.
console.log(item1.show()); // "Sword"

// 리터럴 내 this는 Object.prototype의 복사본입니다.
console.log(item2.show()); // undefined
```

### 고차 함수 (Higher-order Function)
- `고차 함수`는 함수를 인수로 받거나, 함수를 반환하는 함수를 의미합니다.
- `콜백(callback)`은 인수로 넘겨지는 함수입니다.
- 화살표 함수로도 고차 함수를 만들 수 있습니다.

```
function repeater(func, n) {
	for(let i = 0; i < n; i++)
		func();
}
```

### 클로저 (Closure)
- 내부 스코프의 함수가 외부 스코프의 변수를 사용한다면, 이 변수는 `클로저`라는 저장소에 저장됩니다.
	- 이때 변수의 상태는 함수가 생성된 시점을 기준으로 합니다.
- 외부 스코프의 코드가 종료되더라도 함수는 클로저를 통해 계속 변수를 사용할 수 있습니다.
- 클로저 변수를 함수의 private 프로퍼티처럼 활용할 수 있습니다.
	- 함수의 호출이 종료되더라도 클로저 변수는 호출 이전 상태로 돌아가지 않습니다.
	- 클로저 변수는 외부에서 접근할 수 없으며, 오로지 함수 내부에서만 조작이 가능합니다.

```
function poo(x) {
	// 내부 스코프의 함수가 외부 스코프의 변수를 사용하고 있습니다.
	return function() {
		return x;
	}
}
const func1 = poo(5);
const func2 = poo(10);

// 클로저에 저장된 변수를 사용합니다.
console.log(func1()); // 5
// 클로저 변수의 초기 상태는 함수가 생성된 시점을 기준으로 합니다.
console.log(func2()); // 10
```

```
function generateCounter(n = 1) {
	return function () {
		return n++;
	}
}

// 클로저 변수는 함수 내부에서만 조작 가능합니다.
const counter = generateCounter();
console.log(counter()); // 1
console.log(counter()); // 2
console.log(counter()); // 3
```

### 재귀 함수 (Recursive Function)
- `재귀 함수`는 자기 자신을 호출하는 함수입니다.
- 자바스크립트에서도 재귀 함수를 사용할 수 있습니다.

```
function poo() {
	poo();
}
```

### 메서드 체이닝 (Method Chaining)
- `Method Chaining`이란 객체의 메서드를 연속적으로 호출하여, 각 메서드의 결과값이 다음 메서드의 입력값으로 연결되는 방식입니다.
- 메서드 체이닝은 코드를 간결하게 작성하게 하지만, 과도한 사용은 오히려 코드를 복잡하게 만들 수 있으므로, 적절하게 사용하는 것이 중요합니다.

```JavaScript
const result = [1, 2, 3, 4, 5]
  .filter(num => num > 2)<br>
  .map(num => num * 2)<br>
  .reduce((acc, num) => acc + num, 0);<br>
```

위 코드는 배열에서 2보다 큰 숫자만 필터링하고, 각 숫자에 2를 곱한 후, 모든 값을 더하는 과정을 한 줄로 표현합니다.
{% endraw %}