# Spring
Spring은 Java 애플리케이션을 개발하기 위한 오픈 소스 프레임워크입니다. 주로 엔터프라이즈급 애플리케이션을 구축하는 데 사용됩니다.

- **의존성 주입(Dependency Injection, DI)**: 객체 간의 의존 관계를 설정하고 필요한 의존 객체를 주입하는 방식을 지원합니다. 이를 통해 코드의 결합도를 낮추고 유연성을 높입니다.
- **제어 역전(Inversion of Control, IoC)**: 객체의 생성과 관리를 프레임워크가 담당하며, 개발자는 필요한 객체를 가져다 사용하는 방식으로 개발할 수 있습니다.
- **애스펙트 지향 프로그래밍(Aspect-Oriented Programming, AOP)**: 관심사의 분리를 통해 횡단 관심 사항을 모듈화하고, 코드 중복을 줄여줍니다. 예를 들어, 로깅, 트랜잭션 관리 등의 기능을 별도의 모듈로 분리하여 재사용할 수 있습니다.
- **모듈화**: Spring은 다양한 모듈로 구성되어 있어 필요한 기능을 선택적으로 사용할 수 있습니다. 이는 개발자가 프로젝트의 요구 사항에 맞게 Spring을 활용할 수 있도록 합니다.

## Spring Boot
- Spring Framework는 Java 애플리케이션을 위한 종합적인 프레임워크로, 다양한 기능을 제공합니다. 설정이 복잡하고 많은 XML 파일이나 Java Config 파일을 작성해야 할 수 있습니다.
- Spring Boot는 Spring Framework의 설정을 자동화하고, 개발자가 쉽게 애플리케이션을 시작할 수 있도록 돕는 프레임워크입니다. 대부분의 개발자들은 Spring Boot를 선호하고 사용합니다.

## 설치
### Spring Initializr
Spring Initializr는 Spring 공식에서 관리하는 도구로, 빠르게 프로젝트를 생성하고, 필요한 의존성을 추가할 수 있습니다.

> https://start.spring.io/

### Spring 프로젝트 파일 생성 및 실행
1. JDK 설치
2. Gradle 또는 Maven 설치 (+환경 변수)
3. Spring Initializr으로 빈 프로젝트 파일 생성
4. cmd에서 프로젝트 메인 폴더로 이동 후, 다음 커맨드 실행

> gradlew bootRun

로컬 접속 url:
> http://localhost:8080

### Spring 프로젝트 테스트
1. `test/`에 위치한 `Test.java`에서 테스트 클래스 작성
2. cmd에서 프로젝트 메인 폴더로 이동 후, 다음 커맨드 실행

> gradle test

- 출력 결과는 `/build/reports/tests/test/index.html`에서 확인 가능합니다.
- `System.out.println()`으로 콘솔 출력이 가능합니다. 출력 내용은 `index.html`의 Standard output에 있습니다.

### 설정 파일
Spring Boot에서 설정 파일로 `application.properties`와 `application.yml`은 모두 사용될 수 있습니다. 두 파일은 동일한 설정을 정의할 수 있지만, 형식과 사용 방법에 약간의 차이가 있습니다. 

- 단순한 설정이라면 `application.properties`가 더 간단하고 빠르게 작성할 수 있습니다.
- 복잡한 계층 구조와 가독성이 필요한 경우 `application.yml`이 더 적합합니다.
- 동일한 설정이 두 파일에 모두 존재하면 `application.properties`의 값이 우선합니다.

#### `application.properties`
**Key-Value 형식**으로 설정을 정의합니다.

```
server.port=8080
spring.datasource.url=jdbc:mysql://localhost:3306/mydb
spring.datasource.username=root
spring.datasource.password=secret
```

#### `application.yml`
**YAML 형식**으로 설정을 정의합니다. 계층 구조를 들여쓰기로 표현할 수 있습니다.

```
server:
  port: 8080
spring:
  datasource:
    url: jdbc:mysql://localhost:3306/mydb
    username: root
    password: secret
```

## IoC Containers
IoC(Inversion of Control) 컨테이너는 객체의 생명주기를 관리하고 의존성 주입을 수행합니다.

- **객체의 관리**: IoC 컨테이너는 개발자가 정의한 클래스의 객체를 생성하고 관리합니다. 객체의 생성, 초기화, 소멸과 같은 생명주기를 관리합니다. 또한 객체가 생성될 때 초기화 메소드를 호출하고, 소멸될 때 소멸 메소드를 호출합니다.
- **의존성 주입**: IoC 컨테이너는 객체가 필요로 하는 의존성을 자동으로 주입합니다. 이를 통해 객체 간의 결합도를 낮추고 유연한 구조를 유지할 수 있습니다.
- **Bean 설정 및 구성**: IoC 컨테이너는 객체를 생성하기 위한 설정 정보를 관리합니다. XML, Java Config, 어노테이션 등 다양한 방법을 통해 객체의 생성 및 관리 방법을 정의할 수 있습니다.
- **싱글톤 관리**: IoC 컨테이너는 기본적으로 싱글톤 패턴을 따릅니다. 따라서 동일한 빈(Bean) 요청에 대해 항상 동일한 객체를 반환합니다.

Spring에서는 다양한 IoC 컨테이너를 제공합니다. 그 중에서도 가장 널리 사용되는 두 가지 IoC 컨테이너는 다음과 같습니다:

- **BeanFactory**: 가장 기본적인 IoC 컨테이너로, 빈의 등록과 관리에 필요한 기능을 제공합니다.
- **ApplicationContext**: BeanFactory를 확장한 것으로, 빈의 미리 로딩, 국제화 지원, 이벤트 발행 등의 기능을 추가로 제공합니다.

## Bean
Bean은 IoC 컨테이너에 의해 관리되는 Java 클래스의 인스턴스이며, Spring 애플리케이션의 핵심 구성 요소입니다.

- **이름**: Bean을 식별하는 데 사용됩니다.
- **타입**: Bean의 클래스를 나타냅니다.
- **프로퍼티**: Bean의 상태를 나타내는 값입니다.
- **설정**: Bean의 동작을 구성하는 속성입니다.
- **생성 방법**: Bean은 다양한 방법으로 생성될 수 있습니다. 주로 XML 설정, Java Config, 어노테이션 등을 사용하여 Bean을 정의합니다.

Spring 애플리케이션에서 **서비스(@Service)**, **컨트롤러(@Controller)**, **리포지토리(@Repository)**는 모두 빈으로 관리됩니다.
- `@Component`: 기본적인 빈 등록 어노테이션.
- `@Service`: 비즈니스 로직을 구현하는 클래스에 사용.
- `@Controller`: 웹 요청을 처리하는 클래스에 사용.
- `@Repository`: 데이터 액세스 계층을 구현하는 클래스에 사용.

### 스코프 (Scope)
Bean의 스코프(Scope)는 해당 Bean이 생성되고 존재하는 시간 동안의 범위를 나타냅니다. Bean의 스코프를 정의함으로써 Bean이 생성되는 시기, 소멸되는 시기, 그리고 Bean 인스턴스의 공유 여부 등을 제어할 수 있습니다.

주요한 Bean의 스코프에는 다음과 같은 것들이 있습니다:

- **Singleton**: 기본적으로 모든 Bean의 스코프입니다. 단일 인스턴스를 유지하며, 모든 요청에 대해 동일한 인스턴스가 반환됩니다. Singleton 스코프의 Bean은 애플리케이션 전체에서 공유됩니다.
- **Prototype**: 요청할 때마다 새로운 인스턴스가 생성되는 스코프입니다. 각 요청에 대해 새로운 Bean 인스턴스가 생성되므로 Singleton과는 달리 각각의 요청에 대해 별도의 인스턴스가 사용됩니다.
- **Request**: 웹 애플리케이션에서 HTTP 요청당 하나의 인스턴스를 생성하는 스코프입니다. 각 HTTP 요청에 대해 새로운 Bean 인스턴스가 생성되며, 해당 요청이 완료되면 Bean 인스턴스가 소멸됩니다.
- **Session**: 웹 애플리케이션에서 HTTP 세션당 하나의 인스턴스를 생성하는 스코프입니다. 각 세션에 대해 새로운 Bean 인스턴스가 생성되며, 해당 세션이 종료되면 Bean 인스턴스가 소멸됩니다.
- **Global Session**: 포털 애플리케이션에서 사용되며, 포털 전체에 걸쳐 하나의 인스턴스를 생성하는 스코프입니다.

이 외에도 다양한 커스텀 스코프를 정의할 수 있습니다.

#### Singleton
단일 인스턴스를 유지하는 스코프입니다.

```
import org.springframework.context.annotation.Scope;
import org.springframework.stereotype.Component;

@Component
@Scope("singleton")
public class SingletonBean {

    private String message;

    public SingletonBean() {
        System.out.println("Creating SingletonBean instance");
        message = "Hello, I'm a Singleton Bean!";
    }

    public String getMessage() {
        return message;
    }
}
```

#### Prototype
요청할 때마다 새로운 인스턴스가 생성되는 스코프입니다.

```
import org.springframework.context.annotation.Scope;
import org.springframework.stereotype.Component;

@Component
@Scope("prototype")
public class PrototypeBean {

    private String message;

    public PrototypeBean() {
        System.out.println("Creating PrototypeBean instance");
        message = "Hello, I'm a Prototype Bean!";
    }

    public String getMessage() {
        return message;
    }
}
```

### 라이프사이클 (Lifecycle)
Bean의 라이프사이클은 Bean이 생성되고 초기화되며 사용되고 소멸되는 과정을 의미합니다.

- **생성(Creation)**: Bean이 인스턴스화되고 생성됩니다. 이 단계에서는 Bean의 생성자가 호출됩니다.
- **초기화(Initialization)**: Bean이 초기화되고 준비됩니다. 이 단계에서는 개발자가 지정한 초기화 작업이 수행됩니다.
- **사용(Usage)**: Bean이 애플리케이션에서 사용됩니다. 이 단계에서는 Bean이 다른 Bean이나 컴포넌트에 주입되어 사용됩니다.
- **소멸(Destruction)**: Bean이 더 이상 필요하지 않기에 소멸됩니다. 이 단계에서는 Bean의 소멸자가 호출되고, 자원을 해제하거나 정리하는 등의 작업을 수행할 수 있습니다.

```
import javax.annotation.PostConstruct;
import javax.annotation.PreDestroy;

import org.springframework.stereotype.Component;

@Component
public class MyBean {

    public MyBean() {
        System.out.println("MyBean constructor");
    }

    @PostConstruct
    public void init() {
        System.out.println("MyBean initialized");
        // 초기화 작업 수행
    }

    @PreDestroy
    public void destroy() {
        System.out.println("MyBean destroyed");
        // 소멸 작업 수행
    }
}
```

Bean의 라이프사이클은 주로 Singleton 스코프에 적용됩니다. Prototype 스코프의 Bean은 생성된 후에는 Spring 컨테이너에 의해 관리되지 않으므로 소멸 단계가 없습니다.

### 컨텍스트
Spring 컨텍스트의 생성 흐름은 Spring 애플리케이션이 시작될 때부터 **빈(Bean)**이 생성되고 초기화되는 과정까지를 포함합니다. 이 흐름은 크게 **빈 생성**, **의존성 주입**, **초기화**로 나눌 수 있습니다. 아래는 Spring 컨텍스트의 생성 흐름을 단계별로 설명한 것입니다.

#### 1. Spring 애플리케이션 시작
Spring 애플리케이션이 시작되면, Spring Boot의 경우 `SpringApplication.run()` 메서드가 호출됩니다. 이 메서드는 `SpringApplication` 객체를 생성하고, 애플리케이션 컨텍스트를 초기화합니다.

#### 2. `ApplicationContext` 생성
Spring은 `ApplicationContext`라는 인터페이스를 통해 애플리케이션의 모든 빈(Bean)을 관리합니다. 이 `ApplicationContext`는 애플리케이션이 시작될 때 자동으로 생성됩니다.

#### 3. Bean 정의 스캔
Spring은 **빈 정의(Bean definition)**를 스캔하여 `ApplicationContext`에 등록합니다. 이 과정에서 `@Component`, `@Service`, `@Repository`, `@Controller` 등과 같은 어노테이션을 사용하여 빈을 정의합니다.
- **컴포넌트 스캔**: `@ComponentScan` 어노테이션을 사용하여 지정된 패키지에서 빈을 자동으로 검색합니다.
- **Java Config 사용**: `@Configuration` 클래스를 사용하여 빈을 명시적으로 정의할 수 있습니다. 이때 `@Bean` 어노테이션을 사용하여 객체를 생성하고 관리합니다.

#### 4. Bean 인스턴스화
빈 정의가 등록되면, Spring은 **빈 인스턴스를 생성**합니다. 이때 빈의 생성자는 호출되며, 의존성 주입이 이루어집니다.
- **생성자 주입**: Spring은 생성자에 주입할 의존성을 자동으로 해결하여 생성자를 호출합니다.
- **필드 주입**: 필드에 `@Autowired` 또는 `@Value` 어노테이션을 사용하면, Spring은 해당 필드에 값을 주입합니다.
- **메서드 주입**: `@Autowired`가 있는 메서드를 통해 의존성을 주입할 수 있습니다.

#### 5. 초기화
빈이 생성되고 의존성 주입이 완료되면, Spring은 빈을 초기화합니다. 이 과정에서 **초기화 메서드**가 호출될 수 있습니다.
-  @PostConstruct`: 빈의 초기화가 끝난 후 호출되는 메서드입니다. `@PostConstruct` 어노테이션을 사용하면, 빈이 초기화된 후 실행할 작업을 정의할 수 있습니다.
-  InitializingBean` 인터페이스: `afterPropertiesSet()` 메서드를 구현하여 초기화 작업을 수행할 수 있습니다.
-  @Bean(initMethod)`: `@Configuration` 클래스에서 `@Bean` 어노테이션을 사용하여 초기화 메서드를 지정할 수 있습니다.

#### 6. AOP 적용
빈이 초기화된 후, **AOP(Aspect-Oriented Programming)**가 적용될 수 있습니다. AOP는 빈의 메서드 호출 전후에 특정 작업을 수행하는 기능입니다. 예를 들어, `@Transactional` 어노테이션을 사용하여 트랜잭션을 관리하거나, `@Around` 어노테이션을 사용하여 메서드 실행 전후에 로깅 등을 수행할 수 있습니다.

#### 7. 빈 사용
빈이 초기화되고 AOP가 적용되면, 이제 애플리케이션에서 빈을 사용할 수 있습니다. 빈은 `@Autowired` 또는 `@Inject` 등을 사용하여 다른 빈에 주입될 수 있습니다. Spring은 빈을 관리하고, 필요한 시점에 의존성을 주입합니다.

#### 8. 애플리케이션 종료
애플리케이션이 종료되면, Spring은 **빈의 소멸** 작업을 수행합니다. 이때 `@PreDestroy` 어노테이션이나 `DisposableBean` 인터페이스를 사용하여 소멸 작업을 정의할 수 있습니다.

### 의존성 주입 (Dependency Injection)
의존성 주입은 객체가 다른 객체를 생성하는 대신, 외부에서 필요한 객체를 주입받는 방식입니다. 이는 객체 간의 결합도를 낮추고, 유연한 코드 작성을 가능하게 합니다.

Spring에서 `@Autowired`는 의존성 주입(Dependency Injection)을 수행하는 데 사용되는 어노테이션입니다. Spring의 **IoC (Inversion of Control)** 컨테이너가 객체를 관리하면서, 필요한 의존성을 자동으로 주입해줍니다.

Spring은 기본적으로 타입을 기준으로 빈을 주입합니다. 예를 들어, `UserService` 타입의 빈이 하나만 존재한다면, `@Autowired`는 그 빈을 주입합니다.

#### 필드 주입
가장 간단하지만, 테스트가 어려울 수 있고, 의존성이 클래스 외부에서 명시적으로 보이지 않기 때문에 권장되지 않습니다.

```
@Autowired
private UserService userService;
```

Spring은 `UserService` 타입의 빈을 찾아서 `userService` 필드에 자동으로 주입합니다.

#### 생성자 주입
생성자에 `@Autowired`를 사용하면, Spring이 해당 생성자를 호출하여 필요한 의존성을 주입합니다. 생성자 주입은 의존성 주입 방식 중 권장되는 방식입니다.

```
private final UserService userService;

@Autowired
public UserController(UserService userService) {
    this.userService = userService;
}
```

Spring 4.3 이상에서는 생성자 주입을 사용할 때 @Autowired 어노테이션을 생략할 수 있습니다.

#### Setter 주입
`@Autowired`를 setter 메서드에 붙여서 의존성을 주입할 수도 있습니다. 선택적 의존성 주입에 유용하지만, 필수 의존성에 대해서는 적합하지 않습니다.

```
private UserService userService;

