#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
  ios_base :: sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int input=0;
  cin>>input;

  long long pinary[input];

  pinary[0]=1;
  pinary[1]=1;
  for(int i=2;i<input;i++)
    pinary[i]=pinary[i-2]+pinary[i-1];
  cout<<pinary[input-1];
  return 0;
}
