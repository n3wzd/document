# React
React는 페이스북에서 개발한 JavaScript 라이브러리로, 사용자 인터페이스를 만들기 위한 목적으로 설계되었습니다. React는 선언적이고 효율적인 방식으로 사용자 인터페이스를 구축할 수 있게 도와주며, 컴포넌트라는 개념을 중심으로 한 아키텍처를 사용합니다.

다음은 React의 주요 특징과 개념입니다:

1. **컴포넌트 (Components):** React는 재사용 가능한 작은 조각들인 컴포넌트를 기반으로 합니다. 각 컴포넌트는 자체적인 상태(state)와 생명주기(lifecycle)를 가질 수 있습니다. 이러한 컴포넌트들을 조합하여 복잡한 사용자 인터페이스를 구축할 수 있습니다.
2. **가상 DOM (Virtual DOM):** React는 가상 DOM을 사용하여 성능을 최적화합니다. 변경된 부분만 실제 DOM에 반영하는 대신, 가상 DOM을 활용하여 효율적으로 UI 업데이트를 수행합니다.
3. **JSX (JavaScript XML):** React는 JSX라는 문법을 사용하여 JavaScript 코드 안에서 XML 형식의 마크업을 작성할 수 있게 합니다. JSX는 가독성을 높이고 컴포넌트의 구조를 더 직관적으로 만듭니다.
4. **ES6 (ECMAScript 2015):** ECMAScript는JavaScript의 표준을 정의하기 위해 생성되었으며, ES6은 2015년에 생성된 ECMAScript의 6번째 버전입니다. React는 ES6을 사용합니다.
5. **단방향 데이터 바인딩:** React는 단방향 데이터 바인딩을 지원합니다. 데이터의 흐름은 항상 한 방향으로만 흐릅니다. 부모 컴포넌트에서 자식 컴포넌트로 데이터를 전달하고, 자식 컴포넌트는 부모 컴포넌트의 상태를 변경하지 않습니다.
6. **상태 관리 (State Management):** React에서는 컴포넌트의 상태를 통해 동적인 데이터를 다룹니다. 상태는 컴포넌트가 내부적으로 관리하며, 상태가 변경되면 자동으로 UI가 업데이트됩니다.
7. **라우팅 (React Router):** React Router를 사용하여 싱글 페이지 애플리케이션에서의 라우팅을 쉽게 구현할 수 있습니다. 이를 통해 사용자가 다른 경로로 이동할 때 페이지를 새로고침하지 않고도 적절한 컴포넌트를 렌더링할 수 있습니다.
8. **커뮤니티와 생태계:** React는 활발한 커뮤니티와 다양한 생태계를 가지고 있습니다. 수많은 개발자들이 React를 사용하며, 다양한 라이브러리와 도구들이 React 기반의 프로젝트를 지원하고 있습니다.

## 시작
아래 예시는 Create React App을 사용하여 React 앱을 생성하는 방법입니다. Create React App은 React 개발을 시작하기 위한 간편한 도구로, 빠르게 프로젝트를 설정하고 실행할 수 있습니다.

1. **Node.js 및 npm 설치:** React 앱을 생성하려면 먼저 Node.js와 npm을 설치해야 합니다.
2. **Create React App 설치:** 터미널에서 다음 명령어를 사용하여 Create React App을 전역으로 설치합니다.
> npm install -g create-react-app

3. **React 앱 생성:** 새로운 React 앱을 생성하려면 다음 명령어를 실행합니다. 아래 명령에서 `my-react-app`은 새로 생성되는 프로젝트의 폴더 이름으로, 원하는 다른 이름으로 대체할 수 있습니다.
> npx create-react-app my-react-app

4. **프로젝트 폴더로 이동:** 생성된 React 앱의 폴더로 이동합니다.
> cd my-react-app

5. **앱 실행:** 다음 명령어를 실행하여 React 앱을 개발 서버에서 실행합니다.
> npm start

브라우저에서 `http://localhost:3000`으로 접속하면 생성한 React 앱을 확인할 수 있습니다.

### 디렉터리 구조
React 앱을 생성할 때, Create React App과 같은 도구를 사용하면 초기 폴더 구조가 자동으로 생성됩니다.

#### public 폴더
- `index.html`: 앱의 진입점이 되는 HTML 파일. 여기에서 React 컴포넌트가 렌더링됩니다.
- 정적 자산 파일들(css, 이미지 등)이 위치합니다.

#### src 폴더
- `index.js`: React 앱의 시작점으로, ReactDOM.render를 사용하여 루트 컴포넌트를 DOM에 렌더링합니다.
- `App.js`: 주로 루트 컴포넌트가 위치하는 파일입니다.
- `index.css`: 프로젝트의 전역적인 스타일이 정의된 파일입니다.

## 동작
React의 동작 구조는 트리로 나타낼 수 있습니다.

### 렌더 트리 (Render Tree)
- 렌더 트리는 React 컴포넌트 간의 중첩된 관계를 나타냅니다.
- 렌더 트리의 상위 컴포넌트는 그 아래의 모든 컴포넌트에 렌더링 성능에 영향을 미칩니다. 또한 단말에 가까운 컴포넌트일수록 자주 렌더링될 확률이 높습니다. 이를 식별하는 것은 렌더링 성능을 이해하고 디버깅하는 데 유용합니다.
- 조건문에 의한 렌더링을 사용한다면, 렌더링 중에 렌더 트리가 변경될 수 있습니다. 예를 들어 어떤 컴포넌트의 속성 값이 변경된다면 다른 자식 컴포넌트가 렌더될 수 있습니다.

### 의존성 트리 (Dependency Tree)
- 의존성 트리는 React 앱의 모듈 의존성을 나타냅니다.
- 의존성 트리는 필요한 코드를 번들로 묶는 빌드 도구로 사용될 수 있습니다.
- 의존성 트리는 렌더링 시간이 느린 거대한 번들을 디버깅하는 데 유용합니다.

### key
React에서 key는 렌더 트리에서 각 컴포넌트를 식별하는 데 사용되는 특수한 속성입니다. key는 React에게 각 항목의 고유성을 알려주어 업데이트 및 재배열이 효율적으로 이루어지도록 도와줍니다.

### 렌더링 (Rendering)
React가 UI를 제공하는 과정은 세 단계로 이루어집니다:

1. Trigger: 렌더링을 시작하는 초기 단계
2. Render: 컴포넌트들을 재구성하는 단계
3. Commit: 변경사항을 DOM에 반영하는 단계

만약 렌더링 결과가 이전 것과 동일하다면 Commit 단계는 수행되지 않습니다.

## 컴포넌트 (Components)
React에서 컴포넌트는 UI를 작은 독립적인 조각으로 분리하여 구조화하는 핵심 개념입니다. 각각의 컴포넌트는 자체적인 상태와 라이프사이클을 가질 수 있으며, 이들을 결합하여 전체 애플리케이션을 구성합니다.

