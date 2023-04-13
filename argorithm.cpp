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

    stack<int> st;
    int n;
    int result=0;

    cin>>n;

    while(n--){
        int num;
        cin>> num;
        if(num == 0){
            result-= st.top();
            st.pop();
        }else{
            st.push(num);
            result+=num;
        }
    }

    cout<<result;
    
    return 0;
}
