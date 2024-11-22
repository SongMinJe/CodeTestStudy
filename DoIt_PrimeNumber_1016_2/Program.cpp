#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

static vector<bool> prime;

static void isPrime(long min, long max) {
	// 에라스토테네스의 체
	for (long i = 2; i <= sqrt(max); i++) {
		// 제곱수 제외용 변수
		long temp = i * i;
		// 제곱수가 min~max 범위 내에 있을 경우도 제외
		if (temp >= min && temp <= max) {
			// 제곱수 제외
			prime[temp - min] = true;
		}
		// 제곱수 제외용 최소값 지정 // 시간초과 대비용
		// 나누어 떨어지지 않으면 1을 더하여 최소값의 범위를 올린다.
		long sMin = min % temp == 0 ? min / temp : (min / temp) + 1;
		// 제곱수 제외 반복문
		// 최소값 지정 때 temp를 나눴으니 비교시에는 다시 temp를 곱해준다.
		for (long j = sMin; j * temp <= max; j++) {
			// 제곱수 제외
			// 실제의 인덱스와 min~max 범위의 괴리로 인하여 min만큼 빼준 값을 idx로 삼는다.
			prime[(j * temp) - min] = true;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long min, max;
	cin >> min >> max;
	long count = 0;
	prime.resize(max - min + 1, false);

	isPrime(min, max);

	for (long i = 0; i <= max - min; i++) {
		if (prime[i] == false) {
			count++;
		}
	}

	cout << count << "\n";
}