@Autowired
public void setUserService(UserService userService) {
    this.userService = userService;
}
```

### 자동 빈 등록
빈이 자동으로 주입되는 경우는 **컴포넌트 스캔**이 활성화된 경우입니다. Spring에서는 특정 어노테이션을 사용하여 클래스가 빈으로 등록될 수 있습니다.

1.  `@Component`: 일반적인 컴포넌트 클래스에 사용되어 빈으로 등록됩니다.
    -   예: `@Component`, `@Service`, `@Repository`, `@Controller`
2.  `@Service`: 서비스 클래스에 사용되며, `@Component`의 특성을 갖습니다.
3.  `@Repository`: 데이터 접근 계층을 나타내는 클래스에 사용되며, `@Component`의 특성을 갖습니다.
4.  `@Controller`: 웹 계층에서 사용하는 컨트롤러 클래스에 사용됩니다.

### `@Configuration`
Spring에서 설정 클래스를 정의할 때 사용하는 어노테이션입니다. 이 어노테이션이 붙은 클래스는 **빈 정의**를 포함하는 설정 클래스임을 나타내며, Spring의 **애플리케이션 컨텍스트**에 빈을 등록하거나 설정을 제공합니다.

- `@Configuration`이 붙은 클래스는  **싱글톤** 패턴을 따르며, Spring 컨테이너에서 관리되는 **빈 설정**을 포함하고 있습니다.
- 클래스 내에 `@Bean` 어노테이션을 사용하여 객체를 빈으로 등록할 수 있습니다. `@Bean` 메서드는 애플리케이션 컨텍스트에 등록된 **빈 객체**를 반환합니다.
- `@Configuration` 클래스는 **컴포넌트 스캔**의 일부로 동작하므로, `@ComponentScan`을 통해 자동으로 스캔되거나 `@SpringBootApplication` 어노테이션을 통해 기본적으로 스캔됩니다.

```
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

@Configuration
public class AppConfig {

    // 빈을 정의하는 메서드
    @Bean
    public MyService myService() {
        return new MyService();
    }
}
```

위 코드에서 `@Configuration` 어노테이션을 사용하여 `AppConfig` 클래스를 설정 클래스로 지정하고, `@Bean` 어노테이션을 사용하여 `MyService` 객체를 Spring 애플리케이션 컨텍스트에 빈으로 등록합니다.

### `@ComponentScan`
`@ComponentScan`은 Spring에서 **컴포넌트 스캔**을 활성화하는 어노테이션입니다. **컴포넌트 스캔**이란, Spring이 클래스패스를 검색하여 `@Component`, `@Service`, `@Repository`, `@Controller` 등의 어노테이션이 붙은 클래스를 찾아 자동으로 빈으로 등록하는 기능입니다.

`@ComponentScan`은 기본적으로 **현재 클래스가 위치한 패키지와 그 하위 패키지**에서만 컴포넌트를 검색합니다. 예를 들어, `MyApplication` 클래스가 `com.example` 패키지에 위치해 있으면, `com.example`와 그 하위 패키지에 있는 `@Component` 어노테이션이 붙은 클래스들이 자동으로 빈으로 등록됩니다.

```
@ComponentScan(basePackages = "com.example")
public class MyApplication {
    // 컴포넌트 스캔을 통해 com.example 패키지에서 빈을 등록
}
```

### `@SpringBootApplication`
`@SpringBootApplication`은 Spring Boot 애플리케이션을 설정하기 위한 **복합 어노테이션**으로, Spring Boot 애플리케이션을 시작하는 클래스에 자동으로 사용됩니다. 이 어노테이션은 세 가지 중요한 어노테이션을 합친 형태입니다:

- `@EnableAutoConfiguration`: Spring Boot의 자동 설정 기능을 활성화합니다. 애플리케이션의 클래스패스를 분석하고, 필요한 빈을 자동으로 설정합니다.
- `@ComponentScan`: Spring의 컴포넌트 스캔을 활성화하여, `@Component`, `@Service`, `@Repository`, `@Controller` 등의 어노테이션이 붙은 클래스를 자동으로 빈으로 등록합니다.
- `@Configuration`: 애플리케이션의 설정을 위한 클래스를 나타내며, `@Bean` 메서드를 통해 빈을 정의할 수 있게 합니다.

`@SpringBootApplication`은 Spring Boot 애플리케이션을 설정하는 데 필요한 기본적인 설정을 자동으로 처리해줍니다. 이 어노테이션이 붙은 클래스는 애플리케이션의 진입점(즉, `main` 메서드를 포함한 클래스)으로 사용됩니다.

```
@SpringBootApplication
public class MyApplication {
    public static void main(String[] args) {
        SpringApplication.run(MyApplication.class, args);
    }
}
```

`@SpringBootApplication`은 Spring Boot 애플리케이션의 진입점으로 사용되며, 이를 명시적으로 사용함으로써 프로젝트 내에서 일관된 방식으로 애플리케이션을 설정하고 실행할 수 있습니다. `@SpringBootApplication`을 명시적으로 사용하지 않아도 Spring Boot 애플리케이션을 실행할 수는 있지만, 애플리케이션을 간단하고 일관되게 설정하려면 `@SpringBootApplication`을 사용하는 것이 좋습니다.

### @Value
`@Value` 어노테이션을 사용하면 `application.properties` 또는 `application.yml` 파일에 정의된 값을 바로 주입받을 수 있습니다.

```
import org.springframework.beans.factory.annotation.Value;
import org.springframework.stereotype.Service;

@Service
public class EmailService {

    @Value("${spring.mail.host}")
    private String mailHost;

    @Value("${spring.mail.port}")
    private int mailPort;

    public void printMailSettings() {
        System.out.println("Mail Host: " + mailHost);
        System.out.println("Mail Port: " + mailPort);
    }
}
```

이렇게 하면 `application.properties`에 설정된 `spring.mail.host`와 `spring.mail.port` 값을 `EmailService` 클래스에서 바로 사용할 수 있습니다.

`@Value`는 **Spring 컨텍스트가 초기화된 후**에 값을 주입하기 때문에, 클래스의 생성자에서 `@Value`를 사용하는 경우, 생성자에서 사용된 값은 Spring 컨텍스트가 초기화된 후에 주입됩니다. 따라서 생성자 내에서 `@Value`가 주입되지 않은 상태에서 해당 필드를 참조하면 `null`이 될 수 있습니다.

만약 생성자에서 사용하고자 한다면, 생성자 인자에 제공하면 됩니다.
```
public  EmailSender(EmailProviderRepository  emailProviderRepository,
				@Value("${spring.mail.username}") String  mailUserName,
				@Value("${spring.mail.password}") String  mailPassword) {
	...
}
```

### `@ConfigurationProperties`
`@ConfigurationProperties`를 사용하면 설정 파일에서 값을 Java 객체에 매핑할 수 있습니다. 이 방법은 여러 설정 항목을 한 번에 다룰 때 유용합니다.

```
import org.springframework.boot.context.properties.ConfigurationProperties;
import org.springframework.stereotype.Component;

@Component
@ConfigurationProperties(prefix = "spring.mail")
public class MailProperties {

    private String host;
    private int port;
    private String username;
    private String password;

    // Getters and Setters
    
}
```

## 엔티티(Entity)
**엔티티(Entity)**는 **데이터베이스의 테이블과 1:1로 매핑되는 객체**입니다. 객체 지향 프로그래밍(OOP)과 관계형 데이터베이스(RDB) 간의 차이를 해결하기 위해 등장한 개념으로, 자바 클래스와 데이터베이스 테이블 간의 연결을 담당합니다.

1. **데이터베이스 테이블과 매핑**
    - 엔티티는 데이터베이스의 테이블 구조를 자바 클래스의 필드로 표현합니다.
    - 테이블의 각 열(Column)은 클래스의 필드(Field)에 매핑됩니다.
    - JPA(Java Persistence API)를 사용하여 매핑을 정의합니다.
2. **영속성(Persistence)**
    - 엔티티는 JPA를 통해 데이터베이스와 연동됩니다.
    - 엔티티 객체는 영속성 컨텍스트(Persistence Context)에 의해 관리되며, 데이터베이스의 데이터 상태와 동기화됩니다.

엔티티는 어노테이션을 사용하여 매핑 정보를 설정합니다.

을 설정하기 위해 다양한 어노테이션을 사용할 수 있습니다. 주요 어노테이션들은 다음과 같습니다:

### `@Entity`
해당 클래스가 JPA 엔티티임을 나타냅니다. 즉, 데이터베이스의 테이블과 매핑되는 객체임을 지정합니다.

```
@Entity
public class User {
    // 엔티티 속성들
}
```

### `@Table`
`@Entity`로 지정된 클래스가 매핑될 테이블을 명시합니다. 테이블 이름을 지정하지 않으면 기본적으로 클래스 이름과 같은 이름의 테이블이 사용됩니다.

```
@Entity
@Table(name = "users")
public class User {
    // 엔티티 속성들
}
```

### `@Id`
해당 필드가 엔티티의 **기본 키**임을 나타냅니다. 기본 키는 테이블에서 각 행을 고유하게 식별하는 필드입니다.

```
@Entity
public class User {
    @Id
    private String userId;
    // 다른 속성들
}
```

### `@GeneratedValue`
기본 키 값을 자동으로 생성하는 방법을 설정합니다. 예를 들어, 데이터베이스에서 자동 증가하는 ID를 생성하도록 할 수 있습니다.

```
@Entity
public class User {
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;
    // 다른 속성들
}
```

### `@Column`
엔티티 클래스의 필드와 데이터베이스 테이블의 컬럼을 매핑합니다. 컬럼의 이름, 길이, null 여부 등을 설정할 수 있습니다.

```
@Entity
public class User {
    @Id
    private String userId;

    @Column(nullable = false, length = 100)
    private String name;
    // 다른 속성들
}
```

### @Lob
`@Lob` 어노테이션은 "Large Object"를 나타냅니다. 이 어노테이션은 데이터베이스에 저장할 때 큰 크기의 데이터를 처리할 수 있도록 도와줍니다. `@Lob`은 `BLOB`(Binary Large Object) 또는 `CLOB`(Character Large Object) 타입으로 매핑됩니다.

- `BLOB`: 이진 데이터(예: 이미지, 비디오 등)
- `CLOB`: 텍스트 데이터(예: 긴 텍스트, JSON, XML 등)

```
@Lob
@Column(name = "address_components", columnDefinition = "json")
private String addressComponents;
```

`JSON` 형식의 문자열을 저장하기 위해 `CLOB` 타입으로 매핑됩니다.

참고사항:
- **성능**: `@Lob`을 사용한 필드는 `LAZY` 로딩을 기본으로 하므로, 데이터를 실제로 사용할 때만 로딩됩니다. 즉, 데이터를 읽을 때 성능에 영향을 미칠 수 있습니다.
- **데이터베이스 지원**: 데이터베이스마다 `BLOB` 또는 `CLOB` 타입을 지원하지 않는 경우가 있을 수 있으므로, 사용하는 데이터베이스에서 이를 지원하는지 확인해야 합니다.

### `@Embeddable`
`@Embeddable`은 **내장 가능한 클래스**를 정의할 때 사용합니다. 이 클래스는 다른 엔티티의 일부로 포함될 수 있으며, 데이터베이스 테이블의 컬럼으로 매핑됩니다.
    
- 독립적으로 엔티티가 아니며, 다른 엔티티에 포함되어야 합니다.
- 데이터베이스 테이블의 컬럼에 매핑되지만, 독립적인 테이블을 가지지 않습니다.
- 주로 복합 키나 반복적으로 사용되는 필드 그룹을 정의할 때 사용됩니다.

```
@Embeddable
public class UserAchievementKey implements Serializable {
    private int userId;
    private int achvId;

    // Getters, Setters, equals, hashCode
}
```

### `@EmbeddedId`
`@EmbeddedId`는 복합 키(Composite Key)를 엔티티의 기본 키로 설정할 때 사용됩니다. `@Embeddable`로 정의된 클래스와 함께 사용됩니다.
    
- 복합 키를 정의하기 위해 사용되며, 해당 키 클래스는 반드시 `@Embeddable`로 정의되어야 합니다.
- 복합 키는 JPA에서 `Serializable` 인터페이스를 구현해야 합니다.
- 복합 키 클래스는 `equals`와 `hashCode` 메서드를 반드시 구현해야 합니다.

```
@Entity
@Table(name = "user_achievements")
public class UserAchievement {

    @EmbeddedId
    private UserAchievementKey id;

    @Column(name = "achieved_at", nullable = false)
    private LocalDateTime achievedAt;

