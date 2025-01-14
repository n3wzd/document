# Test
## JUnit
**JUnit**은 자바에서 **단위 테스트(Unit Test)**를 작성하고 실행할 수 있게 도와주는 프레임워크입니다. **단위 테스트**는 애플리케이션의 개별적인 기능이나 메서드가 예상대로 작동하는지 확인하는 테스트입니다. JUnit은 테스트를 작성하고, 실행하고, 결과를 확인하는 과정을 간소화해줍니다.

1. **테스트 메서드 정의**: `@Test` 어노테이션을 사용하여 테스트할 메서드를 정의합니다.
2. **Assertions**: 테스트 결과를 검증하기 위한 다양한 **assertion 메서드**를 제공합니다. 예를 들어, `assertEquals()`, `assertTrue()`, `assertNotNull()` 등을 사용하여 실제 값과 예상 값을 비교할 수 있습니다.
3. **테스트 실행 및 결과 확인**: JUnit은 테스트를 자동으로 실행하고, 각 테스트의 성공 여부를 보고합니다.
4. **셋업 및 티어다운**: 테스트를 실행하기 전후에 공통적인 작업을 수행할 수 있는 `@BeforeEach`와 `@AfterEach` 어노테이션을 제공합니다.

**Spring Boot** 프로젝트에서 테스트 코드는 보통 `src/test/java` 폴더 내에 작성되며, **JUnit**을 사용하여 테스트를 작성합니다.

Maven 사용시, `mvn test`, Gradle 사용시 `gradle test` 명령어를 사용하여 테스트를 실행합니다.

### 헬퍼 메서드 (Helper Method)
**헬퍼 메서드**는 **반복적인 작업**을 하나의 메서드로 묶어 **재사용**할 수 있도록 도와주는 **일반적인 메서드**입니다. 테스트에서 반복적으로 사용되는 로직을 한 곳에 모아두면 코드가 간결하고 유지보수가 쉬워집니다.

```
public void registerAndVerifyUser(List<String> userJson, String expectedName, String expectedEmail) throws Exception {
    mockMvc.perform(post("/api/users/register")
            .contentType("application/json")
            .content(userJson.get(0)))  // 첫 번째 사용자 데이터를 사용
            .andExpect(status().isCreated())
            .andExpect(jsonPath("name").value(expectedName))
            .andExpect(jsonPath("email").value(expectedEmail));
}
```

### 파라미터화된 테스트 (Parameterized Test)
JUnit 5부터 사용 가능한 파라미터화된 테스트는 **같은 테스트 메서드를 여러 입력 값에 대해 반복 실행**할 수 있게 해주는 기능으로, 같은 테스트 메서드가 여러 다른 입력 값에 대해 실행되도록 할 수 있습니다. 이를 통해 테스트 케이스를 효율적으로 확장하고 관리할 수 있습니다. `@ParameterizedTest`를 사용하여 파라미터화된 테스트를 진행할 수 있습니다.

- `@ValueSource`: 단일 타입의 데이터를 여러 번 테스트할 때 사용합니다.
- `@MethodSource`: 외부 메서드에서 데이터를 가져오는 방식입니다.
- `@CsvSource`: 테스트 데이터를 인라인으로 제공합니다.
- `@CsvFileSource`: CSV 파일을 읽어 테스트 데이터를 제공합니다.

```
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.CsvSource;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.test.web.servlet.MockMvc;
import org.springframework.test.web.servlet.result.MockMvcResultMatchers;

import static org.springframework.test.web.servlet.request.MockMvcRequestBuilders.post;

public class UserRegistrationTest {

    @Autowired
    private MockMvc mockMvc;

    @ParameterizedTest
    @CsvSource({
            "'{\"name\":\"Alice Smith\",\"email\":\"alice@example.com\"}', Alice Smith, alice@example.com",
            "'{\"name\":\"Bob Johnson\",\"email\":\"bob@example.com\"}', Bob Johnson, bob@example.com"
    })
    public void testUserRegistration(String userJson, String expectedName, String expectedEmail) throws Exception {
        mockMvc.perform(post("/api/users/register")
                .contentType("application/json")
                .content(userJson))
                .andExpect(MockMvcResultMatchers.status().isCreated())
                .andExpect(MockMvcResultMatchers.jsonPath("name").value(expectedName))
                .andExpect(MockMvcResultMatchers.jsonPath("email").value(expectedEmail));
    }
}
```

### `@BeforeAll`
테스트 클래스의 모든 테스트가 실행되기 전에 **한 번** 실행되는 메서드를 지정합니다. 테스트 준비 작업(예: 데이터베이스 초기화, 외부 서비스 연결 등)을 수행할 때 사용됩니다.

### `@AfterAll`
테스트 클래스의 모든 테스트가 실행된 후 **한 번** 실행되는 메서드를 지정합니다. 테스트 종료 후 정리 작업(예: 리소스 해제, 테스트 환경 복원 등)을 수행할 때 사용됩니다.

