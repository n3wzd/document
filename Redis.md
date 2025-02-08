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

서버 변수만 사용할 경우, 다음 문제가 존재할 수 있습니다. Redis를 사용하여 해결할 수 있습니다.
- **서버 재시작 시 데이터 손실**: 서버가 재시작되거나 종료되면 메모리 내 데이터가 사라지므로, 중요한 데이터를 서버 변수에만 저장하는 것은 위험할 수 있습니다.
- **스케일링 어려움**: 여러 서버가 있을 경우, 각각의 서버에 데이터를 저장하려면 동기화가 필요하거나, 클러스터링 등을 구현해야 할 수 있습니다.

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
    - 이 방법은 설정 파일이 적용되지 않으며, 기본 설정이 적용됩니다.
2. **Redis CLI 실행**
    - 같은 폴더에서 `redis-cli.exe`를 실행하여 Redis 서버와 상호작용합니다.

설정 파일을 직접 지정해서 실행할 수 있습니다.
```
redis-server.exe redis.windows.conf
```

## 명령어
Redis CLI에서 다음 명령어를 사용해 데이터를 관리할 수 있습니다:

### 데이터 저장 및 조회
```
SET myKey value       # 데이터 저장
GET myKey             # 데이터 조회
DEL myKey             # 데이터 삭제
```

예시:
```
GET signup:user123
DEL signup:user123
```

### TTL
#### TTL 설정
```
SETEX myKey seconds value  # 유효 기간과 함께 데이터 저장
TTL myKey                  # 남은 유효 기간 확인
```

예시:
```
SETEX signup:user123 86400 '{"email":"user@example.com","name":"John"}'
```

TTL을 설정하거나 갱신할 때, 새로 설정된 TTL은 **기존 TTL을 완전히 덮어씌웁니다**. 이 경우 시간 합산은 일어나지 않으며, 새로운 TTL 값만 적용됩니다.

#### TTL 확인
```
TTL myKey
```

`-1`은 TTL이 없고 영구적인 상태임을 나타냅니다.

#### TTL 제거
```
PERSIST myKey
```

### 해시 테이블
Redis에서 해시는 `field`와 `value`를 쌍으로 저장할 수 있는 자료구조입니다. 예를 들어, 하나의 사용자(`user:1`)에 대해 여러 정보를 저장하고 싶을 때, 해시를 사용하여 `name`, `age`, `email` 등 여러 필드를 하나의 키 아래에 묶어 저장할 수 있습니다.

예시:
```
HSET user:1 name "Alice" age 25  # 해시(Hash) 데이터 저장
HGETALL user:1                   # 해시 데이터 조회
```

결과:
```
1) "name" 2) "Alice" 3) "age" 4) "25"
```

#### HSET
`HSET` 명령어는 Redis의 해시(Hash) 타입에 필드를 추가하거나 업데이트할 때 사용됩니다. 해시는 키-값 쌍으로 데이터를 저장하는 자료구조로, 하나의 키에 여러 개의 필드와 값들을 연결할 수 있습니다.

```
HSET <hash-key> <field> <value>
```

### HGET
`HGET` 명령어는 지정된 해시의 특정 필드 값을 반환합니다.

```
HGET <hash-key> <field>
```

#### HGETALL
`HGETALL` 명령어는 지정된 해시의 모든 필드와 값을 반환합니다. 해시의 모든 데이터를 가져오고 싶을 때 사용합니다.

```
HGETALL <hash-key>
```

### 리스트
Redis의 리스트는 양방향 입출력이 가능한 덱(Deque)과 비슷한 자료구조입니다.

- 리스트는 데이터가 추가된 순서대로 순차적으로 접근할 수 있습니다.

```
LPUSH queue "task1" "task2"      # 리스트(List) 데이터 추가
LRANGE queue 0 -1                # 리스트 조회
```

#### LPUSH, RPUSH
- `LPUSH`는 리스트의 왼쪽에 데이터를 추가합니다.
- `RPUSH`는 리스트의 오른쪽에 데이터를 추가합니다.

