# Kafka
Kafka는 분산 스트리밍 플랫폼으로, 대용량 데이터의 실시간 처리 및 전송을 지원합니다. 주로 로그나 이벤트 데이터를 처리하는 데 사용되며, 데이터를 처리하고 저장하는 시스템 간의 중간 메시지 큐 역할을 합니다. Kafka는 주로 **발행/구독** 모델을 사용하며, 데이터를 **프로듀서**(Producer)가 보내고, **컨슈머**(Consumer)가 받아서 처리합니다.

주요 특징은 다음과 같습니다:

1. **고성능**: 높은 처리량과 낮은 지연 시간을 제공하여 실시간 데이터 스트리밍 처리에 적합합니다.
2. **분산 아키텍처**: Kafka는 분산 시스템으로 여러 서버에 데이터를 분산 저장하고, 이를 통해 고가용성 및 내결함성을 보장합니다.
3. **영속성**: 데이터를 디스크에 저장하여 장애 발생 시에도 데이터 유실 없이 복구할 수 있습니다.
4. **확장성**: 클러스터를 통해 용량을 쉽게 확장할 수 있어, 트래픽이 급증할 때도 효율적으로 처리 가능합니다.

Kafka는 주로 **로그 수집**, **데이터 파이프라인**, **실시간 분석 시스템**, **이벤트 기반 아키텍처**에서 사용됩니다.

## 메시지 큐
메시지 큐는 **비동기적 메시지 전달 시스템**으로, 여러 시스템이나 컴포넌트 간의 **메시지를 저장하고 전달하는 역할**을 합니다. 이를 통해 프로세스 간 통신(IPC)을 간소화하고, 시스템 간의 **비동기적 상호작용**을 가능하게 합니다.

메시지 큐는 큐(queue)라는 자료구조를 사용합니다. 큐는 **선입선출(FIFO, First-In-First-Out)** 방식을 따르기 때문에, 먼저 들어온 메시지가 먼저 처리됩니다.

- **Producer (생산자)**는 메시지를 큐에 전송하고,
- **Consumer (소비자)**는 큐에서 메시지를 받아 처리합니다.

이 과정은 **비동기적**이므로, 생산자는 큐에 메시지를 보내고 즉시 작업을 종료할 수 있으며, 소비자는 그 후에 메시지를 비동기적으로 처리합니다.

### 동작
5. **Producer**는 메시지를 큐에 넣습니다.
6. 큐에 들어온 메시지는 **Consumer**가 처리할 때까지 대기합니다.
7. **Consumer**는 큐에서 메시지를 가져와 처리하고, 처리가 끝나면 큐에서 메시지를 제거합니다.

### 특성
8. **비동기 처리**
    - 생산자와 소비자는 독립적으로 동작합니다. 소비자가 메시지를 처리하는 동안 생산자는 다른 작업을 할 수 있습니다.
9. **내구성(Persistence)**
    - 큐에 저장된 메시지는 시스템 장애가 발생하더라도 안전하게 보존될 수 있습니다. 이를 통해 **메시지 손실을 방지**합니다.
10. **스케일링**
    - 메시지 큐는 다수의 소비자(Consumer)를 추가해 **수평 확장**할 수 있어, 많은 메시지를 동시에 처리할 수 있습니다.
11. **응답 시간 개선**
    - 생산자는 메시지를 큐에 전송한 후 즉시 응답할 수 있으므로 **응답 시간을 단축**할 수 있습니다.
12. **비동기적 통신**
    - 프로세스 간 직접적인 연결을 피하고 **비동기적으로 메시지를 전달**하므로, 시스템 간 결합도가 낮아집니다.

### 활용 예시
#### 전자상거래
전자상거래 플랫폼은 트랜잭션과 사용자 요청을 효율적으로 처리하기 위해 메시지 큐를 사용합니다. 특히 주문 처리 시스템에서 **메시지 큐**는 주문을 비동기적으로 처리하고, 상품 재고를 관리하는 데 중요한 역할을 합니다.

- **Amazon**, **eBay**와 같은 대형 전자상거래 플랫폼은 주문 처리와 결제 시스템에서 **SQS**(Amazon Simple Queue Service)를 사용하여 트래픽을 분산시키고 주문을 안정적으로 처리합니다.
- 사용자 요청이 많아질 때, 메시지 큐를 사용해 주문을 대기열에 넣고, 순차적으로 처리합니다.

#### 금융 서비스
금융 서비스에서는 실시간 거래 처리와 이벤트 기반 시스템을 운영하기 위해 메시지 큐를 사용합니다. 이를 통해 거래 정보나 알림을 비동기적으로 처리하고, 시스템 간의 통합을 원활하게 유지합니다.

