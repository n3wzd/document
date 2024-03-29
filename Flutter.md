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

### 라우트 (Route)
`라우트(Route)`는 Flutter 애플리케이션에서 페이지(page)입니다.

### 네비게이터 (Navigator)
`네비게이터(Navigator)`는 Route간 이동을 처리하는 위젯입니다. Navigator는 Route들을 스택(stack) 구조로 관리합니다.

## Widget
### StatelessWidget
- `StatelessWidget`은 빌드 이후에 상태가 변경되지 않는 위젯입니다.
- `StatelessWidget`는 생성될 때 빌드 메소드가 1번만 호출됩니다.
- 빌드 메소드 `build()`는 하위 위젯을 빌드하는 메소드입니다. 이 함수는 빌드할 하위 위젯을 반환합니다.
- `StatelessWidget`는 불변 클래스(`@immutable`)이므로 모든 프로퍼티는 `final`이어야 합니다.
- 하위 위젯의 상태가 런타임 중간에 바뀌지 않는다면 `StatelessWidget`가 적합합니다.

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

### StatefulWidget
- `StatefulWidget`은 빌드 이후에도 상태가 변경될 수 있는 위젯입니다.
- `StatefulWidget`는 생성된 이후에도 빌드 메소드가 여러 번 호출될 수 있습니다.
- `StatefulWidget`의 빌드 메소드는 `State`에서 정의됩니다.
- `createState()` 메소드를 통해 `State`을 생성합니다.
  - 이 메소드에선 `State` 반환을 제외한 다른 로직은 추가될 수 없습니다. (`State` 반환 로직만 있어야 합니다.)
- `StatefulWidget`는 불변 클래스(`@immutable`)이므로 모든 프로퍼티는 `final`이어야 합니다.
- 하위 위젯의 상태가 런타임 중간에 바뀔 수 있다면 `StatefulWidget`가 적합합니다.

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

### State
- `State`은 상태를 정의하는 클래스이며, `StatefulWidget`와 같이 사용됩니다.
- `State` 객체는 빌드 중간에 변할 수 있습니다. 즉, 프로퍼티의 값은 변경될 수 있습니다.
- `State`는 빌드 메소드를 가지며, `StatefulWidget`가 빌드할 하위 위젯이 여기서 정의됩니다.
- `widget` 프로퍼티는 `StatefulWidget`을 가리킵니다. `widget`을 통해 `StatefulWidget`의 프로퍼티를 가져올 수 있습니다.

```
class _MyAppState extends State<MyApp> {
  @override
  Widget build(BuildContext context) {
    return Container();
  }
}
```

#### setState()
- `setState()`은 상태가 변경되었음을 프레임워크에 통지하는 메소드입니다.
- 이 메소드가 호출되면 빌드가 다시 수행됩니다. 즉, 빌드 메소드가 다시 호출됩니다.
- 이 메소드는 콜백을 인자로 합니다. 이 콜백에서 프로퍼티 변경 로직을 정의할 수 있습니다.

> setState(() { _myState = newValue; });

#### initState()
- `initState()`은 현재 위젯이 위젯 트리에 새로 추가될 때 호출되는 메소드입니다.
- 생성자와 비슷한 용도로 사용할 수 있습니다. (참고: `State`의 생성자는 오버라이드해도 동작하지 않습니다.)

> initState() { ... }

#### dispose()
- `dispose()`은 현재 위젯이 위젯 트리에 완전히 제거될 때 호출되는 메소드입니다.
- 소멸자와 비슷한 용도로 사용할 수 있습니다.

> dispose() { ... }

### BuildContext
- `BuildContext`은 위젯 트리 내에서 위젯을 찾는데 사용됩니다.
- 빌드 메소드의 인자로 사용됩니다.

### Builder
- `Builder` 위젯을 사용해서 `StatelessWidget`을 정의할 수 있습니다.
- `builder` 파라미터는 빌드 메소드를 값으로 합니다.
- `StatelessWidget`을 별도로 정의하지 않고 바로 사용하고자 한다면 `Builder`가 적합합니다.

**Before**
```
class Foo extends StatelessWidget {
  const Foo({super.key});
  @override
  Widget build(BuildContext context) => const Text('foo');
}
...
const Center(child: Foo())
```

**After**
```
Center(
  child: Builder(
    builder: (BuildContext context) => const Text('foo'),
  ),
)
```

### StatefulBuilder
- `StatefulBuilder` 위젯을 사용해서 `StatefulWidget`을 정의할 수 있습니다.
- `builder` 파라미터는 빌드 메소드를 값으로 합니다.
- 빌드 메소드의 `setState` 프로퍼티는 `StatefulWidget`의 `setState`과 동일한 역할을 합니다.
- `StatefulWidget`을 별도로 정의하지 않고 바로 사용하고자 한다면 `StatefulBuilder`가 적합합니다.

```
StatefulBuilder(
  builder: (BuildContext context, StateSetter setState) => IconButton(
    icon: const Icon(Icons.repeat, color: ColorTheme.lightGrey)
    iconSize: 35,
    onPressed: () {
      setState(() {});
    },
  ),
),
```

### StreamBuilder
- `StreamBuilder` 위젯을 사용해서 특정 Stream에 맞게 상태가 변화하는 `StatefulWidget`을 정의할 수 있습니다.
- `StreamBuilder`의 제너릭 타입은 Stream의 잠재적 값 타입입니다.
- `builder` 파라미터의 빌드 메소드는 추가적으로 `AsyncSnapshot` 인자를 가집니다.
- Stream 연산에 따라 빌드가 수행될 필요가 있다면 `StreamBuilder`가 적합합니다.

|파라미터|타입|의미|
|---|---|---|
|stream|Stream\<T\>|사용할 Stream|
|builder|AsyncWidgetBuilder\<T\>|비동기 빌드 메소드|

```
StreamBuilder<T>(
  stream: ...,
  builder: (BuildContext context, AsyncSnapshot<T> snapshot) {
    if (snapshot.hasError) {
      ...
    } else {
      switch (snapshot.connectionState) {
        case ConnectionState.none: ...
        case ConnectionState.waiting: ...
        case ConnectionState.active: ...
        case ConnectionState.done: ...
      }
    }
  }
)
```

### FutureBuilder
- `FutureBuilder` 위젯을 사용해서 특정 Future가 실행되면 빌드되는 `StatefulWidget`을 정의할 수 있습니다.
- 사용 방법은 Stream 대신 Future가 사용된다는 점을 제외하면 `StreamBuilder`와 거의 유사합니다.

### AsyncSnapshot
- `AsyncSnapshot`은 비동기 연산에서 사용되는 데이터 묶음 클래스입니다.
- `AsyncSnapshot`의 제너릭 타입은 Future 또는 Stream의 잠재적 값 타입입니다.
- 주로 `StreamBuilder`에서 사용됩니다.

|프로퍼티|타입|의미|
|---|---|---|
|data||비동기 연산의 잠재적 값|
|connectionState|ConnectionState|비동기 연산과 연결 상태|
|hasError|bool|에러 발생시 true|
|error|Object|비동기 연산에서 발생한 error 객체|
|stackTrace|StackTrace|비동기 연산에서 발생한 `StackTrace`|

### ConnectionState
- `ConnectionState`은 비동기 연산의 연결 상태 값을 정의한 enum입니다.
- 비동기 연산이 진행되면서 Future 또는 Stream의 잠재적 값(data)이 변화합니다.

1. `none`: 비동기 연산과 연결되지 않은 초기 상태
2. `waiting`: 비동기 연산과 연결이 되었으며 연산이 시작되기 이전 상태 (이때 data는 보통 null을 가짐)
3. `active`: 비동기 연산이 진행 중인 상태 (data가 결정되었으나 값이 바뀔 수 있음)
4. `done`: 비동기 연산이 종료된 상태 (data가 완전히 결정됨)

### MediaQuery
- `MediaQuery`는 미디어 쿼리를 서브 트리 구조로 저장하는 클래스입니다.
- static 메소드인 `of`를 사용해서 `MediaQueryData`를 가져올 수 있습니다.
  - `of`는 `BuildContext`를 인자로 합니다.

```
// 현재 기기의 화면 높이
MediaQuery.of(context).size.height
```

### MediaQueryData
- `MediaQuery`는 현재 기기(미디어)에 대한 정보를 제공하는 클래스입니다.

|프로퍼티|타입|의미|
|---|---|---|
|size|Size|화면 크기|

### Function
- `Function`은 함수 클래스이며, 모든 함수 타입의 최상위 객체입니다.
- `Function` 자체에는 아무런 값을 가지지 않습니다.
- 함수 타입을 저장하는 프로퍼티는 저장할 함수의 반환 타입, 파라미터 타입과 이름, 제너릭 타입을 선언해야 합니다.
  - 반환 타입이 void면 타입 표기를 생략할 수 있습니다.
  - 파라미터의 이름은 생략 가능합니다.

```
void foo1() {};
int foo2(int a, int b) { return a + b; };

Function() f1 = foo1;
int Function(int a, int b) f2 = foo2;
```

- 프로퍼티의 타입을 `Function`만으로 표기하는 경우, 모든 함수를 담을 수 있습니다.
- 그러나 이 프로퍼티를 통해 함수를 호출할 수 없습니다.
  - 단, static 타입 값을 다루는 함수는 호출 가능합니다.