컴포넌트는 크게 2가지 종류가 있습니다:

- **함수 컴포넌트:** 주로 state나 lifecycle 메서드 없이 단순한 UI를 표현하는데 사용됩니다.
- **클래스 컴포넌트:** 상태나 라이프사이클 메서드를 필요로 하는 복잡한 로직이 필요한 경우에 사용됩니다.

React 16.8 이전에는 클래스 컴포넌트가 리액트 컴포넌트의 상태 및 라이프사이클을 추적하는 유일한 방법이었습니다. 함수 컴포넌트는 "상태 없음"으로 간주되었습니다. 그러나 Hooks가 추가되면서 함수 컴포넌트는 이제 거의 클래스 컴포넌트와 동등해졌습니다.

클래스 컴포넌트는 여전히 많은 프로젝트에서 사용되고 있지만, 함수 컴포넌트와 Hooks가 간결하면서도 강력한 기능을 제공하므로, 새로운 프로젝트에서는 주로 함수 컴포넌트를 사용하는 추세입니다.

**주의사항**: React에서는 컴포넌트의 이름이 대문자로 시작해야 합니다. 예를 들어, 올바른 컴포넌트 이름은 `MyComponent`이지만, `myComponent`와 같이 소문자로 시작하면 안 됩니다.

### 클래스 컴포넌트 (Class Components)
클래스 컴포넌트는 `React.Component`를 상속받습니다. 이를 통해 생명주기 메서드를 활용하여 컴포넌트의 라이프사이클 이벤트를 처리할 수 있습니다. 또한 클래스 컴포넌트는 내부적으로 상태를 가지며, `setState` 메서드를 사용하여 상태를 변경하고, 변경된 상태에 따라 UI를 업데이트합니다.

#### 클래스 정의
클래스 컴포넌트는 ES6의 클래스 문법을 사용하여 정의됩니다. 아래는 간단한 클래스 컴포넌트의 예제입니다

```
import React, { Component } from 'react';

class MyComponent extends Component {
  constructor(props) {
    super(props);
    this.state = {
      // 초기 상태 설정
    };
  }

  render() {
    return (
      <div>
        {/* JSX로 구성된 컴포넌트의 UI */}
      </div>
    );
  }
}
```

#### 생명주기 메서드
클래스 컴포넌트는 라이프사이클 메서드를 활용하여 컴포넌트의 생명주기 이벤트를 처리합니다. 몇 가지 주요 메서드는 다음과 같습니다:

- **`componentDidMount()`:** 컴포넌트가 마운트된 직후에 호출되는 메서드로, 초기 데이터 로딩이나 외부 리소스 요청 등에 활용됩니다.
- **`componentDidUpdate(prevProps, prevState)`:** 컴포넌트가 업데이트된 직후에 호출되는 메서드로, 이전 프롭스나 상태와 현재 프롭스나 상태를 비교하여 작업을 수행할 수 있습니다.
- **`componentWillUnmount()`:** 컴포넌트가 언마운트되기 전에 호출되는 메서드로, 리소스 해제나 정리 작업에 활용됩니다.

#### 상태 관리
Class Components에서는 `this.state`를 사용하여 컴포넌트의 상태를 관리합니다. `setState()` 메서드를 사용하여 상태를 변경할 수 있으며, 변경된 상태에 따라 컴포넌트가 다시 렌더링됩니다.

```
class Counter extends Component {
  constructor(props) {
    super(props);
    this.state = {
      count: 0,
    };
  }

  increment = () => {
    this.setState({ count: this.state.count + 1 });
  };

  render() {
    return (
      <div>
        <p>Count: {this.state.count}</p>
        <button onClick={this.increment}>Increment</button>
      </div>
    );
  }
}
```

### 함수 컴포넌트 (Functional Components)
함수 컴포넌트는 React에서 UI를 구성하기 위한 기본 요소 중 하나로, JavaScript 함수로 정의된 컴포넌트입니다.

#### 기본 구조
함수 컴포넌트는 함수를 사용하여 UI를 정의합니다. 아래는 간단한 함수 컴포넌트의 예제입니다:

```
import React from 'react';

const MyComponent = () => {
  return (
    <div>
      {/* JSX로 구성된 컴포넌트의 UI */}
    </div>
  );
};
```

#### Hooks
Hooks는 함수 컴포넌트에서 상태 및 라이프사이클 기능을 사용할 수 있게 해주는 기능입니다. 주요 Hooks에는 다음과 같은 것들이 있습니다:

- `useState`: 상태를 추가하고 관리하기 위한 Hook입니다.
- `useEffect`: 생명주기 메서드와 비슷한 역할로, 컴포넌트가 마운트, 업데이트, 언마운트될 때 특정 작업을 수행할 수 있게 합니다.
- `useContext`: 컴포넌트 간에 상태를 전달하기 위해 사용되는 Hook입니다.
- `useReducer`: 복잡한 상태 로직을 다룰 때 사용되는 Hook으로, Redux와 유사한 동작을 합니다.
- `custom Hooks`: 개발자가 자신만의 커스텀 Hook을 작성하여 로직을 재사용할 수 있게 합니다.

#### vs 클래스 컴포넌트
- **상태 관리:** 클래스 컴포넌트에서는 `this.state`를 사용했지만, 함수 컴포넌트에서는 `useState`를 사용하여 상태를 관리합니다.
- **라이프사이클:** 클래스 컴포넌트에서는 라이프사이클 메서드를 사용했으나, 함수 컴포넌트에서는 `useEffect`를 활용하여 비슷한 기능을 수행합니다.
- **가독성과 간결성:** 함수 컴포넌트가 가독성이 높고 간결하므로, 간단한 컴포넌트의 경우 더 선호됩니다.

### 컴포넌트 설계원칙
- 컴포넌트에 사용하는 입력을 변형해서는 안 됩니다. 이는 props, state, 그리고 context를 포함합니다. 화면을 업데이트하려면 기존 객체를 변형하는 대신 상태를 "설정"해야 합니다.
- 렌더링은 언제든 일어날 수 있으므로 컴포넌트는 서로의 렌더링 순서에 의존해서는 안 됩니다.
- 컴포넌트의 논리를 반환하는 JSX를 설계해야 합니다. 무언가를 변경해야 한다면 이벤트 핸들러나 useEffect를 사용할 수 있습니다.

## 속성 (Props)
Props는 React에서 컴포넌트 간에 데이터를 전달하는 메커니즘입니다. 부모 컴포넌트에서 자식 컴포넌트로 데이터를 전달하여 컴포넌트 간 통신이 가능하게 합니다. Props를 통해 컴포넌트는 외부에서 전달된 데이터를 읽기 전용으로 사용할 수 있습니다.

