#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

static vector<bool> prime;

static void isPrime(long min, long max) {
    for (long i = 2; i <= sqrt(max); i++) {
        long pow = i * i;
        if (pow >= min && pow <= max) {
            prime[pow - min] = true;
        }
        long sMin = min % pow == 0 ? min / pow : min / pow + 1;
        for (long j = sMin; j * pow <= max; j++) {
            prime[j * pow - min] = true;
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