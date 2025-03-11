---
categories:
- Practice
date: '2025-01-23'
title: '[Practice] MySQL'
---

{% raw %}
### Error Code: 1506. Foreign keys are not yet supported in conjunction with partitioning
MySQL에서는 파티셔닝(Partitioning) 기능을 사용할 때 외래 키(Foreign Key)를 지원하지 않습니다. 외래 키는 테이블 전체를 검사해야 하지만, 파티셔닝은 특정 파티션만 조회하도록 내부적으로 설계되었기 때문입니다.

외래 키, 파티셔닝 둘 중 하나를 제거해야 합니다.

### CURRENT_DATE/CURDATE()가 기본 DATE 값으로 작동하지 않습니다
`(CURRENT_DATE)`같이 괄호로 감싸줍니다.

출처:
- https://stackoverflow.com/questions/20461030/current-date-curdate-not-working-as-default-date-value

### CSV 파일 추가
1. 좌측 `Navigator`에서 테이블을 우클릭하고 `Table Data Import Wizard`를 선택합니다.
2. csv 파일을 선택합니다.
{% endraw %}