- **읽기 전용 (Read-Only):** Props는 컴포넌트에서 읽기 전용입니다. 자식 컴포넌트에서 부모로부터 전달받은 props를 직접 수정할 수 없습니다.
- **부모에서 자식으로 전달:** Props는 부모 컴포넌트에서 자식 컴포넌트로 데이터를 전달하는데 사용됩니다.
 - **값의 변경이 가능:** Props는 부모 컴포넌트에서 전달되므로, 부모의 상태가 변경되면 해당 변경 사항이 자식 컴포넌트의 props에 반영됩니다.

컴포넌트에서 props가 변경되면, 해당 컴포넌트의 렌더링이 트리거되어 새로운 props에 맞게 UI가 자동으로 업데이트됩니다. 

`componentDidUpdate` 메서드는 props의 변경을 감지하여 특정 작업을 수행할 수 있도록 지원하고 있습니다. 이 메서드는 props나 state가 변경되었을 때 호출되며, 변경된 props에 대한 추가적인 작업을 수행하는 데 사용될 수 있습니다.

### Props 전달
JSX에서 컴포넌트를 사용할 때, 속성을 추가하여 데이터를 전달합니다.

```
// 부모 컴포넌트
 import React from 'react';
 import ChildComponent from './ChildComponent';
 
 const ParentComponent = () => {
   return <ChildComponent message="Hello from parent!" />;
 };
```
 
### Props 수신
자식 컴포넌트에서는 함수의 매개변수로 `props`를 받아 사용합니다. (`props` 대신 다른 이름을 사용할 수 있습니다.)

```
// 자식 컴포넌트
import React from 'react';

const ChildComponent = (props) => {
  return <p>{props.message}</p>;
};

export default ChildComponent;
```

함수의 매개변수에서 분해대입을 사용하여 특정 속성만 추출할 수 있습니다.

```
// 자식 컴포넌트
import React from 'react';

const ChildComponent = ({ message }) => {
  return <p>{message}</p>;
};

export default ChildComponent;
```

### children
React에서 `children`은 컴포넌트의 속성 중 하나로, 해당 컴포넌트가 감싸고 있는 다른 React 엘리먼트나 컴포넌트를 나타냅니다. `children`을 이용하면 부모 컴포넌트에서 자식 컴포넌트에게 HTML 태그나 다른 React 컴포넌트를 포함한 내용을 전달할 수 있습니다.

```
// 부모 컴포넌트
import React from 'react';

const ParentComponent = () => {
  return (
    <div>
      <h1>부모 컴포넌트</h1>
      <ChildComponent>자식 컴포넌트의 내용</ChildComponent>
    </div>
  );
};

// 자식 컴포넌트
const ChildComponent = (props) => {
  return (
    <div>
      <h2>자식 컴포넌트</h2>
      <p>{props.children}</p>
    </div>
  );
};

export default ParentComponent;` 
```

출력은 다음과 같습니다:
```
<div>
  <h1>부모 컴포넌트</h1>
  <div>
    <h2>자식 컴포넌트</h2>
    <p>안녕하세요, 자식 컴포넌트의 내용입니다!</p>
  </div>
</div>
```

### Spread / Rest Syntax
React에서 props를 전달할 때 JavaScript의 spread / rest 연산자를 사용할 수 있습니다.

**spread 연산자**
```
function ParentComponent() {
  const person = {
    name: "John",
    age: 25,
    gender: "Male",
  };

  return (
    <ChildComponent {...person} />
  );
}
```
```
function ChildComponent({ name, age, gender }) {
  return (
    <div>
      <p>Name: {name}</p>
      <p>Age: {age}</p>
      <p>Gender: {gender}</p>
    </div>
  );
}
```

**rest 연산자**
```
<ChildComponent name="John" age={25} />
```

```
function ChildComponent({ ...props }) {
  return (
    <div>
      <p>Name: {props.name}</p>
      <p>Age: {props.age}</p>
    </div>
  );
}
```

## 이벤트 (Events)
React에서 이벤트 처리는 사용자 상호 작용에 대응하여 애플리케이션의 동작을 제어하는 중요한 부분입니다. React는 일반적인 DOM 이벤트 시스템과 유사하지만 몇 가지 차이가 있습니다. 이벤트는 주로 JSX 문법을 통해 다뤄지며, 일반적인 HTML의 이벤트 핸들링과 유사하게 사용됩니다.

### JSX에서의 이벤트 처리
#### 이벤트 핸들러 등록
JSX에서 이벤트 핸들러는 콜백 함수로 등록됩니다. 대부분의 이벤트 핸들러는 콜백 함수를 지정하는 방식으로 사용됩니다.

```
function handleClick() {
  console.log('Button clicked!');
}

const MyComponent = () => {
  return <button onClick={handleClick}>Click me</button>;
};
```

#### 이벤트 객체 사용
이벤트 핸들러 함수는 일반적으로 이벤트 객체를 받습니다. 이 객체를 사용하여 이벤트 정보에 접근할 수 있습니다.

```
function handleClick(event) {
  console.log('Button clicked!', event.target);
}

const MyComponent = () => {
  return <button onClick={handleClick}>Click me</button>;
};
```

#### 이벤트 종류
React에서 지원하는 일부 이벤트 종류는 다음과 같습니다: `onClick`, `onChange`, `onSubmit`, `onFocus`, `onBlur` 등이 있습니다.

```
const MyInput = () => {
  const handleChange = (event) => {
    console.log('Input changed:', event.target.value);
  };

  return <input type="text" onChange={handleChange} />;
};
```

### 클래스 컴포넌트에서의 이벤트 처리
```
import React, { Component } from 'react';

class MyComponent extends Component {
  handleClick = () => {
    console.log('Button clicked!');
  };

  render() {
    return <button onClick={this.handleClick}>Click me</button>;
  }
}
```

### 이벤트 전파
React에서는 이벤트가 자동으로 부모 컴포넌트로 전파되며, 부모에서 자식으로 전파되지 않습니다. 부모 컴포넌트로 전파되는 것을 중단하려면 `stopPropagation`을 사용합니다.

```
const ParentComponent = () => {
  const handleParentClick = () => {
    console.log('Parent clicked!');
  };

  return (
    <div onClick={handleParentClick}>
      <ChildComponent />
    </div>
  );
};

