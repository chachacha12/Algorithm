#include <iostream>
#include <math.h>
#include <algorithm>
#include <list>
#include <stack> 
#include <queue>
using namespace std; 

#define X first 
#define Y second 

string board[28];
bool vis[28][28];

int dx[4]= {1,0,-1,0};
int dy[4]= {0,1,0,-1}; 

 queue<pair<int,int>> q;

int n;

int main(){ 
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> ans;  
    int count=0;  //단지의 갯수

    cin>>n;

    for(int i=0; i<n; i++){
          cin>>board[i];
    }




    //한칸씩 돌면서 확인하다가 1인칸 나오면 바로 BFS실행
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){ 

            if(board[i][j]=='0' || vis[i][j]==1)
                continue; 

            q.push({i,j});
            vis[i][j] = 1;
            count++;  //단지갯수 증가시켜줌
            int size = 1;  // 단지 하나의 크기

            while(!q.empty()){
                auto cur = q.front();
                q.pop();

                for(int i=0; i<4; i++){
                    int x = cur.X + dx[i];
                    int y = cur.Y + dy[i];

                    if(x<0 || x>=n || y<0 || y>=n)
                        continue;
                    if(board[x][y] =='0' || vis[x][y] ==1)
                        continue;
                    
                    q.push({x,y});
                    vis[x][y] = 1;
                    size++;

                }
            }
            ans.push_back(size);
        }
    }
    

    cout<<count<<'\n';
    
    sort(ans.begin(), ans.end());  //오름차순정렬

    for(int i: ans){
        cout<< i <<'\n';
    }

    return 0;
}



