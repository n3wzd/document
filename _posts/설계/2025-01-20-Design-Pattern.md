---
categories:
- Design
date: '2025-01-20'
title: '[Design] Pattern'
---

{% raw %}
### 리모컨 패턴
리모컨 패턴(Remote Control Pattern) 또는 전략 패턴(Strategy Pattern)은 특정 작업을 수행하기 위해 적절한 API와 상호작용하는 클래스를 선택하도록 설계하는 방식으로, 확장성과 유지보수성을 높이는 데 유용합니다. 즉, 외부 패키지와 직접적으로 상호작용하는 코드 외부 패키지를 직접 활용하는 코드를 분리하는 것이 좋습니다.

1. **외부 API와 직접 연결하는 클래스**
    - 각 API에 특화된 클래스.
        - `GooglePlacesClient`: Google Places API와 통신.
        - `OpenStreetMapClient`: OSM API와 통신.
    - 이 클래스들은 공통 인터페이스를 구현하여 일관성을 유지.
2. **명령 처리 클래스 (리모컨 역할)**
    - API를 선택하고 명령을 위임하는 클래스.
    - 예: `ApiCommandProcessor`
    - 현재 사용 중인 API 타입(예: Google, OSM 등)을 기반으로 적절한 클라이언트를 선택.
{% endraw %}