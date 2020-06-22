#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int g namespace std;
int leng;
int leng;
int testcase;
int result;
int i;
int cnt[100][100];
int main()
{
  ios_base :: sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  string input;
  cin>>testcase;

  while(testcase--)
  {
    cin>>input;
    leng=input.length();
    cnt[testcase][input[0]]++;
    for(i=1;i<leng;i++)
    {
      if(input[i-1]!=input[i])
        if(cnt[testcase][input[i]]!=0)  break;
      if(cnt[testcase][input[i]]==0)  cnt[testcase][input[i]]++;
    }
    if(i==leng)
      result++;
  }

  cout<<result<<'\n';

  return 0;
}
