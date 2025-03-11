---
categories:
- JavaScript
date: '2023-07-18'
title: '[JavaScript] 8. Standard Object'
---

{% raw %}
`표준 객체`는 자바스크립트에서 기본적으로 제공하는 객체로, 다른 객체의 기초가 되는 핵심 객체입니다.

### Object
- 자바스크립트의 모든 객체는 Object.prototype을 상속합니다.
- 모든 객체는 Object.prototype의 프로퍼티와 메소드를 사용할 수 있습니다.

#### Object

|메소드|반환|기능|
|---|---|---|
|keys(`object`)|Array|주어진 객체의 열거 가능한(enumerable) 고유 프로퍼티의 이름을 담은 배열 반환|
|getOwnPropertyNames(`object`)|Array|주어진 객체의 모든 고유 프로퍼티의 이름을 담은 배열 반환|
|isExtensible(`object`)|boolean|주어진 객체에 새로운 프로퍼티를 추가할 수 있다면 true 반환|
|getPrototypeOf(`object`)|object|주어진 객체의 프로토타입 반환|
|setPrototypeOf(`child`, `parent`)||객체 `child`의 프로토타입을 객체 `parent`로 설정|
|is(`x`, `y`)|boolean|두 값이 동일한지 비교|
|create(`prototype`, `prop_des`)|object|프로토타입과 속성 기술자를 통해 객체 생성|
|getOwnPropertyDescriptor(`object`, `prop`)|object|주어진 객체 속성의 속성 기술자 반환|
|defineProperty(`object`, `prop`, `prop_des`)||주어진 객체에 새로운 속성 정의|

##### keys()
- 주어진 객체의 열거 가능한(enumerable) 고유 프로퍼티의 이름을 담은 배열을 반환합니다.

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
- 주어진 객체의 모든 고유 프로퍼티의 이름을 담은 배열을 반환합니다.

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
- 주어진 객체에 새로운 프로퍼티를 추가할 수 있다면 true를 반환합니다.

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

##### getPrototypeOf()
- 주어진 객체의 프로토타입을 반환합니다.

```
function Item() {
    this.a = 1;
}
var item = new Item();
console.log(Object.getPrototypeOf(item) === Item.prototype); // true
```


##### setPrototypeOf()
- 주어진 객체의 프로토타입을 변경합니다.

```
var potion = { hp: 100 };
var superPotion = { hp: 200 };
Object.setPrototypeOf(superPotion, potion);
console.log(superPotion.hp); // 200
```

##### is()
- 두 값이 동일한지 비교합니다.
- \=\=\= 연산자와 거의 동일하나, 이하 2가지만 다릅니다.

```
-0 === 0  // true
Object.is(-0, 0) // false

NaN === NaN // false
Object.is(NaN, NaN); // true
```

#### Object.prototype

|프로퍼티|의미|
|---|---|
|constructor|생성자 함수|

|메소드|반환|기능|
|---|---|---|
|hasOwnProperty(`prop-name`)|boolean|현재 객체가 직접 선언된 특정 프로퍼티를 가지고 있다면 true 반환|
|propertyIsEnumerable(`prop-name`)|boolean|현재 객체의 프로퍼티가 열거 가능(enumerable)하다면 true 반환|
|isPrototypeOf(`object`)|boolean|현재 객체가 `object`의 프로토타입 체인에 속하면 true 반환|
|toString()|string|현재 객체를 string으로 변환|
|valueOf()||현재 객체의 원시 타입(number, string...)의 값 반환|

##### constructor
- 함수의 prototype 객체에 존재하는 프로퍼티로, 생성자 함수를 가리킵니다.
- 생성자 함수로 생성된 인스턴스는 생성자 함수의 prototype 객체를 상속하므로, 인스턴스도 동일한 contructor를 갖습니다.

```
function Item() {
    this.a = 1;
}
var item = new Item();

console.log(Item.prototype.constructor === Item); // true
console.log(item.constructor === Item); // true
```

