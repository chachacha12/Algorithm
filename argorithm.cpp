#include <iostream>
#include <math.h>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
using namespace std; 

int n;
int t[20];
int p[20];
int d[20];


int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0); 

  /*
  테이블 정의:
  d[i] = i일까지 일했을때 얻을 수 있는 최대 수익 (뒤부터)

  점화식:

  if(n + tn <= n+1 ) //해당 상담을 퇴사 전에 할 수 있을때

  d[n] =  max(d[n+tn]+pn, d[n+1]  ) //상담 하기로 할때와 안하기로 할때 중 최댓값을 저장 

  else  //해당 상담을 선택여지없이 못할때
  d[n] = d[n+1]

  */

  cin>>n;

  for(int i=1; i<=n; i++){
    cin>>t[i]>>p[i];
  }

  d[n+1] = 0;

  for(int i=n; i>=1; i--){
     if(i + t[i] <= n+1 ){//해당 상담을 퇴사 전에 할 수 있을때
      d[i] =  max(d[i+t[i]]+p[i], d[i+1]  );
      //cout<<"d["<<i<<"]: "<<d[i];
     }else{
      d[i] =d[i+1];
      //cout<<"d["<<i<<"]: "<<d[i];
     }
  }

  cout<<d[1];



  return 0;
}

