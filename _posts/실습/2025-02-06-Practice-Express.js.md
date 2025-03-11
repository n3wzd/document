---
categories:
- Practice
date: '2025-02-06'
title: '[Practice] Express.js'
---

{% raw %}
### Argument of type ... is not assignable to parameter of type 'PathParams'
`app.use`는 반드시 경로를 포함해야 합니다.

공통 미들웨어일 경우, 경로를 "/"로 설정하면 모든 요청에 대해 공통적으로 실행되는 미들웨어로 동작합니다.

### req.body is undefined
`req.body`가 `undefined`인 경우, 일반적으로 `body-parser` 또는 `express.json()` 미들웨어가 제대로 설정되지 않아서 발생합니다. `POST` 요청에서 본문을 제대로 파싱하려면, 미들웨어가 요청 본문을 처리하도록 설정해야 합니다.

`req.body`를 제대로 파싱하려면 Express 앱에서 `express.json()` 미들웨어를 사용해야 합니다. 이는 요청 본문에 포함된 JSON 데이터를 파싱할 수 있게 해줍니다.
{% endraw %}