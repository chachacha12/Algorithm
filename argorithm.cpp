#include <iostream>
#include <math.h>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
using namespace std; 

int d[505][505];
int a[505][505];
int n;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0); 


  /*
  테이블 정의:
  d[i][j] = i층 j칸까지일때 최댓값


  점화식:
  d[i][j] =  max(d[i-1][j-1], d[i-1][j]) + a[i][j]

  초기값:

  */

 cin >> n;

 for(int i=1; i<=n; i++){
  for(int j=1; j<=i; j++){
    cin >> a[i][j];
  }
 }

d[1][1] = a[1][1];

int result=d[1][1];

for(int i=2; i<=n; i++){
  for(int j=1; j<=i; j++){
     d[i][j] = max(d[i-1][j-1], d[i-1][j]) + a[i][j];
     result = max(d[i][j], result);
  }
}

// cout << *max_element(d[n] + 1, d[n] + n+1);  //이러면 1번부터 n번까지 중 최댓값 가져옴
cout<<result;


 

 

  return 0;
}

