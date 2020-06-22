#include<iostream>
#include<algorithm>
using namespace std;
long long input;
long long sum=1;
long long ans=1;
int main()
{
  ios_base :: sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin>>input;

  while(sum<input)
  {
    sum+=6*ans;
    ans++;
  }


  cout<<ans<<'\n';
  return 0;
}
