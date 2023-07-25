# CSS
W3C에서 제작한 `CSS(Cascading Style Sheets)`는 HTML 요소들이 보여지는 것을 정의하는 스타일 시트 언어다.

CSS는 HTML 문서를 꾸미는데 특화되어 있으며, HTML에서 스타일 관련 속성이나 스크립트는 CSS로 분리하는 것이 좋다. 또한 CSS 스크립트는 별도 파일로 분리할 수 있어 유지 보수성이 향상된다. (확장자 = .css)

## 문법
CSS 스크립트의 문법은 다음과 같다.

```
selector { property1: value1; property2: value2; ... }

selector = 선택자
property = 속성명
value = 속성값
```

- `선택자(selector)`는 CSS를 적용할 HTML 요소를 지시한다.
- 선언부에는 `속성(property): 값(value);` 구조로 나열한다.

### 주석 (Comment)
CSS의 주석은 `/* */`를 사용한다.

```
/* comment */
```

## 기본 (Basic)
### 색상 (Color)
HTML 색상과 동일.

### 배경 (Background)

|속성|값|기능|
|---|---|---|
|background||이하 속성들을 한꺼번에 적용할 수 있음 (공백으로 구분)|
|background-color|color|배경 색|
|background-image|url|배경 이미지|
|background-repeat|`repeat-x`,`repeat-y`,`no-repeat`|배경 이미지 반복 설정 (수평 반복, 수직 반복, 반복 없음)|
|background-position|px px|반복되지 않는 배경 이미지 상대 위치|
|background-attachment|`fixed`|배경 이미지 위치 고정 (스크롤해도 위치 변동 없음)|

```
<style>
	div { 
		background-color: grey;
		background-image: url("/image/background.png");
		background-repeat: repeat-x;
		background-position: right center;
		background-attachment: fixed;
	}
</style>
```

```

<style>
	div { 
		background: grey ​url("/image/background.png") repeat-x ​right center fixed;
	}
</style>
```

- background-image는 여러 값을 가질 수 있다. 이때는 여러 이미지가 배경으로 적용되며, 앞에 있는 이미지가 위쪽에 나타난다.

### 텍스트(Text)

|속성|값|기능|
|---|---|---|
|color|color|텍스트 색상|
|direction|`ltr`,`rtl`|텍스트 방향 (left-to-right, right-to-left)|
|letter-spacing|px|텍스트 내에서 글자 사이 간격|
|word-spacing|px|텍스트 내에서 단어 사이 간격|
|text-indent|px|단락의 첫 줄 들여쓰기 간격|
|text-align|`left`,`center`,`right`|텍스트 수평 정렬 방향|
|text-decoration|`overline`,`line-through`,`underline`,`none`|텍스트 효과 (윗줄, 취소선, 밑줄, 없음)|
|text-transform|`uppercase`,`lowercase`,`capitalize`|대소문자 설정 (전체 대문자, 전체 소문자, 단어 첫 문자만 대문자)|
|line-height|float|텍스트의 줄 간격|
|text-shadow|px px color|텍스트 그림자 효과 (가로 상대 위치, 세로 상대 위치, 그림자 색상)|

```
<style>
	div { 
		color: orange;
		direction: ltr;
		letter-spacing: 2px;
		word-spacing: 10px;
		text-indent: 10px;
		text-align: center;
		text-decoration: underline;
		text-transform: capitalize;
		line-height: 0.8;
		text-shadow: 2px 1px grey;
	}
</style>
```

### 글꼴 (Font)

|속성|값|기능|
|---|---|---|
|font-family|font1, font2, ...|적용할 글꼴 목록. 왼쪽부터 우선 적용하며 현재 글꼴이 없으면 우측 것을 반영. 글꼴명이 여러 단어면 "" 사용|
|font-style|`normal`, `italic`|글꼴 모양 (일반, 기울임체)|
|font-variant|`normal`, `small-caps`|소문자 변형 (일반, 영소문자를 작은 대문자로 변경)|
|font-weight|`lighter`, `normal`, `bold`, `bolder`, number|글꼴 두께 (수치 직접 입력 가능)|
|font-size|%, em, px|글꼴 크기. %, em은 기본값이 각각 100, 1인 상대적 크기(둘러싼 HTML 요소의 크기에 영향을 받음), px는 절대적 크기(주변 관계없이 고정된 크기)|

```
<style>
	div { 
		font-family: "Times New Roman", sans-serif, serif;
		font-style: italic;
		font-variant: small-caps;
		font-weight: lighter;
		font-size: 1.5em;
	}
</style>
```
### 링크 (Link)

|속성|값|기능|
|---|---|---|
|background-color|color|링크 배경 색|
|color|color|링크 글자 색|
|font-size|%, em, px|링크 글꼴 크기|
|text-decoration|`overline`,`line-through`,`underline`,`none`|링크 텍스트 효과 (윗줄, 취소선, 밑줄, 없음)|

#### 링크 상태

1. link: 기본 상태. 사용자가 링크를 방문하지 않음
2. visited: 사용자가 링크를 1번 이상 방문한 상태
3. hover: 사용자가 마우스 커서를 링크 위에 올려둔 상태
4. active: 사용자가 링크를 클릭하는 중인 상태
5. focus: 키보드/마우스 이벤트 등이 링크에 포커스를 가진 상태

```
<style>
	a:visited { 
		color: yellow;
		font-decoration: none;
	}
</style>
```

### 리스트 (List)

|속성|값|기능|
|---|---|---|
|list-style||이하 속성들을 한꺼번에 적용할 수 있음|
|list-style-type|`circle`, `square`, `upper-alha`, `lower-roman` ...|마커(리스트 요소 앞에 위치한 숫자/기호) 설정|
|list-style-image|url|마커를 이미지로 설정|
|list-style-position|`outside`, `inside`|리스트 요소의 위치 설정 (기본값 = `outside`)|

```
<style>
	ul { 
		list-style-type: square;
		list-style-position: inside;
	}
</style>
```

### 테이블 (Table)

|속성|값|기능|
|---|---|---|
|border||border 속성들을 한꺼번에 적용할 수 있음|
|border-collapse|`collapse`, `seperate`|`collapse` 설정시 테이블 테두리가 한 줄로 표현됨|
|border-spacing|px px|테이블 요소간 여백 설정|
|text-align|`left`, `center`, `right`|테이블 요소 내 텍스트 수평 방향 정렬|
|vertical-align|`top`, `center`, `bottom`|테이블 요소 내 텍스트 수직 방향 정렬|

```
<style>
	table { 
		border-collapse: collapse;
		border-spacing: 20px 10px
	}
	td {
		text-aligh: left;
		vertical-align: bottom;
	}
</style>
```

### 이미지 스프라이트 (Image Sprite)
`이미지 스프라이트(image sprite)`는 여러 개의 이미지를 1개의 이미지로 통합해서 관리하는 이미지다. 여러 개의 이미지를 로딩하려면 이미지 개수만큼 요청을 여러 번 해야하지만, 이미지 스프라이트를 사용하면 단 1번만 요청하면 되므로 시간이 단축된다. 웹 페이지, 게임 그래픽 등에 활용된다.

아래와 같은 이미지 스프라이트가 있을 때,

```
@$%&
```

다음과 같이 4개의 이미지로 분리해서 활용할 수 있다.

