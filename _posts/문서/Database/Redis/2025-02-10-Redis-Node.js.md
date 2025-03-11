---
categories:
- Redis
date: '2025-02-10'
title: '[Redis] Node.js'
---

{% raw %}
`redis`는 Node.js에서 Redis 데이터베이스와 상호작용할 수 있게 해주는 라이브러리입니다.

설치:
```
npm install redis
```

#### 사용법
```
const redis = require('redis');

// Redis 클라이언트 생성
const client = redis.createClient({
  host: 'localhost',      // Redis 서버 주소
  port: 6379,            // Redis 서버 포트
  password: 'your_password',  // 비밀번호 (설정된 경우)
  db: 0                  // 사용할 데이터베이스 인덱스 (기본은 0)
});

// Redis 연결이 되면 실행될 이벤트 리스너
client.error('connect', function() {
  console.error('Redis client error:', err);
});

// Redis 연결
client.connect().then(() => {<br>
	console.log('Connected to Redis');
  }).catch((err) => {<br>
	console.error('Failed to connect to Redis', err);
  });

// 데이터를 저장하는 예시
client.set('myKey', 'myValue', function(err, reply) {
  if (err) {
    console.error('Error setting value:', err);
  } else {
    console.log('Reply:', reply);  // "OK"
  }
});

// 데이터를 조회하는 예시
client.get('myKey', function(err, reply) {
  if (err) {
    console.error('Error getting value:', err);
  } else {
    console.log('Value from Redis:', reply);  // "myValue"
  }
});
```

`reply`는 **Redis 명령에 대한 응답**을 나타냅니다. 명령이 정상적으로 완료되면 Redis 서버는 `OK`라는 문자열을 반환합니다.

#### `client.on()`
`client.on()` 메서드는 **이벤트 리스너**를 등록하여, 특정 이벤트가 발생했을 때 해당 이벤트에 대해 정의된 콜백 함수를 실행하게 합니다.

`redis` 클라이언트는 여러 가지 이벤트를 처리할 수 있습니다. 대표적인 이벤트는 다음과 같습니다:

1. **'connect'**: Redis 서버에 연결되었을 때 발생합니다.
    - 예: `client.on('connect', () => { console.log('Connected to Redis'); });`<br>
2. **'error'**: Redis 클라이언트에서 오류가 발생했을 때 발생합니다.
    - 예: `client.on('error', (err) => { console.error('Redis client error:', err); });`<br>
3. **'ready'**: Redis 클라이언트가 서버와 연결되어 명령을 처리할 준비가 되었을 때 발생합니다.
    - 예: `client.on('ready', () => { console.log('Redis client is ready'); });`<br>
4. **'end'**: Redis 클라이언트가 연결을 종료했을 때 발생합니다.
    - 예: `client.on('end', () => { console.log('Redis client connection ended'); });`<br>
{% endraw %}