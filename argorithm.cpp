#include <iostream>
#include <math.h>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
using namespace std; 


int n,k;
int a[15];
int ans;

int main(void){ 
  ios::sync_with_stdio(0);
  cin.tie(0); 

  cin>>n>>k;

  for(int i=1; i<=n; i++){
    cin>>a[i];
  }

  for(int i=n; i>0; i--){
    while(1){ 
      if(a[i]<=k){
        k = k-a[i];
        ans++;
      }else{
        break;
      }
    } 
  }

  cout<<ans;



}












