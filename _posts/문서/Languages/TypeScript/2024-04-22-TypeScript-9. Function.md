---
categories:
- TypeScript
date: '2024-04-22'
title: '[TypeScript] 9. Function'
---

{% raw %}
TypeScript에서 함수는 JavaScript의 함수와 매우 유사하며, 추가적인 타입 시스템을 통해 매개변수 및 반환 값의 유형을 지정할 수 있습니다.

```
function add(x: number, y: number): number {
    return x + y;
}
```

위의 코드에서 `add` 함수는 `number` 타입의 `x`와 `y` 매개변수를 받고, `number`를 반환합니다.

### 선택적 매개변수
함수 매개변수를 선택적으로 만들려면 매개변수 이름 뒤에 물음표(`?`)를 붙입니다.

```
function greet(name?: string) {
    if (name) {
        console.log(`Hello, ${name}!`);
    } else {
        console.log(`Hello, stranger!`);
    }
}
```

### 기본 매개변수 값
함수에 기본 매개변수 값을 할당할 수 있습니다.

```
function greet(name: string = "stranger") {
    console.log(`Hello, ${name}!`);
}
```

### 나머지 매개변수
함수에서 임의의 수의 매개변수를 수용하기 위해 나머지 매개변수를 사용할 수 있습니다.

```
function sum(...numbers: number[]): number {
    return numbers.reduce((total, num) => total + num, 0);<br>
}
```

### 익명 함수
익명 함수는 이름이 없는 함수로, 주로 콜백 함수로 사용됩니다.

```
let greet = function(name: string) {
    console.log(`Hello, ${name}!`);
};
```
{% endraw %}