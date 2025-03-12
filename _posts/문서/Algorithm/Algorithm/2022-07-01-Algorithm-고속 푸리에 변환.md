---
categories:
- Algorithm
date: '2022-07-01'
title: '[Algorithm] 고속 푸리에 변환'
---

{% raw %}
## 푸리에 변환 (Fourier Transformation)
푸리에 변환은 시간에 대한 함수를 주파수에 대한 함수로 바꾸는 변환이다.

이산 푸리에 변환(Discrete Fourier transform)은 이산적인 수열에서 적용되는 푸리에 변환이다. 이산 푸리에 변환 수식은 다음과 같이 정의된다.

$$
X_{k}=\sum _{n=0}<sup>{N-1}x_{n}e</sup>{-{\frac {2\pi i}{N}}kn},k=0,\cdots ,N-1
$$

푸리에 역변환은 주파수에 대한 함수를 시간에 대한 함수로 바꾸는 변환으로, 역변환을 하면 다시 원래 함수로 바꿀 수 있다. 이산 푸리에 역변환(Inverse Discrete Fourier Transform)은 다음과 같이 정의된다.
$$
x_{n}={\frac {1}{N}}\sum _{k=0}<sup>{N-1}X_{k}e</sup>{{\frac {2\pi i}{N}}kn},n=0,\cdots ,N-1
$$

역변환은 e의 부호하고 수열에 1 / N의 곱이 있는 것만 제외하면 정변환과 같다.

## 고속 푸리에 변환 (FFT, Fast Fourier Transformation)
이산 푸리에 변환을 프로그램으로 구현해보자. 일반적인 푸리에 변환은 O(N<sup>2</sup>) 시간이 걸리지만 `고속 푸리에 변환 (FFT)`을 사용하면 O(N log N) 시간으로 푸리에 변환을 할 수 있다.

## 설계
FFT에서 가장 자주 활용되는 `Cooley-Tukey 알고리즘`을 사용하자.

사용하기 전에, 수열의 길이는 2의 거듭제곱이어야 한다. 만약 2의 거듭제곱이 아니면 길이가 2의 거듭제곱이 될 때까지 뒤쪽 수열에 0을 채워주자. (ex. 현재 길이가 12면 뒤쪽에 0을 4개 추가) 처음부터 수열의 크기를 2<sup>d</sup> 단위로 설정하는 방법도 있다.

이제 A[n]를 푸리에 변환해보자.  `분할 정복 알고리즘`을 적용해서 수열을 홀수 인덱스, 짝수 인덱스 기준으로 2개의 부분 문제로 분할한다.
```
> FFT(A)<br>
A[N] = 입력 수열
A0[N / 2] = A의 홀수 항 저장
A1[N / 2] = A의 짝수 항 저장

> 문제 분할<br>
FFT(A0)
FFT(A1)
```

그리고 w[n, k]를 아래와 같이 정의하자.

$w[n, k] = e^{{\frac {2\pi i}{N}}kn} ,k=0,\cdots ,N-1$