const ChildComponent = () => {
  const handleChildClick = (event) => {
    event.stopPropagation();
    console.log('Child clicked!');
  };

  return <button onClick={handleChildClick}>Click me</button>;
};
```

### 기본 동작 방지
`preventDefault`를 사용하여 이벤트의 기본 동작을 방지할 수 있습니다.

```
const MyLink = () => {
  const handleClick = (event) => {
    event.preventDefault();
    console.log('Link clicked!');
  };

  return <a href="https://example.com" onClick={handleClick}>Click me</a>;
};
```

## 조건문(Conditional)
조건문은 프로그램에서 특정 조건에 따라 다른 동작을 수행하도록 하는 제어 구조입니다. React에서 조건문은 주로 JSX 내에서 사용되며, 컴포넌트가 렌더링될 때 특정 조건에 따라 다른 내용을 표시할 수 있게 합니다.

### JSX에서의 조건문
JSX 내에서 JavaScript의 조건문을 사용하여 특정 조건에 따라 다른 UI를 렌더링할 수 있습니다.

```
const MyComponent = ({ isLoggedIn }) => {
  return (
    <div>
      {isLoggedIn ? (
        <p>Welcome, User!</p>
      ) : (
        <p>Please log in</p>
      )}
    </div>
  );
};
```

위의 예제에서는 `isLoggedIn`이 `true`이면 "Welcome, User!"를, 그렇지 않으면 "Please log in"을 렌더링합니다. 삼항 연산자(`? :`)를 사용하여 간단한 조건문을 작성할 수 있습니다.

### if-else 문 사용
삼항 연산자 이외에도 JavaScript의 `if-else`문을 사용하여 조건부 렌더링을 할 수 있습니다.

```
const MyComponent = ({ isLoggedIn }) => {
  if (isLoggedIn) {
    return <p>Welcome, User!</p>;
  } else {
    return <p>Please log in</p>;
  }
};
```

### 논리 연산자를 활용한 조건부 렌더링
논리 연산자를 활용하여 간단한 조건부 렌더링도 가능합니다.

```
const MyComponent = ({ isLoggedIn }) => {
  return isLoggedIn && <p>Welcome, User!</p>;
};
```

이 예제에서는 `isLoggedIn`이 `true`이면 오른쪽의 JSX가 반환되고, `false`이면 `false`가 반환되어 아무것도 렌더링되지 않습니다.

## 리스트 (Lists)
React에서 리스트는 동적인 데이터를 효과적으로 렌더링하는데 사용되는 중요한 개념입니다. 리스트는 배열이나 기타 반복 가능한(iterable) 객체를 매핑하여 여러 항목을 렌더링할 수 있도록 도와줍니다. React에서 리스트를 다루기 위한 주요 방법은 JSX 내에서 `map`, `filter` 등 함수를 사용하는 것입니다.

여러 항목을 렌더링할 경우, React에서 각 항목에 고유한 `key` 속성을 제공해야 합니다. 이는 React가 각 항목을 식별하는 데 사용됩니다.

### 배열 매핑 (Mapping Arrays)
가장 일반적인 방법으로 배열의 각 항목을 순회하면서 JSX로 변환하여 렌더링합니다.

```
const numbers = [1, 2, 3, 4, 5];

const NumberList = () => {
  return (
    <ul>
      {numbers.map((number) => (
        <li key={number}>{number}</li>
      ))}
    </ul>
  );
};
```

위의 예제에서 `map` 함수를 사용하여 `numbers` 배열의 각 요소를 `<li>` 태그로 변환하여 리스트를 생성합니다.

`map` 함수 내에서 조건부 렌더링을 사용하여 특정 조건에 따라 항목을 제외하거나 다른 형태로 렌더링할 수 있습니다.

```
const numbers = [1, 2, 3, 4, 5];

const EvenNumbersList = () => {
  return (
    <ul>
      {numbers.map((number) => (
        number % 2 === 0 && <li key={number}>{number}</li>
      ))}
    </ul>
  );
};
```

### 컴포넌트 리스트
리스트 내에서 또 다른 컴포넌트를 렌더링할 수 있습니다.

```
const data = [
  { id: 1, text: 'Item 1' },
  { id: 2, text: 'Item 2' },
  { id: 3, text: 'Item 3' },
];

const ItemList = () => {
  return (
    <ul>
      {data.map((item) => (
        <ListItem key={item.id} text={item.text} />
      ))}
    </ul>
  );
};

const ListItem = ({ text }) => {
  return <li>{text}</li>;
};
```

### React Fragment 사용
여러 요소를 반환할 때, `map` 함수 내에서는 반드시 하나의 부모 요소로 감싸야 합니다. React Fragment (`<>...</>`)를 사용하여 불필요한 부모 요소 없이 여러 요소를 그룹화할 수 있습니다.

```
const numbers = [1, 2, 3, 4, 5];

const NumberList = () => {
  return (
    <>
      {numbers.map((number) => (
        <span key={number}>{number}</span>
      ))}
    </>
  );
};
```

## 폼 (Forms)
React에서 폼은 사용자의 입력을 받고 처리하기 위한 중요한 요소입니다. React에서는 일반 HTML 폼과 비슷하지만, React의 컴포넌트 기능과 상태(State) 관리 기능을 통합하여 보다 동적이고 유연한 폼 처리를 제공합니다.

React를 사용하여 폼을 처리할 때는 주로 제어 컴포넌트를 사용하여 상태를 관리하고, 이를 통해 유연하고 동적인 폼을 만들 수 있습니다.

- **기본 Form 사용:** React에서 기본적인 폼을 사용할 때는 일반 HTML과 유사하게 `<form>` 태그와 여러 폼 요소들을 사용합니다.
- **제어 컴포넌트(Controlled Components):** React에서는 폼 요소를 제어 컴포넌트로 만들어 사용하는 것이 일반적입니다. 제어 컴포넌트는 React 상태(State)를 사용하여 폼 요소의 값을 관리합니다.
- **이벤트 핸들러:** 폼 요소에서 사용자 입력을 감지하려면 `onChange` 이벤트 핸들러를 사용합니다. 입력이 변경될 때마다 해당 이벤트가 발생하고, 이를 통해 상태를 업데이트할 수 있습니다.
- **폼 데이터 제출:** 폼이 제출될 때는 `onSubmit` 이벤트 핸들러를 사용하여 폼 데이터를 처리합니다. 주로 이벤트 객체의 `preventDefault` 메서드를 호출하여 페이지의 새로고침을 방지합니다.
- **비제어 컴포넌트(Uncontrolled Components):** React에서는 제어 컴포넌트 외에도 비제어 컴포넌트를 사용할 수도 있습니다. 비제어 컴포넌트는 React 상태(State)를 사용하지 않고, DOM에서 직접 값을 추출하는 방식입니다. 하지만 이 방식은 상태 관리가 더 어려우며, 주로 특별한 경우에 사용됩니다.

```
import React, { useState } from 'react';

