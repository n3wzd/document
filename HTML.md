# HTML
`HTML`은 HyperText Markup Language의 약자로, 웹페이지를 기술하는 마크업 언어입니다.

## 요소 (element)
HTML 문서는 `요소(element)`들로 구성되어 있으며, 요소의 구조는 다음과 같습니다.

```
|------------ element ------------|
<tag property="value">content</tag>

tag = 태그
property = 속성명
value = 속성값
content = 내용
```

- `태그(tag)`는 해당 요소의 종류와 범위를 나타냅니다.
	- 태그는 `시작 태그(start tag)`와 `종료 태그(end tag)`로 구성됩니다.
	- 일부 요소는 시작 태그만 존재하기도 합니다. (ex. img, br 등)
- `속성(attribute)`은 해당 요소에 추가적인 정보를 제공합니다.
	- 속성은 시작 태그 내에서 작성되며, 한 요소가 여러 개의 속성을 가질 수 있습니다.
	- 속성은 이름과 값으로 구성됩니다. `<name="value">`
		- 이름은 소문자로 작성하는 것이 권장됩니다.
		- 값은 따옴표를 사용해서 감쌉니다.

## 텍스트 (text)
### 제목 (Heading)
#### h
- `<h>`는 제목을 표현합니다. (heading)
- 수가 작을수록 제목의 크기가 큽니다.
- 검색엔진 크롤러가 수집할 수 있습니다.

```
<h1>제목1</h1>
<h2>제목2</h2>
<h3>제목3</h3>
<h4>제목4</h4>
<h5>제목5</h5>
<h6>제목6</h6>
```

### 단락 (Paragraph)
#### p
- `<p>`는 단락을 표현합니다. (paragraph)
- 여러 개의 공백과 줄바꿈은 1개의 공백으로 표현됩니다.

```
<p>단락입니다.
줄바꿈과  공백은 1개로만 표현됩니다.</p>
```

#### br
- `<br>`은 줄바꿈입니다. (break line)

```
<p>이제<br>
줄바꿈이 됩니다.</p>
```

#### pre
- `<pre>`는 코드에 작성된 텍스트 서식이 반영된 단락을 표현합니다. (preformatted)
- 내용에 있는 공백과 줄바꿈을 그대로 반영합니다.
- 글꼴은 고정폭으로 자동변환 됩니다.

```
<pre>단락입니다. 서식과
줄바꿈, 그리고    공백이 그대로 반영됩니다.</pre>
```

#### hr
`<hr>`은 수평 가로 구분선입니다. (horizontal rule)

```
<p>단락이 구분선으로</p>
<hr>
<p>분할됩니다.</p>
```

### 서식 (Formatting)
#### b, strong
- `<b>`, `<strong>`은 볼드체로 표현해줍니다.
- strong은 내용의 중요성을 추가로 포함하고 있습니다. (=검색엔진 크롤러가 우선시합니다.)

```
<b>볼드체입니다.</b>
<strong>중요하지요!</strong>
```

#### i, em
- `<i>`, `<em>`은 기울임체(이탤릭체)로 표현해줍니다.
- em은 내용의 중요성을 추가로 포함하고 있습니다. (emphasized)

```
<i>기울임체입니다.</i>
<em>중요하지요!</em>
```

#### mark
- `<mark>`는 텍스트에 형광 효과를 줍니다.

```
<mark>이 부분이 하이라이팅됩니다.</mark>
```

#### del
- `<del>`은 취소선을 그어줍니다.

```
<del>삭제된 영역입니다.</del>
```

#### ins
- `<ins>`는 밑줄을 그어줍니다. (insert)

```
<ins>밑줄이 그어집니다.</ins>
```

#### sup, sub
- `<sup>`, `<sub>`는 각각 위첨자, 아래첨자를 표현합니다. (superscript, subscript)

```
x<sup>2</sup> + y<sup>2<sup> = a<sub>1<sub>
```

### 인용구 (Quotation)
#### q
- `<q>`는 짧은 인용구를 표현합니다. (quotation)

```
<q>인용된 문구입니다.</q>
```

#### blockquote
- `<blockquote>`는 블록 인용구(긴 인용문)를 표현합니다.

```
<blockquote>
긴 인용문입니다.
길어서 블록으로 분리됐지요.
</blockquote>
```

#### abbr
- `<abbr>`는 축약형을 표현합니다. (arreviation)

|속성|값|
|---|---|
|title|내용에 마우스를 올리면 해당 값이 표시됨|

```
<abbr title="HyperText Markup Language">HTML</abbr>
```

#### address
- `<address>`는 지리적 주소를 표현합니다.

```
<address>경상남도 사천시</address>
```

### 주석 (Comment)
- HTML에서 주석의 구조는 다음과 같습니다.

```
<!-- 주석 내용 -->
```

### 엔티티 (Entity)
- `HTML 예약어(reserved characters)`는 HTML에서 미리 예약된 문자로, 특별한 용도로 해석됩니다. `엔티티(entity)`는 HTML 예약어를 단순 문자로 사용하게 해줍니다.
- 엔티티의 형태는 2가지가 있습니다.

