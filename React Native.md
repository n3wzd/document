# React Native
**React Native**는 **모바일 애플리케이션**을 개발할 수 있게 해주는 **오픈소스 프레임워크**입니다.  **JavaScript**와 **React**를 사용하여 **iOS**와 **Android** 앱을 동시에 개발할 수 있도록 지원합니다. 기본적으로 네이티브 앱을 만드는 데 필요한 성능과 사용자 경험을 제공하면서도, **웹 개발자**가 익숙한 **React**의 문법과 접근 방식으로 모바일 앱을 만들 수 있게 합니다.

1. **크로스 플랫폼 개발**:
    - React Native를 사용하면 iOS와 Android 앱을 **동시에** 개발할 수 있습니다. 대부분의 코드가 공통으로 사용되며, 플랫폼별로 필요한 부분만 따로 수정하면 됩니다.
    - 예를 들어, 앱의 UI나 로직을 한 번 작성하면 두 플랫폼에서 모두 실행 가능합니다.
2. **네이티브 성능**:
    - React Native는 네이티브 모듈을 사용하여 **네이티브 앱**처럼 빠르고 효율적인 성능을 제공합니다.
    - JavaScript 코드와 네이티브 코드가 상호작용하며, 성능을 극대화할 수 있습니다.
3. **핫 리로딩**:
    - **핫 리로딩**(Hot Reloading) 기능을 지원하여 앱을 실행 중에도 코드 수정 후 즉시 결과를 확인할 수 있습니다. 이를 통해 개발 속도가 빨라지고, 빠르게 피드백을 받을 수 있습니다.
4. **풍부한 커뮤니티와 라이브러리**:
    - React Native는 매우 큰 커뮤니티와 많은 라이브러리, 플러그인, 툴을 보유하고 있어 개발에 필요한 기능을 쉽게 추가할 수 있습니다.
    - 예를 들어, 네비게이션, 데이터 관리, 상태 관리 등의 다양한 라이브러리를 사용할 수 있습니다.
5. **네이티브 모듈 사용 가능**:
    - React Native는 기본적으로 제공하는 컴포넌트 외에도 **네이티브 모듈**을 사용하여, 네이티브 앱에서만 제공하는 기능을 직접 호출할 수 있습니다. 예를 들어, 카메라, GPS, 블루투스 등의 네이티브 기능을 사용할 수 있습니다.
6. **사용자 인터페이스(UI)**:
    - React Native는 **React**의 컴포넌트 기반 접근 방식을 그대로 사용하므로, UI를 구성할 때 React의 JSX 문법을 사용할 수 있습니다.
    - 또한, **StyleSheet**를 사용하여 스타일을 정의하며, 기본적으로 제공되는 **View**, **Text**, **Image** 등의 컴포넌트를 사용해 UI를 구성합니다.


## 도구
|**특징**|**Expo**|**React Native CLI**|
|---|---|---|
|**설정**|빠르고 간단한 설정|복잡한 설정 필요 (Xcode, Android Studio 필요)|
|**네이티브 코드 수정**|제한적 (Expo의 내장 API 사용)|자유롭게 수정 가능 (네이티브 코드 수정 가능)|
|**네이티브 모듈 사용**|Expo에서 제공하는 모듈만 사용 가능|Expo 외의 네이티브 모듈을 자유롭게 사용할 수 있음|
|**빌드 도구**|Expo 서버를 통한 간편한 빌드|Xcode, Android Studio를 통한 직접 빌드|
|**빠른 개발 시작**|매우 빠르게 시작 가능 (Expo Go 사용)|초기 설정과 환경 구성이 더 복잡함|
|**배포**|Expo의 빌드 시스템을 통해 간편한 배포|직접 빌드 후 배포 (App Store, Google Play 등)|
|**성능 최적화**|성능 최적화에 제한이 있을 수 있음|네이티브 코드 수정 및 최적화 가능|
|**커스터마이징**|제한적|완전한 커스터마이징 가능|

**Expo**와 **React Native CLI**의 주요 차이는 **SDK와 내장 API**에 있습니다. **Expo SDK**는 Expo에서 제공하는 **내장 API**와 라이브러리를 포함하며, React Native CLI는 이러한 API를 사용할 수 없거나, 별도로 네이티브 모듈을 설치하고 설정해야 할 수 있습니다.

### React Native CLI
**React Native CLI**는 **React Native 앱을 명령줄에서 관리하고 실행하는 도구**입니다. 이 CLI를 사용하면 **React Native 프로젝트를 초기화하고, 빌드하고, 실행**할 수 있습니다.

- **네이티브 코드 수정이 필요할 때**: 네이티브 기능을 추가하거나, 성능 최적화가 필요한 경우 React Native CLI가 적합합니다.
- **네이티브 라이브러리를 사용하고 싶을 때**: Expo에서 제공하지 않는 라이브러리를 사용해야 할 때 React Native CLI를 사용해야 합니다.
- **복잡한 앱 개발**: 앱의 요구 사항이 복잡하고, 세밀한 설정이 필요할 때 React Native CLI가 유리합니다.

### Expo
**Expo**는 React Native 앱 개발을 **더 쉽게 만들기 위한 도구**입니다. Expo는 React Native를 기반으로 한 **개발 플랫폼**으로, 기본적으로 앱을 **빠르게 시작하고 실행할 수 있는 도구와 라이브러리**를 제공합니다.

- **빠르게 시작하고 싶을 때**: 설정이 간단하고, 기본적인 모바일 앱을 빠르게 개발하고 배포할 수 있습니다.
- **네이티브 코드 수정이 필요 없을 때**: Expo에서 제공하는 API로 충분히 앱을 개발할 수 있다면 Expo가 적합합니다.
- **간단한 앱 개발**: 빠르게 프로토타입을 만들거나, 기본적인 기능을 구현할 때 유용합니다.

#### Expo Eject
**Expo Eject**는 **Expo 프로젝트**에서 **Expo의 관리형 환경**을 벗어나 **React Native CLI** 환경으로 변환하는 과정입니다. Expo는 기본적으로 많은 기능을 제공하지만, 때로는 **네이티브 코드 수정**이나 **고급 설정**이 필요한 경우가 있습니다. 이때 **Expo Eject**를 사용하여 Expo의 제한을 벗어나 **직접 네이티브 코드**를 수정하거나 **React Native CLI**에서 제공하는 기능을 활용할 수 있습니다.

## UI
### View
**View**는 React Native에서 가장 기본적인 레이아웃 컴포넌트로, **컨테이너** 역할을 합니다.  **View**는 다른 UI 요소들을 감싸는 용도로 사용되며, 레이아웃을 구성하는 데 필수적인 역할을 합니다. 기본적으로 **div**와 유사한 역할을 하며, 다양한 스타일을 적용하여 배치, 크기, 정렬 등을 설정할 수 있습니다.
    
```
import { View } from 'react-native';

const MyComponent = () => {
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

const MyComponent = () => {
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

const MyComponent = () => {
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

const MyComponent = () => {
  return (
	<Button
	  title="Click Me"
	  onPress={() => alert('Button Pressed')}
	/>
  );
};
```

### TouchableOpacity
**TouchableOpacity**는 터치 가능한 요소로, **버튼**처럼 동작하는 컴포넌트입니다. 사용자가 이 컴포넌트를 터치하면, **opacity**(불투명도)를 조정하여 시각적인 피드백을 제공합니다. 주로 버튼이나 클릭 가능한 요소에 사용되며, 터치 이벤트를 처리할 수 있습니다.
    
```
import { TouchableOpacity, Text } from 'react-native';

const MyComponent = () => {
  return (
	<TouchableOpacity onPress={() => alert('Button Pressed')}>
	  <Text>Click Me!</Text>
	</TouchableOpacity>
  );
};
```
    
### Animated
`Animated`는 React Native에서 애니메이션을 구현할 때 사용하는 기본적인 라이브러리입니다. 성능을 최적화하면서 부드러운 애니메이션을 제공하기 위해 **네이티브 드라이버(native driver)** 를 활용할 수 있도록 설계되었습니다.

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

