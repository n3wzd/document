﻿# CORS
## 출처 (Origin)
`출처(Origin)`는 3가지로 구성됩니다.
> 프로토콜(Protocol), 호스트(Host), 포트(Port)

위의 3가지가 모두 일치하면 같은 출처로 판단됩니다.
```
예: 도메인 주소 = https://www.google.com
프로토콜: 'https://'
호스트: 'www.google.com'
```

## SOP (Same Origin Policy)
`동일 출처 정책(Same Origin Policy, SOP)`은 웹 애플리케이션은 **자기 자신과 동일한 출처**를 가진 리소스만 사용할 수 있다는 정책입니다.

만약 어떤 웹 애플리케이션이 다른 출처의 서버 리소스에 제한 없이 접근할 수 있다면 보안 문제가 발생할 수 있습니다. 그러므로 SOP을 적용하는 것은 보안 측면에서 중요합니다.

하지만 웹 개발에서 다른 출처를 가진 리소스를 사용하는 것은 흔한 일이며, 출처가 다르다는 이유로 차단된다면 불편할 수 있습니다. 그래서 모든 리소스가 SOP에 적용되지는 않으며, 주로 유효성은 다음을 통해 판단됩니다.

1.  일부 리소스는 SOP의 제한을 받지 않습니다.
	- 이미지 파일, CSS 파일, JS 스크립트 파일 요청 등
2.  그 외 리소스는 `CORS` 정책으로 유효성을 판단합니다.

## CORS (Cross-Origin Resource Sharing)
`교차 출처 리소스 공유(Cross-Origin Resource Sharing, CORS)`는 한 출처에서 실행 중인 웹 애플리케이션이 다른 출처를 가진 자원에 접근할 수 있는 권한을 부여하는 정책입니다.

CORS의 동작 방식을 간단하게 설명하면 다음과 같습니다.

1. 웹 애플리케이션은 다른 출처의 리소스를 요청할 때, 요청 헤더의 `Origin` 필드에 자신의 출처를 기록합니다. (예: Origin = https://www.google.com)
2. 서버는 응답 헤더의 `Access-Control-Allow-Origin` 필드에 "이 리소스에 접근하는 것이 허용된 출처"를 기록합니다.
3. 브라우저는 서버로부터 받은 응답의 `Access-Control-Allow-Origin`과 자신이 보낸 요청의 `Origin`을 비교하여 응답의 유효성을 확인합니다.
	- 이때 브라우저가 서버 응답을 유효하지 않다고 하면 CORS 정책이 위반된 것으로 판단됩니다.

### CORS 정책 위반 문제
웹 개발을 하다보면 CORS 정책 위반 문제를 마주칠 수 있습니다. 특히 로컬에서 테스트할 때 자주 발생합니다.

#### 서버
CORS를 직접적으로 우회하는 것은 쉽지 않습니다. CORS는 보안 문제를 해결하는 중요한 정책이며, CORS 정책의 판단은 주로 브라우저가 수행하기 때문입니다.

가장 좋은 방법은 서버에서 CORS 정책에 맞게 적절한 `Access-Control-Allow-Origin`을 설정하는 것입니다. 해당 필드에 애플리케이션의 요청 `Origin` 값을 대입하면 됩니다.

> Access-Control-Allow-Origin: https://www.google.com

#### 로컬
> 에러 메시지 예시:
> Access to audio at 'test.mp3' from origin 'null' has been blocked by CORS policy: Cross origin requests are only supported for protocol schemes: http, data, chrome, chrome-extension, chrome-untrusted, https.

애플리케이션을 로컬로 실행하고 로컬 파일 리소스를 요청할 때 `Origin`이 null로 설정되어 있다면 CORS 정책 위반이 발생합니다.

이 문제는 애플리케이션을 로컬 서버로 실행하면 해결할 수 있습니다.