```
@
$
%
&
```

```
<style>
	.icon1 .icon2 .icon3 .icon4 { background: url("/icon_sprite.png"); }
	.icon1 { width: 20px; height: 20px; background-position: 0 0; }
	.icon2 { width: 20px; height: 20px; background-position: -20px 0; }
	.icon3 { width: 20px; height: 20px; background-position: -40px 0; }
	.icon4 { width: 20px; height: 20px; background-position: -60px 0; }
</style>
<div class="icon1"></div><br>
<div class="icon2"></div><br>
<div class="icon3"></div><br>
<div class="icon4"></div><br>
```

## 모델 (Model)
### 크기 단위
CSS에서 주로 쓰는 단위는 다음과 같다.

- 픽셀(px): 스크린의 절대적인 픽셀 크기
- 백분율(%): 기본 100%에 대한 상대적 크기
- 배수(em): 기본 1em에 대한 상대적 폰트 크기

```
<style>
	.type1 { font-size: 20px }
	.type2 { font-size: 150% }
	.type3 { font-size: 0.5em }
</style>
```

위치 값일 경우, 다음 키워드를 사용해서 배치할 수 있다.
```
left/center/right
top/center/bottom
```

### 크기 (Dimension)
다음 속성은 HTML 요소의 크기를 설정한다.

|속성|값|기능|
|---|---|---|
|height|px|고정 높이|
|width|px|고정 너비|
|max-height|px, `none`|최대 높이|
|min-height|px, 0|최소 높이|
|max-width|px, `none`|최대 너비|
|min-width|px, 0|최소 너비|

최대/최소로 크기를 설정하면 HTML 요소의 크기는 브라우저의 크기에 따라 변할 수 있다.

```
<style>
	div.size1 { width: 100; height: 50; }
	div.size2 { max-width: 100; max-height: 50; }
</style>
```

### 박스 모델 (Box Model)
HTML 요소는 박스 모델(Box Model)로 구성되어 있으며, 박스 모델은 다음으로 구성되어 있다.

- 내용(content): 박스의 실질적인 내용
- 패딩(padding): 내용과 테두리 사이의 간격
- 테두리(border): 내용과 패딩 주변을 감싸는 외곽선
- 마진(margin): 테두리와 이웃하는 요소 사이의 간격
- 아웃라인(outline): 테두리 주변을 둘러싼 외곽선
	- 테두리와 비슷하지만, 아웃라인은 HTML 요소 크기에 영향을 주지 않는다.
	- 아웃라인은 사각형이 아닐 수 있다.

```
|-element------------------------------|
|    margin                            |
|     |--border/outline------------|   |
|     |      padding               |   |
|     |           content          |   |
|     |                            |   |
|     |----------------------------|   |
|                                      |
|--------------------------------------|
```

HTML 요소의 전체 크기는 내용, 패딩, 테두리, 마진을 포함한다. (아웃라인은 포함되지 않는다)

패딩, 테두리, 마진은 단일 속성(ex. padding, border-style 등)으로 4방향을 한꺼번에 설정할 수 있다. 이때 값은 1-4개를 줄 수 있다.

|값 개수|적용|
|---|---|
|4|top right bottom left 순서|
|3|top (right left) bottom 순서|
|2|(top bottom) (right left) 순서|
|1|top right bottom left|

패딩, 테두리, 마진의 특정 방향만을 설정한다면, 박스 모델 요소명 뒤에 다음 접두어를 붙인다. (ex. padding-top, border-bottom, border-right-style, margin-left ...)

|접두어|방향|
|---|---|
|`-top`|위쪽|
|`-right`|오른쪽|
|`-bottom`|아래쪽|
|`-left`|왼쪽|

#### 패딩 (padding)
- 패딩은 background-color에 영향을 받는다.

|속성|값|기능|
|---|---|---|
|padding|px|패딩 길이|

#### 테두리 (border)

|속성|값|기능|
|---|---|---|
|border-style|`none`, `dotted`, `solid` ...|테두리 모양 설정|
|border-width|px, `thin`, `medium`, `thick`|테두리 두께|
|border-color|color, `transparent`|테두리 색|
|border||위 3속성을 한꺼번에 설정 (border-style 필수)|

#### 마진 (margin)
- 마진은 background-color에 영향을 받지 않는다.
- 마진 길이는 음수 값이 가능하다. 이 경우엔 다른 HTML 요소와 겹쳐 보이게 된다.

|속성|값|기능|
|---|---|---|
|margin|px, `inherit`, `auto`|마진 길이|

|값|기능|
|---|---|
|`inherit`|부모 HTML 요소한테 값을 이어받음|
|`auto`|웹 브라우저가 수평 방향 마진 값을 자동으로 설정|

#### 아웃라인 (outline)

|속성|값|기능|
|---|---|---|
|outline-style|`none`, `dotted`, `solid` ...|테두리 모양 설정|
|outline-width|px, `thin`, `medium`, `thick`|테두리 두께|
|outline-color|color, `invert`|테두리 색|
|outline||위 3속성을 한꺼번에 설정 (outline-style 필수)|

#### 테두리 style 값
border-style, outline-style에서 사용 가능한 값은 다음과 같다.

|값|기능|
|---|---|
|`none`|없음|
|`hidden`|존재는 하나 표현되지 않음|
|`dotted`|점선|
|`dashed`|약간 긴 점선|
|`solid`|실선|
|`double`|이중 실선|
|`groove`|3차원 입체선|
|`ridge`|3차원 능선|
|`inset`|3차원 내지 선|
|`outset`|3차원 외지 선|

## 위치 (Position)
### display
- display 속성을 사용해서 HTML 요소의 display 속성값을 변경할 수 있다.
- 단, display 값을 변경하더라도 기존 값의 특성이 일부 남아있다.
	- 기존 inline에서 block으로 변경하더라도, 해당 HTML 요소 내에 다른 HTML 요소를 포함할 수 없다.

|값|기능|
|---|---|
|`block`|display를 block으로 변경|
|`inline`|display를 inline으로 변경|
|`inline-block`|display를 inline-block으로 변경|
|`none`|HTML 요소가 숨겨짐|

inline-block의 특징은 다음과 같다.
- 기본적으로 inline 특성을 따른다.
- 일부 block 특성을 가진다.
	- 너비/높이를 조정할 수 있다.
	- margin이 존재한다.

### visibility
- visibility 속성은 HTML 요소가 보여지는 상태를 결정한다.

|값|기능|
|---|---|
|`visible`|표시됨|
|`hidden`|숨겨짐|
|`collapse`|테이블의 테두리를 한 줄만 보여줌 (동적인 테이블에서만 사용 가능)|

`display: none`으로 하면 레이아웃에서도 숨겨져 해당 HTML 요소가 있던 공간도 없어진다. 이와 달리, `visibiliy: hidden`으로 하면 레이아웃에선 존재하기에 해당 HTML 요소가 있던 자리에 빈 공간이 남아있다.

### opacity
- opacity 속성은 HTML 요소의 투명도를 설정한다. \[0.0, 1.0\] 사이의 값을 가지며, 0에 가까울수록 투명하다.

### position
- position 속성은 HTML 요소가 위치를 결정하는 방식을 설정한다.
- 기본값은 `static`이다.

