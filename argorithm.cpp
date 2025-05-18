#include <vector>
#include <queue>
#include <numeric>  // accumulate 사용을 위해 포함

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    // 큐를 활용하기 위해 queue 컨테이너 사용
    queue<long long> q1, q2;
    long long sum1 = 0, sum2 = 0;

    // 큐 초기화 및 합 계산
    for (int num : queue1) {
        q1.push(num);
        sum1 += num;
    }
    for (int num : queue2) {
        q2.push(num);
        sum2 += num;
    }

    long long totalSum = sum1 + sum2;
    
    // 두 큐의 합이 홀수면 같아질 수 없음
    if (totalSum % 2 != 0) return -1;
    
    long long target = totalSum / 2;  // 목표 합
    int maxOperations = queue1.size() * 3;  // 최대 연산 횟수 제한 (모든 요소를 이동하는 경우)
    int operations = 0;

    // 투 포인터 방식 (q1이 더 크다면 pop하여 q2에 삽입)
    while (sum1 != target && operations < maxOperations) {
        if (sum1 > target) {  // q1의 합이 크다면 q1에서 pop하여 q2로 이동
            long long value = q1.front();
            q1.pop();
            sum1 -= value;
            sum2 += value;
            q2.push(value);
        } else {  // q2의 합이 크다면 q2에서 pop하여 q1으로 이동
            long long value = q2.front();
            q2.pop();
            sum2 -= value;
            sum1 += value;
            q1.push(value);
        }
        operations++;
    }

    return (sum1 == target) ? operations : -1;
}