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

  
  
  /*
  테이블: d[i] = 정수 i가 연산을 쓰는 최소 횟수

  점화식: d[k] = d[k-1] +1
  */

 d[0] = 0;
 d[1] = 0;
 d[2] = 1;
 d[3] = 1;


 for(int i=4; i<1000002; i++){
    
    d[i] = d[i-1]+1;
    if(i%2==0){
      d[i] = min(d[i], d[i/2]+1);
    }
    if(i%3==0){
      d[i] = min(d[i], d[i/3]+1);
    }
 }
 
  cout<<d[n];


  
  return 0;
}












