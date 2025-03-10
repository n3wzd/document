---
categories:
- JavaScript
date: '2023-07-17'
title: '[JavaScript] 7. Object'
---

{% raw %}
- **객체(object)**: 프로퍼티의 정렬되지 않은 집합
- **프로퍼티(property)**: 이름(name)과 값(value)으로 구성된 이름-값 쌍
	- 프로퍼티는 객체를 구성하는 원소입니다.
- **메소드(method)**: 함수가 값인 프로퍼티
	- 메소드는 객체에 포함되어있다는 점에서 일반적인 함수와 다릅니다.
- 자바스크립트에선 number, string, boolean 등 원시 타입도 **래퍼 객체**로 인해 값이 정해진 객체로 취급될 수 있습니다.
- **객체 레퍼런스(object reference)**: 객체가 위치한 주소를 저장하는 변수
	- 자바스크립트에서 객체는 레퍼런스 형태로 변수에 담깁니다.
	- 객체 레퍼런스의 값은 객체 그 자체가 아니라 객체가 메모리에 위치한 주소입니다.

### 생성 (Create)
- **인스턴스(instance)**: 생성된 객체
- 객체를 생성하는 방법은 다음이 있습니다.

1. 리터럴 표기(literal notation)
2. 생성자 함수(constructor function)
3. Object.create()

#### 리터럴 표기 (Literal Notation)
- 직접 객체의 프로퍼티를 작성해서 생성하는 방법입니다.
- 이 방법으로 생성된 객체의 프로토타입은 `Object.prototype`입니다.

> var `object` = {<br>
> 	`property1`: `value1`,<br>
> 	`property2`: `value2`,<br>
> 	...<br>
> };<br>

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
- **생성자 함수**는 객체를 생성할 때 사용되는 함수입니다.
- 모든 함수는 생성자 함수가 될 수 있습니다.
- `new` 연산자로 생성자 함수를 통해 객체를 생성할 수 있습니다.
- 자바스크립트에서 미리 정의된 생성자 함수(`Object`, `Number`, `String` 등)도 있고, 직접 생성자 함수를 작성할 수도 있습니다.

> new `Constructor`<br>

```
var str = new String();
```

#### Object.create()
- 생성할 객체의 **프로토타입**을 1번째 인자를 통해 직접 설정할 수 있습니다.
- 2번째 인자는 **속성 기술자**입니다. 프로퍼티를 추가할 수도 있으며, 추가할 프로퍼티의 부수속성도 같이 설정할 수 있습니다.
	- 속성 기술자의 속성에서 `writable`, `enumerable`, `configurable`을 따로 설정하지 않았다면, 해당 부수속성은 `false`로 취급됩니다.

> Object.create(`prototype`, `prop_des`);<br>

```
var item = Object.create(null, { 
		hp: { value: 100, enumerable:true }, 
		mp: { value: 50, enumerable:true }
	});
console.log(item.hp + ", " + item.mp); // 100, 50
```

### 프로퍼티 (Property)
#### 참조
- 프로퍼티를 참조하는 방법은 다음과 같습니다.

> `object`.`property`<br>
> `object`\["`property`"\]<br>

- 메소드를 호출하는 방법은 다음과 같습니다.

> `object`.`method`()<br>

- 만약 `()`를 붙이지 않으면 프로퍼티로 취급되어, 함수 그 자체가 반환됩니다.

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
- `delete` 키워드를 사용해서 객체의 프로퍼티 자체를 삭제할 수 있습니다.

> delete `object`.`property`<br>

```
var item = {
	hp: 100,
	mp: 50
};

delete item.mp;
console.log(item.hp + ", " + item.mp); // 100, undefined
```

#### 순회
- 객체의 프로퍼티를 순회하는 방법은 다음이 있습니다.

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

```
// 실행 결과
hp
mp
exp
```

### 프로토타입 (Prototype)
- `상속(inheritance)`: 새로운 클래스에서 기존 클래스의 모든 프로퍼티와 메소드를 이어받는 것
	- 객체지향 프로그래밍에선 상속을 통해 클래스 간 종속 관계를 형성해서 객체의 관계를 조직화할 수 있다는 이점이 있습니다.
- 자바스크립트는 `프로토타입 기반(prototype-based)` 객체지향 언어입니다.
	- 기존의 객체를 복사하여 새로운 객체를 생성합니다.
	- C++, Java 등 클래스 기반(class-based) 객체지향 언어와는 다른 점이 있습니다.
