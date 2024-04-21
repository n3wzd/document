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