```
Function foo = (int n) => "$n";
print(foo(1)); // 정상적으로 동작합니다.
```

### VoidCallback
- `VoidCallback`은 빈 `Function`을 의미합니다. (typedef)

> VoidCallback = void Function()

## Layout
### Container
- `Container`는 기본적인 컨테이너 위젯입니다.
- `Container`는 다양한 기능을 가지고 있다는 이점이 있습니다. 하지만 기능이 많아서 동작을 예측하기 어려운 편입니다.
- `Container`의 구조는 HTML의 Box Model하고 유사합니다.

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

- `Container`는 특정한 레이아웃이 없으며, 다른 위젯의 레이아웃을 따릅니다. (위쪽일수록 우선 순위가 높습니다.)
1. `alignment` 조건을 적용합니다.
2. `Container` 크기를 하위 위젯의 크기에 맞게 조정합니다.
3. `width`, `height`, `constraints` 조건을 적용합니다.
4. `Container` 크기를 상위 위젯의 크기에 맞게 확장합니다.
5. 최대한 작아지는 방향으로 크기를 조정합니다.

|파라미터|타입|의미|
|---|---|---|
|child|Widget|하위 위젯|
|width|double|너비|
|height|double|높이|
|padding|EdgeInsetsGeometry|border와 child간 여백|
|margin|EdgeInsetsGeometry|border를 둘러싼 여백|
|alignment|AlignmentGeometry|`child` 배치 방식|
|color|Color|배경색|
|decoration|Decoration|데코레이션|

```
Container(
  height: 200,
  width: 200,
  alignment: Alignment.center,
  color: Colors.yellow,
)
```

### Padding
- `Padding`은 `padding`을 제공하는 위젯입니다.

|파라미터|타입|의미|
|---|---|---|
|child|Widget|하위 위젯|
|padding|EdgeInsetsGeometry|border와 child간 여백|

```
Padding(
  padding: EdgeInsets.all(16.0),
  child: Text('Hello World!'),
)
```

### Center
- `Center`은 가운데 정렬을 제공하는 위젯입니다.

|파라미터|타입|의미|
|---|---|---|
|child|Widget|하위 위젯|

```
Center(
  child: Text('Hello World!'),
)
```

### Align
- `Align`은 정렬을 제공하는 위젯입니다.

|파라미터|타입|의미|
|---|---|---|
|child|Widget|하위 위젯|
|alignment|AlignmentGeometry|정렬 방법|

```
Align(
  alignment: Alignment.centerLeft,
  child: Text('Hello World!'),
)
```

### Expanded
- `Expanded`는 flex 레이아웃을 제공하는 위젯입니다.
- flex 레이아웃은 해당 위젯의 크기를 스크린 끝까지 자동으로 맞춰줍니다.
- 여러 아이템들이 행 또는 열을 이룰 때, flex 값은 각 아이템들이 상대적으로 차지하는 공간을 결정합니다. 만약 아이템 A의 flex가 2, 아이템 B의 flex가 1이면, A와 B는 2:1 크기 비율로 공간을 차지합니다.
- `Expanded`는 `Row`, `Column`, `Flex`의 하위 위젯으로 사용할 수 있습니다. (`Stack`의 하위 위젯으로 사용하면 오류가 발생합니다.)

```
A.flex = 2, B.flex = 1
|----A----|--B--|
```

|파라미터|타입|의미|
|---|---|---|
|child|Widget|하위 위젯|
|flex|int|flex 값|

```
Expanded(
  flex: 2,
  child: Container(
    color: Colors.blue,
    height: 100,
  ),
 )
```

### SizedBox
- `SizedBox`은 고정된 크기를 가진 위젯입니다.
- 레이아웃에서 빈 공간을 추가하는 용도로도 사용할 수 있습니다.

|파라미터|타입|의미|
|---|---|---|
|child|Widget|하위 위젯|
|width|double|너비|
|height|double|높이|

```
SizedBox(
  width: 20,
  height: 30,
  child: Text('Sized!'),
)
```

### FractionallySizedBox
- `FractionallySizedBox`은 전체 공간에서 주어진 비율만큼 하위 위젯의 공간을 제한하는 위젯입니다.

|파라미터|타입|의미|
|---|---|---|
|child|Widget|하위 위젯|
|widthFactor|double|너비 비율|
|heightFactor|double|높이 비율|
|alignment|AlignmentGeometry|`child` 배치 방식|

```
FractionallySizedBox(
  widthFactor: 0.5,
  heightFactor: 0.5,
  alignment: FractionalOffset.center,
  child: child: Container(
    color: Colors.blue,
  ),
),
```

### Spacer
- `Spacer`는 빈 공간을 제공하는 위젯입니다.
- `flex`를 사용할 수 있습니다. (기본값 = 1)
- 주로 `Column`, `Row` 내부에서 사용됩니다.

|파라미터|타입|의미|
|---|---|---|
|flex|int|flex 값|

```
Spacer()
```

### Column
- `Column`은 수직 방향으로 하위 위젯들을 나열하는 위젯입니다.

|파라미터|타입|의미|
|---|---|---|
|children|List<Widget>|하위 위젯 목록|
|mainAxisAlignment|MainAxisAlignment|위젯 정렬 시작점(시작, 끝, 중심)|

```
Column(
  children: <Widget>[
    ...
  ],
)
```

### Row
- `Row`은 수평 방향으로 하위 위젯들을 나열하는 위젯입니다.

|파라미터|타입|의미|
|---|---|---|
|children|List<Widget>|하위 위젯 목록|
|mainAxisAlignment|MainAxisAlignment|위젯 정렬 시작점(시작, 끝, 중심)|

```
Row(
  children: <Widget>[
    ...
  ],
)
```

### Stack
- `Stack`은 모서리를 기준으로 하위 위젯들을 배치하는 위젯입니다.
- `Stack` 내부에 있는 위젯들은 서로 겹쳐질 수 있습니다.

|파라미터|타입|의미|
|---|---|---|
|children|List<Widget>|하위 위젯 목록|

```
Stack(
  children: <Widget>[
    ...
  ],
)
```

### Positioned
- `Positioned`은 `Stack` 내부에서 하위 위젯의 위치를 조정하는 위젯입니다.
- 상대 위치는 `Stack`의 모서리를 기준으로 합니다.

|파라미터|타입|의미|
|---|---|---|
|child|Widget|하위 위젯|
|left|double|왼쪽 모서리간 거리|
|right|double|오른쪽 모서리간 거리|
|top|double|위쪽 모서리간 거리|
|bottom|double|아래쪽 모서리간 거리|
|width|double|`child` 너비|
|height|double|`child` 높이|

```
Stack(
  children: <Widget>[
    Positioned(
      left: 40,
      top: 30,
      child: Container(
        ...
      ),
    ),
  ],
)
```

### SafeArea
- `SafeArea`는 OS로 인한 UI 침입을 막아주는 컨테이너 위젯입니다.
- OS에 따라 여유 공간이 부족하여 디바이스의 UI가 가려지는 현상이 발생할 수 있습니다. `SafeArea`로 감싸면 문제가 자동으로 해결됩니다.
- `SafeArea`는 일반적으로 `Scaffold`의 `body`에서 사용됩니다.

|파라미터|타입|의미|
|---|---|---|
|child|Widget|하위 위젯|

```
SafeArea(
  child: Text('Safe!'),
)
```

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
|itemExtent|double|아이템 길이(스크롤 방향 기준)|

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

- `ListTile.selected` 생성자는 아이템간 구분선을 자동으로 생성합니다.

### ListTile
- `ListTile`은 `ListView`의 아이템으로 사용되는 위젯입니다.
- Tile의 색상을 표시하려면 `Material`을 조상 위젯으로 해야 합니다.

|파라미터|타입|의미|
|---|---|---|
|title|Widget|하위 위젯|
|onTap|GestureTapCallback|탭 제스처 콜백|
|leading|Widget|`title` 앞쪽에 표시되는 위젯|
|trailing|Widget|`title` 뒤쪽에 표시되는 위젯|
|textColor|Color|텍스트 색상|
|selectedColor|Color|선택된 아이템의 텍스트/아이콘 색상|
|tileColor|Color|아이템의 배경 색상|
|selectedTileColor|Color|선택된 아이템의 배경 색상|
|minVerticalPadding|double|`title`과 아이템 상단 모서리간 최소 간격 (기본값 = 4)|

```
ListTile(
  title: Text('$index'),
  onTap: () {},
)
```

### ReorderableListView
- `ReorderableListView`는 사용자가 직접 정렬이 가능한 ListView 위젯입니다.
- 재정렬되면 `onReorder` 프로퍼티의 콜백이 호출됩니다.

```
ReorderableListView(
  onReorder: (oldIndex, newIndex) {
    setState(() {
    if (oldIndex < newIndex) {
      newIndex -= 1;
    }
    final String item = items.removeAt(oldIndex);
    items.insert(newIndex, item);
  });
},
```

### Dismissible
- `Dismissible`은 드래그로 특정 위젯을 삭제할 수 있는 위젯입니다.
- 위젯이 삭제되면 `onDismissed` 프로퍼티에 저장된 콜백이 호출됩니다.
- 위젯이 삭제될 수 있으므로 `key`는 고유한 값을 가져야 합니다.

