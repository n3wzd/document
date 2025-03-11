---
categories:
- Design
date: '2025-01-25'
title: '[Design] React Native'
---

{% raw %}
### 파일 구조
```
src/
 ├── api/         # 서버 API 요청
 ├── components/  # 재사용 가능한 UI 컴포넌트
 ├── config/      # 상수 및 설정값
 ├── screens/     # 페이지 단위 컴포넌트
 ├── hooks/       # 커스텀 훅
 ├── external/    # 외부 API 요청
 ├── services/    # 비즈니스 로직
 ├── store/       # 상태 관리
 ├── styles/      # 공통 스타일링 관리
 ├── types/       # 타입 정의
 ├── utils/       # 정적 유틸리티 함수
 ├── libs/        # 외부 라이브러리 래퍼
 ├── assets/      # 이미지, 폰트 등 리소스 파일
```

### 패키지 정보
> https://www.npmjs.com/package<br>

### 아이콘 검색
> https://icons.expo.fyi/Index<br>

### 전역 상태 관리
Context API는 상위 컴포넌트에서 하위 컴포넌트로만 데이터를 전달할 수 있습니다. 즉, 상위-하위 관계 명확한 트리 구조에서 유용하게 사용됩니다. 보통 중간 컴포넌트가 전달된 파라미터를 사용하지 않거나, 여러 하위 컴포넌트에서 동일한 데이터를 참조해야 할 때 주로 사용됩니다.

하지만 페이지 간 이동이 있는 경우, 특히 상위-하위 관계가 없는 페이지들 간에 데이터를 전달해야 하는 경우, Context API만으로는 한계가 있을 수 있습니다. 이럴 때는 상태 관리 라이브러리(예: Redux, Zustand)를 활용해야 합니다.

### React 상태 리렌더링 범위
React에서는 상태가 변경되면, 변경된 컴포넌트와 그 상위 컴포넌트만 리렌더링됩니다. 단, 그 상위 컴포넌트 내부의 모든 자식 컴포넌트도 함께 리렌더링될 수 있습니다.
{% endraw %}