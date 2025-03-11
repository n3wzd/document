---
categories:
- TypeScript
date: '2024-04-22'
title: '[TypeScript] 4. Object'
---

{% raw %}
객체(Object)는 여러 속성(key-value 쌍)을 포함하는 데이터 구조입니다.

```
type Person = {
    name: string;
    age: number;
    email: string;
};
let person: Person = {
    name: "John",
    age: 30,
    email: "john@example.com"
};
```

객체 유형은 선택적 속성, 읽기 전용 속성 등을 정의할 수도 있습니다.

```
type Person = {
    name: string;
    age: number;
    email?: string; // 선택적 속성
};
```
{% endraw %}