|값|기능|
|---|---|
|`static`|정적 위치 방식|
|`relative`|상대 위치 방식|
|`fixed`|고정 위치 방식|
|`absolute`|절대 위치 방식|

- 정적 위치 방식: 웹 페이지에 의한 기본 위치에 자동 배치된다. top, right, bottom, left의 영향을 받지 않는다.
- 상대 위치 방식: 기본 위치를 기준으로 위치를 설정한다.
- 고정 위치 방식: 뷰포트(viewport)를 기준으로 위치를 설정한다. 웹 페이지를 스크롤해도 해당 요소는 항상 고정된 위치를 갖는다.
- 절대 위치 방식: 위치가 설정된(=position: relative/fixed/absolute으로 설정된) 조상 HTML 요소를 기준으로 위치를 설정한다. 그러한 조상 HTML 요소가 없다면 HTML 문서의 body 요소를 기준으로 한다.

정적 위치 방식이 아닌 다른 방식들은 이하 속성을 통해 기준점으로부터 위치를 조정할 수 있다.

|속성|값|기능|
|---|---|---|
|`top`|px|위쪽 평행이동 값|
|`right`|px|오른쪽 평행이동 값|
|`bottom`|px|아래쪽 평행이동 값|
|`left`|px|왼쪽 평행이동 값|

```
<style>
	.static { position: static; }
	.relative { position: relative; up: 20px; }
	.fixed { position: fixed; right: 30px; }
	.absolute { position: absolute; bottom: 15px; left: 25px; }
</style>
```

### z-index
- 위치에 따라 HTML 요소가 서로 겹치는 상황이 발생할 수 있다.
- z-index 속성은 겹쳐진 HTML 요소들이 쌓인 스택의 순서를 설정한다.
- 스택 순서 값이 클수록 앞에 위치하며(=위에 보여지며), 작을수록 뒤에 위치한다.
- 스택 순서 값은 양수/음수 모두 가능하다.

```
<style>
	.front { z-index: 2 }
	.back { z-index: -1 }
</style>
<div class="front">back 위에 있습니다.</div>
<div class="back">front 아래에 있습니다.</div>
```

### float
- float 속성을 설정하면, 해당 HTML 요소가 자신을 감싸는 컨테이너 좌우측 끝으로 이동한다. (마치 컨테이너 수조에서 떠오르는 것과 비슷하다.)
- float 속성이 적용된 HTML 요소가 이동하면, 남은 빈 자리는 float가 적용되지 않은 다음 HTML 요소가 채운다.

|값|기능|
|---|---|
|`left`|상위 컨테이너 좌측 끝으로 이동|
|`right`|상위 컨테이너 우측 끝으로 이동|
|`none`|float 미적용|

```
|-------|
|  img  |
|-------|
float가 미적용된 상태입니다.
```

```
|-------| img에 float가
|  img  | left로 적용된
|-------| 상태입니다. 이렇게
다음 요소가 빈 공간을 채우게
됩니다.
```

### clear
- clear 속성은 해당 HTML 요소가 float가 적용된 이전 요소들이 이동하면서 남긴 빈 공간을 채우기 위해 이동하는 것을 설정한다.

|값|기능|
|---|---|
|`left`|(float: left) 요소로 인한 이동 방지|
|`right`|(float: right) 요소로 인한 이동 방지|
|`both`|`left`, `right` 모두 보유|
|`none`|clear 미적용|

```
<style>
	#img { float: left; }
	#escape { clear: left; }
</style>
```

```
|-------|
|  img  |
|-------|
id="escape"인 요소는 더 이상 float: left인
요소로 인해 이동하지 않게 됩니다.
```

### overflow
- float가 적용된 HTML 요소의 크기가 자신을 감싸는 상위 컨테이너의 크기보다 크다면, 해당 요소가 컨테이너를 넘게 된다. (마치 컨테이너 수조에서 넘쳐 흐르는 것과 비슷하다.)
- overflow 속성을 활용해서 이러한 문제를 대처할 수 있다.
- 넘치는 방향에 따라 설정할 수도 있다.
	- overflow-x: 수평 방향으로 넘쳤을 때
	- overflow-y: 수직 방향으로 넘쳤을 때

|값|기능|
|---|---|
|`visible`|HTML 요소의 넘친 영역을 그대로 표시함|
|`auto`|HTML 요소의 넘친 영역 크기만큼 상위 컨테이너의 크기를 자동으로 조정|
|`hidden`|HTML 요소의 넘친 영역을 자름|
|`scroll`|`hidden`과 비슷하나, 스크롤바를 상시 제공|

## 선택자 (Selector)
CSS의 선택자 종류로는 다음이 있다.

- 전체 선택자: HTML 모든 요소에 적용한다.
- HTML 요소 선택자: 특정 HTML 요소에 적용한다.
- 아이디(id) 선택자: HTML 속성 `id`로 적용할 HTML 요소를 정한다.
- 클래스(class) 선택자: HTML 속성 `class`로 적용할 HTML 요소를 정한다.
- 그룹(group) 선택자: 여러 선택자를 한번에 단순 나열할 수 있다.

### 전체 선택자
- `*`를 사용한다.

```
<style>
	* { background-color: green; }
</style>
<body>모든 요소에 적용됩니다.</body>
```

### HTML 요소 선택자
- 적용할 HTML 요소의 이름을 직접 사용한다.

```
<style>
	body { background-color: green; }
</style>
<body>body 요소에 적용됩니다.</body>
```

### 아이디(id) 선택자
- `#`으로 적용할 id 값을 정할 수 있다.

```
<style>
	#sword { background-color: green; }
</style>
<p id="sword">id가 "sword"인 요소에 적용됩니다.</p>
```

### 클래스(class) 선택자
- `.`으로 적용할 class 값을 정할 수 있다.

```
<style>
	.item { background-color: green; }
</style>
<p class="item">class가 "item"인 모든 요소에 적용됩니다.</p>
```

### 그룹(group) 선택자
- `,`로 구분해서 적용할 선택자를 나열할 수 있다.

```
<style>
	div, .item { background-color: green; }
</style>
<p class="item">class가 "item"인 모든 요소와</p>
<div>div 요소에 적용됩니다.</div>
```
### 결합 선택자

- 자손(descendant) 선택자: 해당 요소의 모든 하위 요소에 적용한다.
- 자식(child) 선택자: 해당 요소의 1단계 하위 요소에만 적용한다.

#### 자손(descendant) 선택자
- 현재 요소와 자손 요소 사이는 공백으로 구분한다.

```
<style>
	div p { background-color: green; }
</style>
<div>
	<p>적용 OK</p>
	<span>
		<p>적용 OK</p>
	</span>
<div>
```

#### 자식(child) 선택자
- 현재 요소와 자식 요소 사이는 `>`으로 구분한다.

```
<style>
	div p { background-color: green; }
</style>
<div>
	<p>적용 OK</p>
	<span>
		<p>적용 X</p>
	</span>
<div>
```

### 동위(sibling) 선택자

- 일반 동위(general sibling) 선택자: 해당 요소의 뒤에 있는 동위 요소에 적용한다.
- 인접 동위(adjacent sibling) 선택자: 해당 요소의 뒤에 있는 인접한 동위 요소에만 적용한다.

#### 일반 동위(general sibling) 선택자
- 현재 요소와 동위 요소 사이는 `~`으로 구분한다.

