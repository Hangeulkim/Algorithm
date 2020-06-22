#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int ans;
int main()
{
  ios_base :: sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  string input;
  cin>>input;
  int leng=input.length();
  for(int i=0;i<leng;i++)
  {
    if(input[i]=='d')
    {
      if(input[i+1]=='-')
      {
        ans++;
        i+=1;
      }
      else if(input[i+1]=='z'&&input[i+2]=='=')
      {
        ans++;
        i+=2;
      }
      else
        ans++;
    }
    else if(input[i]=='l'||input[i]=='n')
    {
      if(input[i+1]=='j')
      {
        ans++;
        i+=1;
      }
      else
        ans++;
    }
    else if(input[i]=='c'||input[i]=='s'||input[i]=='z')
    {
      if(input[i+1]=='='||input[i+1]=='-')
      {
        ans++;
        i+=1;
      }
      else
        ans++;
    }
    else
      ans++;
  }
  cout<<ans<<'\n';
  return 0;
}
