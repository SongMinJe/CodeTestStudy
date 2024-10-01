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

    //pop ���� ������ ������ ���� ���� ��
    //�־��� ������ �ε�����
    //������ 0����, �ݺ����� �ε����� 1���� ����
    //���� = ����, �ݺ��� i = �񱳱�
    //���� < �񱳱� �϶� ��ū���̹Ƿ�
    //���� ������ ����� �ε����� �̿��Ͽ� ��� �迭�� ����
    //����迭�� ���� �Ϸ� �����Ƿ� pop
    //���� �񱳸� ���� �񱳱��� ����� �ε��� Ǫ��
    for (int i = 1; i < N; i++) {
        while (!S.empty() && A[S.top()] < A[i]) {
            result[S.top()] = A[i];
            S.pop();
        }
        S.push(i);
    }

    //���� ���ÿ� �����ִ� �ε����� ��ū���� ���� �ε�����. 
    while (!S.empty()) {
        result[S.top()] = -1;
        S.pop();
    }

    for (int i = 0; i < N; i++) {
        cout << result[i] << " ";
    }
}