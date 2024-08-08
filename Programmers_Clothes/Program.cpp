#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    //곱의 법칙의 계산에 맞게 1을 미리 넣어준다.
    int answer = 1;
    //한 부위에는 한가지만 착용 가능하다
    //각 부위의 가짓수를 구해야 경우의 수를 구할수 있다.
    unordered_map<string, int> map;
    //범위 for문
    //clothes의 요소들인 1차원 배열들을 받아
    //그 배열들의 갯수만큼 반복한다.
    for(vector<string> cloth : clothes){
        //각 요소의 0번 인덱스는 의상 이름을 나타낸다.
        //1번 인덱스는 의상 종류를 나타낸다.
        //Key값으로 의상 종류를 받아
        //각 부위의 가짓수를 구한다.
        map[cloth[1]]++;
    }
    //c++ iterator > 배열등의 요소를 가리키는 포인터
    //name.begin() > 시작 인덱스의 요소를 가리키는 반복자
    //name.end() > 마지막 요소의 다음 요소를 가리키는 반복자
    //마지막 요소가 끝날 때까지 반복
    for(auto iter = map.begin(); iter != map.end(); iter++){
        //곱의 법칙 > A * B = 독립적으로 동시에 발현되고있는 경우의 수
        //현재 가리키는 요소의 두번째 요소 + 1을 answer에 곱한다.
        //계산의 일관성과 편의성을 위해
        //알몸 상태도 더한다.
        answer *= iter -> second + 1;
    }
    //알몸 상태를 뺀다.
    return answer - 1;
}