```
<style>
	div ~ p { background-color: green; }
</style>
<p>적용 X</p>
<p>적용 X</p>
<div>
	<p>적용 X</p>
	<p>적용 X</p>
<div>
<p>적용 OK</p>
<p>적용 OK</p>
```

#### 인접 동위(adjacent sibling) 선택자
- 현재 요소와 인접한 동위 요소 사이는 `+`으로 구분한다.

```
<style>
	div + p { background-color: green; }
</style>
<p>적용 X</p>
<p>적용 X</p>
<div>
	<p>적용 X</p>
	<p>적용 X</p>
<div>
<p>적용 OK</p>
<p>적용 X</p>
```

### 의사 클래스 (pseudo-class)
- `의사 클래스(pseudo-class)`를 활용해서 HTML 요소의 상태로 HTML 요소를 정할 수 있다.
- 기존 선택자 뒤에 `:의사 클래스 이름`을 붙여서 적용할 수 있다.
- 의사 클래스 이름은 대소문자를 구분하지 않는다.

```
selector:pseudo-class { ... }

selector = 선택자
pseudo-class = 의사 클래스 이름
```

#### 동적(dynamic) 의사 클래스
- 링크(link) 요소의 상태로 선택한다.

|의사 클래스|기능|
|---|---|
|:link|link 요소가 link 상태일 때|
|:visited|link 요소가 visited 상태일 때|
|:hover|link 요소가 hover 상태일 때|
|:active|link 요소가 active 상태일 때|
|:focus|link 요소가 focus 상태일 때|

```
<style>
	a:link { color: red; }
	a:visited { color: orange; }
	a:hover { color: yellow; }
	a:active { color: green; }
	a:focus { color: blue; }
</style>
```

#### 상태(UI) 의사 클래스
- 입력(input) 요소의 상태로 선택한다.

|의사 클래스|기능|
|---|---|
|:checked|input 요소가 checked 상태일 때|
|:enabled|input 요소가 사용 가능할 때|
|:disabled|input 요소가 사용 불가능할 때|

```
<style>
	input:enabled + span { color: orange; }
	input:disabled + span { color: yellow; }
	input:checked + span { color: red; }
</style>
<input type="checkbox" checked><span>아이템 1</span></input>
<input type="checkbox"><span>아이템 2</span></input>
<input type="checkbox" disabled><span>아이템 3</span></input>
```

#### 구조(structural) 의사 클래스
- HTML 요소의 계층 구조를 통해 선택한다.
- -child는 모든 타입의 자식 요소를 고려하는 반면, -of-type는 자신과 동일한 타입의 자식 요소만 고려한다.

|의사 클래스|기능|
|---|---|
|:first-child|자신이 앞에서 1번째 자식 요소면 선택|
|:last-child|자신이 뒤에서 1번째 요소면 선택|
|:nth-child(f(n))|자신이 앞에서부터 f(n)번에 해당하는 자식 요소면 선택|
|:nth-last-child(f(n))|자신이 뒤에서부터 f(n)번에 해당하는 자식 요소면 선택|
|:first-of-type|자신이 앞에서 1번째 자식 특정 타입 요소면 선택|
|:last-of-type|자신이 뒤에서 1번째 특정 타입 요소면 선택|
|:nth-of-type(f(n))|자신이 앞에서부터 f(n)번에 해당하는 특정 타입 자식 요소면 선택|
|:nth-last-of-type(f(n))|자신이 뒤에서부터 f(n)번에 해당하는 특정 타입 자식 요소면 선택|
|:only-child|자신이 상위 요소의 유일한 자식 요소면 선택|
|:only-of-type|자신이 상위 요소의 유일한 특정 타입 자식 요소면 선택|
|:empty|자식 요소가 없다면 선택|
|:root|HTML 문서의 root 요소(=html 요소)를 선택|

```
<style>
	p:first-child { color: red; }
	p:last-child { color: blue; }
	p:nth-child(2n) { color: green; }
	p:nth-last-child(4n-1) { color: yellow; }
</style>
<div>
	<p>1번째 자식입니다. 빨강색입니다.</p>
	<p>2번째 자식입니다. 초록색입니다.</p>
	<p>3번째 자식입니다. 노란색입니다.</p>
	<p>4번째 자식입니다. 초록색입니다.</p>
	<p>5번째 자식입니다. 파랑색입니다.</p>
</div>
```


```
<style>
	p:first-of-type { color: red; }
	p:last-of-type { color: blue; }
	p:nth-of-type(2n) { color: green; }
	p:nth-last-of-type(4n-1) { color: yellow; }
</style>
<div>
	<p>1번째 p타입 자식입니다. 빨강색입니다.</p>
	<span>span타입 자식입니다.</span>
	<p>2번째 p타입 자식입니다. 초록색입니다.</p>
	<p>3번째 p타입 자식입니다. 노란색입니다.</p>
	<span>span타입 자식입니다.</span>
	<p>4번째 p타입 자식입니다. 초록색입니다.</p>
	<p>5번째 p타입 자식입니다. 파랑색입니다.</p>
	<span>span타입 자식입니다.</span>
</div>
```

```
<html>
	<style>
		p:only-of-type { color: blue; }
		p:only-child { color: red; }
		p:empty { width: 100px; height: 50px; background-color: green; }
		:root { color: yellow; }
	</style>
	<div>
		<p>유일한 자식입니다. 빨강색입니다.</p>
	</div>
	<div>
		<p>유일한 p타입 자식입니다. 파랑색입니다.</p>
		<span>span타입 자식입니다. 노랑색입니다.</span><br>
	</div>
	<p></p>
	<p style="color: black;">텍스트 노드도 자식 요소에 해당됩니다.</p>
</html>
```

#### 기타 의사 클래스
##### :not
- 인자로 준 선택자의 반대에 해당하는 선택자를 적용한다.

```
selector:not(target) { ... }

selector: 선택자
target: not을 적용할 선택자
```

```
<style>
	p:not([name="hello"]) { color: orange }
</style>
<p>이름이 없습니다.</p>
<p name="hi">이름이 "hi"입니다.</p>
<p name="hello">이름이 "hello"입니다.</p>
```

##### :lang
- HTML 속성인 lang으로 검색한다.

```
:lang(value) { ... }

value: lang 값
```

```
<style>
	:lang(en) { quotes: '"' '"' "'" "'"; }
	:lang(fr) { quotes: "<<" ">>" "<" ">" }
</style>
<q lang="en">미국식 인용 표현입니다.</q><br>
<q lang="fr">프랑스식 인용 표현입니다.</q>
```

### 의사 요소 (pseudo-element)
- `의사 요소(pseudo-element)`를 활용해서 HTML 요소의 일부분만 선택할 수 있다.
- 기존 선택자 뒤에 `::의사 요소 이름`을 붙여서 적용할 수 있다. (CSS3 기준)
- ::first-letter, ::first-line는 block 요소만 사용 가능하다.

```
selector:pseudo-element { ... }

selector = 선택자
pseudo-element = 의사 요소 이름
```

|의사 요소|선택|
|---|---|
|::first-letter|텍스트의 첫 글자|
|::first-line|텍스트의 첫 라인|
|::before|content 바로 앞|
|::after|content 바로 뒤|
|::selection|사용자가 선택한 부분|

