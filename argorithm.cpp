#include <iostream>
#include <math.h>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
using namespace std; 


int n;
vector<long long> v;
string st;


int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin>>n;

  for(int i=0; i<n; i++){
    cin>>st;
    reverse(st.begin(), st.end());
    v.push_back(stoll(st));
  }
  
  sort(v.begin(), v.end());

  for(int i=0; i<n; i++){
    cout<<v[i]<<"\n";
  }
  

  return 0;
}

