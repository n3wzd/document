---
categories:
- JavaScript
date: '2023-07-14'
title: '[JavaScript] 4. Control Flow'
---

{% raw %}
- `제어문`: 프로그램의 순차적인 흐름을 제어할 때 사용되는 실행문입니다.

### 조건문 (Conditional Statements)
- `조건문`: 주어진 조건을 따라 별도의 명령을 수행하는 제어문입니다.

#### if
- `if`: 조건이 true면 주어진 실행문을 실행하는 조건문입니다.
- `else`: 이전 if가 실행되지 않으면, 여기가 실행됩니다.

> if(`condition1`) {<br>
> 	(`condition1`가 true일 때 실행)<br>
> }<br>
> else if(`condition2`) {<br>
> 	(`condition1`가 false, `condition2`가 true일 때 실행)<br>
> }<br>
> else {<br>
> 	(`condition1`가 false, `condition2`가 false일 때 실행)<br>
> }<br>

```
var n1 = 3, n2 = 5;
if(n1 > n2)<br>
	console.log("n1은 n2보다 큽니다.");
else if(n1 < n2)
	console.log("n1은 n2보다 작습니다.");
else
	console.log("n1은 n2하고 같습니다.");
```

```
// 실행 결과
n1은 n2보다 작습니다.
```

#### switch
- `switch`: 값을 기준으로 여러 case 분기로 나눈 조건문입니다. 주어진 조건 값이 알맞은 case 값을 만족하면 그 위치로 jump하는 방식입니다.
- `case` 내에 있는 `break`는 switch를 탈출하는 기능을 합니다. 만약 break를 넣지 않으면 case 값과 관계없이 아래 실행문이 이어서 실행됩니다.
- 조건 값이 어떠한 case도 해당되지 않으면 `default`로 이동합니다.
	- default 유무는 선택사항입니다.

> switch (`target`) {<br>
> 	case `value1`:<br>
> 		(`target` \=\= `value1`이면 여기로 이동함)<br>
> 		break;<br>
> 	case `value2`:<br>
> 		(`target` \=\= `value2`이면 여기로 이동함)<br>
> 		break;<br>
> 	...<br>
> 	default:<br>
> 		(어떠한 case도 해당되지 않으면 여기로 이동함)<br>
> 		break;<br>
> }<br>

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

```
// 실행 결과
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

```
// 실행 결과
n은 3보다 같거나 큽니다.
n은 4보다 같거나 큽니다.
n은 5보다 같거나 큽니다.
끝!
```

### 반복문 (Iteration Statements)
- `반복문`: 같은 구간을 주어진 횟수만큼 반복 수행하는 제어문입니다.

#### while
- `while`: 주어진 조건이 false일 때까지 반복하는 제어문입니다.
	- 조건 검사를 먼저 수행한 뒤, 루프를 진행합니다.

> while(`condition`) {<br>
> 	(`condition`이 true면 실행)<br>
> }<br>

```
var i = 3;
while(i > 0)<br>
	console.log(i--);
```

```
// 실행 결과
3
2
1
```

#### do / while
- `do / while`: while과 비슷하나, 루프를 실행한 뒤 조건을 검사합니다.

> do {<br>
> 	(`condition`이 true면 실행)<br>
> } while(`condition`);<br>

```
var i = 0;
do {
	console.log(i--);
} while(i > 0);<br>
```

```
// 실행 결과
0
```

#### for
- `for`: 초기식, 조건식, 증감식을 가진 반복문입니다.

> for(`initial`; `condition`;  `incremental`) {<br>
> 	(`condition`이 true면 실행)<br>
> }<br>

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

```
// 실행 결과
0
1
2
```

#### for / in
- `for / in`: 주어진 객체의 열거 가능한 프로퍼티 인덱스를 열거하는 반복문입니다.
	- 부수속성 `enumerable`이 true인 프로퍼티만 순회합니다.
- 사용 방법은 다음과 같습니다. `index`는 루프마다 열거되는 `object`의 프로퍼티 인덱스 문자열입니다.

> for(`index` in `object`) {<br>
> 	(`object`의 열거 가능한 프로퍼티 개수만큼 반복)<br>
> }<br>

```
var arr = [1, 2, 3];
for(i in arr)
	console.log(i); // 0 1 2
```

```
var obj = { name: "klee", id: 2 };
for(p in obj)
	console.log(p); // name id
```

#### for / of
- `for / of`: 주어진 객체의 프로퍼티 값을 열거하는 반복문입니다.
	- 순회 가능한 객체(iterable objects)만 적용 가능합니다. (ex. Array, Map, Set ...)
- 사용 방법은 다음과 같습니다. `target`은 루프마다 열거되는 `object`의 프로퍼티 값입니다.

> for(`target` of `object`) {<br>
> 	(`object`의 프로퍼티 개수만큼 반복)<br>
> }<br>

```
var arr = [1, 2, 3];
for(n of arr)
	console.log(n); // 1 2 3
```

### 기타 제어문
#### label
- `label`: 특정 영역을 식별해주는 식별자

> `label`:<br>
> (식별할 특정 영역)<br>

```
loop:
for(n of arr)
	console.log(n);
```

#### continue
- `continue`: 현재 루프의 조건식으로 jump하는 조건문
- label을 통해 특정 루프를 지정할 수 있습니다.

> continue;<br>
> continue `label`;<br>

- 예제 1
```
for(var i = 1; i <= 5; i++) {
	if(i % 2 == 0)
		continue;
	console.log(i);
}
```

```
// 실행 결과
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

```
// 실행 결과
0
1
0
2
1
0
```

#### break
- `break`: 현재 루프를 탈출하는 조건문
- label을 통해 특정 루프를 지정할 수 있습니다.

> break;<br>
> break `label`;<br>

- 예제 1
```
for(var i = 1; i <= 5; i++) {
	if(i == 4)
		break;
	console.log(i);
}
```

```
// 실행 결과
1
2
3
```

- 예제 2
```
loop1:
for(var i = 1; i <= 5; i++) {
	for(var j = 1; j <= 5; j++) {
		if(i * j > 5)<br>
			break loop1;
		console.log(i * j);
	}
}
```

```
// 실행 결과
1
2
3
4
5
2
4
```
{% endraw %}