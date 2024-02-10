#include <iostream>
#include <math.h>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
using namespace std; 


int n;
pair<int, string> arr[100002];


//사용자정의 함수 - sort()함수에 넣으면 이거대로 정렬가능
bool compare(pair<int, string> a, pair<int, string> b){
  return a.first < b.first;  
}
  
int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin>>n;

  for(int i=0; i<n; i++){
    cin>>arr[i].first>>arr[i].second;
  }

  stable_sort(arr, arr+n, compare);


  for(int i=0; i<n; i++){
    cout<< arr[i].first <<" "<< arr[i].second<<'\n';
  }
  

  return 0;
}

