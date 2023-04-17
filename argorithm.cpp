#include <iostream>
#include <math.h>
#include <algorithm>
#include <list>
#include <stack> 
#include <queue>

using namespace std; 



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

   while(1){
        stack<char> st;
        string s;
        getline(cin, s);   //공백이 있는 문자열을 받을때 사용함 

        if(s=="."){
            break;
        }
        
        
        for(auto c: s){
            if(c=='('){
                st.push(c);
            }else if(c=='['){
                st.push(c);
            }else if(c==')'){
                if(st.empty() || st.top() !='(' ){
                    cout<<"no"<<'\n';
                    break;
                }else{
                    st.pop();
                }
                
            }else if(c==']'){
                if(st.empty() || st.top() !='[' ){
                    cout<<"no"<<'\n';
                    break;
                }else{
                    st.pop();    
                }
            }else if(c=='.'){
                if(st.empty()){
                    cout<<"yes"<<'\n';
                    break;
                }else{
                    cout<<"no"<<'\n';
                    break;
                }
            }
        }


   }


    

    
    
    return 0;
}
