#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int input[10];
int sum;
int main()
{
  ios_base :: sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  for(int i=1;i<=5;i++)
  {
    cin>>input[i];
    if(input[i]<40)
      input[i]=40;
    sum+=input[i];
  }
  cout<<sum/5<<'\n';

  return 0;
}
