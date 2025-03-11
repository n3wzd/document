---
categories:
- PhaserJs
date: '2024-12-05'
title: '[PhaserJs] Phaser.GameObjects.Container'
---

{% raw %}
- 여러 `GameObjects` 객체들을 계층적 구조로 묶는 객체입니다. (`GameObjects`가 아닌 객체는 추가될 수 없습니다.)
- 컨테이너 내 객체들은 컨테이너의 트랜스폼(위치, 크기, 회전) 요소에 영향을 받습니다.
- 내부 객체들은 배열 구조로 저장되며, 이 배열을 사용하여 참조하거나 접근할 수 있습니다.

### `list`
- `list` 속성은 자식 객체들을 저장한 배열을 참조합니다. 이 배열을 통해 자식 객체를 인덱스로 참조할 수 있습니다.

```
const container = new Phaser.GameObjects.Container(scene, x, y);
const sprite1 = this.add.sprite(0, 0, 'spriteKey');
const sprite2 = this.add.sprite(50, 50, 'spriteKey');

container.add(sprite1);
container.add(sprite2);

const firstChild = container.list[0]; // sprite1
const secondChild = container.list[1]; // sprite2
```

### `getByName`
- `getByName` 메서드를 통해 해당 이름의 자식 객체를 가져올 수 있습니다.
- 한 컨테이너에서 같은 이름을 가진 자식 객체가 여러 개 존재할 경우, 처음으로 추가된 자식 객체를 반환합니다.
- 시간 복잡도는 O(n)입니다. (n: 자식 객체의 수)

```
const container = new Phaser.GameObjects.Container(scene, x, y);
const sprite1 = this.add.sprite(0, 0, 'spriteKey').setName('sprite1');
const sprite2 = this.add.sprite(50, 50, 'spriteKey').setName('sprite2');

container.add(sprite1);
container.add(sprite2);

const sprite = container.getByName('sprite1'); // sprite1
```

### `getByID`
- `getByID` 메서드를 통해 해당 ID에 대응되는 자식 객체를 가져올 수 있습니다.
- 시간 복잡도는 O(n)입니다. (n: 자식 객체의 수)

```
const container = new Phaser.GameObjects.Container(this, 100, 100);
const sprite1 = this.add.sprite(0, 0, 'spriteKey').setID(1);
const sprite2 = this.add.sprite(50, 50, 'spriteKey').setID(2);

container.add(sprite1);
container.add(sprite2);

const spriteByID1 = container.getByID(1); // sprite1
const spriteByID2 = container.getByID(2); // sprite2
```
{% endraw %}