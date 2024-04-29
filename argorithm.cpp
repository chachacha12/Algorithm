#include <iostream>
#include <math.h>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
using namespace std; 

int n;
int arr[100005];

int main(void){ 
  ios::sync_with_stdio(0);
  cin.tie(0); 

  cin>>n;

  for(int i=0; i<n; i++){
    cin>>arr[i];
  }


  int a = 1e9+1;
  int b = 1e9+1;


  for(int i=0; i<n; i++){ 
    int index = lower_bound(arr, arr+n, -arr[i]) - arr;  //반대되는 값이 들어갈 수 있는 첫 자리값

    if(index+1<n && index+1 != i && abs(arr[i]+arr[index+1]) < abs(a+b) ){
    
      a = arr[i];
      b = arr[index+1];
    }
    if(index<n && index != i && abs(arr[i]+arr[index]) < abs(a+b) ){
    
      a = arr[i];
      b = arr[index];
    }
    if(index !=0 && index-1 != i && abs(arr[i]+arr[index-1]) < abs(a+b) ){
     
      a = arr[i];
      b = arr[index-1];
    }
  }



  if(a>b) swap(a,b);
    
  cout<<a<<" "<<b;
 

}












