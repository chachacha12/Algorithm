#include <iostream>
#include <math.h>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
using namespace std; 



int n,m;
int a[500005];


int check(int target){

  int* low = lower_bound(a, a+n, target);  //정렬된 배열에서 target값이 정렬 유지하면서 들어갈 수 있는 곳의 가장 아래 주소값
  int* upper = upper_bound(a, a+n, target); //정렬된 배열에서 target값이 정렬 유지하면서 들어갈 수 있는 곳의 가장 윗 주소값

  return upper-low; //즉 배열에서 target값이 나온 횟수와 같음
}


int main(void){ 
  ios::sync_with_stdio(0);
  cin.tie(0); 

  cin>>n;

  for(int i=0; i<n; i++){
    cin>>a[i];
  }
  
  sort(a, a+n);

  int m;
  cin>>m;

  int t;
  while(m--){
    cin>>t;

    cout<<check(t)<<" ";
  }

  return 0;
}












