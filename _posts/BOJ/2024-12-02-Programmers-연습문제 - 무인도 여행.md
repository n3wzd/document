---
categories:
- Programmers
date: '2024-12-02'
title: '[Programmers] 연습문제 - 무인도 여행'
---

{% raw %}
> Lv. 2<br>

## 문제
메리는 여름을 맞아 무인도로 여행을 가기 위해 지도를 보고 있습니다. 지도에는 바다와 무인도들에 대한 정보가 표시돼 있습니다. 지도는 1 x 1크기의 사각형들로 이루어진 직사각형 격자 형태이며, 격자의 각 칸에는 'X' 또는 1에서 9 사이의 자연수가 적혀있습니다. 지도의 'X'는 바다를 나타내며, 숫자는 무인도를 나타냅니다. 이때, 상, 하, 좌, 우로 연결되는 땅들은 하나의 무인도를 이룹니다. 지도의 각 칸에 적힌 숫자는 식량을 나타내는데, 상, 하, 좌, 우로 연결되는 칸에 적힌 숫자를 모두 합한 값은 해당 무인도에서 최대 며칠동안 머물 수 있는지를 나타냅니다. 어떤 섬으로 놀러 갈지 못 정한 메리는 우선 각 섬에서 최대 며칠씩 머물 수 있는지 알아본 후 놀러갈 섬을 결정하려 합니다.

지도를 나타내는 문자열 배열  `maps`가 매개변수로 주어질 때, 각 섬에서 최대 며칠씩 머무를 수 있는지 배열에 오름차순으로 담아 return 하는 solution 함수를 완성해주세요. 만약 지낼 수 있는 무인도가 없다면 -1을 배열에 담아 return 해주세요.

### 제한사항
-   3 ≤  `maps`의 길이 ≤ 100
    -   3 ≤  `maps[i]`의 길이 ≤ 100
    -   `maps[i]`는 'X' 또는 1 과 9 사이의 자연수로 이루어진 문자열입니다.
    -   지도는 직사각형 형태입니다.

## 해결
격자 맵에서 벽으로 구분되는 칸들의 집합을 영역으로 정의했을 때, 각 영역의 합들을 반환하면 됩니다. 영역의 합은 `그래프 탐색`으로 구할 수 있습니다. (현재 칸에서 벽이 아닌 인접한 칸을 다음 정점으로 합니다.)

## 코드
```
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<string> maps;
bool visited[101][101];
int N, M, dx[] = { 1, 0 , -1, 0 }, dy[] = { 0, 1, 0, -1 };

int DFS(int x, int y) {
    visited[y][x] = 1;
    int sum = maps[y][x] - '0';
    for(int d = 0; d < 4; d++) {
        int nx = x + dx[d], ny = y + dy[d];
        if(nx >= 0 && nx < M && ny >= 0 && ny < N && !visited[ny][nx] && maps[ny][nx] != 'X')
            sum += DFS(nx, ny);
    }
    return sum;
}

vector<int> solution(vector<string> mapI) {
    maps = mapI; N = maps.size(), M = maps[0].size();
    vector<int> answer;
    for(int y = 0; y < N; y++)
        for(int x = 0; x < M; x++)
            if(!visited[y][x] && maps[y][x] != 'X')
                answer.push_back(DFS(x, y));
    sort(answer.begin(), answer.end());
    if(answer.empty())
        answer.push_back(-1);
    return answer;
}
```

## 링크
<br>https://school.programmers.co.kr/learn/courses/30/lessons/154540
{% endraw %}