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

## 컴포넌트 (Components)
React에서 컴포넌트는 UI를 작은 독립적인 조각으로 분리하여 구조화하는 핵심 개념입니다. 각각의 컴포넌트는 자체적인 상태와 라이프사이클을 가질 수 있으며, 이들을 결합하여 전체 애플리케이션을 구성합니다.

컴포넌트는 크게 2가지 종류가 있습니다:

- **함수 컴포넌트:** 주로 state나 lifecycle 메서드 없이 단순한 UI를 표현하는데 사용됩니다.
- **클래스 컴포넌트:** 상태나 라이프사이클 메서드를 필요로 하는 복잡한 로직이 필요한 경우에 사용됩니다.

React 16.8 이전에는 클래스 컴포넌트가 리액트 컴포넌트의 상태 및 라이프사이클을 추적하는 유일한 방법이었습니다. 함수 컴포넌트는 "상태 없음"으로 간주되었습니다. 그러나 Hooks가 추가되면서 함수 컴포넌트는 이제 거의 클래스 컴포넌트와 동등해졌습니다.

클래스 컴포넌트는 여전히 많은 프로젝트에서 사용되고 있지만, 함수 컴포넌트와 Hooks가 간결하면서도 강력한 기능을 제공하므로, 새로운 프로젝트에서는 주로 함수 컴포넌트를 사용하는 추세입니다.

**주의사항**
React에서는 컴포넌트의 이름이 대문자로 시작해야 합니다. 예를 들어, 올바른 컴포넌트 이름은 `MyComponent`이지만, `myComponent`와 같이 소문자로 시작하면 안 됩니다.

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

## 속성 (Props)
Props는 React에서 컴포넌트 간에 데이터를 전달하는 메커니즘입니다. 부모 컴포넌트에서 자식 컴포넌트로 데이터를 전달하여 컴포넌트 간 통신이 가능하게 합니다. Props를 통해 컴포넌트는 외부에서 전달된 데이터를 읽기 전용으로 사용할 수 있습니다.

- **읽기 전용 (Read-Only):** Props는 컴포넌트에서 읽기 전용입니다. 자식 컴포넌트에서 부모로부터 전달받은 props를 직접 수정할 수 없습니다.
- **부모에서 자식으로 전달:** Props는 부모 컴포넌트에서 자식 컴포넌트로 데이터를 전달하는데 사용됩니다.
 - **값의 변경이 가능:** Props는 부모 컴포넌트에서 전달되므로, 부모의 상태가 변경되면 해당 변경 사항이 자식 컴포넌트의 props에 반영됩니다.

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
자식 컴포넌트에서는 함수의 매개변수로 props를 받아 사용합니다.

```
// 자식 컴포넌트
import React from 'react';

const ChildComponent = (props) => {
  return <p>{props.message}</p>;
};

export default ChildComponent;
```

### 기본값 설정
부모 컴포넌트가 데이터를 전달하지 않을 경우, 자식 컴포넌트에 설정된 기본값이 사용됩니다.

```
// 자식 컴포넌트
import React from 'react';

const ChildComponent = (props) => {
  return <p>{props.message || 'Default Message'}</p>;
};

export default ChildComponent;
```

### Destructuring
함수의 매개변수에서 분해대입을 사용하여 특정 props만 추출할 수 있습니다.

```
// 자식 컴포넌트
import React from 'react';

const ChildComponent = ({ message }) => {
  return <p>{message}</p>;
};

export default ChildComponent;
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
React에서는 이벤트가 자동으로 부모 컴포넌트로 전파되며, 부모에서 자식으로 전파되지 않습니다. 이를 중단하려면 `stopPropagation`을 사용합니다.

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

### 조건부 렌더링 함수
조건부 렌더링을 처리하는 함수를 따로 작성하여 가독성을 높일 수도 있습니다.

```
const WelcomeMessage = () => <p>Welcome, User!</p>;
const LoginMessage = () => <p>Please log in</p>;

