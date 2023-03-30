#include <iostream>

using namespace std;

/// 배열의 idx자리에 num을 추가하는 함수. len값은 배열의 최대길이임
void insert(int idx, int num, int arr[], int& len){
   
    for(int i = len; i>idx; i--){
        arr[i] = arr[i-1];
    }
    arr[idx] = num;
    len++;  //배열의 길이가 늘어났기에 최종길이값 늘려준것
}


void erase(int idx, int arr[], int& len){

    len--;  //배열 최종길이 줄여준것    
    for(int i=idx; i<len; i++){
        arr[i] = arr[i+1];
    }

}

void printArr(int arr[], int& len{
    for(int i=0; i< len; i++){
        cout<<arr[i] << ' ';
    }
    cout << "\n\n";
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);


    return 0;
}
