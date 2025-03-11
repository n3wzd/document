---
categories:
- ReactNative
date: '2025-01-24'
title: '[ReactNative] React Hook Form'
---

{% raw %}
**React Hook Form**은 `<form>` 태그의 기본 기능을 확장하고, 폼의 상태와 검증을 더 쉽게 관리할 수 있도록 도와줍니다.

1. **폼 상태 관리 간소화**
    - `<form>` 태그만 사용할 경우, 상태 관리를 위해 React의 `useState`를 많이 사용해야 합니다.
    - React Hook Form은 `useForm` 훅으로 폼 전체의 상태를 효율적으로 관리합니다.
2. **내장된 검증 기능**
    - React Hook Form은 HTML5의 기본 검증 속성(`required`, `minLength` 등)을 지원하며, 추가적인 검증 로직도 간단히 추가할 수 있습니다.
    - 에러 메시지와 상태를 관리하기 쉬워집니다.
3. **제어되지 않는 컴포넌트 지원**
    - React Hook Form은 기본적으로 **제어되지 않는(uncontrolled)** 컴포넌트를 사용합니다.
    - 이 방식은 React 상태와의 동기화를 최소화해 성능을 최적화합니다.
4. **리렌더링 최소화**
    - `<form>` 태그만 사용할 경우, 입력 필드 하나가 변경될 때 전체 폼 컴포넌트가 리렌더링될 수 있습니다.
    - React Hook Form은 각 필드를 독립적으로 관리해 불필요한 리렌더링을 방지합니다.
5. **유연성**
    - Yup, Zod와 같은 검증 라이브러리와 쉽게 통합할 수 있어 복잡한 폼 검증도 간단하게 처리할 수 있습니다.

설치:
```
npm install react-hook-form
```

#### useForm
`useForm`은 `react-hook-form` 라이브러리에서 제공하는 훅으로, 폼의 상태 관리와 유효성 검사, 제출을 간단하게 처리할 수 있게 도와줍니다. `useForm`을 사용하면, 폼의 입력값을 관리하고, 유효성 검사를 설정하고, 제출 시 데이터 처리를 쉽게 할 수 있습니다.

```
import React from 'react';
import { useForm } from 'react-hook-form';

interface FormData {
  name: string;
  email: string;
}

const MyForm = () => {<br>
  // useForm 훅을 호출하여 폼 상태와 관련된 기능을 가져옵니다.
  const { register, handleSubmit, formState: { errors } } = useForm<FormData>();

  const onSubmit = (data: FormData) => {<br>
    console.log(data); // 폼 제출 시 데이터 출력
  };

  return (
    <form onSubmit={handleSubmit(onSubmit)}>
      <input {...register('name', { required: '이름을 입력해주세요.' })}/>
      {errors.name && <p>{errors.name.message}</p>}

      <input {...register('email', { required: '이메일을 입력해주세요.' })}/>
      {errors.email && <p>{errors.email.message}</p>}

      <button type="submit">제출</button>
    </form>
  );
};
```

1. `register`: 입력 필드를 `useForm`에 등록하는 함수입니다.
    - `register` 함수는 필드를 등록하고, 필드에 유효성 검사 규칙을 추가할 수 있습니다.
    - 예: `register('name', { required: '이름을 입력해주세요.' })`
    - `name`은 필드의 이름을 의미하고, 두 번째 인자로는 유효성 검사 규칙을 객체 형태로 전달합니다.
2. `control`: 폼의 상태를 관리합니다.
	- `control`을 `useController` 또는 `Controller`에 전달하여 폼 필드를 관리합니다.
3. `handleSubmit`: 폼 제출을 처리하는 함수입니다.
    - `handleSubmit`은 유효성 검사를 통과한 데이터만 `onSubmit` 함수로 전달합니다.
    - 예: `<form onSubmit={handleSubmit(onSubmit)}></form>`
4. `formState`: 폼의 상태를 추적하는 객체입니다.
    - `formState.errors`: 유효성 검사 오류를 추적하는 객체입니다.
    - 예: `formState.errors.name`은 `name` 필드에 대한 오류를 추적합니다.
5. `setValue`: 필드 값을 동적으로 설정할 수 있는 함수입니다.
    - 예: `setValue('name', 'John Doe')`는 `name` 필드의 값을 `'John Doe'`로 설정합니다.
6. `watch`: 필드 값을 실시간으로 추적할 수 있는 함수입니다.
    - 예: `const name = watch('name')`는 `name` 필드의 값을 실시간으로 추적합니다.