    // Getters, Setters
}
```

## 서비스(Service)
**서비스(Service)**는 **애플리케이션의 비즈니스 로직을 처리하는 계층**입니다. Spring 애플리케이션에서는 일반적으로 서비스 계층을 사용하여 컨트롤러(Controller)와 데이터 액세스 계층(Repository) 사이의 중간 역할을 수행합니다.

1. **비즈니스 로직 처리**
    - 데이터 조회, 변환, 계산, 검증 등 비즈니스 규칙을 구현합니다.
    - 컨트롤러에서 처리하기엔 복잡한 로직을 캡슐화하여 재사용성을 높입니다.
2. **데이터 액세스 계층 호출**
    - 데이터베이스 작업(저장, 조회, 수정, 삭제)을 Repository 계층에 위임합니다.
    - 여러 데이터 소스나 외부 API를 조합하여 필요한 데이터를 생성합니다.
3. **컨트롤러와 Repository 간의 분리**
    - 컨트롤러는 요청/응답 처리에만 집중하고, Repository는 데이터베이스 작업에 집중할 수 있도록 역할을 분리합니다.
    - 서비스 계층은 두 계층 간의 의존성을 관리합니다.

### `@Service`
`@Service`는 `@Component`의 특수한 형태로, **서비스 계층**의 클래스를 나타내는 데 사용됩니다. Spring에서 `@Service`는 기본적으로 `@Component`와 동일하게 동작하지만, 서비스 계층을 명확하게 구분하고자 할 때 사용됩니다.

## 컨트롤러(Controller)
**컨트롤러(Controller)**는 **사용자 요청을 처리하고, 응답을 반환하는 역할**을 하는 계층입니다. Spring에서는 **웹 애플리케이션**에서 클라이언트의 요청을 받아 처리하는 역할을 담당합니다. 보통 HTTP 요청을 처리하며, 요청에 맞는 서비스를 호출하고, 그 결과를 클라이언트에게 반환합니다. 컨트롤러는 **MVC(Model-View-Controller)** 패턴에서 **Controller** 역할을 하며, 애플리케이션의 **웹 계층**을 담당합니다.

1. **HTTP 요청 처리**
    - 클라이언트(웹 브라우저, 모바일 앱 등)에서 보낸 HTTP 요청을 처리합니다. 예를 들어, `GET`, `POST`, `PUT`, `DELETE`와 같은 HTTP 메서드를 처리합니다.
2. **서비스 호출**
    - 컨트롤러는 **서비스 계층**을 호출하여 비즈니스 로직을 처리합니다. 서비스 계층은 데이터베이스 작업을 위한 리포지토리와 상호작용합니다.
3. **응답 반환**
    - 처리된 결과를 **HTTP 응답**으로 반환합니다. 이 응답은 클라이언트에게 JSON, HTML, XML 등의 형식으로 전달됩니다.
4. **URL과 메서드 매핑**
    - 특정 URL 경로와 HTTP 메서드(GET, POST 등)를 컨트롤러의 메서드에 매핑하여 요청을 처리합니다.

컨트롤러는 **Spring MVC**에서 사용 가능합니다.

## 리포지토리(Repository)
**리포지토리(Repository)**는 **데이터베이스와의 상호작용을 담당하는 계층**입니다. Spring에서 리포지토리는 **데이터 액세스 계층**으로, 주로 데이터베이스에서 데이터를 조회, 저장, 수정, 삭제하는 기능을 제공합니다. Spring Data JPA는 **JPA(Java Persistence API)**를 기반으로 하며, 리포지토리 인터페이스를 선언하면 Spring이 자동으로 구현체를 생성해줍니다.

1. **데이터베이스 작업 처리**
	- 데이터베이스에서 데이터를 **조회**, **저장**, **수정**, **삭제**하는 작업을 수행합니다.
    - SQL을 직접 작성하는 대신, Spring Data JPA와 같은 라이브러리를 사용하면 **자동으로 쿼리 메서드**를 생성해줍니다.
2. **엔티티와 데이터베이스 테이블 매핑**
    - 리포지토리는 엔티티 객체와 데이터베이스 테이블 간의 매핑을 담당합니다.
    - JPA를 사용하면 객체 지향적으로 데이터를 다룰 수 있으며, SQL을 직접 작성할 필요가 줄어듭니다.
3. **비즈니스 로직과 분리**
    - 비즈니스 로직은 서비스 계층에서 처리하고, 데이터베이스 작업은 리포지토리에서 처리하도록 분리하여 **책임의 분리**를 구현합니다.

## Spring Data JPA
**Spring Data JPA**는 **리포지토리(Repository) 패턴**을 구현하는 **프레임워크**이며, **JPA(Java Persistence API)**를 더 쉽게 사용할 수 있도록 도와주는 모듈입니다. 데이터 액세스 계층을 단순화하고, 데이터베이스와의 상호작용을 효율적으로 처리하도록 설계되었습니다.

**Spring Data JPA**는 `CrudRepository`, `JpaRepository`, `PagingAndSortingRepository` 같은 기본 인터페이스를 제공하며, 이를 확장하여 리포지토리를 정의할 수 있습니다.

### `CrudRepository `
`CrudRepository`는 CRUD(Create, Read, Update, Delete) 작업을 위한 기본 메서드를 제공합니다.

- `save(S entity)`: 엔티티를 저장하거나 업데이트. (엔티티의 상태에 따라 `persist()` 또는 `merge()`를 내부적으로 호출)
- `saveAll(Iterable<S> entities)`: 여러 엔티티를 저장하거나 업데이트.
- `persist(T entity)`: 새로운 엔티티를 저장. 기존 엔티티는 처리하지 않음.
- `merge(T entity)`: 기존 엔티티를 업데이트하거나, 영속성 컨텍스트에 없는 엔티티를 저장.
- `findById(ID id)`: ID로 엔티티를 조회. 없으면 `Optional.empty()` 반환.
- `existsById(ID id)`: ID로 엔티티 존재 여부 확인.
- `findAll()`: 모든 엔티티 조회.
- `findAllById(Iterable<ID> ids)`: 여러 ID로 엔티티 조회.
- `count()`: 엔티티의 총 개수 반환.
- `deleteById(ID id)`: ID로 엔티티 삭제.
- `delete(T entity)`: 엔티티 삭제.
- `deleteAllById(Iterable<? extends ID> ids)`: 여러 ID로 엔티티 삭제.
- `deleteAll()`: 모든 엔티티 삭제.

###  `JpaRepository`
`JpaRepository`는 `CrudRepository`와 `PagingAndSortingRepository`를 확장하며, 추가적인 JPA 관련 기능을 제공합니다.

- `flush()`: 현재 영속성 컨텍스트에 저장된 변경 내용을 데이터베이스에 즉시 반영.
- `saveAndFlush(S entity)`: 엔티티를 저장하고 즉시 데이터베이스에 반영.
- `deleteAllInBatch()`: 모든 엔티티를 배치로 삭제.
- `deleteAllInBatch(Iterable<T> entities)`: 지정된 엔티티들을 배치로 삭제.
- `findAll(Sort sort)`: 정렬 기준으로 모든 엔티티 조회.

### `PagingAndSortingRepository`
페이징과 정렬을 지원하는 메서드를 제공합니다.

- `findAll(Sort sort)`: 정렬 기준으로 모든 엔티티 조회.
- `findAll(Pageable pageable)`: 페이징된 엔티티 조회.

### 쿼리 메서드 생성 규칙
Spring Data JPA에서 **쿼리 메서드 생성 규칙**은 메서드 이름을 기반으로 자동으로 쿼리를 생성하는 방식입니다. 메서드 이름의 구조와 키워드를 사용하여 JPA가 적절한 JPQL 쿼리를 생성합니다. 이를 통해 복잡한 SQL을 작성하지 않고도 데이터를 쉽게 조회할 수 있습니다.

메서드 이름의 구조는 다음과 같습니다:
> `[키워드][조건][필드][연산자]` 

-   **키워드**: `findBy`, `readBy`, `queryBy`, `countBy`, `deleteBy`, `existsBy` 등.
-   **조건**: `And`, `Or`, `Between`, `LessThan`, `GreaterThan` 등.
-   **필드**: 엔티티 클래스에 정의된 필드 이름.
-   **연산자**: `OrderBy` 등 정렬을 위한 추가 키워드.

#### 기본 키워드
- `findBy`: 데이터를 조회.
- `readBy`: 데이터를 읽음(조회와 동일).
- `queryBy`: 데이터를 쿼리(조회와 동일).
- `countBy`: 데이터를 카운트.
- `deleteBy`: 데이터를 삭제.

#### 조건 연결자
- `And`: 두 조건을 **AND** 연산으로 연결.
- `Or`: 두 조건을 **OR** 연산으로 연결.

#### 조건 키워드
- `IsNull`, `IsNotNull`: 필드가 NULL인지 확인.
- `IsTrue`, `IsFalse`: 필드가 Boolean일 때 true/false인지 확인.
- `Between`: 두 값 사이의 범위를 확인.
- `LessThan`, `LessThanEqual`: 값이 특정 값보다 작거나 같은지 확인.
- `GreaterThan`, `GreaterThanEqual`: 값이 특정 값보다 크거나 같은지 확인.
- `Like`, `NotLike`: 부분 일치 검색.
- `In`, `NotIn`: 특정 값 목록에 포함되는지 확인.
- `StartingWith`, `EndingWith`, `Containing`: 문자열 검색.

#### 정렬 키워드
- `OrderBy`: 결과를 정렬.
- 필드 이름 뒤에 `Asc`(오름차순) 또는 `Desc`(내림차순)를 추가.

#### 예제
**기본 조회**
```
User findByEmail(String email); // 이메일로 조회
List<User> findByName(String name); // 이름으로 조회
```

**복합 조건**
```
User findByNameAndEmail(String name, String email); // 이름과 이메일 모두 일치
List<User> findByNameOrEmail(String name, String email); // 이름 또는 이메일 중 하나 일치
```

**조건 키워드**
```
List<User> findByAgeGreaterThan(int age); // age가 특정 값보다 큰 사용자 조회
List<User> findByCreatedAtBetween(LocalDateTime start, LocalDateTime end); // 날짜 범위 조회
List<User> findByNameLike(String name); // 이름이 특정 패턴과 일치
```

**정렬**
```
List<User> findByNameOrderByCreatedAtDesc(String name); // 이름으로 조회 후 생성일 내림차순 정렬
```

**Boolean 조건**
```
List<User> findByActiveTrue(); // active 필드가 true인 사용자 조회
List<User> findByActiveFalse(); // active 필드가 false인 사용자 조회
```

#### `@Query`
만약 쿼리 메서드로 표현하기 어려운 복잡한 쿼리가 필요하다면, 다음 방법을 사용할 수 있습니다:
```
@Query("SELECT u FROM User u WHERE u.name LIKE %:name%")
List<User> searchByName(@Param("name") String name);
```
    
#### `@Modifying`
`@Modifying`은 Spring Data JPA에서 **데이터 변경 작업(INSERT, UPDATE, DELETE)**을 수행하는 쿼리를 사용할 때 필요한 어노테이션입니다. JPA의 기본 동작은 SELECT와 같은 **조회 작업**을 처리하기 위한 것이므로, 데이터 변경 작업을 명시적으로 선언하기 위해 `@Modifying`을 사용합니다.

1. **데이터 변경 작업에 필수**: `@Query`와 함께 사용되며, JPQL 또는 네이티브 쿼리로 데이터를 삽입, 수정, 삭제할 때 필요합니다.
2. **트랜잭션 필요**: 데이터 변경 작업이므로 트랜잭션이 필요합니다.
    -  사용자 정의 JPQL 또는 네이티브 쿼리에서 `@Modifying`을 사용하는 경우에는 트랜잭션을 명시적으로 선언해야 합니다.
    - 트랜잭션이 없으면 `javax.persistence.TransactionRequiredException`이 발생할 수 있습니다.
3. **반환값**: 업데이트된 행(row)의 개수를 반환합니다. 반환값은 `int` 또는 `long`으로 받을 수 있습니다.

## Spring Web
**Spring Web**은 Spring Framework의 일부로, 웹 애플리케이션 개발을 위한 다양한 기능을 제공하는 모듈입니다. Spring Web은 **웹 애플리케이션을 구축**하는 데 필요한 핵심 기능들을 제공하며, 주로 HTTP 요청 처리, RESTful 웹 서비스 구축, 웹 페이지 처리 등을 포함합니다.

1. **웹 애플리케이션 개발**: Spring Web은 웹 애플리케이션의 핵심 기능을 제공합니다. 예를 들어, HTTP 요청을 처리하고, 응답을 반환하는 기능을 제공합니다.
2. **Spring MVC**: **Spring MVC**(Model-View-Controller)는 Spring Web의 주요 구성 요소 중 하나로, 웹 애플리케이션의 **MVC 패턴**을 지원합니다. 이를 통해 웹 요청을 처리하는 컨트롤러를 정의하고, 모델과 뷰를 연결하여 동적인 웹 페이지를 생성할 수 있습니다.
3. **RESTful 웹 서비스**: Spring Web은 RESTful API를 구축하는 데 필요한 기능을 제공합니다. `@RestController`, `@GetMapping`, `@PostMapping` 등의 어노테이션을 사용하여 RESTful 웹 서비스를 쉽게 구현할 수 있습니다.
4.  **폼 처리 및 데이터 바인딩**: Spring Web은 웹 폼 데이터를 처리하고, 이를 Java 객체에 바인딩하는 기능을 제공합니다. `@ModelAttribute`와 같은 어노테이션을 통해 폼 데이터를 객체에 매핑할 수 있습니다.

Spring Boot 프로젝트에서 Spring Web을 사용하려면 `spring-boot-starter-web` 의존성을 `build.gradle`(Gradle) 또는 `pom.xml`(Maven) 파일에 추가해야 합니다.

Spring Web에서는 **어노테이션**을 사용하여 웹 요청을 처리합니다.

###  `@CrossOrigin`
**CORS(Cross-Origin Resource Sharing)**를 설정하는 어노테이션입니다. 이 어노테이션을 사용하여 **다른 도메인**에서의 요청을 허용할 수 있습니다.
        
```
@CrossOrigin(origins = "http://example.com")
@RestController
public class MyController {
    @GetMapping("/api")
    public String getApi() {
        return "Hello";
    }
}
```
        
### `@RequestBody`
HTTP 요청 본문을 **객체로 변환**하여 메소드 파라미터로 전달하는 어노테이션입니다. 주로 **REST API**에서 클라이언트가 보낸 JSON 데이터를 객체로 변환할 때 사용됩니다.

```
@PostMapping("/users")
public ResponseEntity<User> createUser(@RequestBody User user) {
    // user 객체를 사용한 로직 처리
    return ResponseEntity.ok(user);
}
```

### `@RequestPart`
`@RequestPart`는 **Spring MVC**에서 **멀티파트 파일 업로드** 또는 **복합 객체**를 처리할 때 사용되는 어노테이션입니다. 이 어노테이션은 HTTP 요청에서 `multipart/form-data` 형식으로 전송된 부분을 처리할 때 사용됩니다. 주로 파일 업로드와 JSON 등의 데이터를 함께 처리하는 경우에 사용됩니다.

```
@PostMapping("/upload")
public ResponseEntity<String> uploadFile(
		@RequestPart("file") MultipartFile file,
		@RequestPart("metadata") String metadata) {
	
	// 파일 처리
	String filename = file.getOriginalFilename();
	// metadata 처리 (예: JSON)
	System.out.println("Metadata: " + metadata);
	
	return ResponseEntity.ok("File uploaded successfully: " + filename);
}
```

위에서 클라이언트는 `multipart/form-data` 형식으로 두 가지를 전송해야 합니다:
- `"file"`: 업로드할 파일
- `"metadata"`: 파일에 대한 메타데이터(예: JSON 형식)

### `@SessionAttributes`
**세션**에 특정 속성을 저장하고, 해당 속성에 접근할 수 있도록 하는 어노테이션입니다. 주로 **세션 기반 웹 애플리케이션**에서 사용됩니다.

```
@Controller
@SessionAttributes("user")
public class UserController {
    // 세션에 "user" 객체를 저장하고, 이를 참조
}
```
        
### `@EnableWebSecurity`
**Spring Security**를 활성화하는 어노테이션입니다. Spring Web에서 **보안 설정**을 활성화할 때 사용됩니다.

```
@Configuration
@EnableWebSecurity
public class SecurityConfig extends WebSecurityConfigurerAdapter {
    // 보안 설정
}
```

### MultipartFile
`MultipartFile`은 Spring에서 파일 업로드를 처리하는 데 사용되는 인터페이스입니다. `multipart/form-data` 형식으로 전송된 파일 데이터를 쉽게 처리할 수 있게 도와주는 기능을 제공합니다.

`getOriginalFilename()`: 업로드된 파일의 원래 이름을 반환합니다.
```
String originalFileName = file.getOriginalFilename();
```

`getSize()`: 업로드된 파일의 크기(바이트 단위)를 반환합니다.
```
long size = file.getSize();
```

`getContentType()`: 파일의 MIME 타입을 반환합니다. 예를 들어, 이미지 파일의 경우 `image/jpeg` 등의 값이 반환됩니다.
```
String contentType = file.getContentType();
```

`isEmpty()`: 업로드된 파일이 비어 있는지 확인합니다. 파일이 없으면 `true`를 반환합니다.
```
if (file.isEmpty()) {
	// 파일이 비어 있을 경우 처리
}
```

`transferTo(File dest)`: 파일을 서버의 지정된 위치에 저장하는 메서드입니다.
```
file.transferTo(new File("path/to/save"));
```

`getBytes()`: 파일의 내용을 바이트 배열로 반환합니다.
```
byte[] fileBytes = file.getBytes();
```

### OncePerRequestFilter
`OncePerRequestFilter`는 **Spring Web**에서 제공하는 필터 클래스입니다. 이 필터는 요청이 처리될 때 한 번만 실행되도록 보장합니다. 즉, 요청 당 단 한 번만 필터가 적용되도록 하여, 여러 번 호출되는 것을 방지합니다.

- **요청당 한 번만 실행**: `OncePerRequestFilter`는 요청이 들어올 때마다 한 번만 실행되도록 보장합니다. 이 필터는 여러 번 호출되는 것을 방지하기 위해 사용됩니다.
- **필터 체인에서 사용**: `OncePerRequestFilter`는 Spring Security의 필터 체인에서 사용될 수 있습니다. 일반적으로 인증, 인가, 로깅 등의 작업을 필터에서 처리할 때 사용됩니다.
- **doFilterInternal 메서드 구현**: `OncePerRequestFilter`를 상속받아 필터를 구현할 때, `doFilterInternal` 메서드를 오버라이드하여 필터 로직을 작성합니다. 이 메서드는 요청이 들어올 때마다 한 번만 호출됩니다.

#### `doFilterInternal`
`doFilterInternal`은 `OncePerRequestFilter` 클래스에서 제공하는 추상 메서드로, 이 메서드는 요청이 들어올 때마다 한 번만 실행되도록 보장되는 필터에서 실제 필터 로직을 작성하는 곳입니다.

1. **필터 로직 처리**: `doFilterInternal` 메서드 안에서 요청에 대해 필요한 처리를 합니다. 예를 들어, 인증, 권한 검사, 로깅, 데이터 변환 등을 할 수 있습니다.
2. **다음 필터로 전달**: 필터 로직을 처리한 후, `filterChain.doFilter(request, response)`를 호출하여 요청을 필터 체인의 다음 필터로 전달합니다. 이 호출이 없으면 필터 체인의 다른 필터가 실행되지 않습니다.

** 주요 매개변수**
- `HttpServletRequest request`: 클라이언트의 요청을 나타내는 객체입니다. 요청에 포함된 데이터를 읽고, 필요한 경우 수정할 수 있습니다.
- `HttpServletResponse response`: 서버의 응답을 나타내는 객체입니다. 응답을 수정하거나 설정할 수 있습니다.
- `FilterChain filterChain`: 필터 체인 내의 다음 필터를 호출하는 객체입니다. `filterChain.doFilter(request, response)`를 호출하여 요청을 다음 필터로 전달합니다.

```
@Component
public class JwtAuthenticationFilter extends OncePerRequestFilter {

    private final JwtTokenProvider jwtTokenProvider;

    public JwtAuthenticationFilter(JwtTokenProvider jwtTokenProvider) {
        this.jwtTokenProvider = jwtTokenProvider;
    }

    @Override
    protected void doFilterInternal(HttpServletRequest request, HttpServletResponse response, FilterChain filterChain) throws ServletException, IOException {
        // 요청 헤더에서 토큰 추출
        String token = jwtTokenProvider.resolveToken(request);

        // 토큰이 유효하면 인증 정보를 SecurityContext에 설정
        if (token != null && jwtTokenProvider.validateToken(token)) {
            Authentication authentication = jwtTokenProvider.getAuthentication(token);
            SecurityContextHolder.getContext().setAuthentication(authentication);
        }

        // 필터 체인의 다음 필터로 요청을 전달
        filterChain.doFilter(request, response);
    }
}
```

### addFilterBefore
`addFilterBefore()`는 특정 필터를 **기존 필터보다 먼저 실행되도록** 추가하는 데 사용됩니다. 첫 번째 인자는 추가할 필터이고, 두 번째 인자는 해당 필터가 실행될 위치를 지정하는 필터입니다.

두 번째 필터가 필터 체인에 존재하지 않으면, 예외가 발생하지 않고, 첫 번째 필터는 정상적으로 실행되며, 두 번째 필터는 필터 체인에서 생략됩니다.

### RestTemplate
`RestTemplate`은 Spring Framework에서 제공하는 HTTP 클라이언트로, RESTful 웹 서비스와 상호작용하기 위해 사용됩니다. 이를 통해 HTTP 요청을 보내고, 응답을 받을 수 있습니다. `RestTemplate`은 HTTP GET, POST, PUT, DELETE 등의 요청을 손쉽게 처리할 수 있도록 도와줍니다.

1. **HTTP 요청 전송**: `RestTemplate`을 사용하면 HTTP 요청을 전송할 수 있습니다. 예를 들어, GET 요청을 보내서 서버로부터 데이터를 가져오거나, POST 요청을 보내서 데이터를 서버에 전송할 수 있습니다.
2. **응답 처리**: 서버로부터 받은 응답을 Java 객체로 변환할 수 있습니다. 예를 들어, JSON 응답을 Java 객체로 변환하거나, XML 응답을 Java 객체로 변환할 수 있습니다.
3. **다양한 HTTP 메서드 지원**: GET, POST, PUT, DELETE 등의 HTTP 메서드를 지원합니다.

Spring에서는 `RestTemplate`을 빈(bean)으로 등록하여 사용할 수 있습니다. 이렇게 하면 의존성 주입을 통해 애플리케이션에서 손쉽게 `RestTemplate`을 사용할 수 있습니다.

#### getForObject
`getForObject` 메서드는 지정된 URL로 GET 요청을 보내고, 응답을 `String` 형식으로 반환합니다.
```
RestTemplate restTemplate = new RestTemplate();
String url = "https://api.example.com/data";
String response = restTemplate.getForObject(url, String.class);
```

#### postForEntity
`postForEntity`는 POST 요청을 보내고, 서버의 응답을 `ResponseEntity` 객체로 반환합니다.
```
RestTemplate restTemplate = new RestTemplate();
String url = "https://api.example.com/data";
Map<String, String> requestBody = new HashMap<>();
requestBody.put("key", "value");

