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
    priority_queue<int, vector<int>, greater<int>> negativePQ;
    priority_queue<int, vector<int>, less<int>> positivePQ;
    int oneCount = 0;
    int zeroCount = 0;
    int result = 0;

    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        if (temp > 1) {
            positivePQ.push(temp);
        }
        else if (temp < 0) {
            negativePQ.push(temp);
        }
        if (temp == 1) {
            oneCount++;
        }
        else if (temp == 0) {
            zeroCount++;
        }
    }

    while (positivePQ.size() > 1) {
        int first = positivePQ.top();
        positivePQ.pop();
        int sec = positivePQ.top();
        positivePQ.pop();
        result += (first * sec);
    }
    if (positivePQ.empty() == false) {
        result += positivePQ.top();
        positivePQ.pop();
    }

    while (negativePQ.size() > 1) {
        int first = negativePQ.top();
        negativePQ.pop();
        int sec = negativePQ.top();
        negativePQ.pop();
        result += (first * sec);
    }
    if (negativePQ.empty() == false) {
        if (zeroCount == 0) {
            result += negativePQ.top();
            negativePQ.pop();
        }
    }

    result += oneCount;

    cout << result << "\n";
}