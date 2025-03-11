---
categories:
- Design
date: '2025-02-06'
title: '[Design] Node.js'
---

{% raw %}
### 파일 구조
```
src/
 ├── api/           # 서버 API 요청
 ├── external/      # 외부 API 요청
 ├── config/        # 설정 정보 저장
 ├── controllers/   # 클라이언트 요청 응답
 ├── services/      # 비즈니스 로직
 ├── repositories/  # DB 상호작용
 ├── types/         # 타입 정의
 ├── utils/         # 정적 유틸리티 함수
 ├── libs/          # 외부 라이브러리 래퍼
 ├── middlewares/   # Express 미들웨어
```

### `service/` vs `utils/`
둘 다 재사용 가능한 기능을 제공하지만, 역할과 사용 방식이 다릅니다.

|`services/`|`utils/`|
|---|---|---|
|**DB 연동**|있음|없음|
|**외부 API 호출**|가능|없음|
|**상태 관리**|데이터 상태 변경 가능|상태 없음 (순수 함수)|
|**비즈니스 로직**|있음 (컨트롤러에서 호출)|없음 (재사용 함수)|
|**예제**|사용자 관리, 결제 처리|암호화, 포맷 변환, 정규식 검사|

`services/`는 데이터와 연결된 비즈니스 로직, `utils/`는 가벼운 유틸리티 함수입니다.
{% endraw %}