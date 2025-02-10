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

### Transaction
`mysql2`에서 트랜잭션을 사용하려면 `beginTransaction()`, `commit()`, `rollback()`을 사용하여 트랜잭션을 제어할 수 있습니다.
- `beginTransaction()`: 트랜잭션을 시작합니다.
- `commit()`: 모든 쿼리가 성공적으로 실행되면 트랜잭션을 커밋합니다.
- `rollback()`: 오류가 발생하면 트랜잭션을 롤백하여 모든 변경 사항을 취소합니다.

```
const mysql = require('mysql2');

// 데이터베이스 연결 설정
const connection = mysql.createConnection({
  host: 'localhost',
  user: 'root',
  password: 'password',
  database: 'test'
});

// 트랜잭션 예시
async function performTransaction() {
  try {
    // 트랜잭션 시작
    await connection.beginTransaction();

    // 첫 번째 쿼리 실행
    await connection.query('UPDATE accounts SET balance = balance - 100 WHERE account_id = ?', [1]);

    // 두 번째 쿼리 실행
    await connection.query('UPDATE accounts SET balance = balance + 100 WHERE account_id = ?', [2]);

    // 커밋
    await connection.commit();
    console.log('Transaction completed successfully');
  } catch (error) {
    // 오류 발생 시 롤백
    await connection.rollback();
    console.error('Transaction failed, rolled back:', error);
  } finally {
    // 연결 종료
    connection.end();
  }
}

performTransaction();
```

## http-server
`http-server`는 Node.js 환경에서 동작하는 간단한 HTTP 웹 서버입니다. 이 도구를 사용하면 로컬 디렉토리를 기반으로 간단한 정적 파일(HTML, CSS, JavaScript, 이미지 등)을 제공할 수 있습니다.

이 도구는 프로젝트의 개발 및 테스트 단계에서 로컬에서만 사용되며, 실제로 배포할 때는 더 강력하고 안전한 웹 서버 솔루션을 사용하는 것이 일반적입니다.하지만 간단한 정적 파일을 빠르게 서빙하고 테스트하는 데에는 유용하며, 주로 로컬 디렉토리에서 CORS 정책을 준수하기 위해 사용됩니다.

**과정**
2. `http-server`을 설치합니다.
> npm install http-server -g

3. `http-server`를 실행합니다.
> npx http-server

4. 서버에 접속합니다.
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
### TypeScript
Node.js에서도 TypeScript를 사용할 수 있습니다.

#### tsconfig.json
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

### ts-node
`ts-node`는 TypeScript 파일을 직접 실행할 수 있게 해주는 Node.js용 실행 환경입니다. TypeScript를 JavaScript로 컴파일하여 실행하는 대신, `ts-node`를 사용하면 TypeScript 코드를 바로 실행할 수 있습니다.

1. **TypeScript 코드 실행**: `ts-node`를 사용하면 TypeScript 코드를 JavaScript로 변환하지 않고, 바로 실행할 수 있습니다. 개발 중에 빠르게 테스트하고 실행하는 데 유용합니다.
2. **자동 컴파일**: `ts-node`는 TypeScript 파일을 실행할 때 내부적으로 TypeScript 컴파일러를 사용하여 자동으로 컴파일합니다. 즉, 별도로 `tsc` 명령어로 컴파일할 필요 없이, TypeScript 코드를 바로 실행할 수 있습니다.
3. **디버깅 지원**: TypeScript의 디버깅 정보를 제공하며, Node.js와 함께 디버깅 기능을 사용할 수 있습니다.
    
사용하려면 `typescript` 패키지가 먼저 설치되어 있어야 합니다.

설치:
```
npm install ts-node --save-dev
```

#### 실행
설치 후, `ts-node`를 사용하여 `.ts` 파일을 실행할 수 있습니다.
```
npx ts-node <파일명>.ts
```

#### 스크립트
`package.json`의 `scripts` 항목에 `ts-node`를 추가하여 더 쉽게 실행할 수 있습니다.