const MyForm = () => {
  const [formData, setFormData] = useState({
    username: '',
    password: '',
  });

  const handleChange = (event) => {
    const { name, value } = event.target;
    setFormData({
      ...formData,
      [name]: value,
    });
  };

  const handleSubmit = (event) => {
    event.preventDefault();
    // 폼 데이터 처리 로직
    console.log(formData);
  };

  return (
    <form onSubmit={handleSubmit}>
      <label>
        Username:
        <input type="text" name="username" value={formData.username} onChange={handleChange} />
      </label>
      <br />
      <label>
        Password:
        <input type="password" name="password" value={formData.password} onChange={handleChange} />
      </label>
      <br />
      <button type="submit">Submit</button>
    </form>
  );
};
```

위의 예제에서 `useState`를 사용하여 `formData`라는 상태를 생성하고, 폼 요소의 값은 이 상태를 통해 제어됩니다.
  
## 라우터 (Router)
React에서 라우팅을 관리하기 위해 주로 사용되는 라이브러리 중 하나는 React Router입니다. React Router는 React 애플리케이션에서 다양한 페이지 간의 네비게이션을 처리하기 위한 효과적인 도구입니다. 이 라이브러리는 URL의 변화에 따라 다른 컴포넌트를 렌더링하고, 브라우저의 히스토리 API를 활용하여 페이지 전환을 관리합니다.

### `<BrowserRouter>`
React Router의 핵심 컴포넌트 중 하나로, HTML5의 History API를 사용하여 브라우저의 URL을 관리합니다. 전체 애플리케이션을 `<BrowserRouter>`로 감싸서 사용합니다.

```
import { BrowserRouter as Router } from 'react-router-dom';

ReactDOM.render(
  <Router>
    <App />
  </Router>,
  document.getElementById('root')
);
```

### `<Route>`
특정 경로에 대한 라우팅을 정의하는 컴포넌트입니다. 주어진 경로에 대한 일치 여부에 따라 특정 컴포넌트를 렌더링합니다.
    
```
import { Route } from 'react-router-dom';

const Home = () => <div>Home Page</div>;

<Route path="/" component={Home} />;
```
    
### `<Link>`, `<NavLink>`
`<Link>`는 애플리케이션 내에서 다른 경로로 이동하기 위한 컴포넌트입니다.

`<NavLink>`는 `<Link>`와 유사하지만 현재 경로와 일치할 때 스타일을 지정할 수 있는 기능이 추가됩니다.
 
```
import { Link, NavLink } from 'react-router-dom';

<Link to="/about">About</Link>;

<NavLink to="/about" activeClassName="active-link">About</NavLink>;
```

### `<Switch>`
`<Switch>`는 여러 `<Route>` 중에서 첫 번째로 일치하는 라우트만을 렌더링하도록 도와주는 컴포넌트입니다. `<Switch>`로 감싸면 가장 먼저 일치하는 `<Route>`만 렌더링되고 나머지는 무시됩니다.

```
import { Switch, Route } from 'react-router-dom';

<Switch>
  <Route path="/home" component={Home} />
  <Route path="/about" component={About} />
  <Route path="/contact" component={Contact} />
</Switch>
```
  
###  `useHistory`, `useLocation`, `useParams`
함수 컴포넌트에서 라우터의 히스토리, 현재 위치, URL 파라미터 등에 접근하기 위해 사용되는 Hook들입니다.
    
```
import { useHistory, useLocation, useParams } from 'react-router-dom';

const MyComponent = () => {
  const history = useHistory();
  const location = useLocation();
  const params = useParams();

  // ...
};
```

## 스타일링 (Styling)
React에서 스타일링을 하는 방법은 여러 가지가 있습니다.

### Inline Styles
React에서는 JSX 요소에 직접 스타일 객체를 넣어 스타일을 지정할 수 있습니다. 이 방법은 간단하게 스타일을 적용할 수 있지만, 동적인 스타일링에는 다소 제한적일 수 있습니다.

```
const MyComponent = () => {
  const styles = {
    color: 'blue',
    fontSize: '16px',
    fontWeight: 'bold',
  };

  return <div style={styles}>Styled Text</div>;
};
```

### CSS Modules
CSS Modules은 CSS 파일을 모듈처럼 사용할 수 있게 해주는 기술입니다. 각각의 스타일이 컴포넌트와 연결되어, 스타일 이름 충돌을 방지합니다.

```
/* styles.module.css */
.myComponent {
  color: blue;
  font-size: 16px;
  font-weight: bold;
}
```

```
import React from 'react';
import styles from './styles.module.css';

const MyComponent = () => {
  return <div className={styles.myComponent}>Styled Text</div>;
};
```

### Styled Components
Styled Components는 JavaScript 파일 안에서 CSS를 작성할 수 있도록 해주는 라이브러리입니다. 컴포넌트를 만들면서 동시에 스타일을 정의할 수 있습니다. (컴포넌트 기반의 스타일링)

```
import styled from 'styled-components';

const StyledDiv = styled.div`
  color: blue;
  font-size: 16px;
  font-weight: bold;
`;

const MyComponent = () => {
  return <StyledDiv>Styled Text</StyledDiv>;
};
```

### Sass
Sass는 CSS의 확장된 문법을 제공하며, 변수, 중첩 규칙, import 등의 특징을 활용하여 코드를 보다 모듈화하고 가독성을 높일 수 있습니다.

```
$primary-color: blue;

.myComponent {
  color: $primary-color;
  font-size: 16px;

  &:hover {
    text-decoration: underline;
  }
}
```

```
import React from 'react';
import './styles.scss'; // Sass 파일 import

const MyComponent = () => {
  return <div className="myComponent">Styled Text</div>;
};
```

## Hooks
Hooks는 React v16.8에서 소개된 기능으로, 함수 컴포넌트에서 상태(state) 및 React의 다양한 기능들을 사용할 수 있도록 해주는 API입니다. Hooks를 사용하면 함수 컴포넌트에서도 클래스형 컴포넌트와 동일한 기능을 사용할 수 있어서 코드의 재사용성과 가독성을 높일 수 있습니다.

컴포넌트 내의 모든 Hooks은 어느 상황이든 컴포넌트의 최상단에서 호출되어야 합니다. (예: 조건문 등으로 인해 일부 상황에서만 Hooks이 호출되면 안됩니다.)

### useState
상태(state)는 컴포넌트가 리렌더링되도 변경되지 않는 정보이며, 리렌더링 간에 정보를 유지해야 할 때 사용됩니다. 상태 변수의 특징은 다음과 같습니다:

- 각 컴포넌트마다 고유합니다.
- 리렌더링이 발생하기 이전에는 변경되지 않습니다.
- 실제 저장되는 위치는 컴포넌트 외부입니다.
- 렌더 트리에서 동일한 컴포넌트가 동일한 위치에서 렌더링되면 해당 컴포넌트의 상태는 변경되지 않습니다.

`useState`는 React에서 함수 컴포넌트에서 상태를 관리하기 위한 Hook입니다. 이를 사용하여 컴포넌트의 상태를 추가하고, 상태가 변경될 때마다 컴포넌트를 리렌더링할 수 있습니다.

`useState`의 반환값은 배열이며, 첫 번째 요소는 현재 상태 값, 두 번째 요소는 상태를 갱신할 함수입니다. 상태 갱신 함수는 새로운 상태 값을 인자로 하며, 호출되면 현재 상태 값이 변경되고 컴포넌트가 리렌더링됩니다.

```
import React, { useState } from 'react';

