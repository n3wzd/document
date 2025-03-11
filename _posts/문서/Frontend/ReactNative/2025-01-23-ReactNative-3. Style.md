---
categories:
- ReactNative
date: '2025-01-23'
title: '[ReactNative] 3. Style'
---

{% raw %}
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

const MyComponent = () => {<br>
  return (
	<View style={styles.container}>
	  <Text style={styles.text}>Hello, World!</Text>
	</View>
  );
};
```
{% endraw %}