///////////////////////////////////////////
카운팅 소트

n이 1000만이하의 작은 수라면, 카운팅 소트 쓰면 구현쉽고 빠름.
나오는 숫자의 갯수를 세어두었다가 출력해주면 됨. 하지만 수가 크면 이거 못씀.


///////////////////////////////////////////
Radix 소트


///////////////////////////////////////////
  STL 소트 -> 코테는 이거 쓰면됨. O(nlogn) 걸림.

  int a[5] = {1,4,5,2,7};
  sort(a,a+5);

  vector<int> b = {1,4,5,2,7};
  sort(b.begin(), b.end());
