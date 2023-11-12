# Dart
Google에서 개발된 `Dart`는 다양한 플랫폼(Android, iOS, 웹 등)에서 빠르게 앱을 개발할 수 있는 클라이언트 최적화, 객체 지향 프로그래밍 언어입니다.

- 무료이며 오픈소스입니다.
- 네이티브 코드 및 `Javascript` 컴파일이 가능합니다. 실제로 Dart는 자바스크립트와 비슷한 점이 많으며, 자바스크립트를 알고 있다면 Dart도 빠르게 익힐 수 있습니다. (단, 함수와 클래스는 자바스크립트보단 C++하고 유사합니다.)
- Dart를 사용하는 대표적인 프레임워크로 `Flutter`가 있습니다.
- 백엔드 분야에서도 사용할 수 있습니다.

## 기초 (Basic)
- 모든 프로그램은 `main` 함수로 시작됩니다.
- 모든 구문의 끝은 세미콜론 `;`으로 끝납니다.
- 중괄호`{}`를 사용해  블록 구간을 표현합니다.
	- Dart에선 블록이 한 줄이어도 `{}`를 생략하지 않는 편입니다.
- `print` 함수는 콘솔창에 문자열을 출력합니다.
		- `print` 인자에서  `$`와 변수명으로 간편하게 변수를 출력할 수 있습니다.

```
void main() {
	print("Hello World!");
}
```

```
void main() {
	var level = 5;
	print("Level is $level"); // Level is 5
}
```

### 변수 (Variable)
- `변수`는 값을 저장하는 컨테이너이며, 초기화 이후에도 값을 바꿀 수 있습니다.
- 변수는 선언 동시 초기화가 가능합니다.
- Dart에서 변수의 생성 및 이름 규칙은 자바스크립트와 거의 동일합니다.

```
var cnt = 0;
String name = "Steve";
num level = 1;
bool flag = true;
```

#### const
- 키워드 `const`를 사용해 상수를 선언할 수 있습니다.
- const 변수는 선언 동시에 초기화되어야 하며, 초기화 이후에 값을 변경할 수 없습니다.
- const 변수의 값은 컴파일 과정에 결정됩니다.

```
const MAX_LENGTH = 10;
```

#### final
- 키워드 `final`를 사용해 상수를 선언할 수 있습니다.
- final 변수는 선언 동시에 초기화되어야 하며, 초기화 이후에 값을 변경할 수 없습니다.
- final 변수의 값은 런타임 과정에 결정됩니다.
- 상수가 필요할 때, 컴파일 과정에 값이 결정된다면 const, 런타임 과정(클래스 프로퍼티, 파일, 네트워크, 데이터베이스 등)에 값이 결정된다면 final을 사용하면 됩니다.

```
class Item {
	final String name = 'item';
	
	void display() {
		print(name);
	}
}

void main(){
    Item item = Item();
    item.display(); // item
}
```

### 데이터 타입 (Data Types)
- Dart에서 값의 유형은 다음이 있습니다.

|분류|키워드|의미|
|---|---|---|
|Number|`int`, `double`, `num`|수 값|
|String|`String`|문자열 값|
|Boolean|`boolean`|true/false 값|
|List|`list`|리스트 자료구조|
|Map|`map`|map 자료구조|
|Set|`set`|set 자료구조|
|Runes|`runes`|문자열 유니코드 값|
|Null|`null`|null 값|

#### Number
- `int`: 정수 타입
- `double`: 실수 타입
- `num`: 정수/실수 타입
- `int`와 `double`은 `num`의 서브타입입니다.

```
void main() {
	int num1 = 10;
	double num2 = 10.5;
	num num3 = 5;
	num num4 = 5.8;
	
	num sum = num1 + num2 + num3 + num4;
	print("$sum"); // 31.3
}
```

#### String
- `String`: 문자열 타입

```
void main() {
	String str = "This is String";
	print(str);
}
```

#### Boolean
- `bool`: boolean 타입
- true/false 2가지 값을 가집니다.

```
void main() {
	bool trigger = true;
	print(trigger); // true
}
```

#### List
- `List<type>`: `type` 값을 저장하는 리스트(배열)
- 사용 방법은 자바스크립트의 배열과 거의 유사합니다.

```
void main() {
	List<int> arr = [1, 2, 3];
	print(arr[1]); // 2
}
```

#### Set
- `Set<type>`: 집합을 표현하는 `set` 자료구조
- 집합은 중복 없는 원소를 순서 상관없이 저장합니다.

```
void main() {
	Set<String> st = { 'sword', 'shield', 'spear' };
	print(st);
}
```

#### Map
- `Map<key, value>`: 키-값 쌍을 저장하는 `map` 자료구조

```
void main() {
	Map<int, string> mp = {
		1: 'sword',
		2: 'shield',
		3: 'spear'
	};
	print(mp[2]); // shield
}
```

#### Runes
- `runes`은 String의 유니코드를 담은 프로퍼티입니다.

```
void main() {
	String value = 'babc';
	print(value.runes); // 98, 97, 98, 99
}
```

### 타입 확인
- `is` 연산자를 사용하면 타입을 확인할 수 있습니다.

> `value` is `type`

```
void main() {
	int n = 10;
	print(n is int); // true
}
```

### 타입 변환
- 메소드를 사용해서 타입 변환을 할 수 있습니다.

|메소드|이전|이후|
|---|---|---|
|int.parse(`str`)|String|int|
|double.parse(`str`)|String|double|
|toString()|num|String|
|toInt()|double|int|

```
void main() {
	int num1 = int.parse("10");
	String str1 = num1.toString();
	double num2 = double.parse("5.2");
	int num3 = num2.toInt();

	print("$str1, $num2, $num3"); // 10, 5.2, 5
}
```

### 타입 추론
- `var`로 선언된 변수는 컴파일러가 자동으로 타입을 추론합니다.
- `dynamic`으로 선언된 변수는 런타임 중간에 타입이 자동으로 결정됩니다.

```
void main() {
	var n = 10;
	dynamic s = 'abc'
}
```