ResponseEntity<String> response = restTemplate.postForEntity(url, requestBody, String.class);
```

### RestClient
**Spring Framework 6.1**부터 도입된 `RestClient`는 더 현대적인 HTTP 클라이언트 API로 설계되었으며, 기존의 `RestTemplate`와 `WebClient`의 장점을 결합한 방식으로 동작합니다.

1. **동기식 API 지원**:
    - `RestTemplate`처럼 동기적으로 동작합니다.
    - 비동기 작업이 필요하면 `WebClient`를 사용하는 것이 적합합니다.
2. **간결하고 유연한 API**:
    - `RestTemplate`보다 직관적이고 간결한 방식으로 HTTP 요청을 작성할 수 있습니다.
3. **구성 가능**:
    - `RestClient.Builder`를 통해 요청 로깅, 기본 헤더, 타임아웃 등 다양한 설정을 추가할 수 있습니다.
4. **기반 구현**:
    - 내부적으로 `HttpComponents`와 같은 HTTP 클라이언트 라이브러리를 사용하여 더 나은 성능을 제공합니다.

```
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.web.client.RestClient;

@Configuration
public class RestClientConfig {

    @Bean
    public RestClient restClient() {
        return RestClient.builder()
                .baseUrl("https://api.example.com")
                .build();
    }
}
```

```
import org.springframework.stereotype.Service;
import org.springframework.web.client.RestClient;

@Service
public class MyService {

    private final RestClient restClient;

    public MyService(RestClient restClient) {
        this.restClient = restClient;
    }

    public String fetchData() {
        return restClient
                .get()
                .uri("/data")
                .retrieve()
                .body(String.class);
    }
}
```

## Spring MVC
**Spring MVC**는 **Spring Web** 모듈 내에서 웹 애플리케이션에서 **HTTP 요청을 처리하고 응답을 반환**하는 데 특화된 부분으로,  **모델-뷰-컨트롤러(MVC)** 아키텍처를 구현하는 **웹 프레임워크**입니다. **Spring MVC**는 웹 요청을 처리하고, 적절한 응답을 반환하는 과정을 효율적으로 관리하는 데 사용됩니다.

1. **Model**: 애플리케이션의 **데이터**와 관련된 부분을 담당합니다. 주로 데이터베이스와의 상호작용을 담당하는 객체들(예: 엔티티 클래스)로 구성됩니다.
2. **View**: **사용자에게 보여지는 화면**을 담당합니다. HTML, JSP, Thymeleaf 등 다양한 템플릿 엔진을 사용하여 동적 웹 페이지를 생성합니다.
3. **Controller**: **웹 요청을 처리**하는 부분입니다. 사용자가 보낸 HTTP 요청을 받아서, 필요한 로직을 수행하고, 결과를 **Model**에 전달하거나 **View**를 반환합니다.

**주요 컴포넌트**
1. **DispatcherServlet**: 모든 HTTP 요청을 중앙에서 처리하는 **프론트 컨트롤러**입니다. 사용자가 보낸 요청을 받아서 적절한 컨트롤러로 전달하고, 그 결과를 클라이언트에게 응답합니다.
2. **HandlerMapping**: **DispatcherServlet**이 요청을 처리할 적절한 **Controller**를 찾는 역할을 합니다. 요청 URL과 매핑된 메서드를 찾아 해당 메서드를 호출합니다.
3. **Controller**: **웹 요청을 처리**하는 핵심 컴포넌트입니다. **@Controller** 또는 **@RestController** 어노테이션을 사용하여 정의되며, 사용자의 요청을 받아 로직을 수행하고 결과를 반환합니다.
4. **ViewResolver**: **Model**과 **View**를 결합하여 최종적으로 사용자에게 보여줄 화면을 선택하는 역할을 합니다.

**흐름**
1. 사용자가 웹 애플리케이션에 HTTP 요청을 보냅니다.
2. **DispatcherServlet**이 요청을 받습니다.
3. **HandlerMapping**이 요청을 처리할 적절한 **Controller**를 찾습니다.
4. 해당 **Controller**가 요청을 처리하고, **Model**을 준비하여 **View**에 전달합니다.
5. **ViewResolver**가 적절한 **View**를 선택하여 **Model** 데이터를 화면에 렌더링합니다.
6. 최종적으로 사용자에게 **HTML** 등의 응답이 반환됩니다.

**Spring MVC**는 주로 **어노테이션**을 사용하여 동작합니다.

### `@Controller`
**컨트롤러 클래스**를 정의할 때 사용됩니다. 컨트롤러는 HTTP 요청을 처리하는 메서드를 포함하는 클래스입니다.

```
@Controller
public class UserController {
    // 요청을 처리하는 메서드들
}
```

### `@RequestMapping`
**HTTP 요청을 메서드에 매핑**하는 데 사용됩니다. 기본적으로 `@RequestMapping`은 모든 HTTP 메서드(GET, POST, PUT, DELETE 등)를 처리할 수 있지만, 더 구체적인 요청을 처리하려면 `@GetMapping`, `@PostMapping` 등을 사용할 수 있습니다.
    
```
@RequestMapping("/home")
public String home() {
    return "home";  // home.html 뷰를 반환
}
```
    
### `@GetMapping`, `@PostMapping`, `@PutMapping`,`@DeleteMapping`
`@RequestMapping`의 HTTP 메서드별 축약형 어노테이션입니다. `@GetMapping`은 GET 요청을 처리하고, `@PostMapping`은 POST 요청을 처리합니다.

```
@GetMapping("/user")
public String getUser() {
    return "user";  // user.html 뷰를 반환
}

@PostMapping("/user")
public String createUser(@RequestBody User user) {
    // 사용자 생성 로직
    return "redirect:/users";  // 사용자 목록 페이지로 리다이렉트
}
```
    
### `@PathVariable`
URL 경로에서 **변수**를 추출할 때 사용됩니다. 예를 들어, `/user/{id}`와 같은 경로에서 `{id}` 값을 추출할 수 있습니다.
    
```
@GetMapping("/user/{id}")
public String getUserById(@PathVariable("id") Long id) {
    // id에 해당하는 사용자 정보를 가져오는 로직
    return "user";  // user.html 뷰를 반환
}
```
    
### `@RequestParam`
**쿼리 파라미터**를 메서드 파라미터로 바인딩할 때 사용됩니다. 예를 들어, `/user?id=1`과 같은 요청에서 `id` 값을 추출할 수 있습니다.
    
```
@GetMapping("/user")
public String getUserByQuery(@RequestParam("id") Long id) {
    // id에 해당하는 사용자 정보를 가져오는 로직
    return "user";  // user.html 뷰를 반환
}
```
    
### `@ResponseBody`
메서드의 반환값을 **HTTP 응답 본문**에 직접 쓰도록 지정합니다. 주로 JSON 또는 XML 데이터를 반환할 때 사용됩니다.
    
```
@GetMapping("/user/{id}")
@ResponseBody
public User getUserById(@PathVariable("id") Long id) {
    return userService.getUserById(id);  // JSON으로 반환
}
```
    
### `@RestController`
`@Controller`와 `@ResponseBody`를 결합한 어노테이션입니다. RESTful 웹 서비스를 만들 때 사용되며, 메서드의 반환값이 **자동으로 HTTP 응답 본문에 작성**됩니다.
    
```
@RestController
public class UserRestController {
    @GetMapping("/users")
    public List<User> getAllUsers() {
        return userService.getAllUsers();  // JSON으로 반환
    }
}
```

## Spring WebSocket
**Spring WebSocket**은 **Spring Framework**에서 제공하는 기능으로, **웹 애플리케이션에서 실시간 양방향 통신**을 구현하는 데 사용됩니다. WebSocket은 클라이언트와 서버 간에 지속적인 연결을 유지하면서 데이터를 실시간으로 교환할 수 있게 해주는 프로토콜입니다. WebSocket을 사용하면 HTTP 요청-응답 방식으로는 구현하기 어려운 **실시간 채팅**, **알림 시스템**, **게임**, **주식 거래 시스템** 등 다양한 실시간 애플리케이션을 구현할 수 있습니다.

1. **양방향 통신**: WebSocket은 클라이언트와 서버 간에 연결이 열려 있는 상태에서 양방향으로 데이터를 주고받을 수 있습니다. HTTP는 클라이언트가 요청을 보내고 서버가 응답하는 방식인데, WebSocket은 서버도 클라이언트로 데이터를 보낼 수 있어 실시간 통신에 적합합니다.
2. **연결 지속성**: WebSocket은 클라이언트와 서버 간에 연결이 지속적으로 유지됩니다. HTTP 요청/응답 방식에서는 매번 연결을 새로 맺어야 하지만, WebSocket에서는 연결이 한 번 맺히면 계속해서 데이터를 주고받을 수 있습니다.
3. **낮은 지연 시간**: WebSocket은 연결이 유지되므로 데이터 전송 시 오버헤드가 적고, 빠른 실시간 통신이 가능합니다.

### `@EnableWebSocket`
Spring WebSocket을 활성화하는 데 사용됩니다. `@Configuration` 클래스에 붙여서 WebSocket 설정을 구성할 수 있게 해줍니다.
    
```
@Configuration
@EnableWebSocket
public class WebSocketConfig implements WebSocketConfigurer {
    @Override
    public void registerWebSocketHandlers(WebSocketHandlerRegistry registry) {
        registry.addHandler(webSocketHandler(), "/chat")
                .setAllowedOrigins("*");
    }

    public WebSocketHandler webSocketHandler() {
        return new MyWebSocketHandler();
    }
}
```
    
### `@MessageMapping`
**WebSocket** 메시지를 처리하는 메서드를 지정하는 어노테이션입니다. 클라이언트에서 보내는 메시지를 처리하고 응답을 보낼 메서드를 정의할 수 있습니다. 이 어노테이션은 Spring MVC의 `@RequestMapping`과 유사한 역할을 합니다.
- `@MessageMapping`: 클라이언트가 보낸 메시지를 처리하는 메서드를 지정합니다.
- `@SendTo`: 메시지를 클라이언트에게 전송할 경로를 지정합니다. 아래 예에서는 `"/topic/messages"`로 메시지를 전송합니다.
 
```
import org.springframework.messaging.handler.annotation.MessageMapping;
import org.springframework.messaging.handler.annotation.SendTo;

@Controller
public class ChatController {

    @MessageMapping("/chat")
    @SendTo("/topic/messages")
    public String sendMessage(String message) {
        return "Echo: " + message;
    }
}
```

### `@SubscribeMapping`
클라이언트가 특정 경로를 구독(subscribe)했을 때, 초기 메시지를 전송할 때 사용됩니다. 일반적으로 WebSocket 연결이 이루어진 후, 초기 데이터를 클라이언트에 보내는 데 사용됩니다.
    
```
@Controller
public class ChatController {

    @SubscribeMapping("/chat")
    public String sendInitialMessage() {
        return "Welcome to the chat!";
    }
}
```
    
### `@SendToUser`
특정 사용자에게만 메시지를 보내는 데 사용됩니다. 특정 사용자에게 메시지를 보내는 경우 유용합니다.
    
```
@Controller
public class ChatController {

    @MessageMapping("/chat")
    @SendToUser("/queue/messages")
    public String sendPrivateMessage(String message) {
        return "Private message: " + message;
    }
}
```

## Spring WebFlux
**Spring WebFlux**는 **Spring Framework**의 모듈 중 하나로, **비동기적이고 논블로킹(non-blocking)** 방식으로 웹 애플리케이션을 개발할 수 있게 해주는 프레임워크입니다. WebFlux는 주로 **리액티브 프로그래밍**을 기반으로 하며, 대규모 트래픽을 효율적으로 처리할 수 있는 애플리케이션을 만드는 데 유용합니다.

1. **비동기 처리 및 논블로킹 I/O**: WebFlux는 요청과 응답을 비동기적으로 처리합니다. 즉, 요청을 처리하는 동안 다른 요청을 동시에 처리할 수 있어, 대규모 트래픽을 효율적으로 처리할 수 있습니다.
2. **리액티브 프로그래밍 지원**: WebFlux는 **리액티브 프로그래밍**을 지원합니다. 리액티브 프로그래밍은 데이터 스트림을 다루는 방식으로, 데이터가 변경되거나 업데이트되면 그에 따라 반응하는 방식입니다.
    - Spring WebFlux는 **Project Reactor**를 기반으로 하며, `Mono`와 `Flux`라는 리액티브 타입을 사용합니다.
        - `Mono`: 0 또는 1개의 값을 반환하는 리액티브 타입
        - `Flux`: 0개 이상의 값을 반환하는 리액티브 타입
3. **서블릿 컨테이너와 독립적**: Spring WebFlux는 **서블릿 컨테이너**에 의존하지 않으며, **Netty**와 같은 비동기 서버에서도 동작할 수 있습니다. 또한 **Undertow**나 **Jetty**와 같은 서버도 사용할 수 있습니다.
4. **다양한 프로그래밍 모델 지원**: WebFlux는 **어노테이션 기반 프로그래밍**(Spring MVC 스타일)과 **함수형 프로그래밍**(Router 함수 스타일)을 모두 지원합니다. 이로 인해 개발자는 자신에게 편한 스타일로 애플리케이션을 개발할 수 있습니다.

**WebFlux vs Spring MVC**
- **Spring MVC**는 **동기적**이고 **블로킹** 방식으로 요청을 처리합니다. 즉, 요청을 처리하는 동안 다른 요청을 처리할 수 없으며, 요청을 처리하는 동안 다른 작업이 블로킹됩니다.
- **Spring WebFlux**는 **비동기적**이고 **논블로킹** 방식으로 요청을 처리합니다. 요청을 처리하는 동안 다른 요청을 동시에 처리할 수 있어 높은 성능을 요구하는 애플리케이션에 적합합니다.

### `@EnableWebFlux`
WebFlux를 활성화하는 어노테이션으로, Spring 설정 클래스에 붙여서 WebFlux를 사용할 수 있게 합니다.
    
```
@Configuration
@EnableWebFlux
public class WebConfig implements WebFluxConfigurer {
    // WebFlux 설정을 추가할 수 있습니다.
}
```
    
### `@RestController`
Spring MVC와 마찬가지로 WebFlux에서도 **@RestController**를 사용하여 RESTful 웹 서비스를 구현할 수 있습니다. WebFlux에서 `Mono`와 `Flux`를 반환할 수 있습니다.
    
```
@RestController
public class MyController {

    @GetMapping("/hello")
    public Mono<String> hello() {
        return Mono.just("Hello, WebFlux!");
    }
}
```
    
### `@RequestMapping`, `@GetMapping`, `@PostMapping`
WebFlux에서는 Spring MVC와 동일한 방식으로 HTTP 요청을 처리할 수 있습니다. 다만, 리액티브 타입인 `Mono`나 `Flux`를 반환하는 점이 다릅니다.
- **Flux**는 여러 값을 반환하는 리액티브 타입입니다.
- **Mono**는 하나의 값을 반환하는 리액티브 타입입니다.

```
@RestController
public class WebFluxController {
    @GetMapping("/flux")
    public Flux<String> getFlux() {
        return Flux.just("Hello", "World", "From", "WebFlux");
    }

    @GetMapping("/mono")
    public Mono<String> getMono() {
        return Mono.just("Hello, Mono!");
    }
}
```

## Transactional
### `@Transactional`
`@Transactional`은 **트랜잭션 관리를 자동으로 처리**하는 데 사용됩니다. 이 어노테이션을 메서드나 클래스에 적용하면, 해당 메서드나 클래스에서 실행되는 모든 DB 작업이 하나의 트랜잭션으로 묶여서 실행됩니다.

- **트랜잭션 시작**: 메서드가 실행되기 전에 트랜잭션이 시작됩니다.
- **트랜잭션 커밋**: 메서드가 성공적으로 완료되면 트랜잭션이 커밋됩니다.
- **트랜잭션 롤백**: 메서드 실행 중 예외가 발생하면 트랜잭션이 롤백됩니다.

#### 메서드 적용
트랜잭션이 메서드 단위로 관리됩니다.
    
```
@Service
public class UserService {

    @Autowired
    private UserRepository userRepository;

