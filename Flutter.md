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

## Architecture
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

## Widget
### Stateless Widget
- `Stateless Widget`은 런타임 중간에 상태를 변경할 수 없는 위젯입니다. 즉, 빌드 이후에는 상태가 변경되지 않습니다.
- `Stateless Widget`은 `build()` 메소드를 오버라이드해야 합니다. 이 메소드는 `BuildContext`을 인자로 하며, 위젯을 반환합니다. 여기서 `BuildContext`은 위젯 트리 내에서 위젯을 찾는데 사용됩니다.
- 아이콘, 텍스트 등이 `Stateless Widget`에 해당됩니다.

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

### Stateful Widget
- `Stateful Widget`은 빌드 이후에도 상태가 변경될 수 있는 위젯입니다.
- `Stateful Widget`은 `createState()` 메소드를 오버라이드해야 합니다. 이 메소드는 상태를 반환합니다.
- `State`은 위젯의 속성이 가지고 있는 개체의 데이터를 저장합니다.
- 상태는 `build()` 메소드를 오버라이드해야 합니다. (`Stateless Widget`의 `build()`와 같습니다.)

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

```
Container(
	height: 200,
	width: 200,
	color: Colors.yellow,
),
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
Scaffold(
	backgroundColor: const Color.fromARGB(255, 217, 249, 255),
	appBar: AppBar(
		...
	),
	body: const Center(
		child: Text(...)
	),
)
```

### MaterialApp
- `MaterialApp`은 `매터리얼 위젯(Material widget)`들을 감싸는(wrap) 위젯입니다. `MaterialApp`을 통해서 `MaterialApp`의 하위 위젯에 접근할 수 있습니다.
- 일부 위젯은 `MaterialApp`을 조상 위젯으로 요구합니다. (ex. `Scaffold`)

|파라미터|타입|의미|
|---|---|---|
|home|Widget|앱의 기본 루트(default route)일 때 표시되는 위젯|
|title|String|디바이스에 표시되는 앱의 1줄 설명문|
|color|Color|애플리케이션 색|
|debugShowCheckedModeBanner|bool|디버그시 앱 상단 DEBUG 배너 표시 유무|

```
MaterialApp(
	debugShowCheckedModeBanner = false,
	title: 'MyApp',
	home: Scaffold(
		...
	),
);
```

### AppBar
- `AppBar`는 앱 상단 메뉴를 표시하는 위젯입니다.
- `Scaffold`의 `appBar` 파라미터에 적용할 수 있습니다.

|파라미터|타입|의미|
|---|---|---|
|backgrounColor|Color|메뉴바 색상|
|leading|Widget|title 이전에 표시되는 위젯|
|title|Widget|메뉴바 제목으로 표시되는 위젯|

```
AppBar(
	leading: const Icon(Icons.menu),
	backgroundColor: Colors.blue,
	title: const Text(
	    "MyApp",
		textAlign: TextAlign.start,
	),
),
```

### BottomNavigationBar
- `BottomNavigationBar`는 앱 하단 메뉴를 표시하는 위젯입니다.
- `Scaffold`의 `bottomNavigationBar` 파라미터에 적용할 수 있습니다.

|파라미터|타입|의미|
|---|---|---|
|backgrounColor|Color|메뉴바 색상|
|currentIndex|int|현재 아이템 인덱스|
|iconSize|double|아이콘 크기|
|selectedFontSize|double|선택된 아이템 폰트 크기|
|selectedIconColor|Color|선택된 아이템 색상|
|items|List\<BottomNavigationBarItem\>|메뉴 아이템 목록|
|onTap|ValueChanged\<int\>|아이템을 선택할 때 호출되는 메소드|

```
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
```

### Drawer
- `Drawer`는 `Scaffold` 모서리에서 수평으로 슬라이드하면 나타나는 매터리얼 디자인 패널 위젯입니다.
- Scaffold의 `drawer` 파라미터에 적용할 수 있습니다.

|파라미터|타입|의미|
|---|---|---|
|child|Widget|하위 위젯|

```
Drawer(
	child: ListView(
		...
	),
)
```

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
)
```

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
)
```

