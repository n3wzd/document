---
categories:
- ReactNative
date: '2025-02-13'
title: '[ReactNative] WebSocket'
---

{% raw %}
Expo에서 웹소켓을 사용하려면, 기본적으로 **`WebSocket` API**를 사용하면 됩니다. Expo는 네이티브 코드 없이 웹소켓을 지원하므로, 기본적으로 제공하는 `WebSocket` 클래스를 통해 서버와의 연결을 관리할 수 있습니다.

#### 웹소켓 연결
웹소켓 연결 요청은 클라이언트에서 **`WebSocket`** 객체를 생성하면서 자동으로 이루어집니다.
    
```
const socket = new WebSocket('ws://yourserver.com/socket');
```
    
#### 웹소켓 이벤트 처리
웹소켓 연결이 열리면 `onopen` 이벤트가 발생하고, 메시지가 오면 `onmessage` 이벤트가 발생합니다. 오류가 발생하면 `onerror`, 연결이 종료되면 `onclose` 이벤트가 발생합니다.
    
```
socket.onopen = () => {<br>
  console.log('WebSocket connected');
  // 연결이 성공했을 때 할 일
};

socket.onmessage = (event) => {<br>
  console.log('Message received: ', event.data);
  // 서버에서 받은 메시지 처리
};

socket.onerror = (error) => {<br>
  console.log('WebSocket error: ', error);
  // 오류 처리
};

socket.onclose = (event) => {<br>
  console.log('WebSocket closed: ', event);
  // 연결 종료 처리
};
```
    
#### 메시지 보내기
클라이언트에서 서버로 메시지를 보내려면 `send` 메서드를 사용합니다.

```
socket.send('Hello, server!');
```

#### 웹소켓 연결 종료
연결을 종료하려면 `close` 메서드를 호출합니다.

```
socket.close();
```
{% endraw %}