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

## 라우팅 (Routing)
Express.js에서 라우팅(Routing)은 클라이언트의 요청에 대한 응답을 처리하는 주요 메커니즘입니다. 라우터를 사용하여 애플리케이션의 각 엔드포인트(Endpoint)에 대한 동작을 정의할 수 있습니다. 라우팅은 HTTP 메소드(GET, POST, PUT, DELETE 등)와 경로에 따라 처리됩니다.

라우터에서 요청을 처리하는 함수를 핸들러(Handler)라고 합니다. 핸들러는 클라이언트의 요청에 대한 응답을 생성합니다. 아래에서는 Express.js에서 라우팅과 핸들러의 사용에 대해 자세히 설명합니다.

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

### 여러 핸들러 사용
라우트에 여러 핸들러를 사용할 수 있습니다. 다음 핸들러로 전달하기 위해 `next` 함수를 사용합니다.

```
app.get('/example', (req, res, next) => {
  // 첫 번째 핸들러
  console.log('First handler');
  next();
}, (req, res) => {
  // 두 번째 핸들러
  console.log('Second handler');
  res.send('Done');
});
```

위의 코드에서 첫 번째 핸들러는 `next()`를 호출하여 다음 핸들러로 제어를 전달합니다.


### 라우터 분리
Express에서는 라우터를 모듈로 분리하여 관리할 수 있습니다. 이는 애플리케이션이 복잡해질 때 코드를 구조화하는 데 유용합니다.

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

## 템플릿 엔진 (Template Engine)
Express.js에서 템플릿 엔진을 사용하면 동적인 HTML 페이지를 생성할 수 있습니다. 템플릿 엔진은 서버 측에서 데이터를 템플릿과 결합하여 클라이언트에게 돌려주는 역할을 합니다. Express.js에서는 주로 EJS(Embedded JavaScript)와 같은 템플릿 엔진을 많이 사용합니다.

### 템플릿 엔진 설치
템플릿 엔진을 npm을 통해 설치합니다. 여기서는 EJS를 예로 들겠습니다.
    
> npm install ejs
    
### Express에 템플릿 엔진 설정
Express 앱에서 템플릿 엔진을 사용하려면 설정을 추가해야 합니다. `app.set()` 메서드를 사용하여 템플릿 엔진의 뷰 엔진을 설정합니다.

```
const express = require('express');
const app = express();

app.set('view engine', 'ejs');
```

위의 코드에서 `'view engine'`은 Express에게 사용할 뷰 엔진의 종류를 알려주며, `'ejs'`는 EJS를 사용하겠다는 의미입니다.

### 템플릿 파일 생성
EJS를 사용하는 경우 `.ejs` 확장자를 가진 템플릿 파일을 생성합니다. 예를 들어, `views` 폴더에 `index.ejs` 파일을 만들어 보겠습니다. 
    
```
<!-- views/index.ejs -->
<html>
<head>
  <title><%= title %></title>
</head>
<body>
  <h1><%= message %></h1>
</body>
</html>
```

위의 예제에서 `<%= title %>`과 `<%= message %>`는 템플릿 엔진에 의해 동적으로 채워질 부분입니다.

### 템플릿 렌더링
라우터 핸들러에서 `res.render()` 메서드를 사용하여 템플릿을 렌더링합니다.

```
app.get('/', (req, res) => {
  res.render('index', { title: 'Express', message: 'Welcome to Express!' });
});
```

위의 코드에서 `'index'`는 `views` 폴더에 있는 `index.ejs` 템플릿 파일을 참조합니다. 두 번째 인수로 전달된 객체는 템플릿에 전달될 데이터입니다.

뷰 템플릿에서는 `<%= 변수명 %>`을 통해 서버에서 전달받은 데이터를 출력할 수 있습니다. 예를 들어, 위의 템플릿에서는 `title`과 `message`라는 변수를 사용하여 동적으로 HTML을 생성합니다.

## 정적 파일 서비스 (Static File Service)
Express.js에서 정적 파일 서비스는 이미지, CSS, JavaScript와 같은 정적 파일을 제공하는 기능을 의미합니다. 이는 Express.js 앱에서 클라이언트에게 정적 파일을 전송하고 웹 페이지에 포함시키는 데 사용됩니다. 정적 파일 서비스를 설정함으로써, 클라이언트는 해당 파일에 대한 요청을 보내고 Express.js 앱은 그에 맞는 정적 파일을 응답으로 전송합니다.

### express.static
Express.js에서 정적 파일 서비스를 설정하려면 `express.static` 미들웨어를 사용합니다. 이 미들웨어는 특정 디렉토리의 정적 파일을 제공하는 역할을 합니다.

```
const express = require('express');
const app = express();

// public 디렉토리에 있는 정적 파일을 서비스
app.use(express.static('public'));
```

위의 코드에서 `express.static('public')`은 현재 디렉토리의 `public` 폴더에서 정적 파일을 찾아 서비스하라는 의미입니다.

### 여러 디렉토리에서 정적 파일 서비스
여러 디렉토리에서 정적 파일을 서비스하려면 `express.static`을 여러 번 사용할 수 있습니다.

