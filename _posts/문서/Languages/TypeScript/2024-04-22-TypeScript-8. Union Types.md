---
categories:
- TypeScript
date: '2024-04-22'
title: '[TypeScript] 8. Union Types'
---

{% raw %}
공용 유형은 여러 유형 중 하나를 나타낼 수 있는 특별한 유형입니다. 공용 유형은 파이프(`|`)로 구분된 두 개 이상의 유형으로 이루어집니다.

```
let myVar: number | string;

myVar = 10; // 숫자 할당
console.log(myVar);

myVar = "Hello"; // 문자열 할당
console.log(myVar);
```

### keyof
`keyof` 연산자는 객체의 모든 속성 키(key)를 문자열 리터럴 유니온으로 가져옵니다.

```
const person = {
    name: 'John',
    age: 30,
    email: 'john@example.com'
};

type PersonKeys = keyof typeof person; // "name" | "age" | "email"
```

`keyof` 연산자는 주로 제네릭 타입과 함께 사용되어 객체의 속성 키를 동적으로 처리하는 데 유용합니다.

```
function getProperty<T, K extends keyof T>(obj: T, key: K) {
    return obj[key];
}

const nameValue = getProperty(person, 'name'); // nameValue의 타입은 string입니다.
const ageValue = getProperty(person, 'age'); // ageValue의 타입은 number입니다.
const emailValue = getProperty(person, 'email'); // emailValue의 타입은 string입니다.
```
{% endraw %}