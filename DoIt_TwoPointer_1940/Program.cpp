#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long N, M;
	cin >> N >> M;

	vector<int> A(N, 0);
	int start = 0;
	int end = N - 1;
	int answer = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	sort(A.begin(), A.end());

	while (start < end) {
		if (A[start] + A[end] < M) {
			start++;
		}
		else if (A[start] + A[end] > M) {
			end--;
		}
		else {
			start++;
			end--;
			answer++;
		}
	}
	cout << answer << "\n";
}