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
`위젯(Widget)`은 Flutter 애플리케이션을 구성하는 기본 요소입니다. 모든 Flutter 애플리케이션은 트리 구조의 위젯들로 구성되어 있으며, 위젯은 또다른 위젯으로 구성될 수 있습니다. 위젯에서 UI와 애플리케이션의 속성을 설정할 수 있습니다.

### 레이어 (Layer)
Fluttet 프레임워크는 복잡성에 따라 간단하게 3가지 `레이어(Layer)`로 분류할 수 있습니다. (아래로 갈수록 복잡도가 감소합니다.)
1. OS (Android / iOS)
2. 기본 Flutter 위젯
3. 표시되는 UI / 상태 렌더링

### 제스처 (Gesture)
`제스처(Gesture)`는 Flutter 애플리케이션과 관련된 모든 물리적 형태의 상호 작용(탭, 드래그 등)을 처리하는 보이지 않는 위젯입니다.

### 상태 (State)
`상태(State)`는 위젯의 속성이 가지고 있는 개체의 데이터를 저장하는 클래스입니다. Flutter 애플리케이션의 상태가 변경될 때마다 해당 상태와 관련된 위젯이 다시 렌더링됩니다.

## 위젯 (Widget)
### Stateless Widget
- `Stateless Widget`은 런타임 중간에 상태를 변경할 수 없는 위젯입니다. 즉, 빌드 이후에는 상태가 변경되지 않습니다.
- Stateless Widget은 `build()` 메소드를 오버라이드해야 합니다. 이 메소드는 `BuildContext`을 인자로 하며, 위젯을 반환합니다. 여기서 `BuildContext`은 위젯 트리 내에서 위젯을 찾는데 사용됩니다.
- 아이콘, 텍스트 등이 Stateless Widget에 해당됩니다.

```
import 'package:flutter/material.dart';

void main() => runApp(const MyApp());

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

### Stateful Widget
- `Stateful Widget`은 빌드 이후에도 상태가 변경될 수 있는 위젯입니다.
- Stateful Widget은 `createState()` 메소드를 오버라이드해야 합니다. 이 메소드는 상태를 반환합니다.
- `State`은 위젯의 속성이 가지고 있는 개체의 데이터를 저장합니다.
- 상태는 `build()` 메소드를 오버라이드해야 합니다. (Stateless Widget의 `build()`와 같습니다.)

```
import 'package:flutter/material.dart';
 
void main() => runApp(const MyApp());

class MyApp extends StatefulWidget {
	const MyApp({Key? key}) : super(key: key);
 
	@override
 	_MyAppState createState() => _MyAppState();
}
 
class _MyAppState extends State<MyApp> {
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
	_MyAppState createState() => _MyAppState();
}

