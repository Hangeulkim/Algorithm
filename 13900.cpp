#include<iostream>
using namespace std;
int testcase;
int inputnum[100004];
long long sum=0,ans=0;
int main()
{
  ios_base :: sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin>>testcase;
  for(int i=1;i<=testcase;i++)
  {
    cin>>inputnum[i];
    sum+=inputnum[i];
  }
  for(int i=1;i<=testcase;i++)
      ans+=sum*inputnum[i]-inputnum[i]*inputnum[i];
  cout<<ans/2<<'\n';

  return 0;
}
