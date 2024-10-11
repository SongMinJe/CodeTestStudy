#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> A(N, 0);
    vector<int> S(N, 0);

    int result = 0;


    for (int i = 0; i < A.size(); i++) {
        cin >> A[i];
    }
    for (int i = 0; i < N; i++) {
        int point = i;
        int value = A[i];
        for (int j = i - 1; j >= 0; j--) {
            if (A[j] < A[i]) {
                point = j + 1;
                break;
            }
            if (j == 0) {
                point = 0;
            }
        }
        for (int j = i; j > point; j--) {
            A[j] = A[j - 1];
        }
        A[point] = value;
    }
    S[0] = A[0];
    for (int i = 0; i < N; i++) {
        if (i > 0) {
            S[i] = S[i - 1] + A[i];
        }
        result += S[i];
    }

    cout << result << "\n";
}