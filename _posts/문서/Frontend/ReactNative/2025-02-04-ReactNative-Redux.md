---
categories:
- ReactNative
date: '2025-02-04'
title: '[ReactNative] Redux'
---

{% raw %}
Redux는 **상태를 전역으로 관리**하는 상태 관리 라이브러리입니다. 애플리케이션의 상태는 **액션**을 통해 변경되며, 이를 처리하는 **리듀서**가 상태를 반환합니다.

- **예측 가능성**: 상태 변경이 명확하게 추적됩니다.
- **디버깅**: Redux DevTools를 사용하여 상태의 변화를 추적할 수 있습니다.
- **확장성**: 복잡한 애플리케이션에서 유리합니다.
- **보일러플레이트 코드**가 많습니다. 많은 설정과 코드가 필요합니다.

구조:
- **State**: 애플리케이션의 전역 상태를 저장합니다.
- **Action**: 상태를 변경할 때 사용하는 객체입니다. 상태 변경을 설명하는 정보입니다.
- **Reducer**: 액션을 받아서 새로운 상태를 반환하는 순수 함수입니다.
- **Store**: 상태를 저장하고, 액션을 리듀서에 전달하여 상태를 변경하는 객체입니다.
- **Dispatch**: 액션을 store에 전달하는 방법입니다.

설치:
```
npm install redux react-redux
```

#### Action 
`increment()`는 액션을 반환하는 함수입니다. 이 액션은 상태를 변경하는 타입 정보를 포함합니다.

```
// actions.js
export const increment = () => ({<br>
  type: 'INCREMENT'
});
```

#### Reducer 
`counterReducer`는 액션을 처리하여 새로운 상태를 반환하는 함수입니다. 액션 타입에 따라 상태를 변경합니다.

```
// reducer.js
const initialState = {
  count: 0
};

const counterReducer = (state = initialState, action) => {<br>
  switch (action.type) {
    case 'INCREMENT':
      return { ...state, count: state.count + 1 };
    default:
      return state;
  }
};

export default counterReducer;
```

#### Store
`createStore`로 상태를 보관합니다.

```
// store.js
import { createStore } from 'redux';
import counterReducer from './reducer';

const store = createStore(counterReducer);
export default store;
```

#### Provider
`Provider`를 사용하여 전역 상태를 자식 컴포넌트에 전달합니다.

```
// App.js
import React from 'react';
import { Provider } from 'react-redux';
import store from './store';
import Counter from './Counter';

const App = () => (<br>
  <Provider store={store}>
    <Counter />
  </Provider>
);

export default App;
```

#### 상태 사용
- **useSelector**: 전역 상태를 가져옵니다.
- **useDispatch**: 액션을 dispatch하여 상태를 변경합니다.

```
// Counter.js
import React from 'react';
import { useDispatch, useSelector } from 'react-redux';
import { increment } from './actions';

const Counter = () => {<br>
  const count = useSelector((state) => state.count);<br>
  const dispatch = useDispatch();

  return (
    <div>
      <h1>Count: {count}</h1>
      <button onClick={() => dispatch(increment())}>Increment</button><br>
    </div>
  );
};

export default Counter;
```
{% endraw %}