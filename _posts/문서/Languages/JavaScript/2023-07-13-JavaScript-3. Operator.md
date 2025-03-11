---
categories:
- JavaScript
date: '2023-07-13'
title: '[JavaScript] 3. Operator'
---

{% raw %}
### 연산자 우선순위

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
- 피연산자를 산술적으로 계산하는 연산입니다.
- `+` 연산자는 피연산자로 문자열이 올 수 있습니다. (문자열 결합 수행)

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
- 변수에 값을 대입하는 연산입니다.

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
- 전위 연산: 먼저 증감을 수행한 뒤, 다른 연산을 수행합니다.
- 후위 연산: 다른 연산을 수행한 뒤, 증감을 수행합니다.

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
- 비교 판정에 따라 boolean(true/false)를 반환합니다.
- `==`: 값을 비교합니다. (타입이 다르면 타입을 통일시키고 비교합니다.)
- `===`: 값과 타입 모두를 비교합니다.
- 피연산자가 number면, 수 크기로 비교합니다.
- 피연산자가 string이면, 유니코드 기준으로 한 글자씩 비교합니다.

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
100 > 150;          // false<br>
null == undefiend;  // true
null !== undefiend; // true
```

### 논리 연산자 (Logical Operator)
- 논리식 판정에 따라 boolean(true/false)를 반환합니다.

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
- 비트(bit) 단위로 논리 연산을 수행합니다.

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
|-12 >> 2|-3|11111101|<br>
|12 >>> 2|3|00000011|<br>

### 기타 연산자
#### 삼항 연산자 (Ternary Operator)
- 간단한 if / else문으로 활용할 수 있습니다.
- `condition`이 true면 `return1`이 반환되며, 그렇지 않으면 `return2`를 반환합니다.

> `condition` ? `return1` : `return2`<br>

```
3 < 5 ? "correct!" : "wrong!";   // "correct!" 반환
```

#### 쉼표 연산자
- 한 라인에 추가적인 구문을 넣을 수 있습니다.

```
var num1 = 0, num2 = 10;
for(var i = 0, j = 19; i <= j; i++, j--)
	num1 += 1, num2 += 1;
console.log(num1 + ", " + num2);
```

```
// 실행 결과
10, 20
```

#### delete
- 객체, 객체의 프로퍼티, 배열의 요소 등을 삭제합니다.
- 삭제한 자리에는 undefiend로 설정됩니다.
- 배열 요소를 delete해도 배열 길이는 유지됩니다.
- 삭제 성공시 true, 삭제 실패시 false를 반환합니다.

```
var obj = { name: "spongebob", job: "cook" };
if(delete obj.name)
	console.log(obj.name);

var list = [1, 2, 3];
if(delete list[1]);
	console.log(list);
```

```
// 실행 결과
undefined
[1, undefiend, 3]
```

#### typeof
- 피연산자의 타입의 이름 문자열을 반환합니다.

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
- 피연산자가 특정 객체의 인스턴스인지를 판별합니다.
- 맞으면 true, 아니면 false를 반환합니다.

```
var str = new String("string");

