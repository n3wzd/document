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

## 출처 (Reference)
https://www.w3schools.com/java/java_syntax.asp
