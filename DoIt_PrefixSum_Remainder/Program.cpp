#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N = 0;
    int M = 0;
    long answer = 0;

    cin >> N >> M;

    vector<long> A(N, 0);
    vector<long> S(N + 1, 0);
    vector<long> C(M, 0);

    for (int i = 0; i < N; i++) {
        int temp = 0;
        cin >> temp;
        A[i] = temp;
        S[i + 1] = (S[i] + A[i]) % M;
        if (S[i + 1] == 0) {
            answer++;
        }
        //나머지가 같은 인덱스 갯수
        C[S[i + 1]]++;
    }

    for (int j = 0; j < M; j++) {
        if (C[j] > 1) {
            //조합공식 n = C[j] = 나머지가 같은 인덱스
            //nCr = nCr = n! / (r! * (n-r)!)
            //nC2 = n! / (2! * (n-2)!)
            //n * (n-1) * (n-2)! / (2 * 1 * (n-2)!)
            //(n - 2)! 가 약분
            //n * (n - 1) / 2
            answer = answer + (C[j] * (C[j] - 1) / 2);
        }
    }

    cout << answer << "\n";
}