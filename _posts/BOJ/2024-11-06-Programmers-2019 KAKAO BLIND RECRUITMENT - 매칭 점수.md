---
categories:
- Programmers
date: '2024-11-06'
title: '[Programmers] 2019 KAKAO BLIND RECRUITMENT - 매칭 점수'
---

{% raw %}
> Lv. 3<br>

## 문제
프렌즈 대학교 조교였던 제이지는 허드렛일만 시키는 네오 학과장님의 마수에서 벗어나, 카카오에 입사하게 되었다.  
평소에 관심있어하던 검색에 마침 결원이 발생하여, 검색개발팀에 편입될 수 있었고, 대망의 첫 프로젝트를 맡게 되었다.  
그 프로젝트는 검색어에 가장 잘 맞는 웹페이지를 보여주기 위해 아래와 같은 규칙으로 검색어에 대한 웹페이지의 매칭점수를 계산 하는 것이었다.

-   한 웹페이지에 대해서 기본점수, 외부 링크 수, 링크점수, 그리고 매칭점수를 구할 수 있다.
-   한 웹페이지의 기본점수는 해당 웹페이지의 텍스트 중, 검색어가 등장하는 횟수이다. (대소문자 무시)
-   한 웹페이지의 외부 링크 수는 해당 웹페이지에서 다른 외부 페이지로 연결된 링크의 개수이다.
-   한 웹페이지의 링크점수는 해당 웹페이지로 링크가 걸린 다른 웹페이지의 기본점수 ÷ 외부 링크 수의 총합이다.
-   한 웹페이지의 매칭점수는 기본점수와 링크점수의 합으로 계산한다.

검색어 word와 웹페이지의 HTML 목록인 pages가 주어졌을 때, 매칭점수가 가장 높은 웹페이지의 index를 구하라. 만약 그런 웹페이지가 여러 개라면 그중 번호가 가장 작은 것을 구하라.

### 제한사항
-   pages는 HTML 형식의 웹페이지가 문자열 형태로 들어있는 배열이고, 길이는  `1`  이상  `20`  이하이다.
-   한 웹페이지 문자열의 길이는  `1`  이상  `1,500`  이하이다.
-   웹페이지의 index는 pages 배열의 index와 같으며 0부터 시작한다.
-   한 웹페이지의 url은 HTML의 태그 내에  태그의 값으로 주어진다.
    -   예를들어, 아래와 같은 meta tag가 있으면 이 웹페이지의 url은  `<br>https://careers.kakao.com/index`  이다.
    -   `<meta property="og:url" content="<br>https://careers.kakao.com/index" />`
-   한 웹페이지에서 모든 외부 링크는  `<a href="<br>https://careers.kakao.com/index">`의 형태를 가진다.
    -   `<a>`  내에 다른 attribute가 주어지는 경우는 없으며 항상 href로 연결할 사이트의 url만 포함된다.
    -   위의 경우에서 해당 웹페이지는  `<br>https://careers.kakao.com/index`  로 외부링크를 가지고 있다고 볼 수 있다.
-   모든 url은  `<br>https://`  로만 시작한다.
-   검색어 word는 하나의 영어 단어로만 주어지며 알파벳 소문자와 대문자로만 이루어져 있다.
-   word의 길이는  `1`  이상  `12`  이하이다.
-   검색어를 찾을 때, 대소문자 구분은 무시하고 찾는다.
    -   예를들어 검색어가 blind일 때, HTML 내에 Blind라는 단어가 있거나, BLIND라는 단어가 있으면 두 경우 모두 해당된다.
-   검색어는 단어 단위로 비교하며, 단어와 완전히 일치하는 경우에만 기본 점수에 반영한다.
    -   단어는 알파벳을 제외한 다른 모든 문자로 구분한다.
    -   예를들어 검색어가 "aba" 일 때, "abab abababa"는 단어 단위로 일치하는게 없으니, 기본 점수는 0점이 된다.
    -   만약 검색어가 "aba" 라면, "aba@aba aba"는 단어 단위로 세개가 일치하므로, 기본 점수는 3점이다.
-   결과를 돌려줄때, 동일한 매칭점수를 가진 웹페이지가 여러 개라면 그중 index 번호가 가장 작은 것를 리턴한다
    -   즉, 웹페이지가 세개이고, 각각 매칭점수가 3,1,3 이라면 제일 적은 index 번호인 0을 리턴하면 된다.

## 해결
입력이 html 텍스트로 주어지며, 이 텍스트를 파싱해야 합니다. `정규 표현식`을 사용하며, 탐색 범위는 페이지 전체입니다.
- 페이지 주소는 항상 `<meta property="og:url" content="(주소)" />` 구조로 주어집니다.
- 외부 링크는 항상 `<a href="(주소)"/>` 구조로 주어집니다.
- 단어는 알파벳이 아닌 문자로 구분됩니다. 먼저 정규 표현식으로 조건 상관없이 일치하는 패턴을 모두 찾은 뒤, 찾은 패턴의 앞 뒤 모두 알파벳이 존재하지 않는지를 판정하면 됩니다.
- 문자열을 인덱싱하므로 `맵`을 사용합니다.

페이지별 주소, 외부 링크 목록, 단어 개수를 찾았다면 점수를 구할 수 있습니다.
> 기본 점수 = 현 페이지에서 매칭된 단어 수<br>
> 링크 점수 = 현 페이지를 참조하는 외부 페이지를 X라 했을 때, (X의 기본 점수 / X의 외부 링크 개수) 총합<br>

점수는 실수이므로 `double` 자료형을 사용합니다.

## 코드
```
#include <string>
#include <vector>
#include <regex>
#include <map>
#include <cctype>
using namespace std;
int N; double wordScore[20], linkScore[20];
string myLink[20];
vector<string> hyperlink[20];
map<string, int> linkToIdx;

int getMaxScore() {
    double maxScore = -1; int res = 0;
    for (int i = 0; i < N; i++)
        for (auto s : hyperlink[i])
            if(linkToIdx.find(s) != linkToIdx.end())
                linkScore[linkToIdx[s]] += wordScore[i] / hyperlink[i].size();
    for (int i = 0; i < N; i++) {
        double score = wordScore[i] + linkScore[i];
        if (score > maxScore) {
            maxScore = score;
            res = i;
        }
    }
    return res;
}

int solution(string word, vector<string> pages) {
    N = pages.size();
    for (int i = 0; i < N; i++) {
        auto page = pages[i];
        regex pattern1(R"(<a href=\"([^\"]+)\")");
        sregex_iterator iter1(page.begin(), page.end(), pattern1);
        sregex_iterator end;
        while (iter1 != end) {
            hyperlink[i].push_back(iter1->str(1));
            iter1++;
        }

        regex pattern2(R"(<meta\s+[<sup>>]*content=\"([</sup>\"]+)\")");
        sregex_iterator iter2(page.begin(), page.end(), pattern2);
        myLink[i] = iter2->str(1);
        linkToIdx[myLink[i]] = i;

        regex pattern3("(" + word + ")", regex_constants::icase);
        sregex_iterator iter3(page.begin(), page.end(), pattern3);
        while (iter3 != end) {
            int p = iter3->position();
            if(!isalpha(page[p - 1]) && !isalpha(page[p + word.size()]))
                wordScore[i]++;
            iter3++;
        }
    }
    return getMaxScore();
}
```

## 링크
<br>https://school.programmers.co.kr/learn/courses/30/lessons/42893
{% endraw %}