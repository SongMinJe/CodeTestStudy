#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    queue<int> Q;

    for (int i = 1; i <= N; i++) {
        Q.push(i);
    }
    while (Q.size() > 1) {
        Q.pop();
        int popNum = Q.front();
        Q.pop();
        Q.push(popNum);
    }
    cout << Q.front() << "\n";
}