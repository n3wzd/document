# Spring
Spring은 Java 애플리케이션을 개발하기 위한 오픈 소스 프레임워크입니다. 주로 엔터프라이즈급 애플리케이션을 구축하는 데 사용됩니다.

- **의존성 주입(Dependency Injection, DI)**: 객체 간의 의존 관계를 설정하고 필요한 의존 객체를 주입하는 방식을 지원합니다. 이를 통해 코드의 결합도를 낮추고 유연성을 높입니다.
- **제어 역전(Inversion of Control, IoC)**: 객체의 생성과 관리를 프레임워크가 담당하며, 개발자는 필요한 객체를 가져다 사용하는 방식으로 개발할 수 있습니다.
- **애스펙트 지향 프로그래밍(Aspect-Oriented Programming, AOP)**: 관심사의 분리를 통해 횡단 관심 사항을 모듈화하고, 코드 중복을 줄여줍니다. 예를 들어, 로깅, 트랜잭션 관리 등의 기능을 별도의 모듈로 분리하여 재사용할 수 있습니다.
- **트랜잭션 관리**: 데이터베이스 트랜잭션을 효과적으로 관리하여 데이터의 일관성과 무결성을 유지합니다.
- **POJO 기반 개발**: Plain Old Java Object(POJO)를 사용하여 간단하고 가독성 있는 코드를 작성할 수 있습니다.
- **모듈화**: Spring은 다양한 모듈로 구성되어 있어 필요한 기능을 선택적으로 사용할 수 있습니다. 이는 개발자가 프로젝트의 요구 사항에 맞게 Spring을 활용할 수 있도록 합니다.

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

#### Setter 주입
`@Autowired`를 setter 메서드에 붙여서 의존성을 주입할 수도 있습니다. 선택적 의존성 주입에 유용하지만, 필수 의존성에 대해서는 적합하지 않습니다.

```
private UserService userService;

@Autowired
public void setUserService(UserService userService) {
    this.userService = userService;
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
`@Component`의 특수화된 어노테이션으로, Spring 컨테이너가 이 클래스를 자동으로 **빈**으로 등록하도록 합니다. Spring은 애플리케이션 시작 시 클래스 경로를 스캔하여 `@Service`가 붙은 클래스를 빈으로 등록하고, 의존성 주입 등을 처리할 수 있게 만듭니다.

`@Service`는 해당 클래스가 **서비스 계층**에 속하는 클래스를 명확하게 나타냅니다. `@Component`와 같은 일반적인 어노테이션을 사용할 수도 있지만, `@Service`를 사용하면 코드의 가독성이 높아지고, 역할이 분명해집니다.

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

-   **키워드**: `findBy`, `readBy`, `queryBy`, `countBy`, `deleteBy` 등.
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

#### 복잡한 쿼리
만약 쿼리 메서드로 표현하기 어려운 복잡한 쿼리가 필요하다면, 다음 방법을 사용할 수 있습니다:

##### `@Query`
```
@Query("SELECT u FROM User u WHERE u.name LIKE %:name%")
List<User> searchByName(@Param("name") String name);
```
    
##### 네이티브 쿼리 사용
```
@Query(value = "SELECT * FROM users WHERE name = ?1", nativeQuery = true)
List<User> searchByNameNative(String name);
```

##### 커스텀 리포지토리 구현
복잡한 비즈니스 로직이 필요한 경우, 리포지토리 인터페이스를 확장하여 직접 구현할 수 있습니다.

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
