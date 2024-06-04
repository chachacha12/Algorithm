#include <iostream>
#include <math.h>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
using namespace std; 

vector <pair<int,int>> house;
vector<pair<int,int>> chick;

int n,m;
int board[55][55];
int ans=0;  //현재 조합일때의 최소거리
int result=1000000;  //최종적인 최소거리 (정답값)

int main(void){ 
  ios::sync_with_stdio(0);
  cin.tie(0); 

  cin>>n>>m;
  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
      cin>>board[i][j];

      if(board[i][j]==1)
        house.push_back({i,j});  //집은 여기 넣어줌
      if(board[i][j]==2)
        chick.push_back({i,j});  //치킨집은 여기 넣어줌
    }
  }


  //총 치킨집 중 m개를 고르는 조합 방법
  vector<int> brute(chick.size(), 1);
  for(int i=0; i<m; i++){
    brute[i]=0;
  }

  do{
       //모든 집을 돌면서 
        for(int i=0; i<house.size(); i++){
          int x = house[i].first;
          int y = house[i].second;
          int min_dist=100000; //최소 거리

          // cout<<"X: " <<x<<"y: "<<y<<'\n';
          
          //모든 치킨 집 중 m개 조합 고르기
           for(int j = 0; j < chick.size(); j++){
              if(brute[j] == 0) {//고른 치킨집
               int x2 = chick[j].first;
               int y2 = chick[j].second;

              //  cout<<"X2: " <<x2<<"y2: "<<y2<<'\n';

                min_dist = min(abs(x-x2) + abs(y-y2), min_dist); 

              }  
          }
          // cout<<"min_dist"<<min_dist<<'\n';
          ans+=min_dist;  //해당 집의 최소거리를 합에 더해줌   
        }
        //  cout<<"\n";
        // cout<<"ans: "<<ans<<'\n';
        // cout<<"\n";
        result = min(result, ans);
        ans=0;
  }while(next_permutation(brute.begin(), brute.end()));

  cout<<result;


}












