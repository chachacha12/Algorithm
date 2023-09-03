#include <iostream>
#include <math.h>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std; 

#define X first
#define Y second

int dx[4] ={1,0,-1,0};
int dy[4] ={0,1,0,-1};

int arr[502][502];
bool vis[502][502];

int n,m;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin>>n>>m;

  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      cin>>arr[i][j];
    }
  }

  int mx=0; //계속 업뎃되는 가장 큰 그림의 크기
  int num=0; //그림의 갯수

  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      
      //그림이 없는 칸이거나 방문한적 있는 칸일경우엔 패스
      if( arr[i][j]==0 || vis[i][j]) 
        continue;
      
      
        queue<pair<int,int>> q;
        num++;


        int size=0;
        q.push({i,j});
        vis[i][j] = 1;
        
        while(!q.empty()){  
          size++;
          auto cur = q.front();
          q.pop(); 

          for(int i=0; i<4; i++){
            int x = cur.X + dx[i];
            int y = cur.Y + dy[i];

            if(x<0 || x >=n || y<0 || y>=m)
              continue;

            if(arr[x][y]!=1 || vis[x][y] ==1)
              continue;

          
            vis[x][y] =1;
            q.push({x,y});
          }

        }
      mx = max(mx, size); //mx에 최댓값 저장
    }
  }

  cout<<num<<'\n';
  cout<<mx;
 

  

  return 0;
}








