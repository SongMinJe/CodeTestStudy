#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> A(N, 0);
    stack<int> S;
    vector<int> result(N, -1);

    S.push(0);

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    //pop 에러 방지로 스택이 비지 않을 때
    //주어진 수열의 인덱스비교
    //스택은 0부터, 반복문의 인덱스는 1부터 시작
    //스택 = 현재, 반복문 i = 비교군
    //현재 < 비교군 일때 오큰수이므로
    //현재 스택의 저장된 인덱스를 이용하여 결과 배열에 저장
    //결과배열에 저장 완료 했으므로 pop
    //다음 비교를 위해 비교군에 사용한 인덱스 푸쉬
    for (int i = 1; i < N; i++) {
        while (!S.empty() && A[S.top()] < A[i]) {
            result[S.top()] = A[i];
            S.pop();
        }
        S.push(i);
    }

    //현재 스택에 남아있는 인덱스는 오큰수가 없는 인덱스다. 
    while (!S.empty()) {
        result[S.top()] = -1;
        S.pop();
    }

    for (int i = 0; i < N; i++) {
        cout << result[i] << " ";
    }
}