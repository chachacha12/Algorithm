#include <iostream>
#include <math.h>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
using namespace std; 

int t,n;
long long d[105];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0); 

  /*
  테이블 정의:
  d[i] = i번째 정삼각형의 변의 길이
  
  점화식:
  d[k] = d[k-1]+d[k-5] 

  
  */

 cin>>t;

 d[1] =1, d[2]=1, d[3]=1, d[4]=2, d[5]=2;

 for(int i=6; i<=101; i++){
  d[i] = d[i-1]+d[i-5];
 }

while(t--){
  cin>>n;
  cout<<d[n]<<'\n';
}

 


  return 0;
}

