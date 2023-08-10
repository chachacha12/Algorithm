
#include <iostream>
#include <math.h>
#include <algorithm>
#include <list>
#include <stack> 
#include <queue>
using namespace std; 

int n,m;
int a[10];
int result[10];
bool isused[10];

void func(int cur){
  if(cur ==m){
    for(int i=0; i<m; i++){
      cout<<result[i]<<' ';
    }
    cout<<'\n';
    return;
  }
  int tmp =0;  // 중복 수열인지 확인 하기 위해 필요한 임시 변수
  for(int i=0; i<n; i++){
     if (!isused[i] && tmp != a[i]){ //한번도 사용안한 원소이어야하고 +  이전 수열의 마지막 항과 새로운 수열의 마지막 항이 같으면 안됨
      isused[i] = true;
      result[cur] = a[i];
      tmp = result[cur]; 
      func(cur+ 1);
      isused[i] = false;
    }
  }
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>m;
  for(int i=0; i<n; i++){
    cin>>a[i];
  }
  sort(a, a+n);
  func(0);

 

}