### 주석 (Comments)
- `//`: 단일 라인 주석
- `/* */`: 여러 줄 주석
- `///`: documentation 주석

### 연산자 (Operators)
- 대부분의 연산자는 자바스크립트와 동일합니다.

|연산자|기능|
|---|---|
|`~/`|나누기(정수)|
|`is`|특정 타입이 맞으면 true 반환|
|`is!`|특정 타입이 맞으면 false 반환|

#### Cascade Notation
- `..` 연산자를 사용하면 하나의 오브젝트로 메소드를 여러 번 사용할 수 있습니다.

```
List list1 = [];
list1.add(1);
list1.add(2);
list1.add(3);

List list2 = [];
list2
  ..add(1)
  ..add(2)
  ..add(3)
```

### 입력 (Input)
- `stdin.readLineSync()` 메소드는 사용자로부터 입력받은 문자열(String 타입)을 반환합니다. (`stdin`은 `dart:io`에 포함되어 있습니다.)
- 만약 수를 입력받고자 한다면, 형변환을 거쳐야 합니다.

```
import 'dart:io';

void main() {
	String str = stdin.readLineSync();
	print('Input is $str');
}
```

### String
- 따옴표를 3개씩 이어붙이면(`'''`, `"""`) 줄바꿈이나 탭을 포함한 문자열을 표현할 수 있습니다.
- 문자열 내 사용 가능한 특수문자는 다음과 같습니다.

|특수문자|기능|
|---|---|
|`\n`|줄바꿈|
|`\t`|탭|

- 문자열 앞에 `r`을 붙이면 특수문자가 반영되지 않고 그대로 출력됩니다.
- `+` 연산자로 두 문자열을 결합할 수 있습니다.

```
void main() {
	String str1 = "This is String";
	String str2 = '''This
	is
	Multi Line String
	''';
	String str3 = 'Tab\tand\nEnter';
	String str4 = r'Tab\tand\nEnter';

	print(str1);
	print(str2);
	print(str3 + str4); 
}
```

- String에서 주로 사용되는 프로퍼티와 메소드는 다음과 같습니다.
	- 대부분 자바스크립트의 것과 비슷합니다.

|프로퍼티|의미|
|---|---|
|codeUnits|UTF-16 코드|
|isEmpty|문자열이 비어 있다면 true|
|isNotEmpty|문자열이 비어 있다면 false|
|length|문자열 길이(공백 포함)|

|메소드|기능|
|---|---|
|toLowerCase()|모든 문자를 소문자로 바꾼 String 반환|
|toUpperCase()|모든 문자를 대문자로 바꾼 String 반환|
|trim()|모든 공백 문자를 제거한 String 반환|
|compareTo(`str`)|현재 String이 `str`보다 크면(=사전순으로 뒤쪽이면) 1, 작으면 -1, 같으면 0 반환|
|replaceAll(`target`, `word`)|현재 문자열 내 `target`을 `word`로 대체한 String 반환|
|split(`sep`)|현재 문자열을 `sep` 기준으로 분리한 문자열 조각들을 담은 List 반환|
|toString()|현재 값을 String으로 변환|
|substring(`lo`, _`hi`_)|현재 문자열을 `lo` 인덱스부터 `hi` 인덱스까지 자른 문자열 반환 (`hi` 생략시 마지막 인덱스까지)|

### 템플릿 리터럴 (Template Literal)
- Dart에서도 Javascript의 `템플릿 리터럴`을 사용할 수 있습니다.
	- 백틱 대신에 작은 따옴표가 사용됩니다.
	- 변수 단독이면 중괄호를 생략할 수 있습니다.
- Dart 2.0.0부터는 문자열 표현시 이 방법이 권장됩니다.

```
'${user.name}'s level: ${user.level}.' // Steve's level: 5
'$minutesPadding$minutes:$secondsPadding$seconds' // 15:58
```

## 제어문 (Control Flow)
### if
- Dart의 조건문은 자바스크립트와 동일합니다. (`if`, `else`, `else if`)

```
void main() {
	int n = 10;
	if(n > 5) {
		print('n is bigger than 5');
	} else if(n < 5) {
		print('n is smaller than 5');
	} else {
		print('n is 5');
	}
}
```

### assert
- `assert` 메소드는 주어진 조건이 `false`면 오류 메시지를 발생시킵니다.
	- 메시지 인자는 생략 가능합니다.

> assert(`condition`, `msg`);

```
void main() {
	var n = 10;
	assert(n != 10, 'n is 10!');
	print('pass!'); // 실행되지 않습니다!
}
```

### switch
- Dart의 `switch`은 자바스크립트와 동일합니다.

```
void main() {
	int n = 3;
	switch(n) {
		case 1: print('n is 1'); break;
		case 2: print('n is 2'); break;
		case 3: print('n is 3'); break;
	}
}
```

### for
- Dart의 `for`, `for / in`은 자바스크립트와 동일합니다.

```
void main() {
	for(var i = 0; i < 3; i++) {
		print(i);
	}
}
```

### while
- Dart의 `while`, `do / while`은 자바스크립트와 동일합니다.
- while의 조건문은 항상 boolean 타입이어야 합니다.

```
void main() {
	var i = 3;
	while(i > 0) {
		print(i--);
	}
}
```

### break / continue
- Dart의 `break`, `continue`은 자바스크립트와 동일합니다.

```
void main() {
	var i = 5;
	while(i > 0) {
		print(i--);
		if(i == 2) {
			break;
		}
	}
}
```

### 예외 처리 (Exception Handling)
- Dart의 `try`, `catch`, `finally`, `throw`는 자바스크립트와 동일합니다.

```
void main() {
	try {
		var n = 10;
		if(n == 10) {
			throw n;
		}
	} catch(err) {
		print(err);
	}
}
```

## 함수 (Function)
- Dart의 함수의 구조는 C++하고 유사하며, 사용법 역시 같습니다.
- 자바스크립트와 마찬가지로 Dart에서도 함수는 객체입니다.
- Dart의 `범위(scope)`는 `{}`(블록)을 기준으로 합니다.
	- Dart의 전역은 main 함수의 바깥입니다.