```
Dismissible(
  key: UniqueKey(),
  onDismissed: (DismissDirection direction) {
    setState(() {
      removeItem(index);
    });
  },
  child: ...
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

### Wrap
- `Wrap`은 하위 위젯들을 좌측 상단부터 한 줄씩 나열하는 레이아웃 위젯입니다. (텍스트 글자가 나열되는 것과 비슷하게 정렬됩니다.)

### LayoutBuilder
- `LayoutBuilder`는 상위 위젯의 크기에 의존하여 위젯을 빌드하는 클래스입니다.
- `BoxConstraints`을 통해 상위 위젯의 크기를 구할 수 있습니다.
- 빌드 메소드는 `BuildContext`, `BoxConstraints`을 인자로 합니다.

```
LayoutBuilder(
  builder: (context, constraints) {
    ...
  }
);
```

### BoxConstraints
- `BoxConstraints`는 `RenderBox` 레이아웃을 제공하는 클래스입니다.
- 박스 레이아웃의 크기 정보를 포함하고 있습니다.

|파라미터|타입|의미|
|---|---|---|
|minWidth|double|최소 너비|
|maxWidth|double|최대 너비|
|minHeight|double|최소 높이|
|maxHeight|double|최대 높이|

- minWidth \<= Size.width \<= maxWidth
- minHeight \<= Size.height \<= maxHeight

### Visibility
- `Visibility`는 위젯의 표시 유무를 결정하는 위젯입니다.

|파라미터|타입|의미|
|---|---|---|
|visible|bool|표시 유무|
|child|Widget|하위 위젯|

```
Visibility (
  visible: _isVisible,
  child: ...
);
```

### EdgeInsets
- `EdgeInsets`은 4개의 값을 제공하는 클래스입니다.
- 주로 사각형과 관련된 프로퍼티에서 값으로 사용됩니다. (ex. padding)

1. 전체
> EdgeInsets.all(8.0)

2. 수직-수평
> EdgeInsets.symmetric(vertical: 8.0, horizontal: 12.0)

3. 상-하-좌-우
> EdgeInsets.only(left: 8.0, right: 10.0, top: 12.0, bottom: 14.0)

### Alignment
- `Alignment`는 2D 좌표계 값을 제공하는 클래스입니다.
- 원점은 중심인 (0.0, 0.0)입니다.
- 정렬 프로퍼티의 값으로 사용할 수 있습니다.

> Alignment(x, y)

```
              |
     -------(0,-1)------
     |        |        |
     |        |        |
--(-1,0)----(0,0)----(1,0)--
     |        |        |
     |        |        |
     -------(0,1)-------
              |
```

### FractionalOffset
- `FractionalOffset`는 2D 좌표계 값을 제공하는 클래스입니다.
- 원점은 상단 좌측인 (0.0, 0.0)입니다.
- `Alignment`와 동일한 정보를 가지고 있으므로, `Alignment`를 사용할 수 있는 곳에는 `FractionalOffset`도 사용할 수 있습니다.

> FractionalOffset(x, y)

```
    |        |
--(0,0)----(1,0)--
    |        |
    |        |
--(0,1)----(1,1)--
    |        |
```

### CrossAxisAlignment
- `CrossAxisAlignment`는 양끝에 2개의 축이 있는 상황에서 배치 방법을 정의한 enum입니다.

## UI Components
### MaterialApp
- `MaterialApp`은 `매터리얼 위젯(Material widget)`들을 감싸는 위젯입니다. `MaterialApp`을 통해서 `MaterialApp`의 하위 위젯에 접근할 수 있습니다.
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
)
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

### AppBar
- `AppBar`는 앱 상단 메뉴를 표시하는 위젯입니다.
- `Scaffold`의 `appBar` 파라미터에 적용할 수 있습니다.

|파라미터|타입|의미|
|---|---|---|
|backgrounColor|Color|메뉴바 색상|
|leading|Widget|`title` 이전에 표시되는 위젯|
|title|Widget|메뉴바 제목으로 표시되는 위젯|
|centerTitle|bool|`title`의 위치를 중심으로 설정할 것인지 유무|
|flexibleSpace|Widget|`AppBar` 뒤쪽에 위치되는 위젯 (높이는 `AppBar`와 동일)|

```
AppBar(
  leading: const Icon(Icons.menu),
  backgroundColor: Colors.blue,
  title: const Text(
      "MyApp",
    textAlign: TextAlign.start,
  ),
)
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
)
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

### Text
- `Text`는 텍스트를 제공하는 위젯입니다.

|파라미터|타입|의미|
|---|---|---|
|style|TextStyle|텍스트 스타일|
|maxLines|int|표시되는 최대 줄 수|
|overflow|TextOverflow|텍스트가 UI 초과시 처리되는 방법|

```
Text('Hello World!')
```

### TextSpan
- `TextSpan`는 텍스트를 포함한 span입니다.

|파라미터|타입|의미|
|---|---|---|
|text|String|텍스트 내용|
|style|TextStyle|텍스트 스타일|

```
TextSpan(text: 'text');
```

### TextOverflow
- 텍스트가 UI 초과시 처리되는 방법을 정의한 `enum`입니다.

|값|의미|
|---|---|
|`clip`|초과된 텍스트를 표시하지 않습니다.|
|`fade`|초과된 텍스트를 흐릿하게 표시합니다.|
|`ellipsis`|초과된 텍스트를 '...'으로 대체하여 표시합니다.|
|`visible`|초과된 텍스트를 그대로 표시합니다.|

### Dialog
- `Dialog`는 기본적인 메시지 창 위젯입니다.
- 특정 디자인이 적용되지 않으므로 커스타마이징이 자유롭습니다.

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

### DraggableScrollableSheet
- `DraggableScrollableSheet`는 드래그해서 확장할 수 있는 스크롤 가능한 컨테이너 위젯입니다.
- 파라미터를 통해 컨테이너의 크기를 설정할 수 있으며, 값의 범위는 \[0.0, 1.0\]입니다. (1.0이면 상위 위젯과 같은 크기)
- 빌드 메소드 `ScrollableWidgetBuilder`는 2개의 인자 `Context`, `ScrollController`를 가집니다.

|파라미터|타입|의미|
|---|---|---|
|builder|ScrollableWidgetBuilder|빌드 메소드|
|initialChildSize|double|초기 Child 크기 비율|
|maxChildSize|double|최대 Child 크기 비율|
|minChildSize|double|최소 Child 크기 비율|
|controller|DraggableScrollableController|`DraggableScrollableController` 오브젝트|

```
DraggableScrollableSheet(
  initialChildSize: 0.5,
  minChildSize: 0.1,
  maxChildSize: 0.9,
  builder: (BuildContext context, ScrollController scrollController) {
    ...
  },
);
```

### DraggableScrollableController
- `DraggableScrollableController`는 `DraggableScrollableSheet`의 동작을 제어하는 클래스입니다.
- `DraggableScrollableSheet`의 `controller` 파라미터에 대입할 수 있습니다.

|메소드|기능|
|---|---|
|jumpTo|드래그 위치를 특정 위치로 변경합니다|
|animateTo|jumpTo와 비슷한데, 애니메이션이 적용됩니다|
|reset|드래그 위치를 초기 위치로 변경합니다|

### SingleChildScrollView
- `SingleChildScrollView`는 단일 위젯에 스크롤 기능을 추가해주는 위젯입니다.

|파라미터|타입|의미|
|---|---|---|
|child|Widget|하위 위젯|
|scrollDirection|Axis|스크롤 방향|
|ScrollController|ScrollController|`ScrollController` 오브젝트|

```
SingleChildScrollView(
  scrollDirection: Axis.horizontal,
  child: ...
);
```

### ScrollController
- `ScrollController`는 스크롤 동작을 감지하는 클래스입니다.
- `jumpTo` 등 `ScrollPosition` 관련 메소드는 `hasClients`가 true여야 동작합니다.

|프로퍼티|타입|의미|
|---|---|---|
|hasClients|bool|`ScrollPosition` 첨부(attached) 유무|

|메소드|기능|
|---|---|
|jumpTo|스크롤 위치를 특정 위치로 변경합니다|
|animateTo|jumpTo와 비슷한데, 애니메이션이 적용됩니다|

```
ScrollController controller = ScrollController();
SingleChildScrollView(
  controller: controller,
  child: ...
);
...
if (controller.hasClients) {
  controller.jumpTo(0);
}
```

### ScrollPosition
- `ScrollPosition`는 현재 스크롤 위치 정보를 저장하는 클래스입니다.

### NeverScrollableScrollPhysics
- `NeverScrollableScrollPhysics`는 사용자가 스크롤을 하는 제스처를 방지하는 위젯입니다.

```
SingleChildScrollView(
  physics: const NeverScrollableScrollPhysics(),
);
```

### TextPainter
- `TextPainter`는 `TextSpan`을 페인트하는 클래스입니다.
- 주로 `TextSpan`의 길이를 구할 때 사용됩니다.

|파라미터|타입|의미|
|---|---|---|
|text|InlineSpan|텍스트 위젯|
|maxLines|int|최대 줄 수|
|textDirection|TextDirection|텍스트 방향|

|메소드|기능|
|---|---|
|layout|텍스트의 시각적 위치를 계산합니다|

```
TextPainter textPainter = TextPainter(
  text: TextSpan(text: text),
  maxLines: 1,
  textDirection: TextDirection.ltr)
..layout(minWidth: 0, maxWidth: double.infinity);

double textWidth = textPainter.size.width;
```

