#include<bits/stdc++.h>

using namespace std;

int dp[100001][2];
int input[100001];
int N;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>input[i];
    }

    int maxn=input[1];
    dp[1][0]=input[1];
    dp[1][1]=input[1];

    for(int i=2;i<=N;i++){
        dp[i][0]=max(input[i],dp[i-1][0]+input[i]);
        dp[i][1]=max(dp[i-1][0],dp[i-1][1]+input[i]);
        maxn=max(maxn,max(dp[i][0],dp[i][1]));
    }
    cout<<maxn;

    return 0;
}
