---
categories:
- TypeScript
date: '2024-04-22'
title: '[TypeScript] 3. Array'
---

{% raw %}
TypeScript에서 배열(Array)은 동적으로 할당된 요소들의 집합을 나타내는 데이터 구조입니다. 전체적인 사용법은 JavaScript와 같습니다.

### 타입 지정된 배열
배열에 포함될 요소의 타입을 미리 지정할 수 있습니다.
```
let numbers: number[] = [1, 2, 3, 4, 5];
let names: string[] = ["Alice", "Bob", "Charlie"];
```

### 제네릭 배열
제네릭을 사용하여 배열의 요소 타입을 동적으로 지정할 수 있습니다.
```
let items: Array<number> = [1, 2, 3, 4, 5];<br>
```

### 튜플 (Tuples)
튜플(Tuples)은 각 요소의 유형이 고정된 배열입니다. 선언된 요소 외에 다른 인덱스에 접근 시 오류가 발생합니다.

```
let myTuple: [string, number, boolean];
myTuple = ["Hello", 123, true];
console.log(myTuple[0]); // 출력: Hello
console.log(myTuple[1]); // 출력: 123
console.log(myTuple[2]); // 출력: true
myTuple[3] = "extra"; // 에러
```
{% endraw %}