#include <iostream>
#include <math.h>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
using namespace std; 

int n,m;

int a[100005];
int d[100005];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0); 


  /*
  테이블 정의:
    d[i] = a[1]+a[2]+ .. +a[i]
    d[i] = d[i-1] +a[i] 

  점화식:
    d[i] = d[i-1] +a[i]

    i부터 j까지의 합 구하는 점화식:

    result = d[j]-d[i-1]


  초기값:
  d[0]
  
  */

 d[0] = 0; 

 cin>>n>>m;
 for(int i=1; i<=n; i++){
  cin>>a[i];

  d[i] = d[i-1]+a[i];
 }

 int i,j;
 while(m--){
  cin>>i>>j;
  cout<<d[j]-d[i-1]<<'\n';
 }


  return 0;
}

