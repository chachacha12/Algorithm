#include <iostream>
#include <math.h>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
using namespace std; 



int n;
int t;
int d[42][1];


int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0); 


  /*
  테이블 정의:
  d[i][0] = i일때 0이 출력되는 횟수
  d[i][1] = i일때 1이 출력되는 횟수 
  
  d[0][0] = 1
  d[1][0] = 0
  d[2][0] = 1
  d[3][0] = 1
  d[4]    = 2
  d[5]    = 3
  d[6]    = 5

  d[0][1] = 0
  d[1][1] = 1
  d[2][1] = 1
  d[3][1] = 2
  d[4]    = 3
  d[5]    = 5
  d[6]    = 8


  점화식:
  d[k][0] = d[k-1][0] + d[k-2][0] 
  d[k][1] = d[k-1][1] + d[k-2][1]

  초기값:

  */

 cin>>t;

 d[0][0] = 1;
 d[1][0] = 0;

 d[0][1] = 0;
 d[1][1] = 1;

 while(t--){
  cin>>n;
  
  for(int i=2; i<=n; i++){
    d[i][0] = d[i-1][0] + d[i-2][0];
    d[i][1] = d[i-1][1] + d[i-2][1];
  }

  cout<<d[n][0]<<" "<<d[n][1]<<"\n";

 }

 
  return 0;
}

