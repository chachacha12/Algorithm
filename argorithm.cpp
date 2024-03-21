#include <iostream>
#include <math.h>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
using namespace std; 

string board[5];
int k;  //회전수
int t, s; // 회전할 톱니, 스핀 방향

int a,b,c,d; //톱니바퀴가 회전할거면 1, 아니면 0인 플레그
int as,bs,cs,ds; //어디로 회전할건지
int aa,bb,cc,dd; //이미 지난 톱니인지 확인용. 지났으면 1 

//회전시키기
void spin(int t, int s){
  if(s==1){ //시계방향
    rotate(board[t].begin(), board[t].end()-1, board[t].end());
  }else{  //반시계
    rotate(board[t].begin(), board[t].begin()+1, board[t].end());  
  }
}


//회전할 바퀴 t와 맞닺는 부분체크
void check(int t, int s){

  if(t==1){
    a=1; //회전할거임
    aa=1; //방문한 톱니
    as=s; //회전할 방향
      if(board[1][2] != board[2][6] && bb==0  ){ //2번째 바퀴가 아직 회전안했을경우
      
        if(s==1) bs=-1;
        else bs=1;

        check(2, bs);
      }
    }else if(t==2){
      b=1;
      bb=1;
      bs=s;
      if(board[1][2] != board[2][6] && aa==0 ){
       
        if(s==1) as=-1;
        else as=1;

        check(1, as);

      }
      if(board[2][2] != board[3][6] && cc==0 ){
        
         if(s==1) cs=-1;
         else cs=1;

         check(3, cs);
      }


    }else if(t==3){
      c=1;
      cc=1;
      cs=s;
      if(board[2][2] != board[3][6] && bb==0){
       
         if(s==1) bs=-1;
        else bs=1;

         check(2, bs);

      }
      if(board[3][2] != board[4][6]&& d==0 && dd==0){
         if(s==1) ds=-1;
         else ds=1;

         check(4, ds);
         
      }

    }else if(t==4){
      d=1;
      dd=1;
      ds=s;
      if(board[3][2] != board[4][6] &&c==0 && cc==0){
         if(s==1) cs=-1;
         else cs=1;

         check(3, cs);
      }
    }  
}



int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0); 

  for(int i=1; i<=4; i++)
    cin>>board[i];

  cin>>k; //회전수 입력

  while(k--){

    a=0;b=0;c=0;d=0;  //회전할 톱니인지
    aa=0;bb=0;cc=0;dd=0;  //이미 지난 톱니인지
    as=0; bs=0; cs=0; ds=0; //어디로 회전할지

    cin>>t>>s;

    check(t,s);
    
    if(a==1){
      spin(1, as);
    }
    if(b==1){
      spin(2, bs);
    }
    if(c==1){
      spin(3, cs);
    }
    if(d==1){
      spin(4, ds);
    }
  }

  int result=0;
  
  if(board[1][0] =='1')
    result+=1;
  if(board[2][0] =='1')
    result+=2;
  if(board[3][0] =='1')
    result+=4;
  if(board[4][0] =='1')
    result+=8;

  cout<<result;


  return 0;
}












