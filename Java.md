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

### 출력
`System.out.println()` 메서드를 사용해서 콘솔 화면에 텍스트를 출력할 수 있습니다.

```
System.out.println("Hello, Java!");` 
```

### 입력
Java에서 사용자 입력을 받기 위해서는 `java.util.Scanner` 클래스나 `BufferedReader` 클래스 등을 활용할 수 있습니다.

#### Scanner 클래스 사용
```
import java.util.Scanner;

public class UserInputExample {
    public static void main(String[] args) {
        // Scanner 객체 생성
        Scanner scanner = new Scanner(System.in);

        // 정수 입력 받기
        System.out.print("Enter an integer: ");
        int intValue = scanner.nextInt();
        System.out.println("You entered: " + intValue);

        // 문자열 입력 받기
        System.out.print("Enter a string: ");
        String stringValue = scanner.next();
        System.out.println("You entered: " + stringValue);

        // 사용이 끝난 후에는 닫아주기
        scanner.close();
    }
}
```

#### BufferedReader 및 InputStreamReader
```
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class UserInputExample {
    public static void main(String[] args) throws IOException {
        // InputStreamReader와 BufferedReader 객체 생성
        InputStreamReader inputStreamReader = new InputStreamReader(System.in);
        BufferedReader bufferedReader = new BufferedReader(inputStreamReader);

        // 정수 입력 받기
        System.out.print("Enter an integer: ");
        int intValue = Integer.parseInt(bufferedReader.readLine());
        System.out.println("You entered: " + intValue);

        // 문자열 입력 받기
        System.out.print("Enter a string: ");
        String stringValue = bufferedReader.readLine();
        System.out.println("You entered: " + stringValue);

        // 사용이 끝난 후에는 닫아주기
        bufferedReader.close();
    }
}
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

### Lambda Expressions
Lambda 표현식은 Java 8부터 도입된 기능으로, 익명 함수의 간결한 형태를 제공합니다. 주로 함수형 인터페이스(Functional Interface)를 구현하는데 사용되며, 코드를 더 간결하게 작성할 수 있도록 도와줍니다.

```
(parameters) -> expression
```

- `(parameters)`: 입력 매개변수의 타입과 이름을 나타냅니다.
- `->`: Lambda 연산자로, 매개변수와 표현식을 분리합니다.
- `expression`: Lambda 표현식의 본문으로, 수행할 코드를 나타냅니다.

```
// 익명 클래스
Runnable runnable1 = new Runnable() {
    public void run() {
        System.out.println("Hello from anonymous class!");
    }
};

// Lambda 표현식
Runnable runnable2 = () -> System.out.println("Hello from Lambda expression!");
```

#### Functional Interface
Lambda 표현식은 함수형 인터페이스를 구현하는데 사용할 수 있습니다. 함수형 인터페이스는 하나의 추상 메서드를 갖는 인터페이스로, `@FunctionalInterface`을 통해 명시할 수 있습니다.

```
@FunctionalInterface
interface MyFunction {
    void myMethod();
}

MyFunction myFunction = () -> System.out.println("Hello from MyFunction!");
myFunction.myMethod();
```

#### 매개변수
Lambda 표현식도 일반 메서드처럼 매개변수를 가질 수 있습니다.

```
// 두 개의 매개변수를 받아 합을 반환하는 Lambda 표현식
MathOperation addition = (a, b) -> a + b;
System.out.println("10 + 5 = " + addition.operation(10, 5));
```

## OOP
객체 지향 프로그래밍(Object-Oriented Programming, OOP)은 소프트웨어를 객체(object)로 모델링하고, 이 객체들 간의 상호 작용을 통해 프로그램을 구성하는 프로그래밍 패러다임입니다. Java는 객체 지향 프로그래밍 언어로서 OOP의 기본 원칙을 강력하게 지원합니다.

### 객체 (Object)
객체는 데이터와 그 데이터를 처리하는 메서드들을 포함하는 소프트웨어 개체입니다. 객체는 실제 세계의 개체나 추상적인 개념을 나타내며, 특징과 행동을 가지고 있습니다.

### 클래스 (Class)
클래스는 객체를 생성하기 위한 일종의 틀 또는 설계도입니다. 클래스는 객체의 상태를 나타내는 필드(멤버 변수)와 객체의 행동을 나타내는 메서드로 구성됩니다.

```
public class Car {
    // 멤버 변수 (필드)
    String brand;
    String model;
    int year;

    // 메서드
    void start() {
        System.out.println("The car is starting.");
    }

    void drive() {
        System.out.println("The car is driving.");
    }
}
```

**public 클래스**는 반드시 **파일 이름**과 동일해야 합니다.

### 인스턴스 (Instance)
클래스를 기반으로 생성된 실제 객체를 해당 클래스의 인스턴스라고 합니다.

```
Car myCar = new Car(); // Car 클래스의 인스턴스 생성
```

### 속성 (Attributes)
#### 인스턴스 속성 (Instance Attributes)
- **개별 객체의 속성:** 각 객체(인스턴스)가 생성될 때마다 독립적으로 가지는 속성입니다.
- **인스턴스 변수(Instance Variables):** 객체의 상태를 나타내는 변수로, 클래스 내부에서 `this` 키워드를 사용하여 접근합니다.
- **객체마다 값이 별도로 저장:** 서로 다른 객체는 같은 클래스의 멤버 변수라 할지라도 각자의 값을 독립적으로 가집니다.

```
public class Car {
    // 인스턴스 속성(인스턴스 변수)
    String brand;
    String model;
    int year;

    // 생성자
    public Car(String brand, String model, int year) {
        this.brand = brand;
        this.model = model;
        this.year = year;
    }
}
```

#### 클래스 속성 (Class Attributes)
- **모든 객체가 공유:** 클래스의 모든 인스턴스가 함께 사용하는 속성입니다.
- **클래스 변수(Class Variables):** `static` 키워드를 사용하여 선언되며, 클래스 이름을 통해 접근합니다.
- **객체 간에 값이 공유:** 클래스 변수는 모든 객체가 공유하므로 한 객체에서 값을 변경하면 다른 객체에도 영향을 미칩니다.

```
public class Counter {
    // 클래스 속성(클래스 변수)
    static int count = 0;

    // 메서드
    public void increment() {
        count++;
    }

    public int getCount() {
        return count;
    }
}
```

위의 예제에서 `count`는 모든 `Counter` 객체가 함께 사용하는 클래스 변수로, `increment` 메서드를 호출하면 모든 객체에서 `count` 값이 증가합니다.

### 메서드 (Methods)
#### 인스턴스 메서드 (Instance Methods)
- **특정 인스턴스에 속함:** 인스턴스 메서드는 특정 객체(인스턴스)에 속하는 메서드입니다. 즉, 해당 메서드를 호출할 때 사용되는 객체에 종속적입니다.
- **this 키워드 사용 가능:** 메서드 내에서 현재 객체를 나타내는 특별한 참조인 `this` 키워드를 사용할 수 있습니다.
- **인스턴스 변수에 접근 가능:** 인스턴스 메서드는 동일한 클래스 내의 인스턴스 변수에 직접 접근이 가능합니다.
    
```
public class Car {
    // 인스턴스 변수
    String brand;
    String model;

    // 인스턴스 메서드
    public void displayInfo() {
        System.out.println("Brand: " + this.brand);
        System.out.println("Model: " + this.model);
    }
}
```

```
Car myCar = new Car();
myCar.displayInfo(); // 인스턴스 메서드 호출
```

#### 클래스 메서드 (Class Methods)
- **특정 인스턴스에 독립적:** 클래스 메서드는 특정 인스턴스에 속하지 않고, 클래스 자체에 속하는 메서드입니다. 따라서 해당 메서드를 호출할 때 특정 객체에 종속되지 않습니다.
- **this 키워드 사용 불가:** 클래스 메서드 내에서는 현재 객체를 가리키는 `this` 키워드를 사용할 수 없습니다. 왜냐하면 클래스 메서드는 특정 인스턴스에 속하지 않기 때문입니다.
- **클래스 변수에 접근 가능:** 클래스 메서드는 동일한 클래스 내의 클래스 변수에 직접 접근이 가능합니다. `static` 키워드를 사용하여 선언합니다.

```
public class MathOperations {
    // 클래스 변수
    static final double PI = 3.141592;

    // 클래스 메서드
    public static double calculateCircleArea(double radius) {
        return PI * radius * radius;
    }
}
```

```
double area = MathOperations.calculateCircleArea(5.0); // 클래스 메서드 호출
```

### 생성자 (Constructors)
생성자는 객체가 생성될 때 호출되는 특별한 메서드로, 객체의 초기화를 담당합니다. Java에서 생성자는 클래스 이름과 동일하며, 객체를 생성할 때 `new` 키워드와 함께 호출됩니다.

