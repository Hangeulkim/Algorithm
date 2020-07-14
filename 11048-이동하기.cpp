#include<bits/stdc++.h>

using namespace std;

int N,M;
int input;
int dp[1001][1001];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N>>M;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin>>input;
            dp[i][j]=max(max(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])+input;
        }
    }
    cout<<dp[N][M]<<'\n';
    return 0;
}