const MyComponent = () => {
  const [count, setCount] = useState(0);

  return (
    <div>
      <p>Count: {count}</p>
      <button onClick={() => setCount(count + 1)}>Increment</button>
    </div>
  );
};
```

`useState` 함수는 하나의 인자를 받고, 이 인자는 초기 상태값입니다. (위의 예제에서는 `0`이 초기 상태값으로 설정되었습니다.) `setCount`가 호출되면 `count`는 새로운 값을 가지며 컴포넌트가 리렌더링됩니다.

`useState`는 함수를 인자로 받을 수도 있습니다. 이렇게 사용하면 초기 상태값을 계산하는 데 함수를 사용할 수 있습니다. 이 함수는 컴포넌트가 처음 렌더링될 때만 실행되고, 이후 렌더링에서는 실행되지 않습니다.
```
const [count, setCount] = useState(() => {
  // 초기 상태값을 계산하는 함수
  return someExpensiveComputation();
});
```

#### 함수형 업데이트
상태 갱신 함수는 함수를 인자로 할 수 있습니다. 상태 갱신 함수가 제공한 함수들은 큐에 등록되며 렌더링될 때 순차적으로 실행되면서 상태를 업데이트합니다.

```
const [count, setCount] = useState(0);

// 값 업데이트 사용
const handleIncrement = () => {
  setCount(count + 1);
  setCount(count + 1);
};

// 함수형 업데이트 사용
const handleIncrementFunctional = () => {
  setCount((prevCount) => prevCount + 1);
  setCount((prevCount) => prevCount + 1);
};
```

위의 예제에서 두 업데이트 함수는 모두 렌더링을 2번 실행하지만 출력 결과는 다릅니다.

|count|값|함수형|
|---|---|---|
|초기|0|0|
|1번째 렌더링 이후|1|1|
|2번째 렌더링 이후|1|2|

#### 상태 객체
객체를 상태 변수로 활용할 수 있습니다. 이때는 다음 사항을 유의해야 합니다:
- 상태 변수는 렌더링 이전에 불변해야 하므로 상태 객체의 속성을 변경하는 연산은 리렌더링을 트리거하지 않습니다.
- 리렌더링을 하려면 상태 갱신 함수를 실행해야 하며, 상태 갱신 함수의 인자로 새로운 객체를 제공해야 합니다. 이때 객체를 복사하는 작업을 고려할 수 있습니다.

```
const [shape, setShape] = useState({
  color: 'orange',
  position: initialPosition
});

// 리렌더링이 트리거되지 않음
function handleMove1(dx, dy) {
  shape.position.x += dx;
  shape.position.y += dy;
}

// 리렌더링이 트리거됨
function handleMove2(dx, dy) {
  setShape({
    ...shape,
    position: {
      x: shape.position.x + dx,
      y: shape.position.y + dy,
    }
  });
}
```

#### 상태 설계 원칙
- 연관이 높은 상태 변수는 하나로 묶는 것이 좋습니다.
- 상태 변수는 적을수록 좋습니다. 불필요하고 중복된 상태는 가급적 피하는 것이 좋습니다.
- props는 가급적 상태로 사용하지 않는 것이 좋습니다.
- 리렌더링되면 지역 객체는 새로운 주소값을 가지므로, 상태 객체와 비교 연산시 객체 자체 보다는 ID나 인덱스 등 객체의 속성을 활용해야 합니다.
- 컴포넌트를 "Controlled"(props에 의한 제어) 또는 "Uncontrolled"(상태에 의한 제어)으로 분리하여 설계하면 편리합니다.

#### 공통 상태
하나의 상태로 복수의 컴포넌트를 제어해야 하는 경우가 있습니다. 이때는 다음 전략을 따릅니다:

1. 공유할 상태를 컴포넌트의 공통 부모로 배치합니다.
2. 공통 부모에서 정보와 이벤트 핸들러를 props를 통해 하위 컴포넌트로 전달합니다.
3. 하위 컴포넌트에서는 전달받은 이벤트를 사용하여 공통 부모의 상태를 갱신할 수 있습니다.

```
import { useState } from 'react';

// 공통 부모 컴포넌트
export default function SyncedInputs() {
  const [text, setText] = useState('');

  function handleChange(e) {
    setText(e.target.value);
  }

  return (
    <>
      <Input
        label="First input"
        value={text}
        onChange={handleChange}
      />
      <Input
        label="Second input"
        value={text}
        onChange={handleChange}
      />
    </>
  );
}

// 하위 컴포넌트
function Input({ label, value, onChange }) {
  return (
    <label>
      {label}
      {' '}
      <input
        value={value}
        onChange={onChange}
      />
    </label>
  );
}
```

### useReducer
`useReducer`는 React에서 상태 관리를 위한 Hook 중 하나로, 상태 업데이트 로직을 컴포넌트와 분리하여 관리할 때 사용됩니다. `useState`보다 코드가 복잡하지만, 여러 상태 값이나 복잡한 상태 로직을 관리할 때 편리합니다.

reducer 함수에서는 상태 업데이트 로직만 관리하는 것이 바람직합니다. (예: reducer 함수에서 `alert`을 사용하지 않아야 합니다.)

```
import React, { useReducer } from 'react';

// reducer 함수: 현재 상태와 액션을 받아 새로운 상태를 반환
const reducer = (state, action) => {
  switch (action.type) {
    case 'INCREMENT':
      return { count: state.count + 1 };
    case 'DECREMENT':
      return { count: state.count - 1 };
    default:
      return state;
  }
};

const Counter = () => {
  // useReducer를 사용하여 상태와 디스패치 함수를 생성
  const [state, dispatch] = useReducer(reducer, { count: 0 });

  // 생성된 디스패치 함수를 사용하여 액션을 디스패치하고 상태를 업데이트할 수 있습니다.
  return (
    <div>
      <p>Count: {state.count}</p>
      <button onClick={() => dispatch({ type: 'INCREMENT' })}>Increment</button>
      <button onClick={() => dispatch({ type: 'DECREMENT' })}>Decrement</button>
    </div>
  );
};
```

### useContext
`useContext`는 React에서 컨텍스트(Context)를 활용할 때 사용하는 Hook 중 하나입니다. 컨텍스트는 React 컴포넌트 트리 안에서 전역적으로 데이터를 공유할 수 있도록 하는 메커니즘을 제공합니다. `useContext`를 사용하면 컨텍스트의 값을 간편하게 읽어올 수 있습니다.

1. 컨텍스트를 생성합니다. `React.createContext`를 사용하여 컨텍스트를 만들고, 초기 값으로 제공할 값을 전달합니다.

```
// MyContext.js
import { createContext } from 'react';