- **메서드와 유사하지만 반환 타입이 없음:** 생성자는 일반적인 메서드와 유사한 문법을 가지지만, 반환 타입이 없습니다.
- **클래스 이름과 동일:** 생성자의 이름은 해당 클래스의 이름과 동일합니다.
- **오버로딩 가능:** 여러 개의 생성자를 정의하여 다양한 초기화 옵션을 제공할 수 있습니다.

생성자를 사용하여 인스턴스 변수 초기화, 자원 할당 및 초기화, 초기화 로직 수행 등을 수행할 수 있습니다.

#### 기본 생성자(Default Constructor)
만약 클래스에 생성자가 명시적으로 정의되어 있지 않다면, Java는 기본 생성자를 자동으로 제공합니다. 기본 생성자는 매개변수가 없는 형태로, 아무런 초기화를 수행하지 않습니다.

```
public class MyClass {
    // 기본 생성자 (자동으로 생성됨)
    public MyClass() {
        // 아무런 초기화 작업이 없음
    }
}
```

#### 사용자 정의 생성자
클래스 작성자가 필요한 경우, 사용자 정의 생성자를 정의할 수 있습니다. 이 생성자는 객체가 생성될 때 호출되어 필요한 초기화 작업을 수행합니다.

```
public class Car {
    // 인스턴스 변수
    String brand;
    String model;
    int year;

    // 사용자 정의 생성자
    public Car(String brand, String model, int year) {
        this.brand = brand;
        this.model = model;
        this.year = year;
    }
}
```

```
// 사용자 정의 생성자 호출
Car myCar = new Car("Toyota", "Camry", 2022);
```

위의 예제에서 `new Car("Toyota", "Camry", 2022)`는 `Car` 클래스의 사용자 정의 생성자를 호출하여 `myCar` 객체를 생성하고 초기화합니다.

### 수식어 (Modifiers)
수식어는 클래스, 변수, 메서드, 인터페이스 등의 선언에 적용되어 동작을 제어하는 역할을 합니다. 수식어는 다양한 종류가 있으며, 주로 접근 제어, 상속, 다형성 등의 측면에서 클래스와 멤버들을 제어하는 데 사용됩니다.

#### 접근 제어자 (Access Modifiers)
- **private:** 해당 멤버는 같은 클래스 내에서만 접근 가능합니다.
- **default (package-private):** 해당 멤버는 같은 패키지 내에서 접근 가능합니다. 아무 수식어도 붙지 않으면 default로 간주됩니다.
- **protected:** 해당 멤버는 같은 패키지 내에서, 그리고 해당 클래스를 상속받은 하위 클래스에서 접근 가능합니다.
- **public:** 해당 멤버는 어떤 클래스에서든 접근 가능합니다.
    
```
public class Example {
    private int privateVariable;
    int defaultVariable;
    protected int protectedVariable;
    public int publicVariable;
}
```

#### 비접근 제어자 (Non-Access Modifiers)
- **static:** 해당 멤버는 클래스 수준의 멤버로 정의되며, 객체의 생성 없이도 클래스 이름으로 직접 접근 가능합니다.
- **final:** 해당 멤버는 변경될 수 없는 상수이거나, 클래스가 상속될 수 없는 경우를 나타냅니다.
- **abstract:** 해당 클래스가 추상 클래스이거나, 메서드가 추상 메서드임을 나타냅니다. 추상 메서드는 하위 클래스에서 반드시 구현되어야 합니다.
- **synchronized:** 해당 메서드 또는 블록이 동기화된 상태로 실행되어야 함을 나타냅니다. 다중 스레드 환경에서의 동시 접근을 제어하는 데 사용됩니다.
- **transient:** 해당 변수는 직렬화에서 제외됩니다.
- **volatile:** 해당 변수는 다른 스레드 간에 공유되는 변수이며, 컴파일러에 의한 최적화를 방지합니다.

```
public class Example {
    static int staticVariable;
    final int constantVariable = 10;
    abstract void abstractMethod();
    synchronized void synchronizedMethod() {
        // ...
    }
    transient int transientVariable;
    volatile int volatileVariable;
}
```

### 캡슐화 (Encapsulation)
캡슐화는 객체 지향 프로그래밍의 한 원칙으로, 데이터와 해당 데이터를 처리하는 메서드를 하나로 묶어 외부로부터의 접근을 제한하는 것입니다. 캡슐화를 통해 객체의 내부 구현을 숨기고 외부에서는 객체의 인터페이스만을 이용할 수 있게 됩니다. 캡슐화는 객체의 정보은닉과 모듈화에 기여하여 안정적이고 유지보수가 용이한 코드를 작성하는 데 도움을 줍니다.

1. **접근 제어자 사용:** 멤버 변수를 `private`으로 선언하여 외부에서의 직접적인 접근을 제한합니다.
2. **Getter와 Setter 메서드:** 멤버 변수에 접근하고 수정하기 위한 메서드를 제공합니다. 이를 통해 데이터에 대한 조작을 메서드를 통해서만 가능하게 합니다.

```
public class Car {
    // 캡슐화된 멤버 변수
    private String brand;
    private String model;
    private int year;

    // 생성자
    public Car(String brand, String model, int year) {
        this.brand = brand;
        this.model = model;
        this.year = year;
    }

    // Getter 메서드
    public String getBrand() {
        return brand;
    }

    public String getModel() {
        return model;
    }

    public int getYear() {
        return year;
    }

    // Setter 메서드
    public void setBrand(String brand) {
        this.brand = brand;
    }

    public void setModel(String model) {
        this.model = model;
    }

    public void setYear(int year) {
        this.year = year;
    }
}
```

위의 예제에서 `Car` 클래스는 멤버 변수들을 `private`으로 선언하여 외부에서의 직접적인 접근을 막았습니다. 대신에 Getter와 Setter 메서드를 제공하여 외부에서 해당 데이터에 접근하고 수정할 수 있도록 했습니다.

### 상속 (Inheritance)
상속은 객체 지향 프로그래밍에서 중요한 개념 중 하나로, 기존의 클래스를 확장하여 새로운 클래스를 생성하는 메커니즘입니다. 상속을 통해 기존 클래스의 특성과 동작을 재사용하고, 새로운 클래스에서는 그에 덧붙여 새로운 기능을 추가할 수 있습니다.

- **재사용성(Reuse):** 기존 클래스의 코드를 재사용하여 새로운 클래스를 작성할 수 있습니다.
- **계층 구조(Hierarchy):** 클래스들 간의 계층 구조를 형성하게 됩니다. 부모 클래스와 자식 클래스 간의 상속 관계를 표현합니다.
- **메서드 오버라이딩(Method Overriding):** 자식 클래스에서 부모 클래스의 메서드를 재정의하여 새로운 동작을 정의할 수 있습니다.
- **다형성(Polymorphism):** 부모 클래스 타입의 변수에 자식 클래스의 객체를 대입하여 사용할 수 있습니다.

Java에서 상속은 다음과 같은 특징을 같습니다.
- **단일 상속:** Java는 단일 상속만을 지원합니다. 하나의 클래스는 하나의 직계 부모 클래스만을 가질 수 있습니다.
- **다중 인터페이스:** 여러 개의 인터페이스를 구현하는 다중 인터페이스는 가능합니다.
- **접근 제어자:** 자식 클래스에서 부모 클래스의 private 멤버에는 직접 접근할 수 없습니다.

```
// 부모 클래스
class Animal {
    void eat() {
        System.out.println("Animal is eating");
    }
}

// 자식 클래스
class Dog extends Animal {
    void bark() {
        System.out.println("Dog is barking");
    }
}
```

```
Animal myPet = new Dog();
myPet.eat(); // 부모 클래스의 메서드 호출
((Dog) myPet).bark(); // 자식 클래스의 메서드 호출
```

위의 예제에서 `Dog` 클래스는 `Animal` 클래스를 상속받고 있습니다. 이제 `Dog` 클래스는 `Animal` 클래스의 `eat` 메서드를 사용할 수 있으며, `bark`라는 새로운 메서드를 추가로 가지고 있습니다.

#### super
`super` 키워드는 부모 클래스를 가리키는 참조입니다. 자식 클래스에서 부모 클래스의 멤버에 접근하거나, 부모 클래스의 생성자를 호출할 때 사용됩니다.

```
class Dog extends Animal {
    void bark() {
        System.out.println("Dog is barking");
        super.eat(); // 부모 클래스의 eat 메서드 호출
    }
}
```

### 생성자에서의 상속
자식 클래스의 생성자는 부모 클래스의 생성자를 호출해야 합니다. 이때 `super()`를 사용하여 부모 클래스의 생성자를 호출합니다.

