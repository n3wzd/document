---
categories:
- ReactNative
date: '2025-02-02'
title: '[ReactNative] jwt-decode'
---

{% raw %}
`jwt-decode`는 JWT(JSON Web Token)를 **디코딩**하기 위한 경량 JavaScript 라이브러리입니다. 이 라이브러리는 다음과 같은 특징을 가집니다:

- **디코딩 전용**:  
    `jwt-decode`는 JWT 토큰을 디코딩하여 페이로드(payload)와 헤더(header)의 내용을 추출합니다.  
    **서명 검증(signature verification)은 수행하지 않습니다.** 즉, 토큰이 실제로 유효한지, 위변조되지 않았는지는 확인하지 않고 단순히 토큰 내에 포함된 데이터를 읽어옵니다.
- **클라이언트 친화적**:  
    React, React Native(Expo 포함)와 같은 클라이언트 환경에서 사용하기 적합합니다. Node.js 전용 라이브러리인 `jsonwebtoken`과 달리, 브라우저나 모바일 환경에서 문제 없이 사용할 수 있습니다.
- **간단한 사용법**:  
    토큰을 인자로 넣으면 디코딩된 객체를 반환하므로, 예를 들어 사용자 정보나 기타 클레임(claim)을 쉽게 확인할 수 있습니다.

설치:
```
npm install jwt-decode
```

#### 토큰 분석
```
import jwtDecode from 'jwt-decode';

const token = 'eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJzdWIiOiIxMjM0NTY3ODkwIiwibmFtZSI6IkpvaG4gRG9lIiwiaWF0IjoxNTE2MjM5MDIyfQ.SflKxwRJSMeKKF2QT4fwpMeJf36POk6yJV_adQssw5c';
const decoded = jwtDecode(token);

console.log(decoded);
// 예시 출력: { sub: "1234567890", name: "John Doe", iat: 1516239022 }
```
{% endraw %}