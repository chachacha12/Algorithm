#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

bool can_solve_all(int level, const vector<int>& diffs, const vector<int>& times, ll limit) {
    ll total_time = 0;
    int n = diffs.size();
    for (int i = 0; i < n; ++i) {
        int diff = diffs[i];
        int time_cur = times[i];
        int time_prev = (i == 0 ? 0 : times[i - 1]);

        if (diff <= level) {
            total_time += time_cur;
        } else {
            ll fails = diff - level;
            total_time += (time_cur + time_prev) * fails + time_cur;
        }

        if (total_time > limit) return false;
    }
    return true;
}

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int left = 1, right = 100000;
    int answer = 100000;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (can_solve_all(mid, diffs, times, limit)) {
            answer = mid;
            right = mid - 1; // 더 낮은 숙련도 시도
        } else {
            left = mid + 1;  // 더 높은 숙련도 필요
        }
    }

    return answer;
}
