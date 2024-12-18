# Phaser.js
**Phaser.js**는 JavaScript로 개발된 2D 게임을 만들기 위한 프레임워크로, **게임 루프**, **물리 엔진**, **애니메이션**, **입력 처리** 등 기본적인 게임 개발에 필요한 많은 기능을 제공합니다.
- 직관적인 API로 쉽게 게임을 만들 수 있습니다.
- 2D 게임에 최적화되어 있으며, **타일맵**, **물리 엔진**, **충돌 처리** 등을 기본적으로 지원합니다.

Phaser는 기본적으로 **WebGL**을 사용하여 그래픽을 렌더링합니다. WebGL은 브라우저에서 하드웨어 가속을 활용하여 그래픽 렌더링 성능을 최적화합니다.

```
const config = {
	type: Phaser.AUTO,
	width: window.innerWidth,
	height: window.innerHeight,
	scene: {
		preload:  preload,
		create:  create,
		update:  update
	},
};

const game = new Phaser.Game(config);

function preload() {

}

function create() {

}

function update() {

}
```

## Phaser.GameObject
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

## Phaser.GameObjects.Container
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

## Phaser.Geom
- 좌표 계산, 충돌 검사, 도형의 크기와 위치 파악 등을 수행하는 정적 객체입니다.
- 여러 그래픽 요소(`Graphics`, `Sprites`, `Tilemaps` 등)와 결합하여 복잡한 그래픽 작업을 수행할 수 있습니다. (예: 사각형 그라데이션)

### 도형
- 사각형: `Phaser.Geom.Rectangle(x, y, width, height)`
- 원: `Phaser.Geom.Circle(x, y, radius)`

### 충돌 검사
Geom 라이브러리는 도형에 대한 충돌 검사 메서드를 제공합니다:
- 사각형 간 충돌: `Phaser.Geom.Intersects.RectangleToRectangle`
- 원형 간 충돌: `Phaser.Geom.Intersects.CircleToCircle`
- 사각형과 원 간 충돌: `Phaser.Geom.Intersects.RectangleToCircle`

간단한 도형(사각형, 원) 간의 충돌은 빠르게 처리할 수 있습니다. 시간 복잡도는 O(1)입니다.

## Physics
Phaser는 오브젝트의 물리적 동작을 처리하기 위한 내장 물리 엔진을 제공하며, 이동, 충돌, 중력, 속도, 탄성 등 복잡한 물리적인 동작을 쉽게 구현할 수 있게 도와줍니다.

Phaser는 2가지 주요 물리 엔진을 지원합니다:
1. **Arcade Physics**:
    - 가볍고 빠른 2D 물리 엔진.
    - 충돌 검사와 간단한 물리 동작에 적합.
    - **속도(velocity)**, **중력(gravity)**, **반발력(bounce)** 같은 특성을 지원.
2. **Matter.js**:
    -   더 복잡하고 현실적인 물리 동작을 구현 가능.
    -   실제 물리 엔진처럼 동작(마찰, 회전, 토크 등).

