#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int input[10];
int cnt[10];
int result;
int main()
{
  ios_base :: sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin>>input[1]>>input[2]>>input[3];
  result=input[1]*input[2]*input[3];
  string ans=to_string(result);
  int leng=ans.length();
  for(int i=0;i<leng;i++)
    cnt[ans[i]-'0']++;
  for(int i=0;i<10;i++)
    cout<<cnt[i]<<'\n';

  return 0;
}
