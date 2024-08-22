#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    //sort용 vector
    vector<int> v;
    //커맨드 갯수만큼 반복
    for(int n = 0; n < commands.size(); n++){
        //각 커맨드의 0 ~ 2번째 인덱스를 저장
        int i = commands[n][0];
        int j = commands[n][1];
        int k = commands[n][2];
        //array의 i ~ j번째까지 반복
        //인덱스 접근을 위해 i - 1
        for(int m = i - 1; m < j; m++){
            //v vector에 삽입
            v.push_back(array[m]);
        }
        //v 오름차순 정렬
        sort(v.begin(), v.end());
        //k번째 숫자 삽입
        //인덱스 접근을 위해 k - 1
        answer.push_back(v[k-1]);
        //첫 커맨드 연산 후 sort용 vector 비우기
        v.clear();
    }
    //출력
    return answer;
}