```
LPUSH <list-key> <value1> <value2> ...
```

#### LRANGE
LRANGE 명령어는 Redis 리스트에서 지정된 범위의 데이터를 조회합니다. 인덱스를 사용하여 리스트의 일부분을 가져올 수 있습니다.

```
LRANGE <list-key> <start> <end>
```

`<start>`와 `<end>`는 리스트에서 가져올 범위를 지정합니다. 인덱스는 0부터 시작하며, 음수 인덱스를 사용하면 리스트의 끝에서부터 카운트합니다.

### `SCAN`
`SCAN`은 Redis에서 데이터를 효율적으로 순차적으로 검색할 수 있도록 도와주는 명령어입니다. `SCAN`은 **전체 데이터를 한 번에 로드하지 않고, 일정 부분씩 나누어** 데이터를 반환합니다.

- **Cursor 기반 순차 조회**: `SCAN`은 데이터를 순차적으로 반환합니다. 처음에 호출하면 `SCAN`은 `cursor` 값을 반환하며, 이를 사용하여 다음 데이터를 계속 조회할 수 있습니다.
- **비차단적**: `SCAN`은 비차단적이기 때문에 서버가 응답을 기다리는 동안 다른 작업을 계속 수행할 수 있습니다. 즉, 전체 키를 한 번에 반환하지 않고, 여러 번에 걸쳐 나누어 반환하여 Redis 서버가 차단되지 않도록 합니다.
- **배치 처리**: 한 번의 `SCAN` 호출에서 반환되는 키는 일정량으로 제한됩니다. 이 값은 `COUNT` 옵션으로 조절할 수 있습니다. `COUNT`를 사용하여 한 번에 반환할 키의 수를 설정할 수 있지만, 실제 반환되는 키의 수는 Redis의 부하에 따라 달라질 수 있습니다.

```
SCAN cursor [MATCH pattern] [COUNT count]
```

- `cursor`: `SCAN` 명령어는 처음 호출 시 `0`을 시작으로, 이후에는 반환된 `cursor` 값을 사용하여 계속 검색을 이어갑니다. `cursor`는 0이 될 때까지 계속 반복하여 호출합니다.
- `MATCH pattern`: (선택적) 키를 검색할 때 패턴을 지정할 수 있습니다. 예를 들어, `exp:*`로 검색하여 `exp:`로 시작하는 키들만 검색할 수 있습니다.
- `COUNT count`: (선택적) 한 번에 반환할 키의 수를 설정합니다. 기본값은 Redis 서버의 설정에 따라 다를 수 있습니다.

#### `SCAN` vs `KEYS`
- **`KEYS`**: Redis에서 모든 키를 한 번에 반환하며, 지정된 패턴에 맞는 키를 필터링합니다. O(N) 시간 복잡도를 가지며, 데이터가 많으면 성능 저하가 발생할 수 있습니다. `KEYS`는 전체 키를 한 번에 반환하므로 서버 부하가 크고, 큰 데이터셋을 다룰 때는 사용을 피하는 것이 좋습니다.
- `SCAN`: 전체 데이터를 한 번에 다 가져오지 않고 커서를 사용하여 반복적으로 키를 조회합니다. O(N) 시간 복잡도를 가지며, 데이터가 많을수록 시간이 소요됩니다. 그러나 `SCAN`은 비차단적(non-blocking) 방식이므로 한 번에 전체 데이터를 반환하지 않고, 여러 번에 걸쳐 데이터를 반환합니다. 이 방식은 서버의 부하를 분산시킬 수 있습니다.

## 관리
### Redis 서버 상태 확인
```
redis-cli ping
# 출력: PONG
```

### Redis 데이터 확인
```
redis-cli
KEYS *             # 모든 키 조회
DBSIZE             # 저장된 키의 개수
```

### Redis 설정 변경
`redis.conf` 파일에서 설정을 변경하거나, 다음 명령어로 설정을 수정할 수 있습니다:
```
CONFIG SET maxmemory 256mb    # 메모리 제한 설정
CONFIG SET maxmemory-policy allkeys-lru  # LRU 정책 설정
```

