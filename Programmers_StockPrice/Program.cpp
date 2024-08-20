#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> prices) {
    //prices 벡터의 크기를 미리 계산하여 저장 (성능 최적화)
    int n = prices.size();
    
    //결과를 저장할 벡터를 prices와 같은 크기로 초기화
    vector<int> answer(n);
    
    //인덱스를 저장할 스택 선언
    //스택에 인덱스를 저장하는 이유:
    //1. 가격이 떨어지지 않은 기간을 계산하기 위해
    //2. 인덱스로 원본 가격에 쉽게 접근 가능
    stack<int> s;
    
    //prices 벡터를 순회하며 각 가격의 유지 기간 계산
    for(int i = 0; i < n; i++){
        //현재 가격이 스택 top의 가격보다 낮을 때까지 반복
        //이는 가격이 떨어진 시점을 찾는 과정
        while(!s.empty() && prices[s.top()] > prices[i]){
            int top = s.top();
            //가격이 떨어지지 않은 기간 계산: 현재 인덱스 - 스택의 top 인덱스
            answer[top] = i - top;
            //처리 완료된 인덱스는 스택에서 제거
            s.pop();
        }
        //현재 인덱스를 스택에 추가 (다음 비교를 위해)
        s.push(i);
    }
    //스택에 남아있는 인덱스 처리 (끝까지 가격이 떨어지지 않은 경우)
    while(!s.empty()){
        int top = s.top();
        //마지막 가격까지의 기간 계산: 전체 기간 - 해당 인덱스 - 1
        //1을 빼는 이유는 인덱스가 0부터 시작하기 때문
        answer[top] = n - top - 1;
        s.pop();
    }
    return answer;
}