### NavigationBar
- `NavigationBar`는 네비게이션 바를 제공하는 위젯입니다.
- 여러 `NavigationDestination` 중에서 1개를 선택할 수 있습니다.
- 탭뷰를 구현할 수 있습니다.

```
NavigationBar(
  destinations: const [
    NavigationDestination(
      icon: Icon(Icons.star),
      label: 'Favorite',
    ),
    NavigationDestination(
      icon: Icon(Icons.present_to_all),
      label: 'All',
    ),
  ],
  backgroundColor: ColorPalette.transparent,
  selectedIndex: _selectedPageIndex,
  indicatorColor: Colors.green,
  onDestinationSelected: (index) {
    _selectedPageIndex = index;
  },
),
```

### NavigationDestination
- `NavigationDestination`는 `NavigationBar`의 아이템으로 사용되는 위젯입니다.

### Chip
- `Chip`은 칩 디자인으로 구성된 위젯입니다.
- 해시태그 목록 등을 표시할 때는 이 위젯이 적합할 수 있습니다.

```
Chip(
  label: Text('tag#1'),
  backgroundColor: Colors.green,
  padding: const EdgeInsets.symmetric(horizontal: 12, vertical: 8),
),
```

## Design & Animations
### Color
- `Color`는 색을 표현하는 클래스입니다.
- HTML 색 코드로 `Color`를 생성할 수 있습니다. (ARGB 순서)
> Color(0xFFFFFFFF);

- ARGB의 값을 따로 제공할 수도 있습니다.
> Color.fromARGB(int a, int r, int g, int b)

### Colors
- `Colors`는 상수를 통해 색을 가져오는 클래스입니다.

> Colors.orange

### MaterialStateProperty
- `MaterialStateProperty`는 사용자와 위젯의 상호작용 상태에 따라 주어진 아이템을 반환하는 인터페이스 클래스입니다.
- 상호작용 종류는 `MaterialState`에 정의되어 있습니다.
- 인터페이스 함수는 `resolve` 프로퍼티에 저장됩니다.
- `resolve`가 반환하는 아이템의 타입은 제너릭으로 정의됩니다.
- `resolve` 함수는 `Set<MaterialState>`을 인자로 하며, 이는 현재 사용자와 위젯간 상호작용 상태를 의미합니다.

**정적 메소드**
- `all`은 `resolve`는 어떤 상태에서든 단일 아이템을 반환합니다.
> MaterialStateProperty.all\<T\>(T value) → MaterialStateProperty\<T\>

- `resolveWith`에선 `resolve`를 직접 제공할 수 있습니다.
> MaterialStateProperty.resolveWith\<T\>(MaterialPropertyResolver\<T\> callback) → MaterialStateProperty\<T\>

```
MaterialStateProperty.resolveWith((Set<MaterialState> states) {
  const Set<MaterialState> interactiveStates = <MaterialState>{
    MaterialState.pressed,
    MaterialState.hovered,
    MaterialState.focused,
  };
  if (states.any(interactiveStates.contains)) {
    return Colors.blue;
  }
  return Colors.red;
})
```

### MaterialState
- `MaterialState`은 `Material` 위젯의 상호작용 상태를 정의한 enum입니다.

**상태 종류**
1. `hovered`
2. `focused`
3. `pressed`
4. `dragged`
5. `selected`
6. `disabled`
7. `error`

### ButtonStyle
- `ButtonStyle`은 버튼의 style을 정의하는 클래스입니다.

|파라미터|타입|의미|
|---|---|---|
|backgroundColor|MaterialStateProperty\<Color\>|배경 색상|
|iconColor|MaterialStateProperty\<Color\>|Icon 색상|
|shape|MaterialStateProperty\<OutlinedBorder\>|버튼 외형|

```
ButtonStyle(
  iconColor: MaterialStateProperty.all(const Color(0xCCFFFFFF)),
  backgroundColor: MaterialStateProperty.all(Colors.transparent),
)
```

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
)
```

### SlideTransition
- `SlideTransition`은 아이템의 위치 애니메이션을 수행하는 위젯입니다.

|파라미터|타입|의미|
|---|---|---|
|child|Widget|하위 위젯|
|position|Animation\<Offset\>|`child`의 위치를 제어하는 애니메이션|

```
SlideTransition(
  position: Tween<Offset>(
    begin: Offset.zero,
    end: const Offset(1.5, 0.0),
  ).animate(CurvedAnimation(
    ...
  )),
  child: const Padding(
    ...
  ),
)
```

### RotationTransition
- `RotationTransition`은 아이템의 회전 애니메이션을 수행하는 위젯입니다.

|파라미터|타입|의미|
|---|---|---|
|child|Widget|하위 위젯|
|turns|Animation\<double\>|`child`의 회전을 제어하는 애니메이션|

```
RotationTransition(
  turns: Tween(
    begin: 0.0,
    end: 0.15,
  ).animate(CurvedAnimation(
    ...
  )),
  child: const Padding(
    ...
  ),
)
```

### ScaleTransition
- `ScaleTransition`은 아이템의 크기 애니메이션을 수행하는 위젯입니다.

### LinearGradient
- `LinearGradient`는 선형 그라데이션을 그리는 위젯입니다.

### RadialGradient
- `RadialGradient`는 원형 그라데이션을 그리는 위젯입니다.

### Image
- `Image`는 이미지 파일을 표시하는 위젯입니다.

```
Image.asset(
  'assets/image.png',
  width: 300,
  height: 200,
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
)
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

### ThemeData
- `ThemeData`는 테마를 정의하는 위젯입니다.
- `MaterialApp`의 `theme`, `Theme`의 `data` 등에서 값으로 사용됩니다.
- `ThemeData.copyWith` 메소드는 테마 오브젝트를 복사합니다. (인자를 제공해서 원하는 파라미터를 수정할 수 있습니다.)

|파라미터|타입|의미|
|---|---|---|
|colorScheme|ColorScheme|적용할 ColorScheme|
|brightness|Brightness|밝기 테마|
|primaryColor|Color|앱의 주요 부분의 배경 색|

```
ThemeData(
  brightness: Brightness.light,
  primaryColor: Colors.green,
)
```

### ColorScheme
- `ColorScheme`는 대부분의 위젯 색상에 적용 가능한 color system 클래스입니다.
- 특정 역할에 따라 알맞은 색상을 자동 배정합니다.
	- primary: 핵심 컴포넌트 (활성 상태, 중요 버튼 등)
	- secondary: 세부 컴포넌트
 	- tertiary: primary, secondary와 대조되는 색상

|파라미터|타입|의미|
|---|---|---|
|primary|Color|primary 색상|
|secondary|Color|secondary 색상|
|tertiary|Color|tertiary 색상|
|background|Color|배경 색상|
|outline|Color|테두리 색상|

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

### AnimatedOpacity
- `AnimatedOpacity`는 애니메이션이 적용된 투명도를 제공하는 위젯입니다.
- `duration` 프로퍼티를 통해 애니메이션 지속 시간을 정할 수 있습니다.

```
AnimatedOpacity(
  opacity: _opacityLevel,
  duration: const Duration(seconds: 3),
  child: const FlutterLogo(),
),
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

### FlutterLogo
- `FlutterLogo`는 Flutter의 로고 이미지를 포함한 위젯입니다.

|파라미터|타입|의미|
|---|---|---|
|size|double|로고 크기|

```
FlutterLogo(
  size: 150.0
)
```

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
)
```

### Offset
- `Offset`은 2D 좌표에서 변화량을 의미하는 클래스입니다.

```
Offset(double dx, double dy)
```

## Input
### TextField
- `TextField`는 텍스트를 입력할 수 있는 박스를 제공하는 위젯입니다.
- `onSubmitted` 콜백의 인자의 값은 입력된 텍스트입니다.

|파라미터|타입|의미|
|---|---|---|
|controller|TextEditingController|텍스트 수정을 제어하는 컨트롤러|
|onSubmitted|ValueChanged\<T\>|텍스트 제출시 호출되는 콜백|

```
TextField(
  controller: _controller,
  onSubmitted: (String value) async {
    // value = 입력된 텍스트 값
    ...
  },
)
```

### TextButton
- `TextButton`는 텍스트를 포함한 버튼 위젯입니다.
- `onPressed`는 버튼 누를 시 실행되는 콜백을 값으로 합니다. 만약 이 값이 null이면 버튼은 비활성됩니다.

|파라미터|타입|의미|
|---|---|---|
|onPressed|VoidCallback|버튼 누를 시 실행되는 콜백|
|child|Widget|하위 위젯|
|style|ButtonStyle|버튼 스타일|

```
TextButton(
  style: TextButton.styleFrom(
    textStyle: const TextStyle(fontSize: 20),
  ),
  onPressed: () {},
  child: const Text('Button'),
)
```

### OutlinedButton
- `OutlinedButton`는 테두리가 있는 버튼 위젯입니다.

|파라미터|타입|의미|
|---|---|---|
|onPressed|VoidCallback|버튼 누를 시 실행되는 콜백|
|child|Widget|하위 위젯|
|style|ButtonStyle|버튼 스타일|

```
OutlinedButton(
  onPressed: () {},
  child: const Text('Click Me'),
)
```

### ElevatedButton
- `ElevatedButton`는 Material 디자인이 적용된 버튼 위젯입니다.

|파라미터|타입|의미|
|---|---|---|
|onPressed|VoidCallback|버튼 누를 시 실행되는 콜백|
|child|Widget|하위 위젯|
|style|ButtonStyle|버튼 스타일|