### Opacity
- `Opacity`는 투명도를 제공하는 위젯입니다.
- 투명도 값 범위는 \[0.0, 1.0\]입니다.

|파라미터|타입|의미|
|---|---|---|
|child|Widget|하위 위젯|
|opacity|double|투명도|

```
Opacity(
	child: FlutterLogo(size: 150.0),
	opacity: 0.5,
)
```

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
	selectionColor: const Colors.blue,
)
```

### Builder
- `Builder` 위젯은 `StatelessWidget`을 정의하는 또 다른 방법입니다.

-  `Center` 위젯 내부에서 `StatelessWidget`을 사용한다고 합시다.
```
class Foo extends StatelessWidget {
	const Foo({super.key});
	@override
	Widget build(BuildContext context) => const Text('foo');
}
...
const Center(child: Foo())
```

- 이는 `Builder`를 사용해서 다음과 같이 대체할 수 있습니다. (`StatelessWidget`을 별도로 정의하지 않고 바로 사용할 수 있습니다.)
```
Center(
	child: Builder(
		builder: (BuildContext context) => const Text('foo'),
	),
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
)
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
)
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
)
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
)
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
 )
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
)
```

### LinearProgressIndicator
- `LinearProgressIndicator`는 선형 모양의 진행도를 표시하는 위젯입니다.
- 이 외는 `CircularProgressIndicator`와 동일합니다.

```
LinearProgressIndicator(
	backgroundColor: Colors.green,
	strokeWidth: 10,
	value: null,
)
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
)
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
)
```

## Design & Animations
### AnimationController
- `AnimationController`은 애니메이션을 제어하는 위젯입니다.
- `AnimationController`는 `TickerProvider` 오브젝트를 사용합니다. `TickerProvider`는 `Ticker` 오브젝트와 인터페이스하는 클래스이며, `Ticker`는 애니메이션 프레임마다 콜백을 한번씩 호출하는 클래스입니다.
- 만약 `AnimationController`가 상태 클래스에서 생성된다면, 해당 상태는 `TickerProvider`가 구현된 `TickerProviderStateMixin`을 사용할 수 있습니다.
- `AnimationController` 오브젝트는 더 이상 사용되지 않는다면 자원 절약을 위해 소멸되어야 합니다. 만약 `StatefulWidget`을 사용한다면, 보통 `AnimationController`는 상태가 `State.initState`일 때 생성되고 `State.dispose`일 때 소멸되는 것이 일반적입니다.

|파라미터|타입|의미|
|---|---|---|
|duration|Duration|애니메이션 지속 시간|
|vsync|TickerProvider|사용할 `TickerProvider`|

```
AnimationController(
	duration: const Duration(seconds: 3),
	vsync: this,
)
```

### Animation<T>
- `Animation<T>`는 `T` 타입으로 구성된 애니메이션 추상 클래스입니다.

### CurvedAnimation
- `CurvedAnimation`는 커브 애니메이션이 적용된 애니메이션 클래스입니다.

|파라미터|타입|의미|
|---|---|---|
|parent|Animation\<double\>|커브 애니메이션을 적용할 `Animation`|
|curve|Curve|커브 오브젝트|

```
CurvedAnimation(
	parent: _controller,
	curve: Curves.elasticIn,
)
```

### SlideTransition
- `SlideTransition`은 아이템의 상대 위치에 대한 애니메이션을 수행하는 위젯입니다.

|파라미터|타입|의미|
|---|---|---|
|child|Widget|하위 위젯|
|position|Animation\<Offset\>|애니메이션에서 `child`의 위치|

```
SlideTransition(
	position: _offsetAnimation,
	child: const Padding(
		...
	),
)
```

### FlutterLogo
- `FlutterLogo`는 Flutter의 로고 이미지를 포함한 위젯입니다.

|파라미터|타입|의미|
|---|---|---|
|size|double|로고 크기|

```
FlutterLogo(
	size: 150.0
),
```

### Material
- `Material` 위젯은 Clipping, Elevation, Ink 등을 사용할 때 이들의 조상 위젯 역할을 합니다.

|파라미터|타입|의미|
|---|---|---|
|child|Widget|하위 위젯|
|color|Color|배경 색|
|animationDuration|Duration|애니메이션 지속 시간|

```
Material(
	color: Colors.yellow,
	child: InkWell(
		...
	),
),
```

### AnimatedContainer
- `AnimatedContainer`는 `Container`에서 애니메이션을 포함한 위젯입니다.
- `AnimatedContainer`의 내부에는 자체`AnimationController`가 포함되어 있습니다.

|파라미터|타입|의미|
|---|---|---|
|child|Widget|하위 위젯|
|width|double|너비|
|height|double|높이|
|duration|Duration|애니메이션 지속 시간|
|curve|Curve|커브 오브젝트|
```
AnimatedContainer(
	height: 50,
	width: 50,
	duration: const Duration(seconds: 2),
	curve: Curves.easeIn,
	child: Material(
		...
	),
);
```

### InkWell
- `InkWell`은 터치 제스처에 반응하는 직사각형 영역의 매터리얼 위젯입니다.
- `InkWell`을 사용하려면 `Material` 위젯을 조상 위젯으로 해야 합니다.

```
InkWell(
	onTap: () {
		setState(() {
			sideLength == 50 ? sideLength = 100 : sideLength = 50;
		});
	},
),
```

### GridView
- `GridView`는 스크롤이 가능한 2D 그리드 레이아웃 위젯입니다.
- `GridView`에서 가장 자주 사용되는 생성자는 타일 개수가 고정된 그리드를 생성하는 `GridView.count`입니다.

|파라미터|타입|의미|
|---|---|---|
|primary|bool|상위 스크롤 뷰 사용 유무|
|padding|EdgeInsetsGeometry|그리드 바깥 여백 간격|
|crossAxisSpacing|double|아이템간 간격(세로)|
|mainAxisSpacing|double|아이템간 간격(가로)|
|crossAxisCount|double|세로 줄 개수|
|children|List\<Widget\>|아이템 목록|

```
GridView.count(
	primary: false,
	padding: const EdgeInsets.all(20),
	crossAxisSpacing: 10,
	mainAxisSpacing: 10,
	crossAxisCount: 2,
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

### ThemeData
- `ThemeData`는 테마를 정의하는 위젯입니다.
- `MaterialApp`의 `theme`, `Theme`의 `data` 등에서 값으로 사용됩니다.
- `ThemeData.copyWith` 메소드는 테마 오브젝트를 복사합니다. (인자를 제공해서 원하는 파라미터를 수정할 수 있습니다.)

|파라미터|타입|의미|
|---|---|---|
|brightness|Brightness|밝기 테마|
|primaryColor|Color|앱의 주요 부분의 배경 색|

```
ThemeData(
	brightness: Brightness.light,
	primaryColor: Colors.green,
)
```

### Theme
- `Theme`는 후손 위젯에게 테마를 적용하는 위젯입니다.
- `of` 정적 메소드는 주어진 `BuildContext`와 가장 가까운 테마 오브젝트를 반환합니다.

|파라미터|타입|의미|
|---|---|---|
|data|ThemeData|테마 값|
|child|Widget|하위 위젯|

```
Theme(
	data: Theme.of(context).copyWith(
		colorScheme: Theme.of(context).colorScheme,
	),
	child: Container(
		...
	),
)
```

## Class
### Tween<T>
- `Tween<T>`은 `T` 타입에 대해 시작에서 종료까지 선형 차이를 의미하는 클래스입니다.
- `Tween<T>`은 주로 애니메이션에서 사용됩니다.
- `animate` 메소드는 `Animation<T>`를 반환합니다.

|프로퍼티|타입|의미|
|---|---|---|
|begin|`T`|시작 값|
|end|`T`|종료 값|

```
Tween<Offset>(
	begin: const Offset(0.0, 0.0),
	end: const Offset(50.0, 100.0),
),
```

### Offset
- `Offset`은 2D 좌표에서 변화량을 의미하는 클래스입니다.

```
Offset(double dx, double dy)
```

## Example
### Stateless Widget
- 'Stateless Widget'를 출력합니다.
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

![](images/Flutter-Example-StatelessWidget.png)

### Stateful Widget
- 'Stateful Widget'를 출력합니다.
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

![](images/Flutter-Example-StatefulWidget.png)

### AppBar
- 상단에 `AppBar`가 표시됩니다.

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

![](images/Flutter-Example-AppBar.png)

### BottomNavigationBar
- 3가지 아이템(Home, Business, School)을 가지는 메뉴 바입니다.
- 메뉴 바의 아이템을 선택하면 메인 화면에 표시되는 텍스트가 달라집니다.

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

![](images/Flutter-Example-BottomNavigationBar.png)

### Drawer
- 상단 버튼을 클릭하면 `Drawer`가 표시됩니다.
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

![](images/Flutter-Example-Drawer.png)

### AlertDialog
- 버튼을 누르면 `AlertDialog`을 표시합니다.

```
import 'package:flutter/material.dart';
void main() => runApp(const MyApp());

class MyApp extends StatelessWidget {
	const MyApp({Key? key}) : super(key: key);
 
	@override
	Widget build(BuildContext context) {
		return const MaterialApp(
			home: HomePage(),
		);
	}
}
 
class HomePage extends StatefulWidget {
	const HomePage({Key? key}) : super(key: key);
 
	@override
	_HomePageState createState() => _HomePageState();
}
 
class _HomePageState extends State<HomePage> {
	@override
	Widget build(BuildContext context) {
		return Scaffold(
			body: Container(
				child: Center(
					child: ElevatedButton(
						onPressed: () {
							showDialog(
								context: context,
								builder: (ctx) => AlertDialog(
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
							);
						},
						child: const Text("Show Dialog"),
					),
				),
			),
		);
	}
}
```

![](images/Flutter-Example-AlertDialog.png)

### AnimationController
- `CurvedAnimation`와 `SlideTransition`이 적용된 애니메이션입니다.

```
import 'package:flutter/material.dart';
void main() => runApp(const MyApp());

class MyApp extends StatefulWidget {
	const MyApp({super.key});
	
	@override
	State<MyApp> createState() => _MyApp ();
}

class _MyApp extends State<MyApp> with SingleTickerProviderStateMixin {
	late final AnimationController _controller = AnimationController(
		duration: const Duration(seconds: 3),
		vsync: this,
	)..repeat(reverse: true);
	late final Animation<Offset> _offsetAnimation = Tween<Offset>(
		begin: Offset.zero,
		end: const Offset(1.5, 0.0),
	).animate(CurvedAnimation(
		parent: _controller,
		curve: Curves.elasticIn,
	));

	@override
	void dispose() {
		_controller.dispose();
		super.dispose();
	}

	@override
	Widget build(BuildContext context) {
		return SlideTransition(
			position: _offsetAnimation,
			child: const Padding(
				padding: EdgeInsets.all(8.0),
				child: FlutterLogo(size: 150.0),
			),
		);
	}
}
```

![](images/Flutter-Example-AnimationController.png)

### InkWell
- 직사각형을 터치하면 확대 / 축소됩니다.

```
import 'package:flutter/material.dart';

void main() => runApp(const MyApp());

class MyApp extends StatelessWidget {
	const MyApp({super.key});

	@override
	Widget build(BuildContext context) {
		return MaterialApp(
			home: Scaffold(
				body: const Center(
					child: InkWellExample(),
				),
			),
		);
	}
}

class InkWellExample extends StatefulWidget {
	const InkWellExample({super.key});

	@override
	State<InkWellExample> createState() => _InkWellExampleState();
}

class _InkWellExampleState extends State<InkWellExample> {
	double length = 50;

	@override
	Widget build(BuildContext context) {
		return AnimatedContainer(
			height: length,
			width: length,
			duration: const Duration(seconds: 2),
			curve: Curves.easeIn,
			child: Material(
				color: Colors.yellow,
				child: InkWell(
					onTap: () {
						setState(() {
							length == 50 ? length = 100 : length = 50;
						});
					},
				),
			),
		);
	}
}
```

![](images/Flutter-Example-InkWell.png)

## 출처 (Reference)
https://www.geeksforgeeks.org/flutter-tutorial/

https://api.flutter.dev/index.html
