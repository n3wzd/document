---
categories:
- AI
date: '2024-05-08'
title: '[AI] Convolutional Neural Network'
---

{% raw %}
컨볼루셔널 신경망(Convolutional Neural Network, CNN)은 주로 이미지 인식 및 분류와 관련된 문제에 사용되는 딥러닝 신경망 아키텍처입니다. CNN은 이미지 등 공간정보 처리에 특화되어 있으며, 공간의 특징을 자동으로 학습하여 패턴을 인식하고 분류하는 데 사용됩니다.

CNN의 순전파 과정은 다음과 같습니다:
1. **합성곱(Convolution)**:
    - 여러 개의 작은 필터(kernel)를 사용하며, 각 필터는 입력 데이터를 슬라이딩하면서 합성곱 연산을 수행하고, 각 위치에서 특징 맵(feature map)을 생성합니다.
2. **활성화(Activation)**:
    - 합성곱 계층의 생성한 특징 맵에 활성화 함수(비선형 함수)를 적용하여 활성화된 특징 맵을 생성합니다.
3. **풀링(Pooling)**:
    - 활성화된 특징 맵을 다운샘플링하여 특징 맵의 크기를 줄이고 계산량을 줄입니다.
4. **합성곱-활성화-풀링 계층의 반복**:
    - 합성곱-활성화-풀링 계층의 조합이 여러 번 반복됩니다.
    - 풀링 계층의 출력이 다음 컨볼루션 계층의 입력으로 사용됩니다.
5. **완전 연결 계층(Fully Connected Layer)**:
    - 추출된 특징을 기반으로 최종적으로 입력 데이터를 분류합니다.

아래 예제는 MNIST 숫자 이미지 분류 문제를 해결하는 간단한 CNN입니다.
```
import tensorflow as tf
from tensorflow.keras import layers, models

# MNIST 데이터셋 로드
mnist = tf.keras.datasets.mnist
(train_images, train_labels), (test_images, test_labels) = mnist.load_data()

# 이미지 데이터 전처리
train_images = train_images.reshape((60000, 28, 28, 1)) / 255.0
test_images = test_images.reshape((10000, 28, 28, 1)) / 255.0

# CNN 모델 구성
model = models.Sequential([
    layers.Conv2D(32, (3, 3), activation='relu', input_shape=(28, 28, 1)),
    layers.MaxPooling2D((2, 2)),
    layers.Conv2D(64, (3, 3), activation='relu'),
    layers.MaxPooling2D((2, 2)),
    layers.Conv2D(64, (3, 3), activation='relu'),
    layers.Flatten(),
    layers.Dense(64, activation='relu'),
    layers.Dense(10, activation='softmax')
])

# 모델 컴파일
model.compile(optimizer='adam',
              loss='sparse_categorical_crossentropy',
              metrics=['accuracy'])

# 모델 훈련
model.fit(train_images, train_labels, epochs=5, batch_size=64)

# 모델 평가
test_loss, test_acc = model.evaluate(test_images, test_labels)
print('Test accuracy:', test_acc)
```

### Convolution
합성곱(Convolution) 과정은 입력 데이터와 필터(kernel) 사이의 합성곱을 계산하는 과정입니다. 합성곱은 입력 데이터를 필터와 겹쳐지는 부분마다 연산하여 출력값을 생성하며, 이를 통해 입력 데이터의 특징을 추출합니다.

합성곱 과정은 다음과 같습니다.
1. **입력 데이터와 필터(커널)**:
	- 입력 데이터는 주로 이미지나 다차원 배열 형태로 제공됩니다. 필터는 입력 데이터와 동일한 차원을 갖는 작은 행렬로서, 주로 2차원 혹은 3차원으로 사용됩니다. 필터의 크기는 일반적으로 3x3 또는 5x5와 같은 작은 값으로 설정됩니다.
2. **합성곱 연산**:
	- 입력 데이터와 필터의 요소별 곱을 계산합니다.
	- 이 곱의 합을 구하여 출력 맵의 현재 위치에 할당합니다.
	- 필터를 이동하면서 전체 입력 데이터를 스캔하고, 각 위치에서 합성곱 연산을 수행하여 출력 맵을 생성합니다.
3. **스트라이드(Strides)**:
	- 스트라이드는 필터가 이동하는 간격입니다.
	- 보통 스트라이드는 1이며, 필터가 한 칸씩 이동하면서 합성곱이 계산됩니다.
4. **패딩(Padding)**:
	- 패딩은 입력 데이터의 가장자리에 추가되는 가상의 값으로, 출력 맵의 크기를 조절하는 데 사용됩니다.
	- 패딩을 사용하여 출력 맵의 크기를 입력 데이터와 동일하게 만들 수 있습니다.

### Pooling
풀링(Pooling) 과정은 특징 맵의 공간적인 해상도를 줄이고 계산량을 감소시킵니다. 특징의 중요성을 유지하면서 공간적인 차원을 축소하여, 네트워크의 일반화 성능을 향상시키고 과적합을 방지합니다.

풀링 과정은 다음과 같습니다:
1. **풀링 윈도우(Window)**:
	- 풀링 연산은 풀링 윈도우(window)라는 고정 크기의 영역을 사용하여 수행됩니다.
	- 윈도우 영역은 일반적으로 2x2 또는 3x3 크기입니다.
2. **스트라이드(Strides)**:
	- 스트라이드는 윈도우가 이동하는 간격입니다.
	- 보통 스트라이드는 풀링 윈도우의 크기와 동일하게 설정되어, 겹치지 않는 영역에서 연산을 수행합니다.
3. **풀링 연산**:
	- 최대 풀링(Max Pooling): 각 풀링 윈도우 내에서 최대값을 계산합니다.
	- 평균 풀링(Average Pooling): 각 풀링 윈도우 내에서 평균값을 계산합니다.
4. **출력 특징 맵 생성**:
	- 풀링 연산을 통해 얻은 최대값 또는 평균값은 새로운 특징 맵의 해당 위치에 할당됩니다.

### Fully Connected Layer
CNN에서 완전 연결 계층(Fully Connected Layer)은 주로 네트워크의 최종 단계로, 층은 이전 계층에서 추출된 특징들을 사용하여 입력 데이터에 대한 최종적인 출력을 생성합니다. 

완전 연결 계층의 동작 과정은 다음과 같습니다:
1. **입력 데이터 전달**:
	- 이전 계층에서 추출된 특징 맵을 1차원으로 평탄화(flatten)합니다.
	- 평탄화한 벡터 형태의 데이터를 입력으로 사용합니다.
2. **활성화 함수 적용**:
	- 각 뉴런의 가중치와 편향을 적용한 후, 활성화 함수를 적용하여 출력을 생성합니다.
	- 활성화 함수를 거친 출력은 완전 연결 계층의 최종 출력이 됩니다.

완전 연결 계층의 출력은 주어진 작업에 따라 다르게 구성될 수 있습니다. 예를 들어, 분류(classification) 작업에서는 출력 뉴런의 수는 클래스의 수와 동일하게 설정되며, 각 출력 뉴런은 해당 클래스에 속할 확률을 나타냅니다.
{% endraw %}