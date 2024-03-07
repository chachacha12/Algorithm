#include <iostream>
#include <math.h>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
using namespace std; 


int n;
long long d[100];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0); 


  /*
  테이블 정의:
  d[i] = i자리 이친수의 개수

10000

  d[1] = 1
  d[2] = 1
  d[3] = 2
  d[4] = 3
  d[5] = 5

  점화식:
  d[k] = d[k-1] + d[k-2]

  */

 cin>>n;

  d[1] = 1;
  d[2] = 1;

  for(int i=3; i<=n; i++){
    d[i] = d[i-1] + d[i-2];
  }

  cout<<d[n];


 

  return 0;
}