w[n, k]는 오일러 공식(Euler's formula)을 적용해서 삼각함수로 표현할 수 있다.

$e^{xi}=cos⁡x+isin⁡x$
```
> 현재 인덱스가 n일 때,<br>
p = 2 * PI * n / N
w[n] = complex<double>(cos(p), sin(p))
```

마지막으로 다음과 같이 부분 문제를 취합한다.
```
> 현재 인덱스가 n일 때,<br>
A[n] = A0[n] + (w[n] * A1[n])
A[n + N / 2] = A0[n] - (w[n] * A1[n])
```
이 과정을 마치면 A[i]는 푸리에 변환이 완료되었다. 

역변환 구현은 역변환 공식을 그대로 적용하면 된다. 즉, 정변환에서 p에 -1을 곱하고, A[n]에 1 / N를 곱하면 된다.

### 재귀 함수 구현
C++에서 복소수 표현은 복소수를 관리하는 템플릿인 `complex<double>`을 사용한다. 또한 삼각함수(sin, cos)가 필요한데, 이들은 `cmath` 라이브러리에서 가져오면 된다.
```
typedef complex<double> cd
void FFT(vector<cd>& A, bool inv) {
	int n = A.size();
	if (n == 1)
		return;

	vector<cd> A0(n / 2), A1(n / 2);
	for (int i = 0; i < n / 2; i++) {
		A0[i] = A[i * 2];
		A1[i] = A[i * 2 + 1];
	}
	FFT(A0, inv);
	FFT(A1, inv);

	vector<cd> w(n);
	for (int i = 0; i < n; i++) {
		double p = 2 * PI * i / n * (inv ? -1 : 1);
		w[i] = cd(cos(p), sin(p));
	}

	for (int i = 0; i < n / 2; i++) {
		A[i] = A0[i] + w[i] * A1[i];
		A[i + n / 2] = A0[i] - w[i] * A1[i];
	}
	if(inv)
		for (int i = 0; i < n; i++)
			A[i] /= 2;
}
```
※ 푸리에 변환에선 실수가 사용되므로 부동소수점 오차 문제를 피할 수 없다. 그래도 반올림(round)을 해서 사용하면 일반적인 문제를 해결하는데는 문제가 없으니 크게 신경쓰지 않아도 된다.

### 반복문 구현
재귀 함수가 아닌 반복문으로 구현하는 방법도 있다. 다소 복잡하지만 계산 시간이 2배 정도 향상되며, 메모리가 절약된다는 이점이 있다.

간단히 요약하면, 현재 수열을 최소 단위의 하위 문제처럼 위치를 정렬하고 반복문으로 부분 문제들을 정복한다. 전체적인 동작 방식은 분할 정복하고 크게 다르지 않다.

예를 들어 A[8]이 있을 때는 문제가 다음과 같이 분할된다. (홀수/짝수 위치에 따라 분할)
```
 0  1  2  3   4  5  6  7
 
 0  2  4  6 | 1  3  5  7
 
0  4 | 2  6 | 1  5 | 3  7
```
따라서 A[0], A[4], A[2], A[6], A[1], A[5], A[3], A[7] 순서대로 정렬하면 이웃한 문제끼리 연산을 할 수 있다.

여기서 인덱스를 비트 단위로 표현하면,
```
정렬 이전 → 정렬 이후
0(000)     0(000)
1(001)     4(100)
2(010)     2(010)
3(011)     6(110)
4(100)     1(001)
5(101)     5(101)
6(110)     3(011)
7(111)     7(111)
```
2진수를 중심 기준으로 대칭한 값이 정렬 이후의 값임을 알 수 있다. 이 성질을 이용해서 정렬을 구현하면 된다.
```
void FFT(vector<cd>& A, bool inv) {
	// 문제 정렬
	int n = A.size();
	for (int k = 0; k < n; k++) {
		int i = 0, lo = 1, hi = n >> 1;
		for (; lo < hi; lo <<= 1, hi >>= 1) {
			if (k & hi) i += lo;
			if (k & lo) i += hi;
		}
		if (lo == hi && (k & hi))
			i += lo;
		if (k < i)
			swap(A[k], A[i]);
	}

	// 문제 정복
	for (int size = 2; size <= n; size *= 2) {
		double x = 2 * PI / size * (inv ? -1 : 1);
		cd w0 = cd(cos(x), sin(x));
		for (int i = 0; i < n; i += size) {
			cd w = cd(1, 0);
			for (int j = 0; j < size / 2; j++) {
				cd tmp = A[(size / 2) + i + j] * w;
				A[(size / 2) + i + j] = A[i + j] - tmp;
				A[i + j] += tmp;
				w *= w0;
			}
		}
	}
	if (inv)
		for (int i = 0; i < n; i++)
			A[i] /= n;
}
```

## 다항식 곱하기
다항식은 차수를 인덱스, 계수를 값으로 하는 벡터로 표현된다.

2x<sup>0</sup> + 5x<sup>1</sup> + 2x<sup>3</sup> + 6x<sup>5</sup>
→ [2, 5, 0, 2, 0 6]

두 다항식 A, B를 곱해보자. 나이브하게 벡터끼리 곱하는 방법은 O(N<sup>2</sup>) 시간이 걸린다. 하지만 `고속 푸리에 변환`을 적용하면 O(N log N)으로 시간을 단축할 수 있다.

푸리에 변환으로 변환된 다항식의 곱은 다음이 성립함이 알려져 있다. (DFT(A)는 A를 이산 푸리에 변환한 것을 의미한다)
> DFT(A × B) = DFT(A) × DFT(B)<br>

즉, 다항식 2개를 푸리에 변환하고 곱한 결과를 역변환하면 된다.
```
void MUL(vector<cd>& A, vector<cd>& B, vector<cd>& C) {
	FFT(A, 0);
	FFT(B, 0);
	for (int i = 0; i < A.size(); i++)
		C[i] = A[i] * B[i];
	FFT(C, 1);
}
```

### 활용
다항식 곱하기의 대표적인 용도로 서로 다른 집합에 있는 두 수의 합으로 특정 수를 만들 수 있는 경우의 수를 세는 문제가 있다.

아래와 같이 집합 A, B가 주어졌을 때, A, B의 원소의 합으로 G의 원소를 만들 수 있는 경우의 수를 계산해보자.
```
A = [0, 1, 2]
B = [0, 1, 2]
G = [2, 4, 5]
```

A, B를 다항식으로 표현하면 다음과 같다. (원소를 차수로 하고 계수는 모두 1로 한다)
> A = x<sup>0</sup> + x<sup>1</sup> + x<sup>2</sup><br>
> B = x<sup>0</sup> + x<sup>1</sup> + x<sup>2</sup><br>

두 다항식을 곱하면,
> 1x<sup>0</sup> + 2x<sup>1</sup> + 3x<sup>2</sup> + 2x<sup>3</sup> + 1x<sup>4</sup><br>

수의 곱은 지수에선 합이므로 곱한 다항식의 차수는 A, B의 원소의 합이라고 볼 수 있다. 따라서 G의 원소와 같은 차수의 계수를 모두 합하면 된다. 예시에선 3 + 1이 답이다.

## 코드
`BOJ - 10531 - Golf Bot` 코드
```
#include <iostream>
#include <vector>
#include <cmath>
#include <complex>
#define PI 3.14159265358979323846
using namespace std;
typedef complex<double> cd;
const int SIZE = 1 << 19;

void FFT(vector<cd>& A, bool inv) {
	int n = A.size();
	for (int k = 0; k < n; k++) {
		int i = 0, lo = 1, hi = n >> 1;
		for (; lo < hi; lo <<= 1, hi >>= 1) {
			if (k & hi) i += lo;
			if (k & lo) i += hi;
		}
		if (lo == hi && (k & hi))
			i += lo;
		if (k < i)
			swap(A[k], A[i]);
	}

	for (int size = 2; size <= n; size *= 2) {
		double x = 2 * PI / size * (inv ? -1 : 1);
		cd w0 = cd(cos(x), sin(x));
		for (int i = 0; i < n; i += size) {
			cd w = cd(1, 0);
			for (int j = 0; j < size / 2; j++) {
				cd tmp = A[(size / 2) + i + j] * w;
				A[(size / 2) + i + j] = A[i + j] - tmp;
				A[i + j] += tmp;
				w *= w0;
			}
		}
	}
	if (inv)
		for (int i = 0; i < n; i++)
			A[i] /= n;
}

void MUL(vector<cd>& A, vector<cd>& B, vector<cd>& C) {
	FFT(A, 0);
	FFT(B, 0);
	for (int i = 0; i < A.size(); i++)
		C[i] = A[i] * B[i];
	FFT(C, 1);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, M, d, cnt = 0;
	vector<cd> A(SIZE), B(SIZE), C(SIZE);
	vector<int> goal;
	cin >> N;
	A[0] = B[0] = cd(1, 0);
	for (int i = 0; i < N; i++) {
		cin >> d;
		A[d] = B[d] = cd(1, 0);
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> d;
		goal.push_back(d);
	}

	MUL(A, B, C);
	for (int i = 0; i < goal.size(); i++)
		if (round(C[goal[i]].real()) != 0)
			cnt++;
	cout << cnt;
	return 0;
}
```

## 연관 문제
<br>https://www.acmicpc.net/problem/10531
<br>https://www.acmicpc.net/problem/1067
<br>https://www.acmicpc.net/problem/20176

## 참고
<br>https://aruz.tistory.com/1
<br>https://www.geeksforgeeks.org/fast-fourier-transformation-poynomial-multiplication/?ref=gcse
<br>https://ohgym.tistory.com/16
<br>https://seastar105.tistory.com/14
<br>https://ko.wikipedia.org/wiki/%EC%9D%B4%EC%82%B0_%ED%91%B8%EB%A6%AC%EC%97%90_%EB%B3%80%ED%99%98
{% endraw %}