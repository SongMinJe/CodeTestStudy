#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    //string의 한 문자씩 저장하니까 char형 Stack
    stack<char> parenthesesStack;
    
    //s 사이즈만큼 반복
    //s의 한글자씩 c로 비교
    for(char c : s){
        //괄호 종류 판별
        //현재 괄호가 '('
        if(c == '('){
            //시작 괄호가 '(' 이면 삽입
            parenthesesStack.emplace(c);
        }
        //현재 괄호가 ')'
        else{
            //비어있으면 시작 괄호가 맞으므로
            //')'가 먼저오면 틀린순서기 때문에
            //false return
            if(parenthesesStack.empty() == true){
                return false;
            }
            //비어있지 않으면 맞는 괄호 순서
            else{
                //비교가 끝난 기존 '('사출
                parenthesesStack.pop();
            }
        }
    }
    //전부 비어있어야 다 같은 짝을 찾은 괄호다.
    return answer = parenthesesStack.empty();
}