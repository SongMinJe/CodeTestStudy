#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long N, k;
    cin >> N >> k;
    long start = 1;
    long end = k;
    long result = 0;

    while (start <= end) {
        long mid = (start + end) / 2;
        long cnt = 0;

        for (int i = 1; i <= N; i++) {
            cnt += min(mid / i, N);
        }
        if (cnt < k) {
            start = mid + 1;
        }
        else {
            result = mid;
            end = mid - 1;
        }
    }
    cout << result << "\n";
}