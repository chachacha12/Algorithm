#include <iostream>
#include <math.h>
#include <algorithm>
#include <list>
#include <stack> 
#include <queue>

using namespace std; 

//큐 문제


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue<int> Q;
    int n;
    cin>>n;
    

    for(int i=1; i<=n; i++){
        Q.push(i);
    }

    while(Q.size() != 1){
        Q.pop();
        int a = Q.front();
        Q.push( a) ;
        Q.pop();
    }
     cout << Q.front();
    
    
    return 0;
}

