#include <iostream>
#include <math.h>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
using namespace std; 

int n;
int R[1005];
int G[1005];
int B[1005];
int d[1005][3];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0); 

  /*

  테이블 정의: 
  d[i][0] = i번째 집을 빨강으로 칠했을때 비용의 최솟값
  d[i][1] = i번째 집을 초록으로 칠했을때 비용의 최솟값
  d[i][2] = i번째 집을 파랑으로 칠했을때 비용의 최솟값

  점화식:
  d[k][0] = min(d[k-1][1], d[k-1][2]) + R[k]
  d[k][1] = min(d[k-1][0], d[k-1][2]) + G[k]
  d[k][2] = min(d[k-1][1], d[k-1][0]) + B[k]

  초기값: 
  d[1][0] = R[1]
  d[1][1] = G[1]
  d[1][2] = B[1]
  */

  cin>>n;

  for(int i=1; i<=n; i++){
    cin>>R[i] >>G[i]>> B[i];
  }

  d[1][0] = R[1];
  d[1][1] = G[1];
  d[1][2] = B[1];

  for(int k=2; k<=n; k++){
    d[k][0] = min(d[k-1][1], d[k-1][2]) + R[k];
    d[k][1] = min(d[k-1][0], d[k-1][2]) + G[k];
    d[k][2] = min(d[k-1][1], d[k-1][0]) + B[k];
  }


  cout<< min({d[n][0], d[n][1], d[n][2]});

  
  return 0;
}

