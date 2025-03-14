---
categories:
- PhaserJs
date: '2024-12-04'
title: '[PhaserJs] Phaser.js'
---

{% raw %}
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
{% endraw %}