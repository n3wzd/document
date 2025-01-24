# Redis
Redis는 **Remote Dictionary Server**의 약자로, 데이터를 메모리에 저장하고 빠르게 읽고 쓸 수 있는 **오픈 소스, 인메모리 데이터 저장소**입니다. 주로 **캐시, 세션 관리, 실시간 데이터 처리** 등에 사용되며, 다양한 데이터 구조를 지원합니다.

1. **인메모리 데이터 저장**
    - 데이터를 메모리에 저장하므로 매우 빠른 속도로 읽고 쓸 수 있습니다.
    - 디스크에 데이터를 영구 저장하는 옵션도 제공됩니다(예: RDB, AOF).
2. **다양한 데이터 구조 지원**  
    Redis는 단순한 키-값 저장소 이상으로, 다음과 같은 데이터 구조를 지원합니다:
    - **String**: 기본적인 텍스트나 숫자 데이터.
    - **Hash**: 필드와 값을 저장하는 구조 (예: JSON 유사 구조).
    - **List**: 순서가 있는 값의 목록 (예: 대기열).
    - **Set**: 중복 없는 값의 집합.
    - **Sorted Set**: 정렬된 집합 (점수 기반 정렬 가능).
    - **Stream**: 실시간 데이터 처리에 적합한 구조.
3. **TTL 지원**
    - 키마다 유효 기간(Time-To-Live)을 설정할 수 있어, 자동으로 만료되도록 관리 가능합니다.
4. **고성능**
    - 초당 수십만 건의 요청을 처리할 수 있는 성능을 제공합니다.
5. **분산 환경 지원**
    - Redis Cluster를 통해 여러 노드로 확장 가능하며, 고가용성과 분산 처리가 가능합니다.


**Redis의 사용 사례**
1. **캐싱**: 자주 조회되는 데이터를 Redis에 저장하여 데이터베이스의 부하를 줄이고 성능을 향상.
2. **세션 관리**: 사용자 로그인 상태를 관리하고, 만료 시간을 설정하여 자동으로 세션을 종료.
3. **인증 대기 데이터 관리**: 이메일 인증, OTP 코드 등 일정 시간 후 만료가 필요한 데이터를 저장.
4. **실시간 분석 및 순위표**: 게임 순위표, 실시간 클릭 수 집계 등.
5. **메시지 큐**: Redis의 List 또는 Stream을 사용하여 간단한 메시지 큐로 활용 가능.

Redis를 사용하는 방법은 간단하며, 아래 단계를 따라 설정하고 사용할 수 있습니다. Redis는 서버와 클라이언트로 구성되며, 다양한 프로그래밍 언어에서 클라이언트를 통해 접근할 수 있습니다.

## 설치
### Linux
```
sudo apt update
sudo apt install redis
```

### MacOS
```
brew install redis
```

### Docker
```
docker run --name redis-server -d -p 6379:6379 redis
```

### Windows
Redis는 공식적으로 Windows를 지원하지 않지만, Microsoft에서 제공했던 배포판을 사용할 수 있습니다.

> https://github.com/microsoftarchive/redis/releases

1. **Redis 서버 실행**
    - 압축을 푼 폴더로 이동하여 `redis-server.exe`를 실행합니다.
    - Redis 서버가 실행되면 기본적으로 `localhost:6379`에서 대기합니다.
2. **Redis CLI 실행**
    - 같은 폴더에서 `redis-cli.exe`를 실행하여 Redis 서버와 상호작용합니다.

## 실행
Redis 서버를 실행하려면 터미널에서 다음 명령어를 입력합니다:

```
redis-server
```

Redis 클라이언트로 서버에 연결하려면:
```
redis-cli
```

### Windows
1. **Redis 서버 실행**
    - `redis-server.exe`를 실행합니다.
    - Redis 서버가 실행되면 기본적으로 `localhost:6379`에서 대기합니다.
2. **Redis CLI 실행**
    - 같은 폴더에서 `redis-cli.exe`를 실행하여 Redis 서버와 상호작용합니다.

## 명령어
Redis CLI에서 다음 명령어를 사용해 데이터를 관리할 수 있습니다:

### 데이터 저장 및 조회
```
SET key value       # 데이터 저장
GET key             # 데이터 조회
DEL key             # 데이터 삭제
```

예시:
```
GET signup:user123
DEL signup:user123
```

### TTL 설정
```
SETEX key seconds value  # 유효 기간과 함께 데이터 저장
TTL key                  # 남은 유효 기간 확인
```

예시:
```
SETEX signup:user123 86400 '{"email":"user@example.com","name":"John"}'
```

### 다양한 데이터 구조
```
HSET user:1 name "Alice" age 25  # 해시(Hash) 데이터 저장
HGETALL user:1                  # 해시 데이터 조회

LPUSH queue "task1" "task2"     # 리스트(List) 데이터 추가
LRANGE queue 0 -1               # 리스트 조회
```

## 클라이언트
Redis는 다양한 프로그래밍 언어에서 사용할 수 있는 클라이언트를 제공합니다. 아래는 주요 언어별 Redis 클라이언트를 사용하는 방법입니다:

### Java Spring
#### 의존성 추가
Spring Boot 프로젝트의 `pom.xml` 파일에 Redis 관련 의존성을 추가합니다:

```
<dependency>
    <groupId>org.springframework.boot</groupId>
    <artifactId>spring-boot-starter-data-redis</artifactId>
</dependency>
<dependency>
    <groupId>org.springframework.boot</groupId>
    <artifactId>spring-boot-starter-data-redis-reactive</artifactId>
</dependency>
```

#### Redis 설정
`application.properties`에서 Redis 서버의 기본 설정을 추가합니다:
```
spring.redis.host=localhost
spring.redis.port=6379
spring.redis.password= # (Redis에 비밀번호가 설정된 경우 입력)
spring.redis.timeout=2000ms
```

