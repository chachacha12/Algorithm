#include <iostream>
#include <math.h>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
using namespace std; 

int n,m;
int a[100005];

int check(int st, int en, int num){
  int mid;
  int vis=0;

  //1 2 3 4 5

  while(1){   
      mid = (st+en)/2; 
      //cout<<"mid: "<<mid<<"\n";
      
      if(a[mid]<num){ 
        st = mid+1;

      }else if(a[mid]>num){
        en = mid-1; 

      }else if(a[mid]==num){
        vis=1;
        break;
      }
      if(en<st){
          vis=0;
          break;
      }
  }

  //cout<<"vis:"<<vis<<"\n";
  return vis;
}



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

    cout<< check(0, n-1, num)<<"\n";
  }
  
  return 0;
}












