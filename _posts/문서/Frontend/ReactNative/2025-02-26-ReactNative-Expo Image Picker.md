---
categories:
- ReactNative
date: '2025-02-26'
title: '[ReactNative] Expo Image Picker'
---

{% raw %}
`expo-image-picker`는 **Expo** 프레임워크에서 제공하는 라이브러리로, 사용자가 **기기에서 이미지를 선택**하거나 **카메라로 사진을 찍을 수 있도록 도와주는 도구**입니다. 이 모듈을 사용하면 갤러리나 카메라* 쉽게 열어 이미지를 선택하고 이를 앱 내에서 처리할 수 있습니다.

1. **갤러리에서 이미지 선택**: 사용자가 기기의 갤러리에서 이미지를 선택할 수 있습니다.
2. **카메라로 사진 촬영**: 사용자가 카메라를 열어 사진을 찍을 수 있습니다.
3. **이미지 메타데이터**: 선택한 이미지의 크기, 유형 등 메타데이터를 가져올 수 있습니다.
4. **이미지 편집**: 편집할 수 있도록 이미지 크기를 자르거나 비율을 맞출 수 있습니다.

설치:
```
npm install expo-image-picker
```

#### 갤러리에서 이미지 선택
```javascript
import * as ImagePicker from 'expo-image-picker';
import React, { useState } from 'react';
import { Button, Image, View } from 'react-native';

export default function App() {
  const [image, setImage] = useState(null);

  const pickImage = async () => {<br>
    // 갤러리 접근 권한 요청
    const permissionResult = await ImagePicker.requestMediaLibraryPermissionsAsync();
    if (permissionResult.status !== 'granted') {
      alert('갤러리 권한이 필요합니다.');
      return;
    }

    // 갤러리에서 이미지 선택
    const result = await ImagePicker.launchImageLibraryAsync({
      mediaTypes: ['image'],
      allowsEditing: true, // 이미지 편집 허용
      aspect: [4, 3], // 비율 설정
      quality: 1, // 품질 설정 (0~1)
    });

    if (!result.canceled) {
      setImage(result.assets[0].uri); // 선택한 이미지 URI 설정
    }
  };

  return (
    <View>
      <Button title="이미지 선택" onPress={pickImage} />
      {image && <Image source={{ uri: image }} style={{ width: 200, height: 200 }} />}
    </View>
  );
}
```

#### 카메라 사진 촬영
```javascript
const takePhoto = async () => {<br>
  // 카메라 권한 요청
  const permissionResult = await ImagePicker.requestCameraPermissionsAsync();
  if (permissionResult.status !== 'granted') {
    alert('카메라 권한이 필요합니다.');
    return;
  }

  // 카메라로 사진 촬영
  const result = await ImagePicker.launchCameraAsync({
    allowsEditing: true,
    aspect: [4, 3],
    quality: 1,
  });

  if (!result.canceled) {
    setImage(result.assets[0].uri); // 촬영한 이미지 URI 설정
  }
};
```
{% endraw %}