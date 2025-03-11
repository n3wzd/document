---
categories:
- ReactNative
date: '2025-02-05'
title: '[ReactNative] Expo Task Manager'
---

{% raw %}
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
TaskManager.defineTask(LOCATION_TASK_NAME, ({ data, error }) => {<br>
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
{% endraw %}