# JAVA
## 도입 (Intro)
Java는 1995년에 선보인 객체지향 프로그래밍 언어입니다. 플랫폼 독립적이며, 간결하고 확장성이 뛰어나며 안정성이 높은 특징을 가지고 있습니다. Java는 다양한 응용 분야에서 사용되며, 특히 웹 개발, 모바일 애플리케이션, 기업 시스템에서 널리 사용되고 있습니다.

- **플랫폼 독립성:** Java는 JVM(Java Virtual Machine) 위에서 동작하기 때문에 어떤 플랫폼에서도 실행 가능합니다.
- **객체지향:** 코드의 재사용성이 높고, 유지보수가 쉽습니다.
- **간결성:** 다양한 기능을 제공하면서도 간결한 문법을 가지고 있습니다.
- **웹 개발:** Java Servlet, JSP를 이용한 서버 사이드 웹 애플리케이션 개발에 많이 사용됩니다.
- **모바일 애플리케이션:** Android 앱 개발에서 주로 활용됩니다.
- **기업 시스템:** 대규모 기업 시스템의 개발에 적합하며, 안정성이 요구되는 환경에서 많이 사용됩니다.

## 기본 (Basic)
Java의 기본 문법은 C, C++와 유사하며, 중괄호({})를 이용하여 블록을 구분합니다.

```
public class HelloWorld {
    public static void main(String[] args) {
        System.out.println("Hello, World!");
    }
}
```

### main Method
`main` 메서드는 Java 프로그램의 시작점(entry point)으로 사용되는 특별한 메서드입니다. Java 애플리케이션은 프로그램이 실행될 때 JVM(Java Virtual Machine)이 `main` 메서드를 찾아서 호출하게 됩니다.

```
public static void main(String[] args) {
    // 프로그램의 시작 지점
}
```

### Print
`System.out.println()` 메서드를 사용해서 콘솔 화면에 텍스트를 출력할 수 있습니다.

```
System.out.println("Hello, Java!");` 
```

### 주석 (Comment)
한 줄 주석은 `//`로 시작하고, 여러 줄 주석은 `/* */`로 감싸줍니다.

```
// 이것은 한 줄 주석입니다.

/*
여러 줄 주석은
이렇게 사용할 수 있습니다.
*/
```

### 변수 (Variable)
변수는 데이터를 저장하기 위한 메모리 공간을 가리킵니다. Java에서 변수를 사용하려면 먼저 변수를 선언하고 초기화해야 합니다.

### 선언과 초기화
Java에서 변수는 다음과 같이 선언됩니다:

