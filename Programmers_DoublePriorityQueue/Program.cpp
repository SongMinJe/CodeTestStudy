#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<string> operations) {
    // 내림차순 우선순위 큐 (최대 힙)
    priority_queue<int> max_pq;
    // 오름차순 우선순위 큐 (최소 힙)
    priority_queue<int, vector<int>, greater<int>> min_pq;
    // 각 숫자의 출현 횟수를 저장하는 맵
    map<int, int> count;
    // 현재 큐에 있는 유효한 요소의 개수
    int size = 0;
    
    // 모든 operations를 순회
    for(const auto& operation : operations) {
        // 삽입 커맨드인 경우
        if(operation[0] == 'I') {
            // 문자열에서 숫자 부분을 추출하여 정수로 변환
            int num = stoi(operation.substr(2));
            // 최대 힙과 최소 힙에 숫자 삽입
            max_pq.push(num);
            min_pq.push(num);
            // 해당 숫자의 출현 횟수 증가
            count[num]++;
            // 전체 요소 개수 증가
            size++;
        }
        // 삭제 연산이고 큐가 비어있지 않은 경우
        else if(size > 0) {
            // 최대값 삭제 연산
            if(operation[2] == '1' && !max_pq.empty()){
                // 최대값의 출현 횟수 감소
                count[max_pq.top()]--;
                // 최대 힙에서 최대값 제거
                max_pq.pop();
                // 전체 요소 개수 감소
                size--;
            }
            // 최소값 삭제 연산
            else if(operation[2] == '-' && !min_pq.empty()) {
                // 최소값의 출현 횟수 감소
                count[min_pq.top()]--;
                // 최소 힙에서 최소값 제거
                min_pq.pop();
                // 전체 요소 개수 감소
                size--;
            }
        }
    }
    
    // 최종 정리: 이미 다른 쪽에서 삭제된 요소들을 큐에서 제거
    while(!max_pq.empty() && count[max_pq.top()] == 0) max_pq.pop();
    while(!min_pq.empty() && count[min_pq.top()] == 0) min_pq.pop();
    
    // 결과 반환
    if(size == 0) {
        // 큐가 비어있으면 [0, 0] 반환
        return {0, 0};
    }
    else {
        // 최대값과 최소값 반환
        return {max_pq.top(), min_pq.top()};
    }
}