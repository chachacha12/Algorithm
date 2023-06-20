#include <iostream>
#include <math.h>
#include <algorithm>
#include <list>
#include <stack> 
#include <queue>
using namespace std; 


int vis[1000003];

queue<int> q;  //x값만 저장하면 되므로

int f,s,g,u,d;

int main(){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>f>>s>>g>>u>>d;


    fill(vis+1, vis+f+1,-1);

    q.push(s);
    vis[s] = 0;

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        
        for(int nxt : {cur+u,cur-d}  ){

            if(nxt<=0 || nxt > f)
                continue;
            
            if(vis[nxt] >=0 )
                continue;

            q.push(nxt);
            vis[nxt] = vis[cur]+1;

            
        }
    }

  if(vis[g] == -1) cout << "use the stairs";
  else cout << vis[g];


    


    return 0;
}



