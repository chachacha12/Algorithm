#include <iostream>
#include <math.h>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
using namespace std; 


int n,k;
int w[100005];
int v[100005];
int d[105][100005];

int main(void){ 
  ios::sync_with_stdio(0);
  cin.tie(0); 

  cin>>n>>k;

  for(int i=1; i<=n; i++){
    cin>>w[i]>>v[i];
  }


   for(int i=1; i<=n; i++){
      for(int j=1;j<=k; j++){
        if(w[i] > j){
                  d[i][j] = d[i-1][j];
            }else{
              d[i][j] = max( d[i-1][j], v[i]+d[i-1][j-w[i]] );
            }2
      }
         
    }


    
 


  cout<<d[n][k];
  
  return 0;
}












