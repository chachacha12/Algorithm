
#include <iostream>
#include <math.h>
#include <algorithm>
#include <list>
#include <stack> 
#include <queue>
using namespace std; 

//조합 문제임. 몇개중에 몇개를 고르는 문제. 


int a[15];
int s[15];


int k;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  while(true){
    cin>>k;
    if(k==0)
      break;

    for(int i=0; i<k; i++){
      cin>>s[i];


      if(i>=6){
        a[i] = 1;
      }else{
        a[i] = 0;
      }
    }

    do{
      for(int i=0; i<k; i++){
        if(a[i] ==0){
          cout<<s[i]<<" ";
        }
      }
    cout<<'\n';
    }while(next_permutation(a, a+k));
    cout<<'\n';

  }

  

  return 0;
}







