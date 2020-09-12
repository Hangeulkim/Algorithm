#include<bits/stdc++.h>

using namespace std;

int N,K;
long long mod=10007;
long long dp[1002][1002];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N>>K;
    memset(dp,0,sizeof(dp));
    dp[1][1]=1;

    K=min(K,N-K);

    for(int i=2;i<=N+1;i++){
        for(int j=1;j<=min(i,K+2);j++){
            dp[i][j]=(dp[i-1][j]+dp[i-1][j-1])%mod;
        }
    }
    cout<<dp[N+1][K+1]<<'\n';



    return 0;
}
