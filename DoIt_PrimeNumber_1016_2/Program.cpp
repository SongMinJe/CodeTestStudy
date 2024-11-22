#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

static vector<bool> prime;

static void isPrime(long min, long max) {
	// �������׳׽��� ü
	for (long i = 2; i <= sqrt(max); i++) {
		// ������ ���ܿ� ����
		long temp = i * i;
		// �������� min~max ���� ���� ���� ��쵵 ����
		if (temp >= min && temp <= max) {
			// ������ ����
			prime[temp - min] = true;
		}
		// ������ ���ܿ� �ּҰ� ���� // �ð��ʰ� ����
		// ������ �������� ������ 1�� ���Ͽ� �ּҰ��� ������ �ø���.
		long sMin = min % temp == 0 ? min / temp : (min / temp) + 1;
		// ������ ���� �ݺ���
		// �ּҰ� ���� �� temp�� �������� �񱳽ÿ��� �ٽ� temp�� �����ش�.
		for (long j = sMin; j * temp <= max; j++) {
			// ������ ����
			// ������ �ε����� min~max ������ ������ ���Ͽ� min��ŭ ���� ���� idx�� ��´�.
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