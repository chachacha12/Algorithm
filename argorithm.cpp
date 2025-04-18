#include <string>
#include <vector>

using namespace std;

int solution(vector<int> wallet, vector<int> bill) {
    int w1 = wallet[0], w2 = wallet[1];
    int b0 = bill[0], b1 = bill[1];
    int answer = 0;
    // 지폐가 지갑에 들어갈 때까지 접기
    while (!((b0 <= w1 && b1 <= w2) || (b1 <= w1 && b0 <= w2))) {
        if (b0 > b1) {
            b0 /= 2;
        } else {
            b1 /= 2;
        }
        answer++;
    }
    return answer;
}
