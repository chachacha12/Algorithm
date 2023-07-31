#include <iostream>
using namespace std; 

/*
순열과 조합을 구하는 문제를 백트래킹 안쓰고 쉽게 푸는법
: next_permutation 함수

next_permutation함수는 인자로 넣은 수열을 사전순으로 생각했을때 
다음 수열로 바꿔만들고 true를 반환하는 함수임.
만약 현재 수열이 사전순으로 젤 마지막이어서 다음 수열이 존재하지 않으면 false를 반환함.

그래서 아래처럼 do while문으로 작성하면 깔끔함.


순열 예: 5개 중 3개를 순서대로 뽑는 경우 ( 5 x 4 x 3 을 해서 구함)
조합 예: 5개 중 3개를 순서 상관없이 뽑는 경우 (5 x 4 x 3 / 3 x 2 x 1 을 해서 구함)


///백트래킹 강의 끝내며 ////
-> 백트래킹 문제는 많이 풀다보면 함수가 정형화되고 머릿속에서 공식처럼 자리잡아서 두렵지 않게됨.
N과 M문제들을 next_permutation을 써서도 꼭 다시 풀어보기.
앞으로 순열, 조합 문제가 나오면 무조건 next_permutation 쓴다고 생각하기.

*/

int main(){

  //순열 구하기
  int a[3] = {1,2,3};
  do{ 
    for(int i = 0; i < 3; i++)
      cout << a[i];
    cout << '\n';

  }while(next_permutation(a, a+3));

  //조합 구하기 - 4개중 2개 뽑아서 출력하는 문제일때
  int a[4] = {0, 0, 1, 1};
  do{
    for(int i = 0; i < 4; i++){
      if(a[i] == 0)
        cout << i+1;
    }
    cout << '\n';
  }while(next_permutation(a, a+4));

  //조합 구하기 - 5개중 3개를 뽑아서 출력하는 문제일때
  int a[5] = {0, 0, 0, 1, 1};
  do{
    for(int i = 0; i < 5; i++){
      if(a[i] == 0)
        cout << i+1;
    }
    cout << '\n';
  }while(next_permutation(a, a+5));






}


