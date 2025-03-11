---
categories:
- PhaserJs
date: '2024-12-05'
title: '[PhaserJs] Phaser.GameObjects.Group'
---

{% raw %}
`Phaser.GameObjects.Group`은 다수의 객체를 관리하는 객체입니다. 그룹 내 객체는 서로 독립적이며, 개별적으로 제어할 수 있습니다.

```
new Phaser.GameObjects.Group(scene, children, config)
```
- `scene`: 그룹이 속하는 씬(Scene) 객체입니다.
- `children`: 그룹에 추가할 초기 게임 오브젝트 배열입니다.
- `config`: 그룹의 동작 방식을 정의하는 설정 객체입니다.

`config` 속성
1. `classType`: 그룹에 추가되는 객체의 기본 클래스를 지정합니다. 기본 값은 `Phaser.GameObjects.GameObject`가 사용됩니다.
2. `maxSize`: 그룹에 추가될 수 있는 최대 객체 수를 제한합니다. 객체 개수가 최대 제한에 도달했을 때, 새로운 객체를 추가하려고 하면 객체가 추가되지 않습니다. `maxSize`가 설정된 그룹은 객체 풀링이 활성화되며, `0`이면 객체 풀링이 비활성화됩니다.
3. `defaultKey`: 그룹에 추가될 객체의 기본 텍스처 키를 지정합니다.
4. `defaultFrame`: 기본 텍스처의 프레임을 지정합니다.
5.  `runChildUpdate`: `true`로 설정하면 그룹의 모든 자식 객체에서 `update()` 메서드를 호출합니다. 기본 값은 `true`입니다.
6.  `createCallback`: 그룹에 객체가 추가될 때 실행되는 콜백 함수입니다.
7.  `removeCallback`: 그룹에서 객체가 제거될 때 실행되는 콜백 함수입니다.

**주요 메서드**
- `get()`: 그룹에서 비활성화된 객체를 1개 가져옵니다. 비활성화된 객체가 없으면, 새로운 객체를 생성하여 반환합니다.
- `add()`: 하나 이상의 객체를 그룹에 추가합니다.
- `create()`: 그룹에 새로운 객체를 생성하여 추가합니다.
- `getChildren()`: 그룹에 포함된 모든 자식 객체를 배열 형태로 반환합니다.
- `remove()`: 그룹에서 특정 객체를 제거합니다.

### 객체 풀링
`maxSize`가 설정된 그룹은 **객체 풀링**이 적용됩니다. 객체 풀링은 새 객체를 계속 생성하고 삭제하는 대신, 재사용 가능한 객체의 "풀(pool)"을 유지하여 필요에 따라 활성화하거나 비활성화하는 방식입니다. 이를 통해 GC(Garbage Collection)로 인한 성능 저하를 줄이고 게임 실행 중의 프레임 속도를 안정적으로 유지할 수 있습니다. 

```
// 그룹 생성
this.bullets = this.add.group({
    classType: Phaser.GameObjects.Sprite,
    maxSize: 20,
    runChildUpdate: true,
    createCallback: (obj) => {<br>
        console.log(`${obj.texture.key} added to the group`);
    },
    removeCallback: (obj) => {<br>
        console.log(`${obj.texture.key} removed from the group`);
    }
});

// 객체 활성
function fireBullet(x, y) {
    const bullet = this.bullets.get(x, y);
    if (bullet) {
        bullet.setActive(true).setVisible(true);
        bullet.body.velocity.y = -300;
    }
}

// 객체 비활성
function resetBullet(bullet) {
    bullet.setActive(false).setVisible(false);
    bullet.body.stop();
}
```
{% endraw %}