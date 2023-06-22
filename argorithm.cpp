#include <iostream>
#include <math.h>
#include <algorithm>
#include <list>
#include <stack> 
#include <queue>
using namespace std; 

#define X first 
#define Y second 

int board[102][102];
bool vis[102][102];

int dx[4] = {1,0,-1,0};
int dy[4] = {0, 1, 0 ,-1};

int n;

int maxheight; //잠길수있는 물의 최대 높이

int result;



int main(){ 
    ios::sync_with_stdio(0);  
    cin.tie(0); 
    
    cin>>n;

    for(int i=0; i<n; i++){
         for(int j=0; j<n; j++){
            cin>>board[i][j]; 

            maxheight = max(maxheight,board[i][j]);
         }
    }

    //물높이를 0부터 잠길수있는 최대 높이까지 하나씩 해보며 BFS돌려서 몇개의 영역이 생기는지 확인해서 max값을 저장
    for(int h=0; h<maxheight; h++){
        //큐와 vis값은 새로운 물높이일때마다 초기화 해줘야함. 
        queue<pair<int, int>> q;
       
       // 방문배열 초기화
        for(int i = 0; i < n; i++)
             fill(vis[i], vis[i]+n, 0); 

        int count=0;
        
        //한칸씩 움직이면서 BFS진행
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                
                //물에 잠겼거나 방문했으면 패스 
                if(h >= board[i][j] || vis[i][j] == 1 )
                    continue;
                
                //새로운 하나의 영역을 찾은거임 
                count++; 
                
                q.push({i,j});
                vis[i][j] = 1;

                while(!q.empty()){
                    auto cur = q.front();
                    q.pop();
                    
                    for(int i=0; i<4; i++){
                        int x = cur.X + dx[i];
                        int y = cur.Y + dy[i];
                        
                        if(x<0 || x>=n || y <0 || y>=n)
                            continue;

                        //높이가 물높이 이하거나 이미 방문했으면 패스
                        if(board[x][y] <= h ||  vis[x][y] == 1 )
                            continue;
                        
                        q.push({x,y});
                        vis[x][y] =1;
                    }
                }

            }
        }

        //더 큰 값을 비교해서 저장
        result = max(result, count);

    }

    cout<<result;




    return 0;
}



