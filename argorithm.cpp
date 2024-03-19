#include <iostream>
#include <math.h>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
using namespace std; 

int n;
long long t[1500005];
long long p[1500005];
long long d[1500005];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0); 

  /*
  테이블 정의:
  d[i] = i일까지 했을때 얻을 수 있는 최대 이익(뒤부터)

  점화식:
  
  if(n+tn <= n+1)  //범위에 들어서 상담을 할지 말지 정할 수 있는 경우
  d[i] = max( pi+d[d[i+ti]], d[i+1] )

  
  -시간오버로 아예 상담을 시도조차 못할경우
  d[i] = d[i+1]


  */

 cin>>n;

 for(int i=1; i<=n; i++){
  cin>>t[i]>>p[i];
 }

 for(int i=n; i>=1; i--){
   if(i+t[i] <= n+1) {
      d[i] = max( p[i]+d[i+t[i]], d[i+1]);
   }else{
      d[i] = d[i+1];
   }
 }

  cout<<d[1];
  

  return 0;
}

