# Express.js
Express.js는 Node.js를 위한 간단하고 유연한 웹 애플리케이션 프레임워크입니다. Express.js를 사용하면 웹 애플리케이션 및 API를 쉽게 작성하고 구축할 수 있습니다.

Express는 http 모듈을 기반으로 동작하며, http 모듈의 기능을 보완하고 편리하게 사용할 수 있도록 도와줍니다. Express는 http 모듈보다 더 추상화된 인터페이스를 제공하여 웹 애플리케이션을 빠르게 개발할 수 있도록 합니다.

Express를 사용하면 기존의 http 모듈을 사용하는 것보다 웹 애플리케이션을 더 빠르고 쉽게 개발할 수 있습니다. 하지만 Express는 http 모듈에 비해 추상화된 인터페이스를 제공하므로, 더 낮은 수준의 커스터마이징이나 특정 요구사항에 대한 직접적인 접근이 필요한 경우에는 http 모듈을 직접 사용하는 것이 더 적합할 수 있습니다.

## 시작
Express.js를 설치하려면 먼저 Node.js와 npm(Node Package Manager)이 시스템에 설치되어 있어야 합니다.

### 1. Express.js 설치
Express.js는 npm을 통해 설치할 수 있습니다. 프로젝트 디렉토리를 만들고 해당 디렉토리에서 터미널을 열고 다음 명령어를 실행합니다.

> npm install express

이 명령은 Express.js를 현재 프로젝트에 로컬로 설치합니다. `-g` 플래그를 사용하면 전역으로 설치할 수도 있지만, 보통 프로젝트마다 의존성을 따로 관리하는 것이 좋습니다.

### 2. Express 앱 생성
Express.js를 설치한 후, 프로젝트 디렉토리에서 `app.js` 또는 `index.js`와 같은 파일을 생성하고 다음과 같이 작성합니다.

```
const express = require('express');
const app = express();
const port = 3000;

app.get('/', (req, res) => {
  res.send('Hello, Express!');
});

app.listen(port, () => {
  console.log(`Server is running at http://localhost:${port}`);
});
```

### 3. Express 앱 실행
터미널에서 프로젝트 디렉토리로 이동한 후 다음 명령어로 Express 앱을 실행합니다.

> node app.js
        
웹 브라우저에서 `http://localhost:3000`으로 접속하면 "Hello, Express!"가 표시됩니다.
        
## 미들웨어 (Middleware)
미들웨어(Middleware)는 Express.js 애플리케이션에서 HTTP 요청(request)과 응답(response) 사이에서 동작하는 함수입니다. 미들웨어는 요청과 응답 오브젝트에 접근하고 조작할 수 있으며, Express 애플리케이션에서는 이러한 미들웨어를 사용하여 다양한 작업을 수행합니다. 미들웨어는 주로 `app.use()` 메서드를 통해 애플리케이션에 추가됩니다.

- **모듈화:** 애플리케이션 로직을 작은 단위로 분리하여 관리하기 쉽습니다.
- **재사용성:** 미들웨어를 재사용하여 다양한 라우트에서 동일한 기능을 수행할 수 있습니다.
- **확장성:** 새로운 기능을 추가하기 위해 미들웨어를 추가하거나 수정하면 됩니다.

실행 과정:
```
request => [ middleware1, middleware2... ] => response
```

미들웨어는 요청-응답 주기 동안 다음 미들웨어로 제어를 전달하거나 응답을 종료할 수 있습니다. 이를 통해 요청을 가로채고 수정하거나, 특정 작업을 수행하거나, 에러를 처리하는 등의 다양한 작업을 수행할 수 있습니다.

또한 미들웨어는 요청 객체(request)를 수정할 수 있습니다. 예를 들어, 특정 헤더를 추가하거나, 요청 본문을 파싱하여 객체에 저장할 수 있습니다. 다음 미들웨어는 이렇게 변경된 요청 객체를 기반으로 동작합니다.

- **미들웨어의 활용 예시:**
- **인증:** 사용자 인증을 처리하는 미들웨어
- **권한 확인:** 사용자 권한을 확인하는 미들웨어
- **로그 기록:** 요청/응답 정보를 로그에 기록하는 미들웨어
- **데이터 변환:** 요청 데이터를 변환하거나 응답 데이터를 포맷팅하는 미들웨어
- **에러 처리:** 에러를 잡아 처리하는 미들웨어

### 미들웨어 함수
미들웨어는 함수로 표현되며, 다음과 같은 형태를 가지고 있습니다.
```
function myMiddleware(req, res, next) {
  // 미들웨어 작업 수행
  // req: 요청 오브젝트
  // res: 응답 오브젝트
  // next: 다음 미들웨어로 전달하는 함수
}
```

### 미들웨어 순서
`app.use()` 메서드로 추가되는 미들웨어는 등록된 순서대로 실행됩니다. 따라서 `use` 메서드를 호출하는 위치가 미들웨어의 실행 순서를 결정합니다.

