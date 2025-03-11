---
categories:
- Practice
date: '2025-01-25'
title: '[Practice] React Native'
---

{% raw %}
### `router.d.ts`가 업데이트되지 않을 때
`npm start`를 하면 자동으로 업데이트됩니다.

### start by creating a file in the app directory
react-native-dotenv는 expo-router와 호환되지 않습니다. 환경 변수를 사용하려면 다음 방법을 사용합니다.

출처:
- https://stackoverflow.com/questions/78494804/expo-stuck-on-welcome-to-expo-screen
- https://docs.expo.dev/guides/environment-variables/

### Route "" is missing the required default export. Ensure a React component is exported as default.
Expo Router가 라우트 파일에는 기본 내보내기(`default export`)가 필요하다고 강제하는 경우입니다. 라우트 경로(`pages/`, `app/`, `routes/`) 내부에 `types/static-data.ts`가 있으면 Expo Router가 이를 페이지로 인식하여 `default export`가 없다고 오류를 발생시킵니다.

컴포넌트가 아닌 파일은 라우트(`/app`, `/pages`, `/routes`) 내부에 있을 필요가 없으며, 오히려 **라우트 외부로 이동하는 것이 올바른 방식**입니다.

### useLocalSearchParams의 반환 값 타입
`expo-router`의 `useLocalSearchParams`가 `string | string[]` 타입을 반환하는 이유는 쿼리 파라미터가 단일 값일 수도 있고, 배열일 수도 있기 때문입니다.

```
// URL: /game?level=easy&level=hard
const { level } = useLocalSearchParams();
console.log(level); // ["easy", "hard"]
```

### Error: Invalid hook call. Hooks can only be called inside of the body of a function component.
이 오류는 React 훅이 컴포넌트 함수외부에서 호출되었을 때 발생합니다. 훅은 반드시 React 컴포넌트의 함수 내에서만 호출할 수 있습니다. 백그라운드 프로세스나 다른 곳에서 훅을 호출하면 이 오류가 발생합니다.

`useStore`와 같은 훅을 컴포넌트 내에서만 호출하고, 컴포넌트 외부에서 상태를 변경하려면 전역 상태 라이브러리(예: Zustand)를 활용해야 합니다.

백그라운드에서 상태를 업데이트할 때는 `useStore.getState()`를 사용하여 상태를 업데이트할 수 있습니다. 이 방식은 훅을 사용하지 않고도 상태를 변경 수 있게 해줍니다.

```
// Zustand store 정의
import create from 'zustand';

const useStore = create((set) => ({<br>
  state: null,
  updateState: (newState) => set({ state: newState }),<br>
}));

// 백그라운드에서 상태 변경
const backgroundProcess = () => {<br>
  const updateState = useStore.getState().updateState;  // 상태 업데이트 함수 가져오기

  setInterval(() => {<br>
    const newState = calculateNewState(); // 새로운 상태 계산
    updateState(newState);  // 상태 업데이트
  }, 1000);
};
```

### 메시지 없이 아무 화면도 표시되지 않을 때
패키지가 호환되지 않으면 작동되지 않을 수 있습니다. 예를 들어 expo는 `react-native-crypto`,  `node-forge`와 호환되지 않습니다.

### Uncaught Error: java.io.IOException: failed to download remote update
Expo Go에서 네트워크 관련 오류일 확률이 높습니다. 재부팅 등을 하면 해결됩니다.

### The package attempted to import the Node standard library module. It failed because the native React runtime does not include the Node standard library.
Node.js의 내장 모듈을 가져오려 하지만, React Native 환경에는 Node.js 내장 모듈이 없어서 발생합니다.

예: `react-native-svg`는 Node.js 내장 모듈 `buffer`을 사용하기에, `expo-router`와 `react-native-svg`가 충돌하는 경우가 있습니다. expo-router가 설치되어 있다면, `react-native-svg` 버전을 `13.x.x`로 다운그레이드해 보세요.

```
npm install react-native-svg@13.9.0
```

### Text strings must be rendered within a Text component
`&&`문 사용시 공백이 표현될 수 있기 때문입니다. 다음으로 대체합니다.

**DON'T DO**
```javascript
widgetNumber === 10 && <MyComponent />
```

**DO DO**
```javascript
widgetNumber === 10 ? <MyComponent /> : null<br>
```

출처:
- https://stackoverflow.com/questions/52368342/text-strings-must-be-rendered-within-a-text-component

### 반환 값 vs 메서드 체이닝
```
const date = new Date("2024-02-24");
const result = date.setDate(date.getDate() + 5);

console.log(result); // 타임스탬프 (숫자) 반환
console.log(date.toString()); // 수정된 날짜 확인 가능
```

`setDate()`는 수정된 `Date` 객체를 반환하지 않고, 수정된 타임스탬프(숫자)를 반환합니다. 따라서 `setDate()`를 체이닝해서 바로 `.toString()`을 호출하면 안 됩니다.

### FormData (TypeScript)
React Native의 `FormData`는 웹의 FormData와 완전히 동일하지 않습니다.특히, Blob이나 File 객체를 직접 추가하면 정상적으로 작동하지 않을 수 있습니다. React Native에서는 파일을 `Blob` 대신 `{ uri, type, name }` 형식으로 추가해야 합니다.

TypeScript에서 `FormData.append`는 기본적으로 웹 표준을 따르기 때문에, `{ uri, type, name }` 형식을 허용하지 않습니다. 하지만 React Native에서는 파일을 `Blob`이 아니라 `{ uri, type, name }` 형식으로 보내야 하기 때문에, 타입 충돌이 발생하는 것입니다.

이 문제를 해결하려면 TypeScript에게 "이 값이 올바른 형식이다"라고 명시적으로 알려줘야 합니다.
```
formData.append('file', {
	uri: fileUri,
	type: 'image/jpeg',
	name: filename,
} as unknown as Blob);
```

### Error: Call to function 'ExponentFileSystem.downloadAsync' has been rejected. → Caused by: java.io.IOException Location isn't writable.
이 오류는 `expo-file-system`의 `downloadAsync` 메서드를 사용할 때 발생하는 문제로, 파일을 저장하려는 경로가 잘못 지정되었기 때문입니다. 오류 메시지에 나타난 경로는 읽기 전용 경로를 가리키고 있어 쓰기 작업을 할 수 없습니다.

Expo 앱에서 `@/assets` 경로는 앱의 번들에 포함된 리소스를 나타냅니다. 이 경로는 앱의 내부 파일 시스템에서 읽기만 할 수 있으며, 파일을 저장하거나 다운로드할 수 없습니다. 즉, `@/assets/` 폴더는 읽기 전용으로, 파일을 쓸 수 있는 경로가 아닙니다.

### 서버 리소스 요청 캐시
일반적으로 파일 이름이 같으면 기존 캐시된 파일을 계속 가져올 가능성이 높습니다. 이는 서버 요청과 로컬 캐시 요청 모두에서 발생할 수 있습니다. HTTP 캐시 정책 (`Cache-Control`, `ETag`, `Last-Modified` 등) 때문에 새 요청을 보내지 않고 캐시된 응답을 사용할 수 있습니다.

파일이 변경될 때마다 `?v=timestamp` 같은 버전 정보(더미 파라미터)를 쿼리스트링으로 추가하면 캐시를 우회하여 새로운 리소스를 가져올 수 있습니다.

```
const timestamp = Date.now();  
const imageUrl = `/path/to/file.jpg?v=${timestamp}`;
```
{% endraw %}