#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

static bool isPalindrome(int num) {
    string str = to_string(num);
    int start = 0;
    int end = str.length() - 1;
    while (start < end) {
        if (str[start] != str[end]) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<bool> A(2000001, true);
    A[0] = A[1] = false;

    for (int i = 2; i <= sqrt(2000001); i++) {
        if (A[i] == false) {
            continue;
        }
        for (long long j = (long long)i * i; j < 2000001; j += i) {
            A[j] = false;
        }
    }

    for (int i = 2; i < 2000001; i++) {
        if (i >= N && A[i] == true && isPalindrome(i)) {
            cout << i << "\n";
            break;
        }
    }
}