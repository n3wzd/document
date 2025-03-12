---
categories:
- Algorithm
date: '2024-11-04'
title: '[Algorithm] 배열 회전'
---

{% raw %}
2차원 행렬(격자 또는 배열)을 회전해봅시다.

행렬의 회전은 중심을 기준으로 합니다. 제4사분면에서 행렬의 길이가 홀수이며 중심 좌표가 (a, b), 현재 좌표가 (x, y)일 때, 90도 회전한 위치는 다음과 같습니다.
> a - y, b + x (시계 방향)<br>
> a + y, b - x (반시계 방향)<br>

이 함수는 행렬 길이가 홀수일 때만 성립합니다. 만약 행렬 길이가 짝수라면, 행렬의 길이를 홀수 길이로 변환하여 위 연산을 적용한 뒤, 원래 길이로 변환합니다.

## 코드
`rotateAll` 함수는 N x N 크기의 배열 `board`를 90도 반시계 방향 회전시켜 `rotatedBoard`에 저장합니다.
```
void rotate(int x, int y) {
    bool even = N % 2 == 0; int c = even ? N / 2 - 1 : N / 2;
    int dx = x - c + (even && x <= c ? -1 : 0), dy = y - c + (even && y <= c ? -1 : 0);
    int nx = c + dy, ny = c - dx;
    rotatedBoard[ny + (even && ny <= c ? 1 : 0)][nx + (even && nx <= c ? 1 : 0)] = board[y][x];
}

void rotateAll() {
    for (int y = 0; y < N; y++)
        for (int x = 0; x < N; x++)
            rotate(x, y);
}
```

## 연관 문제
https://www.acmicpc.net/problem/20058<br>
https://www.acmicpc.net/problem/21609<br>
https://school.programmers.co.kr/learn/courses/30/lessons/60059<br>
{% endraw %}