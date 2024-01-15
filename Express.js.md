# Express.js
Express.js는 Node.js를 위한 간단하고 유연한 웹 애플리케이션 프레임워크입니다. Express.js를 사용하면 웹 애플리케이션 및 API를 쉽게 작성하고 구축할 수 있습니다.

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

미들웨어는 요청-응답 주기 동안 다음 미들웨어로 제어를 전달하거나 응답을 종료할 수 있습니다. 이를 통해 요청을 가로채고 수정하거나, 특정 작업을 수행하거나, 에러를 처리하는 등의 다양한 작업을 수행할 수 있습니다.

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

### 기본 미들웨어
Express에는 몇 가지 기본 미들웨어가 내장되어 있습니다. 예를 들어, `express.json()`은 JSON 형식의 요청 바디를 파싱하는 데 사용되는 미들웨어이며, `express.urlencoded()`는 URL-encoded 데이터를 파싱하는 데 사용됩니다.
```
const express = require('express');
const app = express();

app.use(express.json()); // JSON 파싱 미들웨어
app.use(express.urlencoded({ extended: true })); // URL 인코딩 미들웨어
```

### 커스텀 미들웨어 추가
`app.use()` 메서드를 사용하여 커스텀 미들웨어를 추가할 수 있습니다. 커스텀 미들웨어는 애플리케이션의 모든 라우트에 적용됩니다.

```
app.use((req, res, next) => {
  console.log('Middleware executed!');
  next(); // 다음 미들웨어로 전달
});
```
        
### 라우트별 미들웨어
특정 라우트에만 미들웨어를 적용하려면 `app.get()`를 사용합니다.

```
app.get('/special', (req, res, next) => {
  console.log('Special route middleware');
  next();
}, (req, res) => {
  res.send('Special route!');
});
```

### 에러 핸들링 미들웨어
에러 핸들링 미들웨어는 에러가 발생했을 때 실행되는 미들웨어입니다. 다음과 같이 에러 핸들링 미들웨어를 등록할 수 있습니다.

```
app.use((err, req, res, next) => {
  console.error(err.stack);
  res.status(500).send('Something went wrong!');
});
```
