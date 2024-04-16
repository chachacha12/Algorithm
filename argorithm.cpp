#include <iostream>
#include <math.h>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
using namespace std; 


#define X first
#define Y second

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

queue<pair<int, int>> q;

string board[102];
int vis[102][102];

int n,m;

int main(void){ 
  ios::sync_with_stdio(0);
  cin.tie(0); 

  cin>>n>>m;

  for(int i=0; i<n; i++){
    cin>>board[i];
  }


  q.push({0,0});
  vis[0][0] = 1;

  while(!q.empty()){
    auto cur = q.front();
    q.pop();
    
    for(int i=0; i<4; i++){
      int x = cur.X+dx[i];
      int y = cur.Y+dy[i];

      if(x<0 || x >= n || y<0 || y>=m  )
        continue;

      if(board[x][y] == '0' || vis[x][y] > 0 )
        continue;
      
      q.push({x,y});
      vis[x][y] = vis[cur.X][cur.Y]+1;
    }
  }

   cout<<vis[n-1][m-1];

  
  return 0;
}












