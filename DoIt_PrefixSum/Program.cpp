#include <iostream>

using namespace std;

int main()
{
    // C의 stdio와 C++의 iostream의 동기화 해제
    // C++만의 독립 버퍼 사용
    // 수행 속도 증가
    ios::sync_with_stdio(false);
    // cin, cout은 기본적으로 하나로 묶임
    // 입 > 출 // 입 > 출 이런식으로 묶임
    // 입, 출력이 반복 될때, 일일이 버퍼를 지워주느라 느려진다.
    // 그러나 해당 기능을 이용하면 입, 출력 순서를 보장받을 수 없다.
    cin.tie(NULL);
    cout.tie(NULL);

    // 비교할 숫자 갯수, 케이스 갯수
    int num, cases = 0;
    cin >> num >> cases;

    // 합 배열
    // ex) num = 1, 2, 3, ... >> S = 1, 3, 6, ...
    int S[100001] = {};

    // 숫자들을 입력 받으면서, 합 배열에도 저장
    for (int i = 1; i <= num; i++) {
        int temp = 0;
        cin >> temp;
        S[i] = S[i - 1] + temp;
    }

    // 연산 케이스 입력
    for (int j = 0; j < cases; j++) {
        int start, end;
        cin >> start >> end;
        // 구간 합 공식 이용
        // S[n] - S[n - 1]
        cout << S[end] - S[start - 1] << "\n";
    }
}