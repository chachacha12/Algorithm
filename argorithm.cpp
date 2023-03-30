#include <iostream>
using namespace std;


/// 바킹독 0x01강 연습문제인 arr가 주어졌을때 그 중 2개수를 골랐을때 합이 100이 되는 수 있으면 1, 아니면 0을 출력하기 문제임
///보통은 O(n제곱) 으로 생각하지만 배열쓰면 O(n)만에 해결가능

int brr[1000];

bool func2(int arr[], int n){
    for(int i=0; i < n ;  i++){
        if(brr[100- arr[i]] ==1)
            return 1;
      
       brr[arr[i]] =1;
    }
    return 0;

}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    
    

    return 0;
}
