#include<iostream>
#include<string>
using namespace std;
int sum;
int main()
{
  ios_base :: sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  string input;
  cin>>input;
  int leng=input.length();
  for(int i=0;i<leng;i++)
  {
    if(input[i]=='A'||input[i]=='B'||input[i]=='C')
      sum+=3;
    else if(input[i]=='D'||input[i]=='E'||input[i]=='F')
      sum+=4;
    else if(input[i]=='G'||input[i]=='H'||input[i]=='I')
      sum+=5;
    else if(input[i]=='J'||input[i]=='K'||input[i]=='L')
      sum+=6;
    else if(input[i]=='M'||input[i]=='N'||input[i]=='O')
      sum+=7;
    else if(input[i]=='P'||input[i]=='Q'||input[i]=='R'||input[i]=='S')
      sum+=8;
    else if(input[i]=='T'||input[i]=='U'||input[i]=='V')
      sum+=9;
    else if(input[i]=='W'||input[i]=='X'||input[i]=='Y'||input[i]=='Z')
      sum+=10;
  }

  cout<<sum<<'\n';

  return 0;
}
