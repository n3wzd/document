---
categories:
- ReactNative
date: '2025-01-25'
title: '[ReactNative] React Native Secure Storage'
---

{% raw %}
`react-native-secure-storage`는 **iOS의 Keychain**과 **Android의 EncryptedSharedPreferences**를 사용하여 민감한 데이터를 안전하게 저장하는 라이브러리입니다. 이 라이브러리도 데이터를 **암호화하여 저장**하며, 보안이 중요한 정보를 안전하게 보관할 수 있습니다.

- **iOS Keychain**과 **Android EncryptedSharedPreferences**를 사용하여 안전한 데이터 저장
- 데이터 암호화 및 복호화 처리
- **react-native-keychain**과 비슷한 기능을 제공하지만, Android에서는 EncryptedSharedPreferences를 사용하여 저장

설치:
```
npm install react-native-secure-storage
```

`react-native-secure-storage.d.ts` 설정: (TypeScript 사용시)
```
// src/types/react-native-secure-storage.d.ts

declare module 'react-native-secure-storage' {
  interface SecureStorageOptions {
    accessible?: string;
    authenticationType?: string;
  }

  interface SecureStorage {
    setItem(key: string, value: string, options?: SecureStorageOptions): Promise<void>;
    getItem(key: string): Promise<string | null>;
    removeItem(key: string): Promise<void>;
    getAllItems(): Promise<{ [key: string]: string }>;
  }

  const SecureStorage: SecureStorage;

  export default SecureStorage;
}
```

사용 예시:
```
import SecureStorage from 'react-native-secure-storage';

// 토큰 저장
const storeToken = async (token: string) => {<br>
  try {
    await SecureStorage.set('user_token', token);
  } catch (e) {
    console.error('Failed to save token:', e);
  }
};

// 토큰 가져오기
const getToken = async () => {<br>
  try {
    const token = await SecureStorage.get('user_token');
    return token;
  } catch (e) {
    console.error('Failed to fetch token:', e);
  }
};

// 토큰 삭제
const removeToken = async () => {<br>
  try {
    await SecureStorage.remove('user_token');
  } catch (e) {
    console.error('Failed to remove token:', e);
  }
};
```
{% endraw %}