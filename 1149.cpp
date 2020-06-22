#include<iostream>
#include<algorithm>
using namespace std;

int color[3];
int sum[3];
int tempsum[3];
int input=0;
int main()
{
  ios_base :: sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> input;

  for(int i=0;i<input;i++){
    cin>>color[0]>>color[1]>>color[2];
    sum[0]=min(tempsum[2],tempsum[1])+color[0];
    sum[1]=min(tempsum[0],tempsum[2])+color[1];
    sum[2]=min(tempsum[1],tempsum[0])+color[2];
    tempsum[0]=sum[0];
    tempsum[1]=sum[1];
    tempsum[2]=sum[2];
  }
  cout << min(sum[0],min(sum[1],sum[2]));
  return 0;
}
