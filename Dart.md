# Dart
Google에서 개발된 `Dart`는 다양한 플랫폼(Android, iOS, 웹 등)에서 빠르게 앱을 개발할 수 있는 클라이언트 최적화, 객체 지향 프로그래밍 언어입니다.

- 무료이며 오픈소스입니다.
- 네이티브 코드 및 `Javascript` 컴파일이 가능합니다. 실제로 Dart는 자바스크립트와 비슷한 점이 많습니다.
- Dart를 사용하는 대표적인 프레임워크로 `Flutter`가 있습니다.
- 백엔드 분야에서도 사용할 수 있습니다.

## 기초 (Basic)
- 모든 프로그램은 `main` 함수로 시작됩니다.
- 모든 구문의 끝은 세미콜론 `;`으로 끝납니다.
- 중괄호`{}`를 사용해  블록 구간을 표현합니다.
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
- Dart에서 변수는 선언 동시 초기화가 가능합니다.
- Dart에서 변수의 생성 및 이름 규칙은 자바스크립트와 거의 동일합니다.

```
var cnt = 0;
String name = "Steve";
num level = 1;
bool flag = true;
```

- Dart에서 키워드 `const`를 사용해 `상수(constant)`를 선언할 수 있습니다. 상수는 초기화 이후에 값을 변경할 수 없습니다.

```
const MAX_LENGTH = 10;
```

### 데이터 타입 (Data Types)
- Dart에서 값의 유형은 다음이 있습니다.

|분류|
|---|---|---|
Number
String
3. Boolean
4. List
5. Map
6. Set
7. Rune
8. Null

#### Number
- 

## 출처 (Reference)
https://dart-tutorial.com/
