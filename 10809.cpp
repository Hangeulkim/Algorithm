#include<iostream>
#include<string>
using namespace std;
int cnt;
int main()
{
  ios_base :: sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  string input;
  cin>>input;
  int leng=input.length();
  for(int i=97;i<=122;i++)
  {
    for(cnt=0;cnt<leng;cnt++)
      if(input[cnt]==i) break;
    if(cnt==leng)
      cout<<"-1 ";
    else
      cout<<cnt<<" ";
  }


  return 0;
}
