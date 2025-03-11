---
categories:
- Practice
date: '2025-02-10'
title: '[Practice] Kafka'
---

{% raw %}
### 입력 줄이 너무 깁니다. 명령 구문이 올바르지 않습니다.
Kafka 실행 명령 길이가 터미널 최대 명령 길이보다 길기 때문입니다. kafka 디렉토리 위치를 C 드라이브에 바로 위치시키면 해결됩니다.

### ERROR Shutdown broker because all log dirs in C:\kafka\kafkakafka-logs have failed
Kafka 로그 데이터가 손상된 경우입니다. Kafka 로그 데이터 삭제 후 재시작하면 해결됩니다.

로그 파일 손상 원인은 **디스크 공간 부족**, **서버 강제 종료** 등이 있습니다.
{% endraw %}