#include <iostream>
#include <vector>

using namespace std;

static vector<vector <int>> A;
static vector <bool> visited;

void DFS(int v) {
    if (visited[v] == true) {
        return;
    }

    visited[v] = true;

    for (int i = 0; i < A[v].size(); i++) {
        if (visited[A[v][i]] == false) {
            DFS(A[v][i]);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    A.resize(N + 1);
    visited = vector<bool>(N + 1, false);

    for (int i = 0; i < M; i++) {
        int start, end;
        cin >> start >> end;
        A[start].push_back(end);
        A[end].push_back(start);
    }

    int count = 0;

    for (int i = 1; i <= N; i++) {
        if (visited[i] == false) {
            count++;
            DFS(i);
        }
    }
    cout << count << "\n";
}