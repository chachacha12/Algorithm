#include <iostream>
#include <math.h>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
using namespace std; 


int n;
pair<long long, long long> p[100005];

bool compare(pair<long long, long long> a,pair<long long, long long> b){
  if(a.second == b.second){
    return a.first <  b.first;
  }
  return a.second < b.second;
}



int main(void){ 
  ios::sync_with_stdio(0);
  cin.tie(0); 
  
  cin>>n;
  
  for(int i=0; i<n; i++){
    cin >> p[i].first>>p[i].second;
  }

  sort(p, p+n, compare);
  
  int ans=1;
  long long t = p[0].second;

  for(int i=1; i<n; i++){
    
   if(p[i].first >= t ){
        ans++;
        t = p[i].second;
    }
  }
  cout<<ans;


  
  return 0;
}












