#include<iostream>
#include<algorithm>
using namespace std;
int input;
int sum;
int ans[2];
int cnt;
int locate;
int main()
{
  ios_base :: sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin>>input;
  while(sum<input)//분자 분모 합 구함
  {
    cnt++;
    sum+=cnt;
  }
  input-=sum-cnt;
  cnt+=1;
  if(cnt%2==0)
    cout<<cnt-input<<"/"<<input<<'\n';
  else
    cout<<input<<"/"<<cnt-input<<'\n';

  return 0;
}