- **PayPal**이나 **Stripe**와 같은 결제 서비스는 거래 이벤트를 메시지 큐를 통해 처리하여, 실시간 트랜잭션을 안정적으로 관리합니다.
- 메시지 큐는 비동기적으로 결제 처리, 트랜잭션 기록 업데이트 등을 수행하여 트래픽이 몰리는 상황에서의 성능을 보장합니다.

#### 클라우드 서비스와 마이크로서비스 아키텍처
마이크로서비스 아키텍처에서는 서비스 간 통신을 메시지 큐로 처리하는 것이 일반적입니다. 각 서비스가 독립적으로 동작하고, 서로 간에 메시지를 주고받을 수 있도록 설계됩니다.

- **Netflix**와 **Spotify**는 마이크로서비스 아키텍처를 기반으로 서비스를 운영하며, **Kafka**를 활용하여 서비스 간의 데이터 전송과 이벤트 처리를 관리합니다.
- **Uber**는 **Kafka**와 **Redis**를 사용하여 사용자 요청을 비동기적으로 처리하고, 실시간 데이터를 수집 및 분석합니다.

### 활용 예제: 게임 서버에서 유저 경험치 처리
멀티플레이 게임에서 유저가 몬스터를 처치하면 경험치(EXP)를 획득합니다. 하지만, **경험치 처리를 API 요청마다 즉시 수행하면 서버 부하가 증가**할 수 있습니다. 따라서, **메시지 큐를 사용하여 비동기적으로 경험치를 처리**하면 성능을 최적화할 수 있습니다.

- **서버 A (유저 활동 집계 서버)**: 유저의 게임 이벤트를 감지하고 메시지를 메시지 큐로 보냄.
- **메시지 큐 (Kafka or RabbitMQ)**: 경험치 증가 요청을 큐에 저장하고, 소비자(Consumer)에게 전달.
- **서버 B (게임 서버)**: 큐에서 메시지를 받아 경험치를 계산하고, DB 업데이트.

#### 흐름도
13. 유저가 몬스터를 처치하면 유저 활동 집계 서버(서버 A)는 `EXP 증가 요청`을 메시지 큐에 보냄.
14. 메시지 큐는 해당 요청을 대기열에 저장.
15. 게임 서버(서버 B)가 큐에서 메시지를 가져와 경험치를 계산 후 DB에 반영.
16. 필요할 경우, 경험치 증가 결과를 서버 A로 전송하여 클라이언트에게 UI 업데이트.

#### 구조
17. **서버 A와 B의 역할 분담**:
    - **서버 A**는 클라이언트와의 상호작용을 담당하며, 경험치와 같은 이벤트를 처리합니다. 하지만 실제 유저 데이터는 서버 A에 저장되지 않고, **서버 B**에 저장됩니다.
    - **서버 B**는 유저 데이터와 관련된 모든 작업을 처리하고, **데이터베이스**와 연결되어 유저의 경험치와 같은 데이터를 업데이트합니다.
18. **Kafka의 역할**:
    - Kafka는 서버 간 **메시지 큐** 역할을 하며, 서버 A에서 발생한 이벤트를 서버 B로 전달하는 데 사용됩니다. 클라이언트는 Kafka와 직접적으로 통신하지 않으며, Kafka는 서버 A와 서버 B 간의 **비동기 통신**을 가능하게 합니다.
    - Kafka를 통해 경험치와 같은 데이터 변경 사항을 **비동기적으로 처리**하며, 서버 간 독립적으로 데이터를 처리할 수 있습니다.
19. **비동기 처리 및 Lazy 업데이트**:
    - **비동기 처리** 덕분에 서버 A는 클라이언트의 요청을 즉시 처리하고, 서버 B는 Kafka를 통해 받은 이벤트를 백그라운드에서 처리하여 서버의 부하를 줄입니다.
    - 데이터 업데이트가 즉시 이루어지지 않지만, **Lazy 업데이트** 방식으로 클라이언트가 데이터를 요청할 때 최신 데이터로 갱신됩니다.
20. **데이터 안정성**:
    - Kafka를 통해 **메시지의 안정적인 전송**이 이루어지므로, 데이터가 손실되지 않도록 보장됩니다. 또한, 서버 A에서 클라이언트의 요청에 대한 빠른 응답을 보낸 후에도 Kafka를 통해 데이터를 비동기적으로 처리하여, 최종적으로 서버 B에서 업데이트됩니다.
