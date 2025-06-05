#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 과제 정보를 담을 구조체
struct Plan {
    string name;
    int start;     // 분 단위 시작 시각
    int playtime;  // 과제 수행 시간(분)
};

vector<string> solution(vector<vector<string>> plans) {
    int n = plans.size();
    vector<Plan> tasks;
    
    // 각 계획을 파싱: 시작 시각을 분 단위 정수로 변환
    for (int i = 0; i < n; i++) {
        Plan p;
        p.name = plans[i][0];
        string timeStr = plans[i][1];
        int hh = stoi(timeStr.substr(0, 2));
        int mm = stoi(timeStr.substr(3, 2));
        p.start = hh * 60 + mm;
        p.playtime = stoi(plans[i][2]);
        tasks.push_back(p);
    }
    
    // 시작 시간 기준 오름차순 정렬
    sort(tasks.begin(), tasks.end(), [](const Plan &a, const Plan &b) {
        return a.start < b.start;
    });
    
    vector<string> answer;
    vector<Plan> stack;  // 진행 중이거나 일시 정지한 과제들을 LIFO로 관리
    int currentTime = tasks[0].start;  // 시뮬레이션 기준 시간
    
    // 정렬된 순서대로 각 과제에 대해 처리
    for (int i = 0; i < n; i++) {
        // 새 과제가 시작되기 전까지의 가용 시간
        if (i > 0) {
            int available = tasks[i].start - currentTime;
            
            // 가용 시간 동안 스택의 과제들을 완료 가능한 만큼 진행
            while (!stack.empty() && available > 0) {
                Plan &top = stack.back();
                if (top.playtime <= available) {
                    available -= top.playtime;
                    currentTime += top.playtime;
                    answer.push_back(top.name);
                    stack.pop_back();
                } else {
                    top.playtime -= available;
                    currentTime += available;
                    available = 0;
                }
            }
        }
        
        // 만약 현재 시간이 새 과제의 시작 시간보다 이전이라면 갱신
        if (currentTime < tasks[i].start) {
            currentTime = tasks[i].start;
        }
        
        // 새 과제 시작 시 즉시 시작(현재 진행 중인 과제는 멈추고 스택에 남김)
        stack.push_back(tasks[i]);
    }
    
    // 모든 계획을 순회한 후, 남은 과제를 LIFO 순서로 종료 처리
    while (!stack.empty()) {
        answer.push_back(stack.back().name);
        stack.pop_back();
    }
    
    return answer;
}
