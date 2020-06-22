#include<iostream>
#include<string>
using namespace std;
int main()
{
  ios_base :: sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int testnum=0;
  cin>>testnum;
  int repeat=0;
  string input;
  for(int i=1;i<=testnum;i++)
  {
    cin>>repeat;
    cin>>input;
    int leng=input.length();
    for(int j=0;j<leng;j++)
      for(int k=1;k<=repeat;k++)
        cout<<input[j];
    cout<<'\n';
  }


  return 0;
}
