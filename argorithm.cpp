
#include <iostream>
#include <math.h>
#include <algorithm>
#include <list>
#include <stack> 
#include <queue>
using namespace std; 

//BFS 응용3 - 시작점이 두 종류일때
// -> 이 문제는 두 시작점이 서로 독립적이라, 불의 BFS 먼저 진행하고 지훈이의 BFS를 진행해도 문제없이 해결됨.
//근데 두 시작점이 서로 상호작용하는 문제도 있음 (불과 소방수 등..) 즉, 하나씩 차례로 시작하면 안되는 문제도 있음. 이런건
//백트래킹으로 풀어야 해결가능해서 나중에 알아볼거임. 


#define X first 
#define Y second

string board[1002];
int n,m;

//불의 BFS를 돌리기 위한 것들
queue<pair<int,int>> Q;
int dist[1002][1002];

//지훈이의 BFS를 돌리기 위한 것들
queue<pair<int,int>> J;
int dist2[1002][1002];


int dx[4] ={1,0,-1,0};
int dy[4] = {0,1,0,-1};


int main(){ 
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;

    for(int i=0; i<n; i++){
        cin>>board[i];
    }

    for(int i=0; i<n; i++){
        fill(dist[i], dist[i]+m, -1);
        fill(dist2[i], dist2[i]+m, -1);
    }

    //불의 초기 위치 찾아서 큐에 삽입
    for(int i=0; i<n; i++){
        string s = board[i];
        for(int j=0; j<m; j++){
            if( s[j] == 'F'){
                Q.push({i,j}); //불일경우 Q 큐에
                dist[i][j] =0;
            
            }
            if( s[j] == 'J'){  //지훈이일경우 J 큐에
                J.push({i,j});
                dist2[i][j] =0;
            }
        }
    }

    //불의 BFS부터 돌면서 dist값을 다 기록하기 
    while(!Q.empty()){
        auto cur = Q.front();
        Q.pop();

        for(int i=0; i<4; i++){
            int x = cur.X + dx[i];
            int y = cur.Y + dy[i];
            
            //board 범위를 넘어간경우 패스
            if(x<0 || x>=n || y<0 || y>=m)
                continue;
            
            //이미 방문한경우 패스 
            if(dist[x][y] >= 0)
                continue;

            // board에 #이 있는 경우, 즉 벽으로 막힌경우
            if(board[x][y] == '#')
                continue;

            Q.push({x,y});
            dist[x][y] = dist[cur.X][cur.Y]+1;
        }
    }


    //이번엔 지훈이의 BFS를 돌면서 dist2값을 다 기록하기 - 근데 불이 이미 지나간 곳은 패스해야함
    while(!J.empty()){
        auto cur = J.front();
        J.pop();

         for(int i=0; i<4; i++){
            int x = cur.X + dx[i];
            int y = cur.Y + dy[i];
            
            //board 범위를 넘어간경우엔 탈출을 했다는 의미임
            if(x<0 || x>=n || y<0 || y>=m){
                cout<< dist2[cur.X][cur.Y]+1;
                return 0;
            }
               
            //이미 방문한경우 패스
            if(dist2[x][y] >= 0)
                continue; 

            // board에 #이나 불이 있는 경우 패스
            if(board[x][y] == '#' || board[x][y] =='F')
                continue;

            //불과 동시에 도달하거나 이미 불이 지나간경우 패스  ->   dist[x][y] !=-1  이 조건 없으면 틀린거처리됨
            if(dist[x][y] !=-1 &&  dist[x][y] <= dist2[cur.X][cur.Y]+1)
                continue;
            
            dist2[x][y] = dist2[cur.X][cur.Y]+1;
            J.push({x,y});
        
        }
    }

    cout<< "IMPOSSIBLE";

   
    return 0;
}


