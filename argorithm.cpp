#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> mats, vector<vector<string>> park) {
    int R = park.size();           // 공원의 행 개수
    int C = park[0].size();        // 공원의 열 개수

    // 가장 큰 돗자리부터 확인하기 위해 내림차순 정렬
    sort(mats.begin(), mats.end(), greater<int>());
    
    // mats에 있는 각 돗자리 크기에 대하여 검사
    for (int size : mats) {
        // 만약 돗자리 크기가 park 전체보다 크면 skip
        if (size > R || size > C) continue;
        
        // 가능한 시작 행, 열 위치에 대해 검사
        for (int i = 0; i <= R - size; i++) {
            for (int j = 0; j <= C - size; j++) {
                bool canPlace = true;
                // 현재 시작점 (i, j)에서 size x size 영역 검증
                for (int x = i; x < i + size && canPlace; x++) {
                    for (int y = j; y < j + size; y++) {
                        if (park[x][y] != "-1") {  // 해당 칸에 사람이 있으면
                            canPlace = false;
                            break;
                        }
                    }
                }
                // 만약 영역이 모두 비어 있다면 해당 크기를 반환
                if (canPlace) {
                    return size;
                }
            }
        }
    }
    
    // 모든 크기에서 찾지 못하면 -1 반환
    return -1;
}