> `type` `fuctionName`(`param1`, `param2`, ...){
> 	// body
> }

```
int adder(int a, int b) {
	return a + b;
}
```

### 매개변수 (Parameter)
- 대괄호`[]`를 사용하면 `선택적 매개변수`가 됩니다.
- 중괄호`{}`를 사용하면 `이름이 있는 매개변수`가 됩니다.
	- 함수를 호출할 때 매개변수의 이름을 직접 지시할 수 있습니다.
	- 이름이 있는 매개변수의 타입은 반드시 nullable이어야 합니다.
- 기본값이 존재하는 `디폴트 매개변수`를 사용할 수 있습니다.
- `@required` 또는 `required` 키워드를 붙여서 필수 매개변수임을 명시할 수 있습니다.

```
double div(int a, [int b = 2]) {
	return a / b;
}
void main() {
	print(div(6)); // 3.0
}
```

```
void printer({String? name, int? level}) {
	print("$name's level = $level");
}
void main() {
	printer(level: 5, name: 'steve'); // steve's level = 5
}
```

```
Status({
	String clan,
	required String name,
	required int level,
})
```

### 익명 함수 (Anonymous Function)
- Dart의 `익명 함수`는 자바스크립트의 것과 동일합니다.
- 익명 함수는 주로 함수를 인자로 제공할 때 사용됩니다.

```
void main() {
	var sqrt = (int n) { return n * n; };
	print(sqrt(3)); // 9
}
```

### 화살표 함수 (Arrow Function)
- Dart에서 `화살표 함수`는 단일 return을 포함한 함수를 축약할 때 사용됩니다.

> `type` `fuctionName`(`param1`, `param2`, ...) \=\> `expression` 

```
int sqrt(int n) => n * n;
void main() {
	print(sqrt(3)); // 9
}
```

### dart:math
- `dart:math`를 import하면 수학 관련 메소드를 사용할 수 있습니다. (`min`, `max`, `pow` 등)

## 표준 객체 (Standard Object)
### List
- Dart에서 `List`는 일반적인 프로그래밍에서 배열입니다.
	- 사용되는 List의 사용법, 프로퍼티, 메소드는 자바스크립트의 `Array`와 거의 같습니다.
- `[]` 연산자로 인덱스를 통해 값을 참조합니다.
- `length` 프로퍼티로 List 길이를 구할 수 있습니다.
- `const`로 선언된 List는 값을 수정할 수 없습니다.

```
List<int> list1 = [1, 2, 3]; // 단일 타입 List
var list2 = [1, '2', false]; // 한 List에 여러 타입을 담을 수 있습니다.
```

#### 생성
- spread 키워드 `...`를 통해 다른 List를 사용해서 List를 생성할 수 있습니다.
- List 생성할 때 조건문을 삽입할 수 있습니다.

```
void main() {
	bool flag = false;
	List<int> arr1 = [1, 2, 3];
	List<int> arr2 = [4, 5, 6];
	List<int> arr3 = [...arr1, ...arr2, if(flag) 7];
	print(arr3); // [1, 2, 3, 4, 5, 6]
}
```

#### 추가

|메소드|기능|
|---|---|
|add(`item`)|마지막 인덱스에 단일 값 추가|
|addAll(`itemList`)|마지막 인덱스에 여러 값(List) 추가|
|insert(`idx`, `item`)|특정 인덱스에 단일 값 추가|
|insertAll(`idx`, `itemList`)|특정 인덱스에 여러 값(List) 추가|

#### 삭제

|메소드|기능|
|---|---|
|remove(`value`)|값을 통해서 아이템 삭제|
|removeAt(`idx`)|인덱스를 통해서 아이템 삭제|
|removeLast()|마지막 인덱스 아이템 삭제|
|removeRange(`lo`, `hi`)|\[lo. hi) 인덱스 아이템 삭제|

### Set
- Dart에서 `Set`은 set 자료구조입니다.
	- set 자료구조는 순서가 없는 집합입니다. set은 중복 원소를 허용하지 않습니다.
	- 사용되는 Set의 사용법, 프로퍼티, 메소드는 자바스크립트의 `Set`와 거의 같습니다.
- Dart에서 Set은 내부적으로 순서가 존재합니다. 따라서 Set에서도 인덱스를 사용할 수 있습니다.

```
void main(){
	Set<int> fruits = {1, 2, 3};
	print(fruits);
}
```

|프로퍼티|의미|
|---|---|
|isEmpty|Set이 비어있으면 true|
|length|Set의 원소 개수|

|메소드|기능|
|---|---|
|add(`item`)|주어진 단일 값을 Set에 추기|
|remove(`item`)|주어진 단일 값을 Set에서 삭제|
|clear()|Set의 모든 원소 삭제|
|elementAt(`idx`)|인덱스를 통해 Set의 값 참조|
|difference(`set`)|현재 Set A와 주어진 Set B의 차집합(A - B) 반환|
|intersection(`set`)|현재 Set A와 주어진 Set B의 교집합 반환|

### Map
- Dart에서 `Map`은 map 자료구조입니다.
	- map 자료구조는 key-value 쌍을 저장합니다. key는 중복을 허용하지 않습니다.
	- 사용되는 Set의 사용법, 프로퍼티, 메소드는 자바스크립트의 `Set`와 거의 같습니다.

```
void main(){
	Map<int, String> shop = {
		1: 'sword',
		2: 'lance',
		3: 'bow'
	};
	print(shop);
}
```

|프로퍼티|의미|
|---|---|
|isEmpty|Map이 비어있으면 true|
|length|Map의 원소 개수|

|메소드|기능|
|---|---|
|containsKey(`key`)|`key`가 Map에 존재하면 true 반환|
|containsValue(`value`)|`value`가 Map에 존재하면 true 반환|
|clear()|Map의 모든 원소 삭제|

### Where
- `where` 메소드는 List, Set, Map에서 특정 원소를 추출할 때 사용됩니다.
- 조건으로 사용되는 bool 타입 콜백 함수를 인자로 하며, 조건에 맞는 원소들은 Iterable 타입으로 묶어서 반환됩니다. (`toList()`으로 List 타입으로 바꿀 수 있습니다.)

