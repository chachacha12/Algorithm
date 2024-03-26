#include <iostream>
#include <math.h>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
using namespace std; 

int n,k;
int a[15];

int main(void){ 
  ios::sync_with_stdio(0);
  cin.tie(0); 

  cin>>n>>k;
  
  for(int i=0; i<n; i++){
    cin>>a[i];
  }
  
  int ans=0;
  
  for(int i=n-1; i>=0; i--){
    
    ans = ans + k/a[i];
    k = k % a[i];
  }

  cout<<ans;


  
  return 0;
}












