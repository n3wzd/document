---
categories:
- ReactNative
date: '2025-02-26'
title: '[ReactNative] Expo File System'
---

{% raw %}
`expo-file-system`은 **Expo SDK**의 모듈로, **파일 시스템에 접근하고 파일을 읽고 쓸 수 있는 기능**을 제공합니다. 이 모듈을 사용하면 모바일 디바이스의 파일 시스템에서 파일을 저장, 읽기, 삭제, 디렉터리 작업 등을 할 수 있습니다. 주로 로컬 파일을 관리하거나, 외부 파일을 앱에 저장하는 경우에 유용합니다.

1. **파일 읽기/쓰기**:
    - 로컬 파일을 읽거나 수정할 수 있습니다.
    - 파일을 새로 생성하거나 기존 파일을 수정할 수 있습니다.
2. **디렉토리 작업**:
    - 디렉토리를 생성하거나 삭제하고, 디렉토리의 내용을 읽을 수 있습니다.
3. **파일 다운로드/업로드**:
    - 네트워크를 통해 파일을 다운로드하거나 로컬 시스템에서 업로드할 수 있습니다.
4. **파일 정보 조회**:
    - 파일의 크기, 생성일, 수정일 등을 가져올 수 있습니다.
5. **파일 경로 관리**:
    - 앱에서 사용되는 다양한 파일 경로를 다룰 수 있습니다 (예: 로컬 파일 시스템 경로, 임시 경로 등).

설치:
```
expo install expo-file-system
```

#### 주요 메서드
- **writeAsStringAsync(uri, string, options?)**: 문자열 데이터를 파일에 저장합니다.
- **readAsStringAsync(uri, options?)**: 파일에서 문자열 데이터를 읽습니다.
- **deleteAsync(uri, options?)**: 파일을 삭제합니다.
- **getInfoAsync(uri, options?)**: 파일 또는 디렉터리의 정보를 반환합니다.
- **makeDirectoryAsync(uri, options?)**: 디렉터리를 생성합니다.
{% endraw %}