```
{
	"scripts": {
		"start": "ts-node index.ts"
	}
}
```

### tsx
> https://www.npmjs.com/package/tsx

`tsx`는 TypeScript 파일을 Node.js에서 직접 실행할 수 있도록 해주는 도구입니다. 이를 통해 TypeScript 코드를 컴파일 없이 바로 실행할 수 있으며, CommonJS와 ESM 모듈을 모두 지원합니다. 이 패키지를 사용하면 TypeScript를 실시간으로 실행할 수 있어 편리합니다.

설치:
```
npm install tsx
```

실행:
```
npx tsx <파일명>.ts
```

#### `watch` 모드
`watch` 모드는 종속성이 변경될 때마다 스크립트를 자동으로 다시 실행합니다. (nodemon과 같은 동작)

```
npx tsx watch <파일명>.ts
```

## jsonwebtoken
`jsonwebtoken`은 JWT (JSON Web Token)를 생성하고, 검증하고, 디코딩하는 데 사용되는 Node.js 라이브러리입니다. JWT는 주로 인증 시스템에서 사용자 정보를 안전하게 전송하기 위해 사용됩니다.

- **JWT 생성 (Sign)**: 사용자 인증 후 JWT를 생성하여 클라이언트에 전송합니다.
- **JWT 검증 (Verify)**: 클라이언트에서 보내온 JWT를 검증하여 유효한 토큰인지 확인합니다.
- **JWT 디코딩 (Decode)**: JWT에서 정보를 추출할 수 있습니다 (유효성 검사 없이).

설치:
```
npm install jsonwebtoken
```

### JWT 생성
- `sign()` 함수는 JWT를 생성합니다.
	- 첫 번째 매개변수: JWT에 포함될 정보 (payload)
	- 두 번째 매개변수: 비밀 키
- `expiresIn`: 토큰 만료 시간

```
const jwt = require('jsonwebtoken');

// 비밀 키
const secretKey = 'your-secret-key';

// 사용자 정보
const user = { id: 1, name: 'John Doe' };

// JWT 생성
const token = jwt.sign(user, secretKey, { expiresIn: '1h' });

console.log('Generated Token:', token);
```

### JWT 검증
- `verify()` 함수는 JWT의 유효성을 검사합니다. 유효한 경우, `decoded` 객체로 디코딩된 정보를 반환합니다.

```
const token = '받은 JWT 토큰';

jwt.verify(token, secretKey, (err, decoded) => {
  if (err) {
    console.error('Token is not valid');
  } else {
    console.log('Decoded JWT:', decoded);
  }
});
```

### JWT 디코딩
`decode()`은 유효성 검사를 하지 않습니다. 단순히 토큰의 내용을 확인할 때 사용합니다.

```
const decoded = jwt.decode(token);
console.log('Decoded Payload:', decoded);
```

## crypto
Node.js의 **crypto 모듈**은 암호화 관련 다양한 기능을 제공하는 내장 모듈입니다. 데이터를 안전하게 보호하고, 데이터 무결성을 검증하는 데 사용됩니다.

- **해시 함수:** 데이터를 고정된 길이의 해시 값으로 변환하는 기능을 제공합니다. 비밀번호 저장, 데이터 무결성 검증 등에 사용됩니다. (예: SHA-256, MD5)
- **암호화/복호화:** 데이터를 암호화하여 안전하게 저장하고, 필요할 때 복호화하여 원본 데이터를 복원합니다. 대칭키 암호화와 비대칭키 암호화를 모두 지원합니다.
- **HMAC:** 메시지 인증 코드를 생성하여 데이터의 무결성을 검증하고, 메시지가 변조되었는지 확인할 수 있습니다.
- **디지털 서명:** 디지털 서명을 생성하고 검증하여 데이터의 출처를 확인하고 위변조를 방지할 수 있습니다.
- **난수 생성:** 암호학적으로 안전한 난수를 생성합니다.