> &엔티티이름;
> or
> &#엔티티번호;

대표적인 엔티티 종류는 다음과 같습니다.

|문자|이름|번호|
|---|---|---|
|<|`&lt;`|`&#60;`|
|>|`&gt;`|`&#62;`|
|&|`&amp;`|`&#38;`|
|"|`&quot;`|`&#34;`|
|'|`&apos;`|`&#39;`|

```
<p> &lt; html &#62;를 표현할 수 있습니다.</p>
```

## 스타일 (Style)
### 스타일 (Style)
- `style` 속성을 사용하면 CSS 스크립트를 요소에 적용할 수 있습니다.

|속성|값|
|---|---|
|style|CSS 스크립트|

```
<p style="background-color:white; color:green; font-align:center">CSS 코드가 반영되었습니다!</p>
```

### 색 (Color)
- HTML에서 색은 3가지 방법으로 표현됩니다.

|방법|값|비고|
|---|---|---|
|색상 이름|color_name|W3C에서 정의된 이름|
|RGB 색상값|rgb(r,g,b)|값 범위는 \[0, 255\]|
|RGB 16진수 색상값|#000000|값 범위는 \[00, FF\]|

```
red
rgb(255,0,0)
#FF0000
```

### 배경 (Background)
- HTML에서 배경을 설정하는 방법은 2가지가 있습니다.

1. 배경을 색으로 설정
2. 배경을 이미지로 설정

#### 색 설정
- CSS를 사용합니다. (ex. CSS의 `background-color` 속성)

```
<p style="background-color:blue">배경이 파랑입니다.</p>
```

#### 이미지 설정
- `background` 속성을 사용합니다.

|속성|값|
|---|---|
|background|이미지 주소|

```
<div background="/images/img.png"></div>
```

## 기본 (Basic)
### 링크 (Link)
#### a
- `<a>`는 하이퍼링크를 추가합니다.

|속성|값|
|---|---|
|href|링크 URL|
|target|링크 문서를 여는 위치(창/탭/프레임)를 설정|
|name|책갈피 생성|

```
<a href="www.google.com">여기를 누르면 구글로 이동합니다.</a>
```

```
<a href="/images/img.png" target="frame1">이 이미지는 frame1에서 열립니다.</a>
...
<iframe name="frame1"></iframe>
```

```
<a herf="#bookmark1">북마크1로 이동합니다.</a>
...
<a name="bookmark1">여기는 북마크1입니다.</a>
```

#### 상태
- HTML 링크의 상태는 4가지가 있습니다.

|상태|내용|
|---|---|
|link|방문한 적이 없음|
|visited|방문한 적이 있음|
|hover|링크 위에 마우스를 올려놓고 있음|
|active|링크를 마우스로 누르고 있음|

### 이미지 (Image)
#### img
- `<img>`는 이미지를 삽입합니다.

|HTML속성|값|
|---|---|
|src|이미지 주소|
|alt|이미지가 로딩되지 않으면 표시되는 문자열|

```
<img src="/images/img.png" alt="이미지가 로딩되지 않으면 이 문장이 표시됩니다.">
```

- img의 스타일 관련 설정(크기, 테두리 등)은 CSS로 하는 것이 좋습니다.

### 리스트 (List)
- HTML 리스트는 3가지 종류가 있습니다.

1. 순서가 없는 리스트 (unordered list)
2. 순서가 있는 리스트 (ordered list)
3. 정의 리스트 (definition list)

#### ul
`<ul>`을 사용해서 순서가 없는 리스트를 생성할 수 있습니다. `<li>`는 리스트 요소를 담당합니다.

```
<ul>
	<li>강아지</li>
	<li>고양이</li>
	<li>햄스터</li>
</ul>
```

#### ol
`<ol>`을 사용해서 순서가 있는 리스트를 생성할 수 있습니다. `<li>`는 리스트 요소를 담당합니다.

```
<ol>
	<li>일어나기</li>
	<li>밥먹기</li>
	<li>출근하기</li>
</ol>
```

#### dl
`<dl>`을 사용해서 정의 리스트를 생성할 수 있습니다. `<dt>`는 용어의 이름, `<dd>`는 용어의 설명을 담당합니다.

```
<dl>
	<dt>dt</dt>
	<dd>용어의 이름</dd>
	<dt>dd</dt>
	<dd>용어의 설명</dd>
</dl>
```

### 테이블 (Table)
- `<table>`으로 HTML에 테이블을 넣을 수 있습니다.

|요소|기능|
|---|---|
|tr|행을 구분함|
|th|열의 제목을 의미|
|td|각 셀(cell)을 의미|
|caption|테이블 상단에 제목을 추가|

```
<table>
	<caption>오늘의 식단표</caption>
	<tr>
		<th>식단</th>
		<th>메뉴</th>
	</tr>
	<tr>
		<td>아침</td>
		<td>참치김치볶음</td>
	</tr>
	<tr>
		<td>점심</td>
		<td>주먹밥</td>
	</tr>
	<tr>
		<td>저녁</td>
		<td>베이컨김치볶음밥</td>
	</tr>
</table>
```

