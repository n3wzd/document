---
categories:
- TensorFlow
date: '2024-05-08'
title: '[TensorFlow] Keras'
---

{% raw %}
Keras는 딥러닝 모델을 구축하고 훈련하기 위한 고수준 신경망 API입니다. Keras는 모듈화와 확장성이 뛰어나며, 사용자 친화적인 인터페이스를 제공하여 딥러닝 모델을 빠르고 쉽게 구현할 수 있도록 도와줍니다. TensorFlow 버전 1.14부터 Keras는 TensorFlow의 일부로 공식적으로 통합되었으며, TensorFlow에서 Keras API를 사용하여 딥러닝 모델을 구현할 수 있습니다.

일반적으로 Keras API를 통해 딥러닝 모델을 활용하는 과정은 다음과 같습니다:
1. **데이터 준비**: 모델 훈련에 사용할 데이터를 준비합니다. `keras.datasets`를 활용할 수 있습니다.
2. **모델 생성**: `keras.models`에 포함된 모델을 사용하여 모델 인스턴스를 만듭니다.
3. **모델 컴파일**: `compile()` 메서드를 사용하여 모델을 컴파일합니다. 이 때 최적화 알고리즘, 손실 함수, 평가 지표 등을 지정합니다.
4. **모델 훈련**: `fit()` 메서드를 사용하여 모델을 훈련합니다. 훈련 데이터와 레이블을 전달하고, 에포크 수와 배치 크기를 지정합니다.
5. **모델 평가**: `evaluate()` 메서드를 사용하여 테스트 데이터에 대한 모델의 성능을 평가합니다.
6. **모델 예측**: `predict()` 메서드를 사용하여 새로운 데이터에 대한 예측을 생성합니다.

아래는 MNIST 데이터셋을 사용하여 손글씨 숫자를 분류하는 간단한 모델입니다.
```
import tensorflow as tf
import numpy as np
from tensorflow.keras.datasets import mnist
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Flatten, Dense

# 데이터 불러오기 및 전처리
(x_train, y_train), (x_test, y_test) = mnist.load_data()
x_train, x_test = x_train / 255.0, x_test / 255.0

# 모델 구성
model = Sequential([
    Flatten(input_shape=(28, 28)),  # 입력 이미지를 1차원으로 펼침
    Dense(128, activation='relu'),  # 은닉층
    Dense(10, activation='softmax') # 출력층 (10개의 클래스에 대한 확률값)
])

# 모델 컴파일
model.compile(optimizer='adam',
              loss='sparse_categorical_crossentropy',
              metrics=['accuracy'])

# 모델 학습
model.fit(x_train, y_train, epochs=5)

# 모델 평가
loss, accuracy = model.evaluate(x_test, y_test)
print(f'Test accuracy: {accuracy}')

# 모델 예측
predictions = model.predict(x_test)
predicted_labels = np.argmax(predictions, axis=1)
print("Predicted labels:", predicted_labels)
```

### keras.datasets
`keras.datasets`는 Keras 라이브러리에서 제공하는 다양한 데이터셋 모듈입니다. 이 모듈을 통해서 여러 표준 데이터셋을 손쉽게 다운로드하고할 수 있습니다. 주로 딥러닝 모델의 기본적인 성능 평가에 사용됩니다.

데이터셋은 일반적으로 튜플 형태로 반환되며, `(x_train, y_train), (x_test, y_test)`와 같이 훈련 데이터와 테스트 데이터를 제공합니다.

#### MNIST
MNIST 데이터셋은 손으로 쓴 숫자 이미지 데이터셋으로, 0에서 9까지의 숫자가 포함되어 있습니다. 

```
from tensorflow.keras.datasets import mnist

# 데이터셋 로드
(x_train, y_train), (x_test, y_test) = mnist.load_data()

# 데이터셋 확인
print(f'Training data shape: {x_train.shape}, Training labels shape: {y_train.shape}')
print(f'Test data shape: {x_test.shape}, Test labels shape: {y_test.shape}')
```

#### CIFAR-10
CIFAR-10 데이터셋은 10개의 서로 다른 클래스에 속하는 60,000개의 32x32 컬러 이미지로 구성되어 있습니다.

```
from tensorflow.keras.datasets import cifar10

# 데이터셋 로드
(x_train, y_train), (x_test, y_test) = cifar10.load_data()

# 데이터셋 확인
print(f'Training data shape: {x_train.shape}, Training labels shape: {y_train.shape}')
print(f'Test data shape: {x_test.shape}, Test labels shape: {y_test.shape}')
```

#### IMDB
IMDB 데이터셋은 50,000개의 영화 리뷰로 구성되어 있으며, 각 리뷰는 긍정적 또는 부정적 평가로 라벨링되어 있습니다. 자연어 처리 모델을 학습시키는 데 사용됩니다.

