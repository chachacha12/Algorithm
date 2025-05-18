#include <iostream>
#include <vector>

using namespace std;

vector<int> discountRates = {10, 20, 30, 40}; // 가능한 할인율 목록
int maxSubscribers = 0;  // 최대 가입자 수
int maxRevenue = 0;      // 최대 매출액

// 할인율 조합을 생성하고 계산하는 재귀 함수
void calculateMaxResult(int index, vector<int>& emoticons, vector<int>& discountCombination, vector<vector<int>>& users) {
    if (index == emoticons.size()) { // 모든 이모티콘의 할인율을 설정했다면
        int subscribers = 0; // 현재 할인율에서의 가입자 수
        int revenue = 0;     // 현재 할인율에서의 총 매출액

        // 모든 사용자에 대해 구매 여부를 판단
        for (auto& user : users) {
            int userDiscountThreshold = user[0]; // 사용자가 원하는 최소 할인율
            int userPriceThreshold = user[1];    // 사용자가 가입을 고려하는 가격 기준

            int totalCost = 0;
            for (int i = 0; i < emoticons.size(); i++) {
                if (discountCombination[i] >= userDiscountThreshold) { // 사용자가 원하는 할인율 이상이면 구매
                    totalCost += emoticons[i] * (100 - discountCombination[i]) / 100;
                }
            }

            if (totalCost >= userPriceThreshold) { // 사용자가 가입 기준을 넘으면 이모티콘 구매 대신 서비스 가입
                subscribers++;
            } else {
                revenue += totalCost; // 이모티콘을 구매한 경우 매출액에 추가
            }
        }

        // 최적의 경우 갱신 (가입자 수 최우선, 그다음 매출액)
        if (subscribers > maxSubscribers || (subscribers == maxSubscribers && revenue > maxRevenue)) {
            maxSubscribers = subscribers;
            maxRevenue = revenue;
        }
        return;
    }

    // 현재 이모티콘에 대해 가능한 할인율을 설정하고 다음 이모티콘 처리
    for (int rate : discountRates) {
        discountCombination[index] = rate;
        calculateMaxResult(index + 1, emoticons, discountCombination, users);
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> discountCombination(emoticons.size()); // 이모티콘별 할인율 저장
    calculateMaxResult(0, emoticons, discountCombination, users); // 완전 탐색 시작
    return {maxSubscribers, maxRevenue}; // 최적의 가입자 수와 매출액 반환
}