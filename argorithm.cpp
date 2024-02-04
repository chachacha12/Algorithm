#include <iostream>
#include <math.h>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
using namespace std; 


long long arr[100002];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin>>n;

  for(int i=0; i<n; i++){
    cin>>arr[i];
  }

  sort(arr, arr+n);

  int cnt=0;
  int maxcnt=0;
  long long maxval= -pow(2,62)-1; 

  for(int i=0; i<n; i++){
    if(i==0 || arr[i-1] == arr[i]){
      cnt++;
    }else{
      if(maxcnt < cnt){
        maxcnt = cnt;
        maxval = arr[i-1];
      }
      cnt=1; 
    }
  }

  if(cnt > maxcnt){
    maxval = arr[n-1];
  }


  cout<< maxval;



  return 0;
}

