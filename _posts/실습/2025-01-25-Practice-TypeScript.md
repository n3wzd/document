---
categories:
- Practice
date: '2025-01-25'
title: '[Practice] TypeScript'
---

{% raw %}
### ts vs tsx
`ts`와 `tsx`는 모두 TypeScript 파일을 나타내지만, 주된 차이는 **JSX 구문**의 사용 가능 여부입니다.

|**특징**|**ts**|**tsx**|
|---|---|---|
|**JSX 지원 여부**|JSX를 포함할 수 없음|JSX를 포함할 수 있음|
|**주요 용도**|로직, 타입 정의, 유틸리티 함수 작성|React 컴포넌트 및 UI 렌더링 코드 작성|
|**파일 확장자**|`.ts`|`.tsx`|

React 프로젝트에서는 컴포넌트 파일을 작성할 때 대부분 `tsx`를 사용하고, 유틸리티나 타입 정의와 같은 비주얼 요소가 없는 코드는 `ts`로 작성하는 것이 일반적입니다.

### tsconfig.json: No inputs were found in config file
TypeScript는 컴파일을 위해 폴더에 적어도 하나의 TypeScript 파일이 있어야 합니다.

### An import path can only end with a '.ts' extension when 'allowImportingTsExtensions' is enabled
`tsconfig.json`에서 다음을 추가합니다.
```
"allowImportingTsExtensions": true
```

### TypeError: Unknown file extension ".ts"
`tsx` 패키지를 사용해야 합니다.

출처: 
- https://stackoverflow.com/questions/62096269/unknown-file-extension-ts-for-a-typescript-file

### 타입 전역 선언
`d.ts` 파일에서 다음과 같이 선언하면 import 없이 전역에서 타입을 사용할 수 있습니다.
```
declare global {
	interface User {
		userId: string;
		name: string;
	}
}
```
{% endraw %}