##### hasOwnProperty()
- 해당 객체가 직접 선언된 특정 프로퍼티를 가지고 있다면 true를 반환합니다.
- 상속받은 프로퍼티는 false로 판단합니다.

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
- 해당 객체의 프로퍼티가 열거 가능(enumerable)하다면 true를 반환합니다.
- 해당 프로퍼티가 객체 내 존재하지 않는다면(=hasOwnProperty()의 결과) false를 반환합니다.

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
- 현재 객체가 특정 객체의 프로토타입 체인에 속하면 true를 반환합니다.
	- 특정 객체가 현재 객체의 상속을 받는지를 판단하는 것과 같습니다.

```
var num = new Number();

console.log(Number.prototype.isPrototypeOf(num)); // true
console.log(String.prototype.isPrototypeOf(num)); // false
console.log(Object.prototype.isPrototypeOf(num)); // true
```

##### toString()
- 현재 객체를 string으로 변환합니다.

```
var item = [100, 50];
console.log(item.toString()); // "100, 50"
```

##### valueOf()
- 현재 객체의 원시 타입(number, string...)의 값을 반환합니다.
- 자바스크립트에선 원시 타입이 기대되는 곳에 객체가 사용되면, 내부적으로 이 메소드를 호출해서 처리합니다.
- 해당 객체가 원시 타입의 값을 가지고 있지 않다면 객체 자신을 반환합니다.
- valueOf()를 새로 작성해서 오버라이드할 수 있습니다.

```
var item = {
	hp: 100,
	mp: 50
};
// valueOf()가 객체 자신을 반환하여 문자열 결합 연산이 수행됩니다.
console.log(item + 100); // [object Object]100

// valueOf() 재정의 (오버라이드)
item.valueOf = function() {
	return this.hp;
};
console.log(item + 100); // 200
```

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
- 전역 함수 `parseFloat()`하고 완전히 동일한 기능을 수행합니다.

##### parseInt()
- 전역 함수 `parseInt()`하고 완전히 동일한 기능을 수행합니다.

##### isFinite()
- 전역 함수 `isFinite()`하고 비슷하지만, number 강제 변환이 수행되지 않습니다.
- 주어진 값이 number 타입이고 값이 유한할 때만 true가 반환되며, 그 외는 false가 반환됩니다.

```
Number.isFinite(500);       // true
Number.isFinite("500");     // false
Number.isFinite(null);      // false
Number.isFinite(Infinity);  // false
Number.isFinite(NaN);       // false
```

##### isNaN()
- 전역 함수 `isNaN()`하고 비슷하지만, number 강제 변환이 수행되지 않습니다.
- 주어진 값이 number 타입이고 값이 NaN일 때만 true가 반환되며, 그 외는 false가 반환됩니다.

```
Number.isNaN("NaN");     // false
Number.isNaN(undefined); // false
Number.isNaN(NaN);       // true
```

##### isInteger()
- 주어진 값이 number 타입이고 정수일 때만 true가 반환되며, 그 외는 false가 반환됩니다.

```
Number.isInteger(10);       // true
Number.isInteger(1.0);      // true
Number.isInteger(1.5);      // false
Number.isInteger("10");     // false
Number.isInteger(Infinity); // false
Number.isInteger(true);     // false
```

##### isSafeInteger()
- 주어진 값이 number 타입이고 안전한 정수일 때만 true가 반환되며, 그 외는 false가 반환됩니다.
- `안전한 정수(safe integer)`: 자바스크립트에서 사용하는 64bit 부동소수점으로 연산했을 때 정밀도가 보장되는 정수
- 안전한 정수의 범위는 \[-(2<sup>53</sup> - 1), 2<sup>53</sup> - 1\]입니다.<br>

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
- Number 인스턴스를 지수 표기법으로 변환한 결과를 반환합니다.
- 선택 인자를 전달하면, 반올림되어 소수점 자리가 n까지 표시됩니다.