```
int age; // 데이터 타입 변수명
age = 25; // 변수 초기화
int level = 15; // 변수 선언과 초기화` 
```

### 식별자 (Identifiers)
식별자는 변수, 메서드, 클래스, 패키지 등을 식별하는 데 사용되는 이름입니다. Java에서 식별자의 명명 규칙은 다음과 같습니다:

- 대소문자를 구분합니다.
- 첫 글자는 문자, 언더스코어(`_`), 달러 기호(`$`) 중 하나로 시작해야 합니다.
- 이후에는 문자, 숫자, 언더스코어, 달러 기호를 포함하여 사용할 수 있습니다.
- 예약어를 식별자로 사용할 수 없습니다.

### 기본 데이터 타입 (Primitive Data Types)
Java는 다양한 기본 데이터 타입을 제공합니다. 이들은 크게 숫자, 논리, 문자로 구분됩니다.

#### 숫자 (Numeric Types)
##### 정수 타입
- **byte:** 8비트 크기의 부호 있는 정수, 범위는 -128에서 127까지
- **short:** 16비트 크기의 부호 있는 정수, 범위는 -32,768에서 32,767까지
- **int:** 32비트 크기의 부호 있는 정수, 범위는 -2^31^에서 2^31-1^까지
- **long:** 64비트 크기의 부호 있는 정수, 범위는 -2^63^에서 2^63-1^까지

```
byte b = 120;
short s = 30000;
int i = 100000;
long l = 1000000000L; // L 또는 l을 숫자 뒤에 붙여서 long 타입임을 나타냄
```

##### 실수 타입
- **float:** 32비트 크기의 부동 소수점
- **double:** 64비트 크기의 부동 소수점

```
float f = 3.14f; // f 또는 F를 숫자 뒤에 붙여서 float 타입임을 나타냄
double d = 3.14;
```

#### 논리 (Boolean Type)
- **boolean:** 참(`true`) 또는 거짓(`false`)을 나타내는 데이터 타입

```
boolean isJavaFun = true;
boolean isFishTasty = false;
``` 

#### 문자 (Character Type)
- **char:** 16비트 크기의 유니코드 문자를 나타내는 데이터 타입

```
char grade = 'A';
char letter = 65; // 유니코드 값으로도 초기화 가능
```

### Java 참조 데이터 타입 (Non-Primitive Data Types)
참조 데이터 타입은 기본 데이터 타입이 아닌, 객체를 참조하는 데이터 타입입니다. 주요 참조 데이터 타입으로는 클래스, 인터페이스, 배열 등이 있습니다.

### 형 변환 (Type Casting)
Java에서 타입 캐스팅은 데이터를 한 타입에서 다른 타입으로 변환하는 과정을 의미합니다.

#### 자동 형 변환 (Implicit Casting)
자동 형 변환은 작은 데이터 타입에서 큰 데이터 타입으로의 변환을 자동으로 처리하는 것을 의미합니다. 이때 데이터의 손실이나 에러가 발생하지 않습니다. 자동 형 변환은 작은 데이터 타입에서 큰 데이터 타입으로만 가능합니다.

```
int intValue = 10;
double doubleValue = intValue; // 자동 형 변환

System.out.println(intValue);    // 10
System.out.println(doubleValue); // 10.0
```

위의 예제에서 `int` 값이 `double`로 자동으로 형 변환되었습니다. 이는 `double`이 `int`보다 더 큰 표현 범위를 가지기 때문에 안전하게 수행됩니다.

#### 강제 형 변환 (Explicit Casting)
강제 형 변환은 큰 데이터 타입에서 작은 데이터 타입으로의 변환을 수동으로 지정하는 것을 의미합니다. 이때 데이터의 손실이나 에러가 발생할 수 있으므로 주의해야 합니다. 강제 형 변환은 큰 데이터 타입에서 작은 데이터 타입으로의 변환일 때에만 가능합니다.

```
double doubleValue = 10.5;
int intValue = (int) doubleValue; // 강제 형 변환

System.out.println(doubleValue); // 10.5
System.out.println(intValue);    // 10
```

위의 예제에서 `double` 값이 `int`로 강제 형 변환되었습니다. 소수 부분은 버려지고 정수 부분만 남게 됩니다.

### 특수 문자 (Special Characters)
Java에서는 특수 문자(Special Characters)를 사용하여 특별한 의미나 동작을 나타냅니다. 이러한 특수 문자는 주로 이스케이프 시퀀스(escape sequence)라고 불리며 역슬래시(`\`)로 시작합니다.

- `\n`: 개행 문자 (New Line)
- `\t`: 탭 문자 (Tab)
- `\\`: 역슬래시 (Backslash)
- `\"`: 큰따옴표 (Double Quote)
- `\'`: 작은따옴표 (Single Quote)
- `\r`: 캐리지 리턴 (Carriage Return)
- `\b`: 백스페이스 (Backspace)
- `\f`: 페이지 넘김 (Form Feed)

## 연산자(Operators)
Java에서는 다양한 연산자(Operators)를 제공하여 변수 및 값들 간의 다양한 연산을 수행할 수 있습니다. 여러 가지 종류의 연산자가 있으며, 각각은 특정한 동작을 수행합니다.

