---
categories:
- ReactNative
date: '2025-01-24'
title: '[ReactNative] Expo Router'
---

{% raw %}
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

const HomeScreen = () => {<br>
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

const HomeScreen = () => {<br>
  const router = useRouter();

  const goToProfile = () => {<br>
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
          tabBarIcon: ({ color, size }) => (<br>
            <Ionicons name="home-outline" color={color} size={size} />
          ),
        }}
      />
      {/* Profile Tab */}
      <Tabs.Screen
        name="profile"
        options={{
          title: 'Profile',
          tabBarIcon: ({ color, size }) => (<br>
            <Ionicons name="person-outline" color={color} size={size} />
          ),
        }}
      />
      {/* Settings Tab */}
      <Tabs.Screen
        name="settings"
        options={{
          title: 'Settings',
          tabBarIcon: ({ color, size }) => (<br>
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
> https://docs.expo.dev/router/advanced/tabs/<br>
{% endraw %}