```
var num = 12.345;
num.toExponential();  // 1.2345e+1
num.toExponential(2); // 1.23e+1
```

##### toFixed()
- Number 인스턴스를 반올림하여 소수점 자리가 n까지인 결과를 반환합니다.
- 인자의 기본 값은 0입니다.

```
var num = 12.345678;
num.toFixed();  // 12
num.toFixed(2); // 12.35
```

##### toPrecision()
- Number 인스턴스를 반올림하여 전체 자리가 n까지인 결과를 반환합니다.
- 인자를 제공하지 않으면 전체 수가 반환됩니다.

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
|trunc(`x`)|`x`의 소수 자리를 잘라낸 값|
|abs(`x`)|`x`의 절댓값|
|sign(`x`)|`x`의 부호 값 (-1, 0, 1)|
|pow(`x`, `y`)|x<sup>y</sup>|
|sqrt(`x`)|`x`의 제곱근|
|cbrt(`x`)|`x`의 세제곱근|
|exp(`x`)|e<sup>x</sup> (e = 자연로그의 밑)|<br>
|log(`x`)|ln `x` (자연로그 값)|
|log10(`x`)|log<sub>10</sub> `x`|<br>
|log2(`x`)|log<sub>2</sub> `x`|<br>
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
- 자바스크립트에선 주로 `Date` 객체를 사용해서 시간과 날짜를 관리합니다.
- 날짜와 시간을 표현하는 값의 범위는 다음과 같습니다.
	- 자바스크립트에선 월의 값이 0부터 시작합니다.
	- 연도일 경우, 2000년대 이전은 2자리 값으로 표기 가능합니다.
	- 2000년대 이후는 4자리로 표현해야 합니다.

|시간|범위(시간)|범위(값)|
|---|---|---|
|year|현재 연도(4자리)||
|month|\[1월, 12월\]|\[0, 11\]|
|day|\[1일, 31일\]|\[1, 31\]|
|hours|\[0시, 23시\]|\[0, 23\]|
|minutes|\[0분, 59분\]|\[0, 59\]|
|seconds|\[0초, 59초\]|\[0, 59\]|

#### 날짜 양식 (Date Format)
자바스크립트에서 날짜를 표현하는 양식은 여러 가지가 있습니다.

1. ISO 날짜 양식
2. Long 날짜 양식
3. Short 날짜 양식
4. Full 날짜 양식

##### ISO 날짜 양식
- `ISO 8601`: 날짜와 시간을 나타내는 국제 표준 양식
- 아래에서 T는 UTC(협정시)를 의미하는 문자입니다.

> `YYYY`-`MM`-`DD`T`HH`:`MM`:`SS`<br>
> `YYYY`-`MM`-`DD`<br>
> `YYYY`<br>
> `YYYY`<br>

```
2023-07-19T07:41:25
2023-07-19           // 기본 시간 = 09:00:00
2023-07              // 기본 일 = 1
2023                 // 기본 월 = 1
```

##### Long 날짜 양식
> `MMM` `DD` `YYYY`<br>
> `DD` `MMM` `YYYY`<br>

```
Jul 19 2023
19 Jul 2023
July 19 2023   // 월의 전체 단어도 인식됩니다.
19, JULY, 2023 // 쉼표를 사용해도 되며, 대소문자 구분은 없습니다.
```

##### Short 날짜 양식
> `MM`-`DD`-`YYYY`<br>
> `YYYY`-`MM`-`DD`<br>

```
2023-07-19
07/19/2023  // /를 사용할 수도 있습니다.
```

##### Full 날짜 양식
> `MM` `DD` `YYYY` `HH`:`MM`:`SS` GMT+`diff-time` (`time-zone`)<br>

```
July 20 2023 02:19:25 GMT+0900 (Seoul Time)
```

#### 생성
Date 객체를 생성하는 다양한 방법이 제공됩니다.

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

