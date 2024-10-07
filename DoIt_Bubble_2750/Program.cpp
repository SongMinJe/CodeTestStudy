#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> v(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - 1 - i; j++) {
            if (v[j] > v[j + 1]) {
                int temp = v[j + 1];
                v[j + 1] = v[j];
                v[j] = temp;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        cout << v[i] << "\n";
    }
}