    @Transactional
    public void createUser(User user) {
        userRepository.save(user);
        // 예외가 발생하면 트랜잭션이 롤백됨
    }
}
```
    
#### 클래스 적용
클래스에 `@Transactional`을 적용하면 해당 클래스의 모든 메서드가 트랜잭션 내에서 실행됩니다.

```
@Service
@Transactional  // 클래스 내 모든 메서드가 트랜잭션으로 관리됨
public class UserService {

    @Autowired
    private UserRepository userRepository;

    public void createUser(User user) {
        userRepository.save(user);
        // 예외가 발생하면 트랜잭션이 롤백됨
    }

    public void updateUser(User user) {
        userRepository.save(user);
        // 예외가 발생하면 트랜잭션이 롤백됨
    }
}
```
    
#### 롤백 규칙 설정
예외가 발생했을 때 **롤백할 예외**를 지정할 수 있습니다.
    
```
@Transactional(rollbackFor = Exception.class)  // 모든 예외에 대해 롤백
public void createUser(User user) throws Exception {
    userRepository.save(user);
    if (someCondition) {
        throw new Exception("Something went wrong");
    }
}
```
    
#### 읽기 전용 트랜잭션
읽기 전용 트랜잭션을 설정하면, 트랜잭션이 데이터베이스에 변경을 가하지 않도록 최적화됩니다.
    
```
@Transactional(readOnly = true)
public User getUser(String userId) {
    return userRepository.findById(userId).orElse(null);
}
```

### `@Rollback`
`@Rollback`은 **Spring의 테스트에서 트랜잭션을 롤백**하는 데 사용되는 어노테이션입니다. 이 어노테이션은 주로 데이터베이스에 반영된 변경 사항을 테스트 후 자동으로 롤백하려는 경우에 사용됩니다. 이를 통해 테스트 중에 DB에 데이터를 저장하거나 수정하더라도, 테스트가 끝난 후에 그 변경 사항이 실제 데이터베이스에 반영되지 않도록 할 수 있습니다.

1.  **기본 동작**:
    - `@Rollback`은 기본적으로 `true`로 설정되어 있으며, 이 경우 **테스트가 끝난 후 트랜잭션을 자동으로 롤백**합니다. 즉, 데이터베이스에 저장된 데이터는 실제로 반영되지 않습니다.
2.  `@Rollback(false)`:
    - `@Rollback(false)`를 설정하면 **테스트 후에 트랜잭션을 커밋**하여 데이터베이스에 반영되도록 할 수 있습니다.

**롤백을 하는 경우**
```
@RunWith(SpringRunner.class)
@SpringBootTest
@Transactional  // 테스트 메서드가 끝난 후 자동으로 롤백
public class UserServiceTest {

    @Autowired
    private UserRepository userRepository;

    @Test
    public void testSaveUser() {
        User user = new User("Alice", "alice@example.com");
        userRepository.save(user);
        // 테스트가 끝나면 이 변경 사항은 DB에 반영되지 않음
    }
}
```

위 예시에서 `@Transactional`을 사용하면, **테스트가 끝난 후 트랜잭션이 롤백**되어 데이터베이스에 반영되지 않습니다. 이때 `@Rollback(true)`는 기본값이므로 명시하지 않아도 롤백됩니다.

**롤백을 하지 않는 경우**
```
@RunWith(SpringRunner.class)
@SpringBootTest
@Transactional
@Rollback(false)  // 테스트 후 변경 사항을 DB에 반영
public class UserServiceTest {

    @Autowired
    private UserRepository userRepository;

    @Test
    public void testSaveUser() {
        User user = new User("Alice", "alice@example.com");
        userRepository.save(user);
        // 테스트가 끝난 후 이 변경 사항은 DB에 반영됨
    }
}
```

위 예시에서는 `@Rollback(false)`를 사용하여 **테스트 후에도 데이터베이스에 변경 사항이 반영되도록** 설정합니다.

## Validation 
### 검증 어노테이션
검증 어노테이션은 Java Bean Validation API (`javax.validation`)에서 제공하는 어노테이션으로, 객체의 필드에 적용하여 해당 필드의 값이 특정 조건을 만족하는지 자동으로 검사할 수 있게 해줍니다. Spring에서는 이를 통해 요청 데이터가 올바른지 검증할 수 있습니다.

- `@NotNull`: 값이 `null`이 아니어야 함.
- `@NotBlank`: 값이 `null`이 아니고, 빈 문자열도 허용하지 않음.
- `@Size`: 문자열, 배열, 컬렉션 등의 크기 범위를 지정.
- `@Min` / `@Max`: 숫자의 최소값/최대값을 지정.
- `@Email`: 이메일 형식이 유효한지 검증.
- `@Pattern`: 정규식을 사용하여 문자열이 특정 패턴을 따르는지 검증.
- `@Past` / `@Future`: 날짜가 과거/미래인지 검증.

```
import javax.validation.constraints.*;

public class User {

    @NotBlank(message = "Username is required")
    private String userId;

    @NotNull(message = "Password is required")
    @Size(min = 8, message = "Password must be at least 8 characters long")
    private String password;

    @Email(message = "Email should be valid")
    @NotBlank(message = "Email is required")
    private String email;

    // Getters and Setters
}
```

검증 어노테이션이 적용된 필드에 잘못된 데이터가 들어오면, Spring은 자동으로 검증을 수행하고, 검증에 실패한 필드에 대해 오류를 발생시킵니다. 이 오류는 `MethodArgumentNotValidException`을 발생시키며, 이를 통해 클라이언트에게 적절한 오류 메시지를 전달할 수 있습니다.

### 커스텀 검증 어노테이션
커스텀 검증 어노테이션은 기존의 Java Bean Validation 어노테이션으로는 처리할 수 없는 복잡한 검증 로직을 구현할 때 사용합니다. 커스텀 어노테이션을 만들어서, 특정 조건을 만족하는지 검증할 수 있습니다.

1.  **커스텀 어노테이션 정의**: `@Constraint` 어노테이션을 사용하여 커스텀 어노테이션을 정의합니다.
2.  **검증 로직 구현**: `ConstraintValidator` 인터페이스를 구현하여 검증 로직을 작성합니다.

**커스텀 어노테이션 정의**:
```
import javax.validation.Constraint;
import javax.validation.Payload;
import java.lang.annotation.ElementType;
import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;
import java.lang.annotation.Target;

@Constraint(validatedBy = PasswordComplexityValidator.class)
@Target({ ElementType.FIELD, ElementType.METHOD, ElementType.PARAMETER })
@Retention(RetentionPolicy.RUNTIME)
public @interface PasswordComplexity {
    String message() default "Password must contain at least one number and one special character";
    Class<?>[] groups() default {};
    Class<? extends Payload>[] payload() default {};
}
```
- `@Constraint(validatedBy = ...)`:  **어떤 Validator 클래스**가 이 어노테이션을 처리할 것인지를 지정합니다.
- `@Target`: 어노테이션이 **적용될 수 있는 위치**를 지정합니다.
    - `ElementType.FIELD`: 필드에 적용 가능.
    - `ElementType.METHOD`: 메서드에 적용 가능.
    - `ElementType.PARAMETER`: 메서드 매개변수에 적용 가능.
- `@Retention`: 어노테이션이 **어느 시점까지 유지될지**를 지정합니다.
    - `RetentionPolicy.RUNTIME`: 런타임까지 유지되어 리플렉션으로 접근할 수 있음.
- `message`: 검증이 실패했을 때 반환할 기본 오류 메시지를 정의합니다. 이 메시지는 `@Valid`를 사용하는 컨트롤러에서 자동으로 처리되거나, 사용자 정의 메시지로 대체할 수 있습니다.
- `groups`: 검증 그룹을 정의합니다. 특정 상황에서만 검증을 수행하고 싶을 때 그룹을 활용할 수 있습니다.

**검증 로직 구현**:
```
import javax.validation.ConstraintValidator;
import javax.validation.ConstraintValidatorContext;

// 이 클래스는 `ConstraintValidator` 인터페이스를 구현합니다.
// 첫 번째 타입은 검증 대상 어노테이션 (`PasswordComplexity`)입니다.
// 두 번째 타입은 검증할 데이터 타입 (`String`)입니다.
public class PasswordComplexityValidator implements ConstraintValidator<PasswordComplexity, String> {

    @Override
    public void initialize(PasswordComplexity constraintAnnotation) {
	    // 검증 클래스 초기화 메서드입니다.
	    // 어노테이션에서 추가적인 속성을 받을 경우 이 메서드에서 처리할 수 있습니다.
    }

    @Override
    public boolean isValid(String password, ConstraintValidatorContext context) {
		// 검증 로직을 구현하는 핵심 메서드로, 항상 정의되어야 합니다.
		// 입력 값 (`password`)과 검증 컨텍스트 (`context`)를 인수로 받습니다.
		// 검증 조건을 만족하면 `true`, 그렇지 않으면 `false`를 반환합니다.
		
        if (password == null) {
            return false;
        }

        boolean hasNumber = false;
        boolean hasSpecialChar = false;

        for (char c : password.toCharArray()) {
            if (Character.isDigit(c)) {
                hasNumber = true;
            } else if (!Character.isLetterOrDigit(c)) {
                hasSpecialChar = true;
            }
        }

        return hasNumber && hasSpecialChar;
    }
}
```

**사용 예시**:
```
public class User {

    @PasswordComplexity(message = "Password must contain at least one number and one special character")
    private String password;

    // Getters and Setters
}
```

## Security
### `PasswordEncoder`
`PasswordEncoder`는 비밀번호를 암호화하고 검증하는 메서드를 정의한 **인터페이스**입니다. 이 인터페이스는 비밀번호를 해시화하고, 나중에 해시된 비밀번호와 입력된 비밀번호를 비교하는 기능을 제공합니다.

- `encode(CharSequence rawPassword)`: 주어진 평문 비밀번호를 해시화하여 암호화된 비밀번호를 반환합니다.
- `matches(CharSequence rawPassword, String encodedPassword)`: 입력된 평문 비밀번호(`rawPassword`)와 이미 암호화된 비밀번호(`encodedPassword`)를 비교하여 일치하는지 여부를 반환합니다.

### `BCryptPasswordEncoder`
`BCryptPasswordEncoder`는 `PasswordEncoder` 인터페이스의 구현체로, **BCrypt 해시 함수**를 사용하여 비밀번호를 암호화합니다. BCrypt는 비밀번호 해시화에 사용되는 매우 안전한 알고리즘으로, **Salt**를 자동으로 생성하고, 여러 번의 해시 연산을 통해 비밀번호를 암호화합니다.

- **Salt 자동 생성**: BCrypt는 비밀번호를 해시화할 때 자동으로 Salt를 생성하고 이를 해시 값에 포함시킵니다.
- **비밀번호 검증**: `BCryptPasswordEncoder`는 입력된 비밀번호와 암호화된 비밀번호를 비교할 때, Salt를 포함하여 검증합니다.
- **비용 인자**: 비용 인자는 **2의 거듭제곱**으로 계산되는 반복 횟수를 결정합니다. 기본 값은 `10`입니다. (예: 비용 인자가 10이면 2^10^번의 해시 연산을 수행합니다.) 해시 연산 횟수는 `BCryptPasswordEncoder`의 생성자에서 설정할 수 있습니다. 비용 인자는 최소 4, 최대 31까지 설정할 수 있으며, 비용 값이 커질수록 해시 연산이 더 많이 수행되므로 보안성이 높아지지만, 성능에 영향을 미칠 수 있습니다.

```
import org.springframework.security.crypto.bcrypt.BCryptPasswordEncoder;
import org.springframework.security.crypto.password.PasswordEncoder;

public class PasswordExample {
    public static void main(String[] args) {
        // PasswordEncoder 인터페이스 사용
        PasswordEncoder encoder = new BCryptPasswordEncoder();

        // 비밀번호 암호화
        String rawPassword = "password123";
        String encodedPassword = encoder.encode(rawPassword);
        System.out.println("Encoded Password: " + encodedPassword);

        // 비밀번호 검증
        boolean matches = encoder.matches(rawPassword, encodedPassword);
        System.out.println("Password matches: " + matches);
    }
}
```

**출력 예시:**
```
Encoded Password: $2a$10$E9Jd0ZyxHnQ2E8Fzv7IY7.Ws5lWhJ8wWgJwPsb6i9XhX5OqgxqL.q
Password matches: true
```

`BCrypt`를 사용하면 생성되는 해시 값의 길이는 **고정된 길이**입니다. `BCrypt`에서 생성된 해시 값은 항상 **60자**입니다. 해시 값의 길이는 알고리즘 자체에 의해 결정되며, 사용자가 설정을 통해 이 길이를 바꿀 수는 없습니다.

### ~~WebSecurityConfigurerAdapter~~
> Spring Security 5.0 이후로는 더 이상`SecurityConfigurerAdapter`, `WebSecurityConfigurerAdapter`를 사용하지 않습니다.

`WebSecurityConfigurerAdapter`는 Spring Security에서 제공하는 추상 클래스입니다. 이 클래스를 확장하여 애플리케이션의 보안 설정을 커스터마이즈할 수 있습니다. 이 클래스는 보안 관련 설정을 쉽게 정의할 수 있도록 여러 가지 기본 메서드를 제공합니다.

### `@EnableWebSecurity`
`@EnableWebSecurity`는 Spring Security를 애플리케이션에 활성화하는 어노테이션입니다. 이 어노테이션을 사용하면 Spring Security의 기본 보안 기능을 활성화합니다. `@EnableWebSecurity`는 주로 Spring Boot 애플리케이션에서 사용되며, 보안 설정을 전역적으로 적용할 수 있도록 합니다.

### SecurityFilterChain
`SecurityFilterChain`은 Spring Security에서 보안 필터 체인을 구성하는 새로운 방식입니다. Spring Security 5.x 이상에서는 `SecurityFilterChain`을 사용하여 보안 설정을 정의하고, HTTP 요청에 대한 보안 필터 체인을 설정합니다.

- **보안 필터 체인 설정**: `SecurityFilterChain`은 HTTP 요청에 대한 보안 필터 체인을 설정하는 방법입니다. 이를 통해 요청을 처리할 때 어떤 보안 필터를 적용할지 정의합니다.
- **HttpSecurity를 통한 설정**: `SecurityFilterChain`은 `HttpSecurity`를 통해 보안 설정을 구성합니다.
- **구성 요소**: `SecurityFilterChain`은 요청에 대한 인증, 권한 부여, 로그인, 로그아웃 등을 설정하는 데 사용됩니다.

```
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.security.config.annotation.web.builders.HttpSecurity;
import org.springframework.security.config.annotation.web.configuration.EnableWebSecurity;
import org.springframework.security.web.SecurityFilterChain;

@Configuration
@EnableWebSecurity
public class SecurityConfig {

    @Bean
    public SecurityFilterChain securityFilterChain(HttpSecurity http) throws Exception {
        // 보안 관련 설정
        return http.build();
    }
}
```

### HttpSecurity
`HttpSecurity`는 Spring Security에서 웹 애플리케이션의 HTTP 보안을 설정하는 데 사용되는 클래스입니다. 이 클래스는 애플리케이션의 HTTP 요청에 대해 인증, 권한 부여, 세션 관리, CSRF 보호 등 다양한 보안 설정을 할 수 있도록 도와줍니다.

`HttpSecurity`를 사용하면 웹 애플리케이션에 대한 보안 설정을 다음과 같은 방식으로 구성할 수 있습니다:
1. **인증 설정**: 로그인 페이지, 로그인 성공 후 리디렉션 URL 등을 설정합니다.
    -   예: `formLogin()`, `loginPage()`, `loginProcessingUrl()`
2. **권한 설정**: URL 패턴에 대한 접근 권한을 설정합니다.
    -   예: `authorizeHttpRequests()`, `antMatchers()`, `permitAll()`, `authenticated()`
3. **세션 관리**: 세션 고정 보호, 세션 타임아웃 등을 설정합니다.
    -   예: `sessionManagement()`, `invalidSessionUrl()`, `maximumSessions()`
4. **CSRF 보호**: Cross-Site Request Forgery(CSRF) 공격을 방지하는 설정입니다.
    -   예: `csrf()`
5. **로그인 및 로그아웃 설정**: 로그인 폼, 로그아웃 URL 등을 설정합니다.
    -   예: `formLogin()`, `logout()`
6. **기타 보안 설정**: CORS, 헤더 설정 등 다양한 보안 관련 설정을 지원합니다.
    -   예: `cors()`, `headers()`

```
@Configuration
@EnableWebSecurity
public class SecurityConfig {

    @Autowired
    private UserService userService;

    @Autowired
    private PasswordEncoder passwordEncoder;

