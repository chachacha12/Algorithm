#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// HH:MM 형태의 시간을 분 단위로 변환하는 함수
int timeToMinutes(const string& time) {
    int hours = stoi(time.substr(0, 2));  // 시간 부분 추출 후 정수 변환
    int minutes = stoi(time.substr(3, 2)); // 분 부분 추출 후 정수 변환
    return hours * 60 + minutes;  // 전체 분 단위로 변환하여 반환
}

int solution(vector<vector<string>> book_time) {
    vector<pair<int, int>> times; // {시작 시간, 종료 시간}을 저장할 벡터

    // 예약 시간을 분 단위로 변환하여 저장
    for (const auto& booking : book_time) {
        int start = timeToMinutes(booking[0]); // 시작 시간 변환
        int end = timeToMinutes(booking[1]) + 10; // 종료 시간 변환 + 청소 시간(10분)
        times.push_back({start, end});
    }

    // 시작 시간을 기준으로 정렬 (같은 경우 종료 시간 기준 정렬)
    sort(times.begin(), times.end());

    vector<int> rooms; // 현재 사용 중인 객실들의 종료 시간을 저장하는 벡터

    for (const auto& time : times) {
        int start = time.first, end = time.second;
        bool assigned = false;

        // 기존 방 중에서 사용 가능한 방이 있는지 확인
        for (int& roomEnd : rooms) {
            if (roomEnd <= start) { // 종료된 방이 있다면 새로운 예약을 배정
                roomEnd = end;
                assigned = true;
                break;
            }
        }

        // 기존 방 중 사용 가능한 것이 없다면 새로운 방 추가
        if (!assigned) {
            rooms.push_back(end);
        }
    }

    return rooms.size(); // 필요한 최소 객실 수 반환
}