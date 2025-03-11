---
categories:
- Redis
date: '2025-02-10'
title: '[Redis] Spring'
---

{% raw %}
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
    public RedisTemplate<String, Object> redisTemplate(RedisConnectionFactory connectionFactory) {<br>
        RedisTemplate<String, Object> template = new RedisTemplate<>();<br>
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
    private RedisTemplate<String, Object> redisTemplate;<br>

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
    public RedisTemplate<String, Object> redisTemplate(RedisConnectionFactory connectionFactory) {<br>
        RedisTemplate<String, Object> template = new RedisTemplate<>();<br>
        template.setConnectionFactory(connectionFactory);

        // JdkSerializationRedisSerializer로 직렬화 설정
        RedisSerializer<Object> serializer = new JdkSerializationRedisSerializer();<br>
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
    private RedisTemplate<String, Object> redisTemplate;<br>

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
    public RedisTemplate<String, Object> redisTemplate(RedisConnectionFactory connectionFactory) {<br>
        RedisTemplate<String, Object> template = new RedisTemplate<>();<br>
        template.setConnectionFactory(connectionFactory);

        // Jackson2JsonRedisSerializer로 직렬화 설정
        Jackson2JsonRedisSerializer<Object> serializer = new Jackson2JsonRedisSerializer<>(Object.class);<br>
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
    private RedisTemplate<String, Object> redisTemplate;<br>

    public void saveObject(String key, MyObject myObject) {
        redisTemplate.opsForValue().set(key, myObject);
    }

    public MyObject getObject(String key) {
        return (MyObject) redisTemplate.opsForValue().get(key);
    }
}
```
{% endraw %}