21. **DB 통합**:
    - 서버 A가 유저 데이터를 별도로 관리하지 않고 서버 B와 DB를 통합하여, **서버 B**에서 모든 유저 데이터를 관리합니다. 이는 DB 분리를 통해 발생할 수 있는 불편함을 해소하고, 데이터 일관성을 보장합니다.

이 구조는 게임 서버와 같은 높은 트래픽을 처리해야 하는 시스템에서 성능을 최적화하고, 확장성과 안정성을 높이기 위한 좋은 접근 방식입니다.

#### 코드 예시
**서버 A (유저 활동 집계 서버) – 경험치 메시지 전송**
```java
@RestController
@RequestMapping("/game")
public class GameController {

    private final KafkaTemplate<String, String> kafkaTemplate;

    public GameController(KafkaTemplate<String, String> kafkaTemplate) {
        this.kafkaTemplate = kafkaTemplate;
    }

    @PostMapping("/gain-exp")
    public ResponseEntity<String> gainExp(@RequestBody ExpEvent event) {
        String message = new ObjectMapper().writeValueAsString(event);
        kafkaTemplate.send("exp-topic", message); // Kafka로 메시지 전송
        return ResponseEntity.ok("EXP 증가 이벤트 전송 완료");
    }
}
```

- 유저가 몬스터를 처치하면 **`/game/gain-exp` API**를 호출.
- 경험치 증가 이벤트(`ExpEvent`)를 Kafka의 **`exp-topic`**에 메시지로 전송.

---

 **서버 B (게임 서버) – 경험치 메시지 소비 및 DB 업데이트**

```java
@Service
public class ExpConsumer {

    private final UserExpService userExpService;

    public ExpConsumer(UserExpService userExpService) {
        this.userExpService = userExpService;
    }

    @KafkaListener(topics = "exp-topic", groupId = "exp-group")
    public void consumeExp(String message) {
        ExpEvent event = new ObjectMapper().readValue(message, ExpEvent.class);
        userExpService.updateUserExp(event.getUserId(), event.getExp());
    }
}
```

- `exp-topic`에 저장된 경험치 메시지를 **실시간으로 소비(consume)**.
- `userExpService.updateUserExp()`를 호출하여 DB의 유저 경험치를 업데이트.

