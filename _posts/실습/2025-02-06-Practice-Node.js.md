---
categories:
- Practice
date: '2025-02-06'
title: '[Practice] Node.js'
---

{% raw %}
### Illegal base64 character
Base64로 인코딩된 문자열에 유효하지 않은 문자가 포함되어 있을 때 발생합니다. 이 문제는 PEM 형식의 공개키 또는 개인키를 처리하는 중에 흔히 발생할 수 있습니다.

PEM 형식은 ase64로 인코딩된 데이터에 `-----BEGIN PUBLIC KEY-----`, `-----END PUBLIC KEY-----`, 개행 문자가 포함됩니다. 이 구분자들은 Base64 인코딩된 데이터를 디코딩할 때 영향을 줄 수 있습니다.

### error:0200006C:rsa routines::data greater than mod len
RSA 암호화에서 암호화할 데이터의 크기가 키의 길이를 초과 때 발생하는 오류입니다. 이 오류는 암호화하려는 데이터의 크기가 RSA 키의 최대 처리 용량을 초과할 때 발생합니다. 예를 들어, 2048비트 RSA 키를 사용하면 암호화할 수 있는 데이터의 최대 크기는 약 245바이트입니다.

암호화/복호화의 패딩 방식과 해시 함수 설정이 서로 일치하지 않을 때도 문제가 발생할 수 있습니다.

### 복호화 오류
Node.js와 Java 간의 암호화/복호화 방식 및 데이터 타입이 완전히 동일야 합니다. 특히 패딩 방식, 해시 함수, 그리고 데이터 타입 (byte[], base64, string 등) 을 맞추지 않으면 정상적으로 동작하지 않습니다.

예를 들어 Java에서 `RSA/ECB/OAEPWithSHA-256AndMGF1Padding` 방식으로 암호화를 했다면, Node.js에서는 `'RSA-OAEP', { md: forge.md.sha256.create(), mgf1: { md: forge.md.sha1.create() } }`으로 복호화를 해야 합니다. (`node-forge`가 필요합니다.)

```java
Cipher cipher = Cipher.getInstance("RSA/ECB/OAEPWithSHA-256AndMGF1Padding");
cipher.init(Cipher.ENCRYPT_MODE, publicKey);
byte[] encryptedBytes = cipher.doFinal(data.getBytes());
return Base64.getEncoder().encodeToString(encryptedBytes);
```

```javascript
import forge from 'node-forge';

const { publicKey, privateKey } = forge.rsa.generateKeyPair(2048);

const decrypt = (encryptedData) => {<br>
    const encryptedBytes = forge.util.decode64(encryptedData);
    const decryptedData = privateKey.decrypt(encryptedBytes, 'RSA-OAEP', {
            md: forge.md.sha256.create(),
            mgf1: {
                md: forge.md.sha1.create()
            }
        });
    return decryptedData;
}
```

출처: 
- https://stackoverflow.com/questions/53834903/javas-rsa-ecb-oaepwithsha-256andmgf1padding-equivalent-in-node-js

### 토큰 분석 불일치
JWT 검증 결과가 동일하려면 두 서버의 비밀키뿐만 아니라 분석(파싱 및 검증) 방식도 동일해야 합니다.   즉, 같은 토큰을 같은 방식으로 검증해야동일한 결과를 얻을 수 있습니다.

1. **알고리즘이 다르면 검증 실패**
    - 한 서버는 `HMAC256`을 사용하고, 다른 서버는 `RSA`를 사용하면 검증이 실패함.
    - 급한 서버의 알고리즘과 검증하는 서버의 알고리즘이 동일해야 함.
2. **시간 기반 검증 차이**
    - 일부 라이브러리는 `exp(만료 시간)`을 자동 검증하지만, 일부는 명시적으로 검증해야 함.
    - 서버마다 `iat(발급 시간)` 또는 `nbf(활성 시간)`을 다르게 해석할 수도 있음.
3. **토큰 클레임(Claim) 해석 차이**
    - `sub(사용자 ID)`, `roles(권한)` 등의 필드를 어떻게 해석하느냐에 따라 인증 방식이 달라질 수 있음.
    - 예를 들어, 한 서버는 `roles` 필드 없이 검증하지만, 다른 서버는 필수 필드로 검증하면 오류 발생.

### 비밀키 타입
비밀키는 대부분 바이트 배열로 사용니다. 문자열 형태의 비밀키를 다루는 경우도 있지만, 실제 서명이나 검증에서는 바이트 배열로 변환해서 사용됩니다.

JWT 토큰을 생성하는 데 사용되는 비밀키도 바이트 배열입니다.

### 비밀키 호환
#### Java에서 비밀키 처리
Java에서는 `JwtBuilder`의 `signWith` 메서드를 사용하여 ase64 인코딩된 비밀키를 제공하는 방식입니다. 이때 비밀키는 문자열로 제공되며, 자동으로 바이트 배열로 변환됩니다.

```java
String base64EncodedSecretKey = "eW91ci1zZWNyZXQta2V5";  // Base64로 인코딩된 비밀키

String token = Jwts.builder()
    .setSubject("user123")
    .signWith(SignatureAlgorithm.HS256, base64EncodedSecretKey)  // Base64로 인코딩된 비밀키를 문자열로 제공
    .compact();
```

- `base64EncodedSecretKey`는 ase64로 인코딩된 비밀키입니다. Java의 `signWith` 메서드는 이를 자동으로 디코딩하여 바이트 배열로 변환하고, 서명에 사용합니다.

#### Node.js에서 비밀키 처리
Node.js에서는 JWT를 검증할 때 비밀키를 `jwt.verify` 메서드에 전달합니다. 비밀키는 바이트 배열또는 문자열로 제공할 수 있으며, ase64로 인코딩된 문자열도 디코딩하여 바이트 배열로 변환해야 합니다.

```javascript
const jwt = require('jsonwebtoken');
const base64EncodedSecretKey = 'eW91ci1zZWNyZXQta2V5';  // Base64로 인코딩된 비밀키

// Base64 디코딩하여 바이트 배열로 변환
const secretKey = Buffer.from(base64EncodedSecretKey, 'base64');

jwt.verify(token, secretKey, { algorithms: ['HS256'] }, (err, decoded) => {<br>
    if (err) {
        console.log('Token is not valid:', err);
    } else {
        console.log('Decoded token:', decoded);
    }
});
```

Node.js에서는 비밀키가 바이트 배열로 전달되어야 하므로, Base64 인코딩된 문자열을 바이트 배열로 디코딩하는 과정이 필요합니다.

### redis.createClient - TypeError: Invalid protocol
url 앞에 `redis://`가 있어야 합니다.

출처:
- https://github.com/redis/node-redis/issues/2201
{% endraw %}