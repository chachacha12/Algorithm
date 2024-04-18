#include <iostream>
#include <math.h>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
using namespace std; 



int n;
int a[1000005];
//int b[1000005];
vector<int> b;
int len;


int main(void){ 
  ios::sync_with_stdio(0);
  cin.tie(0); 

  cin>>n;

  for(int i=0; i<n ; i++){
    cin>>a[i];
    b.push_back(a[i]);
  }

  sort(b.begin(), b.end());
  
  //중복제거 후 b배열로 옮김
  b.erase( unique(b.begin(), b.end()), b.end() );
  

  //이제 이분탐색해서 target의 인덱스값 알아내면됨
  for(int i=0; i<n; i++){

   //cout<<"input[i]: "<<input[i]<<"\n";
    
    cout<< lower_bound(b.begin(), b.end(), a[i]) - b.begin()  <<" ";
  }
  

  return 0;
}












