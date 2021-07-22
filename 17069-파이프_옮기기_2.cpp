#include<bits/stdc++.h>

using namespace std;

int N;
int input[33][33];
long long dp[3][33][33];


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin>>input[i][j];
        }
    }

    dp[0][1][2]=1;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(input[i][j+1]==0)
                dp[0][i][j+1]+=dp[0][i][j]+dp[2][i][j];
            if(input[i+1][j]==0)
                dp[1][i+1][j]+=dp[1][i][j]+dp[2][i][j];
            if(input[i+1][j+1]==0&&input[i][j+1]==0&&input[i+1][j]==0)
                dp[2][i+1][j+1]+=dp[0][i][j]+dp[1][i][j]+dp[2][i][j];
        }
    }

    cout<<dp[0][N][N]+dp[1][N][N]+dp[2][N][N];
    return 0;
}