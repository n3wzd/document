---
categories:
- NodeJs
date: '2025-02-07'
title: '[NodeJs] node-forge'
---

{% raw %}
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
{% endraw %}