```
// 실행 결과
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

- 메소드명에 UTC가 들어가면 UTC 협정시 기준, 아니면 현지 시각을 기준으로 합니다.

```
var date = new Date();
date.setUTCFullYear(2022);
date.setUTCMonth(9);
date.setUTCDate(31);

console.log(date.getUTCFullYear() + "-" + (date.getUTCMonth() + 1) + "-" + date.getUTCDate()); // 2022-10-31
```

### String
- `String`: 문자열에 대한 여러 기능을 제공하는 객체
- String.prototype에서 여러 가지 메소드를 제공합니다.
	- 메소드를 실행해도 현재 문자열은 불변합니다.

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
|localeCompare(`string`)|-1, 0, 1|현재 문자열과 `string`을 사전순으로 비교함 (현재 문자열이 뒤에 있으면 1 반환)|
|search(`reg`)|number|정규 표현식으로 검색한 결과 반환 (성공시 일치한 패턴의 최소 인덱스, 실패시 -1 반환)|
|replace(`reg`, `string`)|string|정규 표현식으로 검색된 패턴을 `string`으로 대체한 입력 문자열 반환|

#### 문자열 위치 찾기
- indexOf(`search`, _`pos`_): 현재 문자열에서 `search` 문자열이 등장하는 첫 위치를 반환합니다.
	- `pos` 전달시, 현재 문자열의 해당 인덱스부터 검색이 시작됩니다.
- lastIndexOf(`search`): 현재 문자열에서 `search` 문자열이 등장하는 마지막 위치를 반환합니다.
- 두 메소드 모두 검색 실패시 -1이 반환됩니다.

```
var str = "abcDEFabc";
str.indexOf("abc");     // 0
str.indexOf("abcd");    // -1
str.indexOf("abc", 3);  // 6
str.lastIndexOf("abc"); // 6
str.indexOf("b");       // 7
```

#### 문자열 문자 접근
- charAt(`i`): 문자열에서 i번째 문자를 반환합니다.
	- `[]` 연산자도 같은 기능을 수행합니다.
	- i >= length일 경우, 빈 문자열이 반환됩니다.
- charCodeAt(`i`): charAt()의 결과를 UFT-16 코드로 반환합니다.

```
var str = "JavaScript";
str.charAt(5);     // c
str[5];            // c
str.charCodeAt(5); // 99
```

#### 문자열 추출
- slice(`lo`, _`hi`_): 현재 문자열을 인덱스 \[`lo`, `hi`\) 범위만큼 추출한 문자열을 반환합니다.
	- `hi` 생략시, 현재 문자열의 마지막까지 추출됩니다.
- substring(), substr(): slice()와 동일합니다.

```
var str = "JavaScript";
str.slice(2, 6); // vaSc
str.substr(2);   // vaScript
```

#### 문자열 분리
- split(`seperator`): 현재 문자열을 `seperator` 기준으로 분할하고, 나뉜 조각들을 담은 배열을 반환합니다.
	- 인수 미제공시, 분할이 발생하지 않습니다. (전체 문자열이 담긴 길이 1 배열이 반환됩니다.)

```
var str = "HTML vs CSS vs JavaScript";

// [ 'HTML', 'CSS', 'JavaScrip' ]
str.split(" vs ");
```

#### 문자열 결합
- concat(`extra`): 현재 문자열 끝에 문자열 `extra`을 덧붙인 결과를 반환합니다.

```
var str = "JavaScript";