    @Bean
    public SecurityFilterChain securityFilterChain(HttpSecurity http) throws Exception {
        http
            .authorizeHttpRequests(authorizeRequests ->
                authorizeRequests
                    .antMatchers("/login", "/register").permitAll()  // 로그인, 회원가입은 누구나 접근 가능
                    .anyRequest().authenticated()  // 나머지 요청은 인증된 사용자만 접근 가능
            )
            .formLogin(formLogin ->
                formLogin
                    .loginPage("/login")  // 커스텀 로그인 페이지
                    .permitAll()  // 로그인 페이지 접근은 누구나 가능
            )
            .logout(logout ->
                logout
                    .permitAll()  // 로그아웃은 누구나 가능
            );
        return http.build();
    }
}
```

- `authorizeHttpRequests()`: HTTP 요청에 대한 권한을 설정합니다. 특정 URL에 대한 접근 권한을 설정할 수 있습니다.
- `formLogin()`: 폼 기반 로그인 설정을 합니다. 로그인 페이지, 로그인 성공 후 리디렉션 URL 등을 설정할 수 있습니다.
- `logout()`: 로그아웃 설정을 합니다. 로그아웃 후 리디렉션 URL 등을 설정할 수 있습니다.
- `csrf()`: CSRF 보호 설정을 합니다. 기본적으로 Spring Security는 CSRF 보호를 활성화합니다.
- `sessionManagement()`: 세션 관리 설정을 합니다. 세션 타임아웃, 세션 고정 보호 등을 설정할 수 있습니다.
- `httpBasic()`: HTTP 기본 인증을 활성화합니다.
- `headers()`: HTTP 헤더를 설정합니다. 보안 헤더를 추가하거나 수정할 수 있습니다.

#### `authorizeHttpRequests()`
`authorizeHttpRequests()`는 HTTP 요청에 대한 권한을 설정하는 새로운 방식입니다. Spring Security 6.x에서는 `authorizeRequests()` 대신 `authorizeHttpRequests()`를 사용하여 권한 설정을 해야 합니다. 또한 기존 방식인 메서드 체인 방식이 아닌 람다식을 통한 함수형을 사용해야 합니다.

※ `authorizeRequests()`는 Spring Security 5.x와 그 이전 버전에서 사용되던 메서드로, 더 이상 사용하지 않습니다.

#### `formLogin()`
`formLogin()`은 **Spring Security**에서 제공하는 메서드로, **폼 기반 로그인**을 설정하는 데 사용됩니다. 이 메서드를 사용하면, 사용자가 웹 애플리케이션에 로그인할 수 있도록 폼 기반 로그인 페이지를 자동으로 설정할 수 있습니다. 로그인 폼을 구현하고, 사용자가 로그인 정보를 제출하면, 이를 처리하는 기본적인 기능을 Spring Security가 제공해 줍니다.

1. **로그인 페이지 설정**:
    - 기본적으로 `/login` URL이 로그인 페이지로 사용됩니다. 이 URL을 사용자가 방문하면 로그인 폼을 보여주고, 사용자가 로그인 정보를 제출하면 이를 처리합니다.
    - 로그인 페이지는 **커스터마이징**할 수 있으며, `loginPage()` 메서드를 사용하여 다른 URL로 로그인 페이지를 지정할 수 있습니다.
2. **로그인 성공 및 실패 처리**:
    - 로그인 성공 후 리디렉션할 URL을 `defaultSuccessUrl()`로 설정할 수 있습니다.
    - 로그인 실패 시 리디렉션할 URL을 `failureUrl()`로 설정할 수 있습니다.
3. **사용자 인증 처리**:
    - 로그인 폼에서 제출된 **아이디**와 **비밀번호**를 사용하여 인증을 수행합니다. 이 정보는 Spring Security가 자동으로 처리하며, 로그인 성공 시 사용자는 인증된 상태로 애플리케이션을 사용할 수 있습니다.
4. **폼 기반 로그인 커스터마이징**:
    - 로그인 페이지의 URL, 로그인 성공 및 실패 시 리디렉션 URL 등을 설정할 수 있습니다.
    - 기본적으로 Spring Security는 `username`과 `password`라는 필드명을 가진 로그인 폼을 기대합니다. 하지만 이를 커스터마이징하여 다른 이름의 필드를 사용할 수도 있습니다.

```
.formLogin(formLogin -> 
    formLogin
        .loginPage("/login")  // 로그인 페이지 경로
        .loginProcessingUrl("/login")  // 로그인 폼 제출 URL
        .defaultSuccessUrl("/home", true)  // 로그인 성공 후 리디렉션할 URL
        .failureUrl("/login?error=true")  // 로그인 실패 후 리디렉션할 URL
        .permitAll()  // 로그인 페이지는 누구나 접근 가능
)
```

- `loginPage(String loginPage)`: 로그인 페이지의 URL을 지정합니다. 기본값은 `/login`입니다. 이 URL을 사용자가 방문하면 로그인 폼을 표시합니다.
- `loginProcessingUrl(String loginProcessingUrl)`: 로그인 폼에서 제출된 데이터를 처리할 URL을 설정합니다. 기본적으로 `/login` URL로 POST 요청을 보내면 Spring Security가 자동으로 처리합니다.
- `defaultSuccessUrl(String defaultSuccessUrl)`: 로그인 성공 후 리디렉션할 URL을 설정합니다. `true`를 설정하면 로그인 후 항상 해당 URL로 리디렉션됩니다.
- `failureUrl(String failureUrl)`: 로그인 실패 시 리디렉션할 URL을 설정합니다. 예를 들어, 로그인 실패 후 에러 메시지를 표시할 수 있는 페이지로 리디렉션할 수 있습니다.
- `permitAll()`: 인증 여부와 관계없이 누구나 접근할 수 있도록 허용합니다.

formLogin은 기본적으로 세션 기반 인증을 사용합니다. RESTful API를 설계할 때는 formLogin 대신 토큰 기반 인증 방식을 사용하는 것이 일반적입니다.

#### `logout()`
`logout()`은 애플리케이션에서 **로그아웃 기능**을 설정하는 데 사용됩니다. 이 메서드는 사용자가 로그아웃할 때 처리해야 할 여러 작업을 자동으로 수행합니다. `logout()`을 설정하면 사용자가 로그아웃할 때 발생하는 보안 관련 작업들을 간편하게 처리할 수 있습니다.

1. **세션 종료**:
    - 사용자가 로그아웃하면 **세션**이 종료됩니다. Spring Security는 자동으로 사용자의 세션을 무효화하고, 로그인 상태를 제거합니다.
2. **Authentication 객체 제거**:
    - 로그아웃 시 `SecurityContext`에서 사용자의 인증 정보를 제거합니다. 즉, `SecurityContextHolder.clearContext()`가 호출되어 현재 인증된 사용자의 정보를 삭제합니다.
3. **쿠키 제거**:
    - 로그인 시 생성된 **JSESSIONID** 쿠키와 같은 세션 관련 쿠키가 자동으로 삭제됩니다.
4. **로그아웃 성공 후 리디렉션**:
    - 로그아웃 후 사용자를 특정 URL로 리디렉션할 수 있습니다. 예를 들어, 로그아웃 후 홈페이지나 로그인 페이지로 리디렉션할 수 있습니다.
5. **로그아웃 성공/실패 처리**:
    - 로그아웃이 성공적으로 처리되었을 때, 이를 처리하는 후속 작업을 지정할 수 있습니다. 예를 들어, 로그아웃 후 사용자에게 알림 메시지를 표시할 수 있습니다.

**로그아웃의 흐름**
1.  사용자가 `/logout` URL에 접근하면, Spring Security는 해당 요청을 처리하고 로그아웃을 수행합니다.
2.  로그아웃 후 **세션이 종료**되고, **인증 정보가 삭제**됩니다.
3.  로그아웃 후, `logoutSuccessUrl`에 설정된 URL로 리디렉션됩니다.

```
.logout(logout -> 
    logout
        .logoutUrl("/logout")  // 로그아웃 URL을 "/logout"로 설정
        .logoutSuccessUrl("/login?logout")  // 로그아웃 후 "/login?logout"으로 리디렉션
        .permitAll()  // 로그아웃 URL에 누구나 접근 가능
);
```

- `logoutUrl(String logoutUrl)`: 로그아웃을 처리할 URL을 지정합니다. 기본값은 `/logout`입니다. 사용자가 이 URL을 호출하면 로그아웃이 처리됩니다.
- `logoutSuccessUrl(String logoutSuccessUrl)`: 로그아웃이 성공적으로 처리된 후 리디렉션할 URL을 지정합니다.
- `deleteCookies(String... cookies)`: 로그아웃 시 삭제할 쿠키를 지정합니다.
- `invalidateHttpSession(boolean invalidateHttpSession)`: 로그아웃 시 HTTP 세션을 무효화할지 여부를 설정합니다. 기본값은 `true`로, 로그아웃 시 세션이 무효화됩니다.
- `permitAll()`: 인증 여부와 관계없이 누구나 접근할 수 있도록 허용합니다.

`formLogin`과 마찬가지로 Spring Security에서 기본적으로 세션 기반으로 동작합니다.

#### `requestMatchers()`
`requestMatchers()`는 특정 URL 패턴에 대해 접근 권한을 설정하는 메서드입니다. URL 패턴을 지정하여, 해당 패턴에 맞는 요청에 대해 **인증 및 권한**을 설정할 수 있습니다.

```
.requestMatchers("/login", "/register").permitAll()  // /login, /register 경로는 누구나 접근 가능
```

※ `antMatchers`는 **Spring Security 5.x 이하**에서 사용되었으며, **Spring Security 5.x 이상**에서는 `requestMatchers`로 대체되었습니다. (기능은 동일하나, 더 유연하고 직관적인 방식이 적용되었습니다.)

#### `anyRequest()`
`anyRequest()`는 **모든 요청**에 대해 접근 권한을 설정하는 메서드입니다. 이 메서드는 특정 URL 패턴에 대한 설정 외에 **모든 요청에 대한 권한**을 설정할 때 사용됩니다.

```
.anyRequest().authenticated();  // 나머지 모든 요청은 인증된 사용자만 접근 가능
```

#### `authenticated()`
`authenticated()`는 **인증된 사용자**만 해당 요청에 접근할 수 있도록 설정하는 메서드입니다.

`authenticated()`는 보통 `anyRequest()`와 함께 사용되어, 모든 요청에 대해 인증된 사용자만 접근할 수 있도록 설정합니다.

#### `hasRole()`
`hasRole()`은 특정 **역할(role)**을 가진 사용자만 해당 URL에 접근할 수 있도록 설정하는 데 사용됩니다.

```
.antMatchers("/admin/**").hasRole("ADMIN")  // ADMIN 역할을 가진 사용자만 /admin/** 경로에 접근 가능
```

역할 이름 앞에 `ROLE_`이 자동으로 붙습니다. 예를 들어, `hasRole("ADMIN")`은 실제로 `ROLE_ADMIN`이라는 역할을 가진 사용자만 접근할 수 있게 설정하는 것입니다.

#### `hasAuthority()`
`hasAuthority()`는 특정 **권한(authority)**을 가진 사용자만 해당 URL에 접근할 수 있도록 설정하는 데 사용됩니다.

```
.antMatchers("/admin/**").hasAuthority("ADMIN_PRIVILEGE")  // "ADMIN_PRIVILEGE" 권한을 가진 사용자만 /admin/** 경로에 접근 가능
```

`hasRole()`과 달리, `hasAuthority()`에서 사용되는 권한은 `ROLE_` 접두어 없이 저장됩니다.

### SecurityContext
`SecurityContext`는 **Spring Security**에서 사용자의 인증 정보를 저장하고 관리하는 컨테이너입니다. 이 객체는 현재 실행 중인 스레드에 대한 인증 상태를 추적하며, 보안 관련 작업을 수행할 때 사용됩니다.

1. **인증 정보 저장**: `SecurityContext`는 사용자가 인증되었을 때, 인증 정보를 저장합니다. 예를 들어, 사용자가 로그인하면, 그 사용자의 `Authentication` 객체가 `SecurityContext`에 저장됩니다.
2. **인증 정보 제공**: 애플리케이션에서 요청을 처리하는 동안, `SecurityContext`에 저장된 `Authentication` 객체를 통해 현재 인증된 사용자의 정보를 가져올 수 있습니다. 이를 통해 사용자가 어떤 권한을 가지고 있는지 확인하거나, 인증 정보를 기반으로 액세스를 제어할 수 있습니다.
3. **스레드 로컬(ThreadLocal)**: `SecurityContext`는 기본적으로 **스레드 로컬**(ThreadLocal)을 사용하여 각 요청마다 독립적인 인증 정보를 저장합니다. 이는 멀티스레드 환경에서 각 요청이 서로 다른 인증 정보를 갖도록 보장합니다.

Spring Security는 보통 요청을 처리하는 동안, 보안 필터에서 `SecurityContext`를 설정합니다. 예를 들어, JWT 인증을 처리하는 필터에서 JWT 토큰을 검증하고, 인증된 사용자의 정보를 `SecurityContext`에 설정합니다.

`SecurityContext`에 인증 정보가 설정되지 않으면, Spring Security는 해당 요청을 인증되지 않은 사용자로 간주하고, 권한이 없는 페이지에 접근하려는 경우 403 Forbidden을 발생시킵니다.

### SecurityContextHolder
`SecurityContextHolder`는 현재 스레드에 대한 `SecurityContext`를 저장하고 관리하는 클래스입니다. `SecurityContextHolder`는 하나의 `SecurityContext`만을 저장합니다.

- `getContext()`: `SecurityContext`를 가져옵니다.
- `setContext()`: `SecurityContext`를 설정합니다.

```
Authentication authentication = SecurityContextHolder.getContext().getAuthentication();
String username = authentication.getName();  // 인증된 사용자의 이름
Collection<? extends GrantedAuthority> authorities = authentication.getAuthorities();  // 권한 정보
```

### Authentication
`Authentication` 인터페이스는 **사용자 인증 정보**를 나타냅니다. Spring Security의 인증 과정에서 사용자의 자격 증명을 포함하고 있는 객체입니다. 이 객체는 사용자가 제공한 자격 증명이 유효한지 확인하는 데 사용됩니다.

- **인증된 사용자 정보**: `Authentication` 객체는 사용자의 이름, 비밀번호, 권한(roles) 등의 인증 정보를 포함합니다.
- **권한(Authorities)**: 사용자가 가진 권한(roles)을 포함할 수 있습니다.

**프로퍼티**: 
- `Principal`: 인증된 사용자의 기본 정보(예: 사용자 이름).
- `Credentials`: 사용자가 제공한 자격 증명(예: 비밀번호).

**메서드**:
- `getPrincipal()`: 인증된 사용자의 기본 정보(보통 `UserDetails` 객체)를 반환합니다.
- `getCredentials()`: 사용자가 제공한 자격 증명(예: 비밀번호)을 반환합니다.
- `getAuthorities()`: 사용자의 권한 목록을 반환합니다.
- `isAuthenticated()`: 인증 여부를 반환합니다.

```
Authentication authentication = SecurityContextHolder.getContext().getAuthentication();
String username = (String) authentication.getPrincipal();
Collection<? extends GrantedAuthority> authorities = authentication.getAuthorities();
```

위 예시에서는 `SecurityContextHolder`를 통해 현재 인증된 사용자의 `Authentication` 객체를 가져오고, 사용자의 이름과 권한을 추출합니다.

### User
`User` 객체는 보통 사용자 정보를 포함하는 **VO(Value Object)**로 사용되며, Spring Security에서는 `UserDetails` 인터페이스를 구현하여 인증 및 권한 관련 기능을 제공합니다.

- 사용자 이름 (`username`): 사용자의 고유 식별자입니다. 로그인 시 사용됩니다.
- 비밀번호 (`password`): 사용자의 비밀번호입니다.
- 권한 (`authorities`): 사용자가 가진 권한 목록입니다. 예를 들어, `ROLE_USER`, `ROLE_ADMIN` 등의 권한이 포함됩니다.

### UserDetails
`UserDetails` 인터페이스는 **사용자에 대한 상세 정보**를 제공하는 객체입니다. `UserDetails`는 `Authentication` 객체에서 `Principal`로 사용되는 객체이며, 인증된 사용자의 정보를 표현하는 데 사용됩니다.

- **사용자 정보 제공**: `UserDetails`는 사용자 이름, 비밀번호, 권한(roles) 등 사용자의 상세 정보를 제공합니다.
- **사용자 정의**: `UserDetails`는 구현체가 필요하며, 보통 사용자 정보를 저장하는 클래스가 이를 구현합니다. 예를 들어, `User` 클래스를 구현하여 사용자 정보를 담을 수 있습니다.
- **권한 관리**: `UserDetails`는 사용자가 가진 권한을 `GrantedAuthority` 객체의 목록으로 반환합니다.

**메서드**:
- `getUsername()`: 사용자의 이름을 반환합니다.
- `getPassword()`: 사용자의 비밀번호를 반환합니다.
- `getAuthorities()`: 사용자의 권한 목록을 반환합니다.
- `isAccountNonExpired()`, `isAccountNonLocked()`, `isCredentialsNonExpired()`, `isEnabled()`: 사용자의 계정 상태를 확인합니다.

### UsernamePasswordAuthenticationToken
`UsernamePasswordAuthenticationToken`은 **인증 정보**를 나타내는 클래스입니다. 사용자가 로그인할 때 입력한 사용자 이름과 비밀번호를 기반으로 인증을 시도하는 데 사용됩니다.

- **인증 정보 객체**: 이 클래스는 사용자 이름(username)과 비밀번호(password)와 같은 인증 정보를 캡슐화합니다.
- **Authentication 인터페이스 구현**: `UsernamePasswordAuthenticationToken`은 `Authentication` 인터페이스를 구현하므로, Spring Security의 인증 시스템에서 인증 요청을 표현하는 데 사용됩니다.
- **인증 요청에 사용**: 사용자가 로그인할 때 입력한 정보를 담고 있으며, 이 객체는 `AuthenticationManager`를 통해 인증 프로세스를 시작하는 데 사용됩니다.

```
UsernamePasswordAuthenticationToken authenticationToken = 
    new UsernamePasswordAuthenticationToken(username, password);
