#include <iostream>
#include <math.h>
#include <algorithm>
#include <list>

using namespace std; 

//연결리스트 문제

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    string s;

    cin>>n;

    while(n--){
        cin >> s;
        
        list<char> L;
        list<char>::iterator it = L.end();

        for(auto c: s){



            if(c =='<'){
                if(it != L.begin()){
                    it--;
                }
                    
            }else if(c=='>'){
                if(it != L.end()){
                    it++;
                }

            }else if(c=='-'){
                if(it != L.begin()){
                    it--;
                    it = L.erase(it);
                }

            }else{  //그냥 문자 비밀번호 칠때
                L.insert(it, c);
            }
        }

        //정답을 출력
        for(auto c: L){
            cout<<c;
        }
         cout<<'\n';  //이것도 중요!! 안해주면 틀림 
    }


    return 0;
}

