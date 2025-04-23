#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> money) {
    const int MOD = 1000000007;
    vector<int> dp(n + 1, 0);
    dp[0] = 1;  // base case: one way to make 0원

    // 무한 동전 조합: 동전을 하나씩 적용하며 dp 갱신
    for (int coin : money) {
        for (int amount = coin; amount <= n; ++amount) {
            dp[amount] = (dp[amount] + dp[amount - coin]) % MOD;
        }
    }

    return dp[n];
}
