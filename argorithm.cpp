
#include <iostream>
#include <math.h>
#include <algorithm>
#include <list>
#include <stack> 
#include <queue>
using namespace std; 

int n,m;
int a[10];


void func(int cur){
  if(cur == m){
    for(int i=0; i<m; i++){
      cout<<a[i]<<' ';
    }
    cout<<'\n';
    return;
  }
  for(int i=1; i<=n; i++){
    if(cur !=0){
      if(a[cur-1] > i)
        continue;
    }
    a[cur] = i;
    func(cur+1);
  }
}


int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>m;
  func(0);

}







