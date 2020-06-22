#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int input[10];
int cnt=0;
int main()
{
  ios_base :: sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  for(int i=1;i<=8;i++)
  {
    cin>>input[i];
    if(input[i]==i)
      cnt++;
    else if(input[i]==9-i)
      cnt--;
  }
  if(cnt==8)
    cout<<"ascending"<<'\n';
  else if(cnt==-8)
    cout<<"descending"<<'\n';
  else
    cout<<"mixed"<<'\n';
  return 0;
}
