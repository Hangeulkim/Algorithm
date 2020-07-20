#include<bits/stdc++.h>

using namespace std;

int N;
long long dp[101];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N;

    dp[1]=1;
    dp[2]=2;
    dp[3]=3;
    dp[4]=4;

    for(int i=5;i<=N;i++){
        dp[i]=dp[i-1]+1;
        for(int j=i-2,cnt=1;j>=1;j--,cnt++){
            dp[i]=max(dp[i],dp[j]*cnt);
        }
    }
    cout<<dp[N];


    return 0;
}
