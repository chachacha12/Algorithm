
#include <iostream>
#include <math.h>
#include <algorithm>
#include <list>
#include <stack> 
#include <queue>
using namespace std; 

//BFS 응용4 - 1차원에서의 BFS

#define X first 
#define Y Second 

int dist[100002]; 
queue<int> Q;
int dx[2] = {1, -1};


int n,k;


int main(){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>n>>k;  //n은 수빈이 위치, k는 동생위치 

    fill(dist, dist+100001, -1);
    
    Q.push(n); 
    dist[n] = 0;

   while(dist[k] == -1 ){  // !Q.empty()하지말고 이렇게 해야 시작점과 정답지점이 같을때도 종료가됨. 
        int cur = Q.front();
        Q.pop();

        for(int num : {cur-1, cur+1, cur*2}){
            
             if(num<0 || num> 100000)  //범위 벗어나면 패스
                continue;
             if(dist[num]>=0) //이미 방문한 곳이면 패스
                 continue;
             
             Q.push(num);
             dist[num] = dist[cur]+1;
        }
    }
    cout<<dist[k];
   
    return 0;
}


