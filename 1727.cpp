#include<iostream>
#include<algorithm>
using namespace std;
int abs(int a)
{
  if(a<0)
    return -a;
  else
    return a;
}

int sum[1001][1001];
int main()
{
  ios_base :: sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int b=0,g=0;
  cin>>b>>g;
  int bchar[b+1],gchar[g+1];
  for(int i=1;i<=b;i++)
    cin>>bchar[i];
  for(int i=1;i<=g;i++)
    cin>>gchar[i];
  sort(bchar+1,bchar+b+1);
  sort(gchar+1,gchar+g+1);
  int i=0,j=0;
  for(i=1;i<=b;i++)
    for(j=1;j<=g;j++){
      sum[i][j]=sum[i-1][j-1]+abs(bchar[i]-gchar[j]);
      if (i > j) sum[i][j] = min(sum[i][j], sum[i - 1][j]);
		  if (i < j) sum[i][j] = min(sum[i][j], sum[i][j - 1]);
    }



  cout<<sum[b][g];

  return 0;
}
