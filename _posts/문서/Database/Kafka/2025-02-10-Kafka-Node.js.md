---
categories:
- Kafka
date: '2025-02-10'
title: '[Kafka] Node.js'
---

{% raw %}
`kafkajs`는 Node.js에서 Kafka를 쉽게 사용할 수 있도록 도와주는 라이브러리로, Kafka의 **프로듀서(Producer)**와 **컨슈머(Consumer)** 기능을 모두 지원합니다.

설치:
```
npm install kafkajs
```

#### Kafka Producer
```javascript
const { Kafka } = require('kafkajs')

// Kafka 인스턴스 생성
const kafka = new Kafka({
  clientId: 'my-app',
  brokers: ['localhost:9092'] // Kafka 브로커 주소
})

// 프로듀서 생성
const producer = kafka.producer()

const run = async () => {<br>
  // 프로듀서 연결
  await producer.connect()

  // 메시지 전송
  await producer.send({
    topic: 'test-topic', // 보낼 토픽 이름
    messages: [
      { value: 'Hello Kafka!' },
    ],
  })

  // 프로듀서 연결 종료
  await producer.disconnect()
}

run().catch(console.error)
```

#### Kafka Consumer
```javascript
const { Kafka } = require('kafkajs')

// Kafka 인스턴스 생성
const kafka = new Kafka({
  clientId: 'my-app',
  brokers: ['localhost:9092'] // Kafka 브로커 주소
})

// 컨슈머 생성
const consumer = kafka.consumer({ groupId: 'test-group' })

const run = async () => {<br>
  // 컨슈머 연결
  await consumer.connect()

  // 메시지 수신 처리
  await consumer.subscribe({ topic: 'test-topic', fromBeginning: true })

  // 메시지를 처리하는 부분
  await consumer.run({
    eachMessage: async ({ topic, partition, message }) => {<br>
      console.log({
        value: message.value.toString(),
      })
    },
  })
}

run().catch(console.error)
```
{% endraw %}