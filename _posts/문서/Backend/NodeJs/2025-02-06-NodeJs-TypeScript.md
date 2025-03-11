---
categories:
- NodeJs
date: '2025-02-06'
title: '[NodeJs] TypeScript'
---

{% raw %}
### TypeScript
Node.js에서도 TypeScript를 사용할 수 있습니다.

#### tsconfig.json
**tsconfig.json** 파일은 TypeScript 프로젝트의 컴파일 옵션을 정의하는 핵심 설정 파일입니다. 이 파일을 통해 프로젝트의 컴파일 방식, 출력 형식, 타입 검사 수준 등을 세밀하게 조절할 수 있습니다.

```
{
  "compilerOptions": {
    "target": "es6",
    "module": "commonjs",
    "outDir": "./dist",
    "rootDir": "./src",
    "strict": true,
    "esModuleInterop": true,
    "skipLibCheck": true,
    "forceConsistentCasingInFileNames": true
  }
}
```

- **target:** 생성될 JavaScript 코드의 ES 버전을 지정합니다. (예: es5, es6, esnext)
- **module:** 모듈 시스템을 지정합니다. (예: commonjs, es2015)
- **outDir:** 컴파일된 JavaScript 파일이 저장될 디렉토리를 지정합니다.
- **rootDir:** 소스 코드의 루트 디렉토리를 지정합니다.
- **strict:** 엄격한 타입 검사를 활성화합니다.
- **esModuleInterop:** CommonJS와 ES Modules 간의 상호 운용성을 위한 옵션입니다.
- **skipLibCheck:** 타입 정의 파일 검사를 생략합니다.
- **forceConsistentCasingInFileNames:** 파일 이름의 대소문자를 일관되게 유지합니다.
- **allowJs:** JavaScript 파일을 포함하여 컴파일할 수 있도록 허용합니다.
- **declaration:** 타입 정의 파일(.d.ts)을 생성합니다.
- **sourceMap:** 소스맵 파일을 생성하여 디버깅을 용이하게 합니다.
- **baseUrl:** 모듈 해결 시 기본 경로를 설정합니다.
- **paths:** 모듈 별칭을 설정합니다.

### ts-node
`ts-node`는 TypeScript 파일을 직접 실행할 수 있게 해주는 Node.js용 실행 환경입니다. TypeScript를 JavaScript로 컴파일하여 실행하는 대신, `ts-node`를 사용하면 TypeScript 코드를 바로 실행할 수 있습니다.

1. **TypeScript 코드 실행**: `ts-node`를 사용하면 TypeScript 코드를 JavaScript로 변환하지 않고, 바로 실행할 수 있습니다. 개발 중에 빠르게 테스트하고 실행하는 데 유용합니다.
2. **자동 컴파일**: `ts-node`는 TypeScript 파일을 실행할 때 내부적으로 TypeScript 컴파일러를 사용하여 자동으로 컴파일합니다. 즉, 별도로 `tsc` 명령어로 컴파일할 필요 없이, TypeScript 코드를 바로 실행할 수 있습니다.
3. **디버깅 지원**: TypeScript의 디버깅 정보를 제공하며, Node.js와 함께 디버깅 기능을 사용할 수 있습니다.
    
사용하려면 `typescript` 패키지가 먼저 설치되어 있어야 합니다.

설치:
```
npm install ts-node --save-dev
```

#### 실행
설치 후, `ts-node`를 사용하여 `.ts` 파일을 실행할 수 있습니다.
```
npx ts-node <파일명>.ts
```

#### 스크립트
`package.json`의 `scripts` 항목에 `ts-node`를 추가하여 더 쉽게 실행할 수 있습니다.

```
{
	"scripts": {
		"start": "ts-node index.ts"
	}
}
```

### tsx
> https://www.npmjs.com/package/tsx<br>

`tsx`는 TypeScript 파일을 Node.js에서 직접 실행할 수 있도록 해주는 도구입니다. 이를 통해 TypeScript 코드를 컴파일 없이 바로 실행할 수 있으며, CommonJS와 ESM 모듈을 모두 지원합니다. 이 패키지를 사용하면 TypeScript를 실시간으로 실행할 수 있어 편리합니다.

설치:
```
npm install tsx
```

실행:
```
npx tsx <파일명>.ts
```

#### `watch` 모드
`watch` 모드는 종속성이 변경될 때마다 스크립트를 자동으로 다시 실행합니다. (nodemon과 같은 동작)

```
npx tsx watch <파일명>.ts
```
{% endraw %}