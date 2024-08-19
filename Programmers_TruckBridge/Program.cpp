#include <bits/stdc++.h>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    //다리위의 총 무게
    int sum = 0;
    //현재 건너려는 트럭의 인덱스
    int idx = 0;
    //다리위를 건너는 트럭들을 담는 큐
    queue<int> q;
    
    //1반복 = 1초
    while(1){
        //지금 건너는 트럭이 마지막이면?
        if(idx == truck_weights.size()){
            //bridge_length만큼 건너는 시간 추가
            //마지막 트럭이 다 건너야 끝나니까
            answer += bridge_length;
            //다 건넜다!
            break;
        }
        //1초 추가
        answer++;
        //다음 트럭의 무게 따로 저장
        int curWeight = truck_weights[idx];
        //가장 앞의 있는 트럭이 다리를 다 건넜을 경우
        if(q.size() == bridge_length){
            //가장 앞의 트럭의 무게를 다리위의총 무게에서 빼기  
            sum -= q.front();
            //다리를 건넜으므로 큐에서 pop
            q.pop();
        }
        //다음 트럭이 다리를 건널수 있나?
        //총 무게 + 다음트럭무게가 하중보다 작냐?
        if(sum + curWeight <= weight){
            //총 무게에 다음 트럭 무게 추가
            sum += curWeight;
            //큐에 다음 트럭 추가
            q.push(curWeight);
            //다음 트럭 지정
            idx++;
        }
        else{
            //빈칸 넣어서 트럭 대기
            q.push(0);
        }
    }
    //결과 출력
    return answer;
}