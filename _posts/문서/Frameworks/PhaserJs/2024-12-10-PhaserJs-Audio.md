---
categories:
- PhaserJs
date: '2024-12-10'
title: '[PhaserJs] Audio'
---

{% raw %}
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
{% endraw %}