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
  int triangle[input][input];
  int sum[input][input];
  int i=0;
  for(i=0;i<input;i++)
    for(int j=0;j<=i;j++)
      cin>>triangle[i][j];
  sum[0][0]=triangle[0][0];
  for(i=1;i<input;i++)
    for(int j=0;j<=i;j++){
      if(j==0)
        sum[i][j]=sum[i-1][j]+triangle[i][j];
      else if(j==i)
        sum[i][j]=sum[i-1][j-1]+triangle[i][j];
      else
        sum[i][j]=max(sum[i-1][j-1],sum[i-1][j])+triangle[i][j];
      }
  cout<<*max_element(sum[input-1],sum[input-1]+i);

  return 0;
}