```
<style>
	p::first-letter { font-size: 1.5em; }
	p::first-line { color: orange; }
	p::before { content: ":)"; }
	p::after { content: ";)"; }
	p::selection { background-color: grey; }
</style>
<p>여러 가지 의사 요소를 적용해봅시다.<br>
특정 부분에 의사 요소가 적용된 것을 볼 수 있습니다.<br>
또한 드래그를 하면 배경이 회색이 됩니다.</p>
```

### 속성(attribute) 선택자
- `속성 선택자`를 사용하면 특정 속성/속성값을 가진 HTML 요소를 선택할 수 있다.

```
[property] { ... }
[property="value"] { ... }

property = HTML 속성명
value = HTML 속성값
```

```
<style>
	[name="hello"] { color: orange; }
</style>
<p>이름이 없습니다.</p>
<p name="hi">이름이 "hi"입니다.</p>
<p name="hello">이름이 "hello"입니다.</p>
```

#### 문자열 속성 선택자
- `문자열 속성 선택자`를 통해 속성값을 더 자세히 검색할 수 있다.
- 검색에서 단어는 공백으로 구분된다.

```
[property~="search"] { ... }
[property|="search"] { ... }
[property^="search"] { ... }
[property$="search"] { ... }
[property*="search"] { ... }

property = HTML 속성명
search = HTML 속성값 검색어
```

|문자열 속성 선택자|선택|
|---|---|
|`~`|속성값에 search 단어가 포함됨|
|`|`|속성값 시작 단어가 search|
|`^`|속성값 시작 문자열이 search|
|`$`|속성값 끝 문자열이 search|
|`*`|속성값에 search 문자열이 포함됨|

이하는 문자열 속성 선택자에 의한 예시의 선택 유무다.

|문자열 속성 선택자|item|item box|item-box|box item|box-item|
|---|---|---|---|---|---|
|`~`|O|O|X|O|X|
|`|`|O|X|O|X|X|
|`^`|O|O|O|X|X|
|`$`|O|X|X|O|O|
|`*`|O|O|O|O|O|

```
<style>
	[name~="item"] { color: orange; }
	[name|="item"] { background-color: grey; }
	[name^="item"] { font-size: 1.2em; }
	[name$="item"] { font-style: italic; }
	[name*="item"] { font-weight: bold; }
</style>
<p name="item">item</p>
<p name="item box">item box</p>
<p name="item-box">item-box</p>
<p name="box item">box item</p>
<p name="box-item">box-item</p>
```

## CSS3
`CSS3`은 CSS의 최신 표준이다.

### 벤더 프리픽스 (Vendor Prefix)
- `벤더 프리픽스(vendor prefix)`를 통해 CSS 권고안에 완벽히 제정되지 않은 기능을 사용할 수 있다.
- 사용할 기능 앞에 벤더 프리픽스를 명시함으로써 적용할 수 있다.
- 벤더 프리픽스는 웹 브라우저 계열마다 다르다. 예를 들어 크롬 브라우저는 `-webkit-`이다.
- 벤더 프리픽스 스크립트를 모두 작성한 다음, 마지막에 CSS 표준 스크립트를 작성해야 벤더 프리픽스 부분이 정상적으로 실행된다.
- CSS 표준으로 제정되었다면 벤더 프리픽스를 더 이상 적용하지 않아도 된다.

```
<style>
	div { 
		background: -webkit-linear-gradient(red, blue); /* 벤더 프리픽스 */
		background: linear-gradient(red, blue); /* CSS 표준 스크립트 */
	}
</style>
<div>벤더 프리픽스 이후에 CSS 표준 스크립트를 넣어야 합니다.</div>
```

### 색 (Color)
CSS3에서 색은 기존 HTML 3가지 방법을 포함해 여러 방법이 있다.

|방법|값|비고|
|---|---|---|
|색상 이름|color_name|W3C에서 정의된 이름|
|RGB 색상값|rgb(r,g,b)|값 범위는 \[0, 255\]|
|RGB 16진수 색상값|#000000|값 범위는 \[00, FF\]|
|RGBA 색상값|rgba(r,g,b,a)|a는 알파값(투명도)이며, 값 범위는 \[0.0, 1.0\]|
|HSL 색상값|hsl(h,s,l)|색상,채도,명도. 색상 값 범위는 \[0, 360\], 채도,명도 값 범위는 \[0%, 100%\]|
|HSLA 색상값|hsla(h,s,l,a)|a는 알파값(투명도)이며, 값 범위는 \[0.0, 1.0\]|
|opacity|opacity:float|opacity는 CSS 속성이며, 색상의 투명도를 설정한다. 값 범위는 \[0.0, 1.0\]|

```
color: red;
color: rgb(255,0,0);
color: #FF0000;
color: rgba(255,0,0,0.5);
color: hsl(120, 100%, 100%);
color: hsla(120, 100%, 100%, 0.5);
opacity: 0.5;
```

- rgba, hsla와 달리, opacity 속성은 해당 요소의 자식 요소에게도 같은 투명도를 적용한다.

### 그라디언트 (Gradient)
#### 선형 그라디언트
- `linear-gradient`를 사용해서 선형 그라디언트를 표현할 수 있다.
- `repeating-linear-gradinet`는 반복되는 선형 그라디언트를 생성한다. 사용법은 linear-gradient하고 같다.

> linear-gradient(_진행 방향_, 색상1, 색상2, ...)

|진행 방향 값|설명|
|---|---|
|`to top`|북쪽|
|`to right`|동쪽|
|`to bottom`|남쪽|
|`to left`|서쪽|
|`to top right`|북동쪽|
|`to top left`|북서쪽|
|`to bottom right`|남동쪽|
|`to bottom left`|남서쪽|
|deg|각도 지정|

- 진행 방향 인자는 생략 가능하며, 기본값은 `to bottom`이다.
- 각도 값의 범위는 \[0,360\]이다. 0deg는 북쪽이며, 양수 각도는 시계 방향이다.

```
<style>
	div { 
		width: 300px;
		height: 200px;
		background: linear-gradient(45deg, rgba(150,150,0,1.0), 
			rgba(150,0,150,0.75), rgba(0,150,150,0.5));
	}
</style>
<div></div>
```

#### 원형 그라디언트
- `radial-gradient`를 사용해서 원형 그라디언트를 표현할 수 있다.
- `repeating-radial-gradinet`는 반복되는 원형 그라디언트를 생성한다. 사용법은 radial-gradient하고 같다.

> radial-gradient(_모양_, 색상1, 색상2, ...)
> radial-gradient(_크기 at 중심점_, 색상1, 색상2, ...)

|모양 값|설명|
|---|---|
|`ellipse`|타원|
|`circle`|원|

|크기 값|설명|
|---|---|
|`closest-side`|그라디언트 크기가 요소의 가장 가까운 면에 닿을 만큼 크기가 확장됨|
|`farthest-side`|그라디언트 크기가 요소의 가장 먼 면에 닿을 만큼 크기가 확장됨|
|`closest-corner`|그라디언트 크기가 요소의 가장 가까운 모서리에 닿을 만큼 크기가 확장됨|
|`farthest-corner`|그라디언트 크기가 요소의 가장 먼 모서리에 닿을 만큼 크기가 확장됨|

|중심점 값|설명|
|---|---|
|px px|중심점 좌표(x,y)|

