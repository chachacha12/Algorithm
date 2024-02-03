#include <iostream>
#include <math.h>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
using namespace std; 



int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int plus[1000002];
  int minus[1000002];
  int n;

  fill(plus, plus+1000002, 0);
  fill(minus, minus+1000002, 0);

  cin>>n;
  
  for(int i=0; i<n; i++){
    int a;
    cin>>a;
    
    if(a<0){
      minus[-a]++;
    }else{
      plus[a]++;
    }
  }

  for(int i=1000000; i>0; i--){
    if(minus[i] !=0 ){
      while(minus[i]--){
         cout<<-i<<"\n";
      }
    }
  }

  for(int i=0; i<1000000; i++){
    if(plus[i] !=0 ){
      while(plus[i]--){
         cout<<i<<"\n";
      }
    }
  }



  return 0;
}

