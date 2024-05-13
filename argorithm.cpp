#include <iostream>
#include <math.h>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
using namespace std; 


int n;
int a[105];
int ans;

int main(void){ 
  ios::sync_with_stdio(0);
  cin.tie(0); 

  cin>>n;

  for(int i=0; i<n; i++){
    cin>>a[i];
  }

  for(int i=n-1; i>=0; i--){

     if(i!=0 ){
        while(a[i] <= a[i-1] ){
          a[i-1]--;
          ans++;
        }
      }
    
  }

  cout<<ans;


}












