---
categories:
- ReactNative
date: '2025-02-04'
title: '[ReactNative] Zustand'
---

{% raw %}
Zustand는 Redux보다 간단하고 가벼운 상태 관리 라이브러리로, **보일러플레이트 코드**를 최소화하고 **간단한 API**로 상태를 관리할 수 있도록 도와줍니다. **React Context**를 사용하여 상태를 관리하고, **컴포넌트 간 상태 공유**가 가능합니다.

- **간단함**: 설정이 간단하고, 상태 관리가 직관적입니다.
- **빠른 리렌더링**: 상태 변경 시, 리렌더링을 최소화할 수 있습니다.
- **성능**: 상태를 변경할 때 최소한의 리렌더링을 수행하여 성능이 뛰어납니다.
- **상대적으로 적은 기능**: Redux와 비교하면 디버깅 도구나 고급 기능이 부족할 수 있습니다.
- **유연성 부족**: 복잡한 상태 관리나 여러 액션을 처리하는 데 있어 Redux만큼 유연하지 않을 수 있습니다.

설치:
```
npm install zustand
```

Zustand는 상태를 **store**에 저장하고, **setter**와 **getter**로 상태를 변경하고 읽습니다.

#### 설정
- **create**: Zustand의 `create` 함수는 상태를 설정하고 반환하는 훅을 만듭니다.
- **set**: `set`을 사용하여 상태를 변경합니다.
- **get**: `get`을 사용하여 현재 상태를 가져올 수 있습니다.

```
// useStore.js
import create from 'zustand';

const useStore = create((set, get) => ({<br>
  count: 0,
  increment: () => set((state) => ({ count: state.count + 1 })),<br>
  decrement: () => set((state) => ({ count: state.count - 1 })),<br>
}));

export default useStore;
```

#### 사용
- **useStore**: 상태를 읽고 변경할 수 있는 커스텀 훅입니다. 각 컴포넌트는 이 훅을 사용하여 상태를 공유합니다.

구독을 설정하는 방법은 `useStore` 훅을 사용하여 상태를 가져오는 것만으로 완료됩니다. `Zustand`는 내부적으로 구독 기능을 제공하므로, 별도의 구독 설정을 직접 할 필요는 없습니다.

```
// Counter.js
import React from 'react';
import useStore from './useStore';

const Counter = () => {<br>
  const { count, increment, decrement } = useStore();

  return (
    <div>
      <h1>Count: {count}</h1>
      <button onClick={increment}>Increment</button>
      <button onClick={decrement}>Decrement</button>
    </div>
  );
};

export default Counter;
```

#### getState
`getState`는 Zustand의 **상태를 직접 가져오는 함수**입니다. 주로 **컴포넌트 외부에서 상태를 접근하거나 업데이트할 때 사용**됩니다.

```javascript
// Zustand store 정의
import create from 'zustand';

const useStore = create((set) => ({<br>
  count: 0,
  increment: () => set((state) => ({ count: state.count + 1 })),<br>
}));

// 컴포넌트 외부에서 상태와 업데이트 함수 사용하기
const state = useStore.getState(); // 상태를 가져옴
console.log(state.count);  // 현재 상태 출력

// 상태 업데이트하기
state.increment();  // 상태를 변경하는 액션 호출
```

#### state
Zustand의 `set` 함수는 **이전 상태(`state`)를 매개변수로 받아** 부분적으로 업데이트할 수 있습니다.

```
import create from 'zustand';

const useStore = create((set) => ({<br>
  count: 0,
  name: 'React',
  increment: () => set((state) => ({ count: state.count + 1 })),<br>
  setName: (newName) => set((state) => ({ name: newName })),<br>
}));
```
{% endraw %}