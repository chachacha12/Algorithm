
#include <iostream>
#include <math.h>
#include <algorithm>
#include <list>
#include <stack> 
#include <queue>
using namespace std; 

//백트래킹은 n값이 작을때 진행하는 알고리즘인듯 

int n;
int cnt;
int isused1[40];
int isused2[40];
int isused3[40];

void func(int cur){
    if(cur == n){  //마지막 줄까지 갔다면
        cnt++;
        return;
    }
    for(int i=0; i<n; i++){
        if( isused1[i] ||  isused2[cur+i]  || isused3[cur-i + n-1]  )
            continue;
        isused1[i] = 1;
        isused2[cur+i] = 1;
        isused3[cur-i + n-1] = 1;
        func(cur+1);
        isused1[i] = 0;
        isused2[cur+i] = 0;
        isused3[cur-i + n-1] = 0;
    }
}



int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  func(0);
  cout<<cnt;
 


}






