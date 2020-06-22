#include<iostream>
#include<cmath>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int t,h,w,n;
  double level=0;
  cin>>t;
  for(int i=1;i<=t;i++)
  {
    cin>>h>>w>>n;
    level=ceil((double)n/h);
    if(level<10)
      cout<<n-(level-1)*h<<"0"<<level<<'\n';
    else
      cout<<n-(level-1)*h<<level<<'\n';
  }


  return 0;
}
