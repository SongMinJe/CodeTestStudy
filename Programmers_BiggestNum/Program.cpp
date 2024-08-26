#include <bits/stdc++.h>

using namespace std;

bool cmp(string a, string b){
    //a+b가 b+a보다 크면 true를 반환하고, 그렇지 않으면 false를 반환.
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    //sort를 위한 vector
    //앞글자 비교를 위한 string
    vector<string> numVec;
    for(auto& num : numbers){
        //numbers string화
        numVec.push_back(to_string(num));
    }
    //string 조합의 크기 비교
    //ascii 기준 비교
    sort(numVec.begin(), numVec.end(), cmp);
    //0이면 0출력
    if (numVec.at(0) == "0"){
        return "0";
    }
    //문자열 다 더하기
    for (auto num : numVec){
        answer += num;
    }
    return answer;
}