7. `reset`: 폼을 초기화하는 함수입니다.
    - 예: `reset()`을 호출하면 폼을 초기 상태로 되돌립니다.
8. `clearErrors`: 특정 필드 또는 모든 필드의 오류를 제거하는 함수입니다.
    - 예: `clearErrors('name')`는 `name` 필드의 오류를 제거합니다.

`register`는 기본적인 폼 필드와 유효성 검사에 사용되며, `control`은 더 복잡한 폼 상태 관리 및 외부 라이브러리와의 통합을 위해 사용됩니다.

|**특징**|`register`|`control`|
|---|---|---|
|**주요 역할**|폼 필드를 등록하고, 유효성 검사 규칙을 설정|폼 상태를 관리하고, 필드 값을 추적|
|**사용되는 위치**|기본 HTML 입력 요소 (예: `<input>`, `<select>`)와 함께 사용|`useController` 또는 `Controller`와 함께 사용|
|**사용 예시**|`<input {...register('fieldName', { rules })} />`|`<Controller control={control} name="fieldName" />`|
|**핸들러 제공 여부**|`value`, `onChange`, `onBlur` 등의 필드 관련 핸들러 반환|`field.value`, `field.onChange`, `field.onBlur` 제공|

#### 유효성 검사
```
const { register, handleSubmit, formState: { errors } } = useForm<FormData>();

const onSubmit = (data: FormData) => {<br>
  console.log(data);
};

return (
  <form onSubmit={handleSubmit(onSubmit)}>
    <input
      {...register('name', { required: '이름을 입력해주세요.', minLength: 2 })}
      placeholder="이름"
    />
    {errors.name && <p>{errors.name.message}</p>}

    <input
      {...register('email', { 
        required: '이메일을 입력해주세요.',
        pattern: {
          value: /<sup>[</sup>\s@]+@[<sup>\s@]+\.[</sup>\s@]+$/,
          message: '이메일 형식이 올바르지 않습니다.'
        }
      })}
      placeholder="이메일"
    />
    {errors.email && <p>{errors.email.message}</p>}

    <button type="submit">제출</button>
  </form>
);
```

- `required`: 필수 입력 필드로 설정합니다.
- `minLength`: 최소 길이를 설정합니다.
- `maxLength`: 최대 길이를 설정합니다.
- `pattern`: 정규식을 사용하여 값이 특정 패턴과 일치하는지 검사합니다.
- `validate`: 사용자 정의 검증 함수를 사용하여 유효성 검사를 추가합니다.

#### useController
`useController`는 `react-hook-form` 라이브러리에서 제공하는 훅으로, 폼 필드와 관련된 상태를 관리하고, 해당 필드에 대한 유효성 검사 및 입력 값을 처리할 수 있게 해줍니다. `useController`는 `useForm` 훅과 함께 사용되며, 주로 폼 필드에 대해 더 세밀한 제어가 필요할 때 사용됩니다.

```
import React from 'react';
import { TextInput, Text, View } from 'react-native';
import { useController } from 'react-hook-form';

const MyInput = ({ control, name, rules, errors }) => {<br>
  // useController를 사용하여 필드의 상태를 관리합니다.
  const { field } = useController({
    name,
    control,
    rules, // 유효성 검사 규칙
  });

  return (
    <View>
      <TextInput
        style={{ borderWidth: 1, padding: 10 }}
        placeholder={name}
        onChangeText={field.onChange} // onChange 이벤트에 연결
        onBlur={field.onBlur} // onBlur 이벤트에 연결
        {...field}
      />
      {errors[name] && <Text style={{ color: 'red' }}>{errors[name]?.message}</Text>}
    </View>
  );
};

export default MyInput;
```

`useController`는 다음과 같은 값을 반환합니다:
- `field`:
    - `onChange`: 필드의 값이 변경될 때 호출되는 함수.
    - `onBlur`: 필드가 포커스를 잃을 때 호출되는 함수.
    - `name`: 필드의 이름 (이 값은 `useController`를 호출할 때 지정한 `name`입니다).
    - `ref`: 필드에 대한 레퍼런스 (주로 `useRef`와 결합되어 사용).
- `fieldState`:
    - `invalid`: 필드가 유효성 검사에서 실패한 경우 `true`.
    - `isTouched`: 필드가 사용자가 상호작용한 경우 `true`.
    - `isDirty`: 필드의 값이 초기 값과 다르면 `true`.
    - `error`: 해당 필드의 오류 메시지.
{% endraw %}