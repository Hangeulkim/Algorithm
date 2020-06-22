#include<iostream>
#include<algorithm>

using namespace std;

int dp[1000001]={1000000,0,1,1};

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int input=0;
  cin>>input;

  for(int cnt=4;cnt<=input;cnt++){
    if(cnt%3==0) dp[cnt]=min(dp[cnt/3],dp[cnt-1])+1;
    else if(cnt%2==0) dp[cnt]=min(dp[cnt/2],dp[cnt-1])+1;
    else dp[cnt]=dp[cnt-1]+1;
  }
  cout<<dp[input]<<'\n';
  return 0;
}
