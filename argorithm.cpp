#include <iostream>
#include <math.h>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
using namespace std; 

int n;
vector<int> p;
vector<int> m;

long long sum;

bool compare(int a, int b){
  return a>b;
}


int main(void){ 
  ios::sync_with_stdio(0);
  cin.tie(0); 

  cin>>n;

  for(int i=0; i<n; i++){
    int num;
    cin>>num;
    if(num>0)
      p.push_back(num);
    else
      m.push_back(num);
  }
  
  sort(p.begin(), p.end(), compare); //내림차순
  sort(m.begin(), m.end()); //오름차순

  //양수 처리
  for(int i=0; i<p.size(); i+=2){
    
    while(p.back()==1){
      sum+=1;
      p.pop_back();
      //cout<<"1sum: "<<sum<<'\n';
    }

    if(p.size()%2!=0){  //홀수면
      sum+= p.back();
      p.pop_back();
      //cout<<"2sum: "<<sum<<'\n';
    }
    if(p.size()!=0){

      sum+=p[i]*p[i+1];
    }
  
    //cout<<"3sum: "<<sum<<'\n';
  } 

  //음수처리
  for(int i=0; i<m.size(); i+=2){
    
    if(m.size()%2!=0){  //홀수면
      sum+= m.back();
      m.pop_back();
    }

    sum+=m[i]*m[i+1];
    //cout<<"sum: "<<sum<<'\n';
  } 


  cout<<sum;

  
  return 0;
}












