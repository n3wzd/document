---
categories:
- ReactNative
date: '2025-01-25'
title: '[ReactNative] Expo Secure Store'
---

{% raw %}
`expo-secure-store`는 Expo 프로젝트에서 보안 저장소 기능을 제공하는 라이브러리입니다. 이 라이브러리는 중요한 데이터(예: 토큰, 사용자 인증 정보 등)를 안전하게 저장하고 관리할 수 있도록 도와줍니다. `expo-secure-store`는 데이터를 암호화하여 저장하므로 민감한 정보를 안전하게 처리할 수 있습니다.

- **암호화된 저장소**: 데이터를 안전하게 암호화하여 저장합니다.
- **플랫폼 독립성**: iOS와 Android에서 동일한 API를 사용하여 안전한 저장소에 접근할 수 있습니다.
- **간단한 API**: 간단한 메서드를 사용하여 데이터를 저장, 가져오기, 삭제할 수 있습니다.

설치:
```
expo install expo-secure-store
```

- `setItemAsync(key, value)`: 지정된 `key`에 `value`를 저장합니다.
- `getItemAsync(key)`: 지정된 `key`에 해당하는 값을 가져옵니다.
- `deleteItemAsync(key)`: 지정된 `key`에 해당하는 값을 삭제합니다.
```
import * as SecureStore from 'expo-secure-store';

// 토큰 저장
const storeToken = async (token: string) => {<br>
  try {
    await SecureStore.setItemAsync('user_token', token);  // 'setItemAsync' 사용
  } catch (e) {
    console.error('Failed to save token:', e);
  }
};

// 토큰 가져오기
const getToken = async () => {<br>
  try {
    const token = await SecureStore.getItemAsync('user_token');  // 'getItemAsync' 사용
    return token;
  } catch (e) {
    console.error('Failed to fetch token:', e);
  }
};

// 토큰 삭제
const removeToken = async () => {<br>
  try {
    await SecureStore.deleteItemAsync('user_token');  // 'deleteItemAsync' 사용
  } catch (e) {
    console.error('Failed to remove token:', e);
  }
};
```
{% endraw %}