#include <iostream>
#include <math.h>
#include <algorithm>
#include <list>
#include <stack> 
#include <queue>
using namespace std; 

char board[32][32][32];
int dist[32][32][32];

int dh[6] = {0,0,0,0,-1,1};
int dx[6] = {1,-1,0,0,0,0};
int dy[6] = {0,0,1,-1,0,0};


int main(){ 
    ios::sync_with_stdio(0);  
    cin.tie(0); 

    while(true){
        queue<tuple<int, int, int>> q;
        int l,r,c;
        cin >> l >> r >> c;

          //종료
        if(l==0 && r == 0 && c==0)
            return 0; 
        
          //dist값 초기화
          for(int i=0; i<l; i++){
            for(int j=0; j<r; j++){
                for(int k = 0; k<c; k++){
                    dist[i][j][k] = -1;
                }
            }
        }

        //입력받아서 board값 채움
        for(int i=0; i<l; i++){
            for(int j=0; j<r; j++){
                for(int k = 0; k<c; k++){
                    cin>>board[i][j][k];
                    
                    //시작점을 큐에 넣음
                    if(board[i][j][k] == 'S'){
                        dist[i][j][k] =0;
                        q.push({i,j,k});
                    }
                        
                }
            }
            //cout<<"\n"; 
        }

        bool escape = false;
        
        ///BFS진행
        while(!q.empty()){
            auto cur = q.front();
            q.pop();

            for(int i=0; i<6; i++){
                int h = get<0>(cur) +dh[i];
                int y = get<1>(cur) +dy[i];
                int x = get<2>(cur) +dx[i];
                
                if(h < 0 || h>=l || y<0 || y >= r || x <0 || x>= c)
                    continue;

                //탈출지점 도착시
                if(board[h][y][x] == 'E'){
                    cout<<"Escaped in "<< dist[get<0>(cur)][get<1>(cur)][get<2>(cur)] +1<<" minute(s)."<<"\n";
                    escape = true;
                    break;
                }
                
                //벽이거나 이미 방문한곳이면 패스
                if(board[h][y][x] == '#'  || dist[h][y][x] >= 0 )
                    continue;
                
                dist[h][y][x] = dist[get<0>(cur)][get<1>(cur)][get<2>(cur)] +1;
                q.push({h,y,x});
            }

            if(escape){
                  break;
            }  
        }

        if(!escape)
            cout<<"Trapped!"<<"\n";


    
    }







    return 0;
}



