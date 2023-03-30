#include <iostream>

using namespace std;

//백준 10808번 알파벳 갯수 문제

int freg[26]; //배열은 전역으로 선언하면 알아서 0으로 초기화됨. 지역변수로 선언하면 쓰레기값들 들어가서..초기화 따로 해줘야함

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    for(auto c: s){
        freg[c-'a']++;
    }
    for(auto n: freg){
        cout<<n<<' ';
    }
    

    return 0;
}
