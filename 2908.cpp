#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
using namespace std;
int ans[2];
int main()
{
  ios_base :: sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  string input1,input2;
  cin>>input1>>input2;

  for(int i=2;i>=0;i--)
  {
    ans[0]+=(input1[i]-'0')*pow(10,i+1);
    ans[1]+=(input2[i]-'0')*pow(10,i+1);
  }

  if(ans[0]>ans[1])
    cout<<ans[0]/10<<'\n';
  else
    cout<<ans[1]/10<<'\n';
  return 0;
}
