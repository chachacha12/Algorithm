#include <iostream>
#include <math.h>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
using namespace std; 


string s;
int tmp, ans;
int sign=1;

int main(void){ 
  ios::sync_with_stdio(0);
  cin.tie(0); 

  cin>>s;

  for(char c: s){
    if(c=='+' || c=='-'){
      ans = ans + tmp * sign;
      if(c=='-'){
        sign = -1;
      }
      tmp=0;
    }else{
      tmp = tmp * 10;
      tmp = tmp + c-'0';
    }
  }
  ans = ans + tmp * sign;

  cout<<ans;
  


  
  return 0;
}