|속성|값|
|---|---|
|colspan|현재 열부터 n만큼 떨어진 열을 병합|
|rowspan|현재 행부터 n만큼 떨어진 행을 병합|

```
<table>
	<tr>
		<th>식단</th>
		<th>메뉴</th>
		<th>후식</th>
	</tr>
	<tr>
		<td rowspan="2">브런치</td>
		<td>양념치킨</td>
		<td>망고주스</td>
	</tr>
	<tr>
		<td>새우튀김</td>
		<td>떠먹는요거트</td>
	</tr>
	<tr>
		<td>저녁</td>
		<td colspan="2">초코케이크</td>
	</tr>
</table>

```

## 디스플레이 (Display)
HTML에서 display 속성값은 2종류가 있습니다.

1. 블록(block): 항상 새 라인에서 시작하며, 해당 라인의 모든 넓이를 차지
2. 인라인(inline): 라인의 일부를 차지

### div
- `<div>`는 대표적인 블록 요소입니다.

```
<div><p>div를 사용해 요소를 블록으로 묶을 수 있습니다</p></div>
```

### span
- `<span>`는 대표적인 인라인 요소입니다.

```
<p><span>span를 사용해 일부분을</span> 묶을 수 있습니다</p>
```

### iframe
- `<iframe>`을 사용하면 HTML 문서 내부에 또다른 웹 페이지를 삽입할 수 있습니다. (inline frame)
- `<a>`를 사용해서 iframe이 표시하는 페이지를 바꿀 수 있습니다.

|속성|값|
|---|---|
|src|표시할 페이지 주소|

```
<iframe src="www.google.com"></iframe>
```

## 레이아웃 (Layout)
레이아웃(layout)은 특정 공간에 여러 구서 요소를 효과적으로 배치하는 작업입니다. HTML에서 보편적인 레이아웃 작성법은 2가지가 있습니다.

1. div 사용
2. HTML5 레이아웃

### div 레이아웃
`<div>`를 사용해서 레이아웃을 커스텀합니다. 구성 요소별로 CSS 스타일을 적용할 수 있다는 이점이 있습니다.

```
<div id="header">header 영역</div>
<div id="nav">nav 영역</div>
<div id="section">section 영역</div>
<div id="footer">footer 영역</div>
```

### HTML5 레이아웃
HTML5에선 레이아웃을 위한 별도의 요소인 의미(semantic) 요소를 제공합니다. (자세한 내용은 HTML5 - 의미 (Semantic) 참고)

## 입력 (Input)
### form
- `<form>`은 사용자의 입력 데이터를 서버 측의 페이지, 즉 폼 핸들러(form handler)로 전송할 수 있습니다.

|속성|값|
|---|---|
|action|처리할 페이지 주소|
|method|전달 방식: get/post|

```
<form action="/server.php" method="get"></form>
```

#### method 속성
- **GET**: 주소에 데이터를 포함하여 전달
	- 데이터가 주소를 통해 외부에 드러납니다.
	- 전달 가능한 데이터의 크기가 제한됩니다.
	- 크기가 작고 중요도가 낮은 데이터에 적합합니다.
- **POST**: 데이터를 별도로 첨부하여 전달
	- 데이터가 외부로부터 감춰집니다.
	- 전달 가능한 데이터 크기에 제한이 없습니다.
	- 보안성 및 활용성이 좋습니다.
	- GET 이외의 데이터는 POST를 사용합니다.

### input
`<input>`은 사용자의 입력을 받을 수 있습니다.

|속성|값|기능|
|---|---|---|
|type|string|입력 종류|
|value|string|입력 필드의 초기값|
|readonly|-|입력 필드 수정 불가 (서버 전송 O)|
|disabled|-|입력 필드 사용 불가 (서버 전송 X)|
|maxlength|number|입력 필드의 문자열 최대 길이|
|size|number|입력 필드에서 표시되는 문자열 최대 길이|

#### 속성
`<input>`의 `type` 속성이나 별도의 요소로 여러 입력을 추가할 수 있습니다.

|type|기능|
|---|---|
|text|한 줄의 텍스트|
|password|비밀번호|
|radio|라디오: 여러 개의 옵션 중 1개 선택|
|checkbox|체크박스: 여러 개의 옵션 중 여러 개 선택|
|file|파일 업로드|
|submit|전송 버튼: 폼 데이터를 폼 핸들러로 전송|

##### text
```
<form action="/server.php">
	아이디를 입력하세요: 
	<input type="text" name="id" value="abcd1234" maxlength="15" size="8">
</form>
```

##### password
```
<form action="/server.php">
	 비밀번호를 입력하세요: 
	<input type="password" name="pw">
</form>
```

##### radio
```
<form action="/server.php">
	원하는 아이템 1개를 고르세요: 
	<input type="radio" name="item" value="sword">검
	<input type="radio" name="item" value="shield">방패
	<input type="radio" name="item" value="spear">창
</form>
```

##### checkbox

