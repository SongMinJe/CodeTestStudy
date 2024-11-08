#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second < b.second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    if (N == 0) {
        cout << "0\n";
        return 0;
    }
    if (N == 1) {
        cout << "1\n";
        return 0;
    }

    vector<pair<int, int>> A(N);

    for (int i = 0; i < N; i++) {
        cin >> A[i].first >> A[i].second;
    }

    sort(A.begin(), A.end(), compare);

    int count = 1;
    int currentEnd = A[0].second;

    for (int i = 1; i < N; i++) {
        if (currentEnd <= A[i].first) {
            count++;
            currentEnd = A[i].second;
        }
    }

    cout << count << "\n";
    return 0;
}