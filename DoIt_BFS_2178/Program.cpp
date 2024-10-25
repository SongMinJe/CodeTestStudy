#include <iostream>
#include <queue>

using namespace std;

static int A[101][101];
static bool visited[101][101] = { false };
static int dx[] = { 0, 1, 0, -1 };
static int dy[] = { 1, 0, -1, 0 };
static int N, M;

static void BFS(int i, int j) {
	queue<pair<int, int>> Q;
	Q.push(make_pair(i, j));
	while (Q.empty() == false)
	{
		int first = Q.front().first;
		int second = Q.front().second;
		Q.pop();
		visited[i][j] = true;

		//4방향
		for (int n = 0; n < 4; n++) {
			int x = first + dx[n];
			int y = second + dy[n];

			//있는 좌표?
			if (x >= 0 && y >= 0 && x < N && y < M) {
				//갈수 있음?
				if (A[x][y] != 0 && visited[x][y] == false) {
					visited[x][y] = true;
					A[x][y] = A[first][second] + 1;
					Q.push(make_pair(x, y));
				}
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		string x;
		cin >> x;
		for (int j = 0; j < M; j++) {
			A[i][j] = x[j] - '0';
		}
	}

	BFS(0, 0);
	cout << A[N - 1][M - 1] << "\n";
}