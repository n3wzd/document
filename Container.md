﻿# Container
컨테이너 방법을 사용하면 로컬 환경에서 애플리케이션을 테스트하고, 이후 다른 환경에서 쉽게 배포할 수 있습니다. 다른 환경(예: 클라우드 서버)에서 일일이 관련 소프트웨어나 코드를 설치하고 설정할 필요 없이, 일관된 환경에서 애플리케이션을 배포할 수 있어 효율적이고 신속한 배포와 유지보수가 가능해집니다.

- **로컬 테스트의 용이성**: 로컬 환경에서 미리 테스트를 완료할 수 있어, 배포 전에 발생할 수 있는 문제를 사전에 해결할 수 있습니다.
- **환경 일관성**: 환경 간의 차이로 인한 문제를 최소화할 수 있습니다. 컨테이너에 포함된 모든 환경이 동일하기 때문에, 로컬에서 테스트한 것과 배포 환경에서 실행한 것이 동일하게 동작합니다.
- **자동화된 배포**: Docker 이미지를 생성한 후 레지스트리에 올리면, 배포 환경에 자동화된 배포 파이프라인을 구축해 쉽게 배포할 수 있습니다.

|**항목**|**컨테이너 사용**|**컨테이너 미사용**|
|---|---|---|
|**설정 환경**|독립된 컨테이너 내부의 환경 설정|배포 환경에서 직접 설치 및 환경 설정|
|**일관성**|로컬과 배포 환경의 일관성 보장|배포 환경과 로컬 환경의 차이 발생 가능|
|**용이성**|한번 만든 이미지를 어디서든지 배포 가능|배포 환경마다 수동으로 설치하고 설정해야 함|
|**확장성**|컨테이너 이미지를 여러 인스턴스에 쉽게 배포 가능|추가적인 인스턴스에서 별도 설치 및 설정 필요|
|**유지보수**|컨테이너 이미지 업데이트 후 재배포|유지보수 및 패치 작업을 직접 처리해야 함|
|**학습 곡선**|Docker 및 컨테이너 기술에 대한 학습 필요|서버 설정 및 운영에 대한 기본적인 지식 요구|

## Docker
**도커(Docker)**는 컨테이너화된 애플리케이션을 개발, 배포 및 실행하기 위한 플랫폼입니다.

도커의 주요 구성 요소는 다음과 같습니다:
- **도커 엔진(Docker Engine)**: 컨테이너를 만들고 실행하는 핵심 엔진입니다.
- **도커 이미지(Docker Image)**: 애플리케이션을 실행하기 위한 파일과 설정 등을 포함하는 템플릿입니다. 이미지는 불변(immutable)하며, 애플리케이션을 실행하는 데 필요한 모든 것을 포함합니다.
- **도커 컨테이너(Docker Container)**: 도커 이미지의 인스턴스로, 실행 중인 애플리케이션을 나타냅니다. 각 컨테이너는 격리된 환경에서 실행되며, 호스트 시스템과는 독립적으로 동작합니다.
- **도커 레지스트리(Docker Registry)**: 도커 이미지를 저장하고 공유하는 데 사용되는 저장소입니다. 대표적인 레지스트리로는 Docker Hub가 있습니다.


### vmmem
vmmem 프로세스가 CPU와 메모리를 점유하고 있는데, 이는 Docker Desktop 관련 문제라고 합니다. cmd에서 다음 커맨드를 입력하면 해결됩니다.

> wsl --shutdown
