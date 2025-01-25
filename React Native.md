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
2. `handleSubmit`: 폼 제출을 처리하는 함수입니다.
    - `handleSubmit`은 유효성 검사를 통과한 데이터만 `onSubmit` 함수로 전달합니다.
    - 예: `<form onSubmit={handleSubmit(onSubmit)}></form>`
3. `formState`: 폼의 상태를 추적하는 객체입니다.
    - `formState.errors`: 유효성 검사 오류를 추적하는 객체입니다.
    - 예: `formState.errors.name`은 `name` 필드에 대한 오류를 추적합니다.
4. `setValue`: 필드 값을 동적으로 설정할 수 있는 함수입니다.
    - 예: `setValue('name', 'John Doe')`는 `name` 필드의 값을 `'John Doe'`로 설정합니다.
5. `watch`: 필드 값을 실시간으로 추적할 수 있는 함수입니다.
    - 예: `const name = watch('name')`는 `name` 필드의 값을 실시간으로 추적합니다.
6. `reset`: 폼을 초기화하는 함수입니다.
    - 예: `reset()`을 호출하면 폼을 초기 상태로 되돌립니다.
7. `clearErrors`: 특정 필드 또는 모든 필드의 오류를 제거하는 함수입니다.
    - 예: `clearErrors('name')`는 `name` 필드의 오류를 제거합니다.

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
    await SecureStorage.setItem('user_token', token);
  } catch (e) {
    console.error('Failed to save token:', e);
  }
};

// 토큰 가져오기
const getToken = async () => {
  try {
    const token = await SecureStorage.getItem('user_token');
    return token;
  } catch (e) {
    console.error('Failed to fetch token:', e);
  }
};

// 토큰 삭제
const removeToken = async () => {
  try {
    await SecureStorage.removeItem('user_token');
  } catch (e) {
    console.error('Failed to remove token:', e);
  }
};
```
