---
categories:
- AI
date: '2024-05-24'
title: '[AI] Transformer'
---

{% raw %}
Transformer는 딥러닝 모델 중 하나로, 주로 Attention 메커니즘을 기반으로 합니다. Transformer 모델은 기존의 RNN이나 CNN에 비해 학습이 빠르며, 병렬 처리가 가능하고 긴 시퀀스에 대해 잘 작동합니다. 이러한 특징으로 인해 자연어 처리에서 널리 사용되고 있습니다. (예: BERT, GPT, T5)

1. **Self-Attention 메커니즘**:
	- Transformer 모델은 Self-Attention 메커니즘을 사용하여 입력 시퀀스 내의 각 워드 간의 관계를 파악합니다.
	- Self-Attention 메커니즘은 각 워드의 중요도를 동적으로 계산하여 해당 워드의 문맥을 잘 이해할 수 있습니다.
2. **인코더-디코더 구조**:
	- Transformer 모델은 주로 인코더-디코더 구조를 사용하여 Sequence-to-Sequence 작업을 수행합니다.
	- 인코더는 입력 시퀀스를 임베딩하고, 디코더는 출력 시퀀스를 생성합니다.
3. **Scaled Dot-Product Attention**:
	- Transformer 모델은 Scaled Dot-Product Attention을 사용하여 각 워드 간의 관계를 계산합니다.
	- Scaled Dot-Product Attention은 메모리를 효율적으로 활용하며 병렬로도 연산할 수 있어 효율적인 학습을 가능하게 합니다.
4. **포지션 임베딩(Positional Embedding)**:
	- 포지션 임베딩은 입력 시퀀스 내의 단어의 위치 정보를 임베딩하는 방법입니다.
	- 포지션 임베딩을 사용해 입력 시퀀스의 위치 정보를 고려할 수 있습니다.
{% endraw %}