> Iterable\<E\> where(
> 	bool condition(E element) { ... }
>)
>// condition이 true인 element는 반환되는 Iterable에 담깁니다.

```
void main() {
  List<int> arr = [1, 2, 3, 4, 5];
  List<int> oddNumbers = arr.where((n) => n.isOdd).toList();
  print(oddNumbers); // [1, 3, 5]
}
```

### DateTime
- Dart에선 날짜, 시간을 관리하는 객체인 `DateTime`을 제공합니다.
- 다음 메소드로 DateTime 인스턴스를 생성할 수 있습니다.

|메소드|기준|
|---|---|
|DateTime.now()|현재 시간|
|DateTime.parse(`str`)|특정 시간(ex. 2023-09-04)|

- 생성된 인스턴스는 다음 프로퍼티와 메소드를 갖습니다.

|프로퍼티|의미|
|---|---|
|year|연도|
|month|월|
|day|일|
|hour|시|
|minute|분|
|second|초|

|메소드|기능|
|---|---|
|add(`Duration`)|시간 더하기|
|subtract(`Duration`)|시간 빼기|
|difference(`DateTime`)|두 Datetime의 차이 반환(Duration)|
|IsAfter(`DateTime`)|현재 DateTime이 뒤에 있으면 true 반환|
|IsBefore(`DateTime`)|현재 DateTime이 앞에 있으면 true 반환|
|IsAtTheSameMoment(`DateTime`)|두 DateTime이 같으면 true 반환|

- DateTime 객체를 연산할 때, 시차를 관리하는 `Duration` 객체가 사용됩니다. 이 객체는 다음 프로퍼티를 갖습니다.

|프로퍼티|의미|
|---|---|
|inDays|현재 시차를 일 단위로 반환|
|inHours|현재 시차를 시 단위로 반환|
|inMinutes|현재 시차를 분 단위로 반환|
|inSeconds|현재 시차를 초 단위로 반환|
|inMilliseconds|현재 시차를 밀리초 단위로 반환|
|inMicroseconds|현재 시차를 마이크로초 단위로 반환|

```
void main() {
	DateTime datetime = DateTime.now();
	print("Year: " + datetime.year.toString());
	print("Month: " + datetime.month.toString());
	print("Day:" + datetime.day.toString());
	print("Hour: " + datetime.hour.toString());
	print("Minute: " + datetime.minute.toString());
	print("Second: " + datetime.second.toString());
}
```

### Random
- `Random` 객체는 무작위 수를 반환할 때 사용됩니다. (`dart:math`에 포함되어 있습니다.)
- `nextInt(n)` 메소드는 \[0, n) 범위 내 무작위 정수를 반환합니다.

```
import 'dart:math';
void main() {
	Random random = Random();
	print(random.nextInt(10)); // [0, 9] 랜덤 정수 반환
}
```

## 파일 (File)
- `File` 객체는 파일 정보를 저장합니다. (`dart:io`에 포함되어 있습니다.)
- File 객체의 생성자는 파일 경로를 인자로 합니다.
- File의 프로퍼티/메소드로 파일을 제어하거나 파일의 정보를 가져올 수 있습니다.

|프로퍼티|의미|
|---|----|
|path|파일 경로|
|absolute.path|파일 절대경로|

|메소드|기능|
|---|----|
|readAsStringSync()|파일 내용 반환 (문자열)|
|writeAsStringSync(`contents`, `mode`)|파일 내용 쓰기|
|existsSync()|파일 존재시 true 반환|
|deleteSync()|파일 삭제|
|lengthSync()|크기(byte) 반환|
|lastModifiedSync()|수정된 날짜 반환|

```
import 'dart:io';

void main() {
	File file = File('test.txt');
	String contents = file.readAsStringSync(); // 파일 읽기
	print(contents);
}
```

```
import 'dart:io';

void main() {
	File file = File('test.txt');
	file.writeAsStringSync('New Contents!!'); // 파일 쓰기
}
```

```
import 'dart:io';

void main() {
	// 파일 이어쓰기
	File file =  File('test.txt');
	file.writeAsStringSync('\nMore Contents!!', mode: FileMode.append);
}
```

## Null Safety
- Dart에서 `Null Safety`는 `null`로 인한 오류를 대비하여 안전한 코드를 제공하는 방법입니다. (null이 포함된 코드는 오류가 발생할 가능성이 잠재되어 있습니다!)
- `non-nullable` 변수에는 null을 할당할 수 없습니다. Dart에서 기본적으로 모든 변수는 non-nullable입니다.
- 변수 선언시 타입 뒤에 `?`를 붙이면 해당 변수는 `nullable`이 됩니다. (null이 할당될 수 있습니다.)
	- non-nullable 타입과 nullable 타입은 서로 구분됩니다. 예를 들어 String과 String?은 `is` 연산자로 확인시 서로 다른 타입으로 취급됩니다.
- nullable 변수는 List, Set, Map, 함수의 매개변수, 클래스 프로퍼티에도 사용 가능합니다.

```
void main() {
	String safeName = null; // 오류가 발생합니다!
	String? name = null;
	name = 'steve';
}
```

### null 감지
- 조건문으로 `null`을 감지할 수 있습니다.
- `??` 연산자는 피연산자 변수가 `null`이면 기본 값을 반환합니다.
- `!` 연산자는 피연산자 변수가 `null`이면 예외를 던집니다.

```
void main() {
	String? name = null;
	if(null == name) {
		print('null 감지!');
	}
	
	String newName = name ?? "steve";
	print(newName); // steve

	try {
		print(name!);
	} catch(e) {
		print('null 감지!');
	}
}
```

### Type Promotion
- Dart에서 `Type Promotion`은 변수의 타입이 상황에 맞게 자동으로 변환되는 메커니즘입니다.
- Type Promotion의 경우는 2가지가 있습니다.

> 1. 상위 타입에서 서브타입으로 자동 변환
> 2. `nullable` 타입에서 `non-nullable` 타입으로 자동 변환