### 산술 연산자 (Arithmetic Operators)
산술 연산자는 기본적인 수학적 연산을 수행합니다.

- `+`: 덧셈
- `-`: 뺄셈
- `*`: 곱셈
- `/`: 나눗셈
- `%`: 나머지

```
int a = 10;
int b = 3;

int sum = a + b; // 13
int difference = a - b; // 7
int product = a * b; // 30
int quotient = a / b; // 3
int remainder = a % b; // 1
```

### 대입 연산자 (Assignment Operators)
대입 연산자는 변수에 값을 할당하는 데 사용됩니다.

- `=`: 변수에 값을 할당

```
`int x = 5; // 변수 x에 5를 할당
```

### 증감 연산자 (Increment and Decrement Operators)
증감 연산자는 변수의 값을 1씩 증가시키거나 감소시킵니다.

- `++`: 증가 연산자
- `--`: 감소 연산자

```
int count = 10;
count++; // count는 11이 됨
count--; // count는 10으로 돌아감
```

### 비교 연산자 (Comparison Operators)
비교 연산자는 두 값의 관계를 비교하여 참(`true`) 또는 거짓(`false`)을 반환합니다.

- `==`: 동등 비교
- `!=`: 부등 비교
- `>`: 크다
- `<`: 작다
- `>=`: 크거나 같다
- `<=`: 작거나 같다

```
int x = 5;
int y = 10;

System.out.println(x == y); // false
System.out.println(x != y); // true
System.out.println(x > y);  // false
System.out.println(x < y);  // true
```

### 논리 연산자 (Logical Operators)
논리 연산자는 논리적인 조건을 결합하여 복합적인 조건을 만듭니다.

- `&&` (AND): 논리 AND
- `||` (OR): 논리 OR
- `!` (NOT): 논리 NOT

```
boolean isJavaFun = true;
boolean isFishTasty = false;

System.out.println(isJavaFun && isFishTasty); // false
System.out.println(isJavaFun || isFishTasty); // true
System.out.println(!isJavaFun); // false
```

### 조건 연산자 (Conditional Operator)
조건 연산자는 조건에 따라 값을 반환합니다.

```
int a = 5;
int b = 10;

int result = (a > b) ? a : b;
System.out.println(result); // 10
```

### 비트 연산자 (Bitwise Operators)
비트 연산자는 이진수로 표현된 값의 비트 단위 연산을 수행합니다.

- `&` (AND): 비트 AND
- `|` (OR): 비트 OR
- `^` (XOR): 비트 XOR
- `~` (NOT): 비트 NOT
- `<<` (Left Shift): 비트를 왼쪽으로 이동
- `>>` (Right Shift): 비트를 오른쪽으로 이동

```
int x = 5; // 이진수로는 0101
int y = 3; // 이진수로는 0011

System.out.println(x & y); // 1 (AND)
System.out.println(x | y); // 7 (OR)
System.out.println(x ^ y); // 6 (XOR)
System.out.println(~x);    // -6 (NOT)
System.out.println(x << 1); // 10 (Left Shift)
System.out.println(x >> 1); // 2 (Right Shift)
```

## 문자열 (String)
Java에서 `String`은 문자열을 나타내는 클래스입니다. 문자열은 텍스트 데이터를 다룰 때 사용되며, Java에서는 문자열을 다루기 위한 다양한 기능을 제공합니다.

### 문자열 생성
Java에서 문자열을 생성하는 방법은 여러 가지가 있습니다.

```
// 문자열 리터럴을 사용
String str1 = "Hello, World!";

// String 클래스의 생성자를 사용
String str2 = new String("Hello, Java!");
```

### 문자열 연산
문자열 연산은 `+` 연산자를 사용하여 문자열을 이어붙일 수 있습니다.

```
String firstName = "John";
String lastName = "Doe";
String fullName = firstName + " " + lastName; // "John Doe"
```

### 문자열의 메서드
`String` 클래스에서는 문자열을 다룰 수 있는 다양한 메서드를 제공합니다.

```
String str = "Hello, Java!";

