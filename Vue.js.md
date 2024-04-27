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

## Methods
Vue.js에서 `methods`는 Vue 인스턴스 안에 정의된 함수들을 포함하는 객체입니다. 이 객체 안에 정의된 함수들은 Vue 인스턴스의 데이터를 조작하거나, 이벤트를 처리하거나, 다른 비동기 동작을 수행할 수 있습니다.

```
<div id="app">  
	<p>Click on the box below:</p>  
	<div v-on:click="writeText">  
		{{ text }}  
	</div>  
</div>  
  
<script src="https://unpkg.com/vue@3/dist/vue.global.js"></script>  
	<script>  
		const  app = Vue.createApp({  
			data() {  
				return  {  
			text:  ''  
			}  
		},  
		methods: {  
			writeText() {  
				this.text  =  'Hello World!'  
				}  
			}  
		})  
	app.mount('#app')  
</script>
```

## Event Modifiers
이벤트 수식어(event modifiers)는 DOM 이벤트에 대한 특정한 수식어를 제공하여 이벤트 처리를 보다 편리하게 할 수 있습니다.

- `.stop`: 이벤트의 전파를 중지시킵니다. 클릭 이벤트의 경우 부모 엘리먼트로의 이벤트 전파를 막습니다.
- `.prevent`: 이벤트의 기본 동작을 취소합니다.
- `.capture`: 이벤트를 캡처 모드로 설정합니다. 이는 이벤트를 하위 요소에서 상위 요소로 전파하는 대신 상위 요소에서 하위 요소로 전파하는 것을 의미합니다.
- `.self`: 이벤트가 자기 자신의 엘리먼트에서만 트리거될 때만 동작합니다.
- `.once`: 이벤트 핸들러를 한 번만 실행하도록 합니다.
- `.passive`: 스크롤 동작에 사용되며, 스크롤 이벤트 핸들러를 막지 않고 스크롤 성능을 향상시킵니다.

## CSS Binding
CSS 바인딩을 사용해서 동적으로 스타일을 적용할 수 있습니다.

### 객체 구문 (Object Syntax)
Vue 인스턴스의 데이터에 따라 인라인 스타일을 동적으로 지정할 수 있습니다.

```
<div v-bind:style="{ color: textColor, fontSize: textSize + 'px' }">Styled Text</div>
```

### 배열 구문 (Array Syntax)
여러 개의 스타일 객체를 배열에 추가하여 조건부로 스타일을 적용할 수 있습니다.

```
<div v-bind:style="[baseStyles, additionalStyles]">Styled Text</div>
```

### 클래스 바인딩 (Class Binding)
클래스를 동적으로 적용하기 위해 `v-bind:class` 디렉티브를 사용할 수 있습니다.

```
<div v-bind:class="{ active: isActive, 'text-danger': hasError }">Styled Text</div>
```

위의 예제에서 `isActive`와 `hasError`는 Vue 인스턴스의 데이터입니다. 데이터의 상태에 따라 클래스가 동적으로 추가 또는 제거됩니다.

## Computed Properties
계산된 속성(Computed Properties)은 Vue 인스턴스의 데이터를 기반으로 계산된 값을 반환하는 속성입니다. 이러한 계산된 속성은 일반 데이터 속성처럼 사용되지만, Vue 인스턴스의 데이터가 변경될 때마다 자동으로 다시 계산되며, 이를 효율적으로 캐시하여 성능을 향상시킵니다. 주로 복잡한 계산이 필요할 때 유용합니다.

- **캐싱(Caching):** 계산된 속성은 종속된 데이터가 변경될 때만 다시 계산됩니다. 그렇기 때문에 필요에 따라 여러 번 접근하더라도 계산은 한 번만 수행됩니다.
- **지연 계산(Lazy Evaluation):** 계산된 속성은 실제로 접근되기 전까지는 계산되지 않습니다. 따라서 해당 값이 필요한 시점에만 계산이 수행됩니다.

계산된 속성을 사용할 때는 `computed` 속성을 사용하여 정의합니다.

```
var vm = new Vue({
  data: {
    width: 10,
    height: 5
  },
  computed: {
    area: function () {
      return this.width * this.height;
    }
  }
});
```

위의 예제에서 `area`는 계산된 속성으로, `width`와 `height` 데이터 속성을 기반으로 계산됩니다. 이러한 계산된 속성을 템플릿에서 사용할 때에는 일반 데이터 속성과 동일하게 접근할 수 있습니다.

```
<div>{{ area }}</div>
```

## Watchers
Watchers는 데이터의 변화를 감지하고 이에 대응하여 특정 동작을 수행하는 방법을 제공합니다. 주로 데이터 변경에 대한 처리나 비동기 작업을 수행하기 위해 사용됩니다.

```
var vm = new Vue({
  data: {
    someData: 'initial value'
  },
  watch: {
    someData(newValue, oldValue) {
      // 데이터가 변경될 때마다 호출됩니다.
      console.log('New value: ', newValue);
      console.log('Old value: ', oldValue);
    }
  }
});
```

위 Watchers는 `someData`의 값이 변경될 때마다 호출되며, 새 값과 이전 값이 인수로 전달됩니다.
