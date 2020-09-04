#include<bits/stdc++.h>

using namespace std;

int N,M,P;
long long dp[101][101];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    dp[0][0]=1;
    cin>>N>>M>>P;
    for(int i=1;i<=P;i++){
        for(int j=1;j<=N;j++){
            dp[i][j]+=dp[i-1][j-1]*(N-j+1);
            if(j>M) dp[i][j]+=dp[i-1][j]*(j-M);
            dp[i][j]%=1000000007;
        }
    }
    cout<<dp[P][N];

    return 0;
}
