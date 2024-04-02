#include <iostream>
#include <math.h>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
using namespace std; 

int n;
vector<int> arr(100005);

bool compare(int a, int b){
  return a>b;
}

int main(void){ 
  ios::sync_with_stdio(0);
  cin.tie(0); 

  cin>>n;
  
  for(int i=0; i<n; i++){
    int a;
    cin >> a;
    arr.push_back(a);
  }

  sort(arr.begin(), arr.end(), compare);


  int maxvalue=arr[0];
  int result;

  for(int i=0; i<n; i++){
    result = arr[i] * (i+1) ; 
    maxvalue = max(maxvalue, result); 
  }

  cout<<maxvalue;
  
  return 0;
}