```
ElevatedButton(
  style: ElevatedButton.styleFrom(
    textStyle: const TextStyle(fontSize: 20)
  ),
  onPressed: () {},
  child: const Text('Button'),
)
```

### IconButton
- `IconButton`는 `Icon`을 포함한 버튼 위젯입니다.
- 아이콘의 색상은 `Icon.color`를 우선으로 합니다. (Icon.color 값 존재시 disable되도 아이콘 색은 Icon.color을 따름)

|파라미터|타입|의미|
|---|---|---|
|onPressed|VoidCallback|버튼 누를 시 실행되는 콜백|
|icon|Widget|아이콘 위젯|
|iconSize|double|아이콘 크기|
|color|Color|아이콘 색|
|style|ButtonStyle|버튼 스타일|

```
IconButton(
  iconSize: 32,
  icon: const Icon(Icons.favorite),
  onPressed: () {},
)
```

### Slider
- `Slider`는 슬라이더 입력을 제공하는 위젯입니다.
- `onChanged` 프로퍼티는 콜백을 값으로 합니다.
	- 이 콜백은 드래그를 통해 슬라이더 값이 변경되면 호출되며, 변경된 슬라이더 값을 인자로 합니다.
- UI에 표시되는 슬라이더 현재 값은 `value` 프로퍼티로 표현됩니다.
- 만약 드래그를 통해 실시간으로 UI 슬라이더 값을 업데이트하려면 `onChanged` 콜백에서 `value`을 조정하는 `State.setState`을 호출하면 됩니다. (`StatefulWidget` 필요)

|파라미터|타입|의미|
|---|---|---|
|value|double|현재 값|
|max|double|최댓값|
|min|double|최솟값|
|divisions|int|분할 구간 개수|
|label|String|슬라이드시 표시되는 라벨 값|
|onChanged|ValueChanged\<double\>|값이 변화될 때마다 실행되는 콜백|
|onChangeStart|ValueChanged\<double\>|값 변경 시작시 실행되는 콜백|
|onChangeEnd|ValueChanged\<double\>|값 변경 완료시 실행되는 콜백|

```
Slider(
  value: _sliderValue,
  max: 100,
  divisions: 5,
  label: _sliderValue.round().toString(),
  onChanged: (double value) {
    setState(() {
      _sliderValue = value;
    });
  },
),
```

### RangeSlider
- `RangeSlider`는 범위 슬라이더 입력을 제공하는 위젯입니다.
- 값으로 `RangeValues`가 사용된다는 점을 제외하면 사용법은 `Slider`와 같습니다.

### RangeValues
- `RangeValues`는 범위를 표현하는 클래스입니다.

> RangeValues(double start, double end)

### Checkbox
- `Checkbox`는 체크박스 입력을 제공하는 위젯입니다.
- 체크박스를 클릭하면 `value`가 토글됩니다.

|파라미터|타입|의미|
|---|---|---|
|value|bool|체크 유무|
|onChanged|ValueChanged\<bool?\>|`value` 변경시 실행되는 콜백|
|checkColor|Color|check icon 색|

```
Checkbox(
  checkColor: Colors.white,
  value: checkMode,
  onChanged: (bool? value) {
    setState(() {
      checkMode = !checkMode;
    });
  },
),
```

### Switch
- `Switch`는 스위치 입력을 제공하는 위젯입니다.

|파라미터|타입|의미|
|---|---|---|
|value|bool|체크 유무|
|onChanged|ValueChanged\<bool?\>|`value` 변경시 실행되는 콜백|
|activeColor|Color|값이 true일 때 색|

```
Switch(
  value: _value,
  activeColor: Colors.blue,
  onChanged: _onChanged,
);
```

### DropdownButton
- `DropdownButton`는 아이템 목록 입력을 제공하는 위젯입니다.
- `value`의 값은 여러 `DropdownButton` 중에서 선택된 것의 `value` 값입니다.
- 제너릭은 `value`의 타입을 결정합니다.
- `isExpanded` 프로퍼티는 내부 컨텐츠의 너비를 수평으로 채울지를 결정합니다.

```
DropdownButton<T>(
  value: menuValue,
  icon: const Icon(Icons.arrow_drop_down),
  onChanged: _onChanged,
  isExpanded: true,
  dropdownColor: Colors.grey,
  items: List<DropdownMenuItem<T>>.generate(valueList.length, (index) {
    return DropdownMenuItem<T>(
	value: _valueList[index]['value'],
	child: Text(_valueList[index]['label']);
  }),
),
```

### DropdownMenuItem
- `DropdownButton`의 목록 아이템을 구성하는 위젯입니다.

### PopupMenuButton
- `PopupMenuButton`는 아이템 목록 입력을 제공하는 위젯입니다.
- `DropdownButton`과 비슷하지만, `PopupMenuButton`는 입력 버튼이 선택된 값 텍스트 대신 고정된 아이콘을 표시한다는 점이 다릅니다.

```
PopupMenuButton(
  color: Colors.yellow,
  icon: const Icon(Icons.add, color: ColorPalette.grey),
  onSelected: (value) {
    if (value == 0) {
      // action 0
    } else if (value == 1) {
      // action 1
    }
  },
  itemBuilder: (context) => <PopupMenuEntry>[
    PopupMenuItem(
      value: 0,
      child: Text('action 0'),
    ),
    PopupMenuItem(
      value: 1,
      child: Text('action 1'),
    ),
  ],
),
```

### PopupMenuEntry
- `PopupMenuEntry`는 `PopupMenuButton`의 아이템을 구성하는 위젯입니다.

## Form
### Form
- `Form` 위젯은 폼과 관련된 위젯들의 조상 위젯 역할을 합니다.

|파라미터|타입|의미|
|---|---|---|
|child|Widget|하위 위젯|

```
Form(
  key: _formKey,
  child: Column(
    ...
  ),
)
```

### FormField
- `FormField`는 폼 필드를 제공하는 위젯입니다.
- `Form` 위젯 내부에 있으면 `FormState`의 메소드를 사용할 수 있습니다. (상태 정보 저장, 리셋, 유효성 검사 등)
- `GlobalKey`를 사용하면 `FormField`에 저장된 상태 정보를 다른 필드에서도 가져올 수 있습니다.

### TextFormField
- `TextFormField`는 `TextField`를 포함한 `FormField` 위젯입니다.
- `validator` 콜백은 유효성 검사할 때 호출되는 함수입니다.
  - 이 콜백의 인자는 입력된 텍스트를 값으로 합니다.
  - 오류가 발생하면, 오류 메시지를 반환합니다. 오류가 없다면 null을 반환합니다.

|파라미터|타입|의미|
|---|---|---|
|decoration|InputDecoration|텍스트 데코레이션|
|validator|FormFieldValidator\<String\>|유효성 검사 콜백|

```
TextFormField(
  decoration: const InputDecoration(
    hintText: 'Enter your ID',
  ),
  validator: (String? value) {
    if (value == null || value.isEmpty) {
      return 'empty text';
    }
    return null;
  },
)
```

## Detector
### GestureDetector
- `GestureDetector`는 제스처를 감지하는 위젯입니다.
- `child` 내에서 특정 제스처를 감지하면 알맞은 콜백을 호출합니다. (각 제스처에 대한 콜백은 파라미터를 통해 설정할 수 있습니다.)

|파라미터|타입|의미|
|---|---|---|
|child|Widget|하위 위젯|

```
GestureDetector(
  onTap: () {
    setState(() {
      _lightIsOn = !_lightIsOn;
    });
  },
  child: Container(
    child: Text(_lightIsOn ? 'TURN LIGHT OFF' : 'TURN LIGHT ON'),
  ),
)
```
- `GestureDetector`에서 제스처 콜백 종류는 다음이 있습니다.

#### Tap
- onTapDown
- onTapUp
- onTap
- onTapCancel

#### Double tap
- onDoubleTap

#### Long press
- onLongPress

#### Vertical Drag
- onVerticalDragStart
- onVerticalDragUpdate
- onVerticalDragEnd

#### Horizontal Drag
- onHorizontalDragStart
- onHorizontalDragUpdate
- onHorizontalDragEnd

### WillPopScope
- `WillPopScope`은 현재 페이지가 pop될 때 실행되는 콜백을 제공하는 위젯입니다.
- `WillPopCallback`은 Future\<bool\>을 반환합니다. 만약 값이 true면 pop이 실행되고, false면 pop이 실행되지 않습니다.
	- 이 점을 활용해서 뒤로가기 버튼을 통한 페이지 종료를 방지할 수 있습니다.

|파라미터|타입|의미|
|---|---|---|
|child|Widget|하위 위젯|
|onWillPop|WillPopCallback|하위 위젯|

```
WillPopScope(
  child: Scaffold(
    ...
  ),
onWillPop: () {
  return Future<bool>.value(false);
},
```

### AppLifecycleState
- `AppLifecycleState`는 애플리케이션 구동 상태를 정의한 enum입니다.
- 구체적인 상태의 내용은 OS마다 다를 수 있습니다.

1. `detached`: 뷰 없이 플러터 엔진만 작동되는 상태 (애플리케이션이 종료되기 직전)
2. `resumed`: 뷰가 제공되고 사용자의 입력도 받는 상태
3. `inactive`: 최소한의 뷰만 제공되며 사용자의 입력은 받지 않는 상태
4. `paused`: 뷰가 제공되지 않고 사용자의 입력도 받지 않는 상태 (Android, iOS 한정 상태)
5. `hidden`: 뷰가 숨겨진 상태

