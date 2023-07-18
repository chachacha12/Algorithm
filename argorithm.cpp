#include <iostream>
#include <math.h>
#include <algorithm>
#include <list>
#include <stack> 
#include <queue>
using namespace std; 


int arr[3000][3000];

int first=0;
int second=0;
int third=0;

void func(int x, int y, int size){

    bool same = true;
    for(int i=y; i<y+size; i++){  //탐색
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
        if(arr[y][x]==-1){
            first++;
        }else if(arr[y][x]==0){
            second++;
        }else{
            third++;
        }
    }else{
        func(x,y,size/3); //1번
        func(x+size/3, y, size/3); //2번
        func(x+2*size/3, y, size/3); //3번
        
        func(x, y+size/3, size/3);
        func(x+size/3, y+size/3, size/3);
        func(x+2*size/3, y+size/3, size/3);

        func(x, y+2*size/3, size/3);
        func(x+size/3, y+2*size/3, size/3);
        func(x+2*size/3, y+2*size/3, size/3);
    }
}


int main(){ 
    ios::sync_with_stdio(0);  
    cin.tie(0); 

    int n;

    cin>>n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }

    func(0,0,n);
    cout<<first<<"\n";
    cout<<second<<"\n";
    cout<<third<<"\n";
   
    return 0;
}