## 설치
### Linux
Kafka를 실행하려면 먼저 **Zookeeper**와 Kafka 브로커를 설정해야 합니다. [Kafka 공식 사이트](https://kafka.apache.org/downloads)에서 Kafka를 다운로드합니다.

압축을 해제한 후 Kafka 폴더에서 터미널을 열고 다음 명령어를 실행합니다.
```
# Zookeeper 실행 (Kafka 3.x 이후 버전에서는 필요 없음)
bin/zookeeper-server-start.sh config/zookeeper.properties  

# Kafka 브로커 실행
bin/kafka-server-start.sh config/server.properties
```

Kafka가 정상적으로 실행되었는지 확인하려면 다음 명령어로 토픽을 생성할 수 있습니다.
```
bin/kafka-topics.sh --create --topic test-topic --bootstrap-server localhost:9092
```

### Windows
Kafka는 Windows에서 **Zookeeper + Kafka 브로커**를 실행해야 합니다.

1. [Apache Kafka 공식 사이트](https://kafka.apache.org/downloads)에서 **Binary 다운로드**
2. 압축을 해제하고 원하는 폴더(`C:\kafka` 등)로 이동

Kafka는 **JDK 8 이상**이 필요합니다.

버전 확인:
```
java -version
```

`config/server.properties` 파일에서 **Windows 환경에 맞게 수정해야** 합니다.
```
log.dirs=C:/kafka/logs
```

`config/zookeeper.properties` 파일도 동일하게 경로를 수정합니다.
```
dataDir=C:/kafka/zookeeper-data
```

다음으로 **Zookeeper**를 실행합니다.
```
cd C:\kafka bin\windows\zookeeper-server-start.bat config\zookeeper.properties
```

새로운 터미널을 열고 Kafka 브로커를 실행합니다.
```
cd C:\kafka bin\windows\kafka-server-start.bat config\server.properties
```

Kafka가 정상적으로 실행되었는지 확인하려면 **테스트용 토픽**을 만들어 봅니다.
```
bin\windows\kafka-topics.bat --create --topic test-topic --bootstrap-server localhost:9092
```

토픽 목록 확인:
```
bin\windows\kafka-topics.bat --list --bootstrap-server localhost:9092
```

## 구성
Kafka는 분산 메시징 시스템으로, **대용량의 데이터 스트리밍**과 **실시간 데이터 처리**를 지원하는 시스템입니다.

### Producer (생산자)
- **Producer**는 Kafka에 메시지를 보내는 클라이언트입니다. 생산자는 Kafka의 특정 **토픽(Topic)**에 데이터를 전송합니다.
- Producer는 메시지를 보낼 때 메시지가 **어떤 파티션**에 저장될지 결정하는데, 기본적으로 Kafka는 메시지를 **파티션 단위**로 분배합니다.
- 메시지 전송 시, **키**가 있으면 Kafka는 동일한 키를 가진 메시지를 동일한 파티션으로 보냅니다.

### Consumer (소비자)
- **Consumer**는 Kafka에서 메시지를 소비하는 클라이언트입니다. 소비자는 특정 **토픽**에 대한 데이터를 읽습니다.

### Consumer Group (소비자 그룹)
- **Consumer Group**은 Kafka에서 메시지를 **동시 처리하는 여러 개의 컨슈머(Consumer)들**을 그룹화한 단위입니다.
- 이 그룹은 **하나의 논리적 소비자**처럼 동작하여, 같은 메시지를 여러 컨슈머가 중복해서 처리하지 않도록 합니다. 즉, 여러 개의 컨슈머가 있을 때 **메시지를 나누어 처리**하는 방식입니다.
- 컨슈머 그룹은 **병렬 처리를 최적화**하는 용도로, **토픽**과 **독립적인 개념**입니다. 따라서 하나의 컨슈머 그룹이 여러 토픽을 구독하고 처리하는 것이 가능합니다. (단, 권장되는 방식은 아닙니다. 각 토픽마다 별도의 컨슈머 그룹을 사용하는 방법이 관리와 확장성 측면에서 유리합니다.)

### Topic (토픽)
- **Topic**은 Kafka에서 메시지를 저장하는 **논리적** 카테고리입니다.
- 각 토픽은 **여러 파티션**을 가질 수 있습니다. 파티션을 통해 데이터를 분산하여 저장하고, **병렬 처리**할 수 있게 됩니다.

### Partition (파티션)
- **Partition**은 **토픽의 물리적 분할 단위**로, 여러 메시지를 저장합니다.
- 각 파티션은 **순차적인 로그**를 가지고 있으며,  **메시지는 파티션 내에서 순차적**으로 처리됩니다.
- Kafka는 파티션을 여러 개의 **브로커**에 분산시켜 저장하여 **확장성**과 **고가용성**을 제공합니다.

예시:
- **Topic: "orders"**
	- **Partition 0**:
	    - 메시지 1: 주문 1 (Offset 0)
	    - 메시지 2: 주문 2 (Offset 1)
	    - 메시지 3: 주문 3 (Offset 2)
	    - 메시지 4: 주문 4 (Offset 3)
	- **Partition 1**:
		- 메시지 1: 주문 5 (Offset 0)
		- 메시지 2: 주문 6 (Offset 1)

### Message (메시지)
- **Message**는 **Producer가 생성하고 Consumer가 처리하는 데이터 단위**입니다.
- Kafka에서 메시지는 **불변**하며, 한번 저장된 메시지는 변경되지 않습니다.
- 메시지는 **로그**처럼 저장되어, 이후 시간에 따라 **다시 읽히거나** 다른 시스템에서 처리될 수 있습니다.

Kafka에서 **메시지**는 주로 다음과 같은 구조로 구성됩니다:
1. **Key** (선택적)
    - 메시지의 **식별자** 또는 **구분자**로 사용될 수 있습니다. 또한 메시지끼리 **순서를 보장**하려면 Key가 필수입니다.
    - 같은 **Key**를 가진 메시지는 항상 같은 파티션에 저장됩니다. Kafka에서 **Key**가 있는 메시지가 **어느 파티션**에 저장될지는 Kafka의 **파티셔너**에 의해 결정됩니다.
	- **기본 파티셔너**는 메시지의 **Key**를 해시값으로 변환하여 해당 파티션에 메시지를 할당합니다. 예를 들어, 메시지의 Key가 "user_id"라면, 이 **Key** 값을 해시한 결과에 따라 특정 파티션으로 메시지가 보내집니다.
2. **Value**
    - 메시지의 실제 **데이터** 부분입니다. 예를 들어, **주문 정보**, **채팅 메시지**, **로그 데이터** 등 실제 처리하려는 데이터가 포함됩니다.
3. **Timestamp**
    - 메시지가 생성된 시간을 나타냅니다. 이 정보는 주로 데이터 처리 시간에 중요한 역할을 합니다.
4. **Headers** (선택적)
    - 메시지에 추가적인 **메타데이터**를 포함할 수 있습니다. 예를 들어, 메시지의 **발송처**, **우선순위**, **분류 정보** 등을 포함할 수 있습니다.

예시(주문 정보 메시지):
- **Key**: "user123"
- **Value**: `{ "order_id": "001", "product": "Laptop", "amount": 1200 }`
- **Timestamp**: `2025-02-09T12:00:00Z`
- **Headers**: `{ "priority": "high", "source": "website" }`

### Offset (오프셋)
- 메시지를 읽을 때 **Offset**을 기록하여, 소비자는 **마지막으로 읽은 메시지의 위치를 추적**하고, 재시작 시 같은 위치에서 메시지를 읽을 수 있습니다.
- 오프셋은 **소비자 그룹 단위로 구별**됩니다. 즉, 소비자 그룹 별로 오프셋이 다릅니다.

### Broker (브로커)
- **Broker**는 Kafka 클러스터의 서버입니다. **하나의 Kafka 클러스터는 여러 개의 브로커**로 구성됩니다.
- 각 브로커는 토픽의 일부 파티션을 관리하며, 여러 브로커가 서로 협력하여 메시지를 분산하고 복제합니다.

### Zookeeper
- **Zookeeper**는 Kafka 클러스터의 **메타데이터 관리**와 **클러스터 상태**를 관리하는 역할을 합니다. Zookeeper는 Kafka의 **클러스터 관리**, **파티션 리더 선출**, **브로커의 상태 확인** 등을 담당합니다.

## 동작
### 1. 메시지 전송 (Producer → Kafka Broker)
- **Producer**는 Kafka의 **토픽**에 메시지를 보냅니다. 메시지는 각 **파티션**에 분배되어 저장됩니다.
- 메시지가 파티션에 어떻게 배분될지는 **키**와 **파티션 수**에 따라 결정됩니다. 기본적으로 Kafka는 **키를 해시하여** 동일한 키를 가진 메시지를 같은 파티션에 배분하려고 합니다.

### 2. 메시지 저장 (Kafka Broker)
- 각 Kafka 브로커는 **디스크에 메시지를 저장**합니다. 메시지는 **순차적인 로그**로 기록되며, **시간 순서대로 저장**됩니다.
- Kafka는 메시지를 **디스크에 영속적으로 저장**하는 방식으로, **내구성**과 **고가용성**을 보장합니다.
- 메시지는 일정 시간이 지나거나 특정 조건에 따라 **삭제되거나 압축**될 수 있습니다.

### 3. 메시지 복제 (Replication)
- Kafka는 **내구성**과 **고가용성**을 보장하기 위해 **메시지 복제**를 사용합니다. 각 파티션은 여러 **복제**를 가질 수 있으며, 레플리카는 다른 브로커에 분산됩니다.
- Kafka는 **리더-팔로워 모델**을 사용합니다. 하나의 파티션은 **리더**를 가지고 있으며, 다른 브로커들은 이 리더의 복사본인 **팔로워** 역할을 합니다. 만약 리더 브로커가 실패하면, 팔로워 중 하나가 자동으로 리더 역할을 맡습니다.

### 4. 메시지 소비 (Kafka Consumer)
- **Consumer**는 Kafka의 **토픽**에서 메시지를 읽습니다. 메시지는 파티션을 따라 **순차적**으로 처리되며, **오프셋**을 기준으로 읽습니다.
- Kafka에서는 각 **Consumer Group**이 각각의 파티션을 읽을 수 있도록 분배합니다. 이렇게 하면 **파티션**이 여러 소비자에게 분배되어 병렬로 데이터를 처리할 수 있습니다.

### 5. 메시지 삭제
- 메시지는 **소비된 후에도 설정된 retention 정책에 의해 삭제되지 않으며**, 지정된 **보존 기간**이나 **크기 조건**이 충족될 때 삭제됩니다. 이 시점이 지나기 전까지는 다른 클라이언트가 여전히 메시지를 읽을 수 있습니다.
- Kafka에서 **파티션 데이터가 삭제**되면, **그 파티션의 복제본**도 **모든 브로커에서 동시에 삭제**됩니다.

## 관리
### 토픽 생성
#### 자동 생성
Kafka는 기본적으로 **자동 생성** 기능을 제공하며, **프로듀서**가 메시지를 첫 번째로 전송하는 토픽이 없다면 자동으로 해당 토픽을 생성합니다. 이때 파티션 수와 복제 factor는 서버 설정에 따라 기본값으로 설정됩니다.

#### 수동 생성
`kafka-topics.sh`를 사용하여 토픽을 생성할 수 있습니다. 토픽을 생성할 때 파티션 수와 복제 factor를 지정할 수 있습니다.

```bash
bin/kafka-topics.sh --create --topic <토픽명> --bootstrap-server <Kafka 브로커 주소> --partitions <파티션 수> --replication-factor <복제 수>
```

관리자가 **수동으로** 토픽을 생성하고 관리할 수 있습니다. **Admin API**를 사용하면, 클라이언트에서 직접 토픽을 생성하고 설정할 수 있습니다.

```java
import org.apache.kafka.clients.admin.*;
import java.util.*;

public class KafkaTopicCreate {
    public static void main(String[] args) {
        Properties props = new Properties();
        props.put("bootstrap.servers", "localhost:9092");
        AdminClient adminClient = AdminClient.create(props);

        // 토픽 생성 (이름, 파티션 수, 복제 수 설정)
        NewTopic newTopic = new NewTopic("my_topic", 3, (short) 1); // 3 파티션, 복제 factor 1

        // 토픽 생성 요청
        adminClient.createTopics(Collections.singletonList(newTopic));
        System.out.println("Topic 'my_topic' created successfully!");

        adminClient.close();
    }
}
```


### 토픽 목록 조회
현재 Kafka 클러스터에서 존재하는 모든 토픽을 조회하려면 다음 명령어를 사용합니다.

```bash
bin/kafka-topics.sh --list --bootstrap-server <Kafka 브로커 주소>
```

### 토픽 정보 조회
특정 토픽에 대한 정보를 조회할 수 있습니다. 이 명령어를 사용하면 파티션 수, 각 파티션의 리더 및 복제본 등의 정보를 확인할 수 있습니다.

```bash
bin/kafka-topics.sh --describe --topic <토픽명> --bootstrap-server <Kafka 브로커 주소>
```

### 토픽 설정 수정
특정 토픽의 설정을 변경할 수도 있습니다. 예를 들어, **메시지 TTL(Time-to-Live)**을 설정하거나 **리텐션 시간**을 설정할 수 있습니다.

```bash
bin/kafka-topics.sh --alter --topic <토픽명> --config <설정명>=<설정값> --bootstrap-server <Kafka 브로커 주소>
```

### 토픽 삭제
토픽을 삭제하려면 다음 명령어를 사용합니다. 단, Kafka의 설정에서 **`delete.topic.enable`**이 `true`로 설정되어 있어야 합니다.

```bash
bin/kafka-topics.sh --delete --topic <토픽명> --bootstrap-server <Kafka 브로커 주소>
```

**DeleteTopics API**를 사용하여 클라이언트가 직접 토픽을 삭제할 수 있습니다.

```java
import org.apache.kafka.clients.admin.*;
import java.util.*;

public class KafkaTopicDelete {
    public static void main(String[] args) {
        Properties props = new Properties();
        props.put("bootstrap.servers", "localhost:9092");
        AdminClient adminClient = AdminClient.create(props);

        // 토픽 삭제
        adminClient.deleteTopics(Collections.singletonList("my_topic"));

        System.out.println("Topic 'my_topic' deleted successfully!");

        adminClient.close();
    }
}
```

다만, **파티션은 삭제할 수 없습니다**. 파티션은 오직 **토픽 삭제**로만 삭제가 가능합니다.

### 파티션 관리
파티션 수는 토픽 생성 시 설정되며, **추가로 파티션을 늘리는 작업만** 가능합니다. 다만, 기존 파티션의 데이터는 새로 추가된 파티션으로 이동하지 않으며, 새로운 파티션만 메시지를 받습니다.

```bash
bin/kafka-topics.sh --alter --topic <토픽명> --partitions <새로운 파티션 수> --bootstrap-server <Kafka 브로커 주소>
```

```java
import org.apache.kafka.clients.admin.*;
import java.util.*;

public class KafkaPartitionAdd {
    public static void main(String[] args) throws Exception {
        Properties props = new Properties();
        props.put("bootstrap.servers", "localhost:9092");

        AdminClient adminClient = AdminClient.create(props);

        // 파티션 수 증가
        NewPartitions newPartitions = NewPartitions.increaseTo(5);  // 5 파티션으로 증가
        Map<String, NewPartitions> newPartitionMap = new HashMap<>();
        newPartitionMap.put("my_topic", newPartitions);

        // 파티션 수 변경
        adminClient.createPartitions(newPartitionMap).all().get();
        System.out.println("Partitions increased to 5 for topic 'my_topic'");

        adminClient.close();
    }
}
```

### Kafka의 토픽 및 파티션 관련 설정
Kafka는 클러스터의 **자동 파티션 할당** 및 **파티션 리밸런싱**을 관리할 수 있습니다. 이러한 설정은 `server.properties` 파일에서 설정할 수 있습니다:

- `num.partitions`: 기본 파티션 수
- `log.retention.hours`: 로그 파일의 유지 시간

```properties
num.partitions=3
log.retention.hours=168
```

## 분산 시스템
Kafka는 **분산 시스템**이므로, **하나의 클러스터 안에 여러 개의 브로커를 두고 운영**하는 방식이 기본적인 설정입니다. 여러 개의 브로커를 사용하는 이유는 다음과 같습니다.

- **확장성(Scalability)**
    - 하나의 브로커가 감당할 수 있는 메시지 처리량에는 한계가 있습니다.
    - 여러 개의 브로커를 추가하면 **더 많은 데이터를 저장하고 더 많은 클라이언트를 처리**할 수 있습니다.
- **부하 분산(Load Balancing)**
    - Kafka는 데이터를 **파티션(Partition)** 단위로 저장하고 관리합니다.
    - 파티션을 여러 개의 브로커에 나누어 저장하면 **데이터 처리 속도가 향상**됩니다.
- **고가용성(High Availability)**
    - Kafka는 **복제(replication)** 기능을 통해 데이터를 여러 브로커에 저장할 수 있습니다.
    - 특정 브로커가 장애로 다운되더라도, **다른 브로커에 저장된 복제본을 사용하여 데이터 손실을 방지**할 수 있습니다.
- **병렬 처리(Parallel Processing)**
    - 여러 개의 브로커가 각각 다른 파티션을 관리하면, **Consumer 그룹이 병렬로 데이터를 처리**할 수 있습니다.
    - 이를 통해 Kafka의 처리 속도가 대폭 향상됩니다.

**클라이언트**는 Kafka의 내부 동작, 여러 브로커의 관리, 파티션 처리 등을 **신경 쓸 필요 없이** 메시지를 보내고 받을 수 있습니다. Kafka의 **추상화** 덕분에 복잡한 시스템 동작을 클라이언트가 알 필요는 없습니다. 또한 **브로커 간 동작**은 Kafka 클러스터가 **자동으로 처리**하며, 복제, 파티션 관리, 장애 처리 등을 브로커가 알아서 관리하므로 클라이언트는 별도로 관리할 필요가 없습니다.

### 구성법
Kafka 클러스터를 구성할 때, **각 브로커는 고유한 `broker.id`를 가져야 합니다**.

**각 브로커가 사용할 설정 파일을 생성** (`server.properties`)
```
cp config/server.properties config/server-1.properties
cp config/server.properties config/server-2.properties

```
    
**각 설정 파일을 수정** (`server-1.properties`, `server-2.properties`)
```
broker.id=1
log.dirs=/tmp/kafka-logs-1
listeners=PLAINTEXT://localhost:9093
```

```
broker.id=2
log.dirs=/tmp/kafka-logs-2
listeners=PLAINTEXT://localhost:9094
```

**각 브로커 실행**
```
bin/kafka-server-start.sh config/server-1.properties &
bin/kafka-server-start.sh config/server-2.properties &
```
    
**브로커가 정상적으로 실행되었는지 확인**
```
bin/kafka-topics.sh --list --bootstrap-server localhost:9092
```

### 브로커 개수 예시
Kafka는 기본적으로 **3개 이상의 브로커를 운영하는 것이 권장**됩니다.  
특히 **복제(replication) 및 장애 조치(failover)** 기능을 활용하려면 **최소 3개의 브로커**가 필요합니다.

- 소규모 서비스: **3~5개 브로커**
- 중간 규모: **5~10개 브로커**
- 대규모 서비스 (예: LinkedIn, Netflix): **수백 개의 브로커**

## 멀티 지역 클러스터
**멀티 지역(Multi-region) 클러스터**는 **여러 지역(Region)에 걸쳐 분산된 Kafka 클러스터**를 의미합니다.

5. **여러 지역(Region)에 브로커 배치**
    - 각 지역에 독립적인 **Kafka 브로커**들을 배치하여 하나의 Kafka 클러스터를 여러 물리적 위치에 분산시킬 수 있습니다. 예를 들어, 미국과 유럽에 각각 Kafka 클러스터가 배치될 수 있습니다.
6. **데이터 복제**
    - 멀티 지역 클러스터에서는 **데이터 복제**가 지역 간에 이루어집니다. 즉, 한 지역에서 발생한 데이터는 다른 지역의 Kafka 클러스터로 복제되어 **고가용성**을 보장합니다.
    - 복제는 **서버 장애**나 **네트워크 장애**가 발생할 경우에도 데이터 손실 없이 클러스터를 유지할 수 있게 도와줍니다.
7. **Geo-Replication (지역 간 복제)**
    - Kafka에서는 **Geo-Replication** 기능을 제공하여 한 지역의 Kafka 클러스터에서 다른 지역의 클러스터로 데이터를 복제합니다. 이를 통해 글로벌 서비스를 위한 데이터 복제와 동기화가 가능해집니다.
    - **MirrorMaker**와 같은 도구를 사용하여 지역 간 데이터를 **자동으로 복제**하고, **데이터 일관성**을 유지할 수 있습니다.
8. **지연 시간 최소화**
    - 사용자나 애플리케이션이 여러 지역에 분산되어 있을 때, **각 지역에 가까운 Kafka 클러스터**에서 데이터를 처리하도록 할 수 있습니다. 이를 통해 **지연 시간**을 최소화하고, 사용자 경험을 향상시킬 수 있습니다.
9. **Kafka의 투명한 분산 처리**  
    - 클라이언트 입장에서 Kafka는 **단일 클러스터처럼 동작**하므로, 물리적으로 떨어져 있는 여러 지역의 브로커 간의 동작을 신경 쓸 필요 없이 **추상화된 방식으로 통신**이 가능합니다.
    - 클라이언트는 Kafka가 제공하는 주제(Topic)를 통해 서로 메시지를 송수신하며, Kafka가 내부적으로 메시지를 여러 지역에 분배하고 복제합니다. 

### 장점
10. **고가용성 (High Availability)**  
    여러 지역에 Kafka 클러스터를 배치함으로써, 하나의 지역에서 장애가 발생하더라도 **다른 지역에서 서비스를 계속 제공**할 수 있어 시스템의 가용성이 향상됩니다.
11. **재해 복구 (Disaster Recovery)**  
    자연 재해, 네트워크 장애 등으로 특정 지역의 클러스터가 손상되더라도 **다른 지역에서 복제된 데이터를 사용**하여 서비스 중단을 방지하고 빠르게 복구할 수 있습니다.
12. **상호 통신**  
    - 멀티 지역 Kafka 클러스터에서 클라이언트 A가 미국에 있고, 클라이언트 B가 유럽에 있더라도, **클라이언트 A**가 보낸 메시지는 **미국 Kafka 클러스터**에서 **유럽 Kafka 클러스터**로 복제되어 **클라이언트 B**에게 전달됩니다. 따라서, **멀리 떨어져 있어도 통신이 가능**합니다.

### 단점
13. **네트워크 비용**
    - 여러 지역 간 데이터를 복제하는 데는 **네트워크 비용**이 발생할 수 있습니다. 특히, 글로벌 규모의 클러스터에서는 **지역 간 네트워크 트래픽**이 많이 발생하므로 이 비용을 관리해야 합니다.
14. **데이터 일관성 유지**
    - 멀티 지역 클러스터에서는 **데이터 일관성**을 유지하는 것이 중요합니다. 네트워크 지연이나 장애로 인해 데이터가 **비동기적으로 복제**될 수 있기 때문에, 데이터 일관성을 보장하기 위한 **복제 설정**과 **동기화 전략**을 신중히 설계해야 합니다.
15. **복잡한 설정과 관리**
    - 여러 지역에 분산된 클러스터를 관리하는 것은 **단일 지역 클러스터보다 복잡**할 수 있습니다. **각 지역의 브로커 설정**, **네트워크 트래픽 관리**, **복제 정책 설정** 등을 모두 고려해야 하므로 관리 부담이 커질 수 있습니다.

### 구현 방법
16. **MirrorMaker**  
    Kafka에서는 **MirrorMaker**라는 도구를 사용하여 **지역 간 복제**를 수행할 수 있습니다. 이 도구는 한 클러스터에서 다른 클러스터로 메시지를 복제하는 데 사용됩니다.
17. **Kafka Connect**  
    **Kafka Connect**를 활용하여 데이터 파이프라인을 구축하고, 여러 지역에 분산된 Kafka 클러스터 간의 데이터 이동을 자동화할 수 있습니다.

## 클라이언트
### Spring Boot
의존성 추가:
```gradle
implementation 'org.springframework.kafka:spring-kafka:3.0.0'
```

#### Kafka Producer
```java
import org.springframework.kafka.core.KafkaTemplate;
import org.springframework.stereotype.Service;

@Service
public class KafkaProducerService {
    private final KafkaTemplate<String, String> kafkaTemplate;

    public KafkaProducerService(KafkaTemplate<String, String> kafkaTemplate) {
        this.kafkaTemplate = kafkaTemplate;
    }

    public void sendMessage(String message) {
        kafkaTemplate.send("test-topic", message);
        System.out.println("메시지 전송: " + message);
    }
}
```

#### Kafka Consumer
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
