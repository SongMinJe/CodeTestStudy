#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string name) {
    int n = name.length();
    int answer = 0;
    int move = n - 1;  // 초기 이동 횟수: 오른쪽으로 쭉 이동하는 경우
    
    for (int i = 0; i < n; i++) {
        // 상하 조작 횟수 계산
        answer += min(name[i] - 'A', 'Z' - name[i] + 1);
        
        // 현재 위치 다음부터의 연속된 A의 개수 확인
        int next = i + 1;
        while (next < n && name[next] == 'A') {
            next++;
        }
        
        // 세 가지 경우 고려
        // 1. 계속 오른쪽으로 이동
        // 2. 현재까지 왔다가 돌아가서 뒤에서부터 이동
        // 3. 뒤에서부터 이동해서 현재 위치까지 오고 다시 돌아가기
        move = min(move, i + (n - next) + min(i, n - next));
    }
    
    answer += move;
    return answer;
}