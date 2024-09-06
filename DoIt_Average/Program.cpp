#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int N = 0;
    int record[1000];
    // 과목 수 입력
    cin >> N;
    // 과목 점수 입력
    for (int i = 0; i < N; i++) {
        cin >> record[i];
    }

    // 범위 초과 대비 long 선언
    long max = 0;
    long sum = 0;

    //최대값과 총합 구하기
    for (int i = 0; i < N; i++) {
        if (max < record[i]) {
            max = record[i];
        }
        sum += record[i];
    }

    //소수점 포함 출력용 double 변수
    //문제조건 연산
    double answer = sum * 100.0 / max / N;

    //정답 출력
    cout << answer << "\n";
}