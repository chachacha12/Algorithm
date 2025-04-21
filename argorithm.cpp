#include <string>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int solution(vector<vector<int>> info, int n, int m) {
    const int INF = numeric_limits<int>::max() / 2;
    // dp[b] = 최소 A의 흔적 합으로 B의 흔적 합이 b가 될 수 있는 경우
    vector<int> dp(m, INF), newdp(m, INF);
    dp[0] = 0;
    for (auto &item : info) {
        int a = item[0], b = item[1];
        fill(newdp.begin(), newdp.end(), INF);
        for (int sumB = 0; sumB < m; ++sumB) {
            if (dp[sumB] == INF) continue;
            int sumA = dp[sumB];
            // 1) A가 이 물건을 훔치는 경우
            int na = sumA + a;
            if (na < n) {
                // B 흔적은 변하지 않음
                newdp[sumB] = min(newdp[sumB], na);
            }
            // 2) B가 이 물건을 훔치는 경우
            int nb = sumB + b;
            if (nb < m) {
                // A 흔적은 변하지 않음
                newdp[nb] = min(newdp[nb], sumA);
            }
        }
        dp.swap(newdp);
    }
    // 가능한 B 흔적 합 중 A 흔적 합의 최소값을 찾는다
    int answer = INF;
    for (int sumB = 0; sumB < m; ++sumB) {
        answer = min(answer, dp[sumB]);
    }
    return (answer == INF ? -1 : answer);
}