- **데이터 변형:** 이전 미들웨어에서 데이터를 변형하면 다음 미들웨어에서 사용할 수 있는 데이터가 달라집니다.
- **성능:** 자주 사용되는 미들웨어는 앞쪽에 배치하여 성능을 향상시킬 수 있습니다.
- **에러 처리:** 에러 처리 미들웨어는 다른 미들웨어 뒤에 위치해야 합니다.
- **로깅:** 로그를 남기는 미들웨어는 요청 처리의 처음이나 끝에 배치하여 전체적인 요청 흐름을 파악하는 데 도움을 줄 수 있습니다.

```
app.use(logger);
app.use(cookieParser());
app.use(express.json());
app.use('/api', router);
```

위 코드에서 미들웨어는 다음과 같은 순서로 실행됩니다.

1. **logger:** 모든 요청에 대한 로그를 남깁니다.
2. **cookieParser:** 쿠키를 파싱합니다.
3. **express.json():** JSON 형식의 요청 본문을 파싱합니다.
4. **router:** `/api`로 시작하는 URL에 대한 라우팅을 처리합니다.

### 미들웨어 종류
#### 기본 미들웨어
Express에는 몇 가지 기본 미들웨어가 내장되어 있습니다. 예를 들어, `express.json()`은 JSON 형식의 요청 바디를 파싱하는 데 사용되는 미들웨어이며, `express.urlencoded()`는 URL-encoded 데이터를 파싱하는 데 사용됩니다.
```
const express = require('express');
const app = express();

app.use(express.json()); // JSON 파싱 미들웨어
app.use(express.urlencoded({ extended: true })); // URL 인코딩 미들웨어
```

#### 커스텀 미들웨어
`app.use()` 메서드를 사용하여 커스텀 미들웨어를 추가할 수 있습니다. 커스텀 미들웨어는 애플리케이션의 모든 라우트에 적용됩니다.

```
app.use((req, res, next) => {
  console.log('Middleware executed!');
  next(); // 다음 미들웨어로 전달
});
```
        
#### 라우트별 미들웨어
`app.get()`을 사용하여 특정 라우터에서만 동작하는 공통 미들웨어를 정의할 수 있습니다.

```
app.get('/special', (req, res, next) => {
  console.log('Special route middleware');
  next();
}, (req, res) => {
  res.send('Special route!');
});
```

위 미들웨어는 `/special`를 포함하는 모든 라우터에서 공통적으로 실행됩니다.

#### 에러 핸들링 미들웨어
에러 핸들링 미들웨어는 에러가 발생했을 때 실행되는 미들웨어입니다. 다음과 같이 에러 핸들링 미들웨어를 등록하면 예외 처리를 전역으로 할 수 있습니다. 일반적으로 에러 핸들링 미들웨어는 다른 미들웨어 뒤에 위치하는 것이 좋습니다.

```
app.use((err, req, res, next) => {
  console.error(err.stack);
  res.status(500).send('Something went wrong!');
});
```

## 라우팅 (Routing)
Express.js에서 라우팅(Routing)은 클라이언트의 요청에 대한 응답을 처리하는 주요 메커니즘입니다. 라우터를 사용하여 애플리케이션의 각 엔드포인트(Endpoint)에 대한 동작을 정의할 수 있습니다. 라우팅은 HTTP 메소드(GET, POST, PUT, DELETE 등)와 경로에 따라 처리됩니다.

### 기본 라우팅
Express.js에서 기본적인 라우팅은 `app.get()`, `app.post()`, `app.put()`, `app.delete()` 등의 메소드를 사용하여 정의됩니다. 아래는 간단한 GET 요청에 대한 라우팅 예제입니다.

```
const express = require('express');
const app = express();

app.get('/', (req, res) => {
  res.send('Hello, World!');
});
```

위의 코드에서 `/` 경로로의 GET 요청에 대한 핸들러 함수가 정의되어 있습니다. 요청이 들어오면 "Hello, World!"를 응답으로 보냅니다.

### 다이나믹 라우팅
Express에서는 동적인 경로 매개변수를 사용하여 다이나믹 라우팅을 구현할 수 있습니다.

```
app.get('/users/:userId', (req, res) => {
  const userId = req.params.userId;
  res.send(`User ID: ${userId}`);
});
```

위의 코드에서 `:userId`는 동적인 매개변수로, 실제 요청에서 해당 위치에 들어온 값은 `req.params.userId`를 통해 접근할 수 있습니다.

### Router
Express에서는 `Router`를 사용하여 모듈로 분리하여 관리할 수 있습니다.

```
// routes.js
const express = require('express');
const router = express.Router();

router.get('/example', (req, res) => {
  res.send('Example route');
});

module.exports = router;

// app.js
const express = require('express');
const app = express();
const routes = require('./routes');

app.use('/', routes);
```

위의 예제에서 `/example` 경로는 `routes.js` 파일에 정의된 라우터에 의해 처리됩니다.