const MyContext = createContext();
export default MyContext;
```

2. 컨텍스트를 사용할 컴포넌트의 최상단에서 `MyContext.Provider`로 값을 제공합니다.

```
// App.js
import React from 'react';
import MyContext from './MyContext';

const App = () => {
  const contextValue = 'Hello from Context';

  return (
    <MyContext.Provider value={contextValue}>
      <MyComponent />
    </MyContext.Provider>
  );
};
```

3. `useContext` Hook을 사용하여 컨텍스트의 값을 읽어옵니다.

```
// MyComponent.js
import React, { useContext } from 'react';
import MyContext from './MyContext';

const MyComponent = () => {
  const contextValue = useContext(MyContext);

  return <p>{contextValue}</p>;
};
```

이제 `MyComponent`에서 `MyContext`의 값을 읽어와 사용할 수 있습니다.

Reducer를 컨텍스트와 결합하면 모든 컴포넌트 요소에서 해당 상태를 읽거나 업데이트할 수 있습니다.

### useRef
#### ref
- `useRef`은 React에게 `ref`를 제공합니다.
- `ref`는 `current`라는 단일 속성을 가진 JavaScript 객체로, 읽거나 설정할 수 있습니다. 주로 렌더링에 사용되지 않는 값을 보존할 때 사용됩니다.
- 상태와 마찬가지로 `ref`를 사용하면 컴포넌트의 리렌더링 간에 정보를 보존할 수 있습니다.
- 상태와 달리 `ref`의 `current`값을 변경해도 렌더링을 트리거하지 않습니다.
- 렌더링 중에는 `ref.current`를 접근하지 않는 것이 좋습니다.

```
import { useState, useRef } from 'react';

export default function Chat() {
  const [text, setText] = useState('');
  const [isSending, setIsSending] = useState(false);

  // 리렌더링 이후에도 정보를 유지하기 위해 ref를 사용합니다.
  const timeoutRef = useRef(null);

  // 타이머를 설정하고 리렌더링합니다.
  function handleSend() {
    setIsSending(true);
    timeoutRef.current = setTimeout(() => {
      alert('Sent!');
      setIsSending(false);
    }, 3000);
  }

  // 설정된 타이머를 해제하고 리렌더링합니다.
  function handleUndo() {
    setIsSending(false);
    clearTimeout(timeoutRef.current);
  }

  return (
    <>
      <input
        disabled={isSending}
        value={text}
        onChange={e => setText(e.target.value)}
      />
      <button
        disabled={isSending}
        onClick={handleSend}>
        {isSending ? 'Sending...' : 'Send'}
      </button>
      {isSending &&
        <button onClick={handleUndo}>
          Undo
        </button>
      }
    </>
  );
}
```

#### DOM
- 컴포넌트는 기본적으로 DOM 노드를 노출하지 않습니다. DOM 노드에 직접 접근하기 위해 `ref`를 사용할 수 있습니다.
- `<div ref={myRef}>`와 같이 전달하여 DOM 노드를 `myRef.current`에 등록합니다. 이후 `myRef.current`을 사용해서 DOM 노드에 접근할 수 있습니다.
- ref를 통해 관리되는 DOM 노드를 변경하는 것은 가급적 피해야 합니다. 만약 등록된 DOM 노드를 수정해야 한다면, React가 업데이트하지 않는 부분만 수정해야 합니다.

```
import React, { useRef, useEffect } from 'react';

const MyComponent = () => {
  const myRef = useRef(null);

  useEffect(() => {
    // ref의 current 프로퍼티를 사용하여 등록한 DOM 노드에 직접 접근
    if (myRef.current) {
      myRef.current.focus();
    }
  }, []);

  // DOM 노드를 ref의 current 프로퍼티에 등록
  return <input ref={myRef} />;
};
```

### useEffect
`useEffect`는 컴포넌트가 렌더링될 때마다 특정 작업을 수행하도록 설정하는 효과(effect)를 제공하는 Hook입니다. 클래스형 컴포넌트의 라이프사이클 메서드와 유사한 역할을 합니다.

1. **부수 효과 함수:**  `useEffect`의 첫 번째 매개변수로 전달되는 함수는 부수 효과를 정의하는 함수입니다.
2. **의존성 배열:** `useEffect`의 두 번째 매개변수는 의존성 배열(dependency array)로, 부수 효과 함수에서 사용된 변수들을 포함해야 합니다. 배열에 있는 변수들이 변경될 때마다 부수 효과 함수가 실행됩니다. 의존성 배열은 비어있을 수 있으며, 이때는 컴포넌트가 처음 마운트될 때만 부수 효과 함수가 실행됩니다. 배열을 전달하지 않을 경우, 컴포넌트가 처음 마운트될 때와 컴포넌트가 렌더링될 때마다 부수 효과 함수가 실행됩니다.
3. **정리 함수:** 부수 효과 함수는 정리(clean-up) 함수를 반환할 수 있으며, 이는 컴포넌트가 언마운트되거나 의존성이 변경될 때 실행됩니다. 주로 구독 해제, 타이머 해제 등의 정리 작업에 사용됩니다.

```
import React, { useEffect, useState } from 'react';

const MyComponent = ({slowMode}) => {
  const [count, setCount] = useState(0);

  // useEffect의 1번째 인자에는 부수 효과를 수행할 함수가 들어갑니다.
  // 2번째 인자에는 의존성 배열이 들어갑니다.
  useEffect(() => {
    // 부수 효과 수행
    function onTick() {
      setCount(c => c + 1);
    }
    const intervalId = setInterval(onTick, slowMode ? 1500 : 1000);

    // 정리 함수를 반환할 수 있음
    return () => clearInterval(intervalId);
  }, [slowMode]);

  return <h1>{count}</h1>;
};
```

`useEffect`를 사용하기 전 유의사항: 
- React의 Strict Mode는 의도적으로 컴포넌트를 2번 마운트하여 버그를 찾습니다. 2번 마운트되므로 한번 렌더링이 발생할 때마다 부수 효과 함수는 2번 호출됩니다. 일반적으로 이 문제에 대한 해결책은 정리 함수를 구현하는 것으로, 부수 효과 함수가 수행하던 작업을 중지하거나 취소해야 합니다.
- Effect는 컴포넌트와 별도의 라이프사이클을 갖습니다. 따라서 Effect를 작성한다면 컴포넌트가 아닌 Effect의 관점(동기화 시작 및 중지 방식)에서 생각해야 합니다.

#### 의존성 제거
- 의존성 배열에서 불필요한 의존성은 최대한 제거하는 것이 좋습니다.
- Effect 외부 부분은 의존성의 영향을 받지 않습니다. 만약 외부 변수가 필요하지만 부수 효과 함수를 트리거하지 않으려면, 외부 함수를 호출하는 방법을 사용할 수 있습니다.
- 불필요한 의존성을 제거해야 한다면, 코드를 수정하는 방향으로 하는 것이 좋습니다. (부수 효과 함수에서 사용되는 API가 제거할 의존성을 요구하지 않도록 합니다.)

```
// 의존성 제거 이전
const ref = useRef(null);

