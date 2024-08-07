#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    //Hash Map
    unordered_map<string, int> phoneMap;
    //Hash Map 초기화
    for(int i = 0; i < phone_book.size(); i++){
        //Hash Map을 직접 비교하면
        //기본값이 0 이기 때문에
        //phone_book[i]을 Key 값, 1을 Value값으로 삽입하여
        //없다면 0, 있다면 0이 아닌 값을 판별하기 위하여
        //아무값인 1을 굳이 삽입한다.
        phoneMap[phone_book[i]] = 1;
    }
    
    //주어진 vector인 phone_book를 순회
    for(int i = 0; i < phone_book.size(); i++){
        //phone_book의 요소들은 string 값
        //string 값은 배열같이 접근 가능하므로
        //각 값의 인덱스로 한글자씩 접근
        //phone_book[i].size() - 1 의 경우에는
        //마지막엔 전체 문자열을 비교하게 되므로
        //자기 자신도 검사하여 무조건 겹치는 결과가 나오게 된다.
        //if문이 의미가 없어지는 결과가 나오게 되는 것.
        for(int j = 0; j < phone_book[i].size() - 1; j++){
            //substr(a, b)는 string값을 a부터 b까지 자른다.
            //단, b 는 길이단위이기 때문에
            //0 부터 시작하는 인덱스에서 + 1 해준다.
            //이 경우에는 한 글자씩 더해주며 비교한다.
            //ex) 1 비교 > 12 비교 > 123 비교 ....
            string prefix = phone_book[i].substr(0, j + 1);
            //prefix에 해당하는 Key 값이 없다면
            //기본값인 0 을 출력
            //밑의 if문은 있다면 통과되고 없다면 0을 출력
            //phoneMap[prefix] != 0 과 동일한 원리
            if(phoneMap[prefix]){
                //접두사가 포함되어있다면 false
                return answer = false;
            }
        }
    }
    //접두사가 포함되어있지 않다면 true
    return answer;
}