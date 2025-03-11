---
categories:
- Jekyll
date: '2025-03-08'
title: '[Jekyll] minimal-mistakes'
---

{% raw %}
Jekyll의 **minimal-mistakes** 테마는 인기 있는 깔끔하고 직관적인 디자인을 제공하는 무료 테마입니다.

> https://github.com/mmistakes/minimal-mistakes?tab=readme-ov-file<br>

설치: `minimal-mistakes`의 GitHub 저장소를 클론하고, Jekyll 프로젝트에 복사합니다.

불필요한 파일은 삭제합니다.
- `.github/`
- `test/`
- `.editorconfig`
- `.gitattributes`
- `.travis.yml`
- `CHANGELOG.md`
- `README.md`
- `screenshot.png`
- `screenshot-layout.png`

### There was an error while loading `minimal-mistakes-jekyll.gemspec`: No such file or directory @ rb_sysopen - package.json. Bundler cannot continue.
로컬 서버 재시작시 발생하는 오류이며, `_site` 폴더를 삭제하면 해결됩니다.

### Quick-Start Guide 삭제
`_data/navigation.yml`에서 상단 바 메뉴를 관리합니다. "Quick-Start Guide" 항목을 삭제합니다.

```
main:
  - title: "Quick-Start Guide"
    url: https://mmistakes.github.io/minimal-mistakes/docs/quick-start-guide/
```

### 컴포넌트 찾기
브라우저의 개발자 도구(F12)에서 Elements으로 간편하게 찾을 수 있습니다.

### 카테고리 페이지 추가
`_pages/` 폴더를 생성하고 각 카테고리마다 md 파일을 생성합니다.
```
---
title: "{title}"
layout: archive
permalink: {permalink}
---

{% assign posts = site.categories.{category} %}
{% for post in posts %} {% include archive-single.html %} {% endfor %}
```
- `title`: 표시되는 카테고리 이름
- `permalink`: 라우팅 경로 (예: categories/menu)
- `category`: post에 작성한 카테고리

하단 내용을 넣으면 `permalink`에 라우팅되는 카테고리 페이지가 추가됩니다. (`archive-single.html`: `_includes/`에 위치한 메뉴 UI입니다.)

### 카테고리 사이드 메뉴 추가
`_includes/sidebar.html`에서 다음을 추가합니다. (카테고리 수에 따라 `ul` 개수를 늘릴 수 있습니다.)
```
{% assign sum = site.posts | size %}
  
<nav class="nav__list">
  <ul class="nav__items" id="category_tag_menu">
	<span class="nav__sub-title">PS</span>
	<ul>
		{% for category in site.categories %}
			{% if category[0] == "{category}" %}
				<li><a href="/categories/boj" class="">카테고리명 ({{category[1].size}})</a></li>
			{% endif %}
		{% endfor %}
	</ul>
  </ul>
</nav>
```

### 본문 오른쪽 여백 제거
`_sass/minimal-mistakes/_page.scss`에서 `padding-inline-end`를 제거합니다.

```
.page {
  @include breakpoint($large) {
    float: inline-end;
    width: calc(100% - #{$right-sidebar-width-narrow});
    padding-inline-end: $right-sidebar-width-narrow;
  }
  
  @include breakpoint($x-large) {
    width: calc(100% - #{$right-sidebar-width});
    padding-inline-end: $right-sidebar-width;
  }
```

### page 최대 넓이 조정
`_sass/minimal-mistakes/_variables.scss`에서 `$x-large`의 값을 조정합니다. (초기 값 = 1280)

```
small: 600px !default;
$medium: 768px !default;
$medium-wide: 900px !default;
$large: 1024px !default;
$x-large: 1280px !default;
$max-width: $x-large !default;
```

### 홈 화면에서 프로필 메뉴 활성
`_include/sidebar.html`에서 초기 조건문을 수정하거나 삭제합니다.

```
{% if page.author_profile or layout.author_profile or page.sidebar %}
```

### 폰트 크기 조정
`_sass/minimal-mistakes/_variables.scss`에서 `$doc-font-size`의 값을 조정합니다. (
초기 값: 16)

```
$doc-font-size: 14px !default;
```

### 프로필 사진 조정
`_sass/minimal-mistakes/_sidebar.scss`에서 `.author__avatar`를 수정합니다.
{% endraw %}