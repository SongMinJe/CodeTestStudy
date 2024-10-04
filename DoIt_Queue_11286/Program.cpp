#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct compare {
    //ÇÔ¼ö °´Ã¼
    bool operator()(int o1, int o2) {
        int fir_abs = abs(o1);
        int sec_abs = abs(o2);
        if (fir_abs == sec_abs) {
            return o1 > o2;
        }
        else {
            return fir_abs > sec_abs;
        }
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    priority_queue<int, vector<int>, compare> Q;

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int request = 0;
        cin >> request;

        if (request == 0) {
            if (Q.empty()) {
                cout << "0\n";
            }
            else {
                cout << Q.top() << "\n";
                Q.pop();
            }
        }
        else {
            Q.push(request);
        }
    }
}