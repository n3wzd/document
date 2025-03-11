---
categories:
- ReactNative
date: '2025-02-05'
title: '[ReactNative] React Native Maps'
---

{% raw %}
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

const MapScreen = () => {<br>
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
{% endraw %}