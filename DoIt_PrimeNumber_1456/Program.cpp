#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long N, M;
    int cnt = 0;
    cin >> N >> M;

    vector<long> A(10000001);

    for (int i = 2; i < 10000001; i++) {
        A[i] = i;
    }
    for (int i = 2; i <= sqrt(10000001); i++) {
        //0 제외
        if (A[i] == 0) {
            continue;
        }
        // 배수 제외시키기
        for (int j = i + i; j < 10000001; j = j + i) {
            A[j] = 0;
        }
    }
    for (int i = 2; i < 10000001; i++) {
        if (A[i] == 0) {
            continue;
        }
        long temp = A[i];
        while ((double)A[i] <= (double)M / (double)temp) {
            if ((double)A[i] >= (double)N / (double)temp) {
                cnt++;
            }
            temp = temp * A[i];
        }
    }
    cout << cnt << "\n";
}