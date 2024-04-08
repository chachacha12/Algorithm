#include <iostream>
#include <math.h>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
using namespace std; 


int t, n;
int a[1000005];

int main(void){ 
  ios::sync_with_stdio(0);
  cin.tie(0); 

  cin>>t;

  while(t--){

    cin>>n;

    for(int i=0; i<n; i++){
      cin>>a[i];
    }
    
    int mx = a[n-1];
    long long sum=0;

    for(int i=n-2; i>=0; i--){  
      if(a[i] < mx){  
        sum = sum + (mx-a[i]);
      }else{
        mx = a[i];
      }
    }
    cout<<sum<<'\n';
  }
  
  
  return 0;
}












