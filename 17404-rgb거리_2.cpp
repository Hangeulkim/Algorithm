#include<bits/stdc++.h>

using namespace std;

int N;
int input[1001][3];
int dp[3][1001][3];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N;
    memset(dp,0,sizeof(dp));
    for(int i=0;i<N;i++)
        cin>>input[i][0]>>input[i][1]>>input[i][2];


    for(int j=0;j<3;j++){
        dp[j][0][j]=input[0][j];
        dp[j][1][0]=j!=0?dp[j][0][j]+input[1][0]:987654321;
        dp[j][1][1]=j!=1?dp[j][0][j]+input[1][1]:987654321;
        dp[j][1][2]=j!=2?dp[j][0][j]+input[1][2]:987654321;
        for(int i=2;i<N;i++){
            dp[j][i][0]=min(dp[j][i-1][1],dp[j][i-1][2])+input[i][0];
            dp[j][i][1]=min(dp[j][i-1][0],dp[j][i-1][2])+input[i][1];
            dp[j][i][2]=min(dp[j][i-1][0],dp[j][i-1][1])+input[i][2];
        }
    }


    cout<<min(min(min(dp[0][N-1][1],dp[0][N-1][2]),min(dp[1][N-1][0],dp[1][N-1][2])),min(dp[2][N-1][0],dp[2][N-1][1]))<<'\n';

    return 0;
}
