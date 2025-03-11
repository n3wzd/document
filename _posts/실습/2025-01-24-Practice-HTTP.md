---
categories:
- Practice
date: '2025-01-24'
title: '[Practice] HTTP'
---

{% raw %}
### Postman
Postman은 API를 테스트하고 디버깅하는 데 유용한 도구입니다. HTTP 요청을 보내고 응답을 확인할 수 있으며, 다양한 기능을 통해 API 개발과 테스트를 쉽게 할 수 있습니다. 

> https://www.postman.com<br>

1. Postman을 실행하고, 왼쪽 상단의 **New** 버튼을 클릭합니다.
2. "Request"를 선택하여 새로운 요청을 만듭니다.
3. 요청의 이름을 입력하고, 요청을 저장할 컬렉션을 선택하거나 새로 생성합니다.

**REST API 작성**
1. HTTP 방법을 설정합니다: GET, POST...
2. url을 작성합니다.
3. Headers의 Authorization 항목을 생성하고 토큰을 넣습니다. (Bearer (TOKEN))
4. (POST일 경우) Body > raw(JSON)에서 파라미터를 작성합니다.<br>

### Error parsing HTTP request header
요청이 잘못되면 403이 반환될 확률이 높습니다. 로그를 통해 정확한 원인을 찾아야 합니다.

- Headers의 Authorization에 토큰이 설정되었는지 확인합니다.
- 주소에서 https 대신 http를 사용합니다.
- body 파라미터가 잘 주어졌는지 확인합니다.
- 서버 코드 동작에 문제가 있는 경우
{% endraw %}