#include <string>
#include <vector>

using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    // 시간대는 0부터 23까지 총 24시간이며, 최대 만료 시각은 23+k 이므로,
    // 이에 맞춰 만료 이벤트를 기록할 벡터를 준비합니다.
    vector<int> expire(24 + k + 1, 0);
    
    int active = 0; // 현재 운영중인 서버 수
    
    // 0시부터 23시까지 각 시간대에 대해 처리
    for (int i = 0; i < 24; i++) {
        // i시가 시작할 때, 만료되어 반납되어야 할 서버들을 active에서 제거
        active -= expire[i];
        
        // 현재 시간대 i의 게임 이용자 수에 따라 필요한 서버 수 계산
        int required = 0;
        if (players[i] >= m) {
            required = players[i] / m;  // 정수 나눗셈: m명 미만은 0, n*m 이상이면 n대 필요
        }
        
        // 만약 현재 운영중인 서버가 필요한 수보다 부족하다면 추가 증설
        if (active < required) {
            int add = required - active;
            answer += add;
            active += add;
            // i시 증설된 서버는 i+k 시에 반납되므로 만료 이벤트 기록
            expire[i + k] += add;
        }
    }
    
    return answer;
}
