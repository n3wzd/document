---
categories:
- Design
date: '2025-01-20'
title: '[Design] Pattern'
---

{% raw %}
### Command Pattern
커맨드 패턴(Command Pattern)은 요청을 객체 형태로 캡슐화하여 추상화하는 패턴입니다. 한 요청에 대한 여러 실행자 중, 상황에 적합한 것을 선택합니다.

예시:
1. 외부 API와 직접 연결하는 클래스 (실행자)
    - 각 API에 특화된 클래스입니다.
        - `GooglePlacesClient`: Google Places API와 통신
        - `OpenStreetMapClient`: OSM API와 통신
    - 이 클래스들은 공통 인터페이스를 구현하여 일관성을 유지합니다.
2. 명령 처리 클래스 (요청자)
    - API를 선택하고 명령을 위임하는 클래스입니다. (예: `ApiCommandProcessor`)
    - 현재 사용 중인 API 타입을 기반으로 적절한 클라이언트를 선택합니다.
{% endraw %}