## Persistence
Redis의 **지속성(Persistence)** 기능은 Redis가 메모리 기반의 데이터 저장소로 동작하는 것에 대한 해결책으로, 데이터를 **디스크에 저장**하여 Redis가 재시작되거나 종료되더라도 데이터를 복구할 수 있게 도와줍니다.

Redis는 두 가지 영속성 방법을 제공합니다. RDB는 **빠른 복구**와 **성능**에 유리하며, AOF는 **최소 데이터 손실**과 **상세한 로그 기록**을 제공합니다.

### RDB (Redis Database Snapshotting)
RDB는 스냅샷(snapshot)을 사용하여 Redis 데이터베이스의 상태를 주기적으로 디스크에 저장하는 방식입니다. Redis가 설정된 시간 간격에 맞춰 메모리 내 데이터를 덤프하여 디스크에 `dump.rdb` 파일로 저장합니다.

- **주기적 백업**: RDB는 설정된 조건을 만족할 때마다 Redis 데이터의 스냅샷을 찍어 저장합니다. 예를 들어, 900초마다 한 번, 10개의 수정이 있을 때마다 한 번씩 스냅샷을 찍을 수 있습니다.
- **장점**:
    - 성능이 뛰어납니다. Redis가 스냅샷을 찍을 때 **Redis는 디스크에 데이터를 동기화**하므로, 클라이언트 요청 처리에는 큰 영향을 미치지 않습니다.
    - **백업 용이**: RDB 파일 하나로 **전체 데이터**를 백업할 수 있습니다.
- **단점**:
    - **최신 데이터 손실**: 스냅샷이 마지막으로 찍힌 시점 이후에 발생한 데이터는 복구되지 않습니다. 예를 들어, 10분 간격으로 스냅샷을 찍으면 그 사이에 변경된 데이터는 손실될 수 있습니다.

**RDB 설정** (`redis.conf`):
```
# RDB 저장 설정
save 900 1     # 900초(15분) 동안 1개 이상의 키가 변경되면 스냅샷
save 300 10    # 300초(5분) 동안 10개 이상의 키가 변경되면 스냅샷
save 60 10000  # 60초 동안 10000개 이상의 키가 변경되면 스냅샷
```

### AOF (Append-Only File)
AOF는 Redis의 **모든 쓰기 작업**을 로그 파일에 **추가적으로 기록**하는 방식입니다. Redis는 **write 명령**이 실행될 때마다 해당 명령을 `appendonly.aof`라는 파일에 기록합니다. Redis 서버가 재시작되면 AOF 파일을 재생하여 데이터를 복구합니다.

- **모든 쓰기 작업 기록**: AOF는 Redis의 **모든 쓰기 작업**을 로그로 기록하므로, AOF 파일을 통해 모든 변경 사항을 추적할 수 있습니다.
- **장점**:
    - **최소 데이터 손실**: AOF는 다양한 동기화 정책을 설정할 수 있기 때문에, 최신 데이터가 손실될 위험을 최소화할 수 있습니다.
    - **AOF 파일 복구**: Redis가 종료된 후 AOF 파일을 사용해 **데이터 복구**가 가능합니다.
- **단점**:
    - **성능 저하**: AOF는 **매번 디스크에 기록**하므로 성능에 영향을 미칠 수 있습니다. 이를 해결하기 위해 **동기화 빈도**를 조정할 수 있습니다.
    - **파일 크기**: AOF 파일은 시간이 지남에 따라 커질 수 있으며, 이를 관리하려면 **파일 압축**이나 **재작성** 작업이 필요합니다.

**AOF 설정** (`redis.conf`):
```
# AOF 활성화
appendonly yes

# AOF 동기화 정책
appendfsync everysec  # 1초마다 AOF 파일 동기화
appendfsync always     # 매번 동기화 (성능 저하)
appendfsync no         # 동기화하지 않음 (위험함)
```

