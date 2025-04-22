#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> land) {
    int n = land.size();
    int m = land[0].size();
    vector<vector<int>> visited(n, vector<int>(m, 0));
    vector<int> colSum(m, 0);
    vector<bool> touched(m, false);
    vector<int> touchedCols;
    int dr[4] = {-1,1,0,0}, dc[4] = {0,0,-1,1};
    
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(land[i][j] == 1 && !visited[i][j]) {
                // BFS to find one oil component
                int size = 0;
                touchedCols.clear();
                queue<pair<int,int>> q;
                visited[i][j] = 1;
                q.push({i,j});
                
                while(!q.empty()) {
                    auto [r,c] = q.front(); q.pop();
                    ++size;
                    if(!touched[c]) {
                        touched[c] = true;
                        touchedCols.push_back(c);
                    }
                    for(int d = 0; d < 4; ++d) {
                        int nr = r + dr[d], nc = c + dc[d];
                        if(nr<0||nr>=n||nc<0||nc>=m) continue;
                        if(land[nr][nc] == 1 && !visited[nr][nc]) {
                            visited[nr][nc] = 1;
                            q.push({nr,nc});
                        }
                    }
                }
                
                // Add this component's size to each touched column
                for(int c : touchedCols) {
                    colSum[c] += size;
                    touched[c] = false;  // reset for next component
                }
            }
        }
    }
    
    // Find max oil sum among columns
    int answer = 0;
    for(int x : colSum) {
        answer = max(answer, x);
    }
    return answer;
}
