#include <iostream>
#include <math.h>
#include <algorithm>
#include <list>
#include <stack> 
#include <queue>
using namespace std; 

int arr[130][130];

int white=0;
int blue=0;

void func(int x, int y, int size){

    bool same=true;
    for(int i=y; i<y+size; i++){
        for(int j=x; j<x+size; j++){
            if(arr[i][j] != arr[y][x] ){
                same = false;
                break;
            }
        }
        if(!same)
            break;
    }
    
    if(same){
        if(arr[y][x] ==0)
            white++;
        else
            blue++;
    }else{
        func(x, y, size/2);
        func(x+size/2, y, size/2);
        func(x, y+size/2, size/2);
        func(x+size/2, y+size/2, size/2);
    }
}



int main(){ 
    ios::sync_with_stdio(0);  
    cin.tie(0); 

    int n;
    cin >>n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }

    func(0,0,n);
    cout<<white<<"\n";
    cout<<blue<<"\n";

    return 0;
}





