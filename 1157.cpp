#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int cnt[130];
int result[50];
int try1;
int main()
{
  ios_base :: sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  string input;
  cin>>input;
  int leng=input.length();
  for(try1=0;try1<leng;try1++)
    cnt[input[try1]]++;
  for(try1=1;try1<=26;try1++)
    result[try1]=cnt[64+try1]+cnt[96+try1];
  int temp=0;
  int tempi=0;

  for(try1=1;try1<=26;try1++)
  {
    if(temp<result[try1])
    {
      temp=result[try1];
      tempi=try1;
    }
  }
  result[tempi]=0;
  for(try1=1;try1<=26;try1++)
  {
    if(result[try1]==temp)
      break;
  }
  if(try1!=27)
    cout<<"?"<<'\n';
  else
    cout<<(char)(tempi+64)<<'\n';

  return 0;
}
