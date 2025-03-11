---
categories:
- ReactNative
date: '2025-01-24'
title: '[ReactNative] axios'
---

{% raw %}
`axios`는 외부 라이브러리로, HTTP 요청을 보다 쉽게 관리할 수 있도록 도와줍니다. `fetch`보다 많은 기능을 제공하며, 개발자 경험을 개선합니다.

- Promise 기반으로 작동.
- 요청 및 응답에 대한 인터셉터(interceptor) 기능 제공.
- HTTP 상태 코드를 기반으로 자동 에러 처리가 가능.
- JSON 데이터를 자동으로 변환.
- 요청 취소, 타임아웃 설정, 기본 URL 설정 등 추가 기능 제공.

설치:
```
npm install axios
```

**GET 요청**
```
import axios from 'axios';

axios
  .get('https://jsonplaceholder.typicode.com/posts/1')
  .then((response) => {<br>
    console.log(response.data); // JSON 데이터 자동 파싱
  })
  .catch((error) => {<br>
    console.error('Error:', error);
  });
```

**POST 요청**
```
import axios from 'axios';

axios
  .post('https://jsonplaceholder.typicode.com/posts', {
    title: 'foo',
    body: 'bar',
    userId: 1,
  })
  .then((response) => {<br>
    console.log(response.data);
  })
  .catch((error) => {<br>
    console.error('Error:', error);
  });
```

|**특징**|**fetch**|**axios**|
|---|---|---|
|**내장 여부**|브라우저와 Node.js에 내장|별도 설치 필요 (`npm install axios`)|
|**Promise 기반**|지원|지원|
|**JSON 자동 파싱**|직접 `response.json()` 호출 필요|자동 파싱|
|**에러 처리**|네트워크 오류만 `catch`로 처리 가능|HTTP 상태 코드도 자동으로 처리 가능|
|**인터셉터**|지원하지 않음|지원|
|**타임아웃 설정**|직접 구현 필요|기본적으로 제공|
|**요청 취소**|직접 구현 필요|기본적으로 제공|
{% endraw %}