// 길이 확인
int length = str.length(); // 12

// 문자 추출
char firstChar = str.charAt(0); // 'H'

// 부분 문자열 추출
String subStr = str.substring(7); // "Java!"

// 문자열 결합
String newStr = str.concat(" Welcome!"); // "Hello, Java! Welcome!"

// 대소문자 변환
String upperCase = str.toUpperCase(); // "HELLO, JAVA!"
String lowerCase = str.toLowerCase(); // "hello, java!"

// 문자열 비교
boolean isEqual = str.equals("Hello, Java!"); // true
```

### 문자열의 불변성 (Immutability)
`String` 클래스는 불변(immutable)하다는 특징을 가집니다. 이는 한 번 생성된 문자열은 변경할 수 없다는 것을 의미합니다. 따라서 문자열의 연산이 수행될 때마다 새로운 문자열이 생성되고, 기존 문자열은 그대로 유지됩니다.

```
String original = "Hello";
String modified = original + ", World!"; // 새로운 문자열 생성
```

### 문자열 포매팅 (String Formatting)
문자열 포매팅은 문자열 내에 변수의 값을 동적으로 삽입하는 방법을 의미합니다. 포맷 패턴은 C 언어의 `printf`와 유사한 문법을 따릅니다.

```
String name = "Alice";
int age = 25;

String message = String.format("Hello, %s! You are %d years old.", name, age);
System.out.println(message);
// 출력: "Hello, Alice! You are 25 years old."
```

### 문자열 분할
`split` 메서드를 사용하여 문자열을 특정 구분자를 기준으로 나눌 수 있습니다.

```
String fruits = "Apple,Orange,Banana";
String[] fruitArray = fruits.split(",");
// fruitArray: ["Apple", "Orange", "Banana"]
```

## 조건문 (Conditional Statements)
Java에서 조건문은 주어진 조건에 따라 프로그램의 실행 흐름을 제어하는 데 사용됩니다. Java에서는 `if`, `else`, `else if`, `switch` 등 다양한 조건문이 제공됩니다.

### if
`if` 문은 주어진 조건이 참일 때 특정 블록의 코드를 실행합니다.

```
int x = 10;

if (x > 5) {
    System.out.println("x는 5보다 큽니다.");
}
```

### if...else
`if...else` 문은 주어진 조건이 참이면 하나의 블록을 실행하고, 거짓이면 다른 블록을 실행합니다.

```
int y = 3;

if (y % 2 == 0) {
    System.out.println("y는 짝수입니다.");
} else {
    System.out.println("y는 홀수입니다.");
}
```

### else if
`else if` 문은 여러 개의 조건을 순차적으로 검사하며, 처음으로 참이 되는 조건의 블록만 실행합니다.

```
int score = 85;

if (score >= 90) {
    System.out.println("A 학점");
} else if (score >= 80) {
    System.out.println("B 학점");
} else if (score >= 70) {
    System.out.println("C 학점");
} else {
    System.out.println("D 학점");
}
```

### switch
`switch` 문은 특정 변수의 값에 따라 다양한 경우(case)를 처리하는 데 사용됩니다. `switch` 문에서 각 `case`는 해당하는 값과 일치할 때 실행됩니다. `break` 문을 사용하여 각 `case`에서 실행을 멈춥니다.

- 각 `case`는 서로 겹치지 않아야 합니다.
- `default`는 선택 사항이며, 어떤 `case`와도 일치하지 않을 때 실행됩니다.
- `break`를 사용하지 않으면 일치하는 `case` 이후의 모든 코드가 실행됩니다.

```
int day = 3;

