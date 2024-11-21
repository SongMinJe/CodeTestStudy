#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

static vector<bool> prime;

static void isPrime(long min, long max) {
    // �����ƴ� ������ ���ϱ� ���� for
    for (long i = 2; i <= sqrt(max); i++) {
        // ������
        long temp = i * i;

        // ������ ��ü�� �������� ������ ���
        if (temp >= min && temp <= max) {
            // min ���� ���۵Ǵ� �迭�� �������� ����
            prime[temp - min] = true;
        }

        // ��꿡 �ʿ��� �ּҰ��� ���ϱ�
        long s = min % temp == 0 ? min / temp : (min / temp) + 1;

        // �ּҰ����� ���������� ����� ���� �������� ����
        for (long j = s; j * temp <= max; j++) {
            // min ���� ���۵Ǵ� �迭�� ������� �������� ����
            prime[(j * temp) - min] = true;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long N, M;
    cin >> N >> M;

    prime.resize((M - N) + 1);

    isPrime(N, M);
    int result = 0;

    for (long i = 0; i <= M - N; i++) {
        if (!prime[i])
            result++;
    }

    cout << result << "\n";
}