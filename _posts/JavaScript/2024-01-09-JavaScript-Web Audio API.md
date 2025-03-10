---
categories:
- JavaScript
date: '2024-01-09'
title: '[JavaScript] Web Audio API'
---

{% raw %}
JavaScript의 `Web Audio API`는 오디오 관련 다양한 기능을 제공하는 API입니다. `Web Audio API`를 활용하면 주파수 분석 등 다양한 오디오 관련 기능을 추가할 수 있습니다.

`Web Audio`의 기본적인 작동 단계는 아래와 같습니다:

1.  `AudioContext`를 생성합니다.
2.  `Source`를 생성합니다.
3.  `Effect`를 생성합니다.
4.  `Destination`를 설정합니다. (예: 시스템 스피커)
5.  `Source`를 `Effect`로 연결하고, `Effect`를 `Destination`에 연결합니다.

```
         Audio Context
------------------------------------
|  input => Effects => Destination |<br>
------------------------------------
```

```
// 1. AudioContext 생성
const audioCtx = new (window.AudioContext || window.webkitAudioContext)();

// 2. Source 생성
const audioSource = audioCtx.createMediaElementSource(audio1);

// 3. Effect 생성
const analyser = audioCtx.createAnalyser();

// 4. Destination 연결
audioSource.connect(analyser);
analyser.connect(audioCtx.destination);
```

### AudioContext
`AudioContext`는 오디오 작업이 수행되는 오디오 프로세싱 그래프를 나타냅니다.

`window` 객체를 통해 `AudioContext`를 생성할 수 있습니다. 이 방법은 대부분의 최신 브라우저에서 지원되지만, 일부 오래된 브라우저는 지원되지 않을 수 있습니다. 이때 호환성을 고려하여 `webkitAudioContext`를 사용할 수도 있습니다.

```
const audioCtx = new (window.AudioContext || window.webkitAudioContext)();
```

### AudioNode
`AudioNode`는 `Web Audio API`에서 제공하는 오디오 프로세싱 모듈입니다. `Source`, `Effect`, `Destination` 등의 객체는 모두 `Audio Node`를 상위 객체로 합니다.

`AudioContext`를 통해 `AudioNode`를 생성할 수 있으며, 팩토리메소드, 생성자 2가지 방법이 있습니다. 

```
const node1 = audioCtx.createMediaElementSource(audio); // 팩토리메소드
const node2 = new MediaElementAudioSourceNode(audioCtx); // 생성자
```

일부 브라우저에서는 생성자를 지원하지 않을 수 있으므로, 팩토리 메서드를 사용하는 것이 보다 안전합니다.

### Source
`Source`는 오디오를 제공하는 `AudioNode`입니다. 다음은 주요 `Source` 유형입니다:

- `MediaElementAudioSourceNode`: HTML의 `<audio>`, `<video>` 태그에서 오디오를 제공합니다.
- `OscillatorNode`: 사인파와 같은 기본 파형을 생성하여 오디오를 생성합니다.

### Effect
`Effect`는 오디오에 다양한 효과를 부여하는 `AudioNode`입니다. 다음은 주요 `Effect` 유형입니다:

- `AnalyserNode`: 오디오를 분석하여 주파수 스펙트럼 및 시간 도메인 데이터를 얻을 수 있는 노드입니다.
- `GainNode`: 볼륨과 관련된 조절을 할 수 있는 노드로, 오디오의 음량을 조절하는 데 사용됩니다.

### Destination
`Destination`은 오디오의 최종 목적지를 나타내는 `AudioNode`이며, 일반적으로 시스템의 스피커나 오디오 출력 장치에 연결됩니다.`AudioContext.destination`을 통해 `Destination`을 참조할 수 있습니다.
{% endraw %}