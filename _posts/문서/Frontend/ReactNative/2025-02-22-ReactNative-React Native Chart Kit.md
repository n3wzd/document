---
categories:
- ReactNative
date: '2025-02-22'
title: '[ReactNative] React Native Chart Kit'
---

{% raw %}
`react-native-chart-kit`은 **React Native에서 데이터를 시각화하기 위한 라이브러리**로, 다양한 차트(막대 그래프, 선 그래프, 원형 그래프 등)를 쉽게 구현할 수 있도록 도와주는 도구입니다. 이 라이브러리는 `react-native-svg`에 의존하여 그래프와 차트를 그리므로, React Native 애플리케이션에서 고품질의 차트를 그릴 수 있습니다.

1. **간편한 설치와 사용**
    - 설치가 간단하고, 사용하기 쉽습니다. 복잡한 설정 없이 바로 데이터를 시각화할 수 있습니다.
2. **다양한 차트 지원**
    - **막대 그래프 (Bar Chart)**
    - **선 그래프 (Line Chart)**
    - **원형 그래프 (Pie Chart)**
    - **혼합 차트 (Multi chart)**
3. **풍부한 커스터마이징**
    - 색상, 데이터 값, 레이블 등을 쉽게 커스터마이즈할 수 있습니다.
    - 애니메이션을 지원하여 데이터가 업데이트될 때 시각적으로 매끄러운 변화를 제공합니다.
4. **직관적인 구성 요소**
    - 그래프를 구성하는 데 필요한 요소가 명확하고, 데이터를 `datasets` 형식으로 넘겨주면 자동으로 차트를 그려줍니다.

설치:
```
npm install react-native-chart-kit react-native-svg
```

#### 사용 예시
- **`BarChart`**: 막대 그래프를 그릴 때 사용합니다.
- **`LineChart`**: 선 그래프를 그릴 때 사용합니다.
- **`PieChart`**: 원형 그래프를 그릴 때 사용합니다.
- **`ProgressChart`**: 진행도 차트를 그릴 때 사용합니다.

```tsx
import React from 'react';
import { View, Text, StyleSheet } from 'react-native';
import { BarChart } from 'react-native-chart-kit';

const data = {
  labels: ["Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"], // x축 레이블
  datasets: [
    {
      data: [1200, 2300, 1500, 3500, 2700, 4800, 2200], // y축 데이터
    }
  ],
};

const ChartComponent = () => {<br>
  return (
    <View style={styles.container}>
      <Text style={styles.title}>주간 걸음 수</Text>
      <BarChart
        data={data}
        width={320}  // 차트의 너비
        height={220} // 차트의 높이
        yAxisSuffix=" steps" // y축에 단위 표시
        chartConfig={{
          backgroundGradientFrom: "#ffffff",  // 배경 색상
          backgroundGradientTo: "#f2f2f2",    // 배경 색상
          color: (opacity = 1) => `rgba(0, 128, 255, ${opacity})`, // 막대 색상<br>
          labelColor: () => "#000000", // 레이블 색상<br>
          barPercentage: 0.5,  // 막대 너비 비율
        }}
      />
    </View>
  );
};

const styles = StyleSheet.create({
  container: { alignItems: 'center', marginTop: 20 },
  title: { fontSize: 18, fontWeight: 'bold', marginBottom: 10 },
});

export default ChartComponent;
```
{% endraw %}