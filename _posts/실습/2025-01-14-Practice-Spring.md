---
categories:
- Practice
date: '2025-01-14'
title: '[Practice] Spring'
---

{% raw %}
### 예외 및 오류 로깅 확인
```
logging.level.org.springframework: DEBUG
logging.level.org.springframework.web: DEBUG
```

#### 기타 빌드 오류시
##### 1. 캐시 초기화
> gradle clean<br>

##### 2. 터미널 리셋
Spring DevTools를 사용 중인 경우, 변경 사항이 제대로 반영되지 않을 수 있습니다. DevTools를 사용하는 경우 애플리케이션을 완전히 종료하고 다시 시작하세요.

### Could not resolve all files for configuration
패키지가 전부 인식되지 않은 것입니다. 이 때는 패키지 중 존재하지 않는 것(버전 불일치 등)이 있으므로 해당 패키지를 제거하거나 변경해야 합니다.

### java.lang.NoClassDefFoundError: javax/xml/bind/DatatypeConverter

클래스 정의를 찾지 못했을 때 발생되는 예외입니다.

위 메시지일 경우, JAXB API가 java11에서부터는 완전히 제거되었음을 의미합니다. 다음을 추가하면 됩니다.
```
implementation 'javax.xml.bind:jaxb-api:2.3.0'
```

### JPA 미작동
JPA (Java Persistence API)를 사용하려면 `application.properties`에서 데이터베이스 연결 설정이 반드시 있어야 합니다.

```
spring.datasource.url=(DB 주소)
spring.datasource.username=(DB 이용자 이름)
spring.datasource.password=(DB 이용자 비밀번호)
```

### Spring Security
#### 403 에러가 발생하는 이유
`implementation 'org.springframework.boot:spring-boot-starter-security'`를 추가한 후 403 에러가 발생하는 이유는 Spring Security가 자동으로 활성화되었기 때문입니다. Spring Security는 기본적으로 모든 요청에 대해 인증 및 권한 검사를 수행합니다. 따라서 인증되지 않은 사용자나 권한이 없는 사용자가 요청을 보낼 경우 `403 Forbidden` 에러가 발생할 수 있습니다.

Spring Security의 기본 설정은 모든 요청을 보호하고, 인증되지 않은 사용자가 접근할 수 없도록 합니다. 그래서 로그인하지 않은 상태에서 `POST /api/users/register`와 같은 요청을 보내면 `403 Forbidden` 에러가 발생하는 것입니다.

Spring Security는 기본적으로 CSRF 보호를 활성화합니다. POST, PUT, DELETE 요청에서 CSRF 토큰이 없으면 403 오류가 발생할 수 있습니다. CSRF 보호를 비활성화하면 해결할 수 있습니다.

`Spring Security`는 요청을 처리할 때 `SecurityContext`에 인증된 사용자 정보를 설정하여 해당 사용자가 요청을 처리할 수 있는지 확인합니다. 이 정보는 주로 `Authentication` 객체에 저장됩니다. `SecurityContext`에 인증 정보가 설정되지 않으면, Spring Security는 해당 요청을 인증되지 않은 사용자로 간주하고, 권한이 없는 페이지에 접근하려는 경우 403 Forbidden을 발생시킵니다.

#### `HttpSecurity`에서 일부 메서드가 deprecated
Spring 5.x부터는 `HttpSecurity`에서 메서드 체이닝이 아닌 람다식으로 작성해야 합니다.

#### 302 Found
HTTP 상태 코드 **302 Found**가 반환된 이유는 **리다이렉션** 때문입니다. Spring Boot 애플리케이션에서 로그인 엔드포인트가 302를 반환하는 주요 원인은 **Spring Security의 기본 설정 때문입니다**. Spring Security는 기본적으로 **세션 기반 인증**을 사용하며, 인증이 성공하면 **리다이렉션**을 통해 로그인 후 페이지로 이동합니다.

세션 기반 인증을 사용하지 않으면 `formLogin`을 비활성화 하면 됩니다.


### `@Value`가 null인 경우
`@Value`는 **Spring 컨텍스트가 초기화된 후**에 값을 주입하기 때문에, 클래스의 생성자에서 `@Value`를 사용하는 경우, 생성자에서 사용된 값은 Spring 컨텍스트가 초기화된 후에 주입됩니다. 따라서 생성자 내에서 `@Value`가 주입되지 않은 상태에서 해당 필드를 참조하면 `null`이 될 수 있습니다.

### org.springframework.util.PlaceholderResolutionException at PlaceholderResolutionException
`application.properties` 또는 `application.yml`의 설정을 인식하지 못했습니다. (구문 오류일 가능성이 높습니다.)

### Request failed with status code 406
컨트롤러 DTO의 `Getter`를 추가하면 됩니다.

