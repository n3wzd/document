---
categories:
- TensorFlow
date: '2024-05-07'
title: '[TensorFlow] Tensor'
---

{% raw %}
텐서(Tensor)는 다차원 배열을 나타내는 수학적인 개념입니다. 벡터(1D 텐서), 행렬(2D 텐서), 그리고 이보다 더 높은 차원의 배열(3D, 4D, ...) 등을 포함합니다. 텐서는 머신러닝과 딥러닝에서 데이터를 표현하고 처리하는 데 주로 사용됩니다.

TensorFlow에서 텐서는 다차원 배열을 나타내는 핵심 데이터 구조입니다. 텐서는 여러 차원을 가질 수 있으며, 다음과 같은 특징을 갖습니다:

- **데이터 타입**: TensorFlow의 텐서는 다양한 데이터 타입을 지원합니다. 예를 들어, 부동 소수점 수(float), 정수(int), 불리언(bool) 등의 데이터 타입을 가질 수 있습니다.
- **차원(Dimension)**: 텐서는 임의의 차원을 가질 수 있습니다. 스칼라(0D 텐서), 벡터(1D 텐서), 행렬(2D 텐서)를 비롯하여 고차원 텐서도 표현할 수 있습니다.
- **불변성(Immutability)**: TensorFlow의 텐서는 불변적입니다. 즉, 한 번 생성되면 그 값을 변경할 수 없습니다. 대신에 새로운 텐서를 생성하여 연산을 수행하고, 필요한 경우 원래 텐서를 대체할 수 있습니다.
- **연산(Operations)**: TensorFlow는 텐서를 대상으로 다양한 수학적 연산을 수행할 수 있습니다. 예를 들어, 덧셈, 곱셈, 행렬 곱셈, 텐서 분할 등의 연산을 지원합니다.

```
import tensorflow as tf

# 1D 텐서(벡터) 생성
tensor_1d = tf.constant([1, 2, 3, 4, 5])
print("1D 텐서(벡터):")
print(tensor_1d)

# 2D 텐서(행렬) 생성
tensor_2d = tf.constant([[1, 2, 3], [4, 5, 6]])
print("\n2D 텐서(행렬):")
print(tensor_2d)

# 3D 텐서 생성
tensor_3d = tf.constant([[[1, 2], [3, 4]], [[5, 6], [7, 8]]])
print("\n3D 텐서:")
print(tensor_3d)
```
{% endraw %}