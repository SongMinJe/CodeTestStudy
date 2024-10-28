#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

static vector<vector<pair<int, int>>> A;
static vector<bool> visited;
static vector<int> dist;

static void BFS(int idx) {
    queue<int> Q;
    Q.push(idx);
    visited[idx] = true;

    while (Q.empty() == false) {
        int now = Q.front();
        Q.pop();
        for (int i = 0; i < A[now].size(); i++) {
            if (visited[A[now][i].first] == false) {
                visited[A[now][i].first] = true;
                Q.push(A[now][i].first);
                dist[A[now][i].first] = dist[now] + A[now][i].second;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    A.resize(N + 1);

    for (int i = 0; i < N; i++) {
        int S;
        cin >> S;
        while (true) {
            int E, V;
            cin >> E;
            if (E == -1) {
                break;
            }
            cin >> V;
            A[S].push_back(make_pair(E, V));
        }
    }

    visited = vector<bool>(N + 1, false);
    dist = vector<int>(N + 1, 0);

    BFS(1);
    int Max = 1;

    for (int i = 2; i <= N; i++) {
        if (dist[Max] < dist[i]) {
            Max = i;
        }
    }
    fill(dist.begin(), dist.end(), 0);
    fill(visited.begin(), visited.end(), false);
    BFS(Max);
    sort(dist.begin(), dist.end());
    cout << dist[N] << "\n";
}