switch (day) {
    case 1:
        System.out.println("월요일");
        break;
    case 2:
        System.out.println("화요일");
        break;
    case 3:
        System.out.println("수요일");
        break;
    default:
        System.out.println("다른 요일");
}
```

## 반복문 (Loop Statements)
Java에서 반복문은 프로그램에서 동일한 코드 블록을 여러 번 실행할 때 사용됩니다.

### while
`while` 문은 주어진 조건이 참인 동안 계속해서 반복됩니다. 조건이 처음부터 거짓이면 코드 블록은 실행되지 않습니다.

```
while (조건식) {
    // 반복 실행될 코드 블록
}
```

### do-while
`do-while` 문은 `while` 문과 유사하지만, 코드 블록이 최소한 한 번은 실행된다는 차이가 있습니다. 조건이 거짓이어도 최초 한 번은 코드 블록이 실행됩니다.

```
do {
    // 반복 실행될 코드 블록
} while (조건식);
```

### for
`for` 문은 초기화 식, 조건식, 증감식으로 구성되어 있습니다. 초기화 식은 반복문이 시작할 때 딱 한 번 실행되며, 조건식은 각 반복마다 평가되어 참일 경우에만 반복문이 실행됩니다. 증감식은 각 반복이 끝난 후 실행됩니다.

```
for (초기화식; 조건식; 증감식) {
    // 반복 실행될 코드 블록
}
```

### for each
`for each` 문는 배열 또는 컬렉션과 같은 iterable 객체의 모든 요소에 대해 반복적으로 작업할 때 사용됩니다. 이 반복문은 배열의 각 요소나 컬렉션의 각 항목을 차례로 처리할 때 간편하게 사용할 수 있습니다.

```
for (변수타입 변수명 : 배열 또는 컬렉션) {
    // 배열 또는 컬렉션의 각 요소에 대한 작업
}
```

```
int[] numbers = {1, 2, 3, 4, 5};

// For Each Loop를 사용하여 배열의 각 요소 출력
for (int num : numbers) {
    System.out.println(num);
}
```

### break
`break` 문은 반복문을 강제로 종료할 때 사용됩니다. `break`가 실행되면 가장 가까운 반복문(while, do-while, for)을 종료하고 해당 반복문 다음의 코드로 이동합니다.

```
for (int i = 0; i < 10; i++) {
    if (i == 5) {
        System.out.println("Loop is breaking at i = " + i);
        break;
    }
    System.out.println(i);
}
```

### continue
`continue` 문은 반복문의 현재 반복을 중지하고 다음 반복으로 넘어갑니다. `continue`가 실행되면 반복문의 나머지 코드는 실행되지 않고, 다음 반복이 시작됩니다.

```
for (int i = 0; i < 5; i++) {
    if (i == 2) {
        System.out.println("Loop is continuing at i = " + i);
        continue;
    }
    System.out.println(i);
}
```

## 배열 (Array)
Java에서 배열(Array)은 동일한 데이터 타입의 여러 값을 담을 수 있는 자료구조입니다. 배열은 크기가 고정되어 있으며, 각 요소는 인덱스를 통해 접근할 수 있습니다.

### 배열 생성
배열을 생성하는 방법은 다음과 같습니다:

```
// 선언과 생성을 동시에
int[] numbers = new int[5];

// 선언 후 나중에 생성
int[] numbers;
numbers = new int[5];
```

### 배열 초기화
배열을 생성하면 각 요소에는 해당 데이터 타입의 기본 값이 할당됩니다. 초기값을 지정하여 배열을 초기화할 수 있습니다.

```
int[] numbers = {1, 2, 3, 4, 5};
```

```
int[] numbers = new int[5];
for (int i = 0; i < 5; i++) {
    numbers[i] = i + 1;
}
```

### 배열 요소 접근
배열의 각 요소에는 인덱스를 사용하여 접근할 수 있습니다. 인덱스는 0부터 (배열의 길이 - 1)까지의 값을 가집니다.

```
int[] numbers = {1, 2, 3, 4, 5};