|속성|값|기능|
|---|---|---|
|checked|-|처음부터 선택됨|
|disable|-|선택 불가|

```
<form action="/server.php">
	원하는 아이템 여러 개를 고르세요: 
	<input type="checkbox" name="item" value="sword" checked>검
	<input type="checkbox" name="item" value="shield">방패
	<input type="checkbox" name="item" value="spear" disable>창
</form>
```

##### file
`accept` 속성을 통해 업로드할 파일의 종류를 제한할 수 있습니다. 여러 개의 값을 추가한다면 or 연산자 `|`를 통해 묶을 수 있습니다.

|값|기능|
|---|---|
|파일 확장자|허용할 파일 확장자 (ex. .png, .doc)|
|`audio/*`|모든 오디오 파일|
|`video/*`|모든 비디오 파일|
|`image/*`|모든 이미지 파일|

```
<form action="/server.php">
	 오디오나 이미지 파일을 선택하세요: 
	<input type="file" name="upload_file" accept="audio/*|image/*">
</form>
```

##### submit
```
<form action="/server.php">
	아이디를 입력하세요: 
	<input type="text" name="id">
	<input type="submit" value="전송">
</form>
```

#### 요소
여러 입력 요소를 통해 입력을 받을 수 있습니다.

|요소|기능|
|---|---|
|`<select>`|드롭다운 리스트|
|`<textarea>`|여러 줄의 텍스트|
|`<button>`|버튼|
|`<fieldset>`|폼 요소와 관련된 데이터를 하나로 묶음|

##### select
`<option>` 요소로 드롭다운 리스트의 옵션을 넣을 수 있습니다.

|속성|값|기능|
|---|---|---|
|selected|-|처음부터 선택됨|

```
<form action="/server.php">
	원하는 아이템을 고르세요: 
	<select name="item">
		<option value="sword">검
		<option value="shield">방패
		<option value="spear" selected>창
	</select>
</form>
```

##### textarea

|속성|값|
|---|---|
|rows|세로 길이|
|cols|가로 길이|

```
<form action="/server.php">
	<textarea name="message" rows="5" cols="20">
	증원 유닛을 요청합니다.</textarea>
</form>
```

##### button
```
<button>버튼</button>
```

##### fieldset
`<legend>` 요소로 fieldset의 제목을 표시할 수 있습니다.

```
<form action="/server.php">
	<fieldset>
		<legend>계정 정보 입력</legend>
		<input type="text" name="id">
		<input type="password" name="pw">
		<input type="submit" value="전송">
	</fieldset>
</form>
```

## 확장 (Extension)
### CSS
HTML에서 CSS를 적용하는 방법은 3가지가 있습니다.

1. 인라인 스타일(Inline style)
2. 내부 스타일 시트(Internal style sheet)
3. 외부 스타일 시트(External style sheet)

적용 우선순위는 다음 순서와 같습니다.
1. 인라인 스타일
2. 내부/외부 스타일 시트: 둘다 있다면 가장 마지막(아래쪽) 것이 적용됩니다.
3. 웹 브라우저 기본 스타일

#### 인라인 스타일 (Inline style)
태그 내 `style` 속성을 이용하는 방법입니다.

```
<p style="color:blue">인라인 스타일입니다. 이 태그 내에서만 적용됩니다.</p>
```

#### 내부 스타일 시트(Internal style sheet)
`<style>` 요소를 사용하는 방법입니다.

```
<style>
	body { background-color: green; }
	div { color: white; background-color: yellow; }
</style>
<body>
	body 스타일이 적용됩니다.
	<div>div 스타일이 적용됩니다.</div>
</body>
```

#### 외부 스타일 시트(External style sheet)
`<link>` 요소를 통해 외부 css 파일을 적용하는 방법입니다.

```
<link rel="stylesheet" href="/style.css">
```

### Javascript
`<script>`를 사용해서 HTML 문서에 javascript를 넣을 수 있습니다.

```
<script>
	alert("여기는 javascript 영역입니다.");
</script>
```

`src` 속성을 사용해서 외부 js파일을 참조할 수 있습니다. src를 사용하면 태그 내 스크립트는 무시됩니다.
```
<script src="/script.js">
	alert("이 스크립트는 실행되지 않습니다.");
</script>
```

`<noscript>`는 스크립트 미지원시 표시되는 문자열을 설정합니다.
```
<noscript>
	스크립트가 지원되지 않는 브라우저입니다.
</noscript>
```

### XHTML
`XHTML(EXtensible HTML)`은 문법이 보다 엄격한 HTML입니다. 기존 HTML에서 허용하던 기법이 XHTML에선 안될 수 있습니다.

- XHTML DOCTYPE을 반드시 명시해야 합니다.
- 모든 태그는 순서대로 닫혀 있어야 합니다.
- 속성 이름은 반드시 소문자여야 합니다.

이 외에 여러 가지 변경사항이 있습니다.

## HTML5
`HTML5`는 HTML의 최신 표준입니다.

