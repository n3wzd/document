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

![](images/Flutter-Widget-StatelessWidget.png)

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

![](images/Flutter-Widget-StatefulWidget.png)

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

|파라미터|타입|의미|
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

|파라미터|타입|의미|
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

|파라미터|타입|의미|
|---|---|---|
|home|Widget|앱의 기본 루트(default route)일 때 표시되는 위젯|
|title|String|디바이스에 표시되는 앱의 1줄 설명문|
|color|Color|애플리케이션 색|
|debugShowCheckedModeBanner|bool|디버그시 앱 상단 DEBUG 배너 표시 유무|

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
- Scaffold의 `appBar` 파라미터에 적용할 수 있습니다.

|파라미터|타입|의미|
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

![](images/Flutter-Widget-AppBar.png)

### BottomNavigationBar
- `BottomNavigationBar`는 앱 하단 메뉴를 표시하는 위젯입니다.
- Scaffold의 `bottomNavigationBar` 파라미터에 적용할 수 있습니다.

|파라미터|타입|의미|
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

![](images/Flutter-Widget-BottomNavigationBar.png)

### Drawer
- `Drawer`는 Scaffold 모서리에서 수평으로 슬라이드하면 나타나는 매터리얼 디자인 패널 위젯입니다.
- Scaffold의 `drawer` 파라미터에 적용할 수 있습니다.

|파라미터|타입|의미|
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

![](images/Flutter-Widget-Drawer.png)

### ClipRect
- `ClipRect`는 사각형 클립을 제공하는 위젯입니다.

|파라미터|타입|의미|
|---|---|---|
|child|Widget|하위 위젯|

```
ClipRect(
	child: Container(
		height: 200,
		width: 200,
		color: Colors.yellow,
	),
),
```

![](images/Flutter-Widget-ClipRect.png)

### ClipRRect
- `ClipRRect`는 모서리가 둥근 사각형 클립을 제공하는 위젯입니다.

|파라미터|타입|의미|
|---|---|---|
|child|Widget|하위 위젯|
|borderRadius|BorderRadiusGeometry|모서리 반지름|

```
ClipRRect(
	child: Container(
		height: 200,
		width: 200,
		color: Colors.yellow,
	),
	borderRadius: BorderRadius.circular(30.0),
);
```

![](images/Flutter-Widget-ClipRRect.png)

### Opacity
- `Opacity`는 투명도를 제공하는 위젯입니다.
- 투명도 값 범위는 \[0.0, 1.0\]입니다.

|파라미터|타입|의미|
|---|---|---|
|child|Widget|하위 위젯|
|opacity|double|투명도|

```
Opacity(
	child: Image.network(...),
	opacity: 0.5,
),
```

![](images/Flutter-Widget-Opacity.png)

### RichText
- `RichText`는 텍스트를 꾸미는 위젯입니다.

|파라미터|타입|의미|
|---|---|---|
|text|InlineSpan|텍스트 위젯|
|textAlign|TextAlign|텍스트 정렬 방식|
|textDirection|TextDirection|텍스트 방향|
|selectionColor|Color|텍스트 선택시 색상|
|maxLines|int|텍스트 최대 라인 개수|

```
RichText(
  text: const TextSpan(text: 'Hello'),
  selectionRegistrar: SelectionContainer.maybeOf(context),
  selectionColor: const Color(0xAF6694e8),
)
```

## UI Components
### AlertDialog
- `AlertDialog`는 경고 메시지 창을 표시하는 위젯입니다.

|파라미터|타입|의미|
|---|---|---|
|actions|List\<Widget\>|창 하단에 표시되는 액션 목록|
|title|Widget|창 상단에 표시되는 제목|
|content|Widget|창 메시지 내용|

```
AlertDialog(
	title: const Text("Alert Dialog Box"),
	content: const Text("This is Alert Dialog Box"),
	actions: <Widget>[
		TextButton(
			onPressed: () {
				Navigator.of(ctx).pop();
			},
            child: Container(
                color: Color.fromARGB(255, 204, 253, 255),
                padding: const EdgeInsets.all(14),
                child: const Text("ok"),
			),
		),
	],
),
```

### SimpleDialog
- `SimpleDialog`는 여러 선택지를 포함한 메시지 창을 표시하는 위젯입니다.

|파라미터|타입|의미|
|---|---|---|
|actions|List\<Widget\>|선택지 목록|
|title|Widget|창 상단에 표시되는 제목|

```
SimpleDialog(
	title:const Text('Simple Dialog Box'),
	children: <Widget>[
		SimpleDialogOption(
			onPressed: () { },
			child:const Text('Option 1'),
		),
		SimpleDialogOption(
			onPressed: () { },
			child: const Text('Option 2'),
		),
	],
),
```

### showDialog
- `showDialog`는 Dialog를 표시해주는 함수입니다. `AlertDialog`, `SimpleDialog`를 사용하려면 `showDialog`을 호출하면 됩니다.

|파라미터|타입|의미|
|---|---|---|
|context|BuildContext|`showDialog`를 호출한 위젯의 BuildContext|
|Builder|WidgetBuilder|빌드 메소드|

```
showDialog(
	context: context,
	builder: (BuildContext context) {
		return Expanded(
	        child: AlertDialog(
	            ...
			),
		);
	},
);
```

### Icon
- `Icon`은 아이콘을 관리하는 위젯입니다.
- `Icon` 생성자의 1번째 파라미터는 아이콘 종류를 인자로 합니다.  아이콘 종류는 `Icons`에서 가져올 수 있습니다.