## Mock
**Mock**(모의 객체)는 소프트웨어 테스트에서 실제 객체의 동작을 시뮬레이션하는 가짜 객체입니다. 실제 객체 대신 사용하여 테스트 환경을 제어하고, 의존하는 외부 시스템이나 복잡한 객체의 동작을 대체하는 역할을 합니다. 주로 단위 테스트에서 사용됩니다.

1. **동작 정의**: 특정 메서드가 호출될 때 반환할 값을 설정하거나, 예외를 발생시킬 수 있습니다.
2. **상호작용 검증**: 테스트 후, Mock 객체의 메서드가 호출되었는지, 몇 번 호출되었는지 등을 검증할 수 있습니다.
3. **독립성**: 실제 객체가 필요하지 않으므로, 테스트 대상이 다른 시스템에 의존하지 않고 독립적으로 동작할 수 있습니다.

예를 들어, 데이터베이스를 사용하는 서비스가 있을 때, 실제 데이터베이스에 연결하지 않고도 데이터베이스 관련 기능을 테스트할 수 있습니다. 이를 위해 데이터베이스 연결을 모의 객체로 대체할 수 있습니다.

## Mockito
Mockito는 Java에서 사용되는 외부 테스트 프레임워크로, 주로 단위 테스트를 작성할 때 사용됩니다. 주된 기능은 **모의 객체(mock object)**를 생성하여 실제 객체의 동작을 시뮬레이션하는 것입니다. 이를 통해 실제 객체를 사용하지 않고도 테스트를 진행할 수 있습니다.

- **모의 객체 생성**: 실제 구현체를 사용하지 않고, 인터페이스나 클래스의 모의 객체를 생성하여 테스트할 수 있습니다.
- **행동 정의**: 모의 객체가 특정 메서드를 호출할 때 반환할 값을 설정할 수 있습니다.
- **검증**: 테스트가 끝난 후, 모의 객체의 메서드가 호출되었는지, 몇 번 호출되었는지를 검증할 수 있습니다.
- **예외 처리**: 특정 메서드 호출 시 예외를 발생시키도록 설정할 수 있습니다.

```
import static org.mockito.Mockito.*;

public class MyServiceTest {
    @Test
    public void testServiceMethod() {
        // MyService의 의존성을 모의 객체로 설정
        MyRepository mockRepo = mock(MyRepository.class);
        when(mockRepo.findData()).thenReturn("Mock Data");

        MyService service = new MyService(mockRepo);
        String result = service.fetchData();

        assertEquals("Mock Data", result);
    }
}
```

`MyRepository`의 실제 구현 대신 `mock`을 사용하고, `findData()` 메서드가 호출될 때 `"Mock Data"`를 반환하도록 설정합니다. 이를 통해 실제 데이터베이스나 외부 시스템을 호출하지 않고도 `MyService`의 `fetchData()` 메서드를 테스트할 수 있습니다.

## MockMvc
`MockMvc`는 **Spring MVC**의 테스트를 위한 도구로, **Spring Web** 애플리케이션을 테스트할 때 **서버를 실제로 실행하지 않고** HTTP 요청과 응답을 시뮬레이션할 수 있게 해주는 **Mocking 프레임워크**입니다. 이를 사용하면 **컨트롤러**의 동작을 테스트하고, 요청을 보내고 응답을 검증하는 등의 작업을 할 수 있습니다.

`MockMvc`는 **Spring Test** 모듈에 포함되어 있으며, 실제 서버를 구동하지 않고도 애플리케이션의 **웹 계층**을 테스트할 수 있게 해줍니다. 주로 **컨트롤러**와 관련된 HTTP 요청/응답을 테스트할 때 사용됩니다.

- **HTTP 요청 시뮬레이션**: `MockMvc`는 `GET`, `POST`, `PUT`, `DELETE` 등 다양한 HTTP 요청을 시뮬레이션하여 실제 서버 없이 테스트할 수 있습니다.
- **응답 검증**: 요청에 대한 응답이 예상한 값과 일치하는지 확인할 수 있습니다. 예를 들어, 응답 상태 코드, 본문 내용, 헤더 등을 검증할 수 있습니다.
- **컨트롤러 테스트**: 실제 애플리케이션을 실행하지 않고도, 컨트롤러의 동작을 테스트하고 검증할 수 있습니다.

`MockMvc`는 주로 `@SpringBootTest`와 함께 사용하여 테스트 환경을 설정합니다. `@AutoConfigureMockMvc`를 통해 `MockMvc` 객체를 자동으로 설정할 수 있습니다.

```
@SpringBootTest
@AutoConfigureMockMvc
public class UserControllerTest {

    @Autowired
    private MockMvc mockMvc;

    @Test
    public void testCreateUser() throws Exception {
        String userJson = "{\"name\":\"Alice\",\"email\":\"alice@example.com\"}";

        mockMvc.perform(post("/api/users/register")
                .contentType("application/json")
                .content(userJson))
                .andExpect(status().isCreated())  // 상태 코드 201 확인
                .andExpect(jsonPath("name").value("Alice"))  // 응답 본문에 name이 Alice인지 확인
                .andExpect(jsonPath("email").value("alice@example.com"));  // 응답 본문에 email이 alice@example.com인지 확인
    }
}
```

