---
categories:
- ReactNative
date: '2025-02-02'
title: '[ReactNative] React Query'
---

{% raw %}
**React Query**는 React 애플리케이션에서 **서버 상태**를 관리하고 **비동기 데이터 fetching**을 간소화하는 라이브러리입니다. 클라이언트 애플리케이션에서 서버와의 데이터를 주고받을 때 필요한 여러 가지 작업을 효율적으로 처리할 수 있게 도와줍니다.

1. **데이터 fetching**: 서버에서 데이터를 가져오는 작업을 훅을 통해 간편하게 처리할 수 있습니다. 비동기 요청을 작성할 때의 번거로움을 줄여줍니다.
2. **자동 캐싱**: 데이터를 한 번 요청하면, React Query가 이를 **자동으로 캐시**하여 불필요한 네트워크 요청을 줄이고 성능을 최적화합니다.
3. **데이터 갱신**: 사용자가 데이터를 수정하거나 새로고침 할 때 **자동으로 최신 데이터**를 가져올 수 있도록 합니다. 또한, **백그라운드에서 데이터 업데이트**가 가능합니다.
4. **로딩/에러 상태 관리**: 서버 요청에 대한 로딩 상태, 에러 상태 등을 자동으로 관리해 줍니다.
5. **자동 리페칭 (Re-fetching)**: 특정 조건에 맞춰 데이터를 자동으로 다시 가져올 수 있습니다. 예를 들어, 사용자가 페이지를 다시 방문하거나 데이터가 일정 시간이 지나면 재요청합니다.

설치:
```
npm install react-query
```

#### useQuery
`useQuery`는 **React Query**에서 데이터를 가져오는 비동기 작업을 처리하는 훅입니다.
    
```
import { useQuery } from 'react-query';
import axios from 'axios';

const fetchData = async () => {<br>
  const response = await axios.get('https://api.example.com/data');
  return response.data;
};

const MyComponent = () => {<br>
  const { data, isLoading, error } = useQuery('dataKey', fetchData);

  if (isLoading) return <div>Loading...</div>;
  if (error) return <div>Error: {error.message}</div>;

  return <div>{JSON.stringify(data)}</div>;
};
```

React Query는 데이터가 성공적으로 가져와지면 해당 데이터를 **자동으로 캐시**합니다. 이렇게 캐시된 데이터는 동일한 쿼리 키를 사용하는 다른 `useQuery` 훅에서 사용될 수 있습니다.

##### 쿼리 키(Query Key)
`useQuery`는 데이터를 요청할 때 **쿼리 키**를 사용하여 데이터를 식별합니다. 쿼리 키는 데이터를 요청하는데 사용되는 고유한 문자열 또는 배열입니다. 쿼리 키를 기반으로 React Query는 데이터를 캐시하고, 재요청 시 해당 캐시 데이터를 반환합니다.
```
const { data, isLoading } = useQuery('dataKey', fetchData);
```

`'dataKey'`는 해당 데이터를 식별하는 쿼리 키입니다. 이 키는 요청한 데이터가 다른 곳에서 사용될 때도 동일한 데이터를 참조하는 데 사용됩니다.

##### 쿼리 함수(Query Function)
`useQuery`의 두 번째 인자로 전달되는 **쿼리 함수**는 데이터를 실제로 가져오는 비동기 함수입니다. 이 함수는 Promise를 반환하고, React Query는 이 Promise가 해결되면 데이터를 저장하고, 컴포넌트는 그 데이터를 사용하게 됩니다.

```
const fetchData = async () => {<br>
  const response = await axios.get('/api/data');
  return response.data;
};

const { data, isLoading } = useQuery('dataKey', fetchData);
```

쿼리 함수는 **비동기**로 데이터를 가져오며, 네트워크 요청이 완료될 때까지 기다립니다.

##### 상태 관리
`useQuery`는 다음과 같은 **상태**를 관리합니다:
- **isLoading**: 데이터가 로딩 중일 때 `true`로 설정됩니다. 처음 데이터가 요청되거나, 네트워크 요청이 실패했을 때 로딩 상태가 표시됩니다.
- **isError**: 데이터 요청에 오류가 발생했을 때 `true`로 설정됩니다.
- **data**: 쿼리 함수가 반환한 데이터를 저장합니다.
- **error**: 쿼리 함수에서 오류가 발생했을 때 그 오류를 저장합니다.
- **isSuccess**: 요청이 성공적으로 완료되었을 때 `true`로 설정됩니다.

#### useMutation
`useMutation`는 데이터를 서버에 보내는 데 사용되는 훅입니다.
    
```
import { useMutation } from 'react-query';
import axios from 'axios';

const sendData = async (newData) => {<br>
  await axios.post('https://api.example.com/data', newData);
};

const MyComponent = () => {<br>
  const { mutate } = useMutation(sendData);

  const handleSubmit = async () => {<br>
	const newData = { name: 'New Data' };
	mutate(newData);
  };

  return (
	<div>
	  <button onClick={handleSubmit}>Submit</button>
	</div>
  );
};
```
{% endraw %}