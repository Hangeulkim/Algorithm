#include<iostream>
#include<algorithm>
using namespace std;
int lcm(int a,int b)
{
    while(b!=0){
        int mod = a%b;
        a = b;
        b = mod;
    }
  return a;
}
int cnt,num,tmp;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int t,m,n,x,y,tmpx,tmpy;
  cin>>t;
  for(int i=0;i<t;i++)
  {
    cin>>m>>n>>x>>y;
    if(n>m)
    {
      swap(m,n);
      swap(x,y);
    }
    tmpx=x;
    tmpy=x;
    num=m*n/lcm(m,n);
    cnt+=x;
    while(1)
    {
      if(tmpy>n)
        tmpy-=n;
      else
        break;
    }
    while(cnt<=num)
    {
      if(tmpx==x&&tmpy==y)
        break;
      tmpy+=m%n;
      if(tmpy>n)
        tmpy-=n;
      cnt+=m;
    }
    if(cnt>num)
      cout<<"-1\n";
    else
      cout<<cnt<<'\n';
    cnt=0;
  }
  return 0;
}
