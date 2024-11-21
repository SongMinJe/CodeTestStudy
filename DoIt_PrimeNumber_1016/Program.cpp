#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

static vector<bool> prime;

static void isPrime(long min, long max) {
    // 제곱아닌 수까지 구하기 위한 for
    for (long i = 2; i <= sqrt(max); i++) {
        // 제곱수
        long temp = i * i;

        // 제곱수 자체가 범위내에 들어오는 경우
        if (temp >= min && temp <= max) {
            // min 부터 시작되는 배열에 제곱수로 저장
            prime[temp - min] = true;
        }

        // 계산에 필요한 최소값을 구하기
        long s = min % temp == 0 ? min / temp : (min / temp) + 1;

        // 최소값부터 제곱값과의 배수의 값을 제곱수로 지정
        for (long j = s; j * temp <= max; j++) {
            // min 부터 시작되는 배열에 배수값을 제곱수로 저장
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