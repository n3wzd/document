# Node.js
`Node.js`는 JavaScript를 사용하여 서버 측 프로그래밍을 할 수 있게 해주는 오픈 소스 런타임 환경입니다. 주로 비동기 이벤트 기반의 서버 측 애플리케이션을 개발하는 데 사용됩니다.

1. **비동기성(Asynchronous):** Node.js는 비동기 이벤트 기반의 프로그래밍 모델을 사용합니다. 이는 입출력 작업이나 네트워크 호출과 같은 비동기 작업을 효율적으로 처리할 수 있도록 도와줍니다.
2. **이벤트 기반(Event-driven):** Node.js는 이벤트 기반의 아키텍처를 기반으로 합니다. 이벤트가 발생하면 콜백 함수가 호출되어 처리됩니다. 이러한 구조는 서버가 여러 작업을 동시에 처리할 수 있도록 합니다.
3. **단일 스레드(Single-threaded):** Node.js는 단일 스레드에서 동작하지만, 비동기적인 방식으로 작업을 처리하여 동시성을 지원합니다. 이를 통해 높은 처리량과 확장성을 얻을 수 있습니다.
4. **모듈 시스템:** Node.js는 CommonJS 스펙을 따르는 모듈 시스템을 사용합니다. 이를 통해 코드를 모듈화하고 재사용성을 높일 수 있습니다.
5. **패키지 관리자(NPM):** Node.js는 NPM(Node Package Manager)을 통해 패키지(라이브러리 및 도구)를 쉽게 설치하고 관리할 수 있습니다.
6.  **크로스 플랫폼:** Node.js는 Windows, macOS, Linux 등 다양한 플랫폼에서 실행할 수 있습니다.
7.  **V8 엔진:** Node.js는 구글에서 개발한 V8 JavaScript 엔진을 사용하여 JavaScript 코드를 빠르게 실행합니다.

