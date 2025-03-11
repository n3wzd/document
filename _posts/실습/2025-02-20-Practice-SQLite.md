---
categories:
- Practice
date: '2025-02-20'
title: '[Practice] SQLite'
---

{% raw %}
### 자동 INTEGER 변환
`2025-02-17` → `2006`  
`2025-02-18` → `2005`  
`2025-02-19` → `2004`

이런 변환이 일어나는 이유는 SQLite가 `TEXT` 타입을 자동으로 숫자로 변환하면서 연산을 수행하기 때문입니다.
{% endraw %}