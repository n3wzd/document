# JSX
JSX(JavaScript XML)는 React에서 사용되는 JavaScript의 확장 문법입니다. JSX는 React에서 UI를 작성하기 위한 강력하고 편리한 방법을 제공합니다.

JSX는 XML과 비슷한 문법을 사용하여 JavaScript 코드 안에 마크업을 작성할 수 있게 해줍니다. JSX는 React 엘리먼트를 생성하는 데 사용되며, 이 엘리먼트는 React 컴포넌트의 기본 빌딩 블록입니다.

JSX의 주요 특징과 사용법은 다음과 같습니다:

1. **XML과 유사한 문법**: JSX는 HTML/XML과 유사한 문법을 가지고 있어, React 컴포넌트를 정의할 때 마크업을 사용하기 쉽습니다.
```
<person>
  <name>John Doe</name>
  <age>30</age>
  <city>New York</city>
</person>
```

2. **JavaScript 표현식 삽입**: JSX 내에서는 중괄호 `{}`를 사용하여 JavaScript 표현식을 삽입할 수 있습니다.
```
const name = "John";
const element = <p>Hello, {name}!</p>;
```

3.  **JSX는 객체로 변환**: JSX 코드는 React.createElement 함수로 변환되어 React 엘리먼트 객체로 만들어집니다.
```
const element = <h1>Hello, World!</h1>;
// 위 코드는 아래와 같이 변환됨
const element = React.createElement('h1', null, 'Hello, World!');
```

4. **React 컴포넌트에서 사용**: JSX는 React 컴포넌트의 렌더 함수에서 반환되는 요소로 사용됩니다.
```
class MyComponent extends React.Component {
  render() {
    return (
      <div>
        <h1>Hello, {this.props.name}!</h1>
      </div>
    );
  }
}
```

5. **속성 전달**: JSX에서는 HTML과 같이 속성을 엘리먼트에 전달할 수 있습니다.
```
const element = <img src="image.jpg" alt="An example image" />;
```

JSX는 React 코드를 더 직관적이고 가독성 있게 만들어주며, JavaScript와의 통합이 자연스럽습니다. 하지만 JSX는 브라우저에서 직접 실행할 수 없고, 트랜스파일러를 통해 일반 JavaScript로 변환되어야 합니다.
