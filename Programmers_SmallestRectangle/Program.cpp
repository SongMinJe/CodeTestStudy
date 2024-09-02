#include <string>
#include <vector>
using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    //높이
    int h = 0;
    //너비
    int w = 0;
    
    //sizes의 요소들 비교
    for(int i = 0; i < sizes.size(); i++)
    {
        //높이와 너비중 더 큰 값 찾기
        if(sizes[i][0] > sizes[i][1])
        {
            //더 큰값을 h로 스왑
            //문제의 명함을 회전시키는 기능
            h = max(h, sizes[i][0]);
            w = max(w, sizes[i][1]);
        }
        else
        {
            h = max(h, sizes[i][1]);
            w = max(w, sizes[i][0]);
        }
    }
    
    //지갑 면적 구하기
    answer = h * w;
    return answer;
}