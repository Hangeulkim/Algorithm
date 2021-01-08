#include<bits/stdc++.h>

using namespace std;

int N;

long long int dp[32][2];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N;
    memset(dp,0,sizeof(dp));
    dp[2][0]=3;
    dp[2][1]=2;

    for(int i=4;i<=N;i+=2){
        dp[i][0]=dp[i-2][0]*3+dp[i-2][1];
        dp[i][1]=dp[i-2][0]*2+dp[i-2][1];
    }
    cout<<dp[N][0];

    return 0;
}