```
class Animal {
    Animal() {
        System.out.println("Animal constructor");
    }
}

class Dog extends Animal {
    Dog() {
        super(); // 부모 클래스의 생성자 호출
        System.out.println("Dog constructor");
    }
}
```

### 다형성 (Polymorphism)
다형성은 객체 지향 프로그래밍의 중요한 특성 중 하나로, 하나의 인터페이스를 통해 다양한 형태의 객체를 사용할 수 있는 능력을 나타냅니다. Java에서는 다형성을 구현하기 위해 메서드 오버로딩과 메서드 오버라이딩을 활용합니다.

다형성은 같은 타입의 객체들을 동일한 인터페이스를 통해 다양하게 다룰 수 있게 해주므로, 코드의 유연성과 확장성을 높여줍니다.

#### 메서드 오버라이딩 (Method Overriding)
메서드 오버라이딩은 부모 클래스에서 정의된 메서드를 자식 클래스에서 동일한 구조로 재정의하는 것을 말합니다. 부모 클래스와 자식 클래스 간에는 IS-A 관계가 성립되어야 합니다.

```
class Animal {
    void makeSound() {
        System.out.println("Some sound");
    }
}

class Dog extends Animal {
    // Animal 클래스의 makeSound 메서드를 재정의
    void makeSound() {
        System.out.println("Bark");
    }
}

class Cat extends Animal {
    // Animal 클래스의 makeSound 메서드를 재정의
    void makeSound() {
        System.out.println("Meow");
    }
}
```

위의 예제에서 `Dog` 클래스와 `Cat` 클래스는 모두 `Animal` 클래스를 상속받아 `makeSound` 메서드를 재정의하고 있습니다.

### 추상 클래스 (Abstract Class)
추상 클래스는 일반 클래스와 유사하지만, 추상 메서드를 가질 수 있습니다. 추상 메서드는 선언만 있고 구현이 없는 메서드로, 해당 클래스를 상속받는 하위 클래스에서 반드시 구현되어야 합니다.

```
// 추상 클래스
abstract class Shape {
    // 추상 메서드
    abstract void draw();

    // 일반 메서드
    void display() {
        System.out.println("Displaying the shape");
    }
}
```

추상 클래스를 상속받는 클래스는 추상 메서드를 반드시 구현해야 합니다.

```
class Circle extends Shape {
    @Override
    void draw() {
        System.out.println("Drawing a circle");
    }
}

class Rectangle extends Shape {
    @Override
    void draw() {
        System.out.println("Drawing a rectangle");
    }
}
```

### 인터페이스 (Interface)
인터페이스는 추상 메서드와 상수만을 가질 수 있는데, Java 8부터는 디폴트 메서드와 정적 메서드를 가질 수 있게 되었습니다. 인터페이스는 다중 상속이 가능하며, 클래스가 여러 인터페이스를 구현할 수 있습니다.

```
// 인터페이스
interface Animal {
    // 추상 메서드
    void makeSound();

    // 디폴트 메서드
    default void eat() {
        System.out.println("Eating");
    }
}
```

인터페이스를 구현하는 클래스는 모든 추상 메서드를 구현해야 합니다.

```
class Dog implements Animal {
    @Override
    public void makeSound() {
        System.out.println("Bark");
    }
}
```

### 내부 클래스(Inner Classes)
내부 클래스는 Java에서 클래스 내에 다른 클래스를 정의하는 기능을 제공하는 개념입니다. 내부 클래스는 주로 외부 클래스의 멤버에 쉽게 접근하거나, 논리적으로 그룹화된 코드를 구성할 때 사용됩니다.

#### 멤버 내부 클래스 (Member Inner Class)
외부 클래스의 멤버로 정의되는 내부 클래스입니다. 주로 외부 클래스의 인스턴스 변수에 쉽게 접근할 수 있도록 설계됩니다.

```
public class OuterClass {
    private int outerVariable = 10;

    // 멤버 내부 클래스
    public class InnerClass {
        void displayOuter() {
            System.out.println("Outer Variable: " + outerVariable);
        }
    }
}
```

```
OuterClass outerObj = new OuterClass();
OuterClass.InnerClass innerObj = outerObj.new InnerClass();
innerObj.displayOuter(); // Outer Variable: 10
```

#### 정적 내부 클래스 (Static Nested Class)
내부 클래스가 정적으로 선언된 경우를 말합니다. 정적 내부 클래스는 외부 클래스의 인스턴스에 종속되지 않으며, 외부 클래스의 정적 멤버에만 접근할 수 있습니다.

```
public class OuterClass {
    private static int staticOuterVariable = 20;

    // 정적 내부 클래스
    public static class StaticInnerClass {
        void displayOuter() {
            System.out.println("Static Outer Variable: " + staticOuterVariable);
        }
    }
}
```

```
OuterClass.StaticInnerClass staticInnerObj = new OuterClass.StaticInnerClass();
staticInnerObj.displayOuter(); // Static Outer Variable: 20
``` 

#### 지역 내부 클래스 (Local Inner Class)
메서드나 코드 블록 내에서 정의되는 내부 클래스를 말합니다. 지역 내부 클래스는 외부 클래스의 멤버에 접근할 수 있고, 메서드의 매개변수나 지역 변수에도 접근할 수 있습니다. 지역 내부 클래스는 해당 메서드나 블록 내에서만 사용 가능합니다.

```
public class OuterClass {
    private int outerVariable = 30;

    // 메서드 내에서 정의된 지역 내부 클래스
    public void localInnerClassMethod() {
        final int localVariable = 40;

        class LocalInnerClass {
            void displayOuter() {
                System.out.println("Outer Variable: " + outerVariable);
                System.out.println("Local Variable: " + localVariable);
            }
        }

        LocalInnerClass localInnerObj = new LocalInnerClass();
        localInnerObj.displayOuter();
    }
}
```

```
OuterClass outerObj = new OuterClass();
outerObj.localInnerClassMethod(); // Outer Variable: 30, Local Variable: 40
```

#### 익명 내부 클래스 (Anonymous Inner Class):
클래스의 이름이 없는 내부 클래스를 익명 내부 클래스라고 합니다. 주로 인터페이스의 구현체나 추상 클래스의 파생 클래스를 생성할 때 사용됩니다.

```
public interface MyInterface {
    void myMethod();
}

public class OuterClass {
    public MyInterface getMyInterfaceInstance() {
        return new MyInterface() {
            @Override
            public void myMethod() {
                System.out.println("Implementation of myMethod");
            }
        };
    }
}
```

익명 내부 클래스는 인터페이스의 구현체를 생성하고 해당 인터페이스의 메서드를 재정의할 수 있습니다.

```
OuterClass outerObj = new OuterClass();
MyInterface myInterfaceObj = outerObj.getMyInterfaceInstance();
myInterfaceObj.myMethod(); // Implementation of myMethod
```

## 패키지(Packages)
패키지는 Java에서 코드를 구조화하고 관리하는 데 사용되는 방법 중 하나입니다. 패키지는 클래스들을 그룹화하여 서로 관련 있는 클래스들을 함께 묶어주는 개념입니다. 이는 코드의 가독성과 유지보수성을 향상시키며, 클래스 이름의 충돌을 방지하는 데 도움이 됩니다.

- **이름 충돌 방지:** 다양한 라이브러리나 프로젝트에서 동일한 이름의 클래스를 사용해야 할 때 패키지를 사용하여 충돌을 방지할 수 있습니다.
- **코드 구조화:** 패키지를 사용하면 코드를 논리적으로 그룹화하고 구조화할 수 있습니다. 서로 관련 있는 클래스들은 함께 묶여 있어 가독성이 높아집니다.
- **접근 제어:** 패키지 내에서는 다른 패키지의 클래스에 대한 접근을 제어할 수 있습니다. `public`, `protected`, `default`, `private`과 같은 접근 제어자를 활용할 수 있습니다.

### 패키지 생성
패키지는 소스 코드 상단에 `package` 키워드를 사용하여 정의됩니다. 디렉토리 구조와 일치하게 하기 위해 패키지 선언은 소스 파일의 맨 첫 줄에 위치해야 합니다.

패키지 이름은 모두 소문자로 작성되어야 합니다. 또한 패키지 이름 사이에는 마침표(`.`)를 사용하여 계층을 표현합니다.

```
// 패키지 선언
package com.example.myproject;

// 클래스 선언
public class MyClass {
    // 클래스 내용
}
```

위의 예제에서 `MyClass`는 `com.example.myproject` 패키지에 속하는 클래스입니다. 디렉토리 구조에서도 `com/example/myproject`와 같이 저장됩니다.

### 패키지 사용
다른 패키지에 속한 클래스를 사용하기 위해서는 해당 클래스의 패키지를 명시해주어야 합니다. `import` 키워드를 사용하여 다른 패키지의 클래스를 현재 파일에서 사용할 수 있도록 선언합니다.

