---
categories:
- ReactNative
date: '2025-01-26'
title: '[ReactNative] React Native Vector Icons'
---

{% raw %}
`react-native-vector-icons`는 React Native 애플리케이션에서 확장 가능한 벡터 아이콘을 사용할 수 있게 해주는 라이브러리입니다. 다양한 인기 있는 아이콘 세트를 제공하며, 버튼, 네비게이션, UI 요소 등에서 활용할 수 있습니다.

1. **아이콘 세트 제공**: MaterialIcons, FontAwesome, Ionicons, Feather 등 다양한 아이콘 세트를 지원합니다.
2. **확장 가능**: 벡터 기반 아이콘이므로 크기를 조정해도 품질 손상이 없습니다.
3. **커스터마이징 가능**: 색상, 크기 등 다양한 스타일을 쉽게 적용할 수 있습니다.
4. **크로스 플랫폼**: iOS와 Android에서 모두 사용할 수 있습니다.

설치 :
```
npm install react-native-vector-icons
```

React Native 0.60 이상에서는 자동 링크가 적용됩니다. 그렇지 않은 경우 `android/app/build.gradle`에 다음을 추가하세요:

```
apply from: "../../node_modules/react-native-vector-icons/fonts.gradle"
```

#### 사용
```
import Icon from 'react-native-vector-icons/MaterialIcons';

const App = () => {<br>
  return (
    <Icon name="home" size={30} color="#900" />
  );
};

export default App;
```

이 코드는 MaterialIcons 세트에서 `home` 아이콘을 가져와 크기와 색상을 설정한 예제입니다.
{% endraw %}