### 기본 구조
HTML5에선 다음이 허용됩니다.
- 태그 이름 대문자 가능
- 속성값 따옴표 생략 가능
- 속성값 생략 가능
- 빈 태그 종료 태그(/) 생략 가능

- DOCTYPE 선언
```
<!DOCTYPE html>
```

- 문자셋 선언 (HTML5의 기본 문자 인코딩 방식은 UFT-8입니다.)
```
<meta charset="UFT-8">
```

### 의미 (Semantic)
HTML5에선 레이아웃을 위한 별도의 요소인 의미(semantic) 요소를 제공합니다. 의미 요소는 그 자체로 의미를 가지며, 브라우저나 독자에게 해당 요소의 의미를 명확히 전달할 수 있습니다. 의미 요소의 예시는 다음과 같습니다.

|요소|기능|
|---|---|
|header|HTML 문서/섹션의 헤더 설정|
|nav|HTML 문서의 탐색 링크 정의|
|section|HTML 문서 내 섹션(section)을 정의 (전체적인 내용과 관련 있는 컨텐츠 집합)|
|article|HTML 문서에서 독립저인 1개의 글을 정의|
|figure|HTML 문서에서 그래픽, 비디오 등 독립적 컨텐츠를 정의|
|figcaption|`<figure>`의 캡션을 정의|
|aside|HTML 문서에서 페이지 외적 내용을 정의|
|footer|HTML 문서/섹션의 푸터 설정|

### 입력 (Input)
HTML5에서 추가된 `<form>`, `<input>`의 속성이 있습니다.

|`<form>` 속성|값|기능|
|---|---|---|
|autocomplete|on/off|입력 데이터 자동저장/자동완성|
|novalidate|-|내부 `<input>`의 유효성 검사 미실시 (email, url 등)|

|`<input>` 속성|값|기능|적용 가능|
|---|---|---|---|
|autocomplete|on/off|입력 데이터 자동저장/자동완성|text, password, range, color, date, datetime-local, month, week, email, url, tel, search|
|autofocus|-|페이지 로드시 해당 요소에 자동으로 포커스(focus)|url, email 등|
|form|string|적용할 `<form>`의 id 속성값. 현재 코드적 위치와 관계없이 포함될 `<form>` 명시|-|
|formaction|string|입력 데이터를 전송할 서버 파일의 위치. 기존 `<form>`의 action 속성을 덮어씀|submit, image|
|formenctype|string|입력데이터의 암호화 방식. 기존 `<form>`의 enctype 속성을 덮어씀. post method만 사용 가능|submit, image|
|formmethod|get/post|입력 데이터를 전송할 method 방식. 기존 `<form>`의 method 속성을 덮어씀|submit, image|
|formnovalidate|-|유효성 검사 미실시. 기존 `<form>`의 novalidate 속성을 덮어씀|submit|
|formtarget|string|응답 페이지 출력 위치. 기존 `<form>`의 target 속성을 덮어씀|submit, image|
|height|number|image의 높이|image|
|width|number|image의 너비|image|
|list|string|적용할 `<datalist>`의 id 속성값|text 등|
|min|number|제한 범위의 최솟값|number, range, date, time, datetime-local, month, week|
|max|number|제한 범위의 최댓값|number, range, date, time, datetime-local, month, week|
|multiple|-|2개 이상의 값 입력 가능|email, file|
|pattern|정규 표현식|정규 표현식(regular expression)으로 입력 제한|text, password, email, tel, url|
|placeholder|string|배경에 희미하게 표시되는 값(입력에 대한 힌트)|text, password, email, tel, url, search|
|required|-|반드시 입력되어야 함을 명시|-|
|step|number|입력 가능한 수 간격 명시 (ex. step="2"면 가능한 수는 -2, 0, 2, 4...)|number, range, date, time, datetime-local, month, week|

#### 요소
HTML5에서 추가된 입력 요소가 있습니다.

|요소|기능|
|---|---|
|`<datalist>`|미리 정의된 옵션 리스트|
|`<keygen>`|전송 데이터 암호화|
|`<output>`|스크립트 등의 결과를 바로 표시|

##### datalist
`<datalist>`는 미리 정의된 옵션 리스트입니다. 다른 input 요소에 datalist를 추가할 수 있으며, 추가 방법은 다음과 같습니다.

> 적용할 `<input>`의 `list` 속성 값 == `<datalist>`의 `id` 속성 값

```
<form action="/server.php">
	<input type="text" list="item">
		<datalist id="item">
			<option value="sword">
			<option value="shield">
			<option value="spear">
		</datalist>
	</input>
</form>
```

##### keygen
`<keygen>`은 전송될 입력 데이터를 암호화합니다. 서버 측은 keygen 요소에서 생성된 key를 통해 데이터를 복호화할 수 있습니다.

```
<form action="/server.php">
	<input type="text" name="userId">
	<keygen name="security">
	<input type="submit" value="전송">
</form>
```

##### output
`<output>`는 스크립트 등의 결과를 바로 표시해줍니다.

|속성|값|기능|
|---|---|---|
|for|관련 요소의 id 속성 목록 (공백으로 구분)|`<output>`과 관련있는 요소를 HTML 문서에 명시적으로 표시|

