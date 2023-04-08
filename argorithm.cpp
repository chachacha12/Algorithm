#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std; 


int arr[10] ={0};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >>n;

    while(n>0){
        arr[n%10]++;
        n /= 10; 
    }

    int entire=0;

    for(int i=0; i<10; i++){
        if(i==6 ||i==9){

        }else{
            if(arr[i] > entire){
                entire = arr[i];
            }
        }
    }


    int six_nine = (arr[6]+arr[9]+1)/2;

    cout << (max(entire, six_nine));


    return 0;
}
