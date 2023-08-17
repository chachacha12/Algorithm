
#include <iostream>
#include <math.h>
#include <algorithm>
#include <list>
#include <stack> 
#include <queue>
using namespace std; 

//조합 문제임. 몇개중에 몇개를 고르는 문제. 

int s[15];
int result[15];
int k;
bool isused[15];

void func(int cur){
  if(cur ==6){
    for(int i=0; i<6; i++){
      cout<<result[i]<<' ';
    }
    cout<<'\n';
  }

  for(int i=0; i<k; i++){
    if(!isused[i] ){
      if(cur !=0 && result[cur-1]>= s[i] )
          continue;
        
      result[cur] = s[i];
      isused[i] = 1;
      func(cur+1); 
      isused[i] =0;
    }
  }

}


int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  while(true){
    cin>> k;
    if(k==0)
      break;
    
    for(int i=0; i<k; i++){
      cin >> s[i];
    }
    func(0);
     cout<<'\n';
  }  

  return 0;
}







