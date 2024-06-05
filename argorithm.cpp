#include <iostream>
#include <math.h>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
using namespace std; 


string s;

int main(void){ 
  ios::sync_with_stdio(0);
  cin.tie(0); 

  cin>>s;
  int zero=0;
  int one=0;
  char flag;

  flag = s[0];
  for(int i=1; i<s.length(); i++){
    if(s[i] =='0'){
      if(flag=='1'){
        flag='0';
        one++;
      }
    }else{
      if(flag=='0')  //이전까지 0이었으면
      {
        flag='1';
        zero++;    
      }
    }
  }
  
  if(flag=='0'){
    zero++;
  }else{
    one++;
  }


  if((zero==0 && one==1) || (one==0 && zero==1)){
    cout<<'0';
  }else{
    cout<<min(one, zero);
  }

  

}