```
from tensorflow.keras.datasets import imdb

# 데이터셋 로드 (빈도 상위 10,000개의 단어만 사용)
(x_train, y_train), (x_test, y_test) = imdb.load_data(num_words=10000)

# 데이터셋 확인
print(f'Training data shape: {x_train.shape}, Training labels shape: {y_train.shape}')
print(f'Test data shape: {x_test.shape}, Test labels shape: {y_test.shape}')
```

#### 데이터셋 전처리
로드한 데이터셋은 종종 전처리가 필요합니다. 예를 들어, 이미지 데이터는 정규화, 텍스트 데이터는 토큰화 등의 과정을 거칩니다.

MNIST나 CIFAR-10 같은 이미지 데이터는 일반적으로 픽셀 값(0-255)을 0과 1 사이로 정규화합니다.

```
x_train = x_train.astype('float32') / 255.0
x_test = x_test.astype('float32') / 255.0
```

IMDB 데이터셋의 경우, 단어를 인덱스로 변환하여 토큰화합니다.

```
from tensorflow.keras.preprocessing.sequence import pad_sequences

# 패딩
x_train = pad_sequences(x_train, maxlen=500)
x_test = pad_sequences(x_test, maxlen=500)
```

### keras.models
`keras.models`는 Keras에서 모델을 정의하고 구성하는 클래스들을 포함하는 모듈입니다. 이 모듈에는 신경망 모델을 구축하는 데 사용되는 클래스들이 포함되어 있습니다.

#### Sequential
Sequential 모델은 Keras에서 가장 간단한 형태의 신경망 모델을 만드는 데 사용되는 클래스입니다. 이 클래스를 사용하면 각 층을 순차적으로 쌓아서 신경망 모델을 만들 수 있습니다. 각 층은 입력과 출력이 연속되어 전달되는 구조를 가지며, 마지막 출력이 최종 예측이 됩니다.

Sequential 모델은 간단한 구조의 신경망을 빠르게 구축하고 테스트할 때 유용합니다. 그러나 복잡한 모델 구조를 가진 경우에는 Functional API나 Model 클래스를 사용하는 것이 더 적합할 수 있습니다.

Sequential 모델을 생성할 때, 초기화 과정에서 층을 구성할 수 있습니다. 층은 `Dense`, `Conv2D`, `MaxPooling2D` 등이 주로 사용됩니다.
```
from keras.models import Sequential
from keras.layers import Dense

# Sequential 모델 생성
model = Sequential()

model = Sequential([
    Flatten(input_shape=(28, 28)),   # Flatten 층 추가
    Dense(128, activation='relu'),   # Dense 층 추가
    Dense(10, activation='softmax')  # Dense 층 추가
])
```

또는 `add()` 메서드를 사용하여 Sequential 모델에 층을 추가할 수 있습니다.

```
model.add(Flatten(input_shape=(28, 28)))
model.add(Dense(128, activation='relu'))
model.add(Dense(10, activation='softmax'))
```

#### Functional API
Functional API는 Keras에서 모델을 구축하는 또 다른 방법으로, Functional API를 사용하면 다중 입력, 다중 출력, 공유 레이어 등과 같은 복잡한 모델을 만들 수 있습니다.

Functional API를 사용하여 모델을 구축하는 일반적인 단계는 다음과 같습니다:

1. **Input 객체 생성**: 모델의 입력을 나타내는 Input 객체를 생성합니다. 이 객체는 shape을 지정하여 입력 데이터의 크기를 정의합니다.
2.  **레이어 함수 호출**: 다양한 레이어를 함수처럼 호출하여 모델의 연산 그래프를 구성합니다. 이전 레이어의 출력을 다음 레이어의 입력으로 사용할 수 있습니다.
3.  **Model 클래스 인스턴스화**: 입력과 출력을 지정하여 Model 클래스를 사용하여 모델을 정의하고 인스턴스화합니다. 이 인스턴스는 컴파일, 훈련 및 평가에 사용할 수 있습니다.

```
import tensorflow as tf
from tensorflow.keras.layers import Input, Dense
from tensorflow.keras.models import Model

# 입력 데이터의 크기를 지정
input_layer = Input(shape=(784,))

# 은닉층 정의
hidden1 = Dense(128, activation='relu')(input_layer)
hidden2 = Dense(64, activation='relu')(hidden1)

# 출력층 정의
output_layer = Dense(10, activation='softmax')(hidden2)

# 입력과 출력을 지정하여 모델 정의
model = Model(inputs=input_layer, outputs=output_layer)
```

### keras.layers
`keras.layers`는 Keras에서 제공하는 층(layer)을 정의하는 모듈입니다. 자주 사용되는 층들은 다음과 같습니다:

