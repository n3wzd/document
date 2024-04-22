# TypeScript
`TypeScript`는 `JavaScript`의 확장된 버전인 오픈 소스 프로그래밍 언어입니다. JavaScript는 동적 타입 언어이기 때문에 코드의 유연성은 높지만, 개발 중 발생하는 오류를 미리 파악하기 어렵고 유지 보수가 어려울 수 있습니다. TypeScript는 이러한 문제를 해결하기 위해 정적 타입 시스템을 제공하여 이러한 문제를 해결합니다.

- **정적 타입 지정**: TypeScript는 변수, 함수, 클래스 등에 명시적인 타입을 지정할 수 있습니다. 이를 통해 컴파일러가 코드를 분석하여 타입 관련 오류를 사전에 발견할 수 있습니다.
- **타입 추론**: 타입스크립트는 변수나 함수에 타입을 명시하지 않아도 컴파일러가 할당된 값 등을 기반으로 타입을 추론합니다.
- **클래스와 인터페이스**: TypeScript는 클래스와 인터페이스를 지원하여 객체지향 프로그래밍을 지원합니다.
- **최신 JavaScript 문법 지원**: TypeScript는 ECMAScript 2015(ES6)부터 최신 ESNext까지의 기능을 모두 지원합니다.
- **컴파일러**: TypeScript는 코드를 JavaScript로 변환해주는 컴파일러를 제공합니다. 이를 통해 TypeScript 코드를 JavaScript 코드로 변환할 수 있습니다.

## 타입 (Types)
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
let fruits: Array<string> = ["apple", "banana", "orange"];
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
type MathFunction = (x: number, y: number) => number;

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

#### Null, Undefined
단독으로는 그다지 유용하지 않지만, 다른 타입의 하위 타입으로 사용됩니다.

```
let u: undefined = undefined;
let n: null = null;
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

## 배열 (Array)
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
let items: Array<number> = [1, 2, 3, 4, 5];
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

## 객체 (Object)
객체(Object)는 여러 속성(key-value 쌍)을 포함하는 데이터 구조입니다.

```
type Person = {
    name: string;
    age: number;
    email: string;
};
let person: Person = {
    name: "John",
    age: 30,
    email: "john@example.com"
};
```

객체 유형은 선택적 속성, 읽기 전용 속성 등을 정의할 수도 있습니다.

```
type Person = {
    name: string;
    age: number;
    email?: string; // 선택적 속성
};
```

## 열거형 (Enums)
열거형(Enums)은 특정 값 집합을 이름으로 정의할 수 있는 기능으로, 숫자 또는 문자열 값의 집합을 나타냅니다.

### 숫자 열거형
숫자 열거형은 숫자 값에 대한 집합을 정의합니다. 기본적으로는 0부터 시작하여 숫자를 1씩 증가시키며 할당됩니다.

```
enum Direction {
    Up, // 0
    Down, // 1
    Left, // 2
    Right // 3
}
```
열거형 멤버에 직접 값을 할당할 수도 있습니다:

```
enum Direction {
    Up = 1,
    Down, // 2
    Left, // 3
    Right // 4
}
```

### 문자열 열거형
문자열 열거형은 각 멤버에 대해 명시적으로 값을 지정할 수 있으며, 숫자 대신 문자열 값을 사용합니다.

```
enum Color {
    Red = "RED",
    Green = "GREEN",
    Blue = "BLUE"
}
```

## 타입 별칭(Type Aliases)
타입 별칭은 새로운 타입의 별칭을 생성하는 데 사용됩니다. 이를 통해 복잡한 타입을 더 짧고 명확하게 표현할 수 있습니다.

```
type Point = {
    x: number;
    y: number;
};
```

위의 코드에서 `Point`는 객체 유형 `{ x: number; y: number; }`의 별칭입니다. 이제 `Point`를 사용하여 유형을 참조할 수 있습니다.

```
let p: Point = { x: 10, y: 20 };
```

## 인터페이스(Interfaces)
인터페이스는 객체의 구조를 정의하기 위한 기능입니다. 인터페이스를 사용하면 객체가 특정 속성이나 메서드를 가져야 한다는 것을 명시적으로 선언할 수 있습니다.

```
interface Person {
    name: string;
    age: number;
    greet(): void;
}
```

위의 코드에서 `Person` 인터페이스는 `name`, `age` 속성과 `greet` 메서드를 가져야 한다는 것을 정의합니다. 이제 이 인터페이스를 구현하는 객체는 해당 속성과 메서드를 가지고 있어야 합니다.

인터페이스는 클래스뿐만 아니라 다른 객체 형식에도 적용될 수 있습니다.
```
class Employee implements Person {
    name: string;
    age: number;

    constructor(name: string, age: number) {
        this.name = name;
        this.age = age;
    }

    greet() {
        console.log(`Hello, my name is ${this.name}.`);
    }
}
```

## 공용 유형 (Union Types)
공용 유형은 여러 유형 중 하나를 나타낼 수 있는 특별한 유형입니다. 공용 유형은 파이프(`|`)로 구분된 두 개 이상의 유형으로 이루어집니다.

```
let myVar: number | string;

myVar = 10; // 숫자 할당
console.log(myVar);

myVar = "Hello"; // 문자열 할당
console.log(myVar);
```

## 함수 (function)
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
    return numbers.reduce((total, num) => total + num, 0);
}
```

### 익명 함수
익명 함수는 이름이 없는 함수로, 주로 콜백 함수로 사용됩니다.

```
let greet = function(name: string) {
    console.log(`Hello, ${name}!`);
};
```
