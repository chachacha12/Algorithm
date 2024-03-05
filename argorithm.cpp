#include <iostream>
#include <math.h>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
using namespace std; 


int d[1005];
int n;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0); 

 /*
 테이블 정의:
 d[i] = 2*i 크기의 직사각형을 채우는 방법의 수

 점화식:
 d[k] = d[k-1] +d[k-2]
  

 초기값:
 d[1] = 1
 d[2] = 2
 d[3] = 3
 
 */

  cin>>n;

  d[1] = 1;
  d[2] = 2;

  for(int i=3; i<=n; i++){
    int sum = d[i-1]+d[i-2];
    d[i] = sum%10007;
  }

  cout<<d[n];





  return 0;
}

