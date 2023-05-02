
#include <iostream>
#include <math.h>
#include <algorithm>
#include <list>
#include <stack> 
#include <queue>
using namespace std; 

#define X first 
#define Y second 

string board[102];

int dist[102][102];




int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};


int main(){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n,m;
    cin>>n>>m; 
    
    for(int i=0; i<n;i++){
        cin>>board[i];
    }

    
    for(int i=0; i<n;i++){
        fill(dist[i], dist[i]+m, -1);
    }

    queue<pair<int, int>> Q;

    Q.push({0,0});
    dist[0][0]=1;

    while(!Q.empty() ){
        pair<int, int> p = Q.front();
        Q.pop();

        for(int i=0; i<4; i++){
            int x = p.X +dx[i];
            int y = p.Y +dy[i];

            if(x < 0|| x>=n || y <0 || y>=m)
                continue;

            if(board[x][y] !='1' ||  dist[x][y] != -1 )
                continue;

            Q.push({x,y});
            dist[x][y] = dist[p.X][p.Y] +1;    
        }
    }

    cout<<dist[n-1][m-1];

    return 0;
}