```
void main(){
	Object name = 'steve';
	if(name is String) {
		// name의 타입이 Object에서 String으로 자동 변환됩니다.
		print(name.length); // 5
	}
}
```

```
void main() {
	String? value = 'test';
	if(value is String) {
		// value의 타입이 String?에서 String으로 자동 변환됩니다.
		print(value.length); // 4
	} else {
        	print('value is Stirng?'); // value가 null이면 여기가 실행됩니다.
	}
}
```

### Late
- non-nullable 변수는 선언시 초기화를 해야 합니다.
- 하지만 `late` 키워드를 사용하면 초기화를 나중에 할 수 있습니다. (단, 변수 사용 전에는 초기화가 반드시 수행되어야 합니다.)
- late 키워드는 클래스 프로퍼티(`final` 포함)에도 사용 가능합니다.

```
void main() {
	late String name;
	name = "steve"; // 나중에 변수를 초기화할 수 있습니다.
	print(name); // 사용 전에는 초기화가 되어 있어야 합니다.
}
```

- `Lazy initialization`은 초기화와 관련된 복잡한 연산이나 과정을 해당 값을 사용하기 전까지 미루는 기법입니다.
- late 키워드를 사용하면 Lazy initialization가 적용됩니다.

```
String getWeapon() {
	print("New Item!!");
	return "Saber";
}

void main() {
	print("Let's Go!");
	late String weapon = getWeapon();
	print("Battle Start!"); // 이 구문이 먼저 실행됩니다.
	print(weapon);
}
```

```
// 실행 결과
Let's Go!
Battle Start!
New Item!!
Saber
```

## 클래스 (Class)
- Dart에선 `class`를 제공하며, 이는 일반적인 객체지향 언어의 클래스와 같은 기능을 합니다.
- 클래스는 프로퍼티와 메소드를 갖습니다.
	- 메소드도 선택적 매개변수, 이름이 있는 매개변수, 디폴트 매개변수를 사용할 수 있습니다.
- 클래스를 사용해서 `instance`를 생성할 수 있습니다. (`new` 키워드를 사용할 수 있으나 생략 가능합니다.)

```
class Item {
	String? name;
	int? atk;
	int? def;

	void display() {
		print("$name: $atk, $def");
	}
}

void main(){
    Item sword = Item();
    sword.name = "sword";
    sword.atk = 10;
    sword.def = 5;
    sword.display(); // sword: 10, 5
}
```

### 생성자 (Constructor)
- Dart의 `생성자`는 일반적인 객체지향 언어의 생성자와 동일합니다. (생성자는 객체 생성시 호출되는 메소드입니다.)
- 생성자를 정의하지 않으면, 인스턴스 생성시`기본 생성자(Default Constructor)`가 자동으로 호출됩니다.
- 기본 생성자를 직접 정의할 수도 있습니다. 인자가 없는 생성자가 곧 기본 생성자입니다. (반대로 인자가 존재하는 생성자를 `Parameterized Constructor`라고 합니다.)
- `this` 키워드는 현재 인스턴스를 가리킵니다.

```
class Item {
	String? name;
	int? atk;
	int? def;

	Item(String name, int atk, int def) {
		this.name = name;
		this.atk = atk;
		this.def = def;
	}

	void display() {
		print("$name: $atk, $def");
	}
}

void main(){
    Item sword = Item("sword", 10, 5);
    sword.display(); // sword: 10, 5
}
```

- Dart에선 this를 통해 할당하는 생성자를 압축해서 쓸 수 있습니다. 예를 들어 위의 생성자는 다음과 같이 압축할 수 있습니다. (동작은 동일합니다.)

```
Item(this.name, this.atk, this.def);
```

#### Named Constructor
- Dart에서 생성자는 오버로딩이 불가합니다. 그러나 Dart에선 생성자에 이름을 부여할 수 있으며, 이를 통해 생성자들을 식별할 수 있습니다.

```
class Item {
	String? name;
	int? atk;
	int? def;

	Item.full(this.name, this.atk, this.def);
	Item.min(this.name) {
		atk = def = 0;
	}

	void display() {
		print("$name: $atk, $def");
	}
}

void main(){
    Item sword = Item.full("sword", 10, 5);
    Item lance = Item.min("lance");
    sword.display(); // sword: 10, 5
    lance.display(); // lance: 0, 0
}
```

#### Constant Constructor
- 생성자 앞에 `const`를 붙이면 `상수 생성자`가 됩니다. 상수 생성자는 상수 인스턴스를 생성하며, 상수 인스턴스는 프로퍼티 변경이 불가합니다. (코드 안전성이 향상됩니다.)
- 상수 생성자를 사용하려면 해당 클래스의 모든 프로퍼티가 `final`이어야 합니다.

```
class Item {
  final int hp;
  final int mp;

  const Item(this.hp, this.mp);
  void display() {
	  print('$hp, $mp');
  }
}

void main() {
	// Item 클래스로 생성된 인스턴스는 프로퍼티 변경이 불가합니다.
	Item item = Item(10, 20);
	item.display();
}
```

- 상수 인스턴스를 담는 변수가 `const`이고, 인스턴스의 프로퍼티가 서로 동일하다면, `hashCode` 값도 동일합니다.

```
class Item {
  final int hp;
  final int mp;

  const Item(this.hp, this.mp);
}

void main() {
	const Item item1 = Item(10, 20);
	print(item1.hashCode);

	const Item item2 = Item(10, 20);
	print(item2.hashCode); // item1과 동일한 값을 갖습니다.

	Item item3 = Item(10, 20);
	print(item3.hashCode);

	Item item4 = Item(10, 20);
	print(item4.hashCode);
}
```

### private
- 프로퍼티 이름 앞에 `_`를 붙여 선언하면 `private` 프로퍼티가 됩니다.
- Dart에서 private 범위는 클래스가 아닌 파일(=library)을 기준으로 합니다. 따라서 한 파일 안에서는 클래스 바깥이라도 private 프로퍼티를 조작할 수 있습니다.
- 일반적인 객체지향 언어처럼 클래스 단위 private로 사용하려면 파일을 분리해야 합니다.

