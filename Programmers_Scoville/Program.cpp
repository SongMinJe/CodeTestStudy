#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    //우선순위 큐<저장할 데이터 타입, 사용할 컨테이너, 오름차순> scoville의 begin ~ end 삽입
    priority_queue<int, vector<int>, greater<int>> minHeap(scoville.begin(), scoville.end());
    
    //큐의 사이즈가 1보다 클 때와
    //오름차순이므로 제일 앞의 숫자가 K보다 작을 때만 반복
    while(minHeap.size() > 1 && minHeap.top() < K){
        //첫 인덱스와 두번째 인덱스를 저장
        //각각 저장 후 비우기
        int least = minHeap.top();
        minHeap.pop();
        int second = minHeap.top();
        minHeap.pop();
        
        //문제의 연산 식
        int mix = least + (second * 2);
        
        //연산 식 힙에 저장
        minHeap.push(mix);
        
        //연산 횟수 카운트
        answer++;
    }
    
    //오름차순 정렬된 큐의 제일 앞 숫자가
    //K보다 크거나 같을때만 answer return
    if(minHeap.top() >= K){
        return answer;
    }
    else{
        return -1;
    }
}