---
categories:
- NodeJs
date: '2025-03-01'
title: '[NodeJs] async-mutex'
---

{% raw %}
`async-mutex`는 JavaScript/TypeScript의 비동기 환경에서 Mutex(뮤텍스, 상호 배제)를 구현하는 라이브러리입니다.

보통 비동기 코드에서는 여러 개의 `async` 함수가 동시에 실행될 수 있기 때문에, **공유 자원에 대한 경쟁 상태(Race Condition)** 가 발생할 수 있습니다. 이를 방지하기 위해 **한 번에 하나의 비동기 함수만 실행되도록 강제**하는 것이 `Mutex`입니다.

설치:
```
npm install async-mutex
```

### `runExclusive()`
- `runExclusive()`를 사용하면 한 번에 하나의 함수만 실행되도록 보장됩니다.
- `criticalSection(2)`, `criticalSection(3)`은 1번이 끝날 때까지 대기합니다.

```ts
import { Mutex } from 'async-mutex';

const mutex = new Mutex();

async function criticalSection(id: number) {
  await mutex.runExclusive(async () => {<br>
    console.log(`${id} 진입`);
    await new Promise(resolve => setTimeout(resolve, 1000)); // 1초 대기<br>
    console.log(`${id} 종료`);
  });
}

criticalSection(1);
criticalSection(2);
criticalSection(3);
```

### `acquire()`, `release()`
- `acquire()`를 사용해 **직접 락을 획득**하고, 작업이 끝나면 `release()`를 호출합니다.
- `try-finally`를 사용해 **오류가 발생해도 락을 해제**하도록 보장합니다.

```ts
import { Mutex } from 'async-mutex';

const mutex = new Mutex();

async function task(id: number) {
  const release = await mutex.acquire();
  try {
    console.log(`${id} 실행 중`);
    await new Promise(resolve => setTimeout(resolve, 1000));<br>
  } finally {
    release(); // 반드시 release() 호출
    console.log(`${id} 종료`);
  }
}

task(1);
task(2);
task(3);
```
{% endraw %}