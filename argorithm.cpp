#include <string>
#include <vector>
#include <cmath>
using namespace std;
using ll = long long;

// x^2 ≤ val을 만족하는 최대 정수 y를 반환 (floor of sqrt(val))
ll isqrt_floor(ll val) {
    ll y = (ll)floor(sqrt((double)val));
    // 보정: y가 너무 작으면 늘려주기
    while ((y+1)*(y+1) <= val) ++y;
    while (y*y > val) --y;
    return y;
}

// x^2 ≥ val을 만족하는 최소 정수 y를 반환 (ceil of sqrt(val))
ll isqrt_ceil(ll val) {
    if (val <= 0) return 0;
    ll y = (ll)floor(sqrt((double)val));
    // 보정: y가 너무 작으면 늘려주기
    while (y*y < val) ++y;
    while ((y-1)*(y-1) >= val) --y;
    return y;
}

long long solution(int r1, int r2) {
    ll r1sq = (ll)r1 * r1;
    ll r2sq = (ll)r2 * r2;
    ll answer = 0;
    
    // x = 0 부터 r2 까지 검사
    for (int x = 0; x <= r2; ++x) {
        ll x2 = (ll)x * x;
        // y^2 >= r1^2 - x^2  그리고  y^2 <= r2^2 - x^2
        ll lowVal  = r1sq - x2;
        ll highVal = r2sq - x2;
        if (highVal < 0) continue;          // 어떤 y도 성립하지 않음
        ll ymin = isqrt_ceil(lowVal);
        ll ymax = isqrt_floor(highVal);
        if (ymax < ymin) continue;
        
        ll totalYs = ymax - ymin + 1;
        bool hasZero = (ymin == 0);
        
        // x=0일 때: (0, y)만 고려 → y≠0이면 ±y 두 점, y=0이면 한 점
        if (x == 0) {
            // y≠0: totalYs - hasZero 개, 각각 ± 대응 → 2*(totalYs - hasZero)
            // y=0: hasZero 개 (0 또는 1)
            answer += 2*(totalYs - hasZero) + (hasZero ? 1 : 0);
        }
        else {
            // x≠0일 때: x, -x 두 축 모두 고려
            // 각 축에 대해:
            //   y≠0: (totalYs - hasZero) 개, 각각 ±y → 2*(totalYs - hasZero)
            //   y=0: hasZero 개 → 1
            // 축 두 개이므로 위 결과에 ×2
            ll perAxis = 2*(totalYs - hasZero) + (hasZero ? 1 : 0);
            answer += perAxis * 2;
        }
    }
    
    return answer;
}
