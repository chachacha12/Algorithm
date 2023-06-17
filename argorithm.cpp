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

int board[102][102];
int vis[102][102];
int num = 0; //구역의 갯수

int m,n,k; 

int main(){ 
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>m>>n>>k; 


    //직사각형 수만큼 반복
    while(k--){
        int leftx, lefty, rightx, righty; 
        cin >> leftx >> lefty >> rightx >> righty;
        
        //직사각형이 있는 좌표들의 board값을 1로 해주기 
        for(int i=lefty; i < righty; i++){
            for(int j=leftx; j < rightx; j++){
                vis[i][j] = 1;
            }
        }
    }

    int size[100] = {};

    //한칸씩 방문하면서 BFS 진행
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){

            queue<pair<int,int>> q;
            
            //방문한적 없거나 벽이 아니라면 - 구역중 한 칸에 들어온거임
            if(vis[i][j] != 1 ){
                num++;
                int sum = 0; //구역의 크기를 저장할 녀석
                q.push({i,j});
                vis[i][j] = 1;
                
                //BFS진행
                while(!q.empty()){
                    auto cur = q.front();
                    q.pop(); 
                    
                    for(int i=0; i<4; i++){  
                        int x = cur.X + dx[i];
                        int y = cur.Y + dy[i];
                        
                        //범위지나면 패스
                        if(x<0 || x>=m || y<0 || y>=n)
                            continue;
                        
                        //방문한적 있으면
                        if(vis[x][y] == 1)
                            continue;
                        
                        q.push({x,y});
                        vis[x][y] = 1;
                        sum++;
                    } 
                }  
                //구역의 크기를 저장
                size[--num] = sum; 
                num++; 
            }

        }
    }

    //오름차순 정렬
    sort(size, size+num);

    cout << num<<'\n';
    
    for(int i=0; i<num; i++){
        cout << size[i]+1<<' ';   
    }
    
    

    

    return 0;
}


