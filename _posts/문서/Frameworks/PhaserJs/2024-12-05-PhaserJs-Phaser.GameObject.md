---
categories:
- PhaserJs
date: '2024-12-05'
title: '[PhaserJs] Phaser.GameObject'
---

{% raw %}
전반적인 게임 오브젝트가 상속하는 상위 객체입니다.

### 객체 생성
오브젝트는 보통 `this.add` 메서드를 통해 생성됩니다.  

`Phaser.GameObjects.Sprite` 객체를 생성하여 씬에 추가:
``` 
const sprite = this.add.sprite(100, 100, 'textureKey');
```

### 객체 삭제
- Phaser 씬에 추가된 게임 오브젝트(`this.add.*`)는 기본적으로 씬이 종료되면 Phaser가 자동으로 정리합니다.
- 전역 변수로 생성되거나 씬의 라이프사이클 외부에서 관리되는 객체는 수동으로 `destroy()`를 호출해야 제거됩니다.
- 이벤트 리스너, 타이머, 커스텀 데이터 구조에 저장된 참조는 가비지 컬렉터가 해제하지 못할 수 있으므로 명시적으로 제거해야 합니다.

```
// 캔버스 수동 정리
canvas = null; // 명시적으로 참조 해제
```

#### `destroy()`
`destroy()`** 메서드를 호출하여 오브젝트를 씬에서 제거할 수 있습니다. 참조 역시 제거되며, 이후 JavaScript의 가비지 컬렉터에 의해 메모리가 회수됩니다.

```
sprite.destroy();
```

`destroy()`를 호출한 후에는 해당 오브젝트에 접근하지 않도록 해야 합니다.

### `name`
- 이름을 통해 객체를 식별하고 검색할 수 있습니다.
- 이름의 타입은 일반적으로 문자열이며, 중복될 수 있습니다.

### `setName`
- `Phaser.GameObjects`의 이름을 설정합니다.

### `id`
- 아이디는 컨테이너 내부에서 객체 간 고유 식별을 위한 목적으로 사용됩니다.
- 아이디의 타입은 일반적으로 정수이며, 중복을 허용하지 않습니다.

### `setID`
- `Phaser.GameObjects`의 아이디를 설정합니다.

### `getBounds`
- `getBounds()`는 해당 객체의 경계 사각형(Rectangle)을 계산하여 반환합니다. 주로 충돌 감지나 객체의 위치 및 크기를 파악할 때 사용됩니다.
- `getBounds()` 메서드의 초기 값은 해당 객체의 렌더링되는 이미지에 의해 자동으로 결정됩니다.
- 객체의 크기나 위치가 변할 때 `getBounds()`는 자동으로 갱신됩니다.
- `Phaser.GameObjects.Sprite`,`Phaser.GameObjects.Container`, `Phaser.GameObjects.Image`, `Phaser.GameObjects.Text`에서 사용할 수 있습니다.

### `setActive`
- 객체가 게임의 논리(물리 연산, 충돌 검사 등)에 참여하는지를 제어하는 메서드입니다.
- `true`로 설정하면 객체는 게임 논리에서 활성 상태로 간주됩니다.
- `false`로 설정하면 객체는 게임 논리에서 비활성화됩니다(물리 연산, 충돌 등이 중지됨).

### `setVisible`
- 객체가 화면에 렌더링될지 여부를 제어하는 메서드입니다.
- `true`로 설정하면 객체가 화면에 출력됩니다.
- `false`로 설정하면 객체가 화면에 렌더링되지 않습니다. (그러나 여전히 활성 상태일 수 있습니다.)
	- 특정 조건에서 객체를 보이지 않게 하지만 여전히 충돌 검사를 수행.
{% endraw %}