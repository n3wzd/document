---
categories:
- NodeJs
date: '2025-02-07'
title: '[NodeJs] jsonwebtoken'
---

{% raw %}
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

jwt.verify(token, secretKey, (err, decoded) => {<br>
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
{% endraw %}