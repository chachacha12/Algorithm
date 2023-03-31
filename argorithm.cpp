#include <iostream>
using namespace std;


int arr[10];
int a,b,c;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>a>>b>>c;
    
    ///10으로 나눈 나머지를 구하면 일의 자리 수를 알 수 있음
    //그 후 sum값은 10씩 나눠주면 모든 자릿수의 숫자값을 확인가능
    int sum = a*b*c;

    while(sum>0){
        int n = sum%10;
        arr[n]++;
        sum/=10;
    }

    for(auto c: arr){
        cout<<c<<'\n';
    }

    return 0;
}