```
app.use(express.static('public'));
app.use(express.static('images'));
```
위의 코드에서는 `public` 폴더와 `images` 폴더에 있는 정적 파일을 서비스합니다.

### 별칭(Alias)을 사용한 정적 파일 서비스
`express.static`을 사용하여 정적 파일 서비스를 설정할 때, 특정 URL 경로에 대해 해당 디렉토리의 파일을 서비스할 수 있습니다.
    
```
app.use('/static', express.static('public'));
```

위의 코드에서 `/static` 경로로 들어오는 요청은 `public` 폴더의 정적 파일을 참조합니다.

### 캐싱 제어
기본적으로 Express.js는 정적 파일을 캐싱하여 성능을 향상시킵니다. 개발 환경에서는 캐싱을 비활성화하여 변경 사항이 바로 반영되도록 할 수 있습니다.

```
app.use(express.static('public', { maxAge: 0 }));
```

위의 코드에서 `maxAge: 0`은 캐싱을 비활성화하는 옵션입니다.

### 기타 옵션
`express.static`에는 다양한 옵션을 설정할 수 있습니다. 예를 들어, 인덱스 파일을 사용할 것인지, 확장자를 무시할 것인지 등을 설정할 수 있습니다.
    
```
app.use(express.static('public', {
  index: 'home.html',
  extensions: ['html', 'htm'] 
}));
```

위의 코드에서 `index`는 디렉토리의 기본 파일을 설정하고, `extensions`는 허용할 파일 확장자를 지정합니다.

## 인증 (Authentication)
사용자 인증(Authentication)과 세션(Session) 관리는 웹 애플리케이션에서 중요한 보안 개념 중 하나입니다.

### 사용자 인증(Authentication)
#### Passport.js 설치
`passport` 및 `passport-local`을 사용하여 사용자 인증을 구현할 수 있습니다. `passport`는 Node.js용 인증 미들웨어이며, `passport-local`은 username과 password를 사용한 로그인을 처리하는 Local Strategy를 제공합니다.
    
> npm install passport passport-local

#### Passport 초기화
Passport를 초기화하고 세션을 사용할 수 있도록 설정합니다.

```
const passport = require('passport');
const LocalStrategy = require('passport-local').Strategy;

app.use(passport.initialize());
app.use(passport.session());
```

#### 사용자 모델 및 인증 전략 정의
사용자 모델을 정의하고 Passport에 사용자 인증 전략을 등록합니다.
 
```
const User = require('./models/user');

passport.use(new LocalStrategy(
  (username, password, done) => {
    User.findOne({ username: username }, (err, user) => {
      if (err) { return done(err); }
      if (!user) { return done(null, false, { message: 'Incorrect username.' }); }
      if (!user.validPassword(password)) { return done(null, false, { message: 'Incorrect password.' }); }
      return done(null, user);
    });
  }
));
```
    
#### 세션 직렬화 및 역직렬화
Passport는 세션에 사용자 정보를 저장하고 복원할 때 사용하는 직렬화 및 역직렬화 함수를 설정해야 합니다.

```
passport.serializeUser((user, done) => {
  done(null, user.id);
});

passport.deserializeUser((id, done) => {
  User.findById(id, (err, user) => {
    done(err, user);
  });
});
```

#### 라우트에서 Passport 사용
Passport를 사용하여 로그인, 로그아웃 및 인증이 필요한 라우트를 설정합니다.

```
app.post('/login', passport.authenticate('local', {
  successRedirect: '/dashboard',
  failureRedirect: '/login',
  failureFlash: true
}));

app.get('/logout', (req, res) => {
  req.logout();
  res.redirect('/');
});

function isLoggedIn(req, res, next) {
  if (req.isAuthenticated()) {
    return next();
  }
  res.redirect('/login');
}

app.get('/dashboard', isLoggedIn, (req, res) => {
  res.render('dashboard', { user: req.user });
});
```

### 세션 관리(Session Management)
#### express-session 설치
`express-session` 미들웨어를 사용하여 세션을 관리합니다.

> npm install express-session
    
#### express-session 설정
`express-session`을 초기화하고 세션 저장소를 설정합니다.

```
const session = require('express-session');

app.use(session({
  secret: 'your-secret-key',
  resave: false,
  saveUninitialized: false
}));
```

`secret`은 세션 데이터를 서명할 때 사용되는 비밀 키입니다.

#### 세션을 Passport에 연결
Passport와 `express-session`을 연결하여 세션을 처리합니다.

```
app.use(passport.initialize());
app.use(passport.session());
```

#### 세션 사용 예제
세션을 사용하여 사용자 상태를 유지하고 로그인 여부를 확인합니다.

```
app.use((req, res, next) => {
  res.locals.isAuthenticated = req.isAuthenticated();
  res.locals.currentUser = req.user;
  next();
});
```

위의 미들웨어를 사용하면 뷰 템플릿에서 `isAuthenticated`와 `currentUser` 변수를 사용할 수 있습니다.
