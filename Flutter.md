# Flutter
`Flutter`는 Android, iOS 앱을 구축할 수 있는 2018년에 출시된 Google의 모바일 UI 프레임워크 SDK입니다. 언어는 `Dart`를 사용합니다.

Flutter는 다음과 같은 이점이 있습니다.
- 단일 코드베이스
- 네이티브 앱
- 유연한 UI
- 재사용 가능한 로직
- 높은 호환성
- 고성능 및 빠른 개발
- 적은 시스템 리소스 소모
- Hot Reload (재컴파일 없이 변경사항 확인 가능)

## 아키텍처
### 위젯 (Widget)
`위젯`은 Flutter 앱을 구성하는 기본 요소입니다. 모든 Flutter 앱은 위젯으로 구성되어 있으며, 위젯은 또다른 위젯으로 구성될 수 있습니다.

### 계층 (Layer)
Fluttet 프레임워크는 복잡성에 따라 간단하게 3가지 `계층`으로 분류할 수 있습니다.
1. OS (Android / iOS)
2. 앱을 구성하는 widgets
3. 표시되는 UI / states

### 제스처 (Gesture)

### 상태 (State)