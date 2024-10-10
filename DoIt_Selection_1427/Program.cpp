#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string N;
    cin >> N;

    vector<int> A(N.size(), 0);

    for (int i = 0; i < A.size(); i++) {
        A[i] = stoi(N.substr(i, 1));
    }

    for (int i = 0; i < A.size(); i++) {
        int Max = A[i];
        for (int j = i + 1; j < A.size(); j++) {
            if (Max < A[j]) {
                Max = A[j];
                A[j] = A[i];
                A[i] = Max;
            }
        }
    }

    for (int i = 0; i < A.size(); i++) {
        cout << A[i];
    }
}