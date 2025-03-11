---
categories:
- ReactNative
date: '2025-01-25'
title: '[ReactNative] React Native Dotenv'
---

{% raw %}
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
{% endraw %}