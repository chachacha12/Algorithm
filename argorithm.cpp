#include <iostream>
#include <math.h>
#include <algorithm>
#include <stack>
#include <queue>
#include <list>
using namespace std; 




int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  while(true){
    stack<char> st;
    string s;
    getline(cin, s);
    if(s=="."){
      break;
    }

    for(auto c : s){
     
      if(c=='('){
        st.push(c);

      }else if(c==')' ){
        if(!st.empty() && st.top()=='('){
          st.pop();
        }else{
          cout<< "no" <<'\n';
          break;
        }
          

      }else if(c=='['){
        st.push(c);

      }else if(c==']'){
        if(!st.empty() && st.top()=='['){
          st.pop();
        }else{
          cout<< "no" <<'\n';
          break;
        }
          
      }else if(c=='.'){
        if(st.empty()){
            cout<< "yes" <<'\n';
            break;
        }
        else{
          cout<< "no" <<'\n';
          break;
        }
      }
    }


  }


  

  return 0;
}







