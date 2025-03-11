---
categories:
- NodeJs
date: '2024-01-17'
title: '[NodeJs] HTTP'
---

{% raw %}
Node.js의 `http` 모듈은 HTTP 웹 서버와 클라이언트를 생성하고 상호 작용하기 위한 메서드와 속성을 제공하는 내장 모듈입니다. 이 모듈은 웹 애플리케이션을 개발하고 웹 서버를 만드는 데 사용됩니다.

HTTP 서버를 만들려면 `http` 모듈을 사용하여 서버를 생성하고, 서버에 이벤트 핸들러를 등록합니다. 예를 들어, 간단한 "Hello, World!"를 반환하는 HTTP 서버를 만들어 보겠습니다.

### HTTP 서버 만들기
```
// http 모듈 가져오기
const http = require('http');

// 서버 생성
const server = http.createServer((req, res) => {<br>
  // HTTP 헤더 설정
  res.writeHead(200, {'Content-Type': 'text/plain'});

  // 응답 전송
  res.end('Hello, World!\n');
});

// 서버 포트 3000에서 실행
const PORT = 3000;
server.listen(PORT, () => {<br>
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
const req = http.request(options, (res) => {<br>
  // 응답 데이터를 받을 때의 처리
  let data = '';

  res.on('data', (chunk) => {<br>
    data += chunk;
  });

  res.on('end', () => {<br>
    console.log(data);
  });
});

// 요청 전송
req.end();
```

위의 코드에서 `http.request` 메서드로 HTTP 요청을 생성하고, 요청에 대한 응답을 처리하기 위해 이벤트 리스너를 등록합니다. 이 예제에서는 간단한 GET 요청을 `www.example.com`으로 보내고 응답을 콘솔에 출력합니다.
{% endraw %}