```
// 다른 패키지의 클래스 사용
import com.example.otherproject.OtherClass;

public class MyClass {
    public static void main(String[] args) {
        OtherClass other = new OtherClass();
        // ...
    }
}
```

- `import`: 클래스 또는 인터페이스가 대상입니다.
- `import static`: static 멤버(필드나 메서드)가 입니다.

### Java API 패키지
Java에서 제공하는 API(Java Standard Edition API) 역시 패키지로 구성되어 있습니다. 예를 들어, `java.lang`, `java.util`, `java.io`와 같은 패키지는 Java에서 제공하는 다양한 클래스와 인터페이스를 포함하고 있습니다.

### ArrayList
`ArrayList`는 Java에서 제공하는 동적 배열(dynamic array)로, 크기를 동적으로 조절할 수 있는 배열을 나타냅니다. `ArrayList`는 `java.util` 패키지에 속해 있습니다. 다른 배열과 달리 크기를 동적으로 조절할 수 있어, 요소를 추가하거나 제거할 때 유연하게 대처할 수 있습니다. 다만, 요소를 중간에서 추가 또는 삭제할 때 많은 데이터를 이동시켜야 하므로, 이 점을 고려하여 사용해야 합니다.

#### ArrayList 생성
```
import java.util.ArrayList;

public class ArrayListExample {
    public static void main(String[] args) {
        // 빈 ArrayList 생성
        ArrayList<String> stringList = new ArrayList<>();

        // 초기 크기 지정하여 생성
        ArrayList<Integer> intList = new ArrayList<>(10);
    }
}
```

#### 요소 추가 및 접근
```
import java.util.ArrayList;

public class ArrayListExample {
    public static void main(String[] args) {
        ArrayList<String> stringList = new ArrayList<>();

        // 요소 추가
        stringList.add("Java");
        stringList.add("Python");
        stringList.add("C++");

        // 요소 접근
        System.out.println("First Element: " + stringList.get(0));
        System.out.println("Second Element: " + stringList.get(1));
    }
}
```

#### 요소 수정
```
import java.util.ArrayList;

public class ArrayListExample {
    public static void main(String[] args) {
        ArrayList<String> stringList = new ArrayList<>();

        stringList.add("Java");
        stringList.add("Python");

        // 요소 수정
        stringList.set(1, "C++");
        System.out.println("Updated Second Element: " + stringList.get(1));
    }
}
```

#### 요소 제거
```
import java.util.ArrayList;

public class ArrayListExample {
    public static void main(String[] args) {
        ArrayList<String> stringList = new ArrayList<>();

        stringList.add("Java");
        stringList.add("Python");

        // 요소 제거
        stringList.remove("Java");
        System.out.println("Remaining Elements: " + stringList);
    }
}
```

#### ArrayList 크기 및 순회
```
import java.util.ArrayList;

public class ArrayListExample {
    public static void main(String[] args) {
        ArrayList<String> stringList = new ArrayList<>();

        stringList.add("Java");
        stringList.add("Python");

        // ArrayList 크기
        System.out.println("Size of ArrayList: " + stringList.size());

        // ArrayList 순회
        for (String element : stringList) {
            System.out.println(element);
        }
    }
}
```

### LinkedList
`LinkedList`는 Java에서 제공하는 데이터 구조 중 하나로, 이중 연결 리스트(doubly linked list)로 구현되어 있습니다. `LinkedList`는 각 요소가 이전 요소와 다음 요소의 참조를 가지고 있어 요소의 삽입 및 삭제가 배열에 비해 빠르게 이루어질 수 있는 장점이 있습니다. 하지만 인덱스로 직접 접근하는 것은 느리며, 메모리 사용량이 좀 더 큽니다.

#### LinkedList 생성
```
import java.util.LinkedList;

public class LinkedListExample {
    public static void main(String[] args) {
        // 빈 LinkedList 생성
        LinkedList<String> linkedList = new LinkedList<>();

        // 기존 컬렉션으로부터 생성
        // List<String> anotherList = Arrays.asList("Apple", "Banana", "Orange");
        // LinkedList<String> linkedListFromList = new LinkedList<>(anotherList);
    }
}
```

#### 요소 추가 및 접근
```
import java.util.LinkedList;

public class LinkedListExample {
    public static void main(String[] args) {
        LinkedList<String> linkedList = new LinkedList<>();

        // 요소 추가
        linkedList.add("Java");
        linkedList.add("Python");

        // 요소 접근
        System.out.println("First Element: " + linkedList.getFirst());
        System.out.println("Last Element: " + linkedList.getLast());
    }
}
```

#### 요소 추가 및 제거
```
import java.util.LinkedList;

public class LinkedListExample {
    public static void main(String[] args) {
        LinkedList<String> linkedList = new LinkedList<>();

        // 요소 추가
        linkedList.add("Java");
        linkedList.add("Python");

        // 특정 위치에 요소 추가
        linkedList.add(1, "C++");

        // 요소 제거
        linkedList.remove("Java");
        linkedList.remove(1);

        // 모든 요소 제거
        linkedList.clear();
    }
}
```

#### 크기 및 순회
```
import java.util.LinkedList;

public class LinkedListExample {
    public static void main(String[] args) {
        LinkedList<String> linkedList = new LinkedList<>();

        // 요소 추가
        linkedList.add("Java");
        linkedList.add("Python");
        linkedList.add("C++");

        // LinkedList 크기
        System.out.println("Size of LinkedList: " + linkedList.size());

        // LinkedList 순회
        for (String element : linkedList) {
            System.out.println(element);
        }
    }
}
```

### HashMap 
`HashMap`은 Java에서 제공하는 해시 맵 자료구조로, 키와 값을 쌍으로 저장하는데 사용됩니다. 이는 해시 함수를 통해 키와 값 간의 매핑을 구현하므로 매우 빠른 검색, 삽입 및 삭제를 제공합니다. `HashMap`은 `java.util` 패키지에 속해 있습니다.

`HashMap`은 키와 값이 `null`이 될 수 있으며, 동시에 여러 쓰레드에서 안전하지 않습니다. 만약 멀티쓰레드 환경에서 사용해야 한다면 `ConcurrentHashMap`을 고려해야 합니다. 해시 맵의 성능은 일반적으로 매우 좋지만, 적재율이 높아지면 충돌이 발생할 가능성이 있으므로 적절한 적재율을 선택하는 것이 중요합니다.

#### HashMap 생성
```
import java.util.HashMap;

public class HashMapExample {
    public static void main(String[] args) {
        // 빈 HashMap 생성
        HashMap<String, Integer> hashMap = new HashMap<>();

        // 초기 용량 및 load factor 지정하여 생성
        // HashMap<String, Integer> anotherMap = new HashMap<>(16, 0.75f);
    }
}
```

#### 요소 추가 및 접근
```
import java.util.HashMap;

public class HashMapExample {
    public static void main(String[] args) {
        HashMap<String, Integer> hashMap = new HashMap<>();

        // 요소 추가
        hashMap.put("Java", 8);
        hashMap.put("Python", 3);
        hashMap.put("C++", 14);

        // 요소 접근
        System.out.println("Java's Version: " + hashMap.get("Java"));
    }
}
```

#### 요소 수정
```
import java.util.HashMap;

public class HashMapExample {
    public static void main(String[] args) {
        HashMap<String, Integer> hashMap = new HashMap<>();

        hashMap.put("Java", 8);

        // 요소 수정
        hashMap.put("Java", 11);
        System.out.println("Updated Java's Version: " + hashMap.get("Java"));
    }
}
```

#### 요소 제거
```
import java.util.HashMap;

public class HashMapExample {
    public static void main(String[] args) {
        HashMap<String, Integer> hashMap = new HashMap<>();

        hashMap.put("Java", 8);
        hashMap.put("Python", 3);

        // 요소 제거
        hashMap.remove("Java");
        System.out.println("Remaining Elements: " + hashMap);
    }
}
```

#### 크기 및 순회
```
import java.util.HashMap;
import java.util.Map;

public class HashMapExample {
    public static void main(String[] args) {
        HashMap<String, Integer> hashMap = new HashMap<>();

        hashMap.put("Java", 8);
        hashMap.put("Python", 3);
        hashMap.put("C++", 14);

        // HashMap 크기
        System.out.println("Size of HashMap: " + hashMap.size());

        // HashMap 순회
        for (Map.Entry<String, Integer> entry : hashMap.entrySet()) {
            System.out.println(entry.getKey() + " : " + entry.getValue());
        }
    }
}
```

### HashSet
`HashSet`은 Java에서 제공하는 집합(set)을 구현한 클래스 중 하나입니다. `HashSet`은 중복을 허용하지 않으며, 요소의 순서를 유지하지 않습니다. `HashSet`은 `java.util` 패키지에 속해 있습니다. `HashSet`은 내부적으로 `HashMap`을 기반으로 하고 있습니다.

