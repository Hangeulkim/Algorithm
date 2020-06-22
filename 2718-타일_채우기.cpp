#include<iostream>

using namespace std;

int dp[10001][5];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T,N;
    cin>>T;
    dp[0][0]=1;
    dp[1][0]=1;
    dp[1][1]=1;
    dp[1][2]=1;
    dp[1][3]=1;

    for(int i=2;i<=10000;i++){
        dp[i][0]=dp[i-2][0]+dp[i-1][0]+dp[i-1][1]+dp[i-1][2]+dp[i-1][3];
        dp[i][1]=dp[i-1][0]+dp[i-1][3];
        dp[i][2]=dp[i-1][0]+dp[i-1][4];
        dp[i][3]=dp[i-1][0]+dp[i-1][1];
        dp[i][4]=dp[i-1][2];
    }

    while(T--){
        cin>>N;
        cout<<dp[N][0]<<'\n';
    }

    return 0;
}
