# Vue.js
 Vue.js는 프론트엔드 웹 애플리케이션을 개발하기 위한 프로그레시브 Javascript 프레임워크입니다.

- **컴포넌트 기반 아키텍처**: Vue.js는 UI를 작은 단위의 컴포넌트로 나누어 개발하는 컴포넌트 기반 아키텍처를 사용합니다.
- **가상 DOM 업데이트**: 효율적인 가상 DOM 업데이트 알고리즘을 통해 뛰어난 성능을 제공합니다.
- **리액티브 데이터 바인딩**: Vue.js는 데이터와 DOM 요소를 연결하여 데이터가 변경될 때 자동으로 화면이 업데이트되는 리액티브 데이터 바인딩을 제공합니다. 

## API
Vue.js에서는 두 가지 주요한 API 스타일이 있습니다.

※ 여기서는 Options API를 기준으로 진행합니다.

### Options API
- Options API는 Vue.js의 초기 버전부터 사용되어 온 전통적인 API 스타일입니다.
- 주로 `data`, `methods`, `computed`, `watch` 등의 속성을 사용하여 Vue 컴포넌트를 정의합니다.
- 데이터, 메서드, 계산된 속성, 감시자 등을 객체 내부에 정의하여 사용합니다.
- 각각의 옵션은 컴포넌트의 특정 부분을 정의하며, 컴포넌트의 구조가 명확하고 간단한 경우에 적합합니다.

```
Vue.component('MyComponent', {
  data() {
    return {
      message: 'Hello, Vue!'
    };
  },
  methods: {
    greet() {
      alert(this.message);
    }
  }
});
```

### Composition API
- Composition API는 Vue.js 3에서 소개된 새로운 API 스타일입니다.
- 컴포넌트 로직을 관련된 부분으로 묶어 재사용 가능한 로직 조각으로 만들 수 있도록 합니다.
- `setup()` 함수 내부에서 컴포넌트의 데이터, 메서드, 계산된 속성 등을 정의합니다.
- `reactive`, `computed`, `watch` 등의 Vue 함수를 사용하여 상태 관리를 할 수 있습니다.
- Composition API는 복잡한 컴포넌트의 로직을 더 구조화하고 재사용 가능하게 만들어줍니다.

```
import { reactive, computed } from 'vue';

export default {
  setup() {
    const state = reactive({
      message: 'Hello, Vue!'
    });

    const greet = () => {
      alert(state.message);
    };

    return {
      state,
      greet
    };
  }
};
```

## Vue Directives
Vue Directives는 HTML 요소에 특별한 속성을 추가하여 템플릿의 동작을 제어하는 방법입니다. Vue에서는 `v-` 접두사를 가진 다양한 디렉티브를 제공합니다.

### v-bind
HTML 속성과 Vue 인스턴스의 데이터를 바인딩할 때 사용됩니다.

```
<div v-bind:id="dynamicId"></div>
```

```
new Vue({
  data: {
    dynamicId: 'my-element'
  }
});
```

### v-model
폼 입력 요소와 Vue 인스턴스의 데이터를 양방향으로 바인딩할 때 사용됩니다.
    
```
<input v-model="message" type="text">
```

```
new Vue({
  data: {
    message: 'Hello Vue!'
  }
});
```

### v-if, v-else-if, v-else
조건부 렌더링을 구현할 때 사용됩니다.
    
```
<p v-if="seen">Hello!</p>
```

### v-for
배열이나 객체의 각 항목을 순회하면서 요소를 생성할 때 사용됩니다.
    
```
<ul>
  <li v-for="item in items">{{ item.text }}</li>
</ul>
```

```
new Vue({
  data: {
    items: [
      { text: '사과' },
      { text: '바나나' },
      { text: '딸기' }
    ]
  }
});
```

### v-on
이벤트 처리를 위해 사용됩니다.
    
```
<button v-on:click="greet">인사하기</button>
```

```
new Vue({
  methods: {
    greet: function () {
      alert('안녕하세요!');
    }
  }
});
```

