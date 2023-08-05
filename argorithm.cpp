
#include <iostream>
#include <math.h>
#include <algorithm>
#include <list>
#include <stack> 
#include <queue>
using namespace std; 

int n,m;
vector<int> a;
int arr[10];
bool isused[10];

void func(int cur){
  if(cur == m){
    for(int i=0; i<m; i++){
      cout<<arr[i]<<' ';
    }
    cout<<'\n';
  }
  for(int i=0; i< a.size() ; i++){
    if(isused[i])
      continue;

    isused[i] = 1;
    arr[cur]= a[i];
    func(cur+1);
    isused[i] = 0;

  }

}


int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>m;
  
  int t;
  for(int i=0; i<n; i++){
    cin>>t;
    a.push_back(t);
  }
  sort(a.begin(), a.end());
  func(0);


  

}







