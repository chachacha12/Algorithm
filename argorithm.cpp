#include <iostream>
#include <math.h>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
using namespace std; 


int n;
int d[305][2];
int a[305];

int main(void){ 
  ios::sync_with_stdio(0);
  cin.tie(0); 

 /*
 테이블: d[i][0] = i번째까지 갔을때 이전계단을 밟았을때 최댓값 (i번째는 무조건 밟음)
        d[i][1] = i번째까지 갔을때 이전계단을 안 밟았을때 최댓값 (i번째는 무조건 밟음)

 점화식: 

 */



  cin>>n;
  for(int i=1; i<=n; i++){
    cin>>a[i];
  }

  d[1][0] = a[1];
  d[1][1] = a[1];

  d[2][0] = a[1]+a[2];
  d[2][1] = a[2];



  for(int i=3; i<=n; i++){
     d[i][0] = d[i-1][1] + a[i];
     d[i][1] = max(d[i-2][0], d[i-2][1] )+ a[i];
  }

  cout<<max(d[n][0], d[n][1]);




}












