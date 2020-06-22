#include<iostream>
#include<algorithm>
using namespace std;
int cnt,a,sosucnt=0;
int sosu[1004];
int input;
int maxnum[1004];
long long ans;
int main()
{
  ios_base :: sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  for(int i=2;i<1000;i++)
  {
    int j=0;
    for(j=i-1;j>1;j--)
      if(i%j==0) break;
    if(j==1)
    {
      sosucnt++;
      sosu[sosucnt]=i;
    }
  }

  int testcase=0,N=0;
  cin>>testcase;
  for(int i=1;i<=testcase;i++)
  {
    cin>>N;
    for(int j=1;j<=N;j++)
    {
      a=1;
      cin>>input;
      while(sosu[a]!=0)
      {
        cnt=0;
        while(1)
        {
          if(input%sosu[a]==0)
          {
            cnt++;
            input/=sosu[a];
            maxnum[a]=max(maxnum[a],cnt);
          }
          else
          {
            a++;
            break;
          }
        }
      }
    }
    a=1;
    ans=1;
    while(sosu[a]!=0)
    {
      int temp=1;
      while(maxnum[a]>0)
      {
        temp*=sosu[a];
        maxnum[a]--;
      }
      ans=ans*temp%1000000007;
      a++;
    }

    cout<<ans<<'\n';
  }
  return 0;
}
