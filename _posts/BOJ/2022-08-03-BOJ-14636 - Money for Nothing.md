---
categories:
- BOJ
date: '2022-08-03'
title: '[BOJ] 14636 - Money for Nothing'
---

{% raw %}
> 다이아몬드 IV<br>

## 문제
In this problem you will be solving one of the most profound challenges of humans across the world since the beginning of time – how to make lots of money.

You are a middleman in the widget market. Your job is to buy widgets from widget producer companies and sell them to widget consumer companies. Each widget consumer company has an open request for one widget per day, until some end date, and a price at which it is willing to buy the widgets. On the other hand, each widget producer company has a start date at which it can start delivering widgets and a price at which it will deliver each widget.

Due to fair competition laws, you can sign a contract with only one producer company and only one consumer company. You will buy widgets from the producer company, one per day, starting on the day it can start delivering, and ending on the date specified by the consumer company. On each of those days you earn the difference between the producer’s selling price and the consumer’s buying price.

Your goal is to choose the consumer company and the producer company that will maximize your profits.

### 입력
The first line of input contains two integers m and n (1 ≤ m, n ≤ 500 000) denoting the number of producer and consumer companies in the market, respectively. It is followed by m lines, the i th of which contains two integers pi  and di  (1 ≤ pi, di  ≤ 10<sup>9</sup>), the price (in dollars) at which the i th producer sells one widget and the day on which the first widget will be available from this company. Then follow n lines, the j th of which contains two integers qj  and ej  (1 ≤ qj, ej  ≤ 10<sup>9</sup>), the price (in dollars) at which the j th consumer is willing to buy widgets and the day immediately after the day on which the last widget has to be delivered to this company.

### 출력
Display the maximum total number of dollars you can earn. If there is no way to sign contracts that gives you any profit, display 0.

## 해결
공급자는 특정 날짜부터 구매가 가능하고 소비자는 특정 날짜까지 판매가 가능하다. 공급자와 소비자는 각각 하나만 선택할 수 있으며, 얻을 수 있는 이익은 두 날짜의 차에서 팔고 남은 금액의 곱이다.

최대 이익을 구하는 수식을 정리하면, (C[i].date > P[j].date)
> F[i, j] = max((C[i].date - P[j].date) × (C[i].price - P[j].price))<br>

모든 i, j 조합을 조사하면 최대 이익을 알 수 있다. 하지만 O(N<sup>2</sup>) 시간이 걸리니 다른 방법을 찾아보자.

먼저 항상 답이 될 수 없는 공급자, 소비자가 존재한다. 어떤 공급자 P[j]가 있을 때 P[j]보다 판매 시작 일자가 더 뒤에 있고 가격도 비싼 공급자는 항상 P[j]보다 손해인 것이 확실하다. 이러한 논리는 소비자에게도 적용할 수 있으며, 상대적으로 덜 효율적인 공급자/소비자를 답의 후보에서 제외하면 된다.
```
> 공급자<br>
1. 날짜 순서대로 정렬
2. 이전 공급자보다 가격이 낮은 공급자만 목록에 추가

> 소비자<br>
3. 가격 순서대로 정렬
4. 이전 소비자보다 날짜가 뒤에 있는 소비자만 목록에 추가
```

그 이후는 `분할정복 최적화`을 적용해서 O(N log N)으로 단축할 수 있다. 어떤 소비자 C[i<sub>1</sub>]를 선택했을 때 최적의 공급자를 P[j<sub>1</sub>]이라고 하자. C[i<sub>1</sub>]보다 구매 종료 일자가 더 이른 소비자 C[i<sub>2</sub>]의 최적의 공급자가 P[j<sub>2</sub>]라면, P[j<sub>2</sub>]의 판매 시작 일자는 항상 P[j<sub>1</sub>]의 판매 시작 일자보다 적다. 따라서 분할정복 최적화를 적용할 수 있다.

i가 고정일 때, j는 다음 조건으로 구할 수 있다.
> 1. F[i, j]가 최대일 때<br>
> 2. P[j].date < C[i].date<br>

※ 전체 최댓값의 초기 값은 0이지만, 각 분할 단계에서 최댓값의 초기 값은 충분히 작은 음수여야 한다. 유통 과정에서 모두 손해를 보는 경우에도 최적의 값은 존재하기 때문.

## 코드
```
#include <iostream>
#include <algorithm>
#include <vector>
typedef long long ll;
using namespace std;
struct Company { ll p, d; };
const int SIZE = 5e5 + 2;
int N, M; ll res = 0;
Company P[SIZE], C[SIZE];
vector<Company> PS, CS;
ll F(ll i, ll j) { return (CS[i].d - PS[j].d) * (CS[i].p - PS[j].p); }
bool cmp(Company a, Company b) { return a.d < b.d; }

void DC(ll lo, ll hi, ll lo2, ll hi2) {
	if (lo > hi)
		return;
	ll i = (lo + hi) / 2;
	ll v = -2e18, v_idx = lo2;

	for (int j = lo2; j <= hi2; j++) {
		if (PS[j].d >= CS[i].d) break;
		if (F(i, j) >= v) {
			v = F(i, j);
			v_idx = j;
		}
	}
	res = max(res, v);

	DC(lo, i - 1, lo2, v_idx);
	DC(i + 1, hi, v_idx, hi2);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> M >> N;
	for (int i = 0; i < M; i++)
		cin >> P[i].p >> P[i].d;
	for (int i = 0; i < N; i++)
		cin >> C[i].p >> C[i].d;
	sort(P, P + M, cmp);
	sort(C, C + N, cmp);

	PS.push_back(P[0]); CS.push_back(C[0]);
	for (int i = 1; i < M; i++)
		if (PS.back().p > P[i].p)
			PS.push_back(P[i]);
	for (int i = 1; i < N; i++) {
		while (!CS.empty() && CS.back().p <= C[i].p)
			CS.pop_back();
		CS.push_back(C[i]);
	}

	DC(0, CS.size() - 1, 0, PS.size() - 1);
	cout << res;
	return 0;
}
```

## 링크
<br>https://www.acmicpc.net/problem/14636
{% endraw %}