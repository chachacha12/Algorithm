#include <iostream>
#include <math.h>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
using namespace std; 


bool compare(string a, string b){
  return a.length() < b.length();
}


int n;
vector<string> vs;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin>>n;

  for(int i=0; i<n; i++){
    string st;
    cin>> st;
    vs.push_back(st);
  }


  //사전순정렬
  sort(vs.begin(), vs.end());

  //길이순 정렬
  stable_sort(vs.begin(), vs.end(), compare);


  //출력
  for(int i=0; i<n; i++){
    if(vs[i]==vs[i+1]) //중복되는것들은 출력안함
      continue;
    cout << vs[i] <<"\n";
  }

  return 0;
}

