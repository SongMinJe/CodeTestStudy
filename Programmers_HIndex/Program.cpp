#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    //인용 횟수가 1 ~ 모든 논문수까지 비교 반복
    //0번 인용은 제외
    for(int i = 1; i <= citations.size(); i++){
        //인용 횟수 기준점 이상인 경우의 수를 세기
        //C++ STL count_if 사용
        //begin()부터 end()까지의 수에서
        //람다식의 조건이 true인 경우의 count 구하기
        //[i] << 람다식에 쓰기 위해 변수 캡처
        //-> bool은 생략 가능
        int count = count_if(citations.begin(), citations.end(),
                              [i](int n) -> bool { return n >= i; });
        //기준점 이상인 경우의 수가
        //기준점 이상이면
        if(count >= i){
            //기준점 저장
            answer = i;
        }
        
    }
    return answer;
}