- 모양은 생략 가능하며, 기본 값은 `ellipse`이다.
- 크기는 생략 가능하며, 기본 값은 `farthest-corner`이다.
- 크기를 먼 면/모서리까지 설정하면 가까운 면/모서리 부분에서 그라디언트가 잘릴 수 있다.
- 그라디언트 내 색상점의 위치를 직접 정할 수 있다. 적용할 색상 뒤에 px 값을 추가하면 적용된다.

```
<style>
	div {
		width: 300px;
		height: 200px;
	}
	#grad1 { 
		background: radial-gradient(circle, rgba(150,150,0,1.0) 20%,
			rgba(150,0,150,0.75) 50%,rgba(0,150,150,0.5) 80%);
	}	
	#grad2 { 
		background: radial-gradient(farthest-side at 20% 40%,
			rgba(150,150,0,1.0),rgba(150,0,150,0.75),rgba(0,150,150,0.5));
	}
</style>
<div id="grad1"></div>
<div id="grad2"></div>
```

### 그림자 (Shadow)
- `text-shadow` 속성은 텍스트에 그림자 효과를 준다.
- `box-shadow` 속성은 HTML 요소에 그림자 효과를 준다.
- `,`를 사용해 2가지 이상 그림자를 넣을 수 있다.

> text-shadow: x y _blur color_, _x2 y2 blur2 color2_ ...
> box-shadow: x y _blur color_, _x2 y2 blur2 color2_ ...

|인자|값|기능|
|---|---|---|
|x|px|그림자의 우측방향 x간격|
|y|px|그림자의 하단방향 y간격|
|blur|px|그림자의 흐린 정도|
|color|color|그림자 색상|

```
<style>
	div {
		width: 300px;
		height: 200px;
		text-shadow: 2px 2px yellow;
		box-shadow: 1px 1px 2px blue, 0 0 5px purple;
	}
</style>
<div>그림자 박스!</div>
```

### 배경 (Background)
- CSS3에 추가된 배경 속성은 다음과 같다.

|속성|값|기능|
|---|---|---|
|background-size|px px, `contain`, `cover`|배경 크기|
|background-origin|`border-box`, `padding-box`, `content-box`|배경 기준점 위치설정|
|background-clip|`border-box`, `padding-box`, `content-box`|배경의 적용범위 설정|

#### background-size
- `contain`:(배경의 크기 <= 해당 요소의 크기)를 만족하는 최대 크기로 설정
	- 배경 이미지의 비율은 유지됨
	- 요소의 일부분이 가려지지 않을 수 있음
- `cover`:(배경의 크기 >= 해당 요소의 크기)를 만족하는 최소 크기로 설정
	- 배경 이미지의 비율은 유지됨
	- 배경 이미지의 일부분이 잘릴 수 있음

#### background-origin
- `border-box`: 테두리(border) 영역의 좌측 상단을 기준점으로 한다.
- `padding-box`: 기본값. 패딩(padding) 영역의 좌측 상단을 기준점으로 한다.
- `content-box`: 내용(content) 영역의 좌측 상단을 기준점으로 한다.

#### background-clip
- `border-box`: 기본값. 테두리(border) 영역까지 배경이 적용된다.
- `padding-box`: 패딩(padding) 영역까지 배경이 적용된다.
- `content-box`: 내용(content) 영역까지 배경이 적용된다.

### 테두리 (Border)
- CSS3에 추가된 테두리 속성은 다음과 같다.

|속성|값|기능|
|---|---|---|
|border-radius|px|둥근 테두리 (px=반지름)|
|border-top-left-radius|px|상단좌측 둥근 테두리|
|border-top-right-radius|px|상단우측 둥근 테두리|
|border-bottom-right-radius|px|하단우측 둥근 테두리|
|border-bottom-left-radius|px|하단좌측 둥근 테두리|
|border-image-source|url|테두리 이미지 url|
|border-image-slice|px|테두리 이미지가 잘리는 정도(=자르기 정사각형 크기)|
|border-image-repeat|`round`, `strench`|테두리 이미지 중간 부분의 처리 방법|
|border-image-width|px|잘린 테두리 이미지의 너비|
|border-image-outset|px|이미지가 테두리 영역 바깥으로 얼만큼 넘어갈지 설정|
|border-image||위 5가지 속성을 한꺼번에 설정|

#### border-radius
- border-radius의 값은 1-4개를 가질 수 있다.

|값 개수|적용|
|---|---|
|4|top-left top-right bottom-right bottom-left 순서|
|3|top-left (top-right bottom-left) bottom-right 순서|
|2|(top-left bottom-right) (top-right bottom-left) 순서|
|1|top-left top-right bottom-right bottom-left|

#### border-image
- 원본 이미지가 있다면, 테두리 이미지는 9등분으로 잘린다.
- 8개의 조각 이미지에서 중간 부분의 4조각은 border-image-repeat에 의해 처리된다.
```
@ | @ | @
--|---|--
@ |   | @
--|---|--
@ | @ | @
```

- border-image-repeat는 2개의 값을 가질 수 있으며, 이때는 수평/수직 순으로 반영된다.
- `round`: 중간 부분을 반복한다.
- `strench`: 중간 부분 1개를 늘린다.


### 텍스트 (Text)
- CSS3에 추가된 텍스트 속성은 다음과 같다.

|속성|값|기능|
|---|---|---|
|text-overflow|`visible`, `clip`, `ellipsis`|내용(content) 영역을 벗어난 텍스트 처리 방식 설정|
|word-wrap|`break-word`|내용(content) 영역을 벗어난 길이가 긴 단어를 다음 줄로 보냄|
|word-break|`break-all`, `keep-all`|내용(content) 영역을 벗어난 길이가 긴 단어를 분리하는 방식 설정|

- word-wrap은 한글에 적용되지 않는다.

#### text-overflow

|값|기능|
|---|---|
|`visible`|넘친 텍스트를 그대로 표시|
|`clip`|넘친 텍스트를 잘라냄|
|`ellipsis`|넘친 텍스트를 생략 부호로 대체|

#### word-break

|값|기능|
|---|---|
|`break-all`|문자 기준으로 분리|
|`keep-all`|`-`를 기준으로 분리|

- 한글은 항상 `break-all`로 적용된다.

## 고급 (Advanced)
### @규칙
CSS에서 W3C가 규정한 규칙들을 사용할 수 있다.

#### @import
- `@import` 규칙은 외부 css 파일을 불러오는 기능을 수행한다.
- 모든 규칙(`@charset` 제외) 중에서 가장 먼저 명시되어야 한다.
- HTML 문서에도 넣을 수 있고, css 파일에서도 넣을 수 있다.

- html => 최종적으로 4개의 css 파일이 로드된다.
```
<link rel="stylesheet" href="style1.css">
@import "style2.css";
```
- style1.css
```
@import url("style3.css");
@import "style4.css";
...
```

#### @font-face
- `@font-face` 규칙은 CSS3에 새로 추가된 규칙으로, 웹 폰트(web font)를 정의할 때 사용된다.
- 웹 폰트는 클라이언트에 설치되지 않은 글꼴이라도 자동으로 서버에서 다운받아 사용할 수 있다. 

|속성|값|기능|
|---|---|---|
|font-family|font|글꼴 이름|
|src|url|글꼴 파일 주소|
|_font-weight_|`normal`, `bold`|글꼴 굵기|

