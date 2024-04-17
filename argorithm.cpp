#include <iostream>
#include <math.h>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
using namespace std; 



int n;

int input[1000005];
int a[1000005];
int b[1000005];
int len;


int check(int target){
  int st=0; 
  int en = len;
  int mid=0;

  while(1){
    mid = (st+en)/2;

    if(b[mid]<target){
      st = mid+1;

    }else if(b[mid] > target){
      en = mid-1;

    }else{
      break;
    }
  }
  return mid;

}


int main(void){ 
  ios::sync_with_stdio(0);
  cin.tie(0); 

  cin>>n;

  for(int i=0; i<n ; i++){
    cin>>a[i];
    input[i] = a[i];
  }

  sort(a, a+n);
  
  //중복제거 후 b배열로 옮김
  int minus=0;
  for(int i=0; i<n ; i++){
    if(i == n-1 || a[i] != a[i+1]){
      b[i-minus] = a[i];
      len++;
    }else{
      minus++;
    } 
  }

  //이제 이분탐색해서 target의 인덱스값 알아내면됨
  for(int i=0; i<n; i++){

   //cout<<"input[i]: "<<input[i]<<"\n";
    
    cout<<check(input[i])<<" ";
  }
  

  return 0;
}












