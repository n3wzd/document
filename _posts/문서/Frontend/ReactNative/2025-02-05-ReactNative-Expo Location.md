---
categories:
- ReactNative
date: '2025-02-05'
title: '[ReactNative] Expo Location'
---

{% raw %}
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

  useEffect(() => {<br>
    (async () => {<br>
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

  useEffect(() => {<br>
    let subscription;

    (async () => {<br>
      let { status } = await Location.requestForegroundPermissionsAsync();
      if (status !== 'granted') {
        return;
      }

      subscription = await Location.watchPositionAsync(
        { accuracy: Location.Accuracy.High, timeInterval: 5000, distanceInterval: 10 },
        (loc) => setLocation(loc)<br>
      );
    })();

    return () => subscription?.remove(); // 컴포넌트 언마운트 시 추적 해제<br>
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
TaskManager.defineTask(LOCATION_TASK_NAME, async ({ data, error }) => {<br>
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
const startBackgroundLocation = async () => {<br>
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
{% endraw %}