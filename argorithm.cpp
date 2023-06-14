#include <iostream>
#include <math.h>
#include <algorithm>
#include <list>
#include <stack> 
#include <queue>
using namespace std; 

#define X first 
#define Y second 

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

string board[1002];
int dist[1002][1002];
int dist2[1002][1002];

int t,w,h;

int main(){ 
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>t;

    while(t--){
        bool success = false;

        ///불의 BFS
        queue<pair<int,int>> q ={};

        ///상근이의 BFS
        queue<pair<int,int>> q2 = {};
       
        cin>>w>>h;

        for(int i=0;i<h; i++){
            fill(dist[i], dist[i]+w, -1);
            fill(dist2[i], dist2[i]+w, -1);        
        }
            
        for(int i=0; i<h; i++){
            cin>>board[i];
        }

        
        ///한번씩 쭉 돌면서 불과 상근이의 위치를 찾아서 큐에 넣어줌
        for(int i=0;i<h;i++){
            string s = board[i];
            for(int j=0; j<w; j++){
                //만약 불이면 큐에넣음
                if(s[j] == '*'){
                    q.push({i,j});
                    dist[i][j] = 0;
                }

                //만약 상근이면 큐2에 넣음
                 if(s[j] == '@'){
                    q2.push({i,j});
                    dist2[i][j] = 0;
                }
            }
        }

        //불의 BFS부터 시작하며 dist값을 채워주기
        while(!q.empty()){
            auto cur = q.front();
            q.pop();

            for(int i=0; i<4; i++){
                int x = cur.X +dx[i];
                int y = cur.Y +dy[i];

                //범위 벗어나면 패스
                if(x<0 || x>=h || y<0 || y>=w )
                    continue;
                //벽이 있으면 패스, 이미 지난곳이면 패스
                if(board[x][y]=='#' || dist[x][y] >=0 )
                    continue;
                
                dist[x][y] = dist[cur.X][cur.Y]+1;  
                q.push({x,y});
            }
        }
    

         //상근이의 BFS 시작하며 dist2값을 채워주기
        while(!q2.empty() && !success ){
            auto cur = q2.front();
            q2.pop();

            for(int i=0; i<4; i++){
                int x = cur.X +dx[i];
                int y = cur.Y +dy[i];

                //범위 벗어나면 탈출성공인것임
                if(x<0 || x>=h || y<0 || y>=w ){ 
                    cout<< dist2[cur.X][cur.Y]+1<<'\n'; 
                    success = true;
                    break;
                }

                //벽이 있으면 패스, 이미 지난곳이면 패스 
                if(board[x][y]=='#' || dist2[x][y] >=0 )
                    continue;

                //불이 이미 지났거나 오는곳이면 패스
                if(dist[x][y] != -1  &&  dist[x][y] <= dist2[cur.X][cur.Y]+1  )
                    continue;

                
                dist2[x][y] = dist2[cur.X][cur.Y]+1;  
                q2.push({x,y});
            }
        }


        if(!success)
            cout<<"IMPOSSIBLE"<<'\n';

    }

    return 0;
}


