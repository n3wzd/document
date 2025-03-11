---
categories:
- ReactNative
date: '2025-02-23'
title: '[ReactNative] React Native Picker Select'
---

{% raw %}
`react-native-picker-select`는 React Native에서 드롭다운 또는 콤보박스를 만들 때 유용하게 사용되는 라이브러리입니다.

1. **유연한 스타일링**: 기본 스타일을 쉽게 변경할 수 있어, 앱의 디자인에 맞게 드롭다운을 꾸밀 수 있습니다.
2. **다양한 입력 타입 지원**: 기본 드롭다운 외에도 텍스트 입력, 다중 선택 등 다양한 기능을 지원합니다.
3. **아이템 필터링**: 선택 가능한 아이템을 필터링할 수 있는 기능도 제공하여, 대규모 목록을 처리할 때 유용합니다.
4. **검색 기능**: 선택할 항목이 많을 경우, 검색을 통해 항목을 필터링할 수 있는 기능도 내장되어 있습니다.

설치:
```
npm install @react-native-picker/picker
```

예시:
```tsx
import React, { useState } from 'react';
import { View, Text } from 'react-native';
import RNPickerSelect from 'react-native-picker-select';

const ComboBox = () => {<br>
  const [selectedValue, setSelectedValue] = useState(null);

  const pickerItems = [
    { label: 'Java', value: 'java' },
    { label: 'JavaScript', value: 'javascript' },
    { label: 'Python', value: 'python' },
  ];

  return (
    <View>
      <Text>선택된 값: {selectedValue}</Text>
      <RNPickerSelect
        onValueChange={(value) => setSelectedValue(value)}<br>
        items={pickerItems}
        placeholder={{ label: '언어를 선택하세요', value: null }}
      />
    </View>
  );
};

export default ComboBox;
```
{% endraw %}