1. **Dense**: 완전 연결 층을 생성하는 데 사용됩니다. 각 입력 뉴런이 이전 층의 모든 뉴런과 연결됩니다.
2. **Conv2D**: 2D 컨볼루션 층을 생성하는 데 사용됩니다. 이미지 처리 및 컨볼루션 신경망에서 주로 사용됩니다.
3. **MaxPooling2D**: 최대 풀링 층을 생성하는 데 사용됩니다. 입력의 각 패치에서 최댓값을 추출하여 출력을 생성합니다.
4. **AveragePooling2D**: 평균 풀링 층을 생성하는 데 사용됩니다. 입력의 각 패치에서 평균 값을 추출하여 출력을 생성합니다.
5. **Flatten**: 다차원 입력을 1차원 벡터로 펼치는 데 사용됩니다. 주로 완전 연결 층에 연결하기 전에 사용됩니다.
6. **Dropout**: 드롭아웃을 적용하는 데 사용됩니다. 훈련 중에 일부 뉴런을 무작위로 비활성화하여 과적합을 줄입니다.
7. **BatchNormalization**: 배치 정규화를 수행하는 데 사용됩니다. 훈련 중에 입력을 정규화하여 학습 속도를 향상시키고 안정성을 높입니다.
8. **Embedding**: 단어나 범주형 데이터를 밀집 벡터로 변환하는 데 사용됩니다. 자연어 처리와 같은 텍스트 데이터에서 주로 사용됩니다.

### keras.callbacks
`keras.callbacks` 모듈은 Keras 모델의 학습 중에 호출되는 콜백(callback) 함수를 제공합니다. 이 콜백 함수들은 모델의 학습을 모니터링하고, 학습 중에 추가적인 작업을 수행하거나 조정할 수 있도록 도와줍니다.

주요 콜백들은 다음과 같습니다:
1. **ModelCheckpoint**: 학습 중에 모델의 가중치를 저장하는 콜백입니다. 정기적으로 모델의 가중치를 저장하여 학습 중간에 중단된 경우에도 모델을 다시 로드하여 학습을 재개할 수 있습니다.
2. **EarlyStopping**: 학습 중에 검증 손실(또는 지정된 지표)이 더 이상 개선되지 않을 때 학습을 조기 종료시키는 콜백입니다. 과적합을 방지하고 학습 시간을 단축시키는 데 유용합니다.
3. **TensorBoard**: 학습 중에 모델의 성능 및 메트릭을 시각화하는 데 사용되는 텐서보드 로그를 작성하는 콜백입니다. 훈련 및 검증 손실, 정확도 등을 모니터링할 수 있습니다.
4. **LearningRateScheduler**: 학습률을 동적으로 조정하는 콜백입니다. 학습률을 시간에 따라 변경하여 학습의 안정성 및 성능을 향상시킬 수 있습니다.
5. **ReduceLROnPlateau**: 검증 손실이 개선되지 않을 때 학습률을 감소시키는 콜백입니다. 학습률을 적절하게 조정하여 최적의 성능을 달성할 수 있도록 돕습니다.
6. **CSVLogger**: 학습 중에 손실 및 메트릭을 CSV 파일로 로깅하는 콜백입니다. CSV 파일은 후에 분석 및 시각화에 사용될 수 있습니다.

### model.compile
`model.compile()` 메서드는 TensorFlow 모델을 학습하기 위해 필요한 몇 가지 학습 설정을 지정하는 역할을 합니다. 이 메서드는 세 가지 주요 매개변수를 사용합니다.

1. **optimizer (옵티마이저)**: 모델의 가중치를 업데이트하는 방법을 결정합니다. 모델이 손실을 최소화하는 방향으로 학습될 때 옵티마이저가 사용됩니다. 주로 'adam', 'sgd'가 사용됩니다.
2. **loss (손실 함수)**: 모델의 출력과 실제 값 사이의 차이를 계산하는 방법을 정의합니다. 모델은 이 손실을 최소화하는 방향으로 학습됩니다. 일반적으로 회귀 문제에는 'mean_squared_error', 분류 문제에는 'sparse_categorical_crossentropy'이 사용됩니다.
3. **metrics (평가 지표)**: 모델의 성능을 평가하는 데 사용됩니다. 일반적으로 'accuracy'를 사용합니다.

### model.fit
`model.fit` 메서드를 통해 모델을 학습할 수 있습니다. 이 메서드는 훈련 데이터를 모델에 제공하여 지정된 에포크 수만큼 학습을 수행합니다.

```
history = model.fit(x, y, epochs=10, batch_size=32, validation_data=(x_val, y_val))
```

1. **x (입력 데이터)**:
   - 모델이 학습할 입력 데이터입니다. 일반적으로 Numpy 배열 또는 TensorFlow 데이터셋 형식입니다.
   - 예: 이미지 데이터일 경우 `(num_samples, height, width, channels)` 형식으로 제공됩니다.