```
<form action="/server.php" oninput="result.value=str1.value+str2.value">
	<p>두 문자열이 합성됩니다.</p>
	<input type="text" id="str1"><br>
	<input type="text" id="str2"><br>
	<output name="result" for="str1 str2"></output>
</form>
```

#### 속성
HTML5에서 추가된 `<input>`의 type 속성값이 있습니다.

|type|기능|
|---|---|
|number|숫자 입력|
|range|수평바|
|color|색상 입력|
|date|날짜 입력|
|time|시간 입력|
|datetime-local|날짜&시간 입력|
|month|연도&월 입력|
|week|연도&주 입력|
|email|이메일 입력|
|url|URL 주소 입력|
|tel|전화번호 입력|
|search|검색어 입력|

##### number
텍스트박스와 비슷하나, 숫자만 입력 가능합니다.

|속성|값|
|---|---|
|min|제한 범위의 최소값|
|max|제한 범위의 최대값|

```
<input type="number" min="1" max="9">
```

##### range
수평바를 통해 수를 입력받습니다.

|속성|값|
|---|---|
|min|제한 범위의 최소값|
|max|제한 범위의 최대값|

```
1<input type="range" min="1" max="9">9
```

##### color
색상을 입력받습니다. value 속성은 색상을 값으로 합니다. (기본 값은 검정입니다.)

```
<input type="color" value="#0000FF">
```

##### date
날짜를 입력받는 캘린더를 제공합니다. value 속성은 날짜를 값으로 합니다.

|속성|값|
|---|---|
|min|제한 범위의 최소 날짜|
|max|제한 범위의 최대 날짜|

```
<input type="date" min="2023-06-01" max="2023-06-30">
```

##### time
```
<input type="time">
```

##### datetime-local
```
<input type="datetime-local">
```

##### month
```
<input type="month">
```

##### week
```
<input type="week">
```

##### email
입력이 유효한 이메일 주소인지 자동으로 검사해줍니다.

```
<input type="email">
```

##### url
입력이 유효한 URL 주소인지 자동으로 검사해줍니다.

```
<input type="url">
```

##### tel
```
<input type="tel">
```

##### search
내용을 지우는 삭제 버튼을 제공합니다.

```
<input type="search">
```

### 멀티미디어 (Multimedia)
#### 비디오 (Video)
HTML5에서 지원하는 비디오 파일 형식은 MP4, WebM, OGV입니다.

|요소|기능|
|---|---|
|`<video>`|비디오 삽입|
|`<source>`|멀티미디어 삽입|
|`<track>`|비디오 재생시 표시될 자막/캡션 파일|

```
<video controls>
	<source src="/source/movie.mp4">
	<source src="/sound/music.ogg">
	<track src="/subtitle/korean.vtt" kind="subtitles" srclang="kr" label="Korean">
</video>
```

##### video

|속성|값|기능|
|---|---|---|
|controls|-|재생, 정지 등 비디오 동작 제어 패널을 표시|
|autoplay|-|페이지 로드시 비디오 자동재생|
|loop|-|비디오 반복재생|

##### source

|속성|값|기능|
|---|---|---|
|src|string|파일 경로|
|autoplay|-|페이지 로드시 비디오 자동재생|
|loop|-|비디오 반복재생|

##### track

|속성|값|기능|
|---|---|---|
|src|string|파일 경로|
|kind|string|자막 문자열의 타입|
|srclang|string|자막 언어 설정 (en, kr 등)|
|label|string|표시될 라벨|

#### 오디오 (Audio)
HTML5에서 지원하는 오디오 파일 형식은 MP3, WAV, OGG입니다.

|요소|기능|
|---|---|
|`<audio>`|오디오 삽입|
|`<source>`|멀티미디어 삽입|

```
<video controls>
	<source src="/sound/music1.mp3">
	<source src="/sound/music2.ogg">
</video>
```

##### audio

|속성|값|기능|
|---|---|---|
|controls|-|재생, 정지 등 오디오 동작 제어 패널을 표시|
|autoplay|-|페이지 로드시 오디오 자동재생|
|loop|-|오디오 반복재생|

#### 플러그인 (Plug-in)
HTML 플러그인(plug-in)은 웹 브라우저의 표준 기능을 확장해 주는 프로그램입니다. (ex. Java Applet, Flash Player 등)

플러그인을 추가하는 방법은 2가지가 있습니다.
- `<object>` 사용
- `<embed>` 사용

##### object
`<object>`를 사용해서 HTML 문서에 객체를 넣을 수 있습니다.

|속성|값|기능|
|---|---|---|
|data|string|파일 경로|

```
<object data="/resource/game.swf"></object>
```

##### embed
`<embed>`를 사용해서 HTML 문서에 객체를 넣을 수 있습니다.

|속성|값|기능|
|---|---|---|
|src|string|파일 경로|

```
<embed data="/resource/walkthrough.pdf"></embed>
```

### 그래픽 (Graphic)
HTML 그래픽 요소는 크게 2가지가 있습니다.