## 시작
### 1. Node.js 설치
Node.js를 사용하려면 먼저 공식 웹 사이트에서 Node.js를 다운로드하고 설치해야 합니다. [Node.js 공식 웹 사이트](https://nodejs.org/)에서 최신 버전을 다운로드하고 설치합니다.

### 2. 실행
터미널을 열고 프로젝트 디렉토리로 이동합니다. 그리고 다음 명령어를 실행하여 코드를 실행합니다.

> node (파일명)

## 모듈 (Modules)
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

## NPM
NPM (Node Package Manager)은 Node.js 패키지를 관리하고 배포하기 위한 온라인 리포지터리 및 커맨드 라인 도구입니다. NPM은 Node.js 설치와 함께 기본적으로 제공되며, JavaScript 프로젝트에서 필요한 라이브러리, 도구, 의존성을 쉽게 관리할 수 있도록 도와줍니다.

1. **패키지 설치 및 의존성 관리:** NPM은 패키지를 설치하고 관리하는 기능을 제공합니다. `npm install` 명령어를 사용하여 프로젝트에 필요한 라이브러리를 쉽게 설치할 수 있습니다. 패키지 정보는 `package.json` 파일에 기록되며, `npm install` 명령어만으로 필요한 의존성을 모두 가져올 수 있습니다.
2. **패키지 배포:** 개발한 패키지를 NPM 리포지터리에 배포할 수 있습니다. 이를 통해 다른 개발자들이 해당 패키지를 사용할 수 있게 됩니다.
3. **버전 관리:** NPM은 의존성 버전을 효과적으로 관리합니다. `package.json` 파일에는 사용 중인 패키지들과 버전 범위가 명시되어 있습니다. 버전 충돌이 발생할 경우 `npm audit` 명령어로 보안 취약점을 확인할 수 있습니다.
4. **스크립트 실행:** `package.json` 파일에는 프로젝트와 관련된 여러 스크립트를 정의할 수 있습니다. 이를 통해 테스트, 빌드, 실행 등의 작업을 쉽게 수행할 수 있습니다.
5. **온라인 패키지 검색:** NPM 웹사이트에서는 수많은 패키지를 검색하고 해당 패키지의 문서를 확인할 수 있습니다. [NPM 웹사이트](https://www.npmjs.com/)

### NPM 명령어
- **패키지 설치:** `npm install 패키지이름` 
- **글로벌 패키지 설치:** `npm install -g 패키지이름` 
- **패키지 삭제:** `npm uninstall 패키지이름` 
- **개발 의존성으로 패키지 설치:** `npm install --save-dev 패키지이름` 
- **NPM 스크립트 실행:** `npm run 스크립트이름` 
- **패키지 업데이트:** `npm update` 
- **NPM 버전 확인:** `npm -v` 
- **패키지 검색:** `npm search 패키지이름` 

### NPX
`npm`과 `npx`는 둘 다 Node.js 패키지 관리 도구에 속하며, JavaScript 패키지를 설치하고 실행하는 데 사용됩니다. `npm`은 프로젝트의 종속성을 관리하고 스크립트를 실행하는 데에 사용되며, `npx`는 글로벌로 설치하지 않고도 일시적으로 필요한 패키지를 실행할 때 사용됩니다.

**NPM**
- `npm`은 Node.js 패키지를 관리하는 도구로, 패키지를 전역(global) 또는 로컬로 설치할 수 있습니다.
- 일반적으로 프로젝트의 종속성(dependency)을 관리하고, `package.json` 파일에 명시된 패키지들을 설치합니다.
- 전역으로 설치된 패키지는 프로젝트 내에서 직접 실행할 수 있습니다.

**NPX**
- `npx`는 npm 패키지를 실행하고 설치하지 않고도 사용할 수 있도록 하는 도구입니다.
- 주로 로컬에 설치된 패키지가 아닌, 일회성으로 사용되어야 하는 패키지를 실행할 때 편리합니다.
- 특정 버전의 패키지를 설치하지 않고 최신 버전을 사용할 수 있습니다.

## HTTP
Node.js의 `http` 모듈은 HTTP 웹 서버와 클라이언트를 생성하고 상호 작용하기 위한 메서드와 속성을 제공하는 내장 모듈입니다. 이 모듈은 웹 애플리케이션을 개발하고 웹 서버를 만드는 데 사용됩니다.

HTTP 서버를 만들려면 `http` 모듈을 사용하여 서버를 생성하고, 서버에 이벤트 핸들러를 등록합니다. 예를 들어, 간단한 "Hello, World!"를 반환하는 HTTP 서버를 만들어 보겠습니다.

### HTTP 서버 만들기
```
// http 모듈 가져오기
const http = require('http');

// 서버 생성
const server = http.createServer((req, res) => {
  // HTTP 헤더 설정
  res.writeHead(200, {'Content-Type': 'text/plain'});

  // 응답 전송
  res.end('Hello, World!\n');
});

// 서버 포트 3000에서 실행
const PORT = 3000;
server.listen(PORT, () => {
  console.log(`Server running at http://localhost:${PORT}/`);
});
```

위의 코드에서 `createServer` 메서드로 서버를 생성하고, 요청(`req`)과 응답(`res`)을 다루는 콜백 함수를 전달합니다. 서버는 3000번 포트에서 실행되며, 요청이 들어올 때마다 "Hello, World!"를 응답으로 보냅니다.

### HTTP 클라이언트
`http` 모듈은 HTTP 클라이언트도 만들 수 있습니다. 다른 서버로 HTTP 요청을 보내고 응답을 받는 데 사용됩니다.

```
// http 모듈 가져오기
const http = require('http');

// 요청 설정
const options = {
  hostname: 'www.example.com',
  port: 80,
  path: '/',
  method: 'GET',
};

// HTTP 요청 생성
const req = http.request(options, (res) => {
  // 응답 데이터를 받을 때의 처리
  let data = '';

  res.on('data', (chunk) => {
    data += chunk;
  });

  res.on('end', () => {
    console.log(data);
  });
});

// 요청 전송
req.end();
```

위의 코드에서 `http.request` 메서드로 HTTP 요청을 생성하고, 요청에 대한 응답을 처리하기 위해 이벤트 리스너를 등록합니다. 이 예제에서는 간단한 GET 요청을 `www.example.com`으로 보내고 응답을 콘솔에 출력합니다.

## fs
Node.js의 `fs` 모듈은 파일 시스템과 상호 작용하기 위한 메서드를 제공하는 내장 모듈입니다. 이 모듈을 사용하면 파일을 읽고 쓰며, 디렉토리를 생성하고 삭제할 수 있습니다.

`fs` 모듈의 메서드들은 대부분 비동기적으로 동작하며, 동기적인 버전도 제공됩니다. (예: `readFileSync`, `writeFileSync` 등)

### 파일 읽기
`readFile` 메서드는 지정된 파일을 비동기적으로 읽어옵니다. 파일이 성공적으로 읽혔을 때 콜백 함수가 호출되며, 콜백 함수의 두 번째 매개변수인 `data`에는 파일의 내용이 포함됩니다.

```
const fs = require('fs');

