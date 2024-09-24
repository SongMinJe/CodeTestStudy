#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long N;

	cin >> N;

	vector<int> A(N, 0);
	int result = 0;

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	sort(A.begin(), A.end());

	for (int k = 0; k < N; k++) {
		long find = A[k];
		int n = 0;
		int m = N - 1;
		//투포인터 알고리즘
		while (n < m) {
			if (A[n] + A[m] == find) {
				//자기 자신을 제외
				if (n != k && m != k) {
					result++;
					break;
				}
				else if (n == k) {
					n++;
				}
				else if (m == k) {
					m--;
				}
			}
			else if (A[n] + A[m] < find) {
				n++;
			}
			else {
				m--;
			}
		}
	}
	cout << result << "\n";
}