// 배열 요소에 접근하여 출력
System.out.println(numbers[0]); // 1
System.out.println(numbers[2]); // 3
```

### 배열 길이
배열의 길이는 `length` 속성을 통해 얻을 수 있습니다.

```
int[] numbers = {1, 2, 3, 4, 5};
System.out.println("배열의 길이: " + numbers.length); // 5
```

### 다차원 배열
Java에서는 다차원 배열도 지원합니다. 2차원 배열은 행(row)과 열(column)로 구성됩니다.

```
int[][] matrix = new int[3][4]; // 3행 4열의 2차원 배열
```

## 메서드(Method)
Java에서 메서드(Method)는 코드의 논리적인 부분을 모듈화하고 재사용성을 높이기 위해 사용되는 코드 블록입니다. 메서드는 특정 작업을 수행하는 코드를 묶어서 호출할 수 있도록 합니다.

### 메서드 선언
메서드는 다음과 같이 선언됩니다.

```
modifier returnType methodName(parameter1Type parameter1Name, parameter2Type parameter2Name, ...) {
    // 메서드의 실행 코드
    return returnValue;
}
```

- `modifier`: 메서드의 접근 제어자를 나타내며, public, private, protected, default 등이 사용될 수 있습니다.
- `returnType`: 메서드가 반환하는 값의 데이터 타입을 나타냅니다. 메서드가 값을 반환하지 않을 경우 `void`를 사용합니다.
- `methodName`: 메서드의 이름입니다.
- `parameter1Type`, `parameter2Type`, ...: 메서드에 전달되는 매개변수의 데이터 타입과 이름입니다.
- `returnValue`: 메서드가 반환하는 값입니다.

### 메서드 호출
메서드는 다음과 같이 호출됩니다:

```
returnType result = methodName(argument1, argument2, ...);
```

- `returnType`: 메서드가 반환하는 값의 데이터 타입입니다.
- `methodName`: 호출하려는 메서드의 이름입니다.
- `argument1`, `argument2`, ...: 메서드에 전달되는 인수(매개변수)입니다.

아래 예제에서 `addNumbers` 메서드는 두 개의 정수를 받아 더하고 그 결과를 반환하는 간단한 메서드입니다.

```
public class Example {
    public static void main(String[] args) {
        // 메서드 호출
        int sum = addNumbers(3, 4);
        System.out.println("Sum: " + sum);
    }

    // 메서드 정의
    public static int addNumbers(int a, int b) {
        return a + b;
    }
}
```

### 매개변수 (Parameters)
메서드 선언에서 매개변수는 메서드가 호출될 때 받게 되는 값을 저장하는 데 사용됩니다. 매개변수는 메서드의 정의 부분에서 명시되며, 메서드 내부에서 이 값을 사용할 수 있습니다.

예를 들어, 다음 메서드에서 `a`와 `b`가 매개변수입니다:

```
public static int addNumbers(int a, int b) {
    return a + b;
}
```

### 전달인자 (Arguments)
메서드를 호출할 때, 실제 값을 전달하여 매개변수에 할당됩니다. 이 전달되는 값들을 전달인자 또는 인수라고 합니다.

```
int result = addNumbers(3, 4);
```

위의 예제에서 `3`과 `4`는 `addNumbers` 메서드에 전달된 전달인자입니다. 이 값들은 메서드의 매개변수 `a`와 `b`에 각각 할당되어 메서드가 실행될 때 사용됩니다.

매개변수와 전달인자의 개수와 데이터 타입이 일치해야 합니다. 위에서 선언한 `addNumbers` 메서드에서는 두 개의 `int` 매개변수가 필요하므로, 메서드 호출 시에도 두 개의 정수를 전달해야 합니다.

### 기본값을 가지는 매개변수
Java 8부터는 기본값을 가지는 매개변수를 정의할 수 있습니다. 이는 메서드를 호출할 때 해당 매개변수에 값을 전달하지 않으면 기본값이 사용되는 특성을 가집니다.

```
public static void exampleMethod(int a, int b, int c = 0) {
    // 메서드 내용
}
```

위의 예제에서 `c`는 기본값이 0으로 지정된 매개변수입니다. 호출 시에 `c`에 값을 전달하지 않으면 자동으로 0이 할당됩니다.

### 메서드 오버로딩(Method Overloading)
메서드 오버로딩은 같은 이름의 메서드가 서로 다른 매개변수를 갖도록 허용하는 것을 의미합니다. 메서드 이름은 동일하지만 매개변수의 개수, 데이터 타입, 순서가 다를 수 있습니다. 메서드 오버로딩은 코드의 가독성을 높이고 사용자에게 편의성을 제공합니다.

메서드 오버로딩에 대한 툭징은 다음과 같습니다.

- 메서드 이름은 동일해야 합니다.
- 매개변수의 개수 또는 타입이 달라야 합니다.
- 반환 타입이 다른 경우는 메서드 오버로딩이 아닙니다.

```
public class Example {

