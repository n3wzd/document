---
categories:
- ReactNative
date: '2025-01-25'
title: '[ReactNative] React Native Keychain'
---

{% raw %}
`react-native-keychain`은 **iOS의 Keychain**과 **Android의 Keystore**를 사용하여 민감한 데이터를 안전하게 저장하는 라이브러리입니다. 이 라이브러리는 **암호화된 저장소**에 데이터를 저장하고, 앱이 종료되거나 시스템이 재시작되더라도 데이터를 안전하게 유지할 수 있도록 합니다.

- **iOS Keychain**과 **Android Keystore**를 사용하여 안전한 데이터 저장
- 데이터 저장 시 자동으로 암호화 처리
- 사용자가 로그인한 후, 로그인 토큰이나 비밀번호와 같은 민감한 정보를 안전하게 저장할 수 있음

설치:
```
npm install react-native-keychain
```


```
import * as Keychain from 'react-native-keychain';

// 토큰 저장
const storeToken = async (token: string) => {<br>
  try {
    await Keychain.setGenericPassword('user_token', token);
  } catch (e) {
    console.error('Failed to save token:', e);
  }
};

// 토큰 가져오기
const getToken = async () => {<br>
  try {
    const credentials = await Keychain.getGenericPassword();
    return credentials ? credentials.password : null;
  } catch (e) {
    console.error('Failed to fetch token:', e);
  }
};

// 토큰 삭제
const removeToken = async () => {<br>
  try {
    await Keychain.resetGenericPassword();
  } catch (e) {
    console.error('Failed to remove token:', e);
  }
};
```
{% endraw %}