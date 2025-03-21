---
categories:
- AI
date: '2024-05-15'
title: '[AI] Perceptron'
---

{% raw %}
## 단일 레이어 퍼셉트론 (Single-Layer Perceptron)
단일 레이어 퍼셉트론은 인공 신경망의 가장 기본적인 형태 중 하나로, 인공 뉴런의 개념을 기반으로 한 간단한 모델입니다. 단일 레이어 퍼셉트론은 입력값을 받아들이고, 가중치를 적용한 후, 활성화 함수를 통해 출력을 생성하는 단일 층으로 구성된 신경망입니다.

1. **입력층(Input Layer)**: 입력 값을 받는 뉴런들이 위치한 층입니다. 각 입력 뉴런은 하나의 특성을 나타냅니다.
2. **출력층(Output Layer)**: 입력 값을 처리하여 최종 출력을 생성하는 뉴런이 위치한 층입니다.

### 퍼셉트론 학습 규칙 (Perceptron Learning Rule)
퍼셉트론 학습 규칙(Perceptron Learning Rule)은 단일 레이어 퍼셉트론을 학습시키기 위해 사용하는 간단하고 직관적인 방법입니다.

퍼셉트론 학습 규칙은 다음과 같습니다:
1. **가중치 초기화**:
	- 가중치와 편향은 보통 작은 무작위 값으로 초기화됩니다.
2. **순전파(Forward Propagation)**:
   - 입력 벡터를 받아 가중합을 계산합니다.
   - 활성화 함수를 적용하여 출력을 계산합니다.
3. **손실 계산(Loss Calculation)**:
   - 손실 함수를 사용하여 예측값과 실제값 사이의 손실을 계산합니다.
4. **가중치 업데이트(Weight Update)**:
   - 계산된 손실을 기반으로 가중치와 편향을 조정합니다.
   - 하이퍼파라미터인 학습률을 사용하여 업데이트 속도를 조절할 수 있습니다.
5. **반복**:
   - 모든 훈련 데이터에 대해 위 과정을 반복합니다.
   - 전체 데이터셋에 대해 손실이 0이 되거나 설정된 반복 횟수에 도달할 때까지 학습을 계속합니다.

퍼셉트론 학습 규칙은 단순한 문제를 해결하는 데 유용하지만, XOR 문제와 같이 선형 분리 불가능한 문제는 해결할 수 없습니다.

## 다중 레이어 퍼셉트론 (Multilayer Perceptron, MLP)
다중 레이어 퍼셉트론은 인공 신경망의 한 형태로, 입력층과 출력층 사이에 하나 이상의 은닉층(hidden layer)을 포함하는 신경망입니다. MLP는 비선형 문제를 해결할 수 있으며, 더 복잡한 패턴과 관계를 학습하는 데 사용됩니다. MLP는 이미지 인식, 자연어 처리, 회귀 문제 등 다양한 분야에서 활용됩니다.

1. **입력층(Input Layer)**: 입력 값을 받는 뉴런들이 위치한 층입니다. 각 입력 뉴런은 하나의 특성을 나타냅니다.
2. **은닉층(Hidden Layer)**: 입력층과 출력층 사이에 위치한 하나 이상의 층입니다. 은닉층의 뉴런들은 가중치와 편향을 통해 연결되어 있으며, 활성화 함수를 사용하여 비선형성을 추가합니다.
3. **출력층(Output Layer)**: 입력 값을 처리하여 최종 출력을 생성하는 뉴런이 위치한 층입니다.

MLP의 동작 과정은 다음과 같습니다:

1. **가중치 초기화**:
	- 가중치와 편향은 보통 작은 무작위 값으로 초기화됩니다.
2. **순전파(Forward Propagation)**:
	- 입력 데이터가 입력층에서 시작하여 은닉층을 거쳐 출력층까지 전달됩니다.
	- 각 뉴런은 가중합과 활성화 함수를 통해 출력값을 계산합니다.
3. **손실 계산(Loss Calculation)**:
	- 손실 함수를 사용하여 예측값과 실제값 사이의 손실을 계산합니다.
4. **역전파(Backpropagation)**:
	- 출력층에서부터 시작하여 오차를 거꾸로 전파하여 각 층의 가중치와 편향에 대한 손실 함수의 기울기를 계산합니다.
	- 각 층의 기울기는 오차와 활성화 함수의 미분값을 곱하여 계산됩니다.
5. **가중치 업데이트(Weight Update)**:
	- 현재 값의 기울기를 통해 손실 함수를 최소화하는 방향으로 각 가중치와 편향을 업데이트합니다.
	- 하이퍼파라미터인 학습률을 사용하여 업데이트 속도를 조절할 수 있습니다.
6. **반복**:
	- 모든 훈련 데이터에 대해 위 과정을 반복합니다.
	- 전체 데이터셋에 대해 손실이 0이 되거나 설정된 반복 횟수에 도달할 때까지 학습을 계속합니다.

### 경사 하강법 (Gradient Descent)
경사 하강법(Gradient Descent)은 함수의 최솟값을 찾는 최적화 알고리즘 중 하나로, 기울기(경사)를 따라 함수의 값을 조금씩 조정하여 최솟값에 수렴하는 방법입니다. 주로 역전파의 가중치 업데이트 과정에서 사용됩니다.

경사 하강법의 기본 아이디어는 다음과 같습니다:
1. **시작점 선택**:
   - 최적화하려는 함수의 시작점을 임의로 선택합니다.
2. **경사 계산**:
   - 선택한 지점에서 함수의 기울기를 계산합니다.
3. **이동**:
   - 현재 위치에서 기울기가 감소하는(함수의 값이 감소하는) 방향으로 이동합니다.
4. **반복**:
   - 새로운 위치에서 위 과정을 반복합니다. 일정한 조건(예: 일정한 반복 횟수 또는 함수 값의 변화량)이 충족될 때까지 이 과정을 반복합니다.
{% endraw %}