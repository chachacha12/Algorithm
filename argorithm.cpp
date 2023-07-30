
#include <iostream>
#include <math.h>
#include <algorithm>
#include <list>
#include <stack> 
#include <queue>
using namespace std; 

int n,s;
int cnt;
int arr[25];


void func(int cur, int sum){ 
  if(cur==n){
    if(sum==s){
      cnt++;
    }
    return;
  }  
  
  func(cur+1, sum );
  func(cur+1, sum + arr[cur]);

  
}


int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>s;
  
  for(int i=0; i<n; i++){
      cin>>arr[i];
  }

  func(0,0);

  if(s==0) //합이 0인걸 구하는거면 수열중 아무것도 안들어가는 경우(공집합)인 경우는 빼줘야함. 문제에서 크기가 양수인 부분수열중에서 구하라해서
    cnt--;

  cout<<cnt;

 

}