- `perform(MockHttpServletRequestBuilder requestBuilder)`: HTTP 요청을 시뮬레이션합니다.
- `andExpect(ResultMatcher... matchers)`: 요청 후의 응답을 검증합니다.

## `@SpringBootTest`
`@SpringBootTest`는 **Spring Boot** 애플리케이션을 테스트할 때 사용하는 애노테이션으로, **전체 Spring 애플리케이션 컨텍스트**를 로드하여 **통합 테스트**를 수행할 수 있게 해줍니다. 이 애노테이션을 사용하면 애플리케이션의 실제 실행 환경과 유사한 환경에서 테스트를 진행할 수 있습니다.

`@SpringBootTest`는 Spring Boot 애플리케이션의 **전체 컨텍스트**를 로드하기 때문에, **애플리케이션의 모든 빈(bean)**, **자동 설정** 등을 포함하여 테스트를 실행합니다. 이를 통해 실제 애플리케이션에서의 동작을 정확하게 테스트할 수 있습니다.

1.  **애플리케이션 컨텍스트 로딩**: `@SpringBootTest`는 테스트가 실행될 때 전체 Spring 컨텍스트를 로드합니다. 이를 통해 애플리케이션의 모든 빈과 설정이 초기화되고, 실제 애플리케이션 환경에서 테스트가 진행됩니다.
2.  **통합 테스트**: 이 애노테이션은 통합 테스트를 위한 애노테이션으로, 실제 데이터베이스나 외부 시스템을 포함한 애플리케이션의 여러 컴포넌트가 제대로 동작하는지 테스트할 수 있습니다.
3.  **테스트 환경 설정**: `@SpringBootTest`는 기본적으로 `@TestConfiguration`을 사용하여 테스트 환경을 설정합니다. 테스트 중에 필요한 설정을 추가할 수 있습니다.

`@SpringBootTest`는 **테스트 클래스**에서 사용되어야 하며, **애플리케이션 코드**에서는 사용하지 않는 것이 좋습니다. 테스트 폴더 내에서 사용하는 것이 일반적입니다.

#### 기본 사용
`@SpringBootTest`는 애플리케이션의 실제 실행 환경을 시뮬레이션하므로, 애플리케이션 컨텍스트와 관련된 빈들이 모두 로드됩니다. 보통 `@Autowired`를 사용하여 필요한 빈을 주입받고 테스트를 진행합니다.

```
@SpringBootTest
public class UserServiceTest {

    @Autowired
    private UserService userService;

    @Test
    public void testRegisterUser() {
        User user = new User("Alice", "alice@example.com");
        User savedUser = userService.registerUser(user);
        
        assertNotNull(savedUser);
        assertEquals("Alice", savedUser.getName());
    }
}
```

#### 웹 애플리케이션 테스트
`@SpringBootTest`는 웹 애플리케이션 테스트 시에도 사용됩니다. `MockMvc`와 함께 사용하여 실제 HTTP 요청을 시뮬레이션하고 응답을 검증할 수 있습니다.

```
@SpringBootTest
@AutoConfigureMockMvc
public class UserControllerTest {

    @Autowired
    private MockMvc mockMvc;

    @Test
    public void testCreateUser() throws Exception {
        String userJson = "{\"name\":\"Alice\",\"email\":\"alice@example.com\"}";

        mockMvc.perform(post("/api/users/register")
                .contentType("application/json")
                .content(userJson))
                .andExpect(status().isCreated())
                .andExpect(jsonPath("$.name").value("Alice"))
                .andExpect(jsonPath("$.email").value("alice@example.com"));
    }
}
```

#### 특정 프로파일 사용
특정 프로파일을 활성화하여 테스트할 때는 `@SpringBootTest`의 `properties`나 `webEnvironment` 속성을 사용하여 환경을 설정할 수 있습니다.

```
@SpringBootTest(properties = "spring.profiles.active=test")
public class UserServiceTest {
    // 테스트 코드
}
```

**주요 속성**
- `webEnvironment`: 웹 애플리케이션을 테스트할 때 사용합니다. `WebEnvironment`는 다음과 같은 옵션을 가질 수 있습니다:
    - `MOCK`: 가짜 서블릿 환경을 사용하여 테스트합니다. 보통 `MockMvc`와 함께 사용됩니다.
    - `RANDOM_PORT`: 임의의 포트에서 서버를 시작하여 테스트합니다.
    - `DEFINED_PORT`: 지정된 포트에서 서버를 시작하여 테스트합니다.
    - `NONE`: 웹 환경을 사용하지 않습니다.


```
@SpringBootTest(webEnvironment = SpringBootTest.WebEnvironment.RANDOM_PORT)
public class UserControllerTest {
    // 테스트 코드
}
```

- `properties`: 테스트에 필요한 설정 값을 `application.properties` 대신 지정할 수 있습니다.

```
@SpringBootTest(properties = "spring.datasource.url=jdbc:h2:mem:testdb")
public class UserServiceTest {
    // 테스트 코드
}
```
