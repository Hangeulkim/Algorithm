#include<iostream>
using namespace std;

int main()
{
  ios_base :: sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int a=0;
  cin >> a;
  int tile[a]={1,2,};
  for(int i=2;i<a;i++)
    tile[i]=(tile[i-2]+tile[i-1])%10007;
  cout << tile[a-1];
  return 0;
}
