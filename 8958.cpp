#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
  ios_base :: sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int num=0,cnt=0;
  cin>>num;
  int score=0;
  string input;
  for(int i=1;i<=num;i++)
  {
    cin>>input;
    int leng=input.length();
    for(int j=0;j<leng;j++)
    {
      if(input[j]=='O')
      {
        cnt++;
        score+=cnt;
      }
      else
        cnt=0;
    }
    cout<<score<<'\n';
    score=0;
    cnt=0;
  }

  return 0;
}
