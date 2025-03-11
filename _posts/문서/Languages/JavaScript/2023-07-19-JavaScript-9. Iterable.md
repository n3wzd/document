---
categories:
- JavaScript
date: '2023-07-19'
title: '[JavaScript] 9. Iterable'
---

{% raw %}
- 반복 가능한 객체는`iterable`이며, `iterable protocol`을 만족합니다.
- iterable은 ES2015에 새로 도입되었습니다.
- iterable의 예시는 `String`, `Array`, `Map`, `Set` 등이 있습니다.
- 다음 조건을 만족하면 해당 객체는 iterable입니다.

> iterable 객체의 `Symbol.iterator` 속성은 특별한 형태의 함수를 저장합니다.<br>

```
const arr = [1, 2, 3];
arr[Symbol.iterator]; // 특별한 형태의 함수
```

iterable 객체는 다음을 사용할 수 있습니다.
- 반복문 for / of
- spread 연산자 (...)
- 분해대입
- iterable을 인수로 받는 함수

### Generator
- `generator` 함수는 호출시 iterable 객체를 생성하는 함수입니다.
- generator 함수는 다음 방법으로 정의할 수 있습니다.

```
// gen은 generator 함수입니다.
function* gen() {
	// ...
}
const it = gen(); // it은 iterable 객체입니다.
```

- generator 함수는 일반 함수와 비슷하지만, `yield` 키워드를 사용할 수 있다는 차이가 있습니다.
- iterable 객체가 반복되면, yield의 값들이 순차적으로 반환됩니다.
	- 각 반복 과정마다, 현재 yield를 만날 때까지 generator 내 코드가 실행됩니다.
	- 반복이 끝나면 마지막 yield의 뒤쪽 코드가 실행됩니다.

```
function* gen() {
	yield 1;
	yield 2;
	yield 3;
}
for(n of gen())
	console.log(n); // 1 2 3
```

```
function* gen() {
	console.log(1);
	yield 'A';
	console.log(2);
	yield 'B';
	console.log(3);
}
for(n of gen()) {
	console.log(n); // 1 A | 2 B | 3
	console.log('|');
}
```

- `yield*`를 사용하면 다른 generator 함수의 yield 값을 받을 수 있습니다.

```
function* gen1() {
	yield 1;
	yield 2;
}
function* gen2() {
	yield* gen1();
	yield* gen1();
}
for(n of gen2())
	console.log(n); // 1 2 1 2
```

- generator 함수가 생성한 iterable 객체는 한 번만 반복 가능합니다.
		- 반면, `String`, `Array` 등은 여러 번 반복 가능합니다.

```
function* gen() {
	yield 1;
	yield 2;
}
const it = gen();

for(n of it)
	console.log(n); // 1 2
for(n of it)
	console.log(n); // 실행되지 않습니다!
```

- 그외 활용처로, generator와 yield 키워드의 특성을 활용해서 `비동기 프로그래밍`을 구현할 수도 있습니다.

### Iterator
- 객체가 iterable을 만족하려면, `Symbol.iterator` 속성에 저장되는 함수가 `iterator` 객체를 반환해야 합니다.
- iterator 객체는 `iterator protocol` 조건을 만족하는 객체입니다. (iterable과 다릅니다!)
- iterator protocol 조건은 다음과 같습니다.

> 1. iterator는 `next`라는 메소드를 갖습니다.<br>
> 2. `next` 메소드는 다음 두 속성을 갖는 객체를 반환해야 합니다.<br>
> 	- `value`: 현재 순서의 값<br>
> 	- `done`: 반복이 모두 끝났는지 표시<br>

```
function* gen() {
	yield 1;
	yield 2;
}
const itr = gen()[Symbol.iterator](); // iterator 객체
console.log(itr.next()); // { value: 1, done: false }
console.log(itr.next()); // { value: 2, done: false }
console.log(itr.next()); // { value: undefined, done: true }
```

### Generator & Iterator
generator 함수로부터 만들어진 객체는 다음 특징을 갖습니다.
1. `iterable protocol`과 `iterator protocol`을 모두 만족합니다.
	- generator 함수가 반환한 객체도 next 메소드를 사용해서 반복을 수행할 수 있습니다.
2. generator 함수 안에서 `return` 키워드를 사용하면 반복이 즉시 종료됩니다.
		- return 값은 반복 과정에서 반환되지 않습니다.
		- 단, next 메소드에서 반환되는 객체의 value에는 return 값이 저장됩니다.
3. next 메소드에 인자를 제공할 수 있으며, 이 인자는 이전 순서의 next에 대응하는 yield 표현식 반환값으로 사용됩니다.

```
function* gen() {
	yield 1;
	return 2;
	yield 3;
}
const it1 = gen();
const it2 = gen();

// 반복 과정에선 return 값이 사용되지 않습니다.
for(n of it1)
	console.log(n); // 1

// next의 value에선 return 값이 사용됩니다.
console.log(it2.next()); // { value: 1, done: false }
console.log(it2.next()); // { value: 2, done: true }
console.log(it2.next()); // { value: undefined, done: false }
```

```
function* gen() {
	// yield의 반환값은 이전 next의 인자입니다.
	for(let i = 1; i <= 3; i++)
		console.log(yield i);
}
const it = gen();
it.next('Straw'); // 출력 없음
it.next('Berry'); // Berry
it.next('Apple'); // Apple
it.next('Grape'); // Grape
it.next('Peach'); // 출력 없음
```
{% endraw %}