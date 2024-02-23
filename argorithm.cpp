#include <iostream>
#include <math.h>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
using namespace std; 


int t, n, m;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin>>t;
  
  while(t--){
    int count=0;
    vector<int> a;
    vector<int> b;

    cin>>n>>m;

    for(int i=0; i<n; i++){
      int num;
      cin>>num;
      a.push_back(num);
    }
    for(int i=0; i<m; i++){
      int num;
      cin>>num;
      b.push_back(num);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());


    for(int i=0; i<n; i++){
      int anum = a[i];
      for(int j=0; j<m; j++){
        int bnum = b[j];
        
        if(anum > bnum){ //a값이 b보다 더 클때
          count++;
        }else{ //a값이 b와 같거나 작을때
          break;
        }

      }
    }
    cout<<count<<'\n';
  }
  

  return 0;
}