`HashSet`은 해시 테이블을 사용하여 요소를 저장하므로, 요소의 추가 및 검색이 매우 빠릅니다. 또한 중복된 요소를 허용하지 않으므로, 집합 연산에 유용하게 사용될 수 있습니다. 그러나 순서가 중요한 경우에는 사용하지 않는 것이 좋습니다.

#### HashSet 생성
```
import java.util.HashSet;

public class HashSetExample {
    public static void main(String[] args) {
        // 빈 HashSet 생성
        HashSet<String> hashSet = new HashSet<>();

        // 다른 컬렉션으로부터 생성
        // Set<String> anotherSet = new HashSet<>(Arrays.asList("Apple", "Banana", "Orange"));
    }
}
```

#### 요소 추가
```
import java.util.HashSet;

public class HashSetExample {
    public static void main(String[] args) {
        HashSet<String> hashSet = new HashSet<>();

        // 요소 추가
        hashSet.add("Java");
        hashSet.add("Python");
        hashSet.add("C++");
        hashSet.add("Java"); // 중복된 요소는 무시됨

        System.out.println("HashSet: " + hashSet);
    }
}
```

#### 요소 제거
```
import java.util.HashSet;

public class HashSetExample {
    public static void main(String[] args) {
        HashSet<String> hashSet = new HashSet<>();

        hashSet.add("Java");
        hashSet.add("Python");

        // 요소 제거
        hashSet.remove("Java");

        System.out.println("Remaining Elements: " + hashSet);
    }
}
```

#### 크기 및 순회
```
import java.util.HashSet;

public class HashSetExample {
    public static void main(String[] args) {
        HashSet<String> hashSet = new HashSet<>();

        hashSet.add("Java");
        hashSet.add("Python");
        hashSet.add("C++");

        // HashSet 크기
        System.out.println("Size of HashSet: " + hashSet.size());

        // HashSet 순회
        for (String element : hashSet) {
            System.out.println(element);
        }
    }
}
```

### java.time
Java에서는 `java.time` 패키지를 통해 날짜와 시간을 다룰 수 있습니다. 이 패키지는 Java 8부터 도입되었으며, 이전의 `java.util.Date` 및 `java.util.Calendar` 클래스보다 강력하고 편리한 API를 제공합니다. `java.time` 패키지의 클래스들은 불변(immutable)하며, 스레드 안전(thread-safe)하게 설계되어 있습니다.

#### LocalDate
`LocalDate` 클래스는 날짜 정보를 나타냅니다. 연, 월, 일을 각각 표현합니다.

```
import java.time.LocalDate;

public class DateExample {
    public static void main(String[] args) {
        // 현재 날짜
        LocalDate currentDate = LocalDate.now();
        System.out.println("Current Date: " + currentDate);

        // 특정 날짜 생성
        LocalDate specificDate = LocalDate.of(2022, 1, 1);
        System.out.println("Specific Date: " + specificDate);
    }
}
```

#### LocalTime
`LocalTime` 클래스는 시간 정보를 나타냅니다. 시, 분, 초를 각각 표현합니다.

```
import java.time.LocalTime;

public class TimeExample {
    public static void main(String[] args) {
        // 현재 시간
        LocalTime currentTime = LocalTime.now();
        System.out.println("Current Time: " + currentTime);

        // 특정 시간 생성
        LocalTime specificTime = LocalTime.of(12, 30, 45);
        System.out.println("Specific Time: " + specificTime);
    }
}
```

#### LocalDateTime
`LocalDateTime` 클래스는 날짜와 시간을 모두 포함하는 클래스입니다.

```
import java.time.LocalDateTime;

public class DateTimeExample {
    public static void main(String[] args) {
        // 현재 날짜와 시간
        LocalDateTime currentDateTime = LocalDateTime.now();
        System.out.println("Current Date and Time: " + currentDateTime);

        // 특정 날짜와 시간 생성
        LocalDateTime specificDateTime = LocalDateTime.of(2022, 1, 1, 12, 30, 45);
        System.out.println("Specific Date and Time: " + specificDateTime);
    }
}
```

#### Period and Duration
`Period` 클래스는 두 날짜 간의 차이를 나타내며, `Duration` 클래스는 두 시간 간의 차이를 나타냅니다.

```
import java.time.LocalDate;
import java.time.Period;
import java.time.temporal.ChronoUnit;

public class PeriodExample {
    public static void main(String[] args) {
        LocalDate startDate = LocalDate.of(2022, 1, 1);
        LocalDate endDate = LocalDate.of(2022, 12, 31);

        // 두 날짜 간의 기간
        Period period = Period.between(startDate, endDate);
        System.out.println("Period: " + period.getYears() + " years, " +
                           period.getMonths() + " months, " +
                           period.getDays() + " days");

        // 두 날짜 간의 일 수 차이
        long daysDifference = ChronoUnit.DAYS.between(startDate, endDate);
        System.out.println("Days Difference: " + daysDifference + " days");
    }
}
```

#### DateTimeFormatter
`DateTimeFormatter` 클래스를 사용하여 날짜와 시간을 원하는 형식으로 변환할 수 있습니다.

```
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

public class DateTimeFormatterExample {
    public static void main(String[] args) {
        LocalDateTime currentDateTime = LocalDateTime.now();

        // 원하는 형식으로 변환
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss");
        String formattedDateTime = currentDateTime.format(formatter);
        System.out.println("Formatted Date and Time: " + formattedDateTime);
    }
}
```

### Iterator
`Iterator`는 Java 컬렉션 프레임워크에서 컬렉션 요소를 순회(traverse)하기 위한 인터페이스입니다. `Iterator`는 모든 컬렉션 클래스에서 사용할 수 있으며, 컬렉션 내의 요소에 접근하고 반복할 때 사용됩니다. `Iterator`를 통해 컬렉션의 내부 구조를 노출시키지 않고, 안전하게 요소에 접근할 수 있습니다.

- `Iterator`는 단방향 순회만 지원하므로, 역방향으로 순회하거나 다시 앞으로 돌아갈 수 없습니다.
- `Iterator`의 `remove()` 메서드는 반드시 `next()` 메서드 호출 후에 사용되어야 하며, 그렇지 않으면 `IllegalStateException`이 발생합니다.
- `Iterator`는 컬렉션의 크기나 내부 구조에 대한 정보를 제공하지 않습니다. 그저 다음 요소가 있는지 여부와 다음 요소를 가져올 뿐입니다.

#### Iterator 인터페이스 메서드
- `boolean hasNext()`: 다음에 읽을 요소가 있는지 여부를 확인합니다.
- `E next()`: 다음 요소를 반환하고 커서를 다음 위치로 이동시킵니다.
- `void remove()`: 현재 가리키고 있는 요소를 제거합니다. (optional)

```
import java.util.ArrayList;
import java.util.Iterator;

public class IteratorExample {
    public static void main(String[] args) {
        ArrayList<String> list = new ArrayList<>();
        list.add("Java");
        list.add("Python");
        list.add("C++");

        // Iterator 생성
        Iterator<String> iterator = list.iterator();

        // hasNext()와 next()를 사용하여 순회
        while (iterator.hasNext()) {
            String element = iterator.next();
            System.out.println(element);
        }
    }
}
```

#### Iterator를 사용한 요소 제거
```
import java.util.ArrayList;
import java.util.Iterator;

public class IteratorExample {
    public static void main(String[] args) {
        ArrayList<String> list = new ArrayList<>();
        list.add("Java");
        list.add("Python");
        list.add("C++");

        // Iterator 생성
        Iterator<String> iterator = list.iterator();

        // 요소 제거
        while (iterator.hasNext()) {
            String element = iterator.next();
            if (element.equals("Java")) {
                iterator.remove();
            }
        }

        System.out.println("Remaining Elements: " + list);
    }
}
```

### Wrapper
Wrapper 클래스는 기본 데이터 타입(primitive data type)을 객체로 다루기 위해 제공되는 클래스들을 말합니다. 기본 데이터 타입에 대응하는 Wrapper 클래스들은 해당 데이터 타입의 값을 감싸고 있는 객체를 생성할 수 있도록 도와줍니다. Wrapper 클래스들은 `java.lang` 패키지에 속해 있습니다.

다음은 기본 데이터 타입과 그에 해당하는 Wrapper 클래스들입니다:
- **byte**: `Byte`
- **short**: `Short`
- **int**: `Integer`
- **long**: `Long`
- **float**: `Float`
- **double**: `Double`
- **char**: `Character`
- **boolean**: `Boolean`

