#include <iostream>
#include <math.h>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
using namespace std; 

int n,m;

int dx[4] ={1,0,-1,0};
int dy[4] = {0,1,0,-1};
int board[505][505];
bool vis[505][505];
queue<pair<int,int>> q;

int num;
int maxsize;

int main(void){ 
  ios::sync_with_stdio(0);
  cin.tie(0); 

  cin>>n>>m;

  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      cin>>board[i][j];
    }
  }

  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      if(board[i][j]==0 || vis[i][j]==1)
        continue;

       num++; //그림 갯수 1증가
       int size=1;
      
       vis[i][j]=1;
       q.push({i,j});

        while(!q.empty()){
          auto cur = q.front();
          q.pop();

          for(int i=0; i<4; i++){
              int x = cur.first + dx[i];
              int y = cur.second + dy[i];

              if(x<0 || x>=n || y<0 || y>=m)
                continue;
              
              if(vis[x][y]==1 || board[x][y]==0)
                continue;
              
              vis[x][y]=1;
              q.push({x,y});
              size++;
          }
        } 
        maxsize = max(size, maxsize); //크기 최댓값 업뎃 
      
    }
  }

  if(num==0)
    cout<<num<<'\n'<<"0";
  else
    cout<<num<<'\n'<<maxsize;

  



  return 0;
}