|그래픽|Canvas|SVG|
|---|---|---|
|기반|pixel 기반|shape 기반|
|HTML 요소|단일 HTML 요소|여러 HTML 요소|
|제어 방법|스크립트로 제어 가능|HTML 요소나 스크립트로 제어 가능|
|좌표계|제4사분면|제4사분면|
|렌더링 시간|화면 크기가 클수록 급격히 증가 => 작은 화면, 많은 픽셀이면 효율적|픽셀 수가 많을수록 급격히 증가 => 큰 화면, 적은 픽셀이면 효율적|
|용도|복잡하고 고성능의 애니메이션, 영상, 게임에 적합|고품질 문서, 정적 이미지에 적합|

#### Canvas
`<canvas>`는 웹 페이지에 그래픽을 담는 컨테이너이며, 다양한 그래픽을 표시할 수 있습니다.

canvas 제어는 자바스크립트로 진행합니다. canvas의 2d context를 통해 평면 그래픽을 그릴 수 있습니다.

```
<canvas id="board" style="width:300px; height:300px; border:1px"></canvas>
<script>
	const canvas = document.getElementById("board");
	const context = canvas.getContext("2d");
</script>
```

|context 프로퍼티|기능|
|---|---|
|fillStyle|현재 영역의 색상/그라디언트|
|font|현재 텍스트의 크기, 폰트, 색상 등|

|context 메서드|기능|
|---|---|
|fillRect(x, y, width, height)|사각형 영역 채우기|
|strokeRect(x, y, width, height)|사각형 영역 테두리 그리기|
|clearRect(x, y, width, height)|사각형 영역 지우기|
|moveTo(x, y)|초기 시작점 설정|
|lineTo(x, y)|현재 점에서 (x, y)까지 이동|
|fill()|시작점에서 도착점까지 영역 채우기|
|storke()|시작점에서 도착점까지 선 그리기|
|beginPath()|경로 그리기 시작|
|closePath()|경로 그리기 종료|
|arc(x, y, radius, startRadian, endRadian)|원호 그리기|
|fillText(text, x, y)|텍스트 채우기|
|strokeText(text, x, y)|텍스트 테두리 그리기|
|createLinearGradient(x1, y1, x2, y2)|선형 그라디언트 생성 (시작점, 끝점)|
|createRadialGradient(x1, y1, r1, x2, y2, r2)|원형 그라디언트 생성 (시작원, 끝원)|
|drawImage(img, x, y)|이미지 그리기 (img = Image 객체)|

|gradient 메서드|기능|
|---|---|
|addColorStop(position, color)|그라디언트 색 추가 (시작 = 0, 끝 = 1)|

##### 사각형
```
<canvas id="board" style="width:300px; height:300px; border:1px"></canvas>
<script>
	const canvas = document.getElementById("board");
	const context = canvas.getContext("2d");

	context.fillStyle = "rgba(0,255,0,1)";
	context.fillRect(30, 30, 100, 100);
	context.fillStyle = "rgba(0,0,0,0.5)";
	context.strokeRect(30, 30, 120, 120);
	context.clearRect(50, 50, 60, 60);
</script>
```

##### 선
```
<canvas id="board" style="width:300px; height:300px; border:1px"></canvas>
<script>
	const canvas = document.getElementById("board");
	const context = canvas.getContext("2d");

	context.moveTo(10, 10);
	context.lineTo(100, 60);
	context.lineTo(60, 100);
	context.lineTo(10, 10);
	context.fillStyle = "#00CCDD";
	context.fill();
	context.stroke();
</script>
```

##### 원호
```
<canvas id="board" style="width:300px; height:300px; border:1px"></canvas>
<script>
	const canvas = document.getElementById("board");
	const context = canvas.getContext("2d");

	context.beginPath();
	context.arc(50, 50, 100, 0, 2 * Math.PI);
	context.closePath();
	context.stroke();
</script>
```

##### 텍스트
```
<canvas id="board" style="width:300px; height:300px; border:1px"></canvas>
<script>
	const canvas = document.getElementById("board");
	const context = canvas.getContext("2d");

	context.font = "20px Arial #223344";
	context.fillText("Welcom To", 40, 40);
	context.strokeText("Canvas", 60, 80);
</script>
```

##### 그라디언트
```
<canvas id="board" style="width:300px; height:300px; border:1px"></canvas>
<script>
	const canvas = document.getElementById("board");
	const context = canvas.getContext("2d");
	
	const g1 = context.createRadialGradient(50, 50, 100, 100, 100, 200);
	g1.addColorStop(0, "white");
	g1.addColorStop(1, "black");
	context.fillStyle = g1;
	context.fillRect(0, 0, 300, 300);
	
	const g2 = context.createLinearGradient(50, 50, 100, 100);
	g2.addColorStop(0, "red");
	g2.addColorStop(1, "blue");
	context.fillStyle = g2;
	context.fillRect(50, 50, 50, 50);
</script>
```

