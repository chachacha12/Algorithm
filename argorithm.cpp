#include <iostream>
#include <math.h>
#include <algorithm>
#include <list>
#include <stack> 
#include <queue>
using namespace std; 


/* 
재귀문제는 n=k가 참이라 칠때, n=k+1도 참이 될만한 반복?되는 그 패턴을 찾아서 재귀함수 만들면됨.
그럼 모든 n에 대해 참이됨
*/

//이 함수는 n이 주어졌을때 r행, c열을 몇번째로 방문했는지를 반환해주는 함수
int func(int n, int r, int c){
    if(n==0)
        return 0;
    
    int half = 1<<(n-1);


    //1번 사각형 안에 포함될경우
    if(r < half && c < half)
        return func(n-1, r, c);
    //2번 사각형
    if(r < half && c >= half)
        return half*half + func(n-1, r, c-half);
    //3번 사각형
    if(r >= half && c< half)
        return 2*half*half + func(n-1, r-half, c);
    //4번 사각형
    return 3*half*half + func(n-1, r-half, c-half);
}



int main(){ 
    ios::sync_with_stdio(0);  
    cin.tie(0); 

    int n,r,c;

    cin>>n>>r>>c;

    cout<<func(n,r,c);

   
    return 0;
}