Wrapper 클래스는 주로 컬렉션 프레임워크에서 기본 데이터 타입을 다룰 때 유용하게 사용됩니다. 또한, 메서드의 매개변수로 객체를 요구하는 경우에 기본 데이터 타입을 객체로 변환할 필요가 있을 때 Wrapper 클래스를 사용할 수 있습니다. Java 5부터는 Autoboxing과 Unboxing을 통해 기본 데이터 타입과 Wrapper 클래스 간의 변환이 자동으로 이루어지므로 편리하게 사용할 수 있습니다.

#### 객체 생성
```
Integer intObject = new Integer(10);
Double doubleObject = new Double(3.14);
Boolean boolObject = new Boolean(true);
```
    
#### 값의 얻기 및 설정
```
int intValue = intObject.intValue();
double doubleValue = doubleObject.doubleValue();
boolean boolValue = boolObject.booleanValue();
```

#### 문자열로 변환
```String intStr = Integer.toString(10);
String doubleStr = Double.toString(3.14);
String boolStr = Boolean.toString(true);
```

#### 문자열을 해당 타입으로 변환
```
int intFromString = Integer.parseInt("10");
double doubleFromString = Double.parseDouble("3.14");
boolean boolFromString = Boolean.parseBoolean("true");
```

#### 정적 상수 및 메서드
```
int maxInt = Integer.MAX_VALUE;
int minInt = Integer.MIN_VALUE;

double maxDouble = Double.MAX_VALUE;
double minDouble = Double.MIN_VALUE;

char digitChar = Character.forDigit(5, 10);  // 5를 10진수로 표현한 문자
```

#### Auto(un)boxing
```
Integer intObject = 10;  // Autoboxing
int intValue = intObject;  // Unboxing

Double doubleObject = 3.14;  // Autoboxing
double doubleValue = doubleObject;  // Unboxing
```

### 정규 표현식 (Regular Expressions)
정규 표현식은 문자열의 검색, 매칭, 패턴 매칭 등과 같은 작업을 수행하는 데 사용되는 강력한 도구입니다. Java에서는 `java.util.regex` 패키지를 통해 정규 표현식을 지원하고 있습니다.

#### 기본 문법
정규 표현식은 문자열의 패턴을 나타내며, 다양한 문자와 메타 문자를 사용하여 이루어집니다.

- **문자 클래스 (Character Classes):**
    - `[abc]`: a, b, c 중 하나와 일치
    - `[^abc]`: a, b, c를 제외한 다른 문자와 일치
    - `[a-z]`: 소문자 a부터 z까지 중 하나와 일치
    - `[A-Z]`: 대문자 A부터 Z까지 중 하나와 일치
- **메타 문자 (Meta Characters):**
    - `.`: 어떤 문자와 일치
    - `^`: 문자열의 시작
    - `$`: 문자열의 끝
    - `*`: 앞의 문자가 0회 이상 반복
    - `+`: 앞의 문자가 1회 이상 반복
    - `?`: 앞의 문자가 0회 또는 1회 등장
    - `|`: 둘 중 하나
    - `()`: 그룹화

#### Java에서의 사용
Java에서는 `Pattern`과 `Matcher` 클래스를 사용하여 정규 표현식을 처리합니다.

```
import java.util.regex.*;

public class RegexExample {
    public static void main(String[] args) {
        String input = "Hello, regex in Java!";
        String patternString = ".*regex.*";

        // 패턴 컴파일
        Pattern pattern = Pattern.compile(patternString);

        // 매처 생성
        Matcher matcher = pattern.matcher(input);

        // 패턴 매칭 확인
        if (matcher.matches()) {
            System.out.println("Pattern matched!");
        } else {
            System.out.println("Pattern not matched!");
        }
    }
}
```

아래는 정규 표현식을 사용하여 주어진 문자열에서 숫자 및 대문자를 추출하는 간단한 예제입니다.

```
import java.util.regex.*;

public class RegexExample {
    public static void main(String[] args) {
        String input = "The code is 12345. Java Regex is powerful.";

        // 숫자 추출 예제
        Pattern digitPattern = Pattern.compile("\\d+");
        Matcher digitMatcher = digitPattern.matcher(input);

        while (digitMatcher.find()) {
            System.out.println("Number: " + digitMatcher.group());
        }

        // 대문자 추출 예제
        Pattern uppercasePattern = Pattern.compile("[A-Z]");
        Matcher uppercaseMatcher = uppercasePattern.matcher(input);

        while (uppercaseMatcher.find()) {
            System.out.println("Uppercase letter: " + uppercaseMatcher.group());
        }
    }
}
```

## 파일 (File)
파일 처리는 Java에서 프로그램이 파일을 읽고 쓸 수 있도록 하는 부분입니다. Java에서 파일 처리는 `java.io` 패키지를 통해 제공됩니다. Java 7부터는 `java.nio.file` 패키지를 통해 향상된 파일 처리 기능이 추가되었으며, Java NIO를 사용하는 것이 권장됩니다.

### Java I/O
#### File
`File` 클래스를 사용하여 파일을 나타냅니다.

```
import java.io.File;

File file = new File("example.txt");
```

#### 파일 읽기
파일에서 데이터를 읽기 위해 `FileInputStream`과 `BufferedReader`를 사용합니다.

```
import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;

try {
    File file = new File("example.txt");
    FileInputStream fis = new FileInputStream(file);
    BufferedReader br = new BufferedReader(new InputStreamReader(fis));

    String line;
    while ((line = br.readLine()) != null) {
        System.out.println(line);
    }

    br.close();
    fis.close();
} catch (IOException e) {
    e.printStackTrace();
}
```

#### 파일 쓰기
파일에 데이터를 쓰기 위해 `FileOutputStream`과 `BufferedWriter`를 사용합니다.

```
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileOutputStream;
import java.io.FileWriter;
import java.io.IOException;

try {
    File file = new File("example.txt");
    FileOutputStream fos = new FileOutputStream(file);
    BufferedWriter bw = new BufferedWriter(new FileWriter(file));

    String content = "Hello, File Handling in Java!";
    bw.write(content);

    bw.close();
    fos.close();
} catch (IOException e) {
    e.printStackTrace();
}
```

### Java NIO (New I/O)
Java NIO를 사용하면 더 효율적이고 간편한 파일 처리가 가능합니다.

#### 파일 읽기
```
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.List;

try {
    Path path = Paths.get("example.txt");
    List<String> lines = Files.readAllLines(path);

    for (String line : lines) {
        System.out.println(line);
    }
} catch (IOException e) {
    e.printStackTrace();
}
```

#### 파일 쓰기
```
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.Collections;

try {
    Path path = Paths.get("example.txt");
    String content = "Hello, File Handling in Java!";
    Files.write(path, Collections.singleton(content));
} catch (IOException e) {
    e.printStackTrace();
}
```

#### 파일 삭제
```
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;

try {
    Path path = Paths.get("example.txt");
    Files.delete(path);
} catch (IOException e) {
    e.printStackTrace();
}
```

## 예외 (Exceptions)
Java에서 예외(Exceptions)는 프로그램 실행 중에 발생할 수 있는 오류 또는 예기치 않은 상황을 나타냅니다. 예외는 프로그램이 정상적으로 실행되는 데 방해가 되는 상황에서 발생하며, 예외 처리를 통해 이러한 상황을 다루거나 전파할 수 있습니다.

예외의 종류는 다음이 있습니다:
1.  **Checked Exceptions:**
    -   컴파일러가 강제하는 예외로, 코드 작성 시에 반드시 예외 처리를 해주어야 합니다.
    -   `IOException`, `SQLException` 등이 여기에 속합니다.
2.  **Unchecked Exceptions:**
    -   컴파일러가 강제하지 않는 예외로, 실행 중에 발생하는 예외입니다.
    -   `RuntimeException` 클래스와 그 하위 클래스들이 여기에 속합니다.
    -   `NullPointerException`, `ArrayIndexOutOfBoundsException` 등이 여기에 속합니다.
3.  **Error:**
    -   프로그램에서 복구할 수 없는 치명적인 오류를 나타냅니다.
    -   프로그래머가 직접적으로 처리하지 않아도 되는 예외입니다.
    -   `OutOfMemoryError`, `StackOverflowError` 등이 여기에 속합니다.

### 예외 처리
Java에서는 예외 처리를 통해 예외 상황을 다룰 수 있습니다. 예외 처리는 `try`, `catch`, `finally` 블록을 사용하여 구현됩니다.

```
try {
    // 예외가 발생할 수 있는 코드
    // 예외 발생 시 예외 객체가 던져짐
} catch (ExceptionType1 e1) {
    // 예외 타입1에 대한 처리
} catch (ExceptionType2 e2) {
    // 예외 타입2에 대한 처리
} finally {
    // 항상 실행되는 블록
    // (예외 발생 여부와 상관없이)
}
```

### 예외 발생
`throw` 키워드를 사용하여 직접 예외를 던질 수 있습니다.

```
if (someCondition) {
    throw new SomeException("Custom error message");
}
```