### Could not write JSON: Java 8 date/time type java.time.LocalDateTime not supported by default
Spring에서 `LocalDateTime`과 같은 Java 8의 날짜/시간 타입을 JSON으로 직렬화할 때, 기본적으로는 `jackson-datatype-jsr310` 모듈이 활성화되지 않습니다. 이 문제를 해결하려면 `jackson-datatype-jsr310` 모듈을 추가해야 합니다.

클라이언트는 일반적으로 ISO 8601 형식의 문자열을 받는 게 일반적이기 때문에, `LocalDateTime` 대신 문자열로 처리하는 방법도 가능합니다.

### Redis 데이터 타입
Redis에서 반환되는 데이터는 기본적으로 문자열 형식으로 처리됩니다. 따라서, `Map<Integer, String>`을 Redis에 저장하고 가져올 때, `Map`의 키는 `String`으로 변환되어 저장됩니다.

### 테스트 환경의 포트 번호
테스트 환경에서는 `ServletUriComponentsBuilder.fromCurrentRequestUri()` 또는 `HttpServletRequest`를 사용할 때, 실제 HTTP 요청이 발생하지 않거나, 요청에 포트 번호가 포함되지 않는 경우가 많습니다. 이는 테스트 환경에서 내장 서버를 사용하고 있기 때문에 포트 번호가 기본적으로 포함되지 않거나, 테스트 설정에 따라 다를 수 있습니다.

따라서 테스트 중에는 포트 번호가 포함되지 않거나 기본값이 설정되지 않은 상태로 URI가 생성될 수 있습니다.

### 이중 URI 인코딩
`UriComponentsBuilder.fromUriString`, `restClient.get().uri(url)` 모두 인코딩을 수행합니다. 둘 중 하나만 인코딩을 해야 합니다.

### Unable to determine Dialect without JDBC metadata
DB 이름이 변경되었으나 반영되지 않았습니다. 모든 설정을 변경된 이름에 맞추고, 캐시 초기화 및 터미널 재시작을 해야 합니다.

### java.lang.IllegalStateException: No Acknowledgment available as an argument, the listener container must have a MANUAL AckMode to populate the Acknowledgment.
이 오류는 **Spring Kafka**를 사용할 때 발생하며, Kafka 메시지를 수동으로 `ACK (Acknowledgment)` 하려고 하지만, 리스너 컨테이너의 `AckMode`가 `MANUAL` 또는 `MANUAL_IMMEDIATE`로 설정되지 않았을 때 발생합니다.

`application.yml`에서 설정 
```
spring:
  kafka:
    listener:
      ack-mode: manual
```

### The serializable class UserAchievementKey does not declare a static final serialVersionUID field of type long
이 메시지는 **Java 직렬화(Serialization)** 관련 경고입니다. 직렬화는 객체를 바이트 스트림으로 변환하여 저장하거나 전송할 수 있게 해주는 기능입니다. 직렬화된 객체를 역직렬화(Deserialization)할 때, Java는 객체의 버전을 비교하여 호환성 문제를 피하기 위해 `serialVersionUID`라는 고유한 ID를 사용합니다.

`serialVersionUID`를 명시적으로 선언하지 않으면, Java는 클래스의 구조를 기반으로 자동으로 값을 생성하는데, 이 값이 클래스 변경에 따라 달라질 수 있습니다. 따라서 명시적으로 선언하는 것이 바람직합니다.

### Project has no explicit encoding set
이클립스에서 `"Project has no explicit encoding set"` 경고가 발생하는 이유는 프로젝트의 문자 인코딩이 명시적으로 설정되지 않았기 때문입니다.

기본적으로 이클립스는 플랫폼 기본 인코딩(예: Windows는 CP949, macOS/Linux는 UTF-8) 을 사용하지만, 프로젝트별로 명확하게 지정하지 않으면 파일 인코딩 문제가 발생할 수 있습니다.

### Multipart FileNotFoundException
MultipartFile에서 파일에 저장할 때는 절대 경로를 사용해야 합니다.

```
Path path = Paths.get(outputFile.toURI()).toAbsolutePath();
file.transferTo(path);
```

출처:
- https://stackoverflow.com/questions/33097322/spring-mvc-multipart-file-upload-random-filenotfoundexception

### 리소스 변경사항이 반영되지 않음
파일을 서버에서 생성한 후 바로 불러오지 않고, 서버 재시작 후에 정상적으로 불러오는 문제는 주로 파일 시스템과 Spring의 리소스 핸들러 간의 동기화 문제나 캐시 문제일 가능성이 큽니다.

유저 업로드 파일은 보통 애플리케이션의 `resources` 폴더가 아닌, 서버의 파일 시스템에 저장하는 것이 좋습니다. 왜냐하면 `resources` 폴더는 애플리케이션 빌드 시 복사되거나 패키징되기 때문에, 사용자가 업로드한 파일이 계속적으로 변동할 수 있는 파일 시스템에 저장하는 것이 바람직합니다.
{% endraw %}