### 비밀번호 해싱
사용자의 비밀번호를 안전하게 저장하기 위해 bcrypt와 유사한 방식으로 해싱하는 예시입니다.
- **salt:** 암호화에 추가적인 랜덤 값을 사용하여 동일한 비밀번호라도 다른 해시 값을 생성합니다.
- **pbkdf2Sync:** 반복적인 해시 연산을 통해 암호화 강도를 높입니다.

```
const crypto = require('crypto');

function hashPassword(password) {
  const salt = crypto.randomBytes(16).toString('hex');
  const hash = crypto.pbkdf2Sync(password, salt, 10000, 64, 'sha512').toString('hex');

  return {
    salt,
    hash
  };
}

const hashedPassword = hashPassword('mypassword');
console.log(hashedPassword);
```

### RSA
#### RSA 키 쌍 생성
- `modulusLength: 2048`: RSA 키 길이를 설정합니다. 일반적으로 2048비트 이상을 권장합니다.
- `spki`(Subject Public Key Info): 공개키의 표준 인코딩 형식.
- `pkcs8`: 비공개키 표준 인코딩 형식.

```
const crypto = require('crypto');

const { publicKey, privateKey } = crypto.generateKeyPairSync('rsa', {
  modulusLength: 2048, // 키 길이 (2048비트 추천)
  publicKeyEncoding: { type: 'spki', format: 'pem' },
  privateKeyEncoding: { type: 'pkcs8', format: 'pem' }
});

console.log("Public Key:\n", publicKey);
console.log("Private Key:\n", privateKey);
```

#### RSA 암호화
공개키를 사용하여 데이터를 암호화합니다.

```
function encryptWithPublicKey(publicKey, data) {
  return crypto.publicEncrypt(
    {
      key: publicKey,
      padding: crypto.constants.RSA_PKCS1_OAEP_PADDING, // 패딩 방식
      oaepHash: 'sha256', // OAEP 해시 알고리즘
    },
    Buffer.from(data) // 문자열을 Buffer로 변환 후 암호화
  );
}

const message = "Hello, this is a secret!";
const encryptedData = encryptWithPublicKey(publicKey, message);
console.log("Encrypted Data:", encryptedData.toString("base64")); // Base64 인코딩
```

#### RSA 복호화
비공개키를 사용하여 데이터를 복호화합니다.

```
function decryptWithPrivateKey(privateKey, encryptedData) {
  return crypto.privateDecrypt(
    {
      key: privateKey,
      padding: crypto.constants.RSA_PKCS1_OAEP_PADDING, // 암호화와 동일한 패딩
      oaepHash: 'sha256',
    },
    encryptedData
  );
}

const decryptedData = decryptWithPrivateKey(privateKey, encryptedData);
console.log("Decrypted Data:", decryptedData.toString()); // 원본 메시지 복원
```

## node-forge
**node-forge**는 **Node.js**에서 사용할 수 있는 **암호화 및 보안 라이브러리**입니다. 이 라이브러리는 다양한 암호화 알고리즘과 보안 프로토콜을 구현하여, Node.js 환경에서 암호화 관련 작업을 손쉽게 처리할 수 있게 해줍니다.

4. **RSA, AES 등 암호화 알고리즘**:
    - RSA, AES, DES, 3DES, HMAC 등 여러 대칭 및 비대칭 암호화 알고리즘을 지원합니다.
5. **PKI (Public Key Infrastructure)**:
    - RSA, DSA, ECDSA 키 생성 및 서명, 인증서 검증 등의 기능을 제공합니다.
6. **X.509 인증서 지원**:
    - 인증서 생성, 구문 분석 및 서명 확인을 지원하여, SSL/TLS 인증서와 같은 보안 인증서를 다룰 수 있습니다.
7. **Base64 인코딩/디코딩**:
    - Base64 인코딩 및 디코딩을 지원하여 바이너리 데이터를 쉽게 텍스트 형식으로 변환할 수 있습니다.
8. **해시 함수**:
    - SHA-1, SHA-256, SHA-512 등 다양한 해시 함수를 제공합니다.
