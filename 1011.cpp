#include<iostream>
#include<cmath>
using namespace std;
long long result;
int main()
{
  ios_base :: sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  long long input,m,n,tmp;
  cin>>input;
  for(int i=0;i<input;i++)
  {
    tmp=1;
    result=0;
    cin>>m>>n;
    long long diff=n-m;
    while(1)
    {
      if(diff>tmp*tmp-tmp&&diff<=tmp*tmp)
      {
        cout<<result+1<<'\n';
        break;
      }
      else if(diff>tmp*tmp&&diff<=tmp*tmp+tmp)
      {
        cout<<result+2<<'\n';
        break;
      }
      for(int i=0;i<=1;i++)
        result+=1;
      tmp++;
    }
  }


  return 0;
}
