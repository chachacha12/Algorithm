#include <iostream>
#include <math.h>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
using namespace std; 


bool compare(pair<int, int>a, pair<int, int>b ){
  return a.first > b.first;
}

int n,c;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >>n>>c;

  vector<pair<int,int>> arr;

  for(int i=0; i<n; i++){
    long long num;
    cin>>num;
    bool check =false;

    for(int j=0; j<i; j++){
      //이미 앞에 나온 수라면
      if(j<i && arr[j].second == num ){
        arr[j].first++;
        check = true;
        break;
      }
    }
    if(!check){
      arr.push_back({1, num});  
    }
  }
  
  stable_sort(arr.begin(), arr.end(), compare);

  for(auto a: arr){
    while(a.first--){
      cout<<a.second<<" ";
    }
  }
  

  return 0;
}