9. **암호화/복호화**:
    - 메시지 암호화 및 복호화, 데이터 서명 및 검증, 키 교환 등을 지원합니다.

설치:
```
npm install node-forge
```

### RSA 키 생성
```
const forge = require('node-forge');

// RSA 키 쌍 생성
const keypair = forge.rsa.generateKeyPair(2048);

// 공개키와 개인키 출력
console.log('Public Key:', forge.pki.publicKeyToPem(keypair.publicKey));
console.log('Private Key:', forge.pki.privateKeyToPem(keypair.privateKey));
```

### Base64 인코딩/디코딩
```
const forge = require('node-forge');

// Base64 인코딩
const encoded = forge.util.encode64('Hello, world!');
console.log('Encoded:', encoded);

// Base64 디코딩
const decoded = forge.util.decode64(encoded);
console.log('Decoded:', decoded);
```

## 환경 변수
Node.js에서 `process.env`를 통해 OS의 환경 변수를 가져올 수 있습니다.

```
console.log(process.env.VARIABLE)  // 환경 변수 VARIABLE 출력
```

## Log
로그 시스템을 선택할 때는 여러 요인을 고려해야 합니다. 주로 **성능**, **사용 편리성**, **확장성**, **기능** 등을 기준으로 선택할 수 있습니다. 각 도구가 가진 장단점을 비교하여 가장 적합한 로그 패키지를 선택하는 것이 중요합니다.

1. **Winston**
    - 매우 널리 사용되는 로깅 라이브러리로 문서와 커뮤니티 지원이 강력합니다.
    - 다양한 트랜스포트를 지원(콘솔, 파일, 원격 서버 등).
    - 로그 포맷, 레벨, 출력 경로 등을 유연하게 설정할 수 있습니다.
    - `winston-daily-rotate-file`과 같은 추가 패키지를 통해 로그 파일 로테이션 및 관리도 용이합니다.
2. **Pino**
    - 성능이 뛰어난 경량화된 JSON 기반 로그 라이브러리로, 많은 로그를 다뤄야 하는 고성능 시스템에 적합합니다.
    - 기본적으로 빠르고 비동기적으로 작동하여 성능에 민감한 환경에 유리합니다.
    - JSON 포맷 로그를 기본으로 사용하여 구조화된 데이터를 쉽게 처리할 수 있습니다.
3. **Log4js**
    - 유연하고, 다양한 설정을 제공하여 로깅을 세밀하게 조정할 수 있습니다.
    - 로그 수준과 필터링을 세밀하게 설정할 수 있어, 고급 기능이 필요한 경우 유용합니다.

선택:
- **고성능을 중시하는 경우**: `Pino`는 경량화되어 성능이 뛰어나며, 빠르게 동작하는 시스템에서 유리합니다. 만약 빠른 속도와 높은 처리량이 요구되는 경우에 적합합니다.
- **유연성과 기능을 중시하는 경우**: `Winston`은 다양한 트랜스포트를 지원하고 설정이 유연하여 다양한 요구 사항을 처리할 수 있습니다. 큰 프로젝트나 로그의 출력을 세밀하게 설정하고 싶은 경우에 유용합니다.

### Pino
**Pino**는 Node.js용 고성능 JSON 로깅 라이브러리입니다. `Pino`는 로그를 빠르고 효율적으로 기록하고, JSON 형식으로 출력을 기본으로 제공하여 로그 데이터를 쉽게 처리하고 분석할 수 있게 해줍니다.

1. **고성능**:
    - `Pino`는 **성능**을 최우선으로 고려한 라이브러리입니다. 이를 위해 비동기적으로 로그를 처리하며, 로그를 기록하는 데 드는 비용을 최소화하고 있습니다.
    - 높은 처리량의 시스템에서도 우수한 성능을 발휘합니다.
