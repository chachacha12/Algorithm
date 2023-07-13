#include <iostream>
#include <math.h>
#include <algorithm>
#include <list>
#include <stack> 
#include <queue>
using namespace std; 


//절차지향적으로.. 함수를 계속 따라들어가는 방식으로 생각하면 무간지옥 빠짐..
// 귀납적으로 생각하기.

// 우선 이 문제에서 n=1일때 무조건 참이됨. 그리고 원판이 n-1일때 모든 원판을 원하는 곳으로 옮길 수 있다고 치면, n일때도 원하는 곳으로 옮길 수 있다는게 참임. 
// (귀납법은 첫 가정이 참이라고 쳤을때 두번째 따라오는 가정이 참이라면, 모든 경우에 대해 참이됨)
// 즉, 이 문제는 수학적 귀납법으로 풀 수 있구나! 알면됨. 수학적 귀납법으로 풀면되니까 재귀함수 만들어서 풀거임.

/*
n=1일때 이 함수는 자명하게 참이됨.
n=k일때 이 함수가 참이라고 치면, n= k+1일때 참이라는 게 확실하다? 그럼 모든 n에 대해 참이됨.

그래서 모든 n에 대해서 이것은 참이될거라는 것만 그냥 믿으면 됨.
*/

void func(int a, int b, int n){
    if(n==1){
        cout<<a<<" "<<b<<"\n";
        return; //함수 종료. 반환값은 없음
    }
    func(a, 6-a-b, n-1);
    cout<<a<<" "<<b<<'\n';
    func(6-a-b, b, n-1);
}



int main(){ 
    ios::sync_with_stdio(0);  
    cin.tie(0); 

    int k;
    cin >>k;
    cout<<(1<<k)-1<<'\n';
    func(1, 3, k);


    return 0;
}