|파라미터|타입|의미|
|---|---|---|
|size|double|아이콘 크기|
|color|Color|아이콘 색|

```
Icon(
	Icons.favorite,
	color: Colors.yellow,
	size: 20.0,
),
```

### Expanded
- `Expanded`는 flex 레이아웃을 제공하는 위젯입니다.
- flex 레이아웃은 해당 위젯이 스크린 너머로 초과하는 것을 자동으로 방지해줍니다.
- 여러 아이템들이 행 또는 열을 이룰 때, flex 값은 각 아이템들이 상대적으로 차지하는 공간을 결정합니다. 만약 아이템 A의 flex가 2, 아이템 B의 flex가 1이면, A와 B는 2:1 크기 비율로 공간을 차지합니다.

```
A.flex = 2, B.flex = 1
|----A----|--B--|
```

|파라미터|타입|의미|
|---|---|---|
|flex|int|flex 값|
|child|Widget|하위 위젯|

```
Expanded(
	flex: 2,
	child: Container(
		color: Colors.amber,
		height: 100,
	),
 ),
```

### CircularProgressIndicator
- `CircularProgressIndicator`는 원형 모양의 진행도를 표시하는 위젯입니다.
- 진행도 위젯은 2가지 타입을 가지고 있습니다.
	- `indeterminate`: 진행도가 특정 값을 가지지 않습니다. (진행 상태만 파악할 수 있습니다.)
	- `determinate`: 진행도가 특정 값을 가집니다. 진행도 값 범위는 \[0.0, 1.0\]입니다.

|파라미터|타입|의미|
|---|---|---|
|backgroundColor|Color|도형 색|
|strokeWidth|double|도형 두께|
|value|dobule|값이 `null`이면 `indeterminate`, 그렇지 않으면 `determinate`|

```
CircularProgressIndicator(
	backgroundColor: Colors.blue,
	strokeWidth: 10,
	value: null,
),
```

### LinearProgressIndicator
- `LinearProgressIndicator`는 선형 모양의 진행도를 표시하는 위젯입니다.
- 이 외는 `CircularProgressIndicator`와 동일합니다.

```
LinearProgressIndicator(
	backgroundColor: Colors.green,
	strokeWidth: 10,
	value: null,
),
```

### DefaultTabController
- `DefaultTabController`는 탭 목록을 관리하는 위젯입니다.

|파라미터|타입|의미|
|---|---|---|
|child|Widget|하위 위젯|
|length|int|탭 개수|

```
DefaultTabController(
	length: 5,
	child: Scaffold(
		appBar: AppBar(
			bottom: const TabBar(
				tabs: [
					Tab(icon: Icon(Icons.music_note)),
					Tab(icon: Icon(Icons.music_video)),
					Tab(icon: Icon(Icons.camera_alt)),
					Tab(icon: Icon(Icons.grade)),
					Tab(icon: Icon(Icons.email)),
				],
			),
		),
	),
);
```

### TabBar
- `TabBar`는 탭 목록을 표시하는 위젯입니다.
- `DefaultTabController`의 `child`에 `TabBar`를 추가해서 탭 목록을 앱에 넣을 수 있습니다.

|파라미터|타입|의미|
|---|---|---|
|tabs|List\<Widget\>|탭 위젯|

### ListView
- `ListView`는 스크롤 가능한 리스트를 표시하는 위젯입니다.
- 일반적으로 `ListView`의 `child` 위젯은 스크린에 표시될 때만 오브젝트가 존재합니다. 즉, `ListView` 아이템이 스크롤되어 스크린에 표시되면 해당 아이템의 오브젝트가 생성되고, 스크린에서 사라지면 해당 오브젝트가 소멸됩니다.
- `ListView`의 기본 생성자는 사용 가능한 모든 아이템을 한꺼번에 빌드를 수행합니다. 리스트의 아이템 개수가 적다면 기본 생성자가 적합합니다.
	- `children` 파라미터를 통해 모든 아이템을 나열합니다.

|파라미터|타입|의미|
|---|---|---|
|children|List\<Widget\>|리스트 아이템 목록|
|scrollDirection|Axis|스크롤 방향|
|padding|EdgeInsetsGeometry|아이템간 간격|

```
ListView(
	scrollDirection: Axis.horizontal,
	padding: const EdgeInsets.all(4),
	children: <Widget>[
		Container(
			...
		),
		Container(
			...
		),
	],
)
```

- `ListView.builder` 생성자는 실제로 스크린에 표시되는 아이템만 빌드합니다. 리스트 아이템 개수가 많다면 `builder` 생성자가 적합합니다.
	- `itemBuilder` 파라미터를 통해 아이템 틀을 작성합니다. `itemBuilder`는 함수를 값으로 하며, 이 함수는 `BuildContext`와 현재 아이템의 인덱스를 의미하는 `int` 파라미터를 갖습니다.

|파라미터|타입|의미|
|---|---|---|
|itemCount|int|아이템 개수|
|scrollDirection|Axis|스크롤 방향|
|padding|EdgeInsetsGeometry|아이템간 간격|

```
ListView.builder(
	padding: const EdgeInsets.all(8),
	itemCount: 10,
	itemBuilder: (BuildContext context, int index) {
		return Container(
			...
		);
	}
);
```

## Design & Animations

## 출처 (Reference)
https://www.geeksforgeeks.org/flutter-tutorial/

https://api.flutter.dev/index.html