str instanceof Object;  // true
str instanceof String;  // true
str instanceof Number;  // false
```

#### void
- 피연산자와 무관하게 항상 undefiend를 반환합니다.

```
void(0)  // undefiend
```

### Short-circuit Evaluation
- `평가(Evaluation)`: 표현식이 값으로 변환되는 절차
- 피연산자가 2개인 연산에서, 앞의 1개의 표현식만으로 연산 결과가 결정나는 경우가 있습니다. 이때 다른쪽 표현식은 평가가 되지 않으며, 이러한 방식을 `Short-circuit Evaluation`라고 합니다.
- 이하 식에선 `expression`은 평가되지 않습니다.

> `false` && `expression`<br>
> `true` || `expression`<br>

```
let k = 5;
if(false && (k = 10));
console.log(k); // 5
```

### Optional Chaining
- ES2020에 새로 추가된 방법으로, `Optional Chaining` 연산자 `?.`를 사용할 수 있습니다.
- 참조 대상이 undefined인 에러 상황을 대비할 수 있습니다.

> `obj?.prop` =<br>
> 만약 `obj`이 `null` or `undefined`이면, `obj` 반환<br>
> 그렇지 않으면, `obj.prop` 반환<br>

```
let obj;
console.log(obj?.prop); // undefined
console.log(obj.prop); // 오류 발생!
```

### Spread Syntax
- `Spread Syntax`는 객체나 배열의 속성이나 요소를 풀어서 가져옵니다.
- 객체도 Spread Syntax를 사용할 수 있으며, 열거 가능한(enumerable) 프로퍼티만 복사됩니다.
- 값의 복사는 얕은 복사로 진행됩니다.

```
const arr1 = [3, 4];
const arr2 = [1, 2, ...arr1, 5]; // [ 1, 2, 3, 4, 5 ]
const obj1 = { b: 2 };
const obj2 = { a: 1, ...obj1, c: 3 }; // { a: 1, b: 2, c: 3 }
```

- 객체를 복사할 때, 같은 속성이 겹치면 가장 마지막에 나오는 객체의 속성 값이 적용됩니다.
```
const obj1 = { a: 1, b: 2 };
const obj2 = { b: 3, c: 4 };

const mergedObj = { ...obj1, ...obj2 };

console.log(mergedObj); // { a: 1, b: 3, c: 4 }
```

### Rest Syntax
- `Rest Syntax`는 여러 개의 인자를 배열 또는 객체로 묶어주는 역할을 합니다.
- 함수의 매개변수에서도 사용할 수 있습니다.

```
const [first, second, ...rest] = [1, 2, 3, 4, 5];
console.log(first); // 1
console.log(second); // 2
console.log(rest); // [3, 4, 5]

const { a, b, ...rest } = { a: 1, b: 2, c: 3, d: 4 };
console.log(a); // 1
console.log(b); // 2
console.log(rest); // { c: 3, d: 4 }
```

### 분해대입 (Destructuring Assignment)
- `분해대입`은 배열이나 객체를 분해해서 다수의 변수를 간편하게 설정하는 방법입니다.
- 분해대입은 ES2015에 도입되었습니다.
- 배열을 활용한 분해대입 사용법은 다음과 같습니다. (배열의 인덱스를 매칭 기준으로 하며, 요소가 변수명/대입할 값입니다.)

```
const [a, b, c] = [1, 2, 3];
console.log(a, b, c); // 1 2 3
```

- 객체를 활용한 분해대입 사용법은 다음과 같습니다. (객체의 프로퍼티를 매칭 기준으로 하며, 프로퍼티의 값이 변수명/대입할 값입니다.)
- 좌측 객체의 프로퍼티의 값을 생략하면 프로퍼티명이 변수명이 됩니다.

```
const { p1: a, p2: b } = { p1: 1, p2: 2 };
console.log(a, b); // 1 2

const { p1, p2 } = { p1: 1, p2: 2 };
console.log(p1, p2); // 1 2
```

- 배열/객체에서 서로 매칭되지 않는 부분이 있다면, 해당 부분은 무시됩니다.
- 좌측 배열/객체에 기본값을 설정할 수 있습니다. 만약 해당 요소에 매칭된 값이 없다면 기본값이 대입됩니다.
- 배열/객체를 중첩해서 사용할 수 있습니다.
- 좌측 배열/객체의 맨 마지막 요소에 `...`을 붙이면 해당 요소는 우측 배열/객체의 나머지 값들을 저장하는 배열이 됩니다.
- 함수의 매개변수에서도 분해대입을 사용할 수 있습니다.

```
let a, b, c, d;
[a, , b] = [1, 2, 3, 4];
console.log(a, b); // 1 3

[a, b, c = 3] = [1, 2];
console.log(a, b, c); // 1 2 3

[a, b, [c, d]] = [1, 2, [3, 4]];
console.log(a, b, c, d); // 1 2 3 4

[a, ...b] = [1, 2, 3, 4];
console.log(b); // [2, 3, 4]
```
{% endraw %}