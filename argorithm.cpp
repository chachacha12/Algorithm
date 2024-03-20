#include <iostream>
#include <math.h>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
using namespace std; 

int t,n,m;
int a[25];
int d[10005];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0); 

  /*
  테이블 정의:
  d[i] = i원 만드는 방법의 수


  점화식:
  d[i] = d[i]+d[i-a[i]]

  */

 cin>>t;

 while(t--){
  fill(d, d+10005,0);
  cin>>n;

    //동전 종류들 저장
  for(int i=0; i<n; i++ ){
    cin>>a[i];
  }

  cin>>m;

  d[0] = 1;

  for(int i=0; i<n; i++){   //동전갯수만큼 반복. 즉 새로운 동전이 추가될때마다 d[i]값은 갱신해줌
    for(int j=a[i]; j<=m; j++){   
      d[j] = d[j] + d[j-a[i]];  
    }
  }

  cout<<d[m]<<"\n";


 }




 





  return 0;
}

