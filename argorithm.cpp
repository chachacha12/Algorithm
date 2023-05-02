
#include <iostream>
#include <math.h>
#include <algorithm>
#include <list>
#include <stack> 
#include <queue>
using namespace std; 

#define X first
#define Y second

int board[502][502];
bool vis[502][502];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int num=0; //그림갯수
int mx=0; //젤 큰 그림 넓이


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin>>n>>m;
    
    for(int i=0; i<n;i++){
        for(int j=0; j<m; j++){
            cin>>board[i][j];
        } 
    }


    for(int i=0; i<n;i++){
        for(int j=0; j<m; j++){
            if( vis[i][j]==1 ||  board[i][j]==0 ){
                continue;
            }
            queue< pair<int,int> > Q;

            num++;
            Q.push( {i,j} );
            vis[i][j] = 1;

            int area=0; //현재 그림의 넓이 

            while( !Q.empty()){
                pair<int,int> p = Q.front();
                Q.pop();
                area++;

                for(int i=0; i<4; i++){
                    int x = p.X +dx[i];
                    int y = p.Y +dy[i];

                    if(x < 0 || x>=n  || y < 0 || y>=m)
                        continue;

                    if(board[x][y]==0 || vis[x][y] )
                        continue;
                    
                    Q.push( {x,y});
                    vis[x][y]=1;
                }

            }
            mx = max(mx,area);

        } 
    }

    cout<<num<<'\n'<<mx;
    


    return 0;
}


