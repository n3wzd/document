---
categories:
- JavaScript
date: '2023-07-15'
title: '[JavaScript] 5. Array'
---

{% raw %}
- `배열(array)`: 이름과 인덱스로 참조되는 정렬된 값의 집합
- `배열 요소(element)`: 배열을 구성하는 각각의 값
- `인덱스(index)`: 배열에서 위치를 가리키는 number
- 배열 요소의 타입은 고정되어 있지 않습니다.
	- 같은 배열에 있는 배열 요소라도 서로 타입이 다를 수 있습니다.
- 인덱스는 불연속적일 수 있습니다.
	- 일부 배열 요소가 undefiend일 수 있습니다.
- 자바스크립트에서 모든 배열은 `Array` 객체로 다뤄집니다.
	- 배열은 `Array` 생성자의 인스턴스입니다.
- 배열의 길이는 `length` 프로퍼티에 저장되어 있습니다.
	- 배열의 길이가 변동되면 length도 자동으로 갱신됩니다.

### 사용법
#### 생성
- 배열을 생성하는 방법은 다음이 있습니다. (결과는 모무 동일합니다.)

> 1. var `arr` = \[`element1`, `element2`, ...\];<br>
> 2. var `arr` = Array(`element1`, `element2`, ...);<br>
> 3. var `arr` = new Array(`element1`, `element2`, ...);<br>

```
var arr = [false, 1, "2", { n: 3 }, [4]];
```

#### 참조
- `[]`연산자를 활용해서 배열 요소를 참조할 수 있습니다.
- 인덱스의 범위는 \[0, 2<sup>32</sup>\)입니다.
- 배열의 현재 길이보다 더 큰 인덱스에 배열 요소를 접근/저장하는 것이 가능합니다.
	- 만약 값을 저장한다면, 배열의 길이는 해당 인덱스만큼 자동으로 연장됩니다.
- `홀(hole)`: 인덱스에 대응하는 배열 요소가 비어있는 부분
	- undefiend 값을 갖습니다.

> `arr`\[`index`\]<br>

```
var arr = [1, 2, 3];
console.log(arr[1]); // 2

arr[4] = 5;
console.log(arr); // [1, 2, 3, undefiend, 5]
```

#### 추가
- 새로운 배열 요소를 추가하는 방법은 다음과 같습니다.
- `push` 메소드를 사용하면 배열 맨 끝에 추가됩니다.
- `index`를 사용하면 해당 인덱스에서 값이 변경/추가됩니다.

> 1. arr.push(`element`);<br>
> 2. arr\[`index`\] = `element`;<br>

#### 순회
- 반복문을 사용해서 모든 요소에 접근할 수 있습니다.
	- `for/ in`, `for / of`를 사용하면 간편하게 순회할 수 있습니다.

```
var arr = [1, 2, 3, 4, 5];
for(n of arr)
	console.log(n); // 1 2 3 4 5
```

### 활용
#### 희소 배열
- `희소 배열`: 배열 요소가 불연속인 배열
	- 배열 요소의 개수 < length

```
var arr = [];
arr[2] = 0;
console.log(arr.length); // 3
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

```
// 실행 결과
[1, 2, 3, 4]
[5, 6, 7, 8]
[9, 10, 11, 12]
```

####  문자열 배열
- 자바스크립트에서 문자열은 읽기 전용 배열로 다룰 수 있습니다.
- `[]` 연산자, Array 객체가 제공하는 메소드를 사용할 수 있습니다.
- 읽기 전용이므로 쓰기는 불가능합니다.

```
var str = "JavaScript";
console.log(str[4]);
console.log(str.length);

str[4] = 'A'; // 반영되지 않습니다.
console.log(str);
```

```
// 실행 결과
S
10
JavaScript
```

#### 배열 여부 확인
- 자바스크립트에선 배열이라는 타입(type)이 없습니다.
	- Array 객체로 배열을 다루기 때문입니다.
	- typeof 연산자는 "object"를 반환합니다.
- 대신, 다음과 같은 방법으로 배열을 판정할 수 있습니다.
	- true 반환시, `target`은 배열입니다.

> 1. Array.isArray(`target`);       // Array 메소드 사용<br>
> 2. `target` instanceof Array    // instanceof 연산자 사용<br>

```
var arr = [], str = "";
console.log(Array.isArray(arr));    // true
console.log(str instanceof Array);  // false
```
{% endraw %}