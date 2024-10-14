#include <iostream>
#include <vector>

using namespace std;

void swap(vector<int>& A, int i, int j) {
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

int pivot(vector<int >& A, int start, int end) {
    if (start + 1 == end) {
        if (A[start] > A[end]) {
            swap(A, start, end);
        }
        return end;
    }
    int M = (start + end) / 2;
    swap(A, M, start);
    int _pivot = A[start];
    int i = start + 1;
    int j = end;

    while (i <= j) {
        while (i < end && _pivot > A[i]) {
            i++;
        }
        while (j >= start + 1 && _pivot < A[j]) {
            j--;
        }
        if (i < j) {
            swap(A, i++, j--);
        }
        else {
            break;
        }
    }

    A[start] = A[j];
    A[j] = _pivot;
    return j;
}

int quick(vector<int>& A, int start, int end, int K) {
    int _pivot = pivot(A, start, end);
    if (_pivot == K) {
        return A[_pivot];
    }
    else if (K < _pivot) {
        return quick(A, start, _pivot - 1, K);
    }
    else {
        return quick(A, _pivot + 1, end, K);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    vector<int> A(N, 0);

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int result = quick(A, 0, N - 1, K - 1);
    cout << result << endl;
}