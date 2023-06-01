
#include <iostream>
#include <math.h>
#include <algorithm>
#include <list>
#include <stack> 
#include <queue>
using namespace std; 

#define X first 
#define Y second 

queue<pair<int,int>> q;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int n;

int sum, sum2;

int main(){ 
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    string board[n];
    int dist[n][n];

    for(int i=0; i<n; i++){
        fill(dist[i], dist[i]+n, -1);
    }

    
    for(int i=0; i<n; i++){
        cin >>board[i];
    }

    //원소를 하나하나 돔 - 적록색약인 사람인경우
    for(int i=0; i<n;i++){
        for(int j=0; j<n; j++){

            if(dist[i][j]== -1){ //아직 방문안한 곳이라면
                
                sum++;

                 dist[i][j] = 0;
                 q.push({i,j});

                 char c = board[i][j];

                  while(!q.empty()){
                      auto cur = q.front();
                      q.pop();
                
                        for(int i=0;i<4;i++){
                            int x = cur.X + dx[i];
                            int y = cur.Y + dy[i];

                            if(x<0 || x>=n || y<0 || y>=n)
                                continue;

                            //방문한 곳이거나 문자가 다른거라면 패스
                            if(dist[x][y] >= 0 || board[x][y] !=  c )
                                continue;

                            dist[x][y] = 0;
                            q.push({x,y});
                        }
                }
            }
        }
    }

    //dist 다시 초기화
    for(int i=0; i<n; i++){
        fill(dist[i], dist[i]+n, -1);
    }

    for(int i=0; i<n;i++){
        for(int j=0; j<n; j++){
            if(board[i][j] == 'R'){
                board[i][j] = 'G';
            }
        }
    }

    //원소를 하나하나 돔 - 적록색약 아닌경우
    for(int i=0; i<n;i++){
        for(int j=0; j<n; j++){

            if(dist[i][j]== -1){ //아직 방문안한 곳이라면
                
                sum2++;

                 dist[i][j] = 0;
                 q.push({i,j});


                 char c = board[i][j];
            

                  while(!q.empty()){
                      auto cur = q.front();
                      q.pop();
                
                        for(int i=0;i<4;i++){
                            int x = cur.X + dx[i];
                            int y = cur.Y + dy[i];

                            if(x<0 || x>=n || y<0 || y>=n)
                                continue;

                            //방문한 곳이거나 문자가 다른거라면 패스
                            if(dist[x][y] >= 0 || board[x][y] !=  c )
                                continue;

                            dist[x][y] = 0;
                            q.push({x,y});
                        }
                }
            }
        }
    }

    cout << sum<<' '<<sum2;

   
    return 0;
}


