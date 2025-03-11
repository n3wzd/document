---
categories:
- Kafka
date: '2025-02-10'
title: '[Kafka] Spring Boot'
---

{% raw %}
의존성 추가:
```gradle
implementation 'org.springframework.kafka:spring-kafka:3.0.0'
```

#### 연결 설정
`application.yml`:
```
spring:
  kafka:
    bootstrap-servers: localhost:9092
    consumer:
      group-id: my-consumer-group
      auto-offset-reset: earliest
      enable-auto-commit: false
    producer:
      acks: all
      retries: 3
      key-serializer: org.apache.kafka.common.serialization.StringSerializer
      value-serializer: org.apache.kafka.common.serialization.StringSerializer
```

- `bootstrap-servers`: Kafka 서버의 주소.
- `consumer.group-id`: Kafka 전역 컨슈머 그룹 ID. (개별 설정이 있다면 개별 설정 우선)
- `auto-offset-reset`: 컨슈머가 처음 연결할 때, 오프셋을 어떻게 처리할지 설정 (`earliest`나 `latest`).
- `enable-auto-commit`: 자동 커밋 활성화 여부.
- `acks`: 프로듀서가 메시지를 전송할 때의 응답 대기 정책 (`all`은 가장 안전한 설정).
- `retries`: 메시지 전송에 실패했을 때 자동으로 메시지를 재시도하는 최대 횟수.
- `key-serializer`, `value-serializer`: 메시지 키와 값에 대한 직렬화 방식.

#### Kafka Producer
```java
import org.springframework.kafka.core.KafkaTemplate;
import org.springframework.stereotype.Service;

@Service
public class KafkaProducerService {
    private final KafkaTemplate<String, String> kafkaTemplate;<br>

    public KafkaProducerService(KafkaTemplate<String, String> kafkaTemplate) {<br>
        this.kafkaTemplate = kafkaTemplate;
    }

    public void sendMessage(String message) {
        kafkaTemplate.send("test-topic", message);
        System.out.println("메시지 전송: " + message);
    }
}
```

#### Kafka Consumer
자동 커밋:
```java
import org.springframework.kafka.annotation.KafkaListener;
import org.springframework.stereotype.Service;

@Service
public class KafkaConsumerService {
    @KafkaListener(topics = "test-topic", groupId = "test-group")
    public void consume(String message) {
        System.out.println("받은 메시지: " + message);
    }
}
```

수동 커밋:
```java
import org.springframework.kafka.annotation.KafkaListener;
import org.springframework.stereotype.Service;

@Service
public class KafkaConsumerService {
    @KafkaListener(topics = "topicName", groupId = "groupId")
	public void consume(String message, Acknowledgment acknowledgment) {
	    // 메시지 처리 로직
	    try {
	        // 메시지 처리 성공
	        acknowledgment.acknowledge();  // 수동 커밋
	    } catch (Exception e) {
	        // 실패 시 처리
	    }
	}
}
```
{% endraw %}