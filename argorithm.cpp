#include <iostream>
//#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << "cccc";

    int n,x,t;
    cin >>n >>x;

    for(int i=0; i<n;i++){
       cin >>t;
       if(t<x) cout <<t<<' ';
    }

    return 0;
}