### 예외 전파
`catch` 블록에서 해당 예외 타입을 처리할 수 없다면(예: 던지는 예외와 잡는 예외 타입이 다름), 예외가 처리되지 않고 상위 메서드로 전파됩니다. Java에서는 예외가 `try-catch` 블록 내에서 처리되지 않으면, 호출 스택을 따라 상위 메서드로 전달되며, 이를 **예외 전파**라고 합니다.

- **예외가 처리되지 않음**: `try-catch` 블록에서 잡을 수 없는 예외 타입이 던져지면, 해당 예외는 처리되지 않고 상위 호출자로 전파됩니다.
- **예상치 못한 예외 전파**: 예외를 잡고 처리하려고 했지만, 타입이 맞지 않아서 처리되지 않는 경우가 발생할 수 있습니다. 이로 인해 예외가 의도치 않게 상위 호출자에게 전달될 수 있습니다.
- **불필요한 예외 처리**: 잡을 수 없는 예외를 `catch` 블록에서 처리하려고 하면, 불필요한 `catch` 절이 발생할 수 있습니다. 이는 코드 가독성을 떨어뜨리고, 예외 처리 흐름을 복잡하게 만들 수 있습니다.

**해결 방법**
1.  **예외 타입을 맞추기**: `try-catch` 블록에서 처리하는 예외 타입을 던지는 예외와 일치시켜야 합니다. 예를 들어, `IllegalArgumentException`을 던진다면, 이를 처리할 `catch` 블록에서 `IllegalArgumentException`을 잡아야 합니다.
2.  **다양한 예외를 잡을 수 있도록**: 여러 예외를 처리할 필요가 있을 때는, `catch` 블록에서 여러 예외를 한 번에 처리할 수 있도록 `catch (IOException | IllegalArgumentException e)`와 같이 사용합니다.

### 예외 체이닝 (Exception Chaining)
예외 체이닝은 한 예외가 발생한 후, 그 예외를 다른 예외로 **감싸서 던지는** 기법을 말합니다. 이를 통해 원래 발생한 예외 정보를 보존하면서, 새로운 예외를 던져서 호출 스택이나 예외 처리를 보다 유연하게 만들 수 있습니다.

1. **원본 예외 정보 보존**: 예외가 발생한 원인을 추적하는 데 도움이 됩니다. 예외를 감싸면서 원본 예외를 포함시켜, 나중에 예외를 처리할 때 원본 예외의 세부 사항을 알 수 있습니다.
2. **예외 처리의 일관성**: 여러 예외를 하나의 타입으로 통합하여 처리할 수 있습니다. 예를 들어, 여러 종류의 예외를 하나의 `ServiceException`으로 감싸서 처리할 수 있습니다.
3. **디버깅 용이성**: 예외 체이닝을 사용하면 예외가 발생한 경로를 추적할 수 있어 디버깅 시 유용합니다.

예외 체이닝은 보통 `throw` 구문을 사용하여 원본 예외를 새로운 예외에 포함시키는 방식으로 이루어집니다. Java에서는 예외를 생성할 때, 생성자의 두 번째 인자로 원본 예외를 넘겨줄 수 있습니다. 이 방법을 통해 예외 체이닝을 할 수 있습니다.

```
public void someMethod() {
    try {
        // 예외가 발생할 수 있는 코드
        externalApiCall();
    } catch (IOException | SQLException e) {
        // 다양한 예외를 하나의 예외로 감싸서 던짐
        throw new ServiceException("An error occurred during operation", e);
    }
}
```

이 예시에서 `ServiceException`은 `IOException`과 `SQLException`을 감싸고 있으며, `ServiceException`의 생성자에 원본 예외 `e`를 전달합니다. 이렇게 하면, `ServiceException`을 처리할 때 원본 예외 정보를 얻을 수 있습니다.

#### 커스텀 예외 (Custom Exceptions)
**커스텀 예외**(Custom Exception)는 애플리케이션에서 발생할 수 있는 특정 상황에 맞게 정의됩니다. Java에서 커스텀 예외를 정의하려면, `Exception`이나 `RuntimeException`을 상속받아 새로운 예외 클래스를 만들면 됩니다.

1. **구체적인 예외 처리**: 특정 애플리케이션에서 발생할 수 있는 예외를 명확하게 정의할 수 있습니다.
2. **예외 체이닝**: 여러 예외를 하나의 커스텀 예외로 감싸서 일관된 방식으로 처리할 수 있습니다.
3. **명확한 의도 전달**: 커스텀 예외는 예외가 발생한 이유나 문맥을 더 명확하게 전달할 수 있습니다.

```
public class ServiceException extends RuntimeException {
    // 기본 생성자
    public ServiceException(String message) {
        super(message);
    }

    // 예외 메시지와 원본 예외를 함께 받는 생성자
    public ServiceException(String message, Throwable cause) {
        super(message, cause);
    }
}
```

예를 들어, `IOException`이나 `SQLException`이 발생하면, 이를 `ServiceException`으로 감싸서 던지게 됩니다:
```
public class UserService {
    public void someMethod() {
        try {
            externalApiCall();
        } catch (IOException | SQLException e) {
            // 여러 예외를 하나의 커스텀 예외로 감싸서 던짐
            throw new ServiceException("An error occurred during operation", e);
        }
    }
}
```

## 쓰레드 (Thread)
Java에서 쓰레드는 동시에 여러 작업을 수행하기 위한 실행 단위입니다. Java는 멀티쓰레드 프로그래밍을 지원하며, 쓰레드를 생성하고 관리하기 위한 다양한 클래스와 메서드를 제공합니다. 쓰레드를 사용하면 여러 작업을 동시에 실행하여 시스템의 성능을 향상시킬 수 있습니다.

### 쓰레드 생성
Java에서는 두 가지 방법으로 쓰레드를 생성할 수 있습니다.

1. **`Thread` 클래스 확장:**
    -   `Thread` 클래스를 상속받아 사용자 정의 클래스에서 `run` 메서드를 오버라이딩합니다.
```
class MyThread extends Thread {
    public void run() {
        // 쓰레드에서 실행될 코드
    }
}

// 쓰레드 생성 및 실행
MyThread myThread = new MyThread();
myThread.start();
```
    
2. **`Runnable` 인터페이스 구현:**
    - `Runnable` 인터페이스를 구현한 클래스에서 `run` 메서드를 정의합니다.
    
```
class MyRunnable implements Runnable {
    public void run() {
        // 쓰레드에서 실행될 코드
    }
}

// 쓰레드 생성 및 실행
Thread myThread = new Thread(new MyRunnable());
myThread.start();
```

### 쓰레드 실행
쓰레드를 실행하기 위해서는 `start` 메서드를 호출합니다. `start` 메서드는 내부적으로 `run` 메서드를 호출하고, 이때 `run` 메서드에 정의된 코드가 쓰레드에서 실행됩니다.

```
class MyThread extends Thread {
    public void run() {
        // 쓰레드에서 실행될 코드
    }
}

// 쓰레드 생성 및 실행
MyThread myThread = new MyThread();
myThread.start();
```

### 쓰레드 생명주기
쓰레드는 여러 상태를 가지며, 이를 생명주기(Thread Lifecycle)라고 합니다. 주요한 쓰레드 상태는 다음과 같습니다:

1. **New :**
    - 쓰레드가 생성되었지만 `start` 메서드가 호출되지 않은 상태입니다.
2. **Runnable:**
    - `start` 메서드가 호출되어 쓰레드가 실행 대기 상태로 들어간 상태입니다.
3. **Blocked:**
    - 쓰레드가 락(lock) 등의 이유로 다른 쓰레드에 의해 차단된 상태입니다.
4. **Waiting:**
    - `Object.wait()`이나 `Thread.join()`과 같은 메서드에 의해 대기 중인 상태입니다.
5. **Timed Waiting:**
    - 제한된 시간 동안 대기하는 상태로, `Thread.sleep()`이나 `Object.wait(timeout)`과 같은 메서드에 의해 발생합니다.
6. **Terminated:**
    - 쓰레드의 `run` 메서드가 종료된 상태입니다.

## 어노테이션(Annotation)
**어노테이션(Annotation)**은 **메타데이터**를 제공하는 특별한 형태의 코드입니다. 어노테이션은 코드에 대한 추가 정보를 제공하거나, 코드의 특정 동작을 지정하는 데 사용됩니다. 일반적으로 어노테이션은 프로그램의 실행에 직접적인 영향을 미치지는 않지만, 컴파일러나 런타임 환경에서 이를 처리하여 동작을 변경할 수 있습니다.