const ModalExample = () => {
  const [visible, setVisible] = useState(false);

  const toggleModal = () => setVisible(!visible);

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

## Style
### StyleSheet
**StyleSheet**는 React Native에서 **스타일을 정의**하는 객체입니다. React Native는 **CSS** 대신 **JavaScript 객체**를 사용하여 스타일을 정의합니다.
    
`StyleSheet.create`를 사용하면 성능 최적화가 이루어지며, 스타일을 정의한 객체를 **재사용**할 수 있습니다.
    
```
import { StyleSheet, View, Text } from 'react-native';

const styles = StyleSheet.create({
  container: {
	flex: 1,
	justifyContent: 'center',
	alignItems: 'center',
  },
  text: {
	fontSize: 20,
	color: 'blue',
  },
});

const MyComponent = () => {
  return (
	<View style={styles.container}>
	  <Text style={styles.text}>Hello, World!</Text>
	</View>
  );
};
```


## Package
### React Navigation
**React Navigation**은 **React Native** 애플리케이션에서 화면 간 이동(네비게이션)을 관리하는 라이브러리입니다. 이 라이브러리는 모바일 앱에서 흔히 필요한 여러 종류의 **네비게이션 패턴 및 관련 UI**를 제공합니다.

- **화면 간 네비게이션 (Navigation Between Screens)**
    - **스택 네비게이션 (Stack Navigation)**: 화면을 스택처럼 쌓고, 뒤로 가기, 앞으로 가기 등의 기능을 제공합니다. 예를 들어, 사용자가 로그인 후 홈 화면으로 이동하고, 다시 뒤로 가기 버튼을 누르면 로그인 화면으로 돌아가는 방식입니다.
    - **탭 네비게이션 (Tab Navigation)**: 하단에 탭을 추가하여 각 탭에 해당하는 화면으로 쉽게 이동할 수 있습니다. 예를 들어, 하단에 "홈", "검색", "알림" 등의 탭을 만들어 각 탭에 해당하는 화면을 표시합니다.
    - **드로어 네비게이션 (Drawer Navigation)**: 왼쪽이나 오른쪽에서 드로어 메뉴를 열고, 메뉴 항목을 선택하여 화면을 전환할 수 있는 네비게이션입니다. 흔히 모바일 앱에서 사이드 메뉴로 사용됩니다.
- **파라미터 전달 (Passing Parameters)**
    - 화면 간에 데이터를 전달할 수 있는 기능을 제공합니다. 예를 들어, 하나의 화면에서 다른 화면으로 이동하면서 파라미터를 전달하고, 전달받은 파라미터를 새 화면에서 사용할 수 있습니다.
- **상태 관리 (State Management)**
    - 네비게이션 상태를 관리하고, 네비게이션 이벤트(예: 화면 이동, 화면 전환 완료 등)에 대한 리스너를 설정할 수 있습니다.
- **커스터마이징 (Customization)**
    - 네비게이션 스타일(헤더, 탭 바, 드로어 메뉴 등)을 커스터마이징할 수 있습니다. 예를 들어, 헤더의 색상, 글꼴, 버튼 등을 설정할 수 있습니다.

설치:
```
npm install react-navigation
```

#### NavigationContainer
`Navigator`는 일반적으로 **앱의 루트**에서 등록되며, **앱의 네비게이션 흐름**을 정의합니다. 예를 들어, `Stack.Navigator`를 루트에 등록하여 앱의 기본 화면 흐름을 정의할 수 있습니다.

`Navigator`는 **전환할 화면을 관리**하고, `Screen`은 실제로 보여지는 **각 화면**을 정의합니다.

##### Stack Navigation
기본적인 네비게이션으로, 화면 간의 전환을 스택 구조로 관리합니다.

```
import React from 'react';
import { createStackNavigator } from '@react-navigation/stack';
import { NavigationContainer } from '@react-navigation/native';
import HomeScreen from './screens/HomeScreen';
import DetailsScreen from './screens/DetailsScreen';

const Stack = createStackNavigator();

export default function App() {
  return (
    <NavigationContainer>
      <Stack.Navigator initialRouteName='Home'>
        <Stack.Screen name="Home" component={HomeScreen} />
        <Stack.Screen name="Details" component={DetailsScreen} />
      </Stack.Navigator>
    </NavigationContainer>
  );
}
```

##### Bottom Tabs Navigation
화면 하단에 탭 네비게이션을 추가합니다.

```
import React from 'react';
import { createBottomTabNavigator } from '@react-navigation/bottom-tabs';
import { NavigationContainer } from '@react-navigation/native';
import HomeScreen from './screens/HomeScreen';
import ProfileScreen from './screens/ProfileScreen';

const Tab = createBottomTabNavigator();

export default function App() {
  return (
    <NavigationContainer>
      <Tab.Navigator>
        <Tab.Screen name="Home" component={HomeScreen} />
        <Tab.Screen name="Profile" component={ProfileScreen} />
      </Tab.Navigator>
    </NavigationContainer>
  );
}
```

##### Drawer Navigation
드로어 메뉴를 사용하여 화면을 전환합니다.

```
import React from 'react';
import { createDrawerNavigator } from '@react-navigation/drawer';
import { NavigationContainer } from '@react-navigation/native';
import HomeScreen from './screens/HomeScreen';
import SettingsScreen from './screens/SettingsScreen';

const Drawer = createDrawerNavigator();

export default function App() {
  return (
    <NavigationContainer>
      <Drawer.Navigator>
        <Drawer.Screen name="Home" component={HomeScreen} />
        <Drawer.Screen name="Settings" component={SettingsScreen} />
      </Drawer.Navigator>
    </NavigationContainer>
  );
}
```

#### navigation
`navigation` 객체는 화면 간 이동을 제어하는 데 사용됩니다. 이를 통해 다른 화면으로 이동하거나, 뒤로 가기, 화면을 리셋하는 등의 작업을 할 수 있습니다.

- **화면 이동**: `navigation.navigate('ScreenName')`을 사용하여 다른 화면으로 이동합니다.
- **뒤로 가기**: `navigation.goBack()`을 사용하여 이전 화면으로 돌아갑니다.

```
import React from 'react';
import { View, Text, Button } from 'react-native';

const HomeScreen = ({ navigation }: { navigation: any }) => {
  return (
    <View>
      <Text>Home Screen</Text>
      <Button
        title="Go to Login"
        onPress={() => navigation.navigate('Login')}
      />
    </View>
  );
};

export default HomeScreen;
```

위의 예시에서는 `HomeScreen`에서 `Login` 화면으로 이동하는 버튼을 클릭하면 `navigation.navigate('Login')`을 통해 `Login` 화면으로 이동합니다.

##### 파라미터 전달
`navigate` 메서드로 다른 화면으로 이동할 때 파라미터를 전달할 수도 있습니다.
```
navigation.navigate('Login', { userId: 123 });
```

그리고 `Login` 화면에서 전달된 파라미터를 받을 수 있습니다:

```
const LoginScreen = ({ route }: { route: any }) => {
  const { userId } = route.params;

  return (
    <View>
      <Text>Login Screen</Text>
      <Text>User ID: {userId}</Text>
    </View>
  );
};
```

### React Hook Form
**React Hook Form**은 `<form>` 태그의 기본 기능을 확장하고, 폼의 상태와 검증을 더 쉽게 관리할 수 있도록 도와줍니다.

1. **폼 상태 관리 간소화**
    - `<form>` 태그만 사용할 경우, 상태 관리를 위해 React의 `useState`를 많이 사용해야 합니다.
    - React Hook Form은 `useForm` 훅으로 폼 전체의 상태를 효율적으로 관리합니다.
2. **내장된 검증 기능**
    - React Hook Form은 HTML5의 기본 검증 속성(`required`, `minLength` 등)을 지원하며, 추가적인 검증 로직도 간단히 추가할 수 있습니다.
    - 에러 메시지와 상태를 관리하기 쉬워집니다.
3. **제어되지 않는 컴포넌트 지원**
    - React Hook Form은 기본적으로 **제어되지 않는(uncontrolled)** 컴포넌트를 사용합니다.
    - 이 방식은 React 상태와의 동기화를 최소화해 성능을 최적화합니다.
4. **리렌더링 최소화**
    - `<form>` 태그만 사용할 경우, 입력 필드 하나가 변경될 때 전체 폼 컴포넌트가 리렌더링될 수 있습니다.
    - React Hook Form은 각 필드를 독립적으로 관리해 불필요한 리렌더링을 방지합니다.
5. **유연성**
    - Yup, Zod와 같은 검증 라이브러리와 쉽게 통합할 수 있어 복잡한 폼 검증도 간단하게 처리할 수 있습니다.

설치:
```
npm install react-hook-form
```

#### useForm
`useForm`은 `react-hook-form` 라이브러리에서 제공하는 훅으로, 폼의 상태 관리와 유효성 검사, 제출을 간단하게 처리할 수 있게 도와줍니다. `useForm`을 사용하면, 폼의 입력값을 관리하고, 유효성 검사를 설정하고, 제출 시 데이터 처리를 쉽게 할 수 있습니다.

```
import React from 'react';
import { useForm } from 'react-hook-form';

interface FormData {
  name: string;
  email: string;
}

const MyForm = () => {
  // useForm 훅을 호출하여 폼 상태와 관련된 기능을 가져옵니다.
  const { register, handleSubmit, formState: { errors } } = useForm<FormData>();

  const onSubmit = (data: FormData) => {
    console.log(data); // 폼 제출 시 데이터 출력
  };

  return (
    <form onSubmit={handleSubmit(onSubmit)}>
      <input {...register('name', { required: '이름을 입력해주세요.' })}/>
      {errors.name && <p>{errors.name.message}</p>}

      <input {...register('email', { required: '이메일을 입력해주세요.' })}/>
      {errors.email && <p>{errors.email.message}</p>}

      <button type="submit">제출</button>
    </form>
  );
};
```

1. `register`: 입력 필드를 `useForm`에 등록하는 함수입니다.
    - `register` 함수는 필드를 등록하고, 필드에 유효성 검사 규칙을 추가할 수 있습니다.
    - 예: `register('name', { required: '이름을 입력해주세요.' })`
    - `name`은 필드의 이름을 의미하고, 두 번째 인자로는 유효성 검사 규칙을 객체 형태로 전달합니다.
2. `control`: 폼의 상태를 관리합니다.
	- `control`을 `useController` 또는 `Controller`에 전달하여 폼 필드를 관리합니다.
3. `handleSubmit`: 폼 제출을 처리하는 함수입니다.
    - `handleSubmit`은 유효성 검사를 통과한 데이터만 `onSubmit` 함수로 전달합니다.
    - 예: `<form onSubmit={handleSubmit(onSubmit)}></form>`
4. `formState`: 폼의 상태를 추적하는 객체입니다.
    - `formState.errors`: 유효성 검사 오류를 추적하는 객체입니다.
    - 예: `formState.errors.name`은 `name` 필드에 대한 오류를 추적합니다.
5. `setValue`: 필드 값을 동적으로 설정할 수 있는 함수입니다.
    - 예: `setValue('name', 'John Doe')`는 `name` 필드의 값을 `'John Doe'`로 설정합니다.
6. `watch`: 필드 값을 실시간으로 추적할 수 있는 함수입니다.
    - 예: `const name = watch('name')`는 `name` 필드의 값을 실시간으로 추적합니다.
7. `reset`: 폼을 초기화하는 함수입니다.
    - 예: `reset()`을 호출하면 폼을 초기 상태로 되돌립니다.
8. `clearErrors`: 특정 필드 또는 모든 필드의 오류를 제거하는 함수입니다.
    - 예: `clearErrors('name')`는 `name` 필드의 오류를 제거합니다.

`register`는 기본적인 폼 필드와 유효성 검사에 사용되며, `control`은 더 복잡한 폼 상태 관리 및 외부 라이브러리와의 통합을 위해 사용됩니다.

|**특징**|`register`|`control`|
|---|---|---|
|**주요 역할**|폼 필드를 등록하고, 유효성 검사 규칙을 설정|폼 상태를 관리하고, 필드 값을 추적|
|**사용되는 위치**|기본 HTML 입력 요소 (예: `<input>`, `<select>`)와 함께 사용|`useController` 또는 `Controller`와 함께 사용|
|**사용 예시**|`<input {...register('fieldName', { rules })} />`|`<Controller control={control} name="fieldName" />`|
|**핸들러 제공 여부**|`value`, `onChange`, `onBlur` 등의 필드 관련 핸들러 반환|`field.value`, `field.onChange`, `field.onBlur` 제공|

#### 유효성 검사
```
const { register, handleSubmit, formState: { errors } } = useForm<FormData>();

const onSubmit = (data: FormData) => {
  console.log(data);
};

return (
  <form onSubmit={handleSubmit(onSubmit)}>
    <input
      {...register('name', { required: '이름을 입력해주세요.', minLength: 2 })}
      placeholder="이름"
    />
    {errors.name && <p>{errors.name.message}</p>}

    <input
      {...register('email', { 
        required: '이메일을 입력해주세요.',
        pattern: {
          value: /^[^\s@]+@[^\s@]+\.[^\s@]+$/,
          message: '이메일 형식이 올바르지 않습니다.'
        }
      })}
      placeholder="이메일"
    />
    {errors.email && <p>{errors.email.message}</p>}

    <button type="submit">제출</button>
  </form>
);
```

- `required`: 필수 입력 필드로 설정합니다.
- `minLength`: 최소 길이를 설정합니다.
- `maxLength`: 최대 길이를 설정합니다.
- `pattern`: 정규식을 사용하여 값이 특정 패턴과 일치하는지 검사합니다.
- `validate`: 사용자 정의 검증 함수를 사용하여 유효성 검사를 추가합니다.

#### useController
`useController`는 `react-hook-form` 라이브러리에서 제공하는 훅으로, 폼 필드와 관련된 상태를 관리하고, 해당 필드에 대한 유효성 검사 및 입력 값을 처리할 수 있게 해줍니다. `useController`는 `useForm` 훅과 함께 사용되며, 주로 폼 필드에 대해 더 세밀한 제어가 필요할 때 사용됩니다.

```
import React from 'react';
import { TextInput, Text, View } from 'react-native';
import { useController } from 'react-hook-form';

const MyInput = ({ control, name, rules, errors }) => {
  // useController를 사용하여 필드의 상태를 관리합니다.
  const { field } = useController({
    name,
    control,
    rules, // 유효성 검사 규칙
  });

  return (
    <View>
      <TextInput
        style={{ borderWidth: 1, padding: 10 }}
        placeholder={name}
        onChangeText={field.onChange} // onChange 이벤트에 연결
        onBlur={field.onBlur} // onBlur 이벤트에 연결
        {...field}
      />
      {errors[name] && <Text style={{ color: 'red' }}>{errors[name]?.message}</Text>}
    </View>
  );
};

export default MyInput;
```

`useController`는 다음과 같은 값을 반환합니다:
- `field`:
    - `onChange`: 필드의 값이 변경될 때 호출되는 함수.
    - `onBlur`: 필드가 포커스를 잃을 때 호출되는 함수.
    - `name`: 필드의 이름 (이 값은 `useController`를 호출할 때 지정한 `name`입니다).
    - `ref`: 필드에 대한 레퍼런스 (주로 `useRef`와 결합되어 사용).
- `fieldState`:
    - `invalid`: 필드가 유효성 검사에서 실패한 경우 `true`.
    - `isTouched`: 필드가 사용자가 상호작용한 경우 `true`.
    - `isDirty`: 필드의 값이 초기 값과 다르면 `true`.
    - `error`: 해당 필드의 오류 메시지.

### Expo Router
`expo-router`는 Expo에서 제공하는 라우팅 라이브러리로, React Navigation을 기반으로 하여 React 앱의 네비게이션을 간편하게 설정할 수 있도록 도와줍니다. 이 라이브러리는 특히 파일 기반 라우팅을 지원하여, 페이지마다 별도의 설정 없이 파일 및 폴더 구조만으로 라우팅을 자동으로 처리할 수 있게 합니다.

1. **파일 기반 라우팅**:
    - `expo-router`는 파일 시스템을 기반으로 라우팅을 처리합니다. 즉, 파일과 폴더 구조에 따라 자동으로 라우팅을 설정할 수 있습니다.
    - 예를 들어, `app/home.tsx` 파일이 있으면 `/home` 경로로 자동으로 연결됩니다.
2. **자동 페이지 전환**:
    - 파일 구조에 따라 페이지가 자동으로 등록되므로, 명시적으로 라우터 설정을 작성할 필요 없이 파일을 추가하거나 이동하는 것만으로 라우팅을 관리할 수 있습니다.
3. **React Navigation 통합**:
    - `expo-router`는 React Navigation을 내부적으로 사용하여, 다양한 네비게이션 기능을 제공합니다. 스택, 탭, 드로어 네비게이션을 손쉽게 구현할 수 있습니다.
4. **Dynamic Routing**:
    - 파일 이름에 동적 경로를 포함시킬 수 있어, 라우트 파라미터를 쉽게 처리할 수 있습니다.
5. **개발자 경험 개선**:
    - `expo-router`는 코드의 양을 줄이고, 네비게이션 설정을 더 직관적으로 만들어주며, 개발자가 페이지와 네비게이션을 관리하는 데 소요되는 시간을 줄여줍니다.

설치:
```
expo install expo-router
```

#### 디렉터리 구조
`expo-router`는 파일 시스템을 기반으로 라우팅을 처리하므로, 디렉토리와 파일 이름이 URL 경로와 자동으로 매핑됩니다. 예를 들어, `app` 폴더 안에 `home.tsx` 파일을 생성하면, 그 파일은 `/home` 경로로 자동으로 연결됩니다.
- `app/home.tsx` 파일을 생성하면 `/home` 경로로 자동으로 연결됩니다.
- `app/settings.tsx` 파일을 생성하면 `/settings` 경로로 자동으로 연결됩니다.

```
/app
  ├── index.tsx          # 홈 화면 ("/")
  ├── login.tsx          # 로그인 화면 ("/login")
  └── profile.tsx        # 프로필 화면 ("/profile")
```

`app/index.tsx`: 기본적으로 `index.tsx` 파일은 루트 경로 (`/`)에 해당합니다.

#### 동적 라우팅
`app/[id].tsx`와 같은 파일 이름을 사용하면, `id`라는 동적 경로 파라미터를 받을 수 있습니다.

```
// app/[id].tsx
import { useRouter } from 'expo-router';

export default function Item() {
  const { query } = useRouter();
  const { id } = query;

  return <Text>Item ID: {id}</Text>;
}
```

#### Link
`expo-router`에서는 `Link` 컴포넌트를 사용하여 화면 간 이동을 처리할 수 있습니다. `Link`는 URL을 변경하여 자동으로 해당 경로로 이동합니다.

```
import React from 'react';
import { View, Text } from 'react-native';
import { Link } from 'expo-router';

const HomeScreen = () => {
  return (
    <View>
      <Text>Welcome to the Home Screen</Text>
      {/* Link를 사용하여 다른 화면으로 이동 */}
      <Link href="/profile">Go to Profile</Link>
    </View>
  );
};

export default HomeScreen;
```

위 코드에서 `Link` 컴포넌트를 사용하여 `/profile` 경로로 이동하는 링크를 생성합니다. `href` 속성에 이동할 경로를 지정해주면 됩니다.

#### useRouter
`expo-router`는 `useRouter` 훅을 제공하여, 프로그래밍적으로 라우팅을 제어할 수 있습니다. 이 훅을 사용하면 `navigate` 메서드를 통해 특정 경로로 이동할 수 있습니다.

```
import React from 'react';
import { View, Text, Button } from 'react-native';
import { useRouter } from 'expo-router';

const HomeScreen = () => {
  const router = useRouter();

  const goToProfile = () => {
    router.push('/profile');
  };

  return (
    <View>
      <Text>Welcome to the Home Screen</Text>
      <Button title="Go to Profile" onPress={goToProfile} />
    </View>
  );
};

export default HomeScreen;
```

위 코드에서는 `useRouter` 훅을 사용하여 `router.push('/profile')`로 `/profile` 경로로 이동합니다. `router.push()`는 URL을 변경하고 해당 경로로 이동하게 만듭니다.

#### Tabs
`Tabs`는 `Expo Router`에서 제공하는 하단 탭 네비게이션 컴포넌트를 설정하기 위한 기본 구성 요소입니다. `react-navigation`의 `createBottomTabNavigator`를 내부적으로 활용하여 동작하며, `Expo Router`의 파일 기반 라우팅 시스템과 함께 사용됩니다.

```
import { Tabs } from 'expo-router';
import Ionicons from 'react-native-vector-icons/Ionicons';

export default function Layout() {
  return (
    <Tabs>
      {/* Home Tab */}
      <Tabs.Screen
        name="home"
        options={{
          title: 'Home',
          tabBarIcon: ({ color, size }) => (
            <Ionicons name="home-outline" color={color} size={size} />
          ),
        }}
      />
      {/* Profile Tab */}
      <Tabs.Screen
        name="profile"
        options={{
          title: 'Profile',
          tabBarIcon: ({ color, size }) => (
            <Ionicons name="person-outline" color={color} size={size} />
          ),
        }}
      />
      {/* Settings Tab */}
      <Tabs.Screen
        name="settings"
        options={{
          title: 'Settings',
          tabBarIcon: ({ color, size }) => (
            <Ionicons name="settings-outline" color={color} size={size} />
          ),
        }}
      />
    </Tabs>
  );
}
```

`Tabs.Screen` 옵션:
1. `name`: 라우트 이름. `app` 디렉토리 내의 파일 이름과 일치해야 합니다.
2. `options`: 화면 설정 옵션.
    - `title`: 탭의 제목.
    - `tabBarIcon`: 탭 아이콘 설정.
    - `tabBarStyle`: 탭 바의 스타일 설정.

자세한 사용법:
> https://docs.expo.dev/router/advanced/tabs/

### `axios`
`axios`는 외부 라이브러리로, HTTP 요청을 보다 쉽게 관리할 수 있도록 도와줍니다. `fetch`보다 많은 기능을 제공하며, 개발자 경험을 개선합니다.

- Promise 기반으로 작동.
- 요청 및 응답에 대한 인터셉터(interceptor) 기능 제공.
- HTTP 상태 코드를 기반으로 자동 에러 처리가 가능.
- JSON 데이터를 자동으로 변환.
- 요청 취소, 타임아웃 설정, 기본 URL 설정 등 추가 기능 제공.

설치:
```
npm install axios
```

**GET 요청**
```
import axios from 'axios';

axios
  .get('https://jsonplaceholder.typicode.com/posts/1')
  .then((response) => {
    console.log(response.data); // JSON 데이터 자동 파싱
  })
  .catch((error) => {
    console.error('Error:', error);
  });
```

**POST 요청**
```
import axios from 'axios';

axios
  .post('https://jsonplaceholder.typicode.com/posts', {
    title: 'foo',
    body: 'bar',
    userId: 1,
  })
  .then((response) => {
    console.log(response.data);
  })
  .catch((error) => {
    console.error('Error:', error);
  });
```

|**특징**|**fetch**|**axios**|
|---|---|---|
|**내장 여부**|브라우저와 Node.js에 내장|별도 설치 필요 (`npm install axios`)|
|**Promise 기반**|지원|지원|
|**JSON 자동 파싱**|직접 `response.json()` 호출 필요|자동 파싱|
|**에러 처리**|네트워크 오류만 `catch`로 처리 가능|HTTP 상태 코드도 자동으로 처리 가능|
|**인터셉터**|지원하지 않음|지원|
|**타임아웃 설정**|직접 구현 필요|기본적으로 제공|
|**요청 취소**|직접 구현 필요|기본적으로 제공|

### React Native Dotenv
`react-native-dotenv`는 React Native 애플리케이션에서 `.env` 파일을 사용하여 환경 변수를 관리할 수 있게 해주는 패키지입니다. 이를 통해 민감한 정보(예: API 키, 서버 URL 등)를 코드와 분리하고, 환경별(개발, 테스트, 프로덕션)로 다른 값을 설정할 수 있습니다.

- `.env` 파일에 정의된 변수를 애플리케이션 코드에서 사용할 수 있도록 제공합니다.
- 환경 변수 값을 쉽게 변경할 수 있어, 환경에 따라 다른 설정을 적용하는 데 유용합니다.
- 민감한 정보를 코드베이스에서 분리하여 보안성을 높입니다.

설치: 
```
npm install react-native-dotenv
```

**`.env` 파일 생성**
프로젝트 루트 디렉터리에 `.env` 파일을 생성하고, 환경 변수를 정의합니다:

```
API_URL=https://api.example.com
API_KEY=your_api_key_here
```

**`babel.config.js` 수정**
Babel 설정 파일에 `react-native-dotenv` 플러그인을 추가합니다:
```
module.exports = function (api) {
  api.cache(true);
  return {
    presets: ['babel-preset-expo'],
    plugins: [
      ['module:react-native-dotenv', {
        moduleName: '@env',
        path: '.env',
        safe: false,
        allowUndefined: true,
      }],
    ],
  };
};
```

**`env.d.ts` 설정** (TypeScript 사용시)
```
declare module "@env" {
    export const API_URL: string;
    export const API_KEY: string;
}
```

**환경 변수 사용**
`.env` 파일에 정의된 변수를 애플리케이션에서 가져와 사용할 수 있습니다:
```
import { API_URL, API_KEY } from '@env';

console.log('API URL:', API_URL);
console.log('API Key:', API_KEY);
```

### React Native Keychain
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
const storeToken = async (token: string) => {
  try {
    await Keychain.setGenericPassword('user_token', token);
  } catch (e) {
    console.error('Failed to save token:', e);
  }
};

// 토큰 가져오기
const getToken = async () => {
  try {
    const credentials = await Keychain.getGenericPassword();
    return credentials ? credentials.password : null;
  } catch (e) {
    console.error('Failed to fetch token:', e);
  }
};

// 토큰 삭제
const removeToken = async () => {
  try {
    await Keychain.resetGenericPassword();
  } catch (e) {
    console.error('Failed to remove token:', e);
  }
};
```

### React Native Secure Storage
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
const storeToken = async (token: string) => {
  try {
    await SecureStorage.set('user_token', token);
  } catch (e) {
    console.error('Failed to save token:', e);
  }
};

// 토큰 가져오기
const getToken = async () => {
  try {
    const token = await SecureStorage.get('user_token');
    return token;
  } catch (e) {
    console.error('Failed to fetch token:', e);
  }
};

// 토큰 삭제
const removeToken = async () => {
  try {
    await SecureStorage.remove('user_token');
  } catch (e) {
    console.error('Failed to remove token:', e);
  }
};
```

### Expo Secure Store
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
const storeToken = async (token: string) => {
  try {
    await SecureStore.setItemAsync('user_token', token);  // 'setItemAsync' 사용
  } catch (e) {
    console.error('Failed to save token:', e);
  }
};

// 토큰 가져오기
const getToken = async () => {
  try {
    const token = await SecureStore.getItemAsync('user_token');  // 'getItemAsync' 사용
    return token;
  } catch (e) {
    console.error('Failed to fetch token:', e);
  }
};

// 토큰 삭제
const removeToken = async () => {
  try {
    await SecureStore.deleteItemAsync('user_token');  // 'deleteItemAsync' 사용
  } catch (e) {
    console.error('Failed to remove token:', e);
  }
};
```

### React Native Vector Icons
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

const App = () => {
  return (
    <Icon name="home" size={30} color="#900" />
  );
};

export default App;
```

이 코드는 MaterialIcons 세트에서 `home` 아이콘을 가져와 크기와 색상을 설정한 예제입니다.

### jwt-decode
`jwt-decode`는 JWT(JSON Web Token)를 **디코딩**하기 위한 경량 JavaScript 라이브러리입니다. 이 라이브러리는 다음과 같은 특징을 가집니다:

- **디코딩 전용**:  
    `jwt-decode`는 JWT 토큰을 디코딩하여 페이로드(payload)와 헤더(header)의 내용을 추출합니다.  
    **서명 검증(signature verification)은 수행하지 않습니다.** 즉, 토큰이 실제로 유효한지, 위변조되지 않았는지는 확인하지 않고 단순히 토큰 내에 포함된 데이터를 읽어옵니다.
- **클라이언트 친화적**:  
    React, React Native(Expo 포함)와 같은 클라이언트 환경에서 사용하기 적합합니다. Node.js 전용 라이브러리인 `jsonwebtoken`과 달리, 브라우저나 모바일 환경에서 문제 없이 사용할 수 있습니다.
- **간단한 사용법**:  
    토큰을 인자로 넣으면 디코딩된 객체를 반환하므로, 예를 들어 사용자 정보나 기타 클레임(claim)을 쉽게 확인할 수 있습니다.

설치:
```
npm install jwt-decode
```

### 토큰 분석
```
import jwtDecode from 'jwt-decode';

const token = 'eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJzdWIiOiIxMjM0NTY3ODkwIiwibmFtZSI6IkpvaG4gRG9lIiwiaWF0IjoxNTE2MjM5MDIyfQ.SflKxwRJSMeKKF2QT4fwpMeJf36POk6yJV_adQssw5c';
const decoded = jwtDecode(token);

console.log(decoded);
// 예시 출력: { sub: "1234567890", name: "John Doe", iat: 1516239022 }
```

### React Query
**React Query**는 React 애플리케이션에서 **서버 상태**를 관리하고 **비동기 데이터 fetching**을 간소화하는 라이브러리입니다. 클라이언트 애플리케이션에서 서버와의 데이터를 주고받을 때 필요한 여러 가지 작업을 효율적으로 처리할 수 있게 도와줍니다.

1. **데이터 fetching**: 서버에서 데이터를 가져오는 작업을 훅을 통해 간편하게 처리할 수 있습니다. 비동기 요청을 작성할 때의 번거로움을 줄여줍니다.
2. **자동 캐싱**: 데이터를 한 번 요청하면, React Query가 이를 **자동으로 캐시**하여 불필요한 네트워크 요청을 줄이고 성능을 최적화합니다.
3. **데이터 갱신**: 사용자가 데이터를 수정하거나 새로고침 할 때 **자동으로 최신 데이터**를 가져올 수 있도록 합니다. 또한, **백그라운드에서 데이터 업데이트**가 가능합니다.
4. **로딩/에러 상태 관리**: 서버 요청에 대한 로딩 상태, 에러 상태 등을 자동으로 관리해 줍니다.
5. **자동 리페칭 (Re-fetching)**: 특정 조건에 맞춰 데이터를 자동으로 다시 가져올 수 있습니다. 예를 들어, 사용자가 페이지를 다시 방문하거나 데이터가 일정 시간이 지나면 재요청합니다.

설치:
```
npm install react-query
```

#### useQuery
`useQuery`는 **React Query**에서 데이터를 가져오는 비동기 작업을 처리하는 훅입니다.
    
```
import { useQuery } from 'react-query';
import axios from 'axios';

const fetchData = async () => {
  const response = await axios.get('https://api.example.com/data');
  return response.data;
};

const MyComponent = () => {
  const { data, isLoading, error } = useQuery('dataKey', fetchData);

  if (isLoading) return <div>Loading...</div>;
  if (error) return <div>Error: {error.message}</div>;

  return <div>{JSON.stringify(data)}</div>;
};
```

React Query는 데이터가 성공적으로 가져와지면 해당 데이터를 **자동으로 캐시**합니다. 이렇게 캐시된 데이터는 동일한 쿼리 키를 사용하는 다른 `useQuery` 훅에서 사용될 수 있습니다.

##### 쿼리 키(Query Key)
`useQuery`는 데이터를 요청할 때 **쿼리 키**를 사용하여 데이터를 식별합니다. 쿼리 키는 데이터를 요청하는데 사용되는 고유한 문자열 또는 배열입니다. 쿼리 키를 기반으로 React Query는 데이터를 캐시하고, 재요청 시 해당 캐시 데이터를 반환합니다.
```
const { data, isLoading } = useQuery('dataKey', fetchData);
```

`'dataKey'`는 해당 데이터를 식별하는 쿼리 키입니다. 이 키는 요청한 데이터가 다른 곳에서 사용될 때도 동일한 데이터를 참조하는 데 사용됩니다.

##### 쿼리 함수(Query Function)
`useQuery`의 두 번째 인자로 전달되는 **쿼리 함수**는 데이터를 실제로 가져오는 비동기 함수입니다. 이 함수는 Promise를 반환하고, React Query는 이 Promise가 해결되면 데이터를 저장하고, 컴포넌트는 그 데이터를 사용하게 됩니다.

```
const fetchData = async () => {
  const response = await axios.get('/api/data');
  return response.data;
};

const { data, isLoading } = useQuery('dataKey', fetchData);
```

쿼리 함수는 **비동기**로 데이터를 가져오며, 네트워크 요청이 완료될 때까지 기다립니다.

##### 상태 관리
`useQuery`는 다음과 같은 **상태**를 관리합니다:
- **isLoading**: 데이터가 로딩 중일 때 `true`로 설정됩니다. 처음 데이터가 요청되거나, 네트워크 요청이 실패했을 때 로딩 상태가 표시됩니다.
- **isError**: 데이터 요청에 오류가 발생했을 때 `true`로 설정됩니다.
- **data**: 쿼리 함수가 반환한 데이터를 저장합니다.
- **error**: 쿼리 함수에서 오류가 발생했을 때 그 오류를 저장합니다.
- **isSuccess**: 요청이 성공적으로 완료되었을 때 `true`로 설정됩니다.

#### useMutation
`useMutation`는 데이터를 서버에 보내는 데 사용되는 훅입니다.
    
```
import { useMutation } from 'react-query';
import axios from 'axios';

const sendData = async (newData) => {
  await axios.post('https://api.example.com/data', newData);
};

const MyComponent = () => {
  const { mutate } = useMutation(sendData);

  const handleSubmit = async () => {
	const newData = { name: 'New Data' };
	mutate(newData);
  };

  return (
	<div>
	  <button onClick={handleSubmit}>Submit</button>
	</div>
  );
};
```

### Redux
Redux는 **상태를 전역으로 관리**하는 상태 관리 라이브러리입니다. 애플리케이션의 상태는 **액션**을 통해 변경되며, 이를 처리하는 **리듀서**가 상태를 반환합니다.

- **예측 가능성**: 상태 변경이 명확하게 추적됩니다.
- **디버깅**: Redux DevTools를 사용하여 상태의 변화를 추적할 수 있습니다.
- **확장성**: 복잡한 애플리케이션에서 유리합니다.
- **보일러플레이트 코드**가 많습니다. 많은 설정과 코드가 필요합니다.

구조:
- **State**: 애플리케이션의 전역 상태를 저장합니다.
- **Action**: 상태를 변경할 때 사용하는 객체입니다. 상태 변경을 설명하는 정보입니다.
- **Reducer**: 액션을 받아서 새로운 상태를 반환하는 순수 함수입니다.
- **Store**: 상태를 저장하고, 액션을 리듀서에 전달하여 상태를 변경하는 객체입니다.
- **Dispatch**: 액션을 store에 전달하는 방법입니다.

설치:
```
npm install redux react-redux
```

#### Action 
`increment()`는 액션을 반환하는 함수입니다. 이 액션은 상태를 변경하는 타입 정보를 포함합니다.

```
// actions.js
export const increment = () => ({
  type: 'INCREMENT'
});
```

#### Reducer 
`counterReducer`는 액션을 처리하여 새로운 상태를 반환하는 함수입니다. 액션 타입에 따라 상태를 변경합니다.

```
// reducer.js
const initialState = {
  count: 0
};

const counterReducer = (state = initialState, action) => {
  switch (action.type) {
    case 'INCREMENT':
      return { ...state, count: state.count + 1 };
    default:
      return state;
  }
};

export default counterReducer;
```

#### Store
`createStore`로 상태를 보관합니다.

```
// store.js
import { createStore } from 'redux';
import counterReducer from './reducer';

const store = createStore(counterReducer);
export default store;
```

#### Provider
`Provider`를 사용하여 전역 상태를 자식 컴포넌트에 전달합니다.

```
// App.js
import React from 'react';
import { Provider } from 'react-redux';
import store from './store';
import Counter from './Counter';

const App = () => (
  <Provider store={store}>
    <Counter />
  </Provider>
);

export default App;
```

#### 상태 사용
- **useSelector**: 전역 상태를 가져옵니다.
- **useDispatch**: 액션을 dispatch하여 상태를 변경합니다.

```
// Counter.js
import React from 'react';
import { useDispatch, useSelector } from 'react-redux';
import { increment } from './actions';

const Counter = () => {
  const count = useSelector((state) => state.count);
  const dispatch = useDispatch();

  return (
    <div>
      <h1>Count: {count}</h1>
      <button onClick={() => dispatch(increment())}>Increment</button>
    </div>
  );
};

export default Counter;
```

### Zustand
Zustand는 Redux보다 간단하고 가벼운 상태 관리 라이브러리로, **보일러플레이트 코드**를 최소화하고 **간단한 API**로 상태를 관리할 수 있도록 도와줍니다. **React Context**를 사용하여 상태를 관리하고, **컴포넌트 간 상태 공유**가 가능합니다.

- **간단함**: 설정이 간단하고, 상태 관리가 직관적입니다.
- **빠른 리렌더링**: 상태 변경 시, 리렌더링을 최소화할 수 있습니다.
- **성능**: 상태를 변경할 때 최소한의 리렌더링을 수행하여 성능이 뛰어납니다.
- **상대적으로 적은 기능**: Redux와 비교하면 디버깅 도구나 고급 기능이 부족할 수 있습니다.
- **유연성 부족**: 복잡한 상태 관리나 여러 액션을 처리하는 데 있어 Redux만큼 유연하지 않을 수 있습니다.

설치:
```
npm install zustand
```

Zustand는 상태를 **store**에 저장하고, **setter**와 **getter**로 상태를 변경하고 읽습니다.

#### 설정
- **create**: Zustand의 `create` 함수는 상태를 설정하고 반환하는 훅을 만듭니다.
- **set**: `set`을 사용하여 상태를 변경합니다.

```
// useStore.js
import create from 'zustand';

const useStore = create((set) => ({
  count: 0,
  increment: () => set((state) => ({ count: state.count + 1 })),
  decrement: () => set((state) => ({ count: state.count - 1 })),
}));

export default useStore;
```

#### 사용
- **useStore**: 상태를 읽고 변경할 수 있는 커스텀 훅입니다. 각 컴포넌트는 이 훅을 사용하여 상태를 공유합니다.

```
// Counter.js
import React from 'react';
import useStore from './useStore';

const Counter = () => {
  const { count, increment, decrement } = useStore();

  return (
    <div>
      <h1>Count: {count}</h1>
      <button onClick={increment}>Increment</button>
      <button onClick={decrement}>Decrement</button>
    </div>
  );
};

export default Counter;
```

#### getState
`getState`는 Zustand의 **상태를 직접 가져오는 함수**입니다. 주로 **컴포넌트 외부에서 상태를 접근하거나 업데이트할 때 사용**됩니다.

```javascript
// Zustand store 정의
import create from 'zustand';

const useStore = create((set) => ({
  count: 0,
  increment: () => set((state) => ({ count: state.count + 1 })),
}));

// 컴포넌트 외부에서 상태와 업데이트 함수 사용하기
const state = useStore.getState(); // 상태를 가져옴
console.log(state.count);  // 현재 상태 출력

// 상태 업데이트하기
state.increment();  // 상태를 변경하는 액션 호출
```

#### state
Zustand의 `set` 함수는 **이전 상태(`state`)를 매개변수로 받아** 부분적으로 업데이트할 수 있습니다.

```
import create from 'zustand';

const useStore = create((set) => ({
  count: 0,
  name: 'React',
  increment: () => set((state) => ({ count: state.count + 1 })),
  setName: (newName) => set((state) => ({ name: newName })),
}));
```

### Expo Location
`expo-location`은 React Native(Expo)에서  **위치 정보를 다루는 라이브러리**입니다.  
이를 사용하면 **GPS 기반 현재 위치 조회, 실시간 위치 추적, 위치 권한 요청** 등의 기능을 쉽게 구현할 수 있습니다.

권한 요청 → 위치 가져오기 → 지속적 추적을 손쉽게 처리할 수 있어 **위치 기반 서비스(지도, 내비게이션, 위치 기록 등)** 개발에 적합합니다.

설치:
```
npx expo install expo-location
```

#### 현재 위치 가져오기
```
import * as Location from 'expo-location';
import { useState, useEffect } from 'react';
import { Text, View } from 'react-native';

export default function App() {
  const [location, setLocation] = useState(null);
  const [errorMsg, setErrorMsg] = useState(null);

  useEffect(() => {
    (async () => {
      let { status } = await Location.requestForegroundPermissionsAsync();
      if (status !== 'granted') {
        setErrorMsg('위치 권한이 필요합니다.');
        return;
      }

      let loc = await Location.getCurrentPositionAsync({});
      setLocation(loc);
    })();
  }, []);

  return (
    <View>
      <Text>위치: {location ? `${location.coords.latitude}, ${location.coords.longitude}` : '로딩 중...'}</Text>
      {errorMsg && <Text>오류: {errorMsg}</Text>}
    </View>
  );
}
```

---

#### 지속적인 위치 추적
```
import * as Location from 'expo-location';
import { useState, useEffect } from 'react';
import { Text, View } from 'react-native';

export default function App() {
  const [location, setLocation] = useState(null);

  useEffect(() => {
    let subscription;

    (async () => {
      let { status } = await Location.requestForegroundPermissionsAsync();
      if (status !== 'granted') {
        return;
      }

      subscription = await Location.watchPositionAsync(
        { accuracy: Location.Accuracy.High, timeInterval: 5000, distanceInterval: 10 },
        (loc) => setLocation(loc)
      );
    })();

    return () => subscription?.remove(); // 컴포넌트 언마운트 시 추적 해제
  }, []);

  return (
    <View>
      <Text>위치: {location ? `${location.coords.latitude}, ${location.coords.longitude}` : '로딩 중...'}</Text>
    </View>
  );
}
```

#### 백그라운드 위치 추적
```
import * as Location from 'expo-location';
import * as TaskManager from 'expo-task-manager';

const LOCATION_TASK_NAME = "background-location-task";

// 백그라운드 위치 추적 작업 정의
TaskManager.defineTask(LOCATION_TASK_NAME, async ({ data, error }) => {
  if (error) {
    console.error("위치 업데이트 오류:", error);
    return;
  }
  if (data) {
    const { locations } = data;
    console.log("백그라운드 위치 업데이트:", locations);
  }
});

// 백그라운드 위치 업데이트 시작
const startBackgroundLocation = async () => {
  const { status } = await Location.requestBackgroundPermissionsAsync();
  if (status !== "granted") {
    console.log("배경 위치 권한이 필요합니다.");
    return;
  }

  await Location.startLocationUpdatesAsync(LOCATION_TASK_NAME, {
    accuracy: Location.Accuracy.High,
    timeInterval: 5000, // 5초마다 업데이트
    distanceInterval: 10, // 10m 이동 시 업데이트
    deferredUpdatesInterval: 60000, // 60초마다 배터리 절약 모드에서 업데이트
  });

  console.log("백그라운드 위치 추적 시작됨!");
};
```

### Expo Task Manager
**`expo-task-manager`**는 **Expo** 환경에서 **백그라운드 작업**을 처리하고 관리할 수 있도록 도와주는 라이브러리입니다. 이를 통해 **백그라운드 작업**(예: 위치 추적, 푸시 알림 등)을 앱이 백그라운드 상태일 때도 지속적으로 실행할 수 있습니다.

1. **백그라운드 작업 관리**
    - `expo-task-manager`는 **백그라운드 작업**을 등록하고, 그 작업이 완료되었을 때 알림을 받을 수 있도록 합니다. 예를 들어, 위치 추적, 파일 다운로드 등을 백그라운드에서 처리할 수 있습니다.
2. **백그라운드 위치 추적**
    - `Location.startLocationUpdatesAsync`와 같이 **위치 추적 작업**을 등록할 때 `expo-task-manager`를 활용하여 **백그라운드에서 위치 추적**을 계속 수행할 수 있습니다.
3. **작업 실행 상태 추적**
    - 등록된 작업이 실행 중인지 아니면 완료되었는지를 추적할 수 있습니다. 이는 작업이 종료되었거나, 특정 상태에 도달했을 때 앱에 알림을 보내거나 다른 작업을 처리하는 데 유용합니다.

설치:
```
npm install expo-task-manager
```

사용:
```
import * as TaskManager from 'expo-task-manager';
import * as Location from 'expo-location';

const LOCATION_TASK_NAME = 'background-location-task';

// 백그라운드에서 실행될 작업 등록
TaskManager.defineTask(LOCATION_TASK_NAME, ({ data, error }) => {
  if (error) {
    console.error(error);
    return;
  }

  const { locations } = data;
  if (locations) {
    console.log("New location:", locations);
  }
});

// 위치 추적 시작
async function startLocationTracking() {
  await Location.startLocationUpdatesAsync(LOCATION_TASK_NAME, {
    accuracy: Location.Accuracy.Balanced,
    timeInterval: 5000, // 5초마다 업데이트
    distanceInterval: 10, // 10m 이동 시 업데이트
  });
}
```

### Expo Sensors
`expo-sensors`는 Expo 프레임워크에서 제공하는 **센서 관련 API**입니다. 이 패키지는 **기기에서 사용할 수 있는 다양한 센서들**에 접근하여 데이터를 얻고, 이를 애플리케이션에서 활용할 수 있도록 돕습니다. 예를 들어, **가속도계(accelerometer)**, **자이로스코프(gyroscope)**, **자기장 센서(magnetometer)**, **기울기 센서(gravimeter)** 등을 통해 장치의 물리적 움직임, 방향, 회전 등을 실시간으로 감지할 수 있습니다.

- **Accelerometer**: 기기의 **가속도**를 측정하여 기기 움직임을 감지합니다. (예: 기기 기울기, 빠르게 움직이는 속도 등)
- **Gyroscope**: 기기의 **회전**을 측정하여 회전 운동을 추적합니다. (예: 화면 회전 감지)
- **Magnetometer**: 기기의 **자기장**을 측정하여 방향을 추정합니다. (예: 나침반 기능)
- **Barometer**: 기기의 **기압**을 측정하여 고도나 날씨 변화를 추적합니다.
- **DeviceMotion**: 여러 센서의 정보를 결합하여 **기기의 움직임**을 종합적으로 추적합니다.

설치:
```
expo install expo-sensors
```

#### 사용
**가속도계 데이터를 실시간으로 받아와서 화면에 표시**하는 예시입니다.
```
import { useEffect, useState } from 'react';
import { Accelerometer } from 'expo-sensors';

export default function App() {
  const [accelerometerData, setAccelerometerData] = useState({
    x: 0,
    y: 0,
    z: 0,
  });

  useEffect(() => {
    const subscription = Accelerometer.addListener((accelerometerData) => {
      setAccelerometerData(accelerometerData);
    });

    // Clean up the subscription when the component unmounts
    return () => subscription.remove();
  }, []);

  return (
    <View>
      <Text>Accelerometer data:</Text>
      <Text>X: {accelerometerData.x}</Text>
      <Text>Y: {accelerometerData.y}</Text>
      <Text>Z: {accelerometerData.z}</Text>
    </View>
  );
}
```

### AsyncStorage
`AsyncStorage`는 **React Native**에서 제공하는 **비동기적(key-value) 데이터 저장 방식**입니다. 이 저장소는 **앱이 종료된 후에도 데이터를 유지**할 수 있으며, 간단한 설정으로 **영구 저장 가능한 데이터를** 저장할 수 있습니다.

- **비동기적**: 데이터를 **비동기적으로 저장하고 불러옵니다.**
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
const storeData = async () => {
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
const getData = async () => {
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
const removeData = async () => {
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
const clearData = async () => {
  try {
    await AsyncStorage.clear();
    console.log('모든 데이터 삭제 완료');
  } catch (error) {
    console.error("초기화 실패", error);
  }
};
```

### react-native-maps
`react-native-maps`는 **React Native** 환경에서 **지도**를 표시하고, **마커**와 **경로** 등을 추가할 수 있게 도와주는 라이브러리입니다.  이 라이브러리는 **Google Maps**, **Apple Maps**, **OpenStreetMap** 등을 사용하여 지도 위에 다양한 요소를 추가할 수 있습니다.

1. **지도 표시**: `MapView` 컴포넌트를 사용하여 기본적인 지도 표시.
2. **마커 추가**: 지도에 특정 위치를 표시할 수 있는 `Marker` 컴포넌트 제공.
3. **경로 그리기**: 두 지점 간의 경로를 그릴 수 있는 기능.
4. **실시간 위치 추적**: 현재 위치를 받아서 지도에 표시하거나, **사용자 위치**에 따라 지도를 업데이트.
5. **다양한 지도 제공**: Google Maps, Apple Maps, OpenStreetMap 등 여러 지도 제공 옵션이 있음.

설치:
```
npm install react-native-maps
```

#### 지도 표시
```
import React from "react";
import { View, StyleSheet } from "react-native";
import MapView from "react-native-maps";

const MapScreen = () => {
  return (
    <View style={styles.container}>
      <MapView 
        style={styles.map} 
        initialRegion={{
          latitude: 37.5665,
          longitude: 126.9780,
          latitudeDelta: 0.01,
          longitudeDelta: 0.01,
        }} 
      />
    </View>
  );
};

const styles = StyleSheet.create({
  container: { flex: 1 },
  map: { flex: 1 },
});

export default MapScreen;
```

|속성|설명|
|---|---|
|`initialRegion`|지도에 처음 표시할 중심 위치와 줌 수준 설정|
|`region`|지도 중심을 동적으로 업데이트할 때 사용 (매번 리렌더링 필요)|
|`style`|지도 컴포넌트의 크기 지정|
|`provider`|`google`을 설정하면 iOS에서도 Google Maps 사용 가능|
|`showsUserLocation`|사용자의 현재 위치를 지도에 표시|

#### 마커 추가
`Marker` 컴포넌트를 사용하여 특정 위치에 마커를 추가할 수 있습니다.

```
import MapView, { Marker } from "react-native-maps";

<MapView style={styles.map} initialRegion={{ latitude: 37.5665, longitude: 126.9780, latitudeDelta: 0.01, longitudeDelta: 0.01 }}>
  <Marker coordinate={{ latitude: 37.5665, longitude: 126.9780 }} title="서울" description="서울의 중심" />
</MapView>
```

### WebSocket
Expo에서 웹소켓을 사용하려면, 기본적으로 **`WebSocket` API**를 사용하면 됩니다. Expo는 네이티브 코드 없이 웹소켓을 지원하므로, 기본적으로 제공하는 `WebSocket` 클래스를 통해 서버와의 연결을 관리할 수 있습니다.

#### 웹소켓 연결
웹소켓 연결 요청은 클라이언트에서 **`WebSocket`** 객체를 생성하면서 자동으로 이루어집니다.
    
```
const socket = new WebSocket('ws://yourserver.com/socket');
```
    
#### 웹소켓 이벤트 처리
웹소켓 연결이 열리면 `onopen` 이벤트가 발생하고, 메시지가 오면 `onmessage` 이벤트가 발생합니다. 오류가 발생하면 `onerror`, 연결이 종료되면 `onclose` 이벤트가 발생합니다.
    
```
socket.onopen = () => {
  console.log('WebSocket connected');
  // 연결이 성공했을 때 할 일
};

socket.onmessage = (event) => {
  console.log('Message received: ', event.data);
  // 서버에서 받은 메시지 처리
};

socket.onerror = (error) => {
  console.log('WebSocket error: ', error);
  // 오류 처리
};

socket.onclose = (event) => {
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

### React Native Rsa Native
`react-native-rsa-native`는 React Native 환경에서 RSA 암호화와 관련된 기능을 제공하는 라이브러리입니다. 이 라이브러리는 RSA 암호화 알고리즘을 구현하여 모바일 애플리케이션에서 데이터를 암호화하고 복호화하는 작업을 수행할 수 있게 해줍니다.

설치:
```
npm install react-native-rsa-native
```

예시:
```
import RsaNative from 'react-native-rsa-native';

// 키 생성
const generateKey = async () => {
  try {
    const keys = await RsaNative.generateKeys(2048);
    console.log(keys);  // 공개키(publicKey), 개인키(privateKey)
  } catch (error) {
    console.error(error);
  }
};

// 데이터 암호화
const encryptData = async (data, publicKey) => {
  try {
    const encryptedData = await RsaNative.encrypt(data, publicKey);
    console.log('Encrypted:', encryptedData);
  } catch (error) {
    console.error(error);
  }
};

// 데이터 복호화
const decryptData = async (encryptedData, privateKey) => {
  try {
    const decryptedData = await RsaNative.decrypt(encryptedData, privateKey);
    console.log('Decrypted:', decryptedData);
  } catch (error) {
    console.error(error);
  }
};
```

### Expo Sqlite
`expo-sqlite`는 **Expo**에서 제공하는 **SQLite** 데이터베이스 인터페이스 라이브러리입니다.  
이 라이브러리는 **모바일 애플리케이션에서 구조화된 데이터를 로컬 데이터베이스에 저장하고 관리**할 수 있도록 도와줍니다.

1️. **로컬 데이터베이스**: 앱 내에서 데이터베이스를 구축하고 관리할 수 있습니다.  
2️. **구조화된 데이터 저장**: 데이터를 테이블과 쿼리를 사용해 구조적으로 저장할 수 있습니다.  
3️. **빠른 조회**: SQL 쿼리를 사용해 데이터를 효율적으로 조회할 수 있습니다.  
4️. **단일 파일**: SQLite는 파일 기반 데이터베이스로, **하나의 파일**로 데이터가 저장됩니다.  
5️. **내장형 SQL 엔진**: 별도의 서버 없이 앱 내에서 SQL 쿼리를 실행할 수 있습니다.

설치:
```bash
npm install expo-sqlite
```

사용법:
> https://docs.expo.dev/versions/latest/sdk/sqlite/

