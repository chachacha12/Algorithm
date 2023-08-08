
#include <iostream>
#include <math.h>
#include <algorithm>
#include <list>
#include <stack> 
#include <queue>
using namespace std; 

int n,m;
int a[10];
int result[10];


void func(int cur){
  if(cur==m){
    for(int i=0; i<m; i++){
      cout<<result[i]<<' ';
    }
    cout<<'\n';
    return;
  }
  for(int i=0; i<n; i++){
    if(cur !=0 && result[cur-1] > a[i] )
      continue;

    result[cur] = a[i];
    func(cur+1);

  }

}



int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>m;
  
  for(int i=0; i<n; i++){
    cin>> a[i];
  }

  sort(a, a+n);
  func(0);


}







