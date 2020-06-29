#include<bits/stdc++.h>

using namespace std;

int T;
long long dp[100001][4];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    dp[1][1]=1;
    dp[2][2]=1;
    dp[3][1]=1;
    dp[3][2]=1;
    dp[3][3]=1;
    for(int i=4;i<=100000;i++){
        dp[i][1]=dp[i-1][2]+dp[i-1][3]%1000000009;
        dp[i][2]=dp[i-2][1]+dp[i-2][3]%1000000009;
        dp[i][3]=dp[i-3][1]+dp[i-3][2]%1000000009;
    }

    cin>>T;
    int W;
    while(T--){
        cin>>W;
        cout<<(dp[W][3]+dp[W][2]+dp[W][1])%1000000009<<'\n';
    }

    return 0;
}
