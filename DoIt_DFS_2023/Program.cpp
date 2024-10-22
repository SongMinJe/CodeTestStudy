#include <iostream>
#include <vector>

using namespace std;

static int N;

static bool IsPrime(int num) {
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

static void DFS(int num, int digits) {
    if (N == digits) {
        if (IsPrime(num)) {
            cout << num << "\n";
        }
        return;
    }
    for (int i = 1; i < 10; i++) {
        if (i % 2 != 0 && IsPrime(num * 10 + i)) {
            DFS(num * 10 + i, digits + 1);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    DFS(2, 1);
    DFS(3, 1);
    DFS(5, 1);
    DFS(7, 1);
}