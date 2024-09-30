#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> seq(N, 0);
    stack<int> S;
    vector<string> result;
    bool isNotMin = false;

    for (int i = 0; i < N; i++) {
        cin >> seq[i];
    }
    int n = 1;
    for (int i = 0; i < seq.size(); i++) {
        if (seq[i] >= n) {
            while (seq[i] >= n) {
                S.push(n++);
                result.push_back("+");
            }
            S.pop();
            result.push_back("-");
        }
        else {
            int t = S.top();
            S.pop();
            if (t > seq[i]) {
                cout << "NO" << "\n";
                isNotMin = true;
                break;
            }
            else {
                result.push_back("-");
            }
        }
    }
    if (isNotMin == false) {
        for (int i = 0; i < result.size(); i++) {
            cout << result[i] << "\n";
        }
    }
}