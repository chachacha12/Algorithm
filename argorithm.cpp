#include <iostream>
#include <math.h>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
using namespace std; 


/*
테이블: d[i] = 숫자i일때 최소 갯수

점화식: d[k] = min(d[k-1제곱]+1, d[k-2제곱]+1, d[k-3제곱]+1,,,,)
*/


int d[100005];
int n;

int main(void){ 
  ios::sync_with_stdio(0);
  cin.tie(0); 

  cin>>n;

  d[0] = 0;
  d[1] = 1;
  d[2] = 2;
  int a =1;

  for(int i=3; i<=100000; i++){
    if(i >= a*a &&  i < (a+1)*(a+1) ){
      int max_v=100000;
      for(int j=1; j<=a; j++ ){
        d[i] = d[i-j*j]+1;    
        d[i] = min(max_v, d[i]);
        max_v = d[i];
      }
    }else{
      a++;
      i--;
    }
  }
  cout<<d[n];
}












