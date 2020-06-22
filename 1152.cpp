#include<iostream>
#include<string>
using namespace std;
int main()
{
  ios_base :: sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string input;
  getline(cin,input);

  int wordnum=0;
  int leng=input.length();
  if((input[0]<='z'&&input[0]>='a')||(input[0]>='A'&&input[0]<='Z')) wordnum++;
  for(int i=1;i<leng;i++)
  {
    if((input[i]<='z'&&input[i]>='a')||(input[i]>='A'&&input[i]<='Z'))
      if(input[i-1]==32)
        wordnum++;
  }
  cout<<wordnum<<'\n';

  return 0;
}