```
Android 기준 상태
백그라운드 전환: `resumed` > `inactive` > `paused`
포그라운드 전환: `paused`> `inactive` > `resumed`
```

### WidgetsBindingObserver
- `WidgetsBindingObserver`는 애플리케이션의 `AppLifecycleState`에 대한 콜백을 추가하는 mixin입니다.
- 적용할 위젯에 mixin으로 추가됩니다.
- 위젯 생성시 `addObserver`, 위젯 제거시 `removeObserver`를 호출해야 합니다.
- `didChangeAppLifecycleState`을 오버라이드해서 상태에 맞는 콜백을 추가할 수 있습니다. (이 메소드는 `AppLifecycleState`을 인자로 합니다.)

```
class _PageState extends State<Page> with WidgetsBindingObserver {
  @override
  void initState() {
    super.initState();
    WidgetsBinding.instance?.addObserver(this);
  }

  @override
  void dispose() {
    WidgetsBinding.instance?.removeObserver(this);
    super.dispose();
  }

  @override
  void didChangeAppLifecycleState(AppLifecycleState state) {
    switch (state) {
      case AppLifecycleState.resumed:
        ...
        break;
      case AppLifecycleState.inactive:
        ...
        break;
      case AppLifecycleState.detached:
        ...
        break;
      case AppLifecycleState.paused:
        ...
        break;
      default:
        ...
        break;
    }
  }
  ...
}
```

### NotificationListener
- `NotificationListener`은 `Notification`을 감지하는 위젯입니다.
- 스크롤의 움직임을 감지할 때 사용할 수 있습니다.

```
NotificationListener<ScrollNotification>(
  onNotification: (scrollNotification) {
    if (scrollNotification is ScrollEndNotification) {
      // scroll is end.
    }
    return true;
  },
  child: ...
)
```

## Key
- Key는 위젯을 식별하는 용도로 사용됩니다.
- 일반적인 `StatefulWidget`은 Key를 저장하는 `key` 프로퍼티를 가지고 있습니다.
- 보통 Key는 자주 쓰이지는 않습니다. 그러나 `StatefulWidget`의 순서나 개수를 변경할 때 Key가 사용됩니다.

### Widget-Element Matching
- Fluter에서 위젯들은 트리 구조로 구성되어 있으며, Element 역시 트리 구조를 이룹니다. 만약 위젯 트리에서 업데이트가 발생하면, Element 트리에서도 업데이트가 발생합니다.
- Flutter가 Element 트리를 참조할 때, 각 Element가 알맞은 위젯과 대응되었는지 확인합니다. `StatelessWidget`일 경우 Type만 확인하며, `StatefulWidget`일 경우 Type과 Key 모두를 확인합니다.
```
Widget Tree            Element Tree

Row                    Row
|                      |
|-- Tile(Key:1)        |-- Tile(Key:1) -- State A
|                      |
|-- Tile(Key:2)        |-- Tile(Key:2) -- State B
```

- 위젯 트리에서 `Row`의 두 하위 위젯 순서를 바꿔봅시다. Flutter가 Element 트리를 탐색하면서 각 Element가 알맞은 위젯에 대응되었는지 확인합니다. 아래 예시에선 Type은 일치하나, Key는 일치하지 않습니다.
```
Widget Tree            Element Tree

Row                    Row
|                      |
|-- Tile(Key:2)        |-- Tile(Key:1) -- State A
|                      |
|-- Tile(Key:1)        |-- Tile(Key:2) -- State B
```

- 불일치한 Element는 비활성되고 Element 트리에서 삭제됩니다. 이후, Flutter는 위젯 트리의 알맞은 레벨로 이동하여 적합한 위젯이 있는지를  탐색합니다.
  - 알맞은 위젯을 찾으면, 해당 위젯과 Element를 대응하고 Element 트리를 업데이트합니다.
  - 알맞은 위젯을 찾지 못하면, 해당 위젯에 대응하는 새로운 Element를 생성합니다.
- 아래 예시에는 적합한 위젯이 존재하므로, 각 Element가 알맞은 위젯과 매칭됩니다. (만약 key가 없다면 타입만 비교될 것이며, Element의 순서가 바뀌지 않을 것입니다.)
```
Widget Tree            Element Tree

Row                    Row
|                      |
|-- Tile(Key:2)        |-- Tile(Key:2) -- State B
|                      |
|-- Tile(Key:1)        |-- Tile(Key:1) -- State A
```

- Flutter의 위젯-Element 매칭 알고리즘은 트리의 레벨 단위로 진행됩니다.
- 탐색은 트리의 최상단부터 시작하며, 레벨 단위로 탐색합니다. (정확히는 동일한 부모 노드를 가지는 노드 집합을 탐색 단위로 합니다.) 불일치한 Element를 발견할 때 알맞은 위젯을 찾는 과정도 마찬가지입니다.
- 위 예제에서 각 타일이 `Container` 위젯으로 감싸진 상태에서 `Tile`의 순서를 바꿔봅시다. (Key는 `LocalKey`로 가정합니다.)
```
Widget Tree             Element Tree

Row                     Row
|                       |
| -- Container          | -- Container
|    |-- Tile(Key:2)    |    |-- Tile(Key:1) -- State A
|                       |
| -- Container          | -- Container
     |-- Tile(Key:1)         |-- Tile(Key:2) -- State B
```

- 이번에는 각 Element에 대해 알맞은 위젯을 찾지 못합니다. 따라서 새로운 Element가 생성됩니다. (기존 `State` 정보가 초기화됩니다.)
```
Widget Tree             Element Tree

Row                     Row
|                       |
| -- Container          | -- Container
|    |-- Tile(Key:2)    |    |-- Tile(Key:2) -- State C
|                       |
| -- Container          | -- Container
     |-- Tile(Key:1)         |-- Tile(Key:1) -- State D
```

- 문제를 해결하려면 Key는 유지해야 하는 상태 정보가 있는 최상단 위젯에 추가되어야 합니다.
- 아래 예제에서 `Container`에 Key를 등록하면 문제가 해결됩니다.
```
Widget Tree             Element Tree

Row                     Row
|                       |
| -- Container(Key:2)   | -- Container(Key:2)
|    |-- Tile           |    |-- Tile -- State B
|                       |
| -- Container(Key:1)   | -- Container(Key:1)
     |-- Tile                |-- Tile -- State A
```

### GlobalKey
- `GlobalKey`는 앱 전체에서 고유한 Key를 가지는 Key 클래스입니다.
- `GlobalKey`은 주로 다음 용도로 사용됩니다.
  - 정보를 유지하며 위젯의 부모를 변경할 수 있습니다.
  - 어떤 위젯의 정보를 다른 위젯 트리에서 접근할 수 있습니다.
- 일반적으로 `GlobalKey`를 갖는 Element를 매칭할 때는 `LocalKey`에 비해 비용이 비쌉니다.

### LocalKey
- `LocalKey`는 `GlobalKey`가 아닌 Key 클래스입니다.
- `LocalKey`의 Key는 같은 부모 노드를 가지는 위젯 집합 내에서만 유일성을 갖습니다.

### UniqueKey
- `UniqueKey`는 고유 키를 생성하는 클래스입니다.

## Navigator
### Route
- `Route`는 `Navigator`에서 아이템인 추상 클래스입니다.

### MaterialPageRoute
- `MaterialPageRoute`은 모달(Modal) Route 클래스입니다.
- 기본적으로 플랫폼 친화적인 트랜지션(transition)이 적용되어 있습니다.

### Navigator
- `Navigator`는 `Route` 위젯들을 스택 구조로 관리하는 위젯입니다.
- 대부분의 앱에서 네비게이터는 위젯 트리의 최상단에 위치합니다.

#### 페이지 추가
- `Navigator.push` 메소드를 사용합니다.
- `context`와 밀접한 `Navigator`에서 `route`를 가장 위쪽에 추가합니다.

> Navigator.push(BuildContext context, Route<T> route)

```
Navigator.push(context, MaterialPageRoute<void>(
    builder: (BuildContext context) {
        return Scaffold(
            appBar: AppBar(title: const Text('My Page')),
            body: Center(
                child: TextButton(
                    child: const Text('POP'),
                    onPressed: () {
                        Navigator.pop(context);
                    },
                ),
        ),
        );
    },
));
```

- 만약 이름이 있는 Route를 추가한다면 `Navigator.pushNamed` 메소드를 사용하면 됩니다. (동작은 `Navigator.push`와 같습니다.)

> Navigator.pushNamed(`context`, `routeName`);

#### 페이지 삭제
- `Navigator.pop` 메소드를 사용합니다.
- `context`와 밀접한 `Navigator`에서 가장 위쪽에 있는 Route를 삭제합니다.

> Navigator.pop(BuildContext context)

```
Navigator.pop(context);
```

#### 페이지 이름
- Route를 관리하는 가장 쉬운 방법은 주소 형식의 이름을 사용하는 것입니다. (ex. `/menu/status`)
- 홈페이지의 주소는 보통 `/`으로 합니다.
- `MaterialApp`의 `routes` 파라미터는 `Map<String, WidgetBuilder>`을 인자로 합니다. 값을 추가하면 `MaterialApp`이 해당 `Navigator`에 주어진 Route를 추가하는 콜백을 호출합니다.

