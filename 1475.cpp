#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int cnt[10];
int ans;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  string num;
  cin>>num;
  int leng=num.length();
  for(int i=0;i<leng;++i)
  {
    ++cnt[num[i]-'0'];
  }
  int n=ceil((double)(cnt[6]+cnt[9])/2);
  ans=max({cnt[0],cnt[1],cnt[2],cnt[3],cnt[4],cnt[5],cnt[7],cnt[8],n});
  cout<<ans;
  return 0;
}
