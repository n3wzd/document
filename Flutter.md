# Flutter
`Flutter`는 Android, iOS 앱을 구축할 수 있는 2018년에 출시된 Google의 모바일 UI 프레임워크 SDK입니다. 언어는 `Dart`를 사용합니다.

Flutter는 다음과 같은 이점이 있습니다.
- 단일 코드베이스
- 네이티브 앱
- 유연한 UI
- 재사용 가능한 로직
- 높은 호환성
- 고성능 및 빠른 개발
- 적은 시스템 리소스 소모
- Hot Reload (컴파일 없이 변경사항 확인 가능)

## 아키텍처 (Architecture)
### 위젯 (Widget)
`위젯`은 Flutter 애플리케이션을 구성하는 기본 요소입니다. 모든 Flutter 애플리케이션은 트리 구조의 위젯들로 구성되어 있으며, 위젯은 또다른 위젯으로 구성될 수 있습니다. 위젯에서 UI와 애플리케이션의 속성을 설정할 수 있습니다.

### 레이어 (Layer)
Fluttet 프레임워크는 복잡성에 따라 간단하게 3가지 `레이어`로 분류할 수 있습니다. (아래로 갈수록 복잡도가 감소합니다.)
1. OS (Android / iOS)
2. 기본 Flutter 위젯
3. 표시되는 UI / 상태 렌더링

### 제스처 (Gesture)
`제스처`는 Flutter 애플리케이션과 관련된 모든 물리적 형태의 상호 작용(탭, 드래그 등)을 처리하는 보이지 않는 위젯입니다.

### 상태 (State)
`상태`는 위젯의 속성이 가지고 있는 개체의 데이터를 저장합니다. Flutter 애플리케이션의 상태가 변경될 때마다 해당 상태와 관련된 위젯이 다시 렌더링됩니다.

## 위젯 (Widget)
### 상태 비저장 위젯 (Stateless Widgets)
- `상태 비저장 위젯(Stateless Widgets)`은 런타임 중간에 상태를 변경할 수 없는 위젯입니다. 즉, 빌드 이후에는 상태가 변경되지 않습니다.
- 상태 비저장 위젯은 `build()` 메소드를 오버라이드해야 합니다. 이 메소드는 `BuildContext`을 인자로 하며, 위젯을 반환합니다. 여기서 `BuildContext`은 위젯 트리 내에서 위젯을 찾는데 사용됩니다.
- 아이콘, 텍스트 등이 상태 비저장 위젯에 해당됩니다.

```
import 'package:flutter/material.dart';

void main() => runApp(const MyApp());

// Stateless Widget을 생성합니다.
class MyApp extends StatelessWidget {
	const MyApp({Key? key}) : super(key: key);
	
	@override
	Widget build(BuildContext context) {
		return Container();
	}
}
```

UI에 디자인을 추가해봅시다. 아래 코드는 'Stateless Widget'를 출력합니다.
```
import 'package:flutter/material.dart';

void main() => runApp(const MyApp());

class MyApp extends StatelessWidget {
	const MyApp({Key? key}) : super(key: key);
  
	@override
	Widget build(BuildContext context) {
		return MaterialApp(
			debugShowCheckedModeBanner: false,
			home: Scaffold(
				backgroundColor: const Color.fromARGB(255, 217, 249, 255),
				appBar: AppBar(
					leading: const Icon(Icons.menu),
					backgroundColor: Colors.blue,
					title: const Text(
					    "MyApp",
						textAlign: TextAlign.start,
					),
				),
				body: const Center(
				child: Text(
					"Stateless Widget",
					style: TextStyle(color: Colors.black, fontSize: 30),
					),
				),
			),
		);
	}
}
```

### 상태 저장 위젯 (Stateful Widgets)
- `상태 저장 위젯(Stateful Widgets)`은 빌드 이후에도 상태가 변경될 수 있는 위젯입니다.
- 상태 저장 위젯은 `createState()` 메소드를 오버라이드해야 합니다. 이 메소드는 상태를 반환합니다.
- `상태(State)`는 위젯의 속성이 가지고 있는 개체의 데이터를 저장합니다.
- 상태는 `build()` 메소드를 오버라이드해야 합니다. (상태 비저장 위젯의 `build()`와 같습니다.)

```
import 'package:flutter/material.dart';
 
void main() => runApp(const MyApp());

// Stateful Widget을 생성합니다.
class MyApp extends StatefulWidget {
	const MyApp({Key? key}) : super(key: key);
 
	@override
 	MyAppState createState() => MyAppState();
}
 
// MyApp 위젯의 State을 생성합니다.
class MyAppState extends State<MyApp> {
	@override
 	Widget build(BuildContext context) {
		return Container();
	}
}
```

UI에 디자인을 추가해봅시다. 아래 코드는 'Stateful Widget'를 출력합니다.
```
import 'package:flutter/material.dart';

void main() => runApp(const MyApp());

class MyApp extends StatefulWidget {
	const MyApp({Key? key}) : super(key: key);

	@override
	MyAppState createState() => MyAppState();
}

class MyAppState extends State<MyApp> {
	@override
	Widget build(BuildContext context) {
		return MaterialApp(
			debugShowCheckedModeBanner: false,
			home: Scaffold(
				backgroundColor: const Color.fromARGB(255, 217, 249, 255),
				appBar: AppBar(
					leading: const Icon(Icons.menu),
					backgroundColor: Colors.blue,
					title: const Text(
					    "MyApp",
						textAlign: TextAlign.start,
					),
				),
				body: const Center(
				child: Text(
					"Stateful Widget",
					style: TextStyle(color: Colors.black, fontSize: 30),
					),
				),
			),
		);
	}
}
```

### 컨테이너 (Container)
- Flutter의 `컨테이너(Container)`는 위젯의 UI, 위치, 크기를 제어하는 위젯입니다.
- 컨테이너는의 구조는 `HTML`의 `박스 모델(Box Model)`와 거의 유사합니다.

```
|-Container----------------------------|
|    margin                            |
|     |--border--------------------|   |
|     |      padding               |   |
|     |           child            |   |
|     |                            |   |
|     |----------------------------|   |
|                                      |
|--------------------------------------|
```

- 대표적인 컨테이너의 프로퍼티는 다음과 같습니다.

|프로퍼티|타입|의미|
|---|---|---|
|child|Widget|자식 위젯|
|color|Color|컨테이너 배경색|
|width|double|컨테이너 너비|
|height|double|컨테이너 높이|
|margin|EdgeInsetsGeometry|컨테이너를 둘러싼 여백|
|padding|EdgeInsetsGeometry|border와 child간 여백|
|alignment|AlignmentGeometry|child의 정렬 방식|
|decoration|Decoration|컨테이너 데코레이션(border 추가 등)|
|transform|Matrix4|컨테이너 변형(회전 등)|

```
Container({Key key,
	Widget child, 
	Color color, 
	double width, 
	double height, 
	EdgeInsetsGeometry margin, 
	EdgeInsetsGeometry padding, 
	AlignmentGeometry alignment, 
	Decoration decoration, 
	Matrix4 transform, 
});
```

## 출처 (Reference)
https://www.geeksforgeeks.org/flutter-tutorial/