```
class Item {
	// private 프로퍼티
	String? _name;
	int? _atk;
	int? _def;

	Item(this.name, this.atk, this.def);

	void display() {
		print("$name: $atk, $def");
	}
}

void main(){
    Item sword = Item('sword', 10, 5);
    sword._def = 20;
    sword.display(); // sword: 10, 20
}
```
### getter / setter
- getter / setter는 private 프로퍼티를 접근할 때 주로 사용됩니다. (코드 안전성 확보)
- getter / setter의 이름은 프로퍼티 이름과 중복될 수 없습니다.

#### getter
- `getter`는 프로퍼티를 참조하는 방식으로 호출되는 메소드입니다.
- 타입과 메소드명 사이에 `get` 키워드를 사용해서 getter를 정의할 수 있습니다.
- getter는 인자가 없고 반환값이 존재합니다.

```
class Item {
	int? _atk;
	int? _def;

	Item(this._atk, this._def);

	int get power => _atk! * _def!;
}

void main(){
    Item sword = Item(10, 5);
    print(sword.power);
}
```

#### setter
- `getter`는 프로퍼티를 설정하는 방식으로 호출되는 메소드입니다.
- 메소드명 앞에 `set` 키워드를 사용해서 setter를 정의할 수 있습니다.
- setter는 반환값이 없고 단일 인자가 존재합니다.

```
class Item {
	int? _atk;
	int? _def;

	void display() {
		print("$_atk, $_def");
	}

	set power(int p) => _atk = _def = p;
}

void main(){
    Item sword = Item();
    sword.power = 10;
    sword.display(); // 10, 10
}
```

### 상속 (Inheritance)
- Dart에서 `상속`은 일반적인 객체지향의 상속과 같은 기능을 합니다.
	- 하위 클래스가 상위 클래스를 상속하면, 상위 클래스의 프로퍼티 / 메소드를 이어받습니다.
- `extends` 키워드를 사용해서 상속을 할 수 있습니다.
- Dart에서는 다중 상속(하위 클래스가 여러 상위 클래스를 상속)을 지원하지 않습니다.
- 생성자는 상위 클래스부터 차례대로 실행됩니다.

```
class Monster {
	String? name;
	int? hp;
	int? mp;

	Monster() {
		print('Warning!!');
	}

	void display() {
		print("$name: $hp, $mp");
	}
}

class Slime extends Monster {
	bool hasPoison = true;

	Slime(int hp, int mp) {
	    name = 'Slime';
	    this.hp = hp;
	    this.mp = mp;
	    print('$name Spawned!!');
	}

	void attack() {
		print("$name uses Gel Punch!");
	}
}

void main() {
	Slime slime = Slime(100, 50);
	slime.display();
	slime.attack();
}
```

```
// 실행 결과
Warning!!
Slime Spawned!!
Slime: 100, 50
Slime uses Gel Punch!
```

### super
- `super`는 상위 클래스(=extends한 클래스)를 참조합니다.
- `super`를 사용해서 상위 클래스의 프로퍼티 / 메소드를 명시적으로 사용할 수 있습니다.

```
class Monster {
	void attack() {
		print("Attack Start!");
	}
}

class Slime extends Monster {
	void attack() {
		super.attack(); // Attack Start!
		print("Slime uses Gel Punch!");
	}
}

void main() {
	Slime slime = Slime();
	slime.attack(); // "Slime uses Gel Punch!"
}
```

### override
- Dart에서도 `오버라이딩`이 가능합니다. (메소드 호출시, 하위 클래스의 메소드를 우선함)
- `@override` 문구를 삽입해 오버라이딩을 명시할 수 있습니다. (해당 문구를 생략해도 동작은 동일합니다.)

```
class Monster {
	String name = 'unknowed';
	void attack() {
		print("$name uses Punch!");
	}
}

class Rogue extends Monster {
	Rogue() {
		name = 'Rogue';
	}
}

class Slime extends Monster {
	Slime() {
		name = 'Slime';
	}
	
	@override
	void attack() {
		print("$name uses Gel Punch!");
	}
}

void main() {
	Rogue rogue = Rogue();
	Slime slime = Slime();
	rogue.attack(); // "Rogue uses Punch!"
	slime.attack(); // "Slime uses Gel Punch!"
}
```

### static
- Dart에서 `static`은 일반적인 객체지향의 static과 동일합니다.
- static 프로퍼티/메소드는 같은 클래스에서 생성된 모든 인스턴스가 공유합니다.
- static 프로퍼티/메소드는 클래스 단위이며, 클래스 생성시 같이 생성됩니다. 접근 또한 인스턴스가 아닌, 클래스를 통해 접근합니다.

```
class Item {
	static String? tag;
	int? _atk;
	int? _def;
	
	static void changeTag(String t) {
		tag = t;
	}
}

void main(){
	Item.changeTag('item');
	print(Item.tag);
}
```

### enum
- `enum`은 상수들을 담을 수 있는 특별한 타입입니다. (일반적인 언어의 enum과 같습니다.)
- enum을 사용해 다수의 상수들을 효율적으로 관리할 수 있습니다.
- enum의 상수들은 `Enum` 객체 타입입니다.

```
enum Weapon {
	sword,
	lance,
	mace
}

void main() {
	print(Weapon.sword);
}
```

### abstract
- Dart에서는 `추상 클래스`를 사용할 수 있습니다.  (C++의 추상 클래스와 거의 같습니다.)
- 추상 클래스만으로는 인스턴스를 생성할 수 없으며, 추상 클래스를 상속하는 클래스를 통해서 인스턴스를 생성할 수 있습니다.
- 추상 클래스에서는 `추상 메소드`를 사용할 수 있습니다. 추상 메소드는 내용 없이 선언만 있으며, 실질적인 내용은 하위 클래스에서 오버라이딩될 때 작성됩니다.
	- 하위 클래스는 추상 클래스에 있는 모든 추상 메소드를 구현해야 합니다.
	- 일반 클래스에선 추상 메소드를 사용할 수 없습니다.

