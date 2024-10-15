#include <iostream>
#include <vector>

using namespace std;

static vector<int> A;
static vector<int> tmp;

void merge(int start, int end) {
	if (start >= end) {
		return;
	}

	int middle = start + (end - start) / 2;
	merge(start, middle);
	merge(middle + 1, end);

	for (int i = start; i <= end; i++) {
		tmp[i] = A[i];
	}

	int k = start;
	int idx1 = start;
	int idx2 = middle + 1;

	while (idx1 <= middle && idx2 <= end)
	{
		if (tmp[idx1] <= tmp[idx2]) {
			A[k++] = tmp[idx1++];
		}
		else {
			A[k++] = tmp[idx2++];
		}
	}

	while (idx1 <= middle)
	{
		A[k++] = tmp[idx1++];
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	A = vector<int>(N + 1, 0);
	tmp = vector<int>(N + 1, 0);

	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}

	merge(1, N);

	for (int i = 1; i <= N; i++) {
		cout << A[i] << "\n";
	}
}