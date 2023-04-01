#include <iostream>
#include <math.h>
#include <algorithm>


using namespace std; 

int arr[20] ={0};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int six_nine=0;
    int other=0;

    cin>>n;
    
    
    while(n>0){
        arr[n%10]++;
        n/=10;
    }
    
    for(int i=0 ;i<10; i++){
        if(i==6 || i==9){
        }else{
            if(other < arr[i]){
                other=arr[i];
            }
        }
    }

    six_nine = (arr[6]+arr[9]+1)/2;
    //six_nine += (arr[6]+arr[9])%2;
    
    other = max(other,six_nine);
    cout<<other;


    return 0;
}