```
abstract class Monster {
	void attack();
	void dropItem();
}

class Slime extends Monster {
	@override
	void attack() {
		print("Slime uses Gel Punch!");
	}
	@override
	void dropItem() {
		print("Slime drops Slime Gel");
	}
}

void main() {
	Slime slime = Slime();
	slime.attack();
	slime.dropItem();
}
```

### implements
- Dart에서 클래스는 암시적으로 interface입니다.
- Dart에서 interface 키워드는 따로 존재하지 않으며, 대신 추상 클래스를 통해 인터페이스를 사용합니다.
- `implements` 키워드를 통해 인터페이스를 구현할 수 있습니다.

```
abstract class Monster {
	String? name;
	void attack();
}
abstract class Enemy {
	void dropItem();
}

class Slime implements Monster, Enemy {
	@override
	String? name = 'Slime';
	@override
	void attack() {
		print("$name uses Gel Punch!");
	}
	@override
	void dropItem() {
		print("$name drops Slime Gel");
	}
}

void main() {
	Slime slime = Slime();
	slime.attack();
	slime.dropItem();
}
```

- `implements`는 상위 클래스-하위 클래스가 존재한다는 점에서 `extends`하고 유사합니다. 하지만 몇몇 점에서 차이가 있습니다.

|extends|implements|
|---|---|
|상속(inherit) 용도로 사용됩니다.|인터페이스(interface) 용도로 사용됩니다.|
|상위 클래스는 1개만 가능합니다.|상위 클래스가 여러 개일 수 있습니다.|
|상위 클래스는 하위 클래스에게 완전한 메소드(선언, 내용)를 제공할 수 있습니다.|(상위 클래스가 완전한 메소드를 가지고 있어도) 상위 클래스는 하위 클래스에게 항상 추상 메소드를 제공합니다.| 
|모든 메소드/프로퍼티가 오버라이드되지 않을 수 있습니다.|모든 메소드/프로퍼티가 오버라이드되어야 합니다.|
|하위 클래스 생성자 호출 이전에 상위 클래스의 생성자가 호출됩니다.|하위 클래스 생성자가 호출되어도 상위 클래스 생성자는 호출되지 않습니다.|
|`super` 키워드를 사용할 수 있습니다.|`super` 키워드를 사용할 수 없습니다.|

### mixin
- Dart에서 `mixin`은 여러 클래스에서 코드를 재사용하는 용도로 사용됩니다.
- mixin가 적용된 클래스는 해당 mixin의 코드를 사용할 수 있습니다. (`with` 키워드 사용)
- mixin에선 프로퍼티 / 메소드, static 프로퍼티 / 메소드, 추상 메소드를 사용할 수 있습니다.
- mixin로 인스턴스를 생성할 수 없습니다.
- mixin은 생성자가 없으며, 상속 또한 불가능합니다.
- 한 클래스는 여러 개의 mixin을 적용할 수 있습니다.

```
mixin isArcher {
	int arrow = 0;
	void displayArrow () {
		print('arrow: $arrow');
	}
}

mixin isWizard {
	int mana = 0;
	void displayMana () {
		print('mana: $mana');
	}
}

class Player with isArcher, isWizard {
	
}

void main() {
	Player player = Player();
	player.displayArrow();
	player.displayMana();
}
```

- mixin에 `on` 키워드를 사용하면 특정 클래스(또는 이 클래스를 상속하는 하위 클래스)만 해당 mixin을 사용하게 됩니다.
- mixin에서 on으로 지정한 클래스의 메소드를 오버라이드할 수 있습니다.

```
class Human {
	String? name;
	Human(this.name);
}

mixin isArcher on Human {
	void arrowShot () {
		print('$name uses arrowShot!');
	}
}

mixin isWizard on Human {
	void fireball () {
		print('$name uses fireball!');
	}
}

class Player extends Human with isArcher, isWizard {
	Player(name) : super(name);
}

void main() {
	Player player = Player('Alex');
	player.arrowShot();
	player.fireball();
}
```

### factory constructor
- 일반적인 생성자는 항상 현재 클래스의 인스턴스를 반환하지만, `factory 생성자`는 해당 클래스 또는 하위 클래스의 인스턴스를 반환할 수 있으며, 반환할 인스턴스를 직접 지정할 수 있습니다.
- 생성자 앞에 `factory` 키워드를 붙이면 factory 생성자가 됩니다.
- factory 생성자는 반드시 `return`을 사용해서 특정 인스턴스를 반환해야 합니다.
- factory 생성자 내부에선 `this` 키워드를 사용할 수 없으며, 생성할 인스턴스의 프로퍼티에 접근할 수 없습니다.
- 일반 생성자와 factory 생성자의 이름은 서로 중복될 수 없습니다.
- factory 생성자는 주로 다음 용도로 활용됩니다.
	- `final` 프로퍼티의 초기화 전처리 과정을 넣을 수 있습니다.
	- 디자인 패턴 - `팩토리` 패턴을 구현할 수 있습니다. (파라미터를 통한 특정 하위 클래스 인스턴스 반환)
	- 디자인 패턴 - `싱글톤` 패턴을 구현할 수 있습니다. (객체가 단일 인스턴스만을 가짐)

```
enum EnemyType { slime, rogue }

abstract class Enemy {
	factory Enemy(EnemyType type) {
		switch (type) {
			case EnemyType.slime: return Slime();
			case EnemyType.rogue: return Rogue();
		}
	}
	void attack();
}

class Slime implements Enemy {
	@override
	void attack() {
		print('Slime uses Gel Punch!');
	}
}

class Rogue implements Enemy {
	@override
	void attack() {
		print('Rogue uses Punch!');
	}
}

void main() {
	// 팩토리 패턴
	Enemy enemy1 = Enemy(EnemyType.slime);
	Enemy enemy2 = Enemy(EnemyType.rogue);
	enemy1.attack(); // Slime uses Gel Punch!
	enemy2.attack(); // Rogue uses Punch!
}
```

