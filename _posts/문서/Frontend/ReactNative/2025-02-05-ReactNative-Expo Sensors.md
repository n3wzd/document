---
categories:
- ReactNative
date: '2025-02-05'
title: '[ReactNative] Expo Sensors'
---

{% raw %}
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

  useEffect(() => {<br>
    const subscription = Accelerometer.addListener((accelerometerData) => {<br>
      setAccelerometerData(accelerometerData);
    });

    // Clean up the subscription when the component unmounts
    return () => subscription.remove();<br>
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
{% endraw %}