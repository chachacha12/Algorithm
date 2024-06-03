#include <iostream>
#include <math.h>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
using namespace std; 

int d[1005][1005];

int main(void){ 
  ios::sync_with_stdio(0);
  cin.tie(0); 

  string a;
  string b;

  cin>>a>>b;

  for(int i=0; i<a.length(); i++){
    d[i][0]=0;
  }
  for(int i=0; i<b.length(); i++){
    d[0][i]=0;
  }


  for(int i=1; i<a.length()+1; i++){
    for(int j=1; j<b.length()+1; j++){
      if(a[i-1]==b[j-1]){
        d[i][j] =  d[i-1][j-1]+1;
        //cout<<"d[i][j]: "<<d[i][j]<<"\n";
      }else{
         d[i][j] = max(d[i-1][j],d[i][j-1]);
         //cout<<"d[i][j]: "<<d[i][j]<<"\n";
      }
    }
  }

  cout<<d[a.length()][b.length()];


}