2. **JSON 기반 로그**:
    - Pino는 로그를 **JSON 형식**으로 출력합니다. 이 방식은 로그를 구조화하여 쉽게 파싱하고 분석할 수 있게 해줍니다.
    - JSON 형식의 로그는 **Kibana**와 같은 로그 분석 도구와 잘 호환됩니다. 즉, 실시간 모니터링 및 대시보드 분석에 매우 유리합니다.
3. **간단한 사용법**:
    - 사용법이 간단하고 직관적입니다. `Pino`는 로그 수준 (예: `info`, `warn`, `error` 등)을 지원하며, 로그 메시지에 추가적인 메타데이터를 포함할 수 있습니다.

#### 기본 설정
기본적으로 `Pino`는 **콘솔**에 로그를 출력합니다.
```javascript
const pino = require('pino');

// 로거 인스턴스 생성
const logger = pino({
  level: 'info',  // 기본 레벨을 'info'로 설정
});

logger.info('이것은 정보 로그입니다'); // 출력됨
logger.error('이것은 오류 로그입니다'); // 출력됨
logger.debug('이것은 디버그 로그입니다'); // 출력되지 않음 (레벨 'info' 이상만 출력)
```

#### 파일 저장
파일에 로그를 저장하려면 `pino`의 스트림 기능을 이용하여 파일에 로그를 출력할 수 있습니다. 예를 들어, `pino.destination()`을 사용하여 로그를 파일에 저장할 수 있습니다.

```javascript
const pino = require('pino');
const fs = require('fs');

// 로그를 'logfile.log'에 저장
const logger = pino({
  level: 'info',  // 로그 레벨 설정
}, pino.destination('./logfile.log'));

logger.info('이것은 정보 로그입니다');  // 'logfile.log' 파일에 저장됩니다.
```

`pino`의 여러 스트림을 설정하여 콘솔과 파일에 동시에 출력할 수 있습니다.
```javascript
const pino = require('pino');
const fs = require('fs');

// 파일 스트림과 콘솔 스트림을 설정
const streams = [
  { stream: process.stdout },   // 콘솔에 출력
  { stream: fs.createWriteStream('./logfile.log', { flags: 'a' }) } // 파일에 출력
];

const logger = pino({
  level: 'info',
}, pino.multistream(streams));

logger.info('이것은 정보 로그입니다');  // 콘솔과 'logfile.log' 파일에 동시에 출력됩니다.
```

## ws
Node.js에서 WebSocket을 사용하려면 `ws` 라이브러리를 사용하는 것이 일반적입니다.

설치:
```
npm install ws
```

### WebSocket 서버
```typescript
import WebSocket, { WebSocketServer } from 'ws';

// WebSocket 서버 생성
const wss = new WebSocketServer({ port: 8080 });

wss.on('connection', (ws) => {
    console.log('클라이언트 연결됨');

    // 메시지 수신 이벤트
    ws.on('message', (message) => {
        console.log(`받은 메시지: ${message}`);

        // 클라이언트에게 메시지 보내기
        ws.send(`서버 응답: ${message}`);
    });

    // 연결 종료 이벤트
    ws.on('close', () => {
        console.log('클라이언트 연결 종료');
    });

    // 에러 처리
    ws.on('error', (error) => {
        console.error('WebSocket 오류:', error);
    });
});

console.log('WebSocket 서버가 8080 포트에서 실행 중...');
```

### WebSocket 클라이언트
```typescript
import WebSocket from 'ws';

// WebSocket 서버에 연결
const ws = new WebSocket('ws://localhost:8080');

// 서버 연결 이벤트
ws.on('open', () => {
    console.log('서버에 연결됨');

    // 서버에 메시지 전송
    ws.send('안녕하세요, 서버!');
});

// 메시지 수신 이벤트
ws.on('message', (message) => {
    console.log(`서버로부터 받은 메시지: ${message}`);
});

// 연결 종료 이벤트
ws.on('close', () => {
    console.log('서버와의 연결 종료');
});

// 에러 처리
ws.on('error', (error) => {
    console.error('WebSocket 오류:', error);
});
```
