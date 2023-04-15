#include <iostream>
#include <math.h>
#include <algorithm>
#include <list>
#include <stack> 
#include <queue>

using namespace std; 

//큐 문제


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue<int> Q;
    int n;
    cin>> n;
    

    while(n--){
        string s;
        cin>>s;

        if(s=="push"){
            int x;
            cin>>x;
            Q.push(x);

        }else if(s=="pop"){
            if(!Q.empty()){
                cout<<Q.front()<<'\n';
                Q.pop();
            }else{
                cout<<-1<<'\n';
            
            }

        }else if(s=="size"){
            cout<<Q.size()<<'\n';

        }else if(s=="empty"){
            if(Q.empty()){
                 cout<<1<<'\n';
            }else{
                cout<<0<<'\n';
            }

        }else if(s=="front"){
            if(!Q.empty()){
                cout<<Q.front()<<'\n';
            }else{
                cout<<-1<<'\n';
            }

        }else if(s=="back"){
            if(!Q.empty()){
                cout<<Q.back()<<'\n';
            }else{
                cout<<-1<<'\n';
            }
        }

    }

    return 0;
}