### RDB와 AOF의 혼합 사용
Redis는 RDB와 AOF를 **동시에 사용할 수 있습니다**. 이렇게 하면 두 가지 방식의 장점을 결합할 수 있습니다:

- **RDB**는 주기적인 스냅샷을 제공하여 **성능을 최적화**합니다.
- **AOF**는 모든 쓰기 작업을 기록하여 **데이터 손실 가능성을 최소화**합니다.

```
# RDB 및 AOF 모두 사용
save 900 1       # 15분마다 스냅샷
appendonly yes   # AOF 활성화
appendfsync everysec  # AOF 동기화 정책 설정
```


## 클라이언트
Redis는 다양한 프로그래밍 언어에서 사용할 수 있는 클라이언트를 제공합니다. 아래는 주요 언어별 Redis 클라이언트를 사용하는 방법입니다:

### Spring
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

###  Node.js
`redis`는 Node.js에서 Redis 데이터베이스와 상호작용할 수 있게 해주는 라이브러리입니다. Redis는 고성능의 키-값 저장소로, 메모리 기반으로 데이터를 저장하고 빠르게 접근할 수 있는 데이터베이스입니다. 주로 캐싱, 세션 관리, 실시간 데이터 처리 등에서 많이 사용됩니다.

`redis` 라이브러리는 Redis 서버와 Node.js 애플리케이션 간의 통신을 쉽게 처리해줍니다. 이 라이브러리를 사용하면 Redis의 다양한 기능(예: 데이터 읽기/쓰기, Pub/Sub, 트랜잭션, 파이프라인 등)을 Node.js 코드에서 직접 사용할 수 있습니다.

설치:
```
npm install redis
```

#### 사용법
```
const redis = require('redis');

// Redis 클라이언트 생성
const client = redis.createClient({
  host: 'localhost',      // Redis 서버 주소
  port: 6379,            // Redis 서버 포트
  password: 'your_password',  // 비밀번호 (설정된 경우)
  db: 0                  // 사용할 데이터베이스 인덱스 (기본은 0)
});

// Redis 연결이 되면 실행될 이벤트 리스너
client.error('connect', function() {
  console.error('Redis client error:', err);
});

// Redis 연결
client.connect().then(() => {
	console.log('Connected to Redis');
  }).catch((err) => {
	console.error('Failed to connect to Redis', err);
  });

// 데이터를 저장하는 예시
client.set('myKey', 'myValue', function(err, reply) {
  if (err) {
    console.error('Error setting value:', err);
  } else {
    console.log('Reply:', reply);  // "OK"
  }
});

// 데이터를 조회하는 예시
client.get('myKey', function(err, reply) {
  if (err) {
    console.error('Error getting value:', err);
  } else {
    console.log('Value from Redis:', reply);  // "myValue"
  }
});
```

`reply`는 **Redis 명령에 대한 응답**을 나타냅니다. 명령이 정상적으로 완료되면 Redis 서버는 `OK`라는 문자열을 반환합니다.

#### `client.on()`
`client.on()` 메서드는 **이벤트 리스너**를 등록하여, 특정 이벤트가 발생했을 때 해당 이벤트에 대해 정의된 콜백 함수를 실행하게 합니다.

`redis` 클라이언트는 여러 가지 이벤트를 처리할 수 있습니다. 대표적인 이벤트는 다음과 같습니다:

2. **'connect'**: Redis 서버에 연결되었을 때 발생합니다.
    - 예: `client.on('connect', () => { console.log('Connected to Redis'); });`
3. **'error'**: Redis 클라이언트에서 오류가 발생했을 때 발생합니다.
    - 예: `client.on('error', (err) => { console.error('Redis client error:', err); });`
4. **'ready'**: Redis 클라이언트가 서버와 연결되어 명령을 처리할 준비가 되었을 때 발생합니다.
    - 예: `client.on('ready', () => { console.log('Redis client is ready'); });`
5. **'end'**: Redis 클라이언트가 연결을 종료했을 때 발생합니다.
    - 예: `client.on('end', () => { console.log('Redis client connection ended'); });`
