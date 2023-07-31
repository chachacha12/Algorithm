
#include <iostream>
#include <math.h>
#include <algorithm>
#include <list>
#include <stack> 
#include <queue>
using namespace std; 

int n,m;
vector<int> a;


int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin>>n>>m;


  if(n==m){
    for(int i=0; i<n; i++)
      cout<<i+1<<' ';
  }else{
      for(int i=0; i<n; i++){
        if(i<m)
          a.push_back(0);
        else
          a.push_back(1);
      }

      do{
        for(int i=0; i<n; i++){
          if(a[i]==0)
            cout<<i+1<<' ';
        }
        cout<<'\n';
      }while(next_permutation(a.begin(), a.end()) );
  }
}







