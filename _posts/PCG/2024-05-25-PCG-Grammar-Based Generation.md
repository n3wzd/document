---
categories:
- PCG
date: '2024-05-25'
title: '[PCG] Grammar-Based Generation'
---

{% raw %}
그래머 기반 생성은 규칙 집합(문법)을 사용하여 컨텐츠를 생성하는 방법입니다. 이러한 시스템은 일반적으로 형식 문법(formal grammar)을 이용하여 콘텐츠의 구조를 정의하고, 규칙을 반복적으로 적용하여 최종 결과물을 생성합니다. 이 방법은 언어 생성, 프로시저적 맵 생성, 스토리 생성 등 다양한 분야에서 사용됩니다.

1. **형식 문법(Formal Grammar)**: 
	- 형식 문법은 언어의 문법 규칙을 형식적으로 정의한 것입니다.
	- 예를 들어, 프로덕션 룰(production rule)을 통해 복잡한 구조를 간단한 구성 요소로 분해합니다.
2. **규칙(Production Rules)**:
	- 규칙은 하나의 심볼(symbol)을 다른 심볼의 조합으로 대체하는 방식으로 정의됩니다.
	- 예를 들어, S → A B는 심볼 S를 심볼 A와 B로 대체합니다.
3. **재귀(Recursion)**:
	- 규칙은 재귀적으로 정의될 수 있으며, 이는 복잡한 구조를 생성하는 데 유용합니다.
	- 예를 들어, S → a S b는 무한히 확장될 수 있는 재귀적인 구조를 만듭니다.

다음은 간단한 문법 예제입니다:
1. **문법 정의**:
	- S → NP VP
	- NP → Det N
	- VP → V NP
	- Det → "the" | "a"
	- N → "cat" | "dog"
	- V → "chases" | "sees"
2. **생성 과정**:
	- 시작 심볼(S)에서 시작하여 규칙을 반복적으로 적용합니다.
	- 예: S → NP VP → Det N VP → "the" N VP → "the" "cat" VP → "the" "cat" V NP → "the" "cat" "chases" NP → "the" "cat" "chases" Det N → "the" "cat" "chases" "a" N → "the" "cat" "chases" "a" "dog"

이러한 규칙을 통해 "the cat chases a dog"라는 문장을 생성할 수 있습니다.
{% endraw %}