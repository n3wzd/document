---
categories:
- Design
date: '2025-01-14'
title: '[Design] Spring'
---

{% raw %}
### 파일 구조
```
src/
 ├── api/          # 서버 API 요청
 ├── annotation/   # 커스텀 어노테이션
 ├── constant/     # 상수 데이터
 ├── component/    # 동적 유틸리티 싱글톤
 ├── config/       # 설정 (Security, DB, CORS 등)
 ├── controller/   # 클라이언트 요청 응답
 ├── service/      # 비즈니스 로직
 ├── repository/   # DB 상호작용
 ├── dto/          # Data Transfer Object 정의
 ├── util/         # 정적 유틸리티 함수
 ├── model/        # 엔티티, 도메인 모델
 ├── lib/          # 외부 라이브러리 래퍼
 ├── exception/    # 예외 처리 클래스
 ├── external/     # 외부 API 요청
 ├── validator/    # 커스텀 유효성 검사
```

### 외부 패키지 확인
> https://mvnrepository.com/<br>

### Component vs Util
#### `@Component`를 사용하는 경우
1.  **의존성 주입(DI)**:
    - `@Component`로 선언된 클래스는 Spring의 의존성 주입을 통해 자동으로 관리됩니다. 따라서 객체를 생성하고 주입하는 과정에서 코드가 간결해집니다.
2. **싱글톤 관리**:
    - `@Component`로 선언된 클래스는 Spring의 기본 빈 관리에 따라 싱글톤으로 관리됩니다. 이를 통해 애플리케이션 전반에서 하나의 인스턴스를 공유할 수 있습니다.
3.  **테스트 용이성**:
    - `@Autowired`를 사용해 자동으로 주입받는 방식이므로, 테스트 시 다른 구현체로 쉽게 교체할 수 있습니다.

#### `Util` 클래스를 사용하는 경우
1. **불필요한 빈 등록**:
    - 모든 유틸 클래스에 `@Component`를 붙이면, 불필요하게 많은 빈들이 Spring 컨테이너에 등록될 수 있습니다. 실제로 이 유틸 클래스가 빈으로 관리될 필요가 없는 경우도 많기 때문에, 불필요한 빈 등록이 발생할 수 있습니다.
2 **성능 문제**:
    - `@Component`로 등록된 클래스는 Spring의 빈 관리 시스템에 의해 생성되고 관리됩니다. 만약 유틸리티 클래스가 자주 사용되거나, 성능에 민감한 경우, 빈 관리 비용 성능에 영향을 줄 수 있습니다. 이 경우에는 static 메서드를 사용하는 것이 더 효율적일 수 있습니다.

### SecurityContext에서 사용자의 정보 가져오기
`SecurityContext`에서 사용자의 정보를 가져오는 작업은 서비스 계층에서 수행하는 것이 더 적합합니다. 이렇게 하면 보안 관련 로직과 비즈니스 로직을 분리할 수 있고, 코드의 재사용성 및 테스트 용이성도 높일 수 있습니다.

### CSRF 토큰
JWT를 Authorization 헤더로 전송하면 CSRF 보호가 필요 없습니다. CSRF는 세션 기반 인증을 보호하기 위한 것이고, JWT는 자체적으로 CSRF 공격을 방어할 수 있습니다.
{% endraw %}