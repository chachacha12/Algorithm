#include <iostream>
#include <math.h>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
using namespace std; 


int n,m;
string s[1005];

int d[1005][1005];
int ans=0;

int main(void){ 
  ios::sync_with_stdio(0);
  cin.tie(0); 

  cin>>n>>m;

  for(int i=0; i<n; i++){
    cin>>s[i];
  }

  for(int i=0; i<n; i++){
    if(s[i][0]=='1')
      d[i][0] = 1;
      ans = max(ans, d[i][0]);
  }

  for(int j=0; j<m; j++){
    if(s[0][j]=='1')
      d[0][j] = 1;
      ans = max(ans, d[0][j]);
  }

  for(int i=1; i<n; i++){
    for(int j=1; j<m; j++){
      if(s[i][j]=='1'){
        d[i][j] = min(d[i-1][j-1],  min(d[i-1][j], d[i][j-1]))+1;
        ans = max(ans, d[i][j]);
      }
    }
  }

  cout<<ans*ans;

}












