#include <iostream>
#include <math.h>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
using namespace std; 


/*
1. 

*/


int n,m;
int arr[10][10];
vector<pair<int,int>> cctv; //각 시시티비가 몇번 시시티비인지 저장



int a[10];

void func(int cur){
  if(cur==m){
    for(int i=0; i<m; i++){
       cout<<a[i]<<" ";
    }
    cout<<"\n";
    return;
  }
  for(int i=1; i<=n; i++ ){
    a[cur] = i;

    func(cur+1);

  }

}


int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin>>n>>m;

  func(0);


  return 0;
}



/*
  cin>>n>>m;
  for(int i=0;i<n; i++){
    for(int j=0; j<m; j++){
      cin>>arr[i][j];
      

    }
  }

  

  cout<<"";

*/