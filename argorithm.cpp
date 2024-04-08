#include <iostream>
#include <math.h>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
using namespace std; 


int n;
int p[1005];


int main(void){ 
  ios::sync_with_stdio(0);
  cin.tie(0); 

  cin>>n;
  
  for(int i=0; i<n; i++){
    cin>>p[i];
  }

  sort(p, p+n); //오름차순 정렬

  int ans=0;
  int sum=0;
  for(int i=0; i<n; i++){
    sum = sum + p[i]; 
    ans += sum;
  }

  cout<<ans;


  

  
  return 0;
}












