#include <iostream>
#include <math.h>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
using namespace std; 


int d[15];
int t;


int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  //점화식 
  //  d[i] = d[i-1]    +  d[i-2]  + d[i-3]

  
  cin >>t;
  int n;

    d[1] = 1;
    d[2] = 2;
    d[3] = 4;

  while(t--){
    cin>>n;
  
    if(n>=4){
      for(int i=4; i<=n; i++){
        d[i] = d[i-1] + d[i-2] +d[i-3];
      }
      cout<<d[n]<<'\n';
    }else{
      cout<<d[n]<<'\n';
    }
  
  }

 
  
  return 0;
}

