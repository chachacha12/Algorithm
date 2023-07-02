#include <iostream>
#include <math.h>
#include <algorithm>
#include <list>
#include <stack> 
#include <queue>
using namespace std; 

/*
아래는 내가 직접 생각해서 짜본 코드이고
바킹독 설명: https://www.youtube.com/watch?v=yPuow6aACvE

-> 이 문제는 시간복잡도 널널하게 n제곱으로 풀어도된다면, 그냥 쉽게
학생 하나하나 반복하면서 다시 자신에게로 돌아오는지만 체크해보면됨. 돌아오면 팀 있는거고
안돌아오면 팀 없는것.  (사이클안에 포함되어 있으면 무조건 자기자신에게로 다시 돌아오기 때문) 

*/



int t;

int main(){ 
    ios::sync_with_stdio(0);  
    cin.tie(0); 

    cin>>t;

    //테스트케이스 수만큼 반복
    while(t--){
        int board[100002];
        int dist[100002]; //0이면 아직 미방문. 1이면 방문한상태(스택에 들어있는상태). 2이면 팀 이미 이뤘거나 절대 못 이루는 상태
        fill(board, board+100002,0);
        fill(dist, dist+100002,0);
        stack<int> s;
        int n=0;
        int chosen_num =0;

        cin>>n;

        //학생들 수만큼 반복하며 각 학생들이 선택한 번호 입력
        for(int i=1; i<=n; i++){
            cin>>board[i];
        }

        //팀 못이룬 학생수를 출력해줘야함
        
        //학생 한명한명 돌면서 만약 아직 미방문인 인덱스면 스택에 넣어줌
        for(int i=1; i<=n;i++){

                if(dist[i] == 2 ) {       //방문한 경우
                    continue;
                }else{        //미방문인 경우
                    s.push(i);
                    dist[i] = 1; //스택에 들어가면 1

                    while(!s.empty()){
                        int index = s.top(); 

                        //미방문인 경우  - 계속해서 다음녀석들 방문해줄거
                        if(dist[board[index]] == 0){
                            s.push(board[index]);
                            dist[board[index]] = 1;  //스택에 넣었다는 표시

                        //방문해서 스택에 있는경우, 즉 사이클 만들어진것 (본인이 본인 선택한 경우도 포함) - 팀이뤄진거임
                        }else if(dist[board[index]] ==  1){

                            while(s.top() != board[index]){
                                dist[ s.top() ] = 2;
                                chosen_num++;
                                s.pop();
                            }
                            dist[ s.top() ] = 2;
                            chosen_num++;
                            s.pop();
                            
                            while(!s.empty()){  //나머지 선택 못받은 녀석들도 다 비워주기
                                dist[ s.top() ] = 2;
                                s.pop();
                            } 

                        }else{  //이미 방문했던 경우 - 팀을 절대 만들 수 없음
                            
                            while(!s.empty()){  //이때끼지 스택에 쌓인 녀석들 다 방문표시
                                dist[ s.top() ] = 2;
                                s.pop();
                            } 
                        }
                    }
                }
        }
         
        int result = n - chosen_num;  //전체 학생수 - 선택받은 학생수
        cout << result<<"\n";
    }
    
    


    return 0;
}



