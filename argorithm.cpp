#include <iostream>
#include <math.h>
#include <algorithm>
#include <list>
#include <stack> 
#include <queue>
using namespace std; 

#define X first 
#define Y second 

int board[305][305];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};


int n,m;

//몇년지났는지 세줌
int years=0;

int main(){ 
    ios::sync_with_stdio(0);  
    cin.tie(0); 

    cin>>n>>m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> board[i][j];
        }
    }



    //나뉜 덩어리가 2개이상이 될 동안 계속 진행 
    while(1){ 
        //변수들 초기화 
        int vis[305][305] = {};

        for(int i=0; i<305; i++){
            fill(vis[i], vis[i]+305, 0);
        }

        queue<pair<int,int>> q = {};
        int count=0;  //빙산 덩어리 몇갠지 세줌


        //하나씩 돌면서 만약 빙산칸 나오면 BFS 진행
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                
                //만약 0이거나 방문기록 있으면 패스 
                if(board[i][j] ==0 || vis[i][j]==1)
                    continue;

                //빙산칸 발견
                vis[i][j] = 1;
                q.push({i,j});
                count++;


                while(!q.empty()){
                    auto cur = q.front();
                    q.pop();

                    for(int i=0; i<4; i++){
                        int x = cur.X + dx[i];
                        int y = cur.Y + dy[i];
                        
                        //이미 방문한 칸이면 패스
                        if(vis[x][y] ==1)
                            continue;


                        //board값이 0이하가 아니고 빙산칸 주변의 0인칸이라면
                        if(board[x][y] == 0 && board[cur.X][cur.Y] !=0 ){
                            board[cur.X][cur.Y]--;
                        }

                         //빙산칸이라면
                        if(board[x][y] > 0){
                            vis[x][y] =1;
                            q.push({x,y});
                        }
                    }
                }
            }
        }
        //1년 지남
        years++; 
        
        //덩어리가 분리되지 않고 다 녺으면
        if(count == 0){
            cout<< 0;
            break;
        }

        //덩어리가 2개 이상일시
        if(count >= 2){ 
            cout << years-1;
            break;
        }
      
    }



    return 0;
}



