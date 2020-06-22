#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
  ios_base :: sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int input=0;
  cin >>input;
  int stair[input]={'\0'};
  int sum[input]={'\0'};
  for(int i=0;i<input;i++)
    cin>>stair[i];
  sum[0]=stair[0],sum[1]=stair[0]+stair[1];
  sum[2]=max(stair[0],stair[1])+stair[2];
  for(int i=3;i<input;i++)
      sum[i]=max(sum[i-3]+stair[i-1],sum[i-2])+stair[i];
  cout << sum[input-1];
  return 0;
}
