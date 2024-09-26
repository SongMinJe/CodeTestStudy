#include <iostream>
#include <deque>

using namespace std;
typedef pair<int, int> Node;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, L;
	cin >> N >> L;
	deque<Node> mydeque;

	for (int i = 0; i < N; i++) {
		int now;
		cin >> now;

		//현재 수보다 큰 값을 deque에서 제거하여 시간 복잡도를 줄임
		while (mydeque.size() && mydeque.back().first > now) {
			mydeque.pop_back();
		}

		mydeque.push_back(Node(now, i));

		//범위에서 벗어난 값은 deque에서 제거
		if (mydeque.front().second <= i - L) {
			mydeque.pop_front();
		}

		cout << mydeque.front().first << ' ';
	}
}