`application.yml`:
```
spring:
  redis:
    host: localhost
    port: 6379
    timeout: 2000ms
```

#### RedisTemplate 설정
Spring Data Redis는 `RedisTemplate`을 통해 Redis와 상호작용합니다. RedisTemplate을 빈으로 등록하려면 설정 클래스를 작성합니다:
```
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.data.redis.connection.RedisConnectionFactory;
import org.springframework.data.redis.core.RedisTemplate;
import org.springframework.data.redis.serializer.StringRedisSerializer;

@Configuration
public class RedisConfig {

    @Bean
    public RedisTemplate<String, Object> redisTemplate(RedisConnectionFactory connectionFactory) {
        RedisTemplate<String, Object> template = new RedisTemplate<>();
        template.setConnectionFactory(connectionFactory);

        // Key와 Value를 문자열로 직렬화
        template.setKeySerializer(new StringRedisSerializer());
        template.setValueSerializer(new StringRedisSerializer());

        return template;
    }
}
```

#### Redis 사용
Redis에 데이터를 저장하고 조회하는 코드를 작성합니다:

```
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.data.redis.core.RedisTemplate;
import org.springframework.stereotype.Service;

import java.util.concurrent.TimeUnit;

@Service
public class RedisService {

    @Autowired
    private RedisTemplate<String, Object> redisTemplate;

    // 데이터 저장
    public void save(String key, String value, long timeout, TimeUnit unit) {
        redisTemplate.opsForValue().set(key, value, timeout, unit);
    }

    // 데이터 조회
    public String get(String key) {
        return (String) redisTemplate.opsForValue().get(key);
    }

    // 데이터 삭제
    public void delete(String key) {
        redisTemplate.delete(key);
    }
}
```

#### Java 객체 저장
Java 객체를 저장하려면, 객체를 직렬화(Serialization)하여 문자열로 변환한 후 저장하고, 다시 역직렬화(Deserialization)하여 객체로 변환해야 합니다.

##### JdkSerializationRedisSerializer
`JdkSerializationRedisSerializer`는 Java의 기본 직렬화 메커니즘을 사용하여 객체를 직렬화합니다.

```
import org.springframework.data.redis.core.RedisTemplate;
import org.springframework.data.redis.serializer.JdkSerializationRedisSerializer;
import org.springframework.data.redis.serializer.RedisSerializer;
import org.springframework.data.redis.connection.RedisConnectionFactory;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

@Configuration
public class RedisConfig {

    @Bean
    public RedisTemplate<String, Object> redisTemplate(RedisConnectionFactory connectionFactory) {
        RedisTemplate<String, Object> template = new RedisTemplate<>();
        template.setConnectionFactory(connectionFactory);

        // JdkSerializationRedisSerializer로 직렬화 설정
        RedisSerializer<Object> serializer = new JdkSerializationRedisSerializer();
        template.setValueSerializer(serializer);
        template.setHashValueSerializer(serializer);

        return template;
    }
}
```

```
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.data.redis.core.RedisTemplate;
import org.springframework.stereotype.Service;

@Service
public class RedisService {

    @Autowired
    private RedisTemplate<String, Object> redisTemplate;

    public void saveObject(String key, MyObject myObject) {
        redisTemplate.opsForValue().set(key, myObject);
    }

    public MyObject getObject(String key) {
        return (MyObject) redisTemplate.opsForValue().get(key);
    }
}
```

##### Jackson2JsonRedisSerializer
`Jackson2JsonRedisSerializer`는 객체를 JSON 형식으로 직렬화하여 저장합니다. 이 방법은 객체를 JSON으로 저장하기 때문에 가독성이 높고, 다른 시스템과의 호환성이 좋습니다.

```
import org.springframework.data.redis.core.RedisTemplate;
import org.springframework.data.redis.serializer.Jackson2JsonRedisSerializer;
import org.springframework.data.redis.serializer.RedisSerializer;
import org.springframework.data.redis.connection.RedisConnectionFactory;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import com.fasterxml.jackson.databind.ObjectMapper;

@Configuration
public class RedisConfig {

    @Bean
    public RedisTemplate<String, Object> redisTemplate(RedisConnectionFactory connectionFactory) {
        RedisTemplate<String, Object> template = new RedisTemplate<>();
        template.setConnectionFactory(connectionFactory);

        // Jackson2JsonRedisSerializer로 직렬화 설정
        Jackson2JsonRedisSerializer<Object> serializer = new Jackson2JsonRedisSerializer<>(Object.class);
        template.setValueSerializer(serializer);
        template.setHashValueSerializer(serializer);

        return template;
    }
}
```

```
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.data.redis.core.RedisTemplate;
import org.springframework.stereotype.Service;

@Service
public class RedisService {

    @Autowired
    private RedisTemplate<String, Object> redisTemplate;

    public void saveObject(String key, MyObject myObject) {
        redisTemplate.opsForValue().set(key, myObject);
    }

    public MyObject getObject(String key) {
        return (MyObject) redisTemplate.opsForValue().get(key);
    }
}
```


### 관리
#### Redis 서버 상태 확인
```
redis-cli ping
# 출력: PONG
```

#### Redis 데이터 확인

```
redis-cli
KEYS *             # 모든 키 조회
DBSIZE             # 저장된 키의 개수
```

#### Redis 설정 변경
`redis.conf` 파일에서 설정을 변경하거나, 다음 명령어로 설정을 수정할 수 있습니다:
```
CONFIG SET maxmemory 256mb    # 메모리 제한 설정
CONFIG SET maxmemory-policy allkeys-lru  # LRU 정책 설정
```