```
class Singleton {
	static final Singleton _inst = Singleton._private();
 
	factory Singleton() {
		return _inst;
	}
	Singleton._private();
}

void main() {
	// 싱글톤 패턴
	Singleton inst1 = Singleton();
	Singleton inst2 = Singleton();
	print(inst1.hashCode);
	print(inst2.hashCode); // 같은 값이 출력됩니다. (단일 인스턴스)
}
```

### Generics
- `generics`은 타입별로 클래스/함수를 생성하는 방법입니다. (C++의 `템플릿`과 유사합니다.)
- generics은 각 클래스별 동작은 모두 동일하나, 데이터 타입만은 차별화해야 할 때 유용합니다. (주로 컨테이너 자료구조가 이에 해당합니다.)
- `List`, `Map`, `Set`도 generics을 사용합니다.
- 클래스/함수 이름 옆에 `<>`을 사용해서 generics을 넣을 수 있으며, `<>` 내부에 사용할 타입의 약칭을 추가할 수 있습니다.
- generics에 여러 개의 타입을 넣을 수 있습니다.

```
class Data<T> {
	T data;
	Data(this.data);
	void display() {
		print(data);
	}
}

void main() {
	Data<int> data1 = Data<int>(15);
	Data<String> data2 = Data<String>('item');
	data1.display();
	data2.display();
}
```

- `extends`를 사용하면 generics에 올 수 있는 타입을 제한할 수 있습니다. (설정한 타입과 그 타입의 하위 타입만이 올 수 있습니다.)

```
// num과 num의 하위 타입만 허용됩니다.
num adder<T extends num>(T a, T b) {
	return a + b;
}

void main() {
	print(adder<int>(10, 20)); // 30
	print(adder<double>(2.5, 6.5)); // 9.0
}
```

### Extension
- Dart 2.7.0에 새로 도입된 `Extension`은 기존에 존재하는 객체의 기능을 확장할 때 사용됩니다.

```
void main(){
	String name = "steve";
	print(name.doubleStr()); // stevesteve
}

extension StringExt on String{
	// 기존 String 객체에 새로운 메소드를 추가합니다.
	String doubleStr() {
		return this + this;
	}
}
```

## 비동기 (Asyncronous)
### Future
- `Future` 객체는 Dart에서 비동기 프로그래밍을 할 때 사용하며, 자바스크립트의 `Promise`와 유사합니다.
- Future마다 잠재적인 값을 가지고 있으며, 이 값은 비동기 연산의 결과로 설정됩니다. 이 값의 타입은 Future의 `generics`에 지정된 타입입니다.
- Future는 다음 메소드로 생성될 수 있습니다.

|메소드|기능|
|---|---|
|Future.delayed(`Duration`, `callback`)|`Duration`시간 이후에 주어진 콜백을 실행하고 값이 설정된 Future 반환|
|Future.value(`value`)|값이 설정된 Future 즉시 반환|

- Future는 2가지 상태를 갖습니다.
	- `Uncompleted`: 비동기 작업이 완료되지 않았거나 오류가 발생한 상태
	- `Completed`: 오류 없이 비동기 작업이 완료된 상태
- Future 인스턴스는 `then` 메소드를 사용할 수 있습니다. `then` 메소드는 콜백을 인자로 하며, Future 상태가 `Completed`이 되면 해당 콜백을 실행합니다.
	- 이 콜백은 Future의 잠재적 값을 인자로 가집니다.

```
Future<String> timer1() async {
	return Future.delayed(Duration(seconds: 2), () => 'Surprise!!');
}

Future<String> timer2() {
	return Future.value('BOOM!!');
}

void main() {
	print("Start");
	timer1().then((value) => print(value));
	timer2().then((value) => print(value));
	print("End");
}
```

```
// 실행 결과
Start
End
BOOM!!
Surprise!!
```

### async / await
- Dart에서 `async`, `await`는 자바스크립트의 `async`, `await`와 유사합니다.
- `async` 키워드는 `비동기 함수`를 정의할 때 사용됩니다.
- `비동기 함수`는 비동기로 실행되는 함수입니다.
- `await` 키워드는 특정 Future의 작업이 완료될 때까지 런타임 실행을 미루며, 작업이 끝나면 해당 Future의 잠재적 값을 반환합니다. `await`는 비동기 함수 내부에서만 효과가 있습니다.

```
Future<String> getFuture() {
	return Future.delayed(Duration(seconds: 2), () => 'Surprise!!');
}

void timer() async {
	print("Start");
	String res = await getFuture();
	print(res);
	print("End");
}

void main() {
	timer();
}
```

```
// 실행 결과
Start
Surprise!!
End
```

### Stream
- Dart에서 `Stream` 객체는 비동기 이벤트나 여러 개의 `Future`를 다룰 때 자주 사용됩니다.
- Stream도 잠재적 값을 가지며, 이 값은 비동기 작업 중간에 달라질 수 있습니다.
- Stream은 여러가지 방법으로 생성할 수 있습니다. (아래는 `Iterable` 사용)
	- `async*` 함수를 사용해서 Stream을 생성할 수 있습니다. `async*` 함수에서 사용 가능한 `yield` 키워드는 Stream의 값을 변경합니다. (`yield`는 Iterable에서 값을 생성할 때도 사용됩니다.)
	- `yield*`은 Iterable이나 Stream을 반환하는 함수를 호출할 때 사용됩니다.
	- `Stream.fromIterable` 메소드로 즉시 Stream을 생성할 수 있습니다.
- Stream은 반복문으로 통해 사용 가능합니다.

```
Stream<int> timer1() async* {
	await Future.delayed(Duration(seconds: 1));
	yield 3;
	await Future.delayed(Duration(seconds: 1));
	yield 2;
	await Future.delayed(Duration(seconds: 1));
	yield 1;
}

Stream<int> timer2() {
	return Stream.fromIterable([3, 2, 1]);
}

void main() async {
	print('Start');
	await for (int n in timer1()) {
		print(n);
	}
	print('End');
}
```

```
// 실행 결과
Start
3
2
1
End
```

## 출처 (Reference)
https://dart-tutorial.com/