class _MyAppState extends State<MyApp> {
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

### Container
- `Container`는 위젯의 UI, 위치, 크기를 제어하는 위젯입니다.
- Container의 구조는 `HTML`의 `Box Model`하고 유사합니다.

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

|프로퍼티|타입|의미|
|---|---|---|
|child|Widget|하위 위젯|
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

### Scaffold
- `Scaffold`는 앱의 기본 디자인 레이아웃을 제공하는 위젯입니다.

```
|-----------------|
|    appbar       |
|-----------------|
|                 |
|    content      |
|                 |
|                 |
|           float |
|-----------------|
| bottomBar       |
|-----------------|
```

|프로퍼티|타입|의미|
|---|---|---|
|appbar|PreferredSizeWidget|상단 바|
|body|Widget|주 내용|
|floatingActionButton|Widget|우측 하단 코너의 버튼|
|drawer|Widget|슬라이드 메뉴/패널|
|bottomNavigationBar|Widget|하단 메뉴|
|backgroundColor|Color|스캐폴드 배경색|

```
Scaffold({Key key,
	AppBar appBar, 
	Center body,
	FloatingActionButton floatingActionButton, 
	Drawer drawer,
	BottomNavigationBar bottomNavigationBar, 
});
```

### MaterialApp
- `MaterialApp`은 `매터리얼 위젯(Material widget)`들을 감싸는(wrap) 위젯입니다.  MaterialApp을 통해서 MaterialApp에 감싸진 위젯에 접근할 수 있습니다.
- 일부 위젯은 MaterialApp으로 감싸져야 동작합니다. (ex. `Scaffold`)

|프로퍼티|타입|의미|
|---|---|---|
|backButtonDispatcher|BackButtonDispatcher|이전 버튼을 누를 때 일어나는 동작|
|color|Color|애플리케이션 색|
|darkTheme|ThemeData|다크 모드 사용시 적용되는 테마|
|debugShowCheckedModeBanner|bool|디버그시 앱 상단 DEBUG 배너 표시 유무|
|debugShowMaterialGrid|bool|그리드 오버레이 표시 유무|
|home|Widget|앱의 기본 루트(default route)일 때 표시되는 위젯|
|locale|Locale|앱의 초기 로케일|
|title|String|디바이스에 표시되는 앱의 1줄 설명문|

```
import 'package:flutter/material.dart';

void main() { runApp(const MyApp()); }

class MyApp extends StatelessWidget {
	const MyApp({Key? key}) : super(key: key);

	// 이 MaterialApp은 Scaffold를 감쌉니다.
	@override
	Widget build(BuildContext context) {
		return MaterialApp(
			title: 'MyApp',
			home: Scaffold(
				appBar: AppBar(title: const Text('MyApp')),
			),
		);
	}
}
```

### AppBar
- `AppBar`는 앱 상단 메뉴를 표시하는 위젯입니다.
- Scaffold의 `appBar` 프로퍼티에 적용할 수 있습니다.

|프로퍼티|타입|의미|
|---|---|---|
|backgrounColor|Color|메뉴바 색상|
|leading|Widget|title 이전에 표시되는 위젯|
|title|Widget|메뉴바 제목으로 표시되는 위젯|

```
import 'package:flutter/material.dart';

void main() => runApp(const MyApp());

class MyApp extends StatelessWidget {
	const MyApp({Key? key}) : super(key: key);
  
	@override
	Widget build(BuildContext context) {
		return MaterialApp(
			home: Scaffold(
				appBar: AppBar(
					leading: const Icon(Icons.menu),
					backgroundColor: Colors.blue,
					title: const Text(
					    "MyApp",
						textAlign: TextAlign.start,
					),
				),
			),
		);
	}
}
```

### BottomNavigationBar
- `BottomNavigationBar`는 앱 하단 메뉴를 표시하는 위젯입니다.
- Scaffold의 `bottomNavigationBar` 프로퍼티에 적용할 수 있습니다.

|프로퍼티|타입|의미|
|---|---|---|
|backgrounColor|Color|메뉴바 색상|
|currentIndex|int|현재 아이템 인덱스|
|iconSize|double|아이콘 크기|
|selectedFontSize|double|선택된 아이템 폰트 크기|
|selectedIconColor|Color|선택된 아이템 색상|
|items|List\<BottomNavigationBarItem\>|메뉴 아이템 목록|
|onTap|ValueChanged\<int\>|아이템을 선택할 때 호출되는 메소드|

다음 예제는 3가지 아이템(Home, Business, School)을 가지는 메뉴 바를 포함합니다. 메뉴 바의 아이템을 선택하면 메인 화면에 표시되는 텍스트가 달라집니다.
```
import 'package:flutter/material.dart';

void main() => runApp(const MyApp());

class MyApp extends StatefulWidget {
	const MyApp({super.key});

	@override
	State<MyApp> createState() => _MyAppState();
}

class _MyAppState extends State<MyApp> {
	int _selectedIndex = 0;
	static const List<Widget> contents = <Widget>[
		Text('0. Home'),
		Text('1. Business'),
		Text('2. School'),
	];

	void _onItemTapped(int index) {
		setState(() {
			_selectedIndex = index;
		});
	}

	@override
	Widget build(BuildContext context) {
		return MaterialApp(
			home: Scaffold(
				body: Center(child: contents[_selectedIndex]),
				bottomNavigationBar: BottomNavigationBar(
					items: const <BottomNavigationBarItem>[
						BottomNavigationBarItem(
							icon: Icon(Icons.home),
							label: 'Home',
						),
						BottomNavigationBarItem(
							icon: Icon(Icons.business),
							label: 'Business',
						),
						BottomNavigationBarItem(
							icon: Icon(Icons.school),
							label: 'School',
						),
					],
					currentIndex: _selectedIndex,
					selectedItemColor: Color.fromARGB(255, 79, 205, 255),
					onTap: _onItemTapped,
				),
			),
		);
	}
}
```

### Drawer
- `Drawer`는 Scaffold 모서리에서 수평으로 슬라이드하면 나타나는 매터리얼 디자인 패널 위젯입니다.
- Scaffold의 `drawer` 프로퍼티에 적용할 수 있습니다.

|프로퍼티|타입|의미|
|---|---|---|
|child|Widget|하위 위젯|

```
import 'package:flutter/material.dart';

void main() => runApp(const MyApp());

class MyApp extends StatelessWidget {
	const MyApp({Key? key}) : super(key: key);
 
	@override
	Widget build(BuildContext context) {
		return MaterialApp(
			home: Scaffold(
				appBar: AppBar(
					backgroundColor: Colors.green,
				),
				drawer: Drawer(
					child: ListView(
						children: [
							const DrawerHeader(
								decoration: BoxDecoration(
									color: Colors.green,
								),
								child: Text(
									"Drawer",
									style: TextStyle(fontSize: 30.0, color: Colors.white),
								),
							),
							ListTile(
								leading: const Icon(Icons.person),
								title: const Text('Profile'),
							),
							ListTile(
								leading: const Icon(Icons.book),
								title: const Text('Information'),
							),
							ListTile(
								leading: const Icon(Icons.logout),
								title: const Text('LogOut'),
							),
						],
					),
				),
			),
		);
	}
}
```

### ClipRect
- `ClipRect`는 사각형 클립을 제공하는 위젯입니다.

|프로퍼티|타입|의미|
|---|---|---|
|child|Widget|하위 위젯|

```
import 'package:flutter/material.dart';

void main() => runApp(const MyApp());

class MyApp extends StatelessWidget {
	const MyApp({Key? key}) : super(key: key);
	
	@override
	Widget build(BuildContext context) {
		return MaterialApp(
			home: Scaffold(
				body: ClipRect(
					child: Container(
						height: 200,
						width: 200,
						color: Colors.yellow,
					),
				),
			),
		);
	}
}
```

### ClipRRect
- `ClipRRect`는 모서리가 둥근 사각형 클립을 제공하는 위젯입니다.

|프로퍼티|타입|의미|
|---|---|---|
|child|Widget|하위 위젯|
|borderRadius|BorderRadiusGeometry|모서리 반지름|

```
import 'package:flutter/material.dart';

void main() => runApp(const MyApp());

class MyApp extends StatelessWidget {
	const MyApp({Key? key}) : super(key: key);
	
	@override
	Widget build(BuildContext context) {
		return MaterialApp(
			home: Scaffold(
				body: ClipRRect(
					child: Container(
						height: 200,
						width: 200,
						color: Colors.yellow,
					),
					borderRadius: BorderRadius.circular(30.0),
				),
			),
		);
	}
}
```

### Opacity
- `Opacity`는 투명도를 제공하는 위젯입니다.
- 투명도 값 범위는 \[0.0, 1.0\]입니다.

|프로퍼티|타입|의미|
|---|---|---|
|child|Widget|하위 위젯|
|opacity|double|투명도|

```
import 'package:flutter/material.dart';

void main() => runApp(const MyApp());

class MyApp extends StatelessWidget {
	const MyApp({Key? key}) : super(key: key);
	
	@override
	Widget build(BuildContext context) {
		return MaterialApp(
			home: Scaffold(
				body: Opacity(
					child: Image.network('https://storage.googleapis.com/cms-storage-bucket/a40ceb6e5d342207de7b.png'),
					opacity: 0.5,
				),
			),
		);
	}
}
```

## 출처 (Reference)
https://www.geeksforgeeks.org/flutter-tutorial/

https://api.flutter.dev/index.html
