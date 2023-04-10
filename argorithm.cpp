#include <iostream>
#include <math.h>
#include <algorithm>
#include <list>

using namespace std; 

//연결리스트가 쓰이는 문제는 크게 응용해서 낼만한게 없고 이 문제처럼 원소를 돌아다니면서 이동하다가 추가나 삭제가 필요한 문제임.
//만약 n이 5000정도로 작으면 O(n제곱)으로 풀어도되어서 우리에게 더 익숙한 vector로 풀어도됨. 

//백준 1406번 에디터 - STL 이용풀이

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    list<char> L;
    string s;
    int n;
    char order; 
    char letter;
    
    cin>> s;

    for(auto c: s){
        L.push_back(c);
    }

    //리스트 젤 끝에 커서를 둠, 단 지정할 수 없게 빈공간을 가리키므로 t--한번해주면
    //그때 젤 마지막 값 가리킬거임
    list<char>::iterator t = L.end(); 
    
    t--;

    L.push_front('a'); //리스트 맨 앞에 더미노드를 하나더 둠
    
    cin>>n;

    for(int i=0; i <n; i++){
        cin>>order;
        if(order == 'L'){
            if(t != L.begin() )  //젤 처음값이 아니라면
                t--;

        }else if(order =='D'){
            t++;
            if(t == L.end() )  //젤 마지막의 다음값이라면
            {
                t--;
            }
                

        }else if(order == 'B'){
            //맨 뒷자리가 아니라면
            t++;
            if(t !=L.end()){
                t--;
                //젤 처음의 더미노드였다면 삭제명령 무시
                if(t == L.begin()){

                }else{ 
                     t = L.erase(t);
                     t--;
                }
            }else{
                t--;
                t--;
                L.pop_back(); //마지막에 있는 데이터를 삭제함
            }


        }else if(order == 'P'){  //삽입하기 명령 - 맨뒤에서 삽입만 예외처리해주면됨
            cin >>letter;
            
            t++;
            if(t == L.end()){
                t--;
                L.push_back(letter);
                t++;
            }else{
                L.insert(t, letter);
                t--;
            }
            
        }       
    }
    L.pop_front();  //L의 맨앞에 넣었던 더미노드뺌

    for(auto c: L){
        cout << c;
    }
    

    return 0;
}

