
#include <iostream>
#include <math.h>
#include <algorithm>
#include <list>
#include <stack> 
#include <queue>
using namespace std; 

#define X first 
#define Y second 

int dist[52][52];

int t;
int m,n,k;

int sum;

queue<pair<int,int>> Q;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};



int main(){ 
    ios::sync_with_stdio(0);
    cin.tie(0);


    cin>>t;

    //테스트 케이스 수만큼 진행
    while(t--){
        sum = 0; //필요한 지렁이 갯수
        for(int i=0; i<52; i++){
             fill(dist[i], dist[i]+52, 0);  //판 초기화
        }
       
        
        cin>>m>>n>>k;
        //존재하는 배추갯수만큼 반복
        while(k--){
            int x,y;
            cin>>x>>y;
            dist[x][y] = 1;
        }

        for(int i=0; i<m;i++){
            for(int j=0; j<n;j++){
                if(dist[i][j]==1){
                    sum++;
                    Q.push({i,j}); 
                    dist[i][j] = 0; 

                    while(!Q.empty()){
                        auto cur = Q.front();
                        Q.pop();

                        for(int i=0;i<4;i++){
                            int x = cur.X + dx[i];
                            int y = cur.Y + dy[i];

                            //범위를 벗어났다면 패스
                            if(x<0 || x>=m || y <0 || y>=n ) 
                                continue;
                            
                            if(dist[x][y]== 0) //이미 방문했거나 배추가 없는 곳이면 패스
                                continue;

                            Q.push({x,y});
                            dist[x][y] = 0;
                        }
                    }
   
                }

            }
        }

        cout<<sum;

    }


   
   
    return 0;
}


