#include <iostream>
#include <math.h>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
using namespace std; 


int n;
int arr[10002];
  
int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin>>n;

  for(int i=0; i<n; i++){
    int a;
    cin>>a;
    arr[a]++;
  }

  //i가 n개까지 확인하는게 아니라 10002까지만 확인해야함 꼭
  for(int i=0; i<10002; i++){
   if(arr[i]!=0){
      while(arr[i]--){
        cout<<i<<"\n";
      }
   }
  }


  return 0;
}