## Phaser.GameObjects.Group
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
maxSize`가 설정된 그룹은 **객체 풀링**이 적용됩니다. 객체 풀링은 새 객체를 계속 생성하고 삭제하는 대신, 재사용 가능한 객체의 "풀(pool)"을 유지하여 필요에 따라 활성화하거나 비활성화하는 방식입니다. 이를 통해 GC(Garbage Collection)로 인한 성능 저하를 줄이고 게임 실행 중의 프레임 속도를 안정적으로 유지할 수 있습니다. 

```
// 그룹 생성
this.bullets = this.add.group({
    classType: Phaser.GameObjects.Sprite,
    maxSize: 20,
    runChildUpdate: true,
    createCallback: (obj) => {
        console.log(`${obj.texture.key} added to the group`);
    },
    removeCallback: (obj) => {
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

## Graphic
### Phaser.Textures.Texture
- 이미지, 캔버스, 비디오 등 다양한 미디어를 게임 씬에서 사용할 수 있는 기본적인 자료입니다.
- `name` 속성(텍스처의 이름)은 해당 텍스처를 식별하는 **텍스처 키**입니다. 이 키는 Phaser에서 텍스처를 참조하거나 관리할 때 사용하는 고유한 문자열입니다.

### HTML.Canvas
- `<canvas>` 태그를 사용해 정교하고 복잡한 동적 그래픽을 자유롭게 그릴 수 있습니다.
- 캔버스로 그릴 때는 GPU 가속을 활용하지 않고 CPU 기반 렌더링을 하므로 성능에 부담이 될 수 있습니다.
- 정적 이미지일 때, 필요한 이미지를 캔버스로 1번만 생성하고 이를 텍스처와 스프라이트로 캐시하면 동작 중에는 캔버스의 성능 부담을 없앨 수 있습니다.

### Phaser.GameObjects.Graphics
- 정적 기본 도형(사각형, 원, 선 등)을 즉시 생성하고 렌더링합니다.
- 사용이 간단하고 직관적이며, Phaser의 다른 요소와 자연스럽게 통합 가능합니다.
- Phaser.Graphics 객체는 WebGL의 배경과 화면 상의 모든 그래픽을 GPU에서 처리하므로 성능이 우수하고, 다수의 객체를 그릴 때 성능상의 이점이 있습니다.
- 복잡한 그래픽을 그리기 어렵다는 단점이 있습니다.

### Phaser.GameObjects.Sprite
- 텍스쳐를 통해 정적 그래픽을 화면에 표시하는 객체입니다.
- 사전 제작된 이미지를 표현할 수 있습니다. 고정된 크기와 모양의 오브젝트를 반복적으로 그릴 수 있습니다.
- 이미 생성된 단순한 이미지나 텍스처를 사용할 때 적합합니다. 캐싱된 텍스처를 재사용하여 성능을 최적화할 수 있습니다.
- 복잡한 효과(그라데이션, 글로우 등)를 적용하기 어렵고, 동적인 그래픽을 사용한다면 추가 작업이 필요합니다.

**특징**
- 다양한 속성(크기, 위치, 회전 등)을 이용하여 이미지를 변형할 수 있습니다.
- `setDisplaySize`를 사용하지 않으면, 스프라이트는 기본적으로 텍스처의 원래 크기에 맞게 표시됩니다.

### Phaser.GameObjects.Shader
- 복잡하고 다이나믹한 그래픽 효과(글로우, 그라데이션, 왜곡, 빛 반사 등)를 실시간으로 적용할 수 있습니다. 조명 효과, 렌즈 플레어와 같은 복잡한 시각적 처리를 구현할 수 있습니다.
- GPU에서 병렬 처리로 실행되므로 실시간 렌더링 성능이 매우 뛰어납니다. 다수의 오브젝트에 동일한 그래픽 효과를 적용할 때도 효율적입니다.
- 셰이더 프로그래밍을 사용하기에 구현 난이도가 높으며, Phaser 내부에서 설정 및 디버깅이 상대적으로 복잡합니다.
- 클라이언트의 하드웨어 사양에 영향을 많이 받습니다.

### 비교
#### 종합
|방법|필요한 순간|적합한 사용 사례|장점|단점|
|---|---|---|---|---|
|Phaser.Graphics|단순한 도형이나 정적 그래픽 필요시|정적/동적 도형|직관적, 빠른 구현 가능|복잡한 효과 구현 어려움, 성능 저하 가능|
|Phaser.Sprite|정적 이미지를 사용할 때|반복적으로 이미지를 그릴 때|텍스처 캐싱으로 성능 최적화, Phaser와 통합 용이|복잡한 효과 제한, 이미지 사전 준비 필요|
|HTML.Canvas|Phaser 외부에서 그래픽 생성 시|동적 텍스처 생성, 사용자 지정 효과|효과 구현 자유도 높음, Phaser와 연동 가능|CPU 의존성 높음, 추가 변환 작업 필요|
|Phaser.Shader|고성능 효과와 실시간 렌더링 필요 시|글로우, 그라데이션, 물결 효과 등|GPU 처리로 고성능, 복잡한 효과 가능|학습 곡선 높음, 설정 및 디버깅 복잡|

- 단순한 도형 → **Phaser.Graphics**
- 캐싱된 정적 이미지 → **Phaser.Sprite**
- 간단한 동적 텍스처 → **HTML.Canvas**
- 실시간 고성능 효과 → **Phaser.Shader**

#### 동적 그래픽: 셰이더 vs 캔버스
|특징|셰이더|캔버스|
|---|---|---|
|실행 위치|GPU (병렬 처리)|CPU|
|성능|매우 빠르고 효율적|상대적으로 느리며 CPU 부하 증가|
|그라데이션 및 효과|고속으로 복잡한 효과 적용 가능|상대적으로 복잡한 처리에 느림|
|사용법|고급 GPU 프로그래밍 지식 필요|직관적이고 사용이 쉬움|
|호환성|거의 모든 브라우저 및 기기 지원|최신 브라우저 및 고사양 GPU 필요|

- 실시간 동적 처리 및 복잡한 그래픽 효과 → **Phaser.Shader**
- 간단한 그래픽 및 일회성 정적 렌더링 → **HTML.Canvas**

## Audio
### Audio
- Phaser의 `preload` 단계에서 로드된 오디오 파일 리소스입니다. 원본 데이터를 제공하며, 여러 사운드 인스턴스가 이 데이터를 참조합니다.

```
this.load.audio('bgMusic', 'assets/audio/background.mp3');
```

`bgMusic`은 오디오 파일 리소스의 키입니다.


### Sound
- `audio`를 기반으로 생성된 오디오 재생 컨트롤러입니다. 오디오를 재생, 일시 정지, 중지, 볼륨 조절 등의 작업을 수행합니다.

```
const bgSound = this.sound.add('bgMusic', { loop: true, volume: 0.5 });
bgSound.play();
```