// 파일 읽기
fs.readFile('example.txt', 'utf8', (err, data) => {
  if (err) {
    console.error(err);
    return;
  }
  console.log(data);
});
```

### 파일 쓰기
`writeFile` 메서드는 비동기적으로 파일에 데이터를 씁니다. 파일이 성공적으로 쓰여졌을 때 콜백 함수가 호출됩니다.

```
const fs = require('fs');

// 파일 쓰기
const content = 'Hello, Node.js!';
fs.writeFile('example.txt', content, 'utf8', (err) => {
  if (err) {
    console.error(err);
    return;
  }
  console.log('File written successfully!');
});
```

### 디렉토리 생성
`mkdir` 메서드는 비동기적으로 디렉토리를 생성합니다. 생성에 성공하면 콜백 함수가 호출됩니다.

```
const fs = require('fs');

// 디렉토리 생성
fs.mkdir('exampleDir', (err) => {
  if (err) {
    console.error(err);
    return;
  }
  console.log('Directory created successfully!');
});
```

### 파일 또는 디렉토리 삭제
`unlink` 메서드는 파일을, `rmdir` 메서드는 디렉토리를 비동기적으로 삭제합니다.

```
const fs = require('fs');

// 파일 삭제
fs.unlink('example.txt', (err) => {
  if (err) {
    console.error(err);
    return;
  }
  console.log('File deleted successfully!');
});

// 디렉토리 삭제
fs.rmdir('exampleDir', (err) => {
  if (err) {
    console.error(err);
    return;
  }
  console.log('Directory deleted successfully!');
});
```

## MySQL
MySQL과 Node.js를 연동하려면 MySQL 드라이버를 사용하여 Node.js 애플리케이션에서 MySQL 데이터베이스에 접속하고 상호 작용해야 합니다. 이를 위해 `mysql` 또는 `mysql2`를 사용할 수 있습니다.

새로운 프로젝트를 시작한다면, `mysql2` 모듈을 사용하는 것이 권장되며, 이하 설명도 `mysql2`을 기준으로 합니다.

### mysql vs mysql2
`mysql`과 `mysql2`는 둘 다 Node.js에서 MySQL과 상호 작용하기 위한 드라이버 모듈들입니다.

- `mysql2` 모듈이 성능 측면에서 뛰어나며, 더 많은 기능을 제공합니다.
- `mysql` 모듈은 여전히 많은 프로젝트에서 사용되고 있으며, 작은 프로젝트나 기존 코드베이스에서 업그레이드하기 어려운 경우에는 유용할 수 있습니다.

**성능**:
- **mysql:** `mysql` 모듈은 비동기 I/O를 사용하면서도, 백그라운드에서 동기적인 쿼리를 수행하므로, 성능에 제한이 있을 수 있습니다.
- **mysql2:** `mysql2` 모듈은 비동기 I/O를 완전히 활용하여 성능이 높습니다. 특히, Connection Pooling 기능을 내장하고 있어 더 효과적으로 여러 연결을 관리할 수 있습니다.

**Promise 및 async/await 지원**:
- **mysql:** `mysql` 모듈은 Callback 스타일의 인터페이스를 주로 사용하며, Promise나 async/await를 직접 지원하지 않습니다. Promise를 사용하려면 추가적인 래퍼 함수나 라이브러리를 사용해야 합니다.
- **mysql2:** `mysql2` 모듈은 기본적으로 Promises를 지원하고 있어, Callback 스타일과 함께 async/await를 쉽게 사용할 수 있습니다.

**Prepared Statements**:
- **mysql:** `mysql` 모듈은 Prepared Statements를 지원하지만, 일부 제한 사항이 있을 수 있습니다.
- **mysql2:** `mysql2` 모듈은 더욱 향상된 Prepared Statements 지원을 제공하고, 더 많은 옵션과 기능을 제공합니다.

**Multiple Statements**:
- **mysql:** `mysql` 모듈은 Multiple Statements 기능을 가지고 있지만, 기본적으로 비활성화되어 있습니다.
- **mysql2:** `mysql2` 모듈은 Multiple Statements를 활성화한 채로 제공되며, 여러 쿼리를 한 번에 실행할 수 있습니다.

**자료형 변환**:
- **mysql:** `mysql` 모듈은 자동으로 JavaScript 데이터 유형으로 변환하는 기능이 제한적입니다.
- **mysql2:** `mysql2` 모듈은 더 나은 자료형 변환 기능을 제공하고, JavaScript와 MySQL 간의 데이터 유형 변환을 더 정확하게 처리합니다.

### MySQL 연결 설정
연결 정보를 설정하고 연결을 만듭니다.

```
const mysql = require('mysql2');

