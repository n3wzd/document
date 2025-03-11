---
categories:
- ReactNative
date: '2025-02-05'
title: '[ReactNative] AsyncStorage'
---

{% raw %}
`AsyncStorage`는 **React Native**에서 제공하는 **비동기적(key-value) 데이터 저장 방식**입니다. 이 저장소는 앱이 종료된 후에도 데이터를 유지할 수 있으며, 간단한 설정으로 영구 저장 가능한 데이터를 저장할 수 있습니다.

- **비동기적**: 데이터를 비동기적으로 저장하고 불러옵니다.
- **영구 저장**: 앱을 종료하더라도 데이터가 저장되어 유지됩니다.
- **간단한 데이터 저장**: `key-value` 형태로 데이터를 저장합니다.
- **보안 미지원**: 민감한 데이터는 암호화되지 않으므로 보안이 중요한 데이터에는 적합하지 않습니다.

설치:
```
npm install @react-native-async-storage/async-storage
```

※ `react-native-async-storage`는 구버전으로, 더 이상 지원되지 않습니다.

#### 데이터 저장
```
import AsyncStorage from '@react-native-async-storage/async-storage';

// 데이터 저장
const storeData = async () => {<br>
  try {
    await AsyncStorage.setItem('user_token', '123456'); // key-value로 저장
  } catch (error) {
    console.error("저장 실패", error);
  }
};
```

#### 데이터 읽기
```
// 데이터 읽기
const getData = async () => {<br>
  try {
    const value = await AsyncStorage.getItem('user_token');
    if(value !== null) {
      console.log('저장된 값:', value);
    }
  } catch (error) {
    console.error("불러오기 실패", error);
  }
};
```

#### 데이터 삭제
```
// 데이터 삭제
const removeData = async () => {<br>
  try {
    await AsyncStorage.removeItem('user_token');
    console.log('데이터 삭제 완료');
  } catch (error) {
    console.error("삭제 실패", error);
  }
};
```

#### 모든 데이터 삭제
```
// 모든 데이터 삭제
const clearData = async () => {<br>
  try {
    await AsyncStorage.clear();
    console.log('모든 데이터 삭제 완료');
  } catch (error) {
    console.error("초기화 실패", error);
  }
};
```
{% endraw %}