useEffect(() => {
  const animation = new FadeInAnimation(ref.current);
  animation.start(duration);
  return () => {
    animation.stop();
  };
}, [duration]);
```

```
// 의존성 제거 이후
const ref = useRef(null);

const onAppear = useEffectEvent(animation => {
  animation.start(duration);
});

useEffect(() => {
  const animation = new FadeInAnimation(ref.current);
  onAppear(animation);
  return () => {
    animation.stop();
  };
}, []);
```

### useCallback
`useCallback`은 함수를 메모이제이션하고, 불필요한 렌더링을 방지합니다. 특히, 자식 컴포넌트에게 콜백 함수를 전달할 때 사용하면 성능 최적화에 도움이 됩니다.

```
import React, { useState, useCallback } from 'react';

const MyComponent = () => {
  const [count, setCount] = useState(0);

  // useCallback을 사용하여 함수를 메모이제이션
  const handleClick = useCallback(() => {
    setCount(count + 1);
  }, [count]); // 의존성 배열에 count를 포함

  return (
    <div>
      <p>Count: {count}</p>
      <button onClick={handleClick}>Increment</button>
    </div>
  );
};
```

### useMemo
`useMemo`은 값을 메모이제이션하고, 불필요한 렌더링을 방지합니다. `useMemo`는 주로 렌더링마다 동일한 결과를 생성하는 경우나, 특정 종속성이 변경될 때에만 다시 계산해야 하는 경우에 유용합니다.

```
import React, { useState, useMemo } from 'react';

const MyComponent = () => {
  const [count, setCount] = useState(0);

  // useMemo를 사용하여 계산 비용이 높은 결과를 메모이제이션
  const expensiveResult = useMemo(() => {
    // count가 변경될 때에만 다시 계산
    return someExpensiveCalculation(count);
  }, [count]);

  return (
    <div>
      <p>Count: {count}</p>
      <p>Expensive Result: {expensiveResult}</p>
      <button onClick={() => setCount(count + 1)}>Increment</button>
    </div>
  );
};
```

`useCallback`과 `useMemo`은 메모이제이션을 수행한다는 점은 동일하지만, `useCallback`은 함수를, `useMemo`은 값을 메모이제이션한다는 점에서 차이가 있습니다.

### Custom Hook
커스텀 훅(Custom Hook)은 상태, 효과(effect), 그리고 기타 로직들을 추상화하여 만들 수 있는 훅입니다.

- 여러 컴포넌트에서 같은 로직을 사용하고 싶을 때 커스텀 훅을 만들면 해당 로직을 간편하게 재사용할 수 있습니다.
- 훅 관련 로직들을 커스텀 훅으로 분리하면서 코드를 정리할 수 있습니다.
- 커스텀 훅의 이름은 "use"로 시작하고 다음 문자는 대문자여야 합니다.
- 커스텀 훅은 특정 컴포넌트에 종속적이지 않습니다. (오직 로직만 공유합니다.)
- 모든 훅은 컴포넌트가 리렌더링될 때마다 다시 실행됩니다.

#### 커스텀 훅 생성
```
import { useState, useEffect } from 'react';

// 커스텀 훅 생성
const useCustomHook = (initialValue) => {
  // 상태 관리
  const [value, setValue] = useState(initialValue);

  // 부수 효과 로직
  useEffect(() => {
    // some side effect
    console.log('Custom Hook Effect:', value);
  }, [value]);

  // 사용자 정의 메서드
  const increment = () => {
    setValue(value + 1);
  };

  // 훅에서 반환하는 값
  return { value, increment };
};
```

#### 커스텀 훅 사용
```
import React from 'react';
import useCustomHook from './useCustomHook';

const MyComponent = () => {
  // 커스텀 훅 사용
  const { value, increment } = useCustomHook(0);

  return (
    <div>
      <p>Value: {value}</p>
      <button onClick={increment}>Increment</button>
    </div>
  );
};
```

## Memo
`React.memo`는 React에서 함수 컴포넌트의 리렌더링 성능을 최적화하기 위해 사용되는 고차 컴포넌트(Higher Order Component)입니다. 이를 사용하면 컴포넌트가 불필요한 리렌더링을 방지할 수 있습니다.

`memo`는 컴포넌트의 `props`가 변경되었는지 여부를 확인하여 리렌더링 여부를 결정합니다. `props`가 변경되지 않으면 이전에 렌더링된 결과를 재사용하고, 변경되었으면 컴포넌트를 리렌더링합니다.

```
import React from 'react';

// propA와 propB 값이 변경되지 않으면 리렌더링이 발생하지 않습니다.
const MyComponent = React.memo(({ propA, propB }) => {
  // 컴포넌트의 내용
  return (
    <div>
      <p>Prop A: {propA}</p>
      <p>Prop B: {propB}</p>
    </div>
  );
});
```

`React.memo`를 사용하기 전 주의사항:

- **`memo` 적용의 유무 판단:** `memo`를 사용하면 리렌더링 성능이 개선될 수 있지만, 항상 적용해야 하는 것은 아닙니다. 컴포넌트가 빈번하게 리렌더링되는 것이 아니라면, `memo`를 적용하지 않는 것이 더 효과적일 수 있습니다.
- **`memo`는 PureComponent와 다름:** `React.memo`는 함수형 컴포넌트에만 적용할 수 있으며, 클래스형 컴포넌트에서는 `PureComponent`를 사용해야 합니다.
- **의존성 배열을 사용할 수 없음:** `memo`는 `useEffect`나 `useCallback`과 달리 의존성 배열을 사용할 수 없습니다. 전체 `props`를 비교하므로, 모든 `props`가 필요하다면 깊은 비교를 수행하는 커스텀 비교 함수를 활용해야 합니다.

### 커스텀 비교 함수 사용
`React.memo`는 기본적으로 `props`를 얕은 비교(Shallow Comparison)합니다. 만약 자세한 비교 로직이 필요하다면, 두 번째 매개변수로 커스텀 비교 함수를 전달할 수 있습니다.

```
import React from 'react';

const MyComponent = React.memo(
  ({ propA, propB }) => {
    // 컴포넌트의 내용
  },
  (prevProps, nextProps) => {
    // 깊은 비교 로직
    return prevProps.propA === nextProps.propA && prevProps.propB === nextProps.propB;
  }
);
```
