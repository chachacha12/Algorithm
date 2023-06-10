
#include <iostream>
#include <math.h>
#include <algorithm>
#include <list>
#include <stack> 
#include <queue>
using namespace std; 

#define X first
#define T second 

///3차원
int board[102][102][102];
int dist[102][102][102];

queue<tuple<int,int,int> > q;

int dx[6] = {1,0,-1,0,0,0};
int dy[6] = {0,1,0,-1,0,0};
int dh[6] = {0,0,0,0,1,-1};

int m, n, h;



int main(){ 
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>> m>>n>>h;

    
    ///입력받기
    for(int floor =0; floor<h; floor++){
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>board[j][i][floor]; 

                ///여러곳에서 동시에 진행하는 BFS는 입력받을때 큐에 넣어줌
                if(board[j][i][floor] == 1){
                    q.push({j, i, floor});
                    dist[j][i][floor] = 0;
                }else{
                    dist[j][i][floor] = -1;
                }
                   
            }
        }
    }

    ///3차원에서의 BFS 진행
    while(!q.empty()){
        auto cur = q.front();
        q.pop();

        for(int i=0; i<6; i++){
            int x = get<0>(cur) + dx[i]; 
            int y = get<1>(cur) + dy[i];
            int z = get<2>(cur) + dh[i];
            
            ///범위 벗어날경우
            if(x<0 || x>=m || y < 0 || y>=n || z <0 || z>=h)
                continue;
            
            ///이미 방문한 곳일경우 or 빈 칸일 경우
            if(dist[x][y][z]>=0 || board[x][y][z] == -1)
                continue;
            
            ///처음 방문하는 곳인경우
            dist[x][y][z] = dist[get<0>(cur)][ get<1>(cur)][get<2>(cur)] +1;
            q.push({x,y,z});
        }
    }
    
    ///최소날수
    int mx=0;


    for(int floor =0; floor<h; floor++){
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                
                
                ///모든 토마토가 익지 못할때
                if(board[j][i][floor]==0 && dist[j][i][floor] ==-1){
                     cout<<-1; 
                     return 0;  
                }

                if(dist[j][i][floor] > mx ){
                    mx = dist[j][i][floor];
                }   
                   
            }
        }
    }

     cout<<mx;
    

    return 0;
}


