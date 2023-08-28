#include <iostream>
#include <math.h>
#include <algorithm>
#include <stack> 
#include <queue>
#include <list>
using namespace std; 

list<char> L;
list<char>::iterator it;

string s; 
int n;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin>>s;
  cin>>n;

  for(auto c: s){
    L.push_back(c);
  }
  it =  L.end();
  
  while(n--){
    char a;
    cin>>a;
    if(a=='L'){
      if(it != L.begin()){
        it--;
      } 

    }else if(a=='D'){
      if(it != L.end()){
        it++;
      }

    }else if(a=='B'){
      if(it == L.begin() ){

      }else if( it==L.end()){
        it--;
        it = L.erase(it);
      }else{
        it--;
        it = L.erase(it);
      }

    }else{
      char word;
      cin>>word;
      L.insert(it, word);
    }

  }

  for(auto c: L){
    cout<<c;
  }

  

  return 0;
}







