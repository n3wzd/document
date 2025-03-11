---
categories:
- TypeScript
date: '2024-04-22'
title: '[TypeScript] 6. Type Aliases'
---

{% raw %}
타입 별칭은 새로운 타입의 별칭을 생성하는 데 사용됩니다. 이를 통해 복잡한 타입을 더 짧고 명확하게 표현할 수 있습니다.

```
type Point = {
    x: number;
    y: number;
};
```

위의 코드에서 `Point`는 객체 유형 `{ x: number; y: number; }`의 별칭입니다. 이제 `Point`를 사용하여 유형을 참조할 수 있습니다.

```
let p: Point = { x: 10, y: 20 };
```
{% endraw %}