    // 정수형 매개변수를 받는 메서드
    public static int add(int a, int b) {
        return a + b;
    }

    // 실수형 매개변수를 받는 메서드
    public static double add(double a, double b) {
        return a + b;
    }

    // 문자열 매개변수를 받는 메서드
    public static String add(String a, String b) {
        return a + b;
    }

    // 정수형과 실수형 매개변수를 받는 메서드
    public static double add(int a, double b) {
        return a + b;
    }

    // 여러 타입의 매개변수를 받는 메서드
    public static int add(int a, int b, int c) {
        return a + b + c;
    }
}
```

위의 예제에서 `add` 메서드는 여러 형태로 정의되어 있습니다. 이 메서드들은 매개변수의 타입이나 개수에 따라 구분됩니다.

### 스코프 (Scope)
Java에서 스코프(Scope)는 변수가 유효한 범위를 나타냅니다. 변수가 선언된 위치에 따라 해당 변수가 어디에서 접근 가능하고 어디서는 접근할 수 없는지를 결정합니다.

#### 블록 스코프 (Block Scope)
일반적으로 중괄호 `{}` 내에 선언된 변수는 해당 블록 내에서만 유효합니다. 블록은 주로 제어문(if, for, while 등) 내부, 메서드 내부, 클래스 블록 내부에서 발생합니다.

```
public class Example {
    public static void main(String[] args) {
        int x = 10; // 메서드 블록 스코프

        if (x > 5) {
            int y = 20; // if 블록 스코프
            System.out.println(x + y);
        }

        // System.out.println(y); // 에러: y는 if 블록 외부에서는 사용할 수 없음
    }
}
```

#### 메서드 스코프 (Method Scope)
메서드 내에서 선언된 변수는 해당 메서드 내에서만 유효합니다.

```
public class Example {
    public static void main(String[] args) {
        int a = 5; // main 메서드 스코프

        doSomething(); // doSomething 메서드 호출

        // System.out.println(b); // 에러: b는 main 메서드 외부에서는 사용할 수 없음
    }

    public static void doSomething() {
        int b = 10; // doSomething 메서드 스코프
        System.out.println(b);
    }
}
```

#### 클래스 스코프 (Class Scope)
클래스 블록 내에서 선언된 변수는 해당 클래스 전체에서 사용할 수 있습니다.

```
public class Example {
    private static int count = 0; // 클래스 스코프

    public static void main(String[] args) {
        System.out.println(count); // 클래스 스코프 변수 사용 가능
    }
}
```

#### 전역 스코프 (Global Scope)
Java에서는 전역 스코프가 없습니다. 가장 가까운 스코프는 클래스 스코프이며, 클래스의 멤버 변수로 선언된 변수가 해당 클래스의 전역 스코프에 해당합니다.

## 출처 (Reference)
https://www.w3schools.com/java/java_syntax.asp
