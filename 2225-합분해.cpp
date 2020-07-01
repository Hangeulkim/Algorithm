#include<bits/stdc++.h>

using namespace std;

int N,K;
long long dp[201][201];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N>>K;
    for(int i=0;i<=N;i++){
        dp[i][1]=1;
    }

    for(int i=0;i<=N;i++){
        for(int j=2;j<=K;j++){
             for(int x=0;x<=i;x++){
                dp[i][j]=(dp[i][j]+dp[x][j-1])%1000000000;
             }
        }
    }
    cout<<dp[N][K]<<'\n';

    return 0;
}