##### 이미지
```
<canvas id="board" style="width:300px; height:300px; border:1px"></canvas>
<script>
	const canvas = document.getElementById("board");
	const context = canvas.getContext("2d");

	const img = new Image();
	img.src = "/image/picture.png";
	img.addEventListener('load', () => {
		// 이미지 로딩 완료시 실행됩니다.
		ctx.drawImage(img, 50, 50);
	});
</script>
```

#### SVG
`SVG(Scalable Vector Graphics)`는 XML 기반 W3C 그래픽 표준 권고안으로, 벡터 이미지를 표현할 수 있습니다. 벡터 이미지는 픽셀의 영향을 받지 않습니다. `<svg>`를 사용해서 SVG를 그릴 수 있습니다.

|요소|기능|
|---|---|
|`<rect>`|사각형 그리기|
|`<line>`|선 그리기|
|`<circle>`|원 그리기|
|`<ellipse>`|타원 그리기|
|`<polygon>`|다각형 그리기|

각 요소의 속성은 CSS에도 존재합니다.

##### rect

|속성|값|기능|
|---|---|---|
|x|number|도형 x위치|
|y|number|도형 y위치|
|rx|number|모서리 굴곡의 x축 반지름|
|ry|number|모서리 굴곡의 y축 반지름|
|width|number|도형 너비|
|height|number|도형 높이|
|stroke|color|도형 테두리 색상|
|stroke-width|number|도형 테두리 굵기|
|fill|color|도형 채우기 색상|
|opacity|\[0, 1\]|도형 투명도|

```
<svg width="300" height="200">
	<rect width="200" height="150" stroke="green" fill="orange" opacity="0.5" x="25" y="25" rx="20" ry="20">
</svg>
```

##### line

|속성|값|기능|
|---|---|---|
|x1|number|선 시작점 x|
|y1|number|선 시작점 y|
|x2|number|선 도착점 x|
|y2|number|선 도착점 y|
|stroke|color|선 테두리 색상|
|stroke-width|number|선 테두리 굵기|

```
<svg width="300" height="200">
	<line x1="25" y1="30" x2="50 y2="100" stroke="teal">
</svg>
```

##### circle

|속성|값|기능|
|---|---|---|
|cx|number|원 중심점 x|
|cy|number|원 중심점 y|
|r|number|원 반지름 길이|

```
<svg width="300" height="200">
	<circle fill="orange" cx="100" cy="100" r="50">
</svg>
```

##### ellipse

|속성|값|기능|
|---|---|---|
|cx|number|타원 중심점 x|
|cy|number|타원 중심점 y|
|rx|number|타원 x축 반지름|
|rx|number|타원 y축 반지름|

```
<svg width="300" height="200">
	<ellipse fill="orange" cx="100" cy="100" rx="100" ry="50">
</svg>
```

##### polygon

|속성|값|기능|
|---|---|---|
|points|x1,y1 x2,y2 ...|다각형을 그리는 순차 좌표점|

```
<svg width="300" height="200">
	<polygon fill="orange" stroke="yellow" points="50,50 50,75 75,50 50,50">
</svg>
```

### API
HTML5는 자바스크립트로 구현된 API를 새롭게 제공합니다.

#### geolocation API
`geolocation API`는 사용자 동의하에 사용자의 현재 위치 정보를 제공하는 API입니다. HTTPS에서만 사용 가능합니다.

|메소드|반환|기능|
|---|---|---|
|getCurrentPosition(success(pos), error(err))|-|사용자의 현재 위치를 가져옴. 성공시 success, 오류시 error 콜백 함수 실행|
|watchPosition(success(pos), error(err))|위치변화 감지 콜백 id|사용자의 움직임을 지속 추적하고 위치 정보를 갱신. 성공시 success, 오류시 error 콜백 함수 실행|
|clearWatch(id)|-|id를 통해 위치변화 감지를 해제|

```
function locationSuccess(position) {
	const lat = position.coords.latitude;
	const lgt = position.coords.longitude;
	console.log("현재 위치는 (" + lat + ", " + lgt + ") 입니다.");
}

function errorHandling(err) {
	console.log("오류 발생!");
}

function main() {
	if(navigator.geolocation) {
		navigator.geolocation.getCurretPosition(locationSuccess, errorHandling);
	}
	else {
		console.log("geolocation API가 지원되지 않습니다!");
	}
}
```

- 위치 객체 coords의 프로퍼티

|프로퍼티|값|
|---|---|
|latitude|위도|
|longitude|경도|
|accuracy|정확도|
|altitude|해발 고도|
|altitudeAccuracy|해발 고도 정확도|

#### drag and drop API
드래그와 드롭 기능을 제공하는 API입니다.

#### web storage API
웹 브라우저가 직접 데이터를 저장하는 방법을 제공하는 API로, 기존 브라우저 쿠키의 문제점을 보완합니다.

#### application cache API
웹 응용 프로그램 캐시 API입니다.

#### web worker API
스크립트 다중 스레드 API입니다.

#### server sent events API
웹 페이지가 갱신된 서버 정보를 자동으로 받는 방법을 제공하는 API입니다.

## 출처 (Reference)
tcpschool.com/html/intro