const connection = mysql.createConnection({
  host: 'localhost',  // MySQL 서버 호스트
  user: 'root',       // MySQL 사용자명
  port: 3306,       // MySQL 포트
  password: 'password', // MySQL 비밀번호
  database: 'dbname'   // 연결할 데이터베이스 이름
});

// 연결 생성
connection.connect((err) => {
  if (err) {
    console.error('Error connecting to MySQL:', err);
    return;
  }
  console.log('Connected to MySQL!');
});

// 연결 종료
connection.end((err) => {
  if (err) {
    console.error('Error closing MySQL connection:', err);
    return;
  }
  console.log('MySQL connection closed.');
});
```

### 쿼리
MySQL 연결이 설정되면 쿼리를 수행하여 데이터베이스와 상호 작용할 수 있습니다.

```
// SELECT 쿼리 수행
connection.query('SELECT * FROM tableName', (err, results, fields) => {
  if (err) {
    console.error('Error executing SELECT query:', err);
    return;
  }

  console.log('Query results:', results);
});

// INSERT 쿼리 수행
const newRecord = { name: 'John', age: 30 };
connection.query('INSERT INTO tableName SET ?', newRecord, (err, results) => {
  if (err) {
    console.error('Error executing INSERT query:', err);
    return;
  }

  console.log('Inserted record ID:', results.insertId);
});
```

### Connection Pool
연결 풀(Connection Pool)은 데이터베이스와의 연결을 미리 여러 개 생성해 놓고, 필요할 때마다 연결 풀에서 연결을 가져다 사용하고, 사용이 끝나면 다시 풀로 반환하는 방식입니다. 많은 사용자가 동시에 접속하는 웹 애플리케이션에서는 연결 풀을 사용하여 시스템 부하를 분산하고 안정적인 서비스를 제공할 수 있습니다.

- **성능 향상:** 매번 새로운 연결을 생성하는 오버헤드를 줄여 성능을 향상시킵니다.
- **자원 효율성:** 불필요한 연결 생성을 방지하여 시스템 자원을 효율적으로 사용할 수 있습니다.
- **안정성:** 연결이 끊어졌을 때 자동으로 재연결하거나, 최대 연결 수를 제한하여 시스템 과부하를 방지할 수 있습니다.

**작동 방식**:
1. **초기화:** 애플리케이션 시작 시 미리 설정된 크기만큼 연결을 생성하여 풀에 저장합니다.
2. **요청 처리:**
    - 클라이언트 요청이 들어오면 풀에서 사용 가능한 연결을 하나 가져옵니다.
    - 가져온 연결을 사용하여 데이터베이스 작업을 수행합니다.
    - 작업이 완료되면 연결을 풀로 반환합니다.
3. **연결 관리:**
    - 연결이 손상되거나 오랫동안 사용되지 않은 연결은 풀에서 제거합니다.
    - 풀에 연결이 부족하면 새로운 연결을 생성하여 풀에 추가합니다.

```
const mysql = require('mysql2/promise');

const pool = mysql.createPool({
  host: 'your_host',
  user: 'your_user',
  password: 'your_password',
  database: 'your_database',
  connectionLimit: 10 // 최대 연결 수 설정
});

// 쿼리 실행
pool.query('SELECT * FROM users')
  .then(([rows, fields]) => {
    console.log(rows);
  })
  .catch(err => {
    console.error(err);
  });
