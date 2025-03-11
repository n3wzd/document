---
categories:
- PhaserJs
date: '2024-12-05'
title: '[PhaserJs] Phaser.Geom'
---

{% raw %}
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
{% endraw %}