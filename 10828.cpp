#include<iostream>
#include<cstdlib>
using namespace std;
int num[10000];
string input;
int cnt=0;
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int i=0;
  cin>>i;
  int temp=0;
  for(int j=0;j<i;j++){
    cin>>input;
    if(input.find("push")!=string::npos)
    {
      cin>>temp;
      num[cnt]=temp;
      cnt++;
    }
    else if(input.find("pop")!=string::npos)
    {
      if(cnt==0) cout<<-1<<"\n";
      else
      {
        cout<<num[cnt-1]<<"\n";
        cnt--;
      }
    }
    else if(input.find("size")!=string::npos)
    {
      cout<<cnt<<"\n";
    }
    else if(input.find("empty")!=string::npos)
    {
      if(cnt==0) cout<<1<<"\n";
      else cout<<0<<"\n";
    }
    else if(input.find("top")!=string::npos)
    {
      if(cnt==0) cout<<-1<<"\n";
      else cout<<num[cnt-1]<<"\n";
    }
  }
  return 0;
}
