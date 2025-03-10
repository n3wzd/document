---
categories:
- Jekyll
date: '2025-03-08'
title: '[Jekyll] Jekyll'
---

{% raw %}
1. **정적 사이트 생성**  
    Jekyll은 **정적 사이트**를 생성하는 도구입니다. 이는 서버 사이드 처리 없이, **고정된 콘텐츠**를 보여주는 방식입니다.
2. **Markdown 지원**  
    Jekyll은 기본적으로 Markdown 형식의 파일을 HTML로 변환합니다. 블로그 포스트나 문서 파일을 마크다운으로 작성하고, Jekyll이 이를 웹 페이지 형식으로 자동 변환해줍니다.
3. **자동화된 빌드 시스템**  
    Jekyll은 파일을 업데이트할 때마다 자동으로 빌드합니다. 즉, 작성한 내용을 저장하고 나면 자동으로 웹사이트가 업데이트됩니다.
4. **카테고리, 태그 및 날짜 관리**  
    Jekyll은 블로그 포스트를 날짜별, 카테고리별, 태그별로 자동 분류해줍니다. 마크다운 파일의 파일명을 `YYYY-MM-DD-파일명.md`와 같은 형식으로 작성하면 날짜별로 자동으로 포스트가 정렬됩니다.
5. **개발자 친화적인 시스템**  
    Jekyll은 사용자가 자신만의 테마를 만들거나 기존 테마를 수정할 수 있도록 유연하게 설계되었습니다. HTML, CSS, JavaScript 등의 웹 기술에 대한 기본적인 이해가 있으면 쉽게 커스터마이징할 수 있습니다.

## 사용
Jekyll은 Ruby로 작성되어 있기 때문에 먼저 Ruby를 설치해야 합니다. 

Jekyll과 Bundler를 설치합니다:
```bash
gem install jekyll bundler
```

Jekyll 프로젝트를 새로 시작하려면 아래 명령어를 사용하여 새 프로젝트를 생성할 수 있습니다.
```bash
jekyll new my-blog
cd my-blog
```

 `my-blog`는 생성할 디렉토리 이름입니다.

### 실행
새로 생성된 Jekyll 프로젝트 디렉토리로 이동한 후, 아래 명령어로 로컬 서버를 실행하여 웹사이트를 확인할 수 있습니다.

```bash
bundle exec jekyll serve
```

위 명령어를 실행하면 Jekyll이 로컬 서버를 시작합니다. 기본적으로 `http://localhost:4000`에서 실행됩니다.

## 파일 구조
Jekyll 프로젝트 디렉토리 구조는 다음과 같습니다:

```
my-blog/
├── _config.yml       # Jekyll 사이트의 설정 파일
├── _posts/           # 블로그 포스트가 저장되는 폴더
├── _site/            # 빌드된 사이트가 저장되는 디렉토리
├── index.md          # 홈페이지 (기본 페이지)
└── Gemfile           # 필요한 Ruby Gems 목록
```

- `_config.yml`: 사이트 설정 파일로, 제목, 설명, URL 등을 설정할 수 있습니다.
- `_posts/`: 마크다운 파일로 블로그 포스트를 작성합니다. 파일 이름은 `YYYY-MM-DD-포스트제목.md` 형식이어야 합니다.
- `index.md`: 홈페이지 파일입니다. 사이트의 첫 번째 페이지에 표시됩니다.
- `_site/`: `jekyll serve` 명령을 실행하면 자동으로 빌드된 HTML 파일들이 저장됩니다.

### 포스트
`_posts/` 디렉토리에 블로그 포스트를 마크다운 파일로 추가할 수 있습니다:
```
---
layout: post
title: "My First Post"
date: 2025-03-08
categories: [blog, introduction]
---

# Welcome to my new blog!

This is my first blog post using Jekyll. It's simple and easy to use.
```

- **layout**: 페이지의 레이아웃을 지정합니다. 일반적으로 `post` 레이아웃을 사용합니다.
- **title**: 블로그 포스트의 제목입니다.
- **date**: 포스트의 날짜입니다.
- **categories**: 포스트를 카테고리별로 분류할 수 있습니다.

## 배포
사이트가 완성되면, 로컬 서버에서 빌드한 파일들을 GitHub Pages, Netlify, 또는 다른 호스팅 서비스에 배포할 수 있습니다.

## 테마
기본적으로 Jekyll은 다양한 테마를 지원하며, 이를 통해 사이트 디자인을 빠르게 변경할 수 있습니다.

### 기본
Jekyll의 기본 테마 중 하나는 **Minima**입니다.

`_config.yml`:
```yaml
theme: minima
```

### 커스터마이징
테마가 제공하는 레이아웃, 스타일, 자바스크립트 파일 등을 직접 수정할 수 있습니다.

- `_layouts`: Jekyll 사이트의 HTML 레이아웃을 정의합니다. `default.html`, `post.html`, `page.html` 등이 여기에 포함됩니다.
- `_includes`: 공통적으로 사용되는 HTML 코드 조각이 저장됩니다. 헤더, 푸터, 내비게이션 메뉴 등을 포함됩니다.
- `_sass`: 테마의 스타일을 정의하는 SCSS(Sass) 파일을 포함합니다. CSS 스타일을 직접 수정하거나 추가할 수 있습니다.
{% endraw %}