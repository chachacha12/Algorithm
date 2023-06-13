
#include <iostream>
#include <math.h>
#include <algorithm>
#include <list>
#include <stack> 
#include <queue>
using namespace std; 


#define X first 
#define Y second 

int board[302][302];
int dist[302][302];
queue<pair<int,int>> q;

int t;
int dx[8] = {-1,-2,-2,-1,1,2,2,1};
int dy[8] = {2,1,-1,-2,-2,-1,1,2};


int main(){ 
    ios::sync_with_stdio(0);
    cin.tie(0);


    cin>>t;

    while(t--){
        int length;  //한변의 길이
        int startx, starty;
        int endx, endy;

        cin>>length;
        cin>>startx>>starty;
        cin>>endx>>endy;
        
         for(int i=0; i<length; i++){
             fill(dist[i], dist[i]+length, -1);
        }

        q.push({startx, starty});
        dist[startx][starty] = 0;
        
        ///BFS 진행
        while(!q.empty()){
            auto cur = q.front();
            q.pop();

            for(int i=0; i<8; i++){ 
                int x = cur.X +dx[i];
                int y = cur.Y +dy[i]; 

                //범위벗어나면 패스
                if(x<0 || x>=length || y<0|| y>=length )
                    continue;
                //이미 방문한 곳이면 패스
                if(dist[x][y]>=0)
                    continue;
                
                q.push({x,y});
                dist[x][y] = dist[cur.X][cur.Y] +1;
            }
        }

        cout<<dist[endx][endy]<<"\n";
    }

    return 0;
}


