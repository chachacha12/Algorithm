#include <iostream>
#include <math.h>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
using namespace std; 

int n;
int x,y;
int ans;

vector<pair<int, int>> v;


int main(void){ 
  ios::sync_with_stdio(0);
  cin.tie(0); 

  cin>>n;


  for(int i=0; i<n; i++){
    int a,b;
    cin>>a>>b;
    v.push_back({a,b});
  }

  sort(v.begin(), v.end());


  int lastx=v[0].first, lasty=v[0].second;
  
  for(int i=1; i<n; i++){
    
    int x = v[i].first;
    int y = v[i].second;

    if(lasty >= x ){
      if(lasty < y){
        lasty = y;
      }
    }else{
      ans+= lasty - lastx;
      lastx = x;
      lasty = y;
    }
  }

  ans += lasty - lastx;

  cout<<ans;

     


  
  return 0;
}