```
void main() {
    runApp(MaterialApp(
        home: const MyAppHome(),
        routes: <String, WidgetBuilder> {
            '/a': (BuildContext context) => const MyPage(title: Text('page A')),
            '/b': (BuildContext context) => const MyPage(title: Text('page B')),
            '/c': (BuildContext context) => const MyPage(title: Text('page C')),
        },
    ));
}
```

#### 페이지 반환
- `Navigator.pop`의 2번째 인자는 해당 페이지를 생성한 `Navigator.push` 메소드가 반환하는 Future의 잠재적 값이 됩니다.
- 아래 예제에서 `value`의 값은 `Navigator.pop`의 2번째 인자이며, 타입은 `Navigator.push`의 2번째 인자로 제공한 `MaterialPageRoute`의 제너릭 타입과 같습니다.

```
bool? value = await Navigator.push(context, MaterialPageRoute<bool>(
  builder: (BuildContext context) {
    return Center(
      child: GestureDetector(
        child: const Text('OK'),
        onTap: () { Navigator.pop(context, true); }
      ),
    );
  }
));
```

#### 페이지 인자
- `Navigator.pushNamed`의 3번째 선택 인자 `arguments`를 통해서 페이지에 인자를 전달할 수 있습니다.
- 인자의 타입은 String, int 등이 사용됩니다. (보통 Map을 사용합니다.) 
- 전달한 인자는 해당 페이지의 생성자로 전달됩니다.

> Navigator.pushNamed(`context`, `routeName`, `arguments`);

```
class StatusRoute {
  StatusRoute({ required this.name, required this.level });
  final String name;
  final String level;
}

void navigate() {
  Navigator.pushNamed(
    context,
    '/status',
    arguments: StatusRoute(name: 'Steve', level: 5),
  );
}
```

## Asyncronous
### Timer
- `Timer`는 주어진 시간 뒤에 실행되는 콜백을 제공하는 클래스입니다.
- `cancel` 메소드로 해당 `Timer`를 취소할 수 있습니다.
- 일시정지는 제공되지 않습니다.

> Timer(Duration duration, void callback())
- `duration` 시간 뒤에 주어진 콜백을 실행합니다.

> Timer.periodic(Duration duration, void callback(Timer timer))
- `duration` 시간마다 주어진 콜백을 실행합니다.

### Stopwatch
- `Stopwatch`는 경과 시간을 측정하는 클래스입니다.

|프로퍼티|타입|의미|
|---|---|---|
|elapsed|Duration|경과 시간|

|메소드|기능|
|---|---|
|reset|리셋|
|start|시작|
|stop|중지|

## dart:async
### Stream
- `Stream`은 비동기 이벤트를 다룰 때 사용되는 클래스입니다.
- `Stream`은 크게 2가지 종류로 구분할 수 있습니다.
	- `single subscription`: 한 곳에서만 listen이 가능합니다.
	- `broadcast`: 여러 곳에서 listen이 가능합니다.

|생성자|기능|
|---|---|
|Stream()|`Stream` 생성|
|Stream.empty()|broadcast `Stream` 생성|
|Stream.fromFuture()|단일 Future를 구독한 `Stream` 생성|
|Stream.periodic()|주기적으로 동작하는 `Stream` 생성|

|메소드|기능|
|---|---|
|take()|현재 `Stream`에서 주어진 횟수만큼 실행되는 `Stream` 반환|
|where()|현재 `Stream`에서 특정 조건일 때만 실행되는 `Stream` 반환|
|listen()|현재 `Stream`에서 값 업데이트시 실행되는 콜백 설정 및 `StreamSubscription` 반환|

#### Stream.periodic
- 주기적으로 동작하는 `Stream` 생성합니다.
- `take` 메소드를 사용해서 실행 횟수를 제한할 수 있습니다.

```
// 0.5초마다 40번 실행되는 Stream 생성
// x: 0 → 39
// 반환값: 0.0 → 0.9...

int delay = 20000;
Stream<double> stream = Stream.periodic(
  const Duration(milliseconds: 500),
  (x) => x * 1.0 / (delay / 500))
  .take(delay ~/ 500);
```

#### Stream.where
- `where` 메소드는 `Stream`이 실행되는 조건을 설정합니다.

```
// state이 ProcessingState.completed일 때만 실행되는 Stream 생성

audioPlayer.processingStateStream
  .where((state) => state == ProcessingState.completed)
  .listen((state) {
    ...
  }
);
```

#### Stream.listen
- `listen` 메소드는 `Stream` 계산값 변동시 실행되는 콜백을 설정합니다.
- 반환되는 `StreamSubscription`을 통해서 `Stream`을 제어할 수 있습니다.

```
// 5초 뒤에 seekToNext() 메소드 실행하는 Future를 구독한 Stream 생성

StreamSubscription<void> subscription = Stream<void>.fromFuture(
  Future<void>.delayed(Duration(milliseconds: 5000), () {}))
  .listen((x) {
    seekToNext();
  }
);
```

### StreamController
- `StreamController`는 `Stream`을 제어하는 클래스입니다.
- 기본적으로 `Stream`을 포함하고 있으며, 주어진 메소드를 통해 이 `Stream`을 제어합니다.
- `add` 메소드 실행시 현재 `Stream`의 이벤트가 수행됩니다.
	- 이때 해당 `Stream`과 연결된 `StreamBuilder`의 빌드가 수행됩니다.

|생성자|기능|
|---|---|
|StreamController()|`Stream`을 포함한 `StreamController` 생성|
|StreamController.broadcast()|broadcast `Stream`을 포함한 `StreamController` 생성|

|프로퍼티|타입|의미|
|---|---|---|
|stream|Stream|현재 포함된 `Stream`|
|onCancel|Function|`Stream` 취소시 실행되는 콜백|
|onListen|Function|`Stream` 값 업데이트시 실행되는 콜백|
|onPause|Function|`Stream` 일시정지시 실행되는 콜백|
|onResume|Function|`Stream` 재개시 실행되는 콜백|

|메소드|기능|
|---|---|
|add()|`Stream`에 특정 값 전송|
|close()|`Stream` 종료|

```
StreamController<bool> streamController = StreamController<bool>.broadcast();
StreamBuilder<bool> streamBuilder(builder) => StreamBuilder<bool>(
  stream: streamController.stream,
  builder: builder,
);
...
streamController.add(true); // streamBuilder 빌드 수행
...
streamController.close();
```

### StreamSubscription
- `StreamSubscription`는 특정 `Stream`을 구독하는 추상 클래스입니다.
- 주로 `Stream.listen` 메소드에서 반환되는 인스턴스를 사용합니다.
- 특정 `Stream`을 일시정지하는 용도로 사용할 수 있습니다.

|프로퍼티|타입|의미|
|---|---|---|
|isPaused|bool|현재 일시정지면 true|

|메소드|기능|
|---|---|
|onData()|`Stream` 값 업데이트시 실행되는 콜백 (설정 가능)|
|onDone()|`Stream` 종료시 실행되는 콜백 (설정 가능)|
|pause()|`Stream` 일시정지|
|resume()|`Stream` 재개|
|cancel()|`Stream` 연결 끊기|

```
StreamSubscription<double> subscription = stream.listen((x) {
    print(x);
  }, onDone: () {
    print('End');
  }
);
...
subscription.pause();
...
subscription.resume();
```

## dart.io
### Directory
- `Directory`는 디렉터리를 표현하는 클래스입니다.
- `list` 메소드를 통해서 디렉터리에 포함된 파일과 서브 디렉터리를 가져올 수 있습니다.
	- 이 메소드의 `recursive` 파라미터를 true로 하면 서브 디렉터리 내부의 파일들도 가져올 수 있습니다.

|프로퍼티|타입|의미|
|---|---|---|
|path|String|디렉터리 경로|

|메소드|반환|기능|
|---|---|---|
|list()|Stream<\FileSystemEntity\>|해당 디렉터리에 포함된 파일, 서브 디렉터리를 Stream으로 반환|
|listSync()|List\<FileSystemEntity\>|`list`의 출력을 List로 반환|

### FileSystemEntity
- `FileSystemEntity`은 `File`, `Directory`, `Link`의 상위 클래스입니다.

|프로퍼티|타입|의미|
|---|---|---|
|path|String|파일 경로|
|uri|Uri|`Uri` 반환|

|static 메소드|반환|기능|
|---|---|---|
|isDirectory()|Future\<bool\>|현재 엔티티가 디렉터리면 true 반환|
|isDirectorySync()|bool|`isDirectory`와 동일|

### Uri
- `Uri`는 URI를 표현하는 클래스입니다.

|프로퍼티|타입|의미|
|---|---|---|
|pathSegments|List\<String\>|분할된 경로 문자열 목록 반환|

## Performance
간혹 Flutter 애플리케이션 구동 시 프레임 저하 등 성능 이슈가 발생할 수 있습니다. 성능 이슈의 원인은 주로 다음이 있습니다.

1. 비싼 빌드 비용
2. 비효율적인 애니메이션

빌드를 많이 할수록, 빌드하는 위젯이 많을수록 비용이 증가합니다. 그러므로 빌드 횟수 및 빌드할 위젯의 개수는 가급적 최소화하는 것이 좋습니다.
추가로, 런타임 중간에 변하지 않는 위젯은 `const`로 하는 것이 좋습니다. Flutter가 빌드를 다시 수행하면 `const` 위젯은 이미 존재시 스킵되므로 전체적인 빌드 효율이 향상됩니다.

