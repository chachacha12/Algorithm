#include <string>
#include <vector>
using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    int n = schedules.size();
    
    for (int i = 0; i < n; i++) {
        bool qualified = true;
        int allowedTime = schedules[i] + 10; // 출근 인정 시각 (희망 시각 + 10분)
        
        // 시각이 정수로 표현되므로 분이 60을 넘으면 시간 조정
        if (allowedTime % 100 >= 60) {
            allowedTime = allowedTime + 40; // 60분 = 1시간 -> +100, -60 = +40
        }
        
        // 일주일 동안의 출근 기록 확인
        for (int day = 0; day < 7; day++) {
            // 현재 요일 계산 (1=월, ..., 7=일)
            int currentDay = (startday + day - 1) % 7 + 1;
            
            // 토요일(6)이나 일요일(7)이면 건너뛰기
            if (currentDay == 6 || currentDay == 7) {
                continue;
            }
            
            // 직원의 해당 일자 출근 시각
            int actualTime = timelogs[i][day];
            
            // 출근 인정 시각보다 늦게 출근했으면 자격 없음
            if (actualTime > allowedTime) {
                qualified = false;
                break;
            }
        }
        
        // 모든 평일에 지각하지 않았으면 상품 받을 자격 있음
        if (qualified) {
            answer++;
        }
    }
    
    return answer;
}