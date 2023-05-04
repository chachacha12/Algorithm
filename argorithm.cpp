
#include <iostream>
#include <math.h>
#include <algorithm>
#include <list>
#include <stack> 
#include <queue>
using namespace std; 

#define X first 
#define Y second 

int board[1002][1002];
int dist[1002][1002]; 

queue<pair<int,int>> Q;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};


int main(){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n,m;
    cin >>n>>m;

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin>>board[i][j];   
            
            if(board[i][j]==1){  //익은 토마토면 큐에 넣음
                Q.push({i,j});
            }
        }
    }

    while(!Q.empty()){
        pair<int,int> p = Q.front();
        Q.pop();

        for(int i=0; i<4;i++){
            int x = p.X +dx[i];
            int y = p.Y +dy[i];

            if(x<0 || x>=m || y<0 || y>=n)  //board값의 좌표를 벗어난경우 패스
                continue;
            if(board[x][y] != 0  ) // 안익은 토마토인 경우 제외하고 나머지(토마토없거나, 익은토마토)는 모두 패스
                continue;

            Q.push({x,y});
            dist[x][y] = dist[p.X][p.Y] +1;
            board[x][y] = 1;  //방문한 곳들은 1로 변경
        }
    }
    
    int ans=0;

    //만약 하나라도 안익는 토마토가 있다면 -1, 없다면 거리값 젤 큰값
    for(int i=0; i<m;i++){
        for(int j=0; j<n;j++){
            if(board[i][j]==0 ){
                cout<<-1;
                return 0;
            } 
            ans = max(ans, dist[i][j]);
            
        }
    }

    cout<<ans;


    return 0;
}


