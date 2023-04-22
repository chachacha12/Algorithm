
#include <iostream>
#include <math.h>
#include <algorithm>
#include <list>
#include <stack> 
#include <queue>
using namespace std; 

#define X first
#define Y second


int board[502][502];  //모두 0으로 초기화
bool vis[502][502];  //방문여부 확인을 위함. 모두 0으로 초기화 되는듯?

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >>n>>m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m;j++){
            cin >> board[i][j];
        }
    }

    int mx=0; //계속 업뎃되는 가장 큰 그림의 크기
    int num=0; //그림의 갯수


    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
        
            //그림이 없는 칸이거나 방문한적 있는 칸일경우엔 패스
            if( board[i][j]==0 || vis[i][j]) 
                continue;
            
            num++; //전체 그림 갯수 1증가
            queue<pair<int, int>> Q;
            int area=0; //현재 그림의 크기 저장 변수 
            vis[i][j] = 1;
            Q.push({i,j});

            //하나의 그림을 반복문 돌면서 전부 방문함
            while( !Q.empty()){
                area++; //큐에 들은 원소를 하나 뺄때마다 넓이를 1증가
                pair<int, int> cur = Q.front();
                Q.pop();
                ///상하좌우칸 확인 로직 
                for(int i=0; i<4; i++){
                    int x = cur.X + dx[i];
                    int y = cur.Y + dy[i];
                    
                    //범위를 벗어나면 패스
                    if( x<0 ||  x>=n || y<0 || y>=m)
                        continue;
                    
                    //그림이 없거나 이미 방문한 칸이면 패스
                    if( board[x][y] !=1 || vis[x][y]) 
                        continue;

                    vis[x][y] =1;
                    Q.push({x,y});
                }
            }
            //이전에 저장된 가장 큰 그림과 현재 확인한 그림의 크기를 비교하여 더 큰 값을 저장 
            mx = max(area, mx);
        }
    }

    cout<<num<<'\n'<<mx;


    return 0;
}


