#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std; 


int arr[2000001] ={0}; //숫자값
int brr[100001] ={0}; //index값

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int index;
    int sum=0;

    cin >> index;

    int n;
   for(int i=0; i<index; i++){
        cin >>n;
        brr[i] = n;
        arr[n]++;
    }

    int x;
    cin >>x;
    
    for(int i=0; i<index; i++){
        if(x-brr[i] >0 &&  arr[x-brr[i]] !=0 ){
            sum++; 
        }
    }

    if(sum !=0){
        sum/=2;
    }

    cout<<sum;


    return 0;
}