```

이 객체는 `AuthenticationManager`에 의해 처리되며, 사용자가 제공한 자격 증명이 올바른지 확인합니다.

### UsernamePasswordAuthenticationFilter
`UsernamePasswordAuthenticationFilter`는 **사용자 인증을 처리하는 필터**입니다. 주로 사용자가 로그인할 때 HTTP 요청에서 사용자 이름과 비밀번호를 추출하고, 이를 `UsernamePasswordAuthenticationToken`으로 변환하여 인증을 처리합니다.

- **HTTP 요청 처리**: `UsernamePasswordAuthenticationFilter`는 HTTP 요청에서 사용자의 자격 증명(사용자 이름, 비밀번호)을 추출하여 인증을 처리합니다.
- **인증 필터**: 이 필터는 인증 요청을 처리하며, `AuthenticationManager`에 인증을 위임합니다.
- **POST 요청 처리**: 기본적으로 이 필터는 `/login` 경로로 오는 POST 요청을 처리하며, 요청 본문에서 사용자 이름과 비밀번호를 추출합니다.
- **인증 처리**: 인증이 성공하면 `SecurityContextHolder`에 인증된 사용자 정보를 설정하고, 이후 요청에서 인증된 사용자로 처리됩니다.

`Authentication`과 `UserDetails`는 **Spring Security**에서 인증 및 권한 부여(Authorization) 관련 작업을 수행하는 핵심 인터페이스입니다. 이 두 인터페이스는 인증된 사용자의 정보를 관리하고, 인증 과정에서 중요한 역할을 합니다.

## Exception
### `@ControllerAdvice`
`@ControllerAdvice`는 **Spring Framework**에서 제공하는 **애플리케이션 전역에서 발생하는 예외를 처리하기 위한 어노테이션**입니다. 이를 사용하면 여러 컨트롤러에서 발생할 수 있는 예외들을 중앙에서 처리할 수 있게 되어, 코드의 중복을 줄이고, 예외 처리를 일관되게 할 수 있습니다.

- **전역 예외 처리**: 애플리케이션 내 모든 컨트롤러에서 발생하는 예외를 한 곳에서 처리할 수 있습니다.
- **모든 컨트롤러에 적용**: 특정 컨트롤러나 메서드에만 적용되는 것이 아니라, 모든 컨트롤러에 적용되어 전역적으로 예외를 처리합니다.
- **모든 종류의 예외 처리**: 특정 예외뿐만 아니라, `Exception`을 사용하여 예기치 못한 예외도 처리할 수 있습니다.

#### 전역 예외 처리
```
@ControllerAdvice
public class GlobalExceptionHandler {

    // 특정 예외 처리
    @ExceptionHandler(ServiceException.class)
    public ResponseEntity<String> handleServiceException(ServiceException e) {
        return ResponseEntity.status(HttpStatus.BAD_REQUEST).body("서비스 오류가 발생했습니다.");
    }

    // 모든 예외 처리
    @ExceptionHandler(Exception.class)
    public ResponseEntity<String> handleException(Exception e) {
        return ResponseEntity.status(HttpStatus.INTERNAL_SERVER_ERROR).body("서버 오류가 발생했습니다.");
    }
}
```

#### 모델 속성 설정
특정 데이터를 모든 컨트롤러에서 공통적으로 사용할 수 있도록 모델 속성을 설정할 수 있습니다.

```
@ControllerAdvice
public class GlobalModelAttribute {

    @ModelAttribute("appName")
    public String appName() {
        return "My Application";
    }
}
```

위 예시에서는 모든 컨트롤러에서 `appName`이라는 속성을 사용할 수 있게 됩니다.

#### 전역 바인딩 설정
`@ControllerAdvice`를 사용하여 공통적인 바인딩 규칙을 설정할 수 있습니다.

```
@ControllerAdvice
public class GlobalBinding {

    @InitBinder
    public void initBinder(WebDataBinder binder) {
        binder.addValidators(new CustomValidator());
    }
}
```

위 예시에서는 모든 요청에 대해 `CustomValidator`를 사용하여 유효성 검사를 할 수 있습니다.

#### 특정 패키지 내의 컨트롤러에만 적용
`basePackages` 속성을 사용하여 `com.example.locaquest.controller` 패키지 내의 모든 컨트롤러에서 발생하는 예외를 처리합니다.

```
@ControllerAdvice(basePackages = "com.example.locaquest.controller")
public class UserControllerAdvice {

    @ExceptionHandler(ServiceException.class)
    public ResponseEntity<String> handleServiceException(ServiceException e) {
        return ResponseEntity.status(HttpStatus.BAD_REQUEST).body("서비스 오류가 발생했습니다.");
    }

    @ExceptionHandler(Exception.class)
    public ResponseEntity<String> handleException(Exception e) {
        return ResponseEntity.status(HttpStatus.INTERNAL_SERVER_ERROR).body("서버 오류가 발생했습니다.");
    }
}
```

#### 특정 컨트롤러 클래스에만 적용
`assignableTypes` 속성을 사용하여 `UserController` 클래스에서 발생하는 예외만 처리하도록 지정합니다.
```
@ControllerAdvice(assignableTypes = UserController.class)
public class UserControllerAdvice {

    @ExceptionHandler(ServiceException.class)
    public ResponseEntity<String> handleServiceException(ServiceException e) {
        return ResponseEntity.status(HttpStatus.BAD_REQUEST).body("서비스 오류가 발생했습니다.");
    }

    @ExceptionHandler(Exception.class)
    public ResponseEntity<String> handleException(Exception e) {
        return ResponseEntity.status(HttpStatus.INTERNAL_SERVER_ERROR).body("서버 오류가 발생했습니다.");
    }
}
```

`UserController`와 `AdminController`에서 발생하는 예외를 처리하도록 `@ControllerAdvice`를 설정합니다.
```
@ControllerAdvice(assignableTypes = {UserController.class, AdminController.class})
public class GlobalControllerAdvice {

    @ExceptionHandler(ServiceException.class)
    public ResponseEntity<String> handleServiceException(ServiceException e) {
        return ResponseEntity.status(HttpStatus.BAD_REQUEST).body("서비스 오류가 발생했습니다.");
    }

    @ExceptionHandler(Exception.class)
    public ResponseEntity<String> handleException(Exception e) {
        return ResponseEntity.status(HttpStatus.INTERNAL_SERVER_ERROR).body("서버 오류가 발생했습니다.");
    }
}
```

## IO
### jsonwebtoken
`jsonwebtoken`은 JWT (JSON Web Token)을 생성하고 검증하는 데 사용되는 Java 라이브러리입니다. JWT는 주로 웹 애플리케이션에서 사용자 인증 및 권한 부여에 사용되는 표준 토큰 형식입니다. 이 라이브러리는 JWT를 쉽게 생성하고 파싱할 수 있도록 도와줍니다.

1. **JWT 생성**: 사용자의 정보를 포함하는 JWT를 생성할 수 있습니다.
2. **JWT 파싱 및 검증**: JWT 토큰을 파싱하여 헤더와 페이로드를 추출할 수 있습니다.
3. **유효성 검사**: JWT의 만료 여부를 확인하거나, 특정 클레임이 유효한지 검사할 수 있습니다.

Java에서는 `JwtBuilder`의 `signWith` 메서드를 사용하여 **Base64 인코딩된 비밀키**를 제공하는 방식입니다. 이때 비밀키는 문자열로 제공되며, 자동으로 바이트 배열로 변환됩니다.

**주요 클래스와 메서드**
1. `Jwts`: JWT를 생성하거나 파싱하는 유틸리티 클래스입니다.
    - `Jwts.builder()`: JWT를 생성하는 빌더 객체를 반환.
    - `Jwts.parser()`: JWT를 파싱하는 파서 객체를 반환.
2. `Claims`: JWT의 페이로드를 나타내는 클래스입니다. 클레임 데이터를 포함하고 있습니다.    
    - `setSubject()`: 사용자 ID와 같은 주체 정보를 설정.
    - `getSubject()`: 설정된 주체 정보를 반환.
3. `SignatureAlgorithm`: JWT 서명에 사용할 알고리즘을 정의하는 열거형 클래스입니다.
    - 예: `HS256`, `RS256`, `HS384` 등.
4. `JwtException`: JWT 파싱이나 검증 중에 발생할 수 있는 예외 클래스입니다.

**JWT 생성:**
```
String jwtToken = Jwts.builder()
        .setSubject("user123")  // 사용자 ID
        .setIssuedAt(new Date())  // 발급 시간
        .setExpiration(new Date(System.currentTimeMillis() + 3600000))  // 만료 시간 (1시간)
        .signWith(SignatureAlgorithm.HS256, "mySecretKey")  // 서명
        .compact();  // 토큰 생성
```

**JWT 검증:**
```
try {
    Claims claims = Jwts.parser()
            .setSigningKey("mySecretKey")  // 서명 검증에 사용할 비밀 키
            .parseClaimsJws(jwtToken)  // 토큰 파싱
            .getBody();  // 페이로드 추출
    String userId = claims.getSubject();  // 사용자 ID 추출
    // 유효한 토큰
} catch (JwtException e) {
    // 유효하지 않은 토큰
}
```

## Log
### Logback
**Logback**은 Java용 로깅 프레임워크로, 로깅의 성능과 유연성을 높이기 위해 설계되었으며, **Spring Boot**에서 기본 로깅 구현체로 사용됩니다. **Spring Boot** 프로젝트에서는 **Logback**과 **SLF4J**가 기본적으로 포함되어 있기 때문에, 별도로 `build.gradle`에 추가할 필요가 없습니다.

1. **SLF4J와의 통합**: Logback은 SLF4J와 함께 사용됩니다. SLF4J는 로깅 API를 제공하고, Logback은 실제 로깅 동작을 처리하는 구현체입니다. 즉, SLF4J는 로깅 인터페이스를 제공하고, Logback은 그 구현을 제공합니다.
2. **성능 최적화**: Logback은 성능에 중점을 두고 설계되었습니다. 특히, **비동기 로깅** 기능을 제공하여 고성능 애플리케이션에서 로깅 성능을 최적화할 수 있습니다.
3. **구성 가능성**: Logback은 XML 또는 Groovy를 사용하여 로깅을 매우 유연하게 구성할 수 있습니다. 이를 통해 로그 출력 형식, 로그 파일의 크기 제한, 로그 파일의 회전 정책 등을 설정할 수 있습니다.
4. **다양한 출력 옵션**: Logback은 로그를 **콘솔**, **파일**, **원격 서버** 등 다양한 출력 대상으로 보낼 수 있습니다.
5. **로그 회전 (Rolling)**: Logback은 로그 파일이 일정 크기나 시간에 따라 회전하도록 설정할 수 있습니다. 예를 들어, 하루 단위로 로그 파일을 새로 생성하거나, 파일 크기가 일정 크기를 넘으면 새로운 파일로 로그를 기록하도록 할 수 있습니다.
6. **자동화된 로그 레벨 설정**: Logback은 로그 레벨을 동적으로 설정할 수 있으며, `logback-spring.xml` 파일을 통해 애플리케이션의 로깅 동작을 조정할 수 있습니다.

#### `logback-spring.xml`
Logback은 `logback-spring.xml` 파일을 통해 설정할 수 있습니다. Spring Boot에서는 기본적으로 `logback-spring.xml` 파일을 사용하며, 이 파일은 `src/main/resources` 폴더에 위치합니다.

- **Appender**: 로그를 출력할 대상을 정의합니다. (콘솔, 파일 등).
- **Root**: 애플리케이션의 기본 로거를 정의합니다.
- **Logger**: 특정 패키지나 클래스에 대한 로깅 설정을 정의합니다.
- **Encoder**: 로그 메시지의 출력 형식을 정의합니다.
- **RollingPolicy**: 로그 파일이 일정 크기를 초과하거나 특정 주기가 지나면 새 파일로 롤링(분리)되도록 설정합니다.

```
<configuration>

    <!-- 콘솔 출력 설정 -->
    <appender name="console" class="ch.qos.logback.core.ConsoleAppender">
        <encoder>
            <pattern>%d{yyyy-MM-dd HH:mm:ss} - %msg%n</pattern>
        </encoder>
    </appender>

    <!-- 로그 파일 설정 -->
    <appender name="file" class="ch.qos.logback.core.rolling.RollingFileAppender">
        <file>logs/application.log</file>
        <rollingPolicy class="ch.qos.logback.core.rolling.TimeBasedRollingPolicy">
            <fileNamePattern>logs/application-%d{yyyy-MM-dd}.log</fileNamePattern>
            <maxHistory>30</maxHistory> <!-- 30일간의 로그를 보관 -->
        </rollingPolicy>
        <encoder>
            <pattern>%d{yyyy-MM-dd HH:mm:ss} - %msg%n</pattern>
        </encoder>
    </appender>

    <!-- 로그 레벨 설정 -->
    <logger name="com.example" level="INFO"/>
    <logger name="org.springframework" level="DEBUG"/>

    <!-- 루트 로그 레벨 설정 -->
    <root level="INFO">
        <appender-ref ref="console"/>
        <appender-ref ref="file"/>
    </root>

</configuration>
```

## Mail
### 의존성 추가
Spring Boot에서는 이메일을 보내기 위해 `spring-boot-starter-mail` 의존성을 사용합니다. 이 의존성을 추가하면 이메일 발송을 위한 기본적인 기능을 사용할 수 있습니다.

`build.gradle`:
```
dependencies {
    implementation 'org.springframework.boot:spring-boot-starter-mail'
}
```

### 애플리케이션 설정
이메일을 보내기 위해 SMTP 서버와 관련된 설정을 `application.properties` 파일에 추가해야 합니다. 예를 들어, Gmail을 사용할 경우 아래와 같은 설정을 추가할 수 있습니다.

- `spring.mail.host`: SMTP 서버 주소 (예: Gmail의 경우 `smtp.gmail.com`).
- `spring.mail.port`: SMTP 서버 포트 (예: Gmail의 경우 587번 포트를 사용).
- `spring.mail.username`: 발송할 이메일 계정.
- `spring.mail.password`: 이메일 계정의 비밀번호.
- `spring.mail.properties.mail.smtp.auth`: SMTP 인증을 사용 여부.
- `spring.mail.properties.mail.smtp.starttls.enable`: STARTTLS를 활성화 여부.

`application.properties`:
```
spring.mail.host=smtp.gmail.com
spring.mail.port=587
spring.mail.username=your-email@gmail.com
spring.mail.password=your-email-password
spring.mail.properties.mail.smtp.auth=true
spring.mail.properties.mail.smtp.starttls.enable=true
spring.mail.properties.mail.smtp.ssl.trust=smtp.gmail.com
```

### `JavaMailSender`
`JavaMailSender`는 Spring Framework에서 제공하는 인터페이스로, 이메일을 보내는 기능을 제공합니다. 이 인터페이스는 JavaMail API를 기반으로 하며, 이메일을 보내는 다양한 기능을 추상화하여 제공합니다. `javaMailSender` 생성 시,`application.properties`에 설정된 값들이 자동으로 반영됩니다.

- `send(MimeMessage message)`: `MimeMessage` 객체를 사용하여 이메일을 전송합니다.
- `createMimeMessage()`: 새로운 `MimeMessage` 객체를 생성합니다.

Spring Boot의 자동 설정은 `JavaMailSenderImpl`을 생성하고, 이를 `JavaMailSender` 인터페이스로 등록합니다. 이 빈은 Spring Boot의 **자동 구성**에 의해 설정되므로, 별도로 `JavaMailSenderImpl`을 수동으로 생성할 필요는 없습니다.

```
@Autowired
private JavaMailSender mailSender;

