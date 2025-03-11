---
categories:
- TypeScript
date: '2024-04-21'
title: '[TypeScript] 2. Types'
---

{% raw %}
### 기본 타입 (Simple Types)
#### Boolean
`true` 또는 `false` 값을 가지는 타입입니다.

```
let isDone: boolean = false;
```

#### Number
숫자를 나타내는 타입으로, 모든 종류의 숫자(정수, 부동 소수점 등)를 포함합니다.

```
let decimal: number = 6;
let hex: number = 0xf00d;
let binary: number = 0b1010;
let octal: number = 0o744;` 
```

#### String
문자열을 나타내는 타입입니다.

```
let color: string = "blue";
let fullName: string = `Bob Bobbington`;
```
####  Array
배열을 나타내는 타입입니다. 배열 요소의 타입은 미리 지정할 수 있습니다.

```
let list: number[] = [1, 2, 3];
let fruits: Array<string> = ["apple", "banana", "orange"];<br>
```

#### Tuple
고정된 개수의 요소로 이루어진 배열을 나타내는 타입입니다. 각 요소의 타입이 미리 정해져 있습니다.

```
let x: [string, number];
x = ["hello", 10]; // OK
x = [10, "hello"]; // Error
```

#### Enum
열거형 타입으로, 숫자 또는 문자열 집합에 이름을 부여할 수 있습니다.

```
enum Color {
    Red,
    Green,
    Blue,
}
let c: Color = Color.Green;
```

### 특수 타입 (Special Types)
#### Any
어떤 타입이든 허용하는 동적 타입입니다. 가능한 사용을 최소화하는 것이 좋습니다.

```
let notSure: any = 4;
notSure = "maybe a string instead";
notSure = false; // OK
```

#### Unknown
`any`와 비슷하지만, `any`보다 더 안전한 동적 타입입니다. `unknown` 타입의 변수는 임의의 값에 할당할 수 있지만, 이 값을 사용하기 전에 명시적으로 타입 체크나 타입 단언을 통해 타입을 지정해야 합니다.

```
let userInput: unknown;
let userName: string;

userInput = 5;
userInput = "hello";

// Type check or type assertion required
if (typeof userInput === "string") {
    userName = userInput;
}
```

#### Never
절대 발생하지 않는 값의 타입을 나타냅니다. 주로 예외를 던지거나 무한 루프를 돌 때 사용됩니다.

```
function error(message: string): never {
    throw new Error(message);
}

function infiniteLoop(): never {
    while (true) {}
}
```

#### Object
모든 비 원시 타입을 나타내는 타입입니다. 즉, `number`, `string`, `boolean`, `symbol`, `null`, 또는 `undefined`가 아닌 모든 것을 포함합니다.

```
function create(obj: object | null): void {
    // Do something
}

create({ prop: 0 }); // OK
create(null); // OK
create(42); // Error
```

#### Function
함수 타입은 매개변수의 유형과 반환 유형을 지정하여 함수의 모양을 설명합니다.

```
type MathFunction = (x: number, y: number) => number;<br>

let add: MathFunction = function(x, y) {
    return x + y;
};
```

#### Void
반환 값이 없는 함수의 반환 타입으로 사용됩니다.

```
function warnUser(): void {
    console.log("This is a warning message");
}
```

#### null
null은 값이 없음을 나타냅니다. 변수에 null을 할당할 수 있습니다.

```
let foo: string | null;
foo = "Hello"; // 올바른 할당
foo = null;    // 올바른 할당
```

#### undefined
undefined는 값이 할당되지 않았음을 나타냅니다. 기본적으로 변수를 선언하고 초기화하지 않았을 때 해당 변수는 undefined 값을 가집니다.

```
let bar: number;
console.log(bar); // 출력: undefined
```

### 캐스팅 (casting)
#### angle-bracket(<>) 구문
JSX를 사용하지 않는 환경에서 주로 사용됩니다.

```
let someValue: any = "this is a string";
let strLength: number = (<string>someValue).length;
```
        
#### as 구문
JSX와 함께 사용할 때나 TypeScript의 JSX와 충돌을 피하기 위해 사용됩니다.

```
let someValue: any = "this is a string";
let strLength: number = (someValue as string).length;
```
{% endraw %}