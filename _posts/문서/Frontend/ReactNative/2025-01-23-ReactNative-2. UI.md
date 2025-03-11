---
categories:
- ReactNative
date: '2025-01-23'
title: '[ReactNative] 2. UI'
---

{% raw %}
### View
**View**는 다른 UI 요소들을 감싸는 용도로 사용되며, 레이아웃을 구성하는 데 필수적인 역할을 합니다. 기본적으로 **div**와 유사한 역할을 하며, 다양한 스타일을 적용하여 배치, 크기, 정렬 등을 설정할 수 있습니다.
    
```
import { View } from 'react-native';

const MyComponent = () => {<br>
  return (
	<View style={{ flex: 1, justifyContent: 'center', alignItems: 'center' }}>
	  {/* 다른 컴포넌트들 */}
	</View>
  );
};
```

### Text
**Text**는 화면에 **텍스트**를 표시하는 컴포넌트입니다. React Native에서 텍스트를 표시할 때는 반드시 **Text** 컴포넌트를 사용해야 합니다. 스타일을 적용하여 글자 크기, 색상, 폰트 등을 조정할 수 있습니다.
    
```
import { Text } from 'react-native';

const MyComponent = () => {<br>
  return (
	<Text style={{ fontSize: 20, color: 'blue' }}>
	  Hello, World!
	</Text>
  );
};
```

### TextInput
**TextInput**은 **사용자 입력**을 받을 수 있는 컴포넌트입니다. 주로 **폼**에서 텍스트를 입력받을 때 사용되며, `onChangeText`, `value` 등의 속성을 통해 상태 관리가 가능합니다.
    
```
import { TextInput } from 'react-native';

const MyComponent = () => {<br>
  const [text, setText] = useState('');

  return (
	<TextInput
	  value={text}
	  onChangeText={setText}
	  placeholder="Enter text"
	  style={{ height: 40, borderColor: 'gray', borderWidth: 1 }}
	/>
  );
};
```

### Button
**Button**은 **기본 버튼** 컴포넌트로, 사용자가 클릭할 수 있는 버튼을 생성합니다. 기본적인 버튼 스타일을 제공하며, `onPress` 속성으로 버튼 클릭 이벤트를 처리할 수 있습니다.
    
```
import { Button } from 'react-native';

const MyComponent = () => {<br>
  return (
	<Button
	  title="Click Me"
	  onPress={() => alert('Button Pressed')}<br>
	/>
  );
};
```

### TouchableOpacity
**TouchableOpacity**는 터치 가능한 요소로, **버튼**처럼 동작하는 컴포넌트입니다. 사용자가 이 컴포넌트를 터치하면, **opacity**(불투명도)를 조정하여 시각적인 피드백을 제공합니다. 주로 버튼이나 클릭 가능한 요소에 사용되며, 터치 이벤트를 처리할 수 있습니다.
    
```
import { TouchableOpacity, Text } from 'react-native';

const MyComponent = () => {<br>
  return (
	<TouchableOpacity onPress={() => alert('Button Pressed')}><br>
	  <Text>Click Me!</Text>
	</TouchableOpacity>
  );
};
```
    
### Animated
`Animated`는 React Native에서 애니메이션을 구현할 때 사용하는 기본적인 라이브러리입니다. 성능을 최적화하면서 부드러운 애니메이션을 제공하기 위해 **네이티브 드라이버(native driver)** 를 활용할 수 있도록 설계되었습니다.

예제:
```
import React, { useRef, useEffect } from "react";
import { View, Animated } from "react-native";

const MyComponent = () => {<br>
  const animation = useRef(new Animated.Value(0)).current;

  useEffect(() => {<br>
    Animated.timing(animation, {
      toValue: 1,
      duration: 1000,
      useNativeDriver: false,
    }).start();
  }, []);

  return (
    <Animated.View
      style={{
        width: 100,
        height: 100,
        backgroundColor: "blue",
        opacity: animation, // 애니메이션 적용
      }}
    />
  );
};

export default MyComponent;
```

#### 애니메이션 값
애니메이션의 상태를 저장하는 값입니다.
- `Animated.Value(number)`: 단일 값 애니메이션 (예: opacity, scale 등)
- `Animated.ValueXY({ x: number, y: number })`: 2D 위치 이동 애니메이션

```
const fadeAnim = useRef(new Animated.Value(0)).current;
```

#### 애니메이션 타이밍
`Animated`는 다양한 방식으로 애니메이션을 실행할 수 있습니다.
- `Animated.timing()`: 일정한 속도로 값 변경 (ease-in, ease-out 가능)
- `Animated.spring()`: 스프링 효과 (물리 기반 애니메이션)
- `Animated.decay()`: 관성 효과 (드래그 후 자연스럽게 감속)

