#include<bits/stdc++.h>

using namespace std;

int N,M,X,Y,a,b;
int dari[505];
int dp[505][105];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N>>M>>a>>b>>X>>Y;
    for(int i=1;i<=M;i++){
        cin>>dari[i];
    }
    fill(&dp[0][0],&dp[501][101],987654321);

    for(int i=0;i<=N;i++){
        dp[0][i]=abs(a-i)*Y;
    }
    for(int i=1;i<=M;i++){
        for(int j=1;j<=N;j++){
            for(int k=1;k<=N;k++){
                if(j==k&&(dari[i]==k||dari[i]+1==k))
                    dp[i][j]=min(dp[i][j],dp[i-1][k]+X);
                else if((k<=dari[i]&&dari[i]+1<=j)||(j<=dari[i]&&dari[i]+1<=k))
                    dp[i][j]=min(dp[i][j],dp[i-1][k]+(abs(k-j)-1)*Y);
                else
                    dp[i][j]=min(dp[i][j],dp[i-1][k]+abs(k-j)*Y);
            }
        }
    }
    cout<<dp[M][b];

    return 0;
}