2. **y (레이블 데이터)**:
   - 모델이 학습할 레이블 데이터입니다. `x`와 같은 형식으로 Numpy 배열 또는 TensorFlow 데이터셋 형식으로 제공됩니다.
   - 예: 분류 문제에서는 `(num_samples, num_classes)` 형식으로 제공됩니다.
3. **epochs (에포크 수)**:
   - 전체 데이터셋을 몇 번 반복해서 학습할지를 지정합니다.
4. **batch_size (배치 크기)**:
   - 모델이 한 번에 학습할 데이터 샘플의 수를 지정합니다. 기본값은 32입니다.
   - 큰 데이터셋의 경우 메모리 제한으로 인해 배치 단위로 데이터를 나누어 학습합니다.
5. **validation_data (검증 데이터)**:
   - 학습 도중 모델을 평가하기 위해 사용하는 검증 데이터입니다. `(x_val, y_val)` 형식의 튜플로 제공됩니다.
   - 각 에포크가 끝날 때마다 검증 데이터를 사용하여 모델의 성능을 평가합니다.
6. **validation_split (검증 데이터 분할 비율)**:
   - 전체 학습 데이터 중 일부를 검증 데이터로 사용하는 경우 지정합니다. 예를 들어, `validation_split=0.2`는 20%의 데이터를 검증용으로 분리합니다.
7. **callbacks (콜백 함수)**:
   - 학습 도중 특정 이벤트에 대한 콜백을 추가할 수 있습니다.
   - 예: `ModelCheckpoint`, `EarlyStopping`, `TensorBoard` 등
8. **verbose (출력 모드)**:
   - 학습 과정의 출력 모드를 지정합니다. `0`, `1`, `2` 중 하나를 선택합니다.
   - `0`: 출력 없음
   - `1`: 진행 막대(progress bar)
   - `2`: 에포크별로 한 줄씩 출력

반환 값으로 `History` 객체를 반환합니다. 이 객체에는 학습 과정에서의 손실과 메트릭 값이 저장됩니다.

### model.evaluate
`model.evaluate` 메서드는 학습된 모델을 평가하는 데 사용됩니다. 이 메서드는 모델의 성능을 측정하기 위해 테스트 데이터에 대한 평가를 수행합니다.

```
loss, accuracy = model.evaluate(x_test, y_test)
```

1. **x (입력 데이터)**:
   - 모델이 평가할 입력 데이터입니다. 일반적으로 Numpy 배열 또는 TensorFlow 데이터셋 형식입니다.
2. **y (레이블 데이터)**:
   - 모델이 평가할 레이블 데이터입니다. `x`와 같은 형식으로 Numpy 배열 또는 TensorFlow 데이터셋 형식으로 제공됩니다.
3. **batch_size (배치 크기)**:
   - 평가할 때 한 번에 처리할 데이터 샘플의 수를 지정합니다. 기본값은 32입니다.
4. **verbose (출력 모드)**:
   - 평가 과정의 출력 모드를 지정합니다. `0`, `1`, `2` 중 하나를 선택합니다.
   - `0`: 출력 없음
   - `1`: 진행 막대(progress bar)
   - `2`: 배치별로 한 줄씩 출력
5. **sample_weight (샘플 가중치)**:
   - 각 샘플에 가중치를 부여하여 평가할 수 있습니다. 샘플 가중치는 Numpy 배열 형식으로 제공됩니다.
6. **steps**:
   - 평가할 총 스텝 수를 지정합니다. 데이터가 배치로 나뉘어 처리될 때 유용합니다.
   - `steps`가 지정되지 않으면 `len(x) // batch_size`가 기본값으로 사용됩니다.

반환 값으로 손실 값과 메트릭 값을 반환합니다. 반환되는 값의 개수는 모델을 컴파일할 때 지정한 메트릭의 수에 따라 달라집니다.

### model.predict
`model.predict` 메서드는 학습된 모델을 사용하여 입력 데이터에 대한 예측을 수행합니다. 주어진 입력에 대한 모델의 출력을 반환합니다.

```
predictions = model.predict(x)
```
- `x`: 입력 데이터입니다. 일반적으로 모델이 예측할 데이터의 특성을 포함하는 배열 또는 텐서입니다.

반환값은 입력 데이터에 대한 예측 결과를 포함하는 `predictions` 배열 또는 텐서입니다. 이 배열의 크기 및 형태는 모델의 출력에 따라 달라집니다.

`predictions` 배열의 각 요소는 해당 입력에 대한 모델의 출력을 나타냅니다. 예를 들어, 다중 클래스 분류 모델의 경우, 각 클래스에 대한 확률 값을 포함하는 배열이 반환될 수 있습니다. 이 확률 값은 모델이 각 클래스에 속할 확률을 나타냅니다.
{% endraw %}