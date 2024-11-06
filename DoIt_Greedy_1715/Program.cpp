#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    int acc = 0;
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < N; i++) {
        int bundle;
        cin >> bundle;
        pq.push(bundle);
    }

    while (pq.size() > 1) {
        int A, B;

        A = pq.top();
        pq.pop();
        B = pq.top();
        pq.pop();

        acc += (A + B);

        pq.push(A + B);
    }

    cout << acc << "\n";
}