## Example
### StatelessWidget
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

### StatefulWidget
- 버튼을 누르면 가운데 수가 1씩 증가합니다.

```
import 'package:flutter/material.dart';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: const StatefulWidgetExample(title: 'Stateful Example'),
      debugShowCheckedModeBanner: false,
    );
  }
}

class StatefulWidgetExample extends StatefulWidget {
  const StatefulWidgetExample({super.key, required this.title});
  final String title;

  @override
  State<StatefulWidgetExample> createState() => _StatefulWidgetExampleState();
}

class _StatefulWidgetExampleState extends State<StatefulWidgetExample> {
  int _counter = 0;

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text(widget.title),
      ),
      body: Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: <Widget>[
            const Text(
              'Button Counting',
            ),
            Text(
              '$_counter',
              style: Theme.of(context).textTheme.headlineMedium,
            ),
          ],
        ),
      ),
      floatingActionButton: FloatingActionButton(
        onPressed: () {
          setState(() {
            _counter++;
          });
        },
        child: const Icon(Icons.add),
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

### DraggableScrollableSheet
- 드래그해서 확장 가능한 컨테이너입니다.
- 화살표 버튼을 누르면 확장/축소를 토글할 수 있습니다.

```
import 'package:flutter/material.dart';

void main() {
  runApp(MaterialApp(home: HomePage()));
}

class HomePage extends StatefulWidget {
  const HomePage({super.key});

  @override
  State<HomePage> createState() => _HomePageState();
}

class _HomePageState extends State<HomePage> {
  final minChildSize = 0.1;
  final maxChildSize = 0.9;
  bool _isExpand = false;

  @override
  Widget build(BuildContext context) {
    DraggableScrollableController controller = DraggableScrollableController();
    return Scaffold(
      body: DraggableScrollableSheet(
        initialChildSize: minChildSize,
        minChildSize: minChildSize,
        maxChildSize: maxChildSize,
        controller: controller,
        builder: (BuildContext context, ScrollController scrollController) {
          return Container(
            color: Colors.grey[100],
            child: ListView.builder(
              controller: scrollController,
              itemCount: 11,
              itemBuilder: (BuildContext context, int index) {
                return index == 0 ?
                  ListTile(
                    title: Icon(_isExpand ? Icons.arrow_drop_down : Icons.arrow_drop_up),
                    onTap: () async {
                      await controller.animateTo(_isExpand ? minChildSize : maxChildSize,
                          duration: const Duration(milliseconds: 500),
                          curve: Curves.easeInOutQuart);
                      setState(() {
                        _isExpand = !_isExpand;
                      });
                    }
                  )
                  : ListTile(
                    title: Text('$index'),
                  );
              },
            ),
          );
        },
      ),
    );
  }
}
```

![](images/Flutter-Example-DraggableScrollableSheet.png)

### MaterialStateProperty
- 버튼을 터치하면 색상 애니메이션이 재생됩니다.

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
          child: MaterialStatePropertyExample(),
        ),
      ),
    );
  }
}

class MaterialStatePropertyExample extends StatelessWidget {
  const MaterialStatePropertyExample({super.key});

  @override
  Widget build(BuildContext context) {
    return TextButton(
      style: ButtonStyle(
        foregroundColor: MaterialStateProperty.resolveWith((Set<MaterialState> states) {
          const Set<MaterialState> interactiveStates = <MaterialState>{
            MaterialState.pressed,
            MaterialState.hovered,
            MaterialState.focused,
          };
          if (states.any(interactiveStates.contains)) {
            return Colors.blue;
          }
          return Colors.red;
        }),
      ),
      onPressed: () {},
      child: const Text('Button'),
    );
  }
}
```

![](images/Flutter-Example-MaterialStateProperty.png)

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

### Slider
- 슬라이드바를 조절할 수 있습니다.

```
import 'package:flutter/material.dart';

void main() => runApp(MyApp());

class MyApp extends StatelessWidget {
  
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: Scaffold(
        body: Center(
          child: SliderExample(),
        ),
      ),
    );
  }
}

class SliderExample extends StatefulWidget {
  const SliderExample({super.key});

  @override
  State<SliderExample> createState() => _SliderExampleState();
}

class _SliderExampleState extends State<SliderExample> {
  double sliderValue = 0;

  @override
  Widget build(BuildContext context) {
    return Slider(
      value: sliderValue,
      max: 100,
      divisions: 5,
      label: sliderValue.round().toString(),
      onChanged: (double value) {
        setState(() {
          sliderValue = value;
        });
      },
    );
  }
}
```

![](images/Flutter-Example-Slider.png)

### Form
- `TextFormField`를 포함한 `Form`입니다.
- ID를 입력하고 제출할 수 있습니다.
- 빈 텍스트는 제출할 수 없습니다.

```
import 'package:flutter/material.dart';

void main() => runApp(const MyApp());

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: Scaffold(
        appBar: AppBar(title: const Text('Form App')),
        body: const FormExample(),
      ),
    );
  }
}

class FormExample extends StatefulWidget {
  const FormExample({super.key});

  @override
  State<FormExample> createState() => _FormExampleState();
}

class _FormExampleState extends State<FormExample> {
  final GlobalKey<FormState> _formKey = GlobalKey<FormState>();

  @override
  Widget build(BuildContext context) {
    return Form(
       key: _formKey,
      child: Column(
        crossAxisAlignment: CrossAxisAlignment.start,
         children: <Widget>[
          TextFormField(
             decoration: const InputDecoration(
               hintText: 'Enter your ID',
            ),
            validator: (String? value) {
              if (value == null || value.isEmpty) {
                return 'Please enter some text';
              }
               return null;
            },
          ),
          Padding(
            padding: const EdgeInsets.symmetric(vertical: 16.0),
            child: ElevatedButton(
              onPressed: () {
                if (_formKey.currentState!.validate()) {
                   // submit 완료
                }
              },
              child: const Text('Submit'),
            ),
          ),
        ],
      ),
    );
  }
}
```

![](images/Flutter-Example-Form.png)

### GestureDetector
- 버튼을 누르면(`GestureDetector.onTap`) 전구 아이콘의 색이 변합니다.

```
import 'package:flutter/material.dart';

void main() => runApp(const MyApp());

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  @override
  Widget build(BuildContext context) {
    return const MaterialApp(
      home: GestureDetectorExample(),
    );
  }
}

class GestureDetectorExample extends StatefulWidget {
  const GestureDetectorExample({super.key});

  @override
  State<GestureDetectorExample> createState() => _GestureDetectorExampleState();
}

class _GestureDetectorExampleState extends State<GestureDetectorExample> {
  bool _lightIsOn = false;

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      body: Container(
        alignment: FractionalOffset.center,
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: <Widget>[
            Padding(
              padding: const EdgeInsets.all(8.0),
              child: Icon(
                Icons.lightbulb_outline,
                color: _lightIsOn ? Colors.yellow.shade600 : Colors.black,
                size: 60,
              ),
            ),
            GestureDetector(
              onTap: () {
                setState(() {
                  _lightIsOn = !_lightIsOn;
                });
              },
              child: Container(
                color: Colors.yellow.shade600,
                padding: const EdgeInsets.all(8),
                child: Text(_lightIsOn ? 'TURN LIGHT OFF' : 'TURN LIGHT ON'),
              ),
            ),
          ],
        ),
      ),
    );
  }
}
```

![](images/Flutter-Example-GestureDetector.png)

### Navigator
- 3개의 페이지가 있습니다.
- 홈페이지의 버튼 2개를 통해 각 페이지로 이동할 수 있습니다.

```
import 'package:flutter/material.dart';

void main() {
  runApp(MaterialApp(
    initialRoute: '/',
    routes: {
      '/': (context) => const HomeRoute(),
      '/second': (context) => const SecondRoute(),
      '/third': (context) => const ThirdRoute(),
    },
  ));
}

class HomeRoute extends StatelessWidget {
  const HomeRoute({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text('Home'),
        backgroundColor: Colors.yellow,
      ),
      body: Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: <Widget>[
            ElevatedButton(
              child: const Text('Second!'),
              onPressed: () {
                Navigator.pushNamed(context, '/second');
              },
            ),
            ElevatedButton(
              child: const Text('Third!'),
              onPressed: () {
                Navigator.pushNamed(context, '/third');
              },
            ),
          ],
        ),
      ),
    );
  }
}

class SecondRoute extends StatelessWidget {
  const SecondRoute({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text("Second Page"),
        backgroundColor: Colors.blue,
      ), // AppBar
      body: Center(
        child: ElevatedButton(
          onPressed: () {
            Navigator.pop(context);
          },
          child: const Text('Back!'),
        ),
      ),
    );
  }
}

class ThirdRoute extends StatelessWidget {
  const ThirdRoute({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text("Third Page"),
        backgroundColor: Colors.green,
      ),
    );
  }
}
```

![](images/Flutter-Example-Navigator.png)

## Reference
https://www.geeksforgeeks.org/flutter-tutorial/

https://api.flutter.dev/index.html

**Key**
https://nsinc.tistory.com/214

**Performance**
https://www.blog.finotes.com/post/frame-rate-issues-in-flutter-apps-and-how-to-solve-them
