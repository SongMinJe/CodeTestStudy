#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> A(N, 0);

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    int M;
    cin >> M;

    for (int i = 0; i < M; i++) {
        int target;
        cin >> target;
        bool isFind = false;
        int start = 0;
        int end = A.size() - 1;
        while (start <= end) {
            int mid;
            mid = (start + end) / 2;
            if (A[mid] > target) {
                end = mid - 1;
            }
            else if (A[mid] < target) {
                start = mid + 1;
            }
            else {
                isFind = true;
                break;
            }
        }
        if (isFind == true) {
            cout << "1" << "\n";
        }
        else {
            cout << "0" << "\n";
        }
    }
}