// "JavaScript is SO AWESOME!!"
str.concat(" is SO AWESOME!!");
```

#### 문자열 대소문자 변환
- toUpperCase(): 현재 문자열의 모든 문자를 대문자로 바꾼 결과를 변환합니다.
- toLowerCase(): 현재 문자열의 모든 문자를 소문자로 바꾼 결과를 변환합니다.

```
var str = "JavaScript";
str.toUpperCase(); // JAVASCRIPT
str.toLowerCase(); // javascript
```

#### 문자열 주위 공백 제거
- trim(): 현재 문자열의 양 끝에 존재하는 모든 공백과 줄바꿈 문자를 제거한 결과를 반환합니다.
	- 문자열 내부에는 영향이 없습니다.

```
var str = "   Java vs Script   ";
str.trim(); // Java vs Script
```

#### 문자열 포함 유무
- includes(`search`): 현재 문자열에 문자열 `search`가 포함되어 있다면 true를 반환합니다.
- startsWith(`search`): 현재 문자열이 문자열 `search`으로 시작하면 true를 반환합니다.
- endsWith(`search`): 현재 문자열이 문자열 `search`으로 끝나면 true를 반환합니다.

```
var str = "JavaScript";
str.includes("Java");   // true
str.includes("scr");    // false
str.startsWith("Java"); // true
str.endsWith("pt");     // true
```

#### 문자열 비교
- localeCompare(`string`): 현재 문자열과 `string`을 사전순으로 비교합니다.
	- 현재 문자열이 뒤에 있으면 1을 반환합니다.
	- 현재 문자열이 앞에 있으면 -1을 반환합니다.
	- 두 문자열이 동일하면 0을 반환합니다.

```
"string".localeCompare("strinz"); // -1
"string".localeCompare("strina"); // 1
"string".localeCompare("string"); // 0
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
- 인자가 Array 객체면 true를 반환합니다.

```
Array.isArray([]);      // true
Array.isArray("Array"); // false
Array.isArray(true);    // false
```

##### from()
- 인자를 Array 객체를 상속하는 객체로 바꾼 결과를 반환합니다.
- 바꿀 수 있는 객체는 다음과 같습니다.
	- 배열과 비슷한 객체: length 프로퍼티와 인덱스 요소가 존재합니다.
	- 반복 가능한 객체: 요소를 개별 선택 가능합니다. (String, Map, Set 등)

```
Array.from(new Map([1, 2], [3, 4])); // [1,2,3,4]
Array.from("JavaScript"); // [J,a,v,a,S,c,r,i,p,t]
```

##### of()
- 제공된 인자로 구성된 배열을 반환합니다. (인수간 타입은 무관합니다.)

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
|sort(`compare`)|변경된 배열|정렬 함수 `compare`를 기준으로 배열의 요소를 정렬|
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

- forEach(), map(), filter(), every(), some()에서 콜백 함수의 선택인자는 다음과 같습니다.

> function calBack(value, index, array) {<br>
>	// value = 현재 배열 요소
>	// index = 현재 배열 인덱스
>	// array = 탐색 중인 배열
> }<br>

##### push()
- 1개 이상의 요소를 배열의 마지막에 추가합니다.
- 추가 성공시, 변경된 배열의 length를 반환합니다.

```
var arr = [1, 2, 3];
arr.push(4);
arr.push(5, 6, 7);
console.log(arr); // [1,2,3,4,5,6,7]
```

##### pop()
- 배열의 가장 마지막 요소를 제거하고, 그 제거된 요소를 반환합니다.

```
var arr = [1, 2, 3];
console.log(arr.pop()); // 3
console.log(arr);       // [1, 2]
```

##### shift()
- 배열의 가장 앞의 요소를 제거하고, 그 제거된 요소를 반환합니다.

```
var arr = [1, 2, 3];
console.log(arr.pop()); // 1
console.log(arr);       // [2, 3]
```

##### unshift()
- 1개 이상의 요소를 배열의 앞에 추가합니다.
- 추가 성공시, 변경된 배열의 length를 반환합니다.

```
var arr = [1, 2, 3];
arr.unshift(0);
arr.unshift(-3, -2, -1);
console.log(arr); // [-3,-2,-1,0,1,2,3]
```

##### reverse()
- 배열의 순서를 뒤집습니다.

```
var arr = [1, 2, 3];
arr.reverse();
console.log(arr); // [3, 2, 1]
```

