#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
 
using namespace std;
 
//vector의 두번쩨 인자를 기준으로 오름차순 정렬
struct cmp{
    bool operator()(vector<int> a, vector<int> b) {
        return a[1] > b[1];
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int curTime = 0;
    int i = 0;
    //요청이 들어온 순서(첫번째 인자) 순서대로 오름차순 정렬
    sort(jobs.begin(), jobs.end());
    //두번째 인자를 기준으로 오름차순 정렬하는 우선순위 큐 선언
    //priority_queue < 저장될 요소의 타입, 
    //요소를 저장하는데 쓰는 컨테이너 타입, 
    //우선순위를 결정하는 비교 함수 객체 >
    priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
    //비교를 위한 인덱스가 jobs의 크기보다 작을때
    //큐가 비어있지 않을때 반복
    while(!pq.empty() || i < jobs.size()){
        //처리해야 할 작업은 남아있지만
        //아직 그 작업을 시작할 시간이 되지 않았을때를 비교하기 위해
        //i < jobs.size()를 한번더 비교하여
        //segmentation fault를 회피
        if(i < jobs.size() && curTime >= jobs[i][0]){
            //먼저 일을 넣고 인덱스 증가
            pq.push(jobs[i++]);
        }
        //일이 있나?
        else if(!pq.empty()){
            //현재시간 += 먼저 해야되는 일의 걸리는 시간
            //일을 끝냄
            curTime += pq.top()[1];
            //총 시간 += 현재시간 - 먼저 해야되는 일의 요청시간
            //대기시간 계산
            answer += curTime - pq.top()[0];
            //작업끝
            pq.pop();
        }
        //현재 해야될 일이 없을때
        else{
            //다음 일의 요청시간으로 이동
            curTime = jobs[i][0];
        }
    }
    //평균구하기
    return answer / jobs.size();
}