public void sendEmail(String to, String subject, String text) {
    MimeMessage message = mailSender.createMimeMessage();
    MimeMessageHelper helper = new MimeMessageHelper(message, true);
    helper.setTo(to);
    helper.setSubject(subject);
    helper.setText(text, true); // HTML 형식으로 설정

    mailSender.send(message); // 이메일 발송
}
```

단, `JavaMailSender` 인터페이스 자체는 메일 서버의 설정을 직접 수정하는 메서드를 제공하지 않습니다. `JavaMailSender`는 메일을 보내는 기능만을 제공하는 인터페이스이고, 메일 서버 설정은 `JavaMailSenderImpl` 클래스에서 수행됩니다. 따라서, `JavaMailSender` 인터페이스를 사용하면서 메일 서버 설정을 변경하려면, `JavaMailSenderImpl`을 사용해야 합니다.

### `JavaMailSenderImpl`
`JavaMailSenderImpl`는 `JavaMailSender` 인터페이스의 기본 구현체입니다. 이 클래스는 이메일을 전송하기 위해 필요한 SMTP 서버 설정과 이메일 발송을 처리하는 기능을 제공합니다.

1. **SMTP 서버 설정**:
    - `setHost()`: SMTP 서버의 호스트 주소를 설정합니다.
    - `setPort()`: SMTP 서버의 포트 번호를 설정합니다.
    - `setUsername()`: SMTP 서버에 로그인할 사용자 이름을 설정합니다.
    - `setPassword()`: SMTP 서버에 로그인할 비밀번호를 설정합니다.
2. **메일 전송**:
    - `send()`: `MimeMessage` 객체를 전달하여 이메일을 전송합니다.
    - `createMimeMessage()`: 이메일 내용을 설정할 수 있는 `MimeMessage` 객체를 생성합니다.
3. **추가 설정**:
    - `setProtocol()`: 이메일 전송에 사용할 프로토콜을 설정합니다. (예: "smtp")
    - `setJavaMailProperties()`: 이메일 전송에 사용할 JavaMail 관련 속성들을 설정할 수 있습니다.

`JavaMailSenderImpl`을 직접 생성하여 사용하면 Spring의 자동 설정을 우회하게 되어, `application.properties`에 설정된 값들이 적용되지 않습니다. 따라서 `JavaMailSenderImpl`을 수동으로 생성하는 경우, `application.properties`의 설정을 직접 코드에서 반영해야 합니다.

```
JavaMailSenderImpl mailSender = new JavaMailSenderImpl();
Properties props = mailSender.getJavaMailProperties();
props.put("mail.smtp.auth", "true");
props.put("mail.smtp.starttls.enable", "true");
```

### `MimeMessageHelper`
`MimeMessageHelper`는 `MimeMessage` 객체를 보다 쉽게 설정할 수 있도록 도와주는 클래스입니다. `MimeMessage`는 JavaMail API에서 이메일 메시지를 나타내는 클래스입니다.

- `setTo(String... to)`: 이메일 수신자의 이메일 주소를 설정합니다.
- `setSubject(String subject)`: 이메일 제목을 설정합니다.
- `setText(String text, boolean isHtml)`: 이메일 본문을 설정합니다. `isHtml`을 `true`로 설정하면 HTML 형식의 이메일을 보낼 수 있습니다.
- `addAttachment(String filename, File file)`: 이메일에 첨부파일을 추가합니다.

```
MimeMessage message = mailSender.createMimeMessage();
MimeMessageHelper helper = new MimeMessageHelper(message, true); // true는 멀티파트 이메일(첨부파일 등)을 사용할 때 필요

helper.setTo("recipient@example.com");
helper.setSubject("Test Email");
helper.setText("<h1>This is a test email</h1>", true); // HTML 형식 이메일

mailSender.send(message); // 이메일 발송
```

`logback-spring.xml` 파일이 없어도 Spring Boot 애플리케이션은 로그를 출력할 수 있습니다. 이때는 기본 설정으로 로그를 출력합니다.

## URI
### ServletUriComponentsBuilder
`ServletUriComponentsBuilder`는 Spring에서 제공하는 유틸리티 클래스로, 현재 HTTP 요청의 URI를 기반으로 상대 URL을 쉽게 생성할 수 있도록 돕는 도구입니다. 주로 컨트롤러에서 요청된 URL을 바탕으로 링크를 생성할 때 사용됩니다.

- **기본 URL 생성**: 현재 서버의 기본 URL을 기반으로 URL을 생성합니다.
- **경로 추가**: 요청된 URL에 경로를 추가할 수 있습니다.
- **쿼리 파라미터 추가**: 쿼리 파라미터를 쉽게 추가할 수 있습니다.
- **현재 요청의 URI 정보**를 바탕으로 URL을 생성할 수 있어, 상대 경로를 지정할 때 유용합니다.

**메서드**
- `path("/home")`: URL에 경로를 추가합니다.
- `queryParam("email", email)`: 쿼리 파라미터를 추가합니다.
- `toUriString()`: 최종적으로 완성된 URL을 문자열로 반환합니다.

#### `fromCurrentRequestUri()`
`fromCurrentRequestUri()`는 **전체 URI**를 기준으로 작업하며, URL을 구성할 때 요청된 전체 URL을 기반으로 합니다.

- 프로토콜 (http/https)
- 호스트 (localhost)
- 포트 번호 (8080)
- 경로 (/api/users)

```
public String generateLink(String email) {
    String url = ServletUriComponentsBuilder.fromCurrentRequestUri()
            .path("/new-path")  // 현재 요청 URI에 "/new-path"를 추가
            .queryParam("email", email)
            .toUriString();  // 최종 URL 반환
    return url;
}
```

요청이 `http://localhost:8080/verify-email?token=12345`라면, 이 코드는 `http://localhost:8080/verify-email/new-path`와 같은 URL을 생성합니다.

#### `fromCurrentRequest()`
`fromCurrentRequest()`는 **전체 URI**를 기반으로 하며, **쿼리 파라미터**까지 포함된 URI를 생성할 수 있습니다.

- 프로토콜 (http/https)
- 호스트 (localhost)
- 포트 번호 (8080)
- 경로 (/api/users)
- 쿼리 파라미터 (?param=value)

#### fromCurrentContextPath()
`fromCurrentContextPath()`는 **컨텍스트 경로**만을 기준으로 작업하며, 요청된 URL의 컨텍스트 경로를 바탕으로 URI를 생성합니다.
```
import org.springframework.web.servlet.support.ServletUriComponentsBuilder;

public String generateLink() {
    String url = ServletUriComponentsBuilder.fromCurrentContextPath()
            .path("/new-path")  // 컨텍스트 경로를 기준으로 "/new-path"를 추가
            .toUriString();  // 최종 URL 반환
    return url;
}
```

웹 애플리케이션의 컨텍스트 경로가 `/myapp`이라면, 이 코드는 `/myapp/new-path`와 같은 URL을 생성합니다.

### UriComponentsBuilder
UriComponentsBuilder는 URI(Uniform Resource Identifier)를 동적으로 생성하고 조합할 때 사용되는 유틸리티 클래스입니다. 주로 **REST API 호출** 시 동적으로 URL을 구성하거나, 쿼리 파라미터를 추가하는 데 사용됩니다.

1. **유연한 URI 생성**:
    - 경로, 쿼리 파라미터, 호스트 등을 동적으로 추가하여 URI를 생성할 수 있습니다.
2. **안전한 URL 인코딩**:
    - 자동으로 URL 인코딩을 처리하므로, 직접 문자열을 조작할 때 발생할 수 있는 문제를 방지합니다.
3. **체이닝 방식**:
    - 빌더 패턴을 사용하여 코드가 간결하고 읽기 쉽습니다.

|메서드|설명|
|---|---|
|`scheme(String scheme)`|URI의 스킴(예: `http`, `https`)을 설정.|
|`host(String host)`|호스트(예: `api.example.com`)를 설정.|
|`port(int port)`|포트 번호를 설정.|
|`path(String path)`|경로를 설정하거나 추가.|
|`queryParam(String name, Object... values)`|쿼리 파라미터를 추가.|
|`build()`|URI를 빌드하며, 인코딩되지 않은 상태로 반환.|
|`buildAndExpand(Object... uriVariables)`|URI 템플릿 변수를 동적으로 치환.|
|`toUriString()`|URI를 문자열로 반환.|
|`toUri()`|URI 객체를 반환.|

#### 기본 URI 생성
```
import org.springframework.web.util.UriComponentsBuilder;

public class UriBuilderExample {
    public static void main(String[] args) {
        String uri = UriComponentsBuilder.newInstance()
                .scheme("https")
                .host("api.example.com")
                .path("/users/{id}")
                .buildAndExpand(123)
                .toUriString();

        System.out.println(uri); // 출력: https://api.example.com/users/123
    }
}
```

#### 쿼리 파라미터 추가
```
String uri = UriComponentsBuilder.newInstance()
        .scheme("https")
        .host("api.example.com")
        .path("/search")
        .queryParam("query", "spring framework")
        .queryParam("page", 1)
        .build()
        .toUriString();

System.out.println(uri);
// 출력: https://api.example.com/search?query=spring+framework&page=1
```

#### `buildAndExpand`
`buildAndExpand`를 사용해 템플릿 변수에 값을 동적으로 삽입합니다.
```
String uri = UriComponentsBuilder.newInstance()
        .scheme("https")
        .host("api.example.com")
        .path("/users/{userId}/posts/{postId}")
        .buildAndExpand(123, 456)
        .toUriString();

System.out.println(uri);
// 출력: https://api.example.com/users/123/posts/456
```

#### URI 확장
기존 URI를 기반으로 새로운 경로나 파라미터를 추가합니다.

```
String uri = UriComponentsBuilder.fromUriString("https://api.example.com/users")
        .path("/{id}")
        .queryParam("active", true)
        .buildAndExpand(123)
        .toUriString();

System.out.println(uri);
// 출력: https://api.example.com/users/123?active=true
```

#### `toUri()`
`toUri()`를 사용하여 `java.net.URI` 객체를 반환합니다.

```
URI uri = UriComponentsBuilder.newInstance()
        .scheme("https")
        .host("api.example.com")
        .path("/users")
        .build()
        .toUri();

System.out.println(uri);
// 출력: https://api.example.com/users
```

## Template
### Thymeleaf
**Thymeleaf**는 Java 기반 웹 애플리케이션에서 서버 측 템플릿 엔진으로 사용되는 라이브러리입니다. HTML, XML, JavaScript, CSS, 텍스트 파일 등을 동적으로 생성하거나 조작하는 데 사용됩니다. 특히 **Spring Boot**와 함께 사용할 때 강력한 통합 기능을 제공하며, HTML 파일에 동적으로 데이터를 삽입하거나 조작할 수 있는 기능이 주요 장점입니다.

1. **표준 HTML과의 호환성**
    - Thymeleaf 템플릿은 순수 HTML 파일로 작성되며, 브라우저에서 바로 열어도 문제가 없습니다.
    - HTML 파일에 Thymeleaf 태그를 추가하면, 서버에서 처리된 후 동적인 결과를 제공합니다.
2. **서버 측 데이터 렌더링**
    - 컨트롤러에서 전달된 데이터를 HTML에 삽입하여 동적으로 렌더링할 수 있습니다.
    - 예: 사용자 이름, 목록 데이터, 조건부 렌더링 등.
3. **Spring Boot와의 통합**
    - Spring Boot는 기본적으로 Thymeleaf를 지원하며, 설정이 간단합니다.
    - 컨트롤러에서 `Model` 객체를 통해 데이터를 Thymeleaf로 전달할 수 있습니다.
4. **표현식 사용**
    - Thymeleaf는 다양한 표현식을 제공하여 데이터를 삽입하거나 조건부 렌더링을 쉽게 처리합니다.
    - 예: `${variable}`, `th:if`, `th:each`.
5. **확장성**
    - 사용자 정의 템플릿, 유틸리티 클래스, 확장 가능한 기능을 제공합니다.

#### Thymeleaf 설정
 **의존성 추가**  
```
spring-boot-starter-thymeleaf
```

**HTML 템플릿 파일 위치**
기본적으로 `src/main/resources/templates/` 경로에 HTML 파일을 저장합니다.

**컨트롤러에서 데이터 전달**
Spring MVC에서는 컨트롤러에서 반환하는 문자열이 템플릿 파일 이름으로 매핑되어, 해당 템플릿 엔진(예: Thymeleaf, JSP 등)을 통해 HTML 파일이 렌더링됩니다.

```
@Controller
public class HomeController {
    @GetMapping("/welcome")
    public String welcome(Model model) {
        model.addAttribute("username", "Alice");
        return "welcome"; // 템플릿 파일 이름 (welcome.html)
    }
}
```
  
**HTML 템플릿 작성**  
파일명: `welcome.html`
```
<!DOCTYPE html>
    <html xmlns:th="http://www.thymeleaf.org">
    <head>
        <title>Welcome</title>
    </head>
    <body>
        <h1>Welcome, <span th:text="${username}">User</span>!</h1>
    </body>
</html>
```

#### **변수 출력**
```
<span th:text="${username}">Default User</span>
```

#### **조건부 렌더링**
```
<p th:if="${isLoggedIn}">You are logged in.</p>
<p th:unless="${isLoggedIn}">Please log in.</p>
```
    
#### **반복문**
```
<ul>
    <li th:each="item : ${items}" th:text="${item}">Item</li>
</ul>
```
    
#### **URL 매핑**
```
<a th:href="@{/login}">Login</a>
```

### SpringTemplateEngine
`SpringTemplateEngine`은 **Spring Framework**에서 제공하는 **템플릿 엔진**으로, 주로 **Thymeleaf**와 함께 사용됩니다. 이 엔진은 HTML, XML, 텍스트 등 다양한 형식의 템플릿을 렌더링할 수 있습니다.

`templateEngine.process()`는 **SpringTemplateEngine**에서 제공하는 메서드로, 주어진 템플릿을 처리하고 결과를 반환하는 역할을 합니다. 이 메서드는 템플릿 파일을 읽고, 템플릿 내에 정의된 변수들을 동적으로 바인딩하여 최종적인 문자열(주로 HTML)을 생성합니다.

```
String htmlContent = templateEngine.process("emailTemplate", context);
```

- `"emailTemplate"`: 템플릿 파일의 이름을 나타냅니다. 예를 들어, `emailTemplate.html` 파일이 `src/main/resources/templates` 폴더에 위치한다고 가정하면, `"emailTemplate"`을 전달하여 해당 템플릿을 렌더링합니다.
- `context`: 템플릿에서 사용할 데이터를 포함하는 객체입니다. 보통 `Context` 클래스를 사용하여 데이터를 설정합니다. 이 데이터는 템플릿 내에서 `${}` 구문을 통해 참조할 수 있습니다.

### Context
`Context`는 **Thymeleaf**에서 템플릿에 데이터를 전달할 때 사용하는 객체입니다. 템플릿에서 사용할 변수들을 설정하고, 이를 템플릿 내에서 `${}` 구문으로 참조할 수 있게 해주는 역할을 합니다.

- **변수 설정**: 템플릿에서 사용될 데이터를 `Context` 객체에 설정합니다.
- **데이터 전달**: `Context` 객체에 설정된 변수들은 템플릿 내에서 `${}` 구문을 사용하여 참조됩니다.

```
Context context = new Context();
context.setVariable("username", username);
context.setVariable("verificationCode", verificationCode);

return templateEngine.process("emailTemplate", context);
```

## Validation
### `@Valid`
`@Valid`는 **Java Bean Validation**을 위한 어노테이션으로, 객체의 유효성을 검사할 때 사용됩니다. 이 어노테이션을 사용하면 객체의 필드에 설정된 제약 조건(예: `@NotNull`, `@Size`, `@Email` 등)이 검증됩니다.

- **DTO**나 **엔티티** 객체에 대한 유효성 검사를 수행할 때 사용됩니다.
- 일반적으로 **컨트롤러**에서 요청 파라미터를 객체로 바인딩할 때 사용하며, **서비스**나 **메서드 파라미터**에서도 유효성 검사를 트리거할 수 있습니다.

```
@RestController
@RequestMapping("/users")
public class UserController {

    @PostMapping("/register")
    public ResponseEntity<String> register(@Valid @RequestBody UserDTO userDTO, BindingResult bindingResult) {
        if (bindingResult.hasErrors()) {
            return ResponseEntity.badRequest().body("Invalid input");
        }
        // 유효성 검사를 통과하면 로직 실행
        return ResponseEntity.ok("User registered successfully");
    }
}
```
- 이 예제에서 `@Valid`는 `userDTO` 객체가 **컨트롤러 메서드**로 전달될 때 유효성 검사를 수행합니다.
- 유효성 검사가 실패하면, `BindingResult` 객체에 오류가 기록되며, 이를 통해 유효성 검사 결과를 확인할 수 있습니다.

`BindingResult`는 유효성 검사 결과를 담고 있는 객체로, `@Valid` 또는 `@Validated`로 유효성 검사를 하는 객체 바로 뒤에 와야 합니다. 즉, 메서드 인자에서 `@Valid`와 `BindingResult`의 순서는 반드시 `@Valid` 객체 뒤에 `BindingResult`가 와야 합니다.

### `@Validated`
`@Valid`와 동일하게 객체의 유효성 검사를 트리거하지만, **Validation Group**을 지정할 수 있다는 추가적인 기능이 있습니다. 특정 그룹을 지정하여 해당 그룹에 포함된 필드만 유효성 검사를 수행할 수 있습니다.

```
public interface CreateGroup {
    // 빈 인터페이스, Create에 관련된 유효성 검사 그룹
}

public interface UpdateGroup {
    // 빈 인터페이스, Update에 관련된 유효성 검사 그룹
}
```

```
public class User {

    @NotNull(groups = {CreateGroup.class, UpdateGroup.class}) // 여러 그룹에 대한 유효성 검사
    @Size(min = 6, groups = CreateGroup.class) // CreateGroup에 대해서만 유효성 검사
    private String username;

    @Size(min = 6, groups = CreateGroup.class)  // CreateGroup에 대해서만 유효성 검사
    private String password;

    @NotNull(groups = UpdateGroup.class)  // UpdateGroup에 대해서만 유효성 검사
    private String email;

    // Getter, Setter
}
```

```
@RestController
public class UserController {

    @PostMapping("/register")
    public ResponseEntity<String> register(@Validated(CreateGroup.class) @RequestBody User user) {
        // CreateGroup에 해당하는 필드만 검증
        return ResponseEntity.ok("User registered");
    }

    @PutMapping("/update")
    public ResponseEntity<String> update(@Validated(UpdateGroup.class) @RequestBody User user) {
        // UpdateGroup에 해당하는 필드만 검증
        return ResponseEntity.ok("User updated");
    }
}
```
