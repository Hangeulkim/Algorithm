#include<iostream>
#include<algorithm>
using namespace std;
int num[1000];
int main()
{
  ios_base :: sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int input;
  cin>>input;
  for(int i=0;i<input;i++)
    cin>>num[i];
  sort(num,num+input);
  for(int i=0;i<input;i++)
    cout<<num[i]<<'\n';
  return 0;
}
