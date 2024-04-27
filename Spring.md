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

### Definition
Spring에서 빈(Bean)을 작성하는 방법은 다양합니다. 일반적으로는 다음과 같은 방법들이 있습니다:

#### XML 기반 설정
Spring에서 빈을 XML 파일에 정의하는 방법입니다. XML 파일에 `<bean>` 요소를 사용하여 빈을 정의하고 필요한 속성들을 설정합니다.
    
```
<beans xmlns="http://www.springframework.org/schema/beans"
       xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
       xsi:schemaLocation="http://www.springframework.org/schema/beans
           http://www.springframework.org/schema/beans/spring-beans.xsd">

    <bean id="myBean" class="com.example.MyBean"/>

</beans>
```

#### Java 기반 설정
Java 구성 클래스를 사용하여 빈을 정의하는 방법입니다. `@Configuration` 어노테이션을 붙인 클래스 내에서 `@Bean` 어노테이션을 사용하여 빈을 생성합니다.
    
```
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

@Configuration
public class AppConfig {

    @Bean
    public MyBean myBean() {
        return new MyBean();
    }
}

```
    
#### Component Scanning
`@Component` 어노테이션을 사용하여 Spring이 자동으로 빈을 검색하고 등록하도록 할 수 있습니다. 클래스 위에 `@Component`, `@Controller`, `@Service`, `@Repository` 등의 어노테이션을 붙여 해당 클래스를 스프링 빈으로 등록합니다.
    
```
import org.springframework.stereotype.Component;

@Component
public class MyBean {
    // 클래스 내용
}
```

###  스코프 (Scope)
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

### Bean Post Processors
Bean Post Processors는 IoC 컨테이너가 Bean을 생성하고 구성한 후에 추가적인 작업을 수행할 수 있도록 하는 확장 포인트입니다. Bean Post Processors는 주로 Bean의 생성, 초기화, 소멸 전 후에 특정한 작업을 수행하거나 Bean을 변경하는 데 사용됩니다. 주요한 기능은 다음과 같습니다:

- **Bean 수정**: Bean Post Processors를 사용하여 Bean의 속성을 변경하거나 다른 Bean으로 대체할 수 있습니다.
- **Bean 유효성 검사**: Bean이 생성된 후에 Bean의 상태를 검사하고 필요한 경우 에러를 반환할 수 있습니다.
- **Bean 초기화**: Bean이 초기화된 후 추가적인 초기화 작업을 수행할 수 있습니다.
- **Bean 소멸**: Bean이 소멸되기 전에 추가적인 정리 작업을 수행할 수 있습니다.

```
import org.springframework.beans.BeansException;
import org.springframework.beans.factory.config.BeanPostProcessor;
import org.springframework.stereotype.Component;

@Component
public class CustomBeanPostProcessor implements BeanPostProcessor {

    @Override
    public Object postProcessBeforeInitialization(Object bean, String beanName) throws BeansException {
        System.out.println("Before initializing bean: " + beanName);
        return bean;
    }

    @Override
    public Object postProcessAfterInitialization(Object bean, String beanName) throws BeansException {
        System.out.println("After initializing bean: " + beanName);
        return bean;
    }
}
```

위 `CustomBeanPostProcessor` 클래스는 `BeanPostProcessor` 인터페이스를 구현하고, `postProcessBeforeInitialization()`과 `postProcessAfterInitialization()` 메서드를 재정의하여 각각 빈이 초기화되기 전과 후에 원하는 작업을 수행합니다. `@Component` 어노테이션이 붙어 있으므로 Spring 컨테이너에 자동으로 등록되며, 따라서 모든 빈이 생성되고 초기화될 때마다 해당 메서드가 호출됩니다.

### Bean Definition Inheritance
Bean Definition Inheritance은 부모 빈 정의에 대한 설정을 상속하여 자식 빈에게 적용하는 기능입니다.

```
public class ParentBean {
    private String name;
    private int age;

    public ParentBean(String name, int age) {
        this.name = name;
        this.age = age;
    }
    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }
}

public class ChildBean extends ParentBean {
    private String school;

    public ChildBean(String name, int age, String school) {
        super(name, age);
        this.school = school;
    }

    public String getSchool() {
        return school;
    }

    public void setSchool(String school) {
        this.school = school;
    }
}
```

### Dependency Injection
일반적으로 Spring에서 DI를 사용하는 방법은 다음과 같습니다:

- **생성자 주입(Constructor Injection)**: 객체를 생성할 때 생성자를 통해 의존 객체를 주입합니다.
- **Setter 주입(Setter Injection)**: Setter 메서드를 이용하여 의존 객체를 주입합니다.

```
public class MyService {
    private final MyRepository repository;

    // 생성자 주입
    public MyService(MyRepository repository) {
        this.repository = repository;
    }

	// Setter 메서드를 통한 주입
    public void setRepository(MyRepository repository) {
        this.repository = repository;
    }

    public void doSomething() {
        repository.saveData();
    }
}

public interface MyRepository {
    void saveData();
}

public class MyRepositoryImpl implements MyRepository {
    public void saveData() {
        // 데이터 저장 로직
    }
}
```

### Inner Beans
Inner Beans는 다른 Bean의 내부에 선언되는 빈을 의미합니다. Inner Beans는 외부에서 직접적으로 접근할 필요가 없는 경우에 유용하게 사용됩니다.

```
<?xml version = "1.0" encoding = "UTF-8"?>

<beans xmlns = "http://www.springframework.org/schema/beans"
   xmlns:xsi = "http://www.w3.org/2001/XMLSchema-instance"
   xsi:schemaLocation = "http://www.springframework.org/schema/beans
   http://www.springframework.org/schema/beans/spring-beans-3.0.xsd">

   <bean id = "outerBean" class = "...">
      <property name = "target">
         <bean id = "innerBean" class = "..."/>
      </property>
   </bean>
   
</beans>
```

### Auto-Wiring
Auto-Wiring은 Spring이 자동으로 Bean 간의 의존성을 주입하는 기능입니다. Auto-Wiring을 사용하면 명시적으로 의존성을 표시하는 과정을 생략할 수 있습니다. Spring에서는 다음과 같은 자동 연결 방식을 지원합니다:

- **constructor** - 생성자를 사용하여 자동으로 의존성을 해결합니다.
- **byType** - 같은 타입의 Bean을 자동으로 주입합니다.
- **byName** - Bean의 이름을 기준으로 자동으로 주입합니다.
- **byConstructor** - 생성자의 파라미터를 기준으로 자동으로 주입합니다.
- **autodetect** - 기본적으로 byType을 사용하며, byType으로 자동 연결이 실패하면 byName을 시도합니다.

```
package com.test;

public class Car {
   private Engine engine;
   private String name;
   
   public void setEngine( Engine engine ){
      this.engine= engine;
   }
}
```

```
<?xml version = "1.0" encoding = "UTF-8"?>

<beans xmlns = "http://www.springframework.org/schema/beans"
   xmlns:xsi = "http://www.w3.org/2001/XMLSchema-instance"
   xsi:schemaLocation = "http://www.springframework.org/schema/beans
   http://www.springframework.org/schema/beans/spring-beans-3.0.xsd">

   <bean id = "car" class = "com.test.Car" autowire = "byName">
	  <!-- Auto-Wiring (byName) -->
      <property name = "name" value = "genesis" />
   </bean>

   <bean id = "engine" class = "com.test.Engine"></bean>

</beans>
```
