#include <iostream>
#include <math.h>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
using namespace std; 


int n,m;

int a[100005];


int main(void){ 
  ios::sync_with_stdio(0);
  cin.tie(0); 

  cin>>n;

  for(int i=0; i<n; i++){
    cin>>a[i];
  }

  sort(a,a+n);

  cin>>m;

  int num;
  for(int i=0; i<m; i++){
    cin>>num;

    cout<<binary_search(a, a+n, num)<<"\n";
  }


  
  
  
  return 0;
}












