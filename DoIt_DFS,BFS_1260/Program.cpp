#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

static vector<vector<int>> A;
static vector<bool> visited;

static void DFS(int now) {
    cout << now << " ";
    visited[now] = true;
    for (int i : A[now]) {
        if (visited[i] == false) {
            DFS(i);
        }
    }
}

static void BFS(int num) {
    queue<int> Q;
    Q.push(num);
    visited[num] = true;

    while (Q.empty() == false) {
        int node = Q.front();
        Q.pop();
        cout << node << " ";
        for (int i : A[node]) {
            if (visited[i] == false) {
                Q.push(i);
                visited[i] = true;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, E, S;
    cin >> N >> E >> S;

    A.resize(N + 1);
    visited = vector<bool>(N + 1, false);

    for (int i = 0; i < E; i++) {
        int start, end;
        cin >> start >> end;
        A[start].push_back(end);
        A[end].push_back(start);
    }

    for (int i = 1; i <= N; i++) {
        sort(A[i].begin(), A[i].end());
    }

    DFS(S);
    fill(visited.begin(), visited.end(), false);
    cout << "\n";
    BFS(S);
    cout << "\n";
}