- `프로토타입(prototype)`: 자바스크립트에서 상속하는 정보를 제공하는 객체
	- 모든 객체는 프로토타입 객체를 가지고 있습니다. (Object.prototype 제외)
	- 모든 객체는 해당 프로토타입으로부터 프로퍼티와 메소드를 상속합니다.
	- 모든 객체는 최소한 1개 이상의 다른 객체를 상속합니다.
- 자바스크립트에서 상속은 현재 존재한 객체를 복제하여 재사용하는 것을 의미합니다.

#### 프로토타입 체인 (Phototype Chain)
- 어떤 객체의 프로토타입을 계속 추적할 경우, 이러한 추적의 종점은 항상 `Object.prototype`입니다.
- 즉, 모든 객체는 Object.prototype를 상속합니다.
- Object.prototype 객체는 어떠한 프로토타입, 프로퍼티를 가지지 않는 빈 객체입니다. => {}<br>
- 위와 같이 어떤 객체부터 Object.prototype까지 프로토타입 연결 관계를 `프로토타입 체인`이라 합니다.

#### 프로토타입 참조
- 어떤 객체의 프로토타입을 참조하는 방법은 다음이 있습니다.

1. Object.getPrototypeOf()
2. \_\_proto\_\_

```
function Item() {
    this.a = 1;
}
var item = new Item();

console.log(Object.getPrototypeOf(item) === Item.prototype); // true
console.log(Object.getPrototypeOf(Item) === Item.prototype); // false
console.log(Object.getPrototypeOf(Item) === Function.prototype); // true
console.log(Item.prototype.__proto__ === Object.prototype); // true
```

- \_\_proto\_\_ 프로퍼티는 사용에 논란이 있어 권장되지 않습니다. (원래 비표준이었으나, 레거시 목적으로 표준이 되었습니다.)

#### 프로토타입 생성
- 생성자 함수에서 인스턴스에 추가할 프로퍼티들을 정의할 수 있습니다.
- `new` 키워드를 통해 생성자 함수로 인스턴스 객체를 생성할 수 있습니다.

> function `Constructor`() {<br>
> 	this.`property1` = `value1`<br>
> 	...<br>
> }<br>

> var `instance` = new `Constructor`();<br>

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

위 예제의 동작을 정리하면 다음과 같습니다.
```
1. 생성자 함수(Item)를 정의할 때 빈 객체가 생성됩니다.
	- 이 객체는 `Item.prototype`으로 참조할 수 있습니다.
	- Item.prototype은 Item 인스턴스의 프로토타입입니다.
	- Item.prototype의 프로토타입은 Object.prototype입니다.
2. new 키워드를 사용하면,
	1. Item.prototype를 복사해서 새로운 객체(인스턴스)를 생성합니다. => item<br>
	2. 생성자 함수가 실행됩니다. (이때 this는 item이다)
```

#### 프로퍼티 추가
##### 인스턴스
- 참조 연산자를 활용해서 인스턴스에 프로퍼티를 추가할 수 있습니다.

> var `instance`.`newProperty` = `value`;<br>

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

```
// 실행 결과
100, 50, undefined
50, 100, 50
```

##### 프로토타입
- 프로토타입에 프로퍼티를 추가하는 방법은 다음이 있습니다. 

1. 생성자 함수에 추가
2. 프로토타입 객체에 직접 추가

> function `Constructor`(...) {<br>
> 	this.`newProperty` = `value`<br>
> }<br>
> or<br>
> `Constructor`.prototype.`newProperty` = `value`;<br>

- 인스턴스에서 프로퍼티를 추가하면 해당 객체에만 적용되지만, 프로토타입에 추가하면 해당 프로토타입을 상속하는 모든 객체에 적용됩니다.

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

```
// 실행 결과
100, 50, 20, 5
50, 100, 10, 5
```

### 전역 객체 (Global Object)
- `전역 객체`: 자바스크립트에서 미리 정의된 객체로, 전역 프로퍼티와 전역 함수가 저장되어 있습니다.
	- 전역에서 `this`를 통해 접근할 수 있습니다.
- 모든 전역 변수와 전역 함수는 전역 객체의 프로퍼티입니다.

### 래퍼 객체 (Wrapper Object)
- `래퍼 객체`: 원시 타입(number, string 등)의 프로퍼티를 접근하려 할 때, 자동으로 생성되는 임시 객체
- 원시 타입은 객체가 아니니 프로퍼티가 없습니다. 그렇기에 원시 타입에서 프로퍼티를 참조하면 오류가 발생할 것으로 예측할 수 있습니다. 그러나 자바스크립트에선 내부적으로 래퍼 객체를 생성함으로써 이러한 동작을 가능하게 합니다!
- 프로퍼티의 참조가 끝나면 래퍼 객체는 자동으로 삭제됩니다.
- 생성자 String, Number, Boolean, Symbol가 래퍼 객체 생성에 사용됩니다.