const MyComponent = ({ isLoggedIn }) => {
  return isLoggedIn ? <WelcomeMessage /> : <LoginMessage />;
};
```

이러한 방식은 복잡한 조건문을 함수로 분리하여 가독성을 높일 수 있습니다.

## 리스트 (Lists)
React에서 리스트는 동적인 데이터를 효과적으로 렌더링하는데 사용되는 중요한 개념입니다. 리스트는 배열이나 기타 반복 가능한(iterable) 객체를 매핑하여 여러 항목을 렌더링할 수 있도록 도와줍니다. React에서 리스트를 다루기 위한 주요 방법은 JSX 내에서 `map` 함수를 사용하는 것입니다.

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

### useState
`useState`는 React에서 함수 컴포넌트에서 상태(state)를 관리하기 위한 Hook입니다. 이를 사용하여 컴포넌트의 상태를 추가하고, 상태가 변경될 때마다 컴포넌트를 리렌더링할 수 있습니다.

`useState`의 반환값은 배열이며, 첫 번째 요소는 현재 상태 값, 두 번째 요소는 상태를 갱신할 함수입니다.

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

`useState` 함수는 하나의 인자를 받고, 이 인자는 초기 상태값입니다. (위의 예제에서는 `0`이 초기 상태값으로 설정되었습니다.)

`useState`는 함수를 인자로 받을 수도 있습니다. 이렇게 사용하면 초기 상태값을 계산하는 데 함수를 사용할 수 있습니다. 이 함수는 컴포넌트가 처음 렌더링될 때만 실행되고, 이후 렌더링에서는 무시됩니다.

```
const [count, setCount] = useState(() => {
  // 초기 상태값을 계산하는 함수
  return someExpensiveComputation();
});
```

### useEffect
컴포넌트가 렌더링될 때마다 특정 작업을 수행하도록 설정할 수 있게 해주는 Hook입니다. 또한, 클래스형 컴포넌트의 라이프사이클 메서드와 유사한 역할을 합니다.

1. **부수 효과 함수:**  `useEffect`의 첫 번째 매개변수로 전달되는 함수는 부수 효과를 정의하는 함수입니다.
2. **의존성 배열:** `useEffect`의 두 번째 매개변수는 의존성 배열(dependency array)입니다. 이 배열에 있는 값이 변경될 때마다 부수 효과 함수가 다시 실행됩니다. 빈 배열을 전달하면 컴포넌트가 처음 마운트될 때, 그리고 컴포넌트가 렌더링될 때마다 부수 효과 함수가 실행됩니다.
3. **Clean-up 함수:** `useEffect` 내부에서 반환된 함수는 clean-up 함수로, 컴포넌트가 언마운트되거나 의존성이 변경될 때 실행됩니다. 주로 구독 해제, 타이머 해제 등의 정리 작업에 사용됩니다.

```
import React, { useEffect, useState } from 'react';

const MyComponent = () => {
  const [data, setData] = useState(null);

  // useEffect의 첫 번째 인자에는 부수 효과를 수행할 함수가 들어갑니다.
  // 두 번째 인자에는 의존성 배열(dependency array)이 들어갑니다.
  useEffect(() => {
    // 부수 효과 수행
    fetchData().then((result) => setData(result));

    // clean-up 함수를 반환할 수 있음
    return () => {
      // 부수 효과 정리(clean-up)
      cleanup();
    };
  }, []);

  return <div>{data ? <p>Data: {data}</p> : <p>Loading...</p>}</div>;
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
 
### useRef
`useRef`는 React에서 DOM 요소에 직접적인 접근이 필요하거나, 함수 컴포넌트에서 컴포넌트의 인스턴스 변수를 유지하거나, 컴포넌트 간 통신이 필요할 때 사용하는 Hook입니다. `useRef`로 생성된 객체는 `.current` 프로퍼티를 통해 현재 값을 유지하게 됩니다.

```
import React, { useRef, useEffect } from 'react';

const MyComponent = () => {
  // useRef를 사용하여 ref 객체 생성
  const myRef = useRef(null);

  useEffect(() => {
    // ref 객체의 current 프로퍼티를 사용하여 DOM에 직접 접근
    if (myRef.current) {
      myRef.current.focus();
    }
  }, []);

  return <input ref={myRef} />;
};
```

### useReducer
`useReducer`는 React에서 상태 관리를 위한 Hook 중 하나로, 상태 업데이트 로직을 컴포넌트 내부 또는 외부에 분리하여 관리할 때 사용됩니다. 주로 복잡한 상태 로직이나 여러 상태 값이 서로 연관되어 있을 때 활용됩니다.
    
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
    
### useCallback
`useCallback`은 React에서 함수를 메모이제이션하고, 불필요한 렌더링을 방지하기 위한 Hook입니다. 특히, 자식 컴포넌트에게 콜백 함수를 전달할 때 사용하면 성능 최적화에 도움이 됩니다.

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
`useCallback`은 React에서 값을 메모이제이션하고, 불필요한 렌더링을 방지하기 위한 Hook입니다. `useMemo`는 주로 렌더링 시마다 동일한 결과를 생성하는 경우나, 특정 종속성이 변경될 때에만 다시 계산해야 하는 경우에 유용합니다.

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
커스텀 훅(Custom Hook)은 React에서 로직을 재사용하기 위한 강력한 방법 중 하나입니다. 함수 컴포넌트에서 상태 관리, 효과(effects), 그리고 다른 컴포넌트 로직을 추상화하여 새로운 훅으로 만들어서 사용할 수 있게 해줍니다.

커스텀 훅은 "use"로 시작하는 이름을 가져야 합니다. 이는 React가 해당 함수가 훅으로 간주하도록 하는 규약입니다.

- **상태와 효과 로직의 추상화:** 커스텀 훅을 사용하면 특정 컴포넌트에 종속되지 않고, 상태나 부수 효과 로직을 추상화할 수 있습니다.
- **로직의 재사용:** 여러 컴포넌트에서 같은 로직을 사용하고 싶을 때 커스텀 훅을 만들면 해당 로직을 간편하게 재사용할 수 있습니다.
- **설계 유연성:** 커스텀 훅을 통해 로직을 구성하면 컴포넌트가 간결해지고, 로직의 변경에 대한 유연성이 높아집니다.
- **의존성 관리:** 커스텀 훅 내에서 사용하는 상태나 효과의 의존성을 컴포넌트에서 관리하면서, 훅의 사용자는 해당 의존성을 신경 쓰지 않고도 커스텀 훅을 사용할 수 있습니다.

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
