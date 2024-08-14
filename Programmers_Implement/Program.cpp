#include <string>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    //일이 끝날때까지 걸리는 날짜를 저장하는 큐
    queue<int> endWorkQueue;
    
    //일이 끝날때까지 걸리는 날짜를 계산하여 큐에 저장
    for(int i = 0; i < progresses.size(); i++){
        endWorkQueue.push(ceil((100.0 - progresses[i]) / speeds[i]));
    }
    
    //날짜 비교가 끝날때 까지 반복
    while(!endWorkQueue.empty()){
        //현재 일이 끝나는 날짜 수 저장
        int max = endWorkQueue.front();
        //다음 비교 케이스를 비교하기 위해 이미 사용한 최댓값 제거
        endWorkQueue.pop();
        //최댓값보다 작은 날짜를 세는 변수
        int count = 1;
        //다음 우선순위의 일이 끝나는 날짜 <= 현재 일이 끝나는 날짜 일때만 반복
        //다음 날짜들을 큐에서 빼면 다음 반복문에 큐가 비어있는지 확인한다.
        while(!endWorkQueue.empty() && endWorkQueue.front() <= max){
            //비교 케이스 제거
            endWorkQueue.pop();
            //현재 진행중인 작업이 걸리는 날짜보다
            //덜 걸리는 작업들을 세기
            count++;
        }
        //우선순위가 가장 높은 작업이 끝나는 타이밍에
        //그 작업보다 우선순위가 낮으면서 덜 걸리는 작업을 센 변수를 정답에 추가
        answer.push_back(count);
    }
    
    return answer;
}