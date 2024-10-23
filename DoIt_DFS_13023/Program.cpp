#include <iostream>
#include <vector>

using namespace std;

static vector<vector<int>> A;
static vector<bool> visits;
static bool isArrive;

void DFS(int now, int depth) {
    if (depth == 5) {
        isArrive = true;
        return;
    }

    visits[now] = true;

    for (int i : A[now]) {
        if (visits[i] == false) {
            DFS(i, depth + 1);
        }
    }

    visits[now] = false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, E;
    cin >> N >> E;

    A.resize(N);
    visits = vector<bool>(N, false);

    for (int i = 0; i < E; i++) {
        int first, second;
        cin >> first >> second;
        A[first].push_back(second);
        A[second].push_back(first);
    }

    for (int i = 0; i < N; i++) {
        DFS(i, 1);
        if (isArrive == true) {
            break;
        }
    }

    if (isArrive == true) {
        cout << "1" << "\n";
    }
    else {
        cout << "0" << "\n";
    }
}