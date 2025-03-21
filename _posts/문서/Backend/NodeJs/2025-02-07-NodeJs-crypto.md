---
categories:
- NodeJs
date: '2025-02-07'
title: '[NodeJs] crypto'
---

{% raw %}
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
{% endraw %}