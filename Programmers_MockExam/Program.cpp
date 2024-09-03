#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    //찍는 방식 패턴 저장
    int std_1[5] = {1, 2, 3, 4, 5};
    int std_2[8] = {2, 1, 2, 3, 2, 4, 2, 5};
    int std_3[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    //학생별 점수판
    int score[3] = {0, 0, 0};
    
    //점수 채점
    for(int i = 0; i < answers.size(); i++){
        //찍기 패턴의 크기로 %연산을 통해 인덱스 초기화
        if(std_1[i % 5] == answers[i]){
            score[0]++;
        }
        if(std_2[i % 8] == answers[i]){
            score[1]++;
        }
        if(std_3[i % 10] == answers[i]){
            score[2]++;
        }
    }
    
    //세명 중 최고 점수 구하기 
    int max = std::max({score[0], score[1], score[2]});
    
    //랭크 매기기
    if(max == score[0]){
        answer.push_back(1);
    }
    if(max == score[1]){
        answer.push_back(2);
    }
    if(max == score[2]){
        answer.push_back(3);
    }
    
    //오름차순 정렬
    sort(answer.begin(), answer.end());
    
    return answer;
}