##### sort()
- 배열의 요소를 주어진 비교 함수에 따라 정렬합니다.
- 비교 함수를 전달하지 않으면, 유니코드 코드포인트 방식으로 비교합니다. (이때는 모든 요소를 string 타입으로 간주한 상태로 비교를 수행합니다.)

```
var arr = ["html", "css", "javascript", 123, true];
arr.sort();
console.log(arr); // [123, "css", "html", "javascript", true]
```

- 비교 함수의 구조는 다음과 같습니다.

> (`a`, `b`)<br>
> 음수 반환시, `a`가 앞에 옵니다.<br>
> 양수 반환시, `b`가 앞에 옵니다.<br>
> 0 반환시, `a`와 `b`는 같은 순서로 간주됩니다.<br>

```
var arr = ["html", "css", "javascript"];
arr.sort((x, y) => x.length - y.length); // 길이 오름차순으로 정렬<br>
console.log(arr); // ["css", "html", "javascript"]
```

- 브라우저마다 다르지만, 일반적으로 sort()는 불안정 정렬을 수행합니다. (같은 순서의 요소들이 정렬 후에는 순서가 서로 바뀌어 있을 수 있습니다.)

##### splice()
- 특정 위치부터 배열의 요소들을 제거하고 주어진 인자들을 해당 자리에 추가합니다.

```
var arr = [1, 2, 3, 4, 5];
console.log(arr.splice(2, 2, "3", "4")); // [3, 4]
console.log(arr); // [1, 2, "3", "4", 5]
```
##### join()
- 배열의 모든 요소를 구분자(제공한 인자)로 구분한 문자열을 반환합니다.
- 인자의 기본값은 `,`입니다.

```
var arr = [1, 2, 3];
arr.join();     // 1,2,3
arr.join("");   // 123
arr.join(" + ") // 1 + 2 + 3
```

##### slice()
- 특정 구간에 해당하는 요소들을 배열로 묶어 반환합니다.
	- 2번째 인자 생략시, 범위가 배열 끝까지 연장됩니다.

```
var arr = [1, 2, 3, 4, 5];
arr.slice(1, 3); // [2, 3]
arr.slice(2); // [3, 4, 5]
```

##### concat()
- 1개 이상의 요소를 배열의 마지막에 추가한 결과를 반환합니다.
- 배열이 인자로 제공된 경우, 해당 인자의 요소들을 추가합니다. (배열 자체가 추가되진 않습니다.)

```
var arr = [1, 2, 3];
console.log(arr.concat(4, 5));      // [1,2,3,4,5]
console.log(arr.concat(4, [5, 6])); // [1,2,3,4,5,6]
```

##### toString()
- 현재 배열을 문자열로 변환합니다. (인자가 없는 join()과 동일합니다.)

```
var arr = [1, 2, 3];
arr.toString(); // 1,2,3
```

##### indexOf()
- 인자값과 동일한 배열 요소의 최소 인덱스를 반환합니다.

```
var arr = [1, 2, 3, 2, 1];
arr.indexOf(2); // 1
```

##### lastIndexOf()
- 인자값과 동일한 배열 요소의 최대 인덱스를 반환합니다.

```
var arr = [1, 2, 3, 2, 1];
arr.indexOf(2); // 3
```


##### forEach()
- 현재 배열의 모든 요소를 대상으로 콜백 함수 1회씩 호출합니다.

```
var arr = ['A', 'B', 'C'];
function printAll(value, index, array) {
	console.log(index + ": " + value);
}
arr.forEach(printAll);
```


```
// 실행 결과
0: A
1: B
2: C
```

##### map()
- 현재 배열의 모든 요소를 대상으로 콜백 함수 1회씩 호출하고, 호출 결과를 각 요소에 대입한 배열을 반환합니다.

```
var arr = [1, -2, 3, -4, 5];
console.log(arr.map(Math.abs)); // [1, 2, 3, 4, 5]
```

