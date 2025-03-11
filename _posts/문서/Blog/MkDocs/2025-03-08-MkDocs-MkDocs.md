---
categories:
- MkDocs
date: '2025-03-08'
title: '[MkDocs] MkDocs'
---

{% raw %}
**MkDocs**는 정적 사이트 생성기로, 주로 Markdown 형식으로 작성된 문서들을 쉽게 웹사이트 형태로 변환해주는 도구입니다. MkDocs를 사용하면 기술 블로그, 문서화 사이트, 포트폴리오 등을 손쉽게 구축할 수 있습니다. 주로 개발자들이 기술 문서를 작성하거나, 프로젝트 문서화에 많이 사용합니다.

1. **Markdown 지원**: 문서 내용은 모두 Markdown 형식으로 작성할 수 있습니다. 문서화 작업에 있어 매우 직관적이고 간단합니다.
2. **정적 사이트 생성**: MkDocs는 정적 사이트를 생성합니다. 즉, 서버 없이 정적 HTML 파일만으로 웹사이트를 호스팅할 수 있습니다.
3. **테마 지원**: 여러 가지 테마가 내장되어 있어, 사용자가 손쉽게 원하는 스타일로 문서를 꾸밀 수 있습니다.
4. **검색 기능 제공**: 기본적으로 검색 기능을 제공하여 많은 문서 중에서 필요한 내용을 쉽게 찾을 수 있습니다.
5. **배포가 쉬움**: 생성된 사이트는 GitHub Pages, Netlify 등 다양한 플랫폼에서 쉽게 호스팅할 수 있습니다.

## 설치 및 사용
1. **MkDocs 설치**: Python이 설치되어 있다면, 터미널에서 아래 명령어로 MkDocs를 설치할 수 있습니다:

```
pip install mkdocs
```

2. **프로젝트 생성**: MkDocs 프로젝트를 생성하려면 아래 명령어를 사용합니다:

```
mkdocs new my-project
cd my-project
```

3. **문서 작성**: 생성된 `docs/` 폴더에 Markdown 파일을 작성합니다.

4. **로컬 서버 실행**: 로컬에서 사이트를 확인하려면:

```
mkdocs serve
```

웹 브라우저에서 `http://127.0.0.1:8000`을 열면 문서를 볼 수 있습니다.
    
5. **배포**: GitHub Pages나 다른 서버에 배포하려면:

```
mkdocs gh-deploy
```


## 테마
MkDocs는 기본적으로 **`mkdocs.yml`** 설정 파일을 통해 다양한 테마와 기능을 설정할 수 있습니다.

설치:
```bs
pip install mkdocs-material
```

적용:
```yaml
site_name: 내 기술 블로그
theme:
  name: material
```

## 카테고리
MkDocs는 파일 및 폴더 구조를 사용하여 자연스럽게 카테고리를 만들 수 있습니다. Markdown 파일들을 폴더별로 분류하면, MkDocs는 이를 자동으로 네비게이션에 반영하여 카테고리화된 문서 사이트를 만들어 줍니다.

MkDocs는 폴더 구조를 그대로 사용하여 카테고리 분류가 가능합니다. 예를 들어, 문서 파일들을 카테고리별로 폴더에 정리하고, `mkdocs.yml` 파일에서 해당 폴더를 네비게이션에 반영하면 됩니다.

파일:
```
docs/
├── index.md  # 홈 페이지
├── 프로젝트/
│   ├── 프로젝트1.md
│   ├── 프로젝트2.md
├── 기술_스터디/
│   ├── Spring.md
│   ├── Node.js.md
```

`mkdocs.yml`:
```yaml
site_name: 내 블로그
theme:
  name: material

nav:
  - 홈: index.md
  - 프로젝트:
      - "프로젝트 1": 프로젝트/프로젝트1.md
      - "프로젝트 2": 프로젝트/프로젝트2.md
  - 기술 스터디:
      - "Spring": 기술_스터디/Spring.md
      - "Node.js": 기술_스터디/Node.js.md
```
{% endraw %}