```
Animated.timing(fadeAnim, {
  toValue: 1,   // 목표 값
  duration: 1000, // 1초 동안 실행
  useNativeDriver: true, // 네이티브 드라이버 사용
}).start();
```

#### 애니메이션 조합
여러 개의 애니메이션을 조합하여 실행할 수 있습니다.
- `Animated.sequence([...])` → 순차적으로 실행
- `Animated.parallel([...])` → 동시에 실행
- `Animated.stagger(time, [...])` → 일정 간격(time)으로 실행

```
Animated.sequence([
  Animated.timing(fadeAnim, { toValue: 1, duration: 500, useNativeDriver: true }),
  Animated.timing(fadeAnim, { toValue: 0, duration: 500, useNativeDriver: true }),
]).start();
```

#### 애니메이션 적용
애니메이션을 적용할 때는 `Animated`가 제공하는 컴포넌트를 사용해야 합니다.

```
<Animated.View style={{ opacity: fadeAnim }}>
  <Text>애니메이션 텍스트</Text>
</Animated.View>
```

#### useNativeDriver
애니메이션 성능을 높이기 위해 **네이티브 드라이버**(`useNativeDriver: true`)를 사용하는 것이 좋습니다.  하지만, 네이티브 드라이버는 **레이아웃 관련 속성(`width`, `height`)** 에는 적용되지 않고, **opacity, transform, scale** 등의 속성에서만 동작합니다.

#### Reanimated
React Native에서 애니메이션을 구현할 때 `Animated`와 함께 **React Native Reanimated** 라이브러리를 사용할 수도 있습니다. 애니메이션이 복잡하고 성능이 중요한 경우 **Reanimated**를 고려하는 것이 좋습니다.

|비교 항목|Animated|Reanimated|
|---|---|---|
|성능|네이티브 드라이버 지원|JSI 기반 네이티브 애니메이션|
|API 스타일|기본적인 애니메이션 구성|선언형 및 더 강력한 기능 제공|
|제스처 지원|별도 처리 필요|`react-native-gesture-handler`와 강력한 연동|

### Modal
**Modal**은 화면 위에 떠 있는 **팝업 창**을 의미합니다. 일반적으로 사용자가 현재 화면과 상호작용을 잠시 중단하고 중요한 정보를 표시하거나, 다른 선택을 하도록 유도할 때 사용됩니다. 모달은 **배경을 흐리게** 하거나 **블러 처리**하여 사용자가 그 외의 화면 요소와 상호작용을 하지 못하도록 하는 경우가 많습니다.

모달은 **전용 UI 창**이나 **팝업** 형태로 여러 종류가 있으며, **경고 메시지**, **폼 입력**, **이미지 갤러리** 등 다양한 용도로 사용됩니다.
- `visible`: 모달이 보일지 말지 결정하는 속성입니다. `true`일 때 모달이 표시됩니다.
- `transparent`: 모달이 배경을 흐리게 할지 여부입니다. `true`로 설정하면 배경이 흐려지고, 모달 영역만 선명하게 보입니다.
- `animationType`: 모달의 애니메이션 효과를 설정할 수 있습니다. `none`, `slide`, `fade` 등을 선택할 수 있습니다.
- `onRequestClose`: Android에서 하드웨어 뒤로가기 버튼을 눌렀을 때 모달을 닫을 수 있도록 처리합니다.

```
import React, { useState } from 'react';
import { Modal, View, Text, Button } from 'react-native';

const ModalExample = () => {<br>
  const [visible, setVisible] = useState(false);

  const toggleModal = () => setVisible(!visible);<br>

  return (
    <View style={{ flex: 1, justifyContent: 'center', alignItems: 'center' }}>
      <Button title="모달 열기" onPress={toggleModal} />

      <Modal
        visible={visible}
        transparent={true} // 배경을 흐리게 할지 여부
        animationType="slide" // 애니메이션 효과 (fade, slide 등)
        onRequestClose={toggleModal} // Android에서 뒤로 가기 버튼 클릭 시 처리
      >
        <View style={{ flex: 1, justifyContent: 'center', alignItems: 'center', backgroundColor: 'rgba(0, 0, 0, 0.5)' }}>
          <View style={{ backgroundColor: 'white', padding: 20, borderRadius: 10 }}>
            <Text>모달 콘텐츠</Text>
            <Button title="닫기" onPress={toggleModal} />
          </View>
        </View>
      </Modal>
    </View>
  );
};

export default ModalExample;
```
{% endraw %}