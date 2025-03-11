---
categories:
- ReactNative
date: '2025-01-24'
title: '[ReactNative] React Navigation'
---

{% raw %}
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

const HomeScreen = ({ navigation }: { navigation: any }) => {<br>
  return (
    <View>
      <Text>Home Screen</Text>
      <Button
        title="Go to Login"
        onPress={() => navigation.navigate('Login')}<br>
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
const LoginScreen = ({ route }: { route: any }) => {<br>
  const { userId } = route.params;

  return (
    <View>
      <Text>Login Screen</Text>
      <Text>User ID: {userId}</Text>
    </View>
  );
};
```
{% endraw %}