#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	int A[10001] = { 0 };
	int num = 0;

	for (int i = 1; i <= N; i++) {
		cin >> num;
		A[num]++;
	}

	for (int i = 0; i <= 10000; i++) {
		if (A[i] != 0) {
			for (int j = 0; j < A[i]; j++) {
				cout << i << "\n";
			}
		}
	}
}