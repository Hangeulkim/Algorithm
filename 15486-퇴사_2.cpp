#include<bits/stdc++.h>

using namespace std;
int N,d,gum;

int dp[1500001];
int result=0;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(dp,0,sizeof(dp));
    cin>>N;

    for(int i=1;i<=N;i++){
        cin>>d>>gum;
        dp[i]=max(dp[i-1],dp[i]);
        result=max(result,dp[i]);
        if(d+i-1>N)
            continue;

        dp[d+i-1]=max(dp[d+i-1],dp[i-1]+gum);
        result=max(result,dp[i]);
    }
    cout<<result<<'\n';

    return 0;
}
