---
categories:
- PCG
date: '2024-05-25'
title: '[PCG] Evolutionary Algorithms'
---

{% raw %}
진화적 알고리즘은 생물 진화의 원리를 모방하여 콘텐츠를 생성하는 방법입니다. 이 알고리즘은 자연 선택, 돌연변이, 교배 등의 개념을 사용하여 콘텐츠를 점진적으로 개선합니다. 진화적 알고리즘은 게임 맵, 캐릭터, 퍼즐, 음악 등 다양한 형태의 콘텐츠를 생성하는 데 사용될 수 있습니다.

1. **개체(Individual)**:
	- 생성할 콘텐츠의 한 예를 나타냅니다.
2. **유전자(Genotype)**:
	- 개체의 특성을 코드화한 것입니다.
3. **집단(Population)**:
	- 여러 개체들의 집합으로, 한 세대의 모든 가능성을 포함합니다.
4. **적합도 함수(Fitness Function)**:
	- 개체의 품질을 평가하는 함수입니다.
5. **선택(Selection)**:
	- 적합도가 높은 개체를 선택하여 다음 세대를 형성합니다.
6. **교배(Crossover)**:
	- 두 개체의 유전자를 조합하여 새로운 개체를 생성합니다.
7. **돌연변이(Mutation)**:
	- 유전자의 일부를 무작위로 변경하여 다양성을 추가합니다.

진화적 알고리즘의 동작 과정은 다음과 같습니다:
1. **초기 집단 생성**:
	- 무작위로 초기 집단을 생성합니다.
2. **적합도 평가**:
	- 각 개체에 대해 적합도 함수를 적용하여 품질을 평가합니다.
3. **선택**:
	- 적합도가 높은 개체를 선택합니다. 일반적으로 룰렛 휠 선택, 토너먼트 선택 등이 사용됩니다.
4. **교배 및 돌연변이**:
	- 선택된 개체들 사이에서 교배를 통해 새로운 개체를 생성하고, 일부 개체에 돌연변이를 적용합니다.
5. **세대 교체**:
	- 새로 생성된 개체들로 집단을 교체합니다.
6. **종료 조건 확인**:
	- 일정 세대 수에 도달하거나 적합도가 충분히 높아질 때까지 반복합니다.

아래는 게임 맵 생성을 하는 예제입니다.
1. **유전자 표현**:
   - 게임 맵을 2D 배열로 표현합니다. 각 셀은 타일 유형(예: 벽, 길, 문 등)을 나타냅니다.
2. **적합도 함수**:
   - 맵의 완성도, 플레이어의 이동 가능성, 퍼즐의 난이도 등을 평가합니다.
3. **진화적 과정**:
   - 초기 맵들을 무작위로 생성하고, 적합도에 따라 선별하여 교배 및 돌연변이를 통해 점진적으로 개선합니다.
{% endraw %}