##### filter()
- 현재 배열의 모든 요소를 대상으로 콜백 함수 1회씩 호출하고, 호출 결과가 true인 요소만 담은 배열을 반환합니다.

```
var arr = [1, -2, 3, -4, 5];
function isOverZero(value) {
	return value > 0;<br>
}
console.log(arr.filter(isOverZero)); // [1, 3, 5]
```

##### every()
- 현재 배열의 모든 요소를 대상으로 콜백 함수 1회씩 호출하고, 호출 결과가 모두 true면 true를 반환합니다.

```
var arr1 = [1, -2, 3, -4, 5];
var arr2 = [1, 2, 3, 4, 5];
function isOverZero(value) {
	return value > 0;<br>
}
console.log(arr1.every(isOverZero)); // false
console.log(arr2.every(isOverZero)); // true
```

##### some()
- 현재 배열의 모든 요소를 대상으로 콜백 함수 1회씩 호출하고, 호출 결과가 하나라도 true면 true를 반환합니다.

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
- 현재 배열에 대해 다음 구조의 콜백 함수를 실행한 결과를 반환합니다.

> A<sub>0</sub> = arr\[0\]<br>
> A<sub>n</sub> = F(A<sub>n-1</sub>, arr\[n\])<br>

> function F(a, b) {<br>
> 	// a = A<sub>n-1</sub><br>
> 	// b = arr\[n\]<br>
> }<br>

```
var arr = [1, 2, 3, 4, 5];
function sumAll(a, b) {
	return a + b;
}
console.log(arr.reduce(sumAll)); // 15
```

##### reduceRight()
- 현재 배열의 순서를 뒤집고 reduce()를 수행합니다.

```
var arr = [1, 2, 3, 4, 5, 15];
function subtactAll(a, b) {
	return a - b;
}
console.log(arr.reduceRight(subtactAll)); // 0
```

##### entries()
- 배열 요소별로 키(key)와 값(value) 쌍으로 이루어진 배열 반복자 객체(Array Iterator Object)로 구성된 배열을 반환합니다.

```
var arr = ['A', 'B', 'C'];
var arrEntries = arr.entries();
for(var entry of arrEntries)
	console.log(entry);
```

```
// 실행 결과
[ 0, 'A' ]
[ 1, 'B' ]
[ 2, 'C' ]
```

### Function
- `Function`: 자바스크립트에서 함수를 담당하는 객체
- Function.prototype에서 여러 가지 프로퍼티를 제공합니다.

|프로퍼티|의미|
|---|---|
|length|함수의 매개변수 개수|
|name|함수의 이름|
|arguments|함수에 전달된 인자 리스트 (유사 배열 객체)|
|prototype|생성자 함수가 인스턴스 생성시 사용하는 프로토타입 객체|

|메소드|반환|기능|
|---|---|---|
|bind(`object`)|function|this의 값이 `object`으로 고정된 함수 반환|

#### arguments
- 함수에 전달된 인자들을 순차적으로 담은 유사 배열 객체입니다.
- arguments 객체를 사용하면 인자의 개수가 매개변수 개수보다 많은 상황을 대처할 수 있습니다.
	- 단, 이러한 용도로 사용하는 것은 ES2015에 도입된 `나머지 매개변수`로 대체 가능합니다.

```
// 인자들의 총합을 구하는 함수 (인자 개수 제약 없음)
function addNum() {
	var sum = 0;
	for(n of arguments)
		sum += n;
	return sum;
}
console.log(addNum(1, 2)); // 3
console.log(addNum(1, 2, 3, 4, 5)); // 15
console.log(addNum()); // 0
```

#### prototype
- 생성자 함수가 인스턴스 생성시 사용하는 프로토타입 객체를 가리킵니다.
	- 이 프로토타입 객체는 Object.prototype의 복사본입니다.
- 함수의 프로토타입과 관련이 없습니다. (함수의 프로토타입은 `Function.prototype`입니다.)

