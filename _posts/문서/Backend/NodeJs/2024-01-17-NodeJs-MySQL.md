---
categories:
- NodeJs
date: '2024-01-17'
title: '[NodeJs] MySQL'
---

{% raw %}
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
connection.connect((err) => {<br>
  if (err) {
    console.error('Error connecting to MySQL:', err);
    return;
  }
  console.log('Connected to MySQL!');
});

// 연결 종료
connection.end((err) => {<br>
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
connection.query('SELECT * FROM tableName', (err, results, fields) => {<br>
  if (err) {
    console.error('Error executing SELECT query:', err);
    return;
  }

  console.log('Query results:', results);
});

// INSERT 쿼리 수행
const newRecord = { name: 'John', age: 30 };
connection.query('INSERT INTO tableName SET ?', newRecord, (err, results) => {<br>
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
  .then(([rows, fields]) => {<br>
    console.log(rows);
  })
  .catch(err => {<br>
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
{% endraw %}