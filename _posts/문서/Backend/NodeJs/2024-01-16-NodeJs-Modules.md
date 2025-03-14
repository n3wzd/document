---
categories:
- NodeJs
date: '2024-01-16'
title: '[NodeJs] Modules'
---

{% raw %}
Node.js에서 모듈은 코드를 논리적으로 구성하고 재사용 가능하게 만드는 데 사용되는 단위입니다. 모듈을 사용하여 코드를 분리하고 각 부분을 독립적으로 개발하고 테스트할 수 있습니다. 

Node.js에서 모듈은 일반적으로 싱글톤처럼 동작합니다. 즉, 하나의 모듈을 여러 번 `require()` 하더라도 메모리 상에는 단 하나의 인스턴스만 존재하게 됩니다. Node.js는 `require()`를 통해 모듈을 처음 로드할 때 메모리에 캐시합니다. 이후 같은 모듈을 다시 요구하면 캐시된 인스턴스를 반환합니다.

### CommonJS (CJS)
Node.js는 **CommonJS** 스펙을 따르며, 모듈 시스템은 `require` 및 `module.exports`를 사용하여 구현됩니다. 모듈을 로드할 때 프로그램 실행이 멈추고 모듈을 먼저 로드하는 동기적 로딩을 사용합니다.

- 서버 사이드 환경에서 널리 사용됩니다.
- 동기적 로딩 방식으로 인해 브라우저 환경에서는 직접 사용하기 어렵습니다.

ECMAScript 2015 (ES6) 모듈은 JavaScript 표준에 공식적으로 포함된 모듈 시스템으로, 새로운 프로젝트를 시작한다면 ES Modules를 사용하여 더 현대적이고 표준적인 방식으로 개발하는 것이 좋습니다. 하지만 기존 프로젝트와의 호환성이나 개발팀의 선호도에 따라 CommonJS를 사용할 수도 있습니다.

#### 모듈 생성
`module.exports`: 모듈에서 내보낼 값을 지정합니다.

```
// math.js

// 더하기 함수
function add(a, b) {
  return a + b;
}

// 뺄셈 함수
function subtract(a, b) {
  return a - b;
}

// 모듈에서 내보내기
module.exports = {
  add,
  subtract
};
```

#### 모듈 가져오기
모듈을 다른 파일에서 사용하려면 `require` 함수를 사용합니다.

```
// app.js

// math.js 모듈 가져오기
const math = require('./math');

// 더하기 함수 호출
const sum = math.add(5, 3);
console.log('Sum:', sum);

// 뺄셈 함수 호출
const difference = math.subtract(8, 4);
console.log('Difference:', difference);
```

### 내장 모듈
Node.js는 기본적으로 몇 가지 내장 모듈을 제공합니다. 이러한 모듈들은 별도의 설치 없이 사용할 수 있습니다. 몇 가지 예시는 다음과 같습니다:

- `fs`: 파일 시스템과 상호 작용할 수 있는 메서드를 제공하는 모듈.
- `http`: HTTP 서버 및 클라이언트를 생성하는 모듈.
- `path`: 파일 경로와 관련된 작업을 수행할 수 있는 모듈.
- `os`: 운영 체제 정보에 접근할 수 있는 모듈.

```
const fs = require('fs');
const http = require('http');
const path = require('path');
const os = require('os');
```

이러한 내장 모듈은 Node.js 설치와 함께 제공되며, `require`를 통해 가져와서 사용할 수 있습니다.
{% endraw %}