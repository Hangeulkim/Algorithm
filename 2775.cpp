#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
  ios_base :: sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int house[15][15]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14};
    for(int i=1;i<15;i++)
      for(int j=1;j<15;j++)
        house[i][j]=house[i-1][j]+house[i][j-1];

  int input=0;
  cin>>input;

  int people[input][2];
    for(int i=0;i<input;i++)
      for(int j=0;j<2;j++)
        cin>>people[i][j];

  for(int i=0;i<input;i++)
    cout<<house[people[i][0]][people[i][1]]<<'\n';

  return 0;
}