#### bind()
- this의 값이 `object`으로 고정된 새 함수를 반환합니다.

```
function powerUp() {
	this.hp += 100;
}
const item = { hp: 100 };
const itemPowerUp = powerUp.bind(item);

itemPowerUp();
console.log(item.hp); // 200
```

### JSON
- `직렬화(Serialization)`는 프로그래밍 언어에서 사용하는 자료구조를 저장/전송 가능한 형태로 가공하는 절차입니다. `역직렬화(Deserialization)`는 직렬화된 데이터를 다시 원래 형태로 변환하는 절차입니다.
- `JSON(JavaScript Object Notation)`은 웹 분야에서 가장 자주 사용되는 직렬화 형식 중 하나로, 자료구조를 자바스크립트 객체와 비슷한 표기법을 사용하는 텍스트로 직렬화합니다.
- 자바스크립트에서는 표준 객체 `JSON`로 JSON을 사용할 수 있습니다.
- JSON 메소드를 사용할 때는 JSON 문법을 적용해야 합니다. (자바스크립트 문법이 JSON으로 자동 변환되지 않습니다.)
	- 예를 들어, JSON에선 속성명을 따옴표로 감쌉니다.

|메소드|기능|
|---|---|
|stringify(`obj`)|JSON 직렬화|
|parse(`json`)|JSON 역직렬화|

```
const potion = { hp: 500, mp: 150, name: "hpPotion" };
const data = JSON.stringify(potion);
console.log(data);
console.log(JSON.parse(data));
```

```
// 실행 결과
{"hp":500,"mp":150,"name":"hpPotion"}
{ hp: 500, mp: 150, name: 'hpPotion' }
```

### Symbol
- `심볼(Symbol)`은 ES2015에 새로 도입된 원시 타입입니다.
- 표준 객체 `Symbol`로 심볼을 생성할 수 있습니다.
- 심볼 생성시, 심볼의 설명을 인자로 줄 수 있습니다. 심볼의 설명은 단순 문자열이며 심볼의 식별에 영향을 주지 않습니다. 즉, 새로 생성된 심볼의 설명이 기존 심볼의 설명과 같다고 해도 두 심볼은 다릅니다.
- 심볼은 객체의 프로퍼티 `식별자(identifier)` 역할을 할 수 있습니다.
	- 대괄호 표기법으로 심볼을 객체의 프로퍼티 식별자로 사용할 수 있습니다.

> Symbol(_`desc`_)<br>

```
const sym = Symbol('hp');
const potion = { [sym]: 500 };
console.log(potion); // { [Symbol(hp)]: 500 }
```

### Map
- `Map` 객체는 키-값 쌍(key-value pair)을 저장하는 자료구조를 제공합니다.
- Map 객체의 키는 어떤 값이든 올 수 있으며, 키를 통해서 원하는 값을 빠르게 검색할 수 있습니다.
- Map 객체는 데이터 추가/삭제가 일반적인 객체보다 빠릅니다.
- Map 객체는 JSON 등으로 직렬화가 어렵습니다.

|메소드|기능|
|---|---|
|set(`key`, `value`)|데이터 추가|
|get(`key`)|`key`에 대응하는 값 반환|
|get(`key`)|`key`를 가진 데이터가 존재하면 true 반환|
|delete(`key`)|`key`를 통해 데이터 삭제|

```
const map = new Map();

map.set(1, 'sword');
console.log(map.get(1)); // 'sword'
console.log(map.has(1)); // true

map.delete(1);
console.log(map.get(1)); // undefined
console.log(map.has(1)); // false
```

### Set
- `Set` 객체는 집합 자료구조를 제공합니다.
- Set 객체는 중복 데이터를 허용하지 않습니다. (중복 데이터가 추가될시 무시됩니다)
- Set 객체 내 데이터는 순서가 없습니다.

```
const set = new Set();

set.add(1);
set.add(2);
set.add(2);
console.log(set); // Set { 1, 2 }
```
{% endraw %}