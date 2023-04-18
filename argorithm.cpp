#include <iostream>
#include <math.h>
#include <algorithm>
#include <list>
#include <stack> 
#include <queue>

using namespace std; 


stack<char> st;



/// (총 막대의 갯수 + 총 관통한 횟수) 계산을 하면 잘린 총 막대의 갯수..즉, 답이 나올듯

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin>>s;

    int sum=0;  //레이저가 막대들을 총 몇번을 관통하는지 셈
    int stick_num=0;  //총 막대의 갯수
    bool pop_check = false; // 레이저나와서 pop한 직후인지 나타내는 함수 true면 바로전에 pop한것

    for(auto c: s){ 
        if(c =='('){
        //이거일경우 스택에 넣어줌
            st.push(c);
            pop_check = false;

        }else if(c==')'){
        //이거일경우엔 2가지 경우로 나눔.
        //1. 레이저인경우
        //2. 닫는 막대기인 경우
            if(pop_check == false  && st.top() == '('){  //레이저인 경우
                st.pop();
                //스택의 크기를 재서 레이저가 몇개의 막대기를 관통하는지 계속 더함
                sum+=st.size();

                pop_check = true;
            }else{         //닫는 막대인경우
                st.pop();
                stick_num++;    
            }
        }
    }

    cout<< stick_num + sum;

   

    
    
    return 0;
}
