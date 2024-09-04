#include <string>
#include <vector>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n;
    // 처음, 끝 학생의 비교를 위한 더미데이터 포함
    // lost, reserve 모두 인덱스의 + 1 한 값이 들어있기 때문에
    // 첫 인덱스도 한칸 띄워준다.
    // 모두 0으로 초기화
    vector<int> std(n + 2, 0);
    
    // 도난당한 학생은 -1, 여벌이 있는 학생은 1
    // 도난당했지만 여벌이 있는 학생은 0
    for(int l : lost) {
        std[l]--;
    }
    for(int r : reserve) {
        std[r]++;
    }
    
    // 도난 당한 학생에게 체육복 빌려주기
    for (int l = 1; l <= n; l++) {
        // 학생 l이 도난당했다면
        if(std[l] == -1) {
            // 다음 학생 or 전 학생이 여분이 있다면 그 학생에게 받기
            if(std[l - 1] == 1) {
                std[l]++;
                std[l - 1]--;
            }
            else if(std[l + 1] == 1) {
                std[l]++;
                std[l + 1]--;
            }
        }
    }
    
    // 수업을 들을 수 있는 학생 수 세기
    for(int i = 1; i <= n; i++) {
        // 해당 학생이 들을 수 없니?
        if(std[i] == -1) {
            // 명단 제외
            answer--;
        }
    }
    
    return answer;
}