#include <string>
#include <vector>
using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    int dPos = n - 1;  // 마지막 배달 필요 집 인덱스 (0-based)
    int pPos = n - 1;  // 마지막 수거 필요 집 인덱스

    // 포인터를 집 번호 1..n으로 변환하려면 index+1을 사용
    while (dPos >= 0 || pPos >= 0) {
        // 다음 배달할 집 찾기
        while (dPos >= 0 && deliveries[dPos] == 0) {
            dPos--;
        }
        // 다음 수거할 집 찾기
        while (pPos >= 0 && pickups[pPos] == 0) {
            pPos--;
        }
        // 모두 끝나면 종료
        if (dPos < 0 && pPos < 0) break;

        // 이번 투어에서 갈 가장 먼 집 번호
        int farthest = max(dPos, pPos) + 1;
        answer += 2LL * farthest;

        // 이 투어에서 남은 배달·수거 용량
        int remainDel = cap;
        int remainPick = cap;

        // 배달 처리 (뒤에서 앞으로)
        while (remainDel > 0 && dPos >= 0) {
            if (deliveries[dPos] == 0) {
                dPos--;
                continue;
            }
            int take = min(deliveries[dPos], remainDel);
            deliveries[dPos] -= take;
            remainDel -= take;
        }
        // 수거 처리 (뒤에서 앞으로)
        while (remainPick > 0 && pPos >= 0) {
            if (pickups[pPos] == 0) {
                pPos--;
                continue;
            }
            int take = min(pickups[pPos], remainPick);
            pickups[pPos] -= take;
            remainPick -= take;
        }
    }

    return answer;
}
