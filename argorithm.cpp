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


  /*
  테이블 정의:
  d[i] = i는 연산을 사용하는 횟수의 최솟값 
  
  점화식:
  d[k] = d[k-1]+1, d[k/2]+1, d[k/3]+1


  초기값:
  
  */
  cin>>n;
  d[1] = 0;

  for(int i=2; i<=n; i++){
    d[i] = d[i-1]+1;
    if(i%2==0) d[i] = min(d[i], d[i/2]+1);
    if(i%3==0) d[i] = min(d[i], d[i/3]+1);
  }

  cout<<d[n];




 


  return 0;
}

