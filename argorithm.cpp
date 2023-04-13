#include <iostream>
#include <math.h>
#include <algorithm>
#include <list>
#include <stack> 

using namespace std; 

//스택 문제

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    stack<int> st;
    int num;

    cin>>n; 

    while(n--){
        string s;
        cin>>s;
        if(s=="push"){
            cin>>num;
            st.push(num);

        }else if(s=="pop"){
            if(st.empty()){
                cout << -1 << '\n';
            }else{
                cout<< st.top() << '\n';
                st.pop();
            }

        }else if(s=="size"){
            cout<<st.size()<<'\n';

        }else if(s=="empty"){
            if(st.empty()){
                cout << 1 << '\n';
            }else{
                cout << 0 << '\n';
            }
        }else if(s=="top"){
            if(st.empty()){
                cout << -1 << '\n';
            }else{
                cout<< st.top() << '\n';
            }
        }
    }
    
    return 0;
}
