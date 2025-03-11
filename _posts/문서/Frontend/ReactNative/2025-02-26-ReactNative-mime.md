---
categories:
- ReactNative
date: '2025-02-26'
title: '[ReactNative] mime'
---

{% raw %}
`mime`은 Node.js에서 MIME 타입(MIME type)을 다루는 데 사용하는 npm 패키지입니다. 파일 확장자를 MIME 타입으로 변환하거나, MIME 타입을 파일 확장자로 변환하는 기능을 제공합니다.

설치:
```
npm install mime
```

예제:
```javascript
const mime = require('mime');

// 파일 확장자로 MIME 타입 얻기
console.log(mime.getType('example.txt')); // 'text/plain'
console.log(mime.getType('image.png')); // 'image/png'

// MIME 타입으로 파일 확장자 얻기
console.log(mime.getExtension('text/html')); // 'html'
console.log(mime.getExtension('application/json')); // 'json'
```
{% endraw %}