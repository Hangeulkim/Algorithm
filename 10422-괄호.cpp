#include<bits/stdc++.h>

using namespace std;

int T,L;
long long dp[5001];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(dp,0,sizeof(dp));
    dp[0]=1;
    dp[2]=1;
    for(int i=4;i<5001;i+=2){
        if(i%2==1)
            continue;
        for(int j=0;j<i;j+=2){
            dp[i]=(dp[i]+dp[j]*dp[i-j-2])%1000000007;
        }
    }

    cin>>T;
    while(T--){
        cin>>L;
        cout<<dp[L]<<'\n';
    }

    return 0;
}
