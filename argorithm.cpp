#include <iostream>
#include <math.h>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
using namespace std; 


int d[305][3];
int s[305];


int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0); 

  //점화식
  // d[k][1] = max(d[k-2][1], d[k-2][2]) + s[k]
  // d[k][2] = d[k-1][1] + s[k]

  int n;
  cin>>n;

   for(int i=1; i<=n; i++){
    cin>>s[i];
   }

  d[1][1] = s[1]; d[1][2] = 0;
  d[2][1] = s[2]; d[2][2] = s[1]+s[2];


  for(int i=3; i<=n; i++){
    d[i][1] = max(d[i-2][1], d[i-2][2]) + s[i];
    d[i][2] = d[i-1][1] + s[i]; 
  }

  cout << max(d[n][1], d[n][2]);
  
  return 0;
}