1. **메타데이터 제공**: 어노테이션은 코드에 대한 설명을 추가하는 용도로 사용됩니다. 예를 들어, `@Override` 어노테이션은 메서드가 부모 클래스의 메서드를 오버라이드한다는 것을 명시적으로 나타냅니다.
2. **컴파일러 및 런타임에서 처리**: 어노테이션은 주로 컴파일러나 런타임에서 처리되며, 코드의 동작을 제어하거나 특정 동작을 유도합니다.
3. **코드의 가독성 향상**: 어노테이션을 사용하면 코드의 의도를 명확하게 나타낼 수 있어 가독성을 높이고, 코드의 유지보수를 용이하게 합니다.

### 종류
어노테이션은 크게 두 가지 유형으로 나눌 수 있습니다:
1. **빌트인 어노테이션**: Java에서 기본적으로 제공하는 어노테이션입니다.
    - `@Override`: 메서드가 부모 클래스에서 오버라이드된 메서드임을 나타냅니다.
    - `@Deprecated`: 더 이상 사용되지 않는 메서드나 클래스에 붙여 사용을 권장하지 않음을 나타냅니다.
    - `@SuppressWarnings`: 컴파일러 경고를 억제합니다.
2. **사용자 정의 어노테이션**: 개발자가 필요에 따라 정의할 수 있는 어노테이션입니다.
    -   예를 들어, `@Entity`, `@Controller`, `@RestController`와 같은 어노테이션은 Spring Framework에서 제공하는 사용자 정의 어노테이션입니다. 이러한 어노테이션은 특정 동작을 수행하거나 클래스의 역할을 정의하는 데 사용됩니다.

`@Override` 예시: 부모 클래스의 메서드를 오버라이드할 때 사용합니다.
```
@Override
public void myMethod() {
    // 부모 클래스의 메서드를 오버라이드
}
```
 
Spring의 `@RestController` 예시: Spring에서 RESTful API 컨트롤러를 정의할 때 사용됩니다.
```
@RestController
public class UserController {
    @GetMapping("/users")
    public List<User> getAllUsers() {
        // 사용자 목록을 반환하는 메서드
    }
}
```

## JPA
**JPA**는 **Java Persistence API**의 약자로, **자바 애플리케이션에서 데이터를 관계형 데이터베이스에 저장하고 관리하기 위한 표준 인터페이스**입니다. JPA는 데이터베이스와 객체 간의 매핑(Object-Relational Mapping, ORM)을 쉽게 구현할 수 있도록 도와줍니다.

1. **ORM (Object-Relational Mapping)**: 객체와 데이터베이스 테이블을 매핑하는 기술로, 자바 객체를 데이터베이스의 행(row)으로 매핑하여 객체 지향 프로그래밍 방식으로 데이터베이스를 다룰 수 있습니다.
2. **표준 명세**: JPA는 특정 구현체가 아니라, Java EE(Enterprise Edition)에서 정의한 **표준 인터페이스**입니다.
3.  **Persistence Context (영속성 컨텍스트)**: JPA에서 엔티티 객체를 관리하는 환경입니다. 데이터베이스와의 연결을 관리하며, 엔티티 객체의 상태를 추적합니다.

## Java Bean 규약
Java Bean 규약에 따르면, 클래스의 필드에 접근하기 위해 다음과 같은 메서드 패턴이 사용됩니다:
-   **Getter**: `get<FieldName>()` 또는 `is<FieldName>()` (boolean 필드의 경우)
-   **Setter**: `set<FieldName>(value)`

이 규약에 따라 Spring이나 Jackson 같은 라이브러리에서 자동으로 이 getter를 사용하여 값을 읽습니다. 즉, Java 클래스에서 Getter가 정의되어 있으면:
- Spring, Jackson 같은 라이브러리에서 자동으로 필드 값을 참조할 수 있습니다.
- Getter를 통해 JSON 직렬화, 데이터 바인딩 등이 이루어집니다.
- Java Bean 규약에 따라 클래스의 필드가 "프로퍼티"로 간주됩니다.

**getter 메서드**는 다음과 같은 양식을 따라야 합니다:
```
public <Type> get<PropertyName>() {
    return <property>;
}
```

아래 클래스는 `name`과 `email`이라는 **프로퍼티**를 가집니다. `getName()`과 `getEmail()` 메서드는 Spring이나 Jackson 같은 라이브러리가 `name`과 `email` 값에 접근할 때 사용됩니다.
```
public class User {
    private String name;
    private String email;

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }
}
```

## Log
### SLF4J
**SLF4J** (Simple Logging Facade for Java)는 Java에서 로깅을 위한 추상화 라이브러리입니다. SLF4J는 다양한 로깅 프레임워크(Log4j, Logback, java.util.logging 등)를 추상화하여, 애플리케이션이 특정 로깅 구현체에 의존하지 않도록 해줍니다. 즉, SLF4J는 로깅 API를 제공하지만, 실제 로깅 동작은 다른 로깅 구현체가 처리합니다. 대표적인 로깅 구현체로는 **Logback**, **Log4j**, **java.util.logging** 등이 있습니다.

1. **로깅 추상화**: SLF4J는 다양한 로깅 프레임워크의 차이를 숨기고, 공통된 인터페이스를 제공합니다. 이를 통해 개발자는 로깅 구현체를 변경할 때 코드 수정 없이 SLF4J API를 그대로 사용할 수 있습니다.
2. **플러그인 시스템**: SLF4J는 실제 로깅 구현체를 선택할 수 있는 플러그인 시스템을 제공합니다. 예를 들어, Logback, Log4j, JDK 로깅 등 다양한 로깅 구현체를 SLF4J와 함께 사용할 수 있습니다.
3. **로깅 성능 최적화**: SLF4J는 성능을 고려하여 설계되었으며, 로깅이 필요한 상황에서만 로깅을 활성화하는 방식으로 성능 저하를 최소화합니다.

**로그 레벨**: SLF4J는 여러 로그 레벨을 지원합니다.
- `TRACE`: 매우 상세한 로그 (주로 개발과 디버깅에 사용)
- `DEBUG`: 디버깅을 위한 로그
- `INFO`: 일반적인 정보성 로그
- `WARN`: 경고 로그
- `ERROR`: 오류 로그

```
package com.example.demo;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.boot.CommandLineRunner;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;

@SpringBootApplication
public class DemoApplication implements CommandLineRunner {

    private static final Logger logger = LoggerFactory.getLogger(DemoApplication.class);

    public static void main(String[] args) {
        SpringApplication.run(DemoApplication.class, args);
    }

    @Override
    public void run(String... args) throws Exception {
        logger.trace("This is a trace message");
        logger.debug("This is a debug message");
        logger.info("This is an info message");
        logger.warn("This is a warn message");
        logger.error("This is an error message");
    }
}
```

#### Logger
`Logger`는 로그 메시지를 기록하는 기능을 제공하는 인터페이스입니다. 

- `debug(String msg)`: `DEBUG` 레벨의 로그를 기록합니다.
- `info(String msg)`: `INFO` 레벨의 로그를 기록합니다.
- `warn(String msg)`: `WARN` 레벨의 로그를 기록합니다.
- `error(String msg)`: `ERROR` 레벨의 로그를 기록합니다.
- `trace(String msg)`: `TRACE` 레벨의 로그를 기록합니다.

#### LoggerFactory
`LoggerFactory`는 `Logger` 인스턴스를 생성하는 팩토리 클래스입니다.

## javax
`Jakarta`와 `javax`는 Java 플랫폼에서 사용되는 패키지 이름의 두 가지 버전입니다. 그 차이는 주로 Java EE (Enterprise Edition)와 관련이 있습니다.

Oracle은 더 이상 `javax` 패키지의 업데이트를 진행하지 않습니다. 새로운 프로젝트에서는 `Jakarta`를 사용하는 것이 권장됩니다.

### javax (Java Extension)
- `javax`는 Java의 초기 버전에서 사용되던 패키지 네임스페이스입니다.
- `javax`는 Java EE (Enterprise Edition)의 일부로, 서블릿, JSP, EJB, JPA 등과 같은 엔터프라이즈 기능을 제공하는 클래스들을 포함하고 있었습니다.
- `javax` 패키지는 Oracle이 Java EE를 관리할 때 사용되었습니다.

### Jakarta
- `Jakarta`는 `javax`의 후속 패키지 네임스페이스입니다.
- 2017년에 Oracle은 Java EE의 관리 권한을 Eclipse 재단에 이전했으며, 그 이후 Java EE는 `Jakarta EE`로 이름이 변경되었습니다.
- `Jakarta`는 `javax` 패키지를 계승하여, Java EE의 기술들을 Eclipse 재단의 관리 하에 발전시킵니다.
- 이 변화는 Java EE의 라이센스가 변경되면서 발생했으며, 새로운 API와 기능들이 `Jakarta` 네임스페이스에서 관리됩니다.

## 출처 (Reference)
https://www.w3schools.com/java/java_syntax.asp
