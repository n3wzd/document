---
categories:
- AI
date: '2024-05-10'
title: '[AI] Recurrent Neural Network'
---

{% raw %}
순환 신경망(Recurrent Neural Network, RNN)은 이전 단계의 출력을 현재 단계의 입력으로 사용하는 구조를 가진 딥러닝의 한 유형입니다. 이전 정보를 현재의 결정에 반영할 수 있다는 점에서 RNN은 순차 데이터를 처리할 때 효과적입니다. RNN은 자연어 처리 (번역, 텍스트 생성 등), 시계열 예측 (주식 시장 예측, 날씨 예측 등), 음성 인식 등 다양한 응용 분야에서 활용됩니다.

RNN은 다음과 같이 구성됩니다:
1. **입력층(Input Layer)**:
	- 입력 데이터를 받습니다.
2. **은닉층(Hidden Layer)**:
	- 이전 단계의 출력을 현재 단계의 입력과 결합하여 새로운 출력을 생성합니다.
	- 이전 단계의 은닉 상태를 다음 단계로 전달하는 순환적인 구조를 가지며 여러 번 반복됩니다.
3. **출력층(Output Layer)**: 모델의 최종 출력을 생성합니다.

다음은 0부터 9까지의 숫자 시퀀스를 예측하는 간단한 RNN 모델입니다.
```
import numpy as np
import tensorflow as tf
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import SimpleRNN, Dense

# 입력: [[0], [1], [2], [3], [4], [5], [6], [7], [8]]
# 출력: [[1], [2], [3], [4], [5], [6], [7], [8], [9]]

# 입력 데이터 (samples, time steps, features)
X = np.array([[[i]] for i in range(9)])
# 출력 데이터 (samples, features)
y = np.array([[i + 1] for i in range(9)])

# RNN 모델 구성
model = Sequential()
model.add(SimpleRNN(10, input_shape=(1, 1)))
model.add(Dense(1))

# 모델 컴파일
model.compile(optimizer='adam', loss='mse')

# 모델 훈련
model.fit(X, y, epochs=200, verbose=0)

# 예측
predictions = model.predict(X)

# 결과 출력
for i in range(len(predictions)):
    print(f'입력: {i} => 예측 출력: {predictions[i][0]:.2f}')<br>
```
{% endraw %}