#include <iostream>
#include <math.h>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
using namespace std; 


int n;
int d[1000005];

int main(void){ 
  ios::sync_with_stdio(0);
  cin.tie(0); 

  cin>>n;


  d[2] =1;
  d[3] =1;
  for(int i=4; i<=n; i++){
    if(i%3==0){
      d[i] = min(d[i/3],d[i-1])+1;
    }else if(i%2==0){
      d[i] = min(d[i/2],d[i-1])+1;
    }else{
      d[i] = d[i-1]+1;
    }
  }

  cout<<d[n];

}












