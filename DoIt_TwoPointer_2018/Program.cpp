#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N = 0;

    cin >> N;

    int answer = 1;
    int start = 1;
    int end = 1;
    int sum = 1;

    while (end != N) {
        if (sum == N) {
            answer++;
            end++;
            sum += end;
        }
        else if (sum > N) {
            sum -= start;
            start++;
        }
        else {
            end++;
            sum += end;
        }
    }
    cout << answer << "\n";
}