#include <iostream>
#include <math.h>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
using namespace std; 

bool compare(pair<int, int> a, pair<int, int> b){

  if(a.second < b.second){
    return true;
  }else if(a.second == b.second){
    return a.first < b.first;
  }else{
    return false;
  }
}


int n;
pair<int, int> p[100002];


int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin>>n;

  for(int i=0; i<n; i++){
    cin >> p[i].first >> p[i].second;
  }

  sort(p, p+n, compare);

  for(int i=0; i<n; i++){
    cout << p[i].first <<" "<< p[i].second;
    cout<<'\n';
  }
  
  

  return 0;
}

