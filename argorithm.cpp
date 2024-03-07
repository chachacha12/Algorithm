#include <iostream>
#include <math.h>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
using namespace std; 


int n;
int d[100005];
int a[100005];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0); 


  /*
  테이블 정의:
  d[i] = i번째 까지 봤을때 구할 수 있는 최댓값


  점화식:
  d[k] = max( d[k-1] +a[k], a[k] )  
  

  */

 cin>>n;
 for(int i=1; i<=n; i++){
  cin>>a[i];
 }

d[1] = a[1];


int result = a[1];

 for(int i=2; i<=n; i++){
   d[i] = max( d[i-1] +a[i], a[i] ) ;
   if(result<d[i]) result = d[i];
 }

 cout<<result;


  return 0;
}

