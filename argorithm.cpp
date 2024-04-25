#include <iostream>
#include <math.h>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
using namespace std; 

int m,n;
vector<pair<int, int>> x[102];


int main(void){ 
  ios::sync_with_stdio(0);
  cin.tie(0); 

  cin>>m>>n;

  for(int i=0; i<m; i++){
    for(int j=0; j<n; j++){
      int num;
      cin>>num;
      x[i].push_back({num,j});  //그 값과 그 값의 인덱스순서를 저장
    }
  }

  for(int i=0; i<m; i++){
    sort(x[i].begin(), x[i].end());
  }

  int sum=0;

  for(int i=0; i<m-1; i++){
    for(int j=i+1; j<m; j++){
      for(int k=0; k<n; k++){
        
        pair<int,int> a = x[i][k];
        pair<int,int> b = x[j][k];

        if( a.second != b.second   ){
            break;
        }

        if(k==n-1){
          sum++;
          break;
        }

        if( (x[i][k].first < x[i][k+1].first) != (x[j][k].first < x[j][k+1].first) ){
          break;
        }
      }
    }
  }

  cout<<sum;


}












