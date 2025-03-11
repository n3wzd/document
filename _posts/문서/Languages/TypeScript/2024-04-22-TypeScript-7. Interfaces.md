---
categories:
- TypeScript
date: '2024-04-22'
title: '[TypeScript] 7. Interfaces'
---

{% raw %}
인터페이스는 객체의 구조를 정의하기 위한 기능입니다. 인터페이스를 사용하면 객체가 특정 속성이나 메서드를 가져야 한다는 것을 명시적으로 선언할 수 있습니다.

```
interface Person {
    name: string;
    age: number;
    greet(): void;
}
```

위의 코드에서 `Person` 인터페이스는 `name`, `age` 속성과 `greet` 메서드를 가져야 한다는 것을 정의합니다. 이제 이 인터페이스를 구현하는 객체는 해당 속성과 메서드를 가지고 있어야 합니다.

인터페이스는 클래스뿐만 아니라 다른 객체 형식에도 적용될 수 있습니다.
```
class Employee implements Person {
    name: string;
    age: number;

    constructor(name: string, age: number) {
        this.name = name;
        this.age = age;
    }

    greet() {
        console.log(`Hello, my name is ${this.name}.`);
    }
}
```
{% endraw %}