```
var str = "JavaScript";
console.log(str.length); // 10
```

- 위 예제는 자바스크립트에서 내부적으로 아래와 비슷하게 바뀝니다.
```
var str = "JavaScript";
console.log((new String(str)).length);
```

### 속성 가리기 (Property Shadowing)
- 프로토타입 체인에서 같은 이름의 속성이 여러 번 등장할 수 있습니다. 이때는 현재 객체와 가장 가까운 프로토타입(또는 자신)의 것이 선택됩니다.
- 이처럼 상위 프로퍼티보다 하위 프로퍼티가 우선시되는 현상을 `속성 가리기`라고 합니다.

```
var potion = { hp: 100 };
var superPotion = { hp: 200 };
Object.setPrototypeOf(superPotion, potion);

// 같은 이름의 프로퍼티가 있다면 하위 것을 우선시합니다.
console.log(superPotion.hp); // 200
```

### 정적 메소드 (Static Method)
- `정적 메소드`는 생성자 함수의 프로퍼티에 직접 지정된 메소드입니다.
- 생성자 함수의 prototype 객체에 정의하는 것이 아니므로 인스턴스는 정적 메소드를 사용할 수 없습니다.
- 정적 메소드의 예시로는 Object.create(), Array.isArray() 등이 있습니다.

```
function Item() { 
	this.hp = 100;
}

// 생성자 함수의 프로퍼티로 정적 메소드를 추가할 수 있습니다.
Item.powerUp = function(item) {
	item.hp += 100;
}
```

### 부수속성 (Property Attribute)
- 속성의 `부수속성`은 해당 속성의 특성 정보를 저장합니다.
- `속성 기술자(property descripot)` 객체는 속성의 부수속성들을 담고 있습니다. 속성 기술자는 `Object.getOwnPropertyDescriptor()` 메소드로 얻을 수 있습니다.
- 속성 기술자는 주로 속성을 정의할 때 부수속성 정보를 넘겨주는 인자로 활용됩니다.
- `데이터 속성`에 대한 속성 기술자는 다음 프로퍼티를 갖습니다. 

|프로퍼티|값|
|---|---|
|value|속성에 저장된 값|
|writable|변경 가능성|
|enumerable|열거 가능성|
|configurable|부수속성 변경 및 프로퍼티 삭제 가능성|

```
const item = { hp: 100, mp: 50 };
Object.defineProperty(item, 'exp', {value: 75, writable: false, enumerable : false} );

for(p in item)
	console.log(p); // exp는 출력되지 않습니다!

item.exp = 150; // 해당 대입은 반영되지 않습니다!
console.log(item.exp); // 75
```

### 접근자 속성 (Accessor Property)
- `접근자 속성`은 `getter`와 `setter`가 정의된 속성입니다.
- `getter`: 특정 프로퍼티의 값을 받아오는 메소드
- `setter`: 특정 프로퍼티의 값을 설정하는 메소드
- getter와 setter는 호출 방법이 프로퍼티 조작과 비슷합니다.

> `object`.`getter`<br>
> `object`.`setter` = `argument`<br>

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

- 접근자 속성의 부수속성은 다음과 같습니다. (데이터 속성에서 get, set만 다릅니다.)

|부수속성|값|
|---|---|
|get|getter 메소드|
|set|setter 메소드|
|enumerable|열거 가능성|
|configurable|부수속성 변경 및 속성 삭제 가능성|

### 얕은 복사(Shallow Copy) vs 깊은 복사(Deep Copy)
- 중첩된 자료구조를 포함한 자료구조를 복사하는 것은 크게 2가지 방법이 있습니다.
- `얕은 복사(Shallow Copy)`는 중첩된 자료구조의 참조만 복사합니다.
- `깊은 복사(Deep Copy)`는 중첩된 자료구조까지 완전히 복사합니다.
- 자바스크립트에서 중첩된 객체 복사시, 기본적으로 얕은 복사를 따릅니다. 따라서 깊은 복사를 사용하려면 직접 구현해야 합니다.

```
const healBuff = { time: 30, hp: 30 };
const hpPotion = { hp: 500, buff: healBuff };
const mpPotion = Object.assign({}, hpPotion); // 얕은 복사가 진행됩니다.
console.log(hpPotion.buff === mpPotion.buff); // true
```
{% endraw %}