```
<style>
	@font-face {
		font-family: newFont;
		src: url(/font/newFont.woff);
	}
</style>
```

- 이외 글꼴 관련 선택적 속성을 추가할 수 있다.

#### @media
- `@media` 규칙을 통해 서로 다른 매체(media)마다 스타일을 적용할 수 있다.
- CSS3에선 더 구체화된 `미디어 쿼리(media query)`를 사용할 수 있다.
- 기기의 매체 유형이 지정한 매체 유형(media_type)과 일치하고 표현식(expression)이 true를 반환하면 css script 부분이 실행된다.

> @media only|not `media_type` and `(expression)` { `css script` }

- HTML의 media 속성에서도 미디어 쿼리를 작성할 수 있다. 이 방법으로 기기별로 스타일 시트 파일을 지정할 수 있다.

> media="`media_type` and|only|not `(expression)`"

```
<style>
	@media screen and (max-width: 300px) {
		/* 뷰포트의 최대 너비가 300px 이하인 기기 */
		html { background: orange; }
	}
	@media print {
		/* 프린트 기기 */
		html { background: cyan; }
	}
</style>
```

##### 매체 유형

|매체 유형|설명|
|---|---|
|`all`|모든 매체|
|`print`|프린트 기기|
|`screen`|스크린이 있는 기기|
|`speech`|스크린 리더|

##### 미디어 쿼리 속성
- min-, max- 접두사를 붙여 최소/최대 속성을 이용할 수 있다.

|속성|값|기능|
|---|---|---|
|width|px|화면 너비|
|height|px|화면 높이|
|device-width|px|기기 화면 너비|
|device-height|px|기기 화면 높이|

### 사용자 인터페이스 (User Interface, UI)
- 이하 속성은 CSS3부터 사용 가능하다.

|속성|값|기능|
|---|---|---|
|resize|`none`, `both`, `horizontal`, `vertical`|사용자가 직접 크기 조절 가능|
|outline-offset|px|테두리(border)와 아웃라인(outline) 사이 공간|
|box-sizing|`border-box`|요소의 크기에 내용, 패딩, 테두리만 포함함 (마진 제외)|

### 다중 칼럼(multi-column) 레이아웃
- 다중 칼럼 레이아웃은 한 요소를 n개의 세로 칼럼으로 분할하는 레이아웃이다.
- 자식 요소에게도 다중 칼럼 레이아웃이 전파된다.
- 모든 칼럼의 너비는 동등하다.

|속성|값|기능|
|---|---|---|
|column-count|number|칼럼 개수|
|column-gap|px|칼럼 사이 간격|
|column-width|px|칼럼 너비|
|column-span|number, `all`|병합할 칼럼 개수|
|column-rule-style|`solid`|칼럼 사이에 있는 라인의 스타일|
|column-rule-width|px|칼럼 사이에 있는 라인의 두께|
|column-rule-color|color|칼럼 사이에 있는 라인의 색|
|column-rule||column-rule 관련 속성을 한꺼번에 설정|

```
<style>
	div {
		column-count: 3;
		cloumn-gap: 10px;
		column-width: 30px;
		column-rule-style: solid;
		column-rule-width: 1px;
		column-rule-color: grey;
	}
	.merge {
		column-span: all;
	}
</style>
<div>
	<h2 class="merge">다중 칼럼 레이아웃<h2>
	<p>다중 칼럼 레이아웃을 테스트해봅시다. 3개의 칼럼으로 내용이 분할됩니다. 또한 column-rule을 사용해서 칼럼 구분선을 표시합니다. merge 클래스는 칼럼이 병합됩니다.</p>
</div>
```

### 플렉서블 박스(flexible box) 레이아웃
- 플렉스 박스(flex box): 플렉스 컨테이너(flex container)와 플렉스 요소(flex item)로 구성
- 플렉스 컨테이너는 1개 이상의 플렉스 요소, 1개의 플렉스 라인를 포함함
- 플렉스 요소는 플렉스 컨테이너 안에서 가상의 선, 플렉스 라인(flex line)을 따라 위치하게 됨
- 플렉스 라인은 direction 속성값에 영향을 받음
	- (direction: rtl)이면 플렉스 라인의 방향이 오른쪽에서 왼쪽으로 됨

- 플렉스 컨테이너

|속성|값|기능|
|---|---|---|
|display|`flex`, `inline-flex`|플렉스 박스 설정 (블록/인라인)|
|flex-direction|`row`, `row-revers`, `column`, `column-reverse`|플렉스 라인 방향 설정|
|justify-content|`flex-start`, `flex-end`, `center`, `space-between`, `space-around`|플렉스 요소의 수평 정렬 방식 설정|
|align-items|`stretch`, `flex-start`, `flex-end`, `center`, `baseline`|플렉스 요소의 수직 정렬 방식 설정|
|flex-wrap|`nowrap`, `wrap`, `wrap-reverse`|플렉스 라인에 여유 공간이 없을 때, 플렉스 요소의 위치를 다음 줄로 넘기는 방식을 설정|
|align-content|`strench`, `flex-start`, `flex-end`, `center`, `space-between`, `space-around`|flex-wrap의 동작 방식 설정 (플렉스 라인 정렬)|

- 플렉스 요소

|속성|값|기능|
|---|---|---|
|order|number|플렉스 요소의 순서 (작을수록 앞쪽에 배치됨)|
|margin|`auto`|수평 방향의 여유 공간 제거|
|align-self||align-items의 요소별 설정|
|flex|number|플렉스 요소간 상대적 너비|

- (플렉스 요소의 너비 비중) = (플렉스 요소의 flex 값) / (전체 플렉스 요소의 flex 총합)

```
<style>
	div { 
		display: flex;
		flex-direction: row;
		justify-content: space-around;
		align-items: center;
		flex-wrap: wrap;
		align-content: stretch;
	}
</style>
<div>
	<p style="order: -1; flex: 1;">1-1</p>
	<p style="order: -2; flex: 2;">1-2</p>
	<p style="order: -3; flex: 3;">1-3</p>
	<p style="order: -4; flex: 4;">1-4</p>
</div>
```

#### flex-direction

|값|기능|
|---|---|
|`row`|왼=>오른 (기본값)|
|`row-reverse`|오른=>왼|
|`column`|위=>아래|
|`column-reverse`|아래=>위|

#### justify-content

|값|기능|
|---|---|
|`flex-start`|컨테이너 앞쪽 끝부터 배치 (기본값)|
|`flex-end`|컨테이너 뒤쪽 끝부터 배치|
|`center`|컨테이너 가운데부터 배치|
|`space-between`|컨테이너 양끝 배치|
|`space-around`|컨테이너 양끝 배치 (양끝에 여유 공간 존재)|

#### align-items
- 2줄 이상을 가지는 플렉스 박스에게 효과가 있다.

|값|기능|
|---|---|
|`stretch`|플렉스 요소의 높이를 플렉스 컨테이너 높이와 같게 맞춘 후, 연이어 배치 (기본값)|
|`flex-start`|위쪽부터 배치|
|`flex-end`|아래쪽부터 배치|
|`center`|가운데부터 배치|
|`baseline`|플렉스 컨테이너의 기준선에 배치|

#### flex-wrap

