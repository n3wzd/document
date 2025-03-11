---
categories:
- ReactNative
date: '2025-02-15'
title: '[ReactNative] React Native Rsa Native'
---

{% raw %}
`react-native-rsa-native`는 React Native 환경에서 RSA 암호화와 관련된 기능을 제공하는 라이브러리입니다. 이 라이브러리는 RSA 암호화 알고리즘을 구현하여 모바일 애플리케이션에서 데이터를 암호화하고 복호화하는 작업을 수행할 수 있게 해줍니다.

설치:
```
npm install react-native-rsa-native
```

예시:
```
import RsaNative from 'react-native-rsa-native';

// 키 생성
const generateKey = async () => {<br>
  try {
    const keys = await RsaNative.generateKeys(2048);
    console.log(keys);  // 공개키(publicKey), 개인키(privateKey)
  } catch (error) {
    console.error(error);
  }
};

// 데이터 암호화
const encryptData = async (data, publicKey) => {<br>
  try {
    const encryptedData = await RsaNative.encrypt(data, publicKey);
    console.log('Encrypted:', encryptedData);
  } catch (error) {
    console.error(error);
  }
};

// 데이터 복호화
const decryptData = async (encryptedData, privateKey) => {<br>
  try {
    const decryptedData = await RsaNative.decrypt(encryptedData, privateKey);
    console.log('Decrypted:', decryptedData);
  } catch (error) {
    console.error(error);
  }
};
```
{% endraw %}