```

## http-server
`http-server`는 Node.js 환경에서 동작하는 간단한 HTTP 웹 서버입니다. 이 도구를 사용하면 로컬 디렉토리를 기반으로 간단한 정적 파일(HTML, CSS, JavaScript, 이미지 등)을 제공할 수 있습니다.

이 도구는 프로젝트의 개발 및 테스트 단계에서 로컬에서만 사용되며, 실제로 배포할 때는 더 강력하고 안전한 웹 서버 솔루션을 사용하는 것이 일반적입니다.하지만 간단한 정적 파일을 빠르게 서빙하고 테스트하는 데에는 유용하며, 주로 로컬 디렉토리에서 CORS 정책을 준수하기 위해 사용됩니다.

**과정**
4. `http-server`을 설치합니다.
> npm install http-server -g

5. `http-server`를 실행합니다.
> npx http-server

6. 서버에 접속합니다.
> http://127.0.0.1:8080

가끔씩 외부 소스 파일(예: script.js)이 업데이트되지 않는 경우가 발생할 수 있습니다. 이는 캐시 파일이 로드되어 변경 사항이 반영되지 않은 것입니다. 이 문제는 캐시를 사용하지 않도록 설정하여 해결할 수 있습니다.
> npx http-server -c-1

`-c`는 캐시 유지 시간을 설정하는 옵션입니다. `-c-1`을 사용하면 캐시를 사용하지 않습니다.

## Nodemon
**Nodemon**은 Node.js 개발자가 애플리케이션을 개발할 때 매우 유용하게 활용하는 도구입니다. Node.js 애플리케이션을 실행하고, **코드를 변경할 때마다 자동으로 애플리케이션을 다시 시작**해주는 역할을 합니다.

- **자동 재시작:** 코드 변경 시 자동으로 애플리케이션을 재시작합니다.
- **파일 감시:** 특정 디렉토리 또는 파일의 변경 사항을 감지합니다.
- **커스텀 스크립트 실행:** 애플리케이션 시작 전후에 커스텀 스크립트를 실행할 수 있습니다.
- **다양한 옵션 지원:** 포트 변경, 지연 시간 설정 등 다양한 옵션을 제공합니다.

**설치:**
```
npm install -g nodemon
```

**실행:**
```
npm run dev
```

## TypeScript
Node.js에서도 TypeScript를 사용할 수 있습니다.

### tsconfig.json
**tsconfig.json** 파일은 TypeScript 프로젝트의 컴파일 옵션을 정의하는 핵심 설정 파일입니다. 이 파일을 통해 프로젝트의 컴파일 방식, 출력 형식, 타입 검사 수준 등을 세밀하게 조절할 수 있습니다.

```
{
  "compilerOptions": {
    "target": "es6",
    "module": "commonjs",
    "outDir": "./dist",
    "rootDir": "./src",
    "strict": true,
    "esModuleInterop": true,
    "skipLibCheck": true,
    "forceConsistentCasingInFileNames": true
  }
}
```

- **target:** 생성될 JavaScript 코드의 ES 버전을 지정합니다. (예: es5, es6, esnext)
- **module:** 모듈 시스템을 지정합니다. (예: commonjs, es2015)
- **outDir:** 컴파일된 JavaScript 파일이 저장될 디렉토리를 지정합니다.
- **rootDir:** 소스 코드의 루트 디렉토리를 지정합니다.
- **strict:** 엄격한 타입 검사를 활성화합니다.
- **esModuleInterop:** CommonJS와 ES Modules 간의 상호 운용성을 위한 옵션입니다.
- **skipLibCheck:** 타입 정의 파일 검사를 생략합니다.
- **forceConsistentCasingInFileNames:** 파일 이름의 대소문자를 일관되게 유지합니다.
- **allowJs:** JavaScript 파일을 포함하여 컴파일할 수 있도록 허용합니다.
- **declaration:** 타입 정의 파일(.d.ts)을 생성합니다.
- **sourceMap:** 소스맵 파일을 생성하여 디버깅을 용이하게 합니다.
- **baseUrl:** 모듈 해결 시 기본 경로를 설정합니다.
- **paths:** 모듈 별칭을 설정합니다.