|값|기능|
|---|---|
|`nowrap`|다음 줄로 넘어가지 않고, 플렉스 요소의 너비를 줄여 한 줄에 모두 배치 (기본값)|
|`wrap`|아래쪽 다음 줄로 넘어감|
|`wrap-reverse`|위쪽 다음 줄로 넘어감|

#### align-content

|값|기능|
|---|---|
|`stretch`|플렉스 라인의 높이가 남는 공간을 모두 차지함 (기본값)|
|`flex-start`|앞쪽부터 배치|
|`flex-end`|뒤쪽부터 배치|
|`center`|가운데부터 배치|
|`space-between`|고르게 배치|
|`space-around`|양쪽 끝에 여유를 두고 고르게 배치|

## 애니메이션 (Animation)
### transform
- CSS3에선 trasform 속성을 사용해서 HTML 요소의 모양, 크기, 위치 등을 바꿀 수 있다.
- CSS의 좌표계는 HTML과 동일하다. (제4사분면)

|속성|값|기능|
|---|---|---|
|transform|transform_method|HTML 요소에 transform 적용|
|transform-origin|px px|HTML 요소에 적용되는 transform 중심점 설정|

#### 2D Transform

|메소드|기능|
|---|---|
|translateX(dx)|위치를 x방향 dx만큼 평행이동|
|translateY(dy)|위치를 y방향 dy만큼 평행이동|
|translate(dx, dy)|위치를 (dx, dy)만큼 평행이동|
|rotate(deg)|deg만큼 시계 방향 회전|
|scaleX(rate)|rate 배율만큼 x방향 크기 확대/축소 (기준값 = 1.0)|
|scaleY(rate)|rate 배율만큼 y방향 크기 확대/축소 (기준값 = 1.0)|
|scale(x-rate, y-rate)|rate 배율만큼 크기 확대/축소 (기준값 = 1.0)|
|skewX(deg)|deg만큼 x축 방향으로 기울임|
|skewY(deg)|deg만큼 y축 방향으로 기울임|
|skew(x-deg, y-deg)|deg만큼 x/y축 방향으로 기울임|
|matrix(scaleX, skewY, skewX, scaleY, translateX, translateY)|6가지 메소드를 한번에 적용|

```
<style>
	div { width: 100px; height: 100px; border-style: solid; }
	.translate { transform: translate(20px, 20px); }
	.rotate { transform: rotate(120deg); }
	.scale { transform: scale(1.25, 0.75); }
	.skew { transform: skew(20deg, 30deg); }
</style>
<div class="traslate"></div>
<div class="rotate"></div>
<div class="scale"></div>
<div class="skew"></div>
```

#### 3D transform

|메소드|기능|
|---|---|
|translateX(dx)|위치를 x방향 dx만큼 평행이동|
|translateY(dy)|위치를 y방향 dy만큼 평행이동|
|translateZ(dz)|위치를 z방향 dz만큼 평행이동|
|translate3d(dx, dy, z)|위치를 (dx, dy, dz)만큼 평행이동|
|rotateX(deg)|deg만큼 x축 기준 회전|
|rotateY(deg)|deg만큼 y축 기준 회전|
|rotateZ(deg)|deg만큼 z축 기준 회전|
|rotate3d(x-deg, y-deg, z-deg)|deg만큼 x축/y축/z축 기준 회전|
|scaleX(rate)|rate 배율만큼 x방향 크기 확대/축소|
|scaleY(rate)|rate 배율만큼 y방향 크기 확대/축소|
|scaleZ(rate)|rate 배율만큼 z방향 크기 확대/축소|
|scale3d(x-rate, y-rate, z-rate)|rate 배율만큼 크기 확대/축소|
|matrix3d(...)|16가지 메소드를 한번에 적용|
|perspective(px)|3D 요소에 원근감 표현시 사용할 픽셀 수 설정|

```
<style>
	div { width: 100px; height: 100px; border-style: solid; transform: perspective(300px); }
	.translate { transform: translate3d(20px, 20px, 20px); }
	.rotate { transform: rotate3d(45deg, 45deg, 45deg); }
	.scale { transform: scale3d(1.25, 1.0, 0.75); }
</style>
<div class="traslate"></div>
<div class="rotate"></div>
<div class="scale"></div>
```

### transition
- CSS3에선 transition 속성을 사용해서 HTML 요소의 속성을 부드럽게 바꿀 수 있다.
- transition의 값을 여러 개 제공해서 여러 속성을 적용할 수 있다.

> transition: `property` `time`, _`property2`_,  _`time2`_ ...;

- property = 효과를 적용할 CSS 속성명
- time = 트랜지션 지속 시간 (ex. 3초 -> 3s)

|속성|값|기능|
|---|---|---|
|transition-timing-function|`linear`, `ease`, `ease-in`, `ease-out` ...|전환 효과의 시간당 속도 설정|
|transition-delay|time|전환 효과 시작전 대기 시간|

```
<style>
	div {
		border: solid orange 2px;
		width: 100px;
		height: 100px;
		transition: width 1s, height 1s, transform 1s;
		transition-timing-function: ease-in-out;
		transition-delay: 0.25s;
	}
	div:hover {
		width: 200px;
		height:200px;
		transform: rotate(60deg);
	}
</style>
<div></div>
```

### animation
- CSS3에선 animation 속성과 @keyframes 규칙을 사용해서 CSS의 스타일을 부드럽게 바꿀 수 있다.

> @keyframes `animation_name` { 
> 	from { `css_script` }
> 	to { `css_script` }
> }

- css_script에는 각 애니메이션 진행 상황에 맞는 스타일 스크립트가 들어간다.
- from, to 대신 %로 진행 상황을 명시할 수 있다. (from = 0%, to = 100%)

|속성|값|기능|
|---|---|---|
|animation-name|animation_name|현재 스타일에 적용할 애니메이션 정의|
|animation-duration|time|애니메이션 지속 시간|
|animation-delay|time|애니메이션 시작전 대기 시간|
|animation-iteration-count|number, `infinite`|애니메이션 반복 횟수|
|animation-direction|`reverse`, `alternate`|애니메이션 진행 방향 설정|
|animation-timing-function|`linear`, `ease`, `ease-in`, `ease-out` ...|애니메이션의 시간당 속도 설정|
|animation||animation 관련 속성을 한꺼번에 설정|

```
<style>
	div {
		border: solid black 2px;
		width: 100px;
		height: 100px;
		animation-name: rainbowBox;
		animation-duration: 3s;
		animation-iteration-count: infinite;
		animation-direction: reverse;
	}
	@keyframes rainbowBox {
		from { background-color: red; }
		20% { background-color: yellow; }
		40% { background-color: green; }
		60% { background-color: blue; }
		80% { background-color: purple; }
		to { background-color: red; }
	}
</style>
<div></div>
```

#### animation-direction

|값|방향|
|---|---|
|`reverse`|to->from|
|`alternate`|from->to, to->from 번갈아 진행|

### timing-function
- transition-timing-function, animation-timing-function에서 사용된다.

|값|속도 변화|
|---|---|
|`linaer`|등속도|
|`ease`|0->고속->0|
|`ease-in`|0->저속|
|`ease-out`|저속->0|
|`ease-in-out`|0->저속->0|
|`cubic-bezier(n,n,n,n)`|cubic-bezier 함수 사용|

## 출처 (Reference)
http://www.tcpschool.com/css/intro
